#include "Tests/Merging/ChairMergerTestBase.h"
#include "Tests/XmlTestUtils.h"

void ChairMergerTestBase::SetUp()
{
}

void ChairMergerTestBase::TearDown()
{
    m_pMerger.reset();
}

void ChairMergerTestBase::InitTest(const std::string& testName)
{
    ASSERT_TRUE(m_TestName.empty());

    m_TestName = testName;
    m_BaseDir = fs::current_path() / "Testing/ChairMerger";
    m_TestDir = m_BaseDir / fs::u8path(testName);
    m_TempDir = m_TestDir / "_temp";

    if (fs::exists(m_TempDir))
        fs::remove_all(m_TempDir);

    m_GameDir = m_TempDir / "Game";

    fs::create_directories(m_TempDir);
    fs::create_directories(m_GameDir);

    fs::path emptyZip = m_BaseDir / "EmptyZip.zip";

    // Create fake paks in game root
    constexpr const char* FAKE_PAKS[] = {
        "Localization/english.pak",
        "Localization/English_anim.pak",
        "Localization/English_anim_patch.pak",
        "Localization/english_patch.pak",
        "Localization/English_xml.pak",
        "Localization/English_xml_patch.pak",

        "GameSDK/Levels/Campaign/EndGame/level.pak",
        "GameSDK/Levels/Campaign/EndGame/TerrainTexture.pak",
        "GameSDK/Levels/Campaign/Engineering/CargoBay/level.pak",
        "GameSDK/Levels/Campaign/Engineering/CargoBay/terraintexture.pak",
        "GameSDK/Levels/Campaign/Engineering/LifeSupport/level.pak",
        "GameSDK/Levels/Campaign/Engineering/LifeSupport/terraintexture.pak",
        "GameSDK/Levels/Campaign/Engineering/PowerSource/level.pak",
        "GameSDK/Levels/Campaign/Engineering/PowerSource/terraintexture.pak",
        "GameSDK/Levels/Campaign/Executive/Arboretum/level.pak",
        "GameSDK/Levels/Campaign/Executive/Arboretum/terraintexture.pak",
        "GameSDK/Levels/Campaign/Executive/Bridge/level.pak",
        "GameSDK/Levels/Campaign/Executive/Bridge/terraintexture.pak",
        "GameSDK/Levels/Campaign/Executive/CorporateIT/level.pak",
        "GameSDK/Levels/Campaign/Executive/CorporateIT/terraintexture.pak",
        "GameSDK/Levels/Campaign/Executive/CrewFacilities/level.pak",
        "GameSDK/Levels/Campaign/Executive/CrewFacilities/terraintexture.pak",
        "GameSDK/Levels/Campaign/PlayerGenderSelect/level.pak",
        "GameSDK/Levels/Campaign/Research/Lobby/level.pak",
        "GameSDK/Levels/Campaign/Research/Lobby/TerrainTexture.pak",
        "GameSDK/Levels/Campaign/Research/Prototype/level.pak",
        "GameSDK/Levels/Campaign/Research/Prototype/terraintexture.pak",
        "GameSDK/Levels/Campaign/Research/Psychotronics/level.pak",
        "GameSDK/Levels/Campaign/Research/Psychotronics/terraintexture.pak",
        "GameSDK/Levels/Campaign/Research/ShuttleBay/level.pak",
        "GameSDK/Levels/Campaign/Research/ShuttleBay/terraintexture.pak",
        "GameSDK/Levels/Campaign/Research/SimulationLabs/level.pak",
        "GameSDK/Levels/Campaign/Research/SimulationLabs/TerrainTexture.pak",
        "GameSDK/Levels/Campaign/Research/ZeroG_UtilityTunnels/level.pak",
        "GameSDK/Levels/Campaign/Research/ZeroG_UtilityTunnels/terraintexture.pak",
        "GameSDK/Levels/Campaign/Station/Exterior/level.pak",
        "GameSDK/Levels/Campaign/Station/Exterior/terraintexture.pak",
    };

    for (const char* fakePakName : FAKE_PAKS)
    {
        fs::path fakePak = m_GameDir / fakePakName;
        fs::create_directories(fakePak.parent_path());
        fs::copy_file(emptyZip, fakePak);
    }
}

void ChairMergerTestBase::LoadMods()
{
    ASSERT_FALSE(m_TestName.empty());

    int modNumber = 1;

    for (;;)
    {
        std::string modName = fmt::format("Mod{}", modNumber);
        fs::path modDir = m_TestDir / fs::u8path(modName);

        if (!fs::exists(modDir))
            break;

        Mod& mod = m_Mods.emplace_back();
        mod.modName = modName;
        mod.displayName = modName;
        mod.version = fmt::format("1.{}", modNumber);
        mod.author = "Tester";
        mod.loadOrder = modNumber;
        mod.path = modDir;
        mod.installed = true;
        mod.enabled = true;
        mod.deployed = false;
        mod.hasXML = true;
        mod.hasLevelXML = fs::exists(modDir / "Data/Levels");

        modNumber++;
    }

    for (Mod& i : m_Mods)
    {
        m_ModsMap[i.modName] = &i;
    }

    m_ConfigManager.init(this);
}

