// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkresearchtopic.h
class ArkResearchTopicAbilityGroup : public ArkReflectedObject // Id=8016B61 Size=32
{
public:
	class ArkScansRequiredProperty : public ArkProperty // Id=8016B62 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopicAbilityGroup::ArkScansRequiredProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopicAbilityGroup::ArkScansRequiredProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkResearchTopicAbilityGroup::ArkScansRequiredProperty s_ArkScansRequiredProperty;
	int m_ScansRequired;
	
	class ArkAbilitiesProperty : public ArkProperty // Id=8016B63 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopicAbilityGroup::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107BFE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopicAbilityGroup::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107C000);
		static inline auto FIsArray = PreyFunction<bool(ArkResearchTopicAbilityGroup::ArkAbilitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkResearchTopicAbilityGroup::ArkAbilitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x107C020);
	};

	static ArkResearchTopicAbilityGroup::ArkAbilitiesProperty s_ArkAbilitiesProperty;
	std::vector<unsigned __int64> m_Abilities;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetScansRequired(int arg0);
	const int &GetScansRequired() const;
	std::vector<unsigned __int64> &GetAbilities();
	std::vector<unsigned __int64> const &GetAbilities() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1071490);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107D090);
};

// Header: Exact
// Prey/Ark/ArkResearchTopic.h
class ArkResearchTopic : public ArkReflectedObject // Id=8016B64 Size=88
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016B65 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkResearchTopic::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016B66 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkResearchTopic::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLoreScansRequiredProperty : public ArkProperty // Id=8016B67 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkLoreScansRequiredProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkLoreScansRequiredProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkResearchTopic::ArkLoreScansRequiredProperty s_ArkLoreScansRequiredProperty;
	int m_LoreScansRequired;
	
	class ArkLoreProperty : public ArkProperty // Id=8016B68 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkLoreProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkLoreProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkResearchTopic::ArkLoreProperty s_ArkLoreProperty;
	uint64_t m_Lore;
	
	class ArkAbilityGroupsProperty : public ArkProperty // Id=8016B69 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkAbilityGroupsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107C030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkAbilityGroupsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107C070);
		static inline auto FIsArray = PreyFunction<bool(ArkResearchTopic::ArkAbilityGroupsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkResearchTopic::ArkAbilityGroupsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107C090);
	};

	static ArkResearchTopic::ArkAbilityGroupsProperty s_ArkAbilityGroupsProperty;
	std::vector<ArkResearchTopicAbilityGroup> m_AbilityGroups;
	
	class ArkMetaTagsProperty : public ArkProperty // Id=8016B77 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopic::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopic::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(ArkResearchTopic::ArkMetaTagsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkResearchTopic::ArkMetaTagsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkResearchTopic::ArkMetaTagsProperty s_ArkMetaTagsProperty;
	std::vector<unsigned __int64> m_MetaTags;
	int m_maxScansRequired;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLoreScansRequired(int arg0);
	const int &GetLoreScansRequired() const;
	void SetLore(uint64_t arg0);
	const uint64_t &GetLore() const;
	std::vector<ArkResearchTopicAbilityGroup> &GetAbilityGroups();
	std::vector<ArkResearchTopicAbilityGroup> const &GetAbilityGroups() const;
	std::vector<unsigned __int64> &GetMetaTags();
	std::vector<unsigned __int64> const &GetMetaTags() const;
	int GetMaxScansRequired() const;
	void SetMaxScansRequired(const int arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107CF00);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107CFF0);
};

