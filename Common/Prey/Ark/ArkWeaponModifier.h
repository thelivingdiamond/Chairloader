// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkweaponmodifier.h
class ArkWeaponModLevel : public ArkReflectedObject // Id=8015F9F Size=88
{
public:
	class ArkLevelProperty : public ArkProperty // Id=8015FA0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkLevelProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10571E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkLevelProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkWeaponModLevel::ArkLevelProperty s_ArkLevelProperty;
	uint8_t m_Level;

	class ArkSummaryProperty : public ArkProperty // Id=8015FA1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkSummaryProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkSummaryProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static ArkWeaponModLevel::ArkSummaryProperty s_ArkSummaryProperty;
	string m_Summary;

	class ArkFanfareTextProperty : public ArkProperty // Id=8015FA2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkFanfareTextProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkFanfareTextProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	static ArkWeaponModLevel::ArkFanfareTextProperty s_ArkFanfareTextProperty;
	string m_FanfareText;

	class ArkTagStateProperty : public ArkProperty // Id=8015FA3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkTagStateProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkTagStateProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	static ArkWeaponModLevel::ArkTagStateProperty s_ArkTagStateProperty;
	string m_TagState;

	class ArkPrereqProperty : public ArkProperty // Id=8015FA4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkPrereqProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkPrereqProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static ArkWeaponModLevel::ArkPrereqProperty s_ArkPrereqProperty;
	uint64_t m_Prereq;

	class ArkSignalModifiersProperty : public ArkProperty // Id=8015FA5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1086E70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1086EA0);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModLevel::ArkSignalModifiersProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModLevel::ArkSignalModifiersProperty const* const _this, ArkReflectedObject* _pObject)>(0x1088B40);
	};

	static ArkWeaponModLevel::ArkSignalModifiersProperty s_ArkSignalModifiersProperty;
	std::vector<ArkSignalModifer> m_SignalModifiers;

	class ArkStatModifiersProperty : public ArkProperty // Id=8015FA6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkWeaponModLevel::ArkStatModifiersProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1086EC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkWeaponModLevel::ArkStatModifiersProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1086F20);
		static inline auto FIsArray = PreyFunction<bool(ArkWeaponModLevel::ArkStatModifiersProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkWeaponModLevel::ArkStatModifiersProperty const* const _this, ArkReflectedObject* _pObject)>(0x1086F40);
	};

	static ArkWeaponModLevel::ArkStatModifiersProperty s_ArkStatModifiersProperty;
	std::vector<ArkStatModifier> m_StatModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetLevel(uint8_t arg0);
	const uint8_t& GetLevel() const;
	void SetSummary(string arg0);
	string const& GetSummary() const;
	void SetFanfareText(string arg0);
	string const& GetFanfareText() const;
	void SetTagState(string arg0);
	string const& GetTagState() const;
	void SetPrereq(uint64_t arg0);
	const uint64_t& GetPrereq() const;
	std::vector<ArkSignalModifer>& GetSignalModifiers();
	std::vector<ArkSignalModifer> const& GetSignalModifiers() const;
	std::vector<ArkStatModifier>& GetStatModifiers();
	std::vector<ArkStatModifier> const& GetStatModifiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1087FC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10880D0);
};

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
	virtual ~ArkWeaponModifiers();
	
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAbility.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class ArkClass;
class IArkValueBase;

