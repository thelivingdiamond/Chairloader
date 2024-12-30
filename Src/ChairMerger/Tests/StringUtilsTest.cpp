#include <Chairloader/Private/StringUtils.h>

using TestValue = std::pair<std::string, std::string>;

class StringUtilsTest : public testing::TestWithParam<TestValue>
{
};

TEST_P(StringUtilsTest, Compare)
{
    std::string input = GetParam().first;
    std::string expected = GetParam().second;
    std::string actual = std::string(TrimStringView(input));
    EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
    StringUtils_Compare,
    StringUtilsTest,
    testing::Values(
        TestValue("", ""),
        TestValue("A", "A"),
        TestValue(" A", "A"),
        TestValue("A ", "A"),
        TestValue(" A ", "A"),
        TestValue(" AB  ", "AB")
        ));
