#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <Manager/XmlNamespaces.h>

namespace po = boost::program_options;

using NodeTypeMap = std::map<const MergingPolicy3*, std::string>;

// TODO 2024-05-04: Remove this
struct ChairloaderGlobalEnvironment* gCL;

static constexpr char LINES[] = "----------------------------------------------------------------------";

static constexpr char XS_SCHEMA[] = "xs:schema";

void SaveXml(const pugi::xml_document& doc, const fs::path& outFile)
{
    if (!doc.save_file(outFile.c_str(), "  "))
        throw std::runtime_error("Failed to save XML");
}

pugi::xml_document CreateXsd()
{
    pugi::xml_document doc;

    // XML declaration
    pugi::xml_node xmlDecl = doc.append_child(pugi::node_declaration);
    xmlDecl.set_name("xml");
    xmlDecl.append_attribute("version").set_value("1.0");
    xmlDecl.append_attribute("encoding").set_value("utf-8");

    // Root element
    pugi::xml_node schema = doc.append_child(XS_SCHEMA);
    schema.append_attribute("xmlns").set_value(CHAIR_XML_NS_PREY);
    schema.append_attribute("xmlns:xs").set_value("http://www.w3.org/2001/XMLSchema");
    schema.append_attribute("xmlns:ch").set_value(CHAIR_XML_NS_CHAIRLOADER);
    schema.append_attribute("targetNamespace").set_value(CHAIR_XML_NS_PREY);
    schema.append_attribute("elementFormDefault").set_value("qualified");

    return doc;
}

pugi::xml_node CreateDocNode(pugi::xml_node parent, const std::string& text)
{
    pugi::xml_node annotation = parent.append_child("xs:annotation");
    pugi::xml_node documentation = annotation.append_child("xs:documentation");

    if (!text.empty())
    {
        std::vector<std::string> lines;
        boost::split(lines, text, boost::is_any_of("\n"));

        for (size_t i = 0; i < lines.size(); i++)
        {
            if (i != 0)
                documentation.append_child("br");
            documentation.append_child(pugi::node_pcdata).set_value(lines[i].c_str());
        }
    }

    return documentation;
}

