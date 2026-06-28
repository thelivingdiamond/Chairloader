// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>
#include <_unknown/TProceduralClip.h>

struct SSetStanceParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CProceduralClipSetStance
// Header:  Prey/GameDll/ProceduralClipSetStance.h
class CProceduralClipSetStance : public TProceduralClip<SSetStanceParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float blendTime, float duration, const SSetStanceParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime, float duration, const SSetStanceParams& params)>(0x18F4610);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipSetStance* const _this, float timePassed)>(0x1333E90);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime)>(0x1333E90);
};

// SSetStanceParams
// Header:  Prey/GameDll/ProceduralClipSetStance.h
struct SSetStanceParams : public IProceduralParams
{ // Size=16 (0x10)
	CCryName stance;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SSetStanceParams* const _this, Serialization::IArchive& ar)>(0x18F45D0);
};
#endif // MOONCRASH
