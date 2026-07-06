// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralClip.h>

struct CArkPlayerCameraLockEventParams;

// CArkPlayerCameraLockClipEvent
// Header:  Prey/GameDll/ark/ArkPlayerCameraLockClipEvent.h
class CArkPlayerCameraLockClipEvent : public TProceduralClip<CArkPlayerCameraLockEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float blendTime, float duration, const CArkPlayerCameraLockEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CArkPlayerCameraLockClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float blendTime, float duration, const CArkPlayerCameraLockEventParams& params)>(0x12F43F0);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float blendTime)>(0x12F4410);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float timePassed)>(0x1333E90);
};
#endif // !MOONCRASH
