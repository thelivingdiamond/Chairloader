//
// Created by theli on 4/2/2023.
//

#include <gtest/gtest.h>
#include <numeric>
#include "HashUtils.h"
#include "Manager/ThreadPool.h"

TEST(HashUtilsTest, HashFile)
{
    auto digest = HashUtils::HashFile("Testing/PreyFiles/Ark/ArkFactions.xml");
    auto expectedDigest = SHA256::fromString("9FA881B8E5C6D344A8263FFA7B43FB436D6AF54A9DC9DA22EC2C5D5F93422240");
    EXPECT_EQ(digest, expectedDigest);
}

TEST(HashUtilsTest, HashDirectory)
{
    auto digest = HashUtils::HashDirectory("Testing/PreyFiles/Ark");
    auto expectedDigest = SHA256::fromString("8af38e6f00847bda16a782f056a399f3f3187a12aa15d3a5c978e2c88c88b98c");
    EXPECT_EQ(digest, expectedDigest);
}

TEST(HashUtilsTest, HashUncompressedFile)
{
    auto digest = HashUtils::HashUncompressedFile("Testing/Hashing/level.pak");
    auto expectedDigest = SHA256::fromString("532439abc6f2dfd937c4ee2ec4f014f0da6d21d26c74af853c9b47ec63f91a3a");

    EXPECT_EQ(digest, expectedDigest);
}

TEST(HashUtilsTest, UncompressedFileDirectoryEquality)
{
    //    the hash of a directory and the hash of the uncompressed file should be the same
    auto digest = HashUtils::HashDirectory("Testing/PreyFiles/Ark");
    auto uncompressedDigest = HashUtils::HashUncompressedFile("Testing/Hashing/Ark.pak");

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