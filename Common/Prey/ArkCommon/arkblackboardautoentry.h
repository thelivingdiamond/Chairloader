// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/npc/blackboard/entry/emboldened/ArkNpcBlackboardEntry_Emboldened.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/incombat/arknpcblackboardentry_incombat.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/targetentity/ArkNpcBlackboardEntry_TargetEntity.h>
#include <_unknown/ArkBlackboard_boost__mpl__vector_ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na,boost__mpl__na_,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo_.h>
#include <_unknown/ArkNpcBlackboardKey_Emboldened.h>
#include <_unknown/ArkNpcBlackboardKey_LockedInMimicry.h>
#include <_unknown/ArkNpcBlackboardKey_TargetEntity.h>

struct IEntity;

// Header: Exact
// Prey/ArkCommon/arkblackboardautoentry.h
template <typename T, typename TTargetEnt>
class ArkBlackboardAutoEntry // Id=80178F6 Size=32
{
public:
	using BlackboardType = T;
	using KeyType = TTargetEnt;
	using EntryType = ArkNpcBlackboardEntry_TargetEntity;
	using ValueType = IEntity *;
	using ConstValueType = IEntity *;
	
	T *m_pBlackboard;
	boost::optional<TTargetEnt> m_optEntryKey;
	
#if 0
	void ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilit();
	void ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilit(ArkBlackboardAutoEntry<T,TTargetEnt> const &arg0);
	void ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilit(ArkBlackboardAutoEntry<T,TTargetEnt> *arg0);
	~ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibili();
	ArkBlackboardAutoEntry<T,TTargetEnt> &operator=(ArkBlackboardAutoEntry<T,TTargetEnt> _other);
	int *operator int ArkSafeBool<class ArkBlackboardAutoEntry<class ArkBlackboard<struct boost::mpl::vector<class ArkNpcBlackboardKey_Emboldened,class ArkNpcBlackboardKey_EntityOccluded,class ArkNpcBlackboardKey_EntityReachable,class ArkNpcBlackboardKey_InCombat,c() const;
	void Reset();
	T &GetBlackboard() const;
	ArkNpcBlackboardKey_TargetEntity const &GetKey() const;
	IEntity *GetValue();
	IEntity *GetValue() const;
	ArkNpcBlackboardEntry_TargetEntity &GetEntry();
	ArkNpcBlackboardEntry_TargetEntity const &GetEntry() const;
#endif
};

