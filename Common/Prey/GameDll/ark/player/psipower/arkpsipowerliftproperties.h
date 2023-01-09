// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiLiftProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiLiftProperties : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkPsiLiftProperties::ArkMaxHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxHeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiLiftProperties::ArkDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	static inline auto s_ArkMaxHeightProperty = PreyGlobal<ArkPsiLiftProperties::ArkMaxHeightProperty>(0x2BD9CB0);
	float m_MaxHeight;
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiLiftProperties::ArkDurationSecProperty>(0x2BD9C90);
	float m_DurationSec;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMaxHeight(float _arg0_);
	const float& GetMaxHeight() const;
	void SetDurationSec(float _arg0_);
	const float& GetDurationSec() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F65E0);
};

// ArkPsiPowerLiftLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerLiftLevelProperties : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkLiftPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLiftPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty>(0x2BD9F10);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty>(0x2BD9F30);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty>(0x2BD9F50);
	float m_CooldownDurationSec;
	static inline auto s_ArkLiftPropertiesProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty>(0x2BD9F70);
	ArkPsiLiftProperties m_LiftProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetLiftProperties(ArkPsiLiftProperties _arg0_);
	const ArkPsiLiftProperties& GetLiftProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6460);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F6680);
};

// ArkPsiPowerLiftUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerLiftUniqueProperties : public ArkReflectedObject
{ // Size=104 (0x68)
public:
	// ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMinHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinHeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxRangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxRangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxRangeZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxRangeZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkGravityProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkGravityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGravityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkInwardLiftForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInwardLiftForceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkUpwardLiftForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUpwardLiftForceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkLiftForceZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLiftForceZeroGProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverVelocityDampingProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverVelocityDampingProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverVelocityFalloffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverVelocityFalloffProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverFalloffDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverFalloffDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkTargetingParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkTargetingParticleEffectLightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingParticleEffectLightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerPostEffectIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerPostEffectIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerEnterAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerEnterAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerExitAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerExitAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
	};

	// ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkEnterLiftSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnterLiftSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	static inline auto s_ArkMinHeightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty>(0x2BD9CD0);
	float m_MinHeight;
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty>(0x2BD9CF0);
	float m_MaxRange;
	static inline auto s_ArkMaxRangeZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty>(0x2BD9D10);
	float m_MaxRangeZeroG;
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty>(0x2BD9D30);
	float m_Radius;
	static inline auto s_ArkGravityProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkGravityProperty>(0x2BD9D50);
	float m_Gravity;
	static inline auto s_ArkInwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty>(0x2BD9D70);
	float m_InwardLiftForce;
	static inline auto s_ArkUpwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty>(0x2BD9D90);
	float m_UpwardLiftForce;
	static inline auto s_ArkLiftForceZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty>(0x2BD9DB0);
	float m_LiftForceZeroG;
	static inline auto s_ArkHoverVelocityDampingProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty>(0x2BD9DD0);
	float m_HoverVelocityDamping;
	static inline auto s_ArkHoverVelocityFalloffProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty>(0x2BD9DF0);
	float m_HoverVelocityFalloff;
	static inline auto s_ArkHoverFalloffDistanceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty>(0x2BD9E10);
	float m_HoverFalloffDistance;
	static inline auto s_ArkParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty>(0x2BD9E30);
	string m_ParticleEffect;
	static inline auto s_ArkTargetingParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty>(0x2BD9E50);
	string m_TargetingParticleEffect;
	static inline auto s_ArkTargetingParticleEffectLightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty>(0x2BD9E70);
	string m_TargetingParticleEffectLight;
	static inline auto s_ArkPlayerPostEffectIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty>(0x2BD9E90);
	uint64_t m_PlayerPostEffectId;
	static inline auto s_ArkPlayerEnterAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty>(0x2BD9EB0);
	string m_PlayerEnterAudioTrigger;
	static inline auto s_ArkPlayerExitAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty>(0x2BD9ED0);
	string m_PlayerExitAudioTrigger;
	static inline auto s_ArkEnterLiftSignalPackageIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty>(0x2BD9EF0);
	uint64_t m_EnterLiftSignalPackageId;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMinHeight(float _arg0_);
	const float& GetMinHeight() const;
	void SetMaxRange(float _arg0_);
	const float& GetMaxRange() const;
	void SetMaxRangeZeroG(float _arg0_);
	const float& GetMaxRangeZeroG() const;
	void SetRadius(float _arg0_);
	const float& GetRadius() const;
	void SetGravity(float _arg0_);
	const float& GetGravity() const;
	void SetInwardLiftForce(float _arg0_);
	const float& GetInwardLiftForce() const;
	void SetUpwardLiftForce(float _arg0_);
	const float& GetUpwardLiftForce() const;
	void SetLiftForceZeroG(float _arg0_);
	const float& GetLiftForceZeroG() const;
	void SetHoverVelocityDamping(float _arg0_);
	const float& GetHoverVelocityDamping() const;
	void SetHoverVelocityFalloff(float _arg0_);
	const float& GetHoverVelocityFalloff() const;
	void SetHoverFalloffDistance(float _arg0_);
	const float& GetHoverFalloffDistance() const;
	void SetParticleEffect(string _arg0_);
	const string& GetParticleEffect() const;
	void SetTargetingParticleEffect(string _arg0_);
	const string& GetTargetingParticleEffect() const;
	void SetTargetingParticleEffectLight(string _arg0_);
	const string& GetTargetingParticleEffectLight() const;
	void SetPlayerPostEffectId(uint64_t _arg0_);
	const uint64_t& GetPlayerPostEffectId() const;
	void SetPlayerEnterAudioTrigger(string _arg0_);
	const string& GetPlayerEnterAudioTrigger() const;
	void SetPlayerExitAudioTrigger(string _arg0_);
	const string& GetPlayerExitAudioTrigger() const;
	void SetEnterLiftSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetEnterLiftSignalPackageId() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F64A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F6720);
};

// LiftPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class LiftPowerProperties : public ArkReflectedLibrary
{ // Size=344 (0x158)
public:
	// LiftPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// LiftPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// LiftPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
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

		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5EA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F5F50);
		static inline auto FIsArray = PreyFunction<bool(const LiftPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x12F5FA0);
	};

	using LevelProperties = ArkPsiPowerLiftLevelProperties;
	using UniqueProperties = ArkPsiPowerLiftUniqueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<LiftPowerProperties::ArkCommonProperty>(0x2BD9F90);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<LiftPowerProperties::ArkUniqueProperty>(0x2BD9FB0);
	ArkPsiPowerLiftUniqueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<LiftPowerProperties::ArkLevelsProperty>(0x2BD9FD0);
	std::vector<ArkPsiPowerLiftLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerLiftUniqueProperties _arg0_);
	const ArkPsiPowerLiftUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerLiftLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerLiftLevelProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F64F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F67C0);
	static inline auto FInit = PreyFunction<bool(LiftPowerProperties* const _this)>(0x12F68B0);
};

