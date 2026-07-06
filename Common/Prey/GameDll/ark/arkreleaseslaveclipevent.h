// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct SArkReleaseSlaveClipEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkreleaseslaveclipevent.h
class CArkReleaseSlaveProceduralClipEvent : public TProceduralClip<SArkReleaseSlaveClipEventParams> // Id=801950D Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, SArkReleaseSlaveClipEventParams const &_params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	virtual ~CArkReleaseSlaveProceduralClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime, float duration, SArkReleaseSlaveClipEventParams const &_params)>(0x11AD8E0);
	static inline auto FOnExit = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float timePassed)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TProceduralClip.h>

struct SArkReleaseSlaveClipEventParams;

// CArkReleaseSlaveProceduralClipEvent
// Header:  Prey/GameDll/ark/arkreleaseslaveclipevent.h
class CArkReleaseSlaveProceduralClipEvent : public TProceduralClip<SArkReleaseSlaveClipEventParams>
{ // Size=48 (0x30)
public:
	virtual void OnEnter(float blendTime, float duration, const SArkReleaseSlaveClipEventParams& _params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CArkReleaseSlaveProceduralClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float blendTime, float duration, const SArkReleaseSlaveClipEventParams& _params)>(0x122AF40);
	static inline auto FOnExit = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float timePassed)>(0x1333E90);
};
#endif // !MOONCRASH
