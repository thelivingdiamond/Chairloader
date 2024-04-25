#include <cstdlib>
#include <vector>
#include <fstream>
#include <chrono>
#include <BinDiff/BinDiff.h>
#include <Prey/CryCore/Platform/platform_impl.inl>

// TODO 2023-08-25: Remove this
struct ChairloaderGlobalEnvironment* gCL;

static std::vector<uint8_t> ReadFile(const char* path)
{
	std::ifstream file;
	file.exceptions(std::ios::failbit | std::ios::badbit);
	file.open(path, std::ios::binary);
	file.seekg(0, std::ios::end);
	uint64_t size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<uint8_t> data(size);
	file.read((char*)data.data(), size);
	return data;
}

static double TimeToSeconds(std::chrono::nanoseconds time)
{
	return std::chrono::duration_cast<std::chrono::microseconds>(time).count() / 1000000.0;
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		printf("Usage: BinDiff <source file> <dest file> <output diff file>\n");
		return 1;
	}

	std::vector<uint8_t> srcFile = ReadFile(argv[1]);
	std::vector<uint8_t> dstFile = ReadFile(argv[2]);

	printf("Src size: %llu\n", srcFile.size());
	printf("Dst size: %llu\n", dstFile.size());

	//if (false)
	{
		std::ofstream outFile;
		outFile.exceptions(std::ios::failbit | std::ios::badbit);
		outFile.open(argv[3], std::ios::binary);

		auto startTime = std::chrono::steady_clock::now();
		uint32_t lastProgressPos = 0;
		auto lastProgressTime = startTime;

		auto progressCb = [&](int progress, uint32_t dstPos)
		{
			auto timeNow = std::chrono::steady_clock::now();
			double timeDelta = TimeToSeconds(timeNow - lastProgressTime);
			double speed = (dstPos - lastProgressPos) / timeDelta;
			uint32_t sizeLeft = dstFile.size() - dstPos;
			int etaSeconds = (int)(sizeLeft / speed);
			printf("%u - %d.%d%% - ETA %d min %d sec (%.1f KiB/s)\n", dstPos,
				progress / 10, progress % 10, etaSeconds / 60, etaSeconds % 60, speed / 1000.0);
			lastProgressTime = timeNow;
			lastProgressPos = dstPos;
		};

		BinDiff::CreateDiff(srcFile, dstFile, outFile, progressCb);
		auto endTime = std::chrono::steady_clock::now();
		int timeTaken = (int)(TimeToSeconds(endTime - startTime));
		printf("Finished in %d min %d sec\n", timeTaken / 60, timeTaken % 60);
	}

	{
		std::vector<uint8_t> diffFile = ReadFile(argv[3]);

		SHA256::Digest digest;
		std::vector<uint8_t> dstConv = BinDiff::ApplyDiff(srcFile, diffFile, digest);
		printf("Source SHA256: %s\n", SHA256::toString(digest.data()).c_str());

		if (dstConv != dstFile)
		{
			printf("VALIDATION ERROR! There is a bug in the code!\n");
			printf("Outputting converted file for debugging");
			std::ofstream outFile;
			outFile.exceptions(std::ios::failbit | std::ios::badbit);
			outFile.open(std::string(argv[2]) + ".conv_bug_fix_me_pls", std::ios::binary);
			outFile.write((char*)dstConv.data(), dstConv.size());
			outFile.close();
			std::abort();
		}
	}
}
