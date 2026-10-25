// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ProceduralContextColliderMode.h>
#include <Prey/CryAction/ICryMannequinDefs.h>
#include <Prey/CryAction/ICryMannequin.h>

struct SColliderModeParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SColliderModeParams
// Header:  Prey/GameDll/ProceduralClipColliderMode.h
struct SColliderModeParams : public IProceduralParams
{ // Size=16 (0x10)
	SCRCRef<0,SCRCRefHash_CRC32Lowercase> mode;

	virtual void Serialize(Serialization::IArchive& ar);

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SColliderModeParams* const _this, Serialization::IArchive& ar)>(0x17CBBC0);
#else
	static inline auto FSerialize = PreyFunction<void(SColliderModeParams* const _this, Serialization::IArchive& ar)>(0x18F2A80);
#endif
};

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

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime, float duration, const SColliderModeParams& params)>(0x17CBC90);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime)>(0x17CBCC0);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipColliderMode* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime, float duration, const SColliderModeParams& params)>(0x18F2B50);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipColliderMode* const _this, float blendTime)>(0x18F2B80);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipColliderMode* const _this, float timePassed)>(0x1333E90);
#endif
};

