#include <SHA256/SHA256.h>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlValidator.h>

static char nibbleToHex(uint8_t val)
{
    return val >= 0xA ? (val + 'A' - 0xA) : (val + '0');
}

static uint8_t hexToNibble(char c)
{
    return c >= 'A' ? (c - 'A' + 0xA) : (c - '0');
}

void PreyFilePatcher::PatchNode(
    pugi::xml_node node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
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
                std::string hashString;

                for (const std::string& hashAttrName : patches.addEntityGuidHash)
                {
                    hashString += childNode.attribute(hashAttrName.c_str()).as_string();
                    hashString += '|';
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
                    guid[guid.size() - 1] = nibbleToHex(val + 1);
                }

                generatedGuids.insert(guid);
                guidAttr.set_value(guid.c_str());
            }
        }
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

        PatchNode(childNode, *pChildPolicy, childErrorStack);

        i++;
    }
}

void PreyFilePatcher::PatchDocument(
    pugi::xml_document& doc,
    const FileMergingPolicy3& policy,
    const XmlErrorStack& parentErrorStack)
{
    pugi::xml_node node = doc.first_child();
    XmlErrorStack errorStack = parentErrorStack.GetChild(node);
    PatchNode(node, policy.GetRootNode(), errorStack);
}

void PreyFilePatcher::PatchDirectory(
    const fs::path& dirPath,
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

        // Not validating original file. It may have old patches, which will be incompatible
        // with potentially updated merging policy.

        // Patch
        auto [xmlDoc, errorStack] = XmlUtils::LoadDocumentWithStack(fullPath);
        PatchDocument(xmlDoc, *pFilePolicy, errorStack);

        // Validate
        XmlValidator::Context context;
        context.nodeType = XmlValidator::ENodeType::MergingBase;
        context.pTypeLib = pTypeLib;

        XmlValidator::Result validationResult = XmlValidator::ValidateNode(
            context,
            xmlDoc.first_child(),
            pFilePolicy->GetRootNode());

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