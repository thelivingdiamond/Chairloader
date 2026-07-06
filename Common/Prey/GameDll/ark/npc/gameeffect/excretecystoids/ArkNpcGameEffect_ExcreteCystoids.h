// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <_unknown/ArkInterval.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_ExcreteCystoids;

// ArkNpcGameEffect_ExcreteCystoids
// Header:  Prey/GameDll/ark/npc/gameeffect/excretecystoids/ArkNpcGameEffect_ExcreteCystoids.h
class ArkNpcGameEffect_ExcreteCystoids : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>
{ // Size=48 (0x30)
public:
	string m_cystoidArchetypeName;
	ArkInterval<unsigned __int64> m_spawnCountInterval;
	ArkInterval<float> m_spawnPeriodInterval;
	ArkAudioTrigger m_excreteAudioTrigger;

	static const char* ClassName() { return FClassName(); }
	void OnAttached(ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance) const { FOnAttached(this, _npc, _gameEffectInstance); }
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	void Serialize(ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance, TSerialize _serializer) const { FSerialize(this, _npc, _gameEffectInstance, _serializer); }

	static inline auto FClassName = PreyFunction<const char* ()>(0x12AC140);
	static inline auto FOnAttached = PreyFunction<void(const ArkNpcGameEffect_ExcreteCystoids* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance)>(0x12AC150);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_ExcreteCystoids* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance, float _elapsedTime)>(0x12AC270);
	static inline auto FSerialize = PreyFunction<void(const ArkNpcGameEffect_ExcreteCystoids* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_ExcreteCystoids& _gameEffectInstance, TSerialize _serializer)>(0x12AC220);
};
#endif // MOONCRASH
