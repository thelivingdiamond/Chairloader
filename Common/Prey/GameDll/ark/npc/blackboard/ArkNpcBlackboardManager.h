// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkBlackboard.h>

// ArkNpcBlackboardManager
// Header:  Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardManager.h
class ArkNpcBlackboardManager
{ // Size=648 (0x288)
public:
	ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo> m_blackboard;

	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>& GetBlackboard() { return FGetBlackboard(this); }

#if 0
	ArkNpcBlackboardManager();
	ArkNpcBlackboardManager(const ArkNpcBlackboardManager& _arg0_);
	ArkNpcBlackboardManager& operator=(const ArkNpcBlackboardManager& _arg0_);
#endif

	static inline auto FReset = PreyFunction<void(ArkNpcBlackboardManager* const _this, bool _bEnteringGameMode)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBlackboardManager* const _this, float _elapsedTime)>(0x129DDB0);
	static inline auto FGetBlackboard = PreyFunction<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>& (ArkNpcBlackboardManager* const _this)>(0x3DAC90);
};
#endif // MOONCRASH
