#include "Tests/Merging/ChairMergerTestBase.h"
#include "Tests/XmlTestUtils.h"

class ChairMergerTestFile
    : public ChairMergerTestBase
    , public testing::WithParamInterface<std::string>
{
};

TEST_P(ChairMergerTestFile, ProcessXMLFile)
{
    InitTest("ProcessXMLFile");
    LoadMods();
    CreateMerger();

    constexpr char MOD_NAME[] = "Mod1";
    fs::path relativePath = fs::u8path(GetParam());
    fs::path modDataDir = m_TestDir / MOD_NAME / "Data";
    fs::path modFilePath = modDataDir / relativePath;

    m_pMerger->ProcessXMLFile(modFilePath, modDataDir, MOD_NAME, false);

    pugi::xml_document docOutput = XmlTestUtils::LoadDocument(m_TempDir / "Output" / relativePath);
    pugi::xml_document docExpected = XmlTestUtils::LoadDocument(m_TestDir / "Expected" / relativePath);

    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(docExpected, docOutput));
}

const auto TEST_FILES = testing::Values<std::string>(
    "Ark/ArkFactions.xml",
    "Ark/Player/PlayerConfig.xml"
);

INSTANTIATE_TEST_SUITE_P(ChairMerger, ChairMergerTestFile, TEST_FILES);

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
