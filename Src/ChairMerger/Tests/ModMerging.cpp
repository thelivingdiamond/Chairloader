#include <libzippp.h>
#include <ChairMerger/MergingLibrary3.h>
#include "ChairMergerTestBase.h"
#include "XmlTestUtils.h"
#include "Cache/DiskXmlCache.h"

class ChairMergerTestProcessXMLFile
    : public ChairMergerTestBase
    , public testing::WithParamInterface<std::string>
{
};

TEST_P(ChairMergerTestProcessXMLFile, ProcessXMLFile)
{
    InitTest("ProcessXMLFile");
    LoadMods();
    CreateMerger();

    constexpr char MOD_NAME[] = "Mod1";
    fs::path relativePath = fs::u8path(GetParam());
    fs::path modDataDir = m_TestDir / MOD_NAME / "Data";
    fs::path modFilePath = modDataDir / relativePath;

    ChairMerger::Mod mod;
    mod.type = ChairMerger::EModType::Native;
    mod.modName = MOD_NAME;
    mod.dataPath = modDataDir;

    DiskXmlCache modXmlCache;
    modXmlCache.SetRootDir(mod.dataPath);

    const FileMergingPolicy3* pPolicy = m_pMerger->m_pMergingLibrary->FindPolicyForFile(relativePath);
    ASSERT_NE(nullptr, pPolicy);

    m_pMerger->m_pBaseFileCache = std::make_unique<DiskXmlCache>();
    m_pMerger->m_pBaseFileCache->SetRootDir(m_pMerger->m_PreyFilesPath);
    m_pMerger->ProcessXMLFile(mod, &modXmlCache, relativePath, *pPolicy);
    m_pMerger->m_pBaseFileCache->ExportModifiedFiles(m_pMerger->m_OutputPath);

    pugi::xml_document docOutput = XmlUtils::LoadDocument(m_TempDir / "Output" / relativePath);
    pugi::xml_document docExpected = XmlUtils::LoadDocument(m_TestDir / "Expected" / relativePath);

    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(docExpected, docOutput));
}

const auto TEST_FILES = testing::Values<std::string>(
    "Ark/ArkFactions.xml",
    "Ark/Player/PlayerConfig.xml"
);

INSTANTIATE_TEST_SUITE_P(ChairMerger, ChairMergerTestProcessXMLFile, TEST_FILES);

TEST_F(ChairMergerTestBase, CopyModDataFiles)
{
    InitTest("CopyModDataFiles");
    LoadMods();
    CreateMerger();

    constexpr char MOD_NAME[] = "Mod1";
    fs::path modDataDir = m_TestDir / MOD_NAME / "Data";
    m_pMerger->CopyModDataFiles(modDataDir);
    m_pMerger->m_MergeThreadPool->wait();

    EXPECT_TRUE(CheckEqualDirectories(m_TestDir / "Expected", m_TempDir / "Output", true));
}

class ChairMergerTestFullMerging
    : public ChairMergerTestBase
    , public testing::WithParamInterface<std::string>
{
protected:
    bool CheckPak(const fs::path& expectedFiles, const fs::path& pakPath)
    {
        if (!fs::exists(pakPath))
        {
            ADD_FAILURE() << "CheckPak: pak is missing: " << pakPath.u8string();
            return false;
        }

        fs::path pakExtractDir = pakPath;
        pakExtractDir.replace_extension();
        fs::create_directory(pakExtractDir);

        // Open the pak
        libzippp::ZipArchive archive(pakPath.string());
        if (!archive.open(libzippp::ZipArchive::ReadOnly))
        {
            ADD_FAILURE() << "archive.open failed";
            return false;
        }
        
        // Extract the pak
        std::vector<libzippp::ZipEntry> entries = archive.getEntries();
        for (auto& entry : entries)
        {
            if (entry.isDirectory())
                continue;

            fs::path outFilePath = pakExtractDir / fs::u8path(entry.getName());
            fs::create_directories(outFilePath.parent_path());

            std::ofstream outFile;
            outFile.exceptions(std::ios::failbit | std::ios::badbit);
            outFile.open(outFilePath, std::ios::binary);
            if (entry.readContent(outFile) != LIBZIPPP_OK)
            {
                ADD_FAILURE() << "entry.readContent failed";
                return false;
            }
        }

        // Validate
        return CheckEqualDirectories(expectedFiles, pakExtractDir, true);
    }
};

TEST_P(ChairMergerTestFullMerging, FullTest)
{
    InitTest(GetParam());
    LoadMods();
    CreateMerger();

    m_pMerger->Deploy();

    ASSERT_FALSE(m_pMerger->DeployFailed()) << "Deploy failed: " << m_pMerger->GetDeployFailedMessage();

    fs::path expectedDir = m_TestDir / "Expected";
    fs::path mainExpectedDir = expectedDir / "Main";
    fs::path levelsExpectedDir = expectedDir / "Levels";
    fs::path localizationExpectedDir = expectedDir / "Localization";
    
    // Main
    if (fs::exists(mainExpectedDir))
    {
        EXPECT_TRUE(CheckPak(mainExpectedDir, m_GameDir / "GameSDK/Precache/patch_chairloader.pak"))
            << "Main patch pak is incorrect";
    }

    // Levels
    if (fs::exists(levelsExpectedDir))
    {
        for (const fs::directory_entry& i : fs::recursive_directory_iterator(levelsExpectedDir))
        {
            fs::path curPath = i.path();

            if (!i.is_directory() || curPath.filename() != "level")
                continue;

            fs::path relativePath = curPath.lexically_relative(levelsExpectedDir);
            relativePath.replace_extension("pak");
            EXPECT_TRUE(CheckPak(curPath, m_GameDir / "GameSDK/Levels" / relativePath))
                << "Level patch pak is incorrect: " << relativePath.u8string();
        }
    }

    // Localization
    if (fs::exists(localizationExpectedDir))
    {
        for (const fs::directory_entry& i : fs::directory_iterator(localizationExpectedDir))
        {
            fs::path pakName = i.path().filename();
            pakName.replace_extension("pak");
            EXPECT_TRUE(CheckPak(i.path(), m_GameDir / "Localization" / pakName))
                << "Localization patch pak is incorrect: " << pakName.u8string();
        }
    }

    // TODO 2023-12-31: Check that paks were not created if there are no files
}

const auto FULL_TEST_NAMES = testing::Values<std::string>(
    "FullTestMain",
    "FullTestLocalization",
    "FullTestLevels",
    "FullTestEverything"
);

INSTANTIATE_TEST_SUITE_P(ChairMerger, ChairMergerTestFullMerging, FULL_TEST_NAMES);
