// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/SCRCRef.h>
#include <_unknown/TProceduralContextualClip.h>

struct SColliderModeParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CProceduralClipColliderMode
// Header:  Prey/GameDll/ProceduralClipColliderMode.h
class CProceduralClipColliderMode : public TProceduralContextualClip<CProceduralContextColliderMode,SColliderModeParams>
{ // Size=72 (0x48)
public:
	unsigned m_requestId;

	virtual void OnEnter(float blendTime, float duration, const SColliderModeParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CProceduralClipColliderMode();
#endif

	static inline auto FOnEnter = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime, float duration, const SColliderModeParams& params)>(0x18F2B50);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime)>(0x18F2B80);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipColliderMode* const _this, float timePassed)>(0x1333E90);
};

// SColliderModeParams
// Header:  Prey/GameDll/ProceduralClipColliderMode.h
struct SColliderModeParams : public IProceduralParams
{ // Size=16 (0x10)
	SCRCRef<0,SCRCRefHash_CRC32Lowercase> mode;

	virtual void Serialize(Serialization::IArchive& ar);

	static inline auto FSerialize = PreyFunction<void(SColliderModeParams* const _this, Serialization::IArchive& ar)>(0x18F2A80);
};
#endif // MOONCRASH
