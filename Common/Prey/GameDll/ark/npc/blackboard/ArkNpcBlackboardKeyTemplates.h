// One instantiation per blackboard key. No method has an address, so they stay under #if 0.
#pragma once

class ArkNpc;

// Base of every ArkNpcBlackboardKey_*. Size=8.
// ValueType/ConstValueType come from the entry type (e.g. bool for Emboldened), so it must be complete.
template<typename EntryKey, typename Entry>
class ArkNpcBlackboardKeyTemplate
{
public:
	using EntryKeyType = EntryKey;
	using EntryType = Entry;
	using ValueType = typename Entry::ValueType;
	using ConstValueType = typename Entry::ConstValueType;

	const ArkNpc* m_pNpc;

#if 0
	const ArkNpc& GetNpc() const;
	ArkNpcBlackboardKeyTemplate(const ArkNpc&);
#endif
};

// Base of every ArkNpcBlackboardEntryKey_* (CRTP). Size=8.
template<typename DerivedKey>
class ArkNpcBlackboardEntryKeyTemplate
{
public:
	using DerivedKeyType = DerivedKey;

	const ArkNpc* m_pNpc;

#if 0
	const ArkNpc& GetNpc() const;
	ArkNpcBlackboardEntryKeyTemplate(const ArkNpc&);
	bool EqualTo(const DerivedKey&) const;
	uint64_t GetHash(const uint64_t) const;
#endif
};

// Hash functor for the blackboard's per-key unordered_maps. Size=1.
template<typename EntryKey>
struct ArkNpcBlackboardEntryKeyHash
{
#if 0
	uint64_t operator()(const EntryKey&) const;
#endif
};

// Equality functor for the blackboard's per-key unordered_maps. Size=1.
template<typename EntryKey>
struct ArkNpcBlackboardEntryKeyEqualTo
{
#if 0
	bool operator()(const EntryKey&, const EntryKey&) const;
#endif
};
