// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
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
	virtual ~ArkExplosiveTank();
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkLeakable.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionTestResult;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;
struct IGameObject;
struct SEntityUpdateContext;

// ArkExplosiveTank
// Header:  Prey/GameDll/ark/environment/ArkExplosiveTank.h
class ArkExplosiveTank : public ArkLeakable, public IArkPlayerInteractionListener
{ // Size=544 (0x220)
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
	const ArkSignalSystem::Data::SignalGroupData* m_pDamageSignalGroup;
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
	virtual ~ArkExplosiveTank();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void OnReset(bool _bEnteringGameMode);
	void TriggerExplosion() { FTriggerExplosion(this); }
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	void SetState(EArkExplosiveTankState _state, ArkExplosiveTank::ForceType _forceType) { FSetState(this, _state, _forceType); }
	void Explode() { FExplode(this); }
	virtual void LoadProperties();
	virtual bool CanLeak() const;
	virtual void LeakingStarted(const ArkLeakable::LeakInfo& _leak);
	virtual void RegisterForSignals(bool _bRegister);
	bool TestAndPopulateInteractionInfo(ArkInteractionInfo& _interactionInfo) const { return FTestAndPopulateInteractionInfo(this, _interactionInfo); }
	bool CanConsumeOxygen() const { return FCanConsumeOxygen(this); }

#if 0
	void ShowRenderMesh(bool _arg0_);
#endif

	static inline auto FArkExplosiveTankOv1 = PreyFunction<void(ArkExplosiveTank* const _this)>(0x14C9740);
	static inline auto FInit = PreyFunction<bool(ArkExplosiveTank* const _this, IGameObject* _pGameObject)>(0x14C9DC0);
	static inline auto FPostInit = PreyFunction<void(ArkExplosiveTank* const _this, IGameObject* _pGameObject)>(0x14CAF80);
	static inline auto FUpdate = PreyFunction<void(ArkExplosiveTank* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x14CB860);
	static inline auto FFullSerialize = PreyFunction<void(ArkExplosiveTank* const _this, TSerialize _ser)>(0x14C9C10);
	static inline auto FPostSerialize = PreyFunction<void(ArkExplosiveTank* const _this)>(0x14CB070);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkExplosiveTank* const _this, const ArkSignalSystem::Package& _package)>(0x14CAAA0);
	static inline auto FOnReset = PreyFunction<void(ArkExplosiveTank* const _this, bool _bEnteringGameMode)>(0x14CAD20);
	static inline auto FTriggerExplosion = PreyFunction<void(ArkExplosiveTank* const _this)>(0x14CB710);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x14CAE00);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x14CAF70);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x14CA9D0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x14CB6E0);
	static inline auto FSetState = PreyFunction<void(ArkExplosiveTank* const _this, EArkExplosiveTankState _state, ArkExplosiveTank::ForceType _forceType)>(0x14CB190);
	static inline auto FExplode = PreyFunction<void(ArkExplosiveTank* const _this)>(0x14C9970);
	static inline auto FLoadProperties = PreyFunction<void(ArkExplosiveTank* const _this)>(0x14C9F60);
	static inline auto FCanLeak = PreyFunction<bool(const ArkExplosiveTank* const _this)>(0x14C9960);
	static inline auto FLeakingStarted = PreyFunction<void(ArkExplosiveTank* const _this, const ArkLeakable::LeakInfo& _leak)>(0x14C9E00);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkExplosiveTank* const _this, bool _bRegister)>(0x14CB0A0);
	static inline auto FTestAndPopulateInteractionInfo = PreyFunction<bool(const ArkExplosiveTank* const _this, ArkInteractionInfo& _interactionInfo)>(0x14CB3D0);
	static inline auto FCanConsumeOxygen = PreyFunction<bool(const ArkExplosiveTank* const _this)>(0x14C9900);
};
#endif // !MOONCRASH
