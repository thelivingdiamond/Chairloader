#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlFinalizer3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "XmlTestUtils.h"

static FileMergingPolicy3 LoadFilePolicy(const fs::path& path)
{
    FileMergingPolicy3 policy;
    auto [policyDoc, errorStack] = XmlUtils::LoadDocumentWithStack(path);
    policy.LoadXmlNode(nullptr, policyDoc.first_child(), errorStack);
    return policy;
}

TEST(XmlFinalizerTest, PatchNode)
{
    fs::path testDir = "Testing/XmlFinalizer3";
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path expectedPath = testDir / "2_Expected.xml";

    XmlTypeLibrary typeLibrary;
    typeLibrary.LoadTypesFromFile("XmlTypeLibrary.xml");
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    pugi::xml_document document = XmlUtils::LoadDocument(basePath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Finalize
    XmlFinalizerContext context;
    XmlFinalizer3::FinalizeDocument(context, document, policy);

    // Validate output
    XmlValidator::Context valCtx;
    valCtx.mode = XmlValidator::EMode::Prey;
    valCtx.pTypeLib = &typeLibrary;

    XmlValidator::Result validationResult = XmlValidator::ValidateDocument(valCtx, document, policy);
    ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, document));
}
