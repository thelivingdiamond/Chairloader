// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/arkpdapageequipmentmods.h>

class ArkEquipmentModComponent;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapagescopechipsets.h
class CArkPDAPageScopeChipsets : public CArkPDAPageEquipmentMods // Id=801BA73 Size=152
{
public:
	CArkPDAPageScopeChipsets();
	virtual void Reset();
	virtual void Open();
	virtual ArkEquipmentModComponent &GetChipsetComponent() const;
	virtual int GetChipsetType() const;
	virtual ~CArkPDAPageScopeChipsets();
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FReset = PreyFunction<void(CArkPDAPageScopeChipsets *const _this)>(0x134B3F0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageScopeChipsets *const _this)>(0x134B230);
	static inline auto FGetChipsetComponent = PreyFunction<ArkEquipmentModComponent &(CArkPDAPageScopeChipsets const *const _this)>(0x134B1E0);
	static inline auto FGetChipsetType = PreyFunction<int(CArkPDAPageScopeChipsets const *const _this)>(0x134B200);
};