void CreateTypeForPolicy(
    const NodeTypeMap& nodeTypeMap,
    const MergingPolicy3& policy,
    const MergingPolicy3::Collection* pParentCollection,
    pugi::xml_node outNode)
{
    outNode.set_name("xs:complexType");

    // Generate comment
    std::string comment;

    if (pParentCollection)
    {
        switch (pParentCollection->type)
        {
        case MergingPolicy3::ECollectionType::None:
        {
            throw std::logic_error("Collection with type None may not have child nodes");
        }
        case MergingPolicy3::ECollectionType::Dict:
        {
            comment += "Dictionary item\n";
            comment += "Key: ";

            if (pParentCollection->keyChildName)
                comment += "<Child Name> ";

            if (pParentCollection->keyChildText)
                comment += "<Child Text> ";

            for (const std::string& keyAttr : pParentCollection->keyChildAttributes)
                comment += fmt::format("\"{}\" ", keyAttr);

            break;
        }
        case MergingPolicy3::ECollectionType::Array:
        {
            comment += "Array item\n";
            break;
        }
        case MergingPolicy3::ECollectionType::ReplaceOnly:
        {
            comment += "Replace Only Node\n";
            break;
        }
        }
    }

    if (!comment.empty())
        CreateDocNode(outNode, comment);

    pugi::xml_node complexContent = outNode.append_child("xs:complexContent");
    pugi::xml_node extension = complexContent.append_child("xs:extension");
    pugi::xml_attribute baseTypeAttr = extension.append_attribute("base");

    // Decide on the type
    auto fnHasAttribute = [&](auto pred)
    {
        auto it = std::find_if(policy.GetAttributes().begin(), policy.GetAttributes().end(), pred);
        return it != policy.GetAttributes().end();
    };

    if (fnHasAttribute([](const MergingPolicy3::Attribute& x) { return x.name == "ch:index" && x.required; }))
    {
        baseTypeAttr.set_value("ch:RequiredIndexedMetaType");
    }
    else if (fnHasAttribute([](const MergingPolicy3::Attribute& x) { return x.name == "ch:index" && !x.required; }))
    {
        baseTypeAttr.set_value("ch:IndexedMetaType");
    }
    else
    {
        baseTypeAttr.set_value("ch:MetaType");
    }

    // Child nodes
    pugi::xml_node choice;

    for (auto& [childNodeName, childNodePolicy] : policy.GetChildNodes())
    {
        if (!choice)
        {
            choice = extension.append_child("xs:choice");
            choice.append_attribute("maxOccurs").set_value("unbounded");
        }

        pugi::xml_node element = choice.append_child("xs:element");
        element.append_attribute("name").set_value(childNodeName.c_str());
        element.append_attribute("minOccurs").set_value("0");
        element.append_attribute("maxOccurs").set_value("unbounded");

        auto it = nodeTypeMap.find(childNodePolicy);

        if (it != nodeTypeMap.end())
        {
            // NodeByType
            element.append_attribute("type").set_value(it->second.c_str());
        }
        else
        {
            // Node
            pugi::xml_node elementType = element.append_child();
            CreateTypeForPolicy(nodeTypeMap, *childNodePolicy, &policy.GetCollection(), elementType);
        }
    }

    // TODO 2024-09-03: Regex nodes

    // Attributes
    for (const MergingPolicy3::Attribute& attr : policy.GetAttributes())
    {
        if (boost::starts_with(attr.name, "ch:"))
        {
            continue;
        }

        pugi::xml_node attribute = extension.append_child("xs:attribute");
        attribute.append_attribute("name").set_value(attr.name.c_str());

        if (!attr.allowEmpty)
        {
            // Reference the type directly
            attribute.append_attribute("type").set_value(attr.type.c_str());
        }

        std::string docText;

        if (pParentCollection && pParentCollection->type == MergingPolicy3::ECollectionType::Dict)
        {
            auto it = std::find(pParentCollection->keyChildAttributes.begin(), pParentCollection->keyChildAttributes.end(), attr.name);

            if (it != pParentCollection->keyChildAttributes.end())
            {
                attribute.append_attribute("use").set_value("required");
                docText += "[KEY] ";
            }
        }

        if (attr.readOnly)
            docText += "[READ-ONLY] ";

        if (attr.allowEmpty)
            docText += "[MAY BE EMPTY] ";

        if (!attr.comment.empty())
        {
            docText += "\n";
            docText += attr.comment;
        }

        if (!docText.empty())
        {
            CreateDocNode(attribute, docText);
        }

        if (attr.allowEmpty)
        {
            // Create a union type of the type and an empty string
            pugi::xml_node unionxs = attribute
                .append_child("xs:simpleType")
                .append_child("xs:union");

            pugi::xml_node strRestr = unionxs
                .append_child("xs:simpleType")
                .append_child("xs:restriction");

            strRestr
                .append_attribute("base")
                .set_value("xs:string");

            strRestr
                .append_child("xs:length")
                .append_attribute("value")
                .set_value("0");

            unionxs
                .append_child("xs:simpleType")
                .append_child("xs:restriction")
                .append_attribute("base")
                .set_value(attr.type.c_str());
        }
    }

    if (policy.IsAllowingUnknownAttributes())
    {
        extension
            .append_child("xs:anyAttribute")
            .append_attribute("processContents")
            .set_value("skip");
    }
}

void GenerateValueTypes(const XmlTypeLibrary& typeLib, const fs::path& outFile)
{
    pugi::xml_document doc = CreateXsd();
    pugi::xml_node root = doc.child(XS_SCHEMA);
    std::vector<const IXmlValueType*> types = typeLib.GetValueTypes();

    for (const IXmlValueType* pType : types)
    {
        pugi::xml_node typeNode = root.append_child("temp");
        pType->GetXsdType(typeNode);
    }

    SaveXml(doc, outFile);
}

NodeTypeMap GenerateNodeTypes(const XmlTypeLibrary& typeLib, const fs::path& outFile)
{
    pugi::xml_document doc = CreateXsd();
    pugi::xml_node root = doc.child(XS_SCHEMA);
    std::vector<std::pair<const MergingPolicy3*, std::string>> types = typeLib.GetNodeTypes();

    // Include value types
    root.append_child("xs:include").append_attribute("schemaLocation").set_value("./ValueTypes.xsd");

    // Import meta-node
    pugi::xml_node importMeta = root.append_child("xs:import");
    importMeta.append_attribute("namespace").set_value(CHAIR_XML_NS_CHAIRLOADER);
    importMeta.append_attribute("schemaLocation").set_value(("../Chairloader/" + std::string(CHAIR_XSD_META_TYPE)).c_str());

    // Cache all type names
    NodeTypeMap typeNameMap;

    for (const auto& [pPolicy, typeName] : types)
    {
        typeNameMap.emplace(pPolicy, typeName);
    }

    // Generate types
    for (const auto& [pPolicy, typeName] : types)
    {
        pugi::xml_node typeNode = root.append_child();
        typeNode.append_attribute("name").set_value(typeName.c_str());
        CreateTypeForPolicy(typeNameMap, *pPolicy, nullptr, typeNode);
    }

    SaveXml(doc, outFile);
    return typeNameMap;
}

