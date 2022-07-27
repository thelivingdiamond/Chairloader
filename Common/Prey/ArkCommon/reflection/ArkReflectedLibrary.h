// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/ArkCommon/reflection/ArkReflectedLibrary.h
class ArkReflectedLibrary : public ArkReflectedObject // Id=8009BA8 Size=8
{
public:
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual bool Shutdown();
	virtual bool IsAlwaysLoaded() const;
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10586A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105CE70);
	static inline auto FInit = PreyFunction<bool(ArkReflectedLibrary *const _this)>(0xDD23F0);
	static inline auto FShutdown = PreyFunction<bool(ArkReflectedLibrary *const _this)>(0xDD23F0);
	static inline auto FIsAlwaysLoaded = PreyFunction<bool(ArkReflectedLibrary const *const _this)>(0xDD23F0);
};

