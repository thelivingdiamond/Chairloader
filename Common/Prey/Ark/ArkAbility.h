// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkability.h
class ArkStatModifier : public ArkReflectedObject // Id=80134F7 Size=16
{
public:
	class ArkStatNameProperty : public ArkProperty // Id=80134F8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkStatModifier::ArkStatNameProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkStatModifier::ArkStatNameProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkStatModifier::ArkStatNameProperty s_ArkStatNameProperty;
	CCryName m_StatName;

	class ArkModifierProperty : public ArkProperty // Id=80134F9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkStatModifier::ArkModifierProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkStatModifier::ArkModifierProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static ArkStatModifier::ArkModifierProperty s_ArkModifierProperty;
	float m_Modifier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetStatName(CCryName arg0);
	CCryName const& GetStatName() const;
	void SetModifier(float arg0);
	const float& GetModifier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1058720);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10589B0);
};

// Header: Exact
// Prey/Ark/ArkAbility.h
class ArkAbility : public ArkReflectedObject // Id=80134D5 Size=160
{
public:
	class ArkIDProperty : public ArkProperty // Id=80134D6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAbility::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkIconProperty : public ArkProperty // Id=80134D7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkIconProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkIconProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAbility::ArkIconProperty s_ArkIconProperty;
	string m_Icon;
	
	class ArkNameProperty : public ArkProperty // Id=80134D8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAbility::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=80134D9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkAbility::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkDescriptionProperty : public ArkProperty // Id=80134DA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkAbility::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkTierProperty : public ArkProperty // Id=80134DB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkTierProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkTierProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkAbility::ArkTierProperty s_ArkTierProperty;
	int m_Tier;
	
	class ArkNightmareHeatProperty : public ArkProperty // Id=80134DC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkNightmareHeatProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkNightmareHeatProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkAbility::ArkNightmareHeatProperty s_ArkNightmareHeatProperty;
	float m_NightmareHeat;
	
	class ArkCostProperty : public ArkProperty // Id=80134DD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkCostProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkCostProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkAbility::ArkCostProperty s_ArkCostProperty;
	uint8_t m_Cost;
	
	class ArkRequireScannerProperty : public ArkProperty // Id=80134DE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkRequireScannerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056F50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkRequireScannerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F60);
	};

	static ArkAbility::ArkRequireScannerProperty s_ArkRequireScannerProperty;
	bool m_RequireScanner;
	
	class ArkPrereqsProperty : public ArkProperty // Id=80134DF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkPrereqsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkPrereqsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(ArkAbility::ArkPrereqsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbility::ArkPrereqsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1059650);
	};

	static ArkAbility::ArkPrereqsProperty s_ArkPrereqsProperty;
	std::vector<unsigned __int64> m_Prereqs;
	
	class ArkPowerProperty : public ArkProperty // Id=80134E0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkPowerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056F70);
	};

	static ArkAbility::ArkPowerProperty s_ArkPowerProperty;
	EArkPsiPowers m_Power;
	
	class ArkPowerLevelProperty : public ArkProperty // Id=80134E1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkPowerLevelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkPowerLevelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056FD0);
	};

	static ArkAbility::ArkPowerLevelProperty s_ArkPowerLevelProperty;
	uint8_t m_PowerLevel;
	
	class ArkSignalModifiersProperty : public ArkProperty // Id=80134E2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1056FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1057010);
		static inline auto FIsArray = PreyFunction<bool(ArkAbility::ArkSignalModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbility::ArkSignalModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x106D710);
	};

	static ArkAbility::ArkSignalModifiersProperty s_ArkSignalModifiersProperty;
	std::vector<ArkSignalModifer> m_SignalModifiers;
	
	class ArkStatModifiersProperty : public ArkProperty // Id=80134F3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkStatModifiersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10570E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkStatModifiersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1057140);
		static inline auto FIsArray = PreyFunction<bool(ArkAbility::ArkStatModifiersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbility::ArkStatModifiersProperty const *const _this, ArkReflectedObject *_pObject)>(0x1057160);
	};

	static ArkAbility::ArkStatModifiersProperty s_ArkStatModifiersProperty;
	std::vector<ArkStatModifier> m_StatModifiers;
	
	class ArkTutorialProperty : public ArkProperty // Id=8013504 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10571F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4DB0);
	};

	static ArkAbility::ArkTutorialProperty s_ArkTutorialProperty;
	string m_Tutorial;
	
	class ArkTutorialPCProperty : public ArkProperty // Id=8013505 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkTutorialPCProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1057250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkTutorialPCProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10822A0);
	};

	static ArkAbility::ArkTutorialPCProperty s_ArkTutorialPCProperty;
	string m_TutorialPC;
	
	class ArkTutorialImageProperty : public ArkProperty // Id=8013506 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbility::ArkTutorialImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10572B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbility::ArkTutorialImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10736E0);
	};

	static ArkAbility::ArkTutorialImageProperty s_ArkTutorialImageProperty;
	string m_TutorialImage;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetIcon(string arg0);
	string const &GetIcon() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetTier(int arg0);
	const int &GetTier() const;
	void SetNightmareHeat(float arg0);
	const float &GetNightmareHeat() const;
	void SetCost(uint8_t arg0);
	const uint8_t &GetCost() const;
	void SetRequireScanner(bool arg0);
	const bool &GetRequireScanner() const;
	std::vector<unsigned __int64> &GetPrereqs();
	std::vector<unsigned __int64> const &GetPrereqs() const;
	void SetPower(string arg0);
	EArkPsiPowers const &GetPower() const;
	void SetPowerLevel(uint8_t arg0);
	const uint8_t &GetPowerLevel() const;
	std::vector<ArkSignalModifer> &GetSignalModifiers();
	std::vector<ArkSignalModifer> const &GetSignalModifiers() const;
	std::vector<ArkStatModifier> &GetStatModifiers();
	std::vector<ArkStatModifier> const &GetStatModifiers() const;
	void SetTutorial(string arg0);
	string const &GetTutorial() const;
	void SetTutorialPC(string arg0);
	string const &GetTutorialPC() const;
	void SetTutorialImage(string arg0);
	string const &GetTutorialImage() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1058620);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1058870);
};

