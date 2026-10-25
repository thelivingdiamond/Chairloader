// Header file automatically created from a PDB (dumped under _unknown/ArkNpcBlackboard{Entry,}Key_*.h).
// Collected in one header: the game gives no source path for these key classes.
#pragma once
#include <Prey/GameDll/ark/npc/blackboard/ArkNpcBlackboardKeyTemplates.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/emboldened/ArkNpcBlackboardEntry_Emboldened.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/entityoccluded/ArkNpcBlackboardEntry_EntityOccluded.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/entityreachable/ArkNpcBlackboardEntry_EntityReachable.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/incombat/ArkNpcBlackboardEntry_InCombat.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/lockedinmimicry/ArkNpcBlackboardEntry_LockedInMimicry.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/lostvisibilitytime/ArkNpcBlackboardEntry_LostVisibilityTime.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/targetarmedtime/ArkNpcBlackboardEntry_TargetArmedTime.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/targetentity/ArkNpcBlackboardEntry_TargetEntity.h>
#include <Prey/GameDll/ark/npc/blackboard/entry/visibilitytime/ArkNpcBlackboardEntry_VisibilityTime.h>

class ArkNpc;
// Only used by value in the TargetEntity keys; int underlying type assumed.
enum class EArkNpcBlackboardTargetType : int
{
	hostile = 0,
};

// ArkNpcBlackboardEntryKey_Emboldened
// Header:  _unknown/ArkNpcBlackboardEntryKey_Emboldened.h
class ArkNpcBlackboardEntryKey_Emboldened : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_Emboldened>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardEntryKey_Emboldened(const ArkNpc& _arg0_);
#endif
};

// ArkNpcBlackboardKey_Emboldened
// Header:  _unknown/ArkNpcBlackboardKey_Emboldened.h
class ArkNpcBlackboardKey_Emboldened : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_Emboldened,ArkNpcBlackboardEntry_Emboldened>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardKey_Emboldened(const ArkNpc& _arg0_);
	ArkNpcBlackboardEntryKey_Emboldened GetEntryKey() const;
	ArkNpcBlackboardEntry_Emboldened MakeEntry() const;
#endif
};

// ArkNpcBlackboardEntryKey_EntityOccluded
// Header:  _unknown/ArkNpcBlackboardEntryKey_EntityOccluded.h
class ArkNpcBlackboardEntryKey_EntityOccluded : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_EntityOccluded>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardEntryKey_EntityOccluded(const ArkNpc& _arg0_, const unsigned _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_EntityOccluded& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
#endif
};

// ArkNpcBlackboardKey_EntityOccluded
// Header:  _unknown/ArkNpcBlackboardKey_EntityOccluded.h
class ArkNpcBlackboardKey_EntityOccluded : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_EntityOccluded,ArkNpcBlackboardEntry_EntityOccluded>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardKey_EntityOccluded(const ArkNpc& _arg0_, const unsigned _arg1_);
	ArkNpcBlackboardKey_EntityOccluded(const ArkNpc& _arg0_, const IEntity& _arg1_);
	ArkNpcBlackboardEntryKey_EntityOccluded GetEntryKey() const;
	ArkNpcBlackboardEntry_EntityOccluded MakeEntry() const;
	unsigned GetEntityId() const;
#endif
};

// ArkNpcBlackboardEntryKey_EntityReachable
// Header:  _unknown/ArkNpcBlackboardEntryKey_EntityReachable.h
class ArkNpcBlackboardEntryKey_EntityReachable : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_EntityReachable>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardEntryKey_EntityReachable(const ArkNpc& _arg0_, const unsigned _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_EntityReachable& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
#endif
};

// ArkNpcBlackboardKey_EntityReachable
// Header:  _unknown/ArkNpcBlackboardKey_EntityReachable.h
class ArkNpcBlackboardKey_EntityReachable : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_EntityReachable,ArkNpcBlackboardEntry_EntityReachable>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardKey_EntityReachable(const ArkNpc& _arg0_, const unsigned _arg1_);
	ArkNpcBlackboardKey_EntityReachable(const ArkNpc& _arg0_, const IEntity& _arg1_);
	ArkNpcBlackboardEntryKey_EntityReachable GetEntryKey() const;
	ArkNpcBlackboardEntry_EntityReachable MakeEntry() const;
	unsigned GetEntityId() const;
#endif
};

// ArkNpcBlackboardEntryKey_InCombat
// Header:  _unknown/ArkNpcBlackboardEntryKey_InCombat.h
class ArkNpcBlackboardEntryKey_InCombat : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_InCombat>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardEntryKey_InCombat(const ArkNpc& _arg0_);
#endif
};

// ArkNpcBlackboardKey_InCombat
// Header:  _unknown/ArkNpcBlackboardKey_InCombat.h
class ArkNpcBlackboardKey_InCombat : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_InCombat,ArkNpcBlackboardEntry_InCombat>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardKey_InCombat(const ArkNpc& _arg0_);
	ArkNpcBlackboardEntryKey_InCombat GetEntryKey() const;
	ArkNpcBlackboardEntry_InCombat MakeEntry() const;
#endif
};

// ArkNpcBlackboardEntryKey_LockedInMimicry
// Header:  _unknown/ArkNpcBlackboardEntryKey_LockedInMimicry.h
class ArkNpcBlackboardEntryKey_LockedInMimicry : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_LockedInMimicry>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardEntryKey_LockedInMimicry(const ArkNpc& _arg0_);
#endif
};

