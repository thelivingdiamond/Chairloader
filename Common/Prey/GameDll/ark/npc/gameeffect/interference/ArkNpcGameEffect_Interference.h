// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkBlackListItem.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>

class ArkNpc;
struct ArkNpcGameEffectInstance_Interference;

// ArkNpcGameEffect_Interference
// Header:  Prey/GameDll/ark/npc/gameeffect/interference/ArkNpcGameEffect_Interference.h
class ArkNpcGameEffect_Interference : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>
{ // Size=48 (0x30)
public:
	uint64_t m_signalPackageId;
	float m_signalRadius;
	float m_signalFrequency;
	std::vector<ArkBlackListItem> m_blackList;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Interference();
	uint64_t GetSignalPackageId() const { return FGetSignalPackageId(this); }
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_Interference& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Interference& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1354C80);
	static inline auto FArkNpcGameEffect_Interference = PreyFunction<void(ArkNpcGameEffect_Interference* const _this)>(0x1354AF0);
	static inline auto FGetSignalPackageId = PreyFunction<uint64_t(const ArkNpcGameEffect_Interference* const _this)>(0x12DC700);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_Interference* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Interference& _gameEffectInstance, float _elapsedTime)>(0x1354CE0);
};
#endif // MOONCRASH
