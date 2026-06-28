// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkTip;

// Header: FromCpp
// Prey/GameDll/ark/ArkTipComponent.h
class ArkTipComponent // Id=8016917 Size=112
{
public:
	std::vector<unsigned __int64> m_unlocks;
	std::vector<unsigned __int64> m_shownTips;
	std::unordered_map<unsigned __int64,unsigned int> m_sequenceIndexes;
	
	ArkTipComponent();
	~ArkTipComponent();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SetLocked(const uint64_t _lockId, const bool _bLocked) { FSetLocked(this,_lockId,_bLocked); }
	unsigned GetAvailableCount(ArkTip const &_tip) const { return FGetAvailableCount(this,_tip); }
	ArkTip const *GetRandomTip(bool _bDeathScreen) { return FGetRandomTip(this,_bDeathScreen); }
	void ResetSequences() { FResetSequences(this); }
	
	static inline auto FBitNotArkTipComponent = PreyFunction<void(ArkTipComponent *const _this)>(0x11AFE40);
	static inline auto FReset = PreyFunction<void(ArkTipComponent *const _this)>(0x11B07B0);
	static inline auto FSerialize = PreyFunction<void(ArkTipComponent *const _this, TSerialize _ser)>(0x11B0A20);
	static inline auto FSetLocked = PreyFunction<void(ArkTipComponent *const _this, const uint64_t _lockId, const bool _bLocked)>(0x11B0A80);
	static inline auto FGetAvailableCount = PreyFunction<unsigned(ArkTipComponent const *const _this, ArkTip const &_tip)>(0x11B0130);
	static inline auto FGetRandomTip = PreyFunction<ArkTip const *(ArkTipComponent *const _this, bool _bDeathScreen)>(0x11B02F0);
	static inline auto FResetSequences = PreyFunction<void(ArkTipComponent *const _this)>(0x11B0830);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkTip;

// ArkTipComponent
// Header:  Prey/GameDll/ark/ArkTipComponent.h
class ArkTipComponent
{ // Size=112 (0x70)
public:
	std::vector<uint64_t> m_unlocks;
	std::vector<uint64_t> m_shownTips;
	std::unordered_map<uint64_t, unsigned int> m_sequenceIndexes;

	ArkTipComponent();
	~ArkTipComponent();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SetLocked(const uint64_t _lockId, const bool _bLocked) { FSetLocked(this, _lockId, _bLocked); }
	unsigned GetAvailableCount(const ArkTip& _tip) const { return FGetAvailableCount(this, _tip); }
	const ArkTip* GetRandomTip(bool _bDeathScreen) { return FGetRandomTip(this, _bDeathScreen); }
	void ResetSequences() { FResetSequences(this); }

	static inline auto FArkTipComponentOv1 = PreyFunction<void(ArkTipComponent* const _this)>(0x122D360);
	static inline auto FBitNotArkTipComponent = PreyFunction<void(ArkTipComponent* const _this)>(0x122D420);
	static inline auto FReset = PreyFunction<void(ArkTipComponent* const _this)>(0x122DD90);
	static inline auto FSerialize = PreyFunction<void(ArkTipComponent* const _this, TSerialize _ser)>(0x122E000);
	static inline auto FSetLocked = PreyFunction<void(ArkTipComponent* const _this, const uint64_t _lockId, const bool _bLocked)>(0x122E060);
	static inline auto FGetAvailableCount = PreyFunction<unsigned(const ArkTipComponent* const _this, const ArkTip& _tip)>(0x122D710);
	static inline auto FGetRandomTip = PreyFunction<const ArkTip* (ArkTipComponent* const _this, bool _bDeathScreen)>(0x122D8D0);
	static inline auto FResetSequences = PreyFunction<void(ArkTipComponent* const _this)>(0x122DE10);
};
#endif // !MOONCRASH
