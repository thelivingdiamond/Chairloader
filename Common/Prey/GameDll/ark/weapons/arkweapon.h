// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkRegularOutcome.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
//#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkStatsComponent.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerLightOwner.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>
#include <Prey/GameDll/ark/playerIArkCombatFocusListener.h>
#include <Prey/GameDll/ark/weapons/IArkWeapon.h>
#include <Prey/GameDll/arkitem.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/ui/arkinventoryui.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ArkWeaponModifier;
class CArkInventoryUI;
class IActionController;
class IArkInventory;
struct IArkWeaponEventListener;
struct IAttachment;
struct IAttachmentManager;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct ILoadGame;
struct ISaveGame;
struct IUIElement;
struct SActionEvent;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SMannequinItemParams;

// Header: Exact
// Prey/GameDll/ark/weapons/arkweapon.h
class CArkWeapon : public IArkWeapon, public CArkItem, public IArkInventoryListener, public IArkStatsListener, public IEntityEventListener, public IArkCombatFocusListener, public IGameFrameworkListener, public IArkPlayerLightOwner // Id=8015F0F Size=1216
{
public:
	struct ReticleInfo // Id=8015FC4 Size=24
	{
		IEntity *m_pEntity;
		Vec3 m_position;
	};

	enum class EArkWeaponStatus
	{
		normal = 0,
		damaged = 1,
		broken = 2,
		invalid = 3,
	};

	struct ArkWeaponMods // Id=8015FC6 Size=64
	{
		std::unordered_map<unsigned __int64,int> m_weaponModIds;
		
		void AddMod(const uint64_t _modId) { FAddMod(this,_modId); }
		int GetCurrentLevel(const uint64_t _modId) const { return FGetCurrentLevel(this,_modId); }
		void Clear() { FClear(this); }
		unsigned GetTotalLevel() const { return FGetTotalLevel(this); }
		
#if 0
		void Serialize(TSerialize arg0);
#endif
		
		static inline auto FAddMod = PreyFunction<void(CArkWeapon::ArkWeaponMods *const _this, const uint64_t _modId)>(0x1662F00);
		static inline auto FGetCurrentLevel = PreyFunction<int(CArkWeapon::ArkWeaponMods const *const _this, const uint64_t _modId)>(0x1665F70);
		static inline auto FClear = PreyFunction<void(CArkWeapon::ArkWeaponMods *const _this)>(0x13C24D0);
		static inline auto FGetTotalLevel = PreyFunction<unsigned(CArkWeapon::ArkWeaponMods const *const _this)>(0x16675E0);
	};

	ArkRegularOutcome m_criticalOutcome;
	ArkStatsComponent m_statsComponent;
	CArkWeapon::ArkWeaponMods m_weaponMods;
	EntityEffects::CEffectsController m_effectController;
	IAttachment *m_pAttachment;
	ArkSimpleTimer m_attackTimer;
	ArkSimpleTimer m_hudDamageIconTimer;
	bool m_bAmmoIsPooled;
	bool m_bIsAttacking;
	bool m_bWantsToAttack;
	bool m_bWantsToReload;
	_smart_ptr<IAction> m_pWeaponIdleAction;
	_smart_ptr<IAction> m_pWeaponFireAction;
	string m_pWeaponClassName;
	string m_ammoArchetypeName;
	string m_ammoSpawnPointName;
	string m_uiElementName;
	unsigned m_weaponUIType;
	Vec3 m_defaultLightColor;
	Vec3 m_damagedLightColor;
	Vec3 m_brokenLightColor;
	bool m_bAutoload;
	bool m_bAllowInterruptReloading;
	bool m_bAffectedByDisruption;
	bool m_bTakesHazardDamage;
	float m_idleBreakDelayTime;
	float m_ironsightsTargetDistance;
	float m_ironsightsTargetWidth;
	float m_ironsightsTargetSpeed;
	float m_ironsightsMaxAngularVelocity;
	float m_ironsightsSuccessDistance;
	float m_aimAssistRangeMax;
	float m_ammoLootImpulse;
	float m_condition;
	float m_malfunctionThreshold;
	float m_malfunctionRate;
	uint64_t m_disrepairModifier;
	uint64_t m_tutorialPrompt;
	uint64_t m_tutorialCard;
	int m_minStartAmmo;
	int m_maxStartAmmo;
	int m_disruptionSubMatIndex;
	ArkEntityAttachmentEffect m_disruptionVFX;
	std::vector<ArkMaterialParamOverride> m_originalInterferenceValues;
	float m_spawnFromCameraTestDistance;
	float m_spawnBehindCameraDistance;
	string m_upgradeInfoDesc;
	string m_focusDecription;
	CCryName m_leverageBaseName;
	string m_muzzleLightAttachName;
	_smart_ptr<IParticleEffect> m_pMuzzleLight;
	
