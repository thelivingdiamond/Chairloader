#include <cstring>
#include <string>
#include <chrono>
#include "BinDiff.h"

constexpr char FILE_HEADER[] = "BINDIFF";
constexpr uint32_t MAX_LEN = 255;
constexpr uint32_t SEARCH_DELTA = 64 * 1024;

static void WriteUInt32(std::ostream& outFile, uint32_t val)
{
	char buf[sizeof(val)];
	memcpy(buf, &val, sizeof(val));
	outFile.write(buf, sizeof(val));
}

static void WriteByte(std::ostream& outFile, uint8_t val)
{
	outFile.write((char*)&val, 1);
}

void BinDiff::CreateDiff(const std::vector<uint8_t>& srcFile, const std::vector<uint8_t>& dstFile,
	std::ostream& outFile, const ProgressCallback& progressCb)
{
	if (srcFile.size() > MAX_FILE_SIZE)
		throw std::logic_error("source file is too large");
	if (dstFile.size() > MAX_FILE_SIZE)
		throw std::logic_error("destination file is too large");

	outFile.write(FILE_HEADER, sizeof(FILE_HEADER));
	WriteUInt32(outFile, dstFile.size());

	// Write SHA256 hash of source file
	{
		SHA256 hash;
		hash.update(srcFile.data(), srcFile.size());
		SHA256::Digest digest = hash.digest();
		outFile.write((char*)digest.data(), digest.size());
	}

	// Find all bytes in source
	std::vector<uint32_t> byteOffsets(256);
	for (int i = 0; i < byteOffsets.size(); i++)
	{
		auto it = std::find(srcFile.begin(), srcFile.end(), (uint8_t)i);
		if (it == srcFile.end())
		{
			throw std::runtime_error("byte " + std::to_string(i) + " not found in src file");
		}
		byteOffsets[i] = it - srcFile.begin();
	}

	int lastProgress = 0;
	uint32_t curPos = 0;
	uint32_t sizeLeft = dstFile.size();
	while (sizeLeft != 0)
	{
		uint32_t longestSrcOffset = 0;
		uint32_t longestSrcLen = 0;

		uint32_t srcOffset = curPos >= SEARCH_DELTA ? curPos - SEARCH_DELTA : 0;
		uint32_t srcEnd = std::min((uint32_t)srcFile.size(), curPos + SEARCH_DELTA);
		uint32_t maxLen = std::min(MAX_LEN, sizeLeft);
		uint32_t curLen = 0;

		for (; srcOffset < srcEnd; srcOffset++)
		{
			if (srcFile[srcOffset] == dstFile[curPos + curLen])
			{
				curLen++;
				if (curLen > longestSrcLen)
				{
					longestSrcOffset = srcOffset - curLen + 1;
					longestSrcLen = curLen;
				}

				if (curPos + curLen == dstFile.size() || curLen >= maxLen)
					break;
			}
			else
			{
				curLen = 0;
			}
		}

		if (curLen > longestSrcLen)
		{
			longestSrcOffset = srcOffset;
			longestSrcLen = curLen;
		}

		if (longestSrcLen == 0)
		{
			// Fall back to single byte
			longestSrcOffset = byteOffsets[dstFile[curPos]];
			longestSrcLen = 1;
		}

		WriteUInt32(outFile, longestSrcOffset);
		WriteByte(outFile, (uint8_t)longestSrcLen);
		curPos += longestSrcLen;
		sizeLeft -= longestSrcLen;

		int progress = (int)(1000.0 * curPos / dstFile.size());
		if (progress != lastProgress)
		{
			progressCb(progress, curPos);
			lastProgress = progress;
		}
	}
}

std::vector<uint8_t> BinDiff::ApplyDiff(const std::vector<uint8_t>& srcFile, const std::vector<uint8_t>& diffFile, SHA256::Digest& srcHash)
{
	size_t diffFilePos = 0;

	auto ReadDiffFile = [&](char* buf, size_t size)
	{
		if (diffFilePos + size > diffFile.size())
			throw std::runtime_error("diff file too small");
		memcpy(buf, diffFile.data() + diffFilePos, size);
		diffFilePos += size;
	};

	auto ReadUInt32 = [&]()
	{
		uint32_t val;
		char buf[sizeof(val)];
		ReadDiffFile(buf, sizeof(val));
		memcpy(&val, &buf, sizeof(val));
		return val;
	};

	auto ReadByte = [&]()
	{
		uint8_t val;
		ReadDiffFile((char*)&val, 1);
		return val;
	};

	char header[sizeof(FILE_HEADER)];
	ReadDiffFile(header, sizeof(header));

	if (memcmp(header, FILE_HEADER, sizeof(header)))
		throw std::runtime_error("invalid header");

	uint32_t dstSize = ReadUInt32();
	std::vector<uint8_t> result;
	result.resize(dstSize);

	ReadDiffFile((char*)srcHash.data(), srcHash.size());

	uint32_t outOffset = 0;
	while (outOffset < dstSize)
	{
		uint32_t offset = ReadUInt32();
		uint8_t len = ReadByte();

		if (outOffset + len > dstSize)
			throw std::runtime_error("invalid diff file: total len > dstSize");

		memcpy(result.data() + outOffset, srcFile.data() + offset, len);
		outOffset += len;
	}

	return result;
}
