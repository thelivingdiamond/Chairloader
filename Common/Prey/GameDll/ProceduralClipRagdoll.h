// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TProceduralContextualClip.h>

struct SRagdollParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CProceduralClipRagdoll
// Header:  Prey/GameDll/ProceduralClipRagdoll.h
class CProceduralClipRagdoll : public TProceduralContextualClip<CProceduralContextRagdoll,SRagdollParams>
{ // Size=80 (0x50)
public:
	float m_stiffness;
	float m_randomTriggerTime;
	float m_totalTimePassed;
	bool m_ragdollSleep;

	virtual void OnEnter(float blendTime, float duration, const SRagdollParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);

#if 0
	CProceduralClipRagdoll();
#endif

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipRagdoll* const _this, float blendTime, float duration, const SRagdollParams& params)>(0x18F4340);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipRagdoll* const _this, float timePassed)>(0x18F4390);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipRagdoll* const _this, float blendTime)>(0x18F43E0);
};

// SRagdollParams
// Header:  Prey/GameDll/ProceduralClipRagdoll.h
struct SRagdollParams : public IProceduralParams
{ // Size=16 (0x10)
	float sleep;
	float stiffness;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SRagdollParams* const _this, Serialization::IArchive& ar)>(0x18F42D0);
};
#endif // MOONCRASH
