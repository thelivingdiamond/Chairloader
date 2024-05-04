#include <gmock/gmock-matchers.h>
#include <ChairMerger/MergingPolicy3.h>
#include "XmlTestUtils.h"

static void ExpectEqualsMergingPolicy3(const MergingPolicy3& expected, const MergingPolicy3& actual);

static void ExpectEqualsAttribute(const MergingPolicy3::Attribute& expected, const MergingPolicy3::Attribute& actual)
{
    EXPECT_EQ(expected.name, actual.name);
    EXPECT_EQ(expected.type, actual.type);
    EXPECT_EQ(expected.required, actual.required);
    EXPECT_EQ(expected.readOnly, actual.readOnly);
}

static void ExpectEqualsCollection(const MergingPolicy3::Collection& expected, const MergingPolicy3::Collection& actual)
{
    EXPECT_EQ(expected.type, actual.type);
    EXPECT_EQ(expected.keyChildName, actual.keyChildName);
    EXPECT_THAT(expected.keyChildAttributes, testing::ContainerEq(actual.keyChildAttributes));
}

static void ExpectEqualsChildConstraints(const MergingPolicy3::ChildConstraints& expected, const MergingPolicy3::ChildConstraints& actual)
{
    EXPECT_THAT(expected.uniqueAttributes, testing::ContainerEq(actual.uniqueAttributes));
}

static void ExpectEqualsMergingPolicy3List(const std::vector<MergingPolicy3>& expected, const std::vector<MergingPolicy3>& actual)
{
    ASSERT_EQ(expected.size(), actual.size());

    for (size_t i = 0; i < expected.size(); i++)
    {
        ExpectEqualsMergingPolicy3(expected.at(i), actual.at(i));
    }
}

static void ExpectEqualsMergingPolicy3(const MergingPolicy3& expected, const MergingPolicy3& actual)
{
    EXPECT_EQ(expected.GetNodeName(), actual.GetNodeName());
    EXPECT_EQ(expected.IsNodeNameRegex(), actual.IsNodeNameRegex());
    EXPECT_EQ(expected.IsRecursive(), actual.IsRecursive());

    ASSERT_EQ(expected.GetAttributes().size(), actual.GetAttributes().size());

    for (size_t i = 0; i < expected.GetAttributes().size(); i++)
    {
        ExpectEqualsAttribute(expected.GetAttributes().at(i), actual.GetAttributes().at(i));
    }

    EXPECT_EQ(expected.IsAllowingUnknownAttributes(), actual.IsAllowingUnknownAttributes());

    ExpectEqualsCollection(expected.GetCollection(), actual.GetCollection());
    ExpectEqualsChildConstraints(expected.GetChildConstraints(), actual.GetChildConstraints());
    ExpectEqualsMergingPolicy3List(expected.GetChildNodes(), actual.GetChildNodes());
    ExpectEqualsMergingPolicy3List(expected.GetChildNodesRegex(), actual.GetChildNodesRegex());
}

static MergingPolicy3 CreateExpectedNode()
{
    MergingPolicy3 expected;
    {
        expected.SetNodeName("RootNodeName");
        expected.GetCollection().type = MergingPolicy3::ECollectionType::Dict;
        expected.GetCollection().keyChildName = true;

        MergingPolicy3 testNode1;
        {
            testNode1.SetNodeName("TestNode1");

            {
                MergingPolicy3::Attribute attr;
                attr.name = "testValue";
                attr.type = "string";
                testNode1.GetAttributes().push_back(attr);
            }
            {
                testNode1.GetCollection().type = MergingPolicy3::ECollectionType::Dict;
                testNode1.GetCollection().keyChildAttributes.push_back("signalInput");
                testNode1.GetCollection().keyChildAttributes.push_back("signalOutput");
            }
            {
                MergingPolicy3 positiveSignalValue;
                {
                    positiveSignalValue.SetNodeName("PositiveSignalValue");

                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        positiveSignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        positiveSignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "scale";
                        attr.type = "float";
                        positiveSignalValue.GetAttributes().push_back(attr);
                    }

                    testNode1.AppendNode(positiveSignalValue);
                }

                MergingPolicy3 negativeSignalValue;
                {
                    negativeSignalValue.SetNodeName("NegativeSignalValue");

                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        negativeSignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        negativeSignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "scale";
                        attr.type = "float";
                        negativeSignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "offset";
                        attr.type = "float";
                        negativeSignalValue.GetAttributes().push_back(attr);
                    }

                    testNode1.AppendNode(negativeSignalValue);
                }

                MergingPolicy3 anySignalValue;
                {
                    anySignalValue.SetNodeName(".*SignalValue", true);
                    anySignalValue.SetRecursive(true);

                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        anySignalValue.GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "ArkUniqueIdRef";
                        attr.readOnly = "true";
                        attr.required = "true";
                        anySignalValue.GetAttributes().push_back(attr);
                    }

                    testNode1.AppendNode(anySignalValue);
                }
            }

            expected.AppendNode(testNode1);
        }
    }

    return expected;
}

TEST(MergingPolicy3, LoadFromXml)
{
    MergingPolicy3 expected = CreateExpectedNode();

    auto [policyXml, errorStack] = XmlUtils::LoadDocumentWithStack("Testing/MergingPolicy3/LoadFromXml.xml");
    MergingPolicy3 actual;
    actual.LoadXmlNode(policyXml.first_child().first_child(), errorStack);

    ExpectEqualsMergingPolicy3(expected, actual);
}

TEST(FileMergingPolicy3, LoadFromXml)
{
    MergingPolicy3 expectedNode = CreateExpectedNode();

    auto [policyXml, errorStack] = XmlUtils::LoadDocumentWithStack("Testing/MergingPolicy3/LoadFromXml.xml");
    FileMergingPolicy3 actual;
    actual.LoadXmlNode(policyXml.first_child(), errorStack);

    EXPECT_EQ(actual.GetFileName(), R"((In)?validRegex\.xml)");
    EXPECT_EQ(actual.IsRegexName(), true);
    EXPECT_EQ(actual.IsRecursive(), true);
    ExpectEqualsMergingPolicy3(expectedNode, actual.GetRootNode());
}
