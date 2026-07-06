// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <_unknown/ArkNpcGameEffectInstance.h>

struct ArkInteractionTestResult;
class ArkNpc;
class ArkNpcGameEffect_Pet;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;

// ArkNpcGameEffectInstance_Pet
// Header:  Prey/GameDll/ark/npc/gameeffect/pet/ArkNpcGameEffect_Pet.h
struct ArkNpcGameEffectInstance_Pet : public ArkNpcGameEffectInstance, public IArkPlayerInteractionListener
{ // Size=40 (0x28)
	const ArkNpcGameEffect_Pet* m_pGameEffect;
	unsigned m_npcEntityId;
	unsigned m_interactHoldTimerId;
	bool m_bUseMuleInventory;

	virtual void OnStartLookingAt(unsigned _targetEntityId);
	virtual void OnStopLookingAt(unsigned _targetEntityId);
	virtual bool OnHoldToUseStopped(IEntity* const _pEntity);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	void OnInteractHoldTimerExpired(void* _pUserData, unsigned _timerId) { FOnInteractHoldTimerExpired(this, _pUserData, _timerId); }

#if 0
	ArkNpcGameEffectInstance_Pet();
	void ResetInteractHoldTimer();
#endif

	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetEntityId)>(0x12B1540);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetEntityId)>(0x12B1570);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0x12B1370);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x12B1400);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x12B15A0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x12B1630);
	static inline auto FOnInteractHoldTimerExpired = PreyFunction<void(ArkNpcGameEffectInstance_Pet* const _this, void* _pUserData, unsigned _timerId)>(0x12B13B0);
};

// ArkNpcGameEffect_Pet
// Header:  Prey/GameDll/ark/npc/gameeffect/pet/ArkNpcGameEffect_Pet.h
class ArkNpcGameEffect_Pet : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>
{ // Size=16 (0x10)
public:
	float m_interactHoldDurationSec;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Pet();
	void InternalAttach(ArkNpc& _npc, ArkNpcGameEffectInstance_Pet& _gameEffectInstance) const { FInternalAttach(this, _npc, _gameEffectInstance); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
	void Update(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, const float _arg2_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Pet& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B1000);
	static inline auto FArkNpcGameEffect_Pet = PreyFunction<void(ArkNpcGameEffect_Pet* const _this)>(0x12B0FB0);
	static inline auto FInternalAttach = PreyFunction<void(const ArkNpcGameEffect_Pet* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Pet& _gameEffectInstance)>(0x12B1100);
};
#endif // MOONCRASH
