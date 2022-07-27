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

