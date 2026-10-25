// The std::iterator base (deprecated in C++17) is replaced by the same typedefs; layout is unchanged.
#pragma once
#include <iterator>

template<typename Iterator>
class ArkSafeIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = typename std::iterator_traits<Iterator>::value_type;
	using difference_type = int64_t;
	using pointer = value_type*;
	using reference = value_type&;

	Iterator m_iter;
	bool m_bInvalidated;

#if 0
	ArkSafeIterator();
	ArkSafeIterator(const Iterator&);
	ArkSafeIterator(const ArkSafeIterator<Iterator>&);
	ArkSafeIterator<Iterator>& operator=(const Iterator&);
	ArkSafeIterator<Iterator>& operator=(const ArkSafeIterator<Iterator>&);
	operator Iterator() const;
	ArkSafeIterator<Iterator>& operator++();
	ArkSafeIterator<Iterator> operator++(int);
	bool operator==(const Iterator&) const;
	bool operator==(const ArkSafeIterator<Iterator>&) const;
	bool operator!=(const Iterator&) const;
	bool operator!=(const ArkSafeIterator<Iterator>&) const;
	reference operator*() const;
	pointer operator->() const;
	Iterator GetBase() const;
	void Invalidate(const Iterator&);
#endif
};
