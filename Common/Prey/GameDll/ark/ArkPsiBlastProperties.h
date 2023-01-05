// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>

class ArkClass;
class IArkValueBase;
class ArkPsiPowerTargetingComponent;
struct IParticleEffect;

// ArkPsiBlastProperties
// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
class ArkPsiBlastProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiBlastProperties::ArkRadiusProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiBlastProperties::ArkTriggerRadiusProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkTriggerRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTriggerRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiBlastProperties::ArkForceProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkForceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiBlastProperties::ArkFalloffScaleProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkFalloffScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFalloffScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiBlastProperties::ArkFalloffRadiusProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkFalloffRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFalloffRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiBlastProperties::ArkDelaySecProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiBlastProperties::ArkExplosionDelaySecProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkExplosionDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiBlastProperties::ArkDurationSecProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	// ArkPsiBlastProperties::ArkUpdateIntervalSecProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkUpdateIntervalSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUpdateIntervalSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiBlastProperties::ArkMaxBlastCountProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkMaxBlastCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBlastCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
	};

	// ArkPsiBlastProperties::ArkSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkExplosionSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiBlastProperties::ArkNoiseIdProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkNoiseIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoiseIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiBlastProperties::ArkLoudnessIdProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkLoudnessIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoudnessIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	// ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkPreExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPreExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	// ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkKillPreExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKillPreExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiBlastProperties::ArkExplosionParticleEffectProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
	};

	// ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkStartDelayAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartDelayAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	// ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkStopDelayAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStopDelayAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D20);
	};

	// ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkExplosionAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082260);
	};

	// ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkStartPersistentAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartPersistentAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D30);
	};

	// ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkStopPersistentAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStopPersistentAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10617E0);
	};

	// ArkPsiBlastProperties::ArkCameraShakeProperty
	// Header:  Prey/GameDll/ark/ArkPsiBlastProperties.h
	class ArkCameraShakeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCameraShakeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4DB0);
	};

	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkRadiusProperty>(0x2BE0A78);
	float m_Radius;
	static inline auto s_ArkTriggerRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkTriggerRadiusProperty>(0x2BE0A98);
	float m_TriggerRadius;
	static inline auto s_ArkForceProperty = PreyGlobal<ArkPsiBlastProperties::ArkForceProperty>(0x2BE0AB8);
	float m_Force;
	static inline auto s_ArkFalloffScaleProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffScaleProperty>(0x2BE0AD8);
	float m_FalloffScale;
	static inline auto s_ArkFalloffRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffRadiusProperty>(0x2BE0AF8);
	float m_FalloffRadius;
	static inline auto s_ArkDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDelaySecProperty>(0x2BE0B18);
	float m_DelaySec;
	static inline auto s_ArkExplosionDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionDelaySecProperty>(0x2BE0B38);
	float m_ExplosionDelaySec;
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDurationSecProperty>(0x2BE0B58);
	float m_DurationSec;
	static inline auto s_ArkUpdateIntervalSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkUpdateIntervalSecProperty>(0x2BE0B78);
	float m_UpdateIntervalSec;
	static inline auto s_ArkMaxBlastCountProperty = PreyGlobal<ArkPsiBlastProperties::ArkMaxBlastCountProperty>(0x2BE0B98);
	int m_MaxBlastCount;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkSignalPackageIdProperty>(0x2BE0BB8);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkExplosionSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty>(0x2BE0BD8);
	uint64_t m_ExplosionSignalPackageId;
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkNoiseIdProperty>(0x2BE0BF8);
	uint64_t m_NoiseId;
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkLoudnessIdProperty>(0x2BE0C18);
	uint64_t m_LoudnessId;
	static inline auto s_ArkPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty>(0x2BE0C38);
	string m_PreExplosionParticleEffect;
	static inline auto s_ArkKillPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty>(0x2BE0C58);
	bool m_KillPreExplosionParticleEffect;
	static inline auto s_ArkExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionParticleEffectProperty>(0x2BE0C78);
	string m_ExplosionParticleEffect;
	static inline auto s_ArkStartDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty>(0x2BE0C98);
	string m_StartDelayAudioTrigger;
	static inline auto s_ArkStopDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty>(0x2BE0CB8);
	string m_StopDelayAudioTrigger;
	static inline auto s_ArkExplosionAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty>(0x2BE0CD8);
	string m_ExplosionAudioTrigger;
	static inline auto s_ArkStartPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty>(0x2BE0CF8);
	string m_StartPersistentAudioTrigger;
	static inline auto s_ArkStopPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty>(0x2BE0D18);
	string m_StopPersistentAudioTrigger;
	static inline auto s_ArkCameraShakeProperty = PreyGlobal<ArkPsiBlastProperties::ArkCameraShakeProperty>(0x2BE0D38);
	uint64_t m_CameraShake;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetRadius(float _arg0_);
	const float& GetRadius() const;
	void SetTriggerRadius(float _arg0_);
	const float& GetTriggerRadius() const;
	void SetForce(float _arg0_);
	const float& GetForce() const;
	void SetFalloffScale(float _arg0_);
	const float& GetFalloffScale() const;
	void SetFalloffRadius(float _arg0_);
	const float& GetFalloffRadius() const;
	void SetDelaySec(float _arg0_);
	const float& GetDelaySec() const;
	void SetExplosionDelaySec(float _arg0_);
	const float& GetExplosionDelaySec() const;
	void SetDurationSec(float _arg0_);
	const float& GetDurationSec() const;
	void SetUpdateIntervalSec(float _arg0_);
	const float& GetUpdateIntervalSec() const;
	void SetMaxBlastCount(int _arg0_);
	const int& GetMaxBlastCount() const;
	void SetSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetSignalPackageId() const;
	void SetExplosionSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetExplosionSignalPackageId() const;
	void SetNoiseId(uint64_t _arg0_);
	const uint64_t& GetNoiseId() const;
	void SetLoudnessId(uint64_t _arg0_);
	const uint64_t& GetLoudnessId() const;
	void SetPreExplosionParticleEffect(string _arg0_);
	const string& GetPreExplosionParticleEffect() const;
	void SetKillPreExplosionParticleEffect(bool _arg0_);
	const bool& GetKillPreExplosionParticleEffect() const;
	void SetExplosionParticleEffect(string _arg0_);
	const string& GetExplosionParticleEffect() const;
	void SetStartDelayAudioTrigger(string _arg0_);
	const string& GetStartDelayAudioTrigger() const;
	void SetStopDelayAudioTrigger(string _arg0_);
	const string& GetStopDelayAudioTrigger() const;
	void SetExplosionAudioTrigger(string _arg0_);
	const string& GetExplosionAudioTrigger() const;
	void SetStartPersistentAudioTrigger(string _arg0_);
	const string& GetStartPersistentAudioTrigger() const;
	void SetStopPersistentAudioTrigger(string _arg0_);
	const string& GetStopPersistentAudioTrigger() const;
	void SetCameraShake(uint64_t _arg0_);
	const uint64_t& GetCameraShake() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15811D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13D4DE0);
};

// CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>
// Header:  _unknown/CArkPsiBlastProperties.h
template <typename TData>
class CArkPsiBlastProperties
{ // Size=128 (0x80)
public:
	using Data = TData;

	ArkGameNoise::Params m_noiseParams;
	_smart_ptr<IParticleEffect> m_pPreExplosionParticleEffect;
	ArkFireAndForgetEffect m_explosionParticleEffect;
	ArkAudioTrigger m_onStartDelayAudioTrigger;
	ArkAudioTrigger m_onStopDelayAudioTrigger;
	ArkAudioTrigger m_onExplosionAudioTrigger;
	ArkAudioTrigger m_onStartPersistentAudioTrigger;
	ArkAudioTrigger m_onStopPersistentAudioTrigger;
	const TData* m_pData;
	const ArkPsiPowerTargetingComponent* m_pTargetingComponent;

	void SetData(const TData& _data, const ArkPsiPowerTargetingComponent& _targetingComponent);

#if 0
	CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>();
	const ArkPsiElectrostaticBurstProperties& GetData() const;
	const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
#endif
};
