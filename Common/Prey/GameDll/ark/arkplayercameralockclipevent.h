// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

struct CArkPlayerCameraLockEventParams;

// Header: FromCpp
// Prey/GameDll/ark/arkplayercameralockclipevent.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
// CArkPlayerCameraLockEventParams
// Header:  _unknown/CArkPlayerCameraLockEventParams.h
struct CArkPlayerCameraLockEventParams : public IProceduralParams
{ // Size=8 (0x8)
	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	CArkPlayerCameraLockEventParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(CArkPlayerCameraLockEventParams* const _this, Serialization::IArchive& ar)>(0xA13080);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const CArkPlayerCameraLockEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0xA13080);
#else
	static inline auto FSerialize = PreyFunction<void(CArkPlayerCameraLockEventParams* const _this, Serialization::IArchive& ar)>(0x1333E90);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const CArkPlayerCameraLockEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
#endif
};

class CArkPlayerCameraLockClipEvent : public TProceduralClip<CArkPlayerCameraLockEventParams> // Id=801A890 Size=48
{
public:
	virtual void OnEnter(float blendTime, float duration, CArkPlayerCameraLockEventParams const &params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	virtual ~CArkPlayerCameraLockClipEvent();
	
#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float blendTime, float duration, CArkPlayerCameraLockEventParams const &params)>(0x124FE60);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float blendTime)>(0x124FE80);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerCameraLockClipEvent *const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float blendTime, float duration, const CArkPlayerCameraLockEventParams& params)>(0x12F43F0);
	static inline auto FOnExit = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float blendTime)>(0x12F4410);
	static inline auto FUpdate = PreyFunction<void(CArkPlayerCameraLockClipEvent* const _this, float timePassed)>(0x1333E90);
#endif
};
