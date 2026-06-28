// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcAliveFsmBase_template_.h>

class ArkNpc;

// ArkNpcAliveFsm
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveFsm.h
class ArkNpcAliveFsm : public ArkNpcAliveFsmBase_template_<void>
{ // Size=704 (0x2C0)
public:
	const ArkNpc* m_pNpc;

	ArkNpcAliveFsm();
	void SetNpc(const ArkNpc& _npc) { FSetNpc(this, _npc); }
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize() { FPostSerialize(this); }

#if 0
	bool IsBreakable() const;
#endif

	static inline auto FArkNpcAliveFsm = PreyFunction<void(ArkNpcAliveFsm* const _this)>(0x12A5930);
	static inline auto FSetNpc = PreyFunction<void(ArkNpcAliveFsm* const _this, const ArkNpc& _npc)>(0x12A5A50);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAliveFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A5A60);
	static inline auto FSerialize = PreyFunction<void(ArkNpcAliveFsm* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A59D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcAliveFsm* const _this)>(0x12A59B0);
};
#endif // MOONCRASH