void GenerateFileSchema(
    const fs::path& xsdRefPath,
    const NodeTypeMap& nodeTypeMap,
    const FileMergingPolicy3& policy,
    const fs::path& outFile)
{
    if (policy.GetMethod() != FileMergingPolicy3::EMethod::Merge &&
        policy.GetMethod() != FileMergingPolicy3::EMethod::ReadOnly)
        return;

    pugi::xml_document doc = CreateXsd();
    pugi::xml_node root = doc.child(XS_SCHEMA);

    // Include types
    if (!xsdRefPath.empty())
        root.append_child("xs:include").append_attribute("schemaLocation").set_value((xsdRefPath / "Prey/ValueTypes.xsd").generic_u8string().c_str());
    else
        root.append_child("xs:include").append_attribute("schemaLocation").set_value(fmt::format("{}/ValueTypes.xsd", CHAIR_XML_NS_PREY).c_str());

    if (!xsdRefPath.empty())
        root.append_child("xs:include").append_attribute("schemaLocation").set_value((xsdRefPath / "Prey/NodeTypes.xsd").generic_u8string().c_str());
    else
        root.append_child("xs:include").append_attribute("schemaLocation").set_value(fmt::format("{}/NodeTypes.xsd", CHAIR_XML_NS_PREY).c_str());

    // Import meta-node
    pugi::xml_node importMeta = root.append_child("xs:import");
    importMeta.append_attribute("namespace").set_value(CHAIR_XML_NS_CHAIRLOADER);
    importMeta.append_attribute("schemaLocation").set_value((xsdRefPath / "Chairloader" / CHAIR_XSD_META_TYPE).generic_u8string().c_str());

    // Add root node
    pugi::xml_node element = root.append_child("xs:element");
    element.append_attribute("name").set_value(policy.GetRootNodeName().c_str());

    auto it = nodeTypeMap.find(&policy.GetRootNode());

    if (it != nodeTypeMap.end())
    {
        // NodeByType
        element.append_attribute("type").set_value(it->second.c_str());
    }
    else
    {
        // Node
        pugi::xml_node elementType = element.append_child();
        CreateTypeForPolicy(nodeTypeMap, policy.GetRootNode(), nullptr, elementType);
    }

    SaveXml(doc, outFile);
}

int main(int argc, char** argv)
{
    po::options_description desc("Generate XML Schema files for Prey files based on the merging policy");
    po::variables_map vm;

    try
    {
        desc.add_options()
            ("help", "produce help message")
            ("type-lib", po::value<std::string>()->required(), "path to the type library")
            ("merging-lib", po::value<std::string>()->required(), "path to the merging library")
            ("out-dir", po::value<std::string>()->required(), "path to the output XSD directory");

        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }

        po::notify(vm);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        std::cout << desc << "\n";
        return 1;
    }

    try
    {
        auto startTime = std::chrono::steady_clock::now();

        fs::path outDir = fs::u8path(vm["out-dir"].as<std::string>());

        // Load type library
        fs::path typeLibPath = fs::u8path(vm["type-lib"].as<std::string>());
        XmlTypeLibrary typeLib;
        typeLib.LoadTypesFromFile(typeLibPath);

        // Load merging library
        fs::path mergingLibraryPath = fs::u8path(vm["merging-lib"].as<std::string>());
        fmt::println("Merging library: {}", mergingLibraryPath.u8string());
        MergingLibrary3 mergingLibrary(&typeLib);
        mergingLibrary.LoadFromPath(mergingLibraryPath);

        // Generate value types
        fs::path valueTypesPath = outDir / "ValueTypes.xsd";
        GenerateValueTypes(typeLib, valueTypesPath);

        // Generate node types
        fs::path nodeTypesPath = outDir / "NodeTypes.xsd";
        NodeTypeMap nodeTypeMap = GenerateNodeTypes(typeLib, nodeTypesPath);

        // Generate XSD for each file
        const auto& policyFiles = mergingLibrary.GetFilePathMap();

        for (const auto& [relPath, pFilePolicy] : policyFiles)
        {
            try
            {
                fs::path filePath = outDir / relPath;
                fs::create_directories(filePath.parent_path());
                GenerateFileSchema(outDir.parent_path(), nodeTypeMap , *pFilePolicy, outDir / relPath);
            }
            catch (const std::exception& e)
            {
                fmt::println("{}: {}", relPath.u8string(), e.what());
            }
        }

        // Record processing time here so printing doesn't count
        auto endTime = std::chrono::steady_clock::now();

        auto timeElapsed = endTime - startTime;
        fmt::println("Time elapsed: {:.3f} s", std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed).count() / 1000.0);
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 2;
}