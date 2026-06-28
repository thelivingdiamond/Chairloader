// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
//#include <Prey/CryAction/IPlayerProfiles.h>

// Header: Override
// Prey/GameDll/ark/iface/ISaveGameEnumerator.h
#include <Prey/ArkStubs.h>
struct ISaveGameEnumerator // Id=8001FC9 Size=8
{
	struct SGameMetaData // Id=8001FCA Size=56
	{
		const char *levelName;
		const char *gameRules;
		int fileVersion;
		const char *buildVersion;
		int64_t saveTime;
		int64_t loadTime;
		XmlNodeRef xmlMetaDataNode;
	};

	struct SGameDescription // Id=8001FCB Size=80
	{
		const char *name;
		const char *humanName;
		const char *description;
		ISaveGameEnumerator::SGameMetaData metaData;
	};

	virtual ~ISaveGameEnumerator();
	virtual int GetSlot() const = 0;
	virtual void Delete(const char *const arg0) = 0;
	virtual void Update(const char *const arg0) = 0;
	virtual int GetCount() = 0;
	virtual bool GetDescription(int arg0, ISaveGameEnumerator::SGameDescription &arg1) = 0;
	virtual _smart_ptr<ISaveGameThumbnail> GetThumbnail(int arg0) = 0;
	virtual _smart_ptr<ISaveGameThumbnail> GetThumbnail(const char *arg0) = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>

struct ISaveGameThumbnail;

// ISaveGameEnumerator
// Header:  Prey/GameDll/ark/iface/ISaveGameEnumerator.h
// Include: Prey/CryAction/IPlayerProfiles.h
struct ISaveGameEnumerator
{ // Size=8 (0x8)
	// ISaveGameEnumerator::SGameMetaData
	// Header:  Prey/GameDll/ark/iface/ISaveGameEnumerator.h
	struct SGameMetaData
	{ // Size=56 (0x38)
		const char* levelName;
		const char* gameRules;
		int fileVersion;
		const char* buildVersion;
		int64_t saveTime;
		int64_t loadTime;
		XmlNodeRef xmlMetaDataNode;
	};

	// ISaveGameEnumerator::SGameDescription
	// Header:  Prey/GameDll/ark/iface/ISaveGameEnumerator.h
	struct SGameDescription
	{ // Size=80 (0x50)
		const char* name;
		const char* humanName;
		const char* description;
		ISaveGameEnumerator::SGameMetaData metaData;
	};

	virtual ~ISaveGameEnumerator();
	virtual int GetSlot() const = 0;
	virtual void Delete(const char* const _name) = 0;
	virtual void Update(const char* const _name) = 0;
	virtual int GetCount() = 0;
	virtual bool GetDescription(int index, ISaveGameEnumerator::SGameDescription& desc) = 0;
	virtual _smart_ptr<ISaveGameThumbnail> GetThumbnail(int index) = 0;
	virtual _smart_ptr<ISaveGameThumbnail> GetThumbnail(const char* saveGameName) = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};
#endif // !MOONCRASH
