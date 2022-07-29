// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/arkpdapageequipmentmods.h>

class ArkEquipmentModComponent;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagesuitchipsets.h
class CArkPDAPageSuitChipsets : public CArkPDAPageEquipmentMods // Id=801BADB Size=152
{
public:
	CArkPDAPageSuitChipsets();
	virtual void Reset();
	virtual void Open();
	virtual ArkEquipmentModComponent &GetChipsetComponent() const;
	virtual int GetChipsetType() const;
	virtual ~CArkPDAPageSuitChipsets();
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FReset = PreyFunction<void(CArkPDAPageSuitChipsets *const _this)>(0x134EE70);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageSuitChipsets *const _this)>(0x134ECD0);
	static inline auto FGetChipsetComponent = PreyFunction<ArkEquipmentModComponent &(CArkPDAPageSuitChipsets const *const _this)>(0x134EB40);
	static inline auto FGetChipsetType = PreyFunction<int(CArkPDAPageSuitChipsets const *const _this)>(0x134EB60);
};

