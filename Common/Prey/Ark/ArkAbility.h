// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkability.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

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

