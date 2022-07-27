// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDataComponentBase.h>

class ArkKeyCodeComponent;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkNoteComponent.h
class ArkNoteComponent : public ArkDataComponentBase // Id=8016F0B Size=32
{
public:
	void Collect(const uint64_t _id) { FCollect(this,_id); }
	static wstring GetFormattedContent(const uint64_t _id) { return FGetFormattedContent(_id); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	virtual bool IsValidData(const uint64_t _id) const;
	
#if 0
	void CollectAll();
	static ArkKeyCodeComponent &GetKeyCodeComponent();
#endif
	
	static inline auto FCollect = PreyFunction<void(ArkNoteComponent *const _this, const uint64_t _id)>(0x15B5B30);
	static inline auto FGetFormattedContent = PreyFunction<wstring(const uint64_t _id)>(0x15B5C50);
	static inline auto FSerialize = PreyFunction<void(ArkNoteComponent *const _this, TSerialize ser)>(0x15B5D90);
	static inline auto FIsValidData = PreyFunction<bool(ArkNoteComponent const *const _this, const uint64_t _id)>(0x15B5D30);
};

