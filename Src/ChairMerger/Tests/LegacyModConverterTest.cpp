#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "XmlTestUtils.h"

class LegacyModConverterTest : public testing::Test
{
protected:
    fs::path m_TestDir;

    LegacyModConverterTest()
    {
        m_TestDir = "Testing/LegacyModConverter";
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
};

class LegacyModConverterNodeTest
    : public LegacyModConverterTest
    , public testing::WithParamInterface<std::string>
{
};

TEST_P(LegacyModConverterNodeTest, Success)
{
    std::string testName = GetParam();
    fs::path testDir = m_TestDir / fs::u8path(testName);
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path preyPath = testDir / "1_Prey.xml";
    fs::path modPath = testDir / "1_Mod.xml";
    fs::path expectedPath = testDir / "3_Expected.xml";

    std::unique_ptr<XmlTypeLibrary> pTypeLibrary = LoadTypeLib();
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document preyDoc = XmlUtils::LoadDocument(preyPath);
    pugi::xml_document legacyModDoc = XmlUtils::LoadDocument(modPath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Validate prey
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::MergingBase;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, preyDoc, policy);
        ASSERT_TRUE(validationResult) << "Prey file is invalid:\n" << validationResult.ToString("  ");
    }

    // Validate mod
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::MergingBase;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, legacyModDoc, policy);
        ASSERT_TRUE(validationResult) << "Legacy mod file is invalid:\n" << validationResult.ToString("  ");
    }

    // Convert
    // TODO
    pugi::xml_document modDoc;

    // Validate mod document
    {
        XmlValidator::Context valCtx;
        valCtx.mode = XmlValidator::EMode::Mod;
        valCtx.pTypeLib = pTypeLibrary.get();

        XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, modDoc, policy);
        ASSERT_TRUE(validationResult) << "Resulting mod is invalid:\n" << validationResult.ToString("  ");
    }

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, modDoc));
}

INSTANTIATE_TEST_SUITE_P(
    LegacyModConverter,
    LegacyModConverterNodeTest,
    testing::Values(
        "Array_Mix",
        "Array_NoChanges",
        "Array_NoChanges_DuplicatePrey",
        "Attributes_Missing",
        "Attributes_Root",
        "Dict_Delete",
        "Dict_Existsing_1",
        "Dict_Mix",
        "Dict_New_1",
        "Dict_New_2",
        "Dict_New_OutOfOrder",
        "Dict_NoChanges",
        "ReplaceOnly"));
