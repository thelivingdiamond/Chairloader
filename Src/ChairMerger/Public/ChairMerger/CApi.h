#pragma once
#include <ChairMerger/ChairMergerSettings.h>
#include <ChairMerger/Export.h>

#ifdef __cplusplus
extern "C" {
#endif

    struct ChairMergerMod
    {
        //! Mod type. See ChairMerger::EModType
        int type;

        //! The mod name. Used for logging and enabled mod checks.
        const char* modName;

        //! Path to the Data folder.
        const char* dataPath;

        //! Path to the config XML. May be null.
        const char* configPath;
    };

    struct ChairMergerParams
    {
        //! ChairMerger files directory.
        const char* mergerFiles;

        //! Source Prey files directory.
        const char* preyFiles;

        //! Where to place output directories.
        const char* outputRoot;

        //! Game directory.
        const char* gamePath;

        //! The list of mods.
        const struct ChairMergerMod* mods;
        size_t modCount;

        //! Merger settings.
        struct ChairMergerSettings settings;

        //! Callback for log messages. String may not be null-terminated.
        void (*pfnLogCallback)(int verbosity, const char* msg, size_t msgLen);
    };

    //! Runs ChairMerger with specified parameters. Can be called from C code or via FFI.
    bool CHAIRMERGER_EXPORT ChairMerger_RunMerging(const struct ChairMergerParams* pParams);

#ifdef __cplusplus
}
#endif
