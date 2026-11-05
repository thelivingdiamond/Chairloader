// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>

namespace
{
// `anonymous namespace'::Params (defined in ArkProcClipCorpsePose.cpp in the game)
struct Params : public IProceduralParams
{ // Size=16 (0x10)
	string poseName;

	virtual void Serialize(Serialization::IArchive& _arg0_);
};
} // namespace

// ArkProcClipCorpsePose
// Header:  Prey/GameDll/ark/npc/anim/ArkProcClipCorpsePose.h
class ArkProcClipCorpsePose : public TProceduralClip<Params>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const Params& _params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#ifndef MOONCRASH
	static inline auto FOnEnter = PreyFunction<void(ArkProcClipCorpsePose* const _this, float _blendTime, float _duration, const Params& _params)>(0x11EDDC0);
	static inline auto FOnExit = PreyFunction<void(ArkProcClipCorpsePose* const _this, float blendTime)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(ArkProcClipCorpsePose* const _this, float timePassed)>(0xA13080);
#else
	static inline auto FOnEnter = PreyFunction<void(ArkProcClipCorpsePose* const _this, float _blendTime, float _duration, const Params& _params)>(0x127A2A0);
	static inline auto FOnExit = PreyFunction<void(ArkProcClipCorpsePose* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(ArkProcClipCorpsePose* const _this, float timePassed)>(0x1333E90);
#endif
};

