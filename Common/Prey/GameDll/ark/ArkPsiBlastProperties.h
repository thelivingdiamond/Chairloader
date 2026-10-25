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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkTriggerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffScaleProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkFalloffRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionDelaySecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkUpdateIntervalSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkMaxBlastCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkNoiseIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkLoudnessIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10917B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443D70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D20);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0B90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082260);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D30);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0C50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10617E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x16B7F00);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4DB0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiBlastProperties::ArkCameraShakeProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C570);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkRadiusProperty>(0x2BE0A78);
#else
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkRadiusProperty>(0x2D5ABB8);
#endif
	float m_Radius;
#ifndef MOONCRASH
	static inline auto s_ArkTriggerRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkTriggerRadiusProperty>(0x2BE0A98);
#else
	static inline auto s_ArkTriggerRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkTriggerRadiusProperty>(0x2D5ABD8);
#endif
	float m_TriggerRadius;
#ifndef MOONCRASH
	static inline auto s_ArkForceProperty = PreyGlobal<ArkPsiBlastProperties::ArkForceProperty>(0x2BE0AB8);
#else
	static inline auto s_ArkForceProperty = PreyGlobal<ArkPsiBlastProperties::ArkForceProperty>(0x2D5ABF8);
#endif
	float m_Force;
#ifndef MOONCRASH
	static inline auto s_ArkFalloffScaleProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffScaleProperty>(0x2BE0AD8);
#else
	static inline auto s_ArkFalloffScaleProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffScaleProperty>(0x2D5AC18);
#endif
	float m_FalloffScale;
#ifndef MOONCRASH
	static inline auto s_ArkFalloffRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffRadiusProperty>(0x2BE0AF8);
#else
	static inline auto s_ArkFalloffRadiusProperty = PreyGlobal<ArkPsiBlastProperties::ArkFalloffRadiusProperty>(0x2D5AC38);
#endif
	float m_FalloffRadius;
#ifndef MOONCRASH
	static inline auto s_ArkDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDelaySecProperty>(0x2BE0B18);
#else
	static inline auto s_ArkDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDelaySecProperty>(0x2D5AC58);
#endif
	float m_DelaySec;
#ifndef MOONCRASH
	static inline auto s_ArkExplosionDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionDelaySecProperty>(0x2BE0B38);
#else
	static inline auto s_ArkExplosionDelaySecProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionDelaySecProperty>(0x2D5AC78);
#endif
	float m_ExplosionDelaySec;
#ifndef MOONCRASH
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDurationSecProperty>(0x2BE0B58);
#else
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkDurationSecProperty>(0x2D5AC98);
#endif
	float m_DurationSec;
#ifndef MOONCRASH
	static inline auto s_ArkUpdateIntervalSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkUpdateIntervalSecProperty>(0x2BE0B78);
#else
	static inline auto s_ArkUpdateIntervalSecProperty = PreyGlobal<ArkPsiBlastProperties::ArkUpdateIntervalSecProperty>(0x2D5ACB8);
#endif
	float m_UpdateIntervalSec;
#ifndef MOONCRASH
	static inline auto s_ArkMaxBlastCountProperty = PreyGlobal<ArkPsiBlastProperties::ArkMaxBlastCountProperty>(0x2BE0B98);
#else
	static inline auto s_ArkMaxBlastCountProperty = PreyGlobal<ArkPsiBlastProperties::ArkMaxBlastCountProperty>(0x2D5ACD8);
#endif
	int m_MaxBlastCount;
#ifndef MOONCRASH
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkSignalPackageIdProperty>(0x2BE0BB8);
#else
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkSignalPackageIdProperty>(0x2D5ACF8);
#endif
	uint64_t m_SignalPackageId;
#ifndef MOONCRASH
	static inline auto s_ArkExplosionSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty>(0x2BE0BD8);
#else
	static inline auto s_ArkExplosionSignalPackageIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty>(0x2D5AD18);
#endif
	uint64_t m_ExplosionSignalPackageId;
#ifndef MOONCRASH
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkNoiseIdProperty>(0x2BE0BF8);
#else
	static inline auto s_ArkNoiseIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkNoiseIdProperty>(0x2D5AD38);
#endif
	uint64_t m_NoiseId;
#ifndef MOONCRASH
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkLoudnessIdProperty>(0x2BE0C18);
#else
	static inline auto s_ArkLoudnessIdProperty = PreyGlobal<ArkPsiBlastProperties::ArkLoudnessIdProperty>(0x2D5AD58);
#endif
	uint64_t m_LoudnessId;
#ifndef MOONCRASH
	static inline auto s_ArkPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty>(0x2BE0C38);
#else
	static inline auto s_ArkPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty>(0x2D5AD78);
#endif
	string m_PreExplosionParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkKillPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty>(0x2BE0C58);
#else
	static inline auto s_ArkKillPreExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty>(0x2D5AD98);
#endif
	bool m_KillPreExplosionParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionParticleEffectProperty>(0x2BE0C78);
#else
	static inline auto s_ArkExplosionParticleEffectProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionParticleEffectProperty>(0x2D5ADB8);
#endif
	string m_ExplosionParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkStartDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty>(0x2BE0C98);
#else
	static inline auto s_ArkStartDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty>(0x2D5ADD8);
#endif
	string m_StartDelayAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkStopDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty>(0x2BE0CB8);
#else
	static inline auto s_ArkStopDelayAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty>(0x2D5ADF8);
#endif
	string m_StopDelayAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkExplosionAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty>(0x2BE0CD8);
#else
	static inline auto s_ArkExplosionAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty>(0x2D5AE18);
#endif
	string m_ExplosionAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkStartPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty>(0x2BE0CF8);
#else
	static inline auto s_ArkStartPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty>(0x2D5AE38);
#endif
	string m_StartPersistentAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkStopPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty>(0x2BE0D18);
#else
	static inline auto s_ArkStopPersistentAudioTriggerProperty = PreyGlobal<ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty>(0x2D5AE58);
#endif
	string m_StopPersistentAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkCameraShakeProperty = PreyGlobal<ArkPsiBlastProperties::ArkCameraShakeProperty>(0x2BE0D38);
#else
	static inline auto s_ArkCameraShakeProperty = PreyGlobal<ArkPsiBlastProperties::ArkCameraShakeProperty>(0x2D5AE78);
#endif
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

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15811D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13D4DE0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16A9600);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14E0D10);
#endif
};

// CArkPsiBlastProperties<TData> (Size=128 for every instantiation)
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
	CArkPsiBlastProperties();
	const TData& GetData() const;
	const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
#endif
};
