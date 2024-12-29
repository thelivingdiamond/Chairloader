#include <gmock/gmock-matchers.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "XmlTestUtils.h"

class XmlMerger3Test : public testing::Test
{
protected:
    fs::path m_TestDir;

    XmlMerger3Test()
    {
        m_TestDir = "Testing/XmlMerger3";
    }

    FileMergingPolicy3 LoadFilePolicy(const fs::path& path, XmlTypeLibrary* pTypeLib = nullptr)
    {
        FileMergingPolicy3 policy;
        auto [policyDoc, errorStack] = XmlUtils::LoadDocumentWithStack(path);
        policy.LoadXmlNode(fs::path(), pTypeLib, policyDoc.first_child(), errorStack);
        return policy;
    }

    std::unique_ptr<XmlTypeLibrary> LoadTypeLib()
    {
        auto lib = std::make_unique<XmlTypeLibrary>();
        lib->LoadTypesFromFile("XmlTypeLibrary.xml");
        return lib;
    }

    std::string ReadFileToString(const fs::path& path)
    {
        std::ifstream t(path);
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }
};

class XmlMerger3SuccessTest
    : public XmlMerger3Test
    , public testing::WithParamInterface<std::string>
{
protected:
    XmlMerger3SuccessTest()
    {
        m_TestDir = m_TestDir / "Success";
    }
};

class XmlMerger3SuccessLocTest
    : public XmlMerger3Test
    , public testing::WithParamInterface<std::string>
{
protected:
    XmlMerger3SuccessLocTest()
    {
        m_TestDir = m_TestDir / "Success";
    }
};

class XmlMerger3FailTest
    : public XmlMerger3Test
    , public testing::WithParamInterface<std::string>
{
protected:
    XmlMerger3FailTest()
    {
        m_TestDir = m_TestDir / "Fail";
    }
};

class XmlMerger3TypeLibTest
    : public XmlMerger3Test
    , public testing::WithParamInterface<std::string>
{
protected:
    XmlMerger3TypeLibTest()
    {
        m_TestDir = m_TestDir / "TypeLib";
    }
};

TEST_P(XmlMerger3SuccessTest, Success)
{
    std::vector<std::pair<std::string, fs::path>> modPaths;
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path expectedPath = testDir / "3_Expected.xml";

    fs::path singleModPath = testDir / "2_Mod.xml";

    if (fs::exists(singleModPath))
    {
        // Only use single mod
        modPaths.push_back(std::make_pair("Chairloader.TestMod", singleModPath));
    }
    else
    {
        // Merge multiple mods
        for (int i = 1; i < 100; i++)
        {
            fs::path modPath = testDir / fmt::format("2_Mod{}.xml", i);
            
            if (!fs::exists(modPath))
                break;

            modPaths.push_back(std::make_pair(fmt::format("Chairloader.TestMod{}", i), modPath));
        }
    }

    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = LoadTypeLib();
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document baseDoc = XmlUtils::LoadDocument(basePath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Validate base
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::MergingBase;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, baseDoc, policy);
        ASSERT_TRUE(validationResult) << "Base file is invalid:\n" << validationResult.ToString("  ");
    }

    // Merge
    for (auto& i : modPaths)
    {
        pugi::xml_document modDoc = XmlUtils::LoadDocument(i.second);

        // Validate mod node
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::Mod;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, modDoc, policy);
        ASSERT_TRUE(validationResult) << "Mod failed validation:\n" << validationResult.ToString("  ");

        XmlMergerContext context;
        context.modName = i.first;
        context.pTypeLib = pTypeLibrary.get();
        XmlMerger3::MergeDocument(context, baseDoc, modDoc, policy);
    }

    // Validate output
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::MergingBase;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, baseDoc, policy);
        ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");
    }

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, baseDoc));
}

TEST_P(XmlMerger3SuccessLocTest, SuccessLoc)
{
    std::vector<std::pair<std::string, fs::path>> modPaths;
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path expectedPath = testDir / "3_Expected.xml";

    fs::path singleModPath = testDir / "2_Mod.xml";

    if (fs::exists(singleModPath))
    {
        // Only use single mod
        modPaths.push_back(std::make_pair("Chairloader.TestMod", singleModPath));
    }
    else
    {
        // Merge multiple mods
        for (int i = 1; i < 100; i++)
        {
            fs::path modPath = testDir / fmt::format("2_Mod{}.xml", i);

            if (!fs::exists(modPath))
                break;

            modPaths.push_back(std::make_pair(fmt::format("Chairloader.TestMod{}", i), modPath));
        }
    }

    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = LoadTypeLib();
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document baseDoc = XmlUtils::LoadDocument(basePath, XmlMerger3::EXCEL_PARSE_OPTIONS);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath, XmlMerger3::EXCEL_PARSE_OPTIONS);

    // Merge
    for (auto& i : modPaths)
    {
        pugi::xml_document modDoc = XmlUtils::LoadDocument(i.second);

        XmlMergerContext context;
        context.modName = i.first;
        context.pTypeLib = pTypeLibrary.get();
        XmlMerger3::MergeExcelDocument(context, baseDoc, modDoc, policy);
    }

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, baseDoc));
}

