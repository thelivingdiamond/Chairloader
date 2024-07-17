#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlValidator.h>

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

        if (!validationResult)
        {
            std::string validationError = validationResult.ToString("  ");
            errorStack.ThrowException("Validation failed after patching. This is a Chairloader bug.\n" + validationError);
        }

        // Save
        const char* indent = "    ";
        unsigned formatFlags = pugi::format_indent | pugi::format_indent_attributes;
        xmlDoc.save_file(fullPath.c_str(), indent, formatFlags);
    }
}
