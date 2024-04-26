#pragma once
#include <gtest/gtest.h>
#include <ChairMerger/ChairMerger.h>
#include <Manager/IChairManager.h>
#include <Manager/ConfigManager.h>
#include "../../ChairManager/Mod.h" // TODO 2024-04-26: Fix this

class ChairMergerTestBase : public ::testing::Test, private IChairManager
{
public:
    // testing::Test
    void SetUp() override;
    void TearDown() override;

protected:
    std::string m_TestName;
    fs::path m_BaseDir; //!< Where common test files are located
    fs::path m_TestDir; //!< Where this test's files are located
    fs::path m_TempDir; //!< Temporary files (e.g. merging results)
    fs::path m_GameDir; //!< Game directory
    std::unique_ptr<ChairMerger> m_pMerger;

    std::vector<Mod> m_Mods;
    std::map<std::string, Mod*> m_ModsMap;
    ConfigManager m_ConfigManager;

    //! Initializes the test paths.
    void InitTest(const std::string& testName);

    //! Loads mods from the current test directory
    void LoadMods();

    //! Creates the ChairMerger instance for current test.
    void CreateMerger();

    //! Checks that two directories contain equivalent files.
    //! @param  expected        The directory with expected files.
    //! @param  dirToCheck      Directory to check with expected.
    //! @param  expectAllFiles  If false, only files in dirToCheck are checked. If true, return false if any files are missing.
    bool CheckEqualDirectories(const fs::path& expected, const fs::path& dirToCheck, bool expectAllFiles);

private:
    std::vector<uint8_t> ReadFile(const fs::path& path);

    // IChairManager
    virtual void LogString(severityLevel level, std::string_view str) override;
    virtual void OverlayLogString(severityLevel level, std::string_view str) override;
    virtual fs::path GetConfigPath() override;
    virtual fs::path GetModPath(const std::string& modName) override;
    virtual std::vector<std::string> GetModNames() override;
    virtual std::vector<std::string> GetLegacyModNames() override;
    virtual const std::vector<Mod>& GetMods() const override;
    virtual std::string GetModDisplayName(const std::string& modName) override;
    virtual const ModConfig* GetModConfig(const std::string& modName) const override;
    virtual bool IsModEnabled(const std::string& modName) override;
};
