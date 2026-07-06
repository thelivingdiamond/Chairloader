// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TProceduralContextualClip.h>

struct SProceduralClipMovementControlMethodParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CProceduralClipMovementControlMethod
// Header:  Prey/GameDll/ProceduralClipMovementControlMethod.h
class CProceduralClipMovementControlMethod : public TProceduralContextualClip<CProceduralContextMovementControlMethod,SProceduralClipMovementControlMethodParams>
{ // Size=72 (0x48)
public:
	unsigned m_requestId;

	virtual void OnEnter(float blendTime, float duration, const SProceduralClipMovementControlMethodParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CProceduralClipMovementControlMethod();
#endif

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipMovementControlMethod* const _this, float blendTime, float duration, const SProceduralClipMovementControlMethodParams& params)>(0x18F4080);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipMovementControlMethod* const _this, float blendTime)>(0x18F40E0);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipMovementControlMethod* const _this, float timePassed)>(0x1333E90);
};

// SProceduralClipMovementControlMethodParams
// Header:  Prey/GameDll/ProceduralClipMovementControlMethod.h
struct SProceduralClipMovementControlMethodParams : public IProceduralParams
{ // Size=16 (0x10)
	float horizontal;
	float vertical;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SProceduralClipMovementControlMethodParams* const _this, Serialization::IArchive& ar)>(0x18F3FF0);
};
#endif // MOONCRASH
