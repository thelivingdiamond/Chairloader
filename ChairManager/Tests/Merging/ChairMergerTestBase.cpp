#include "Tests/Merging/ChairMergerTestBase.h"

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
    m_TempDir = m_BaseDir / "_temp";

    if (fs::exists(m_TempDir))
        fs::remove_all(m_TempDir);

    fs::create_directories(m_TempDir);
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
        m_BaseDir / "_GamePath",
        static_cast<ILogger*>(this),
        static_cast<IChairManager*>(this)
    );
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
