// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkweaponmodifier.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkWeaponModifier.h
class ArkWeaponModifier : public ArkReflectedObject // Id=8015F94 Size=72
{
public:
	class ArkIDProperty : public ArkProperty // Id=8015F95 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkWeaponModifier::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8015F96 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkWeaponModifier::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8015F97 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkWeaponModifier::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkDefaultSummaryProperty : public ArkProperty // Id=8015F98 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkDefaultSummaryProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkDefaultSummaryProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkWeaponModifier::ArkDefaultSummaryProperty s_ArkDefaultSummaryProperty;
	string m_DefaultSummary;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8015F99 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkWeaponModifier::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkInstallWeaponProperty : public ArkProperty // Id=8015F9A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkInstallWeaponProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkInstallWeaponProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkWeaponModifier::ArkInstallWeaponProperty s_ArkInstallWeaponProperty;
	string m_InstallWeapon;
	
	class ArkWeaponModLevelsProperty : public ArkProperty // Id=8015F9B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifier::ArkWeaponModLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifier::ArkWeaponModLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1087070);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModifier::ArkWeaponModLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModifier::ArkWeaponModLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1087090);
	};

	static ArkWeaponModifier::ArkWeaponModLevelsProperty s_ArkWeaponModLevelsProperty;
	std::vector<ArkWeaponModLevel> m_WeaponModLevels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkWeaponModLevel const *GetLevelWeaponMod(const int _level) const { return FGetLevelWeaponMod(this,_level); }
	int GetNumberLevels() const { return FGetNumberLevels(this); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetDefaultSummary(string arg0);
	string const &GetDefaultSummary() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetInstallWeapon(string arg0);
	string const &GetInstallWeapon() const;
	std::vector<ArkWeaponModLevel> &GetWeaponModLevels();
	std::vector<ArkWeaponModLevel> const &GetWeaponModLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1088020);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1088170);
	static inline auto FGetLevelWeaponMod = PreyFunction<ArkWeaponModLevel const *(ArkWeaponModifier const *const _this, const int _level)>(0x1088300);
	static inline auto FGetNumberLevels = PreyFunction<int(ArkWeaponModifier const *const _this)>(0x1088330);
};

// Header: Exact
// Prey/Ark/arkweaponmodifier.h
class ArkWeaponModLevel : public ArkReflectedObject // Id=8015F9F Size=88
{
public:
	class ArkLevelProperty : public ArkProperty // Id=8015FA0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkLevelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10571E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkLevelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkWeaponModLevel::ArkLevelProperty s_ArkLevelProperty;
	uint8_t m_Level;
	
	class ArkSummaryProperty : public ArkProperty // Id=8015FA1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkSummaryProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkSummaryProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkWeaponModLevel::ArkSummaryProperty s_ArkSummaryProperty;
	string m_Summary;
	
	class ArkFanfareTextProperty : public ArkProperty // Id=8015FA2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkFanfareTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkFanfareTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkWeaponModLevel::ArkFanfareTextProperty s_ArkFanfareTextProperty;
	string m_FanfareText;
	
	class ArkTagStateProperty : public ArkProperty // Id=8015FA3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkTagStateProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkTagStateProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkWeaponModLevel::ArkTagStateProperty s_ArkTagStateProperty;
	string m_TagState;
	
	class ArkPrereqProperty : public ArkProperty // Id=8015FA4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkPrereqProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkPrereqProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkWeaponModLevel::ArkPrereqProperty s_ArkPrereqProperty;
	uint64_t m_Prereq;
	
	class ArkSignalModifiersProperty : public ArkProperty // Id=8015FA5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086EA0);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModLevel::ArkSignalModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModLevel::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1088B40);
	};

	static ArkWeaponModLevel::ArkSignalModifiersProperty s_ArkSignalModifiersProperty;
	std::vector<ArkSignalModifer> m_SignalModifiers;
	
	class ArkStatModifiersProperty : public ArkProperty // Id=8015FA6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkStatModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086EC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModLevel::ArkStatModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086F20);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModLevel::ArkStatModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModLevel::ArkStatModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1086F40);
	};

	static ArkWeaponModLevel::ArkStatModifiersProperty s_ArkStatModifiersProperty;
	std::vector<ArkStatModifier> m_StatModifiers;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetLevel(uint8_t arg0);
	const uint8_t &GetLevel() const;
	void SetSummary(string arg0);
	string const &GetSummary() const;
	void SetFanfareText(string arg0);
	string const &GetFanfareText() const;
	void SetTagState(string arg0);
	string const &GetTagState() const;
	void SetPrereq(uint64_t arg0);
	const uint64_t &GetPrereq() const;
	std::vector<ArkSignalModifer> &GetSignalModifiers();
	std::vector<ArkSignalModifer> const &GetSignalModifiers() const;
	std::vector<ArkStatModifier> &GetStatModifiers();
	std::vector<ArkStatModifier> const &GetStatModifiers() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1087FC0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10880D0);
};

// Header: Exact
// Prey/Ark/arkweaponmodifier.h
class ArkWeaponModifiers : public ArkReflectedLibrary // Id=8016CD4 Size=32
{
public:
	class ArkWeaponModifiersProperty : public ArkProperty // Id=8016CD5 Size=32
	{
	public:
		ArkWeaponModifiersProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkWeaponModifiers::ArkWeaponModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086CE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkWeaponModifiers::ArkWeaponModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086DB0);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModifiers::ArkWeaponModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModifiers::ArkWeaponModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1086DF0);
	};

	static ArkWeaponModifiers::ArkWeaponModifiersProperty s_ArkWeaponModifiersProperty;
	std::vector<ArkWeaponModifier> m_WeaponModifiers;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkWeaponModifier const *GetWeaponModByID(uint64_t _modID) const { return FGetWeaponModByIDOv1(this,_modID); }
	virtual bool Init();
	
#if 0
	std::vector<ArkWeaponModifier> &GetWeaponModifiers();
	std::vector<ArkWeaponModifier> const &GetWeaponModifiers() const;
	ArkWeaponModifier *GetWeaponModByID(uint64_t arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1088070);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1088210);
	static inline auto FGetWeaponModByIDOv1 = PreyFunction<ArkWeaponModifier const *(ArkWeaponModifiers const *const _this, uint64_t _modID)>(0x1088360);
	static inline auto FInit = PreyFunction<bool(ArkWeaponModifiers *const _this)>(0x1088390);
};

