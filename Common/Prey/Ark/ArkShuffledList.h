// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkShuffledList
// Header:  Prey/Ark/ArkShuffledList.h
class ArkShuffledList : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkShuffledList::ArkIDProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkShuffledList::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledList::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkShuffledList::ArkNameProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkShuffledList::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledList::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkShuffledList::ArkMinValueProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkMinValueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinValueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkShuffledList::ArkMinValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledList::ArkMinValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkShuffledList::ArkMaxValueProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkMaxValueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxValueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkShuffledList::ArkMaxValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledList::ArkMaxValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkShuffledList::ArkStepSizeProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkStepSizeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStepSizeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkShuffledList::ArkStepSizeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledList::ArkStepSizeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkShuffledList::ArkIDProperty>(0x2D28210);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkShuffledList::ArkNameProperty>(0x2D28230);
	string m_Name;
	static inline auto s_ArkMinValueProperty = PreyGlobal<ArkShuffledList::ArkMinValueProperty>(0x2D28250);
	int m_MinValue;
	static inline auto s_ArkMaxValueProperty = PreyGlobal<ArkShuffledList::ArkMaxValueProperty>(0x2D28270);
	int m_MaxValue;
	static inline auto s_ArkStepSizeProperty = PreyGlobal<ArkShuffledList::ArkStepSizeProperty>(0x2D28290);
	int m_StepSize;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkShuffledList();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetMinValue(int _arg0_);
	const int& GetMinValue() const;
	void SetMaxValue(int _arg0_);
	const int& GetMaxValue() const;
	void SetStepSize(int _arg0_);
	const int& GetStepSize() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A8F80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A9050);
};

// ArkShuffledListLibrary
// Header:  Prey/Ark/ArkShuffledList.h
class ArkShuffledListLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkShuffledListLibrary::ArkShuffledListsProperty
	// Header:  Prey/Ark/ArkShuffledList.h
	class ArkShuffledListsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkShuffledListsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkShuffledListsPropertyOv2 = PreyFunction<void(ArkShuffledListLibrary::ArkShuffledListsProperty* const _this)>(0x10A8D50);
		static inline auto FSetValue = PreyFunction<void(const ArkShuffledListLibrary::ArkShuffledListsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A88D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkShuffledListLibrary::ArkShuffledListsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A8960);
		static inline auto FIsArray = PreyFunction<bool(const ArkShuffledListLibrary::ArkShuffledListsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkShuffledListLibrary::ArkShuffledListsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A89A0);
	};

	static inline auto s_ArkShuffledListsProperty = PreyGlobal<ArkShuffledListLibrary::ArkShuffledListsProperty>(0x2D282B0);
	std::vector<ArkShuffledList> m_ShuffledLists;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkShuffledList* Find(const uint64_t _id) const { return FFind(this, _id); }
	virtual bool Init();

#if 0
	std::vector<ArkShuffledList>& GetShuffledLists();
	const std::vector<ArkShuffledList>& GetShuffledLists() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A8FC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A90F0);
	static inline auto FFind = PreyFunction<const ArkShuffledList* (const ArkShuffledListLibrary* const _this, const uint64_t _id)>(0x10A9020);
	static inline auto FInit = PreyFunction<bool(ArkShuffledListLibrary* const _this)>(0x10A91E0);
};
#endif // MOONCRASH