// ArkWeaponEnchantmentAdditionalArt
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponEnchantmentAdditionalArt : public ArkReflectedObject
{ // Size=64 (0x40)
public:
	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentPointNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentPointNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameAddProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentPointNameAddProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentPointNameAddProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameAddProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameAddProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectAddProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentEffectAddProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentEffectAddProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectAddProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectAddProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkVFXLibraryNameProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkVFXLibraryNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVFXLibraryNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkVFXLibraryNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkVFXLibraryNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkVFXEffectNameProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkVFXEffectNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVFXEffectNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkVFXEffectNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkVFXEffectNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentModelProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkWeaponEnchantmentAdditionalArt::ArkAttachmentAnimProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAttachmentAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttachmentAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentAdditionalArt::ArkAttachmentAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	static inline auto s_ArkAttachmentPointNameProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameProperty>(0x2D298B0);
	string m_AttachmentPointName;
	static inline auto s_ArkAttachmentPointNameAddProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentPointNameAddProperty>(0x2D298D0);
	string m_AttachmentPointNameAdd;
	static inline auto s_ArkAttachmentEffectProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectProperty>(0x2D298F0);
	string m_AttachmentEffect;
	static inline auto s_ArkAttachmentEffectAddProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentEffectAddProperty>(0x2D29910);
	string m_AttachmentEffectAdd;
	static inline auto s_ArkVFXLibraryNameProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkVFXLibraryNameProperty>(0x2D29930);
	string m_VFXLibraryName;
	static inline auto s_ArkVFXEffectNameProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkVFXEffectNameProperty>(0x2D29950);
	string m_VFXEffectName;
	static inline auto s_ArkAttachmentModelProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentModelProperty>(0x2D29970);
	string m_AttachmentModel;
	static inline auto s_ArkAttachmentAnimProperty = PreyGlobal<ArkWeaponEnchantmentAdditionalArt::ArkAttachmentAnimProperty>(0x2D29990);
	string m_AttachmentAnim;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetAttachmentPointName(string _arg0_);
	const string& GetAttachmentPointName() const;
	void SetAttachmentPointNameAdd(string _arg0_);
	const string& GetAttachmentPointNameAdd() const;
	void SetAttachmentEffect(string _arg0_);
	const string& GetAttachmentEffect() const;
	void SetAttachmentEffectAdd(string _arg0_);
	const string& GetAttachmentEffectAdd() const;
	void SetVFXLibraryName(string _arg0_);
	const string& GetVFXLibraryName() const;
	void SetVFXEffectName(string _arg0_);
	const string& GetVFXEffectName() const;
	void SetAttachmentModel(string _arg0_);
	const string& GetAttachmentModel() const;
	void SetAttachmentAnim(string _arg0_);
	const string& GetAttachmentAnim() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B58D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B5D90);
};

// ArkWeaponEnchantmentReplacementArt
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponEnchantmentReplacementArt : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkWeaponEnchantmentReplacementArt::ArkTracerEffectProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkTracerEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTracerEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentReplacementArt::ArkTracerEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentReplacementArt::ArkTracerEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponEnchantmentReplacementArt::ArkPickupModel3PProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkPickupModel3PProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPickupModel3PProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentReplacementArt::ArkPickupModel3PProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentReplacementArt::ArkPickupModel3PProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkTracerEffectProperty = PreyGlobal<ArkWeaponEnchantmentReplacementArt::ArkTracerEffectProperty>(0x2D29870);
	string m_TracerEffect;
	static inline auto s_ArkPickupModel3PProperty = PreyGlobal<ArkWeaponEnchantmentReplacementArt::ArkPickupModel3PProperty>(0x2D29890);
	string m_PickupModel3P;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetTracerEffect(string _arg0_);
	const string& GetTracerEffect() const;
	void SetPickupModel3P(string _arg0_);
	const string& GetPickupModel3P() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10929D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B5ED0);
};

