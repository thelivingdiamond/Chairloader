// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkLoreComponent
// Header:  Prey/GameDll/ark/player/pda/ArkLoreComponent.h
class ArkLoreComponent
{ // Size=24 (0x18)
public:
	// ArkLoreComponent::LoreData
	// Header:  Prey/GameDll/ark/player/pda/ArkLoreComponent.h
	class LoreData
	{ // Size=16 (0x10)
	public:
		uint64_t m_id;
		bool m_bLongForm;
		bool m_bNew;

	#if 0
		LoreData();
		LoreData(const uint64_t _arg0_, const bool _arg1_);
		bool operator==(const uint64_t _arg0_) const;
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::vector<ArkLoreComponent::LoreData> m_collected;

	void GiveLore(const uint64_t _id, const bool _bLongForm) { FGiveLore(this, _id, _bLongForm); }
	bool HasLore(const uint64_t _id) const { return FHasLore(this, _id); }
	bool IsNew(const uint64_t _id) const { return FIsNew(this, _id); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	wstring GetFormattedContent(const uint64_t _id, string& _image) { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetFormattedContent(this, reinterpret_cast<wstring*>(_return_buf_), _id, _image); }

#if 0
	ArkLoreComponent();
	void CollectAll();
	void Reset();
	const std::vector<ArkLoreComponent::LoreData>& GetCollected() const;
#endif

	static inline auto FGiveLore = PreyFunction<void(ArkLoreComponent* const _this, const uint64_t _id, const bool _bLongForm)>(0x132F390);
	static inline auto FHasLore = PreyFunction<bool(const ArkLoreComponent* const _this, const uint64_t _id)>(0x132F3F0);
	static inline auto FIsNew = PreyFunction<bool(const ArkLoreComponent* const _this, const uint64_t _id)>(0x132F420);
	static inline auto FSerialize = PreyFunction<void(ArkLoreComponent* const _this, TSerialize _ser)>(0x132F450);
	static inline auto FGetFormattedContent = PreyFunction<wstring*(ArkLoreComponent* const _this, wstring* _return_value_, const uint64_t _id, string& _image)>(0x132F1D0);
};