// Header: Exact
// Prey/Ark/arkability.h
class ArkAbilities : public ArkReflectedLibrary // Id=8013547 Size=32
{
public:
	class ArkAbilitiesProperty : public ArkProperty // Id=8013548 Size=32
	{
	public:
		ArkAbilitiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilities::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1057030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilities::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1057080);
		static inline auto FIsArray = PreyFunction<bool(ArkAbilities::ArkAbilitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbilities::ArkAbilitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x10570C0);
	};

	static ArkAbilities::ArkAbilitiesProperty s_ArkAbilitiesProperty;
	std::vector<ArkAbility> m_Abilities;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkAbility const *GetAbilityByID(uint64_t _abilityID) const { return FGetAbilityByIDOv1(this,_abilityID); }
	virtual bool Init();
	virtual bool Shutdown();
	void RemoveLoops_r(ArkAbility &_currentAbility, std::vector<unsigned __int64> &_abilityIDs) { FRemoveLoops_r(this,_currentAbility,_abilityIDs); }
	virtual ~ArkAbilities();
	
#if 0
	std::vector<ArkAbility> &GetAbilities();
	std::vector<ArkAbility> const &GetAbilities() const;
	ArkAbility *GetAbilityByID(uint64_t arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10585C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1058780);
	static inline auto FGetAbilityByIDOv1 = PreyFunction<ArkAbility const *(ArkAbilities const *const _this, uint64_t _abilityID)>(0x1058750);
	static inline auto FInit = PreyFunction<bool(ArkAbilities *const _this)>(0x1058A50);
	static inline auto FShutdown = PreyFunction<bool(ArkAbilities *const _this)>(0x1058E90);
	static inline auto FRemoveLoops_r = PreyFunction<void(ArkAbilities *const _this, ArkAbility &_currentAbility, std::vector<unsigned __int64> &_abilityIDs)>(0x1058CE0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSignalModifer.h>

class ArkClass;
class IArkValueBase;

// ArkStatModifier
// Header:  Prey/Ark/ArkAbility.h
class ArkStatModifier : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkStatModifier::ArkStatNameProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkStatNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStatNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStatModifier::ArkStatNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStatModifier::ArkStatNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkStatModifier::ArkModifierProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkModifierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModifierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStatModifier::ArkModifierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStatModifier::ArkModifierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkStatNameProperty = PreyGlobal<ArkStatModifier::ArkStatNameProperty>(0x2D20CD0);
	CCryName m_StatName;
	static inline auto s_ArkModifierProperty = PreyGlobal<ArkStatModifier::ArkModifierProperty>(0x2D20CF0);
	float m_Modifier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetStatName(CCryName _arg0_);
	const CCryName& GetStatName() const;
	void SetModifier(float _arg0_);
	const float& GetModifier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1074E10);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10750A0);
};

