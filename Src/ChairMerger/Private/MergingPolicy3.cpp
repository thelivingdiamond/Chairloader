#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlTypeLibrary.h>

static const std::map<std::string, FileMergingPolicy3::EMethod, std::less<>> g_MethodValues = {
    { "readOnly", FileMergingPolicy3::EMethod::ReadOnly },
    { "merge", FileMergingPolicy3::EMethod::Merge },
    { "replace", FileMergingPolicy3::EMethod::Replace },
    { "localization", FileMergingPolicy3::EMethod::Localization },
};

//---------------------------------------------------------------------------------
// MergingPolicyAllocator
//---------------------------------------------------------------------------------
MergingPolicyAllocator::MergingPolicyAllocator()
{
}

MergingPolicyAllocator::~MergingPolicyAllocator()
{
}

MergingPolicy3* MergingPolicyAllocator::AllocateEmptyPolicy()
{
    return m_PolicyPool.emplace_back(std::make_unique<MergingPolicy3>()).get();
}


//---------------------------------------------------------------------------------
// MergingPolicy3::Collection
//---------------------------------------------------------------------------------
std::string MergingPolicy3::Collection::GetKeyString() const
{
    std::string keyName;

    for (size_t i = 0; i < keyChildAttributes.size(); i++)
    {
        if (i != 0)
            keyName += ',';

        keyName += keyChildAttributes[i];
    }

    return keyName;
}

std::pair<std::string, std::string> MergingPolicy3::Collection::GetKeyValuePair(const pugi::xml_node& childNode) const
{
    std::string keyName = GetKeyString();
    std::string keyValue;

    for (size_t i = 0; i < keyChildAttributes.size(); i++)
    {
        if (i != 0)
            keyValue += ',';

        keyValue += childNode.attribute(keyChildAttributes[i].c_str()).as_string("<not set>");
    }

    return std::make_pair(std::move(keyName), std::move(keyValue));
}

//---------------------------------------------------------------------------------
// MergingPolicy3
//---------------------------------------------------------------------------------
const MergingPolicy3::Attribute* MergingPolicy3::FindAttribute(std::string_view name) const
{
    for (const Attribute& attr : m_Attributes)
    {
        if (attr.name == name)
            return &attr;
    }

    return nullptr;
}

const MergingPolicy3* MergingPolicy3::FindChildNode(std::string_view name) const
{
    // Check exact nodes
    if (auto it = m_ChildNodes.find(name); it != m_ChildNodes.end())
        return it->second;

    // Check regex
    std::string nameAsStr(name);

    for (const auto& [regex, node] : m_ChildNodesRegex)
    {
        if (boost::regex_match(nameAsStr, regex))
            return node;
    }

    // Recursive if not found
    if (m_IsRecursive)
        return this;

    return nullptr;
}

void MergingPolicy3::AppendNode(std::string_view name, bool isRegex, const MergingPolicy3* node)
{
    if (isRegex)
    {
        m_ChildNodesRegex.emplace_back(boost::regex(std::string(name)), node);
    }
    else
    {
        m_ChildNodes.emplace(std::string(name), node);
    }
}

void MergingPolicy3::LoadXmlNode(IMergingPolicyAllocator* pAlloc, XmlTypeLibrary* pTypeLib, const pugi::xml_node& node, const XmlErrorStack& errorStack)
{
    SetRecursive(node.attribute("recursive").as_bool(false));
    SetTextType(node.attribute("textType").as_string(""));
    SetEmptyTextAllowed(node.attribute("allowEmptyText").as_bool(false));

    // Reset fields
    m_AllowUnknownAttributes = false;
    m_Attributes.clear();
    m_Collection = Collection();
    m_ChildConstraints = ChildConstraints();

    bool foundAttributes = false;
    bool foundPatches = false;
    bool foundCollection = false;
    bool foundChildConstraints = false;
    bool foundChildNodes = false;

    for (const pugi::xml_node childNode : node)
    {
        if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_ATTRIBUTES, &foundAttributes))
            LoadXmlAttributes(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_PATCHES, &foundPatches))
            LoadXmlPatches(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_COLLECTION, &foundCollection))
            LoadXmlCollection(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_CHILD_CONSTRAINTS, &foundChildConstraints))
            LoadXmlChildConstraints(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_CHILD_NODES, &foundChildNodes))
            LoadXmlChildNodes(pAlloc, pTypeLib, childNode, errorStack);
        else
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
    }

    XmlUtils::ThrowMissingNodeIfFalse(errorStack, XML_NODE_ATTRIBUTES, foundAttributes);
}

