// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContext.h>
#include <Prey/GameDll/ark/npc/ability/context/ArkNpcAbilityContextProfile.h>

class ArkNpcAbility;
class ArkNpcGameEffect;

// ArkLibrary<unsigned __int64,ArkNpcAbilityContext>
// Header:  Prey/ArkCommon/arklibrary.h
class ArkLibrary<unsigned __int64,ArkNpcAbilityContext>
{ // Size=64 (0x40)
public:
	using ItemMap = std::unordered_map<uint64_t, ArkNpcAbilityContext>;

	std::unordered_map<uint64_t, ArkNpcAbilityContext> m_items;

	bool HasItem(const uint64_t& _itemId) const { return FHasItem(this, _itemId); }

#if 0
	ArkLibrary<unsigned __int64,ArkNpcAbilityContext>();
	ArkLibrary<unsigned __int64,ArkNpcAbilityContext>(const ArkLibrary<unsigned __int64,ArkNpcAbilityContext>& _arg0_);
	ArkLibrary<unsigned __int64,ArkNpcAbilityContext>(ArkLibrary<unsigned __int64,ArkNpcAbilityContext>&& _arg0_);
	ArkLibrary<unsigned __int64,ArkNpcAbilityContext>& operator=(ArkLibrary<unsigned __int64,ArkNpcAbilityContext> _arg0_);
	ArkNpcAbilityContext& operator[](const uint64_t& _arg0_);
	void ReserveItems(uint64_t _arg0_);
	ArkNpcAbilityContext& AddItem(const uint64_t& _arg0_, const ArkNpcAbilityContext& _arg1_);
	uint64_t GetItemCount() const;
	ArkNpcAbilityContext* FindItem(const uint64_t& _arg0_);
	const ArkNpcAbilityContext* FindItem(const uint64_t& _arg0_) const;
	ArkNpcAbilityContext& GetItem(const uint64_t& _arg0_);
	const ArkNpcAbilityContext& GetItem(const uint64_t& _arg0_) const;
	void Clear();
#endif

	static inline auto FHasItem = PreyFunction<bool(const ArkLibrary<unsigned __int64,ArkNpcAbilityContext>* const _this, const uint64_t& _itemId)>(0x138B970);
};

// ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>
// Header:  Prey/ArkCommon/arklibrary.h
class ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>
{ // Size=64 (0x40)
public:
	using ItemMap = std::unordered_map<uint64_t, ArkNpcAbilityContextProfile>;

	std::unordered_map<uint64_t, ArkNpcAbilityContextProfile> m_items;

	ArkNpcAbilityContextProfile* FindItem(const uint64_t& _itemId) { return FFindItemOv1(this, _itemId); }
	void Clear() { FClear(this); }

#if 0
	ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>();
	ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>(const ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>& _arg0_);
	ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>(ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>&& _arg0_);
	ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>& operator=(ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile> _arg0_);
	ArkNpcAbilityContextProfile& operator[](const uint64_t& _arg0_);
	void ReserveItems(uint64_t _arg0_);
	ArkNpcAbilityContextProfile& AddItem(const uint64_t& _arg0_, const ArkNpcAbilityContextProfile& _arg1_);
	uint64_t GetItemCount() const;
	bool HasItem(const uint64_t& _arg0_) const;
	const ArkNpcAbilityContextProfile* FindItem(const uint64_t& _arg0_) const;
	ArkNpcAbilityContextProfile& GetItem(const uint64_t& _arg0_);
	const ArkNpcAbilityContextProfile& GetItem(const uint64_t& _arg0_) const;
#endif

	static inline auto FFindItemOv1 = PreyFunction<ArkNpcAbilityContextProfile* (ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>* const _this, const uint64_t& _itemId)>(0x1380610);
	static inline auto FClear = PreyFunction<void(ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>* const _this)>(0x1380270);
};

// ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >
// Header:  Prey/ArkCommon/arklibrary.h
class ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >
{ // Size=64 (0x40)
public:
	using ItemMap = std::unordered_map<uint64_t, std::unique_ptr<ArkNpcAbility>>;

	std::unordered_map<uint64_t, std::unique_ptr<ArkNpcAbility>> m_items;

	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >();
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >&& _other);

#if 0
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >(const ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >& _arg0_);
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >& operator=(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > > _arg0_);
	std::unique_ptr<ArkNpcAbility>& operator[](const uint64_t& _arg0_);
	void ReserveItems(uint64_t _arg0_);
	std::unique_ptr<ArkNpcAbility>& AddItem(const uint64_t& _arg0_, const std::unique_ptr<ArkNpcAbility>& _arg1_);
	uint64_t GetItemCount() const;
	bool HasItem(const uint64_t& _arg0_) const;
	std::unique_ptr<ArkNpcAbility>* FindItem(const uint64_t& _arg0_);
	const std::unique_ptr<ArkNpcAbility>* FindItem(const uint64_t& _arg0_) const;
	std::unique_ptr<ArkNpcAbility>& GetItem(const uint64_t& _arg0_);
	const std::unique_ptr<ArkNpcAbility>& GetItem(const uint64_t& _arg0_) const;
	void Clear();
#endif

	static inline auto FArkLibraryLessunsigned __int64Commastd::unique_ptrLessArkNpcAbilityCommastd::default_deleteLessArkNpcAbilityGreater Greater GreaterOv2 = PreyFunction<void(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >* const _this)>(0x137A450);
	static inline auto FArkLibraryLessunsigned __int64Commastd::unique_ptrLessArkNpcAbilityCommastd::default_deleteLessArkNpcAbilityGreater Greater GreaterOv0 = PreyFunction<void(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >* const _this, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >&& _other)>(0x137A380);
};

// ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >
// Header:  Prey/ArkCommon/arklibrary.h
class ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >
{ // Size=64 (0x40)
public:
	using ItemMap = std::unordered_map<uint64_t, std::unique_ptr<ArkNpcGameEffect>>;

	std::unordered_map<uint64_t, std::unique_ptr<ArkNpcGameEffect>> m_items;

	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >();
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >&& _other);

#if 0
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >(const ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >& _arg0_);
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >& operator=(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > > _arg0_);
	std::unique_ptr<ArkNpcGameEffect>& operator[](const uint64_t& _arg0_);
	void ReserveItems(uint64_t _arg0_);
	std::unique_ptr<ArkNpcGameEffect>& AddItem(const uint64_t& _arg0_, const std::unique_ptr<ArkNpcGameEffect>& _arg1_);
	uint64_t GetItemCount() const;
	bool HasItem(const uint64_t& _arg0_) const;
	std::unique_ptr<ArkNpcGameEffect>* FindItem(const uint64_t& _arg0_);
	const std::unique_ptr<ArkNpcGameEffect>* FindItem(const uint64_t& _arg0_) const;
	std::unique_ptr<ArkNpcGameEffect>& GetItem(const uint64_t& _arg0_);
	const std::unique_ptr<ArkNpcGameEffect>& GetItem(const uint64_t& _arg0_) const;
	void Clear();
#endif

	static inline auto FArkLibraryLessunsigned __int64Commastd::unique_ptrLessArkNpcGameEffectCommastd::default_deleteLessArkNpcGameEffectGreater Greater GreaterOv2 = PreyFunction<void(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >* const _this)>(0x1341FA0);
	static inline auto FArkLibraryLessunsigned __int64Commastd::unique_ptrLessArkNpcGameEffectCommastd::default_deleteLessArkNpcGameEffectGreater Greater GreaterOv0 = PreyFunction<void(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >* const _this, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >&& _other)>(0x1341ED0);
};
#endif // !MOONCRASH
