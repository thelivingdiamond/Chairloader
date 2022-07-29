// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkPsiBlastProperties.h
class ArkPsiBlastProperties : public ArkReflectedObject // Id=801BDD8 Size=144
{
public:
	class ArkRadiusProperty : public ArkProperty // Id=801BDD9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiBlastProperties::ArkRadiusProperty s_ArkRadiusProperty;
	float m_Radius;
	
	class ArkTriggerRadiusProperty : public ArkProperty // Id=801BDDA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkTriggerRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkTriggerRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiBlastProperties::ArkTriggerRadiusProperty s_ArkTriggerRadiusProperty;
	float m_TriggerRadius;
	
	class ArkForceProperty : public ArkProperty // Id=801BDDB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkForceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkForceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiBlastProperties::ArkForceProperty s_ArkForceProperty;
	float m_Force;
	
	class ArkFalloffScaleProperty : public ArkProperty // Id=801BDDC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkFalloffScaleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkFalloffScaleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkPsiBlastProperties::ArkFalloffScaleProperty s_ArkFalloffScaleProperty;
	float m_FalloffScale;
	
	class ArkFalloffRadiusProperty : public ArkProperty // Id=801BDDD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkFalloffRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkFalloffRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiBlastProperties::ArkFalloffRadiusProperty s_ArkFalloffRadiusProperty;
	float m_FalloffRadius;
	
	class ArkDelaySecProperty : public ArkProperty // Id=801BDDE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkDelaySecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkDelaySecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiBlastProperties::ArkDelaySecProperty s_ArkDelaySecProperty;
	float m_DelaySec;
	
	class ArkExplosionDelaySecProperty : public ArkProperty // Id=801BDDF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkExplosionDelaySecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkExplosionDelaySecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiBlastProperties::ArkExplosionDelaySecProperty s_ArkExplosionDelaySecProperty;
	float m_ExplosionDelaySec;
	
	class ArkDurationSecProperty : public ArkProperty // Id=801BDE0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkPsiBlastProperties::ArkDurationSecProperty s_ArkDurationSecProperty;
	float m_DurationSec;
	
	class ArkUpdateIntervalSecProperty : public ArkProperty // Id=801BDE1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkUpdateIntervalSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkUpdateIntervalSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiBlastProperties::ArkUpdateIntervalSecProperty s_ArkUpdateIntervalSecProperty;
	float m_UpdateIntervalSec;
	
