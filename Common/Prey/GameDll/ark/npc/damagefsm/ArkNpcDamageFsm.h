// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcDamageFsmBase_template_.h>

class ArkNpc;
enum class EArkNpcDamageStateId;

// ArkNpcDamageFsm
// Header:  Prey/GameDll/ark/npc/damagefsm/ArkNpcDamageFsm.h
class ArkNpcDamageFsm : protected ArkNpcDamageFsmBase_template_<void>
{ // Size=60 (0x3C)
public:
	bool m_bCanBeDisabled;
	bool m_bShouldInstantlyDie;

	ArkNpcDamageFsm();
	void Initiate(ArkNpc& _npc, float _npcInitialHealth) { FInitiate(this, _npc, _npcInitialHealth); }
	void Terminate(ArkNpc& _npc) { FTerminate(this, _npc); }
	EArkNpcDamageStateId GetCurrentStateId() const { return FGetCurrentStateId(this); }
	void SetBroken(ArkNpc& _npc) { FSetBroken(this, _npc); }
	void OnHealthChange(ArkNpc& _npc, float _npcNewHealth, bool _bTakingDamage) { FOnHealthChange(this, _npc, _npcNewHealth, _bTakingDamage); }
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	bool IsDisabled() const { return FIsDisabled(this); }
	bool IsDestroyed() const { return FIsDestroyed(this); }
	void SetShouldInstantlyDie() { FSetShouldInstantlyDie(this); }
	bool ShouldInstantlyDie() { return FShouldInstantlyDie(this); }
	void Serialize(TSerialize _ser, ArkNpc& _npc) { FSerialize(this, _ser, _npc); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }
	void OnReactionComplete(ArkNpc& _npc) { FOnReactionComplete(this, _npc); }

	static inline auto FArkNpcDamageFsmOv2 = PreyFunction<void(ArkNpcDamageFsm* const _this)>(0x12A08B0);
	static inline auto FInitiate = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc, float _npcInitialHealth)>(0x12A08F0);
	static inline auto FTerminate = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc)>(0x12A0E30);
	static inline auto FGetCurrentStateId = PreyFunction<EArkNpcDamageStateId(const ArkNpcDamageFsm* const _this)>(0x12A08E0);
	static inline auto FSetBroken = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc)>(0x12A0DC0);
	static inline auto FOnHealthChange = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc, float _npcNewHealth, bool _bTakingDamage)>(0x12A0AA0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A0ED0);
	static inline auto FIsDisabled = PreyFunction<bool(const ArkNpcDamageFsm* const _this)>(0x143DFE0);
	static inline auto FIsDestroyed = PreyFunction<bool(const ArkNpcDamageFsm* const _this)>(0x12A0A80);
	static inline auto FSetShouldInstantlyDie = PreyFunction<void(ArkNpcDamageFsm* const _this)>(0x12A0E10);
	static inline auto FShouldInstantlyDie = PreyFunction<bool(ArkNpcDamageFsm* const _this)>(0x12A0E20);
	static inline auto FSerialize = PreyFunction<void(ArkNpcDamageFsm* const _this, TSerialize _ser, ArkNpc& _npc)>(0x12A0C90);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc)>(0x12A0BF0);
	static inline auto FOnReactionComplete = PreyFunction<void(ArkNpcDamageFsm* const _this, ArkNpc& _npc)>(0x1333E90);
};
#endif // MOONCRASH
