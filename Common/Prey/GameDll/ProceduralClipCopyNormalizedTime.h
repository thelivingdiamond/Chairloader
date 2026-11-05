// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequinDefs.h>
#include <Prey/CryAction/ICryMannequin.h>

class IScope;
struct SProceduralParamsCopyNormalizedTime;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SProceduralParamsCopyNormalizedTime
// Header:  Prey/GameDll/ProceduralClipCopyNormalizedTime.h
struct SProceduralParamsCopyNormalizedTime : public IProceduralParams
{ // Size=24 (0x18)
	float sourceLayer;
	float layer;
	SCRCRef<0,SCRCRefHash_CRC32Lowercase> sourceScope;

	virtual void Serialize(Serialization::IArchive& ar);

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SProceduralParamsCopyNormalizedTime* const _this, Serialization::IArchive& ar)>(0x17CC350);
#else
	static inline auto FSerialize = PreyFunction<void(SProceduralParamsCopyNormalizedTime* const _this, Serialization::IArchive& ar)>(0x18F3210);
#endif
};

// CProceduralClipCopyNormalizedTime
// Header:  Prey/GameDll/ProceduralClipCopyNormalizedTime.h
class CProceduralClipCopyNormalizedTime : public TProceduralClip<SProceduralParamsCopyNormalizedTime>
{ // Size=72 (0x48)
public:
	int m_sourceLayer;
	int m_targetLayer;

	virtual void OnEnter(float blendTime, float duration, const SProceduralParamsCopyNormalizedTime& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CProceduralClipCopyNormalizedTime();
	bool IsSetupValid() const;
	const IScope* GetSourceScope(const SCRCRef<0,SCRCRefHash_CRC32Lowercase>& _arg0_) const;
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float blendTime, float duration, const SProceduralParamsCopyNormalizedTime& params)>(0x17CC450);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float blendTime)>(0x17CC670);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float timePassed)>(0x17CC700);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float blendTime, float duration, const SProceduralParamsCopyNormalizedTime& params)>(0x18F3310);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float blendTime)>(0x18F3530);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipCopyNormalizedTime* const _this, float timePassed)>(0x18F35C0);
#endif
};

