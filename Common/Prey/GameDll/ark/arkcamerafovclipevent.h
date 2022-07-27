// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/ark/arkcamerafovclipevent.h
struct CArkCameraFOVClipEventParams : public IProceduralParams // Id=8018FD0 Size=16
{
	float m_desiredHFOV;
	float m_restoreHFOVDurationSec;
	
	virtual ~CArkCameraFOVClipEventParams();
	virtual void Serialize(Serialization::IArchive &_ar);
	
	static inline auto FSerialize = PreyFunction<void(CArkCameraFOVClipEventParams *const _this, Serialization::IArchive &_ar)>(0x114C500);
};

// Header: FromCpp
// Prey/GameDll/ark/arkcamerafovclipevent.h
class CArkCameraFOVClipEvent : public TProceduralClip<CArkCameraFOVClipEventParams> // Id=8018FD1 Size=80
{
public:
	CArkCameraFOVClipEventParams m_params;
	int m_zoomHandle;
	
	virtual void OnEnter(float _blendTime, float _duration, CArkCameraFOVClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _frameTime);
	virtual ~CArkCameraFOVClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkCameraFOVClipEvent *const _this, float _blendTime, float _duration, CArkCameraFOVClipEventParams const &_params)>(0x114C3A0);
	static inline auto FOnExit = PreyFunction<void(CArkCameraFOVClipEvent *const _this, float _blendTime)>(0x114C410);
	static inline auto FUpdate = PreyFunction<void(CArkCameraFOVClipEvent *const _this, float _frameTime)>(0xA13080);
};

