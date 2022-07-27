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
	
	static inline auto FOnEnter = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime, float duration, SArkReleaseSlaveClipEventParams const &_params)>(0x11AD8E0);
	static inline auto FOnExit = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float timePassed)>(0xA13080);
};