	struct ArkIronsightsTargetInfo // Id=8015FFA Size=16
	{
		IEntityClass *m_entityClass;
		string m_targetBoneOrAttachName;
		
#if 0
		bool operator==(IEntityClass *arg0) const;
#endif
	};

	static std::vector<CArkWeapon::ArkIronsightsTargetInfo> m_ironsightsTargetClasses;
	static bool m_bIronsightsTargetClassesLoaded;
	std::vector<IArkWeaponEventListener *> m_listeners;
	ArkPlayerLightEntity m_playerLight;
	SMannequinItemParams::FragmentIDs const *m_pFragmentIDs;
	IUIElement *m_pUIElement;
	int m_zoomHandle;
	int m_numAmmoLoaded;
	bool m_bIdleBreakEnabled;
	bool m_bShouldFinishReloading;
	bool m_bCancelTutorialEnabled;
	bool m_bIsReadyToAttack;
	bool m_bIsReloading;
	bool m_bIsUnequipping;
	const bool m_bRetainPhysicsOnEquip;
	unsigned m_ironsightsTargetId;
	string m_ironsightsBoneOrAttachName;
	bool m_bHasAmmoBeenLooted;
	IEntityArchetype *m_pAmmoPickupArchetype;
	ArkAudioTrigger m_startMalfunctionTrigger;
	ArkAudioTrigger m_stopMalfunctionTrigger;
	ArkAudioTrigger m_brokeTrigger;
	ArkAudioTrigger m_ammoPickupTrigger;
	
