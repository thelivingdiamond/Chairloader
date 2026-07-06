// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>
#include <_unknown/TProceduralClip.h>

struct CArkPsiPowerSmokeFormClipEventParams;
struct CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkPsiPowerSmokeFormEnterClipEvent
// Header:  Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormEnterClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkPsiPowerSmokeFormEnterClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B230);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormEnterClipEvent* const _this, float _timePassed)>(0x1333E90);
};

// CArkPsiPowerSmokeFormExitClipEvent
// Header:  Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeFormExitClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkPsiPowerSmokeFormExitClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B280);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeFormExitClipEvent* const _this, float _timePassed)>(0x1333E90);
};

// CArkPsiPowerSmokeStartActiveParticleEffectClipEvent
// Header:  Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStartActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkPsiPowerSmokeStartActiveParticleEffectClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams& _params)>(0x122B390);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
};

// CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams
// Header:  Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
struct CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams : public IProceduralParams
{ // Size=16 (0x10)
	CCryName m_effectName;

	virtual void Serialize(Serialization::IArchive& _ar);

#if 0
	CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerSmokeStartActiveParticleEffectClipEventParams* const _this, Serialization::IArchive& _ar)>(0x122B2D0);
};

// CArkPsiPowerSmokeStopActiveParticleEffectClipEvent
// Header:  Prey/GameDll/ark/arkpsipowersmokeformclipevent.h
class CArkPsiPowerSmokeStopActiveParticleEffectClipEvent : public TProceduralClip<CArkPsiPowerSmokeFormClipEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkPsiPowerSmokeStopActiveParticleEffectClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerSmokeFormClipEventParams& _params)>(0x122B3F0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerSmokeStopActiveParticleEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
};
#endif // !MOONCRASH
