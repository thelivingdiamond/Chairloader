// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <_unknown/IProceduralParams.h>
#include <_unknown/TProceduralClip.h>

struct SArkNpcSpawnRockClipEventParams;
namespace Serialization
{
class IArchive;
} // namespace Serialization

// CArkNpcSpawnRockProceduralClipEvent
// Header:  Prey/GameDll/ark/npc/anim/arknpcspawnrockclipevent.h
class CArkNpcSpawnRockProceduralClipEvent : public TProceduralClip<SArkNpcSpawnRockClipEventParams>
{ // Size=56 (0x38)
public:
	static unsigned GetStartCRC() { return FGetStartCRC(); }
	virtual void OnEnter(float blendTime, float duration, const SArkNpcSpawnRockClipEventParams& params);
	virtual void OnExit(float blendTime);
	virtual void Update(float timePassed);

#if 0
	CArkNpcSpawnRockProceduralClipEvent();
	static unsigned GetStopCRC();
#endif

	static inline auto FGetStartCRC = PreyFunction<unsigned()>(0x1279F00);
	static inline auto FOnEnter = PreyFunction<void(CArkNpcSpawnRockProceduralClipEvent* const _this, float blendTime, float duration, const SArkNpcSpawnRockClipEventParams& params)>(0x127A010);
	static inline auto FOnExit = PreyFunction<void(CArkNpcSpawnRockProceduralClipEvent* const _this, float blendTime)>(0x127A100);
	static inline auto FUpdate = PreyFunction<void(CArkNpcSpawnRockProceduralClipEvent* const _this, float timePassed)>(0x1333E90);
};

// SArkNpcSpawnRockClipEventParams
// Header:  Prey/GameDll/ark/npc/anim/arknpcspawnrockclipevent.h
struct SArkNpcSpawnRockClipEventParams : public IProceduralParams
{ // Size=16 (0x10)
	string m_attachmentName;

	virtual void Serialize(Serialization::IArchive& ar);
	virtual void GetExtraDebugInfo(IProceduralParams::StringWrapperImpl<char>& extraInfoOut) const;

#if 0
	SArkNpcSpawnRockClipEventParams();
#endif

	static inline auto FSerialize = PreyFunction<void(SArkNpcSpawnRockClipEventParams* const _this, Serialization::IArchive& ar)>(0x127A1D0);
	static inline auto FGetExtraDebugInfo = PreyFunction<void(const SArkNpcSpawnRockClipEventParams* const _this, IProceduralParams::StringWrapperImpl<char>& extraInfoOut)>(0x1333E90);
};
#endif // MOONCRASH
