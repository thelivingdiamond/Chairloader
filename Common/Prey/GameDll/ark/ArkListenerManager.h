// Header file automatically created from a PDB.

#pragma once

class CCryName;
class IArkAbilityListener;
class IArkBreakableListener;
class IArkCharacterStatusListener;
class IArkCombatFocusListener;
class IArkEmailListener;
class IArkEtherDuplicateListener;
class IArkFabricationPlanListener;
class IArkGravShaftListener;
class IArkGroundColliderListener;
class IArkHUDListener;
class IArkInventoryListener;
class IArkMetaTagListener;
class IArkObjectiveStateListener;
class IArkPDAListener;
class IArkPauseMenuListener;
class IArkPlayerCarryListener;
class IArkPlayerCombatListener;
class IArkPlayerHealthListener;
class IArkPlayerInteractionListener;
class IArkPlayerPsiListener;
class IArkPlayerStatusListener;
class IArkPsiPowerCreatePhantomListener;
class IArkPsiPowerListener;
class IArkPsiPowerTargetingListener;
class IArkSignalManagerListener;
class IArkStatsListener;
class IArkUtilityListener;

// Header: Override
// Prey/GameDll/ark/ArkListenerManager.h
class ArkListenerManager // Id=80154C5 Size=1032
{
public:
	std::vector<IArkAbilityListener *> m_AbilityListeners;
	std::vector<IArkCharacterStatusListener *> m_CharacterStatusListeners;
	std::vector<IArkCombatFocusListener *> m_CombatFocusListeners;
	std::vector<IArkEmailListener *> m_EmailListeners;
	std::vector<IArkEtherDuplicateListener *> m_EtherDuplicateListeners;
	std::vector<IArkGravShaftListener *> m_GravShaftListeners;
	std::vector<IArkFabricationPlanListener *> m_FabricationPlanListeners;
	std::vector<IArkHUDListener *> m_HUDListeners;
	std::vector<IArkMetaTagListener *> m_MetaTagListeners;
	std::vector<IArkObjectiveStateListener *> m_ObjectiveStateListeners;
	std::vector<IArkPauseMenuListener *> m_PauseMenuListeners;
	std::vector<IArkPDAListener *> m_PDAListeners;
	std::vector<IArkPlayerCarryListener *> m_PlayerCarryListeners;
	std::vector<IArkPlayerCombatListener *> m_PlayerCombatListeners;
	std::vector<IArkPlayerHealthListener *> m_PlayerHealthListeners;
	std::vector<IArkPlayerPsiListener *> m_PlayerPsiListeners;
	std::vector<IArkPlayerStatusListener *> m_PlayerStatusListeners;
	std::vector<IArkPsiPowerListener *> m_PsiPowerListeners;
	std::vector<IArkPsiPowerCreatePhantomListener *> m_PsiPowerCreatePhantomListeners;
	std::vector<IArkUtilityListener *> m_UtilityListeners;
	std::vector<IArkBreakableListener *> m_BreakableListeners;
	std::unordered_map<unsigned int,std::vector<IArkGroundColliderListener *>> m_GroundColliderListeners;
	std::vector<IArkGroundColliderListener *> m_emptyGroundCollider;
	std::unordered_map<unsigned int,std::vector<IArkInventoryListener *>> m_InventoryListeners;
	std::vector<IArkInventoryListener *> m_emptyInventory;
	std::unordered_map<unsigned int,std::vector<IArkPlayerInteractionListener *>> m_PlayerInteractionListeners;
	std::vector<IArkPlayerInteractionListener *> m_emptyPlayerInteraction;
	std::unordered_map<unsigned int,std::vector<IArkPsiPowerTargetingListener *>> m_PsiPowerTargetingListeners;
	std::vector<IArkPsiPowerTargetingListener *> m_emptyPsiPowerTargeting;
	std::unordered_map<unsigned int,std::vector<IArkSignalManagerListener *>> m_SignalManagerListeners;
	std::vector<IArkSignalManagerListener *> m_emptySignalManager;
	std::unordered_map<unsigned int,std::unordered_map<CCryName,std::vector<IArkStatsListener *>>,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const,std::unordered_map<CCryName,std::vector<IArkStatsListener *>>>>> m_StatsListeners;
	std::vector<IArkStatsListener *> m_emptyStats;
	
