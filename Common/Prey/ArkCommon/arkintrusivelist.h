// Header file automatically created from a PDB.

#pragma once
#include <iterator>

template <typename T>
class ArkIntrusiveList;

template <typename T>
class ArkIntrusiveListElement // Id=801416A Size=24
{
public:
	ArkIntrusiveList<T>* m_pList;
	ArkIntrusiveListElement<T>* m_pPrev;
	ArkIntrusiveListElement<T>* m_pNext;

#if 0
	bool IsLinked() const;
	void Unlink();
	ArkIntrusiveListElement<T>& Prev() const;
	ArkIntrusiveListElement<T>& Next() const;
	bool IsInList(ArkIntrusiveList<T> const& arg0) const;
	ArkIntrusiveList<T>& GetList() const;
	void Insert(ArkIntrusiveList<T>& arg0, ArkIntrusiveListElement<T>& arg1);
	void Remove();
#endif
};

// The std::iterator base (deprecated in C++17) is replaced by the same typedefs. Size=8.
namespace ArkIntrusiveListImpl
{

template <typename T>
class ArkIntrusiveListIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = T;
	using difference_type = int64_t;
	using pointer = T*;
	using reference = T&;

	ArkIntrusiveListElement<T>* m_pElem;

#if 0
	ArkIntrusiveListIterator();
	ArkIntrusiveListIterator(const ArkIntrusiveListIterator<T>&);
	ArkIntrusiveListIterator(ArkIntrusiveListElement<T>&);
	ArkIntrusiveListIterator<T>& operator=(const ArkIntrusiveListIterator<T>&);
	operator ArkIntrusiveListConstIterator<T>() const;
	ArkIntrusiveListIterator<T>& operator--();
	ArkIntrusiveListIterator<T> operator--(int);
	ArkIntrusiveListIterator<T>& operator++();
	ArkIntrusiveListIterator<T> operator++(int);
	bool operator==(const ArkIntrusiveListIterator<T>&) const;
	bool operator!=(const ArkIntrusiveListIterator<T>&) const;
	T& operator*() const;
	T* operator->() const;
#endif
};

template <typename T>
class ArkIntrusiveListConstIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = const T;
	using difference_type = int64_t;
	using pointer = const T*;
	using reference = const T&;

	ArkIntrusiveListElement<T>* m_pElem; // non-const in the game

#if 0
	ArkIntrusiveListConstIterator();
	ArkIntrusiveListConstIterator(const ArkIntrusiveListConstIterator<T>&);
	ArkIntrusiveListConstIterator(const ArkIntrusiveListElement<T>&);
	ArkIntrusiveListConstIterator<T>& operator=(const ArkIntrusiveListConstIterator<T>&);
	ArkIntrusiveListConstIterator<T>& operator--();
	ArkIntrusiveListConstIterator<T> operator--(int);
	ArkIntrusiveListConstIterator<T>& operator++();
	ArkIntrusiveListConstIterator<T> operator++(int);
	bool operator==(const ArkIntrusiveListConstIterator<T>&) const;
	bool operator!=(const ArkIntrusiveListConstIterator<T>&) const;
	T& operator*() const;
	T* operator->() const;
#endif
};

} // namespace ArkIntrusiveListImpl


// Header: Exact
// Prey/ArkCommon/arkintrusivelist.h
template <typename T>
class ArkIntrusiveList // Id=8014096 Size=32
{
public:
	using value_type = T;
	using reference = T &;
	using const_reference = T const &;
	using pointer = T *;
	using const_pointer = T const *;
	using iterator = ArkIntrusiveListImpl::ArkIntrusiveListIterator<T>;
	using const_iterator = ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T>;
	using reverse_iterator = std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> >;
	using const_reverse_iterator = std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> >;
	using difference_type = int64_t;
	using size_type = uint64_t;
	
	uint64_t m_size;
	ArkIntrusiveListElement<T> m_head;
	
#if 0
	~ArkIntrusiveList<T>();
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> begin();
	ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> begin() const;
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> end();
	ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> end() const;
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> > rbegin();
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> > rbegin() const;
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> > rend();
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> > rend() const;
	ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> cbegin() const;
	ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> cend() const;
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> > crbegin() const;
	std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> > crend() const;
	bool empty() const;
	uint64_t size() const;
	uint64_t max_size() const;
	T &front();
	T const &front() const;
	T &back();
	T const &back() const;
	void pop_front();
	void push_front(T &arg0);
	void push_back(T &arg0);
	void pop_back();
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> insert(ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> arg0, T &arg1);
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> erase(ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> arg0);
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> erase(ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> arg0, ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> arg1);
	void clear();
	void remove(T &arg0);
	ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> find(T &arg0);
	ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> find(T const &arg0) const;
	void unsafe_remove(ArkIntrusiveListElement<T> &arg0);
#endif
};
