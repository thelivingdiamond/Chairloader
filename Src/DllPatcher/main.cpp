//
// Created by theli on 11/3/2024.
//

#include <iostream>
#include <pugixml.hpp>
#include "boost/json.hpp"

#include <Prey/CryCore/Platform/platform_impl.inl>
#include <SHA256/SHA256.h>
#include <zlib.h>
#include <BinDiff/BinDiff.h>

// TODO 2024-05-04: Remove this
struct ChairloaderGlobalEnvironment* gCL;


static constexpr char VERSIONS_PATH[] = "Versions";
static constexpr char XML_NAME[] = "Versions.xml";
static constexpr char DIFF_EXT[] = ".diff.gz";

namespace
{

    class ZStream
    {
    public:
        z_stream s;

        ZStream()
        {
            s.avail_in = 0;
            s.next_in = nullptr;
            s.zalloc = nullptr;
            s.zfree = nullptr;
            s.opaque = nullptr;
            int ret = inflateInit2(&s, 16 + MAX_WBITS);
            if (ret != Z_OK)
                throw std::runtime_error("inflateInit2 failed: " + std::string(s.msg));
        }

        ~ZStream()
        {
            inflateEnd(&s);
        }
    };

    std::vector<uint8_t> DecompressGZipFile(const fs::path& path)
    {
        constexpr size_t CHUNK_SIZE = 16 * 1024;
        ZStream zstream;
        int ret = 0;
        std::ifstream file;
        file.open(path, std::ios::binary);

        std::vector<uint8_t> outFile;

        // decompress until deflate stream ends or end of file
        do
        {
            uint8_t buf[CHUNK_SIZE];
            file.read((char*)buf, CHUNK_SIZE);
            zstream.s.avail_in = file.gcount();

            if (zstream.s.avail_in == 0)
                break;
            zstream.s.next_in = buf;

            // run inflate() on input until output buffer not full
            do
            {
                uint8_t outBuf[CHUNK_SIZE];
                zstream.s.avail_out = CHUNK_SIZE;
                zstream.s.next_out = outBuf;

                ret = inflate(&zstream.s, Z_NO_FLUSH);
                        assert(ret != Z_STREAM_ERROR);  /* state not clobbered */

                switch (ret) {
                    case Z_NEED_DICT:
                    case Z_DATA_ERROR:
                    case Z_MEM_ERROR:
                        throw std::runtime_error("inflate failed: " + std::string(zstream.s.msg));
                }

                size_t have = CHUNK_SIZE - zstream.s.avail_out;
                size_t outPos = outFile.size();
                outFile.resize(outPos + have);
                memcpy(outFile.data() + outPos, outBuf, have);

            } while (zstream.s.avail_out == 0);

            // done when inflate() says it's done
        } while (ret != Z_STREAM_END);

        if (ret != Z_STREAM_END)
            throw std::runtime_error("Incomplete gzip stream");

        return outFile;
    }

    std::vector<uint8_t> ReadFile(const fs::path& path)
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

}


//void (*pfnLogCallback)(int verbosity, const char* msg, size_t msgLen);

static std::string logLevelToString(int level) {
    switch(level) {
        case 0:
            return "trace";
        case 1:
            return "debug";
        case 2:
            return "info";
        case 3:
            return "warning";
        case 4:
            return "error";
        case 5:
            return "fatal";
        default:
            return "unknown";
    }
}

static void LogCallback(int verbosity, const char* msg, size_t msgLen) {
    std::string_view msgView(msg, msgLen);
    // print it out like [info] : message
    std::cout << "[" << logLevelToString(verbosity) << "] : " << msgView << std::endl;
}

static void Log(int verbosity, const std::string msg) {
    LogCallback(verbosity, msg.c_str(), msg.size());
}

void PatchTheGame(SHA256::Digest* installedVersionHash, const fs::path& dllPath, const fs::path& backupFilePath)
{
    // See if diff file exists
    std::string diffFileName = SHA256::toString(installedVersionHash->data()).substr(0, 16) + DIFF_EXT;
    fs::path diffPath = fs::current_path() / VERSIONS_PATH / diffFileName;
    if (!fs::exists(diffPath))
        throw std::runtime_error("Diff file \"" + diffFileName + "\" not found");

    // Make a backup of PreyDll.dll
    fs::copy_file(dllPath, backupFilePath, fs::copy_options::overwrite_existing);

    // Decompress diff file
    std::vector<uint8_t> diffFile = DecompressGZipFile(diffPath);

    // Apply diff
    SHA256::Digest diffOrigFileHash;
    std::vector<uint8_t> origFile = ReadFile(dllPath);
    std::vector<uint8_t> patchedFile = BinDiff::ApplyDiff(origFile, diffFile, diffOrigFileHash);

    if (diffOrigFileHash != *installedVersionHash)
        throw std::runtime_error("Diff file \"" + diffFileName + "\" is created for a different source file. Diff hash is " +
                                 SHA256::toString(diffOrigFileHash.data()));

    // Write the file
    std::ofstream outDllFile;
    outDllFile.exceptions(std::ios::failbit | std::ios::badbit);
    outDllFile.open(dllPath, std::ios::binary);
    outDllFile.write((char*)patchedFile.data(), patchedFile.size());
}

int main(int argc, char** argv)
{
    // we take in the path to the game dll, the installed version hash, and the backup file path
    if (argc != 4)
    {
        printf("Usage: ChairPatcher <dll path> <installed version hash> <backup file path>\n");
        return 1;
    }

    // Parse the arguments
    fs::path dllPath = argv[1];
    SHA256::Digest installedVersionHash;
    installedVersionHash = SHA256::fromString(argv[2]);
    fs::path backupFilePath = argv[3];

    try
    {
        PatchTheGame(&installedVersionHash, dllPath, backupFilePath);
    }
    catch (const std::exception& e)
    {
        Log(4, e.what());
        return 1;
    }


    return 0;
}

