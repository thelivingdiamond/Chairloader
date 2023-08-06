//
// Created by theli on 3/28/2023.
//

#include <gtest/gtest.h>
#include "XMLMerger2.h"



TEST(XMLMerger2Test, FuseXmlNode) {
    pugi::xml_document baseDoc, modDoc;
    baseDoc.load_string(R"(
        <X a="1" b="2" c="3">
            <Y a="1" b="2" c="3">
                <Z a="1" b="2" c="3" />
                <Z2 a="1" b="2" c="3" />
            </Y>
        </X>
    )");
    modDoc.load_string(R"(
        <X a="4" b="5" c="6">
            <Y a="4" b="5" c="6">
                <Z a="4" b="5" c="6" />
                <Z2 a="4" b="5" c="6" />
            </Y>
        </X>
    )");
    XMLMerger2::FuseXMLNode(baseDoc.first_child(), modDoc.first_child());
    EXPECT_EQ(baseDoc.first_child().attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().attribute("c").value(), std::string("6"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("c").value(), std::string("6"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z").attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z").attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z").attribute("c").value(), std::string("6"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z2").attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z2").attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z2").attribute("c").value(), std::string("6"));
}

TEST(XMLMerger2Test, PatchXmlNode) {
    pugi::xml_document baseDoc, modDoc;
    baseDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y a="1" b="2" c="3">
            <Z a="1" b="2" c="3" />
            <Z2 a="1" b="2" c="3" />
        </Y>
    </X>
    )");
    modDoc.load_string(R"(
    <X a="4" d="6">
        <Y a="4" b="5" d="6">
            <Z2 a="4" b="5" d="6" />
        </Y>
    </X>
    )");
    XMLMerger2::PatchXmlNode(baseDoc.first_child(), modDoc.first_child());
    EXPECT_TRUE(baseDoc.first_child().attribute("a").value() == std::string("4"));
    EXPECT_TRUE(baseDoc.first_child().attribute("b").value() == std::string("2"));
    EXPECT_TRUE(baseDoc.first_child().attribute("c").value() == std::string("3"));
    EXPECT_TRUE(baseDoc.first_child().attribute("d").value() == std::string("6"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").attribute("a").value() == std::string("4"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").attribute("b").value() == std::string("5"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").attribute("c").value() == std::string("3"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").attribute("d").value() == std::string("6"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z").attribute("a").value() == std::string("1"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z").attribute("b").value() == std::string("2"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z").attribute("c").value() == std::string("3"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z2").attribute("a").value() == std::string("4"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z2").attribute("b").value() == std::string("5"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z2").attribute("c").value() == std::string("3"));
    EXPECT_TRUE(baseDoc.first_child().child("Y").child("Z2").attribute("d").value() == std::string("6"));
}

TEST(XMLMerger2Test, MergeXmlNodeAttributes) {
    pugi::xml_document baseDoc, modDoc;
    baseDoc.load_string(R"(<X a="1" b="2" c="3" />)");
    modDoc.load_string(R"(<X a="4" b="5" d="6" />)");
    XMLMerger2::MergeXmlNodeAttributes(baseDoc.first_child(), modDoc.first_child());
    EXPECT_TRUE(baseDoc.first_child().attribute("a").value() == std::string("4"));
    EXPECT_TRUE(baseDoc.first_child().attribute("b").value() == std::string("5"));
    EXPECT_TRUE(baseDoc.first_child().attribute("c").value() == std::string("3"));
    EXPECT_TRUE(baseDoc.first_child().attribute("d").value() == std::string("6"));

}

