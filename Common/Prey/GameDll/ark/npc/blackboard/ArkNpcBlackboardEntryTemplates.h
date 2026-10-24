// Primary templates reproducing the game's instantiations.
// No methods have addresses (all inlined), so they stay under #if 0.
#pragma once

// Instantiations: LostVisibilityTime, VisibilityTime (float, float), TargetArmedTime (Mooncrash). Size=1 (empty).
template<typename BlackboardKey, typename EntryKey, typename DerivedEntry, typename Value, typename ConstValue>
class ArkNpcBlackboardEntryTemplate_GetUpdate
{
public:
	using BlackboardKeyType = BlackboardKey;
	using EntryKeyType = EntryKey;
	using DerivedEntryType = DerivedEntry;
	using ValueType = Value;
	using ConstValueType = ConstValue;

#if 0
	ValueType GetValue(const BlackboardKey&);
	ConstValueType GetValue(const BlackboardKey&) const;
	void UpdateEntry(const EntryKey&, const float);
#endif
};

// Instantiations: EntityOccluded, EntityReachable (bool, bool), TargetPosition (const boost::optional<Vec3>&). Size=1.
template<typename BlackboardKey, typename EntryKey, typename DerivedEntry, typename Value, typename ConstValue>
class ArkNpcBlackboardEntryTemplate_LazyGet
{
public:
	using BlackboardKeyType = BlackboardKey;
	using EntryKeyType = EntryKey;
	using DerivedEntryType = DerivedEntry;
	using ValueType = Value;
	using ConstValueType = ConstValue;

	bool m_bEvaluated;

#if 0
	ValueType GetValue(const BlackboardKey&);
	ConstValueType GetValue(const BlackboardKey&) const;
	void UpdateEntry(const EntryKey&, const float);
#endif
};

// Instantiations: Emboldened (bool, bool). Size=1.
template<typename BlackboardKey, typename EntryKey, typename DerivedEntry, typename Value, typename ConstValue>
class ArkNpcBlackboardEntryTemplate_LazyGetUpdate
{
public:
	using BlackboardKeyType = BlackboardKey;
	using EntryKeyType = EntryKey;
	using DerivedEntryType = DerivedEntry;
	using ValueType = Value;
	using ConstValueType = ConstValue;

	bool m_bEvaluated;

#if 0
	ValueType GetValue(const BlackboardKey&);
	ConstValueType GetValue(const BlackboardKey&) const;
	void UpdateEntry(const EntryKey&, const float);
#endif
};

// Instantiations: InCombat, LockedInMimicry (bool, bool), TargetEntity (IEntity*). Size=1 (empty).
template<typename BlackboardKey, typename EntryKey, typename DerivedEntry, typename Value, typename ConstValue>
class ArkNpcBlackboardEntryTemplate_SetGet
{
public:
	using BlackboardKeyType = BlackboardKey;
	using EntryKeyType = EntryKey;
	using DerivedEntryType = DerivedEntry;
	using ValueType = Value;
	using ConstValueType = ConstValue;

#if 0
	ValueType GetValue(const BlackboardKey&);
	ConstValueType GetValue(const BlackboardKey&) const;
	void UpdateEntry(const EntryKey&, float);
#endif
};
