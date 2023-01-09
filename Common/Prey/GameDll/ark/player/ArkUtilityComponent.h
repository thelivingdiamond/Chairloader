// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkUtilityComponent
// Header:  Prey/GameDll/ark/player/ArkUtilityComponent.h
class ArkUtilityComponent
{ // Size=256 (0x100)
public:
	std::unordered_map<uint64_t, bool> m_utilityState;
	std::unordered_map<uint64_t, bool> m_utilityHidden;
	std::unordered_map<uint64_t, bool> m_utilityButtonState;
	std::unordered_map<uint64_t, bool> m_utilityButtonHidden;

	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	bool IsUtilityEnabled(uint64_t _id) const { return FIsUtilityEnabled(this, _id); }
	void SetUtilityEnabled(uint64_t _id, bool _bEnabled) { FSetUtilityEnabled(this, _id, _bEnabled); }
	bool IsUtilityHidden(uint64_t _id) const { return FIsUtilityHidden(this, _id); }
	void SetUtilityHidden(uint64_t _id, bool _bHidden) { FSetUtilityHidden(this, _id, _bHidden); }
	bool IsUtilityButtonEnabled(uint64_t _id) const { return FIsUtilityButtonEnabled(this, _id); }
	void SetUtilityButtonEnabled(uint64_t _id, bool _bEnabled) { FSetUtilityButtonEnabled(this, _id, _bEnabled); }
	bool IsUtilityButtonHidden(uint64_t _id) const { return FIsUtilityButtonHidden(this, _id); }
	void SetUtilityButtonHidden(uint64_t _id, bool _bHidden) { FSetUtilityButtonHidden(this, _id, _bHidden); }

#if 0
	void Reset();
	bool GetDefaultEnabledState(uint64_t _arg0_) const;
	bool GetDefaultHiddenState(uint64_t _arg0_) const;
	bool GetDefaultEnabledStateForButton(uint64_t _arg0_) const;
	bool GetDefaultHiddenStateForButton(uint64_t _arg0_) const;
#endif

	static inline auto FSerialize = PreyFunction<void(ArkUtilityComponent* const _this, TSerialize ser)>(0x132D020);
	static inline auto FIsUtilityEnabled = PreyFunction<bool(const ArkUtilityComponent* const _this, uint64_t _id)>(0x132CEE0);
	static inline auto FSetUtilityEnabled = PreyFunction<void(ArkUtilityComponent* const _this, uint64_t _id, bool _bEnabled)>(0x132D1D0);
	static inline auto FIsUtilityHidden = PreyFunction<bool(const ArkUtilityComponent* const _this, uint64_t _id)>(0x132CF80);
	static inline auto FSetUtilityHidden = PreyFunction<void(ArkUtilityComponent* const _this, uint64_t _id, bool _bHidden)>(0x132D260);
	static inline auto FIsUtilityButtonEnabled = PreyFunction<bool(const ArkUtilityComponent* const _this, uint64_t _id)>(0x132CDD0);
	static inline auto FSetUtilityButtonEnabled = PreyFunction<void(ArkUtilityComponent* const _this, uint64_t _id, bool _bEnabled)>(0x132D0B0);
	static inline auto FIsUtilityButtonHidden = PreyFunction<bool(const ArkUtilityComponent* const _this, uint64_t _id)>(0x132CE50);
	static inline auto FSetUtilityButtonHidden = PreyFunction<void(ArkUtilityComponent* const _this, uint64_t _id, bool _bHidden)>(0x132D140);
};

