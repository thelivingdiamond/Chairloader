// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState.h>

struct ArkNpcDamageEnterStateParams;
struct ArkNpcDamageExitStateParams;
struct ArkNpcDamagePostSerializeStateParams;
struct ArkNpcDamageSerializeStateParams;
struct ArkNpcDamageStateParam;
struct ArkNpcDamageUpdateStateParams;

// ArkNpcDamageState_Disabled
// Header:  Prey/GameDll/ark/npc/damagefsm/states/ArkNpcDamageState_Disabled.h
class ArkNpcDamageState_Disabled : public ArkNpcDamageState
{ // Size=12 (0xC)
public:
	ArkSimpleTimer m_disabledSpeakerEventCD;
	float m_flickerDuration;

	ArkNpcDamageState_Disabled();
	void Enter(const ArkNpcDamageEnterStateParams& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcDamageExitStateParams& _params) const { FExit(this, _params); }
	void Update(const ArkNpcDamageUpdateStateParams& _params, float _elapsedTime) { FUpdate(this, _params, _elapsedTime); }
	void Serialize(TSerialize _serializer, const ArkNpcDamageSerializeStateParams& _params) { FSerialize(this, _serializer, _params); }
	void PostSerialize(const ArkNpcDamagePostSerializeStateParams& _params) { FPostSerialize(this, _params); }
	void EnterInternal(const ArkNpcDamageStateParam& _params) { FEnterInternal(this, _params); }

	static inline auto FArkNpcDamageState_Disabled = PreyFunction<void(ArkNpcDamageState_Disabled* const _this)>(0x12A1EB0);
	static inline auto FEnter = PreyFunction<void(ArkNpcDamageState_Disabled* const _this, const ArkNpcDamageEnterStateParams& _params)>(0x12A1ED0);
	static inline auto FExit = PreyFunction<void(const ArkNpcDamageState_Disabled* const _this, const ArkNpcDamageExitStateParams& _params)>(0x12A2120);
	static inline auto FUpdate = PreyFunction<void(ArkNpcDamageState_Disabled* const _this, const ArkNpcDamageUpdateStateParams& _params, float _elapsedTime)>(0x12A2270);
	static inline auto FSerialize = PreyFunction<void(ArkNpcDamageState_Disabled* const _this, TSerialize _serializer, const ArkNpcDamageSerializeStateParams& _params)>(0x12A21D0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcDamageState_Disabled* const _this, const ArkNpcDamagePostSerializeStateParams& _params)>(0x12A21C0);
	static inline auto FEnterInternal = PreyFunction<void(ArkNpcDamageState_Disabled* const _this, const ArkNpcDamageStateParam& _params)>(0x12A2080);
};
#endif // MOONCRASH
