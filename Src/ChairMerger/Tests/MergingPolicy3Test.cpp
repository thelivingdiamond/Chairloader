#include <gmock/gmock-matchers.h>
#include <ChairMerger/MergingPolicy3.h>
#include "XmlTestUtils.h"

namespace
{

class TestAlloc : public IMergingPolicyAllocator
{
public:
    // IMergingPolicyAllocator
    virtual MergingPolicy3* AllocateEmptyPolicy() = 0;

private:
    std::vector<std::unique_ptr<MergingPolicy3>> m_PolicyPool;
};

} // namespace

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

static void ExpectEqualsMergingPolicy3List(const MergingPolicy3::ChildNodeMap& expected, const MergingPolicy3::ChildNodeMap& actual)
{
    ASSERT_EQ(expected.size(), actual.size());

    for (const auto& [name, node] : expected)
    {
        auto it = actual.find(name);
        ASSERT_NE(actual.end(), it);
        ExpectEqualsMergingPolicy3(*node, *it->second);
    }
}

static void ExpectEqualsMergingPolicy3List(const MergingPolicy3::RegexChildNodeList& expected, const MergingPolicy3::RegexChildNodeList& actual)
{
    ASSERT_EQ(expected.size(), actual.size());

    for (size_t i = 0; i < expected.size(); i++)
    {
        ExpectEqualsMergingPolicy3(*expected[i].second, *actual[i].second);
    }
}

static void ExpectEqualsMergingPolicy3(const MergingPolicy3& expected, const MergingPolicy3& actual)
{
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

static MergingPolicy3* CreateExpectedNode(IMergingPolicyAllocator* pAlloc)
{
    MergingPolicy3* expected = pAlloc->AllocateEmptyPolicy();
    {
        expected->GetCollection().type = MergingPolicy3::ECollectionType::Dict;
        expected->GetCollection().keyChildName = true;

        MergingPolicy3* testNode1 = pAlloc->AllocateEmptyPolicy();
        {
            {
                MergingPolicy3::Attribute attr;
                attr.name = "testValue";
                attr.type = "string";
                testNode1->GetAttributes().push_back(attr);
            }
            {
                testNode1->GetCollection().type = MergingPolicy3::ECollectionType::Dict;
                testNode1->GetCollection().keyChildAttributes.push_back("signalInput");
                testNode1->GetCollection().keyChildAttributes.push_back("signalOutput");
            }
            {
                MergingPolicy3* positiveSignalValue = pAlloc->AllocateEmptyPolicy();
                {
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        positiveSignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        positiveSignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "scale";
                        attr.type = "float";
                        positiveSignalValue->GetAttributes().push_back(attr);
                    }

                    testNode1->AppendNode("PositiveSignalValue", false, positiveSignalValue);
                }

                MergingPolicy3* negativeSignalValue = pAlloc->AllocateEmptyPolicy();
                {
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        negativeSignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        negativeSignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "scale";
                        attr.type = "float";
                        negativeSignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "offset";
                        attr.type = "float";
                        negativeSignalValue->GetAttributes().push_back(attr);
                    }

                    testNode1->AppendNode("NegativeSignalValue", false, negativeSignalValue);
                }

                MergingPolicy3* anySignalValue = pAlloc->AllocateEmptyPolicy();
                {
                    anySignalValue->SetRecursive(true);

                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalInput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        anySignalValue->GetAttributes().push_back(attr);
                    }
                    {
                        MergingPolicy3::Attribute attr;
                        attr.name = "signalOutput";
                        attr.type = "uint64";
                        attr.readOnly = "true";
                        attr.required = "true";
                        anySignalValue->GetAttributes().push_back(attr);
                    }

                    testNode1->AppendNode(".*SignalValue", true, anySignalValue);
                }
            }

            expected->AppendNode("TestNode1", false, testNode1);
        }
    }

    return expected;
}

TEST(MergingPolicy3, LoadFromXml)
{
    MergingPolicyAllocator allocator;
    MergingPolicy3* expected = CreateExpectedNode(&allocator);

    auto [policyXml, errorStack] = XmlUtils::LoadDocumentWithStack("Testing/MergingPolicy3/LoadFromXml.xml");
    MergingPolicy3* actual = allocator.AllocateEmptyPolicy();
    actual->LoadXmlNode(&allocator, nullptr, policyXml.first_child().first_child(), errorStack);

    ExpectEqualsMergingPolicy3(*expected, *actual);
}

TEST(FileMergingPolicy3, LoadFromXml)
{
    MergingPolicyAllocator allocator;
    MergingPolicy3* expectedNode = CreateExpectedNode(&allocator);

    auto [policyXml, errorStack] = XmlUtils::LoadDocumentWithStack("Testing/MergingPolicy3/LoadFromXml.xml");
    FileMergingPolicy3 actual;
    actual.LoadXmlNode(fs::path(), nullptr, policyXml.first_child(), errorStack);

    EXPECT_EQ(actual.GetFileName(), R"((In)?validRegex\.xml)");
    EXPECT_EQ(actual.IsRegexName(), true);
    EXPECT_EQ(actual.IsRecursive(), true);
    ExpectEqualsMergingPolicy3(*expectedNode, actual.GetRootNode());
}
