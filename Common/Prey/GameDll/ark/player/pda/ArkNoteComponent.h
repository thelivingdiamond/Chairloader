// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDataComponentBase.h>

class ArkKeyCodeComponent;

// ArkNoteComponent
// Header:  Prey/GameDll/ark/player/pda/ArkNoteComponent.h
class ArkNoteComponent : public ArkDataComponentBase
{ // Size=56 (0x38)
public:
	std::vector<uint64_t> m_notesThatResetOnCharacterChange;

	void Collect(const uint64_t _id) { FCollect(this, _id); }
	static wstring GetFormattedContent(const uint64_t _id) { return FGetFormattedContent(_id); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual bool IsValidData(const uint64_t _id) const;
	void Reset() { FReset(this); }
	void ResetForCharacterChange() { FResetForCharacterChange(this); }

#if 0
	void CollectAll();
	static ArkKeyCodeComponent& GetKeyCodeComponent();
#endif

	static inline auto FCollect = PreyFunction<void(ArkNoteComponent* const _this, const uint64_t _id)>(0x16DB2A0);
	static inline auto FGetFormattedContent = PreyFunction<wstring(const uint64_t _id)>(0x16DB3E0);
	static inline auto FSerialize = PreyFunction<void(ArkNoteComponent* const _this, TSerialize ser)>(0x16DB5E0);
	static inline auto FIsValidData = PreyFunction<bool(const ArkNoteComponent* const _this, const uint64_t _id)>(0x16DB4C0);
	static inline auto FReset = PreyFunction<void(ArkNoteComponent* const _this)>(0x16DB520);
	static inline auto FResetForCharacterChange = PreyFunction<void(ArkNoteComponent* const _this)>(0x16DB540);
};
#endif // !MOONCRASH
