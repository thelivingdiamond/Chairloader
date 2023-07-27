// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkRegularOutcome.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ArkItem.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkStatsComponent.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/ArkPlayerLight.h>
#include <Prey/GameDll/ark/player/IArkPlayerLightOwner.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/playerIArkCombatFocusListener.h>
#include <Prey/GameDll/ark/ui/ArkInventoryUI.h>
#include <Prey/GameDll/ark/weapons/IArkWeapon.h>

struct ArkInteractionTestResult;
class ArkWeaponModifier;
enum class EArkInteractionMode;
enum class EArkInteractionType;
class IAction;
class IActionController;
class IArkInventory;
struct IArkWeaponEventListener;
struct IAttachment;
struct IAttachmentManager;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IEntityClass;
struct IGameObject;
struct ILoadGame;
struct IParticleEffect;
struct ISaveGame;
struct IUIElement;
struct SActionEvent;
struct SEntityEvent;
struct SEntityUpdateContext;

// CArkWeapon
// Header:  Prey/GameDll/ark/weapons/ArkWeapon.h
class CArkWeapon
	: public IArkWeapon
	, public CArkItem
	, public IArkInventoryListener
	, public IArkStatsListener
	, public IEntityEventListener
	, public IArkCombatFocusListener
	, public IGameFrameworkListener
	, public IArkPlayerLightOwner
{ // Size=1216 (0x4C0)
public:
	enum class EArkWeaponStatus
	{
		normal = 0,
		damaged = 1,
		broken = 2,
		invalid = 3,
	};

	// CArkWeapon::ReticleInfo
	// Header:  Prey/GameDll/ark/weapons/ArkWeapon.h
	struct ReticleInfo
	{ // Size=24 (0x18)
		IEntity* m_pEntity;
		Vec3 m_position;

#if 0
		ReticleInfo();
#endif
	};

	// CArkWeapon::ArkWeaponMods
	// Header:  Prey/GameDll/ark/weapons/ArkWeapon.h
	struct ArkWeaponMods
	{ // Size=64 (0x40)
		std::unordered_map<uint64_t, int> m_weaponModIds;

		void AddMod(const uint64_t _modId) { FAddMod(this, _modId); }
		int GetCurrentLevel(const uint64_t _modId) const { return FGetCurrentLevel(this, _modId); }
		void Clear() { FClear(this); }
		unsigned GetTotalLevel() const { return FGetTotalLevel(this); }

#if 0
		void Serialize(TSerialize _arg0_);
#endif

		static inline auto FAddMod = PreyFunction<void(CArkWeapon::ArkWeaponMods* const _this, const uint64_t _modId)>(0x1662F00);
		static inline auto FGetCurrentLevel = PreyFunction<int(const CArkWeapon::ArkWeaponMods* const _this, const uint64_t _modId)>(0x1665F70);
		static inline auto FClear = PreyFunction<void(CArkWeapon::ArkWeaponMods* const _this)>(0x13C24D0);
		static inline auto FGetTotalLevel = PreyFunction<unsigned(const CArkWeapon::ArkWeaponMods* const _this)>(0x16675E0);
	};

	// CArkWeapon::ArkIronsightsTargetInfo
	// Header:  Prey/GameDll/ark/weapons/ArkWeapon.h
	struct ArkIronsightsTargetInfo
	{ // Size=16 (0x10)
		IEntityClass* m_entityClass;
		string m_targetBoneOrAttachName;

#if 0
		ArkIronsightsTargetInfo(IEntityClass* _arg0_, const string _arg1_);
		bool operator==(IEntityClass* _arg0_) const;
#endif
	};

	ArkRegularOutcome m_criticalOutcome;
	ArkStatsComponent m_statsComponent;
	CArkWeapon::ArkWeaponMods m_weaponMods;
	EntityEffects::CEffectsController m_effectController;
	IAttachment* m_pAttachment = nullptr;
	ArkSimpleTimer m_attackTimer;
	ArkSimpleTimer m_hudDamageIconTimer;
	bool m_bAmmoIsPooled = false;
	bool m_bIsAttacking = false;
	bool m_bWantsToAttack = false;
	bool m_bWantsToReload = false;
	_smart_ptr<IAction> m_pWeaponIdleAction;
	_smart_ptr<IAction> m_pWeaponFireAction;
	string m_pWeaponClassName;
	string m_ammoArchetypeName;
	string m_ammoSpawnPointName;
	string m_uiElementName;
	unsigned m_weaponUIType;
	Vec3 m_defaultLightColor = Vec3(ZERO);
	Vec3 m_damagedLightColor = Vec3(ZERO);
	Vec3 m_brokenLightColor = Vec3(ZERO);
	bool m_bAutoload = false;
	bool m_bAllowInterruptReloading = false;
	bool m_bAffectedByDisruption = false;
	bool m_bTakesHazardDamage = false;
	float m_idleBreakDelayTime = 0.0f;
	float m_ironsightsTargetDistance = 0.0f;
	float m_ironsightsTargetWidth = 0.0f;
	float m_ironsightsTargetSpeed = 1.0f;
	float m_ironsightsMaxAngularVelocity = 0.0f;
	float m_ironsightsSuccessDistance = 0.001f;
	float m_aimAssistRangeMax = 0.0f;
	float m_ammoLootImpulse = 0.0f;
	float m_condition = 0.0f;
	float m_malfunctionThreshold = 0.0f;
	float m_malfunctionRate = 0.0f;
	uint64_t m_disrepairModifier = 0;
	uint64_t m_tutorialPrompt = 0;
	uint64_t m_tutorialCard = 0;
	int m_minStartAmmo = 0;
	int m_maxStartAmmo = 0;
	int m_disruptionSubMatIndex = -1;
	ArkEntityAttachmentEffect m_disruptionVFX;
	std::vector<ArkMaterialParamOverride> m_originalInterferenceValues;
	float m_spawnFromCameraTestDistance = 1.1f;
	float m_spawnBehindCameraDistance = 0.0f;
	string m_upgradeInfoDesc;
	string m_focusDecription;
	CCryName m_leverageBaseName;
	string m_muzzleLightAttachName;
	_smart_ptr<IParticleEffect> m_pMuzzleLight;
	static inline auto m_ironsightsTargetClasses = PreyGlobal<std::vector<CArkWeapon::ArkIronsightsTargetInfo>>(0x2C07F90);
	static inline auto m_bIronsightsTargetClassesLoaded = PreyGlobal<bool>(0x2C07F88);
	std::vector<IArkWeaponEventListener*> m_listeners;
	ArkPlayerLightEntity m_playerLight;
	const SMannequinItemParams::FragmentIDs* m_pFragmentIDs = nullptr;
	IUIElement* m_pUIElement = nullptr;
	int m_zoomHandle = 0;
	int m_numAmmoLoaded = 0;
	bool m_bIdleBreakEnabled = true;
	bool m_bShouldFinishReloading = false;
	bool m_bCancelTutorialEnabled = false;
	bool m_bIsReadyToAttack = true;
	bool m_bIsReloading = false;
	bool m_bIsUnequipping = false;
	const bool m_bRetainPhysicsOnEquip;
	unsigned m_ironsightsTargetId = 0;
	string m_ironsightsBoneOrAttachName;
	bool m_bHasAmmoBeenLooted = false;
	IEntityArchetype* m_pAmmoPickupArchetype = nullptr;
	ArkAudioTrigger m_startMalfunctionTrigger;
	ArkAudioTrigger m_stopMalfunctionTrigger;
	ArkAudioTrigger m_brokeTrigger;
	ArkAudioTrigger m_ammoPickupTrigger;

	CArkWeapon(bool _bRetainPhysicsOnEquip);
	virtual ~CArkWeapon();
	virtual bool Init(IGameObject* _pGameObject) { return FInit(this, _pGameObject); }
	virtual void PostInit(IGameObject* _pGameObject) { FPostInit(this, _pGameObject); }
	virtual void Release() { FRelease(this); }
	virtual void FullSerialize(TSerialize _ser) { FFullSerialize(this, _ser); }
	virtual void SerializeLTL(TSerialize _ser) { FSerializeLTL(this, _ser); }
	virtual void PostSerialize() { FPostSerialize(this); }
	virtual void Update(SEntityUpdateContext& _ctx, int _slot) { FUpdate(this, _ctx, _slot); }
	virtual void ProcessEvent(SEntityEvent& _event) { FProcessEvent(this, _event); }
	virtual void GetMemoryUsage(ICrySizer* _s) const { FGetMemoryUsage(this, _s); }
	virtual void OnPostUpdate(float fDeltaTime) { FOnPostUpdate(this, fDeltaTime); }
	virtual void OnSaveGame(ISaveGame* pSaveGame) { FOnSaveGame(this, pSaveGame); }
	virtual void OnLoadGame(ILoadGame* pLoadGame) { FOnLoadGame(this, pLoadGame); }
	virtual void OnLevelEnd(const char* nextLevel) { FOnLevelEnd(this, nextLevel); }
	virtual void OnActionEvent(const SActionEvent& event) { FOnActionEvent(this, event); }
	virtual void OnPreRender() { FOnPreRender(this); }
	static uint64_t GetWeaponModArchetypeId() { return FGetWeaponModArchetypeId(); }
	virtual bool PickUp(const unsigned _pickerId, bool _bScale) { return FPickUp(this, _pickerId, _bScale); }
	virtual bool GiveOwner(IArkInventory* _pInventory) { return FGiveOwner(this, _pInventory); }
	virtual void Drop(int _count, const Vec3* const _altPosition) { FDrop(this, _count, _altPosition); }
	virtual bool IsWeapon() const { return FIsWeapon(this); }
	virtual bool IsEquippable() const { return FIsEquippable(this); }
	virtual const char* GetIcon() const { return FGetIcon(this); }
	virtual const char* GetHUDIcon() const { return FGetHUDIcon(this); }
	virtual bool ShowsAmmoOnHUD() const { return FShowsAmmoOnHUD(this); }
	virtual wstring GetDisplayName(const int _count) const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetDisplayName(this, reinterpret_cast<wstring*>(_return_buf_), _count); }
	void SetupAttachment() { FSetupAttachment(this); }
	virtual void OnEquip() { FOnEquip(this); }
	virtual void OnUnequip(const bool _bUnselect) { FOnUnequip(this, _bUnselect); }
	void UnequipOnPlayer() const { FUnequipOnPlayer(this); }
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId) { FOnItemAdded(this, _itemId, _originalId); }
	virtual void OnItemRemoved(unsigned _itemId) { FOnItemRemoved(this, _itemId); }
	virtual void OnItemCountChanged(unsigned _itemId) { FOnItemCountChanged(this, _itemId); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event) { FOnEntityEvent(this, _pEntity, _event); }
	virtual bool OnActionAttackUse(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value) { return FOnActionAttackUse(this, _entityId, _actionId, _activationMode, _value); }
	virtual bool OnActionAttackPrimary(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value) { return FOnActionAttackPrimary(this, _entityId, _actionId, _activationMode, _value); }
	virtual bool OnActionReload(unsigned _entityId, const CCryName& _actionId, int _activationMode, float _value) { return FOnActionReload(this, _entityId, _actionId, _activationMode, _value); }
	virtual void SustainedAttack() { FSustainedAttack(this); }
	virtual bool CanStartAttack() { return FCanStartAttack(this); }
	virtual void CancelCharge() { FCancelCharge(this); }
	virtual void ThrowingIdle() { FThrowingIdle(this); }
	virtual void ThrowingCancel(const bool _bCheckIdle) { FThrowingCancel(this, _bCheckIdle); }
	virtual void OnReloadStart() { FOnReloadStart(this); }
	static CArkWeapon* GetWeaponFromEntityId(const unsigned _entityId) { return FGetWeaponFromEntityId(_entityId); }
	virtual void AutoloadAmmo() { FAutoloadAmmo(this); }
	virtual void StartReloadAmmo() { FStartReloadAmmo(this); }
	virtual void ContinueReloadAmmo() { FContinueReloadAmmo(this); }
	virtual void ReloadAmmo(const bool _bContinueReload) { FReloadAmmo(this, _bContinueReload); }
	virtual void StopReloadAmmo(const bool _bInterrupted) { FStopReloadAmmo(this, _bInterrupted); }
	virtual void ReadjustAmmo() { FReadjustAmmo(this); }
	virtual void SetWeaponAmmoCount(const int _weaponAmmoCount) { FSetWeaponAmmoCount(this, _weaponAmmoCount); }
	virtual int GetWeaponAmmoCount() const { return FGetWeaponAmmoCount(this); }
	virtual int GetInventoryAmmoCount() const { return FGetInventoryAmmoCount(this); }
	virtual string GetUIAmmoCountString() const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetUIAmmoCountString(this, reinterpret_cast<string*>(_return_buf_)); }
	virtual const string& GetAmmoArchetypeName() const { return FGetAmmoArchetypeName(this); }
	virtual void RegisterListener(IArkWeaponEventListener* _pListener) { FRegisterListener(this, _pListener); }
	virtual void UnregisterListener(IArkWeaponEventListener* _pListener) { FUnregisterListener(this, _pListener); }
	virtual bool StartAttack() { return FStartAttack(this); }
	virtual bool ContinueAttack() { return FContinueAttack(this); }
	virtual bool StopAttack() { return FStopAttack(this); }
	virtual void EnterAttackAction() { FEnterAttackAction(this); }
	virtual void ExitAttackAction() { FExitAttackAction(this); }
	virtual void ExitSelectAction() { FExitSelectAction(this); }
	virtual void ThrowGrenade() { FThrowGrenade(this); }
	virtual void DeployGrenade() { FDeployGrenade(this); }
	virtual void ReloadGrenade() { FReloadGrenade(this); }
	virtual void ProjectileDestroyed() { FProjectileDestroyed(this); }
	virtual void StartSprinting() { FStartSprinting(this); }
	virtual float GetAimRange() const { return FGetAimRange(this); }
	virtual Vec3 GetReticlePosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetReticlePosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	float GetStatFloat(const CCryName& _statName) const { return FGetStatFloat(this, _statName); }
	int GetStatInt(const CCryName& _statName) const { return FGetStatInt(this, _statName); }
	float GetStatFloatPlayer(const CCryName& _statName) const { return FGetStatFloatPlayer(this, _statName); }
	virtual int GetAmmoCost() const { return FGetAmmoCost(this); }
	virtual int GetClipSize() const { return FGetClipSize(this); }
	virtual float GetDegradationRate() const { return FGetDegradationRate(this); }
	void SetWeaponCondition(float _condition) { FSetWeaponCondition(this, _condition); }
	bool DoesWeaponDegrade() const { return FDoesWeaponDegrade(this); }
	void DegradeWeaponCondition() { FDegradeWeaponCondition(this); }
	void RepairWeapon(int _numRepairs) { FRepairWeapon(this, _numRepairs); }
	int GetNumPartsToFullyRepair() const { return FGetNumPartsToFullyRepair(this); }
	bool CanRepair() const { return FCanRepair(this); }
	bool IsBroken(float _condition) const { return FIsBroken(this, _condition); }
	void ShowWeaponDamageIndicator() { FShowWeaponDamageIndicator(this); }
	float GetWalkSpeedMultiplier() const { return FGetWalkSpeedMultiplier(this); }
	float GetCameraSpeedMultiplier() const { return FGetCameraSpeedMultiplier(this); }
	virtual float GetWalkSpeedStat() const { return FGetWalkSpeedStat(this); }
	virtual float GetZoomedWalkSpeedStat() const { return FGetZoomedWalkSpeedStat(this); }
	virtual float GetCameraSpeedStat() const { return FGetCameraSpeedStat(this); }
	virtual float GetZoomedCameraSpeedStat() const { return FGetZoomedCameraSpeedStat(this); }
	virtual float GetDispersion() const { return FGetDispersion(this); }
	bool CanInstallMod(const uint64_t _modId) const { return FCanInstallModOv1(this, _modId); }
	bool CanInstallMod(const ArkWeaponModifier* _pWeaponModifier) const { return FCanInstallModOv0(this, _pWeaponModifier); }
	bool CanUpgrade() const { return FCanUpgrade(this); }
	void InstallMod(const uint64_t _modId, const unsigned _kitId) { FInstallModOv1(this, _modId, _kitId); }
	void InstallMod(const ArkWeaponModifier* _pWeaponModifier, unsigned _kitId) { FInstallModOv0(this, _pWeaponModifier, _kitId); }
	void PopulateWeaponInfo(CArkInventoryUI::SelectedWeaponInfo& _weaponInfo) const { FPopulateWeaponInfo(this, _weaponInfo); }
	wstring GetWeaponModDescription(uint64_t _modId, int _modLevel) const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetWeaponModDescription(this, reinterpret_cast<wstring*>(_return_buf_), _modId, _modLevel); }
	static int GetWeaponKitCount() { return FGetWeaponKitCount(); }
	virtual void UpdateDispersion() { FUpdateDispersion(this); }
	void ApplySignalModifiers(const unsigned _entityId) const { FApplySignalModifiers(this, _entityId); }
	void RemoveSignalModifiers(const unsigned _entityId) const { FRemoveSignalModifiers(this, _entityId); }
	Vec3 GetIronsightsTargetPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetIronsightsTargetPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	virtual bool IsProximity() const { return FIsProximity(this); }
	virtual CCryName GetReticleName() const { alignas(CCryName) std::byte _return_buf_[sizeof(CCryName)]; return *FGetReticleName(this, reinterpret_cast<CCryName*>(_return_buf_)); }
	void PlayAction(_smart_ptr<IAction> _pAction, float _speedOverride) const { FPlayAction(this, _pAction, _speedOverride); }
	bool DetachFromHand() { return FDetachFromHand(this); }
	float GetImpulseScaleForEntity(const IEntity* const _pEntity) const { return FGetImpulseScaleForEntity(this, _pEntity); }
	IUIElement* GetUIElement() { return FGetUIElement(this); }
	bool IsEquipped() const { return FIsEquipped(this); }
	void FindIronsightsTarget() { FFindIronsightsTarget(this); }
	virtual bool HasTarget() const { return FHasTarget(this); }
	virtual float GetTargetLockPercentage() const { return FGetTargetLockPercentage(this); }
	virtual float GetTargetLockTimeOutElapsedSec() const { return FGetTargetLockTimeOutElapsedSec(this); }
	virtual void OnAttackStopped() { FOnAttackStopped(this); }
	virtual void OnMalfunctionStart() { FOnMalfunctionStart(this); }
	virtual void OnMalfunctionEvent() { FOnMalfunctionEvent(this); }
	void OnMuzzleFlash() { FOnMuzzleFlash(this); }
	virtual float GetDamageScale(const float _distance) const { return FGetDamageScale(this, _distance); }
	IEntityArchetype* GetAmmoPickupArchetype() const { return FGetAmmoPickupArchetype(this); }
	bool ShouldTreatAsFirstPickup() const { return FShouldTreatAsFirstPickup(this); }
	bool IsDisrupted() const { return FIsDisrupted(this); }
	virtual bool ForceCancelCharge() { return FForceCancelCharge(this); }
	virtual bool IsCharging() const { return FIsCharging(this); }
	void UpdateDisruptedVisuals(bool _bDisrupted) { FUpdateDisruptedVisuals(this, _bDisrupted); }
	CArkWeapon::ReticleInfo GetReticleInfoForFiring() const { alignas(CArkWeapon::ReticleInfo) std::byte _return_buf_[sizeof(CArkWeapon::ReticleInfo)]; return *FGetReticleInfoForFiring(this, reinterpret_cast<CArkWeapon::ReticleInfo*>(_return_buf_)); }
	void ApplyRecoil() const { FApplyRecoil(this); }
	virtual void LoadCachedProperties() { FLoadCachedProperties(this); }
	virtual void InitializeStats() { FInitializeStats(this); }
	void UpdateTimers(float _frameTime) { FUpdateTimers(this, _frameTime); }
	void UpdateAnimationTag(bool _bSelected, const char* _tagName) { FUpdateAnimationTag(this, _bSelected, _tagName); }
	virtual _smart_ptr<IAction> ConstructReloadAction(const int _fragmentId) const { alignas(_smart_ptr<IAction>) std::byte _return_buf_[sizeof(_smart_ptr<IAction>)]; return *FConstructReloadAction(this, reinterpret_cast<_smart_ptr<IAction>*>(_return_buf_), _fragmentId); }
	void AttachToShadowHand(bool _bAttach) { FAttachToShadowHand(this, _bAttach); }
	virtual void ConsumeAmmo() { FConsumeAmmo(this); }
	virtual bool CanLoadAmmo() const { return FCanLoadAmmo(this); }
	virtual bool HasAmmo() const { return FHasAmmo(this); }
	void StopSprinting() const { FStopSprinting(this); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue) { FOnStatChange(this, _ownerId, _stat64i32, _previousValue, _newValue); }
	virtual void OnCombatFocusChanged(bool _bActive) { FOnCombatFocusChanged(this, _bActive); }
	void UpdateCritical() { FUpdateCritical(this); }
	bool ShouldMalfunction() const { return FShouldMalfunction(this); }
	void DoMalfunction() { FDoMalfunction(this); }
	void FireWeapon() { FFireWeapon(this); }
	std::pair<bool, Vec3> GetSpawnPosition(const int _ignoreCollisionType, IEntity* const _pAttachEntity) const { alignas(std::pair<bool, Vec3>) std::byte _return_buf_[sizeof(std::pair<bool, Vec3>)]; return *FGetSpawnPosition(this, reinterpret_cast<std::pair<bool, Vec3>*>(_return_buf_), _ignoreCollisionType, _pAttachEntity); }
	virtual void OnAmmoDepleted() { FOnAmmoDepleted(this); }
	virtual void UpdateAmmoCountUI() const { FUpdateAmmoCountUI(this); }
	virtual void EnableCancelTutorial(const string _tutorialHintString) { FEnableCancelTutorial(this, _tutorialHintString); }
	virtual void DisableCancelTutorial() { FDisableCancelTutorial(this); }
	void EnableChargeFilter(const bool _bEnable) { FEnableChargeFilter(this, _bEnable); }
	virtual int GetBaseDamage() const { return FGetBaseDamage(this); }
	virtual int GetModifiedDamage(const std::vector<uint64_t>& _modifiers) const { return FGetModifiedDamage(this, _modifiers); }
	std::vector<uint64_t> GetSignalModifiers() const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetSignalModifiers(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_)); }
	float CalculateBaseDamage(uint64_t _pkgId, uint64_t _dmgSignal) const { return FCalculateBaseDamage(this, _pkgId, _dmgSignal); }
	void SpawnMuzzleLight(bool _bAttach) { FSpawnMuzzleLight(this, _bAttach); }
	void StopMuzzleLight() { FStopMuzzleLight(this); }
	void UpdateConditionFeedback() const { FUpdateConditionFeedback(this); }
	void UpdateArkLightColor(CArkWeapon::EArkWeaponStatus _condition) const { FUpdateArkLightColor(this, _condition); }
	void InitializeCondition() { FInitializeCondition(this); }
	unsigned SpawnAmmo() { return FSpawnAmmo(this); }
	bool AttachToHand() { return FAttachToHand(this); }
	IActionController* GetOwnerActionController() const { return FGetOwnerActionController(this); }
	void UpdateAnimationScopeContexts() { FUpdateAnimationScopeContexts(this); }
	bool IsItemWeaponAmmo(unsigned _itemId) { return FIsItemWeaponAmmo(this, _itemId); }
	virtual CCryName GetPlayerWeaponSpecificCritChanceStatName() const { alignas(CCryName) std::byte _return_buf_[sizeof(CCryName)]; return *FGetPlayerWeaponSpecificCritChanceStatName(this, reinterpret_cast<CCryName*>(_return_buf_)); }
	void InitializeAmmoCount() { FInitializeAmmoCount(this); }
	void GiveAmmoClip(const unsigned _pickerId) { FGiveAmmoClip(this, _pickerId); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity) { return FOnInteraction(this, _interaction, _mode, _pEntity); }
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const { return FTestInteraction(this, _pEntity, _interactionInfo, _mode, _result); }
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const { return FPopulateInteractionInfo(this, _pEntity, _interactionArray); }
	void DisplayTutorialCard() const { FDisplayTutorialCard(this); }
	void UpdateStatusIcon(bool _bForceRemove) const { FUpdateStatusIcon(this, _bForceRemove); }

