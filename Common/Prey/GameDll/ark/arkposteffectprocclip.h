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