// ArkNpcBlackboardKey_LockedInMimicry
// Header:  _unknown/ArkNpcBlackboardKey_LockedInMimicry.h
class ArkNpcBlackboardKey_LockedInMimicry : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_LockedInMimicry,ArkNpcBlackboardEntry_LockedInMimicry>
{ // Size=8 (0x8)
public:
#if 0
	ArkNpcBlackboardKey_LockedInMimicry(const ArkNpc& _arg0_);
	ArkNpcBlackboardEntryKey_LockedInMimicry GetEntryKey() const;
	ArkNpcBlackboardEntry_LockedInMimicry MakeEntry() const;
#endif
};

// ArkNpcBlackboardEntryKey_LostVisibilityTime
// Header:  _unknown/ArkNpcBlackboardEntryKey_LostVisibilityTime.h
class ArkNpcBlackboardEntryKey_LostVisibilityTime : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_LostVisibilityTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardEntryKey_LostVisibilityTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_LostVisibilityTime& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
	unsigned GetEntityId() const;
#endif
};

// ArkNpcBlackboardKey_LostVisibilityTime
// Header:  _unknown/ArkNpcBlackboardKey_LostVisibilityTime.h
class ArkNpcBlackboardKey_LostVisibilityTime : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_LostVisibilityTime,ArkNpcBlackboardEntry_LostVisibilityTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardKey_LostVisibilityTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	ArkNpcBlackboardKey_LostVisibilityTime(const ArkNpc& _arg0_, const IEntity& _arg1_);
	ArkNpcBlackboardEntryKey_LostVisibilityTime GetEntryKey() const;
	ArkNpcBlackboardEntry_LostVisibilityTime MakeEntry() const;
#endif
};

#ifdef MOONCRASH
// ArkNpcBlackboardEntryKey_TargetArmedTime
// Header:  _unknown/ArkNpcBlackboardEntryKey_TargetArmedTime.h
class ArkNpcBlackboardEntryKey_TargetArmedTime : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_TargetArmedTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardEntryKey_TargetArmedTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_TargetArmedTime& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
	unsigned GetEntityId() const;
#endif
};
#endif // MOONCRASH

#ifdef MOONCRASH
// ArkNpcBlackboardKey_TargetArmedTime
// Header:  _unknown/ArkNpcBlackboardKey_TargetArmedTime.h
class ArkNpcBlackboardKey_TargetArmedTime : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_TargetArmedTime,ArkNpcBlackboardEntry_TargetArmedTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardKey_TargetArmedTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	ArkNpcBlackboardKey_TargetArmedTime(const ArkNpc& _arg0_, const IEntity& _arg1_);
	ArkNpcBlackboardEntryKey_TargetArmedTime GetEntryKey() const;
	ArkNpcBlackboardEntry_TargetArmedTime MakeEntry() const;
#endif
};
#endif // MOONCRASH

// ArkNpcBlackboardEntryKey_TargetEntity
// Header:  _unknown/ArkNpcBlackboardEntryKey_TargetEntity.h
class ArkNpcBlackboardEntryKey_TargetEntity : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_TargetEntity>
{ // Size=16 (0x10)
public:
	EArkNpcBlackboardTargetType m_targetType;

#if 0
	ArkNpcBlackboardEntryKey_TargetEntity(const ArkNpc& _arg0_, const EArkNpcBlackboardTargetType _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_TargetEntity& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
#endif
};

// ArkNpcBlackboardKey_TargetEntity
// Header:  _unknown/ArkNpcBlackboardKey_TargetEntity.h
class ArkNpcBlackboardKey_TargetEntity : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_TargetEntity,ArkNpcBlackboardEntry_TargetEntity>
{ // Size=16 (0x10)
public:
	EArkNpcBlackboardTargetType m_targetType;

#if 0
	ArkNpcBlackboardKey_TargetEntity(const ArkNpc& _arg0_, const EArkNpcBlackboardTargetType _arg1_);
	ArkNpcBlackboardEntryKey_TargetEntity GetEntryKey() const;
	ArkNpcBlackboardEntry_TargetEntity MakeEntry() const;
#endif
};

// ArkNpcBlackboardEntryKey_VisibilityTime
// Header:  _unknown/ArkNpcBlackboardEntryKey_VisibilityTime.h
class ArkNpcBlackboardEntryKey_VisibilityTime : public ArkNpcBlackboardEntryKeyTemplate<ArkNpcBlackboardEntryKey_VisibilityTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardEntryKey_VisibilityTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	bool EqualTo(const ArkNpcBlackboardEntryKey_VisibilityTime& _arg0_) const;
	uint64_t GetHash(const uint64_t _arg0_) const;
	unsigned GetEntityId() const;
#endif
};

// ArkNpcBlackboardKey_VisibilityTime
// Header:  _unknown/ArkNpcBlackboardKey_VisibilityTime.h
class ArkNpcBlackboardKey_VisibilityTime : public ArkNpcBlackboardKeyTemplate<ArkNpcBlackboardEntryKey_VisibilityTime,ArkNpcBlackboardEntry_VisibilityTime>
{ // Size=16 (0x10)
public:
	unsigned m_entityId;

#if 0
	ArkNpcBlackboardKey_VisibilityTime(const ArkNpc& _arg0_, const unsigned _arg1_);
	ArkNpcBlackboardKey_VisibilityTime(const ArkNpc& _arg0_, const IEntity& _arg1_);
	ArkNpcBlackboardEntryKey_VisibilityTime GetEntryKey() const;
	ArkNpcBlackboardEntry_VisibilityTime MakeEntry() const;
#endif
};