// ArkWeaponEnchantmentInfo
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponEnchantmentInfo : public ArkReflectedObject
{ // Size=192 (0xC0)
public:
	// ArkWeaponEnchantmentInfo::ArkInstallWeaponProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkInstallWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInstallWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponEnchantmentInfo::ArkTagStateProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkTagStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTagStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponEnchantmentInfo::ArkReplacementArtProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkReplacementArtProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReplacementArtProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkReplacementArtProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkReplacementArtProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponEnchantmentInfo::ArkAdditionalArtProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAdditionalArtProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAdditionalArtProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkAdditionalArtProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2B90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkAdditionalArtProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponEnchantmentInfo::ArkProjectileOverrideProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkProjectileOverrideProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkProjectileOverrideProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkProjectileOverrideProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkProjectileOverrideProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkWeaponEnchantmentInfo::ArkAOERadiusProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAOERadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAOERadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkAOERadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089F60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkAOERadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkWeaponEnchantmentInfo::ArkAOESignalPackageProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkAOESignalPackageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAOESignalPackageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkAOESignalPackageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkAOESignalPackageProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2CE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2D10);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2D40);
	};

	// ArkWeaponEnchantmentInfo::ArkStatModifiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkStatModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStatModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2DD0);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponEnchantmentInfo::ArkStatModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkStatModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2E00);
	};

	// ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkSignalPackageIdsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalPackageIdsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2E40);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2E70);
	};

	static inline auto s_ArkInstallWeaponProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkInstallWeaponProperty>(0x2D299B0);
	string m_InstallWeapon;
	static inline auto s_ArkTagStateProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkTagStateProperty>(0x2D299D0);
	string m_TagState;
	static inline auto s_ArkReplacementArtProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkReplacementArtProperty>(0x2D299F0);
	ArkWeaponEnchantmentReplacementArt m_ReplacementArt;
	static inline auto s_ArkAdditionalArtProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkAdditionalArtProperty>(0x2D29A10);
	ArkWeaponEnchantmentAdditionalArt m_AdditionalArt;
	static inline auto s_ArkProjectileOverrideProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkProjectileOverrideProperty>(0x2D29A30);
	string m_ProjectileOverride;
	static inline auto s_ArkAOERadiusProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkAOERadiusProperty>(0x2D29A50);
	float m_AOERadius;
	static inline auto s_ArkAOESignalPackageProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkAOESignalPackageProperty>(0x2D29A70);
	uint64_t m_AOESignalPackage;
	static inline auto s_ArkSignalModifiersProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkSignalModifiersProperty>(0x2D29A90);
	std::vector<ArkSignalModifer> m_SignalModifiers;
	static inline auto s_ArkStatModifiersProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkStatModifiersProperty>(0x2D29AB0);
	std::vector<ArkStatModifier> m_StatModifiers;
	static inline auto s_ArkSignalPackageIdsProperty = PreyGlobal<ArkWeaponEnchantmentInfo::ArkSignalPackageIdsProperty>(0x2D29AD0);
	std::vector<uint64_t> m_SignalPackageIds;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetInstallWeapon(string _arg0_);
	const string& GetInstallWeapon() const;
	void SetTagState(string _arg0_);
	const string& GetTagState() const;
	void SetReplacementArt(ArkWeaponEnchantmentReplacementArt _arg0_);
	const ArkWeaponEnchantmentReplacementArt& GetReplacementArt() const;
	void SetAdditionalArt(ArkWeaponEnchantmentAdditionalArt _arg0_);
	const ArkWeaponEnchantmentAdditionalArt& GetAdditionalArt() const;
	void SetProjectileOverride(string _arg0_);
	const string& GetProjectileOverride() const;
	void SetAOERadius(float _arg0_);
	const float& GetAOERadius() const;
	void SetAOESignalPackage(uint64_t _arg0_);
	const uint64_t& GetAOESignalPackage() const;
	std::vector<ArkSignalModifer>& GetSignalModifiers();
	const std::vector<ArkSignalModifer>& GetSignalModifiers() const;
	std::vector<ArkStatModifier>& GetStatModifiers();
	const std::vector<ArkStatModifier>& GetStatModifiers() const;
	std::vector<uint64_t>& GetSignalPackageIds();
	const std::vector<uint64_t>& GetSignalPackageIds() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5920);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B5E30);
};

