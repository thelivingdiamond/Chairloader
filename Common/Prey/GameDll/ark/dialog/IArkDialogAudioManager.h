// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkDialogAudioTrigger;
class ArkDialogLoader;
class IArkDialogLoadListener;

// Prey/GameDll/ark/dialog/IArkDialogAudioManager.h
class IArkDialogAudioManager // Id=80020CA Size=8
{
public:
	enum class ELoadResult
	{
		failed = 0,
		loading = 1,
		loaded = 2,
	};

	virtual IArkDialogAudioManager::ELoadResult Load(unsigned arg0, IArkDialogLoadListener &arg1) = 0;
	virtual void Unload(unsigned arg0, IArkDialogLoadListener &arg1) = 0;
	virtual void OnLoad(unsigned arg0, ArkDialogLoader *arg1, bool arg2) = 0;
	virtual bool IsLoaded(unsigned arg0) = 0;
	virtual uint64_t GeneratePlaybackHandle() = 0;
	virtual void RegisterTrigger(ArkDialogAudioTrigger const *arg0) = 0;
	virtual void UnregisterTrigger(ArkDialogAudioTrigger const *arg0) = 0;
	virtual bool IsRegistered(ArkDialogAudioTrigger const *arg0) const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkDialogAudioTrigger;
class ArkDialogLoader;
class IArkDialogLoadListener;

// IArkDialogAudioManager
// Header:  Prey/GameDll/ark/dialog/IArkDialogAudioManager.h
class IArkDialogAudioManager
{ // Size=8 (0x8)
public:
	enum class ELoadResult
	{
		failed = 0,
		loading = 1,
		loaded = 2,
	};

	virtual IArkDialogAudioManager::ELoadResult Load(unsigned _controlId, IArkDialogLoadListener& _listener) = 0;
	virtual void Unload(unsigned _controlId, IArkDialogLoadListener& _listener) = 0;
	virtual void OnLoad(unsigned _controlId, ArkDialogLoader* _pLoader, bool _bSuccess) = 0;
	virtual bool IsLoaded(unsigned _controlId) = 0;
	virtual uint64_t GeneratePlaybackHandle() = 0;
	virtual void RegisterTrigger(const ArkDialogAudioTrigger* _pTrigger) = 0;
	virtual void UnregisterTrigger(const ArkDialogAudioTrigger* _pTrigger) = 0;
	virtual bool IsRegistered(const ArkDialogAudioTrigger* _pTrigger) const = 0;
};
#endif // !MOONCRASH
