// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiBlastProperties
// Header:  Prey/Ark/ArkPsiBlastProperties.h
class ArkPsiBlastProperties : public ArkReflectedObject
{ // Size=144 (0x90)
public:
	// ArkPsiBlastProperties::ArkRadiusProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiBlastProperties::ArkTriggerRadiusProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkTriggerRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTriggerRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkPsiBlastProperties::ArkForceProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkForceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiBlastProperties::ArkFalloffScaleProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkFalloffScaleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFalloffScaleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// ArkPsiBlastProperties::ArkFalloffRadiusProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkFalloffRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFalloffRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiBlastProperties::ArkDelaySecProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkPsiBlastProperties::ArkExplosionDelaySecProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkExplosionDelaySecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionDelaySecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiBlastProperties::ArkDurationSecProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkPsiBlastProperties::ArkUpdateIntervalSecProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkUpdateIntervalSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUpdateIntervalSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiBlastProperties::ArkMaxBlastCountProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkMaxBlastCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBlastCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	// ArkPsiBlastProperties::ArkSignalPackageIdProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkExplosionSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPsiBlastProperties::ArkNoiseIdProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkNoiseIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNoiseIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkPsiBlastProperties::ArkLoudnessIdProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkLoudnessIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLoudnessIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkPreExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPreExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10917B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkKillPreExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKillPreExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// ArkPsiBlastProperties::ArkExplosionParticleEffectProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkExplosionParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkStartDelayAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartDelayAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkStopDelayAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStopDelayAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0B90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkExplosionAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExplosionAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkStartPersistentAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartPersistentAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0C50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkStopPersistentAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStopPersistentAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x16B7F00);
	};

	// ArkPsiBlastProperties::ArkCameraShakeProperty
	// Header:  Prey/Ark/ArkPsiBlastProperties.h
	class ArkCameraShakeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCameraShakeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C570);
	};

	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkRadiusProperty>(0x2D5ABB8);
	float m_Radius;
	static inline auto s_ArkTriggerRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkTriggerRadiusProperty>(0x2D5ABD8);
	float m_TriggerRadius;
	static inline auto s_ArkForceProperty = PreyGlobal<ArkPsiBlastProperties::ArkForceProperty>(0x2D5ABF8);
	float m_Force;
	static inline auto s_ArkFalloffScaleProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffScaleProperty>(0x2D5AC18);
	float m_FalloffScale;
	static inline auto s_ArkFalloffRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffRadiusProperty>(0x2D5AC38);
	float m_FalloffRadius;
	static inline auto s_ArkDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDelaySecProperty>(0x2D5AC58);
	float m_DelaySec;
	static inline auto s_ArkExplosionDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionDelaySecProperty>(0x2D5AC78);
	float m_ExplosionDelaySec;
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDurationSecProperty>(0x2D5AC98);
	float m_DurationSec;
	static inline auto s_ArkUpdateIntervalSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkUpdateIntervalSecProperty>(0x2D5ACB8);
	float m_UpdateIntervalSec;
	static inline auto s_ArkMaxBlastCountProperty = PreyGlobal<ArkPsiBlastProperties::ArkMaxBlastCountProperty>(0x2D5ACD8);
	int m_MaxBlastCount;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkSignalPackageIdProperty>(0x2D5ACF8);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkExplosionSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty>(0x2D5AD18);
	uint64_t m_ExplosionSignalPackageId;
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkNoiseIdProperty>(0x2D5AD38);
	uint64_t m_NoiseId;
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkLoudnessIdProperty>(0x2D5AD58);
	uint64_t m_LoudnessId;
	static inline auto s_ArkPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty>(0x2D5AD78);
	string m_PreExplosionParticleEffect;
	static inline auto s_ArkKillPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty>(0x2D5AD98);
	bool m_KillPreExplosionParticleEffect;
	static inline auto s_ArkExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionParticleEffectProperty>(0x2D5ADB8);
	string m_ExplosionParticleEffect;
	static inline auto s_ArkStartDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty>(0x2D5ADD8);
	string m_StartDelayAudioTrigger;
	static inline auto s_ArkStopDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty>(0x2D5ADF8);
	string m_StopDelayAudioTrigger;
	static inline auto s_ArkExplosionAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty>(0x2D5AE18);
	string m_ExplosionAudioTrigger;
	static inline auto s_ArkStartPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty>(0x2D5AE38);
	string m_StartPersistentAudioTrigger;
	static inline auto s_ArkStopPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty>(0x2D5AE58);
	string m_StopPersistentAudioTrigger;
	static inline auto s_ArkCameraShakeProperty = PreyGlobal<ArkPsiBlastProperties::ArkCameraShakeProperty>(0x2D5AE78);
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

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16A9600);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14E0D10);
};
#endif // MOONCRASH