	class ArkMaxBlastCountProperty : public ArkProperty // Id=801BDE2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkMaxBlastCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkMaxBlastCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328510);
	};

	static ArkPsiBlastProperties::ArkMaxBlastCountProperty s_ArkMaxBlastCountProperty;
	int m_MaxBlastCount;
	
	class ArkSignalPackageIdProperty : public ArkProperty // Id=801BDE3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiBlastProperties::ArkSignalPackageIdProperty s_ArkSignalPackageIdProperty;
	uint64_t m_SignalPackageId;
	
	class ArkExplosionSignalPackageIdProperty : public ArkProperty // Id=801BDE4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiBlastProperties::ArkExplosionSignalPackageIdProperty s_ArkExplosionSignalPackageIdProperty;
	uint64_t m_ExplosionSignalPackageId;
	
	class ArkNoiseIdProperty : public ArkProperty // Id=801BDE5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkNoiseIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiBlastProperties::ArkNoiseIdProperty s_ArkNoiseIdProperty;
	uint64_t m_NoiseId;
	
	class ArkLoudnessIdProperty : public ArkProperty // Id=801BDE6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkLoudnessIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiBlastProperties::ArkLoudnessIdProperty s_ArkLoudnessIdProperty;
	uint64_t m_LoudnessId;
	
	class ArkPreExplosionParticleEffectProperty : public ArkProperty // Id=801BDE7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkPsiBlastProperties::ArkPreExplosionParticleEffectProperty s_ArkPreExplosionParticleEffectProperty;
	string m_PreExplosionParticleEffect;
	
	class ArkKillPreExplosionParticleEffectProperty : public ArkProperty // Id=801BDE8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiBlastProperties::ArkKillPreExplosionParticleEffectProperty s_ArkKillPreExplosionParticleEffectProperty;
	bool m_KillPreExplosionParticleEffect;
	
	class ArkExplosionParticleEffectProperty : public ArkProperty // Id=801BDE9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkExplosionParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkPsiBlastProperties::ArkExplosionParticleEffectProperty s_ArkExplosionParticleEffectProperty;
	string m_ExplosionParticleEffect;
	
	class ArkStartDelayAudioTriggerProperty : public ArkProperty // Id=801BDEA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkPsiBlastProperties::ArkStartDelayAudioTriggerProperty s_ArkStartDelayAudioTriggerProperty;
	string m_StartDelayAudioTrigger;
	
	class ArkStopDelayAudioTriggerProperty : public ArkProperty // Id=801BDEB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkPsiBlastProperties::ArkStopDelayAudioTriggerProperty s_ArkStopDelayAudioTriggerProperty;
	string m_StopDelayAudioTrigger;
	
	class ArkExplosionAudioTriggerProperty : public ArkProperty // Id=801BDEC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkPsiBlastProperties::ArkExplosionAudioTriggerProperty s_ArkExplosionAudioTriggerProperty;
	string m_ExplosionAudioTrigger;
	
	class ArkStartPersistentAudioTriggerProperty : public ArkProperty // Id=801BDED Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D30);
	};

	static ArkPsiBlastProperties::ArkStartPersistentAudioTriggerProperty s_ArkStartPersistentAudioTriggerProperty;
	string m_StartPersistentAudioTrigger;
	
	class ArkStopPersistentAudioTriggerProperty : public ArkProperty // Id=801BDEE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4D40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10617E0);
	};

	static ArkPsiBlastProperties::ArkStopPersistentAudioTriggerProperty s_ArkStopPersistentAudioTriggerProperty;
	string m_StopPersistentAudioTrigger;
	
	class ArkCameraShakeProperty : public ArkProperty // Id=801BDEF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiBlastProperties::ArkCameraShakeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiBlastProperties::ArkCameraShakeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4DB0);
	};

	static ArkPsiBlastProperties::ArkCameraShakeProperty s_ArkCameraShakeProperty;
	uint64_t m_CameraShake;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetRadius(float arg0);
	const float &GetRadius() const;
	void SetTriggerRadius(float arg0);
	const float &GetTriggerRadius() const;
	void SetForce(float arg0);
	const float &GetForce() const;
	void SetFalloffScale(float arg0);
	const float &GetFalloffScale() const;
	void SetFalloffRadius(float arg0);
	const float &GetFalloffRadius() const;
	void SetDelaySec(float arg0);
	const float &GetDelaySec() const;
	void SetExplosionDelaySec(float arg0);
	const float &GetExplosionDelaySec() const;
	void SetDurationSec(float arg0);
	const float &GetDurationSec() const;
	void SetUpdateIntervalSec(float arg0);
	const float &GetUpdateIntervalSec() const;
	void SetMaxBlastCount(int arg0);
	const int &GetMaxBlastCount() const;
	void SetSignalPackageId(uint64_t arg0);
	const uint64_t &GetSignalPackageId() const;
	void SetExplosionSignalPackageId(uint64_t arg0);
	const uint64_t &GetExplosionSignalPackageId() const;
	void SetNoiseId(uint64_t arg0);
	const uint64_t &GetNoiseId() const;
	void SetLoudnessId(uint64_t arg0);
	const uint64_t &GetLoudnessId() const;
	void SetPreExplosionParticleEffect(string arg0);
	string const &GetPreExplosionParticleEffect() const;
	void SetKillPreExplosionParticleEffect(bool arg0);
	const bool &GetKillPreExplosionParticleEffect() const;
	void SetExplosionParticleEffect(string arg0);
	string const &GetExplosionParticleEffect() const;
	void SetStartDelayAudioTrigger(string arg0);
	string const &GetStartDelayAudioTrigger() const;
	void SetStopDelayAudioTrigger(string arg0);
	string const &GetStopDelayAudioTrigger() const;
	void SetExplosionAudioTrigger(string arg0);
	string const &GetExplosionAudioTrigger() const;
	void SetStartPersistentAudioTrigger(string arg0);
	string const &GetStartPersistentAudioTrigger() const;
	void SetStopPersistentAudioTrigger(string arg0);
	string const &GetStopPersistentAudioTrigger() const;
	void SetCameraShake(uint64_t arg0);
	const uint64_t &GetCameraShake() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15811D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x13D4DE0);
};

