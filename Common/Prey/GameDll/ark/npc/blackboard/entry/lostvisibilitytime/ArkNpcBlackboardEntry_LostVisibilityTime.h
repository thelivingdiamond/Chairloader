// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

class ArkNpcBlackboardKey_LostVisibilityTime;
class ArkNpcBlackboardEntryKey_LostVisibilityTime;

// ArkNpcBlackboardEntry_LostVisibilityTime
// Header:  Prey/GameDll/ark/npc/blackboard/entry/lostvisibilitytime/ArkNpcBlackboardEntry_LostVisibilityTime.h
class ArkNpcBlackboardEntry_LostVisibilityTime : public ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardEntryKey_LostVisibilityTime,ArkNpcBlackboardEntry_LostVisibilityTime,float,float>
{ // Size=4 (0x4)
public:
	float m_time;

	ArkNpcBlackboardEntry_LostVisibilityTime();
	float Get() const { return FGet(this); }
	void Update(const ArkNpcBlackboardEntryKey_LostVisibilityTime& _entryKey, float _elapsedTime) { FUpdate(this, _entryKey, _elapsedTime); }

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_LostVisibilityTimeOv2 = PreyFunction<void(ArkNpcBlackboardEntry_LostVisibilityTime* const _this)>(0x1524620);
	static inline auto FGet = PreyFunction<float(const ArkNpcBlackboardEntry_LostVisibilityTime* const _this)>(0x10BDAB0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_LostVisibilityTime* const _this, const ArkNpcBlackboardEntryKey_LostVisibilityTime& _entryKey, float _elapsedTime)>(0x12104A0);
#else
	static inline auto FArkNpcBlackboardEntry_LostVisibilityTimeOv2 = PreyFunction<void(ArkNpcBlackboardEntry_LostVisibilityTime* const _this)>(0x1643FB0);
	static inline auto FGet = PreyFunction<float(const ArkNpcBlackboardEntry_LostVisibilityTime* const _this)>(0x12FC750);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_LostVisibilityTime* const _this, const ArkNpcBlackboardEntryKey_LostVisibilityTime& _entryKey, float _elapsedTime)>(0x129F600);
#endif
};

