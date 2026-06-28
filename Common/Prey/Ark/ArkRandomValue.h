// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkRandomDoorState
// Header:  Prey/Ark/ArkRandomValue.h
class ArkRandomDoorState : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkRandomDoorState::ArkIDProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomDoorState::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomDoorState::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkRandomDoorState::ArkNameProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomDoorState::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomDoorState::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkRandomDoorState::ArkLinkIdProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkLinkIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLinkIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomDoorState::ArkLinkIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomDoorState::ArkLinkIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkRandomDoorState::ArkIDProperty>(0x2D27BD0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkRandomDoorState::ArkNameProperty>(0x2D27BF0);
	string m_Name;
	static inline auto s_ArkLinkIdProperty = PreyGlobal<ArkRandomDoorState::ArkLinkIdProperty>(0x2D27C10);
	uint64_t m_LinkId;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLinkId(uint64_t _arg0_);
	const uint64_t& GetLinkId() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x2B8C20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A50D0);
};

// ArkRandomDoorStates
// Header:  Prey/Ark/ArkRandomValue.h
class ArkRandomDoorStates : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkRandomDoorStates::ArkRandomDoorStatesProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkRandomDoorStatesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkRandomDoorStatesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomDoorStates::ArkRandomDoorStatesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A45D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomDoorStates::ArkRandomDoorStatesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A4650);
		static inline auto FIsArray = PreyFunction<bool(const ArkRandomDoorStates::ArkRandomDoorStatesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkRandomDoorStates::ArkRandomDoorStatesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A4750);
	};

	static inline auto s_ArkRandomDoorStatesProperty = PreyGlobal<ArkRandomDoorStates::ArkRandomDoorStatesProperty>(0x2D27C30);
	std::vector<ArkRandomDoorState> m_RandomDoorStates;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkRandomDoorState>& GetRandomDoorStates();
	const std::vector<ArkRandomDoorState>& GetRandomDoorStates() const;
	const ArkRandomDoorState* Find(const uint64_t _arg0_) const;
	const ArkRandomDoorState* Find(const char* _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A5010);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A5170);
	static inline auto FInit = PreyFunction<bool(ArkRandomDoorStates* const _this)>(0x10A5350);
};

// ArkRandomValue
// Header:  Prey/Ark/ArkRandomValue.h
class ArkRandomValue : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkRandomValue::ArkIDProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomValue::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomValue::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkRandomValue::ArkNameProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomValue::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomValue::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkRandomValue::ArkMinProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkMinProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomValue::ArkMinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomValue::ArkMinProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkRandomValue::ArkMaxProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkMaxProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomValue::ArkMaxProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomValue::ArkMaxProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkRandomValue::ArkIDProperty>(0x2D27B30);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkRandomValue::ArkNameProperty>(0x2D27B50);
	string m_Name;
	static inline auto s_ArkMinProperty = PreyGlobal<ArkRandomValue::ArkMinProperty>(0x2D27B70);
	int m_Min;
	static inline auto s_ArkMaxProperty = PreyGlobal<ArkRandomValue::ArkMaxProperty>(0x2D27B90);
	int m_Max;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetMin(int _arg0_);
	const int& GetMin() const;
	void SetMax(int _arg0_);
	const int& GetMax() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x2B8C20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A5210);
};

// ArkRandomValues
// Header:  Prey/Ark/ArkRandomValue.h
class ArkRandomValues : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkRandomValues::ArkRandomValuesProperty
	// Header:  Prey/Ark/ArkRandomValue.h
	class ArkRandomValuesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkRandomValuesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkRandomValues::ArkRandomValuesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A4690);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkRandomValues::ArkRandomValuesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A4710);
		static inline auto FIsArray = PreyFunction<bool(const ArkRandomValues::ArkRandomValuesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkRandomValues::ArkRandomValuesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A4750);
	};

	static inline auto s_ArkRandomValuesProperty = PreyGlobal<ArkRandomValues::ArkRandomValuesProperty>(0x2D27BB0);
	std::vector<ArkRandomValue> m_RandomValues;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkRandomValue>& GetRandomValues();
	const std::vector<ArkRandomValue>& GetRandomValues() const;
	const ArkRandomValue* Find(const uint64_t _arg0_) const;
	const ArkRandomValue* Find(const char* _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A5070);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A52B0);
	static inline auto FInit = PreyFunction<bool(ArkRandomValues* const _this)>(0x10A5520);
};
#endif // MOONCRASH
