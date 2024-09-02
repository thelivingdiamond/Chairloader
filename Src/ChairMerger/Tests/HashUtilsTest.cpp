//
// Created by theli on 4/2/2023.
//

#include <gtest/gtest.h>
#include <numeric>
#include <ChairMerger/ZipUtils.h>
#include "Manager/ThreadPool.h"
#include "HashUtils.h"

static const fs::path g_PreyFiles = "Testing/ChairMerger/_PreyFiles";

TEST(HashUtilsTest, HashFile)
{
    auto digest = HashUtils::HashFile(g_PreyFiles / "Ark/ArkFactions.xml");
    std::string digestStr = SHA256::toString(digest.data());
    std::string expectedDigestStr = "9fa881b8e5c6d344a8263ffa7b43fb436d6af54a9dc9da22ec2c5d5f93422240";
    EXPECT_EQ(digestStr, expectedDigestStr);
}

TEST(HashUtilsTest, HashDirectory)
{
    auto digest = HashUtils::HashDirectory(g_PreyFiles);
    std::string digestStr = SHA256::toString(digest.data());
    std::string expectedDigestStr = "e725f5a933387c69d20f6e4add3fdf65a7c9760b464cc268037718780c00eef8";
    EXPECT_EQ(digestStr, expectedDigestStr);
}

TEST(HashUtilsTest, HashUncompressedFile)
{
    SHA256::Digest digest;
    ASSERT_TRUE(HashUtils::HashUncompressedFile("Testing/Hashing/level.pak", digest));
    auto expectedDigest = SHA256::fromString("532439abc6f2dfd937c4ee2ec4f014f0da6d21d26c74af853c9b47ec63f91a3a");

    EXPECT_EQ(digest, expectedDigest);
}

TEST(HashUtilsTest, UncompressedFileDirectoryEquality)
{
    //    the hash of a directory and the hash of the uncompressed file should be the same
    ZipUtils::CompressFolder(g_PreyFiles / "Ark", "Testing/Hashing/Ark.pak");
    auto digest = HashUtils::HashDirectory(g_PreyFiles / "Ark");
    SHA256::Digest uncompressedDigest;

    ASSERT_TRUE(HashUtils::HashUncompressedFile("Testing/Hashing/Ark.pak", uncompressedDigest));
    EXPECT_EQ(digest, uncompressedDigest);
}

// TEST(HashUtilsTest, HardDrivePerformanceTest20Iterations){
//     std::vector<uint64_t> durations;
//     for(int i = 0; i < 20; i++) {
//         system("python F:\\PreyHashingTest\\GenerateHashingTarget.py");
//         fs::path path = "F:\\PreyHashingTest\\test.pak";
//         auto now = std::chrono::high_resolution_clock::now();
//         auto digest = HashUtils::HashUncompressedFile(path);
//         auto end = std::chrono::high_resolution_clock::now();
//         auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count();
//         std::cout << "Hashing took " << duration << "ms" << std::endl;
//         durations.emplace_back(duration);
//     }
//     //    average the durations
//     uint64_t sum = 0;
//     for(auto duration : durations){
//         sum += duration;
//     }
//     auto average = sum / durations.size();
//     std::cout << "Average hashing time: " << average << "ms" << std::endl;
// }
//
// TEST(HashUtilsTest, HardDrivePerformanceTest16Threads){
//     std::vector<uint64_t> durations;
//     ThreadPool threadPool(16);
//     for(int i = 0; i < 5; i++) {
//         system("python F:\\PreyHashingTest\\Generate16HashingTargets.py");
//         auto now = std::chrono::high_resolution_clock::now();
//         for (int i = 0; i < 16; i++) {
//             fs::path path = "F:\\PreyHashingTest\\test" + std::to_string(i) + ".pak";
//             threadPool.enqueue([path](){
//                 auto digest = HashUtils::HashUncompressedFile(path);
//             });
//         }
//         threadPool.wait();
//         auto end = std::chrono::high_resolution_clock::now();
//         auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - now).count();
//         std::cout << "Hashing took " << duration << "ms" << std::endl;
//         durations.emplace_back(duration);
//     }
//     //    average the durations
//     uint64_t sum = 0;
//     for(auto duration : durations){
//         sum += duration;
//     }
//     auto average = sum / durations.size();
//     std::cout << "Average hashing time: " << average << "ms" << std::endl;
// }