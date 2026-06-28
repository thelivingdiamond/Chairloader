// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/GameDll/ark/spatial/arkspatialmanagerentry.h
template <typename T>
class ArkSpatialManagerEntry // Id=80152EF Size=16
{
public:
	using ImplType = T;
	using KeyType = typename T::KeyType;
	
	T m_impl;
	KeyType m_key;
	
#if 0
	void Reset();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_apextentacle.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_typhonnest.h>
#include <_unknown/ArkSpatialManagerKey.h>

// ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry.h
class ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>
{ // Size=16 (0x10)
public:
	using ImplType = ArkSpatialManagerEntryImpl_ApexTentacle;
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>;

	ArkSpatialManagerEntryImpl_ApexTentacle m_impl;
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> m_key;

	void Reset() { FReset(this); }

#if 0
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>();
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>&& _arg0_);
	~ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>();
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>& operator=(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>&& _arg0_);
#endif

	static inline auto FReset = PreyFunction<void(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle>* const _this)>(0x130B5B0);
};

// ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry.h
class ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>
{ // Size=16 (0x10)
public:
	using ImplType = ArkSpatialManagerEntryImpl_TyphonNest;
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>;

	ArkSpatialManagerEntryImpl_TyphonNest m_impl;
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest> m_key;

	void Reset() { FReset(this); }

#if 0
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>();
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>&& _arg0_);
	~ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>();
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>& operator=(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>&& _arg0_);
#endif

	static inline auto FReset = PreyFunction<void(ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_TyphonNest>* const _this)>(0x11DC790);
};
#endif // !MOONCRASH
