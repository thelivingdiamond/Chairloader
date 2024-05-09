#include <boost/algorithm/string/predicate.hpp>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include "XmlTestUtils.h"

static bool IsFileNameForTest(const fs::path& path)
{
    std::string name = path.stem().u8string();
    return !boost::iends_with(name, "_mod")
        && !boost::iends_with(name, "_expected");
}

static fs::path AppendToFileName(fs::path path, std::string_view suffix)
{
    std::string name = path.stem().u8string();
    name += suffix;
    name += path.extension().u8string();
    return path.replace_filename(name);
}

TEST(MainMergingLibraryTest, TestMerging)
{
    fs::path testFilesPath = "Testing/MergingLibrary3";
    XmlTypeLibrary typeLibrary;
    typeLibrary.LoadTypesFromFile("XmlTypeLibrary.xml");
    MergingLibrary3 mergingLibrary;
    mergingLibrary.LoadFromPath("MergingLibrary");

    for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(testFilesPath))
    {
        if (dirEnt.is_directory())
            continue;

        fs::path baseFilePath = dirEnt.path();
        if (!IsFileNameForTest(baseFilePath))
            continue;

        fs::path relPath = baseFilePath.lexically_relative(testFilesPath);
        fs::path modFilePath = AppendToFileName(baseFilePath, "_mod");
        fs::path expectedFilePath = AppendToFileName(baseFilePath, "_expected");
        
        pugi::xml_document baseDoc = XmlUtils::LoadDocument(baseFilePath);
        pugi::xml_document modDoc = XmlUtils::LoadDocument(modFilePath);
        pugi::xml_document expectedDoc = XmlUtils::LoadDocument(expectedFilePath);
        XmlValidator::Result validationResult;

        // Find the policy
        const FileMergingPolicy3* pPolicy = mergingLibrary.FindPolicyForFile(relPath);
        ASSERT_NE(nullptr, pPolicy) << "Policy for file '" << relPath.u8string() << " not found";

        // Validate input
        validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), pPolicy->GetRootNode(), &typeLibrary);
        ASSERT_TRUE(validationResult) << "Input file is invalid:\n" << validationResult.ToString("  ");

        // Merge
        XmlMergerContext context;
        context.pTypeLib = &typeLibrary;
        XmlMerger3::MergeDocument(context, baseDoc, modDoc, *pPolicy);

        // Validate output
        validationResult = XmlValidator::ValidateNode(baseDoc.first_child(), pPolicy->GetRootNode(), &typeLibrary);
        ASSERT_TRUE(validationResult) << "Output after merging is invalid:\n" << validationResult.ToString("  ");

        // Compare with expected
        EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(expectedDoc, baseDoc));
    }
}
