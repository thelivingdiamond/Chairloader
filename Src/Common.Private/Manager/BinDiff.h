#pragma once
#include <cstdint>
#include <vector>
#include <ostream>
#include <istream>
#include <functional>
#include "SHA256.h"

namespace BinDiff
{

//! Maximum file size that BinDiff supports
constexpr uint32_t MAX_FILE_SIZE = std::numeric_limits<uint32_t>::max();

//! Called when progress changes. Progress = percent * 10
using ProgressCallback = std::function<void(int progress, uint32_t dstPos)>;

//! Creates a diff file. Using the diff file and src file it's possible to contstruct dstFile.
void CreateDiff(const std::vector<uint8_t>& srcFile, const std::vector<uint8_t>& dstFile, std::ostream& outFile, const ProgressCallback& progressCb);

//! Applies a .diff file to the source file.
//! @param srcHash Source hash as read from the diff file
std::vector<uint8_t> ApplyDiff(const std::vector<uint8_t>& srcFile, const std::vector<uint8_t>& diffFile, SHA256::Digest& srcHash);

}
