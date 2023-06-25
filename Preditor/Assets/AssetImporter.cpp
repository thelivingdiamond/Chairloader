#include "AssetImporter.h"
#include "AssetsCommon.h"

Assets::AssetImporter::AssetImporter()
{
}

Assets::AssetImporter::~AssetImporter()
{
}

void Assets::AssetImporter::ImportAsset(AssetMetadata& meta)
{
    CRY_ASSERT_MESSAGE(!m_pMetadata, "AssetImporter may only be used once");
    m_pMetadata = &meta;

    Import();

    CRY_ASSERT_MESSAGE(!m_OutFiles.empty(), "Import() must call AddOutputFile");

    if (m_OutFiles.empty())
        throw std::logic_error("No output files were created");
}

void Assets::AssetImporter::AddOutputFile(const std::string relPath)
{
    std::string relPath2 = relPath;

    for (char& c : relPath2)
    {
        // Normalize slashes
        if (c == '\\')
            c = '/';
        else
            c = CharToLower(c);
    }

    m_OutFiles.emplace_back(std::move(relPath2));
}
