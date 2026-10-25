// Header file automatically created from a PDB.
#pragma once

class ICrySizer;
struct SGameEffectParams;

// IGameEffect
// Header:  _unknown/IGameEffect.h
struct IGameEffect
{ // Size=8 (0x8)
	virtual ~IGameEffect();
	virtual void Initialise(const SGameEffectParams* gameEffectParams) = 0;
	virtual void Release() = 0;
	virtual void Update(float frameTime) = 0;
	virtual void SetActive(bool isActive) = 0;
	virtual void SetFlag(unsigned flag, bool state) = 0;
	virtual bool IsFlagSet(unsigned flag) const = 0;
	virtual unsigned GetFlags() const = 0;
	virtual void SetFlags(unsigned flags) = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
	virtual const char* GetName() const = 0;
	virtual IGameEffect* Next() const = 0;
	virtual IGameEffect* Prev() const = 0;
	virtual void SetNext(IGameEffect* newNext) = 0;
	virtual void SetPrev(IGameEffect* newPrev) = 0;
};

