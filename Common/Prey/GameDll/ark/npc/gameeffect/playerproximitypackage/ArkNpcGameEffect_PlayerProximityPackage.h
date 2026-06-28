// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_PlayerProximityPackage;

// ArkNpcGameEffect_PlayerProximityPackage
// Header:  Prey/GameDll/ark/npc/gameeffect/playerproximitypackage/ArkNpcGameEffect_PlayerProximityPackage.h
class ArkNpcGameEffect_PlayerProximityPackage : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>
{ // Size=40 (0x28)
public:
	uint64_t m_packageId;
	float m_packageFrequency;
	float m_minDistance;
	float m_maxDistance;
	float m_minScale;
	float m_maxScale;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_PlayerProximityPackage();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_PlayerProximityPackage& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B1720);
	static inline auto FArkNpcGameEffect_PlayerProximityPackage = PreyFunction<void(ArkNpcGameEffect_PlayerProximityPackage* const _this)>(0x12B16E0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_PlayerProximityPackage* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_PlayerProximityPackage& _gameEffectInstance, float _elapsedTime)>(0x12B1790);
};
#endif // MOONCRASH
