// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkKeyCodeEntry;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkKeyCodeComponent.h
class ArkKeyCodeComponent // Id=8016F0D Size=24
{
public:
	std::vector<ArkKeyCodeEntry> m_Collected;
	
	ArkKeyCodeComponent();
	bool Collect(const uint64_t _id) { return FCollect(this,_id); }
	bool Validate(const uint64_t _id, string const &_code) { return FValidate(this,_id,_code); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	bool InitializeEntryCode(ArkKeyCodeEntry &_entry) { return FInitializeEntryCode(this,_entry); }
	void MarkCollectedViewed() { FMarkCollectedViewed(this); }
	wstring GetFormattedLabel(const uint64_t _id) { return FGetFormattedLabel(this,_id); }
	bool FormatStringWithCode(wstring &_input, const uint64_t _id) { return FFormatStringWithCode(this,_input,_id); }
	ArkKeyCodeEntry *GetEntry(const uint64_t _id) { return FGetEntry(this,_id); }
	
#if 0
	void CollectAll();
	std::vector<ArkKeyCodeEntry> const &GetCollected() const;
#endif
	
	static inline auto FCollect = PreyFunction<bool(ArkKeyCodeComponent *const _this, const uint64_t _id)>(0x15B74E0);
	static inline auto FValidate = PreyFunction<bool(ArkKeyCodeComponent *const _this, const uint64_t _id, string const &_code)>(0x15B7C30);
	static inline auto FReset = PreyFunction<void(ArkKeyCodeComponent *const _this)>(0x15B7BD0);
	static inline auto FSerialize = PreyFunction<void(ArkKeyCodeComponent *const _this, TSerialize ser)>(0x15B7BE0);
	static inline auto FInitializeEntryCode = PreyFunction<bool(ArkKeyCodeComponent *const _this, ArkKeyCodeEntry &_entry)>(0x15B7A20);
	static inline auto FMarkCollectedViewed = PreyFunction<void(ArkKeyCodeComponent *const _this)>(0x15B7BB0);
	static inline auto FGetFormattedLabel = PreyFunction<wstring(ArkKeyCodeComponent *const _this, const uint64_t _id)>(0x15B7930);
	static inline auto FFormatStringWithCode = PreyFunction<bool(ArkKeyCodeComponent *const _this, wstring &_input, const uint64_t _id)>(0x15B76F0);
	static inline auto FGetEntry = PreyFunction<ArkKeyCodeEntry *(ArkKeyCodeComponent *const _this, const uint64_t _id)>(0x15B7890);
};

