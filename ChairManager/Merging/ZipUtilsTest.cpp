//
// Created by theli on 4/3/2023.
//

#include "ZipUtils.h"
#include <gtest/gtest.h>
#include "HashUtils.h"

TEST(ZipUtilsTest, RoundTripTest){
    ZipUtils::CompressFolder("Testing/PreyFiles/Ark", "Testing/Hashing/Ark.pak");
    fs::remove_all("Testing/Hashing/Ark");
    ZipUtils::ExtractFolder("Testing/Hashing/Ark.pak", "Testing/Hashing/Ark");

    auto digest = HashUtils::HashDirectory("Testing/PreyFiles/Ark");
    auto extractedDigest = HashUtils::HashDirectory("Testing/Hashing/Ark");

    EXPECT_EQ(digest, extractedDigest);
}
