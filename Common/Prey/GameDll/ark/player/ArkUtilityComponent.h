// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/ArkUtilityComponent.h
class ArkUtilityComponent // Id=80170E1 Size=256
{
public:
	std::unordered_map<unsigned __int64,bool> m_utilityState;
	std::unordered_map<unsigned __int64,bool> m_utilityHidden;
	std::unordered_map<unsigned __int64,bool> m_utilityButtonState;
	std::unordered_map<unsigned __int64,bool> m_utilityButtonHidden;
	
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	bool IsUtilityEnabled(uint64_t _id) const { return FIsUtilityEnabled(this,_id); }
	void SetUtilityEnabled(uint64_t _id, bool _bEnabled) { FSetUtilityEnabled(this,_id,_bEnabled); }
	bool IsUtilityHidden(uint64_t _id) const { return FIsUtilityHidden(this,_id); }
	void SetUtilityHidden(uint64_t _id, bool _bHidden) { FSetUtilityHidden(this,_id,_bHidden); }
	bool IsUtilityButtonEnabled(uint64_t _id) const { return FIsUtilityButtonEnabled(this,_id); }
	void SetUtilityButtonEnabled(uint64_t _id, bool _bEnabled) { FSetUtilityButtonEnabled(this,_id,_bEnabled); }
	bool IsUtilityButtonHidden(uint64_t _id) const { return FIsUtilityButtonHidden(this,_id); }
	void SetUtilityButtonHidden(uint64_t _id, bool _bHidden) { FSetUtilityButtonHidden(this,_id,_bHidden); }
	
#if 0
	void Reset();
	bool GetDefaultEnabledState(uint64_t arg0) const;
	bool GetDefaultHiddenState(uint64_t arg0) const;
	bool GetDefaultEnabledStateForButton(uint64_t arg0) const;
	bool GetDefaultHiddenStateForButton(uint64_t arg0) const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(ArkUtilityComponent *const _this, TSerialize ser)>(0x132D020);
	static inline auto FIsUtilityEnabled = PreyFunction<bool(ArkUtilityComponent const *const _this, uint64_t _id)>(0x132CEE0);
	static inline auto FSetUtilityEnabled = PreyFunction<void(ArkUtilityComponent *const _this, uint64_t _id, bool _bEnabled)>(0x132D1D0);
	static inline auto FIsUtilityHidden = PreyFunction<bool(ArkUtilityComponent const *const _this, uint64_t _id)>(0x132CF80);
	static inline auto FSetUtilityHidden = PreyFunction<void(ArkUtilityComponent *const _this, uint64_t _id, bool _bHidden)>(0x132D260);
	static inline auto FIsUtilityButtonEnabled = PreyFunction<bool(ArkUtilityComponent const *const _this, uint64_t _id)>(0x132CDD0);
	static inline auto FSetUtilityButtonEnabled = PreyFunction<void(ArkUtilityComponent *const _this, uint64_t _id, bool _bEnabled)>(0x132D0B0);
	static inline auto FIsUtilityButtonHidden = PreyFunction<bool(ArkUtilityComponent const *const _this, uint64_t _id)>(0x132CE50);
	static inline auto FSetUtilityButtonHidden = PreyFunction<void(ArkUtilityComponent *const _this, uint64_t _id, bool _bHidden)>(0x132D140);
};

