// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkGameObjectExtension.h>
#include <Prey/GameDll/ark/ArkLaserTriplineSignalReceiver.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/ArkLaserTripline.h
class ArkLaserTripline : public CArkGameObjectExtension<ArkLaserTripline>, public IArkDisruptableListener, public IArkPlayerInteractionListener // Id=8019369 Size=344
{
public:
	bool m_bEnabled;
	bool m_bEnabledAtStartup;
	bool m_bDisrupted;
	bool m_bBeamFullyVisible;
	bool m_bDoDeepLinecheck;
	bool m_bIsSetupProperly;
	float m_visibleBeamLengthStart;
	float m_visibleBeamLengthEnd;
	uint64_t m_abilityDisarmRequirement;
	uint64_t m_damageSignalGroup;
	ColorF m_beamColor;
	ArkDisruptable m_disruptable;
	std::vector<IPhysicalEntity *> m_ignoredEntities;
	ArkLaserTriplineSignalReceiver m_signalReceiver;
	Vec3 m_lineCheckEndpoint;
	
	ArkLaserTripline();
	virtual ~ArkLaserTripline();
	void OnReceiveSignal(ArkSignalSystem::Package const &_package) { FOnReceiveSignal(this,_package); }
	void RegisterForSignals(bool _bRegister) { FRegisterForSignals(this,_bRegister); }
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	void InitProperties() { FInitProperties(this); }
	void DrawBeam(Vec3 const &_start, Vec3 const &_end) { FDrawBeam(this,_start,_end); }
	void SetupEndPoint() { FSetupEndPoint(this); }
	
#if 0
	void OnDamaged(unsigned arg0, float arg1);
#endif
	
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkLaserTripline *const _this, ArkSignalSystem::Package const &_package)>(0x1188440);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkLaserTripline *const _this, bool _bRegister)>(0x11887A0);
	static inline auto FUpdate = PreyFunction<void(ArkLaserTripline *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1188D00);
	static inline auto FProcessEvent = PreyFunction<void(ArkLaserTripline *const _this, SEntityEvent &_event)>(0x1188650);
	static inline auto FInit = PreyFunction<bool(ArkLaserTripline *const _this, IGameObject *_pGameObject)>(0x1187E20);
	static inline auto FPostInit = PreyFunction<void(ArkLaserTripline *const _this, IGameObject *_pGameObject)>(0x11885B0);
	static inline auto FRelease = PreyFunction<void(ArkLaserTripline *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkLaserTripline *const _this, TSerialize _ser)>(0x1187D30);
	static inline auto FPostSerialize = PreyFunction<void(ArkLaserTripline *const _this)>(0x1188630);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkLaserTripline *const _this, bool _bDisrupted, bool _bWasForced)>(0x11883F0);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(ArkLaserTripline const *const _this)>(0x1187DB0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkLaserTripline *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x1188400);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkLaserTripline const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1188590);
	static inline auto FTestInteraction = PreyFunction<bool(ArkLaserTripline const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1188AF0);
	static inline auto FInitProperties = PreyFunction<void(ArkLaserTripline *const _this)>(0x1187E50);
	static inline auto FDrawBeam = PreyFunction<void(ArkLaserTripline *const _this, Vec3 const &_start, Vec3 const &_end)>(0x1187950);
	static inline auto FSetupEndPoint = PreyFunction<void(ArkLaserTripline *const _this)>(0x11888B0);
};

