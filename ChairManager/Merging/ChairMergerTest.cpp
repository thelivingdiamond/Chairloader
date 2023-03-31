//
// Created by theli on 3/28/2023.
//

#include "ChairMerger.h"
#include "ChairManager.h"
#include <gtest/gtest.h>


class ChairMergerTest : public ::testing::Test {
public:
    void SetUp() override {
        manager = std::make_unique<ChairManager>();
        manager->GTestInit();
        for(auto& mod : manager->GetMods()){
            if(mod.modName == "TheChair.ExampleMod"){
                exampleMod = std::make_shared<Mod>(mod);
                break;
            }
        }
        // remove contents of the output directory
        fs::remove_all(merger->m_OutputPath);
        fs::create_directories(merger->m_OutputPath);
        merger = std::make_unique<ChairMerger>();
        merger->m_ModPath = "Testing/Mods";
        merger->m_OutputPath = "Testing/Output";
        merger->m_PreyFilePath = "Testing/PreyFiles";
    }

    void TearDown() override {
        manager.reset();
        merger.reset();
    }
protected:
    std::unique_ptr<ChairManager> manager;
    std::unique_ptr<ChairMerger> merger;
    std::shared_ptr<Mod> exampleMod;

    bool ProcessXMLFile(fs::path relativePath){
        merger->ProcessXMLFile("Testing/Mods/TheChair.ExampleMod/Data" / relativePath, exampleMod->modName, false);
        pugi::xml_document outputFile, expectedFile;
        outputFile.load_file(("Testing/Output" /relativePath).wstring().c_str());
        expectedFile.load_file(("Testing/Expected"/relativePath).wstring().c_str());
        return TestXmlFileEquality(outputFile, expectedFile);
    }

    bool TestXmlFileEquality(pugi::xml_document& outputDoc, pugi::xml_document& expectedDoc){
        std::stringstream output, expected;
        outputDoc.save(output, "", pugi::format_raw);
        expectedDoc.save(expected, "", pugi::format_raw);
        return output.str() == expected.str();
    }

