#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingLibrary3.h>

MergingLibrary3::MergingLibrary3(XmlTypeLibrary* pTypeLib)
{
    m_pTypeLib = pTypeLib;
}

MergingLibrary3::~MergingLibrary3()
{
}

void MergingLibrary3::LoadFromPath(const fs::path& path)
{
    CheckFileExists(path);

    if (fs::is_directory(path))
        LoadFromDir(path);
    else
        LoadFromFile(path);
}

void MergingLibrary3::LoadFromFile(const fs::path& path)
{
    throw std::logic_error("Not implemented");
}

void MergingLibrary3::LoadFromDir(const fs::path& path)
{
    CheckFileExists(path);

    if (!fs::is_directory(path))
        throw std::logic_error(fmt::format("Not a directory: {}", path.u8string()));

    for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(path))
    {
        if (dirEnt.is_directory())
            continue;

        fs::path relPath = dirEnt.path().lexically_relative(path);
        AddFile(dirEnt.path(), relPath);
    }
}

const FileMergingPolicy3* MergingLibrary3::FindPolicyForFile(const fs::path& relPath) const
{
    CheckPathRelative(relPath);
    std::string relPathNorm = NormalizePath(relPath.u8string());

    // Find exact match
    auto itExact = m_FileMergingPolicy.find(relPathNorm);

    if (itExact != m_FileMergingPolicy.end())
    {
        CRY_ASSERT(!itExact->second->IsRegexName());
        return itExact->second.get();
    }

    // Find match via directory name
    bool isDirectParent = true;

    for (fs::path dirPath = relPath.parent_path(); dirPath.has_parent_path(); dirPath = dirPath.parent_path())
    {
        std::string dirPathStr = NormalizePath(dirPath.u8string());
        auto itDir = m_DirMergingPolicy.find(dirPathStr);

        if (itDir != m_DirMergingPolicy.end())
        {
            std::string relPathInDir = NormalizePath(relPath.lexically_relative(dirPath).u8string());

            for (const FileMergingPolicy3Ptr& policy : itDir->second)
            {
                CRY_ASSERT(policy->IsRegexName());

                if (!isDirectParent && !policy->IsRecursive())
                    continue;

                if (policy->MatchFileName(relPathInDir))
                    return policy.get();
            }
        }

        isDirectParent = false;
    }

    return nullptr;
}

void MergingLibrary3::AddFile(const fs::path& filePath, const fs::path& relPath)
{
    auto [document, errorStack] = XmlUtils::LoadDocumentWithStack(filePath);
    AddNode(document.first_child(), errorStack, relPath);
}

void MergingLibrary3::AddNode(const pugi::xml_node& node, const XmlErrorStack& errorStack, const fs::path& relPath)
{
    CheckPathRelative(relPath);
    FileMergingPolicy3Ptr filePolicy = std::make_unique<FileMergingPolicy3>();
    filePolicy->LoadXmlNode(m_pTypeLib, node, errorStack);


    if (filePolicy->IsRegexName())
    {
        std::string relPathNorm = NormalizePath(relPath.parent_path().u8string());
        auto& policyList = m_DirMergingPolicy[relPathNorm];
        policyList.push_back(std::move(filePolicy));
    }
    else
    {
        std::string relPathNorm = NormalizePath(relPath.u8string());
        auto it = m_FileMergingPolicy.find(relPathNorm);

        if (it != m_FileMergingPolicy.end())
            errorStack.ThrowException(fmt::format("Duplicate path '{}'", relPathNorm));

        m_FileMergingPolicy.emplace(relPathNorm, std::move(filePolicy));
    }
}

void MergingLibrary3::CheckFileExists(const fs::path& path)
{
    if (!fs::exists(path))
        throw std::logic_error(fmt::format("Path doesn't exist: {}", path.u8string()));
}

void MergingLibrary3::CheckPathRelative(const fs::path& path)
{
    if (!path.is_relative() || path.is_absolute())
        throw std::logic_error(fmt::format("Path is not relative: {}", path.u8string()));
}

std::string MergingLibrary3::NormalizePath(const std::string_view s)
{
    std::string out;
    out.resize(s.size());

    for (size_t i = 0; i < out.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            out[i] = s[i] - 'A' + 'a';
        else if (s[i] == '\\')
            out[i] = '/';
        else
            out[i] = s[i];
    }

    return out;
}
