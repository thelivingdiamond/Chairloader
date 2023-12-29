//
// Created by theli on 3/28/2023.
//

#include "ChairMerger.h"
#include "ChairManager.h"
#include <gtest/gtest.h>
#include <chrono>
#include <Manager/LuaUtils.h>

class ChairMergerTest : public ::testing::Test
{
  public:
    void SetUp() override
    {
        manager = std::make_unique<ChairManager>();
        manager->GTestInit();
        for (auto& mod : manager->GetMods())
        {
            if (mod.modName == "TheChair.ExampleMod")
            {
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

    void TearDown() override
    {
        manager.reset();
        merger.reset();
    }

  protected:
    std::unique_ptr<ChairManager> manager;
    std::unique_ptr<ChairMerger> merger;
    std::shared_ptr<Mod> exampleMod;

    bool ProcessXMLFile(fs::path relativePath)
    {
        merger->ProcessXMLFile("Testing/Mods/TheChair.ExampleMod/Data" / relativePath, exampleMod->modName, false);
        pugi::xml_document outputFile, expectedFile;
        outputFile.load_file(("Testing/Output" / relativePath).wstring().c_str());
        expectedFile.load_file(("Testing/Expected" / relativePath).wstring().c_str());
        return TestXmlFileEquality(outputFile, expectedFile);
    }

    bool TestXmlFileEquality(pugi::xml_document& outputDoc, pugi::xml_document& expectedDoc)
    {
        std::stringstream output, expected;
        outputDoc.save(output, "", pugi::format_raw);
        expectedDoc.save(expected, "", pugi::format_raw);
        return output.str() == expected.str();
    }

    // this function needs to recursively traverse Output/ and Expected/ and compare the files using
    // TestXmlFileEquality, the files are already processed so do not use ProcessXMLFile
    bool RecursiveOutputEquivalenceCheck(fs::path relativePath)
    {
        fs::path outputPath = "Testing/Output" / relativePath;
        fs::path expectedPath = "Testing/Expected" / relativePath;
        // check against all output files, this only checks that any files that are in the output directory are
        // equivalent to the expected files this does not check that all expected files are in the output directory
        if (fs::is_directory(outputPath))
        {
            for (auto& entry : fs::directory_iterator(outputPath))
            {
                if (!RecursiveOutputEquivalenceCheck(relativePath / entry.path().filename()))
                {
                    return false;
                }
            }
        }
        else if (outputPath.extension() == ".xml")
        {
            pugi::xml_document outputFile, expectedFile;
            outputFile.load_file(outputPath.wstring().c_str());
            expectedFile.load_file(expectedPath.wstring().c_str());
            bool equal = TestXmlFileEquality(outputFile, expectedFile);
            if (!equal)
            {
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        else if (fs::is_regular_file(outputPath))
        {
            bool equal = fs::exists(outputPath);
            if (!equal)
            {
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        return true;
    }
    bool RecursiveOutputAbsoluteCheck(fs::path relativePath)
    {
        fs::path outputPath = "Testing/Output" / relativePath;
        fs::path expectedPath = "Testing/Expected" / relativePath;
        // check against all the files in the expected directory, this ensures that no files are missing
        if (fs::is_directory(expectedPath))
        {
            for (auto& entry : fs::directory_iterator(expectedPath))
            {
                if (!RecursiveOutputAbsoluteCheck(relativePath / entry.path().filename()))
                {
                    return false;
                }
            }
        }
        else if (expectedPath.extension() == ".xml")
        {
            pugi::xml_document outputFile, expectedFile;
            outputFile.load_file(outputPath.wstring().c_str());
            expectedFile.load_file(expectedPath.wstring().c_str());
            bool equal = TestXmlFileEquality(outputFile, expectedFile);
            if (!equal)
            {
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        else if (fs::is_regular_file(outputPath))
        {
            bool equal = fs::exists(outputPath);
            if (!equal)
            {
                printf("Failed to find equivalent file for %s\n", expectedPath.string().c_str());
            }
            return equal;
        }
        return true;
    }
};

TEST_F(ChairMergerTest, ResolveFileWildcardSingleNode)
{
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(<X ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}" />)");
    ASSERT_TRUE(exampleMod != nullptr);
    // profile this function, it is slow
    auto start = std::chrono::high_resolution_clock::now();
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod->modName);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of microseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // print the time it took to run
    printf("ResolveFileWildcards took %lld microseconds\n", duration.count());
    EXPECT_EQ(doc.first_child().attribute("ch:apply_if").as_bool(), true);
    EXPECT_EQ(doc.first_child().attribute("absolute_unit").value(),
              std::string("The quick brown fox fuckin jumped over the lazy dog"));
}

TEST_F(ChairMergerTest, ResolveFileWildcardMultipleNodes)
{
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
    //    auto variables = ChairManager::Get().GetConfigManager()->getModSpaceBooleanVariables("TheChair.ExampleMod");
    // profile this function, it is slow
    auto start = std::chrono::high_resolution_clock::now();
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod->modName);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of microseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // print the time it took to run
    printf("ResolveFileWildcards took %lld microseconds\n", duration.count());
    EXPECT_TRUE(doc.first_child().attribute("ch:apply_if").value() == std::string("true"));
    EXPECT_TRUE(doc.first_child().attribute("absolute_unit").value() ==
                std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto y = doc.first_child().child("Y");
    EXPECT_TRUE(y.attribute("ch:apply_if").value() == std::string("true"));
    EXPECT_TRUE(y.attribute("absolute_unit").value() ==
                std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto z = y.child("Z");
    EXPECT_TRUE(z.attribute("ch:apply_if").value() == std::string("true"));
    EXPECT_TRUE(z.attribute("absolute_unit").value() ==
                std::string("The quick brown fox fuckin jumped over the lazy dog"));
    auto z2 = y.child("Z2");
    EXPECT_TRUE(z2.attribute("ch:apply_if").value() == std::string("true"));
    EXPECT_TRUE(z2.attribute("absolute_unit").value() ==
                std::string("The quick brown fox fuckin jumped over the lazy dog"));
}

TEST_F(ChairMergerTest, LuaAttributeResolution)
{
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(
        <X ch:apply_if="{{ testInt < testUInt }}" absolute_unit="{{ testEnum }}">
            <Y ch:apply_if="{{ testXMLNode.node1 == 'IDK put whatever tf you want here' }}" absolute_unit="{{ G.TheChair.ExampleMod.testXMLNode.node2 }}"/>
        </X>
    )");
    ASSERT_TRUE(exampleMod != nullptr);

    auto start = std::chrono::high_resolution_clock::now();
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod->modName);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of microseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // print the time it took to run
    printf("ResolveFileWildcards took %lld microseconds\n", duration.count());

    EXPECT_EQ(doc.first_child().attribute("ch:apply_if").as_bool(), true);
    EXPECT_EQ(doc.first_child().attribute("absolute_unit").value(), std::string("B"));
    auto y = doc.first_child().child("Y");
    EXPECT_EQ(y.attribute("ch:apply_if").as_bool(), true);
    EXPECT_EQ(y.attribute("absolute_unit").value(), std::string("OUG"));
}

TEST_F(ChairMergerTest, LuaGlobalFail)
{
    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(
        <X ch:apply_if="{{ testInt == testUInt }}" absolute_unit="{{ testEnum }}" enum_table="{{testEnum_enum['option'..tostring(0)]}}">
            <Y ch:apply_if="{{ testXMLNode.node1 == 'IDK put whatever tf you want here' }}" absolute_unit="{{ G.TheChair.ExampleMod.testXMLNode.node2 }}" test="{{IsModEnabled('TheChair.ExampleMod')}}"/>
            <Z random_enum_test="{{testEnum_enum['option'..tostring(Random(0,2))]}}" lltest="{{testInt64}}" ulltest="{{testUInt64}}"/>
        </X>
    )");
    ASSERT_TRUE(exampleMod != nullptr);

    auto start = std::chrono::high_resolution_clock::now();
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod->modName);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of microseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // print the time it took to run
    printf("ResolveFileWildcards took %lld microseconds\n", duration.count());

    EXPECT_EQ(doc.first_child().attribute("ch:apply_if").as_string(), std::string("false"));
    EXPECT_EQ(doc.first_child().attribute("absolute_unit").value(), std::string("B"));
    EXPECT_EQ(doc.first_child().attribute("enum_table").value(), std::string("A"));
    auto y = doc.first_child().child("Y");
    EXPECT_EQ(y.attribute("ch:apply_if").as_bool(), true);
    EXPECT_EQ(y.attribute("absolute_unit").value(), std::string("OUG"));
    EXPECT_EQ(y.attribute("test").as_bool(), true);
    auto z = doc.first_child().child("Z");
    std::string random_enum_test = z.attribute("random_enum_test").value();
    EXPECT_TRUE(random_enum_test == "B" || random_enum_test == "A" || random_enum_test == "C");
    EXPECT_EQ(z.attribute("lltest").value(), std::string("-6942000000000000"));
    EXPECT_EQ(z.attribute("ulltest").value(), std::string("18446744073709551615"));
    printf("random_enum_test: %s\n", random_enum_test.c_str());
}

TEST_F(ChairMergerTest, LuaRandomTest)
{
    // start by testing the randomfloat function
    auto f = ChairMerger::RandomFloat(1.5, 3.5);
    ASSERT_TRUE(f >= 1.5 && f <= 3.5);

    auto wildcard = std::make_shared<AttributeWildcard>();
    wildcard->mod_name = "TheChair.ExampleMod";
    pugi::xml_document doc;
    doc.load_string(R"(
        <X random1="{{Random(1,10)}}" random2="{{Random(20,40)}}" random3="{{ RandomFloat(1.5, 3.5) }}" />
    )");
    ASSERT_TRUE(exampleMod != nullptr);

    auto start = std::chrono::high_resolution_clock::now();
    ChairMerger::ResolveFileWildcards(doc.first_child(), exampleMod->modName);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of microseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    // print the time it took to run
    printf("ResolveFileWildcards took %lld microseconds\n", duration.count());

    EXPECT_TRUE(doc.first_child().attribute("random1").as_int() <= 10 &&
                doc.first_child().attribute("random1").as_int() >= 1);
    EXPECT_TRUE(doc.first_child().attribute("random2").as_int() <= 40 &&
                doc.first_child().attribute("random2").as_int() >= 20);
    EXPECT_TRUE(doc.first_child().attribute("random3").as_float() <= 3.5f &&
                doc.first_child().attribute("random3").as_float() >= 1.5f);
}

// TEST_F(ChairMergerTest, GetAttributeWildcardValue) {
//     auto wildcard = std::make_shared<AttributeWildcard>();
//     wildcard->mod_name = "TheChair.ExampleMod";
//     auto variables = ChairManager::Get().GetConfigManager()->getModSpaceBooleanVariables("TheChair.ExampleMod");
//     pugi::xml_document doc;
//     doc.load_string(R"(<X ch:apply_if="{{ testBool }}" absolute_unit="{{ testString }}" />)");
//     wildcard->attribute = doc.child("X").attribute("ch:apply_if");
//     EXPECT_TRUE(ChairMerger::GetAttributeWildcardValue(wildcard, variables));
//     EXPECT_TRUE(wildcard->match_value == "true");
//     wildcard = std::make_shared<AttributeWildcard>();
//     wildcard->mod_name = "TheChair.ExampleMod";
//     wildcard->attribute = doc.child("X").attribute("absolute_unit");
//     EXPECT_TRUE(ChairMerger::GetAttributeWildcardValue(wildcard, variables));
//     EXPECT_TRUE(wildcard->match_value == "The quick brown fox fuckin jumped over the lazy dog");
// }

TEST_F(ChairMergerTest, ProcessXMLFileArkFactions)
{
    fs::path relativePath = "Ark/ArkFactions.xml";
    std::stringstream output, expected;
    EXPECT_TRUE(ProcessXMLFile(relativePath));
}

TEST_F(ChairMergerTest, ProcessXMLFilePlayerConfig)
{
    fs::path relativePath = "Ark/Player/PlayerConfig.xml";

    std::stringstream output, expected;
    EXPECT_TRUE(ProcessXMLFile(relativePath));
}

TEST_F(ChairMergerTest, CopyModDataFiles)
{
    fs::path dataPath = ChairMerger::m_ModPath / exampleMod->modName / "Data";
    merger->CopyModDataFiles(dataPath);
    merger->m_MergeThreadPool->wait();

    EXPECT_TRUE(RecursiveOutputEquivalenceCheck(""));
}

TEST_F(ChairMergerTest, RecursiveXmlMerge)
{
    merger->RecursiveMergeXMLFiles("Testing/Mods/TheChair.ExampleMod/Data", exampleMod->modName, false);
    merger->m_MergeThreadPool->wait();

    EXPECT_TRUE(RecursiveOutputEquivalenceCheck(""));
}

TEST_F(ChairMergerTest, ProcessExampleMod)
{
    merger->ProcessMod(exampleMod);
    // wait for the threadpool to finish all its tasks
    merger->m_MergeThreadPool->wait();
    EXPECT_TRUE(RecursiveOutputAbsoluteCheck(""));
}

TEST_F(ChairMergerTest, LoadPatchChecksums)
{
    merger->LoadPatchFileChecksums();
    EXPECT_TRUE(merger->m_LevelFileChecksums.size() > 0);
    EXPECT_TRUE(merger->m_LocalizationFileChecksums.size() > 0);
}

// FIXME 2023-07-07: Moved to class NameToIdMap
#if 0
TEST_F(ChairMergerTest, LoadIdNamePairs){
    pugi::xml_document doc;
    std::string docString = R"(
        <X>
            <X2>
                <Y id="1" name="test1" />
                <Y id="2" name="test2" />
                <Y id="3" name="test3" />
            </X2>
        </X>
    )";
    auto result = doc.load_string(docString.c_str());
    ASSERT_TRUE(result);

    std::map<std::string, uint64_t> expectedPairs = {
        {"test1", 1},
        {"test2", 2},
        {"test3", 3}
    };

    auto pairs = merger->LoadIdNamePairsFromXml(doc.root(), "X/X2", "name", "id");
    EXPECT_TRUE(pairs.size() == 3);
    for(auto & pair : pairs){
        EXPECT_TRUE(expectedPairs[pair.first] == pair.second);
    }
}
#endif

TEST_F(ChairMergerTest, IdNamePairUsage)
{
    merger->m_PreyFilePath = "PreyFiles";

    // profile this function to see if it's slow
    auto start1 = std::chrono::high_resolution_clock::now();
    merger->LoadIdNameMap();
    auto end1 = std::chrono::high_resolution_clock::now();
    // get the number of milliseconds it took to run
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    // print the time it took to run
    printf("LoadIdNameMap took %lld milliseconds\n", duration1.count());

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // profile this function to see if it's slow
    auto start = std::chrono::high_resolution_clock::now();
    // merger->AddIdNameMapToLua(L);
    auto end = std::chrono::high_resolution_clock::now();
    // get the number of milliseconds it took to run
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // print the time it took to run
    printf("AddIdNameMapToLua took %lld milliseconds\n", duration.count());

    std::string luaString = R"(
    function dump(o)
       if type(o) == 'table' then
          local s = '{ '
          for k,v in pairs(o) do
             if type(k) ~= 'number' then k = '\"'..k..'\"' end
             s = s .. '['..k..'] = ' .. dump(v) .. ','
          end
          return s .. '} '
       else
          return tostring(o)
       end
    end

    function countElements(tbl)
        local count = 0
        for k, v in pairs(tbl) do
            if type(v) == "table" then
                count = count + countElements(v)
            else
                count = count + 1
            end
        end
        return count
    end

    arkSize = countElements(Ark)
    libSize = countElements(Libs)
    print("Ark Size:" .. tostring(arkSize))
    print("Libs Size:" .. tostring(libSize))
    print("Total Size:" .. tostring(arkSize + libSize))
    print("Ark:" .. dump(Ark))
    print("Libs:" .. dump(Libs))
    )";

    auto result = luaL_dostring(L, luaString.c_str());
    LuaUtils::report_errors(L, result);

    lua_close(L);

    // FIXME 2023-07-07: This test is broken.
    // FIXME 2023-07-07: merger->AddIdNameMapToLua(L) was moved to WildcardResolver - tmp64

    // check the console to see what the output was
    // TODO: fetch it off the stack and check it here
}
