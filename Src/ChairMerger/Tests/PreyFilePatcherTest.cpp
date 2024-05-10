#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "XmlTestUtils.h"

static FileMergingPolicy3 LoadFilePolicy(const fs::path& path)
{
    FileMergingPolicy3 policy;
    auto [policyDoc, errorStack] = XmlUtils::LoadDocumentWithStack(path);
    policy.LoadXmlNode(policyDoc.first_child(), errorStack);
    return policy;
}

TEST(PreyFilePatcherTest, PatchNode)
{
    fs::path testDir = "Testing/PreyFilePatcher";
    fs::path policyPath = testDir / "0_Policy.xml";
    fs::path basePath = testDir / "1_Base.xml";
    fs::path expectedPath = testDir / "2_Expected.xml";

    XmlTypeLibrary typeLibrary;
    typeLibrary.LoadTypesFromFile("XmlTypeLibrary.xml");
    FileMergingPolicy3 policy = LoadFilePolicy(policyPath);

    auto [baseDoc, errorStack] = XmlUtils::LoadDocumentWithStack(basePath);
    pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedPath);

    // Patch
    PreyFilePatcher::PatchDocument(baseDoc, policy, errorStack);

    // Validate output
    XmlValidator::Result validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), policy.GetRootNode(), &typeLibrary);
    ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");

    // Compare with expected
    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, baseDoc));
}
