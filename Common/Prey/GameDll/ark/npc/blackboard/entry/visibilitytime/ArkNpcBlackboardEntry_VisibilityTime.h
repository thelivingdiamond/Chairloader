// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

class ArkNpcBlackboardKey_VisibilityTime;
class ArkNpcBlackboardEntryKey_VisibilityTime;

// ArkNpcBlackboardEntry_VisibilityTime
// Header:  Prey/GameDll/ark/npc/blackboard/entry/visibilitytime/ArkNpcBlackboardEntry_VisibilityTime.h
class ArkNpcBlackboardEntry_VisibilityTime : public ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_VisibilityTime,ArkNpcBlackboardEntryKey_VisibilityTime,ArkNpcBlackboardEntry_VisibilityTime,float,float>
{ // Size=4 (0x4)
public:
	float m_time;

	ArkNpcBlackboardEntry_VisibilityTime();
	float Get() const { return FGet(this); }
	void Update(const ArkNpcBlackboardEntryKey_VisibilityTime& _entryKey, float _elapsedTime) { FUpdate(this, _entryKey, _elapsedTime); }

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_VisibilityTimeOv2 = PreyFunction<void(ArkNpcBlackboardEntry_VisibilityTime* const _this)>(0x1524620);
	static inline auto FGet = PreyFunction<float(const ArkNpcBlackboardEntry_VisibilityTime* const _this)>(0x10BDAB0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_VisibilityTime* const _this, const ArkNpcBlackboardEntryKey_VisibilityTime& _entryKey, float _elapsedTime)>(0x1210530);
#else
	static inline auto FArkNpcBlackboardEntry_VisibilityTimeOv2 = PreyFunction<void(ArkNpcBlackboardEntry_VisibilityTime* const _this)>(0x1643FB0);
	static inline auto FGet = PreyFunction<float(const ArkNpcBlackboardEntry_VisibilityTime* const _this)>(0x12FC750);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardEntry_VisibilityTime* const _this, const ArkNpcBlackboardEntryKey_VisibilityTime& _entryKey, float _elapsedTime)>(0x129F700);
#endif
};

