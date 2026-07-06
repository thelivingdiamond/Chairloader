// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState.h>

class ArkNpc;
struct ArkNpcDamageEnterStateParams;
struct ArkNpcDamageExitStateParams;
struct ArkNpcDamagePostSerializeStateParams;
struct ArkNpcDamageSerializeStateParams;
struct ArkNpcDamageStateParam;
struct ArkNpcDamageUpdateStateParams;

// ArkNpcDamageState_Destroyed
// Header:  Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Destroyed.h
class ArkNpcDamageState_Destroyed : public ArkNpcDamageState
{ // Size=32 (0x20)
public:
	QuatT m_bodyTm;
	float m_explodeDelayTimer;

	ArkNpcDamageState_Destroyed();
	void Enter(const ArkNpcDamageEnterStateParams& _params) { FEnter(this, _params); }
	void Update(const ArkNpcDamageUpdateStateParams& _params, float _elapsedTime) { FUpdate(this, _params, _elapsedTime); }
	void Exit(const ArkNpcDamageExitStateParams& _params) const { FExit(this, _params); }
	void Serialize(TSerialize _serializer, const ArkNpcDamageSerializeStateParams& _params) { FSerialize(this, _serializer, _params); }
	void PostSerialize(const ArkNpcDamagePostSerializeStateParams& _params) { FPostSerialize(this, _params); }
	bool IsCompletelyDestroyed() const { return FIsCompletelyDestroyed(this); }
	void SwapToDestroyed(ArkNpc& _npc, bool _bDamage) { FSwapToDestroyed(this, _npc, _bDamage); }
	Matrix34 GetBodyWorldTm(ArkNpc& _npc) const { alignas(Matrix34) std::byte _return_buf_[sizeof(Matrix34)]; return *FGetBodyWorldTm(this, reinterpret_cast<Matrix34*>(_return_buf_), _npc); }

#if 0
	void EnterInternal(const ArkNpcDamageStateParam& _arg0_);
#endif

	static inline auto FArkNpcDamageState_DestroyedOv2 = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this)>(0x12A10B0);
	static inline auto FEnter = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this, const ArkNpcDamageEnterStateParams& _params)>(0x12A10C0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this, const ArkNpcDamageUpdateStateParams& _params, float _elapsedTime)>(0x12A1C10);
	static inline auto FExit = PreyFunction<void(const ArkNpcDamageState_Destroyed* const _this, const ArkNpcDamageExitStateParams& _params)>(0x12A13E0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this, TSerialize _serializer, const ArkNpcDamageSerializeStateParams& _params)>(0x12A1680);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this, const ArkNpcDamagePostSerializeStateParams& _params)>(0x12A1600);
	static inline auto FIsCompletelyDestroyed = PreyFunction<bool(const ArkNpcDamageState_Destroyed* const _this)>(0x12A15F0);
	static inline auto FSwapToDestroyed = PreyFunction<void(ArkNpcDamageState_Destroyed* const _this, ArkNpc& _npc, bool _bDamage)>(0x12A1790);
	static inline auto FGetBodyWorldTm = PreyFunction<Matrix34*(const ArkNpcDamageState_Destroyed* const _this, Matrix34* _return_value_, ArkNpc& _npc)>(0x12A1450);
};
#endif // MOONCRASH
