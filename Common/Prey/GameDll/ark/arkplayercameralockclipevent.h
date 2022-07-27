// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPlayerCameraLockEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkplayercameralockclipevent.h
class CArkPlayerCameraLockClipEvent : public TProceduralClip<CArkPlayerCameraLockEventParams> // Id=801A890 Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, CArkPlayerCameraLockEventParams const &params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	virtual ~CArkPlayerCameraLockClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float blendTime, float duration, CArkPlayerCameraLockEventParams const &params)>(0x124FE60);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float blendTime)>(0x124FE80);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float timePassed)>(0xA13080);
};

