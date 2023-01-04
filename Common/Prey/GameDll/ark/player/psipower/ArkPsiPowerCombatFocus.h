// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkInputLegend;
class ArkPsiPowerCombatFocusProperties;
class CCryName;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
struct SEntityEvent;

// CombatFocusPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
class CombatFocusPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// CombatFocusPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCommonProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const CombatFocusPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CombatFocusPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// CombatFocusPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkUniqueProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const CombatFocusPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CombatFocusPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// CombatFocusPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#if 0
		ArkLevelsProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const CombatFocusPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F3600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CombatFocusPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3750);
		static inline auto FIsArray = PreyFunction<bool(const CombatFocusPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const CombatFocusPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x12F37A0);
	};

	using LevelProperties = ArkPsiPowerCombatFocusProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<CombatFocusPowerProperties::ArkCommonProperty>(0x2BD9B68);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<CombatFocusPowerProperties::ArkUniqueProperty>(0x2BD9B88);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<CombatFocusPowerProperties::ArkLevelsProperty>(0x2BD9BA8);
	std::vector<ArkPsiPowerCombatFocusProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerCombatFocusProperties>& GetLevels();
	const std::vector<ArkPsiPowerCombatFocusProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F4D30);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F5080);
	static inline auto FInit = PreyFunction<bool(CombatFocusPowerProperties* const _this)>(0x12F54D0);
};

// CArkPsiPowerCombatFocus
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
class CArkPsiPowerCombatFocus : public CArkPsiPower<CombatFocusPowerProperties>, public IEntityEventListener
{ // Size=112 (0x70)
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
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void CleanUp() { FCleanUp(this); }
	void Activate(bool _bFromSave) { FActivate(this, _bFromSave); }
	void Deactivate() { FDeactivate(this); }
	virtual void SetLevel_Derived(const int _level);

	static inline auto FCArkPsiPowerCombatFocusOv1 = PreyFunction<void(CArkPsiPowerCombatFocus* const _this)>(0x12F42B0);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerCombatFocus* const _this)>(0x12F5B40);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerCombatFocus* const _this)>(0x12F5AC0);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerCombatFocus* const _this, const float _fFrameTime)>(0x12F5B50);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerCombatFocus* const _this)>(0x12F5A70);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerCombatFocus* const _this, TSerialize _ser)>(0x12F57C0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerCombatFocus* const _this)>(0x12F56F0);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerCombatFocus* const _this)>(0x912270);
	static inline auto FProcessInput = PreyFunction<void(CArkPsiPowerCombatFocus* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x12F5720);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPowerCombatFocus* const _this)>(0x12F53C0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x12F56B0);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerCombatFocus* const _this)>(0x12F4BC0);
	static inline auto FActivate = PreyFunction<void(CArkPsiPowerCombatFocus* const _this, bool _bFromSave)>(0x12F49E0);
	static inline auto FDeactivate = PreyFunction<void(CArkPsiPowerCombatFocus* const _this)>(0x12F4E00);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerCombatFocus* const _this, const int _level)>(0x12F59A0);
};

// ArkPsiPowerCombatFocusProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
class ArkPsiPowerCombatFocusProperties : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkStatPackageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStatPackageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkOutboundSignalModifierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOutboundSignalModifierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiPowerCombatFocusProperties::ArkDurationProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkTimeScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTimeScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10821B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328680);
	};

	// ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkPlayerTimeScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerTimeScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkActiveAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkActiveAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCombatFocus.h
	class ArkInactiveAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInactiveAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkDisplayNameProperty>(0x2BD9A28);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkDescriptionProperty>(0x2BD9A48);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkCooldownDurationSecProperty>(0x2BD9A68);
	float m_CooldownDurationSec;
	static inline auto s_ArkStatPackageProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkStatPackageProperty>(0x2BD9A88);
	uint64_t m_StatPackage;
	static inline auto s_ArkOutboundSignalModifierProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkOutboundSignalModifierProperty>(0x2BD9AA8);
	uint64_t m_OutboundSignalModifier;
	static inline auto s_ArkDurationProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkDurationProperty>(0x2BD9AC8);
	float m_Duration;
	static inline auto s_ArkTimeScaleProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkTimeScaleProperty>(0x2BD9AE8);
	float m_TimeScale;
	static inline auto s_ArkPlayerTimeScaleProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkPlayerTimeScaleProperty>(0x2BD9B08);
	float m_PlayerTimeScale;
	static inline auto s_ArkActiveAudioTriggerProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkActiveAudioTriggerProperty>(0x2BD9B28);
	string m_ActiveAudioTrigger;
	static inline auto s_ArkInactiveAudioTriggerProperty = PreyGlobal<ArkPsiPowerCombatFocusProperties::ArkInactiveAudioTriggerProperty>(0x2BD9B48);
	string m_InactiveAudioTrigger;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetStatPackage(uint64_t _arg0_);
	const uint64_t& GetStatPackage() const;
	void SetOutboundSignalModifier(uint64_t _arg0_);
	const uint64_t& GetOutboundSignalModifier() const;
	void SetDuration(float _arg0_);
	const float& GetDuration() const;
	void SetTimeScale(float _arg0_);
	const float& GetTimeScale() const;
	void SetPlayerTimeScale(float _arg0_);
	const float& GetPlayerTimeScale() const;
	void SetActiveAudioTrigger(string _arg0_);
	const string& GetActiveAudioTrigger() const;
	void SetInactiveAudioTrigger(string _arg0_);
	const string& GetInactiveAudioTrigger() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F4CE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F4FE0);
};

