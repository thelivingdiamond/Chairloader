// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayerTranscribe.h>
#include <Prey/GameDll/ark/player/arkplayercomponent.h>
#include <Prey/GameDll/ark/player/arkplayerhealthcomponent.h>
#include <Prey/GameDll/ark/player/pda/ArkLiveTranscribeComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkFabricationPlanComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkRosterComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkEmailComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkKeyCardComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkLoreComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkLocationComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkKeyCodeComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkNoteComponent.h>
#include <Prey/GameDll/ark/player/pda/ArkAudioLogComponent.h>
#include <Prey/GameDll/ark/player/ability/ArkAbilityComponent.h>
#include <Prey/GameDll/ark/ArkGameMetricsComponent.h>
#include <Prey/GameDll/ark/ui/ArkPDAComponent.h>

class ArkAbilityComponent;
class ArkAimAssistComponent;
class ArkAudioLogComponent;
class ArkEmailComponent;
class ArkFabricationPlanComponent;
class ArkFocusModeComponent;
class ArkGameMetricsComponent;
class ArkKeyCardComponent;
class ArkKeyCodeComponent;
class ArkLiveTranscribeComponent;
class ArkLocationComponent;
class ArkLoreComponent;
class ArkMarkedEnemyComponent;
class ArkNoteComponent;
class ArkPDAComponent;
class ArkPOIComponent;
class ArkPharmaComponent;
class ArkPlayerAchievementComponent;
class ArkPlayerAwarenessComponent;
class ArkPlayerEntitlementComponent;
class ArkPlayerFXComponent;
class ArkPlayerFatigueComponent;
class ArkPlayerHealthComponent;
class ArkPlayerLightManager;
class ArkPlayerPropulsionComponent;
class ArkPlayerRadiationComponent;
class ArkPlayerScopeComponent;
class ArkPlayerSignalReceiver;
class ArkPlayerStatusComponent;
class ArkPlayerUIComponent;
class ArkQuickSelectComponent;
class ArkRosterComponent;
class ArkSpeakerBase;
class ArkStationAccessComponent;
class ArkUtilityComponent;
class CArkPsiComponent;
class CCryName;
class XmlNodeRef;

// Header: Override
// Prey/GameDll/ark/player/ArkPlayerComponent.h
class ArkPlayerComponent // Id=8016E64 Size=328
{
public:
	std::unique_ptr<CArkPsiComponent> m_pPsiComponent;
	std::unique_ptr<ArkAbilityComponent> m_pAbilityComponent;
	std::unique_ptr<ArkAudioLogComponent> m_pAudioLogComponent;
	std::unique_ptr<ArkNoteComponent> m_pNoteComponent;
	std::unique_ptr<ArkKeyCodeComponent> m_pKeyCodeComponent;
	std::unique_ptr<ArkLocationComponent> m_pLocationComponent;
	std::unique_ptr<ArkLoreComponent> m_pLoreComponent;
	std::unique_ptr<ArkKeyCardComponent> m_pKeyCardComponent;
	std::unique_ptr<ArkEmailComponent> m_pEmailComponent;
	std::unique_ptr<ArkQuickSelectComponent> m_pQuickSelectComponent;
	std::unique_ptr<ArkRosterComponent> m_pRosterComponent;
	std::unique_ptr<ArkUtilityComponent> m_pUtilityComponent;
	std::unique_ptr<ArkPharmaComponent> m_pPharmaComponent;
	std::unique_ptr<ArkPDAComponent> m_pPDAComponent;
	std::unique_ptr<ArkPlayerAchievementComponent> m_pAchievementComponent;
	std::unique_ptr<ArkPlayerAwarenessComponent> m_pAwarenessComponent;
	std::unique_ptr<ArkPlayerEntitlementComponent> m_pEntitlementComponent;
	std::unique_ptr<ArkPlayerFatigueComponent> m_pFatigueComponent;
	std::unique_ptr<ArkPlayerHealthComponent> m_pHealthComponent;
	std::unique_ptr<ArkPlayerRadiationComponent> m_pRadiationComponent;
	std::unique_ptr<ArkPlayerLightManager> m_pLightManager;
	std::unique_ptr<ArkPlayerFXComponent> m_pFXComponent;
	std::unique_ptr<ArkPlayerUIComponent> m_pUIComponent;
	std::unique_ptr<ArkFabricationPlanComponent> m_pFabricationPlanComponent;
	std::unique_ptr<ArkPlayerStatusComponent> m_pStatusComponent;
	std::unique_ptr<ArkPlayerPropulsionComponent> m_pPropulsionComponent;
	std::unique_ptr<ArkPlayerSignalReceiver> m_pSignalReceiver;
	std::unique_ptr<ArkAimAssistComponent> m_pAimAssistComponent;
	std::unique_ptr<ArkMarkedEnemyComponent> m_pMarkedEnemyComponent;
	std::unique_ptr<ArkPlayerScopeComponent> m_pScopeComponent;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pPlayerSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pSuitSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayer>> m_pDiscRifleSpeaker;
	std::unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>> m_pTranscribeSpeaker;
	std::unique_ptr<ArkGameMetricsComponent> m_pGameMetricsComponent;
	std::unique_ptr<ArkFocusModeComponent> m_pFocusModeComponent;
	std::unique_ptr<ArkLiveTranscribeComponent> m_pLiveTranscribeComponent;
	std::unique_ptr<ArkStationAccessComponent> m_pStationAccessComponent;
	std::unique_ptr<ArkPOIComponent> m_pPOIComponent;
	float m_fShadowDissolveBlend;
	float m_fShadowDissolveTarget;
	float m_fShadowDissolveTimeScale;
	bool m_bItemsRestricted;
	bool m_bMarkerTextDisplayed;
	