// ArkWeaponEnchantment
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponEnchantment : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkWeaponEnchantment::ArkIDProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponEnchantment::ArkNameProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponEnchantment::ArkLabelProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponEnchantment::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWeaponEnchantment::ArkIconNameSmallProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkIconNameSmallProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconNameSmallProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkIconNameSmallProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkIconNameSmallProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponEnchantment::ArkIconNameLargeProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkIconNameLargeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconNameLargeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkIconNameLargeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkIconNameLargeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkWeaponEnchantment::ArkKeywordProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkKeywordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKeywordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkKeywordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkKeywordProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkWeaponEnchantment::ArkKeywordSignalIDProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkKeywordSignalIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKeywordSignalIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkKeywordSignalIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkKeywordSignalIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkWeaponEnchantment::ArkWeaponsAllowedProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkWeaponsAllowedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponsAllowedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantment::ArkWeaponsAllowedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B31E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantment::ArkWeaponsAllowedProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B3220);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponEnchantment::ArkWeaponsAllowedProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponEnchantment::ArkWeaponsAllowedProperty* const _this, ArkReflectedObject* _pObject)>(0x10B3250);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkWeaponEnchantment::ArkIDProperty>(0x2D29AF0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkWeaponEnchantment::ArkNameProperty>(0x2D29B10);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkWeaponEnchantment::ArkLabelProperty>(0x2D29B30);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkWeaponEnchantment::ArkDescriptionProperty>(0x2D29B50);
	string m_Description;
	static inline auto s_ArkIconNameSmallProperty = PreyGlobal<ArkWeaponEnchantment::ArkIconNameSmallProperty>(0x2D29B70);
	string m_IconNameSmall;
	static inline auto s_ArkIconNameLargeProperty = PreyGlobal<ArkWeaponEnchantment::ArkIconNameLargeProperty>(0x2D29B90);
	string m_IconNameLarge;
	static inline auto s_ArkKeywordProperty = PreyGlobal<ArkWeaponEnchantment::ArkKeywordProperty>(0x2D29BB0);
	string m_Keyword;
	static inline auto s_ArkKeywordSignalIDProperty = PreyGlobal<ArkWeaponEnchantment::ArkKeywordSignalIDProperty>(0x2D29BD0);
	uint64_t m_KeywordSignalID;
	static inline auto s_ArkWeaponsAllowedProperty = PreyGlobal<ArkWeaponEnchantment::ArkWeaponsAllowedProperty>(0x2D29BF0);
	std::vector<ArkWeaponEnchantmentInfo> m_WeaponsAllowed;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetIconNameSmall(string _arg0_);
	const string& GetIconNameSmall() const;
	void SetIconNameLarge(string _arg0_);
	const string& GetIconNameLarge() const;
	void SetKeyword(string _arg0_);
	const string& GetKeyword() const;
	void SetKeywordSignalID(uint64_t _arg0_);
	const uint64_t& GetKeywordSignalID() const;
	std::vector<ArkWeaponEnchantmentInfo>& GetWeaponsAllowed();
	const std::vector<ArkWeaponEnchantmentInfo>& GetWeaponsAllowed() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5860);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B5CF0);
};

// ArkWeaponEnchantments
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponEnchantments : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkWeaponEnchantmentsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponEnchantmentsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B27F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2840);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2880);
	};

	static inline auto s_ArkWeaponEnchantmentsProperty = PreyGlobal<ArkWeaponEnchantments::ArkWeaponEnchantmentsProperty>(0x2D29C10);
	std::vector<ArkWeaponEnchantment> m_WeaponEnchantments;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkWeaponEnchantmentInfo* GetWeaponInfoByID(const uint64_t _enchantID, const string& _installWeapon) const { return FGetWeaponInfoByID(this, _enchantID, _installWeapon); }
	const ArkWeaponEnchantment* GetWeaponEnchantmentByID(uint64_t _enchantID) const { return FGetWeaponEnchantmentByIDOv1(this, _enchantID); }
	std::vector<const ArkWeaponEnchantment*> GetWeaponEnchantmentsByInstallWeapon(const string& _installWeaponName) const { alignas(std::vector<const ArkWeaponEnchantment*>) std::byte _return_buf_[sizeof(std::vector<const ArkWeaponEnchantment*>)]; return *FGetWeaponEnchantmentsByInstallWeapon(this, reinterpret_cast<std::vector<const ArkWeaponEnchantment*>*>(_return_buf_), _installWeaponName); }

