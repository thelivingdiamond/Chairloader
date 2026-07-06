// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

namespace `anonymous-namespace'
{
struct Params;
} // namespace `anonymous-namespace'

// ArkProcClipCorpsePose
// Header:  Prey/GameDll/ark/npc/anim/ArkProcClipCorpsePose.h
class ArkProcClipCorpsePose : public TProceduralClip<`anonymous namespace'::Params>
{ // Size=56 (0x38)
public:
	virtual void OnEnter(float _blendTime, float _duration, const `anonymous-namespace'::Params& _params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

	static inline auto FOnEnter = PreyFunction<void(ArkProcClipCorpsePose* const _this, float _blendTime, float _duration, const `anonymous-namespace'::Params& _params)>(0x127A2A0);
	static inline auto FOnExit = PreyFunction<void(ArkProcClipCorpsePose* const _this, float blendTime)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(ArkProcClipCorpsePose* const _this, float timePassed)>(0x1333E90);
};
#endif // MOONCRASH
