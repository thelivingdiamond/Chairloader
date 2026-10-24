// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ProceduralContextAim.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SAimSmoothingParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SAimSmoothingParams
// Header:  Prey/GameDll/ProceduralClipAimSmoothing.h
struct SAimSmoothingParams : public IProceduralParams
{ // Size=24 (0x18)
	float smoothTimeSeconds;
	float maxYawDegreesPerSecond;
	float maxPitchDegreesPerSecond;

	virtual void Serialize(Serialization::IArchive& ar);

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SAimSmoothingParams* const _this, Serialization::IArchive& ar)>(0x17CB910);
#else
	static inline auto FSerialize = PreyFunction<void(SAimSmoothingParams* const _this, Serialization::IArchive& ar)>(0x18F27D0);
#endif
};


// CProceduralClipAimSmoothing
// Header:  Prey/GameDll/ProceduralClipAimSmoothing.h
class CProceduralClipAimSmoothing : public TProceduralContextualClip<CProceduralContextAim,SAimSmoothingParams>
{ // Size=80 (0x50)
public:
	unsigned m_requestId;

	virtual void OnEnter(float blendTime, float duration, const SAimSmoothingParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CProceduralClipAimSmoothing();
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float blendTime, float duration, const SAimSmoothingParams& params)>(0x17CB980);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float blendTime)>(0x17CB9D0);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float blendTime, float duration, const SAimSmoothingParams& params)>(0x18F2840);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float blendTime)>(0x18F2890);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipAimSmoothing* const _this, float timePassed)>(0x1333E90);
#endif
};