TEST_P(XmlMerger3FailTest, Fail)
{
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path modPath = testDir / "2_Mod.xml";
    fs::path errorPath = testDir / "3_Error.txt";
    fs::path skipValidationPath = testDir / "4_SkipValidation.txt";

    XmlValidator::Result validationResult;
    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = LoadTypeLib();
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document baseDoc = XmlUtils::LoadDocument(basePath);
    pugi::xml_document modDoc = XmlUtils::LoadDocument(modPath);
    std::string expectedError = ReadFileToString(errorPath);
    ASSERT_NE("", expectedError);

    // Validate base
    if (!fs::exists(skipValidationPath))
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::MergingBase;
        valCtx.pTypeLib = pTypeLibrary.get();

        validationResult = XmlValidator::ValidateDocument(valCtx, baseDoc, policy);
        ASSERT_TRUE(validationResult) << "Base file is invalid:\n" << validationResult.ToString("  ");
    }

    EXPECT_ANY_THROW({
        try
        {
            // Merge
            XmlMergerContext context;
            context.modName = "Chairloader.TestMod";
            context.pTypeLib = pTypeLibrary.get();
            XmlMerger3::MergeDocument(context, baseDoc, modDoc, policy);
        }
        catch (const std::exception& e)
        {
            EXPECT_THAT(e.what(), testing::HasSubstr(expectedError));
            throw;
        }
    });
}

TEST_P(XmlMerger3TypeLibTest, TypeLib)
{
    std::vector<std::pair<std::string, fs::path>> modPaths;
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path typeLibPath = testDir / "0_TypeLib.xml";
    fs::path policyPath = testDir / "1_Policy.xml";
    fs::path basePath = testDir / "2_Base.xml";
    fs::path expectedPath = testDir / "4_Expected.xml";

    fs::path singleModPath = testDir / "3_Mod.xml";

    if (fs::exists(singleModPath))
    {
        // Only use single mod
        modPaths.push_back(std::make_pair("Chairloader.TestMod", singleModPath));
    }
    else
    {
        // Merge multiple mods
        for (int i = 1; i < 100; i++)
        {
            fs::path modPath = testDir / fmt::format("3_Mod{}.xml", i);

            if (!fs::exists(modPath))
                break;

            modPaths.push_back(std::make_pair(fmt::format("Chairloader.TestMod{}", i), modPath));
        }
    }

    XmlValidator::Result validationResult;
    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = std::make_unique<XmlTypeLibrary>();
    pTypeLibrary->LoadTypesFromFile(typeLibPath);
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath, pTypeLibrary.get());

    pugi::xml_document baseDoc = XmlUtils::LoadDocument(basePath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Validate base
    XmlValidator::Context valCtx;
    valCtx.mode = XmlValidator::EMode::MergingBase;
    valCtx.pTypeLib = pTypeLibrary.get();

    validationResult = XmlValidator::ValidateDocument(valCtx, baseDoc, policy);
    ASSERT_TRUE(validationResult) << "Base file is invalid:\n" << validationResult.ToString("  ");

    // Merge
    for (auto& i : modPaths)
    {
        pugi::xml_document modDoc = XmlUtils::LoadDocument(i.second);
        XmlMergerContext context;
        context.modName = i.first;
        context.pTypeLib = pTypeLibrary.get();
        XmlMerger3::MergeDocument(context, baseDoc, modDoc, policy);
    }

    // Validate output
    validationResult = XmlValidator::ValidateDocument(valCtx, baseDoc, policy);
    ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, baseDoc));
}

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3SuccessTest,
    testing::Values(
        "Action_Delete",
        "Action_DeleteNonExistant",
        "Action_Replace",
        "Action_ReplaceChildren",
        "Array",
        "Array_ApplyIf",
        "Array_ModOverride",
        "Attributes",
        "Attributes_AllowUnknown",
        "Attributes_Text",
        "BasedOn",
        "BasedOn_AlreadyExists",
        "Dict_Append",
        "Dict_ApplyIf",
        "Dict_Key1",
        "Dict_Key2",
        "Dict_NodeName",
        "Dict_NodeText"));

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3SuccessLocTest,
    testing::Values(
        "Method_Localization",
        "Method_LocalizationTouchUp"));

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3FailTest,
    testing::Values(
        "Array_InvalidIndex",
        "Array_InvalidIndexInBase",
        "Array_InvalidNewNode",
        "Array_MissingIndex",
        "Array_MissingIndexInBase",
        "Array_UnknownMod",
        "Array_UnsortedBase1",
        "Array_UnsortedBase2",
        "Attributes_InvalidValue",
        "Attributes_ReadOnlyChanged",
        "Attributes_Text_Duplicate",
        "Attributes_Text_InvalidValue",
        "Attributes_Text_NotEmpty",
        "Attributes_Unknown",
        "BasedOn_NotFound",
        "Dict_InvalidChildName",
        "Dict_InvalidNewNode",
        "Dict_MissingKeyAttr1",
        "Dict_MissingKeyAttr2",
        "Dict_NodeNameMismatch",
        "Method_ReadOnly",
        "NoCollection_Children"));

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3TypeLibTest,
    testing::Values(
        "Recursion"));