	void RegisterAbilityListener(IArkAbilityListener *_pListener) { FRegisterAbilityListener(this,_pListener); }
	void UnregisterAbilityListener(IArkAbilityListener *_pListener) { FUnregisterAbilityListener(this,_pListener); }
	std::vector<IArkAbilityListener *> const &GetAbilityListeners() const { return FGetAbilityListeners(this); }
	void RegisterCharacterStatusListener(IArkCharacterStatusListener *_pListener) { FRegisterCharacterStatusListener(this,_pListener); }
	void UnregisterCharacterStatusListener(IArkCharacterStatusListener *_pListener) { FUnregisterCharacterStatusListener(this,_pListener); }
	std::vector<IArkCharacterStatusListener *> const &GetCharacterStatusListeners() const { return FGetCharacterStatusListeners(this); }
	void RegisterCombatFocusListener(IArkCombatFocusListener *_pListener) { FRegisterCombatFocusListener(this,_pListener); }
	void UnregisterCombatFocusListener(IArkCombatFocusListener *_pListener) { FUnregisterCombatFocusListener(this,_pListener); }
	std::vector<IArkCombatFocusListener *> const &GetCombatFocusListeners() const { return FGetCombatFocusListeners(this); }
	void RegisterEmailListener(IArkEmailListener *_pListener) { FRegisterEmailListener(this,_pListener); }
	void UnregisterEmailListener(IArkEmailListener *_pListener) { FUnregisterEmailListener(this,_pListener); }
	std::vector<IArkEmailListener *> const &GetEmailListeners() const { return FGetEmailListeners(this); }
	void RegisterEtherDuplicateListener(IArkEtherDuplicateListener *_pListener) { FRegisterEtherDuplicateListener(this,_pListener); }
	void UnregisterEtherDuplicateListener(IArkEtherDuplicateListener *_pListener) { FUnregisterEtherDuplicateListener(this,_pListener); }
	std::vector<IArkEtherDuplicateListener *> const &GetEtherDuplicateListeners() const { return FGetEtherDuplicateListeners(this); }
	void RegisterGravShaftListener(IArkGravShaftListener *_pListener) { FRegisterGravShaftListener(this,_pListener); }
	void UnregisterGravShaftListener(IArkGravShaftListener *_pListener) { FUnregisterGravShaftListener(this,_pListener); }
	std::vector<IArkGravShaftListener *> const &GetGravShaftListeners() const { return FGetGravShaftListeners(this); }
	void RegisterFabricationPlanListener(IArkFabricationPlanListener *_pListener) { FRegisterFabricationPlanListener(this,_pListener); }
	void UnregisterFabricationPlanListener(IArkFabricationPlanListener *_pListener) { FUnregisterFabricationPlanListener(this,_pListener); }
	std::vector<IArkFabricationPlanListener *> const &GetFabricationPlanListeners() const { return FGetFabricationPlanListeners(this); }
	void RegisterHUDListener(IArkHUDListener *_pListener) { FRegisterHUDListener(this,_pListener); }
	void UnregisterHUDListener(IArkHUDListener *_pListener) { FUnregisterHUDListener(this,_pListener); }
	std::vector<IArkHUDListener *> const &GetHUDListeners() const { return FGetHUDListeners(this); }
	void RegisterMetaTagListener(IArkMetaTagListener *_pListener) { FRegisterMetaTagListener(this,_pListener); }
	void UnregisterMetaTagListener(IArkMetaTagListener *_pListener) { FUnregisterMetaTagListener(this,_pListener); }
	std::vector<IArkMetaTagListener *> const &GetMetaTagListeners() const { return FGetMetaTagListeners(this); }
	void RegisterObjectiveStateListener(IArkObjectiveStateListener *_pListener) { FRegisterObjectiveStateListener(this,_pListener); }
	void UnregisterObjectiveStateListener(IArkObjectiveStateListener *_pListener) { FUnregisterObjectiveStateListener(this,_pListener); }
	std::vector<IArkObjectiveStateListener *> const &GetObjectiveStateListeners() const { return FGetObjectiveStateListeners(this); }
	void RegisterPauseMenuListener(IArkPauseMenuListener *_pListener) { FRegisterPauseMenuListener(this,_pListener); }
	void UnregisterPauseMenuListener(IArkPauseMenuListener *_pListener) { FUnregisterPauseMenuListener(this,_pListener); }
	std::vector<IArkPauseMenuListener *> const &GetPauseMenuListeners() const { return FGetPauseMenuListeners(this); }
	void RegisterPDAListener(IArkPDAListener *_pListener) { FRegisterPDAListener(this,_pListener); }
	void UnregisterPDAListener(IArkPDAListener *_pListener) { FUnregisterPDAListener(this,_pListener); }
	std::vector<IArkPDAListener *> const &GetPDAListeners() const { return FGetPDAListeners(this); }
	void RegisterPlayerCarryListener(IArkPlayerCarryListener *_pListener) { FRegisterPlayerCarryListener(this,_pListener); }
	void UnregisterPlayerCarryListener(IArkPlayerCarryListener *_pListener) { FUnregisterPlayerCarryListener(this,_pListener); }
	std::vector<IArkPlayerCarryListener *> const &GetPlayerCarryListeners() const { return FGetPlayerCarryListeners(this); }
	void RegisterPlayerCombatListener(IArkPlayerCombatListener *_pListener) { FRegisterPlayerCombatListener(this,_pListener); }
	void UnregisterPlayerCombatListener(IArkPlayerCombatListener *_pListener) { FUnregisterPlayerCombatListener(this,_pListener); }
	std::vector<IArkPlayerCombatListener *> const &GetPlayerCombatListeners() const { return FGetPlayerCombatListeners(this); }
	void RegisterPlayerHealthListener(IArkPlayerHealthListener *_pListener) { FRegisterPlayerHealthListener(this,_pListener); }
	void UnregisterPlayerHealthListener(IArkPlayerHealthListener *_pListener) { FUnregisterPlayerHealthListener(this,_pListener); }
	std::vector<IArkPlayerHealthListener *> const &GetPlayerHealthListeners() const { return FGetPlayerHealthListeners(this); }
	void RegisterPlayerPsiListener(IArkPlayerPsiListener *_pListener) { FRegisterPlayerPsiListener(this,_pListener); }
	void UnregisterPlayerPsiListener(IArkPlayerPsiListener *_pListener) { FUnregisterPlayerPsiListener(this,_pListener); }
	std::vector<IArkPlayerPsiListener *> const &GetPlayerPsiListeners() const { return FGetPlayerPsiListeners(this); }
	void RegisterPlayerStatusListener(IArkPlayerStatusListener *_pListener) { FRegisterPlayerStatusListener(this,_pListener); }
	void UnregisterPlayerStatusListener(IArkPlayerStatusListener *_pListener) { FUnregisterPlayerStatusListener(this,_pListener); }
	std::vector<IArkPlayerStatusListener *> const &GetPlayerStatusListeners() const { return FGetPlayerStatusListeners(this); }
	void RegisterPsiPowerListener(IArkPsiPowerListener *_pListener) { FRegisterPsiPowerListener(this,_pListener); }
	void UnregisterPsiPowerListener(IArkPsiPowerListener *_pListener) { FUnregisterPsiPowerListener(this,_pListener); }
	std::vector<IArkPsiPowerListener *> const &GetPsiPowerListeners() const { return FGetPsiPowerListeners(this); }
	void RegisterPsiPowerCreatePhantomListener(IArkPsiPowerCreatePhantomListener *_pListener) { FRegisterPsiPowerCreatePhantomListener(this,_pListener); }
	void UnregisterPsiPowerCreatePhantomListener(IArkPsiPowerCreatePhantomListener *_pListener) { FUnregisterPsiPowerCreatePhantomListener(this,_pListener); }
	std::vector<IArkPsiPowerCreatePhantomListener *> const &GetPsiPowerCreatePhantomListeners() const { return FGetPsiPowerCreatePhantomListeners(this); }
	void RegisterUtilityListener(IArkUtilityListener *_pListener) { FRegisterUtilityListener(this,_pListener); }
	void UnregisterUtilityListener(IArkUtilityListener *_pListener) { FUnregisterUtilityListener(this,_pListener); }
	std::vector<IArkUtilityListener *> const &GetUtilityListeners() const { return FGetUtilityListeners(this); }
	void RegisterBreakableListener(IArkBreakableListener *_pListener) { FRegisterBreakableListener(this,_pListener); }
	void UnregisterBreakableListener(IArkBreakableListener *_pListener) { FUnregisterBreakableListener(this,_pListener); }
	std::vector<IArkBreakableListener *> const &GetBreakableListeners() const { return FGetBreakableListeners(this); }
	void RegisterGroundColliderListener(unsigned _entity, IArkGroundColliderListener *_pListener) { FRegisterGroundColliderListener(this,_entity,_pListener); }
	void UnregisterGroundColliderListener(unsigned _entity, IArkGroundColliderListener *_pListener) { FUnregisterGroundColliderListener(this,_entity,_pListener); }
	std::vector<IArkGroundColliderListener *> const &GetGroundColliderListeners(unsigned _entity) const { return FGetGroundColliderListenersOv1(this,_entity); }
	void RegisterInventoryListener(unsigned _entity, IArkInventoryListener *_pListener) { FRegisterInventoryListener(this,_entity,_pListener); }
	void UnregisterInventoryListener(unsigned _entity, IArkInventoryListener *_pListener) { FUnregisterInventoryListener(this,_entity,_pListener); }
	std::vector<IArkInventoryListener *> const &GetInventoryListeners(unsigned _entity) const { return FGetInventoryListenersOv1(this,_entity); }
	void RegisterPlayerInteractionListener(unsigned _entity, IArkPlayerInteractionListener *_pListener) { FRegisterPlayerInteractionListener(this,_entity,_pListener); }
	void UnregisterPlayerInteractionListener(unsigned _entity, IArkPlayerInteractionListener *_pListener) { FUnregisterPlayerInteractionListener(this,_entity,_pListener); }
	std::vector<IArkPlayerInteractionListener *> const &GetPlayerInteractionListeners(unsigned _entity) const { return FGetPlayerInteractionListenersOv1(this,_entity); }
	void RegisterPsiPowerTargetingListener(unsigned _entity, IArkPsiPowerTargetingListener *_pListener) { FRegisterPsiPowerTargetingListener(this,_entity,_pListener); }
	void UnregisterPsiPowerTargetingListener(unsigned _entity, IArkPsiPowerTargetingListener *_pListener) { FUnregisterPsiPowerTargetingListener(this,_entity,_pListener); }
	std::vector<IArkPsiPowerTargetingListener *> const &GetPsiPowerTargetingListeners(unsigned _entity) const { return FGetPsiPowerTargetingListenersOv1(this,_entity); }
	void RegisterSignalManagerListener(unsigned _entity, IArkSignalManagerListener *_pListener) { FRegisterSignalManagerListener(this,_entity,_pListener); }
	void UnregisterSignalManagerListener(unsigned _entity, IArkSignalManagerListener *_pListener) { FUnregisterSignalManagerListener(this,_entity,_pListener); }
	std::vector<IArkSignalManagerListener *> const &GetSignalManagerListeners(unsigned _entity) const { return FGetSignalManagerListenersOv1(this,_entity); }
	void RegisterStatsListener(const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener) { FRegisterStatsListener(this,_entity,_cryName,_pListener); }
	void UnregisterStatsListener(const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener) { FUnregisterStatsListener(this,_entity,_cryName,_pListener); }
	std::vector<IArkStatsListener *> const &GetStatsListeners(const unsigned _entity, CCryName const &_cryName) const { return FGetStatsListeners(this,_entity,_cryName); }
	
#if 0
	std::unordered_map<unsigned int,std::vector<IArkGroundColliderListener *>> const &GetGroundColliderListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkInventoryListener *>> const &GetInventoryListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkPlayerInteractionListener *>> const &GetPlayerInteractionListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkPsiPowerTargetingListener *>> const &GetPsiPowerTargetingListeners() const;
	std::unordered_map<unsigned int,std::vector<IArkSignalManagerListener *>> const &GetSignalManagerListeners() const;
#endif
	
