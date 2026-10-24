// Header file automatically created from a PDB.
#pragma once

class ICrySizer;

// IGameSharedParameters
// Header:  _unknown/IGameSharedParameters.h
struct IGameSharedParameters
{ // Size=16 (0x10)
	unsigned m_refs;

	virtual ~IGameSharedParameters();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual const char* GetDataType() const = 0;
	virtual void ReleaseLevelResources() = 0;

#if 0
	IGameSharedParameters();
	void AddRef() const;
	unsigned GetRefCount() const;
	void Release() const;
#endif
};

