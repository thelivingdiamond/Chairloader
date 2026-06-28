// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/arkitem.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkNeuromod.h
class ArkNeuromod : public CArkItem // Id=80193B2 Size=384
{
public:
	string m_multiPickupModel;
	int m_multiSubMaterialId;
	_smart_ptr<IMaterial> m_pClonedMaterial;
	
	ArkNeuromod();
	virtual void LoadCachedProperties();
	virtual const char *GetPickupModel() const;
	virtual void SetupModel(bool _bFirstPerson);
	virtual ~ArkNeuromod();
	
#if 0
	bool IsMultiModel() const;
#endif
	
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkNeuromod *const _this)>(0x11A1F80);
	static inline auto FGetPickupModel = PreyFunction<const char *(ArkNeuromod const *const _this)>(0x11A1F40);
	static inline auto FSetupModel = PreyFunction<void(ArkNeuromod *const _this, bool _bFirstPerson)>(0x11A2260);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ArkItem.h>

struct IMaterial;

// ArkNeuromod
// Header:  Prey/GameDll/ark/ArkNeuromod.h
class ArkNeuromod : public CArkItem
{ // Size=408 (0x198)
public:
	string m_multiPickupModel;
	int m_multiSubMaterialId;
	_smart_ptr<IMaterial> m_pClonedMaterial;

	ArkNeuromod();
	virtual void LoadCachedProperties();
	virtual const char* GetPickupModel() const;
	virtual void SetupModel(bool _bFirstPerson);

#if 0
	bool IsMultiModel() const;
#endif

	static inline auto FArkNeuromodOv2 = PreyFunction<void(ArkNeuromod* const _this)>(0x121F350);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkNeuromod* const _this)>(0x121F450);
	static inline auto FGetPickupModel = PreyFunction<const char* (const ArkNeuromod* const _this)>(0x121F410);
	static inline auto FSetupModel = PreyFunction<void(ArkNeuromod* const _this, bool _bFirstPerson)>(0x121F730);
};
#endif // !MOONCRASH
