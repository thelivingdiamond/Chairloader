#pragma once
#include <ChairMerger/Export.h>

class MergingPolicy3;
class FileMergingPolicy3;
class MergingLibrary3;
class XmlErrorStack;
class XmlTypeLibrary;

//! Patches original prey files for merging support.
//! Only adds new stuff, never removes original data.
//! Must be able to run on an already patched file (even by an older patcher version)
//! and convert it into a properly patched version.
class CHAIRMERGER_EXPORT PreyFilePatcher
{
public:
    using ProgressCallback = std::function<void(const std::string& fileName)>;

    //! Patches a node recursively using the policy.
    static void PatchNode(
        const fs::path& xmlFilePath,
        pugi::xml_node node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    //! Patches an XML document using the merging policy.
    static void PatchDocument(
        const fs::path& xmlFilePath,
        const fs::path& xsdRefPath,
        pugi::xml_document& doc,
        const FileMergingPolicy3& policy,
        const XmlErrorStack& parentErrorStack);

    //! Patches a directory using the policy. Calls the callback for each file.
    static void PatchDirectory(
        const fs::path& dirPath,
        const fs::path& xsdRefPath,
        const MergingLibrary3& policyLib,
        const XmlTypeLibrary* pTypeLib,
        const ProgressCallback& callback);

private:
    static void PatchEntityIds(
        pugi::xml_node node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack,
        const std::map<int, std::string>& entityGuidMap);
};
