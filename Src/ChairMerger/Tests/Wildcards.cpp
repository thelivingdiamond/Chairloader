#include "ChairMergerTestBase.h"
#include "XmlTestUtils.h"

TEST_F(ChairMergerTestBase, ResolveFileWildcards)
{
    InitTest("ResolveFileWildcards");
    LoadMods();
    CreateMerger();

    pugi::xml_document docSource = XmlTestUtils::LoadDocument(m_TestDir / "Source.xml");
    pugi::xml_document docExpected = XmlTestUtils::LoadDocument(m_TestDir / "Expected.xml");

    m_pMerger->ResolveFileWildcards(docSource.first_child(), "Mod1");

    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(docExpected, docSource));
}
