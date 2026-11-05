// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPlayerDisableMovementEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkplayerdisablemovementclipevent.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
// CArkPlayerDisableMovementEventParams
// Header:  _unknown/CArkPlayerDisableMovementEventParams.h
struct CArkPlayerDisableMovementEventParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	CArkPlayerDisableMovementEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkPlayerDisableMovementEventParams* const _this, Serialization::IArchive& ar)>(0xA13080);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const CArkPlayerDisableMovementEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(CArkPlayerDisableMovementEventParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const CArkPlayerDisableMovementEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

class CArkPlayerDisableMovementClipEvent : public TProceduralClip<CArkPlayerDisableMovementEventParams> // Id=801A896 Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, CArkPlayerDisableMovementEventParams const &params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	virtual ~CArkPlayerDisableMovementClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float blendTime, float duration, CArkPlayerDisableMovementEventParams const &params)>(0x12500F0);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float blendTime)>(0x1250160);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerDisableMovementClipEvent *const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerDisableMovementClipEvent* const _this, float blendTime, float duration, const CArkPlayerDisableMovementEventParams& params)>(0x12F4600);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerDisableMovementClipEvent* const _this, float blendTime)>(0x12F4680);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerDisableMovementClipEvent* const _this, float timePassed)>(0x1333E90);
#endif
};