#if 0
	std::vector<ArkWeaponEnchantment>& GetWeaponEnchantments();
	const std::vector<ArkWeaponEnchantment>& GetWeaponEnchantments() const;
	ArkWeaponEnchantment* GetWeaponEnchantmentByID(uint64_t _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B59E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B5F70);
	static inline auto FInit = PreyFunction<bool(ArkWeaponEnchantments* const _this)>(0x10B67B0);
	static inline auto FGetWeaponInfoByID = PreyFunction<const ArkWeaponEnchantmentInfo* (const ArkWeaponEnchantments* const _this, const uint64_t _enchantID, const string& _installWeapon)>(0x10B6670);
	static inline auto FGetWeaponEnchantmentByIDOv1 = PreyFunction<const ArkWeaponEnchantment* (const ArkWeaponEnchantments* const _this, uint64_t _enchantID)>(0x109D3E0);
	static inline auto FGetWeaponEnchantmentsByInstallWeapon = PreyFunction<std::vector<const ArkWeaponEnchantment*>*(const ArkWeaponEnchantments* const _this, std::vector<const ArkWeaponEnchantment*>* _return_value_, const string& _installWeaponName)>(0x10B65B0);
};

// ArkWeaponModLevel
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponModLevel : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkWeaponModLevel::ArkLevelProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkLevelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLevelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2A90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkLevelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponModLevel::ArkSummaryProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkSummaryProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummaryProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkSummaryProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkSummaryProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponModLevel::ArkFanfareTextProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkFanfareTextProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFanfareTextProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkFanfareTextProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkFanfareTextProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponModLevel::ArkTagStateProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkTagStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTagStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkTagStateProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWeaponModLevel::ArkPrereqProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkPrereqProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPrereqProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkPrereqProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkPrereqProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponModLevel::ArkSignalModifiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkSignalModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSignalModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2730);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponModLevel::ArkSignalModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponModLevel::ArkSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2750);
	};

	// ArkWeaponModLevel::ArkStatModifiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkStatModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStatModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModLevel::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2760);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModLevel::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B27C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponModLevel::ArkStatModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponModLevel::ArkStatModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B27E0);
	};

	static inline auto s_ArkLevelProperty = PreyGlobal<ArkWeaponModLevel::ArkLevelProperty>(0x2D29690);
	uint8_t m_Level;
	static inline auto s_ArkSummaryProperty = PreyGlobal<ArkWeaponModLevel::ArkSummaryProperty>(0x2D296B0);
	string m_Summary;
	static inline auto s_ArkFanfareTextProperty = PreyGlobal<ArkWeaponModLevel::ArkFanfareTextProperty>(0x2D296D0);
	string m_FanfareText;
	static inline auto s_ArkTagStateProperty = PreyGlobal<ArkWeaponModLevel::ArkTagStateProperty>(0x2D296F0);
	string m_TagState;
	static inline auto s_ArkPrereqProperty = PreyGlobal<ArkWeaponModLevel::ArkPrereqProperty>(0x2D29710);
	uint64_t m_Prereq;
	static inline auto s_ArkSignalModifiersProperty = PreyGlobal<ArkWeaponModLevel::ArkSignalModifiersProperty>(0x2D29730);
	std::vector<ArkSignalModifer> m_SignalModifiers;
	static inline auto s_ArkStatModifiersProperty = PreyGlobal<ArkWeaponModLevel::ArkStatModifiersProperty>(0x2D29750);
	std::vector<ArkStatModifier> m_StatModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWeaponModLevel();
	void SetLevel(uint8_t _arg0_);
	const uint8_t& GetLevel() const;
	void SetSummary(string _arg0_);
	const string& GetSummary() const;
	void SetFanfareText(string _arg0_);
	const string& GetFanfareText() const;
	void SetTagState(string _arg0_);
	const string& GetTagState() const;
	void SetPrereq(uint64_t _arg0_);
	const uint64_t& GetPrereq() const;
	std::vector<ArkSignalModifer>& GetSignalModifiers();
	const std::vector<ArkSignalModifer>& GetSignalModifiers() const;
	std::vector<ArkStatModifier>& GetStatModifiers();
	const std::vector<ArkStatModifier>& GetStatModifiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5A40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B6010);
};