#if 0
	bool CanPickUp(unsigned _arg0_) const;
	bool IsZoomingIn() const;
	void HideAttachment(const bool _arg0_) const;
	bool IsAttacking() const;
	bool IsReadyToAttack() const;
	void SetIsReadyToAttack(const bool _arg0_);
	bool IsReloading() const;
	void SetIsReloading(const bool _arg0_);
	bool ShouldFinishReloading() const;
	void SetShouldFinishReloading(const bool _arg0_);
	const SMannequinItemParams::FragmentIDs* const GetFragmentIDs() const;
	float GetReticlePositionRange() const;
	const ArkStatsComponent& GetStatsComponent() const;
	float GetWeaponCondition() const;
	int GetUIWeaponCondition() const;
	bool TakesHazardDamage() const;
	void BreakAndUnequip();
	float GetIdleBreakDelayTme() const;
	bool IsIdleBreakEnabled() const;
	void EnableIdleBreaks(const bool _arg0_);
	float GetIronsightsMaxAngularVelocity() const;
	float GetIronsightsSuccessDistance() const;
	float GetIronsightsSpeed() const;
	unsigned GetIronsightsTargetId() const;
	void SetIronsightsTargetId(const unsigned _arg0_);
	bool IsUnequipping() const;
	float GetAimAssistRangeMax() const;
	bool RollCritical() const;
	string GetFocusModeDescription() const;
	void CloseWeaponDamageIndicator();
	const Matrix34 GetWorldTM() const;
	void InhibitSprinting(const bool _arg0_) const;
	Vec3 GetSpawnDirection(const Vec3& _arg0_) const;
	CArkWeapon::EArkWeaponStatus GetConditionStatus() const;
	void DrawSlot(int _arg0_, bool _arg1_, bool _arg2_);
	void ClearAnimationScopeContexts();
	IAttachmentManager* GetAttachmentManager(const unsigned _arg0_);
	void TriggerOutOfAmmoUI() const;
	bool AreAllModsInstalled() const;
