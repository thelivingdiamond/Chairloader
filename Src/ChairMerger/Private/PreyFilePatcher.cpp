#include <boost/algorithm/string.hpp>
#include <SHA256/SHA256.h>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlValidator.h>
#include "Manager/XmlNamespaces.h"
#include "MetaAttributes.h"

static char nibbleToHex(uint8_t val)
{
    CRY_ASSERT(val <= 0xF);
    return val >= 0xA ? (val + 'A' - 0xA) : (val + '0');
}

static uint8_t hexToNibble(char c)
{
    CRY_ASSERT((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'));
    return c >= 'A' ? (c - 'A' + 0xA) : (c - '0');
}

void PreyFilePatcher::PatchNode(
    const fs::path& xmlFilePath,
    pugi::xml_node node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    if (policy.GetCollection().type == MergingPolicy3::ECollectionType::ReplaceOnly &&
        node.children().begin() != node.children().end())
    {
        // User can only replace all children in this node.
        // Pre-set the action to replaceChildren for ease of use
        XmlUtils::GetOrAddAttribute(node, MetaAttributes::ACTION).set_value("replaceChildren");
    }

    const MergingPolicy3::Patches& patches = policy.GetPatches();

    // RemoveAttribute
    for (const std::string& attrName : patches.removeAttr)
    {
        node.remove_attribute(attrName.c_str());
    }

    // AddChildIndex
    if (patches.addChildIndex)
    {
        int i = 0;

        for (pugi::xml_node childNode : node.children())
        {
            int index = (i + 1) * patches.childIndexIncrement;
            childNode.remove_attribute(patches.childIndexAttr.c_str());
            childNode.prepend_attribute(patches.childIndexAttr.c_str()).set_value(index);

            i++;
        }
    }

    // AddEntityGuid
    if (patches.addEntityGuid)
    {
        std::set<std::string> generatedGuids;
        int i = 0;

        // xmlFilePath looks like Levels/Campaign/EndGame/level/mission_mission0.xml
        std::string levelName = xmlFilePath.parent_path().parent_path().filename().u8string();

        for (pugi::xml_node childNode : node.children())
        {
            XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
            childErrorStack.SetIndex(i);

            pugi::xml_attribute guidAttr = childNode.attribute(patches.addEntityGuidName.c_str());
            pugi::xml_attribute flagAttr = childNode.attribute(patches.addEntityGuidFlagName.c_str());

            if (!guidAttr || flagAttr)
            {
                // Create the attributes if they don't exist
                if (!guidAttr)
                    guidAttr = childNode.append_attribute(patches.addEntityGuidName.c_str());
                if (!flagAttr)
                    flagAttr = childNode.append_attribute(patches.addEntityGuidFlagName.c_str());

                // Set the flag
                flagAttr.set_value(true);

                // Generate hash string
                std::string hashString = levelName;

                for (const std::string& hashAttrName : patches.addEntityGuidHash)
                {
                    hashString += '|';
                    hashString += childNode.attribute(hashAttrName.c_str()).as_string();
                }

                // Hash
                SHA256 sha;
                sha.update(hashString);
                SHA256::Digest hash = sha.digest();

                // Take first 16 chars
                constexpr size_t HASH_LEN = 16;
                std::string guid(HASH_LEN, '.');

                for (size_t i = 0; i < HASH_LEN; i++)
                {
                    uint8_t val;

                    if (i % 2 == 0)
                        val = hash[i / 2] & 0x0F;
                    else
                        val = hash[i / 2] >> 4;

                    guid[i] = nibbleToHex(val);
                }

                // Check for collisions
                int collisionCount = 0;

                while (generatedGuids.find(guid) != generatedGuids.end())
                {
                    if (collisionCount >= 16)
                        childErrorStack.ThrowException(fmt::format("Hash collision: '{}'", guid));
                    collisionCount++;

                    uint8_t val = hexToNibble(guid[guid.size() - 1]);
                    guid[guid.size() - 1] = nibbleToHex((val + 1) & 0xF);
                }

                generatedGuids.insert(guid);
                guidAttr.set_value(guid.c_str());
            }
        }
    }

    if (patches.addEntitySerialize)
    {
        fs::path serializePath = xmlFilePath / fs::u8path(patches.addEntitySerializeFilePath);
        pugi::xml_document serializeDoc = XmlUtils::LoadDocument(serializePath);

        for (const pugi::xml_node& serializeNode : serializeDoc.child("EntitySerialization"))
        {
            std::string_view serEntityId = serializeNode.attribute("id").as_string();

            if (serEntityId.empty())
                errorStack.ThrowException(fmt::format("{} contains empty id", patches.addEntitySerializeFilePath));

            // Find the entity
            for (pugi::xml_node childNode : node.children())
            {
                std::string_view entityId = childNode.attribute(patches.addEntitySerializeIdAttrName.c_str()).as_string();

                if (entityId == serEntityId)
                {
                    // Set it as serializable
                    pugi::xml_attribute serAttr = XmlUtils::GetOrAddAttribute(childNode, patches.addEntitySerializeAttrName.c_str());
                    serAttr.set_value(true);
                    break;
                }
            }

            // If not found - not an error. Some IDs are actually missing.
        }
    }

    // Recurse down
    int i = 0;

    for (pugi::xml_node childNode : node.children())
    {
        if (XmlUtils::IsTextNode(childNode))
            continue;

        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        const MergingPolicy3* pChildPolicy = policy.FindChildNode(childNode.name());
        if (!pChildPolicy)
        {
            childErrorStack.ThrowException(fmt::format(
                "Node {} can't be a child of {} (merging policy not found)",
                childNode.name(),
                node.name()));
        }

        PatchNode(xmlFilePath, childNode, *pChildPolicy, childErrorStack);

        i++;
    }

    // ReplaceEntityIDs
    // Process after AddEntityGuid in child nodes
    if (patches.replaceEntityIDs)
    {
        // Preload all entity GUIDs
        std::map<int, std::string> entityGuidMap;
        XmlErrorStack objectsErrorStack = errorStack.GetChild("Objects");
        int j = -1;

        for (const pugi::xml_node& entityNode : node.child("Objects").children())
        {
            j++;

            if (strcmp(entityNode.name(), "Entity"))
                continue;

            XmlErrorStack entityErrorStack = objectsErrorStack.GetChild(entityNode);
            entityErrorStack.SetIndex(j);

            std::string entityGuid = XmlUtils::GetRequiredAttr(entityErrorStack, entityNode, "EntityGuid").as_string();
            entityErrorStack.SetId("EntityGuid", entityGuid);

            int entityId = XmlUtils::GetRequiredAttr(entityErrorStack, entityNode, "EntityId").as_int(-9999);
            if (entityId == -9999)
                entityErrorStack.ThrowException("Invalid EntityId");

            if (entityGuidMap.find(entityId) != entityGuidMap.end())
                entityErrorStack.ThrowException(fmt::format("Duplicate EntityId {}", entityId));

            entityGuidMap.emplace(entityId, std::move(entityGuid));
        }

        // Go over all nodes. If found an attribute with type EntityId, replace it
        PatchEntityIds(node, policy, errorStack, entityGuidMap);
    }
}

void PreyFilePatcher::PatchDocument(
    const fs::path& xmlFilePath,
    const fs::path& xsdRefPath,
    pugi::xml_document& doc,
    const FileMergingPolicy3& policy,
    const XmlErrorStack& parentErrorStack)
{
    pugi::xml_node node = doc.first_child();
    XmlErrorStack errorStack = parentErrorStack.GetChild(node);

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        throw std::logic_error("Localization files can't be patched");

    // Remove old XSDs
    node.remove_attribute("xmlns");
    node.remove_attribute("xmlns:ch");
    node.remove_attribute("xmlns:xsi");
    node.remove_attribute("xsi:schemaLocation");

    // Add XSD reference
    fs::path xsdRelPath = policy.GetRelPath();
    xsdRelPath.replace_extension("xsd");

    std::string xsdPreyLocation =
        !xsdRefPath.empty()
        ? (xsdRefPath / "Prey" / xsdRelPath).generic_u8string()
        : CHAIR_XML_NS_PREY + ("/" + xsdRelPath.generic_u8string());

    std::string xsdChairLocation =
        !xsdRefPath.empty()
        ? (xsdRefPath / "Chairloader" / CHAIR_XSD_META_TYPE).generic_u8string()
        : std::string(CHAIR_XML_NS_CHAIRLOADER) + "/" + CHAIR_XSD_META_TYPE;

    node.prepend_attribute("xsi:schemaLocation").set_value(fmt::format(
        "{} {} {} {}",
        CHAIR_XML_NS_PREY, xsdPreyLocation,
        CHAIR_XML_NS_CHAIRLOADER, xsdChairLocation).c_str());
    node.prepend_attribute("xmlns:xsi").set_value("http://www.w3.org/2001/XMLSchema-instance");
    node.prepend_attribute("xmlns:ch").set_value(CHAIR_XML_NS_CHAIRLOADER);
    node.prepend_attribute("xmlns").set_value(CHAIR_XML_NS_PREY);

    PatchNode(xmlFilePath, node, policy.GetRootNode(), errorStack);
}

void PreyFilePatcher::PatchDirectory(
    const fs::path& dirPath,
    const fs::path& xsdRefPath,
    const MergingLibrary3& policyLib,
    const XmlTypeLibrary* pTypeLib,
    const ProgressCallback& callback)
{
    for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(dirPath))
    {
        if (dirEnt.is_directory())
            continue;

        fs::path fullPath = dirEnt.path();
        fs::path relPath = fullPath.lexically_relative(dirPath);

        if (callback)
            callback(relPath.generic_u8string());

        // Find it in policy
        const FileMergingPolicy3* pFilePolicy = policyLib.FindPolicyForFile(relPath);
        if (!pFilePolicy)
        {
            // File not supported. Skip.
            continue;
        }

        if (pFilePolicy->GetMethod() == FileMergingPolicy3::EMethod::Replace ||
            pFilePolicy->GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
        {
            // File not merged. Skip.
            continue;
        }

        if (pFilePolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        {
            // Localization can't be patched
            continue;
        }

        // Not validating original file. It may have old patches, which will be incompatible
        // with potentially updated merging policy.

        // Patch
        auto [xmlDoc, errorStack] = XmlUtils::LoadDocumentWithStack(fullPath);
        PatchDocument(fullPath, xsdRefPath, xmlDoc, *pFilePolicy, errorStack);

        // Validate
        XmlValidator::Context context;
        context.mode = XmlValidator::EMode::MergingBase;
        context.pTypeLib = pTypeLib;

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(
            context,
            xmlDoc,
            *pFilePolicy);

        // Save
        const char* indent = "    ";
        unsigned formatFlags = pugi::format_indent | pugi::format_indent_attributes;

        if (!validationResult)
        {
            std::string validationError = validationResult.ToString("  ");
            fs::path failPath = fullPath;
            failPath.replace_extension(".fail.xml");
            xmlDoc.save_file(failPath.c_str(), indent, formatFlags);
            errorStack.ThrowException("Validation failed after patching. This is a Chairloader bug.\n" + validationError);
        }

        xmlDoc.save_file(fullPath.c_str(), indent, formatFlags);
    }
}

void PreyFilePatcher::PatchEntityIds(
    pugi::xml_node node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack,
    const std::map<int, std::string>& entityGuidMap)
{
    // Check attributes
    for (pugi::xml_attribute attr : node.attributes())
    {
        const MergingPolicy3::Attribute* policyAttr = policy.FindAttribute(attr.name());
        if (!policyAttr)
            continue;

        if (policyAttr->type != "EntityId")
            continue;

        if (boost::starts_with(attr.as_string(), "$(EntityId"))
        {
            // Already patched
            continue;
        }

        // Find entity guid
        int entityId = attr.as_int(-9999);
        if (entityId == -9999)
            errorStack.ThrowException(fmt::format("Invalid EntityId '{}'", attr.as_string()));

        if (entityId == 0)
        {
            // Null entity reference
            continue;
        }

        auto it = entityGuidMap.find(entityId);
        if (it == entityGuidMap.end())
        {
            /*
            [error] XML patching failed: Unknown EntityId '453'
              at encounterTableEntry[0]
              at encounter[2]
              at encounterProfile[2]
              at encounterRoot[7]
              at Mission
              at file Levels\Campaign\Research\Prototype\level\mission_mission0.xml
            */
            // Unknown entity id. Not an error: some Prey files actually have invalid references
            // Leave the reference as-is in such case.
            continue;
        }

        attr.set_value(fmt::format("$(EntityId:{})", it->second).c_str());
    }

    // Recurse down
    int i = 0;

    for (pugi::xml_node childNode : node.children())
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        childErrorStack.SetIndex(i);

        const MergingPolicy3* pChildPolicy = policy.FindChildNode(childNode.name());
        if (!pChildPolicy)
        {
            childErrorStack.ThrowException(fmt::format(
                "Node {} can't be a child of {} (merging policy not found)",
                childNode.name(),
                node.name()));
        }

        PatchEntityIds(childNode, *pChildPolicy, childErrorStack, entityGuidMap);

        i++;
    }
}
