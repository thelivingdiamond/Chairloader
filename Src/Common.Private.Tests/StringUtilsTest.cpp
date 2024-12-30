#include <Chairloader/Private/StringUtils.h>

using namespace std::string_view_literals;

TEST(TrimStringView, Empty)
{
    EXPECT_EQ(""sv, TrimStringView(""));
}

TEST(TrimStringView, NoSpaces)
{
    EXPECT_EQ("Test"sv, TrimStringView("Test"));
}

TEST(TrimStringView, LeftSide)
{
    EXPECT_EQ("Test"sv, TrimStringView(" Test"));
    EXPECT_EQ("Test"sv, TrimStringView("  Test"));
    EXPECT_EQ("Test"sv, TrimStringView("   Test"));
}

TEST(TrimStringView, RightSide)
{
    EXPECT_EQ("Test"sv, TrimStringView("Test "));
    EXPECT_EQ("Test"sv, TrimStringView("Test  "));
    EXPECT_EQ("Test"sv, TrimStringView("Test   "));
}

TEST(TrimStringView, BothSides)
{
    EXPECT_EQ("Test"sv, TrimStringView(" Test "));
    EXPECT_EQ("Test"sv, TrimStringView("  Test  "));
    EXPECT_EQ("Test"sv, TrimStringView("   Test   "));
}
