// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkEscapeMethod
// Header:  Prey/Ark/ArkEscapeMethod.h
class ArkEscapeMethod : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkEscapeMethod::ArkIDProperty
	// Header:  Prey/Ark/ArkEscapeMethod.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEscapeMethod::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEscapeMethod::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkEscapeMethod::ArkNameProperty
	// Header:  Prey/Ark/ArkEscapeMethod.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEscapeMethod::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEscapeMethod::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkEscapeMethod::ArkLabelProperty
	// Header:  Prey/Ark/ArkEscapeMethod.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEscapeMethod::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEscapeMethod::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkEscapeMethod::ArkIDProperty>(0x2D238A0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEscapeMethod::ArkNameProperty>(0x2D238C0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkEscapeMethod::ArkLabelProperty>(0x2D238E0);
	string m_Label;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107E6A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1088490);
};

// ArkEscapeMethodLibrary
// Header:  Prey/Ark/ArkEscapeMethod.h
class ArkEscapeMethodLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkEscapeMethodLibrary::ArkMethodsProperty
	// Header:  Prey/Ark/ArkEscapeMethod.h
	class ArkMethodsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkMethodsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkMethodsPropertyOv2 = PreyFunction<void(ArkEscapeMethodLibrary::ArkMethodsProperty* const _this)>(0x1088180);
		static inline auto FSetValue = PreyFunction<void(const ArkEscapeMethodLibrary::ArkMethodsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1087D20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEscapeMethodLibrary::ArkMethodsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1087DC0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEscapeMethodLibrary::ArkMethodsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEscapeMethodLibrary::ArkMethodsProperty* const _this, ArkReflectedObject* _pObject)>(0x107D820);
	};

	static inline auto s_ArkMethodsProperty = PreyGlobal<ArkEscapeMethodLibrary::ArkMethodsProperty>(0x2D23900);
	std::vector<ArkEscapeMethod> m_Methods;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkEscapeMethod* Find(const uint64_t _id) const { return FFind(this, _id); }
	const ArkEscapeMethod* FindByName(const char* _name) const { return FFindByName(this, _name); }

#if 0
	std::vector<ArkEscapeMethod>& GetMethods();
	const std::vector<ArkEscapeMethod>& GetMethods() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10883B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1088530);
	static inline auto FInit = PreyFunction<bool(ArkEscapeMethodLibrary* const _this)>(0x1088620);
	static inline auto FFind = PreyFunction<const ArkEscapeMethod* (const ArkEscapeMethodLibrary* const _this, const uint64_t _id)>(0x1088410);
	static inline auto FFindByName = PreyFunction<const ArkEscapeMethod* (const ArkEscapeMethodLibrary* const _this, const char* _name)>(0x1088440);
};
#endif // MOONCRASH
