// Header file automatically created from a PDB.
#pragma once

class ICrySizer;

// IResourceList
// Header:  _unknown/IResourceList.h
// Include: Prey/CrySystem/File/ICryPak.h
struct IResourceList : public _reference_target<int>
{ // Size=16 (0x10)
	virtual void Add(const char* sResourceFile) = 0;
	virtual void Clear() = 0;
	virtual bool IsExist(const char* sResourceFile) = 0;
	virtual bool Load(const char* sResourceListFilename) = 0;
	virtual const char* GetFirst() = 0;
	virtual const char* GetNext() = 0;
	virtual void GetMemoryStatistics(ICrySizer* pSizer) = 0;
};

