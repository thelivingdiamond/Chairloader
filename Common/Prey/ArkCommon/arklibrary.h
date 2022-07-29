// Header file automatically created from a PDB.

#pragma once

class ArkNpcAbilityContext;
class ArkNpcAbilityContextProfile;

// Header: Exact
// Prey/ArkCommon/arklibrary.h
template <typename K, typename V>
class ArkLibrary // Id=8015891 Size=64
{
public:
	using ItemMap = std::unordered_map<K,V>;
	
	std::unordered_map<K,V> m_items;
	
#if 0
	ArkLibrary();
	ArkLibrary(ArkLibrary *_other);
	V &operator[](const uint64_t &arg0);
	void ReserveItems(uint64_t arg0);
	V &AddItem(const uint64_t &arg0, V const &arg1);
	uint64_t GetItemCount() const;
	bool HasItem(const uint64_t &arg0) const;
	V *FindItem(const uint64_t &arg0);
	V const *FindItem(const uint64_t &arg0) const;
	V &GetItem(const uint64_t &arg0);
	V const &GetItem(const uint64_t &arg0) const;
	void Clear();
#endif
};