void MergingPolicy3::LoadXmlAttributes(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_ATTRIBUTES);
    m_AllowUnknownAttributes = node.attribute("allowUnknown").as_bool(false);

    int i = 0;

    for (const pugi::xml_node childNode : node)
    {
        if (!strcmp(childNode.name(), XML_NODE_ATTRIBUTE))
        {
            XmlErrorStack curErrorStack = errorStack.GetChild(XML_NODE_ATTRIBUTE);
            curErrorStack.SetIndex(i);

            Attribute attr;
            attr.name = XmlUtils::GetRequiredAttr(curErrorStack, childNode, "name").as_string();
            attr.type = XmlUtils::GetRequiredAttr(curErrorStack, childNode, "type").as_string();
            attr.required = childNode.attribute("required").as_bool(false);
            attr.allowEmpty = childNode.attribute("allowEmpty").as_bool(false);
            attr.readOnly = childNode.attribute("readOnly").as_bool(false);
            attr.generated = childNode.attribute("generated").as_bool(false);
            attr.comment = childNode.attribute("comment").as_string();

            if (attr.readOnly && !attr.required)
                curErrorStack.ThrowException("Read-only attribute must be required");

            m_Attributes.emplace_back(attr);
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }

        i++;
    }
}

void MergingPolicy3::LoadXmlPatches(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_PATCHES);
    int i = 0;
    bool foundAddChildIndex = false;
    bool foundAddEntityGuid = false;
    bool foundAddEntitySerialize = false;

    for (const pugi::xml_node childNode : node)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        if (!strcmp(childNode.name(), XML_NODE_REMOVE_ATTR))
        {
            std::string attrName = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "name").as_string();
            m_Patches.removeAttr.emplace_back(std::move(attrName));
        }
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_ADD_CHILD_INDEX, &foundAddChildIndex))
        {
            m_Patches.addChildIndex = true;
            m_Patches.childIndexAttr = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "name").as_string();
            m_Patches.childIndexIncrement = childNode.attribute("increment").as_int(1000);
        }
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_ADD_ENTITY_GUID, &foundAddEntityGuid))
        {
            m_Patches.addEntityGuid = true;
            m_Patches.addEntityGuidName = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "guidName").as_string();
            m_Patches.addEntityGuidFlagName = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "flagName").as_string();

            for (const pugi::xml_node hashAttrNode : childNode)
            {
                m_Patches.addEntityGuidHash.push_back(hashAttrNode.text().as_string());
            }
        }
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_ADD_ENTITY_SERIALIZE, &foundAddEntitySerialize))
        {
            m_Patches.addEntitySerialize = true;
            m_Patches.addEntitySerializeIdAttrName = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "idAttrName").as_string();
            m_Patches.addEntitySerializeAttrName = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "serializeAttrName").as_string();
            m_Patches.addEntitySerializeFilePath = XmlUtils::GetRequiredAttr(childErrorStack, childNode, "filePath").as_string();
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }

        i++;
    }
}

