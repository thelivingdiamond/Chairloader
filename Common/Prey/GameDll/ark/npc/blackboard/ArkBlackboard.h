// The only instantiation is ArkNpcBlackboardManager's
//   ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_...>, ArkNpcBlackboardEntryKeyHash, ArkNpcBlackboardEntryKeyEqualTo>
// (8 keys / Size=576; Mooncrash 9 keys / Size=648: one 72-byte variant per key).
// No method has an address, so they stay under #if 0.
#pragma once
#include <array>
#include <unordered_map>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/variant.hpp>

template<typename TKeyTypes, template<typename> class Hash, template<typename> class EqualTo>
class ArkBlackboard
{
public:
	// Size = 8 + sizeof(Entry), e.g. 40 for ArkNpcBlackboardEntry_Emboldened.
	template<typename Entry>
	struct RefCountedEntry
	{
		uint64_t m_count;
		Entry m_entry;

#if 0
		RefCountedEntry(Entry&&);
#endif
	};

	// Size=1 metafunction: blackboard key -> map from its entry key to its ref-counted entry.
	template<typename Key>
	struct KeyToEntryMapType
	{
		using type = std::unordered_map<
			typename Key::EntryKeyType,
			RefCountedEntry<typename Key::EntryType>,
			Hash<typename Key::EntryKeyType>,
			EqualTo<typename Key::EntryKeyType>>;
	};

	// Only declared in the game's header.
	struct IsEmptyVisitor;

	template<typename Function>
	struct ForEachElemVisitor : public boost::static_visitor<void>
	{
		Function& m_function;

#if 0
		ForEachElemVisitor(Function&);
#endif
	};

	using KeyTypes = TKeyTypes;
	using EntryMapTypes = typename boost::mpl::transform<KeyTypes, KeyToEntryMapType<boost::mpl::_1>>::type;
	using EntryMapVariant = typename boost::make_variant_over<EntryMapTypes>::type;

	static constexpr const uint64_t k_entryTypeCount = boost::mpl::size<KeyTypes>::value;
	using EntryMapArray = std::array<EntryMapVariant, k_entryTypeCount>;

	// Size=1 recursive helper, instantiated for Index = 0..Count.
	template<int Index, int Count>
	struct Initializer
	{
#if 0
		static void Initialize(EntryMapArray&);
#endif
	};

	EntryMapArray m_entries;

#if 0
	ArkBlackboard();
	~ArkBlackboard();
	bool IsEmpty() const;
#endif
};
