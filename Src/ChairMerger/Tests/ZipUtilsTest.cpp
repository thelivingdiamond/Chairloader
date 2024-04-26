//
// Created by theli on 4/3/2023.
//

#include <ChairMerger/ZipUtils.h>
#include <gtest/gtest.h>
#include "HashUtils.h"

static const fs::path g_PreyFiles = "Testing/ChairMerger/_PreyFiles";

TEST(ZipUtilsTest, RoundTripTest)
{
    ZipUtils::CompressFolder(g_PreyFiles / "Ark", "Testing/Hashing/Ark.pak");
    fs::remove_all("Testing/Hashing/Ark");
    ZipUtils::ExtractFolder("Testing/Hashing/Ark.pak", "Testing/Hashing/Ark");

    auto digest = HashUtils::HashDirectory(g_PreyFiles / "Ark");
    auto extractedDigest = HashUtils::HashDirectory("Testing/Hashing/Ark");

    EXPECT_EQ(digest, extractedDigest);
}