	static inline auto FRegisterAbilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkAbilityListener *_pListener)>(0x1193F40);
	static inline auto FUnregisterAbilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkAbilityListener *_pListener)>(0x1195080);
	static inline auto FGetAbilityListeners = PreyFunction<std::vector<IArkAbilityListener *> const &(ArkListenerManager const *const _this)>(0xC71190);
	static inline auto FRegisterCharacterStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCharacterStatusListener *_pListener)>(0x1193FD0);
	static inline auto FUnregisterCharacterStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCharacterStatusListener *_pListener)>(0x1195110);
	static inline auto FGetCharacterStatusListeners = PreyFunction<std::vector<IArkCharacterStatusListener *> const &(ArkListenerManager const *const _this)>(0x12BDA70);
	static inline auto FRegisterCombatFocusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCombatFocusListener *_pListener)>(0x1194020);
	static inline auto FUnregisterCombatFocusListener = PreyFunction<void(ArkListenerManager *const _this, IArkCombatFocusListener *_pListener)>(0x1195150);
	static inline auto FGetCombatFocusListeners = PreyFunction<std::vector<IArkCombatFocusListener *> const &(ArkListenerManager const *const _this)>(0x12BDA00);
	static inline auto FRegisterEmailListener = PreyFunction<void(ArkListenerManager *const _this, IArkEmailListener *_pListener)>(0x1194070);
	static inline auto FUnregisterEmailListener = PreyFunction<void(ArkListenerManager *const _this, IArkEmailListener *_pListener)>(0x1195190);
	static inline auto FGetEmailListeners = PreyFunction<std::vector<IArkEmailListener *> const &(ArkListenerManager const *const _this)>(0x222910);
	static inline auto FRegisterEtherDuplicateListener = PreyFunction<void(ArkListenerManager *const _this, IArkEtherDuplicateListener *_pListener)>(0x11940C0);
	static inline auto FUnregisterEtherDuplicateListener = PreyFunction<void(ArkListenerManager *const _this, IArkEtherDuplicateListener *_pListener)>(0x11951D0);
	static inline auto FGetEtherDuplicateListeners = PreyFunction<std::vector<IArkEtherDuplicateListener *> const &(ArkListenerManager const *const _this)>(0x10BD9E0);
	static inline auto FRegisterGravShaftListener = PreyFunction<void(ArkListenerManager *const _this, IArkGravShaftListener *_pListener)>(0x1194160);
	static inline auto FUnregisterGravShaftListener = PreyFunction<void(ArkListenerManager *const _this, IArkGravShaftListener *_pListener)>(0x1195260);
	static inline auto FGetGravShaftListeners = PreyFunction<std::vector<IArkGravShaftListener *> const &(ArkListenerManager const *const _this)>(0x10BD7D0);
	static inline auto FRegisterFabricationPlanListener = PreyFunction<void(ArkListenerManager *const _this, IArkFabricationPlanListener *_pListener)>(0x1194110);
	static inline auto FUnregisterFabricationPlanListener = PreyFunction<void(ArkListenerManager *const _this, IArkFabricationPlanListener *_pListener)>(0x1195210);
	static inline auto FGetFabricationPlanListeners = PreyFunction<std::vector<IArkFabricationPlanListener *> const &(ArkListenerManager const *const _this)>(0x10BD460);
	static inline auto FRegisterHUDListener = PreyFunction<void(ArkListenerManager *const _this, IArkHUDListener *_pListener)>(0x1194350);
	static inline auto FUnregisterHUDListener = PreyFunction<void(ArkListenerManager *const _this, IArkHUDListener *_pListener)>(0x11953E0);
	static inline auto FGetHUDListeners = PreyFunction<std::vector<IArkHUDListener *> const &(ArkListenerManager const *const _this)>(0x10BD340);
	static inline auto FRegisterMetaTagListener = PreyFunction<void(ArkListenerManager *const _this, IArkMetaTagListener *_pListener)>(0x1194540);
	static inline auto FUnregisterMetaTagListener = PreyFunction<void(ArkListenerManager *const _this, IArkMetaTagListener *_pListener)>(0x1195560);
	static inline auto FGetMetaTagListeners = PreyFunction<std::vector<IArkMetaTagListener *> const &(ArkListenerManager const *const _this)>(0x10BD8F0);
	static inline auto FRegisterObjectiveStateListener = PreyFunction<void(ArkListenerManager *const _this, IArkObjectiveStateListener *_pListener)>(0x1194590);
	static inline auto FUnregisterObjectiveStateListener = PreyFunction<void(ArkListenerManager *const _this, IArkObjectiveStateListener *_pListener)>(0x11955B0);
	static inline auto FGetObjectiveStateListeners = PreyFunction<std::vector<IArkObjectiveStateListener *> const &(ArkListenerManager const *const _this)>(0x10BD4D0);
	static inline auto FRegisterPauseMenuListener = PreyFunction<void(ArkListenerManager *const _this, IArkPauseMenuListener *_pListener)>(0x1194630);
	static inline auto FUnregisterPauseMenuListener = PreyFunction<void(ArkListenerManager *const _this, IArkPauseMenuListener *_pListener)>(0x1195650);
	static inline auto FGetPauseMenuListeners = PreyFunction<std::vector<IArkPauseMenuListener *> const &(ArkListenerManager const *const _this)>(0x10BD930);
	static inline auto FRegisterPDAListener = PreyFunction<void(ArkListenerManager *const _this, IArkPDAListener *_pListener)>(0x11945E0);
	static inline auto FUnregisterPDAListener = PreyFunction<void(ArkListenerManager *const _this, IArkPDAListener *_pListener)>(0x1195600);
	static inline auto FGetPDAListeners = PreyFunction<std::vector<IArkPDAListener *> const &(ArkListenerManager const *const _this)>(0x10BD840);
	static inline auto FRegisterPlayerCarryListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCarryListener *_pListener)>(0x1194680);
	static inline auto FUnregisterPlayerCarryListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCarryListener *_pListener)>(0x11956A0);
	static inline auto FGetPlayerCarryListeners = PreyFunction<std::vector<IArkPlayerCarryListener *> const &(ArkListenerManager const *const _this)>(0x1193B60);
	static inline auto FRegisterPlayerCombatListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCombatListener *_pListener)>(0x11946D0);
	static inline auto FUnregisterPlayerCombatListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerCombatListener *_pListener)>(0x11956F0);
	static inline auto FGetPlayerCombatListeners = PreyFunction<std::vector<IArkPlayerCombatListener *> const &(ArkListenerManager const *const _this)>(0x10BD4A0);
	static inline auto FRegisterPlayerHealthListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerHealthListener *_pListener)>(0x1194720);
	static inline auto FUnregisterPlayerHealthListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerHealthListener *_pListener)>(0x1195740);
	static inline auto FGetPlayerHealthListeners = PreyFunction<std::vector<IArkPlayerHealthListener *> const &(ArkListenerManager const *const _this)>(0x10BD370);
	static inline auto FRegisterPlayerPsiListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerPsiListener *_pListener)>(0x1194910);
	static inline auto FUnregisterPlayerPsiListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerPsiListener *_pListener)>(0x11958C0);
	static inline auto FGetPlayerPsiListeners = PreyFunction<std::vector<IArkPlayerPsiListener *> const &(ArkListenerManager const *const _this)>(0x10BD890);
	static inline auto FRegisterPlayerStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerStatusListener *_pListener)>(0x1194960);
	static inline auto FUnregisterPlayerStatusListener = PreyFunction<void(ArkListenerManager *const _this, IArkPlayerStatusListener *_pListener)>(0x1195910);
	static inline auto FGetPlayerStatusListeners = PreyFunction<std::vector<IArkPlayerStatusListener *> const &(ArkListenerManager const *const _this)>(0x10BD8D0);
	static inline auto FRegisterPsiPowerListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerListener *_pListener)>(0x1194A00);
	static inline auto FUnregisterPsiPowerListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerListener *_pListener)>(0x11959B0);
	static inline auto FGetPsiPowerListeners = PreyFunction<std::vector<IArkPsiPowerListener *> const &(ArkListenerManager const *const _this)>(0x1193C40);
	static inline auto FRegisterPsiPowerCreatePhantomListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerCreatePhantomListener *_pListener)>(0x11949B0);
	static inline auto FUnregisterPsiPowerCreatePhantomListener = PreyFunction<void(ArkListenerManager *const _this, IArkPsiPowerCreatePhantomListener *_pListener)>(0x1195960);
	static inline auto FGetPsiPowerCreatePhantomListeners = PreyFunction<std::vector<IArkPsiPowerCreatePhantomListener *> const &(ArkListenerManager const *const _this)>(0x10BD4C0);
	static inline auto FRegisterUtilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkUtilityListener *_pListener)>(0x1195030);
	static inline auto FUnregisterUtilityListener = PreyFunction<void(ArkListenerManager *const _this, IArkUtilityListener *_pListener)>(0x1195E10);
	static inline auto FGetUtilityListeners = PreyFunction<std::vector<IArkUtilityListener *> const &(ArkListenerManager const *const _this)>(0x1193F30);
	static inline auto FRegisterBreakableListener = PreyFunction<void(ArkListenerManager *const _this, IArkBreakableListener *_pListener)>(0x1193F80);
	static inline auto FUnregisterBreakableListener = PreyFunction<void(ArkListenerManager *const _this, IArkBreakableListener *_pListener)>(0x11950C0);
	static inline auto FGetBreakableListeners = PreyFunction<std::vector<IArkBreakableListener *> const &(ArkListenerManager const *const _this)>(0x11939B0);
	static inline auto FRegisterGroundColliderListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkGroundColliderListener *_pListener)>(0x11941B0);
	static inline auto FUnregisterGroundColliderListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkGroundColliderListener *_pListener)>(0x11952B0);
	static inline auto FGetGroundColliderListenersOv1 = PreyFunction<std::vector<IArkGroundColliderListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x11939C0);
	static inline auto FRegisterInventoryListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkInventoryListener *_pListener)>(0x11943A0);
	static inline auto FUnregisterInventoryListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkInventoryListener *_pListener)>(0x1195430);
	static inline auto FGetInventoryListenersOv1 = PreyFunction<std::vector<IArkInventoryListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193A90);
	static inline auto FRegisterPlayerInteractionListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPlayerInteractionListener *_pListener)>(0x1194770);
	static inline auto FUnregisterPlayerInteractionListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPlayerInteractionListener *_pListener)>(0x1195790);
	static inline auto FGetPlayerInteractionListenersOv1 = PreyFunction<std::vector<IArkPlayerInteractionListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193B70);
	static inline auto FRegisterPsiPowerTargetingListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPsiPowerTargetingListener *_pListener)>(0x1194A50);
	static inline auto FUnregisterPsiPowerTargetingListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkPsiPowerTargetingListener *_pListener)>(0x1195A00);
	static inline auto FGetPsiPowerTargetingListenersOv1 = PreyFunction<std::vector<IArkPsiPowerTargetingListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193C50);
	static inline auto FRegisterSignalManagerListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkSignalManagerListener *_pListener)>(0x1194BF0);
	static inline auto FUnregisterSignalManagerListener = PreyFunction<void(ArkListenerManager *const _this, unsigned _entity, IArkSignalManagerListener *_pListener)>(0x1195B30);
	static inline auto FGetSignalManagerListenersOv1 = PreyFunction<std::vector<IArkSignalManagerListener *> const &(ArkListenerManager const *const _this, unsigned _entity)>(0x1193D20);
	static inline auto FRegisterStatsListener = PreyFunction<void(ArkListenerManager *const _this, const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener)>(0x1194D90);
	static inline auto FUnregisterStatsListener = PreyFunction<void(ArkListenerManager *const _this, const unsigned _entity, CCryName const &_cryName, IArkStatsListener *_pListener)>(0x1195C60);
	static inline auto FGetStatsListeners = PreyFunction<std::vector<IArkStatsListener *> const &(ArkListenerManager const *const _this, const unsigned _entity, CCryName const &_cryName)>(0x1193DF0);
};

