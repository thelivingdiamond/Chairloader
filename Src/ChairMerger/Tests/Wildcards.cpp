#include "ChairMergerTestBase.h"
#include "XmlTestUtils.h"

TEST_F(ChairMergerTestBase, ResolveFileWildcards)
{
    InitTest("ResolveFileWildcards");
    LoadMods();
    CreateMerger();

    pugi::xml_document docSource = XmlTestUtils::LoadDocument(m_TestDir / "Source.xml");
    pugi::xml_document docExpected = XmlTestUtils::LoadDocument(m_TestDir / "Expected.xml");

    m_pMerger->ResolveFileWildcards(m_pMerger->m_Mods[1], docSource.first_child());

    EXPECT_TRUE(XmlTestUtils::CheckNodesEqual(docExpected, docSource));
}
