// Header file automatically created from a PDB.
#pragma once

struct IActionMap;
struct IAttributeEnumerator;
struct ILevelRotationFile;
struct ILoadGame;
struct ISaveGame;
struct ISaveGameEnumerator;
class TFlowInputData;
class XmlNodeRef;

// IPlayerProfile
// Header:  _unknown/IPlayerProfile.h
// Include: Prey/CryAction/IPlayerProfiles.h
struct IPlayerProfile
{ // Size=8 (0x8)
	virtual ~IPlayerProfile();
	virtual bool Reset() = 0;
	virtual bool IsDefault() const = 0;
	virtual void LoadGamerProfileDefaults() = 0;
	virtual const char* GetName() = 0;
	virtual const char* GetUserId() = 0;
	virtual IActionMap* GetActionMap(const char* name) = 0;
	virtual bool SetAttribute(const char* name, const TFlowInputData& value) = 0;
	virtual bool ResetAttribute(const char* name) = 0;
	virtual void DeleteAttribute(const char* name) = 0;
	virtual bool GetAttribute(const char* name, TFlowInputData& val, bool bUseDefaultFallback) const = 0;
	virtual _smart_ptr<IAttributeEnumerator> CreateAttributeEnumerator() = 0;
	virtual _smart_ptr<ISaveGameEnumerator> CreateSaveGameEnumerator(int _slot) = 0;
	virtual ISaveGame* CreateSaveGame(int _slot) = 0;
	virtual ILoadGame* CreateLoadGame(int _slot) = 0;
	virtual bool DeleteSaveGame(int _slot, const char* name) = 0;
	virtual XmlNodeRef GetLevelState(const int _slot, const char* const _levelName) = 0;
	virtual ILevelRotationFile* GetLevelRotationFile(const char* name) = 0;
};

