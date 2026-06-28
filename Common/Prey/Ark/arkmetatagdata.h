// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

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
	virtual ~ArkMetaTags();
	
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkMetaTag
// Header:  Prey/Ark/arkmetatagdata.h
class ArkMetaTag : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkMetaTag::ArknameProperty
	// Header:  Prey/Ark/arkmetatagdata.h
	class ArknameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArknameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkMetaTag::ArknameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMetaTag::ArknameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkMetaTag::ArkidProperty
	// Header:  Prey/Ark/arkmetatagdata.h
	class ArkidProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkidProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkMetaTag::ArkidProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMetaTag::ArkidProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArknameProperty = PreyGlobal<ArkMetaTag::ArknameProperty>(0x2D26970);
	string m_name;
	static inline auto s_ArkidProperty = PreyGlobal<ArkMetaTag::ArkidProperty>(0x2D26990);
	uint64_t m_id;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkMetaTag();
	void Setname(string _arg0_);
	const string& Getname() const;
	void Setid(uint64_t _arg0_);
	const uint64_t& Getid() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109E190);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109E220);
};

// ArkMetaTags
// Header:  Prey/Ark/arkmetatagdata.h
class ArkMetaTags : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkMetaTags::ArkMetaTagsProperty
	// Header:  Prey/Ark/arkmetatagdata.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkMetaTagsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkMetaTagsPropertyOv2 = PreyFunction<void(ArkMetaTags::ArkMetaTagsProperty* const _this)>(0x109DF60);
		static inline auto FSetValue = PreyFunction<void(const ArkMetaTags::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x109DB70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMetaTags::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x109DBE0);
		static inline auto FIsArray = PreyFunction<bool(const ArkMetaTags::ArkMetaTagsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkMetaTags::ArkMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x109DC20);
	};

	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkMetaTags::ArkMetaTagsProperty>(0x2D269B0);
	std::vector<ArkMetaTag> m_MetaTags;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	uint64_t GetTagId(const char* const _pTagName) const { return FGetTagId(this, _pTagName); }
	virtual bool IsAlwaysLoaded() const;

#if 0
	std::vector<ArkMetaTag>& GetMetaTags();
	const std::vector<ArkMetaTag>& GetMetaTags() const;
	const char* GetTagName(uint64_t _arg0_) const;
	int GetTagCount() const;
	const ArkMetaTag& GetTag(int _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109E1C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109E2C0);
	static inline auto FInit = PreyFunction<bool(ArkMetaTags* const _this)>(0x109E400);
	static inline auto FGetTagId = PreyFunction<uint64_t(const ArkMetaTags* const _this, const char* const _pTagName)>(0x109E3B0);
	static inline auto FIsAlwaysLoaded = PreyFunction<bool(const ArkMetaTags* const _this)>(0x1A302A0);
};
#endif // !MOONCRASH
