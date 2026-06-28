// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPsiPowerMimicClipEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkpsipowermimicclipevent.h
class CArkPsiPowerMimicMorphInObjectClipEvent : public TProceduralClip<CArkPsiPowerMimicClipEventParams> // Id=80194D7 Size=48
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkPsiPowerMimicClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);
	virtual ~CArkPsiPowerMimicMorphInObjectClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _blendTime, float _duration, CArkPsiPowerMimicClipEventParams const &_params)>(0x11ABCE0);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent *const _this, float _timePassed)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralClip.h>

struct CArkPsiPowerMimicClipEventParams;

// CArkPsiPowerMimicMorphInObjectClipEvent
// Header:  Prey/GameDll/ark/arkpsipowermimicclipevent.h
class CArkPsiPowerMimicMorphInObjectClipEvent : public TProceduralClip<CArkPsiPowerMimicClipEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkPsiPowerMimicClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

#if 0
	CArkPsiPowerMimicMorphInObjectClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _blendTime, float _duration, const CArkPsiPowerMimicClipEventParams& _params)>(0x1226F80);
	static inline auto FOnExit = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimicMorphInObjectClipEvent* const _this, float _timePassed)>(0x1333E90);
};
#endif // !MOONCRASH
