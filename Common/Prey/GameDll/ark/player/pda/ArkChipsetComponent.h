// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

// ArkChipsetComponent
// Header:  Prey/GameDll/ark/player/pda/ArkChipsetComponent.h
class ArkChipsetComponent
{ // Size=352 (0x160)
public:
	// ArkChipsetComponent::InstalledChipset
	// Header:  Prey/GameDll/ark/player/pda/ArkChipsetComponent.h
	class InstalledChipset
	{ // Size=32 (0x20)
	public:
		std::vector<unsigned int> m_activeStatMods;
		uint64_t m_archetype;

		void UninstallChipset() { FUninstallChipset(this); }
		void AddModifiers(const char* const _inbound, const char* const _outbound) const { FAddModifiers(this, _inbound, _outbound); }
		void RemoveModifiers(const char* const _inbound, const char* const _outbound) const { FRemoveModifiers(this, _inbound, _outbound); }
		void SetupActiveStatMods() { FSetupActiveStatMods(this); }

	#if 0
		InstalledChipset();
		void Serialize(TSerialize _arg0_);
		uint64_t GetArchetype() const;
		uint64_t GetSignalPackage() const;
		void InstallChipset(uint64_t _arg0_);
		void Activate() const;
		void Deactivate() const;
		void ClearActiveStatMods();
	#endif

		static inline auto FUninstallChipset = PreyFunction<void(ArkChipsetComponent::InstalledChipset* const _this)>(0x1409EA0);
		static inline auto FAddModifiers = PreyFunction<void(const ArkChipsetComponent::InstalledChipset* const _this, const char* const _inbound, const char* const _outbound)>(0x1408320);
		static inline auto FRemoveModifiers = PreyFunction<void(const ArkChipsetComponent::InstalledChipset* const _this, const char* const _inbound, const char* const _outbound)>(0x1409420);
		static inline auto FSetupActiveStatMods = PreyFunction<void(ArkChipsetComponent::InstalledChipset* const _this)>(0x1409C60);
	};

	static constexpr const int k_maxInstalled = 8;
	std::vector<uint64_t> m_collectedChipsets;
	std::vector<uint64_t> m_ownedChipsets;
	std::vector<uint64_t> m_newChipsets;
	std::vector<uint64_t> m_readyRoomNewChipsets;
	std::array<ArkChipsetComponent::InstalledChipset, 8> m_installedChipsets;

	ArkChipsetComponent();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Reset() { FReset(this); }
	void ResetForCharacterChange() { FResetForCharacterChange(this); }
	void AddToInventory(uint64_t _chipsetId) { FAddToInventory(this, _chipsetId); }
	void InstallChipset(uint64_t _chipsetId) { FInstallChipset(this, _chipsetId); }
	void UninstallChipset(int _installIndex) { FUninstallChipset(this, _installIndex); }
	int GetNumInstallableSlots() const { return FGetNumInstallableSlots(this); }
	int GetNumInstalledChipsets() const { return FGetNumInstalledChipsets(this); }
	bool IsNew(uint64_t _chipsetId) const { return FIsNew(this, _chipsetId); }
	void MarkAsSeen(uint64_t _chipsetId) { FMarkAsSeen(this, _chipsetId); }
	bool IsReadyRoomNew(uint64_t _chipsetId) const { return FIsReadyRoomNew(this, _chipsetId); }
	void MarkAsSeenInReadyRoom(uint64_t _chipsetId) { FMarkAsSeenInReadyRoom(this, _chipsetId); }
	const std::array<uint64_t, 8> GetInstalledChipsets() const { alignas(const std::array<uint64_t, 8>) std::byte _return_buf_[sizeof(const std::array<uint64_t, 8>)]; return *FGetInstalledChipsets(this, reinterpret_cast<const std::array<uint64_t, 8>*>(_return_buf_)); }
	uint64_t GetChipsetAtIndex(int _index) const { return FGetChipsetAtIndex(this, _index); }
	void ActivateChipset(const uint64_t _archetypeId) const { FActivateChipset(this, _archetypeId); }
	void DeactivateChipset(const uint64_t _archetypeId) const { FDeactivateChipset(this, _archetypeId); }
	int GetIndexOfChipset(uint64_t _chipsetId) const { return FGetIndexOfChipset(this, _chipsetId); }
	int GetInstallIndexOfChipset(uint64_t _chipsetId) const { return FGetInstallIndexOfChipset(this, _chipsetId); }
	bool IsChipsetInstalled(const uint64_t _archetypeId) const { return FIsChipsetInstalled(this, _archetypeId); }
	uint64_t GetChipsetSignalPackage(const uint64_t _archetypeId) const { return FGetChipsetSignalPackage(this, _archetypeId); }
	bool HasSpace(uint64_t _chipsetId) const { return FHasSpace(this, _chipsetId); }
	std::vector<uint64_t> GetChipsetExclusives(uint64_t _chipsetId) const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetChipsetExclusives(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_), _chipsetId); }

