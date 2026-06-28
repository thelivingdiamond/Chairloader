// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>

class ArkPsiPowerTargetingComponent;
struct IEntity;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsiblast.h
template <typename T, typename TProp>
class CArkPsiBlast // Id=801C116 Size=80
{
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	TProp const *m_pProperties;
	bool m_bApplyImpulse;
	
#if 0
	void CArkPsiBlast(CArkPsiBlast *_blast);
	void CArkPsiBlast(Vec3 const &_position, TProp const *_pProperties);
	void ~CArkPsiBlast();
	bool operator==(CArkPsiBlast const &arg0) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float arg0) const;
	Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	bool Update(const float _frameTime);
	void OnEnterArea(IEntity const &arg0);
	CArkPsiBlast::ArkState GetState() const;
	unsigned GetEntityId() const;
	TProp const &GetProperties() const;
	void SetProperties(TProp const *arg0);
	void Serialize(TSerialize arg0);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(std::vector<IEntity *> arg0) const;
	void UpdateEffect(std::vector<IEntity *> arg0) const;
	void UpdateFrame(const float arg0) const;
	void OnEnterAreaDerived(IEntity const &arg0);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#include <_unknown/CArkPsiBlastProperties.h>

class ArkPsiFlareBlastProperties;
class ArkPsiPowerTargetingComponent;
enum class EArkPsiPowers;
struct IEntity;
struct IParticleEffect;

// CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >
{ // Size=80 (0x50)
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >::ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >&& _blast);
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >(const Vec3& _position, const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _pProperties);
	~CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >();
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >();
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >(const CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >& _arg0_);
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >& operator=(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >& operator=(const CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >& _arg0_);
	bool operator==(const CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >::ArkState GetState() const;
	unsigned GetEntityId() const;
	const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>& GetProperties() const;
	void SetProperties(const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif

	static inline auto FCArkPsiBlastLessCArkPsiElectrostaticBurstCommaCArkPsiBlastPropertiesLessArkPsiElectrostaticBurstPropertiesGreater GreaterOv2 = PreyFunction<void(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >* const _this, CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >&& _blast)>(0x16AD7E0);
	static inline auto FCArkPsiBlastLessCArkPsiElectrostaticBurstCommaCArkPsiBlastPropertiesLessArkPsiElectrostaticBurstPropertiesGreater GreaterOv1 = PreyFunction<void(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >* const _this, const Vec3& _position, const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>* _pProperties)>(0x16A8670);
	static inline auto FBitNotCArkPsiBlastLessCArkPsiElectrostaticBurstCommaCArkPsiBlastPropertiesLessArkPsiElectrostaticBurstPropertiesGreater Greater = PreyFunction<void(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >* const _this)>(0x16A81A0);
	static inline auto FUpdate = PreyFunction<bool(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >* const _this, const float _frameTime)>(0x16B52A0);
};

// CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >
{ // Size=80 (0x50)
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >::ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >&& _blast);
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >(const Vec3& _position, const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _pProperties);
	~CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >();
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >();
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >(const CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >& _arg0_);
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >& operator=(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >& operator=(const CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >& _arg0_);
	bool operator==(const CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >::ArkState GetState() const;
	unsigned GetEntityId() const;
	const CArkPsiBlastProperties<ArkPsiFearBlastProperties>& GetProperties() const;
	void SetProperties(const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif

	static inline auto FCArkPsiBlastLessCArkPsiFearBlastCommaCArkPsiBlastPropertiesLessArkPsiFearBlastPropertiesGreater GreaterOv2 = PreyFunction<void(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >* const _this, CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >&& _blast)>(0x16AD7E0);
	static inline auto FCArkPsiBlastLessCArkPsiFearBlastCommaCArkPsiBlastPropertiesLessArkPsiFearBlastPropertiesGreater GreaterOv1 = PreyFunction<void(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >* const _this, const Vec3& _position, const CArkPsiBlastProperties<ArkPsiFearBlastProperties>* _pProperties)>(0x16A8670);
	static inline auto FBitNotCArkPsiBlastLessCArkPsiFearBlastCommaCArkPsiBlastPropertiesLessArkPsiFearBlastPropertiesGreater Greater = PreyFunction<void(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >* const _this)>(0x16A81A0);
	static inline auto FUpdate = PreyFunction<bool(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >* const _this, const float _frameTime)>(0x16B5720);
};

// CArkPsiBlastProperties<ArkPsiFlareBlastProperties>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlastProperties<ArkPsiFlareBlastProperties>
{ // Size=128 (0x80)
public:
	using Data = ArkPsiFlareBlastProperties;

	ArkGameNoise::Params m_noiseParams;
	_smart_ptr<IParticleEffect> m_pPreExplosionParticleEffect;
	ArkFireAndForgetEffect m_explosionParticleEffect;
	ArkAudioTrigger m_onStartDelayAudioTrigger;
	ArkAudioTrigger m_onStopDelayAudioTrigger;
	ArkAudioTrigger m_onExplosionAudioTrigger;
	ArkAudioTrigger m_onStartPersistentAudioTrigger;
	ArkAudioTrigger m_onStopPersistentAudioTrigger;
	const ArkPsiFlareBlastProperties* m_pData;
	const ArkPsiPowerTargetingComponent* m_pTargetingComponent;

	void SetData(const ArkPsiFlareBlastProperties& _data, const ArkPsiPowerTargetingComponent& _targetingComponent) { FSetData(this, _data, _targetingComponent); }

#if 0
	CArkPsiBlastProperties<ArkPsiFlareBlastProperties>();
	const ArkPsiFlareBlastProperties& GetData() const;
	const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
#endif

	static inline auto FSetData = PreyFunction<void(CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* const _this, const ArkPsiFlareBlastProperties& _data, const ArkPsiPowerTargetingComponent& _targetingComponent)>(0x13BB540);
};

// CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >
{ // Size=80 (0x50)
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >::ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >(const Vec3& _position, const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* _pProperties);
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >();
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >(CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >(const CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >& _arg0_);
	~CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >();
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >& operator=(CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >& operator=(const CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >& _arg0_);
	bool operator==(const CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >::ArkState GetState() const;
	unsigned GetEntityId() const;
	const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>& GetProperties() const;
	void SetProperties(const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif

	static inline auto FCArkPsiBlastLessCArkPsiFlareBlastCommaCArkPsiBlastPropertiesLessArkPsiFlareBlastPropertiesGreater GreaterOv1 = PreyFunction<void(CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >* const _this, const Vec3& _position, const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* _pProperties)>(0x13C8860);
	static inline auto FUpdate = PreyFunction<bool(CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >* const _this, const float _frameTime)>(0x13BBBD0);
};

// CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >
{ // Size=80 (0x50)
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >::ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >&& _blast);
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >(const Vec3& _position, const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* _pProperties);
	~CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >();
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >();
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >(const CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >& _arg0_);
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >& operator=(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >& operator=(const CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >& _arg0_);
	bool operator==(const CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >::ArkState GetState() const;
	unsigned GetEntityId() const;
	const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>& GetProperties() const;
	void SetProperties(const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif

	static inline auto FCArkPsiBlastLessCArkPsiKineticBlastCommaCArkPsiBlastPropertiesLessArkPsiKineticBlastPropertiesGreater GreaterOv2 = PreyFunction<void(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >* const _this, CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >&& _blast)>(0x16AD7E0);
	static inline auto FCArkPsiBlastLessCArkPsiKineticBlastCommaCArkPsiBlastPropertiesLessArkPsiKineticBlastPropertiesGreater GreaterOv1 = PreyFunction<void(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >* const _this, const Vec3& _position, const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>* _pProperties)>(0x16A8670);
	static inline auto FBitNotCArkPsiBlastLessCArkPsiKineticBlastCommaCArkPsiBlastPropertiesLessArkPsiKineticBlastPropertiesGreater Greater = PreyFunction<void(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >* const _this)>(0x16A81A0);
	static inline auto FUpdate = PreyFunction<bool(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >* const _this, const float _frameTime)>(0x13B1CA0);
};

// CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
class CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >
{ // Size=80 (0x50)
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >::ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >(const Vec3& _position, const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>* _pProperties);
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }

#if 0
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >();
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >(CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >(const CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >& _arg0_);
	~CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >();
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >& operator=(CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >&& _arg0_);
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >& operator=(const CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >& _arg0_);
	bool operator==(const CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >::ArkState GetState() const;
	unsigned GetEntityId() const;
	const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>& GetProperties() const;
	void SetProperties(const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif

	static inline auto FCArkPsiBlastLessCArkPsiThermalBlastCommaCArkPsiBlastPropertiesLessArkPsiThermalBlastPropertiesGreater GreaterOv1 = PreyFunction<void(CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >* const _this, const Vec3& _position, const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>* _pProperties)>(0x16A8670);
	static inline auto FUpdate = PreyFunction<bool(CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >* const _this, const float _frameTime)>(0x15861B0);
};
#endif // !MOONCRASH
