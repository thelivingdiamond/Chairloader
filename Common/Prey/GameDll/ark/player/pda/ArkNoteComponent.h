// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDataComponentBase.h>

class ArkKeyCodeComponent;

// ArkNoteComponent
// Header:  Prey/GameDll/ark/player/pda/ArkNoteComponent.h
class ArkNoteComponent : public ArkDataComponentBase
{ // Size=32 (0x20)
public:
	void Collect(const uint64_t _id) { FCollect(this, _id); }
	static wstring GetFormattedContent(const uint64_t _id) { return FGetFormattedContent(_id); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual bool IsValidData(const uint64_t _id) const;

#if 0
	void CollectAll();
	static ArkKeyCodeComponent& GetKeyCodeComponent();
#endif

	static inline auto FCollect = PreyFunction<void(ArkNoteComponent* const _this, const uint64_t _id)>(0x15B5B30);
	static inline auto FGetFormattedContent = PreyFunction<wstring(const uint64_t _id)>(0x15B5C50);
	static inline auto FSerialize = PreyFunction<void(ArkNoteComponent* const _this, TSerialize ser)>(0x15B5D90);
	static inline auto FIsValidData = PreyFunction<bool(const ArkNoteComponent* const _this, const uint64_t _id)>(0x15B5D30);
};

