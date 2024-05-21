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

    FileMergingPolicy3 LoadFilePolicy(const fs::path& path)
    {
        FileMergingPolicy3 policy;
        auto [policyDoc, errorStack] = XmlUtils::LoadDocumentWithStack(path);
        policy.LoadXmlNode(policyDoc.first_child(), errorStack);
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

TEST_P(XmlMerger3SuccessTest, Success)
{
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path modPath = testDir / "2_Mod.xml";
    fs::path expectedPath = testDir / "3_Expected.xml";

    XmlValidator::Result validationResult;
    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = LoadTypeLib();
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document baseDoc = XmlUtils::LoadDocument(basePath);
    pugi::xml_document modDoc = XmlUtils::LoadDocument(modPath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Validate base
    validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), policy.GetRootNode(), pTypeLibrary.get());
    ASSERT_TRUE(validationResult) << "Base file is invalid:\n" << validationResult.ToString("  ");

    // Merge
    XmlMergerContext context;
    context.pTypeLib = pTypeLibrary.get();
    XmlMerger3::MergeDocument(context, baseDoc, modDoc, policy);

    // Validate output
    validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), policy.GetRootNode(), pTypeLibrary.get());
    ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");

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
        validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), policy.GetRootNode(), pTypeLibrary.get());
        ASSERT_TRUE(validationResult) << "Base file is invalid:\n" << validationResult.ToString("  ");
    }

    EXPECT_ANY_THROW({
        try
        {
            // Merge
            XmlMergerContext context;
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

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3SuccessTest,
    testing::Values(
        "Attributes",
        "Attributes_AllowUnknown",
        "Attributes_Text",
        "Dict_NodeName",
        "Dict_Key1",
        "Dict_Key2",
        "Dict_Append",
        "Array",
        "Array_ApplyIf",
        "Dict_ApplyIf"));

INSTANTIATE_TEST_SUITE_P(
    XmlMerger3,
    XmlMerger3FailTest,
    testing::Values(
        "NoCollection_Children",
        "Attributes_Unknown",
        "Attributes_ReadOnlyChanged",
        "Attributes_InvalidValue",
        "Attributes_Text_NotEmpty",
        "Attributes_Text_InvalidValue",
        "Attributes_Text_Duplicate",
        "Dict_InvalidChildName",
        "Dict_InvalidNewNode",
        "Dict_MissingKeyAttr1",
        "Dict_MissingKeyAttr2",
        "Array_MissingIndex",
        "Array_MissingIndexInBase",
        "Array_InvalidIndex",
        "Array_InvalidIndexInBase",
        "Array_UnsortedBase1",
        "Array_UnsortedBase2",
        "Array_InvalidNewNode"));
