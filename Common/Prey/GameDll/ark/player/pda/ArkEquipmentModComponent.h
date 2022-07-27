// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkEquipmentMod;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkEquipmentModComponent.h
class ArkEquipmentModComponent // Id=80173B4 Size=64
{
public:
	static constexpr const int k_maxInstalled = 8;
	const bool m_bSuitMods;
	std::vector<unsigned int> m_ownedChipsets;
	std::array<unsigned int,8> m_installedChipsets;
	
	ArkEquipmentModComponent(bool _bSuitMods);
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this,_ser); }
	void Reset() { FReset(this); }
	void AddToInventory(unsigned _chipsetId) { FAddToInventory(this,_chipsetId); }
	void RemoveFromInventory(unsigned _chipsetId) { FRemoveFromInventory(this,_chipsetId); }
	void InstallMod(ArkEquipmentMod &_mod) { FInstallMod(this,_mod); }
	void UninstallMod(ArkEquipmentMod &_mod) { FUninstallMod(this,_mod); }
	bool IsInstalled(ArkEquipmentMod const &_mod) const { return FIsInstalled(this,_mod); }
	int GetNumInstallableSlots() const { return FGetNumInstallableSlots(this); }
	int GetNumInstalledChipsets() const { return FGetNumInstalledChipsets(this); }
	std::array<unsigned int,8> const &GetInstalledChipsets() const { return FGetInstalledChipsetsOv1(this); }
	ArkEquipmentMod *GetChipsetAtIndex(int _index) const { return FGetChipsetAtIndex(this,_index); }
	void ActivateMod(const uint64_t _archetypeId) const { FActivateMod(this,_archetypeId); }
	void DeactivateMod(const uint64_t _archetypeId) const { FDeactivateMod(this,_archetypeId); }
	int GetIndexOfChipset(unsigned _modId) const { return FGetIndexOfChipset(this,_modId); }
	int GetInstallIndexOfChipset(unsigned _chipsetId) const { return FGetInstallIndexOfChipset(this,_chipsetId); }
	bool IsModInstalled(const uint64_t _archetypeId) const { return FIsModInstalled(this,_archetypeId); }
	uint64_t GetModSignalPackage(const uint64_t _archetypeId) const { return FGetModSignalPackage(this,_archetypeId); }
	bool HasSpace(ArkEquipmentMod const &_chipset) const { return FHasSpace(this,_chipset); }
	
#if 0
	std::vector<unsigned int> const &GetAllChipsets() const;
	std::vector<ArkEquipmentMod *> GetInstalledChipsets(const uint64_t arg0) const;
	void DoMetricsSnapshot(XmlNodeRef const &arg0) const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(ArkEquipmentModComponent *const _this, TSerialize _ser)>(0x132E2C0);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkEquipmentModComponent *const _this, TSerialize _ser)>(0x132E580);
	static inline auto FReset = PreyFunction<void(ArkEquipmentModComponent *const _this)>(0x132E2A0);
	static inline auto FAddToInventory = PreyFunction<void(ArkEquipmentModComponent *const _this, unsigned _chipsetId)>(0x132DA10);
	static inline auto FRemoveFromInventory = PreyFunction<void(ArkEquipmentModComponent *const _this, unsigned _chipsetId)>(0x132E1D0);
	static inline auto FInstallMod = PreyFunction<void(ArkEquipmentModComponent *const _this, ArkEquipmentMod &_mod)>(0x132E010);
	static inline auto FUninstallMod = PreyFunction<void(ArkEquipmentModComponent *const _this, ArkEquipmentMod &_mod)>(0x132EA80);
	static inline auto FIsInstalled = PreyFunction<bool(ArkEquipmentModComponent const *const _this, ArkEquipmentMod const &_mod)>(0x132E070);
	static inline auto FGetNumInstallableSlots = PreyFunction<int(ArkEquipmentModComponent const *const _this)>(0x132DE50);
	static inline auto FGetNumInstalledChipsets = PreyFunction<int(ArkEquipmentModComponent const *const _this)>(0x132DE90);
	static inline auto FGetInstalledChipsetsOv1 = PreyFunction<std::array<unsigned int,8> const &(ArkEquipmentModComponent const *const _this)>(0x10BD820);
	static inline auto FGetChipsetAtIndex = PreyFunction<ArkEquipmentMod *(ArkEquipmentModComponent const *const _this, int _index)>(0x132DCB0);
	static inline auto FActivateMod = PreyFunction<void(ArkEquipmentModComponent const *const _this, const uint64_t _archetypeId)>(0x132D8D0);
	static inline auto FDeactivateMod = PreyFunction<void(ArkEquipmentModComponent const *const _this, const uint64_t _archetypeId)>(0x132DB70);
	static inline auto FGetIndexOfChipset = PreyFunction<int(ArkEquipmentModComponent const *const _this, unsigned _modId)>(0x132DCE0);
	static inline auto FGetInstallIndexOfChipset = PreyFunction<int(ArkEquipmentModComponent const *const _this, unsigned _chipsetId)>(0x132DD10);
	static inline auto FIsModInstalled = PreyFunction<bool(ArkEquipmentModComponent const *const _this, const uint64_t _archetypeId)>(0x132E0C0);
	static inline auto FGetModSignalPackage = PreyFunction<uint64_t(ArkEquipmentModComponent const *const _this, const uint64_t _archetypeId)>(0x132DD40);
	static inline auto FHasSpace = PreyFunction<bool(ArkEquipmentModComponent const *const _this, ArkEquipmentMod const &_chipset)>(0x132DEE0);
};