// ArkAbility
// Header:  Prey/Ark/ArkAbility.h
class ArkAbility : public ArkReflectedObject
{ // Size=192 (0xC0)
public:
	// ArkAbility::ArkIDProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkAbility::ArkIconProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkAbility::ArkNameProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkAbility::ArkLabelProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkAbility::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkAbility::ArkTierProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkTierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkTierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkTierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkAbility::ArkNightmareHeatProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkNightmareHeatProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNightmareHeatProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkNightmareHeatProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkNightmareHeatProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3130);
	};

	// ArkAbility::ArkCostProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkCostProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCostProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkCostProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkCostProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkAbility::ArkRequireScannerProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkRequireScannerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRequireScannerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkRequireScannerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkRequireScannerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073730);
	};

	// ArkAbility::ArkPrereqsProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkPrereqsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPrereqsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkPrereqsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkPrereqsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073740);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbility::ArkPrereqsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbility::ArkPrereqsProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
	};

	// ArkAbility::ArkPowerProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkPowerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkPowerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkPowerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073760);
	};

	// ArkAbility::ArkPowerLevelProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkPowerLevelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPowerLevelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkPowerLevelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkPowerLevelProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// ArkAbility::ArkSignalModifiersProperty
	// Header:  Prey/Ark/ArkAbility.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10737B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkSignalModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10737E0);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbility::ArkSignalModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbility::ArkSignalModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x1079660);
	};

	// ArkAbility::ArkStatModifiersProperty
	// Header:  Prey/Ark/ArkAbility.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkStatModifiersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10735D0);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbility::ArkStatModifiersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbility::ArkStatModifiersProperty* const _this, ArkReflectedObject* _pObject)>(0x10735F0);
	};

	// ArkAbility::ArkTutorialProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkTutorialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C570);
	};

	// ArkAbility::ArkTutorialPCProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkTutorialPCProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialPCProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkTutorialPCProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BF640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkTutorialPCProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// ArkAbility::ArkTutorialImageProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkTutorialImageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTutorialImageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkTutorialImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE1B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkTutorialImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkAbility::ArkSignalKeywordProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkSignalKeywordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalKeywordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkSignalKeywordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkSignalKeywordProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	// ArkAbility::ArkSignalIdProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkSignalIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkSignalIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD5B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkSignalIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	// ArkAbility::ArkPackageIdProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10736D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1000);
	};

	// ArkAbility::ArkIsInboundProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkIsInboundProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsInboundProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkIsInboundProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10736E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkIsInboundProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1070);
	};

	// ArkAbility::ArkSignalScaleProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkSignalScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbility::ArkSignalScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10736F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbility::ArkSignalScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073700);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkAbility::ArkIDProperty>(0x2D20D10);
	uint64_t m_ID;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkAbility::ArkIconProperty>(0x2D20D30);
	string m_Icon;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkAbility::ArkNameProperty>(0x2D20D50);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkAbility::ArkLabelProperty>(0x2D20D70);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkAbility::ArkDescriptionProperty>(0x2D20D90);
	string m_Description;
	static inline auto s_ArkTierProperty = PreyGlobal<ArkAbility::ArkTierProperty>(0x2D20DB0);
	int m_Tier;
	static inline auto s_ArkNightmareHeatProperty = PreyGlobal<ArkAbility::ArkNightmareHeatProperty>(0x2D20DD0);
	float m_NightmareHeat;
	static inline auto s_ArkCostProperty = PreyGlobal<ArkAbility::ArkCostProperty>(0x2D20DF0);
	uint8_t m_Cost;
	static inline auto s_ArkRequireScannerProperty = PreyGlobal<ArkAbility::ArkRequireScannerProperty>(0x2D20E10);
	bool m_RequireScanner;
	static inline auto s_ArkPrereqsProperty = PreyGlobal<ArkAbility::ArkPrereqsProperty>(0x2D20E30);
	std::vector<uint64_t> m_Prereqs;
	static inline auto s_ArkPowerProperty = PreyGlobal<ArkAbility::ArkPowerProperty>(0x2D20E50);
	EArkPsiPowers m_Power;
	static inline auto s_ArkPowerLevelProperty = PreyGlobal<ArkAbility::ArkPowerLevelProperty>(0x2D20E70);
	uint8_t m_PowerLevel;
	static inline auto s_ArkSignalModifiersProperty = PreyGlobal<ArkAbility::ArkSignalModifiersProperty>(0x2D20E90);
	std::vector<ArkSignalModifer> m_SignalModifiers;
	static inline auto s_ArkStatModifiersProperty = PreyGlobal<ArkAbility::ArkStatModifiersProperty>(0x2D20EB0);
	std::vector<ArkStatModifier> m_StatModifiers;
	static inline auto s_ArkTutorialProperty = PreyGlobal<ArkAbility::ArkTutorialProperty>(0x2D20ED0);
	string m_Tutorial;
	static inline auto s_ArkTutorialPCProperty = PreyGlobal<ArkAbility::ArkTutorialPCProperty>(0x2D20EF0);
	string m_TutorialPC;
	static inline auto s_ArkTutorialImageProperty = PreyGlobal<ArkAbility::ArkTutorialImageProperty>(0x2D20F10);
	string m_TutorialImage;
	static inline auto s_ArkSignalKeywordProperty = PreyGlobal<ArkAbility::ArkSignalKeywordProperty>(0x2D20F30);
	string m_SignalKeyword;
	static inline auto s_ArkSignalIdProperty = PreyGlobal<ArkAbility::ArkSignalIdProperty>(0x2D20F50);
	uint64_t m_SignalId;
	static inline auto s_ArkPackageIdProperty = PreyGlobal<ArkAbility::ArkPackageIdProperty>(0x2D20F70);
	uint64_t m_PackageId;
	static inline auto s_ArkIsInboundProperty = PreyGlobal<ArkAbility::ArkIsInboundProperty>(0x2D20F90);
	bool m_IsInbound;
	static inline auto s_ArkSignalScaleProperty = PreyGlobal<ArkAbility::ArkSignalScaleProperty>(0x2D20FB0);
	float m_SignalScale;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkAbility();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetIcon(string _arg0_);
	const string& GetIcon() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetTier(int _arg0_);
	const int& GetTier() const;
	void SetNightmareHeat(float _arg0_);
	const float& GetNightmareHeat() const;
	void SetCost(uint8_t _arg0_);
	const uint8_t& GetCost() const;
	void SetRequireScanner(bool _arg0_);
	const bool& GetRequireScanner() const;
	std::vector<uint64_t>& GetPrereqs();
	const std::vector<uint64_t>& GetPrereqs() const;
	void SetPower(string _arg0_);
	const EArkPsiPowers& GetPower() const;
	void SetPowerLevel(uint8_t _arg0_);
	const uint8_t& GetPowerLevel() const;
	std::vector<ArkSignalModifer>& GetSignalModifiers();
	const std::vector<ArkSignalModifer>& GetSignalModifiers() const;
	std::vector<ArkStatModifier>& GetStatModifiers();
	const std::vector<ArkStatModifier>& GetStatModifiers() const;
	void SetTutorial(string _arg0_);
	const string& GetTutorial() const;
	void SetTutorialPC(string _arg0_);
	const string& GetTutorialPC() const;
	void SetTutorialImage(string _arg0_);
	const string& GetTutorialImage() const;
	void SetSignalKeyword(string _arg0_);
	const string& GetSignalKeyword() const;
	void SetSignalId(uint64_t _arg0_);
	const uint64_t& GetSignalId() const;
	void SetPackageId(uint64_t _arg0_);
	const uint64_t& GetPackageId() const;
	void SetIsInbound(bool _arg0_);
	const bool& GetIsInbound() const;
	void SetSignalScale(float _arg0_);
	const float& GetSignalScale() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1074CE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1074F60);
};

