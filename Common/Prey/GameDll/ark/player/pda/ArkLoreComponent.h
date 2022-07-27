// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkLoreComponent.h
class ArkLoreComponent // Id=8016F32 Size=24
{
public:
	class LoreData // Id=8016F33 Size=16
	{
	public:
		uint64_t m_id;
		bool m_bLongForm;
		bool m_bNew;
		
#if 0
		bool operator==(const uint64_t arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkLoreComponent::LoreData> m_collected;
	
	void GiveLore(const uint64_t _id, const bool _bLongForm) { FGiveLore(this,_id,_bLongForm); }
	bool HasLore(const uint64_t _id) const { return FHasLore(this,_id); }
	bool IsNew(const uint64_t _id) const { return FIsNew(this,_id); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	wstring GetFormattedContent(const uint64_t _id, string &_image) { return FGetFormattedContent(this,_id,_image); }
	
#if 0
	void CollectAll();
	void Reset();
	std::vector<ArkLoreComponent::LoreData> const &GetCollected() const;
#endif
	
	static inline auto FGiveLore = PreyFunction<void(ArkLoreComponent *const _this, const uint64_t _id, const bool _bLongForm)>(0x132F390);
	static inline auto FHasLore = PreyFunction<bool(ArkLoreComponent const *const _this, const uint64_t _id)>(0x132F3F0);
	static inline auto FIsNew = PreyFunction<bool(ArkLoreComponent const *const _this, const uint64_t _id)>(0x132F420);
	static inline auto FSerialize = PreyFunction<void(ArkLoreComponent *const _this, TSerialize _ser)>(0x132F450);
	static inline auto FGetFormattedContent = PreyFunction<wstring(ArkLoreComponent *const _this, const uint64_t _id, string &_image)>(0x132F1D0);
};

