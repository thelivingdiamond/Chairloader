// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
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
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkChargeTrap.h
class ArkChargeTrap : public ArkEnvironmentalObject, public IArkRepairableListener, public IArkPlayerInteractionListener // Id=8019733 Size=304
{
public:
	ArkRepairable m_repairable;
	string m_displayText;
	string m_chargeArchetype;
	Vec3 m_chargeOffset;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamagingSignalGroup;
	
	ArkChargeTrap();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void RegisterForSignals(bool _bRegister);
	virtual void HandleScriptEvent(const char *_pEvent, SEntityEvent &_event);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	void TriggerExplosion() { FTriggerExplosion(this); }
	
	static inline auto FInit = PreyFunction<bool(ArkChargeTrap *const _this, IGameObject *_pGameObject)>(0x11B8A80);
	static inline auto FPostInit = PreyFunction<void(ArkChargeTrap *const _this, IGameObject *_pGameObject)>(0x11B9180);
	static inline auto FFullSerialize = PreyFunction<void(ArkChargeTrap *const _this, TSerialize _ser)>(0x11B8990);
	static inline auto FPostSerialize = PreyFunction<void(ArkChargeTrap *const _this)>(0x11B91C0);
	static inline auto FUpdate = PreyFunction<void(ArkChargeTrap *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x11B9570);
	static inline auto FOnInteraction = PreyFunction<bool(ArkChargeTrap *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x11B9010);
	static inline auto FTestInteraction = PreyFunction<bool(ArkChargeTrap const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x11B92B0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkChargeTrap const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x11B9150);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkChargeTrap *const _this, bool _bBroken, bool _bWasForced)>(0x11B8EE0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkChargeTrap *const _this, ArkSignalSystem::Package const &_package)>(0x11B9030);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkChargeTrap *const _this, bool _bRegister)>(0x11B91D0);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkChargeTrap *const _this, const char *_pEvent, SEntityEvent &_event)>(0x11B8A00);
	static inline auto FOnReset = PreyFunction<void(ArkChargeTrap *const _this, bool _bEnteringGameMode)>(0x11B9120);
	static inline auto FLoadProperties = PreyFunction<void(ArkChargeTrap *const _this)>(0x11B8AB0);
	static inline auto FTriggerExplosion = PreyFunction<void(ArkChargeTrap *const _this)>(0x11B92D0);
};