    // this function needs to recursively traverse Output/ and Expected/ and compare the files using TestXmlFileEquality, the files are already processed so do not use ProcessXMLFile
    bool RecursiveOutputEquivalenceCheck(fs::path relativePath){
        fs::path outputPath = "Testing/Output" / relativePath;
        fs::path expectedPath = "Testing/Expected" / relativePath;
        // check against all output files, this only checks that any files that are in the output directory are equivalent to the expected files
        // this does not check that all expected files are in the output directory
        if(fs::is_directory(outputPath)){
            for(auto& entry : fs::directory_iterator(outputPath)){
                if(!RecursiveOutputEquivalenceCheck(relativePath / entry.path().filename())){
                    return false;
                }
            }
        } else if(outputPath.extension() == ".xml"){
            pugi::xml_document outputFile, expectedFile;
            outputFile.load_file(outputPath.wstring().c_str());
            expectedFile.load_file(expectedPath.wstring().c_str());
            bool equal = TestXmlFileEquality(outputFile, expectedFile);
            if(!equal){
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        } else if(fs::is_regular_file(outputPath)) {
            bool equal = fs::exists(outputPath);
            if(!equal){
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        return true;
    }
    bool RecursiveOutputAbsoluteCheck(fs::path relativePath){
        fs::path outputPath = "Testing/Output" / relativePath;
        fs::path expectedPath = "Testing/Expected" / relativePath;
        // check against all the files in the expected directory, this ensures that no files are missing
        if(fs::is_directory(expectedPath)){
            for(auto& entry : fs::directory_iterator(expectedPath)){
                if(!RecursiveOutputAbsoluteCheck(relativePath / entry.path().filename())){
                    return false;
                }
            }
        } else if(expectedPath.extension() == ".xml"){
            pugi::xml_document outputFile, expectedFile;
            outputFile.load_file(outputPath.wstring().c_str());
            expectedFile.load_file(expectedPath.wstring().c_str());
            bool equal = TestXmlFileEquality(outputFile, expectedFile);
            if(!equal){
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        } else if(fs::is_regular_file(outputPath)) {
            bool equal = fs::exists(outputPath);
            if(!equal){
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        return true;
    }
};

TEST_F(ChairMergerTest, ResolveFileWildcardSingleNode) {
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(<X ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}" />)");
    ASSERT_TRUE(exampleMod != nullptr);
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod);
    EXPECT_TRUE(doc.first_child().attribute("ch:apply_if").value() == std::string("1"));
    EXPECT_TRUE(doc.first_child().attribute("absolute_unit").value() == std::string("The quick brown fox fuckin jumped over the lazy dog"));
}

TEST_F(ChairMergerTest, ResolveFileWildcardMultipleNodes) {
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(
        <X ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}">
            <Y ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}">
                <Z ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}"/>
                <Z2 ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}"/>
            </Y>
        </X>
    )");
    ASSERT_TRUE(exampleMod != nullptr);
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod);
    EXPECT_TRUE(doc.first_child().attribute("ch:apply_if").value() == std::string("1"));
    EXPECT_TRUE(doc.first_child().attribute("absolute_unit").value() == std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto y = doc.first_child().child("Y");
    EXPECT_TRUE(y.attribute("ch:apply_if").value() == std::string("1"));
    EXPECT_TRUE(y.attribute("absolute_unit").value() == std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto z = y.child("Z");
    EXPECT_TRUE(z.attribute("ch:apply_if").value() == std::string("1"));
    EXPECT_TRUE(z.attribute("absolute_unit").value() == std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto z2 = y.child("Z2");
    EXPECT_TRUE(z2.attribute("ch:apply_if").value() == std::string("1"));
    EXPECT_TRUE(z2.attribute("absolute_unit").value() == std::string("The quick brown fox fuckin jumped over the lazy dog"));
}


TEST_F(ChairMergerTest, GetAttributeWildcardValue) {
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(<X ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}" />)");
    wildcard->attribute = doc.child("X").attribute("ch:apply_if");
    EXPECT_TRUE(ChairMerger::GetAttributeWildcardValue(wildcard));
    EXPECT_TRUE(wildcard->match_value == "1");
    wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    wildcard->attribute = doc.child("X").attribute("absolute_unit");
    EXPECT_TRUE(ChairMerger::GetAttributeWildcardValue(wildcard));
    EXPECT_TRUE(wildcard->match_value == "The quick brown fox fuckin jumped over the lazy dog");
}




TEST_F(ChairMergerTest, ProcessXMLFileArkFactions){
    fs::path relativePath = "Ark/ArkFactions.xml";
    std::stringstream output, expected;
    EXPECT_TRUE(ProcessXMLFile(relativePath));
}

TEST_F(ChairMergerTest, ProcessXMLFilePlayerConfig){
    fs::path relativePath = "Ark/Player/PlayerConfig.xml";

    std::stringstream output, expected;
    EXPECT_TRUE(ProcessXMLFile(relativePath));
}

TEST_F(ChairMergerTest, CopyModDataFiles){
    fs::path dataPath = ChairMerger::m_ModPath / exampleMod->modName / "Data";
    merger->CopyModDataFiles(dataPath, exampleMod->modName);
    merger->m_MergeThreadPool->wait();

    EXPECT_TRUE(RecursiveOutputEquivalenceCheck(""));
}

TEST_F(ChairMergerTest, RecursiveXmlMerge){
    merger->RecursiveMergeXMLFiles("Testing/Mods/TheChair.ExampleMod/Data", exampleMod->modName, false);
    merger->m_MergeThreadPool->wait();

    EXPECT_TRUE(RecursiveOutputEquivalenceCheck(""));
}

TEST_F(ChairMergerTest, ProcessExampleMod){
    merger->ProcessMod(exampleMod);
    // wait for the threadpool to finish all its tasks
    merger->m_MergeThreadPool->wait();
    EXPECT_TRUE(RecursiveOutputAbsoluteCheck(""));
}

TEST_F(ChairMergerTest, IsLevelFile){
    fs::path modPath = ChairMerger::m_ModPath / exampleMod->modName / "Data";
    fs::path testPath = modPath / "Ark" / "ArkFactions.xml";
    EXPECT_FALSE(ChairMerger::IsLevelFile(testPath, exampleMod->modName));
    testPath = modPath / "Ark" / "Player" / "PlayerConfig.xml";
    EXPECT_FALSE(ChairMerger::IsLevelFile(testPath, exampleMod->modName));
    EXPECT_FALSE(merger->m_LevelFilesChanged);
    testPath = modPath / "Levels" / "Campaign" / "Research" / "Lobby" / "level" / "mission_mission0.xml";
    EXPECT_TRUE(ChairMerger::IsLevelFile(testPath, exampleMod->modName));
    testPath = modPath / "Levels" / "Campaign" / "Research" / "Lobby" / "level" / "shaderslist.txt";
    EXPECT_TRUE(ChairMerger::IsLevelFile(testPath, exampleMod->modName));
    EXPECT_TRUE(merger->m_LevelFilesChanged);
}



