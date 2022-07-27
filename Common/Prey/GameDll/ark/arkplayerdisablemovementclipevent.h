// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPlayerDisableMovementEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkplayerdisablemovementclipevent.h
class CArkPlayerDisableMovementClipEvent : public TProceduralClip<CArkPlayerDisableMovementEventParams> // Id=801A896 Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, CArkPlayerDisableMovementEventParams const &params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float blendTime, float duration, CArkPlayerDisableMovementEventParams const &params)>(0x12500F0);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float blendTime)>(0x1250160);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float timePassed)>(0xA13080);
};

