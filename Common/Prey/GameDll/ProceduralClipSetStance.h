// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SSetStanceParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SSetStanceParams
// Header:  Prey/GameDll/ProceduralClipSetStance.h
struct SSetStanceParams : public IProceduralParams
{ // Size=16 (0x10)
	CCryName stance;

	virtual void Serialize(Serialization::IArchive& ar);

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SSetStanceParams* const _this, Serialization::IArchive& ar)>(0x17CD810);
#else
	static inline auto FSerialize = PreyFunction<void(SSetStanceParams* const _this, Serialization::IArchive& ar)>(0x18F45D0);
#endif
};

// CProceduralClipSetStance
// Header:  Prey/GameDll/ProceduralClipSetStance.h
class CProceduralClipSetStance : public TProceduralClip<SSetStanceParams>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float blendTime, float duration, const SSetStanceParams& params);
	virtual void Update(float timePassed);
	virtual void OnExit(float blendTime);

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime, float duration, const SSetStanceParams& params)>(0x17CD930);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipSetStance* const _this, float timePassed)>(0xA13080);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime, float duration, const SSetStanceParams& params)>(0x18F4610);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipSetStance* const _this, float timePassed)>(0x1333E90);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipSetStance* const _this, float blendTime)>(0x1333E90);
#endif
};

