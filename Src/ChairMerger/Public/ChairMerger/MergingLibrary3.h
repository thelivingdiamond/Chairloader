#pragma once
#include <ChairMerger/Export.h>
#include <ChairMerger/MergingPolicy3.h>

class XmlErrorStack;
class XmlTypeLibrary;

class CHAIRMERGER_EXPORT MergingLibrary3 : boost::noncopyable
{
public:
    MergingLibrary3(XmlTypeLibrary* pTypeLib);
    ~MergingLibrary3();

    //! Loads merging library from a file or directory.
    void LoadFromPath(const fs::path& path);

    //! Loads merging library from a file.
    void LoadFromFile(const fs::path& path);

    //! Loads merging library from a directory.
    void LoadFromDir(const fs::path& path);

    //! Finds the policy for the specified file.
    //! @returns Policy or nullptr if not found.
    const FileMergingPolicy3* FindPolicyForFile(const fs::path& relPath) const;

private:
    XmlTypeLibrary* m_pTypeLib = nullptr;
    std::map<std::string, FileMergingPolicy3Ptr, std::less<>> m_FileMergingPolicy;
    std::map<std::string, std::vector<FileMergingPolicy3Ptr>, std::less<>> m_DirMergingPolicy;

    void AddFile(const fs::path& filePath, const fs::path& relPath);
    void AddNode(const pugi::xml_node& node, const XmlErrorStack& errorStack, const fs::path& relPath);

    static void CheckFileExists(const fs::path& path);
    static void CheckPathRelative(const fs::path& path);
    static std::string NormalizePath(const std::string_view s);
};