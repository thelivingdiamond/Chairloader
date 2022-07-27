// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkLeakable.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
struct IEntity;
struct IGameObject;
struct SEntityUpdateContext;

// Header: Exact
// Prey/GameDll/ark/environment/ArkExplosiveTank.h
class ArkExplosiveTank : public ArkLeakable, public IArkPlayerInteractionListener // Id=801BDA4 Size=536
{
public:
	enum class ForceType
	{
		none = 0,
		init = 1,
		serialize = 2,
	};

	EArkExplosiveTankState m_state;
	ArkSimpleTimer m_timer;
	ArkFireAndForgetEffect m_explosionVfx;
	bool m_bConsumed;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamageSignalGroup;
	uint64_t m_explosionSignalPackage;
	uint64_t m_consumeSignalPackage;
	uint64_t m_cameraShakeId;
	float m_explodeDelay;
	float m_minRadius;
	float m_maxRadius;
	float m_explosionImpulse;
	float m_instantExplosionThreshold;
	ArkAudioTrigger m_triggerExplosion;
	string m_consumedDisplayName;
	
	ArkExplosiveTank();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void OnReset(bool _bEnteringGameMode);
	void TriggerExplosion() { FTriggerExplosion(this); }
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	void SetState(EArkExplosiveTankState _state, ArkExplosiveTank::ForceType _forceType) { FSetState(this,_state,_forceType); }
	void Explode() { FExplode(this); }
	virtual void LoadProperties();
	virtual bool CanLeak() const;
	virtual void LeakingStarted(ArkLeakable::LeakInfo const &_leak);
	virtual void RegisterForSignals(bool _bRegister);
	bool TestAndPopulateInteractionInfo(ArkInteractionInfo &_interactionInfo) const { return FTestAndPopulateInteractionInfo(this,_interactionInfo); }
	bool CanConsumeOxygen() const { return FCanConsumeOxygen(this); }
	
#if 0
	void ShowRenderMesh(bool arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkExplosiveTank *const _this, IGameObject *_pGameObject)>(0x13BDAC0);
	static inline auto FPostInit = PreyFunction<void(ArkExplosiveTank *const _this, IGameObject *_pGameObject)>(0x13BEC40);
	static inline auto FUpdate = PreyFunction<void(ArkExplosiveTank *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0x13BF530);
	static inline auto FFullSerialize = PreyFunction<void(ArkExplosiveTank *const _this, TSerialize _ser)>(0x13BD910);
	static inline auto FPostSerialize = PreyFunction<void(ArkExplosiveTank *const _this)>(0x13BED30);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkExplosiveTank *const _this, ArkSignalSystem::Package const &_package)>(0x13BE7A0);
	static inline auto FOnReset = PreyFunction<void(ArkExplosiveTank *const _this, bool _bEnteringGameMode)>(0x13BEA30);
	static inline auto FTriggerExplosion = PreyFunction<void(ArkExplosiveTank *const _this)>(0x13BF3D0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkExplosiveTank const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x13BEB10);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkExplosiveTank const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x13BEC30);
	static inline auto FOnInteraction = PreyFunction<bool(ArkExplosiveTank *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x13BE6D0);
	static inline auto FTestInteraction = PreyFunction<bool(ArkExplosiveTank const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x13BF3A0);
	static inline auto FSetState = PreyFunction<void(ArkExplosiveTank *const _this, EArkExplosiveTankState _state, ArkExplosiveTank::ForceType _forceType)>(0x13BEE50);
	static inline auto FExplode = PreyFunction<void(ArkExplosiveTank *const _this)>(0x13BD670);
	static inline auto FLoadProperties = PreyFunction<void(ArkExplosiveTank *const _this)>(0x13BDC60);
	static inline auto FCanLeak = PreyFunction<bool(ArkExplosiveTank const *const _this)>(0x13BD660);
	static inline auto FLeakingStarted = PreyFunction<void(ArkExplosiveTank *const _this, ArkLeakable::LeakInfo const &_leak)>(0x13BDB00);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkExplosiveTank *const _this, bool _bRegister)>(0x13BED60);
	static inline auto FTestAndPopulateInteractionInfo = PreyFunction<bool(ArkExplosiveTank const *const _this, ArkInteractionInfo &_interactionInfo)>(0x13BF090);
	static inline auto FCanConsumeOxygen = PreyFunction<bool(ArkExplosiveTank const *const _this)>(0x13BD5E0);
};