void ChairMergerTestBase::CreateMerger()
{
    ASSERT_FALSE(m_TestName.empty());
    ASSERT_EQ(nullptr, m_pMerger);

    m_pMerger = std::make_unique<ChairMerger>(
        fs::current_path(),
        m_BaseDir / "_PreyFiles",
        m_BaseDir / "_ChairloaderPatch",
        m_TempDir,
        m_GameDir,
        static_cast<ILogger*>(this),
        static_cast<IChairManager*>(this)
    );
}

bool ChairMergerTestBase::CheckEqualDirectories(const fs::path& expected, const fs::path& dirToCheck, bool expectAllFiles)
{
    if (!fs::exists(expected))
    {
        ADD_FAILURE() << "Expected file doesn't exist: " << expected.u8string();
        return false;
    }

    if (!fs::exists(dirToCheck))
    {
        ADD_FAILURE() << "File doesn't exist: " << dirToCheck.u8string();
        return false;
    }

    EXPECT_EQ(fs::is_directory(expected), fs::is_directory(dirToCheck));

    if (fs::is_directory(dirToCheck))
    {
        // Check files in the dir
        bool isOk = true;

        for (auto& entry : fs::directory_iterator(dirToCheck))
        {
            fs::path relativePath = entry.path().lexically_relative(dirToCheck);
            isOk &= CheckEqualDirectories(expected / relativePath, dirToCheck / relativePath, false);
        }

        if (expectAllFiles)
        {
            // Check that all files in expected exist
            for (auto& entry : fs::recursive_directory_iterator(expected))
            {
                fs::path relativePath = entry.path().lexically_relative(expected);
                fs::path fullPath = dirToCheck / relativePath;

                if (!fs::exists(fullPath))
                {
                    ADD_FAILURE() << "File doesn't exist but it is expected: " << fullPath.u8string();
                    isOk = false;
                }
            }
        }

        return isOk;
    }
    else
    {
        // Compare the file
        if (dirToCheck.extension() == ".xml")
        {
            // Compare XML
            pugi::xml_document docExpected = XmlTestUtils::LoadDocument(expected);
            pugi::xml_document docActual = XmlTestUtils::LoadDocument(dirToCheck);
            return XmlTestUtils::CheckNodesEqual(docExpected, docActual);
        }
        else
        {
            // Compare data
            std::vector<uint8_t> expectedData = ReadFile(expected);
            std::vector<uint8_t> actualData = ReadFile(dirToCheck);

            if (expectedData.size() != actualData.size())
            {
                ADD_FAILURE() << "File size mismatch: \n" << expected.u8string() << " " << dirToCheck.u8string() << "\n"
                    << expectedData.size() << " " << actualData.size();
                return false;
            }

            if (memcmp(expectedData.data(), actualData.data(), expectedData.size()))
            {
                ADD_FAILURE() << "File content mismatch: \n" << expected.u8string() << "\n\n" << dirToCheck.u8string();
                return false;
            }

            return true;
        }
    }
}

std::vector<uint8_t> ChairMergerTestBase::ReadFile(const fs::path& path)
{
    std::vector<uint8_t> fileData;
    std::ifstream f;
    f.exceptions(std::ios::badbit | std::ios::failbit);
    f.open(path, std::ios::binary);
    f.seekg(0, std::ios::end);
    fileData.resize((size_t)f.tellg());
    f.seekg(0, std::ios::beg);
    f.read((char*)fileData.data(), fileData.size());
    return fileData;
}

void ChairMergerTestBase::LogString(severityLevel level, std::string_view str)
{
    std::cerr << str << '\n';

    if (level >= severityLevel::warning)
    {
        ADD_FAILURE() << "Log Fail: " << str;
    }
}

void ChairMergerTestBase::OverlayLogString(severityLevel level, std::string_view str)
{
    LogString(level, str);
}

fs::path ChairMergerTestBase::GetConfigPath()
{
    return m_TestDir / "Configs";
}

fs::path ChairMergerTestBase::GetModPath(const std::string& modName)
{
    auto it = m_ModsMap.find(modName);

    if (it == m_ModsMap.end())
        return fs::path();
    else
        return it->second->path;
}

std::vector<std::string> ChairMergerTestBase::GetModNames()
{
    std::vector<std::string> list;

    for (const Mod& i : m_Mods)
        list.push_back(i.modName);

    return list;
}

std::vector<std::string> ChairMergerTestBase::GetLegacyModNames()
{
    // TODO 2023-12-30: Add legacy mod support
    return std::vector<std::string>();
}

const std::vector<Mod>& ChairMergerTestBase::GetMods() const
{
    return m_Mods;
}

std::string ChairMergerTestBase::GetModDisplayName(const std::string& modName)
{
    auto it = m_ModsMap.find(modName);

    if (it == m_ModsMap.end())
        throw std::invalid_argument("GetModDisplayName: mod not found: " + modName);
    else
        return it->second->displayName;
}

const ModConfig* ChairMergerTestBase::GetModConfig(const std::string& modName) const
{
    return &const_cast<ConfigManager&>(m_ConfigManager).getModConfig(modName);
}

bool ChairMergerTestBase::IsModEnabled(const std::string& modName)
{
    auto it = m_ModsMap.find(modName);

    if (it == m_ModsMap.end())
        throw std::invalid_argument("IsModEnabled: mod not found: " + modName);
    else
        return it->second->enabled;
}
