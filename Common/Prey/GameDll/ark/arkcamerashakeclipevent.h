// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/ark/arkcamerashakeclipevent.h
struct CArkCameraShakeClipEventParams : public IProceduralParams // Id=8018FD6 Size=16
{
	uint64_t m_cameraShakeId;
	
	virtual ~CArkCameraShakeClipEventParams();
	virtual void Serialize(Serialization::IArchive &_ar);
	
	static inline auto FSerialize = PreyFunction<void(CArkCameraShakeClipEventParams *const _this, Serialization::IArchive &_ar)>(0x114C6F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkcamerashakeclipevent.h
class CArkCameraShakeClipEvent : public TProceduralClip<CArkCameraShakeClipEventParams> // Id=8018FD7 Size=56
{
public:
	virtual void OnEnter(float _blendTime, float _duration, CArkCameraShakeClipEventParams const &_params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _frameTime);
	virtual ~CArkCameraShakeClipEvent();
	
	static inline auto FOnEnter = PreyFunction<void(CArkCameraShakeClipEvent *const _this, float _blendTime, float _duration, CArkCameraShakeClipEventParams const &_params)>(0x114C900);
	static inline auto FOnExit = PreyFunction<void(CArkCameraShakeClipEvent *const _this, float _blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkCameraShakeClipEvent *const _this, float _frameTime)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TProceduralClip.h>

struct CArkCameraShakeClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkCameraShakeClipEvent
// Header:  Prey/GameDll/ark/ArkCameraShakeClipEvent.h
class CArkCameraShakeClipEvent : public TProceduralClip<CArkCameraShakeClipEventParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const CArkCameraShakeClipEventParams& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _frameTime);

#if 0
	CArkCameraShakeClipEvent();
#endif

	static inline auto FOnEnter = PreyFunction<void(CArkCameraShakeClipEvent* const _this, float _blendTime, float _duration, const CArkCameraShakeClipEventParams& _params)>(0x1193A60);
	static inline auto FOnExit = PreyFunction<void(CArkCameraShakeClipEvent* const _this, float _blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkCameraShakeClipEvent* const _this, float _frameTime)>(0x1333E90);
};

// CArkCameraShakeClipEventParams
// Header:  Prey/GameDll/ark/ArkCameraShakeClipEvent.h
struct CArkCameraShakeClipEventParams : public IProceduralParams
{ // Size=16 (0x10)
	uint64_t m_cameraShakeId;

	virtual ~CArkCameraShakeClipEventParams();
	virtual void Serialize(Serialization::IArchive& _ar);

#if 0
	CArkCameraShakeClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(CArkCameraShakeClipEventParams* const _this, Serialization::IArchive& _ar)>(0x1193810);
};
#endif // !MOONCRASH