// ArkAbilities
// Header:  Prey/Ark/ArkAbility.h
class ArkAbilities : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkAbilities::ArkAbilitiesProperty
	// Header:  Prey/Ark/ArkAbility.h
	class ArkAbilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkAbilitiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkAbilitiesPropertyOv2 = PreyFunction<void(ArkAbilities::ArkAbilitiesProperty* const _this)>(0x10744A0);
		static inline auto FSetValue = PreyFunction<void(const ArkAbilities::ArkAbilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1073800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilities::ArkAbilitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073850);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbilities::ArkAbilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbilities::ArkAbilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x1073890);
	};

	static inline auto s_ArkAbilitiesProperty = PreyGlobal<ArkAbilities::ArkAbilitiesProperty>(0x2D20FD0);
	std::vector<ArkAbility> m_Abilities;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkAbility* GetAbilityByID(uint64_t _abilityID) const { return FGetAbilityByIDOv1(this, _abilityID); }
	virtual bool Init();
	virtual bool Shutdown();
	void RemoveLoops_r(ArkAbility& _currentAbility, std::vector<uint64_t>& _abilityIDs) { FRemoveLoops_r(this, _currentAbility, _abilityIDs); }

#if 0
	std::vector<ArkAbility>& GetAbilities();
	const std::vector<ArkAbility>& GetAbilities() const;
	ArkAbility* GetAbilityByID(uint64_t _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1074C80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1074E70);
	static inline auto FGetAbilityByIDOv1 = PreyFunction<const ArkAbility* (const ArkAbilities* const _this, uint64_t _abilityID)>(0x1074E40);
	static inline auto FInit = PreyFunction<bool(ArkAbilities* const _this)>(0x1075140);
	static inline auto FShutdown = PreyFunction<bool(ArkAbilities* const _this)>(0x1075590);
	static inline auto FRemoveLoops_r = PreyFunction<void(ArkAbilities* const _this, ArkAbility& _currentAbility, std::vector<uint64_t>& _abilityIDs)>(0x10753E0);
};
#endif // !MOONCRASH
