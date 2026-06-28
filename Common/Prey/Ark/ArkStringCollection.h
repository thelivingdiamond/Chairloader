// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkStringCollection
// Header:  Prey/Ark/ArkStringCollection.h
class ArkStringCollection : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkStringCollection::ArkIDProperty
	// Header:  Prey/Ark/ArkStringCollection.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStringCollection::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStringCollection::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkStringCollection::ArkNameProperty
	// Header:  Prey/Ark/ArkStringCollection.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStringCollection::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStringCollection::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkStringCollection::ArkStringsProperty
	// Header:  Prey/Ark/ArkStringCollection.h
	class ArkStringsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStringsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStringCollection::ArkStringsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AA1A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStringCollection::ArkStringsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AA200);
		static inline auto FIsArray = PreyFunction<bool(const ArkStringCollection::ArkStringsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkStringCollection::ArkStringsProperty* const _this, ArkReflectedObject* _pObject)>(0x10AA220);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkStringCollection::ArkIDProperty>(0x2D28530);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkStringCollection::ArkNameProperty>(0x2D28550);
	string m_Name;
	static inline auto s_ArkStringsProperty = PreyGlobal<ArkStringCollection::ArkStringsProperty>(0x2D28570);
	std::vector<string> m_Strings;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<string>& GetStrings();
	const std::vector<string>& GetStrings() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10972A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10AAC10);
};

// ArkStringCollectionLibrary
// Header:  Prey/Ark/ArkStringCollection.h
class ArkStringCollectionLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkStringCollectionLibrary::ArkCollectionsProperty
	// Header:  Prey/Ark/ArkStringCollection.h
	class ArkCollectionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkCollectionsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkCollectionsPropertyOv2 = PreyFunction<void(ArkStringCollectionLibrary::ArkCollectionsProperty* const _this)>(0x10AA860);
		static inline auto FSetValue = PreyFunction<void(const ArkStringCollectionLibrary::ArkCollectionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AA290);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStringCollectionLibrary::ArkCollectionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10AA320);
		static inline auto FIsArray = PreyFunction<bool(const ArkStringCollectionLibrary::ArkCollectionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkStringCollectionLibrary::ArkCollectionsProperty* const _this, ArkReflectedObject* _pObject)>(0x10AA360);
	};

	static inline auto s_ArkCollectionsProperty = PreyGlobal<ArkStringCollectionLibrary::ArkCollectionsProperty>(0x2D28590);
	std::vector<ArkStringCollection> m_Collections;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkStringCollection* Find(const uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkStringCollection>& GetCollections();
	const std::vector<ArkStringCollection>& GetCollections() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10AAB80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10AACB0);
	static inline auto FInit = PreyFunction<bool(ArkStringCollectionLibrary* const _this)>(0x10AADA0);
	static inline auto FFind = PreyFunction<const ArkStringCollection* (const ArkStringCollectionLibrary* const _this, const uint64_t _id)>(0x10AABE0);
};
#endif // MOONCRASH
