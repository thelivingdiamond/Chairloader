// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkmetatagdata.h
class ArkMetaTag : public ArkReflectedObject // Id=8016B00 Size=16
{
public:
	class ArknameProperty : public ArkProperty // Id=8016B01 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMetaTag::ArknameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetaTag::ArknameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMetaTag::ArknameProperty s_ArknameProperty;
	string m_name;
	
	class ArkidProperty : public ArkProperty // Id=8016B02 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMetaTag::ArkidProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107F050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetaTag::ArkidProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkMetaTag::ArkidProperty s_ArkidProperty;
	uint64_t m_id;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void Setname(string arg0);
	string const &Getname() const;
	void Setid(uint64_t arg0);
	const uint64_t &Getid() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1078480);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1078510);
};

// Header: Exact
// Prey/Ark/arkmetatagdata.h
class ArkMetaTags : public ArkReflectedLibrary // Id=8016B10 Size=32
{
public:
	class ArkMetaTagsProperty : public ArkProperty // Id=8016B11 Size=32
	{
	public:
		ArkMetaTagsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMetaTags::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1077E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMetaTags::ArkMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1077ED0);
		static inline auto FIsArray = PreyFunction<bool(ArkMetaTags::ArkMetaTagsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMetaTags::ArkMetaTagsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1077F10);
	};

	static ArkMetaTags::ArkMetaTagsProperty s_ArkMetaTagsProperty;
	std::vector<ArkMetaTag> m_MetaTags;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	uint64_t GetTagId(const char *const _pTagName) const { return FGetTagId(this,_pTagName); }
	virtual bool IsAlwaysLoaded() const;
	
#if 0
	std::vector<ArkMetaTag> &GetMetaTags();
	std::vector<ArkMetaTag> const &GetMetaTags() const;
	const char *GetTagName(uint64_t arg0) const;
	int GetTagCount() const;
	ArkMetaTag const &GetTag(int arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10784B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10785B0);
	static inline auto FInit = PreyFunction<bool(ArkMetaTags *const _this)>(0x10786F0);
	static inline auto FGetTagId = PreyFunction<uint64_t(ArkMetaTags const *const _this, const char *const _pTagName)>(0x10786A0);
	static inline auto FIsAlwaysLoaded = PreyFunction<bool(ArkMetaTags const *const _this)>(0x1B933B0);
};

