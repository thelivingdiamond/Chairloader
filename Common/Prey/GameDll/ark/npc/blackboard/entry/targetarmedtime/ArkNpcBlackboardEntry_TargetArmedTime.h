// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcBlackboardEntryTemplate_GetUpdate.h>

class ArkNpcBlackboardEntryKey_TargetArmedTime;

// ArkNpcBlackboardEntry_TargetArmedTime
// Header:  Prey/GameDll/ark/npc/blackboard/entry/targetarmedtime/ArkNpcBlackboardEntry_TargetArmedTime.h
class ArkNpcBlackboardEntry_TargetArmedTime : public ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardEntryKey_TargetArmedTime,ArkNpcBlackboardEntry_TargetArmedTime,float,float>
{ // Size=4 (0x4)
public:
	float m_time;

	ArkNpcBlackboardEntry_TargetArmedTime();
	float Get() const { return FGet(this); }
	void Update(const ArkNpcBlackboardEntryKey_TargetArmedTime& _entryKey, float _elapsedTime) { FUpdate(this, _entryKey, _elapsedTime); }

	static inline auto FArkNpcBlackboardEntry_TargetArmedTimeOv2 = PreyFunction<void(ArkNpcBlackboardEntry_TargetArmedTime* const _this)>(0x1643FB0);
	static inline auto FGet = PreyFunction<float(const ArkNpcBlackboardEntry_TargetArmedTime* const _this)>(0x12FC750);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_TargetArmedTime* const _this, const ArkNpcBlackboardEntryKey_TargetArmedTime& _entryKey, float _elapsedTime)>(0x129F670);
};
#endif // MOONCRASH