TEST(XMLMerger2Test, CheckNodeEquality) {
    pugi::xml_document doc1, doc2, doc3, doc4;
    doc1.load_string(R"(
    <X a="2"/>
    )");
    doc2.load_string(R"(
    <X a="2"/>
    )");
    doc3.load_string(R"(
    <X a="3"/>
    )");
    doc4.load_string(R"(
    <Y a="2"/>
    )");
    EXPECT_TRUE(XMLMerger2::CheckNodeEquality(doc1.first_child(), doc2.first_child()));
    EXPECT_FALSE(XMLMerger2::CheckNodeEquality(doc1.first_child(), doc3.first_child()));
    EXPECT_FALSE(XMLMerger2::CheckNodeEquality(doc1.first_child(), doc4.first_child()));
    EXPECT_FALSE(XMLMerger2::CheckNodeEquality(doc3.first_child(), doc4.first_child()));
}


TEST(XMLMerger2Test, MergeXmlNodeSimple){
pugi::xml_document baseDoc, modDoc, originalDoc;
    originalDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    baseDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    modDoc.load_string(R"(
    <X a="4" b="5" c="6">
        <Y d="7"/>
    </X>
    )");
    XMLMerger2::MergeXmlNode(baseDoc.first_child(), modDoc.first_child(), originalDoc.first_child());

    EXPECT_EQ(baseDoc.first_child().attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().attribute("c").value(), std::string("6"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("d").value(), std::string("7"));
}

TEST(XMLMerger2Test, MergeXmlNodeApplyIfTrue){
    pugi::xml_document baseDoc, modDoc, originalDoc;
    originalDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    baseDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    modDoc.load_string(R"(
    <X a="4" b="5" c="6" ch:apply_if="true">
        <Y d="7"/>
    </X>
    )");
    XMLMerger2::MergeXmlNode(baseDoc.first_child(), modDoc.first_child(), originalDoc.first_child());

    EXPECT_EQ(baseDoc.first_child().attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().attribute("b").value(), std::string("5"));
    EXPECT_EQ(baseDoc.first_child().attribute("c").value(), std::string("6"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("d").value(), std::string("7"));
}

TEST(XMLMerger2Test, MergeXmlNodeApplyIfFalse){
    pugi::xml_document baseDoc, modDoc, originalDoc;
    originalDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    baseDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    )");
    modDoc.load_string(R"(
    <X a="4" b="5" c="6" ch:apply_if="false">
        <Y d="7"/>
    </X>
    )");
    XMLMerger2::MergeXmlNode(baseDoc.first_child(), modDoc.first_child(), originalDoc.first_child());

    EXPECT_EQ(baseDoc.first_child().attribute("a").value(), std::string("1"));
    EXPECT_EQ(baseDoc.first_child().attribute("b").value(), std::string("2"));
    EXPECT_EQ(baseDoc.first_child().attribute("c").value(), std::string("3"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("d").value(), std::string("4"));
}

TEST(XMLMerger2Test, MergeXmlNodeRemove){
    pugi::xml_document baseDoc, modDoc, originalDoc;
    originalDoc.load_string(R"(
    <Parent>
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    </Parent>
    )");
    baseDoc.load_string(R"(
    <Parent>
    <X a="1" b="2" c="3">
        <Y d="4"/>
    </X>
    </Parent>
    )");
    modDoc.load_string(R"(
    <Parent>
    <X a="4" b="5" c="6" ch:remove="true">
        <Y d="7"/>
    </X>
    </Parent>
    )");
    XMLMerger2::MergeXmlNode(baseDoc.first_child().first_child(), modDoc.first_child().first_child(), originalDoc.first_child().first_child());

    EXPECT_FALSE(baseDoc.first_child().first_child());
}

TEST(XMLMerger2Test, MergeXmlNodePatchMode){
    pugi::xml_document baseDoc, modDoc, originalDoc;
    originalDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4" e="27">
            <Z f="8" g="69"/>
        </Y>
    </X>
    )");
    baseDoc.load_string(R"(
    <X a="1" b="2" c="3">
        <Y d="4" e="27">
            <Z f="8" g="69"/>
        </Y>
    </X>
    )");
    modDoc.load_string(R"(
    <X a="4" ch:patch_mode="true">
        <Y d="7">
            <Z g="420"/>
        </Y>
    </X>
    )");
    XMLMerger2::MergeXmlNode(baseDoc.first_child(), modDoc.first_child(), originalDoc.first_child());

    EXPECT_EQ(baseDoc.first_child().attribute("a").value(), std::string("4"));
    EXPECT_EQ(baseDoc.first_child().attribute("b").value(), std::string("2"));
    EXPECT_EQ(baseDoc.first_child().attribute("c").value(), std::string("3"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("d").value(), std::string("7"));
    EXPECT_EQ(baseDoc.first_child().child("Y").attribute("e").value(), std::string("27"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z").attribute("f").value(), std::string("8"));
    EXPECT_EQ(baseDoc.first_child().child("Y").child("Z").attribute("g").value(), std::string("420"));
}


TEST(XMLMerger2Test, ResolvePolicyPathWildcards) {
    pugi::xml_document modDoc, policyDoc;
    modDoc.load_string(R"(
    <Mod>
        <ImportantNode>
            <FunDetail/>
        </ImportantNode>
    </Mod>
    )");

    policyDoc.load_string(R"(
    <_wildcard_>
        <_wildcard_>
            <_wildcard_/>
        </_wildcard_>
    </_wildcard_>
    )");

    XMLMerger2::ResolvePolicyPathWildcards(modDoc.first_child(), policyDoc.first_child());
    EXPECT_TRUE(policyDoc.first_child().name() == std::string("Mod"));
    EXPECT_TRUE(policyDoc.first_child().first_child().name() == std::string("ImportantNode"));
    EXPECT_TRUE(policyDoc.first_child().first_child().first_child().name() == std::string("FunDetail"));
}



TEST(XMLMerger2Test, MergeByAttributes) {
    MergingPolicy policy;
    pugi::xml_document baseDoc, modDoc, originalDoc, policyDoc;
    policyDoc.load_string(R"(
    <mergingPolicy identification_policy="match_attribute">
        <attribute name="Name" priority="0"/>
        <nodeStructure>
            <TestList merge_children="true"/>
        </nodeStructure>
    </mergingPolicy>
   )");

    originalDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="1" b="2" c="3"/>
        <Test Name="Test2" a="1" b="2" c="3"/>
        <Test Name="Test3" a="1" b="2" c="3"/>
    </TestList>
    )");

    baseDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="1" b="2" c="3"/>
        <Test Name="Test2" a="6" b="7" c="8"/>
        <Test Name="Test3" a="1" b="2" c="3"/>
    </TestList>
    )");

    modDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="4" b="5" c="6" d="a"/>
        <Test Name="Test2" a="1" b="2" c="3" d="a"/>
        <Test Name="Test3" a="4" b="5" c="6" d="a"/>
    </TestList>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeByAttribute(baseDoc.first_child(), modDoc.first_child(),originalDoc.first_child(), policy);
    auto test1Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test1");
    auto test2Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test2");
    auto test3Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test3");

    EXPECT_EQ(test1Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test1Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test1Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test1Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test2Node.attribute("a").value(), std::string("1"));
    EXPECT_EQ(test2Node.attribute("b").value(), std::string("2"));
    EXPECT_EQ(test2Node.attribute("c").value(), std::string("3"));
    EXPECT_EQ(test2Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test3Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test3Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test3Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test3Node.attribute("d").value(), std::string("a"));
}

TEST(XMLMerger2Test, MergeByTag) {
    MergingPolicy policy;
    pugi::xml_document baseDoc, modDoc, originalDoc, policyDoc;
    policyDoc.load_string(R"(
    <mergingPolicy identification_policy="match_tag">
        <nodeStructure>
            <TestList merge_children="true"/>
        </nodeStructure>
    </mergingPolicy>
   )");

    originalDoc.load_string(R"(
    <TestList>
        <Test1 a="1" b="2" c="3"/>
        <Test2 a="1" b="2" c="3"/>
        <Test3 a="1" b="2" c="3"/>
    </TestList>
    )");

    baseDoc.load_string(R"(
    <TestList>
        <Test1 a="1" b="2" c="3"/>
        <Test2 a="6" b="7" c="8"/>
        <Test3 a="1" b="2" c="3"/>
    </TestList>
    )");

    modDoc.load_string(R"(
    <TestList>
        <Test1 a="4" b="5" c="6" d="a"/>
        <Test2 a="1" b="2" c="3" d="a"/>
        <Test3 a="4" b="5" c="6" d="a"/>
    </TestList>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeByTag(baseDoc.first_child(), modDoc.first_child(),originalDoc.first_child(), policy);
    auto test1Node = baseDoc.first_child().child("Test1");
    auto test2Node = baseDoc.first_child().child("Test2");
    auto test3Node = baseDoc.first_child().child("Test3");

    EXPECT_EQ(test1Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test1Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test1Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test1Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test2Node.attribute("a").value(), std::string("1"));
    EXPECT_EQ(test2Node.attribute("b").value(), std::string("2"));
    EXPECT_EQ(test2Node.attribute("c").value(), std::string("3"));
    EXPECT_EQ(test2Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test3Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test3Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test3Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test3Node.attribute("d").value(), std::string("a"));
}

TEST(XMLMerger2Test, MergeByContents) {
    MergingPolicy policy;
    pugi::xml_document baseDoc, modDoc, originalDoc, policyDoc;
    policyDoc.load_string(R"(
    <mergingPolicy identification_policy="match_contents">
        <nodeStructure>
            <TestList merge_children="true"/>
        </nodeStructure>
    </mergingPolicy>
   )");

    originalDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="1" b="2" c="3">This is Test 1</Test>
        <Test Name="Test2" a="1" b="2" c="3">This is Test 2</Test>
        <Test Name="Test3" a="1" b="2" c="3">This is Test 3</Test>
    </TestList>
    )");

    baseDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="1" b="2" c="3">This is Test 1</Test>
        <Test Name="Test2" a="6" b="7" c="8">This is Test 2</Test>
        <Test Name="Test3" a="1" b="2" c="3">This is Test 3</Test>
    </TestList>
    )");

    modDoc.load_string(R"(
    <TestList>
        <Test Name="Test1" a="4" b="5" c="6" d="a">This is Test 1</Test>
        <Test Name="Test2" a="1" b="2" c="3" d="a">This is Test 2</Test>
        <Test Name="Test3" a="4" b="5" c="6" d="a">This is Test 3</Test>
    </TestList>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeByContents(baseDoc.first_child(), modDoc.first_child(),originalDoc.first_child(), policy);

    auto test1Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test1");
    auto test2Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test2");
    auto test3Node = baseDoc.first_child().find_child_by_attribute("Test", "Name", "Test3");

    EXPECT_EQ(test1Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test1Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test1Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test1Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test2Node.attribute("a").value(), std::string("1"));
    EXPECT_EQ(test2Node.attribute("b").value(), std::string("2"));
    EXPECT_EQ(test2Node.attribute("c").value(), std::string("3"));
    EXPECT_EQ(test2Node.attribute("d").value(), std::string("a"));

    EXPECT_EQ(test3Node.attribute("a").value(), std::string("4"));
    EXPECT_EQ(test3Node.attribute("b").value(), std::string("5"));
    EXPECT_EQ(test3Node.attribute("c").value(), std::string("6"));
    EXPECT_EQ(test3Node.attribute("d").value(), std::string("a"));
}

TEST(XMLMerger2Test, MergeBySpreadsheet) {
    MergingPolicy policy;
    pugi::xml_document baseDoc, modDoc, originalDoc, policyDoc, expectedDoc;
    policyDoc.load_string(R"(
    <mergingPolicy identification_policy="match_spreadsheet"/>
   )");
    // This just has to be messy D:

    originalDoc.load_string(R"(
    <Workbook>
    <Worksheet>
      <Table>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">open_door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">close_door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
      </Table>
    </Worksheet>
    </Workbook>
    )");

    baseDoc.load_string(R"(
    <Workbook>
    <Worksheet>
      <Table>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">open_door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">close_door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">HIPPO Close Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door_GIRAFFE</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door_REMOVE</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
      </Table>
    </Worksheet>
    </Workbook>
    )");

    modDoc.load_string(R"(
    <Workbook>
    <Worksheet>
      <Table>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">open_door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Open Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">close_door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row ch:remove="true">
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door_REMOVE</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
      </Table>
    </Worksheet>
    </Workbook>
    )");

    expectedDoc.load_string(R"(
    <Workbook>
    <Worksheet>
      <Table>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">open_door</Data></Cell>
        <Cell><Data ss:Type="String">Open Door</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Open Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">close_door</Data></Cell>
        <Cell><Data ss:Type="String">Close Door</Data></Cell>
        <Cell><Data ss:Type="String">HIPPO Close Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_ladder</Data></Cell>
        <Cell><Data ss:Type="String">Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Use Ladder</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">ZEBRA Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
       <Row>
        <Cell ss:StyleID="s62"><Data ss:Type="String">use_door_GIRAFFE</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">Use Door</Data></Cell>
        <Cell><Data ss:Type="String">LOCKED</Data></Cell>
       </Row>
      </Table>
    </Worksheet>
    </Workbook>
    )");

    pugi::xml_node baseNode = baseDoc.first_child();
    pugi::xml_node modNode = modDoc.first_child();
    pugi::xml_node originalNode = originalDoc.first_child();
    pugi::xml_node expectedNode = expectedDoc.first_child();

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeBySpreadsheet(baseNode, modNode, originalNode, policy);

    std::stringstream base, expected;
    baseDoc.save(base, "", pugi::format_raw);
    expectedDoc.save(expected, "", pugi::format_raw);

    ASSERT_EQ(base.str(), expected.str());
}


TEST(XMLMerger2Test, MergeNodeStructureAttribute){
    pugi::xml_document baseDoc, modDoc, originalDoc, expectedDoc, policyDoc;
    MergingPolicy policy;

    baseDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");
    originalDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");

    modDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    expectedDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    policyDoc.load_string(R"(
        <mergingPolicy identification_policy="match_attribute">
            <attribute name="id" priority="0"/>
            <nodeStructure>
                <X merge_attributes="true">
                    <Y merge_children="true"/>
                    <W merge_node="true"/>
                </X>
            </nodeStructure>
        </mergingPolicy>
    )");

    pugi::xml_node baseNode = baseDoc.first_child();
    pugi::xml_node modNode = modDoc.first_child();
    pugi::xml_node originalNode = originalDoc.first_child();
    pugi::xml_node expectedNode = expectedDoc.first_child();

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeNodeStructure(baseNode, modNode, originalNode, policy);

    std::stringstream base, expected;
    baseDoc.save(base, "", pugi::format_raw);
    expectedDoc.save(expected, "", pugi::format_raw);

    ASSERT_EQ(base.str(), expected.str());
}

TEST(XMLMerger2Test, MergeXMLDocument){
    pugi::xml_document baseDoc, modDoc, originalDoc, expectedDoc, policyDoc;
    MergingPolicy policy;

    baseDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");
    originalDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");

    modDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    expectedDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    policyDoc.load_string(R"(
        <mergingPolicy identification_policy="match_attribute">
            <attribute name="id" priority="0"/>
            <nodeStructure>
                <_wildcard_ merge_attributes="true">
                    <Y merge_children="true"/>
                    <W merge_node="true"/>
                </_wildcard_>
            </nodeStructure>
        </mergingPolicy>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);

    std::stringstream base, expected;
    baseDoc.save(base, "", pugi::format_raw);
    expectedDoc.save(expected, "", pugi::format_raw);

    ASSERT_EQ(base.str(), expected.str());
}

TEST(XMLMerger2Test, CopySibling) {
    pugi::xml_document baseDoc, modDoc, originalDoc, expectedDoc, policyDoc;
    MergingPolicy policy;

    baseDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");
    originalDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");

    modDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
             <Z id="8" ch:copy_sibling="id=2">
                <A val="420"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    expectedDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="8" ch:copy_sibling="id=2">
                <A val="420"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
        </Y>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    policyDoc.load_string(R"(
        <mergingPolicy identification_policy="match_attribute">
            <attribute name="id" priority="0"/>
            <nodeStructure>
                <_wildcard_ merge_attributes="true">
                    <Y merge_children="true"/>
                    <W merge_node="true"/>
                </_wildcard_>
            </nodeStructure>
        </mergingPolicy>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);

    std::stringstream base, expected;
    baseDoc.save(base, "", pugi::format_raw);
    expectedDoc.save(expected, "", pugi::format_raw);

    ASSERT_EQ(base.str(), expected.str());
}

TEST(XMLMerger2Test, ParseSiblingQuery) {
    struct Item
    {
        std::string str;
        std::vector<std::pair<std::string, std::string>> parsed;
    };

    Item items[] = {
        Item{ "" },
        Item{ "key=value", {{"key", "value"}}},
        Item{ "key1=value1;key2=value2", {{"key1", "value1"}, {"key2", "value2"}}},
    };

    for (Item& i : items)
    {
        auto parsed = XMLMerger2::ParseSiblingQuery(i.str);
        ASSERT_EQ(parsed, i.parsed);
    }
}


TEST(XMLMerger2Test, NodeNotInBaseDocument){
    pugi::xml_document baseDoc, modDoc, originalDoc, expectedDoc, policyDoc;
    MergingPolicy policy;

    baseDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");
    originalDoc.load_string(R"(
    <X hippo="false">
        <Y>
            <Z id="1">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="2">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
            <Z id="3">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
             <Z id="4">
                <A val="1"/>
                <B val="2"/>
                <C val="3"/>
            </Z>
        </Y>
        <W zebra="27">I'm a zebra</W>
    </X>
    )");

    modDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
             <Z id="8" ch:copy_sibling="id=2">
                <A val="420"/>
            </Z>
        </Y>
        <J newStuff="true">
            <X>This merge target doesnt exist in the base document</X>
        </J>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    expectedDoc.load_string(R"(
    <X hippo="true">
        <Y>
            <Z id="1">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="2">
                <A val="4"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
            <Z id="3">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="4">
                <A val="10"/>
                <B val="11"/>
                <C val="12"/>
            </Z>
             <Z id="8" ch:copy_sibling="id=2">
                <A val="420"/>
                <B val="5"/>
                <C val="6"/>
            </Z>
        </Y>
        <J newStuff="true">
            <X>This merge target doesnt exist in the base document</X>
        </J>
        <W zebra="42">I'm a special zebra</W>
    </X>
    )");

    policyDoc.load_string(R"(
        <mergingPolicy identification_policy="match_attribute">
            <attribute name="id" priority="0"/>
            <nodeStructure>
                <_wildcard_ merge_attributes="true">
                    <Y merge_children="true"/>
                    <J merge_children="true"/>
                    <W merge_node="true"/>
                </_wildcard_>
            </nodeStructure>
        </mergingPolicy>
    )");

    policy = MergingPolicy(policyDoc.first_child(), "Ark/", "TheChair.ExampleMod");

    XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);

    std::stringstream base, expected;

    auto baseJ = baseDoc.child("X").child("J");
    auto expectedJ = expectedDoc.child("X").child("J");

    baseJ.print(base, "", pugi::format_raw);
    expectedJ.print(expected, "", pugi::format_raw);

    ASSERT_EQ(base.str(), expected.str());
}