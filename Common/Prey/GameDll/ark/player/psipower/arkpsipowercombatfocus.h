// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkInputLegend;
class CCryName;
struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercombatfocus.h
class ArkPsiPowerCombatFocusProperties : public ArkReflectedObject // Id=801B698 Size=72
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801B699 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801B69A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801B69B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkStatPackageProperty : public ArkProperty // Id=801B69C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty s_ArkStatPackageProperty;
	uint64_t m_StatPackage;
	
	class ArkOutboundSignalModifierProperty : public ArkProperty // Id=801B69D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty s_ArkOutboundSignalModifierProperty;
	uint64_t m_OutboundSignalModifier;
	
	class ArkDurationProperty : public ArkProperty // Id=801B69E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiPowerCombatFocusProperties::ArkDurationProperty s_ArkDurationProperty;
	float m_Duration;
	
	class ArkTimeScaleProperty : public ArkProperty // Id=801B69F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328680);
	};

	static ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty s_ArkTimeScaleProperty;
	float m_TimeScale;
	
	class ArkPlayerTimeScaleProperty : public ArkProperty // Id=801B6A0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty s_ArkPlayerTimeScaleProperty;
	float m_PlayerTimeScale;
	
	class ArkActiveAudioTriggerProperty : public ArkProperty // Id=801B6A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty s_ArkActiveAudioTriggerProperty;
	string m_ActiveAudioTrigger;
	
	class ArkInactiveAudioTriggerProperty : public ArkProperty // Id=801B6A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty s_ArkInactiveAudioTriggerProperty;
	string m_InactiveAudioTrigger;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetStatPackage(uint64_t arg0);
	const uint64_t &GetStatPackage() const;
	void SetOutboundSignalModifier(uint64_t arg0);
	const uint64_t &GetOutboundSignalModifier() const;
	void SetDuration(float arg0);
	const float &GetDuration() const;
	void SetTimeScale(float arg0);
	const float &GetTimeScale() const;
	void SetPlayerTimeScale(float arg0);
	const float &GetPlayerTimeScale() const;
	void SetActiveAudioTrigger(string arg0);
	string const &GetActiveAudioTrigger() const;
	void SetInactiveAudioTrigger(string arg0);
	string const &GetInactiveAudioTrigger() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F4CE0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F4FE0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercombatfocus.h
class CombatFocusPowerProperties : public ArkReflectedLibrary // Id=801B6A3 Size=248
{
public:
	using LevelProperties = ArkPsiPowerCombatFocusProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801B6A4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CombatFocusPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CombatFocusPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static CombatFocusPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801B6A5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CombatFocusPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CombatFocusPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static CombatFocusPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801B6A6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CombatFocusPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12F3600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CombatFocusPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3750);
		static inline auto FIsArray = PreyFunction<bool(CombatFocusPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(CombatFocusPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x12F37A0);
	};

	static CombatFocusPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerCombatFocusProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~CombatFocusPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerCombatFocusProperties> &GetLevels();
	std::vector<ArkPsiPowerCombatFocusProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F4D30);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F5080);
	static inline auto FInit = PreyFunction<bool(CombatFocusPowerProperties *const _this)>(0x12F54D0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowercombatfocus.h
class CArkPsiPowerCombatFocus : public CArkPsiPower<CombatFocusPowerProperties>, public IEntityEventListener // Id=801B6B5 Size=112
{
public:
	ArkSimpleTimer m_timer;
	ArkAudioTrigger m_triggerActive;
	ArkAudioTrigger m_triggerInactive;
	int m_timeScaleHandle;
	int m_playerTimeScaleHandle;
	unsigned m_packageHandle;
	uint64_t m_appliedSignalModifier;
	
	CArkPsiPowerCombatFocus();
	virtual ~CArkPsiPowerCombatFocus();
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual void ProcessInput(CCryName const &_actionId, int _activationMode, float _value);
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void CleanUp() { FCleanUp(this); }
	void Activate(bool _bFromSave) { FActivate(this,_bFromSave); }
	void Deactivate() { FDeactivate(this); }
	virtual void SetLevel_Derived(const int _level);
	
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerCombatFocus *const _this)>(0x12F5B40);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerCombatFocus *const _this)>(0x12F5AC0);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, const float _fFrameTime)>(0x12F5B50);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerCombatFocus *const _this)>(0x12F5A70);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, TSerialize _ser)>(0x12F57C0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerCombatFocus *const _this)>(0x12F56F0);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(CArkPsiPowerCombatFocus const *const _this)>(0x912270);
	static inline auto FProcessInput = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0x12F5720);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(CArkPsiPowerCombatFocus const *const _this)>(0x12F53C0);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x12F56B0);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerCombatFocus *const _this)>(0x12F4BC0);
	static inline auto FActivate = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, bool _bFromSave)>(0x12F49E0);
	static inline auto FDeactivate = PreyFunction<void(CArkPsiPowerCombatFocus *const _this)>(0x12F4E00);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerCombatFocus *const _this, const int _level)>(0x12F59A0);
};