#if 0
	void RemoveFromInventory(uint64_t _arg0_);
	const std::vector<uint64_t>& GetCollectedChipsets() const;
	const std::vector<uint64_t>& GetAllChipsets() const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
#endif

	static inline auto FArkChipsetComponentOv2 = PreyFunction<void(ArkChipsetComponent* const _this)>(0x14081B0);
	static inline auto FSerialize = PreyFunction<void(ArkChipsetComponent* const _this, TSerialize _ser)>(0x1409AB0);
	static inline auto FReset = PreyFunction<void(ArkChipsetComponent* const _this)>(0x14097E0);
	static inline auto FResetForCharacterChange = PreyFunction<void(ArkChipsetComponent* const _this)>(0x1409A50);
	static inline auto FAddToInventory = PreyFunction<void(ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x14086E0);
	static inline auto FInstallChipset = PreyFunction<void(ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x1409300);
	static inline auto FUninstallChipset = PreyFunction<void(ArkChipsetComponent* const _this, int _installIndex)>(0x1409E80);
	static inline auto FGetNumInstallableSlots = PreyFunction<int(const ArkChipsetComponent* const _this)>(0x1409040);
	static inline auto FGetNumInstalledChipsets = PreyFunction<int(const ArkChipsetComponent* const _this)>(0x1409070);
	static inline auto FIsNew = PreyFunction<bool(const ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x14093C0);
	static inline auto FMarkAsSeen = PreyFunction<void(ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x1210D50);
	static inline auto FIsReadyRoomNew = PreyFunction<bool(const ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x14093F0);
	static inline auto FMarkAsSeenInReadyRoom = PreyFunction<void(ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x1210D90);
	static inline auto FGetInstalledChipsets = PreyFunction<const std::array<uint64_t, 8>*(const ArkChipsetComponent* const _this, const std::array<uint64_t, 8>* _return_value_)>(0x1408FE0);
	static inline auto FGetChipsetAtIndex = PreyFunction<uint64_t(const ArkChipsetComponent* const _this, int _index)>(0x14088E0);
	static inline auto FActivateChipset = PreyFunction<void(const ArkChipsetComponent* const _this, const uint64_t _archetypeId)>(0x14082D0);
	static inline auto FDeactivateChipset = PreyFunction<void(const ArkChipsetComponent* const _this, const uint64_t _archetypeId)>(0x1408890);
	static inline auto FGetIndexOfChipset = PreyFunction<int(const ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x1408F80);
	static inline auto FGetInstallIndexOfChipset = PreyFunction<int(const ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x1408FB0);
	static inline auto FIsChipsetInstalled = PreyFunction<bool(const ArkChipsetComponent* const _this, const uint64_t _archetypeId)>(0x1409380);
	static inline auto FGetChipsetSignalPackage = PreyFunction<uint64_t(const ArkChipsetComponent* const _this, const uint64_t _archetypeId)>(0x1408E60);
	static inline auto FHasSpace = PreyFunction<bool(const ArkChipsetComponent* const _this, uint64_t _chipsetId)>(0x14090B0);
	static inline auto FGetChipsetExclusives = PreyFunction<std::vector<uint64_t>*(const ArkChipsetComponent* const _this, std::vector<uint64_t>* _return_value_, uint64_t _chipsetId)>(0x1408900);
};
#endif // MOONCRASH
