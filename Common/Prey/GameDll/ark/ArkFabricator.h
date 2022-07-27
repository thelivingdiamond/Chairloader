// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkFabricationPlanIngredients.h>
#include <Prey/GameDll/ark/ArkInteractiveMachine.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/iface/IArkFabricationPlanListener.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ArkFabricator.h
class ArkFabricator : public ArkInteractiveMachine, public ArkUIMenuBase<ArkFabricator>, public IArkInventoryListener, public IArkFabricationPlanListener // Id=8019076 Size=1960
{
public:
	EArkFabricatorState m_state;
	ArkSimpleTimer m_timer;
	ArkSimpleTimer m_idleTimer;
	ArkSimpleTimer m_errorTimer;
	ArkTimeRemaining m_fabricationTimer;
	ArkFabricationPlanIngredients m_ingredients;
	ArkFabricationPlanIngredients m_playerIngredients;
	unsigned m_spawnedItem;
	unsigned m_rawMaterial;
	uint64_t m_planId;
	bool m_bItemNeedsSpawn;
	bool m_bSlotsFlashing;
	bool m_bUIInitialized;
	float m_rawMaterialAnimTime;
	std::array<std::vector<unsigned int>,4> m_spawnedIngredients;
	std::array<std::vector<QuatT>,4> m_gridLocs;
	ArkMaterialAnimationManager m_materialAnimationManager;
	std::vector<unsigned __int64> m_planOrder;
	int m_animFabricateId;
	int m_animShortFabricateId;
	float m_releaseTime;
	float m_shortReleaseTime;
	QuatT m_spawnLoc;
	QuatT m_serializeLoc;
	QuatT m_offsetSpawnLoc;
	string m_spawnAttachmentName;
	string m_serializeAttachmentName;
	string m_spawnBoneName;
	string m_animName;
	string m_shortAnimName;
	float m_itemClearDistSq;
	float m_slotGlowAmount;
	float m_fabricatedWeaponIntegrity;
	int m_maxIngredientRows;
	int m_subMaterialId;
	string m_addIngredientsPrompt;
	string m_useWorldUIPrompt;
	string m_worldUIOffDisplayName;
	ArkAudioTrigger m_triggerCraft;
	ArkAudioTrigger m_triggerPowerOff;
	ArkAudioTrigger m_triggerPowerLP;
	ArkAudioTrigger m_triggerPlaceIngredients;
	ArkAudioTrigger m_triggerTakeItem;
	ArkAudioTrigger m_triggerSelectPlan;
	ArkAudioTrigger m_triggerNoPlans;
	int m_gameTokenNumTimesFabricatorUsed;
	int m_gameTokenFabricatedEntityName;
	int m_gameTokenFabricatedEntityId;
	std::array<unsigned __int64,4> m_ingredientArchetypes;
	
