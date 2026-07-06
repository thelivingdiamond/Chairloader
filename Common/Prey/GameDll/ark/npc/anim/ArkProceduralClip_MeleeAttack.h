// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/TProceduralClip.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// ArkProceduralClipParams_MeleeAttack
// Header:  Prey/GameDll/ark/npc/anim/ArkProceduralClip_MeleeAttack.h
struct ArkProceduralClipParams_MeleeAttack : public IProceduralParams
{ // Size=24 (0x18)
	string m_attachmentName;
	float m_attachmentRadius;

	virtual void Serialize(Serialization::IArchive& _archive);

#if 0
	ArkProceduralClipParams_MeleeAttack();
#endif

	static inline auto FSerialize = PreyFunction<void(ArkProceduralClipParams_MeleeAttack* const _this, Serialization::IArchive& _archive)>(0x127A9B0);
};

// ArkProceduralClip_MeleeAttack
// Header:  Prey/GameDll/ark/npc/anim/ArkProceduralClip_MeleeAttack.h
class ArkProceduralClip_MeleeAttack : public TProceduralClip<ArkProceduralClipParams_MeleeAttack>
{ // Size=64 (0x40)
public:
	static unsigned GetCrc() { return FGetCrc(); }
	virtual void OnEnter(float _blendTime, float _duration, const ArkProceduralClipParams_MeleeAttack& _params);
	virtual void OnExit(float _blendTime);
	virtual void Update(float _timePassed);

	static inline auto FGetCrc = PreyFunction<unsigned()>(0x127A940);
	static inline auto FOnEnter = PreyFunction<void(ArkProceduralClip_MeleeAttack* const _this, float _blendTime, float _duration, const ArkProceduralClipParams_MeleeAttack& _params)>(0x127A620);
	static inline auto FOnExit = PreyFunction<void(ArkProceduralClip_MeleeAttack* const _this, float _blendTime)>(0x127A690);
	static inline auto FUpdate = PreyFunction<void(ArkProceduralClip_MeleeAttack* const _this, float _timePassed)>(0x1333E90);
};
#endif // MOONCRASH
