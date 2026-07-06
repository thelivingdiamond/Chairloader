// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/ark/arkposteffectprocclip.h
struct CArkPostEffectClipEventParams : public IProceduralParams // Id=8019443 Size=16
{
	uint64_t m_postEffectId;
	
	virtual void Serialize(Serialization::IArchive &_ar);
	virtual ~CArkPostEffectClipEventParams();
	
	static inline auto FSerialize = PreyFunction<void(CArkPostEffectClipEventParams *const _this, Serialization::IArchive &_ar)>(0x11AB7F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkposteffectprocclip.h
class CArkEnablePostEffectClipEvent : public TProceduralClip<CArkPostEffectClipEventParams> // Id=8019444 Size=56
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPostEffectClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkEnablePostEffectClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkEnablePostEffectClipEvent *const _this, float _blendTime, float _duration, CArkPostEffectClipEventParams const &_params)>(0x11AB730);
	static inline auto FOnExit = PreyFunction<void(CArkEnablePostEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkEnablePostEffectClipEvent *const _this, float _timePassed)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/arkposteffectprocclip.h
class CArkDisablePostEffectClipEvent : public TProceduralClip<CArkPostEffectClipEventParams> // Id=8019446 Size=56
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPostEffectClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkDisablePostEffectClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkDisablePostEffectClipEvent *const _this, float _blendTime, float _duration, CArkPostEffectClipEventParams const &_params)>(0x11AB750);
	static inline auto FOnExit = PreyFunction<void(CArkDisablePostEffectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkDisablePostEffectClipEvent *const _this, float _timePassed)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TProceduralClip.h>

struct CArkPostEffectClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkDisablePostEffectClipEvent
// Header:  Prey/GameDll/ark/arkposteffectprocclip.h
class CArkDisablePostEffectClipEvent : public TProceduralClip<CArkPostEffectClipEventParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPostEffectClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkDisablePostEffectClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkDisablePostEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPostEffectClipEventParams& _params)>(0x1226BF0);
	static inline auto FOnExit = PreyFunction<void(CArkDisablePostEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkDisablePostEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
};

// CArkEnablePostEffectClipEvent
// Header:  Prey/GameDll/ark/arkposteffectprocclip.h
class CArkEnablePostEffectClipEvent : public TProceduralClip<CArkPostEffectClipEventParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPostEffectClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkEnablePostEffectClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkEnablePostEffectClipEvent* const _this, float _blendTime, float _duration, const CArkPostEffectClipEventParams& _params)>(0x1226BD0);
	static inline auto FOnExit = PreyFunction<void(CArkEnablePostEffectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkEnablePostEffectClipEvent* const _this, float _timePassed)>(0x1333E90);
};

// CArkPostEffectClipEventParams
// Header:  Prey/GameDll/ark/arkposteffectprocclip.h
struct CArkPostEffectClipEventParams : public IProceduralParams
{ // Size=16 (0x10)
	uint64_t m_postEffectId;

	virtual void Serialize(Serialization::IArchive& _ar);

#if 0
	CArkPostEffectClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(CArkPostEffectClipEventParams* const _this, Serialization::IArchive& _ar)>(0x12269A0);
};
#endif // !MOONCRASH
