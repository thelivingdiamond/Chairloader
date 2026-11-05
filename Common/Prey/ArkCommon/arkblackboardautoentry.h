// One per key held by ArkNpcBlackboardCombatGroup. Size = 8 + sizeof(boost::optional<Key>).
// Methods stay under #if 0: their addresses differ per instantiation.
#pragma once
#include <boost/optional.hpp>

template<typename Blackboard, typename Key>
class ArkBlackboardAutoEntry
{
public:
	using BlackboardType = Blackboard;
	using KeyType = Key;
	using EntryType = typename Key::EntryType;
	using ValueType = typename Key::ValueType;
	using ConstValueType = typename Key::ConstValueType;

	Blackboard* m_pBlackboard;
	boost::optional<Key> m_optEntryKey;

#if 0
	ArkBlackboardAutoEntry();
	ArkBlackboardAutoEntry(const ArkBlackboardAutoEntry&);
	ArkBlackboardAutoEntry(ArkBlackboardAutoEntry&&);
	~ArkBlackboardAutoEntry();
	ArkBlackboardAutoEntry& operator=(ArkBlackboardAutoEntry);
	void Reset();
	Blackboard& GetBlackboard() const;
	const Key& GetKey() const;
	ValueType GetValue();
	ConstValueType GetValue() const;
	EntryType& GetEntry();
	const EntryType& GetEntry() const;
#endif
};