void MergingPolicy3::LoadXmlCollection(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_COLLECTION);
    
    std::string typeStr = XmlUtils::GetRequiredAttr(errorStack, node, "type").as_string();

    if (typeStr == "dict")
    {
        m_Collection.type = ECollectionType::Dict;
    }
    else if (typeStr == "nodeDict")
    {
        m_Collection.type = ECollectionType::Dict;
        m_Collection.keyChildName = true;

        if (node.begin() != node.end())
            errorStack.ThrowException("Collection may not have any other properties if type is nodeDict");
    }
    else if (typeStr == "array")
    {
        m_Collection.type = ECollectionType::Array;
    }
    else if (typeStr == "replaceOnly")
    {
        m_Collection.type = ECollectionType::ReplaceOnly;
    }
    else
    {
        errorStack.ThrowException(fmt::format("Unknown type '{}'", typeStr));
    }

    bool foundPrimaryKey = false;
    bool foundArrayIndex = false;

    for (const pugi::xml_node childNode : node)
    {
        if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_PRIMARY_KEY, &foundPrimaryKey))
        {
            XmlErrorStack pkeyErrorStack = errorStack.GetChild(XML_NODE_PRIMARY_KEY);

            if (m_Collection.type != ECollectionType::Dict)
                pkeyErrorStack.ThrowException("Primary key may only be set for a dictionary");

            int i = 0;

            for (const pugi::xml_node keyNode : childNode)
            {
                XmlErrorStack keyErrorStack = errorStack.GetChild(keyNode.name());
                keyErrorStack.SetIndex(i);

                if (XmlUtils::EqualsOnceOrThrow(errorStack, keyNode, XML_NODE_CHILD_NAME, &m_Collection.keyChildName))
                {
                    m_Collection.keyChildName = true;
                }
                else if (!strcmp(keyNode.name(), XML_NODE_CHILD_ATTRIBUTE))
                {
                    std::string attrName = XmlUtils::GetRequiredAttr(keyErrorStack, keyNode, "name").as_string();
                    m_Collection.keyChildAttributes.emplace_back(std::move(attrName));
                }
                else
                {
                    XmlUtils::ThrowUnknownNode(errorStack, keyNode);
                }

                i++;
            }
        }
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_CHILD_INDEX_ATTR, &foundArrayIndex))
        {
            XmlErrorStack indexErrorStack = errorStack.GetChild(XML_NODE_PRIMARY_KEY);

            if (m_Collection.type != ECollectionType::Array)
                indexErrorStack.ThrowException("Index attribute may only be set for an array");

            m_Collection.arrayIndexAttr = XmlUtils::GetRequiredAttr(indexErrorStack, childNode, "name").as_string();

            if (m_Collection.arrayIndexAttr.empty())
                indexErrorStack.ThrowException("Index attribute may not be empty");
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }
    }

    if (m_Collection.type == ECollectionType::Dict)
    {
        if (!m_Collection.keyChildName && m_Collection.keyChildAttributes.empty())
            errorStack.ThrowException("Dict collection has no primary key defined");
    }
    else if (m_Collection.type == ECollectionType::Array)
    {
        XmlUtils::ThrowMissingNodeIfFalse(errorStack, XML_NODE_CHILD_INDEX_ATTR, foundArrayIndex);
    }
}

void MergingPolicy3::LoadXmlChildConstraints(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_CHILD_CONSTRAINTS);
    int i = 0;

    for (const pugi::xml_node childNode : node)
    {
        XmlErrorStack curErrorStack = errorStack.GetChild(childNode.name());
        curErrorStack.SetIndex(i);

        if (!strcmp(childNode.name(), XML_NODE_UNIQUE_ATTRIBUTE))
        {
            std::string attrName = XmlUtils::GetRequiredAttr(curErrorStack, childNode, "name").as_string();
            m_ChildConstraints.uniqueAttributes.emplace_back(std::move(attrName));
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }

        i++;
    }
}

