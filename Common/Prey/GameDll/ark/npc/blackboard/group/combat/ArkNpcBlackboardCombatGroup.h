// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/arkblackboardautoentry.h>
#include <_unknown/ArkBlackboardAutoEntry.h>

class ArkNpc;
struct IEntity;

// ArkNpcBlackboardCombatGroup
// Header:  Prey/GameDll/ark/npc/blackboard/group/combat/ArkNpcBlackboardCombatGroup.h
class ArkNpcBlackboardCombatGroup
{ // Size=216 (0xD8)
public:
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_TargetEntity> m_bbTargetEntity;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_InCombat> m_bbInCombat;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_EntityOccluded> m_bbEntityOccluded;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_EntityReachable> m_bbEntityReachable;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_LostVisibilityTime> m_bbLostVisibilityTime;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_TargetArmedTime> m_bbTargetArmedTime;
	ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_VisibilityTime> m_bbVisibilityTime;

	ArkNpcBlackboardCombatGroup(const ArkNpc& _npc);
	void SetTargetEntity(unsigned _targetEntityId) { FSetTargetEntityOv2(this, _targetEntityId); }
	unsigned GetTargetEntityId() const { return FGetTargetEntityId(this); }
	IEntity* GetTargetEntity() const { return FGetTargetEntity(this); }
	void SetInCombat(bool _bInCombat) { FSetInCombat(this, _bInCombat); }
	bool GetEntityOccluded() const { return FGetEntityOccluded(this); }

#if 0
	void SetTargetEntity(const IEntity& _arg0_);
	void SetTargetEntity(const IEntity* _arg0_);
	bool GetInCombat() const;
	bool GetEntityReachable() const;
	float GetLostVisibilityTime() const;
	float GetTargetArmedTime() const;
	float GetVisibilityTime() const;
#endif

	static inline auto FArkNpcBlackboardCombatGroupOv2 = PreyFunction<void(ArkNpcBlackboardCombatGroup* const _this, const ArkNpc& _npc)>(0x129FF70);
	static inline auto FSetTargetEntityOv2 = PreyFunction<void(ArkNpcBlackboardCombatGroup* const _this, unsigned _targetEntityId)>(0x12A02E0);
	static inline auto FGetTargetEntityId = PreyFunction<unsigned(const ArkNpcBlackboardCombatGroup* const _this)>(0x12A0210);
	static inline auto FGetTargetEntity = PreyFunction<IEntity* (const ArkNpcBlackboardCombatGroup* const _this)>(0x12A01D0);
	static inline auto FSetInCombat = PreyFunction<void(ArkNpcBlackboardCombatGroup* const _this, bool _bInCombat)>(0x12A0270);
	static inline auto FGetEntityOccluded = PreyFunction<bool(const ArkNpcBlackboardCombatGroup* const _this)>(0x12A00D0);
};
#endif // MOONCRASH
