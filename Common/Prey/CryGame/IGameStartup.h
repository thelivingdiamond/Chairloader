// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryGame/IGame.h>
#include <Prey/CryGame/IGameStartup.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Chairloader/PreyFunction.h>

struct IAntiCheatManager;
class IArkDoor;
class IArkEncounterManager;
class IArkFactionManager;
struct IArkGlintConfigManager;
class IArkGlooIslandNavLinkManager;
class IArkGravShaft;
class IArkMetaTagManager;
class IArkNpc;
class IArkPADialogManager;
class IArkPatrolManager;
class IArkPlayer;
struct IArkPostEffectManager;
class IArkResponseManager;
class ICrySizer;
struct IGameFramework;
struct IGamePhysicsSettings;
struct IGameRef;
struct IGameStateRecorder;
struct IGameToEditorInterface;
struct IGameWarningsListener;
struct IGameplayListener;
struct SRenderingPassInfo;
struct SSystemInitParams;
class XmlNodeRef;

// Header: Exact
// CryEngine/crycommon/IGameStartup.h
struct IGameStartup // Id=8001E58 Size=8
{
	using TEntryFunction = IGameStartup *(*)();
	
	virtual ~IGameStartup();
	virtual IGameRef Init(SSystemInitParams &arg0) = 0;
	virtual void Shutdown() = 0;
	virtual int Update(bool arg0, unsigned arg1) = 0;
	virtual bool GetRestartLevel(char **arg0) = 0;
	virtual const char *GetPatch() const = 0;
	virtual bool GetRestartMod(char *arg0, int arg1) = 0;
	virtual int Run(const char *arg0) = 0;
	virtual const uint8_t *GetRSAKey(unsigned *pKeySize) const;
	
	static inline auto FGetRSAKey = PreyFunction<const uint8_t *(IGameStartup const *const _this, unsigned *pKeySize)>(0x17399C0);
    static inline auto FInit2 = PreyFunction<IGameRef&(IGameStartup *_this, IGameRef &result, SSystemInitParams &startupParams)>(0x1739A90);
};

