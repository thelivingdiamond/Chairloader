// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ArkInventory.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleCharge.h>
#include <Prey/GameDll/ark/environment/ArkTyphonNest.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionTestResult;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum class EArkTyphonNestState;
struct IEntity;
struct IGameObject;
struct IPhysicalEntity;
struct SEntityEvent;

// ArkApexTentacleNest
// Header:  Prey/GameDll/ark/environment/ArkApexTentacleNest.h
class ArkApexTentacleNest
	: public ArkTyphonNest
	, public IArkPlayerInteractionListener
	, public IEntityEventListener
{ // Size=632 (0x278)
public:
	QuatT m_spawnLoc;
	unsigned m_tentacleSpawner;
	ArkSimpleCharge m_glooAccumulation;
	bool m_bActiveWhenGlooed;
	uint64_t m_spawnerArchetype;
	string m_interactVerb;
	ArkInventory::EArkGridSizes m_inventorySize;
	uint64_t m_lootTable;
	uint64_t m_glooSignal;
	float m_glooActivationAmount;

	ArkApexTentacleNest();
	virtual ~ArkApexTentacleNest();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Release();
	void AddToPhysicalEntIgnoreList(std::vector<IPhysicalEntity*>& out_ignoreList) const { FAddToPhysicalEntIgnoreList(this, out_ignoreList); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void UpdateFromCystoidManager(const float _frameTime, const int _zeroGUpdateSlice, bool& _bDidZeroGTest);
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void RegisterForSignals(bool _bRegister);
	virtual bool CanActivate() const;
	virtual bool SetState(EArkTyphonNestState _state, bool _bForce);
	virtual void LoadProperties();
	virtual void InitCachedPositionData();
	virtual bool SpawnTyphon();
	virtual bool IsActive() const;

#if 0
	std::vector<unsigned int> GetTentacleIds() const;
	std::vector<unsigned int> GetTentacleAndHeadIds() const;
	void FillInteractionInfo(ArkInteractionInfo& _arg0_) const;
#endif

	static inline auto FArkApexTentacleNest = PreyFunction<void(ArkApexTentacleNest* const _this)>(0x11C8CF0);
	static inline auto FPostInit = PreyFunction<void(ArkApexTentacleNest* const _this, IGameObject* _pGameObject)>(0x11C9DE0);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexTentacleNest* const _this, TSerialize _ser)>(0x11C90F0);
	static inline auto FRelease = PreyFunction<void(ArkApexTentacleNest* const _this)>(0x11C9F30);
	static inline auto FAddToPhysicalEntIgnoreList = PreyFunction<void(const ArkApexTentacleNest* const _this, std::vector<IPhysicalEntity*>& out_ignoreList)>(0x11C8E90);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x11C9B60);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x11CA280);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x11C9D60);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x11C9DA0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x11C9B10);
	static inline auto FOnReset = PreyFunction<void(ArkApexTentacleNest* const _this, bool _bEnteringGameMode)>(0x11C9D40);
	static inline auto FUpdateFromCystoidManager = PreyFunction<void(ArkApexTentacleNest* const _this, const float _frameTime, const int _zeroGUpdateSlice, bool& _bDidZeroGTest)>(0x11CA2A0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkApexTentacleNest* const _this, const ArkSignalSystem::Package& _package)>(0x11C9BC0);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkApexTentacleNest* const _this, bool _bRegister)>(0x11C9E50);
	static inline auto FCanActivate = PreyFunction<bool(const ArkApexTentacleNest* const _this)>(0x11C90C0);
	static inline auto FSetState = PreyFunction<bool(ArkApexTentacleNest* const _this, EArkTyphonNestState _state, bool _bForce)>(0x11C9F60);
	static inline auto FLoadProperties = PreyFunction<void(ArkApexTentacleNest* const _this)>(0x11C9440);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkApexTentacleNest* const _this)>(0x11C9300);
	static inline auto FSpawnTyphon = PreyFunction<bool(ArkApexTentacleNest* const _this)>(0x11CA0C0);
	static inline auto FIsActive = PreyFunction<bool(const ArkApexTentacleNest* const _this)>(0x11C9410);
};
#endif // MOONCRASH
