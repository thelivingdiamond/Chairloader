// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ArkInventory.h>
#include <Prey/GameDll/ark/ArkFabricationPlanIngredients.h>
#include <Prey/GameDll/ark/ArkInteractiveMachine.h>
#include <Prey/GameDll/ark/ArkInterval.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class CCryName;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ArkRecycler.h
class ArkRecycler : public ArkInteractiveMachine, public IArkInventoryListener, public ArkUIMenuBase<ArkRecycler>, public IArkStatsListener // Id=801A89D Size=1248
{
public:
	enum class ForceType
	{
		none = 0,
		init = 1,
		serialize = 2,
	};

	EArkRecyclerState m_state;
	ArkTimeRemaining m_timer;
	ArkInventory *m_pInventory;
	ArkEntityEffect m_recycleVfx;
	ArkFireAndForgetEffect m_recyclerFinishedVfx;
	
	class RecycleData // Id=801A8BD Size=24
	{
	public:
		unsigned m_entityToRecycle;
		ArkFabricationPlanIngredients m_scrap;
		
#if 0
		bool operator==(const unsigned arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkRecycler::RecycleData> m_entitiesToRecycle;
	ArkFabricationPlanIngredients m_scraps;
	ArkFabricationPlanIngredients m_producingScraps;
	float m_blockMultiplier;
	EArkCraftingIngredientType m_ingredientTypeToSpawn;
	unsigned m_lastIngredientSpawned;
	QuatT m_spawnLoc;
	QuatT m_vfxLoc;
	QuatT m_interactionLoc;
	string m_spawnAttachmentName;
	string m_vfxAttachmentName;
	string m_interactionAttachmentName;
	string m_interactText;
	float m_recycleDelay;
	float m_processingTimePerItem;
	float m_spawnInterval;
	float m_spawnImpulse;
	int m_maxNumSpawnedEntities;
	ArkInterval<float> m_percentRecycleRange;
	ArkInventory::EArkGridSizes m_inventorySize;
	ArkAudioTrigger m_triggerRecyclingLP;
	ArkAudioTrigger m_triggerCompleted;
	
	ArkRecycler();
	virtual ~ArkRecycler();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual Vec3 GetInteractionPosition(IEntity const *const _pEntity) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnButtonPress(this,_pSender,_event,_args); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void InitCachedPositionData();
	virtual bool IsProcessing() const;
	virtual bool IsInteractive() const;
	virtual void OnEnabledChanged(bool _bForce);
	void SetState(EArkRecyclerState _state, ArkRecycler::ForceType _forceType) { FSetState(this,_state,_forceType); }
	bool PopulateScrapsForEntity(IEntity const *const _pEntity, ArkFabricationPlanIngredients &_scraps) const { return FPopulateScrapsForEntity(this,_pEntity,_scraps); }
	void SpawnNextIngredient() { FSpawnNextIngredient(this); }
	void RefreshUIRecycleButton(bool _bAnimate) { FRefreshUIRecycleButton(this,_bAnimate); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void OnStatSerialize(const unsigned _ownerId, CCryName const &_stat64i32, const float _value);
	void RefreshUI(bool _bInit) { FRefreshUI(this,_bInit); }
	
#if 0
	EArkCraftingIngredientType GetScrapType(IEntity const *arg0) const;
#endif
	
	static inline auto FBitNotArkRecycler = PreyFunction<void(ArkRecycler *const _this)>(0x12513B0);
	static inline auto FPostInit = PreyFunction<void(ArkRecycler *const _this, IGameObject *_pGameObject)>(0x1253C50);
	static inline auto FFullSerialize = PreyFunction<void(ArkRecycler *const _this, TSerialize _ser)>(0x1251D50);
	static inline auto FPostSerialize = PreyFunction<void(ArkRecycler *const _this)>(0x1253D10);
	static inline auto FUpdate = PreyFunction<void(ArkRecycler *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1255390);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkRecycler const *const _this, ICrySizer *_s)>(0x1252890);
	static inline auto FOnItemAdded = PreyFunction<void(ArkRecycler *const _this, unsigned _itemId, unsigned _originalId)>(0x12536B0);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkRecycler *const _this, unsigned _itemId)>(0x1253780);
	static inline auto FOnItemCountChanged = PreyFunction<void(ArkRecycler *const _this, unsigned _itemId)>(0x1253770);
	static inline auto FOnInteraction = PreyFunction<bool(ArkRecycler *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x12535F0);
	static inline auto FTestInteraction = PreyFunction<bool(ArkRecycler const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1255260);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3(ArkRecycler const *const _this, IEntity const *const _pEntity)>(0x1252870);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkRecycler const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x1253B10);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkRecycler *const _this, IUIElement *_pUIInstance)>(0x1253A60);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkRecycler *const _this, IUIElement *_pUIInstance)>(0x1253AD0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkRecycler *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1253570);
	static inline auto FOnReset = PreyFunction<void(ArkRecycler *const _this, bool _bEnteringGameMode)>(0x1253820);
	static inline auto FLoadProperties = PreyFunction<void(ArkRecycler *const _this)>(0x1252B20);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkRecycler *const _this)>(0x1252910);
	static inline auto FIsProcessing = PreyFunction<bool(ArkRecycler const *const _this)>(0x1252AE0);
	static inline auto FIsInteractive = PreyFunction<bool(ArkRecycler const *const _this)>(0x1252AD0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkRecycler *const _this, bool _bForce)>(0x1253590);
	static inline auto FSetState = PreyFunction<void(ArkRecycler *const _this, EArkRecyclerState _state, ArkRecycler::ForceType _forceType)>(0x12540D0);
	static inline auto FPopulateScrapsForEntity = PreyFunction<bool(ArkRecycler const *const _this, IEntity const *const _pEntity, ArkFabricationPlanIngredients &_scraps)>(0x1253B70);
	static inline auto FSpawnNextIngredient = PreyFunction<void(ArkRecycler *const _this)>(0x1254E40);
	static inline auto FRefreshUIRecycleButton = PreyFunction<void(ArkRecycler *const _this, bool _bAnimate)>(0x1253F90);
	static inline auto FOnStatChange = PreyFunction<void(ArkRecycler *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x1253870);
	static inline auto FOnStatSerialize = PreyFunction<void(ArkRecycler *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _value)>(0x1253940);
	static inline auto FRefreshUI = PreyFunction<void(ArkRecycler *const _this, bool _bInit)>(0x1253D60);
};