	ArkFabricator();
	virtual ~ArkFabricator();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual Vec3 GetInteractionPosition(IEntity const *const _pEntity) const;
	virtual void OnFabricationPlanAdded(const uint64_t _id);
	virtual void OnFabricationPlanUsed(const uint64_t _id);
	virtual void OnFabricationErrorSet(const uint64_t _id);
	virtual void OnFabricationErrorCleared(const uint64_t _id);
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnButtonPress(this,_pSender,_event,_args); }
	void OnItemCreate(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnItemCreate(this,_pSender,_event,_args); }
	void OnItemSelect(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnItemSelect(this,_pSender,_event,_args); }
	void OnPlaceIngredients(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPlaceIngredients(this,_pSender,_event,_args); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void InitCachedPositionData();
	virtual bool IsProcessing() const;
	virtual bool IsInteractive() const;
	void SetState(EArkFabricatorState _state) { FSetState(this,_state); }
	IEntity *SpawnItem() { return FSpawnItem(this); }
	void SpawnMaterial() { FSpawnMaterial(this); }
	void ClearSpawnedItem() { FClearSpawnedItem(this); }
	void RegisterSpawnedItem() { FRegisterSpawnedItem(this); }
	void ReinitializeUI() { FReinitializeUI(this); }
	void RefreshUIPlayerIngredients() { FRefreshUIPlayerIngredients(this); }
	void RefreshUIIngredients() { FRefreshUIIngredients(this); }
	void RefreshUIDisplayedPlans() { FRefreshUIDisplayedPlans(this); }
	void RefreshUIPlanDescription() { FRefreshUIPlanDescription(this); }
	void SpawnIngredients() { FSpawnIngredients(this); }
	void OnUsed() { FOnUsed(this); }
	void InitGridLocs() { FInitGridLocs(this); }
	void SetSlotsFlashing(bool _bFlashing) { FSetSlotsFlashing(this,_bFlashing); }
	void TestForIngredientChange(unsigned _itemId) { FTestForIngredientChange(this,_itemId); }
	void UpdateFlashing() { FUpdateFlashing(this); }
	virtual void OnEnabledChanged(bool _bForce);
	void AwakeSpawnedItem() const { FAwakeSpawnedItem(this); }
	void RefreshPlanOrder() { FRefreshPlanOrder(this); }
	
#if 0
	bool IsItemPresent() const;
	void AddIngredients();
	void RefreshForPlan(const uint64_t arg0);
	void SpawnIngredient(EArkCraftingIngredientType arg0, unsigned arg1);
	bool RemoveIngredient(EArkCraftingIngredientType arg0, unsigned arg1);
	void SetError(string const &arg0, string const &arg1);
#endif
	
	static inline auto FBitNotArkFabricator = PreyFunction<void(ArkFabricator *const _this)>(0x11618F0);
	static inline auto FPostInit = PreyFunction<void(ArkFabricator *const _this, IGameObject *_pGameObject)>(0x1165730);
	static inline auto FFullSerialize = PreyFunction<void(ArkFabricator *const _this, TSerialize _ser)>(0x1162D00);
	static inline auto FPostSerialize = PreyFunction<void(ArkFabricator *const _this)>(0x11657A0);
	static inline auto FUpdate = PreyFunction<void(ArkFabricator *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1168290);
	static inline auto FProcessEvent = PreyFunction<void(ArkFabricator *const _this, SEntityEvent &_event)>(0x1165890);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFabricator const *const _this, ICrySizer *_s)>(0x1163120);
	static inline auto FOnItemAdded = PreyFunction<void(ArkFabricator *const _this, unsigned _itemId, unsigned _originalId)>(0x1164D60);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkFabricator *const _this, unsigned _itemId)>(0x1165060);
	static inline auto FOnItemCountChanged = PreyFunction<void(ArkFabricator *const _this, unsigned _itemId)>(0x1164EB0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkFabricator *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x1164C70);
	static inline auto FTestInteraction = PreyFunction<bool(ArkFabricator const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x11680B0);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkFabricator *const _this, unsigned _targetId)>(0x1165420);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkFabricator *const _this, unsigned _targetId)>(0x1165450);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3(ArkFabricator const *const _this, IEntity const *const _pEntity)>(0x11630B0);
	static inline auto FOnFabricationPlanAdded = PreyFunction<void(ArkFabricator *const _this, const uint64_t _id)>(0x1164BD0);
	static inline auto FOnFabricationPlanUsed = PreyFunction<void(ArkFabricator *const _this, const uint64_t _id)>(0x1164C20);
	static inline auto FOnFabricationErrorSet = PreyFunction<void(ArkFabricator *const _this, const uint64_t _id)>(0x1164C20);
	static inline auto FOnFabricationErrorCleared = PreyFunction<void(ArkFabricator *const _this, const uint64_t _id)>(0x1164C20);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkFabricator *const _this, IUIElement *_pUIInstance)>(0x1165630);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkFabricator *const _this, IUIElement *_pUIInstance)>(0x11656C0);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkFabricator const *const _this)>(0x158AEF0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkFabricator *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x11648A0);
	static inline auto FOnItemCreate = PreyFunction<void(ArkFabricator *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1164EC0);
	static inline auto FOnItemSelect = PreyFunction<void(ArkFabricator *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x11650A0);
	static inline auto FOnPlaceIngredients = PreyFunction<void(ArkFabricator *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x11651E0);
	static inline auto FOnReset = PreyFunction<void(ArkFabricator *const _this, bool _bEnteringGameMode)>(0x11651F0);
	static inline auto FLoadProperties = PreyFunction<void(ArkFabricator *const _this)>(0x1163870);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkFabricator *const _this)>(0x1163200);
	static inline auto FIsProcessing = PreyFunction<bool(ArkFabricator const *const _this)>(0x1163860);
	static inline auto FIsInteractive = PreyFunction<bool(ArkFabricator const *const _this)>(0x1163840);
	static inline auto FSetState = PreyFunction<void(ArkFabricator *const _this, EArkFabricatorState _state)>(0x11666A0);
	static inline auto FSpawnItem = PreyFunction<IEntity *(ArkFabricator *const _this)>(0x1166DE0);
	static inline auto FSpawnMaterial = PreyFunction<void(ArkFabricator *const _this)>(0x1167D90);
	static inline auto FClearSpawnedItem = PreyFunction<void(ArkFabricator *const _this)>(0x1162CC0);
	static inline auto FRegisterSpawnedItem = PreyFunction<void(ArkFabricator *const _this)>(0x1166450);
	static inline auto FReinitializeUI = PreyFunction<void(ArkFabricator *const _this)>(0x1166530);
	static inline auto FRefreshUIPlayerIngredients = PreyFunction<void(ArkFabricator *const _this)>(0x1166300);
	static inline auto FRefreshUIIngredients = PreyFunction<void(ArkFabricator *const _this)>(0x1165DA0);
	static inline auto FRefreshUIDisplayedPlans = PreyFunction<void(ArkFabricator *const _this)>(0x1165A00);
	static inline auto FRefreshUIPlanDescription = PreyFunction<void(ArkFabricator *const _this)>(0x1166060);
	static inline auto FSpawnIngredients = PreyFunction<void(ArkFabricator *const _this)>(0x1166BB0);
	static inline auto FOnUsed = PreyFunction<void(ArkFabricator *const _this)>(0x1165490);
	static inline auto FInitGridLocs = PreyFunction<void(ArkFabricator *const _this)>(0x11634F0);
	static inline auto FSetSlotsFlashing = PreyFunction<void(ArkFabricator *const _this, bool _bFlashing)>(0x1166600);
	static inline auto FTestForIngredientChange = PreyFunction<void(ArkFabricator *const _this, unsigned _itemId)>(0x1168020);
	static inline auto FUpdateFlashing = PreyFunction<void(ArkFabricator *const _this)>(0x11684A0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkFabricator *const _this, bool _bForce)>(0x1164970);
	static inline auto FAwakeSpawnedItem = PreyFunction<void(ArkFabricator const *const _this)>(0x1162AD0);
	static inline auto FRefreshPlanOrder = PreyFunction<void(ArkFabricator *const _this)>(0x1165980);
};

