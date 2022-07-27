// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/arkinteractiveobject.h>
#include <Prey/GameDll/ark/arkrepairable.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#include <Prey/GameDll/ark/worldui/ArkInteractiveScreen.h>

struct IEntity;
struct IGameObject;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkInteractiveMachine.h
class ArkInteractiveMachine : public ArkInteractiveScreen, public IArkRepairableListener, public IEntityEventListener // Id=8019073 Size=760
{
public:
	ArkInteractiveMachinePerceivable m_perceivable;
	ArkRepairableLite m_repairable;
	unsigned m_repairBox;
	ArkEntityEffect m_idleVfx;
	QuatT m_repairBoxLoc;
	string m_repairBoxAttachmentName;
	string m_repairBoxArchetype;
	_smart_ptr<IMaterial> m_pScreensaverMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	ArkGameNoise::Params m_gameNoiseParams;
	
	ArkInteractiveMachine();
	virtual ~ArkInteractiveMachine();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void SetPowered(bool _bPowered, bool _bForce);
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void InitCachedPositionData();
	virtual bool IsEnabled() const;
	virtual bool IsInteractive() const;
	virtual void OnEnabledChanged(bool _bForce);
	void CreateRepairBox() { FCreateRepairBox(this); }
	virtual bool HasClock() const;
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual void SetupStaticMaterial();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void TriggerGameNoise(float _estimatedDuration) { FTriggerGameNoise(this,_estimatedDuration); }
	
	static inline auto FBitNotArkInteractiveMachine = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x1182990);
	static inline auto FInit = PreyFunction<bool(ArkInteractiveMachine *const _this, IGameObject *_pGameObject)>(0x1183090);
	static inline auto FPostInit = PreyFunction<void(ArkInteractiveMachine *const _this, IGameObject *_pGameObject)>(0x1184080);
	static inline auto FFullSerialize = PreyFunction<void(ArkInteractiveMachine *const _this, TSerialize _ser)>(0x1182FF0);
	static inline auto FPostSerialize = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x11840B0);
	static inline auto FProcessEvent = PreyFunction<void(ArkInteractiveMachine *const _this, SEntityEvent &_event)>(0x1184110);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkInteractiveMachine const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1183FB0);
	static inline auto FSetPowered = PreyFunction<void(ArkInteractiveMachine *const _this, bool _bPowered, bool _bForce)>(0x1184160);
	static inline auto FLoadProperties = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x1183770);
	static inline auto FOnReset = PreyFunction<void(ArkInteractiveMachine *const _this, bool _bEnteringGameMode)>(0x1183F60);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x11830F0);
	static inline auto FIsEnabled = PreyFunction<bool(ArkInteractiveMachine const *const _this)>(0x1183750);
	static inline auto FIsInteractive = PreyFunction<bool(ArkInteractiveMachine const *const _this)>(0x1B933B0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkInteractiveMachine *const _this, bool _bForce)>(0x139ED30);
	static inline auto FCreateRepairBox = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x1182CA0);
	static inline auto FHasClock = PreyFunction<bool(ArkInteractiveMachine const *const _this)>(0x1B933B0);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkInteractiveMachine *const _this, bool _bBroken, bool _bWasForced)>(0x1183E50);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkInteractiveMachine *const _this, bool _bDisrupted, bool _bWasForced)>(0x1183EC0);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkInteractiveMachine *const _this)>(0x11841A0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkInteractiveMachine *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x1183EF0);
	static inline auto FTriggerGameNoise = PreyFunction<void(ArkInteractiveMachine *const _this, float _estimatedDuration)>(0x1184210);
};

