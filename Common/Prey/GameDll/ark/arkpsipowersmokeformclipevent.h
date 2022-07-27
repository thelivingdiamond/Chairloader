// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>

struct CArkPsiPowerSmokeFormClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormEnterClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=8019537 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeFormEnterClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADBD0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent *const _this, float _timePassed)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormExitClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=8019539 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeFormExitClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADC20);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent *const _this, float _timePassed)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
struct CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams : public IProceduralParams // Id=801953A Size=16
{
	CCryName m_effectName;
	
	virtual void Serialize(Serialization::IArchive &_ar);
	virtual ~CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams();
	
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams *const _this, Serialization::IArchive &_ar)>(0x11ADC70);
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStartActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams> // Id=801953B Size=56
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeStartActiveParticleEffectClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams const &_params)>(0x11ADCB0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent *const _this, float _timePassed)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStopActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams> // Id=801953D Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerSmokeStopActiveParticleEffectClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerSmokeFormClipEventParams const &_params)>(0x11ADD50);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent *const _this, float _timePassed)>(0xA13080);
};