	CArkWeapon(bool _bRetainPhysicsOnEquip);
	virtual ~CArkWeapon();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void SerializeLTL(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame *pSaveGame);
	virtual void OnLoadGame(ILoadGame *pLoadGame);
	virtual void OnLevelEnd(const char *nextLevel);
	virtual void OnActionEvent(SActionEvent const &event);
	virtual void OnPreRender();
	static uint64_t GetWeaponModArchetypeId() { return FGetWeaponModArchetypeId(); }
	virtual bool PickUp(const unsigned _pickerId, bool _bScale);
	virtual bool GiveOwner(IArkInventory *_pInventory);
	virtual void Drop(int _count, Vec3 const *const _altPosition);
	virtual bool IsWeapon() const;
	virtual bool IsEquippable() const;
	virtual const char *GetIcon() const;
	virtual const char *GetHUDIcon() const;
	virtual bool ShowsAmmoOnHUD() const;
	virtual wstring GetDisplayName(const int _count) const;
	void SetupAttachment() { FSetupAttachment(this); }
	virtual void OnEquip();
	virtual void OnUnequip(const bool _bUnselect);
	void UnequipOnPlayer() const { FUnequipOnPlayer(this); }
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnItemCountChanged(unsigned _itemId);
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	virtual bool OnActionAttackUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual bool OnActionReload(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value);
	virtual void SustainedAttack();
	virtual bool CanStartAttack();
	virtual void CancelCharge();
	virtual void ThrowingIdle();
	virtual void ThrowingCancel(const bool _bCheckIdle);
	virtual void OnReloadStart();
	static CArkWeapon *GetWeaponFromEntityId(const unsigned _entityId) { return FGetWeaponFromEntityId(_entityId); }
	virtual void AutoloadAmmo();
	virtual void StartReloadAmmo();
	virtual void ContinueReloadAmmo();
	virtual void ReloadAmmo(const bool _bContinueReload);
	virtual void StopReloadAmmo(const bool _bInterrupted);
	virtual void ReadjustAmmo();
	virtual void SetWeaponAmmoCount(const int _weaponAmmoCount);
	virtual int GetWeaponAmmoCount() const;
	virtual int GetInventoryAmmoCount() const;
	virtual string GetUIAmmoCountString() const;
	virtual string const &GetAmmoArchetypeName() const;
	virtual void RegisterListener(IArkWeaponEventListener *_pListener);
	virtual void UnregisterListener(IArkWeaponEventListener *_pListener);
	virtual bool StartAttack();
	virtual bool ContinueAttack();
	virtual bool StopAttack();
	virtual void EnterAttackAction();
	virtual void ExitAttackAction();
	virtual void ExitSelectAction();
	virtual void ThrowGrenade();
	virtual void DeployGrenade();
	virtual void ReloadGrenade();
	virtual void ProjectileDestroyed();
	virtual void StartSprinting();
	virtual float GetAimRange() const;
	virtual Vec3 GetReticlePosition() const;
	float GetStatFloat(CCryName const &_statName) const { return FGetStatFloat(this,_statName); }
	int GetStatInt(CCryName const &_statName) const { return FGetStatInt(this,_statName); }
	float GetStatFloatPlayer(CCryName const &_statName) const { return FGetStatFloatPlayer(this,_statName); }
	virtual int GetAmmoCost() const;
	virtual int GetClipSize() const;
	virtual float GetDegradationRate() const;
	void SetWeaponCondition(float _condition) { FSetWeaponCondition(this,_condition); }
	bool DoesWeaponDegrade() const { return FDoesWeaponDegrade(this); }
	void DegradeWeaponCondition() { FDegradeWeaponCondition(this); }
	void RepairWeapon(int _numRepairs) { FRepairWeapon(this,_numRepairs); }
	int GetNumPartsToFullyRepair() const { return FGetNumPartsToFullyRepair(this); }
	bool CanRepair() const { return FCanRepair(this); }
	bool IsBroken(float _condition) const { return FIsBroken(this,_condition); }
	void ShowWeaponDamageIndicator() { FShowWeaponDamageIndicator(this); }
	float GetWalkSpeedMultiplier() const { return FGetWalkSpeedMultiplier(this); }
	float GetCameraSpeedMultiplier() const { return FGetCameraSpeedMultiplier(this); }
	virtual float GetWalkSpeedStat() const;
	virtual float GetZoomedWalkSpeedStat() const;
	virtual float GetCameraSpeedStat() const;
	virtual float GetZoomedCameraSpeedStat() const;
	virtual float GetDispersion() const;
	bool CanInstallMod(const uint64_t _modId) const { return FCanInstallModOv1(this,_modId); }
	bool CanInstallMod(ArkWeaponModifier const *_pWeaponModifier) const { return FCanInstallModOv0(this,_pWeaponModifier); }
	bool CanUpgrade() const { return FCanUpgrade(this); }
	void InstallMod(const uint64_t _modId, const unsigned _kitId) { FInstallModOv1(this,_modId,_kitId); }
	void InstallMod(ArkWeaponModifier const *_pWeaponModifier, unsigned _kitId) { FInstallModOv0(this,_pWeaponModifier,_kitId); }
	void PopulateWeaponInfo(CArkInventoryUI::SelectedWeaponInfo &_weaponInfo) const { FPopulateWeaponInfo(this,_weaponInfo); }
	wstring GetWeaponModDescription(uint64_t _modId, int _modLevel) const { return FGetWeaponModDescription(this,_modId,_modLevel); }
	static int GetWeaponKitCount() { return FGetWeaponKitCount(); }
	virtual void UpdateDispersion();
	void ApplySignalModifiers(const unsigned _entityId) const { FApplySignalModifiers(this,_entityId); }
	void RemoveSignalModifiers(const unsigned _entityId) const { FRemoveSignalModifiers(this,_entityId); }
	Vec3 GetIronsightsTargetPos() const { return FGetIronsightsTargetPos(this); }
	virtual bool IsProximity() const;
	virtual CCryName GetReticleName() const;
	void PlayAction(_smart_ptr<IAction> _pAction, float _speedOverride) const { FPlayAction(this,_pAction,_speedOverride); }
	bool DetachFromHand() { return FDetachFromHand(this); }
	float GetImpulseScaleForEntity(IEntity const *const _pEntity) const { return FGetImpulseScaleForEntity(this,_pEntity); }
	IUIElement *GetUIElement() { return FGetUIElement(this); }
	bool IsEquipped() const { return FIsEquipped(this); }
	void FindIronsightsTarget() { FFindIronsightsTarget(this); }
	virtual bool HasTarget() const;
	virtual float GetTargetLockPercentage() const;
	virtual float GetTargetLockTimeOutElapsedSec() const;
	virtual void OnAttackStopped();
	virtual void OnMalfunctionStart();
	virtual void OnMalfunctionEvent();
	void OnMuzzleFlash() { FOnMuzzleFlash(this); }
	virtual float GetDamageScale(const float _distance) const;
	IEntityArchetype *GetAmmoPickupArchetype() const { return FGetAmmoPickupArchetype(this); }
	bool ShouldTreatAsFirstPickup() const { return FShouldTreatAsFirstPickup(this); }
	bool IsDisrupted() const { return FIsDisrupted(this); }
	virtual bool ForceCancelCharge();
	virtual bool IsCharging() const;
	void UpdateDisruptedVisuals(bool _bDisrupted) { FUpdateDisruptedVisuals(this,_bDisrupted); }
	CArkWeapon::ReticleInfo GetReticleInfoForFiring() const { return FGetReticleInfoForFiring(this); }
	void ApplyRecoil() const { FApplyRecoil(this); }
	virtual void LoadCachedProperties();
	virtual void InitializeStats();
	void UpdateTimers(float _frameTime) { FUpdateTimers(this,_frameTime); }
	void UpdateAnimationTag(bool _bSelected, const char *_tagName) { FUpdateAnimationTag(this,_bSelected,_tagName); }
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const;
	void AttachToShadowHand(bool _bAttach) { FAttachToShadowHand(this,_bAttach); }
	virtual void ConsumeAmmo();
	virtual bool CanLoadAmmo() const;
	virtual bool HasAmmo() const;
	void StopSprinting() const { FStopSprinting(this); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void OnCombatFocusChanged(bool _bActive);
	void UpdateCritical() { FUpdateCritical(this); }
	bool ShouldMalfunction() const { return FShouldMalfunction(this); }
	void DoMalfunction() { FDoMalfunction(this); }
	void FireWeapon() { FFireWeapon(this); }
	std::pair<bool,Vec3> GetSpawnPosition(const int _ignoreCollisionType, IEntity *const _pAttachEntity) const { return FGetSpawnPosition(this,_ignoreCollisionType,_pAttachEntity); }
	virtual void OnAmmoDepleted();
	virtual void UpdateAmmoCountUI() const;
	virtual void EnableCancelTutorial(string _tutorialHintString);
	virtual void DisableCancelTutorial();
	void EnableChargeFilter(const bool _bEnable) { FEnableChargeFilter(this,_bEnable); }
	virtual int GetBaseDamage() const;
	virtual int GetModifiedDamage(std::vector<unsigned __int64> const &_modifiers) const;
	std::vector<unsigned __int64> GetSignalModifiers() const { return FGetSignalModifiers(this); }
	float CalculateBaseDamage(uint64_t _pkgId, uint64_t _dmgSignal) const { return FCalculateBaseDamage(this,_pkgId,_dmgSignal); }
	void SpawnMuzzleLight(bool _bAttach) { FSpawnMuzzleLight(this,_bAttach); }
	void StopMuzzleLight() { FStopMuzzleLight(this); }
	void UpdateConditionFeedback() const { FUpdateConditionFeedback(this); }
	void UpdateArkLightColor(CArkWeapon::EArkWeaponStatus _condition) const { FUpdateArkLightColor(this,_condition); }
	void InitializeCondition() { FInitializeCondition(this); }
	unsigned SpawnAmmo() { return FSpawnAmmo(this); }
	bool AttachToHand() { return FAttachToHand(this); }
	IActionController *GetOwnerActionController() const { return FGetOwnerActionController(this); }
	void UpdateAnimationScopeContexts() { FUpdateAnimationScopeContexts(this); }
	bool IsItemWeaponAmmo(unsigned _itemId) { return FIsItemWeaponAmmo(this,_itemId); }
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const;
	void InitializeAmmoCount() { FInitializeAmmoCount(this); }
	void GiveAmmoClip(const unsigned _pickerId) { FGiveAmmoClip(this,_pickerId); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	void DisplayTutorialCard() const { FDisplayTutorialCard(this); }
	void UpdateStatusIcon(bool _bForceRemove) const { FUpdateStatusIcon(this,_bForceRemove); }
	
#if 0
	bool CanPickUp(unsigned arg0) const;
	bool IsZoomingIn() const;
	void HideAttachment(const bool arg0) const;
	bool IsAttacking() const;
	bool IsReadyToAttack() const;
	void SetIsReadyToAttack(const bool arg0);
	bool IsReloading() const;
	void SetIsReloading(const bool arg0);
	bool ShouldFinishReloading() const;
	void SetShouldFinishReloading(const bool arg0);
	SMannequinItemParams::FragmentIDs const *const  GetFragmentIDs() const;
	float GetReticlePositionRange() const;
	ArkStatsComponent const &GetStatsComponent() const;
	float GetWeaponCondition() const;
	int GetUIWeaponCondition() const;
	bool TakesHazardDamage() const;
	void BreakAndUnequip();
	float GetIdleBreakDelayTme() const;
	bool IsIdleBreakEnabled() const;
	void EnableIdleBreaks(const bool arg0);
	float GetIronsightsMaxAngularVelocity() const;
	float GetIronsightsSuccessDistance() const;
	float GetIronsightsSpeed() const;
	unsigned GetIronsightsTargetId() const;
	void SetIronsightsTargetId(const unsigned arg0);
	bool IsUnequipping() const;
	float GetAimAssistRangeMax() const;
	bool RollCritical() const;
	string GetFocusModeDescription() const;
	void CloseWeaponDamageIndicator();
	Matrix34 GetWorldTM() const;
	void InhibitSprinting(const bool arg0) const;
	Vec3 GetSpawnDirection(Vec3 const &arg0) const;
	CArkWeapon::EArkWeaponStatus GetConditionStatus() const;
	void DrawSlot(int arg0, bool arg1, bool arg2);
	void ClearAnimationScopeContexts();
	IAttachmentManager *GetAttachmentManager(const unsigned arg0);
	void TriggerOutOfAmmoUI() const;
	bool AreAllModsInstalled() const;
	void __dflt_ctor_closure();
#endif
	
	static inline auto FBitNotCArkWeapon = PreyFunction<void(CArkWeapon *const _this)>(0x1662A50);
	static inline auto FInit = PreyFunction<bool(CArkWeapon *const _this, IGameObject *_pGameObject)>(0x1668490);
	static inline auto FPostInit = PreyFunction<void(CArkWeapon *const _this, IGameObject *_pGameObject)>(0x166CF80);
	static inline auto FRelease = PreyFunction<void(CArkWeapon *const _this)>(0x166D280);
	static inline auto FFullSerialize = PreyFunction<void(CArkWeapon *const _this, TSerialize _ser)>(0x1665C30);
	static inline auto FSerializeLTL = PreyFunction<void(CArkWeapon *const _this, TSerialize _ser)>(0x166D680);
	static inline auto FPostSerialize = PreyFunction<void(CArkWeapon *const _this)>(0x166D080);
	static inline auto FUpdate = PreyFunction<void(CArkWeapon *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x166E960);
	static inline auto FProcessEvent = PreyFunction<void(CArkWeapon *const _this, SEntityEvent &_event)>(0x166D100);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkWeapon const *const _this, ICrySizer *_s)>(0x1666CB0);
	static inline auto FOnPostUpdate = PreyFunction<void(CArkWeapon *const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(CArkWeapon *const _this, ISaveGame *pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(CArkWeapon *const _this, ILoadGame *pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(CArkWeapon *const _this, const char *nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(CArkWeapon *const _this, SActionEvent const &event)>(0xA13080);
	static inline auto FOnPreRender = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FGetWeaponModArchetypeId = PreyFunction<uint64_t()>(0x16677B0);
	static inline auto FPickUp = PreyFunction<bool(CArkWeapon *const _this, const unsigned _pickerId, bool _bScale)>(0x166C8E0);
	static inline auto FGiveOwner = PreyFunction<bool(CArkWeapon *const _this, IArkInventory *_pInventory)>(0x1668430);
	static inline auto FDrop = PreyFunction<void(CArkWeapon *const _this, int _count, Vec3 const *const _altPosition)>(0x1665180);
	static inline auto FIsWeapon = PreyFunction<bool(CArkWeapon const *const _this)>(0x1B933B0);
	static inline auto FIsEquippable = PreyFunction<bool(CArkWeapon const *const _this)>(0x1B933B0);
	static inline auto FGetIcon = PreyFunction<const char *(CArkWeapon const *const _this)>(0x16664F0);
	static inline auto FGetHUDIcon = PreyFunction<const char *(CArkWeapon const *const _this)>(0x1666270);
	static inline auto FShowsAmmoOnHUD = PreyFunction<bool(CArkWeapon const *const _this)>(0xDD23F0);
	static inline auto FGetDisplayName = PreyFunction<wstring(CArkWeapon const *const _this, const int _count)>(0x16660B0);
	static inline auto FSetupAttachment = PreyFunction<void(CArkWeapon *const _this)>(0x166D9F0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeapon *const _this)>(0x166BDA0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeapon *const _this, const bool _bUnselect)>(0x166C5A0);
	static inline auto FUnequipOnPlayer = PreyFunction<void(CArkWeapon const *const _this)>(0x166E8A0);
	static inline auto FOnItemAdded = PreyFunction<void(CArkWeapon *const _this, unsigned _itemId, unsigned _originalId)>(0x166C470);
	static inline auto FOnItemRemoved = PreyFunction<void(CArkWeapon *const _this, unsigned _itemId)>(0x166C4B0);
	static inline auto FOnItemCountChanged = PreyFunction<void(CArkWeapon *const _this, unsigned _itemId)>(0x166C470);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkWeapon *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x166BD20);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeapon *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0xDD23F0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeapon *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x166BB50);
	static inline auto FOnActionReload = PreyFunction<bool(CArkWeapon *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x166BC60);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FCanStartAttack = PreyFunction<bool(CArkWeapon *const _this)>(0x16643E0);
	static inline auto FCancelCharge = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FThrowingIdle = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FThrowingCancel = PreyFunction<void(CArkWeapon *const _this, const bool _bCheckIdle)>(0xA13080);
	static inline auto FOnReloadStart = PreyFunction<void(CArkWeapon *const _this)>(0x138A940);
	static inline auto FGetWeaponFromEntityId = PreyFunction<CArkWeapon *(const unsigned _entityId)>(0x1667720);
	static inline auto FAutoloadAmmo = PreyFunction<void(CArkWeapon *const _this)>(0x1664160);
	static inline auto FStartReloadAmmo = PreyFunction<void(CArkWeapon *const _this)>(0x166E420);
	static inline auto FContinueReloadAmmo = PreyFunction<void(CArkWeapon *const _this)>(0x1664930);
	static inline auto FReloadAmmo = PreyFunction<void(CArkWeapon *const _this, const bool _bContinueReload)>(0x166D400);
	static inline auto FStopReloadAmmo = PreyFunction<void(CArkWeapon *const _this, const bool _bInterrupted)>(0x166E630);
	static inline auto FReadjustAmmo = PreyFunction<void(CArkWeapon *const _this)>(0x166D1E0);
	static inline auto FSetWeaponAmmoCount = PreyFunction<void(CArkWeapon *const _this, const int _weaponAmmoCount)>(0x166D840);
	static inline auto FGetWeaponAmmoCount = PreyFunction<int(CArkWeapon const *const _this)>(0x138A0D0);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(CArkWeapon const *const _this)>(0x1666A50);
	static inline auto FGetUIAmmoCountString = PreyFunction<string(CArkWeapon const *const _this)>(0x1667600);
	static inline auto FGetAmmoArchetypeName = PreyFunction<string const &(CArkWeapon const *const _this)>(0x1248410);
	static inline auto FRegisterListener = PreyFunction<void(CArkWeapon *const _this, IArkWeaponEventListener *_pListener)>(0x166D220);
	static inline auto FUnregisterListener = PreyFunction<void(CArkWeapon *const _this, IArkWeaponEventListener *_pListener)>(0x166E900);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeapon *const _this)>(0x166E320);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeapon *const _this)>(0x16648C0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeapon *const _this)>(0x166E530);
	static inline auto FEnterAttackAction = PreyFunction<void(CArkWeapon *const _this)>(0x16653B0);
	static inline auto FExitAttackAction = PreyFunction<void(CArkWeapon *const _this)>(0x16653C0);
	static inline auto FExitSelectAction = PreyFunction<void(CArkWeapon *const _this)>(0x16654A0);
	static inline auto FThrowGrenade = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FDeployGrenade = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FReloadGrenade = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FProjectileDestroyed = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FStartSprinting = PreyFunction<void(CArkWeapon *const _this)>(0x37CD00);
	static inline auto FGetAimRange = PreyFunction<float(CArkWeapon const *const _this)>(0x1665E70);
	static inline auto FGetReticlePosition = PreyFunction<Vec3(CArkWeapon const *const _this)>(0x1666F70);
	static inline auto FGetStatFloat = PreyFunction<float(CArkWeapon const *const _this, CCryName const &_statName)>(0x1667570);
	static inline auto FGetStatInt = PreyFunction<int(CArkWeapon const *const _this, CCryName const &_statName)>(0x16675C0);
	static inline auto FGetStatFloatPlayer = PreyFunction<float(CArkWeapon const *const _this, CCryName const &_statName)>(0x1667580);
	static inline auto FGetAmmoCost = PreyFunction<int(CArkWeapon const *const _this)>(0x1665E90);
	static inline auto FGetClipSize = PreyFunction<int(CArkWeapon const *const _this)>(0x1665F50);
	static inline auto FGetDegradationRate = PreyFunction<float(CArkWeapon const *const _this)>(0x1666060);
	static inline auto FSetWeaponCondition = PreyFunction<void(CArkWeapon *const _this, float _condition)>(0x166D8E0);
	static inline auto FDoesWeaponDegrade = PreyFunction<bool(CArkWeapon const *const _this)>(0x1665130);
	static inline auto FDegradeWeaponCondition = PreyFunction<void(CArkWeapon *const _this)>(0x16649E0);
	static inline auto FRepairWeapon = PreyFunction<void(CArkWeapon *const _this, int _numRepairs)>(0x166D600);
	static inline auto FGetNumPartsToFullyRepair = PreyFunction<int(CArkWeapon const *const _this)>(0x1666CD0);
	static inline auto FCanRepair = PreyFunction<bool(CArkWeapon const *const _this)>(0x16643C0);
	static inline auto FIsBroken = PreyFunction<bool(CArkWeapon const *const _this, float _condition)>(0x1669FF0);
	static inline auto FShowWeaponDamageIndicator = PreyFunction<void(CArkWeapon *const _this)>(0x166DDC0);
	static inline auto FGetWalkSpeedMultiplier = PreyFunction<float(CArkWeapon const *const _this)>(0x1667690);
	static inline auto FGetCameraSpeedMultiplier = PreyFunction<float(CArkWeapon const *const _this)>(0x1665EC0);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(CArkWeapon const *const _this)>(0x1667700);
	static inline auto FGetZoomedWalkSpeedStat = PreyFunction<float(CArkWeapon const *const _this)>(0x16682C0);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(CArkWeapon const *const _this)>(0x1665F30);
	static inline auto FGetZoomedCameraSpeedStat = PreyFunction<float(CArkWeapon const *const _this)>(0x16682A0);
	static inline auto FGetDispersion = PreyFunction<float(CArkWeapon const *const _this)>(0xB5F050);
	static inline auto FCanInstallModOv1 = PreyFunction<bool(CArkWeapon const *const _this, const uint64_t _modId)>(0x1664300);
	static inline auto FCanInstallModOv0 = PreyFunction<bool(CArkWeapon const *const _this, ArkWeaponModifier const *_pWeaponModifier)>(0x1664220);
	static inline auto FCanUpgrade = PreyFunction<bool(CArkWeapon const *const _this)>(0x1664740);
	static inline auto FInstallModOv1 = PreyFunction<void(CArkWeapon *const _this, const uint64_t _modId, const unsigned _kitId)>(0x1669FA0);
	static inline auto FInstallModOv0 = PreyFunction<void(CArkWeapon *const _this, ArkWeaponModifier const *_pWeaponModifier, unsigned _kitId)>(0x1669D30);
	static inline auto FPopulateWeaponInfo = PreyFunction<void(CArkWeapon const *const _this, CArkInventoryUI::SelectedWeaponInfo &_weaponInfo)>(0x166CC80);
	static inline auto FGetWeaponModDescription = PreyFunction<wstring(CArkWeapon const *const _this, uint64_t _modId, int _modLevel)>(0x1667830);
	static inline auto FGetWeaponKitCount = PreyFunction<int()>(0x1667770);
	static inline auto FUpdateDispersion = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FApplySignalModifiers = PreyFunction<void(CArkWeapon const *const _this, const unsigned _entityId)>(0x1663930);
	static inline auto FRemoveSignalModifiers = PreyFunction<void(CArkWeapon const *const _this, const unsigned _entityId)>(0x166D4F0);
	static inline auto FGetIronsightsTargetPos = PreyFunction<Vec3(CArkWeapon const *const _this)>(0x1666AC0);
	static inline auto FIsProximity = PreyFunction<bool(CArkWeapon const *const _this)>(0xDD23F0);
	static inline auto FGetReticleName = PreyFunction<CCryName(CArkWeapon const *const _this)>(0x138A040);
	static inline auto FPlayAction = PreyFunction<void(CArkWeapon const *const _this, _smart_ptr<IAction> _pAction, float _speedOverride)>(0x166CB50);
	static inline auto FDetachFromHand = PreyFunction<bool(CArkWeapon *const _this)>(0x1664A30);
	static inline auto FGetImpulseScaleForEntity = PreyFunction<float(CArkWeapon const *const _this, IEntity const *const _pEntity)>(0x1666760);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(CArkWeapon *const _this)>(0x1667680);
	static inline auto FIsEquipped = PreyFunction<bool(CArkWeapon const *const _this)>(0x166A050);
	static inline auto FFindIronsightsTarget = PreyFunction<void(CArkWeapon *const _this)>(0x16655F0);
	static inline auto FHasTarget = PreyFunction<bool(CArkWeapon const *const _this)>(0xDD23F0);
	static inline auto FGetTargetLockPercentage = PreyFunction<float(CArkWeapon const *const _this)>(0xB5F050);
	static inline auto FGetTargetLockTimeOutElapsedSec = PreyFunction<float(CArkWeapon const *const _this)>(0xB5F050);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FOnMalfunctionStart = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FOnMalfunctionEvent = PreyFunction<void(CArkWeapon *const _this)>(0xA13080);
	static inline auto FOnMuzzleFlash = PreyFunction<void(CArkWeapon *const _this)>(0x166C4F0);
	static inline auto FGetDamageScale = PreyFunction<float(CArkWeapon const *const _this, const float _distance)>(0x18C0850);
	static inline auto FGetAmmoPickupArchetype = PreyFunction<IEntityArchetype *(CArkWeapon const *const _this)>(0x1665EB0);
	static inline auto FShouldTreatAsFirstPickup = PreyFunction<bool(CArkWeapon const *const _this)>(0x166DD70);
	static inline auto FIsDisrupted = PreyFunction<bool(CArkWeapon const *const _this)>(0x166A000);
	static inline auto FForceCancelCharge = PreyFunction<bool(CArkWeapon *const _this)>(0xDD23F0);
	static inline auto FIsCharging = PreyFunction<bool(CArkWeapon const *const _this)>(0xDD23F0);
	static inline auto FUpdateDisruptedVisuals = PreyFunction<void(CArkWeapon *const _this, bool _bDisrupted)>(0x166F470);
	static inline auto FGetReticleInfoForFiring = PreyFunction<CArkWeapon::ReticleInfo(CArkWeapon const *const _this)>(0x1666DE0);
	static inline auto FApplyRecoil = PreyFunction<void(CArkWeapon const *const _this)>(0x16630A0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkWeapon *const _this)>(0x166A130);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeapon *const _this)>(0x1668BF0);
	static inline auto FUpdateTimers = PreyFunction<void(CArkWeapon *const _this, float _frameTime)>(0x166F7B0);
	static inline auto FUpdateAnimationTag = PreyFunction<void(CArkWeapon *const _this, bool _bSelected, const char *_tagName)>(0x166F000);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>(CArkWeapon const *const _this, const int _fragmentId)>(0x16647B0);
	static inline auto FAttachToShadowHand = PreyFunction<void(CArkWeapon *const _this, bool _bAttach)>(0x1663D40);
	static inline auto FConsumeAmmo = PreyFunction<void(CArkWeapon *const _this)>(0x1664810);
	static inline auto FCanLoadAmmo = PreyFunction<bool(CArkWeapon const *const _this)>(0x1664350);
	static inline auto FHasAmmo = PreyFunction<bool(CArkWeapon const *const _this)>(0x1668460);
	static inline auto FStopSprinting = PreyFunction<void(CArkWeapon const *const _this)>(0x166E7C0);
	static inline auto FOnStatChange = PreyFunction<void(CArkWeapon *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x166C580);
	static inline auto FOnCombatFocusChanged = PreyFunction<void(CArkWeapon *const _this, bool _bActive)>(0x166BD10);
	static inline auto FUpdateCritical = PreyFunction<void(CArkWeapon *const _this)>(0x166F300);
	static inline auto FShouldMalfunction = PreyFunction<bool(CArkWeapon const *const _this)>(0x166DD20);
	static inline auto FDoMalfunction = PreyFunction<void(CArkWeapon *const _this)>(0x1664FE0);
	static inline auto FFireWeapon = PreyFunction<void(CArkWeapon *const _this)>(0x16659B0);
	static inline auto FGetSpawnPosition = PreyFunction<std::pair<bool,Vec3>(CArkWeapon const *const _this, const int _ignoreCollisionType, IEntity *const _pAttachEntity)>(0x1667110);
	static inline auto FOnAmmoDepleted = PreyFunction<void(CArkWeapon *const _this)>(0x166BC80);
	static inline auto FUpdateAmmoCountUI = PreyFunction<void(CArkWeapon const *const _this)>(0x166EAD0);
	static inline auto FEnableCancelTutorial = PreyFunction<void(CArkWeapon *const _this, string _tutorialHintString)>(0x1665210);
	static inline auto FDisableCancelTutorial = PreyFunction<void(CArkWeapon *const _this)>(0x1664E90);
	static inline auto FEnableChargeFilter = PreyFunction<void(CArkWeapon *const _this, const bool _bEnable)>(0x1665390);
	static inline auto FGetBaseDamage = PreyFunction<int(CArkWeapon const *const _this)>(0x158AEF0);
	static inline auto FGetModifiedDamage = PreyFunction<int(CArkWeapon const *const _this, std::vector<unsigned __int64> const &_modifiers)>(0x158AEF0);
	static inline auto FGetSignalModifiers = PreyFunction<std::vector<unsigned __int64>(CArkWeapon const *const _this)>(0x1667010);
	static inline auto FCalculateBaseDamage = PreyFunction<float(CArkWeapon const *const _this, uint64_t _pkgId, uint64_t _dmgSignal)>(0x16641A0);
	static inline auto FSpawnMuzzleLight = PreyFunction<void(CArkWeapon *const _this, bool _bAttach)>(0x166E130);
	static inline auto FStopMuzzleLight = PreyFunction<void(CArkWeapon *const _this)>(0x166E5C0);
	static inline auto FUpdateConditionFeedback = PreyFunction<void(CArkWeapon const *const _this)>(0x166F2A0);
	static inline auto FUpdateArkLightColor = PreyFunction<void(CArkWeapon const *const _this, CArkWeapon::EArkWeaponStatus _condition)>(0x166F130);
	static inline auto FInitializeCondition = PreyFunction<void(CArkWeapon *const _this)>(0x16686D0);
	static inline auto FSpawnAmmo = PreyFunction<unsigned(CArkWeapon *const _this)>(0x166DF70);
	static inline auto FAttachToHand = PreyFunction<bool(CArkWeapon *const _this)>(0x1663A40);
	static inline auto FGetOwnerActionController = PreyFunction<IActionController *(CArkWeapon const *const _this)>(0x1666D50);
	static inline auto FUpdateAnimationScopeContexts = PreyFunction<void(CArkWeapon *const _this)>(0x166EC80);
	static inline auto FIsItemWeaponAmmo = PreyFunction<bool(CArkWeapon *const _this, unsigned _itemId)>(0x166A080);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName(CArkWeapon const *const _this)>(0x13883F0);
	static inline auto FInitializeAmmoCount = PreyFunction<void(CArkWeapon *const _this)>(0x16684F0);
	static inline auto FGiveAmmoClip = PreyFunction<void(CArkWeapon *const _this, const unsigned _pickerId)>(0x16682E0);
	static inline auto FOnInteraction = PreyFunction<bool(CArkWeapon *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x166C260);
	static inline auto FTestInteraction = PreyFunction<bool(CArkWeapon const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x166E810);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(CArkWeapon const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x166CBD0);
	static inline auto FDisplayTutorialCard = PreyFunction<void(CArkWeapon const *const _this)>(0x1664F90);
	static inline auto FUpdateStatusIcon = PreyFunction<void(CArkWeapon const *const _this, bool _bForceRemove)>(0x166F620);
};