// ArkWeaponModifier
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponModifier : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkWeaponModifier::ArkIDProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponModifier::ArkNameProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponModifier::ArkLabelProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponModifier::ArkDefaultSummaryProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkDefaultSummaryProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultSummaryProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkDefaultSummaryProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkDefaultSummaryProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWeaponModifier::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponModifier::ArkInstallWeaponProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkInstallWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInstallWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkWeaponModifier::ArkWeaponModLevelsProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkWeaponModLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponModLevelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifier::ArkWeaponModLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B28F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifier::ArkWeaponModLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2A10);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponModifier::ArkWeaponModLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponModifier::ArkWeaponModLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2A30);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkWeaponModifier::ArkIDProperty>(0x2D29770);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkWeaponModifier::ArkNameProperty>(0x2D29790);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkWeaponModifier::ArkLabelProperty>(0x2D297B0);
	string m_Label;
	static inline auto s_ArkDefaultSummaryProperty = PreyGlobal<ArkWeaponModifier::ArkDefaultSummaryProperty>(0x2D297D0);
	string m_DefaultSummary;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkWeaponModifier::ArkDescriptionProperty>(0x2D297F0);
	string m_Description;
	static inline auto s_ArkInstallWeaponProperty = PreyGlobal<ArkWeaponModifier::ArkInstallWeaponProperty>(0x2D29810);
	string m_InstallWeapon;
	static inline auto s_ArkWeaponModLevelsProperty = PreyGlobal<ArkWeaponModifier::ArkWeaponModLevelsProperty>(0x2D29830);
	std::vector<ArkWeaponModLevel> m_WeaponModLevels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkWeaponModLevel* GetLevelWeaponMod(const int _level) const { return FGetLevelWeaponMod(this, _level); }
	int GetNumberLevels() const { return FGetNumberLevels(this); }

#if 0
	ArkWeaponModifier();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDefaultSummary(string _arg0_);
	const string& GetDefaultSummary() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetInstallWeapon(string _arg0_);
	const string& GetInstallWeapon() const;
	std::vector<ArkWeaponModLevel>& GetWeaponModLevels();
	const std::vector<ArkWeaponModLevel>& GetWeaponModLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5AA0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B60B0);
	static inline auto FGetLevelWeaponMod = PreyFunction<const ArkWeaponModLevel* (const ArkWeaponModifier* const _this, const int _level)>(0x10B63D0);
	static inline auto FGetNumberLevels = PreyFunction<int(const ArkWeaponModifier* const _this)>(0x10B6580);
};

// ArkWeaponModifiers
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponModifiers : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkWeaponModifiers::ArkWeaponModifiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkWeaponModifiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponModifiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponModifiers::ArkWeaponModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponModifiers::ArkWeaponModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B3130);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponModifiers::ArkWeaponModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponModifiers::ArkWeaponModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B3170);
	};

	static inline auto s_ArkWeaponModifiersProperty = PreyGlobal<ArkWeaponModifiers::ArkWeaponModifiersProperty>(0x2D29850);
	std::vector<ArkWeaponModifier> m_WeaponModifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkWeaponModifier* GetWeaponModByID(uint64_t _modID) const { return FGetWeaponModByIDOv1(this, _modID); }
	std::vector<const ArkWeaponModifier*> GetWeaponModsByInstallWeapon(const string& _installWeaponName) const { alignas(std::vector<const ArkWeaponModifier*>) std::byte _return_buf_[sizeof(std::vector<const ArkWeaponModifier*>)]; return *FGetWeaponModsByInstallWeapon(this, reinterpret_cast<std::vector<const ArkWeaponModifier*>*>(_return_buf_), _installWeaponName); }
	virtual bool Init();