	ArkPlayerComponent();
	~ArkPlayerComponent();
	void Init() { FInit(this); }
	void Release() { FRelease(this); }
	void Update(const float _deltaTime) { FUpdate(this,_deltaTime); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void UpdateAimAssist() { FUpdateAimAssist(this); }
	void Reset() { FReset(this); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	CArkPsiComponent &GetPsiComponent() { return FGetPsiComponentOv1(this); }
	CArkPsiComponent const &GetPsiComponent() const { return FGetPsiComponentOv0(this); }
	ArkAbilityComponent &GetAbilityComponent() { return FGetAbilityComponentOv1(this); }
	ArkAbilityComponent const &GetAbilityComponent() const { return FGetAbilityComponentOv0(this); }
	ArkAudioLogComponent &GetAudioLogComponent() { return FGetAudioLogComponentOv1(this); }
	ArkNoteComponent &GetNoteComponent() { return FGetNoteComponentOv1(this); }
	ArkNoteComponent const &GetNoteComponent() const { return FGetNoteComponentOv0(this); }
	ArkKeyCodeComponent &GetKeyCodeComponent() { return FGetKeyCodeComponentOv1(this); }
	ArkLocationComponent &GetLocationComponent() { return FGetLocationComponentOv1(this); }
	ArkLocationComponent const &GetLocationComponent() const { return FGetLocationComponentOv0(this); }
	ArkLoreComponent &GetLoreComponent() { return FGetLoreComponentOv1(this); }
	ArkKeyCardComponent &GetKeyCardComponent() { return FGetKeyCardComponentOv1(this); }
	ArkEmailComponent &GetEmailComponent() { return FGetEmailComponentOv1(this); }
	ArkEmailComponent const &GetEmailComponent() const { return FGetEmailComponentOv0(this); }
	ArkQuickSelectComponent &GetQuickSelectComponent() { return FGetQuickSelectComponentOv1(this); }
	ArkQuickSelectComponent const &GetQuickSelectComponent() const { return FGetQuickSelectComponentOv0(this); }
	ArkRosterComponent &GetRosterComponent() { return FGetRosterComponentOv1(this); }
	ArkRosterComponent const &GetRosterComponent() const { return FGetRosterComponentOv0(this); }
	ArkPDAComponent &GetPDAComponent() { return FGetPDAComponentOv1(this); }
	ArkPDAComponent const &GetPDAComponent() const { return FGetPDAComponentOv0(this); }
	ArkPlayerAwarenessComponent &GetAwarenessComponent() { return FGetAwarenessComponentOv1(this); }
	ArkPlayerAwarenessComponent const &GetAwarenessComponent() const { return FGetAwarenessComponentOv0(this); }
	ArkPlayerFatigueComponent &GetFatigueComponent() { return FGetFatigueComponentOv1(this); }
	ArkPlayerFatigueComponent const &GetFatigueComponent() const { return FGetFatigueComponentOv0(this); }
	ArkPlayerHealthComponent &GetHealthComponent() { return FGetHealthComponentOv1(this); }
	ArkPlayerHealthComponent const &GetHealthComponent() const { return FGetHealthComponentOv0(this); }
	ArkPlayerRadiationComponent &GetRadiationComponent() { return FGetRadiationComponentOv1(this); }
	ArkPlayerFXComponent &GetFXComponent() { return FGetFXComponentOv1(this); }
	ArkUtilityComponent &GetUtilityComponent() { return FGetUtilityComponentOv1(this); }
	ArkUtilityComponent const &GetUtilityComponent() const { return FGetUtilityComponentOv0(this); }
	ArkPharmaComponent &GetPharmaComponent() { return FGetPharmaComponentOv1(this); }
	ArkPlayerUIComponent &GetUIComponent() { return FGetUIComponentOv1(this); }
	ArkPlayerLightManager &GetLightManager() { return FGetLightManagerOv1(this); }
	ArkFabricationPlanComponent &GetFabricationPlanComponent() { return FGetFabricationPlanComponentOv1(this); }
	ArkFabricationPlanComponent const &GetFabricationPlanComponent() const { return FGetFabricationPlanComponentOv0(this); }
	ArkPlayerStatusComponent &GetStatusComponent() { return FGetStatusComponentOv1(this); }
	ArkPlayerStatusComponent const &GetStatusComponent() const { return FGetStatusComponentOv0(this); }
	ArkPlayerAchievementComponent &GetAchievementComponent() { return FGetAchievementComponent(this); }
	ArkPlayerEntitlementComponent &GetEntitlementComponent() { return FGetEntitlementComponent(this); }
	ArkPlayerPropulsionComponent &GetPropulsionComponent() { return FGetPropulsionComponentOv1(this); }
	ArkPlayerPropulsionComponent const &GetPropulsionComponent() const { return FGetPropulsionComponentOv0(this); }
	ArkAimAssistComponent const &GetAimAssistComponent() const { return FGetAimAssistComponent(this); }
	ArkMarkedEnemyComponent &GetMarkedEnemyComponent() { return FGetMarkedEnemyComponentOv1(this); }
	ArkMarkedEnemyComponent const &GetMarkedEnemyComponent() const { return FGetMarkedEnemyComponentOv0(this); }
	ArkPlayerScopeComponent &GetScopeComponent() { return FGetScopeComponentOv1(this); }
	ArkPlayerScopeComponent const &GetScopeComponent() const { return FGetScopeComponentOv0(this); }
	ArkGameMetricsComponent &GetGameMetricComponent() { return FGetGameMetricComponentOv1(this); }
	ArkFocusModeComponent &GetFocusModeComponent() { return FGetFocusModeComponentOv1(this); }
	ArkFocusModeComponent const &GetFocusModeComponent() const { return FGetFocusModeComponentOv0(this); }
	ArkLiveTranscribeComponent &GetLiveTranscribeComponent() { return FGetLiveTranscribeComponentOv1(this); }
	ArkStationAccessComponent &GetStationAccessComponent() { return FGetStationAccessComponentOv1(this); }
	ArkPOIComponent &GetPOIComponent() { return FGetPOIComponentOv1(this); }
	ArkSpeakerBase *GetPlayerSpeaker() { return FGetPlayerSpeaker(this); }
	ArkSpeakerBase *GetSuitSpeaker() { return FGetSuitSpeaker(this); }
	ArkSpeakerBase *GetDiscRifleSpeaker() { return FGetDiscRifleSpeaker(this); }
	ArkSpeaker<ArkDialogPlayerTranscribe> *GetTranscribeSpeaker() { return FGetTranscribeSpeaker(this); }
	void ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue) { FProcessInput(this,_rActionId,_activationMode,_fValue); }
	void PreSerialize() { FPreSerialize(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SerializeForLevelTransition(TSerialize _ser) { FSerializeForLevelTransition(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeForLevelTransition() { FPostSerializeForLevelTransition(this); }
	void CollectNote(int64_t _id) { FCollectNote(this,_id); }
	void OnDead() { FOnDead(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void TriggerDamageDialog(const float _damage) const { FTriggerDamageDialog(this,_damage); }
	void SetItemsRestricted(const bool _bRestricted) { FSetItemsRestricted(this,_bRestricted); }
	void SerializeEither(TSerialize _ser) { FSerializeEither(this,_ser); }
	
#if 0
	ArkAudioLogComponent const &GetAudioLogComponent() const;
	ArkKeyCodeComponent const &GetKeyCodeComponent() const;
	ArkLoreComponent const &GetLoreComponent() const;
	ArkKeyCardComponent const &GetKeyCardComponent() const;
	ArkPlayerRadiationComponent const &GetRadiationComponent() const;
	ArkPlayerFXComponent const &GetFXComponent() const;
	ArkPharmaComponent const &GetPharmaComponent() const;
	ArkPlayerUIComponent const &GetUIComponent() const;
	ArkPlayerLightManager const &GetLightManager() const;
	ArkGameMetricsComponent const &GetGameMetricComponent() const;
	ArkLiveTranscribeComponent const &GetLiveTranscribeComponent() const;
	ArkPlayerSignalReceiver const &GetSignalReceiver() const;
	ArkStationAccessComponent const &GetStationAccessComponent() const;
	ArkPOIComponent const &GetPOIComponent() const;
	void DissolveShadow(bool arg0, float arg1);
	void CollectAllData();
	bool GetItemsRestricted() const;
	bool IsMarkerTextDisplayed() const;
	void SetMarkerTextDisplayed();
#endif
	
	static inline auto FBitNotArkPlayerComponent = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155A7D0);
	static inline auto FInit = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155ADB0);
	static inline auto FRelease = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B5B0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerComponent *const _this, const float _deltaTime)>(0x155C170);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155C390);
	static inline auto FUpdateAimAssist = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155C380);
	static inline auto FReset = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B5E0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerComponent *const _this, XmlNodeRef const &_node)>(0x155AE20);
	static inline auto FGetPsiComponentOv1 = PreyFunction<CArkPsiComponent &(ArkPlayerComponent *const _this)>(0x12E5E70);
	static inline auto FGetPsiComponentOv0 = PreyFunction<CArkPsiComponent const &(ArkPlayerComponent const *const _this)>(0x12E5E70);
	static inline auto FGetAbilityComponentOv1 = PreyFunction<ArkAbilityComponent &(ArkPlayerComponent *const _this)>(0x12AAC70);
	static inline auto FGetAbilityComponentOv0 = PreyFunction<ArkAbilityComponent const &(ArkPlayerComponent const *const _this)>(0x12AAC70);
	static inline auto FGetAudioLogComponentOv1 = PreyFunction<ArkAudioLogComponent &(ArkPlayerComponent *const _this)>(0x5BFB50);
	static inline auto FGetNoteComponentOv1 = PreyFunction<ArkNoteComponent &(ArkPlayerComponent *const _this)>(0xD87500);
	static inline auto FGetNoteComponentOv0 = PreyFunction<ArkNoteComponent const &(ArkPlayerComponent const *const _this)>(0xD87500);
	static inline auto FGetKeyCodeComponentOv1 = PreyFunction<ArkKeyCodeComponent &(ArkPlayerComponent *const _this)>(0x1140FE0);
	static inline auto FGetLocationComponentOv1 = PreyFunction<ArkLocationComponent &(ArkPlayerComponent *const _this)>(0xD87510);
	static inline auto FGetLocationComponentOv0 = PreyFunction<ArkLocationComponent const &(ArkPlayerComponent const *const _this)>(0xD87510);
	static inline auto FGetLoreComponentOv1 = PreyFunction<ArkLoreComponent &(ArkPlayerComponent *const _this)>(0x862100);
	static inline auto FGetKeyCardComponentOv1 = PreyFunction<ArkKeyCardComponent &(ArkPlayerComponent *const _this)>(0x864AF0);
	static inline auto FGetEmailComponentOv1 = PreyFunction<ArkEmailComponent &(ArkPlayerComponent *const _this)>(0x855C80);
	static inline auto FGetEmailComponentOv0 = PreyFunction<ArkEmailComponent const &(ArkPlayerComponent const *const _this)>(0x855C80);
	static inline auto FGetQuickSelectComponentOv1 = PreyFunction<ArkQuickSelectComponent &(ArkPlayerComponent *const _this)>(0x1A1FF50);
	static inline auto FGetQuickSelectComponentOv0 = PreyFunction<ArkQuickSelectComponent const &(ArkPlayerComponent const *const _this)>(0x1A1FF50);
	static inline auto FGetRosterComponentOv1 = PreyFunction<ArkRosterComponent &(ArkPlayerComponent *const _this)>(0x9DFAA0);
	static inline auto FGetRosterComponentOv0 = PreyFunction<ArkRosterComponent const &(ArkPlayerComponent const *const _this)>(0x9DFAA0);
	static inline auto FGetPDAComponentOv1 = PreyFunction<ArkPDAComponent &(ArkPlayerComponent *const _this)>(0x155AD50);
	static inline auto FGetPDAComponentOv0 = PreyFunction<ArkPDAComponent const &(ArkPlayerComponent const *const _this)>(0x155AD50);
	static inline auto FGetAwarenessComponentOv1 = PreyFunction<ArkPlayerAwarenessComponent &(ArkPlayerComponent *const _this)>(0x155ACE0);
	static inline auto FGetAwarenessComponentOv0 = PreyFunction<ArkPlayerAwarenessComponent const &(ArkPlayerComponent const *const _this)>(0x155ACE0);
	static inline auto FGetFatigueComponentOv1 = PreyFunction<ArkPlayerFatigueComponent &(ArkPlayerComponent *const _this)>(0x82E930);
	static inline auto FGetFatigueComponentOv0 = PreyFunction<ArkPlayerFatigueComponent const &(ArkPlayerComponent const *const _this)>(0x82E930);
	static inline auto FGetHealthComponentOv1 = PreyFunction<ArkPlayerHealthComponent &(ArkPlayerComponent *const _this)>(0x155AD30);
	static inline auto FGetHealthComponentOv0 = PreyFunction<ArkPlayerHealthComponent const &(ArkPlayerComponent const *const _this)>(0x155AD30);
	static inline auto FGetRadiationComponentOv1 = PreyFunction<ArkPlayerRadiationComponent &(ArkPlayerComponent *const _this)>(0x24DDE0);
	static inline auto FGetFXComponentOv1 = PreyFunction<ArkPlayerFXComponent &(ArkPlayerComponent *const _this)>(0x1315370);
	static inline auto FGetUtilityComponentOv1 = PreyFunction<ArkUtilityComponent &(ArkPlayerComponent *const _this)>(0x1545000);
	static inline auto FGetUtilityComponentOv0 = PreyFunction<ArkUtilityComponent const &(ArkPlayerComponent const *const _this)>(0x1545000);
	static inline auto FGetPharmaComponentOv1 = PreyFunction<ArkPharmaComponent &(ArkPlayerComponent *const _this)>(0x1C27C0);
	static inline auto FGetUIComponentOv1 = PreyFunction<ArkPlayerUIComponent &(ArkPlayerComponent *const _this)>(0x11A67A0);
	static inline auto FGetLightManagerOv1 = PreyFunction<ArkPlayerLightManager &(ArkPlayerComponent *const _this)>(0x9DFAE0);
	static inline auto FGetFabricationPlanComponentOv1 = PreyFunction<ArkFabricationPlanComponent &(ArkPlayerComponent *const _this)>(0x155AD10);
	static inline auto FGetFabricationPlanComponentOv0 = PreyFunction<ArkFabricationPlanComponent const &(ArkPlayerComponent const *const _this)>(0x155AD10);
	static inline auto FGetStatusComponentOv1 = PreyFunction<ArkPlayerStatusComponent &(ArkPlayerComponent *const _this)>(0x12C8A0);
	static inline auto FGetStatusComponentOv0 = PreyFunction<ArkPlayerStatusComponent const &(ArkPlayerComponent const *const _this)>(0x12C8A0);
	static inline auto FGetAchievementComponent = PreyFunction<ArkPlayerAchievementComponent &(ArkPlayerComponent *const _this)>(0xE70280);
	static inline auto FGetEntitlementComponent = PreyFunction<ArkPlayerEntitlementComponent &(ArkPlayerComponent *const _this)>(0x16A1030);
	static inline auto FGetPropulsionComponentOv1 = PreyFunction<ArkPlayerPropulsionComponent &(ArkPlayerComponent *const _this)>(0x155AD90);
	static inline auto FGetPropulsionComponentOv0 = PreyFunction<ArkPlayerPropulsionComponent const &(ArkPlayerComponent const *const _this)>(0x155AD90);
	static inline auto FGetAimAssistComponent = PreyFunction<ArkAimAssistComponent const &(ArkPlayerComponent const *const _this)>(0x155ACD0);
	static inline auto FGetMarkedEnemyComponentOv1 = PreyFunction<ArkMarkedEnemyComponent &(ArkPlayerComponent *const _this)>(0x155AD40);
	static inline auto FGetMarkedEnemyComponentOv0 = PreyFunction<ArkMarkedEnemyComponent const &(ArkPlayerComponent const *const _this)>(0x155AD40);
	static inline auto FGetScopeComponentOv1 = PreyFunction<ArkPlayerScopeComponent &(ArkPlayerComponent *const _this)>(0x155ADA0);
	static inline auto FGetScopeComponentOv0 = PreyFunction<ArkPlayerScopeComponent const &(ArkPlayerComponent const *const _this)>(0x155ADA0);
	static inline auto FGetGameMetricComponentOv1 = PreyFunction<ArkGameMetricsComponent &(ArkPlayerComponent *const _this)>(0x1906510);
	static inline auto FGetFocusModeComponentOv1 = PreyFunction<ArkFocusModeComponent &(ArkPlayerComponent *const _this)>(0x155AD20);
	static inline auto FGetFocusModeComponentOv0 = PreyFunction<ArkFocusModeComponent const &(ArkPlayerComponent const *const _this)>(0x155AD20);
	static inline auto FGetLiveTranscribeComponentOv1 = PreyFunction<ArkLiveTranscribeComponent &(ArkPlayerComponent *const _this)>(0xE98550);
	static inline auto FGetStationAccessComponentOv1 = PreyFunction<ArkStationAccessComponent &(ArkPlayerComponent *const _this)>(0x116D810);
	static inline auto FGetPOIComponentOv1 = PreyFunction<ArkPOIComponent &(ArkPlayerComponent *const _this)>(0x155AD60);
	static inline auto FGetPlayerSpeaker = PreyFunction<ArkSpeakerBase *(ArkPlayerComponent *const _this)>(0x833BD0);
	static inline auto FGetSuitSpeaker = PreyFunction<ArkSpeakerBase *(ArkPlayerComponent *const _this)>(0x36CFD0);
	static inline auto FGetDiscRifleSpeaker = PreyFunction<ArkSpeakerBase *(ArkPlayerComponent *const _this)>(0x155AD00);
	static inline auto FGetTranscribeSpeaker = PreyFunction<ArkSpeaker<ArkDialogPlayerTranscribe> *(ArkPlayerComponent *const _this)>(0x9046A0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerComponent *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x155B4F0);
	static inline auto FPreSerialize = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B4C0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerComponent *const _this, TSerialize _ser)>(0x155BBD0);
	static inline auto FSerializeForLevelTransition = PreyFunction<void(ArkPlayerComponent *const _this, TSerialize _ser)>(0x155BF80);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B310);
	static inline auto FPostSerializeForLevelTransition = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B460);
	static inline auto FCollectNote = PreyFunction<void(ArkPlayerComponent *const _this, int64_t _id)>(0x155AC70);
	static inline auto FOnDead = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B150);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPlayerComponent *const _this)>(0x155B250);
	static inline auto FTriggerDamageDialog = PreyFunction<void(ArkPlayerComponent const *const _this, const float _damage)>(0x155C090);
	static inline auto FSetItemsRestricted = PreyFunction<void(ArkPlayerComponent *const _this, const bool _bRestricted)>(0x155C020);
	static inline auto FSerializeEither = PreyFunction<void(ArkPlayerComponent *const _this, TSerialize _ser)>(0x155BC70);
};

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayercomponent.h
class ClimbPosInfo // Id=80173E6 Size=16
{
public:
	Vec3 m_point;
	EStance m_stance;
	
	ClimbPosInfo(Vec3 _point, EStance _stance);
	Vec3 GetPoint() const { return FGetPoint(this); }
	EStance GetStance() const { return FGetStance(this); }
	
	static inline auto FGetPoint = PreyFunction<Vec3(ClimbPosInfo const *const _this)>(0x155AD70);
	static inline auto FGetStance = PreyFunction<EStance(ClimbPosInfo const *const _this)>(0x1A4D090);
};

