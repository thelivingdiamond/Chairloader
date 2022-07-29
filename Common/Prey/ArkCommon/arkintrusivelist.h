// Header file automatically created from a PDB.

#pragma once

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
	//using iterator = ArkIntrusiveListImpl::ArkIntrusiveListIterator<T>;
	//using const_iterator = ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T>;
	//using reverse_iterator = std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<T> >;
	//using const_reverse_iterator = std::reverse_iterator<ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<T> >;
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