// Header: Exact
// Prey/Ark/arkresearchtopic.h
class ArkResearchTopics : public ArkReflectedLibrary // Id=8016B86 Size=32
{
public:
	class ArkTopicsProperty : public ArkProperty // Id=8016B87 Size=32
	{
	public:
		ArkTopicsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkResearchTopics::ArkTopicsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107BE30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkResearchTopics::ArkTopicsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107BF00);
		static inline auto FIsArray = PreyFunction<bool(ArkResearchTopics::ArkTopicsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkResearchTopics::ArkTopicsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107BF40);
	};

	static ArkResearchTopics::ArkTopicsProperty s_ArkTopicsProperty;
	std::vector<ArkResearchTopic> m_Topics;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkResearchTopic const *Find(const uint64_t _id) const { return FFindOv1(this,_id); }
	std::vector<ArkResearchTopic const *> GetResearchTopicsForTags(std::vector<unsigned __int64> _tags) const { return FGetResearchTopicsForTags(this,_tags); }
	ArkResearchTopic const *GetResearchTopicByLore(const uint64_t _id) const { return FGetResearchTopicByLore(this,_id); }
	virtual ~ArkResearchTopics();
	
#if 0
	std::vector<ArkResearchTopic> &GetTopics();
	std::vector<ArkResearchTopic> const &GetTopics() const;
	ArkResearchTopic const *Find(const char *arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x107CF60);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x107D130);
	static inline auto FInit = PreyFunction<bool(ArkResearchTopics *const _this)>(0x107D330);
	static inline auto FFindOv1 = PreyFunction<ArkResearchTopic const *(ArkResearchTopics const *const _this, const uint64_t _id)>(0x107CFC0);
	static inline auto FGetResearchTopicsForTags = PreyFunction<std::vector<ArkResearchTopic const *>(ArkResearchTopics const *const _this, std::vector<unsigned __int64> _tags)>(0x107D250);
	static inline auto FGetResearchTopicByLore = PreyFunction<ArkResearchTopic const *(ArkResearchTopics const *const _this, const uint64_t _id)>(0x107D220);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkResearchTopicAbilityGroup
// Header:  Prey/Ark/ArkResearchTopic.h
class ArkResearchTopicAbilityGroup : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkResearchTopicAbilityGroup::ArkScansRequiredProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkScansRequiredProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkScansRequiredProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopicAbilityGroup::ArkScansRequiredProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopicAbilityGroup::ArkScansRequiredProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkResearchTopicAbilityGroup::ArkAbilitiesProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkAbilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkAbilitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopicAbilityGroup::ArkAbilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopicAbilityGroup::ArkAbilitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A5720);
		static inline auto FIsArray = PreyFunction<bool(const ArkResearchTopicAbilityGroup::ArkAbilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkResearchTopicAbilityGroup::ArkAbilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x139EF00);
	};

	static inline auto s_ArkScansRequiredProperty = PreyGlobal<ArkResearchTopicAbilityGroup::ArkScansRequiredProperty>(0x2D27DD0);
	int m_ScansRequired;
	static inline auto s_ArkAbilitiesProperty = PreyGlobal<ArkResearchTopicAbilityGroup::ArkAbilitiesProperty>(0x2D27DF0);
	std::vector<uint64_t> m_Abilities;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetScansRequired(int _arg0_);
	const int& GetScansRequired() const;
	std::vector<uint64_t>& GetAbilities();
	const std::vector<uint64_t>& GetAbilities() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A6840);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A69B0);
};

