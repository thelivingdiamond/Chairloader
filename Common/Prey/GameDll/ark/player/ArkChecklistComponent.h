// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkChecklistEntry;

// ArkChecklistComponent
// Header:  Prey/GameDll/ark/player/ArkChecklistComponent.h
class ArkChecklistComponent
{ // Size=152 (0x98)
public:
	std::unordered_set<uint64_t> m_completedEntries;
	std::unordered_set<uint64_t> m_disabledEntries;
	std::vector<uint64_t> m_entriesCompletedThisRun;

	void Reset() { FReset(this); }
	void StartSimulationRun() { FStartSimulationRun(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void CompleteEntry(uint64_t _entryId) { FCompleteEntry(this, _entryId); }
	bool IsEntryComplete(uint64_t _entryId) const { return FIsEntryComplete(this, _entryId); }
	bool IsEntryEnabled(uint64_t _entryId) const { return FIsEntryEnabled(this, _entryId); }
	int GetNumCompletedEntries() const { return FGetNumCompletedEntries(this); }
	void SetEntryEnabled(bool _bEnabled, uint64_t _entryId) { FSetEntryEnabled(this, _bEnabled, _entryId); }
	wstring GetChecklistEntryLabel(const ArkChecklistEntry& _entry) const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetChecklistEntryLabel(this, reinterpret_cast<wstring*>(_return_buf_), _entry); }

#if 0
	const std::vector<uint64_t>& GetEntriesCompletedThisRun() const;
#endif

	static inline auto FReset = PreyFunction<void(ArkChecklistComponent* const _this)>(0x12C07F0);
	static inline auto FStartSimulationRun = PreyFunction<void(ArkChecklistComponent* const _this)>(0x12C0C00);
	static inline auto FSerialize = PreyFunction<void(ArkChecklistComponent* const _this, TSerialize _ser)>(0x12C0960);
	static inline auto FCompleteEntry = PreyFunction<void(ArkChecklistComponent* const _this, uint64_t _entryId)>(0x12C0030);
	static inline auto FIsEntryComplete = PreyFunction<bool(const ArkChecklistComponent* const _this, uint64_t _entryId)>(0x12C0790);
	static inline auto FIsEntryEnabled = PreyFunction<bool(const ArkChecklistComponent* const _this, uint64_t _entryId)>(0x12C07C0);
	static inline auto FGetNumCompletedEntries = PreyFunction<int(const ArkChecklistComponent* const _this)>(0x387590);
	static inline auto FSetEntryEnabled = PreyFunction<void(ArkChecklistComponent* const _this, bool _bEnabled, uint64_t _entryId)>(0x12C0B00);
	static inline auto FGetChecklistEntryLabel = PreyFunction<wstring*(const ArkChecklistComponent* const _this, wstring* _return_value_, const ArkChecklistEntry& _entry)>(0x12C02B0);
};
#endif // MOONCRASH
