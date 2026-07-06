// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesire.h>
#include <Prey/GameDll/ark/npc/gameeffect/arknpcgameeffecttemplate.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>
#include <_unknown/ArkNpcGameEffectInstance.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcGameEffect_Underground;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
enum class EArkUndergroundEmergeType;
struct IParticleEffect;

// ArkNpcUndergroundReceiver
// Header:  Prey/GameDll/ark/npc/gameeffect/underground/ArkNpcGameEffect_Underground.h
class ArkNpcUndergroundReceiver : public ArkSignalSystem::Receiver
{ // Size=32 (0x20)
public:
	unsigned m_npcEntityId;
	uint64_t m_signalModifierId;

	virtual ~ArkNpcUndergroundReceiver();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);

#if 0
	ArkNpcUndergroundReceiver();
	void Initialize(unsigned _arg0_, unsigned _arg1_, uint64_t _arg2_);
	unsigned GetUndergroundEntityId() const;
	unsigned GetNpcEntityId() const;
#endif

	static inline auto FOnReceiveSignal = PreyFunction<void(ArkNpcUndergroundReceiver* const _this, const ArkSignalSystem::Package& _package)>(0x12B4340);
};

// ArkNpcGameEffectInstance_Underground
// Header:  Prey/GameDll/ark/npc/gameeffect/underground/ArkNpcGameEffect_Underground.h
struct ArkNpcGameEffectInstance_Underground : public ArkNpcGameEffectInstance, public ArkNpcAnimActionObserver
{ // Size=304 (0x130)
	const ArkNpcGameEffect_Underground* m_pGameEffect;
	ArkNpcUndergroundReceiver m_signalReceiver;
	unsigned m_attachmentId;
	unsigned m_npcId;
	unsigned m_burrowedCollisionEntityId;
	ArkLooseEffect m_burrowedGroundSurfaceEffect;
	bool m_bIsFullyUnderground;
	CTimeValue m_timeSinceLiftedFromUnderground;
	bool m_bLockedUnderground;
	bool m_bLockedAboveground;
	ArkNpcNoiseStateDesire m_undergroundNoiseState;

	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimFragmentStarted(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);

#if 0
	ArkNpcGameEffectInstance_Underground();
#endif

	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimFragmentStarted = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1333E90);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x12B4040);
};

// ArkNpcGameEffect_Underground
// Header:  Prey/GameDll/ark/npc/gameeffect/underground/ArkNpcGameEffect_Underground.h
class ArkNpcGameEffect_Underground : public ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>
{ // Size=72 (0x48)
public:
	float m_undergroundColliderHeight;
	float m_radius;
	float m_timeLiftPreventsBurrowing;
	float m_distanceToAttackOutOfBurrow;
	uint64_t m_signalModifierId;
	uint64_t m_emergeAoESignalPackageId;
	float m_emergeAoEDamageRadius;
	float m_energeAoEImpulse;
	uint64_t m_emergeMeleeDamagePackageId;
	uint64_t m_burrowedCameraShakeId;
	_smart_ptr<IParticleEffect> m_pUndergroundSurfaceEffect;

	static const char* ClassName() { return FClassName(); }
	ArkNpcGameEffect_Underground();
	void Update(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, float _elapsedTime) const { FUpdate(this, _npc, _gameEffectInstance, _elapsedTime); }
	bool TryBurrowing(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance) const { return FTryBurrowing(this, _npc, _gameEffectInstance); }
	bool TryUnburrowing(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, EArkUndergroundEmergeType _emergeType) const { return FTryUnburrowing(this, _npc, _gameEffectInstance, _emergeType); }
	void SetBurrowed(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bBurrowed, bool _bForceTransition) const { FSetBurrowed(this, _npc, _gameEffectInstance, _bBurrowed, _bForceTransition); }
	void OnLiftAttempt(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance) const { FOnLiftAttempt(this, _npc, _gameEffectInstance); }
	bool TryLockBurrow(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance) const { return FTryLockBurrow(this, _npc, _gameEffectInstance); }
	bool TryUnlockBurrow(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bTryUnburrowing) const { return FTryUnlockBurrow(this, _npc, _gameEffectInstance, _bTryUnburrowing); }
	bool TryLockUnburrow(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance) const { return FTryLockUnburrow(this, _npc, _gameEffectInstance); }
	bool TryUnlockUnburrow(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bTryBurrowing) const { return FTryUnlockUnburrow(this, _npc, _gameEffectInstance, _bTryBurrowing); }
	void SetBurrowingStatePhysics(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bBurrowed) const { FSetBurrowingStatePhysics(this, _npc, _gameEffectInstance, _bBurrowed); }
	void UpdateBurrowedCollisionEntity(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance) const { FUpdateBurrowedCollisionEntity(this, _npc, _gameEffectInstance); }
	void SetVisible(ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bVisible) const { FSetVisible(this, _npc, _gameEffectInstance, _bVisible); }

#if 0
	void OnAttached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void OnDetached(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void Serialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_, TSerialize _arg2_) const;
	void PostSerialize(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void SpawnRocks(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void OnUnburrowFragmentVisible(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	bool IsLiftBlocked(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void CreateBurrowedCollisionEntity(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void RemoveBurrowedCollisionEntity(ArkNpc& _arg0_, ArkNpcGameEffectInstance_Underground& _arg1_) const;
	void StartCameraShake(ArkNpc& _arg0_) const;
	void StopCameraShake(ArkNpc& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12B3CE0);
	static inline auto FArkNpcGameEffect_Underground = PreyFunction<void(ArkNpcGameEffect_Underground* const _this)>(0x12B3B30);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, float _elapsedTime)>(0x12B4D50);
	static inline auto FTryBurrowing = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance)>(0x12B4A60);
	static inline auto FTryUnburrowing = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, EArkUndergroundEmergeType _emergeType)>(0x12B4C60);
	static inline auto FSetBurrowed = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bBurrowed, bool _bForceTransition)>(0x12B4470);
	static inline auto FOnLiftAttempt = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance)>(0x12B3FE0);
	static inline auto FTryLockBurrow = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance)>(0x12B4B10);
	static inline auto FTryUnlockBurrow = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bTryUnburrowing)>(0x12B4CB0);
	static inline auto FTryLockUnburrow = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance)>(0x12B4BC0);
	static inline auto FTryUnlockUnburrow = PreyFunction<bool(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bTryBurrowing)>(0x12B4D10);
	static inline auto FSetBurrowingStatePhysics = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bBurrowed)>(0x12B4880);
	static inline auto FUpdateBurrowedCollisionEntity = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance)>(0x12B5000);
	static inline auto FSetVisible = PreyFunction<void(const ArkNpcGameEffect_Underground* const _this, ArkNpc& _npc, ArkNpcGameEffectInstance_Underground& _gameEffectInstance, bool _bVisible)>(0x12B4960);
};
#endif // MOONCRASH
