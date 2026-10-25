// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct SArkReleaseSlaveClipEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkreleaseslaveclipevent.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
// SArkReleaseSlaveClipEventParams
// Header:  _unknown/SArkReleaseSlaveClipEventParams.h
struct SArkReleaseSlaveClipEventParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkReleaseSlaveClipEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SArkReleaseSlaveClipEventParams* const _this, Serialization::IArchive& ar)>(0xA13080);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkReleaseSlaveClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(SArkReleaseSlaveClipEventParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkReleaseSlaveClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

class CArkReleaseSlaveProceduralClipEvent : public TProceduralClip<SArkReleaseSlaveClipEventParams> // Id=801950D Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, SArkReleaseSlaveClipEventParams const &_params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	virtual ~CArkReleaseSlaveProceduralClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime, float duration, SArkReleaseSlaveClipEventParams const &_params)>(0x11AD8E0);
	static inline auto FOnExit = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent *const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float blendTime, float duration, const SArkReleaseSlaveClipEventParams& _params)>(0x122AF40);
	static inline auto FOnExit = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkReleaseSlaveProceduralClipEvent* const _this, float timePassed)>(0x1333E90);
#endif
};
