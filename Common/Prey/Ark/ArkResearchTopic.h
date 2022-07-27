// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkresearchtopic.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

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

