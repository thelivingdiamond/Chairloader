// Header file automatically created from a PDB.
// (Dumped under _unknown/; placed next to the other blackboard entries.)
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

class ArkNpcBlackboardKey_InCombat;
class ArkNpcBlackboardEntryKey_InCombat;

// ArkNpcBlackboardEntry_InCombat
// Header:  Prey/GameDll/ark/npc/blackboard/entry/incombat/ArkNpcBlackboardEntry_InCombat.h
class ArkNpcBlackboardEntry_InCombat : public ArkNpcBlackboardEntryTemplate_SetGet<ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardEntryKey_InCombat,ArkNpcBlackboardEntry_InCombat,bool,bool>
{ // Size=1 (0x1)
public:
	bool m_bInCombat;

	ArkNpcBlackboardEntry_InCombat();
	void Set(bool _bInCombat) { FSet(this, _bInCombat); }
	bool Get() const { return FGet(this); }

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_InCombatOv2 = PreyFunction<void(ArkNpcBlackboardEntry_InCombat* const _this)>(0x1210480);
	static inline auto FSet = PreyFunction<void(ArkNpcBlackboardEntry_InCombat* const _this, bool _bInCombat)>(0x1210470);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_InCombat* const _this)>(0x1210490);
#else
	static inline auto FArkNpcBlackboardEntry_InCombatOv2 = PreyFunction<void(ArkNpcBlackboardEntry_InCombat* const _this)>(0x18E26C0);
	static inline auto FSet = PreyFunction<void(ArkNpcBlackboardEntry_InCombat* const _this, bool _bInCombat)>(0x129F5E0);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_InCombat* const _this)>(0x129F5F0);
#endif
};
