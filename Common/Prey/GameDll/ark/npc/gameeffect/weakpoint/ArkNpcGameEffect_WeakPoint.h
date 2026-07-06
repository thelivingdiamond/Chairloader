// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_WeakPoint;

// ArkNpcGameEffect_WeakPoint
// Header:  Prey/GameDll/ark/npc/gameeffect/weakpoint/ArkNpcGameEffect_WeakPoint.h
class ArkNpcGameEffect_WeakPoint : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>
{ // Size=32 (0x20)
public:
	string m_attachmentName;
	float m_radius;
	uint64_t m_signalModifierId;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_WeakPoint();
	void Physicalize(ArkNpc& _npc, ArkNpcGameEffectInstance_WeakPoint& _gameEffectInstance) const { FPhysicalize(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, float _arg2_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_WeakPoint& _arg1_, TSerialize _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B51A0);
	static inline auto FArkNpcGameEffect_WeakPoint = PreyFunction<void(ArkNpcGameEffect_WeakPoint* const _this)>(0x12B50C0);
	static inline auto FPhysicalize = PreyFunction<void(const ArkNpcGameEffect_WeakPoint* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_WeakPoint& _gameEffectInstance)>(0x12B52D0);
};
#endif // MOONCRASH
