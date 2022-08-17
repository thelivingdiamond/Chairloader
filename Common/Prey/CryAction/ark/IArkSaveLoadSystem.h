// Header file automatically created from a PDB.

#pragma once
#include <ChairLoader/pch.h>
#include <Prey/CryCore/functor.h>

class IArkSaveLoadListener;

// Header: MadeUp
// _unknown/IArkSaveLoadSystem.h
class IArkSaveLoadSystem // Id=8002008 Size=8
{
public:
	virtual void SetCampaignSlot(const int arg0) = 0;
	virtual int GetCampaignSlot() const = 0;
	virtual bool InLevelTransition() const = 0;
	virtual bool IsRestoringLevelState() const = 0;
	virtual void ClearMetadataCache() = 0;
	virtual void RegisterListener(IArkSaveLoadListener *arg0) = 0;
	virtual void UnregisterListener(IArkSaveLoadListener *arg0) = 0;
	virtual void SaveNewGamePlusData(int arg0, Functor1<TSerialize> arg1) = 0;
	virtual bool LoadNewGamePlusData(int arg0, Functor1<TSerialize> arg1) = 0;
};