#if 0
	std::vector<ArkWeaponModifier>& GetWeaponModifiers();
	const std::vector<ArkWeaponModifier>& GetWeaponModifiers() const;
	ArkWeaponModifier* GetWeaponModByID(uint64_t _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5AF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B6150);
	static inline auto FGetWeaponModByIDOv1 = PreyFunction<const ArkWeaponModifier* (const ArkWeaponModifiers* const _this, uint64_t _modID)>(0x12C9620);
	static inline auto FGetWeaponModsByInstallWeapon = PreyFunction<std::vector<const ArkWeaponModifier*>*(const ArkWeaponModifiers* const _this, std::vector<const ArkWeaponModifier*>* _return_value_, const string& _installWeaponName)>(0x10B6710);
	static inline auto FInit = PreyFunction<bool(ArkWeaponModifiers* const _this)>(0x10B6A50);
};

// ArkWeaponQualityTierInfo
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponQualityTierInfo : public ArkReflectedObject
{ // Size=3 (0x3)
public:
	// ArkWeaponQualityTierInfo::ArkNumModsToInstallProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkNumModsToInstallProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNumModsToInstallProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTierInfo::ArkNumModsToInstallProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2A90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTierInfo::ArkNumModsToInstallProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponQualityTierInfo::ArkMaxModsPerStatProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkMaxModsPerStatProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxModsPerStatProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTierInfo::ArkMaxModsPerStatProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTierInfo::ArkMaxModsPerStatProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2AB0);
	};

	// ArkWeaponQualityTierInfo::ArkChanceForEnchantmentProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkChanceForEnchantmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkChanceForEnchantmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTierInfo::ArkChanceForEnchantmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2AC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTierInfo::ArkChanceForEnchantmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2AD0);
	};

	static inline auto s_ArkNumModsToInstallProperty = PreyGlobal<ArkWeaponQualityTierInfo::ArkNumModsToInstallProperty>(0x2D29550);
	uint8_t m_NumModsToInstall;
	static inline auto s_ArkMaxModsPerStatProperty = PreyGlobal<ArkWeaponQualityTierInfo::ArkMaxModsPerStatProperty>(0x2D29570);
	uint8_t m_MaxModsPerStat;
	static inline auto s_ArkChanceForEnchantmentProperty = PreyGlobal<ArkWeaponQualityTierInfo::ArkChanceForEnchantmentProperty>(0x2D29590);
	uint8_t m_ChanceForEnchantment;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWeaponQualityTierInfo();
	void SetNumModsToInstall(uint8_t _arg0_);
	const uint8_t& GetNumModsToInstall() const;
	void SetMaxModsPerStat(uint8_t _arg0_);
	const uint8_t& GetMaxModsPerStat() const;
	void SetChanceForEnchantment(uint8_t _arg0_);
	const uint8_t& GetChanceForEnchantment() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5C00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B6330);
};

