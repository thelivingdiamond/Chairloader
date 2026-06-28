// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkKeyCode.h
class ArkKeyCode : public ArkReflectedObject // Id=801CA14 Size=40
{
public:
	class ArkIDProperty : public ArkProperty // Id=801CA15 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCode::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCode::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkKeyCode::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801CA16 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCode::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCode::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkKeyCode::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=801CA17 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCode::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCode::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkKeyCode::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkCodeProperty : public ArkProperty // Id=801CA18 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCode::ArkCodeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCode::ArkCodeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkKeyCode::ArkCodeProperty s_ArkCodeProperty;
	string m_Code;
	
	class ArkLocationProperty : public ArkProperty // Id=801CA19 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCode::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCode::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkKeyCode::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetCode(string arg0);
	string const &GetCode() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15B6830);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15B68D0);
};

// Header: Exact
// Prey/Ark/arkkeycode.h
class ArkKeyCodes : public ArkReflectedLibrary // Id=801CA27 Size=32
{
public:
	class ArkKeyCodesProperty : public ArkProperty // Id=801CA28 Size=32
	{
	public:
		ArkKeyCodesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCodes::ArkKeyCodesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15B5F10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCodes::ArkKeyCodesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15B6000);
		static inline auto FIsArray = PreyFunction<bool(ArkKeyCodes::ArkKeyCodesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkKeyCodes::ArkKeyCodesProperty const *const _this, ArkReflectedObject *_pObject)>(0x15B6040);
	};

	static ArkKeyCodes::ArkKeyCodesProperty s_ArkKeyCodesProperty;
	std::vector<ArkKeyCode> m_KeyCodes;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkKeyCodes();
	
#if 0
	std::vector<ArkKeyCode> &GetKeyCodes();
	std::vector<ArkKeyCode> const &GetKeyCodes() const;
	ArkKeyCode const *FindKeyCode(const uint64_t arg0) const;
	ArkKeyCode const *FindKeyCode(string const &arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15B6870);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15B6970);
	static inline auto FInit = PreyFunction<bool(ArkKeyCodes *const _this)>(0x15B6A60);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkKeyCode
// Header:  Prey/Ark/ArkKeyCode.h
class ArkKeyCode : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkKeyCode::ArkIDProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCode::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCode::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkKeyCode::ArkNameProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCode::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCode::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkKeyCode::ArkLabelProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCode::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCode::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkKeyCode::ArkCodeProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkCodeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCodeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCode::ArkCodeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCode::ArkCodeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkKeyCode::ArkLocationProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCode::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCode::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkKeyCode::ArkIDProperty>(0x2D7F1C0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkKeyCode::ArkNameProperty>(0x2D7F1E0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkKeyCode::ArkLabelProperty>(0x2D7F200);
	string m_Label;
	static inline auto s_ArkCodeProperty = PreyGlobal<ArkKeyCode::ArkCodeProperty>(0x2D7F220);
	string m_Code;
	static inline auto s_ArkLocationProperty = PreyGlobal<ArkKeyCode::ArkLocationProperty>(0x2D7F240);
	uint64_t m_Location;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetCode(string _arg0_);
	const string& GetCode() const;
	void SetLocation(uint64_t _arg0_);
	const uint64_t& GetLocation() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16DBF60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16DC000);
};

// ArkKeyCodes
// Header:  Prey/Ark/ArkKeyCode.h
class ArkKeyCodes : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkKeyCodes::ArkKeyCodesProperty
	// Header:  Prey/Ark/ArkKeyCode.h
	class ArkKeyCodesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkKeyCodesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkKeyCodesPropertyOv2 = PreyFunction<void(ArkKeyCodes::ArkKeyCodesProperty* const _this)>(0x16DBC60);
		static inline auto FSetValue = PreyFunction<void(const ArkKeyCodes::ArkKeyCodesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16DB640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCodes::ArkKeyCodesProperty* const _this, ArkReflectedObject* const _pObject)>(0x16DB730);
		static inline auto FIsArray = PreyFunction<bool(const ArkKeyCodes::ArkKeyCodesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkKeyCodes::ArkKeyCodesProperty* const _this, ArkReflectedObject* _pObject)>(0x16DB770);
	};

	static inline auto s_ArkKeyCodesProperty = PreyGlobal<ArkKeyCodes::ArkKeyCodesProperty>(0x2D7F260);
	std::vector<ArkKeyCode> m_KeyCodes;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkKeyCode>& GetKeyCodes();
	const std::vector<ArkKeyCode>& GetKeyCodes() const;
	const ArkKeyCode* FindKeyCode(const uint64_t _arg0_) const;
	const ArkKeyCode* FindKeyCode(const string& _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16DBFA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x16DC0A0);
	static inline auto FInit = PreyFunction<bool(ArkKeyCodes* const _this)>(0x16DC190);
};
#endif // !MOONCRASH
