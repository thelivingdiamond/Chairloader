#include <ChairMerger/CApi.h>
#include <ChairMerger/ChairMerger.h>
#include <Manager/ILogger.h>

namespace
{

using LogCallbackFn = void (*)(int verbosity, const char* msg, size_t msgLen);

class CallbackLogger : public ILogger
{
public:
    CallbackLogger(LogCallbackFn callback)
    {
        m_pfnCallback = callback;
    }

    // ILogger
    virtual void LogString(severityLevel level, std::string_view str) override
    {
        if (m_pfnCallback)
            m_pfnCallback((int)level, str.data(), str.size());
    }

    virtual void OverlayLogString(severityLevel level, std::string_view str) override
    {
        // Not supported
        std::abort();
    }

private:
    LogCallbackFn m_pfnCallback = nullptr;
};

} // namespace

bool CHAIRMERGER_EXPORT ChairMerger_RunMerging(const ChairMergerParams* pParams)
{
    CallbackLogger logger(pParams->pfnLogCallback);

    std::vector<ChairMerger::Mod> mods;

    for (size_t i = 0; i < pParams->modCount; i++)
    {
        const ChairMergerMod& sourceMod = pParams->mods[i];
        ChairMerger::Mod& mergedMod = mods.emplace_back();
        mergedMod.type = (ChairMerger::EModType)sourceMod.type;
        mergedMod.modName = sourceMod.modName;
        mergedMod.dataPath = fs::u8path(sourceMod.dataPath);

        if (sourceMod.configPath)
        {
            pugi::xml_parse_result result = mergedMod.config.load_file(fs::u8path(sourceMod.configPath).string().c_str());

            if (!result)
            {
                logger.Log(
                    severityLevel::error,
                    "Failed to load mod config '%s' (file: %s). Reason: %s. Offset: %d",
                    mergedMod.modName,
                    sourceMod.configPath,
                    result.description(),
                    result.offset);
                return false;
            }
        }
    }

    ChairMerger merger(
        fs::u8path(pParams->mergerFiles),
        fs::u8path(pParams->preyFiles),
        fs::u8path(pParams->outputRoot),
        fs::u8path(pParams->gamePath),
        &logger
    );

    merger.SetMods(std::move(mods));
    merger.SetSettings(pParams->settings);

    merger.Deploy();
    return !merger.DeployFailed();
}
