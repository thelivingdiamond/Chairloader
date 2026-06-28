// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_OperatorArmsRetracted;

// ArkNpcGameEffect_OperatorArmsRetracted
// Header:  Prey/GameDll/ark/npc/gameeffect/operatorarmsretracted/ArkNpcGameEffect_OperatorArmsRetracted.h
class ArkNpcGameEffect_OperatorArmsRetracted : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>
{ // Size=8 (0x8)
public:
	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_OperatorArmsRetracted();
	void InternalStart(ArkNpc& _npc, ArkNpcGameEffectInstance_OperatorArmsRetracted& _gameEffectInstance) const { FInternalStart(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_OperatorArmsRetracted& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B0E10);
	static inline auto FArkNpcGameEffect_OperatorArmsRetracted = PreyFunction<void(ArkNpcGameEffect_OperatorArmsRetracted* const _this)>(0x12B0DA0);
	static inline auto FInternalStart = PreyFunction<void(const ArkNpcGameEffect_OperatorArmsRetracted* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_OperatorArmsRetracted& _gameEffectInstance)>(0x12B0EC0);
};
#endif // MOONCRASH
