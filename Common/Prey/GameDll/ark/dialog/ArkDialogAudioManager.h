// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/IArkDialogAudioManager.h>
#include <Prey/GameDll/ark/dialog/arkdialogaudiomanager.h>

class ArkDialogAudioTrigger;
class IArkDialogLoadListener;
struct SAudioRequestInfo;

// Header: FromCpp
// Prey/GameDll/ark/dialog/arkdialogaudiomanager.h
class ArkDialogLoader // Id=80020CC Size=56
{
public:
	enum class EArkLoadState
	{
		CryModuleCRTFree = 0,
		loading = 1,
		loadNotice = 2,
		loaded = 3,
	};

	std::vector<IArkDialogLoadListener *> m_listeners;
	std::vector<IArkDialogLoadListener *> m_pendingRemovals;
	unsigned m_controlId;
	ArkDialogLoader::EArkLoadState m_state;
	
	void RemoveRef(IArkDialogLoadListener &_listener) { FRemoveRef(this,_listener); }
	void OnLoad(const bool _bSuccess) { FOnLoad(this,_bSuccess); }
	void Unload() { FUnload(this); }
	
#if 0
	void Load(unsigned arg0);
	void AddRef(IArkDialogLoadListener &arg0);
	bool IsLoaded() const;
	bool IsFree() const;
	unsigned GetControlId() const;
	unsigned GetRefCount() const;
	ArkDialogLoader::EArkLoadState GetState() const;
#endif
	
	static inline auto FRemoveRef = PreyFunction<void(ArkDialogLoader *const _this, IArkDialogLoadListener &_listener)>(0x13F7220);
	static inline auto FOnLoad = PreyFunction<void(ArkDialogLoader *const _this, const bool _bSuccess)>(0x13F7080);
	static inline auto FUnload = PreyFunction<void(ArkDialogLoader *const _this)>(0x13F7300);
};

// Header: Exact
// Prey/GameDll/ark/dialog/ArkDialogAudioManager.h
class ArkDialogAudioManager : public IArkDialogAudioManager // Id=80139B0 Size=936
{
public:
	using TDialogLoaders = std::array<ArkDialogLoader,16>;
	
	std::vector<ArkDialogAudioTrigger const *> m_triggers;
	std::array<ArkDialogLoader,16> m_loaders;
	uint64_t m_playbackHandleGen;
	static int s_drawDialogAudioDebug;
	
	ArkDialogAudioManager();
	virtual ~ArkDialogAudioManager();
	virtual IArkDialogAudioManager::ELoadResult Load(unsigned _controlId, IArkDialogLoadListener &_listener);
	virtual void Unload(unsigned _controlId, IArkDialogLoadListener &_listener);
	virtual void OnLoad(unsigned _controlId, ArkDialogLoader *_pLoader, bool _bSuccess);
	virtual bool IsLoaded(unsigned _controlId);
	void Update() { FUpdate(this); }
	virtual uint64_t GeneratePlaybackHandle();
	virtual void RegisterTrigger(ArkDialogAudioTrigger const *_pTrigger);
	virtual void UnregisterTrigger(ArkDialogAudioTrigger const *_pTrigger);
	virtual bool IsRegistered(ArkDialogAudioTrigger const *_pTrigger) const;
	static void OnAudioEvent(SAudioRequestInfo const *const pAudioRequestInfo) { FOnAudioEvent(pAudioRequestInfo); }
	
	static inline auto FBitNotArkDialogAudioManager = PreyFunction<void(ArkDialogAudioManager *const _this)>(0x13F6AE0);
	static inline auto FLoad = PreyFunction<IArkDialogAudioManager::ELoadResult(ArkDialogAudioManager *const _this, unsigned _controlId, IArkDialogLoadListener &_listener)>(0x13F6CE0);
	static inline auto FUnload = PreyFunction<void(ArkDialogAudioManager *const _this, unsigned _controlId, IArkDialogLoadListener &_listener)>(0x13F72C0);
	static inline auto FOnLoad = PreyFunction<void(ArkDialogAudioManager *const _this, unsigned _controlId, ArkDialogLoader *_pLoader, bool _bSuccess)>(0x13F6FE0);
	static inline auto FIsLoaded = PreyFunction<bool(ArkDialogAudioManager *const _this, unsigned _controlId)>(0x13F6C50);
	static inline auto FUpdate = PreyFunction<void(ArkDialogAudioManager *const _this)>(0x13F7430);
	static inline auto FGeneratePlaybackHandle = PreyFunction<uint64_t(ArkDialogAudioManager *const _this)>(0x13F6C30);
	static inline auto FRegisterTrigger = PreyFunction<void(ArkDialogAudioManager *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0x13F7190);
	static inline auto FUnregisterTrigger = PreyFunction<void(ArkDialogAudioManager *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0x13F73A0);
	static inline auto FIsRegistered = PreyFunction<bool(ArkDialogAudioManager const *const _this, ArkDialogAudioTrigger const *_pTrigger)>(0x13F6C80);
	static inline auto FOnAudioEvent = PreyFunction<void(SAudioRequestInfo const *const pAudioRequestInfo)>(0x13F6E50);
};