// ArkResearchTopic
// Header:  Prey/Ark/ArkResearchTopic.h
class ArkResearchTopic : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkResearchTopic::ArkIDProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkResearchTopic::ArkNameProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkResearchTopic::ArkLoreScansRequiredProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkLoreScansRequiredProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoreScansRequiredProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkLoreScansRequiredProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkLoreScansRequiredProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkResearchTopic::ArkLoreProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkLoreProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoreProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkLoreProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkLoreProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkResearchTopic::ArkAbilityGroupsProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkAbilityGroupsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkAbilityGroupsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkAbilityGroupsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkAbilityGroupsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A5780);
		static inline auto FIsArray = PreyFunction<bool(const ArkResearchTopic::ArkAbilityGroupsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkResearchTopic::ArkAbilityGroupsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A57A0);
	};

	// ArkResearchTopic::ArkMetaTagsProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopic::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopic::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073740);
		static inline auto FIsArray = PreyFunction<bool(const ArkResearchTopic::ArkMetaTagsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkResearchTopic::ArkMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkResearchTopic::ArkIDProperty>(0x2D27E10);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkResearchTopic::ArkNameProperty>(0x2D27E30);
	string m_Name;
	static inline auto s_ArkLoreScansRequiredProperty = PreyGlobal<ArkResearchTopic::ArkLoreScansRequiredProperty>(0x2D27E50);
	int m_LoreScansRequired;
	static inline auto s_ArkLoreProperty = PreyGlobal<ArkResearchTopic::ArkLoreProperty>(0x2D27E70);
	uint64_t m_Lore;
	static inline auto s_ArkAbilityGroupsProperty = PreyGlobal<ArkResearchTopic::ArkAbilityGroupsProperty>(0x2D27E90);
	std::vector<ArkResearchTopicAbilityGroup> m_AbilityGroups;
	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkResearchTopic::ArkMetaTagsProperty>(0x2D27EB0);
	std::vector<uint64_t> m_MetaTags;
	int m_maxScansRequired;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLoreScansRequired(int _arg0_);
	const int& GetLoreScansRequired() const;
	void SetLore(uint64_t _arg0_);
	const uint64_t& GetLore() const;
	std::vector<ArkResearchTopicAbilityGroup>& GetAbilityGroups();
	const std::vector<ArkResearchTopicAbilityGroup>& GetAbilityGroups() const;
	std::vector<uint64_t>& GetMetaTags();
	const std::vector<uint64_t>& GetMetaTags() const;
	int GetMaxScansRequired() const;
	void SetMaxScansRequired(const int _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A67E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A6910);
};

// ArkResearchTopics
// Header:  Prey/Ark/ArkResearchTopic.h
class ArkResearchTopics : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkResearchTopics::ArkTopicsProperty
	// Header:  Prey/Ark/ArkResearchTopic.h
	class ArkTopicsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkTopicsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkTopicsPropertyOv2 = PreyFunction<void(ArkResearchTopics::ArkTopicsProperty* const _this)>(0x10A64C0);
		static inline auto FSetValue = PreyFunction<void(const ArkResearchTopics::ArkTopicsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5820);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkResearchTopics::ArkTopicsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A58F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkResearchTopics::ArkTopicsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkResearchTopics::ArkTopicsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A5930);
	};

	static inline auto s_ArkTopicsProperty = PreyGlobal<ArkResearchTopics::ArkTopicsProperty>(0x2D27ED0);
	std::vector<ArkResearchTopic> m_Topics;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkResearchTopic* Find(const uint64_t _id) const { return FFindOv1(this, _id); }
	std::vector<const ArkResearchTopic*> GetResearchTopicsForTags(std::vector<uint64_t> _tags) const { alignas(std::vector<const ArkResearchTopic*>) std::byte _return_buf_[sizeof(std::vector<const ArkResearchTopic*>)]; return *FGetResearchTopicsForTags(this, reinterpret_cast<std::vector<const ArkResearchTopic*>*>(_return_buf_), _tags); }
	const ArkResearchTopic* GetResearchTopicByLore(const uint64_t _id) const { return FGetResearchTopicByLore(this, _id); }

#if 0
	std::vector<ArkResearchTopic>& GetTopics();
	const std::vector<ArkResearchTopic>& GetTopics() const;
	const ArkResearchTopic* Find(const char* _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A6880);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A6A50);
	static inline auto FInit = PreyFunction<bool(ArkResearchTopics* const _this)>(0x10A6C60);
	static inline auto FFindOv1 = PreyFunction<const ArkResearchTopic* (const ArkResearchTopics* const _this, const uint64_t _id)>(0x10A68E0);
	static inline auto FGetResearchTopicsForTags = PreyFunction<std::vector<const ArkResearchTopic*>*(const ArkResearchTopics* const _this, std::vector<const ArkResearchTopic*>* _return_value_, std::vector<uint64_t> _tags)>(0x10A6B70);
	static inline auto FGetResearchTopicByLore = PreyFunction<const ArkResearchTopic* (const ArkResearchTopics* const _this, const uint64_t _id)>(0x10A6B40);
};
#endif // !MOONCRASH
