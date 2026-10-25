// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPsiPowerMimicClipEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowermimicclipevent.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
// CArkPsiPowerMimicClipEventParams
// Header:  _unknown/CArkPsiPowerMimicClipEventParams.h
struct CArkPsiPowerMimicClipEventParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);

#if 0
	CArkPsiPowerMimicClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerMimicClipEventParams* const _this, Serialization::IArchive& ar)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerMimicClipEventParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
#endif
};

class CArkPsiPowerMimicMorphInObjectClipEvent : public TProceduralClip<CArkPsiPowerMimicClipEventParams> // Id=80194D7 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerMimicClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerMimicMorphInObjectClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerMimicClipEventParams const &_params)>(0x11ABCE0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerMimicClipEventParams& _params)>(0x1226F80);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _timePassed)>(0x1333E90);
#endif
};