#endif

	static inline auto FCArkWeaponOv1 = PreyFunction<void(CArkWeapon* const _this, bool _bRetainPhysicsOnEquip)>(0x1662580);
	static inline auto FBitNotCArkWeapon = PreyFunction<void(CArkWeapon* const _this)>(0x1662A50);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject * _pGameObject)>(0x1668490);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject * _pGameObject)>(0x166CF80);
	static inline auto FRelease = PreyFunction<void(CArkItem* const _this)>(0x166D280);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x1665C30);
	static inline auto FSerializeLTL = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x166D680);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem* const _this)>(0x166D080);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext & _ctx, int _slot)>(0x166E960);
	static inline auto FProcessEvent = PreyFunction<void(CArkItem* const _this, SEntityEvent & _event)>(0x166D100);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer * _s)>(0x1666CB0);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame * pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame * pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent & event)>(0xA13080);
	static inline auto FOnPreRender = PreyFunction<void(IGameFrameworkListener* const _this)>(0xA13080);
	static inline auto FGetWeaponModArchetypeId = PreyFunction<uint64_t()>(0x16677B0);
	static inline auto FPickUp = PreyFunction<bool(CArkItem* const _this, const unsigned _pickerId, bool _bScale)>(0x166C8E0);
	static inline auto FGiveOwner = PreyFunction<bool(CArkItem* const _this, IArkInventory * _pInventory)>(0x1668430);
	static inline auto FDrop = PreyFunction<void(CArkItem* const _this, int _count, const Vec3* const _altPosition)>(0x1665180);
	static inline auto FIsWeapon = PreyFunction<bool(const CArkItem* const _this)>(0x1B933B0);
	static inline auto FIsEquippable = PreyFunction<bool(const CArkItem* const _this)>(0x1B933B0);
	static inline auto FGetIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x16664F0);
	static inline auto FGetHUDIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x1666270);
	static inline auto FShowsAmmoOnHUD = PreyFunction<bool(const CArkWeapon* const _this)>(0xDD23F0);
	static inline auto FGetDisplayName = PreyFunction<wstring * (const CArkItem* const _this, wstring * _return_value_, const int _count)>(0x16660B0);
	static inline auto FSetupAttachment = PreyFunction<void(CArkWeapon* const _this)>(0x166D9F0);
	static inline auto FOnEquip = PreyFunction<void(CArkWeapon* const _this)>(0x166BDA0);
	static inline auto FOnUnequip = PreyFunction<void(CArkWeapon* const _this, const bool _bUnselect)>(0x166C5A0);
	static inline auto FUnequipOnPlayer = PreyFunction<void(const CArkWeapon* const _this)>(0x166E8A0);
	static inline auto FOnItemAdded = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId, unsigned _originalId)>(0x166C470);
	static inline auto FOnItemRemoved = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId)>(0x166C4B0);
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId)>(0x166C470);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity * _pEntity, SEntityEvent & _event)>(0x166BD20);
	static inline auto FOnActionAttackUse = PreyFunction<bool(CArkWeapon* const _this, unsigned _entityId, const CCryName & _actionId, int _activationMode, float _value)>(0xDD23F0);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(CArkWeapon* const _this, unsigned _entityId, const CCryName & _actionId, int _activationMode, float _value)>(0x166BB50);
	static inline auto FOnActionReload = PreyFunction<bool(CArkWeapon* const _this, unsigned _entityId, const CCryName & _actionId, int _activationMode, float _value)>(0x166BC60);
	static inline auto FSustainedAttack = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FCanStartAttack = PreyFunction<bool(CArkWeapon* const _this)>(0x16643E0);
	static inline auto FCancelCharge = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FThrowingIdle = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FThrowingCancel = PreyFunction<void(CArkWeapon* const _this, const bool _bCheckIdle)>(0xA13080);
	static inline auto FOnReloadStart = PreyFunction<void(CArkWeapon* const _this)>(0x138A940);
	static inline auto FGetWeaponFromEntityId = PreyFunction<CArkWeapon * (const unsigned _entityId)>(0x1667720);
	static inline auto FAutoloadAmmo = PreyFunction<void(CArkWeapon* const _this)>(0x1664160);
	static inline auto FStartReloadAmmo = PreyFunction<void(CArkWeapon* const _this)>(0x166E420);
	static inline auto FContinueReloadAmmo = PreyFunction<void(CArkWeapon* const _this)>(0x1664930);
	static inline auto FReloadAmmo = PreyFunction<void(CArkWeapon* const _this, const bool _bContinueReload)>(0x166D400);
	static inline auto FStopReloadAmmo = PreyFunction<void(CArkWeapon* const _this, const bool _bInterrupted)>(0x166E630);
	static inline auto FReadjustAmmo = PreyFunction<void(CArkWeapon* const _this)>(0x166D1E0);
	static inline auto FSetWeaponAmmoCount = PreyFunction<void(CArkWeapon* const _this, const int _weaponAmmoCount)>(0x166D840);
	static inline auto FGetWeaponAmmoCount = PreyFunction<int(const CArkWeapon* const _this)>(0x138A0D0);
	static inline auto FGetInventoryAmmoCount = PreyFunction<int(const CArkWeapon* const _this)>(0x1666A50);
	static inline auto FGetUIAmmoCountString = PreyFunction<string * (const CArkWeapon* const _this, string * _return_value_)>(0x1667600);
	static inline auto FGetAmmoArchetypeName = PreyFunction<const string & (const CArkWeapon* const _this)>(0x1248410);
	static inline auto FRegisterListener = PreyFunction<void(CArkWeapon* const _this, IArkWeaponEventListener * _pListener)>(0x166D220);
	static inline auto FUnregisterListener = PreyFunction<void(CArkWeapon* const _this, IArkWeaponEventListener * _pListener)>(0x166E900);
	static inline auto FStartAttack = PreyFunction<bool(CArkWeapon* const _this)>(0x166E320);
	static inline auto FContinueAttack = PreyFunction<bool(CArkWeapon* const _this)>(0x16648C0);
	static inline auto FStopAttack = PreyFunction<bool(CArkWeapon* const _this)>(0x166E530);
	static inline auto FEnterAttackAction = PreyFunction<void(CArkWeapon* const _this)>(0x16653B0);
	static inline auto FExitAttackAction = PreyFunction<void(CArkWeapon* const _this)>(0x16653C0);
	static inline auto FExitSelectAction = PreyFunction<void(CArkWeapon* const _this)>(0x16654A0);
	static inline auto FThrowGrenade = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FDeployGrenade = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FReloadGrenade = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FProjectileDestroyed = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FStartSprinting = PreyFunction<void(CArkWeapon* const _this)>(0x37CD00);
	static inline auto FGetAimRange = PreyFunction<float(const CArkWeapon* const _this)>(0x1665E70);
	static inline auto FGetReticlePosition = PreyFunction<Vec3 * (const CArkWeapon* const _this, Vec3 * _return_value_)>(0x1666F70);
	static inline auto FGetStatFloat = PreyFunction<float(const CArkWeapon* const _this, const CCryName & _statName)>(0x1667570);
	static inline auto FGetStatInt = PreyFunction<int(const CArkWeapon* const _this, const CCryName & _statName)>(0x16675C0);
	static inline auto FGetStatFloatPlayer = PreyFunction<float(const CArkWeapon* const _this, const CCryName & _statName)>(0x1667580);
	static inline auto FGetAmmoCost = PreyFunction<int(const CArkWeapon* const _this)>(0x1665E90);
	static inline auto FGetClipSize = PreyFunction<int(const CArkWeapon* const _this)>(0x1665F50);
	static inline auto FGetDegradationRate = PreyFunction<float(const CArkWeapon* const _this)>(0x1666060);
	static inline auto FSetWeaponCondition = PreyFunction<void(CArkWeapon* const _this, float _condition)>(0x166D8E0);
	static inline auto FDoesWeaponDegrade = PreyFunction<bool(const CArkWeapon* const _this)>(0x1665130);
	static inline auto FDegradeWeaponCondition = PreyFunction<void(CArkWeapon* const _this)>(0x16649E0);
	static inline auto FRepairWeapon = PreyFunction<void(CArkWeapon* const _this, int _numRepairs)>(0x166D600);
	static inline auto FGetNumPartsToFullyRepair = PreyFunction<int(const CArkWeapon* const _this)>(0x1666CD0);
	static inline auto FCanRepair = PreyFunction<bool(const CArkWeapon* const _this)>(0x16643C0);
	static inline auto FIsBroken = PreyFunction<bool(const CArkWeapon* const _this, float _condition)>(0x1669FF0);
	static inline auto FShowWeaponDamageIndicator = PreyFunction<void(CArkWeapon* const _this)>(0x166DDC0);
	static inline auto FGetWalkSpeedMultiplier = PreyFunction<float(const CArkWeapon* const _this)>(0x1667690);
	static inline auto FGetCameraSpeedMultiplier = PreyFunction<float(const CArkWeapon* const _this)>(0x1665EC0);
	static inline auto FGetWalkSpeedStat = PreyFunction<float(const CArkWeapon* const _this)>(0x1667700);
	static inline auto FGetZoomedWalkSpeedStat = PreyFunction<float(const CArkWeapon* const _this)>(0x16682C0);
	static inline auto FGetCameraSpeedStat = PreyFunction<float(const CArkWeapon* const _this)>(0x1665F30);
	static inline auto FGetZoomedCameraSpeedStat = PreyFunction<float(const CArkWeapon* const _this)>(0x16682A0);
	static inline auto FGetDispersion = PreyFunction<float(const CArkWeapon* const _this)>(0xB5F050);
	static inline auto FCanInstallModOv1 = PreyFunction<bool(const CArkWeapon* const _this, const uint64_t _modId)>(0x1664300);
	static inline auto FCanInstallModOv0 = PreyFunction<bool(const CArkWeapon* const _this, const ArkWeaponModifier * _pWeaponModifier)>(0x1664220);
	static inline auto FCanUpgrade = PreyFunction<bool(const CArkWeapon* const _this)>(0x1664740);
	static inline auto FInstallModOv1 = PreyFunction<void(CArkWeapon* const _this, const uint64_t _modId, const unsigned _kitId)>(0x1669FA0);
	static inline auto FInstallModOv0 = PreyFunction<void(CArkWeapon* const _this, const ArkWeaponModifier * _pWeaponModifier, unsigned _kitId)>(0x1669D30);
	static inline auto FPopulateWeaponInfo = PreyFunction<void(const CArkWeapon* const _this, CArkInventoryUI::SelectedWeaponInfo & _weaponInfo)>(0x166CC80);
	static inline auto FGetWeaponModDescription = PreyFunction<wstring * (const CArkWeapon* const _this, wstring * _return_value_, uint64_t _modId, int _modLevel)>(0x1667830);
	static inline auto FGetWeaponKitCount = PreyFunction<int()>(0x1667770);
	static inline auto FUpdateDispersion = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FApplySignalModifiers = PreyFunction<void(const CArkWeapon* const _this, const unsigned _entityId)>(0x1663930);
	static inline auto FRemoveSignalModifiers = PreyFunction<void(const CArkWeapon* const _this, const unsigned _entityId)>(0x166D4F0);
	static inline auto FGetIronsightsTargetPos = PreyFunction<Vec3 * (const CArkWeapon* const _this, Vec3 * _return_value_)>(0x1666AC0);
	static inline auto FIsProximity = PreyFunction<bool(const CArkWeapon* const _this)>(0xDD23F0);
	static inline auto FGetReticleName = PreyFunction<CCryName * (const CArkWeapon* const _this, CCryName * _return_value_)>(0x138A040);
	static inline auto FPlayAction = PreyFunction<void(const CArkWeapon* const _this, _smart_ptr<IAction> _pAction, float _speedOverride)>(0x166CB50);
	static inline auto FDetachFromHand = PreyFunction<bool(CArkWeapon* const _this)>(0x1664A30);
	static inline auto FGetImpulseScaleForEntity = PreyFunction<float(const CArkWeapon* const _this, const IEntity* const _pEntity)>(0x1666760);
	static inline auto FGetUIElement = PreyFunction<IUIElement * (CArkWeapon* const _this)>(0x1667680);
	static inline auto FIsEquipped = PreyFunction<bool(const CArkWeapon* const _this)>(0x166A050);
	static inline auto FFindIronsightsTarget = PreyFunction<void(CArkWeapon* const _this)>(0x16655F0);
	static inline auto FHasTarget = PreyFunction<bool(const CArkWeapon* const _this)>(0xDD23F0);
	static inline auto FGetTargetLockPercentage = PreyFunction<float(const CArkWeapon* const _this)>(0xB5F050);
	static inline auto FGetTargetLockTimeOutElapsedSec = PreyFunction<float(const CArkWeapon* const _this)>(0xB5F050);
	static inline auto FOnAttackStopped = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FOnMalfunctionStart = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FOnMalfunctionEvent = PreyFunction<void(CArkWeapon* const _this)>(0xA13080);
	static inline auto FOnMuzzleFlash = PreyFunction<void(CArkWeapon* const _this)>(0x166C4F0);
	static inline auto FGetDamageScale = PreyFunction<float(const CArkWeapon* const _this, const float _distance)>(0x18C0850);
	static inline auto FGetAmmoPickupArchetype = PreyFunction<IEntityArchetype * (const CArkWeapon* const _this)>(0x1665EB0);
	static inline auto FShouldTreatAsFirstPickup = PreyFunction<bool(const CArkWeapon* const _this)>(0x166DD70);
	static inline auto FIsDisrupted = PreyFunction<bool(const CArkWeapon* const _this)>(0x166A000);
	static inline auto FForceCancelCharge = PreyFunction<bool(CArkWeapon* const _this)>(0xDD23F0);
	static inline auto FIsCharging = PreyFunction<bool(const CArkWeapon* const _this)>(0xDD23F0);
	static inline auto FUpdateDisruptedVisuals = PreyFunction<void(CArkWeapon* const _this, bool _bDisrupted)>(0x166F470);
	static inline auto FGetReticleInfoForFiring = PreyFunction<CArkWeapon::ReticleInfo * (const CArkWeapon* const _this, CArkWeapon::ReticleInfo * _return_value_)>(0x1666DE0);
	static inline auto FApplyRecoil = PreyFunction<void(const CArkWeapon* const _this)>(0x16630A0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x166A130);
	static inline auto FInitializeStats = PreyFunction<void(CArkWeapon* const _this)>(0x1668BF0);
	static inline auto FUpdateTimers = PreyFunction<void(CArkWeapon* const _this, float _frameTime)>(0x166F7B0);
	static inline auto FUpdateAnimationTag = PreyFunction<void(CArkWeapon* const _this, bool _bSelected, const char* _tagName)>(0x166F000);
	static inline auto FConstructReloadAction = PreyFunction<_smart_ptr<IAction>*(const CArkWeapon* const _this, _smart_ptr<IAction>*_return_value_, const int _fragmentId)>(0x16647B0);
	static inline auto FAttachToShadowHand = PreyFunction<void(CArkWeapon* const _this, bool _bAttach)>(0x1663D40);
	static inline auto FConsumeAmmo = PreyFunction<void(CArkWeapon* const _this)>(0x1664810);
	static inline auto FCanLoadAmmo = PreyFunction<bool(const CArkWeapon* const _this)>(0x1664350);
	static inline auto FHasAmmo = PreyFunction<bool(const CArkWeapon* const _this)>(0x1668460);
	static inline auto FStopSprinting = PreyFunction<void(const CArkWeapon* const _this)>(0x166E7C0);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName & _stat64i32, const float _previousValue, const float _newValue)>(0x166C580);
	static inline auto FOnCombatFocusChanged = PreyFunction<void(IArkCombatFocusListener* const _this, bool _bActive)>(0x166BD10);
	static inline auto FUpdateCritical = PreyFunction<void(CArkWeapon* const _this)>(0x166F300);
	static inline auto FShouldMalfunction = PreyFunction<bool(const CArkWeapon* const _this)>(0x166DD20);
	static inline auto FDoMalfunction = PreyFunction<void(CArkWeapon* const _this)>(0x1664FE0);
	static inline auto FFireWeapon = PreyFunction<void(CArkWeapon* const _this)>(0x16659B0);
	static inline auto FGetSpawnPosition = PreyFunction<std::pair<bool, Vec3>* (const CArkWeapon* const _this, std::pair<bool, Vec3>* _return_value_, const int _ignoreCollisionType, IEntity* const _pAttachEntity)>(0x1667110);
	static inline auto FOnAmmoDepleted = PreyFunction<void(CArkWeapon* const _this)>(0x166BC80);
	static inline auto FUpdateAmmoCountUI = PreyFunction<void(const CArkWeapon* const _this)>(0x166EAD0);
	static inline auto FEnableCancelTutorial = PreyFunction<void(CArkWeapon* const _this, const string _tutorialHintString)>(0x1665210);
	static inline auto FDisableCancelTutorial = PreyFunction<void(CArkWeapon* const _this)>(0x1664E90);
	static inline auto FEnableChargeFilter = PreyFunction<void(CArkWeapon* const _this, const bool _bEnable)>(0x1665390);
	static inline auto FGetBaseDamage = PreyFunction<int(const CArkWeapon* const _this)>(0x158AEF0);
	static inline auto FGetModifiedDamage = PreyFunction<int(const CArkWeapon* const _this, const std::vector<uint64_t>&_modifiers)>(0x158AEF0);
	static inline auto FGetSignalModifiers = PreyFunction<std::vector<uint64_t>*(const CArkWeapon* const _this, std::vector<uint64_t>*_return_value_)>(0x1667010);
	static inline auto FCalculateBaseDamage = PreyFunction<float(const CArkWeapon* const _this, uint64_t _pkgId, uint64_t _dmgSignal)>(0x16641A0);
	static inline auto FSpawnMuzzleLight = PreyFunction<void(CArkWeapon* const _this, bool _bAttach)>(0x166E130);
	static inline auto FStopMuzzleLight = PreyFunction<void(CArkWeapon* const _this)>(0x166E5C0);
	static inline auto FUpdateConditionFeedback = PreyFunction<void(const CArkWeapon* const _this)>(0x166F2A0);
	static inline auto FUpdateArkLightColor = PreyFunction<void(const CArkWeapon* const _this, CArkWeapon::EArkWeaponStatus _condition)>(0x166F130);
	static inline auto FInitializeCondition = PreyFunction<void(CArkWeapon* const _this)>(0x16686D0);
	static inline auto FSpawnAmmo = PreyFunction<unsigned(CArkWeapon* const _this)>(0x166DF70);
	static inline auto FAttachToHand = PreyFunction<bool(CArkWeapon* const _this)>(0x1663A40);
	static inline auto FGetOwnerActionController = PreyFunction<IActionController * (const CArkWeapon* const _this)>(0x1666D50);
	static inline auto FUpdateAnimationScopeContexts = PreyFunction<void(CArkWeapon* const _this)>(0x166EC80);
	static inline auto FIsItemWeaponAmmo = PreyFunction<bool(CArkWeapon* const _this, unsigned _itemId)>(0x166A080);
	static inline auto FGetPlayerWeaponSpecificCritChanceStatName = PreyFunction<CCryName * (const CArkWeapon* const _this, CCryName * _return_value_)>(0x13883F0);
	static inline auto FInitializeAmmoCount = PreyFunction<void(CArkWeapon* const _this)>(0x16684F0);
	static inline auto FGiveAmmoClip = PreyFunction<void(CArkWeapon* const _this, const unsigned _pickerId)>(0x16682E0);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x166C260);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo & _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult & _result)>(0x166E810);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>&_interactionArray)>(0x166CBD0);
	static inline auto FDisplayTutorialCard = PreyFunction<void(const CArkWeapon* const _this)>(0x1664F90);
	static inline auto FUpdateStatusIcon = PreyFunction<void(const CArkWeapon* const _this, bool _bForceRemove)>(0x166F620);
};
