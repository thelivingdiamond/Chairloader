// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkEquipmentMod;
class XmlNodeRef;

// ArkEquipmentModComponent
// Header:  Prey/GameDll/ark/player/pda/ArkEquipmentModComponent.h
class ArkEquipmentModComponent
{ // Size=64 (0x40)
public:
	static constexpr const int k_maxInstalled = 8;
	const bool m_bSuitMods;
	std::vector<unsigned int> m_ownedChipsets;
	std::array<unsigned int,8> m_installedChipsets;

	ArkEquipmentModComponent(bool _bSuitMods);
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this, _ser); }
	void Reset() { FReset(this); }
	void AddToInventory(unsigned _chipsetId) { FAddToInventory(this, _chipsetId); }
	void RemoveFromInventory(unsigned _chipsetId) { FRemoveFromInventory(this, _chipsetId); }
	void InstallMod(ArkEquipmentMod& _mod) { FInstallMod(this, _mod); }
	void UninstallMod(ArkEquipmentMod& _mod) { FUninstallMod(this, _mod); }
	bool IsInstalled(const ArkEquipmentMod& _mod) const { return FIsInstalled(this, _mod); }
	int GetNumInstallableSlots() const { return FGetNumInstallableSlots(this); }
	int GetNumInstalledChipsets() const { return FGetNumInstalledChipsets(this); }
	const std::array<unsigned int,8>& GetInstalledChipsets() const { return FGetInstalledChipsetsOv1(this); }
	ArkEquipmentMod* GetChipsetAtIndex(int _index) const { return FGetChipsetAtIndex(this, _index); }
	void ActivateMod(const uint64_t _archetypeId) const { FActivateMod(this, _archetypeId); }
	void DeactivateMod(const uint64_t _archetypeId) const { FDeactivateMod(this, _archetypeId); }
	int GetIndexOfChipset(unsigned _modId) const { return FGetIndexOfChipset(this, _modId); }
	int GetInstallIndexOfChipset(unsigned _chipsetId) const { return FGetInstallIndexOfChipset(this, _chipsetId); }
	bool IsModInstalled(const uint64_t _archetypeId) const { return FIsModInstalled(this, _archetypeId); }
	uint64_t GetModSignalPackage(const uint64_t _archetypeId) const { return FGetModSignalPackage(this, _archetypeId); }
	bool HasSpace(const ArkEquipmentMod& _chipset) const { return FHasSpace(this, _chipset); }

#if 0
	const std::vector<unsigned int>& GetAllChipsets() const;
	std::vector<ArkEquipmentMod*> GetInstalledChipsets(const uint64_t _arg0_) const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
#endif

	static inline auto FArkEquipmentModComponentOv2 = PreyFunction<void(ArkEquipmentModComponent* const _this, bool _bSuitMods)>(0x132D8A0);
	static inline auto FSerialize = PreyFunction<void(ArkEquipmentModComponent* const _this, TSerialize _ser)>(0x132E2C0);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkEquipmentModComponent* const _this, TSerialize _ser)>(0x132E580);
	static inline auto FReset = PreyFunction<void(ArkEquipmentModComponent* const _this)>(0x132E2A0);
	static inline auto FAddToInventory = PreyFunction<void(ArkEquipmentModComponent* const _this, unsigned _chipsetId)>(0x132DA10);
	static inline auto FRemoveFromInventory = PreyFunction<void(ArkEquipmentModComponent* const _this, unsigned _chipsetId)>(0x132E1D0);
	static inline auto FInstallMod = PreyFunction<void(ArkEquipmentModComponent* const _this, ArkEquipmentMod& _mod)>(0x132E010);
	static inline auto FUninstallMod = PreyFunction<void(ArkEquipmentModComponent* const _this, ArkEquipmentMod& _mod)>(0x132EA80);
	static inline auto FIsInstalled = PreyFunction<bool(const ArkEquipmentModComponent* const _this, const ArkEquipmentMod& _mod)>(0x132E070);
	static inline auto FGetNumInstallableSlots = PreyFunction<int(const ArkEquipmentModComponent* const _this)>(0x132DE50);
	static inline auto FGetNumInstalledChipsets = PreyFunction<int(const ArkEquipmentModComponent* const _this)>(0x132DE90);
	static inline auto FGetInstalledChipsetsOv1 = PreyFunction<const std::array<unsigned int,8>& (const ArkEquipmentModComponent* const _this)>(0x10BD820);
	static inline auto FGetChipsetAtIndex = PreyFunction<ArkEquipmentMod* (const ArkEquipmentModComponent* const _this, int _index)>(0x132DCB0);
	static inline auto FActivateMod = PreyFunction<void(const ArkEquipmentModComponent* const _this, const uint64_t _archetypeId)>(0x132D8D0);
	static inline auto FDeactivateMod = PreyFunction<void(const ArkEquipmentModComponent* const _this, const uint64_t _archetypeId)>(0x132DB70);
	static inline auto FGetIndexOfChipset = PreyFunction<int(const ArkEquipmentModComponent* const _this, unsigned _modId)>(0x132DCE0);
	static inline auto FGetInstallIndexOfChipset = PreyFunction<int(const ArkEquipmentModComponent* const _this, unsigned _chipsetId)>(0x132DD10);
	static inline auto FIsModInstalled = PreyFunction<bool(const ArkEquipmentModComponent* const _this, const uint64_t _archetypeId)>(0x132E0C0);
	static inline auto FGetModSignalPackage = PreyFunction<uint64_t(const ArkEquipmentModComponent* const _this, const uint64_t _archetypeId)>(0x132DD40);
	static inline auto FHasSpace = PreyFunction<bool(const ArkEquipmentModComponent* const _this, const ArkEquipmentMod& _chipset)>(0x132DEE0);
};