// ArkWeaponQualityTier
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponQualityTier : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkWeaponQualityTier::ArkInstallWeaponProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkInstallWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInstallWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkInstallWeaponProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponQualityTier::ArkDefaultTierProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkDefaultTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDefaultTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkDefaultTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2C30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkDefaultTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponQualityTier::ArkCommonTierProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkCommonTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkCommonTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2C50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkCommonTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2C70);
	};

	// ArkWeaponQualityTier::ArkRareTierProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkRareTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRareTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkRareTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkRareTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2CA0);
	};

	// ArkWeaponQualityTier::ArkLegendaryTierProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkLegendaryTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLegendaryTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkLegendaryTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkLegendaryTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x14437E0);
	};

	// ArkWeaponQualityTier::ArkSpecialTierProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkSpecialTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpecialTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQualityTier::ArkSpecialTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2D50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQualityTier::ArkSpecialTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	static inline auto s_ArkInstallWeaponProperty = PreyGlobal<ArkWeaponQualityTier::ArkInstallWeaponProperty>(0x2D295B0);
	string m_InstallWeapon;
	static inline auto s_ArkDefaultTierProperty = PreyGlobal<ArkWeaponQualityTier::ArkDefaultTierProperty>(0x2D295D0);
	ArkWeaponQualityTierInfo m_DefaultTier;
	static inline auto s_ArkCommonTierProperty = PreyGlobal<ArkWeaponQualityTier::ArkCommonTierProperty>(0x2D295F0);
	ArkWeaponQualityTierInfo m_CommonTier;
	static inline auto s_ArkRareTierProperty = PreyGlobal<ArkWeaponQualityTier::ArkRareTierProperty>(0x2D29610);
	ArkWeaponQualityTierInfo m_RareTier;
	static inline auto s_ArkLegendaryTierProperty = PreyGlobal<ArkWeaponQualityTier::ArkLegendaryTierProperty>(0x2D29630);
	ArkWeaponQualityTierInfo m_LegendaryTier;
	static inline auto s_ArkSpecialTierProperty = PreyGlobal<ArkWeaponQualityTier::ArkSpecialTierProperty>(0x2D29650);
	ArkWeaponQualityTierInfo m_SpecialTier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWeaponQualityTier();
	void SetInstallWeapon(string _arg0_);
	const string& GetInstallWeapon() const;
	void SetDefaultTier(ArkWeaponQualityTierInfo _arg0_);
	const ArkWeaponQualityTierInfo& GetDefaultTier() const;
	void SetCommonTier(ArkWeaponQualityTierInfo _arg0_);
	const ArkWeaponQualityTierInfo& GetCommonTier() const;
	void SetRareTier(ArkWeaponQualityTierInfo _arg0_);
	const ArkWeaponQualityTierInfo& GetRareTier() const;
	void SetLegendaryTier(ArkWeaponQualityTierInfo _arg0_);
	const ArkWeaponQualityTierInfo& GetLegendaryTier() const;
	void SetSpecialTier(ArkWeaponQualityTierInfo _arg0_);
	const ArkWeaponQualityTierInfo& GetSpecialTier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5BB0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B6290);
};

// ArkWeaponQuality
// Header:  Prey/Ark/ArkWeaponModifier.h
class ArkWeaponQuality : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkWeaponQuality::ArkQualityTiersProperty
	// Header:  Prey/Ark/ArkWeaponModifier.h
	class ArkQualityTiersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkQualityTiersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponQuality::ArkQualityTiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B2E80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponQuality::ArkQualityTiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B2F40);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponQuality::ArkQualityTiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponQuality::ArkQualityTiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2F80);
	};

	static inline auto s_ArkQualityTiersProperty = PreyGlobal<ArkWeaponQuality::ArkQualityTiersProperty>(0x2D29670);
	std::vector<ArkWeaponQualityTier> m_QualityTiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	uint8_t GetNumModsToInstall(const string& _installWeaponName, const IArkItem::EArkQualityTier _tier) const { return FGetNumModsToInstall(this, _installWeaponName, _tier); }
	uint8_t GetMaxModsPerStat(const string& _installWeaponName, const IArkItem::EArkQualityTier _tier) const { return FGetMaxModsPerStat(this, _installWeaponName, _tier); }
	uint8_t GetChanceForEnchantment(const string& _installWeaponName, const IArkItem::EArkQualityTier _tier) const { return FGetChanceForEnchantment(this, _installWeaponName, _tier); }

#if 0
	std::vector<ArkWeaponQualityTier>& GetQualityTiers();
	const std::vector<ArkWeaponQualityTier>& GetQualityTiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B5B50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10B61F0);
	static inline auto FInit = PreyFunction<bool(ArkWeaponQuality* const _this)>(0x10B6CF0);
	static inline auto FGetNumModsToInstall = PreyFunction<uint8_t(const ArkWeaponQuality* const _this, const string& _installWeaponName, const IArkItem::EArkQualityTier _tier)>(0x10B64C0);
	static inline auto FGetMaxModsPerStat = PreyFunction<uint8_t(const ArkWeaponQuality* const _this, const string& _installWeaponName, const IArkItem::EArkQualityTier _tier)>(0x10B6400);
	static inline auto FGetChanceForEnchantment = PreyFunction<uint8_t(const ArkWeaponQuality* const _this, const string& _installWeaponName, const IArkItem::EArkQualityTier _tier)>(0x10B5C30);
};
#endif // !MOONCRASH
