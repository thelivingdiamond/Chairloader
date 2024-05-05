#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>

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

std::pair<std::string, std::string> MergingPolicy3::Collection::GetKeyValuePair(const pugi::xml_node& node) const
{
    std::string keyName = GetKeyString();
    std::string keyValue;

    for (size_t i = 0; i < keyChildAttributes.size(); i++)
    {
        if (i != 0)
            keyValue += ',';

        keyValue += node.attribute(keyChildAttributes[i].c_str()).as_string("<not set>");
    }

    return std::make_pair(std::move(keyName), std::move(keyValue));
}

//---------------------------------------------------------------------------------
// MergingPolicy3
//---------------------------------------------------------------------------------
void MergingPolicy3::SetNodeName(std::string_view nodeName, bool isRegex)
{
    m_NodeName = nodeName;

    if (isRegex)
    {
        m_NodeNameRegex = std::regex(m_NodeName);
        m_IsNodeNameRegex = true;
    }
    else
    {
        m_NodeNameRegex = std::regex();
        m_IsNodeNameRegex = false;
    }
}

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
    for (const MergingPolicy3& i : m_ChildNodes)
    {
        if (i.GetNodeName() == name)
            return &i;
    }

    // Check regex
    std::string nameAsStr(name);

    for (const MergingPolicy3& i : m_ChildNodesRegex)
    {
        if (std::regex_match(nameAsStr, i.m_NodeNameRegex))
            return &i;
    }

    // Recursive if not found
    if (m_IsRecursive)
        return this;

    return nullptr;
}

void MergingPolicy3::AppendNode(const MergingPolicy3& node)
{
    GetCollectionForNewNode(node).emplace_back(node);
}

void MergingPolicy3::AppendNode(MergingPolicy3&& node)
{
    GetCollectionForNewNode(node).emplace_back(std::move(node));
}

void MergingPolicy3::LoadXmlNode(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack, int indexInParent)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_NAME);
    errorStack.SetIndex(indexInParent);

    SetNodeName(
        XmlUtils::GetRequiredAttr(errorStack, node, "name").as_string(),
        node.attribute("nameRegex").as_bool(false));

    errorStack.SetId("name", GetNodeName());

    SetRecursive(node.attribute("recursive").as_bool(false));

    // Reset fields
    m_AllowUnknownAttributes = false;
    m_Attributes.clear();
    m_Collection = Collection();
    m_ChildConstraints = ChildConstraints();

    bool foundAttributes = false;
    bool foundCollection = false;
    bool foundChildConstraints = false;
    bool foundChildNodes = false;

    for (const pugi::xml_node childNode : node)
    {
        if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_ATTRIBUTES, &foundAttributes))
            LoadXmlAttributes(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_COLLECTION, &foundCollection))
            LoadXmlCollection(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_CHILD_CONSTRAINTS, &foundChildConstraints))
            LoadXmlChildConstraints(childNode, errorStack);
        else if (XmlUtils::EqualsOnceOrThrow(errorStack, childNode, XML_NODE_CHILD_NODES, &foundChildNodes))
            LoadXmlChildNodes(childNode, errorStack);
        else
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
    }

    XmlUtils::ThrowMissingNodeIfFalse(errorStack, XML_NODE_ATTRIBUTES, foundAttributes);
}

std::vector<MergingPolicy3>& MergingPolicy3::GetCollectionForNewNode(const MergingPolicy3& node)
{
    if (node.IsNodeNameRegex())
        return m_ChildNodesRegex;
    else
        return m_ChildNodes;
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
            attr.comment = childNode.attribute("comment").as_string();

            m_Attributes.emplace_back(attr);
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
    else
    {
        errorStack.ThrowException(fmt::format("Unknown type '{}'", typeStr));
    }

    bool foundPrimaryKey = false;

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
        else
        {
            XmlUtils::ThrowUnknownNode(errorStack, childNode);
        }
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

void MergingPolicy3::LoadXmlChildNodes(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_CHILD_NODES);
    int i = 0;

    for (const pugi::xml_node childNode : node)
    {
        if (!strcmp(childNode.name(), XML_NODE_NAME))
        {
            if (m_Collection.type == ECollectionType::None)
                errorStack.ThrowException("Child nodes are not allowed if collection is not set");

            MergingPolicy3 item;
            item.LoadXmlNode(childNode, errorStack, i);
            AppendNode(std::move(item));
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
        return std::regex_match(name, m_FileNameRegex);
    else
        return m_FileName == name;
}

void FileMergingPolicy3::SetFileName(std::string_view fileName, bool isRegex)
{
    m_FileName = fileName;

    if (isRegex)
    {
        m_FileNameRegex = std::regex(m_FileName, std::regex_constants::ECMAScript | std::regex_constants::icase);
        m_IsFileNameRegex = true;
    }
    else
    {
        m_FileNameRegex = std::regex();
        m_IsFileNameRegex = false;
    }
}

void FileMergingPolicy3::LoadXmlNode(const pugi::xml_node& node, const XmlErrorStack& parentErrorStack)
{
    XmlErrorStack errorStack = parentErrorStack.GetChild(XML_NODE_NAME);

    if (pugi::xml_attribute fileNameRegexAttr = node.attribute("fileNameRegex"))
        SetFileName(fileNameRegexAttr.as_string(), true);

    SetRecursive(node.attribute("recursive").as_bool(false));

    const pugi::xml_node rootNode = XmlUtils::GetRequiredNode(errorStack, node, MergingPolicy3::XML_NODE_NAME);
    m_RootNode.LoadXmlNode(rootNode, errorStack);
}
