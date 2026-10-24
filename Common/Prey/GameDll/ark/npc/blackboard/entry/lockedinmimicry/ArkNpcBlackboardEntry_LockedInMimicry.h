// Header file automatically created from a PDB.
// (Dumped under _unknown/; placed next to the other blackboard entries.)
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardEntryTemplates.h>

class ArkNpcBlackboardKey_LockedInMimicry;
class ArkNpcBlackboardEntryKey_LockedInMimicry;

// ArkNpcBlackboardEntry_LockedInMimicry
// Header:  Prey/GameDll/ark/npc/blackboard/entry/lockedinmimicry/ArkNpcBlackboardEntry_LockedInMimicry.h
class ArkNpcBlackboardEntry_LockedInMimicry : public ArkNpcBlackboardEntryTemplate_SetGet<ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardEntryKey_LockedInMimicry,ArkNpcBlackboardEntry_LockedInMimicry,bool,bool>
{ // Size=1 (0x1)
public:
	bool m_bLockedInMimicry;

	ArkNpcBlackboardEntry_LockedInMimicry();
	void Set(bool _bLockedInMimicry) { FSet(this, _bLockedInMimicry); }
	bool Get() const { return FGet(this); }

#ifndef MOONCRASH
	static inline auto FArkNpcBlackboardEntry_LockedInMimicryOv2 = PreyFunction<void(ArkNpcBlackboardEntry_LockedInMimicry* const _this)>(0x1210480);
	static inline auto FSet = PreyFunction<void(ArkNpcBlackboardEntry_LockedInMimicry* const _this, bool _bLockedInMimicry)>(0x1210470);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_LockedInMimicry* const _this)>(0x1210490);
#else
	static inline auto FArkNpcBlackboardEntry_LockedInMimicryOv2 = PreyFunction<void(ArkNpcBlackboardEntry_LockedInMimicry* const _this)>(0x18E26C0);
	static inline auto FSet = PreyFunction<void(ArkNpcBlackboardEntry_LockedInMimicry* const _this, bool _bLockedInMimicry)>(0x129F5E0);
	static inline auto FGet = PreyFunction<bool(const ArkNpcBlackboardEntry_LockedInMimicry* const _this)>(0x129F5F0);
#endif
};