void MergingPolicy3::LoadXmlChildNodes(IMergingPolicyAllocator* pAlloc, XmlTypeLibrary* pTypeLib, const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_CHILD_NODES);
    int i = 0;

    for (const pugi::xml_node childNode : node)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        std::string_view name = XmlUtils::GetRequiredAttr(errorStack, childNode, "name").as_string();
        childErrorStack.SetId("name", name);

        if (m_Collection.type == ECollectionType::None)
            childErrorStack.ThrowException("Child nodes are not allowed if collection is not set");

        bool isRegex = childNode.attribute("nameRegex").as_bool(false);

        if (!strcmp(childNode.name(), XML_NODE_NAME))
        {
            MergingPolicy3* item = pAlloc->AllocateEmptyPolicy();
            item->LoadXmlNode(pAlloc, pTypeLib, childNode, childErrorStack);
            AppendNode(name, isRegex, item);
        }
        else if (!strcmp(childNode.name(), XML_NODE_NODE_BY_TYPE))
        {
            if (!pTypeLib)
                childErrorStack.ThrowException("Can't use NodeByType since no type library is available");

            std::string_view typeName = XmlUtils::GetRequiredAttr(errorStack, childNode, "type").as_string();
            const MergingPolicy3* item = pTypeLib->FindNodeType(typeName);

            if (!item)
                childErrorStack.ThrowException(fmt::format("Node type '{}' not found", typeName));

            AppendNode(name, isRegex, item);
        }
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }

        i++;
    }
}

//---------------------------------------------------------------------------------
// FileMergingPolicy3
//---------------------------------------------------------------------------------
bool FileMergingPolicy3::MatchFileName(const std::string& name) const
{
    if (m_IsFileNameRegex)
        return boost::regex_match(name, m_FileNameRegex);
    else
        return m_FileName == name;
}

void FileMergingPolicy3::SetFileName(std::string_view fileName, bool isRegex)
{
    m_FileName = fileName;

    if (isRegex)
    {
        m_FileNameRegex = boost::regex(m_FileName, boost::regex_constants::ECMAScript | boost::regex_constants::icase);
        m_IsFileNameRegex = true;
    }
    else
    {
        m_FileNameRegex = boost::regex();
        m_IsFileNameRegex = false;
    }
}

void FileMergingPolicy3::LoadXmlNode(
    XmlTypeLibrary* pTypeLib,
    const pugi::xml_node& node,
    const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_NAME);

    if (pugi::xml_attribute fileNameRegexAttr = node.attribute("fileNameRegex"))
        SetFileName(fileNameRegexAttr.as_string(), true);

    SetRecursive(node.attribute("recursive").as_bool(false));

    if (!XmlUtils::TryGetEnumAttribute(node.attribute("method"), g_MethodValues, m_Method))
        m_Method = EMethod::Merge;

    const pugi::xml_node rootNode = node.child("Node");
    const pugi::xml_node rootNodeByType = node.child("NodeByType");

    if (rootNode && rootNodeByType)
        errorStack.ThrowException("Only one of Node or NodeByType must be specified");
    else if (!rootNode && !rootNodeByType)
        errorStack.ThrowException("One of Node or NodeByType must be specified");

    if (rootNode)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(rootNode);
        m_RootNodeName = XmlUtils::GetRequiredAttr(childErrorStack, rootNode, "name").as_string();
        MergingPolicy3* item = m_Alloc.AllocateEmptyPolicy();
        item->LoadXmlNode(&m_Alloc, pTypeLib, rootNode, errorStack);
        m_RootNode = item;
    }
    else if (rootNodeByType)
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(rootNodeByType);
        m_RootNodeName = XmlUtils::GetRequiredAttr(childErrorStack, rootNodeByType, "name").as_string();

        if (!pTypeLib)
            childErrorStack.ThrowException("Can't use NodeByType since no type library is available");

        std::string_view typeName = XmlUtils::GetRequiredAttr(errorStack, rootNodeByType, "type").as_string();
        const MergingPolicy3* item = pTypeLib->FindNodeType(typeName);

        if (!item)
            childErrorStack.ThrowException(fmt::format("Node type '{}' not found", typeName));

        m_RootNode = item;
    }
}
