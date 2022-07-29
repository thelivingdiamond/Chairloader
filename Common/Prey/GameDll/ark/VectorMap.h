// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/VectorMap.h
template <typename TKey, typename TValue, typename TCompare, typename TAllocator>
class VectorMap : private TCompare // Id=8000387 Size=24
{
public:
	union key_type // Id=800038B Size=16
	{
	public:
		uint64_t a;
		uint64_t b;
		uint16_t nWidth;
		uint16_t nHeight;
		unsigned nFormat;
		uint8_t nTexType;
		uint8_t nMips;
		uint16_t nArraySize;
		
#if 0
		void TexturePoolKey(uint16_t arg0, uint16_t arg1, unsigned arg2, uint8_t arg3, uint8_t arg4, uint16_t arg5); // :-1 Refs: 0
		void GetMemoryUsage(ICrySizer *arg0) const; // :-1 Refs: 0
#endif
	};

	using mapped_type = TValue;
	using allocator_type = TAllocator;
	using value_type = std::pair<TKey,TValue>;
	using key_compare = TCompare;
	
	class FirstLess // Id=800038F Size=0
	{
	public:
	};

	using container_type = std::vector<std::pair<TKey,TValue>>;
	using iterator = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > >;
	using const_iterator = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > >;
	using reverse_iterator = std::reverse_iterator<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > >;
	using const_reverse_iterator = std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > >;
	using reference = std::pair<TKey,TValue> &;
	using const_reference = std::pair<TKey,TValue> const &;
	using pointer = std::pair<TKey,TValue> *;
	using const_pointer = std::pair<TKey,TValue> const *;
	using size_type = uint64_t;
	
	std::vector<std::pair<TKey,TValue>> m_entries;
	
#if 0
	void SwapElementsWithVector(std::vector<std::pair<TKey,TValue>> &arg0); // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > begin(); // :-1 Refs: 0
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > begin() const; // :-1 Refs: 0
	uint64_t capacity() const; // :-1 Refs: 0
	void clear(); // :-1 Refs: 0
	void clearAndFreeMemory(); // :-1 Refs: 0
	uint64_t count(TKey const &arg0) const; // :-1 Refs: 0
	bool empty() const; // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > end(); // :-1 Refs: 0
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > end() const; // :-1 Refs: 0
	std::pair<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > >,std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > equal_range(TKey const &arg0); // :-1 Refs: 0
	std::pair<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > >,std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > equal_range(TKey const &arg0) const; // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > erase(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > arg0); // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > erase(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > arg0, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > arg1); // :-1 Refs: 0
	void erase(TKey const &arg0); // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > find(TKey const &arg0); // :-1 Refs: 0
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > find(TKey const &arg0) const; // :-1 Refs: 0
	TAllocator get_allocator() const; // :-1 Refs: 0
	std::pair<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > >,bool> insert(std::pair<TKey,TValue> const &arg0); // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > insert(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > arg0, std::pair<TKey,TValue> const &arg1); // :-1 Refs: 0
	TCompare key_comp() const; // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > lower_bound(TKey const &arg0); // :-1 Refs: 0
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > lower_bound(TKey const &arg0) const; // :-1 Refs: 0
	uint64_t max_size() const; // :-1 Refs: 0
	std::reverse_iterator<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > rbegin(); // :-1 Refs: 0
	std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > rbegin() const; // :-1 Refs: 0
	std::reverse_iterator<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > rend(); // :-1 Refs: 0
	std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > > rend() const; // :-1 Refs: 0
	void reserve(uint64_t arg0); // :-1 Refs: 0
	uint64_t size() const; // :-1 Refs: 0
	void swap(VectorMap<TKey,TValue,TCompare,TAllocator > &arg0); // :-1 Refs: 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > upper_bound(TKey const &arg0); // :-1 Refs: 0
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<TKey,TValue> > > > upper_bound(TKey const &arg0) const; // :-1 Refs: 0
	TValue&operator[](TKey const &arg0); // :-1 Refs: 0
#endif
};
