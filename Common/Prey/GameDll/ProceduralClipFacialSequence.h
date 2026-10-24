// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryString/CryName.h>

struct IFacialAnimSequence;
struct SProceduralClipFacialSequenceParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// SProceduralClipFacialSequenceParams
// Header:  Prey/GameDll/ProceduralClipFacialSequence.h
struct SProceduralClipFacialSequenceParams : public IProceduralParams
{ // Size=24 (0x18)
	bool continueAfterExit;
	bool looping;
	CCryName fileName;

	virtual void Serialize(Serialization::IArchive& ar);

#if 0
	SProceduralClipFacialSequenceParams();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SProceduralClipFacialSequenceParams* const _this, Serialization::IArchive& ar)>(0x17CC9F0);
#else
	static inline auto FSerialize = PreyFunction<void(SProceduralClipFacialSequenceParams* const _this, Serialization::IArchive& ar)>(0x18F38B0);
#endif
};

// CProceduralClipFacialSequence
// Header:  Prey/GameDll/ProceduralClipFacialSequence.h
class CProceduralClipFacialSequence : public TProceduralClip<SProceduralClipFacialSequenceParams>
{ // Size=80 (0x50)
public:
	_smart_ptr<IFacialAnimSequence> m_pCurrentSequence;
	float m_seekTime;
	bool m_waiting;
	bool m_loop;
	bool m_stopAtExit;

	virtual void OnEnter(float blendTime, float duration, const SProceduralClipFacialSequenceParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);
	void PlaySequenceIfNotStarted() { FPlaySequenceIfNotStarted(this); }

#if 0
	CProceduralClipFacialSequence();
#endif

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipFacialSequence* const _this, float blendTime, float duration, const SProceduralClipFacialSequenceParams& params)>(0x17CCB80);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipFacialSequence* const _this, float blendTime)>(0x17CCC80);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipFacialSequence* const _this, float timePassed)>(0x17CCD00);
	static inline auto FPlaySequenceIfNotStarted = PreyFunction<void(CProceduralClipFacialSequence* const _this)>(0x17CCF60);
#else
	static inline auto FOnEnter = PreyFunction<void(CProceduralClipFacialSequence* const _this, float blendTime, float duration, const SProceduralClipFacialSequenceParams& params)>(0x18F39E0);
	static inline auto FOnExit = PreyFunction<void(CProceduralClipFacialSequence* const _this, float blendTime)>(0x18F3AE0);
	static inline auto FUpdate = PreyFunction<void(CProceduralClipFacialSequence* const _this, float timePassed)>(0x18F3B60);
	static inline auto FPlaySequenceIfNotStarted = PreyFunction<void(CProceduralClipFacialSequence* const _this)>(0x18F3DC0);
#endif
};

