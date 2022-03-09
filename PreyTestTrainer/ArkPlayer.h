
#include <iostream>
#include <memory>
#include <vector>
#include <optional>
#include "ArkBasicTypes.h"
using std::vector;
using std::unique_ptr;

typedef unsigned char   undefined;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef char    sbyte;
typedef signed char    schar;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct ArkPlayer ArkPlayer, *PArkPlayer;

typedef struct ArkPlayerMovementFSM ArkPlayerMovementFSM, *PArkPlayerMovementFSM;

typedef struct ArkPlayerComponent ArkPlayerComponent, *PArkPlayerComponent;

typedef struct ArkStatsComponent ArkStatsComponent, *PArkStatsComponent;

typedef struct ArkEquipmentModComponent ArkEquipmentModComponent, *PArkEquipmentModComponent;

typedef struct ArkPlayerInput ArkPlayerInput, *PArkPlayerInput;

typedef struct ArkExaminationMode ArkExaminationMode, *PArkExaminationMode;

typedef struct ArkPlayerInteraction ArkPlayerInteraction, *PArkPlayerInteraction;

typedef struct ArkGroundColliderComponent ArkGroundColliderComponent, *PArkGroundColliderComponent;

typedef struct ArkPlayerFlashlight ArkPlayerFlashlight, *PArkPlayerFlashlight;

typedef struct ArkPlayerAudio ArkPlayerAudio, *PArkPlayerAudio;

typedef struct ArkPlayerCamera ArkPlayerCamera, *PArkPlayerCamera;

typedef struct ArkPlayerHelmet ArkPlayerHelmet, *PArkPlayerHelmet;

typedef struct ArkPlayerWeaponComponent ArkPlayerWeaponComponent, *PArkPlayerWeaponComponent;

typedef struct vector<IPlayerEventListener*,std::allocator<IPlayerEventListener*>> vector<IPlayerEventListener*,std::allocator<IPlayerEventListener*>>, *Pvector<IPlayerEventListener*,std::allocator<IPlayerEventListener*>>;

typedef struct vector<std::pair<CryStringT<char>,unsignedint>,std::allocator<std::pair<CryStringT<char>,unsignedint>>> vector<std::pair<CryStringT<char>,unsignedint>,std::allocator<std::pair<CryStringT<char>,unsignedint>>>, *Pvector<std::pair<CryStringT<char>,unsignedint>,std::allocator<std::pair<CryStringT<char>,unsignedint>>>;

typedef struct vector<unsigned__int64,std::allocator<unsigned__int64>> vector<unsigned__int64,std::allocator<unsigned__int64>>, *Pvector<unsigned__int64,std::allocator<unsigned__int64>>;

typedef struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> vector<CryStringT<char>,std::allocator<CryStringT<char>>>, *Pvector<CryStringT<char>,std::allocator<CryStringT<char>>>;

typedef struct array<StanceInfo,18> array<StanceInfo,18>, *Parray<StanceInfo,18>;

typedef struct CryStringT<char> CryStringT<char>, *PCryStringT<char>;


typedef struct _smart_ptr<IAction> _smart_ptr<IAction>, *P_smart_ptr<IAction>;

typedef struct unique_ptr<ArkPlayerMovementController,std::default_delete<ArkPlayerMovementController>> unique_ptr<ArkPlayerMovementController,std::default_delete<ArkPlayerMovementController>>, *Punique_ptr<ArkPlayerMovementController,std::default_delete<ArkPlayerMovementController>>;

typedef struct IAnimatedCharacter IAnimatedCharacter, *PIAnimatedCharacter;

typedef struct ArkInventory ArkInventory, *PArkInventory;

typedef struct unique_ptr<CFragmentCache,std::default_delete<CFragmentCache>> unique_ptr<CFragmentCache,std::default_delete<CFragmentCache>>, *Punique_ptr<CFragmentCache,std::default_delete<CFragmentCache>>;

typedef ulonglong __uint64;

typedef struct ArkSimpleTimer ArkSimpleTimer, *PArkSimpleTimer;

typedef enum EStance {
    STANCE_UNLOCKED=-2,
    STANCE_NULL=-1,
    STANCE_STAND=0,
    STANCE_SNEAK=1,
    STANCE_CRAWL=2,
    STANCE_SMOKE=3,
    STANCE_PRONE=4,
    STANCE_RELAXED=5,
    STANCE_STEALTH=6,
    STANCE_ALERTED=7,
    STANCE_SWIM=8,
    STANCE_ZEROG=9,
    STANCE_HOVER=10,
    STANCE_CORRUPTED=11,
    STANCE_INVESTIGATE_ANOMALY=12,
    STANCE_INVESTIGATE_DANGER=13,
    STANCE_INVESTIGATE_VISION=14,
    STANCE_HUNT=15,
    STANCE_GUNUP=16,
    STANCE_CHARGE=17,
    STANCE_LAST=18
} EStance;

typedef struct ArkPlayerAttentionObject ArkPlayerAttentionObject, *PArkPlayerAttentionObject;

typedef struct ArkPlayerZoomManager ArkPlayerZoomManager, *PArkPlayerZoomManager;

typedef struct vector<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>,std::allocator<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>>> vector<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>,std::allocator<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>>>, *Pvector<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>,std::allocator<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>>>;

typedef struct ArkMaterialAnimationManager ArkMaterialAnimationManager, *PArkMaterialAnimationManager;

typedef struct optional<ClimbPosInfo> optional<ClimbPosInfo>, *Poptional<ClimbPosInfo>;

typedef struct StagingInfo StagingInfo, *PStagingInfo;

typedef enum EArkFlyMode {
    off=0,
    on=1,
    onNoCollision=2
} EArkFlyMode;

typedef struct unique_ptr<CArkPsiComponent,std::default_delete<CArkPsiComponent>> unique_ptr<CArkPsiComponent,std::default_delete<CArkPsiComponent>>, *Punique_ptr<CArkPsiComponent,std::default_delete<CArkPsiComponent>>;

typedef struct unique_ptr<ArkAbilityComponent,std::default_delete<ArkAbilityComponent>> unique_ptr<ArkAbilityComponent,std::default_delete<ArkAbilityComponent>>, *Punique_ptr<ArkAbilityComponent,std::default_delete<ArkAbilityComponent>>;

typedef struct unique_ptr<ArkAudioLogComponent,std::default_delete<ArkAudioLogComponent>> unique_ptr<ArkAudioLogComponent,std::default_delete<ArkAudioLogComponent>>, *Punique_ptr<ArkAudioLogComponent,std::default_delete<ArkAudioLogComponent>>;

typedef struct unique_ptr<ArkNoteComponent,std::default_delete<ArkNoteComponent>> unique_ptr<ArkNoteComponent,std::default_delete<ArkNoteComponent>>, *Punique_ptr<ArkNoteComponent,std::default_delete<ArkNoteComponent>>;

typedef struct unique_ptr<ArkKeyCodeComponent,std::default_delete<ArkKeyCodeComponent>> unique_ptr<ArkKeyCodeComponent,std::default_delete<ArkKeyCodeComponent>>, *Punique_ptr<ArkKeyCodeComponent,std::default_delete<ArkKeyCodeComponent>>;

typedef struct unique_ptr<ArkLocationComponent,std::default_delete<ArkLocationComponent>> unique_ptr<ArkLocationComponent,std::default_delete<ArkLocationComponent>>, *Punique_ptr<ArkLocationComponent,std::default_delete<ArkLocationComponent>>;

typedef struct unique_ptr<ArkLoreComponent,std::default_delete<ArkLoreComponent>> unique_ptr<ArkLoreComponent,std::default_delete<ArkLoreComponent>>, *Punique_ptr<ArkLoreComponent,std::default_delete<ArkLoreComponent>>;

typedef struct unique_ptr<ArkKeyCardComponent,std::default_delete<ArkKeyCardComponent>> unique_ptr<ArkKeyCardComponent,std::default_delete<ArkKeyCardComponent>>, *Punique_ptr<ArkKeyCardComponent,std::default_delete<ArkKeyCardComponent>>;

typedef struct unique_ptr<ArkEmailComponent,std::default_delete<ArkEmailComponent>> unique_ptr<ArkEmailComponent,std::default_delete<ArkEmailComponent>>, *Punique_ptr<ArkEmailComponent,std::default_delete<ArkEmailComponent>>;

typedef struct unique_ptr<ArkQuickSelectComponent,std::default_delete<ArkQuickSelectComponent>> unique_ptr<ArkQuickSelectComponent,std::default_delete<ArkQuickSelectComponent>>, *Punique_ptr<ArkQuickSelectComponent,std::default_delete<ArkQuickSelectComponent>>;

typedef struct unique_ptr<ArkRosterComponent,std::default_delete<ArkRosterComponent>> unique_ptr<ArkRosterComponent,std::default_delete<ArkRosterComponent>>, *Punique_ptr<ArkRosterComponent,std::default_delete<ArkRosterComponent>>;

typedef struct unique_ptr<ArkUtilityComponent,std::default_delete<ArkUtilityComponent>> unique_ptr<ArkUtilityComponent,std::default_delete<ArkUtilityComponent>>, *Punique_ptr<ArkUtilityComponent,std::default_delete<ArkUtilityComponent>>;

typedef struct unique_ptr<ArkPharmaComponent,std::default_delete<ArkPharmaComponent>> unique_ptr<ArkPharmaComponent,std::default_delete<ArkPharmaComponent>>, *Punique_ptr<ArkPharmaComponent,std::default_delete<ArkPharmaComponent>>;

typedef struct unique_ptr<ArkPDAComponent,std::default_delete<ArkPDAComponent>> unique_ptr<ArkPDAComponent,std::default_delete<ArkPDAComponent>>, *Punique_ptr<ArkPDAComponent,std::default_delete<ArkPDAComponent>>;

typedef struct unique_ptr<ArkPlayerAchievementComponent,std::default_delete<ArkPlayerAchievementComponent>> unique_ptr<ArkPlayerAchievementComponent,std::default_delete<ArkPlayerAchievementComponent>>, *Punique_ptr<ArkPlayerAchievementComponent,std::default_delete<ArkPlayerAchievementComponent>>;

typedef struct unique_ptr<ArkPlayerAwarenessComponent,std::default_delete<ArkPlayerAwarenessComponent>> unique_ptr<ArkPlayerAwarenessComponent,std::default_delete<ArkPlayerAwarenessComponent>>, *Punique_ptr<ArkPlayerAwarenessComponent,std::default_delete<ArkPlayerAwarenessComponent>>;

typedef struct unique_ptr<ArkPlayerEntitlementComponent,std::default_delete<ArkPlayerEntitlementComponent>> unique_ptr<ArkPlayerEntitlementComponent,std::default_delete<ArkPlayerEntitlementComponent>>, *Punique_ptr<ArkPlayerEntitlementComponent,std::default_delete<ArkPlayerEntitlementComponent>>;

typedef struct unique_ptr<ArkPlayerFatigueComponent,std::default_delete<ArkPlayerFatigueComponent>> unique_ptr<ArkPlayerFatigueComponent,std::default_delete<ArkPlayerFatigueComponent>>, *Punique_ptr<ArkPlayerFatigueComponent,std::default_delete<ArkPlayerFatigueComponent>>;

typedef struct unique_ptr<ArkPlayerHealthComponent,std::default_delete<ArkPlayerHealthComponent>> unique_ptr<ArkPlayerHealthComponent,std::default_delete<ArkPlayerHealthComponent>>, *Punique_ptr<ArkPlayerHealthComponent,std::default_delete<ArkPlayerHealthComponent>>;

typedef struct unique_ptr<ArkPlayerRadiationComponent,std::default_delete<ArkPlayerRadiationComponent>> unique_ptr<ArkPlayerRadiationComponent,std::default_delete<ArkPlayerRadiationComponent>>, *Punique_ptr<ArkPlayerRadiationComponent,std::default_delete<ArkPlayerRadiationComponent>>;

typedef struct unique_ptr<ArkPlayerLightManager,std::default_delete<ArkPlayerLightManager>> unique_ptr<ArkPlayerLightManager,std::default_delete<ArkPlayerLightManager>>, *Punique_ptr<ArkPlayerLightManager,std::default_delete<ArkPlayerLightManager>>;

typedef struct unique_ptr<ArkPlayerFXComponent,std::default_delete<ArkPlayerFXComponent>> unique_ptr<ArkPlayerFXComponent,std::default_delete<ArkPlayerFXComponent>>, *Punique_ptr<ArkPlayerFXComponent,std::default_delete<ArkPlayerFXComponent>>;

typedef struct unique_ptr<ArkPlayerUIComponent,std::default_delete<ArkPlayerUIComponent>> unique_ptr<ArkPlayerUIComponent,std::default_delete<ArkPlayerUIComponent>>, *Punique_ptr<ArkPlayerUIComponent,std::default_delete<ArkPlayerUIComponent>>;

typedef struct unique_ptr<ArkFabricationPlanComponent,std::default_delete<ArkFabricationPlanComponent>> unique_ptr<ArkFabricationPlanComponent,std::default_delete<ArkFabricationPlanComponent>>, *Punique_ptr<ArkFabricationPlanComponent,std::default_delete<ArkFabricationPlanComponent>>;

typedef struct unique_ptr<ArkPlayerStatusComponent,std::default_delete<ArkPlayerStatusComponent>> unique_ptr<ArkPlayerStatusComponent,std::default_delete<ArkPlayerStatusComponent>>, *Punique_ptr<ArkPlayerStatusComponent,std::default_delete<ArkPlayerStatusComponent>>;

typedef struct unique_ptr<ArkPlayerPropulsionComponent,std::default_delete<ArkPlayerPropulsionComponent>> unique_ptr<ArkPlayerPropulsionComponent,std::default_delete<ArkPlayerPropulsionComponent>>, *Punique_ptr<ArkPlayerPropulsionComponent,std::default_delete<ArkPlayerPropulsionComponent>>;

typedef struct unique_ptr<ArkPlayerSignalReceiver,std::default_delete<ArkPlayerSignalReceiver>> unique_ptr<ArkPlayerSignalReceiver,std::default_delete<ArkPlayerSignalReceiver>>, *Punique_ptr<ArkPlayerSignalReceiver,std::default_delete<ArkPlayerSignalReceiver>>;

typedef struct unique_ptr<ArkAimAssistComponent,std::default_delete<ArkAimAssistComponent>> unique_ptr<ArkAimAssistComponent,std::default_delete<ArkAimAssistComponent>>, *Punique_ptr<ArkAimAssistComponent,std::default_delete<ArkAimAssistComponent>>;

typedef struct unique_ptr<ArkMarkedEnemyComponent,std::default_delete<ArkMarkedEnemyComponent>> unique_ptr<ArkMarkedEnemyComponent,std::default_delete<ArkMarkedEnemyComponent>>, *Punique_ptr<ArkMarkedEnemyComponent,std::default_delete<ArkMarkedEnemyComponent>>;

typedef struct unique_ptr<ArkPlayerScopeComponent,std::default_delete<ArkPlayerScopeComponent>> unique_ptr<ArkPlayerScopeComponent,std::default_delete<ArkPlayerScopeComponent>>, *Punique_ptr<ArkPlayerScopeComponent,std::default_delete<ArkPlayerScopeComponent>>;

typedef struct unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>> unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>>, *Punique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>>;

typedef struct unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>,std::default_delete<ArkSpeaker<ArkDialogPlayerTranscribe>>> unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>,std::default_delete<ArkSpeaker<ArkDialogPlayerTranscribe>>>, *Punique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>,std::default_delete<ArkSpeaker<ArkDialogPlayerTranscribe>>>;

typedef struct unique_ptr<ArkGameMetricsComponent,std::default_delete<ArkGameMetricsComponent>> unique_ptr<ArkGameMetricsComponent,std::default_delete<ArkGameMetricsComponent>>, *Punique_ptr<ArkGameMetricsComponent,std::default_delete<ArkGameMetricsComponent>>;

typedef struct unique_ptr<ArkFocusModeComponent,std::default_delete<ArkFocusModeComponent>> unique_ptr<ArkFocusModeComponent,std::default_delete<ArkFocusModeComponent>>, *Punique_ptr<ArkFocusModeComponent,std::default_delete<ArkFocusModeComponent>>;

typedef struct unique_ptr<ArkLiveTranscribeComponent,std::default_delete<ArkLiveTranscribeComponent>> unique_ptr<ArkLiveTranscribeComponent,std::default_delete<ArkLiveTranscribeComponent>>, *Punique_ptr<ArkLiveTranscribeComponent,std::default_delete<ArkLiveTranscribeComponent>>;

typedef struct unique_ptr<ArkStationAccessComponent,std::default_delete<ArkStationAccessComponent>> unique_ptr<ArkStationAccessComponent,std::default_delete<ArkStationAccessComponent>>, *Punique_ptr<ArkStationAccessComponent,std::default_delete<ArkStationAccessComponent>>;

typedef struct unique_ptr<ArkPOIComponent,std::default_delete<ArkPOIComponent>> unique_ptr<ArkPOIComponent,std::default_delete<ArkPOIComponent>>, *Punique_ptr<ArkPOIComponent,std::default_delete<ArkPOIComponent>>;

typedef struct unordered_map<CCryName,ArkStatsComponent::ArkStat,std::hash<CCryName>,std::equal_to<CCryName>,std::allocator<std::pair<CCryNameconst,ArkStatsComponent::ArkStat>>> unordered_map<CCryName,ArkStatsComponent::ArkStat,std::hash<CCryName>,std::equal_to<CCryName>,std::allocator<std::pair<CCryNameconst,ArkStatsComponent::ArkStat>>>, *Punordered_map<CCryName,ArkStatsComponent::ArkStat,std::hash<CCryName>,std::equal_to<CCryName>,std::allocator<std::pair<CCryNameconst,ArkStatsComponent::ArkStat>>>;

typedef struct ArkStatModifierPackages ArkStatModifierPackages, *PArkStatModifierPackages;

typedef struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>>, *Punordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>>;

typedef struct vector<unsignedint,std::allocator<unsignedint>> vector<unsignedint,std::allocator<unsignedint>>, *Pvector<unsignedint,std::allocator<unsignedint>>;

typedef struct array<unsignedint,8> array<unsignedint,8>, *Parray<unsignedint,8>;

typedef struct vector<ArkPlayerInput::ModeAndHandle,std::allocator<ArkPlayerInput::ModeAndHandle>> vector<ArkPlayerInput::ModeAndHandle,std::allocator<ArkPlayerInput::ModeAndHandle>>, *Pvector<ArkPlayerInput::ModeAndHandle,std::allocator<ArkPlayerInput::ModeAndHandle>>;

typedef struct TActionHandler<ArkPlayerInput> TActionHandler<ArkPlayerInput>, *PTActionHandler<ArkPlayerInput>;

typedef struct Ang3_tpl<float> Ang3_tpl<float>, *PAng3_tpl<float>;

typedef struct MovementButtonPressInfo MovementButtonPressInfo, *PMovementButtonPressInfo;



typedef enum CinematicMode {
    off=0,
    allowLook=1,
    complete=2
} CinematicMode;

typedef enum Mode {
    player=0,
    world_ui_examination=1,
    examination=2,
    menu=3,
    flycam=4,
    focusmode=5,
    ether_duplicate=6,
    hacking=7,
    psi_scanning_fanfare=8,
    mimic_grab=9,
    _count=10
} Mode;


typedef enum EArkExaminationType {
    none=0,
    worldUI=1,
    telescope=2,
    other=3
} EArkExaminationType;

typedef enum EArkExaminationState {
    inactive=0,
    active=1,
    exiting=2
} EArkExaminationState;

typedef enum ExamineMode {
    Normal=0,
    RemoteManipulation=1,
    Forced=2
} ExamineMode;

typedef struct ArkInputLegend ArkInputLegend, *PArkInputLegend;

typedef struct ArkInputLegendHandler ArkInputLegendHandler, *PArkInputLegendHandler;

typedef struct ArkEntityGrabber ArkEntityGrabber, *PArkEntityGrabber;

typedef struct ArkPlayerCarry ArkPlayerCarry, *PArkPlayerCarry;

typedef struct array<ArkInteractionInfo,4> array<ArkInteractionInfo,4>, *Parray<ArkInteractionInfo,4>;

typedef struct array<bool,4> array<bool,4>, *Parray<bool,4>;

typedef struct ArkPlayerTargetSelector ArkPlayerTargetSelector, *PArkPlayerTargetSelector;

typedef struct ArkInventoryPreview ArkInventoryPreview, *PArkInventoryPreview;

typedef struct ArkButtonPromptCollection ArkButtonPromptCollection, *PArkButtonPromptCollection;

typedef struct IEntity IEntity, *PIEntity;

typedef struct ArkPlayerLightEntity ArkPlayerLightEntity, *PArkPlayerLightEntity;

typedef struct ArkAudioTrigger ArkAudioTrigger, *PArkAudioTrigger;

typedef struct vector<ArkPlayerFlashlight::DimRange,std::allocator<ArkPlayerFlashlight::DimRange>> vector<ArkPlayerFlashlight::DimRange,std::allocator<ArkPlayerFlashlight::DimRange>>, *Pvector<ArkPlayerFlashlight::DimRange,std::allocator<ArkPlayerFlashlight::DimRange>>;

typedef struct TArkAudioSwitch<enumEPlayerSex> TArkAudioSwitch<enumEPlayerSex>, *PTArkAudioSwitch<enumEPlayerSex>;

typedef struct ArkAudioRtpc ArkAudioRtpc, *PArkAudioRtpc;

typedef struct ArkAudioSwitch ArkAudioSwitch, *PArkAudioSwitch;

typedef struct ArkAudioSwitchState ArkAudioSwitchState, *PArkAudioSwitchState;

typedef struct array<CryStringT<char>,17> array<CryStringT<char>,17>, *Parray<CryStringT<char>,17>;

typedef struct function<Quat_tpl<float>__cdecl(float)> function<Quat_tpl<float>__cdecl(float)>, *Pfunction<Quat_tpl<float>__cdecl(float)>;

typedef struct function<Vec3_tpl<float>__cdecl(float)> function<Vec3_tpl<float>__cdecl(float)>, *Pfunction<Vec3_tpl<float>__cdecl(float)>;

typedef struct function<void__cdecl(SViewParams&)> function<void__cdecl(SViewParams&)>, *Pfunction<void__cdecl(SViewParams&)>;


/* WARNING! conflicting data type names: /PreyDll.pdb/ArkPlayerCamera/Mode - /PreyDll.pdb/ArkPlayerInput/Mode */

typedef struct unique_ptr<ArkPlayerOxygenComponent,std::default_delete<ArkPlayerOxygenComponent>> unique_ptr<ArkPlayerOxygenComponent,std::default_delete<ArkPlayerOxygenComponent>>, *Punique_ptr<ArkPlayerOxygenComponent,std::default_delete<ArkPlayerOxygenComponent>>;

typedef enum EQueuedDialog {
    none=0,
    activate=1,
    deactivate=2
} EQueuedDialog;

typedef struct vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>> vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>>, *Pvector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>>;

typedef struct StanceInfo StanceInfo, *PStanceInfo;

typedef struct IAction IAction, *PIAction;

typedef enum EArkGridSizes {
    tinyExternal=0,
    smallExternal=1,
    mediumExternal=2,
    largeExternal=3,
    chipSet=4,
    player=5,
    overflow=6
} EArkGridSizes;

typedef struct vector<ArkInventory::StorageCell,std::allocator<ArkInventory::StorageCell>> vector<ArkInventory::StorageCell,std::allocator<ArkInventory::StorageCell>>, *Pvector<ArkInventory::StorageCell,std::allocator<ArkInventory::StorageCell>>;

typedef enum InventorySort {
    none=0,
    name=1,
    category=2,
    size=3,
    last=4
} InventorySort;

typedef struct vector<ArkPlayerZoomManager::ZoomData,std::allocator<ArkPlayerZoomManager::ZoomData>> vector<ArkPlayerZoomManager::ZoomData,std::allocator<ArkPlayerZoomManager::ZoomData>>, *Pvector<ArkPlayerZoomManager::ZoomData,std::allocator<ArkPlayerZoomManager::ZoomData>>;

typedef struct vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>> vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>>, *Pvector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>>;

typedef struct ArkMaterialAnimation ArkMaterialAnimation, *PArkMaterialAnimation;

typedef struct ActiveAnimationData ActiveAnimationData, *PActiveAnimationData;

typedef struct unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>> unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>>, *Punordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>>;

typedef struct vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>> vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>>, *Pvector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>>;

typedef struct vector<ArkStatModifierPackage,std::allocator<ArkStatModifierPackage>> vector<ArkStatModifierPackage,std::allocator<ArkStatModifierPackage>>, *Pvector<ArkStatModifierPackage,std::allocator<ArkStatModifierPackage>>;

typedef struct multimap<CCryName,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float),std::less<CCryName>,std::allocator<std::pair<CCryNameconst,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float)>>> multimap<CCryName,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float),std::less<CCryName>,std::allocator<std::pair<CCryNameconst,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float)>>>, *Pmultimap<CCryName,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float),std::less<CCryName>,std::allocator<std::pair<CCryNameconst,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float)>>>;

typedef struct vector<ArkInputLegendItem,std::allocator<ArkInputLegendItem>> vector<ArkInputLegendItem,std::allocator<ArkInputLegendItem>>, *Pvector<ArkInputLegendItem,std::allocator<ArkInputLegendItem>>;

typedef struct array<float,4> array<float,4>, *Parray<float,4>;

typedef struct ArkInteractionInfo ArkInteractionInfo, *PArkInteractionInfo;

typedef struct vector<ArkPlayerTargetSelector::ArkPlayerTarget,std::allocator<ArkPlayerTargetSelector::ArkPlayerTarget>> vector<ArkPlayerTargetSelector::ArkPlayerTarget,std::allocator<ArkPlayerTargetSelector::ArkPlayerTarget>>, *Pvector<ArkPlayerTargetSelector::ArkPlayerTarget,std::allocator<ArkPlayerTargetSelector::ArkPlayerTarget>>;

typedef struct map<unsigned__int64,float,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,float>>> map<unsigned__int64,float,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,float>>>, *Pmap<unsigned__int64,float,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,float>>>;

typedef struct array<ArkButtonPrompt,8> array<ArkButtonPrompt,8>, *Parray<ArkButtonPrompt,8>;

typedef struct ArkExclusiveActionFilter ArkExclusiveActionFilter, *PArkExclusiveActionFilter;

typedef struct SAnimationContext SAnimationContext, *PSAnimationContext;

typedef enum EStatus {
    None=0,
    Pending=1,
    Installed=2,
    Exiting=3,
    Finished=4
} EStatus;

typedef struct IScope IScope, *PIScope;

typedef struct STagState<12> STagState<12>, *PSTagState<12>;

typedef struct CMannequinParams CMannequinParams, *PCMannequinParams;

typedef struct DynArray<_smart_ptr<IAction>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<_smart_ptr<IAction>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<_smart_ptr<IAction>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>> vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>>, *Pvector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>>;

typedef struct vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>> vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>>, *Pvector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>>;

typedef enum EArkInteractionType {
    none=0,
    scriptDefined=1,
    unavailable=2,
    codeDefined=3,
    pickup=4,
    consume=5,
    carry=6,
    hack=7,
    repair=8,
    fortify=9,
    examine=10,
    equip=11,
    hoover=12,
    last=13
} EArkInteractionType;

typedef struct ArkButtonPrompt ArkButtonPrompt, *PArkButtonPrompt;

typedef struct vector<CCryName,std::allocator<CCryName>> vector<CCryName,std::allocator<CCryName>>, *Pvector<CCryName,std::allocator<CCryName>>;

typedef struct SControllerDef SControllerDef, *PSControllerDef;

typedef struct CTagState CTagState, *PCTagState;

typedef struct DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct CMTRand_int32 CMTRand_int32, *PCMTRand_int32;

typedef struct vector<SMannParameter,std::allocator<SMannParameter>> vector<SMannParameter,std::allocator<SMannParameter>>, *Pvector<SMannParameter,std::allocator<SMannParameter>>;

typedef struct CCryName CCryName, *PCCryName;

typedef struct CryStringT<wchar_t> CryStringT<wchar_t>, *PCryStringT<wchar_t>;

typedef struct SCRCRef<1,SCRCRefHash_CRC32Lowercase> SCRCRef<1,SCRCRefHash_CRC32Lowercase>, *PSCRCRef<1,SCRCRefHash_CRC32Lowercase>;

typedef struct CTagDefinition CTagDefinition, *PCTagDefinition;

typedef struct DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef wchar_t wchar;

typedef struct DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct STagDefData STagDefData, *PSTagDefData;

typedef struct DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

struct unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>,std::default_delete<ArkSpeaker<ArkDialogPlayerTranscribe>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct STagState<12> {
    uchar state[12];
};

struct ArkGroundColliderComponent {
    struct IEntity * m_pOwner;
    uint m_groundEntity;
};

struct unique_ptr<ArkPharmaComponent,std::default_delete<ArkPharmaComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<SMannParameter,std::allocator<SMannParameter>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct function<Quat_tpl<float>__cdecl(float)> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct unique_ptr<ArkAudioLogComponent,std::default_delete<ArkAudioLogComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkRosterComponent,std::default_delete<ArkRosterComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct STagDefData {
    struct DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> tagMasks;
    struct DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> groupMasks;
    uint numBits;
    undefined field3_0x14;
    undefined field4_0x15;
    undefined field5_0x16;
    undefined field6_0x17;
};

struct vector<std::pair<CryStringT<char>,unsignedint>,std::allocator<std::pair<CryStringT<char>,unsignedint>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ActiveAnimationData {
    struct vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>> m_keyframeQueue;
};

struct vector<ArkPlayerTargetSelector::ArkPlayerTarget,std::allocator<ArkPlayerTargetSelector::ArkPlayerTarget>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkAudioTrigger {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct Vec2_tpl<float> {
    float x;
    float y;
};

struct vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkMaterialAnimationManager {
    struct IEntity * m_pEntity;
    struct vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>> m_attachmentMaterials;
    struct ArkMaterialAnimation * m_pOneOffMaterialAnimation;
    struct ActiveAnimationData m_oneOffAnimationData;
    struct unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>> m_animationsByType;
    struct ActiveAnimationData m_activeAnimationsByType[18];
    struct vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>> m_materialParameterRamps;
};

struct vector<ArkInventory::StorageCell,std::allocator<ArkInventory::StorageCell>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct array<unsignedint,8> {
    uint _Elems[8];
};

struct vector<unsignedint,std::allocator<unsignedint>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkEquipmentModComponent {
    bool m_bSuitMods;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct vector<unsignedint,std::allocator<unsignedint>> m_ownedChipsets;
    struct array<unsignedint,8> m_installedChipsets;
};

struct vector<unsigned__int64,std::allocator<unsigned__int64>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerWeaponComponent {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    struct vector<unsignedint,std::allocator<unsignedint>> m_weaponEntityIds;
    struct vector<unsignedint,std::allocator<unsignedint>> m_specialWeaponIds;
    struct ArkPlayer * m_player;
    struct ArkAudioTrigger m_triggerSneakAttack;
    struct ArkAudioTrigger m_triggerCriticalHit;
    uint m_equippedWeaponId;
    uint m_lastEquippedWeaponId;
    uint m_backupWeaponId;
    uint m_toBeEquippedWeaponId;
    float m_weaponCameraSpeedMultiplierAcceleration;
    float m_weaponCameraSpeedMultiplier;
    float m_aimAssistTargetRangeSq;
    float m_gameLogReportWindow;
    bool m_bIsUnequipping;
    bool m_bCanEquip;
    undefined field39_0x7a;
    undefined field40_0x7b;
    undefined field41_0x7c;
    undefined field42_0x7d;
    undefined field43_0x7e;
    undefined field44_0x7f;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_weaponTypesAcquired;
    struct vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>> m_sneakAttackData;
    struct vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>> m_criticalHitData;
    struct vector<ArkPlayerWeaponComponent::GameLogData,std::allocator<ArkPlayerWeaponComponent::GameLogData>> m_mimicHitData;
};

struct unique_ptr<ArkQuickSelectComponent,std::default_delete<ArkQuickSelectComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<IPlayerEventListener*,std::allocator<IPlayerEventListener*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct unique_ptr<ArkEmailComponent,std::default_delete<ArkEmailComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct SCRCRef<1,SCRCRefHash_CRC32Lowercase> {
    uint crc;
    char * stringValue;
};

struct DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CryStringT<char> {
    char * m_str;
};

struct DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CTagDefinition {
    struct CryStringT<char> m_filename;
    struct DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_tags;
    struct DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_tagGroups;
    struct STagDefData m_defData;
    struct DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_priorityTallies;
    bool m_hasMasks;
};

struct DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct SControllerDef {
    struct SCRCRef<1,SCRCRefHash_CRC32Lowercase> m_filename;
    struct CTagDefinition * m_tags;
    struct CTagDefinition * m_fragmentIDs;
    struct CTagDefinition m_scopeIDs;
    struct CTagDefinition m_subContextIDs;
    struct CTagDefinition m_scopeContexts;
    struct DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_fragmentDef;
    struct DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_scopeDef;
    struct DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_scopeContextDef;
    struct DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_subContext;
};

struct IEntity {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct Ang3_tpl<float> {
    float x;
    float y;
    float z;
};

struct vector<CCryName,std::allocator<CCryName>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkExclusiveActionFilter {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    bool m_bIgnoreActionMapState;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    struct CryStringT<char> m_filterName;
    struct CryStringT<char> m_actionMap;
    struct vector<CCryName,std::allocator<CCryName>> m_filteredActionIds;
    struct vector<CCryName,std::allocator<CCryName>> m_allowedActionIds;
};

struct vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkMaterialAnimation {
    __uint64 m_Id;
    struct CryStringT<char> m_Name;
    struct CryStringT<char> m_AttachmentName;
    int m_MeshSlot;
    struct CryStringT<char> m_MaterialReference;
    struct vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>> m_SubMaterials;
    struct vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>> m_keyframeQueue;
};

struct CCryName {
    char * m_str;
};

struct ArkSimpleTimer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float m_duration;
};

struct CryStringT<wchar_t> {
    wchar * m_str;
};

struct ArkButtonPrompt {
    struct CCryName m_actionId;
    struct CryStringT<char> m_actionMap;
    struct ArkSimpleTimer m_holdTimer;
    float m_baseHoldDuration;
    bool m_bUseHoldTriggerDelay;
    struct CryStringT<wchar_t> m_inputPromptString;
    struct CryStringT<wchar_t> m_promptText;
    bool m_bEnabled;
    bool m_bDirty;
};

struct array<ArkButtonPrompt,8> {
    struct ArkButtonPrompt _Elems[8];
};

struct ArkButtonPromptCollection {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct array<ArkButtonPrompt,8> m_buttonPrompts;
    uchar m_maxUsed;
    undefined field18_0x1d1;
    undefined field19_0x1d2;
    undefined field20_0x1d3;
    undefined field21_0x1d4;
    undefined field22_0x1d5;
    undefined field23_0x1d6;
    undefined field24_0x1d7;
    struct CryStringT<char> m_formatFunction;
    struct CryStringT<char> m_setFunctionOrArrayName;
    struct ArkExclusiveActionFilter m_filter;
    bool m_bInitialized;
    undefined field29_0x241;
    undefined field30_0x242;
    undefined field31_0x243;
    undefined field32_0x244;
    undefined field33_0x245;
    undefined field34_0x246;
    undefined field35_0x247;
};

struct ArkAudioSwitchState {
    uint m_id;
};

struct TArkAudioSwitch<enumEPlayerSex> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    struct ArkAudioSwitchState m_states[2];
};

struct ArkAudioRtpc {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct ArkAudioSwitch {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct ArkPlayerAudio {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct TArkAudioSwitch<enumEPlayerSex> m_genderAudioSwitch;
    struct ArkAudioRtpc m_combatIntensityRtpc;
    struct ArkAudioRtpc m_jumpHeightRtpc;
    struct ArkAudioSwitch m_combatAudioSwitch;
    struct ArkAudioSwitchState m_combatOnAudioState;
    struct ArkAudioSwitchState m_combatOffAudioState;
    struct ArkAudioTrigger m_combatEndAudio;
    struct ArkAudioTrigger m_setHelmetOnAtmosphere;
    struct ArkAudioTrigger m_setHelmetOnNoAtmosphere;
    struct ArkAudioTrigger m_setHelmetOffAtmosphere;
    struct ArkAudioTrigger m_setHelmetOffNoAtmosphere;
    struct ArkAudioTrigger m_helmetOn;
    struct ArkAudioTrigger m_helmetOff;
    float m_combatIntensity;
    float m_combatIntensityEventStartThreshold;
    float m_combatIntensityEventStopThreshold;
};

struct unique_ptr<ArkUtilityComponent,std::default_delete<ArkUtilityComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct array<CryStringT<char>,17> {
    struct CryStringT<char> _Elems[17];
};

struct map<unsigned__int64,float,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,float>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct ArkPlayerTargetSelector {
    bool m_bDrawDebug;
    bool m_bIsHoovering;
    float m_innerAimDistance;
    float m_outerAimDistance;
    float m_interactDistance;
    float m_pickupTimerSec;
    float m_pickupMaxCooldownSec;
    float m_pickupInitialCooldownSec;
    uint m_forceSelectEntity;
    struct vector<ArkPlayerTargetSelector::ArkPlayerTarget,std::allocator<ArkPlayerTargetSelector::ArkPlayerTarget>> m_candidateTargets;
    struct map<unsigned__int64,float,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,float>>> m_itemTypePriorityMap;
};

struct ArkInventoryPreview {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct ArkInventory * m_pInventory;
    uint m_interactionEntityId;
    int m_x;
    int m_y;
    int m_startingRow;
    struct ArkAudioTrigger m_lootItemTrigger;
    struct ArkAudioTrigger m_lootFailedTrigger;
    struct ArkAudioTrigger m_inventoryFullTrigger;
    undefined field24_0x34;
    undefined field25_0x35;
    undefined field26_0x36;
    undefined field27_0x37;
    struct ArkButtonPromptCollection m_inputPrompts;
    struct ArkSimpleTimer m_errorTimer;
};

struct vector<ArkInputLegendItem,std::allocator<ArkInputLegendItem>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkInputLegend {
    struct CryStringT<char> m_ActionMap;
    struct vector<ArkInputLegendItem,std::allocator<ArkInputLegendItem>> m_Items;
};

struct array<bool,4> {
    bool _Elems[4];
};

struct ArkInputLegendHandler {
    uint m_handle;
};

struct ArkEntityGrabber {
    float m_breakDistanceSq;
    float m_lastDesiredLerpVelocity;
    float m_timeUnderDesiredLerpVelocity;
    float m_totalDistanceForLerp;
    float m_lerpSpeed;
    float m_lerpObstructedSpeed;
    float m_lerpAcceleration;
    float m_lerpObstructedAcceleration;
    float m_maxTimeAllowedUnderDesiredLerpVelocity;
    bool m_bConstrained;
};

struct Vec3_tpl<float> {
    float x;
    float y;
    float z;
};

struct Quat_tpl<float> {
    struct Vec3_tpl<float> v;
    float w;
};

struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct array<float,4> {
    float _Elems[4];
};

struct ArkPlayerCarry {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct ArkInputLegend m_carryLegend;
    struct ArkInputLegendHandler m_carryLegendHandler;
    struct ArkSimpleTimer m_collisionRestoreTimer;
    struct ArkEntityGrabber m_grabber;
    struct ArkAudioTrigger m_throwAudio;
    struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> m_dragCorpseJointNames;
    struct array<float,4> m_throwKickBacks;
    struct array<float,4> m_leverageHoldDurations;
    struct Quat_tpl<float> m_pickupEntityOriginalRotation;
    uint m_pickedUpEntityId;
    int m_pickedUpEntityConstraintId;
    float m_carryMaxPullForce;
    float m_carryMaxPullForceZeroG;
    float m_carryHeightOffset;
    float m_carryCameraRotationToEntityMinThreshold;
    float m_carryCameraRotationToEntityMaxThreshold;
    float m_carryObjectLengthRotationLimitScaleMin;
    float m_carryObjectLengthRotationLimitScaleMax;
    float m_carrySneakPitchLimit;
    float m_dragCorpseHeight;
    float m_dragCorpseDistance;
    float m_dragCorpseBreakDistanceSq;
    float m_dragCorpseSyncSpeed;
    float m_dragCorpseRemoteSyncSpeed;
    float m_opacity;
    int m_dragCorpsePartId;
    int m_attachedEmitterSlot;
    enum EStance m_dragCorpsePreviousStance;
    bool m_bThrowCarriedEntity;
    bool m_bCastSunShadow;
    bool m_bRemoteManipulatedCorpse;
    bool m_bJustThrown;
};

struct ArkInteractionInfo {
    enum EArkInteractionType m_interactionType;
    struct CryStringT<char> m_displayText;
    bool m_bDisplayTextSpecified;
    float m_holdDuration;
};

struct array<ArkInteractionInfo,4> {
    struct ArkInteractionInfo _Elems[4];
};

struct ArkPlayerInteraction {
    struct ArkEntityGrabber m_remoteItemGrabber;
    struct ArkPlayerCarry m_playerCarry;
    struct array<ArkInteractionInfo,4> m_interactionInfo;
    struct array<bool,4> m_interactionHidden;
    undefined field4_0x18c;
    undefined field5_0x18d;
    undefined field6_0x18e;
    undefined field7_0x18f;
    struct ArkPlayerTargetSelector m_targetSelector;
    struct ArkInventoryPreview m_inventoryPreview;
    struct ArkSimpleTimer m_carryDelay;
    int m_disableInteractionPromptCount;
    uint m_usableEntityId;
    bool m_bCanClimb;
    bool m_bHideFailedAbilityInteractions;
    undefined field15_0x472;
    undefined field16_0x473;
    undefined field17_0x474;
    undefined field18_0x475;
    undefined field19_0x476;
    undefined field20_0x477;
    struct ArkButtonPromptCollection m_buttonPrompts;
    struct ArkInputLegend m_alternativePrompts;
    struct ArkInputLegendHandler m_alternativePromptHandler;
    undefined field24_0x6e4;
    undefined field25_0x6e5;
    undefined field26_0x6e6;
    undefined field27_0x6e7;
};

struct ArkPlayerAttentionObject {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    struct ArkPlayer * m_pPlayer;
    uint m_roomEntityId;
    undefined field34_0x2c;
    undefined field35_0x2d;
    undefined field36_0x2e;
    undefined field37_0x2f;
};

struct _smart_ptr<IAction> {
    struct IAction * p;
};

struct unique_ptr<ArkPlayerRadiationComponent,std::default_delete<ArkPlayerRadiationComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkAimAssistComponent,std::default_delete<ArkAimAssistComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkFocusModeComponent,std::default_delete<ArkFocusModeComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPOIComponent,std::default_delete<ArkPOIComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerScopeComponent,std::default_delete<ArkPlayerScopeComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkKeyCodeComponent,std::default_delete<ArkKeyCodeComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerFXComponent,std::default_delete<ArkPlayerFXComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerPropulsionComponent,std::default_delete<ArkPlayerPropulsionComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkNoteComponent,std::default_delete<ArkNoteComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerAchievementComponent,std::default_delete<ArkPlayerAchievementComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<CArkPsiComponent,std::default_delete<CArkPsiComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkStationAccessComponent,std::default_delete<ArkStationAccessComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerLightManager,std::default_delete<ArkPlayerLightManager>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkLiveTranscribeComponent,std::default_delete<ArkLiveTranscribeComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerSignalReceiver,std::default_delete<ArkPlayerSignalReceiver>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkLocationComponent,std::default_delete<ArkLocationComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPDAComponent,std::default_delete<ArkPDAComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkGameMetricsComponent,std::default_delete<ArkGameMetricsComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerEntitlementComponent,std::default_delete<ArkPlayerEntitlementComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkLoreComponent,std::default_delete<ArkLoreComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerHealthComponent,std::default_delete<ArkPlayerHealthComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerStatusComponent,std::default_delete<ArkPlayerStatusComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkFabricationPlanComponent,std::default_delete<ArkFabricationPlanComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerUIComponent,std::default_delete<ArkPlayerUIComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerFatigueComponent,std::default_delete<ArkPlayerFatigueComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkKeyCardComponent,std::default_delete<ArkKeyCardComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkAbilityComponent,std::default_delete<ArkAbilityComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkPlayerAwarenessComponent,std::default_delete<ArkPlayerAwarenessComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unique_ptr<ArkMarkedEnemyComponent,std::default_delete<ArkMarkedEnemyComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkPlayerComponent {
    struct unique_ptr<CArkPsiComponent,std::default_delete<CArkPsiComponent>> m_pPsiComponent;
    struct unique_ptr<ArkAbilityComponent,std::default_delete<ArkAbilityComponent>> m_pAbilityComponent;
    struct unique_ptr<ArkAudioLogComponent,std::default_delete<ArkAudioLogComponent>> m_pAudioLogComponent;
    struct unique_ptr<ArkNoteComponent,std::default_delete<ArkNoteComponent>> m_pNoteComponent;
    struct unique_ptr<ArkKeyCodeComponent,std::default_delete<ArkKeyCodeComponent>> m_pKeyCodeComponent;
    struct unique_ptr<ArkLocationComponent,std::default_delete<ArkLocationComponent>> m_pLocationComponent;
    struct unique_ptr<ArkLoreComponent,std::default_delete<ArkLoreComponent>> m_pLoreComponent;
    struct unique_ptr<ArkKeyCardComponent,std::default_delete<ArkKeyCardComponent>> m_pKeyCardComponent;
    struct unique_ptr<ArkEmailComponent,std::default_delete<ArkEmailComponent>> m_pEmailComponent;
    struct unique_ptr<ArkQuickSelectComponent,std::default_delete<ArkQuickSelectComponent>> m_pQuickSelectComponent;
    struct unique_ptr<ArkRosterComponent,std::default_delete<ArkRosterComponent>> m_pRosterComponent;
    struct unique_ptr<ArkUtilityComponent,std::default_delete<ArkUtilityComponent>> m_pUtilityComponent;
    struct unique_ptr<ArkPharmaComponent,std::default_delete<ArkPharmaComponent>> m_pPharmaComponent;
    struct unique_ptr<ArkPDAComponent,std::default_delete<ArkPDAComponent>> m_pPDAComponent;
    struct unique_ptr<ArkPlayerAchievementComponent,std::default_delete<ArkPlayerAchievementComponent>> m_pAchievementComponent;
    struct unique_ptr<ArkPlayerAwarenessComponent,std::default_delete<ArkPlayerAwarenessComponent>> m_pAwarenessComponent;
    struct unique_ptr<ArkPlayerEntitlementComponent,std::default_delete<ArkPlayerEntitlementComponent>> m_pEntitlementComponent;
    struct unique_ptr<ArkPlayerFatigueComponent,std::default_delete<ArkPlayerFatigueComponent>> m_pFatigueComponent;
    struct unique_ptr<ArkPlayerHealthComponent,std::default_delete<ArkPlayerHealthComponent>> m_pHealthComponent;
    struct unique_ptr<ArkPlayerRadiationComponent,std::default_delete<ArkPlayerRadiationComponent>> m_pRadiationComponent;
    struct unique_ptr<ArkPlayerLightManager,std::default_delete<ArkPlayerLightManager>> m_pLightManager;
    struct unique_ptr<ArkPlayerFXComponent,std::default_delete<ArkPlayerFXComponent>> m_pFXComponent;
    struct unique_ptr<ArkPlayerUIComponent,std::default_delete<ArkPlayerUIComponent>> m_pUIComponent;
    struct unique_ptr<ArkFabricationPlanComponent,std::default_delete<ArkFabricationPlanComponent>> m_pFabricationPlanComponent;
    struct unique_ptr<ArkPlayerStatusComponent,std::default_delete<ArkPlayerStatusComponent>> m_pStatusComponent;
    struct unique_ptr<ArkPlayerPropulsionComponent,std::default_delete<ArkPlayerPropulsionComponent>> m_pPropulsionComponent;
    struct unique_ptr<ArkPlayerSignalReceiver,std::default_delete<ArkPlayerSignalReceiver>> m_pSignalReceiver;
    struct unique_ptr<ArkAimAssistComponent,std::default_delete<ArkAimAssistComponent>> m_pAimAssistComponent;
    struct unique_ptr<ArkMarkedEnemyComponent,std::default_delete<ArkMarkedEnemyComponent>> m_pMarkedEnemyComponent;
    struct unique_ptr<ArkPlayerScopeComponent,std::default_delete<ArkPlayerScopeComponent>> m_pScopeComponent;
    struct unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>> m_pPlayerSpeaker;
    struct unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>> m_pSuitSpeaker;
    struct unique_ptr<ArkSpeaker<ArkDialogPlayer>,std::default_delete<ArkSpeaker<ArkDialogPlayer>>> m_pDiscRifleSpeaker;
    struct unique_ptr<ArkSpeaker<ArkDialogPlayerTranscribe>,std::default_delete<ArkSpeaker<ArkDialogPlayerTranscribe>>> m_pTranscribeSpeaker;
    struct unique_ptr<ArkGameMetricsComponent,std::default_delete<ArkGameMetricsComponent>> m_pGameMetricsComponent;
    struct unique_ptr<ArkFocusModeComponent,std::default_delete<ArkFocusModeComponent>> m_pFocusModeComponent;
    struct unique_ptr<ArkLiveTranscribeComponent,std::default_delete<ArkLiveTranscribeComponent>> m_pLiveTranscribeComponent;
    struct unique_ptr<ArkStationAccessComponent,std::default_delete<ArkStationAccessComponent>> m_pStationAccessComponent;
    struct unique_ptr<ArkPOIComponent,std::default_delete<ArkPOIComponent>> m_pPOIComponent;
    float m_fShadowDissolveBlend;
    float m_fShadowDissolveTarget;
    float m_fShadowDissolveTimeScale;
    bool m_bItemsRestricted;
    bool m_bMarkerTextDisplayed;
};

struct vector<ArkPlayerZoomManager::ZoomData,std::allocator<ArkPlayerZoomManager::ZoomData>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerZoomManager {
    struct vector<ArkPlayerZoomManager::ZoomData,std::allocator<ArkPlayerZoomManager::ZoomData>> m_zoomStack;
    float m_currentHFOV;
    float m_prevDesiredHFOV;
    float m_interpTime;
    bool m_bUseUITime;
    int m_nearFOVLockedCount;
    int m_handleGenerator;
};

struct optional<ClimbPosInfo> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
};

struct StagingInfo {
    struct Ang3_tpl<float> m_rotation;
    float m_yaw;
    float m_pitch;
};

struct ArkPlayerMovementFSM {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    undefined field100_0x64;
    undefined field101_0x65;
    undefined field102_0x66;
    undefined field103_0x67;
    undefined field104_0x68;
    undefined field105_0x69;
    undefined field106_0x6a;
    undefined field107_0x6b;
    undefined field108_0x6c;
    undefined field109_0x6d;
    undefined field110_0x6e;
    undefined field111_0x6f;
    undefined field112_0x70;
    undefined field113_0x71;
    undefined field114_0x72;
    undefined field115_0x73;
    undefined field116_0x74;
    undefined field117_0x75;
    undefined field118_0x76;
    undefined field119_0x77;
    undefined field120_0x78;
    undefined field121_0x79;
    undefined field122_0x7a;
    undefined field123_0x7b;
    undefined field124_0x7c;
    undefined field125_0x7d;
    undefined field126_0x7e;
    undefined field127_0x7f;
    undefined field128_0x80;
    undefined field129_0x81;
    undefined field130_0x82;
    undefined field131_0x83;
    undefined field132_0x84;
    undefined field133_0x85;
    undefined field134_0x86;
    undefined field135_0x87;
    undefined field136_0x88;
    undefined field137_0x89;
    undefined field138_0x8a;
    undefined field139_0x8b;
    undefined field140_0x8c;
    undefined field141_0x8d;
    undefined field142_0x8e;
    undefined field143_0x8f;
    undefined field144_0x90;
    undefined field145_0x91;
    undefined field146_0x92;
    undefined field147_0x93;
    undefined field148_0x94;
    undefined field149_0x95;
    undefined field150_0x96;
    undefined field151_0x97;
    undefined field152_0x98;
    undefined field153_0x99;
    undefined field154_0x9a;
    undefined field155_0x9b;
    undefined field156_0x9c;
    undefined field157_0x9d;
    undefined field158_0x9e;
    undefined field159_0x9f;
    undefined field160_0xa0;
    undefined field161_0xa1;
    undefined field162_0xa2;
    undefined field163_0xa3;
    undefined field164_0xa4;
    undefined field165_0xa5;
    undefined field166_0xa6;
    undefined field167_0xa7;
    undefined field168_0xa8;
    undefined field169_0xa9;
    undefined field170_0xaa;
    undefined field171_0xab;
    undefined field172_0xac;
    undefined field173_0xad;
    undefined field174_0xae;
    undefined field175_0xaf;
    undefined field176_0xb0;
    undefined field177_0xb1;
    undefined field178_0xb2;
    undefined field179_0xb3;
    undefined field180_0xb4;
    undefined field181_0xb5;
    undefined field182_0xb6;
    undefined field183_0xb7;
    undefined field184_0xb8;
    undefined field185_0xb9;
    undefined field186_0xba;
    undefined field187_0xbb;
    undefined field188_0xbc;
    undefined field189_0xbd;
    undefined field190_0xbe;
    undefined field191_0xbf;
    undefined field192_0xc0;
    undefined field193_0xc1;
    undefined field194_0xc2;
    undefined field195_0xc3;
    undefined field196_0xc4;
    undefined field197_0xc5;
    undefined field198_0xc6;
    undefined field199_0xc7;
    undefined field200_0xc8;
    undefined field201_0xc9;
    undefined field202_0xca;
    undefined field203_0xcb;
    undefined field204_0xcc;
    undefined field205_0xcd;
    undefined field206_0xce;
    undefined field207_0xcf;
    undefined field208_0xd0;
    undefined field209_0xd1;
    undefined field210_0xd2;
    undefined field211_0xd3;
    undefined field212_0xd4;
    undefined field213_0xd5;
    undefined field214_0xd6;
    undefined field215_0xd7;
    undefined field216_0xd8;
    undefined field217_0xd9;
    undefined field218_0xda;
    undefined field219_0xdb;
    undefined field220_0xdc;
    undefined field221_0xdd;
    undefined field222_0xde;
    undefined field223_0xdf;
    undefined field224_0xe0;
    undefined field225_0xe1;
    undefined field226_0xe2;
    undefined field227_0xe3;
    undefined field228_0xe4;
    undefined field229_0xe5;
    undefined field230_0xe6;
    undefined field231_0xe7;
    undefined field232_0xe8;
    undefined field233_0xe9;
    undefined field234_0xea;
    undefined field235_0xeb;
    undefined field236_0xec;
    undefined field237_0xed;
    undefined field238_0xee;
    undefined field239_0xef;
    undefined field240_0xf0;
    undefined field241_0xf1;
    undefined field242_0xf2;
    undefined field243_0xf3;
    undefined field244_0xf4;
    undefined field245_0xf5;
    undefined field246_0xf6;
    undefined field247_0xf7;
    undefined field248_0xf8;
    undefined field249_0xf9;
    undefined field250_0xfa;
    undefined field251_0xfb;
    undefined field252_0xfc;
    undefined field253_0xfd;
    undefined field254_0xfe;
    undefined field255_0xff;
    undefined field256_0x100;
    undefined field257_0x101;
    undefined field258_0x102;
    undefined field259_0x103;
    undefined field260_0x104;
    undefined field261_0x105;
    undefined field262_0x106;
    undefined field263_0x107;
    undefined field264_0x108;
    undefined field265_0x109;
    undefined field266_0x10a;
    undefined field267_0x10b;
    undefined field268_0x10c;
    undefined field269_0x10d;
    undefined field270_0x10e;
    undefined field271_0x10f;
    undefined field272_0x110;
    undefined field273_0x111;
    undefined field274_0x112;
    undefined field275_0x113;
    undefined field276_0x114;
    undefined field277_0x115;
    undefined field278_0x116;
    undefined field279_0x117;
    undefined field280_0x118;
    undefined field281_0x119;
    undefined field282_0x11a;
    undefined field283_0x11b;
    undefined field284_0x11c;
    undefined field285_0x11d;
    undefined field286_0x11e;
    undefined field287_0x11f;
    undefined field288_0x120;
    undefined field289_0x121;
    undefined field290_0x122;
    undefined field291_0x123;
    undefined field292_0x124;
    undefined field293_0x125;
    undefined field294_0x126;
    undefined field295_0x127;
    undefined field296_0x128;
    undefined field297_0x129;
    undefined field298_0x12a;
    undefined field299_0x12b;
    undefined field300_0x12c;
    undefined field301_0x12d;
    undefined field302_0x12e;
    undefined field303_0x12f;
    undefined field304_0x130;
    undefined field305_0x131;
    undefined field306_0x132;
    undefined field307_0x133;
    undefined field308_0x134;
    undefined field309_0x135;
    undefined field310_0x136;
    undefined field311_0x137;
    undefined field312_0x138;
    undefined field313_0x139;
    undefined field314_0x13a;
    undefined field315_0x13b;
    undefined field316_0x13c;
    undefined field317_0x13d;
    undefined field318_0x13e;
    undefined field319_0x13f;
    undefined field320_0x140;
    undefined field321_0x141;
    undefined field322_0x142;
    undefined field323_0x143;
    undefined field324_0x144;
    undefined field325_0x145;
    undefined field326_0x146;
    undefined field327_0x147;
    undefined field328_0x148;
    undefined field329_0x149;
    undefined field330_0x14a;
    undefined field331_0x14b;
    undefined field332_0x14c;
    undefined field333_0x14d;
    undefined field334_0x14e;
    undefined field335_0x14f;
    undefined field336_0x150;
    undefined field337_0x151;
    undefined field338_0x152;
    undefined field339_0x153;
    undefined field340_0x154;
    undefined field341_0x155;
    undefined field342_0x156;
    undefined field343_0x157;
    undefined field344_0x158;
    undefined field345_0x159;
    undefined field346_0x15a;
    undefined field347_0x15b;
    undefined field348_0x15c;
    undefined field349_0x15d;
    undefined field350_0x15e;
    undefined field351_0x15f;
    undefined field352_0x160;
    undefined field353_0x161;
    undefined field354_0x162;
    undefined field355_0x163;
    undefined field356_0x164;
    undefined field357_0x165;
    undefined field358_0x166;
    undefined field359_0x167;
    undefined field360_0x168;
    undefined field361_0x169;
    undefined field362_0x16a;
    undefined field363_0x16b;
    undefined field364_0x16c;
    undefined field365_0x16d;
    undefined field366_0x16e;
    undefined field367_0x16f;
    undefined field368_0x170;
    undefined field369_0x171;
    undefined field370_0x172;
    undefined field371_0x173;
    undefined field372_0x174;
    undefined field373_0x175;
    undefined field374_0x176;
    undefined field375_0x177;
    undefined field376_0x178;
    undefined field377_0x179;
    undefined field378_0x17a;
    undefined field379_0x17b;
    undefined field380_0x17c;
    undefined field381_0x17d;
    undefined field382_0x17e;
    undefined field383_0x17f;
    undefined field384_0x180;
    undefined field385_0x181;
    undefined field386_0x182;
    undefined field387_0x183;
    undefined field388_0x184;
    undefined field389_0x185;
    undefined field390_0x186;
    undefined field391_0x187;
    undefined field392_0x188;
    undefined field393_0x189;
    undefined field394_0x18a;
    undefined field395_0x18b;
    undefined field396_0x18c;
    undefined field397_0x18d;
    undefined field398_0x18e;
    undefined field399_0x18f;
    undefined field400_0x190;
    undefined field401_0x191;
    undefined field402_0x192;
    undefined field403_0x193;
    undefined field404_0x194;
    undefined field405_0x195;
    undefined field406_0x196;
    undefined field407_0x197;
    undefined field408_0x198;
    undefined field409_0x199;
    undefined field410_0x19a;
    undefined field411_0x19b;
    undefined field412_0x19c;
    undefined field413_0x19d;
    undefined field414_0x19e;
    undefined field415_0x19f;
    undefined field416_0x1a0;
    undefined field417_0x1a1;
    undefined field418_0x1a2;
    undefined field419_0x1a3;
    undefined field420_0x1a4;
    undefined field421_0x1a5;
    undefined field422_0x1a6;
    undefined field423_0x1a7;
    undefined field424_0x1a8;
    undefined field425_0x1a9;
    undefined field426_0x1aa;
    undefined field427_0x1ab;
    undefined field428_0x1ac;
    undefined field429_0x1ad;
    undefined field430_0x1ae;
    undefined field431_0x1af;
    undefined field432_0x1b0;
    undefined field433_0x1b1;
    undefined field434_0x1b2;
    undefined field435_0x1b3;
    undefined field436_0x1b4;
    undefined field437_0x1b5;
    undefined field438_0x1b6;
    undefined field439_0x1b7;
    undefined field440_0x1b8;
    undefined field441_0x1b9;
    undefined field442_0x1ba;
    undefined field443_0x1bb;
    undefined field444_0x1bc;
    undefined field445_0x1bd;
    undefined field446_0x1be;
    undefined field447_0x1bf;
    undefined field448_0x1c0;
    undefined field449_0x1c1;
    undefined field450_0x1c2;
    undefined field451_0x1c3;
    undefined field452_0x1c4;
    undefined field453_0x1c5;
    undefined field454_0x1c6;
    undefined field455_0x1c7;
    undefined field456_0x1c8;
    undefined field457_0x1c9;
    undefined field458_0x1ca;
    undefined field459_0x1cb;
    undefined field460_0x1cc;
    undefined field461_0x1cd;
    undefined field462_0x1ce;
    undefined field463_0x1cf;
    undefined field464_0x1d0;
    undefined field465_0x1d1;
    undefined field466_0x1d2;
    undefined field467_0x1d3;
    undefined field468_0x1d4;
    undefined field469_0x1d5;
    undefined field470_0x1d6;
    undefined field471_0x1d7;
    undefined field472_0x1d8;
    undefined field473_0x1d9;
    undefined field474_0x1da;
    undefined field475_0x1db;
    undefined field476_0x1dc;
    undefined field477_0x1dd;
    undefined field478_0x1de;
    undefined field479_0x1df;
    undefined field480_0x1e0;
    undefined field481_0x1e1;
    undefined field482_0x1e2;
    undefined field483_0x1e3;
    undefined field484_0x1e4;
    undefined field485_0x1e5;
    undefined field486_0x1e6;
    undefined field487_0x1e7;
    undefined field488_0x1e8;
    undefined field489_0x1e9;
    undefined field490_0x1ea;
    undefined field491_0x1eb;
    undefined field492_0x1ec;
    undefined field493_0x1ed;
    undefined field494_0x1ee;
    undefined field495_0x1ef;
    undefined field496_0x1f0;
    undefined field497_0x1f1;
    undefined field498_0x1f2;
    undefined field499_0x1f3;
    undefined field500_0x1f4;
    undefined field501_0x1f5;
    undefined field502_0x1f6;
    undefined field503_0x1f7;
    undefined field504_0x1f8;
    undefined field505_0x1f9;
    undefined field506_0x1fa;
    undefined field507_0x1fb;
    undefined field508_0x1fc;
    undefined field509_0x1fd;
    undefined field510_0x1fe;
    undefined field511_0x1ff;
    undefined field512_0x200;
    undefined field513_0x201;
    undefined field514_0x202;
    undefined field515_0x203;
    undefined field516_0x204;
    undefined field517_0x205;
    undefined field518_0x206;
    undefined field519_0x207;
    undefined field520_0x208;
    undefined field521_0x209;
    undefined field522_0x20a;
    undefined field523_0x20b;
    undefined field524_0x20c;
    undefined field525_0x20d;
    undefined field526_0x20e;
    undefined field527_0x20f;
    undefined field528_0x210;
    undefined field529_0x211;
    undefined field530_0x212;
    undefined field531_0x213;
    undefined field532_0x214;
    undefined field533_0x215;
    undefined field534_0x216;
    undefined field535_0x217;
    undefined field536_0x218;
    undefined field537_0x219;
    undefined field538_0x21a;
    undefined field539_0x21b;
    undefined field540_0x21c;
    undefined field541_0x21d;
    undefined field542_0x21e;
    undefined field543_0x21f;
    undefined field544_0x220;
    undefined field545_0x221;
    undefined field546_0x222;
    undefined field547_0x223;
    undefined field548_0x224;
    undefined field549_0x225;
    undefined field550_0x226;
    undefined field551_0x227;
    undefined field552_0x228;
    undefined field553_0x229;
    undefined field554_0x22a;
    undefined field555_0x22b;
    undefined field556_0x22c;
    undefined field557_0x22d;
    undefined field558_0x22e;
    undefined field559_0x22f;
    undefined field560_0x230;
    undefined field561_0x231;
    undefined field562_0x232;
    undefined field563_0x233;
    undefined field564_0x234;
    undefined field565_0x235;
    undefined field566_0x236;
    undefined field567_0x237;
    undefined field568_0x238;
    undefined field569_0x239;
    undefined field570_0x23a;
    undefined field571_0x23b;
    undefined field572_0x23c;
    undefined field573_0x23d;
    undefined field574_0x23e;
    undefined field575_0x23f;
    undefined field576_0x240;
    undefined field577_0x241;
    undefined field578_0x242;
    undefined field579_0x243;
    undefined field580_0x244;
    undefined field581_0x245;
    undefined field582_0x246;
    undefined field583_0x247;
    undefined field584_0x248;
    undefined field585_0x249;
    undefined field586_0x24a;
    undefined field587_0x24b;
    undefined field588_0x24c;
    undefined field589_0x24d;
    undefined field590_0x24e;
    undefined field591_0x24f;
    undefined field592_0x250;
    undefined field593_0x251;
    undefined field594_0x252;
    undefined field595_0x253;
    undefined field596_0x254;
    undefined field597_0x255;
    undefined field598_0x256;
    undefined field599_0x257;
    undefined field600_0x258;
    undefined field601_0x259;
    undefined field602_0x25a;
    undefined field603_0x25b;
    undefined field604_0x25c;
    undefined field605_0x25d;
    undefined field606_0x25e;
    undefined field607_0x25f;
    undefined field608_0x260;
    undefined field609_0x261;
    undefined field610_0x262;
    undefined field611_0x263;
    undefined field612_0x264;
    undefined field613_0x265;
    undefined field614_0x266;
    undefined field615_0x267;
    undefined field616_0x268;
    undefined field617_0x269;
    undefined field618_0x26a;
    undefined field619_0x26b;
    undefined field620_0x26c;
    undefined field621_0x26d;
    undefined field622_0x26e;
    undefined field623_0x26f;
    undefined field624_0x270;
    undefined field625_0x271;
    undefined field626_0x272;
    undefined field627_0x273;
    undefined field628_0x274;
    undefined field629_0x275;
    undefined field630_0x276;
    undefined field631_0x277;
    undefined field632_0x278;
    undefined field633_0x279;
    undefined field634_0x27a;
    undefined field635_0x27b;
    undefined field636_0x27c;
    undefined field637_0x27d;
    undefined field638_0x27e;
    undefined field639_0x27f;
    undefined field640_0x280;
    undefined field641_0x281;
    undefined field642_0x282;
    undefined field643_0x283;
    undefined field644_0x284;
    undefined field645_0x285;
    undefined field646_0x286;
    undefined field647_0x287;
    undefined field648_0x288;
    undefined field649_0x289;
    undefined field650_0x28a;
    undefined field651_0x28b;
    undefined field652_0x28c;
    undefined field653_0x28d;
    undefined field654_0x28e;
    undefined field655_0x28f;
    undefined field656_0x290;
    undefined field657_0x291;
    undefined field658_0x292;
    undefined field659_0x293;
    undefined field660_0x294;
    undefined field661_0x295;
    undefined field662_0x296;
    undefined field663_0x297;
    undefined field664_0x298;
    undefined field665_0x299;
    undefined field666_0x29a;
    undefined field667_0x29b;
    undefined field668_0x29c;
    undefined field669_0x29d;
    undefined field670_0x29e;
    undefined field671_0x29f;
    undefined field672_0x2a0;
    undefined field673_0x2a1;
    undefined field674_0x2a2;
    undefined field675_0x2a3;
    undefined field676_0x2a4;
    undefined field677_0x2a5;
    undefined field678_0x2a6;
    undefined field679_0x2a7;
    undefined field680_0x2a8;
    undefined field681_0x2a9;
    undefined field682_0x2aa;
    undefined field683_0x2ab;
    undefined field684_0x2ac;
    undefined field685_0x2ad;
    undefined field686_0x2ae;
    undefined field687_0x2af;
    undefined field688_0x2b0;
    undefined field689_0x2b1;
    undefined field690_0x2b2;
    undefined field691_0x2b3;
    undefined field692_0x2b4;
    undefined field693_0x2b5;
    undefined field694_0x2b6;
    undefined field695_0x2b7;
    undefined field696_0x2b8;
    undefined field697_0x2b9;
    undefined field698_0x2ba;
    undefined field699_0x2bb;
    undefined field700_0x2bc;
    undefined field701_0x2bd;
    undefined field702_0x2be;
    undefined field703_0x2bf;
    undefined field704_0x2c0;
    undefined field705_0x2c1;
    undefined field706_0x2c2;
    undefined field707_0x2c3;
    undefined field708_0x2c4;
    undefined field709_0x2c5;
    undefined field710_0x2c6;
    undefined field711_0x2c7;
    undefined field712_0x2c8;
    undefined field713_0x2c9;
    undefined field714_0x2ca;
    undefined field715_0x2cb;
    undefined field716_0x2cc;
    undefined field717_0x2cd;
    undefined field718_0x2ce;
    undefined field719_0x2cf;
    undefined field720_0x2d0;
    undefined field721_0x2d1;
    undefined field722_0x2d2;
    undefined field723_0x2d3;
    undefined field724_0x2d4;
    undefined field725_0x2d5;
    undefined field726_0x2d6;
    undefined field727_0x2d7;
    undefined field728_0x2d8;
    undefined field729_0x2d9;
    undefined field730_0x2da;
    undefined field731_0x2db;
    undefined field732_0x2dc;
    undefined field733_0x2dd;
    undefined field734_0x2de;
    undefined field735_0x2df;
    undefined field736_0x2e0;
    undefined field737_0x2e1;
    undefined field738_0x2e2;
    undefined field739_0x2e3;
    undefined field740_0x2e4;
    undefined field741_0x2e5;
    undefined field742_0x2e6;
    undefined field743_0x2e7;
    undefined field744_0x2e8;
    undefined field745_0x2e9;
    undefined field746_0x2ea;
    undefined field747_0x2eb;
    undefined field748_0x2ec;
    undefined field749_0x2ed;
    undefined field750_0x2ee;
    undefined field751_0x2ef;
    undefined field752_0x2f0;
    undefined field753_0x2f1;
    undefined field754_0x2f2;
    undefined field755_0x2f3;
    undefined field756_0x2f4;
    undefined field757_0x2f5;
    undefined field758_0x2f6;
    undefined field759_0x2f7;
    undefined field760_0x2f8;
    undefined field761_0x2f9;
    undefined field762_0x2fa;
    undefined field763_0x2fb;
    undefined field764_0x2fc;
    undefined field765_0x2fd;
    undefined field766_0x2fe;
    undefined field767_0x2ff;
    undefined field768_0x300;
    undefined field769_0x301;
    undefined field770_0x302;
    undefined field771_0x303;
    undefined field772_0x304;
    undefined field773_0x305;
    undefined field774_0x306;
    undefined field775_0x307;
    undefined field776_0x308;
    undefined field777_0x309;
    undefined field778_0x30a;
    undefined field779_0x30b;
    undefined field780_0x30c;
    undefined field781_0x30d;
    undefined field782_0x30e;
    undefined field783_0x30f;
    undefined field784_0x310;
    undefined field785_0x311;
    undefined field786_0x312;
    undefined field787_0x313;
    undefined field788_0x314;
    undefined field789_0x315;
    undefined field790_0x316;
    undefined field791_0x317;
    undefined field792_0x318;
    undefined field793_0x319;
    undefined field794_0x31a;
    undefined field795_0x31b;
    undefined field796_0x31c;
    undefined field797_0x31d;
    undefined field798_0x31e;
    undefined field799_0x31f;
    undefined field800_0x320;
    undefined field801_0x321;
    undefined field802_0x322;
    undefined field803_0x323;
    undefined field804_0x324;
    undefined field805_0x325;
    undefined field806_0x326;
    undefined field807_0x327;
    undefined field808_0x328;
    undefined field809_0x329;
    undefined field810_0x32a;
    undefined field811_0x32b;
    undefined field812_0x32c;
    undefined field813_0x32d;
    undefined field814_0x32e;
    undefined field815_0x32f;
    undefined field816_0x330;
    undefined field817_0x331;
    undefined field818_0x332;
    undefined field819_0x333;
    undefined field820_0x334;
    undefined field821_0x335;
    undefined field822_0x336;
    undefined field823_0x337;
    undefined field824_0x338;
    undefined field825_0x339;
    undefined field826_0x33a;
    undefined field827_0x33b;
    undefined field828_0x33c;
    undefined field829_0x33d;
    undefined field830_0x33e;
    undefined field831_0x33f;
    undefined field832_0x340;
    undefined field833_0x341;
    undefined field834_0x342;
    undefined field835_0x343;
    undefined field836_0x344;
    undefined field837_0x345;
    undefined field838_0x346;
    undefined field839_0x347;
    undefined field840_0x348;
    undefined field841_0x349;
    undefined field842_0x34a;
    undefined field843_0x34b;
    undefined field844_0x34c;
    undefined field845_0x34d;
    undefined field846_0x34e;
    undefined field847_0x34f;
    undefined field848_0x350;
    undefined field849_0x351;
    undefined field850_0x352;
    undefined field851_0x353;
    undefined field852_0x354;
    undefined field853_0x355;
    undefined field854_0x356;
    undefined field855_0x357;
    undefined field856_0x358;
    undefined field857_0x359;
    undefined field858_0x35a;
    undefined field859_0x35b;
    undefined field860_0x35c;
    undefined field861_0x35d;
    undefined field862_0x35e;
    undefined field863_0x35f;
    undefined field864_0x360;
    undefined field865_0x361;
    undefined field866_0x362;
    undefined field867_0x363;
    undefined field868_0x364;
    undefined field869_0x365;
    undefined field870_0x366;
    undefined field871_0x367;
    undefined field872_0x368;
    undefined field873_0x369;
    undefined field874_0x36a;
    undefined field875_0x36b;
    undefined field876_0x36c;
    undefined field877_0x36d;
    undefined field878_0x36e;
    undefined field879_0x36f;
    undefined field880_0x370;
    undefined field881_0x371;
    undefined field882_0x372;
    undefined field883_0x373;
    undefined field884_0x374;
    undefined field885_0x375;
    undefined field886_0x376;
    undefined field887_0x377;
    undefined field888_0x378;
    undefined field889_0x379;
    undefined field890_0x37a;
    undefined field891_0x37b;
    undefined field892_0x37c;
    undefined field893_0x37d;
    undefined field894_0x37e;
    undefined field895_0x37f;
    undefined field896_0x380;
    undefined field897_0x381;
    undefined field898_0x382;
    undefined field899_0x383;
    undefined field900_0x384;
    undefined field901_0x385;
    undefined field902_0x386;
    undefined field903_0x387;
    undefined field904_0x388;
    undefined field905_0x389;
    undefined field906_0x38a;
    undefined field907_0x38b;
    undefined field908_0x38c;
    undefined field909_0x38d;
    undefined field910_0x38e;
    undefined field911_0x38f;
    undefined field912_0x390;
    undefined field913_0x391;
    undefined field914_0x392;
    undefined field915_0x393;
    undefined field916_0x394;
    undefined field917_0x395;
    undefined field918_0x396;
    undefined field919_0x397;
    undefined field920_0x398;
    undefined field921_0x399;
    undefined field922_0x39a;
    undefined field923_0x39b;
    undefined field924_0x39c;
    undefined field925_0x39d;
    undefined field926_0x39e;
    undefined field927_0x39f;
    undefined field928_0x3a0;
    undefined field929_0x3a1;
    undefined field930_0x3a2;
    undefined field931_0x3a3;
    undefined field932_0x3a4;
    undefined field933_0x3a5;
    undefined field934_0x3a6;
    undefined field935_0x3a7;
    undefined field936_0x3a8;
    undefined field937_0x3a9;
    undefined field938_0x3aa;
    undefined field939_0x3ab;
    undefined field940_0x3ac;
    undefined field941_0x3ad;
    undefined field942_0x3ae;
    undefined field943_0x3af;
    undefined field944_0x3b0;
    undefined field945_0x3b1;
    undefined field946_0x3b2;
    undefined field947_0x3b3;
    undefined field948_0x3b4;
    undefined field949_0x3b5;
    undefined field950_0x3b6;
    undefined field951_0x3b7;
    undefined field952_0x3b8;
    undefined field953_0x3b9;
    undefined field954_0x3ba;
    undefined field955_0x3bb;
    undefined field956_0x3bc;
    undefined field957_0x3bd;
    undefined field958_0x3be;
    undefined field959_0x3bf;
    undefined field960_0x3c0;
    undefined field961_0x3c1;
    undefined field962_0x3c2;
    undefined field963_0x3c3;
    undefined field964_0x3c4;
    undefined field965_0x3c5;
    undefined field966_0x3c6;
    undefined field967_0x3c7;
    undefined field968_0x3c8;
    undefined field969_0x3c9;
    undefined field970_0x3ca;
    undefined field971_0x3cb;
    undefined field972_0x3cc;
    undefined field973_0x3cd;
    undefined field974_0x3ce;
    undefined field975_0x3cf;
    undefined field976_0x3d0;
    undefined field977_0x3d1;
    undefined field978_0x3d2;
    undefined field979_0x3d3;
    undefined field980_0x3d4;
    undefined field981_0x3d5;
    undefined field982_0x3d6;
    undefined field983_0x3d7;
    undefined field984_0x3d8;
    undefined field985_0x3d9;
    undefined field986_0x3da;
    undefined field987_0x3db;
    undefined field988_0x3dc;
    undefined field989_0x3dd;
    undefined field990_0x3de;
    undefined field991_0x3df;
    undefined field992_0x3e0;
    undefined field993_0x3e1;
    undefined field994_0x3e2;
    undefined field995_0x3e3;
    undefined field996_0x3e4;
    undefined field997_0x3e5;
    undefined field998_0x3e6;
    undefined field999_0x3e7;
    undefined field1000_0x3e8;
    undefined field1001_0x3e9;
    undefined field1002_0x3ea;
    undefined field1003_0x3eb;
    undefined field1004_0x3ec;
    undefined field1005_0x3ed;
    undefined field1006_0x3ee;
    undefined field1007_0x3ef;
    undefined field1008_0x3f0;
    undefined field1009_0x3f1;
    undefined field1010_0x3f2;
    undefined field1011_0x3f3;
    undefined field1012_0x3f4;
    undefined field1013_0x3f5;
    undefined field1014_0x3f6;
    undefined field1015_0x3f7;
    undefined field1016_0x3f8;
    undefined field1017_0x3f9;
    undefined field1018_0x3fa;
    undefined field1019_0x3fb;
    undefined field1020_0x3fc;
    undefined field1021_0x3fd;
    undefined field1022_0x3fe;
    undefined field1023_0x3ff;
    undefined field1024_0x400;
    undefined field1025_0x401;
    undefined field1026_0x402;
    undefined field1027_0x403;
    undefined field1028_0x404;
    undefined field1029_0x405;
    undefined field1030_0x406;
    undefined field1031_0x407;
    undefined field1032_0x408;
    undefined field1033_0x409;
    undefined field1034_0x40a;
    undefined field1035_0x40b;
    undefined field1036_0x40c;
    undefined field1037_0x40d;
    undefined field1038_0x40e;
    undefined field1039_0x40f;
    undefined field1040_0x410;
    undefined field1041_0x411;
    undefined field1042_0x412;
    undefined field1043_0x413;
    undefined field1044_0x414;
    undefined field1045_0x415;
    undefined field1046_0x416;
    undefined field1047_0x417;
    undefined field1048_0x418;
    undefined field1049_0x419;
    undefined field1050_0x41a;
    undefined field1051_0x41b;
    undefined field1052_0x41c;
    undefined field1053_0x41d;
    undefined field1054_0x41e;
    undefined field1055_0x41f;
    undefined field1056_0x420;
    undefined field1057_0x421;
    undefined field1058_0x422;
    undefined field1059_0x423;
    undefined field1060_0x424;
    undefined field1061_0x425;
    undefined field1062_0x426;
    undefined field1063_0x427;
    undefined field1064_0x428;
    undefined field1065_0x429;
    undefined field1066_0x42a;
    undefined field1067_0x42b;
    undefined field1068_0x42c;
    undefined field1069_0x42d;
    undefined field1070_0x42e;
    undefined field1071_0x42f;
    undefined field1072_0x430;
    undefined field1073_0x431;
    undefined field1074_0x432;
    undefined field1075_0x433;
    undefined field1076_0x434;
    undefined field1077_0x435;
    undefined field1078_0x436;
    undefined field1079_0x437;
    undefined field1080_0x438;
    undefined field1081_0x439;
    undefined field1082_0x43a;
    undefined field1083_0x43b;
    undefined field1084_0x43c;
    undefined field1085_0x43d;
    undefined field1086_0x43e;
    undefined field1087_0x43f;
    undefined field1088_0x440;
    undefined field1089_0x441;
    undefined field1090_0x442;
    undefined field1091_0x443;
    undefined field1092_0x444;
    undefined field1093_0x445;
    undefined field1094_0x446;
    undefined field1095_0x447;
    undefined field1096_0x448;
    undefined field1097_0x449;
    undefined field1098_0x44a;
    undefined field1099_0x44b;
    undefined field1100_0x44c;
    undefined field1101_0x44d;
    undefined field1102_0x44e;
    undefined field1103_0x44f;
    undefined field1104_0x450;
    undefined field1105_0x451;
    undefined field1106_0x452;
    undefined field1107_0x453;
    undefined field1108_0x454;
    undefined field1109_0x455;
    undefined field1110_0x456;
    undefined field1111_0x457;
    undefined field1112_0x458;
    undefined field1113_0x459;
    undefined field1114_0x45a;
    undefined field1115_0x45b;
    undefined field1116_0x45c;
    undefined field1117_0x45d;
    undefined field1118_0x45e;
    undefined field1119_0x45f;
    undefined field1120_0x460;
    undefined field1121_0x461;
    undefined field1122_0x462;
    undefined field1123_0x463;
    undefined field1124_0x464;
    undefined field1125_0x465;
    undefined field1126_0x466;
    undefined field1127_0x467;
    undefined field1128_0x468;
    undefined field1129_0x469;
    undefined field1130_0x46a;
    undefined field1131_0x46b;
    undefined field1132_0x46c;
    undefined field1133_0x46d;
    undefined field1134_0x46e;
    undefined field1135_0x46f;
    undefined field1136_0x470;
    undefined field1137_0x471;
    undefined field1138_0x472;
    undefined field1139_0x473;
    undefined field1140_0x474;
    undefined field1141_0x475;
    undefined field1142_0x476;
    undefined field1143_0x477;
    undefined field1144_0x478;
    undefined field1145_0x479;
    undefined field1146_0x47a;
    undefined field1147_0x47b;
    undefined field1148_0x47c;
    undefined field1149_0x47d;
    undefined field1150_0x47e;
    undefined field1151_0x47f;
    undefined field1152_0x480;
    undefined field1153_0x481;
    undefined field1154_0x482;
    undefined field1155_0x483;
    undefined field1156_0x484;
    undefined field1157_0x485;
    undefined field1158_0x486;
    undefined field1159_0x487;
    undefined field1160_0x488;
    undefined field1161_0x489;
    undefined field1162_0x48a;
    undefined field1163_0x48b;
    undefined field1164_0x48c;
    undefined field1165_0x48d;
    undefined field1166_0x48e;
    undefined field1167_0x48f;
    undefined field1168_0x490;
    undefined field1169_0x491;
    undefined field1170_0x492;
    undefined field1171_0x493;
    undefined field1172_0x494;
    undefined field1173_0x495;
    undefined field1174_0x496;
    undefined field1175_0x497;
    undefined field1176_0x498;
    undefined field1177_0x499;
    undefined field1178_0x49a;
    undefined field1179_0x49b;
    undefined field1180_0x49c;
    undefined field1181_0x49d;
    undefined field1182_0x49e;
    undefined field1183_0x49f;
    undefined field1184_0x4a0;
    undefined field1185_0x4a1;
    undefined field1186_0x4a2;
    undefined field1187_0x4a3;
    undefined field1188_0x4a4;
    undefined field1189_0x4a5;
    undefined field1190_0x4a6;
    undefined field1191_0x4a7;
    undefined field1192_0x4a8;
    undefined field1193_0x4a9;
    undefined field1194_0x4aa;
    undefined field1195_0x4ab;
    undefined field1196_0x4ac;
    undefined field1197_0x4ad;
    undefined field1198_0x4ae;
    undefined field1199_0x4af;
    undefined field1200_0x4b0;
    undefined field1201_0x4b1;
    undefined field1202_0x4b2;
    undefined field1203_0x4b3;
    undefined field1204_0x4b4;
    undefined field1205_0x4b5;
    undefined field1206_0x4b6;
    undefined field1207_0x4b7;
    undefined field1208_0x4b8;
    undefined field1209_0x4b9;
    undefined field1210_0x4ba;
    undefined field1211_0x4bb;
    undefined field1212_0x4bc;
    undefined field1213_0x4bd;
    undefined field1214_0x4be;
    undefined field1215_0x4bf;
    undefined field1216_0x4c0;
    undefined field1217_0x4c1;
    undefined field1218_0x4c2;
    undefined field1219_0x4c3;
    undefined field1220_0x4c4;
    undefined field1221_0x4c5;
    undefined field1222_0x4c6;
    undefined field1223_0x4c7;
    undefined field1224_0x4c8;
    undefined field1225_0x4c9;
    undefined field1226_0x4ca;
    undefined field1227_0x4cb;
    undefined field1228_0x4cc;
    undefined field1229_0x4cd;
    undefined field1230_0x4ce;
    undefined field1231_0x4cf;
    undefined field1232_0x4d0;
    undefined field1233_0x4d1;
    undefined field1234_0x4d2;
    undefined field1235_0x4d3;
    undefined field1236_0x4d4;
    undefined field1237_0x4d5;
    undefined field1238_0x4d6;
    undefined field1239_0x4d7;
    undefined field1240_0x4d8;
    undefined field1241_0x4d9;
    undefined field1242_0x4da;
    undefined field1243_0x4db;
    undefined field1244_0x4dc;
    undefined field1245_0x4dd;
    undefined field1246_0x4de;
    undefined field1247_0x4df;
    undefined field1248_0x4e0;
    undefined field1249_0x4e1;
    undefined field1250_0x4e2;
    undefined field1251_0x4e3;
    undefined field1252_0x4e4;
    undefined field1253_0x4e5;
    undefined field1254_0x4e6;
    undefined field1255_0x4e7;
    undefined field1256_0x4e8;
    undefined field1257_0x4e9;
    undefined field1258_0x4ea;
    undefined field1259_0x4eb;
    undefined field1260_0x4ec;
    undefined field1261_0x4ed;
    undefined field1262_0x4ee;
    undefined field1263_0x4ef;
    undefined field1264_0x4f0;
    undefined field1265_0x4f1;
    undefined field1266_0x4f2;
    undefined field1267_0x4f3;
    undefined field1268_0x4f4;
    undefined field1269_0x4f5;
    undefined field1270_0x4f6;
    undefined field1271_0x4f7;
    undefined field1272_0x4f8;
    undefined field1273_0x4f9;
    undefined field1274_0x4fa;
    undefined field1275_0x4fb;
    undefined field1276_0x4fc;
    undefined field1277_0x4fd;
    undefined field1278_0x4fe;
    undefined field1279_0x4ff;
    undefined field1280_0x500;
    undefined field1281_0x501;
    undefined field1282_0x502;
    undefined field1283_0x503;
    undefined field1284_0x504;
    undefined field1285_0x505;
    undefined field1286_0x506;
    undefined field1287_0x507;
    undefined field1288_0x508;
    undefined field1289_0x509;
    undefined field1290_0x50a;
    undefined field1291_0x50b;
    undefined field1292_0x50c;
    undefined field1293_0x50d;
    undefined field1294_0x50e;
    undefined field1295_0x50f;
    undefined field1296_0x510;
    undefined field1297_0x511;
    undefined field1298_0x512;
    undefined field1299_0x513;
    undefined field1300_0x514;
    undefined field1301_0x515;
    undefined field1302_0x516;
    undefined field1303_0x517;
    undefined field1304_0x518;
    undefined field1305_0x519;
    undefined field1306_0x51a;
    undefined field1307_0x51b;
    undefined field1308_0x51c;
    undefined field1309_0x51d;
    undefined field1310_0x51e;
    undefined field1311_0x51f;
    undefined field1312_0x520;
    undefined field1313_0x521;
    undefined field1314_0x522;
    undefined field1315_0x523;
    undefined field1316_0x524;
    undefined field1317_0x525;
    undefined field1318_0x526;
    undefined field1319_0x527;
    undefined field1320_0x528;
    undefined field1321_0x529;
    undefined field1322_0x52a;
    undefined field1323_0x52b;
    undefined field1324_0x52c;
    undefined field1325_0x52d;
    undefined field1326_0x52e;
    undefined field1327_0x52f;
    undefined field1328_0x530;
    undefined field1329_0x531;
    undefined field1330_0x532;
    undefined field1331_0x533;
    undefined field1332_0x534;
    undefined field1333_0x535;
    undefined field1334_0x536;
    undefined field1335_0x537;
    undefined field1336_0x538;
    undefined field1337_0x539;
    undefined field1338_0x53a;
    undefined field1339_0x53b;
    undefined field1340_0x53c;
    undefined field1341_0x53d;
    undefined field1342_0x53e;
    undefined field1343_0x53f;
    undefined field1344_0x540;
    undefined field1345_0x541;
    undefined field1346_0x542;
    undefined field1347_0x543;
    undefined field1348_0x544;
    undefined field1349_0x545;
    undefined field1350_0x546;
    undefined field1351_0x547;
    undefined field1352_0x548;
    undefined field1353_0x549;
    undefined field1354_0x54a;
    undefined field1355_0x54b;
    undefined field1356_0x54c;
    undefined field1357_0x54d;
    undefined field1358_0x54e;
    undefined field1359_0x54f;
    undefined field1360_0x550;
    undefined field1361_0x551;
    undefined field1362_0x552;
    undefined field1363_0x553;
    undefined field1364_0x554;
    undefined field1365_0x555;
    undefined field1366_0x556;
    undefined field1367_0x557;
    undefined field1368_0x558;
    undefined field1369_0x559;
    undefined field1370_0x55a;
    undefined field1371_0x55b;
    undefined field1372_0x55c;
    undefined field1373_0x55d;
    undefined field1374_0x55e;
    undefined field1375_0x55f;
    undefined field1376_0x560;
    undefined field1377_0x561;
    undefined field1378_0x562;
    undefined field1379_0x563;
    undefined field1380_0x564;
    undefined field1381_0x565;
    undefined field1382_0x566;
    undefined field1383_0x567;
    undefined field1384_0x568;
    undefined field1385_0x569;
    undefined field1386_0x56a;
    undefined field1387_0x56b;
    undefined field1388_0x56c;
    undefined field1389_0x56d;
    undefined field1390_0x56e;
    undefined field1391_0x56f;
    undefined field1392_0x570;
    undefined field1393_0x571;
    undefined field1394_0x572;
    undefined field1395_0x573;
    undefined field1396_0x574;
    undefined field1397_0x575;
    undefined field1398_0x576;
    undefined field1399_0x577;
    undefined field1400_0x578;
    undefined field1401_0x579;
    undefined field1402_0x57a;
    undefined field1403_0x57b;
    undefined field1404_0x57c;
    undefined field1405_0x57d;
    undefined field1406_0x57e;
    undefined field1407_0x57f;
    undefined field1408_0x580;
    undefined field1409_0x581;
    undefined field1410_0x582;
    undefined field1411_0x583;
    undefined field1412_0x584;
    undefined field1413_0x585;
    undefined field1414_0x586;
    undefined field1415_0x587;
    undefined field1416_0x588;
    undefined field1417_0x589;
    undefined field1418_0x58a;
    undefined field1419_0x58b;
    undefined field1420_0x58c;
    undefined field1421_0x58d;
    undefined field1422_0x58e;
    undefined field1423_0x58f;
    undefined field1424_0x590;
    undefined field1425_0x591;
    undefined field1426_0x592;
    undefined field1427_0x593;
    undefined field1428_0x594;
    undefined field1429_0x595;
    undefined field1430_0x596;
    undefined field1431_0x597;
    undefined field1432_0x598;
    undefined field1433_0x599;
    undefined field1434_0x59a;
    undefined field1435_0x59b;
    undefined field1436_0x59c;
    undefined field1437_0x59d;
    undefined field1438_0x59e;
    undefined field1439_0x59f;
    undefined field1440_0x5a0;
    undefined field1441_0x5a1;
    undefined field1442_0x5a2;
    undefined field1443_0x5a3;
    undefined field1444_0x5a4;
    undefined field1445_0x5a5;
    undefined field1446_0x5a6;
    undefined field1447_0x5a7;
    undefined field1448_0x5a8;
    undefined field1449_0x5a9;
    undefined field1450_0x5aa;
    undefined field1451_0x5ab;
    undefined field1452_0x5ac;
    undefined field1453_0x5ad;
    undefined field1454_0x5ae;
    undefined field1455_0x5af;
    undefined field1456_0x5b0;
    undefined field1457_0x5b1;
    undefined field1458_0x5b2;
    undefined field1459_0x5b3;
    undefined field1460_0x5b4;
    undefined field1461_0x5b5;
    undefined field1462_0x5b6;
    undefined field1463_0x5b7;
    undefined field1464_0x5b8;
    undefined field1465_0x5b9;
    undefined field1466_0x5ba;
    undefined field1467_0x5bb;
    undefined field1468_0x5bc;
    undefined field1469_0x5bd;
    undefined field1470_0x5be;
    undefined field1471_0x5bf;
    struct optional<ClimbPosInfo> m_climbPosInfo;
    struct StagingInfo m_stagingInfo;
    enum EArkFlyMode m_flyMode;
    float m_carrySpeedScale;
    float m_climbHorizontalFromEdgeProbeDistance;
    float m_climbVerticalReachDistance;
    float m_climbVerticalNormalMaxAngle;
    float m_cameraRoll;
    float m_cameraRollMaxAngle;
    float m_cameraRollIncreaseSpeed;
    float m_cameraRollRecoverySpeed;
    float m_airControl;
    bool m_bInputSneak;
    bool m_bInputJumpPressed;
    bool m_bJumpRequested;
    bool m_bMovementRestricted;
    float m_verticalSpeed;
    float m_jumpRequestedTime;
    undefined field1490_0x61c;
    undefined field1491_0x61d;
    undefined field1492_0x61e;
    undefined field1493_0x61f;
};

struct StanceInfo {
    struct Vec3_tpl<float> m_colliderSize;
    float m_colliderHeight;
    float m_viewHeight;
    float m_halfHeight;
};

struct array<StanceInfo,18> {
    struct StanceInfo _Elems[18];
};

struct MovementButtonPressInfo {
    bool bForward;
    bool bBack;
    bool bLeft;
    bool bRight;
};

struct multimap<CCryName,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float),std::less<CCryName>,std::allocator<std::pair<CCryNameconst,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float)>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct TActionHandler<ArkPlayerInput> {
    struct multimap<CCryName,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float),std::less<CCryName>,std::allocator<std::pair<CCryNameconst,bool(__cdeclArkPlayerInput::*)(unsignedint,CCryNameconst&,int,float)>>> m_actionHandlers;
};

struct vector<ArkPlayerInput::ModeAndHandle,std::allocator<ArkPlayerInput::ModeAndHandle>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerInput {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct vector<ArkPlayerInput::ModeAndHandle,std::allocator<ArkPlayerInput::ModeAndHandle>> m_modeStack;
    struct TActionHandler<ArkPlayerInput> m_actionHandler;
    struct Ang3_tpl<float> m_deltaRotation;
    struct Ang3_tpl<float> m_gamePadRotation;
    struct Ang3_tpl<float> m_adjustedGamePadRotation;
    struct Vec2_tpl<float> m_movement;
    struct Vec2_tpl<float> m_reticleMovement;
    struct MovementButtonPressInfo m_movementButtonPressInfo;
    struct ArkPlayer * m_player;
    float m_debugTimeScale;
    float m_lean;
    float m_rawLean;
    float m_lastRegisteredInputTime;
    float m_currentGamePadRotationSpeed;
    int m_mashesRemaining;
    int m_mimicGrabMashesRequired;
    enum CinematicMode m_cinematicMode;
    float m_sprintCameraRotationRateScale;
    float m_zoomCameraRotationRateScale;
    float m_sprintCancelForwardThreshold;
    float m_sprintCancelBackwardThreshold;
    float m_sprintCancelStrafeThreshold;
    bool m_bSprint;
    bool m_bUseHeld;
    bool m_bTriggeredUse;
    bool m_bTriggeredHoldUse;
    bool m_bTriggeredSpecialUse;
    bool m_bZeroGBraking;
    bool m_bSprintInhibited;
    bool m_bJumpInhibited;
    bool m_bRotationInhibited;
    bool m_bLeftLean;
    bool m_bRightLean;
    undefined field49_0xb7;
    float m_deadzone;
    float m_curvePercentTurnSpeed;
    float m_accelerationThreshold;
    float m_accelerationRate;
    float m_accelerationMaxTurnSpeed;
    enum Mode m_disabledMode;
};

struct unique_ptr<ArkPlayerOxygenComponent,std::default_delete<ArkPlayerOxygenComponent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkPlayerHelmet {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct Quat_tpl<float> m_target;
    struct unique_ptr<ArkPlayerOxygenComponent,std::default_delete<ArkPlayerOxygenComponent>> m_pOxygenComponent;
    struct Vec2_tpl<float> m_tolerance;
    struct ArkSimpleTimer m_reactTimer;
    __uint64 m_signalModifier;
    float m_catchUpSpeed;
    enum EQueuedDialog m_queuedDialog;
    int m_crackSubMatId;
    bool m_bActive;
    bool m_bPaused;
    bool m_bNonReactActivated;
    bool m_bCatchUp;
    bool m_bConsideredCaughtUp;
    undefined field21_0x49;
    undefined field22_0x4a;
    undefined field23_0x4b;
    undefined field24_0x4c;
    undefined field25_0x4d;
    undefined field26_0x4e;
    undefined field27_0x4f;
};

struct ArkExaminationMode {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    struct Quat_tpl<float> m_initialRotation;
    struct Vec3_tpl<float> m_playerCameraPosition;
    struct Quat_tpl<float> m_playerCameraRotation;
    struct Ang3_tpl<float> m_localRotation;
    struct Quat_tpl<float> m_rotation;
    struct Vec2_tpl<float> m_reticlePos;
    struct Vec3_tpl<float> m_optimalCameraPos;
    float m_cameraLerpStartTime;
    float m_activeLerpDuration;
    float m_viewingBuffer;
    float m_maxCameraRotation;
    float m_cameraSpeedMultiplier;
    float m_cameraLerpDuration;
    float m_telescopeLerpDuration;
    float m_distFromNonWorldUI;
    enum EArkExaminationType m_examinationType;
    enum EArkExaminationState m_examinationState;
    uint m_targetEntity;
    int m_inputHandle;
    int m_zoomHandle;
    enum ExamineMode m_mode;
    undefined field45_0xac;
    undefined field46_0xad;
    undefined field47_0xae;
    undefined field48_0xaf;
    struct ArkInputLegend m_inputLegendWorldUI;
    struct ArkInputLegend m_inputLegendDefault;
    struct ArkInputLegend m_inputLegendTelescope;
    struct ArkInputLegendHandler m_examinationLegendHandler;
    undefined field53_0x114;
    undefined field54_0x115;
    undefined field55_0x116;
    undefined field56_0x117;
};

struct unique_ptr<CFragmentCache,std::default_delete<CFragmentCache>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>,std::allocator<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<ArkPlayerFlashlight::DimRange,std::allocator<ArkPlayerFlashlight::DimRange>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerLightEntity {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    uint m_attachmentEntity;
    uint m_lightEntity;
    struct CryStringT<char> m_archetypeName;
    struct CryStringT<char> m_attachmentName;
};

struct ArkPlayerFlashlight {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct ArkPlayerLightEntity m_playerLight;
    struct ArkAudioTrigger m_toggleAudio;
    undefined field18_0x4c;
    undefined field19_0x4d;
    undefined field20_0x4e;
    undefined field21_0x4f;
    struct vector<ArkPlayerFlashlight::DimRange,std::allocator<ArkPlayerFlashlight::DimRange>> m_dimRanges;
    float m_dimRangeDeltaRate;
    float m_currentDimRangeDiffuse;
    float m_drainRate;
    float m_chargeRate;
    float m_maxCharge;
    float m_currentCharge;
    float m_dimStart;
    float m_minDimAmount;
    bool m_bEnabled;
    bool m_bShowingUI;
    bool m_bFlashlightOn;
    undefined field34_0x8b;
    undefined field35_0x8c;
    undefined field36_0x8d;
    undefined field37_0x8e;
    undefined field38_0x8f;
};

struct vector<ArkStatModifierPackage,std::allocator<ArkStatModifierPackage>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkStatModifierPackages {
    struct vector<ArkStatModifierPackage,std::allocator<ArkStatModifierPackage>> m_Packages;
};

struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct unordered_map<CCryName,ArkStatsComponent::ArkStat,std::hash<CCryName>,std::equal_to<CCryName>,std::allocator<std::pair<CCryNameconst,ArkStatsComponent::ArkStat>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct ArkStatsComponent {
    uint m_ownerId;
    uint m_currentId;
    struct unordered_map<CCryName,ArkStatsComponent::ArkStat,std::hash<CCryName>,std::equal_to<CCryName>,std::allocator<std::pair<CCryNameconst,ArkStatsComponent::ArkStat>>> m_stats;
    struct ArkStatModifierPackages m_packagesDesc;
    struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> m_activePackages;
};

struct function<Vec3_tpl<float>__cdecl(float)> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct function<void__cdecl(SViewParams&)> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct ArkPlayerCamera {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct array<CryStringT<char>,17> m_boneNames;
    struct function<Quat_tpl<float>__cdecl(float)> m_customUpdateFunction;
    struct function<Vec3_tpl<float>__cdecl(float)> m_customOffsetFunction;
    struct function<void__cdecl(SViewParams&)> m_customViewFunction;
    struct Quat_tpl<float> m_rotation;
    struct Vec2_tpl<float> m_recoilStep;
    float m_recoilTimeRemaining;
    float m_recoilDelayRemaining;
    float m_leanAmount;
    float m_leanAngle;
    float m_leanOffset;
    float m_eyeOffset;
    float m_transitionTime;
    float m_transitionTimeRemain;
    struct Quat_tpl<float> m_transitionStartRot;
    struct Vec3_tpl<float> m_deathPos;
    enum Mode m_mode;
    float m_bRecycleGrenadeDeathSpeed;
    struct Vec3_tpl<float> m_nonLeaningTargetPosition;
    float m_FPIKWeight;
    float m_FPIKWeightTarget;
    float m_stanceChangeInterSpeed;
    undefined field30_0x1c4;
    undefined field31_0x1c5;
    undefined field32_0x1c6;
    undefined field33_0x1c7;
};

struct unique_ptr<ArkPlayerMovementController,std::default_delete<ArkPlayerMovementController>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkPlayer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    struct ArkPlayerMovementFSM m_movementFSM;
    struct ArkPlayerComponent m_playerComponent;
    struct ArkStatsComponent m_statsComponent;
    struct ArkEquipmentModComponent m_suitChipsetComponent;
    struct ArkEquipmentModComponent m_scopeChipsetComponent;
    struct ArkPlayerInput m_input;
    struct ArkExaminationMode m_examinationMode;
    struct ArkPlayerInteraction m_interaction;
    struct ArkGroundColliderComponent m_groundColliderComponent;
    struct ArkPlayerFlashlight m_flashlight;
    struct ArkPlayerAudio m_audio;
    struct ArkPlayerCamera m_camera;
    struct ArkPlayerHelmet m_helmet;
    struct ArkPlayerWeaponComponent m_weaponComponent;
    struct vector<IPlayerEventListener*,std::allocator<IPlayerEventListener*>> m_playerEventListeners;
    struct vector<std::pair<CryStringT<char>,unsignedint>,std::allocator<std::pair<CryStringT<char>,unsignedint>>> m_attachmentFlags;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_learnedNames;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_criticalHitMetaTags;
    struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> m_animationTagsSetFromFG;
    struct array<StanceInfo,18> m_stanceInfos;
    struct CryStringT<char> m_modelName;
    struct Vec3_tpl<float> m_serializedVelocity;
    struct Vec3_tpl<float> m_cachedReticlePos;
    struct Vec3_tpl<float> m_cachedReticleDir;
    struct Vec2_tpl<float> m_reticlePos;
    undefined field113_0x17f4;
    undefined field114_0x17f5;
    undefined field115_0x17f6;
    undefined field116_0x17f7;
    struct _smart_ptr<IAction> m_pHeadBobbingAction;
    struct unique_ptr<ArkPlayerMovementController,std::default_delete<ArkPlayerMovementController>> m_pMovementController;
    struct IAnimatedCharacter * m_pAnimatedCharacter;
    struct ArkInventory * m_pInventory;
    struct unique_ptr<CFragmentCache,std::default_delete<CFragmentCache>> m_pFragmentCache;
    __uint64 m_coralSignalPackageId;
    struct ArkSimpleTimer m_coralInteractionTimer;
    float m_knockdownLoopDuration;
    float m_idleFragmentSpeedThreshold;
    enum EStance m_stance;
    undefined field127_0x183c;
    undefined field128_0x183d;
    undefined field129_0x183e;
    undefined field130_0x183f;
    struct ArkPlayerAttentionObject m_attentionObject;
    float m_fearNoiseAmplitude;
    float m_autoSaveHealthThreshold;
    float m_autoSaveOxygenThreshold;
    float m_attackTargetPosHeightPercent;
    float m_lookAtFarRange;
    bool m_bInTrackview;
    bool m_bInAir;
    bool m_bShowArmor;
    bool m_bShowHealth;
    bool m_bAllowIdleBreak;
    bool m_bJustPhysicalized;
    bool m_bShowContinuePrompt;
    bool m_bReceivedStartLevelEvent;
    bool m_bReticleViewPositionValid;
    undefined field146_0x188d;
    undefined field147_0x188e;
    undefined field148_0x188f;
    struct ArkSimpleTimer m_autoSaveBlockedBySignalTimer;
    struct ArkPlayerZoomManager m_zoomManager;
    uint m_rotationModifierHandleGenerator;
    undefined field152_0x18cc;
    undefined field153_0x18cd;
    undefined field154_0x18ce;
    undefined field155_0x18cf;
    struct vector<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>,std::allocator<std::pair<unsignedint,Functor2<Ang3_tpl<float>&,float>>>> m_rotationModifiers;
    uint m_mimicGrabSequenceEntityId;
    undefined field158_0x18ec;
    undefined field159_0x18ed;
    undefined field160_0x18ee;
    undefined field161_0x18ef;
    struct ArkMaterialAnimationManager m_materialAnimationManager;
};

struct DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CTagState {
    struct CTagDefinition * m_defs;
    struct STagState<12> m_state;
};

struct CMTRand_int32 {
    uint m_nState[625];
    int p;
};

struct SAnimationContext {
    struct SControllerDef * controllerDef;
    struct CTagState state;
    struct DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> subStates;
    struct CMTRand_int32 randGenerator;
};

struct CMannequinParams {
    struct vector<SMannParameter,std::allocator<SMannParameter>> m_paramList;
};

struct DynArray<_smart_ptr<IAction>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct IScope {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct IAction {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct SAnimationContext * m_context;
    float m_activeTime;
    float m_queueTime;
    uint m_forcedScopeMask;
    uint m_installedScopeMask;
    int m_subContext;
    int m_priority;
    enum EStatus m_eStatus;
    uint m_flags;
    struct IScope * m_rootScope;
    int m_fragmentID;
    struct STagState<12> m_fragTags;
    uint m_optionIdx;
    uint m_userToken;
    int m_refCount;
    float m_speedBias;
    float m_animWeight;
    undefined field25_0x5c;
    undefined field26_0x5d;
    undefined field27_0x5e;
    undefined field28_0x5f;
    struct CMannequinParams m_mannequinParams;
    struct DynArray<_smart_ptr<IAction>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_slaveActions;
};

struct ArkInventory {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    bool m_bSortDirty;
    bool m_bSerializeOpen;
    bool m_bPreventStorage;
    bool m_bTakesTrash;
    enum EArkGridSizes m_size;
    struct vector<ArkInventory::StorageCell,std::allocator<ArkInventory::StorageCell>> m_storedItems;
    struct ArkSimpleTimer m_lookAtTimer;
    enum InventorySort m_currentSort;
    undefined field96_0x84;
    undefined field97_0x85;
    undefined field98_0x86;
    undefined field99_0x87;
};

struct IAnimatedCharacter {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

typedef struct ArkPlayerAchievementComponent ArkPlayerAchievementComponent, *PArkPlayerAchievementComponent;

typedef struct vector<ArkPlayerAchievementComponent::TimerWindowCount,std::allocator<ArkPlayerAchievementComponent::TimerWindowCount>> vector<ArkPlayerAchievementComponent::TimerWindowCount,std::allocator<ArkPlayerAchievementComponent::TimerWindowCount>>, *Pvector<ArkPlayerAchievementComponent::TimerWindowCount,std::allocator<ArkPlayerAchievementComponent::TimerWindowCount>>;

struct vector<ArkPlayerAchievementComponent::TimerWindowCount,std::allocator<ArkPlayerAchievementComponent::TimerWindowCount>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerAchievementComponent {
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_mimickedObjects;
    struct vector<unsignedint,std::allocator<unsignedint>> m_repairedWeapons;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_consumedFoodAndDrink;
    struct ArkSimpleTimer m_recycledTimer;
    struct ArkSimpleTimer m_blastOffWindow;
    struct Vec3_tpl<float> m_blastOffPosition;
    undefined field6_0x64;
    undefined field7_0x65;
    undefined field8_0x66;
    undefined field9_0x67;
    struct vector<ArkPlayerAchievementComponent::TimerWindowCount,std::allocator<ArkPlayerAchievementComponent::TimerWindowCount>> m_timerWindows;
};

typedef struct ArkPlayerAction ArkPlayerAction, *PArkPlayerAction;

struct ArkPlayerAction {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    undefined field100_0x64;
    undefined field101_0x65;
    undefined field102_0x66;
    undefined field103_0x67;
    undefined field104_0x68;
    undefined field105_0x69;
    undefined field106_0x6a;
    undefined field107_0x6b;
    undefined field108_0x6c;
    undefined field109_0x6d;
    undefined field110_0x6e;
    undefined field111_0x6f;
    undefined field112_0x70;
    undefined field113_0x71;
    undefined field114_0x72;
    undefined field115_0x73;
    undefined field116_0x74;
    undefined field117_0x75;
    undefined field118_0x76;
    undefined field119_0x77;
    undefined field120_0x78;
    undefined field121_0x79;
    undefined field122_0x7a;
    undefined field123_0x7b;
    undefined field124_0x7c;
    undefined field125_0x7d;
    undefined field126_0x7e;
    undefined field127_0x7f;
};

typedef struct ArkPlayerAwarenessComponent ArkPlayerAwarenessComponent, *PArkPlayerAwarenessComponent;

typedef struct VectorMap<unsignedint,ArkPlayerAwarenessComponent::AwarenessState,std::less<unsignedint>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> VectorMap<unsignedint,ArkPlayerAwarenessComponent::AwarenessState,std::less<unsignedint>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>>, *PVectorMap<unsignedint,ArkPlayerAwarenessComponent::AwarenessState,std::less<unsignedint>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>>;

typedef struct vector<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> vector<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>>, *Pvector<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>>;

struct vector<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct VectorMap<unsignedint,ArkPlayerAwarenessComponent::AwarenessState,std::less<unsignedint>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> {
    struct vector<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> m_entries;
};

struct ArkPlayerAwarenessComponent {
    struct VectorMap<unsignedint,ArkPlayerAwarenessComponent::AwarenessState,std::less<unsignedint>,std::allocator<std::pair<unsignedint,ArkPlayerAwarenessComponent::AwarenessState>>> m_awarenessStates;
    struct vector<unsignedint,std::allocator<unsignedint>> m_blockedSneakAttackTargets;
    float m_fullyAwareDuration;
    float m_minTimeToBeShown;
    float m_obscuredButShownDuration;
    float m_proxyDistanceSq;
};

typedef struct ArkPlayerCameraLockKey ArkPlayerCameraLockKey, *PArkPlayerCameraLockKey;

struct ArkPlayerCameraLockKey {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    bool m_bLock;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    float m_interpolateTime;
    char m_lookAtAnimNode[128];
    char m_boneAttachmentName[128];
};

typedef struct ArkPlayerCameraLockTrack ArkPlayerCameraLockTrack, *PArkPlayerCameraLockTrack;

struct ArkPlayerCameraLockTrack {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
};

typedef struct ArkPlayerEntitlementComponent ArkPlayerEntitlementComponent, *PArkPlayerEntitlementComponent;

typedef struct vector<ArkPlayerEntitlementComponent::OverflowItem,std::allocator<ArkPlayerEntitlementComponent::OverflowItem>> vector<ArkPlayerEntitlementComponent::OverflowItem,std::allocator<ArkPlayerEntitlementComponent::OverflowItem>>, *Pvector<ArkPlayerEntitlementComponent::OverflowItem,std::allocator<ArkPlayerEntitlementComponent::OverflowItem>>;

struct vector<ArkPlayerEntitlementComponent::OverflowItem,std::allocator<ArkPlayerEntitlementComponent::OverflowItem>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerEntitlementComponent {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    uint m_bonusContainerId;
    undefined field25_0x1c;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    __uint64 m_bonusContainerLocationId;
    bool m_bEntitlementUnlocksInContainer;
    bool m_bRefreshEntitlements;
    undefined field32_0x2a;
    undefined field33_0x2b;
    undefined field34_0x2c;
    undefined field35_0x2d;
    undefined field36_0x2e;
    undefined field37_0x2f;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_populatedEntitlements;
    struct vector<unsigned__int64,std::allocator<unsigned__int64>> m_previouslyPopulatedEntitlements;
    struct vector<ArkPlayerEntitlementComponent::OverflowItem,std::allocator<ArkPlayerEntitlementComponent::OverflowItem>> m_overflowItems;
    bool m_bRestoreMargrave;
    undefined field42_0x79;
    undefined field43_0x7a;
    undefined field44_0x7b;
    undefined field45_0x7c;
    undefined field46_0x7d;
    undefined field47_0x7e;
    undefined field48_0x7f;
};

typedef struct ArkPlayerFatigueComponent ArkPlayerFatigueComponent, *PArkPlayerFatigueComponent;

typedef struct ArkChargeAmount ArkChargeAmount, *PArkChargeAmount;

struct ArkChargeAmount {
    float m_amount;
    float m_maxAmount;
};

struct ArkPlayerFatigueComponent {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    bool m_bExhausted;
    bool m_bPlayingAudio;
    bool m_bShowingUI;
    undefined field11_0xb;
    int m_bInfiniteStamina;
    struct ArkChargeAmount m_fatigue;
    float m_staminaPercentStartAudio;
    float m_staminaPercentStopAudio;
    float m_showUIPercent;
    struct ArkSimpleTimer m_drainDelay;
    struct ArkAudioRtpc m_rtpcFatigue;
    struct ArkAudioTrigger m_triggerStart;
    struct ArkAudioTrigger m_triggerStop;
};

typedef struct ArkPlayerFXComponent ArkPlayerFXComponent, *PArkPlayerFXComponent;

typedef struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>>, *Pvector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>>;

typedef struct unordered_map<unsigned__int64,ArkPlayerFXComponent::ArkPlayerEffect,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,ArkPlayerFXComponent::ArkPlayerEffect>>> unordered_map<unsigned__int64,ArkPlayerFXComponent::ArkPlayerEffect,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,ArkPlayerFXComponent::ArkPlayerEffect>>>, *Punordered_map<unsigned__int64,ArkPlayerFXComponent::ArkPlayerEffect,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,ArkPlayerFXComponent::ArkPlayerEffect>>>;

struct unordered_map<unsigned__int64,ArkPlayerFXComponent::ArkPlayerEffect,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,ArkPlayerFXComponent::ArkPlayerEffect>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ArkPlayerFXComponent {
    struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> m_loopingSFX;
    struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> m_loopingPostFX;
    struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> m_loopingVFX;
    struct vector<ArkPlayerFXComponent::FXTimerData,std::allocator<ArkPlayerFXComponent::FXTimerData>> m_cooldowns;
    struct unordered_map<unsigned__int64,ArkPlayerFXComponent::ArkPlayerEffect,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,ArkPlayerFXComponent::ArkPlayerEffect>>> m_activeVFX;
};

typedef struct ArkPlayerHealthComponent ArkPlayerHealthComponent, *PArkPlayerHealthComponent;

typedef struct ArkPlayerHealthFeedback ArkPlayerHealthFeedback, *PArkPlayerHealthFeedback;

typedef struct IParticleEffect IParticleEffect, *PIParticleEffect;

struct ArkPlayerHealthFeedback {
    float m_lowHealth;
    float m_nearDeath;
    float m_prevHealth;
    int m_vfxSlot;
    bool m_bTookDamageThisTick;
    struct IParticleEffect * m_pLowHealthParticle;
    struct IParticleEffect * m_pNearDeathParticle;
    __uint64 m_lowHealthPostEffect;
    __uint64 m_nearDeathPostEffect;
    struct ArkAudioTrigger m_triggerNearDeathStart;
    struct ArkAudioTrigger m_triggerNearDeathStop;
    struct ArkAudioTrigger m_triggerNearDeathStinger;
    struct ArkAudioRtpc m_rtpcNearDeathIntensity;
};

struct IParticleEffect {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct ArkPlayerHealthComponent {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct ArkAudioTrigger m_damageAudio;
    struct ArkAudioTrigger m_deathAudio;
    struct ArkAudioTrigger m_lastChanceAudio;
    struct ArkAudioTrigger m_regenStartAudio;
    struct ArkAudioTrigger m_regenStopAudio;
    undefined field13_0x1c;
    undefined field14_0x1d;
    undefined field15_0x1e;
    undefined field16_0x1f;
    struct CryStringT<char> m_deathCharacter;
    float m_damageSinceRegen;
    float m_elapsedSinceDamaged;
    struct ArkSimpleTimer m_lastChanceTimeout;
    struct ArkSimpleTimer m_timeRemainingBeforeDeathMenu;
    struct ArkPlayerHealthFeedback m_feedback;
    bool m_bDeathMenuOpened;
    bool m_bRegening;
    undefined field25_0x8a;
    undefined field26_0x8b;
    struct Vec3_tpl<float> m_bWeaponPosition;
    uint m_killer;
    undefined field29_0x9c;
    undefined field30_0x9d;
    undefined field31_0x9e;
    undefined field32_0x9f;
};

typedef struct ArkPlayerInCombatCondition ArkPlayerInCombatCondition, *PArkPlayerInCombatCondition;

struct ArkPlayerInCombatCondition {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

typedef struct ArkPlayerLiftEntity ArkPlayerLiftEntity, *PArkPlayerLiftEntity;

struct ArkPlayerLiftEntity {
    struct ArkSimpleTimer m_destroyGooTimer;
    float m_inwardLiftForce;
    float m_upwardLiftForce;
};

typedef struct ArkPlayerLiftEntitySpawner ArkPlayerLiftEntitySpawner, *PArkPlayerLiftEntitySpawner;

typedef struct ArkPsiPowerLiftUniqueProperties ArkPsiPowerLiftUniqueProperties, *PArkPsiPowerLiftUniqueProperties;

struct ArkPlayerLiftEntitySpawner {
    struct ArkPsiPowerLiftUniqueProperties * m_properties;
};

struct ArkPsiPowerLiftUniqueProperties {
    float m_MinHeight;
    float m_MaxRange;
    float m_MaxRangeZeroG;
    float m_Radius;
    float m_Gravity;
    float m_InwardLiftForce;
    float m_UpwardLiftForce;
    float m_LiftForceZeroG;
    float m_HoverVelocityDamping;
    float m_HoverVelocityFalloff;
    float m_HoverFalloffDistance;
    struct CryStringT<char> m_ParticleEffect;
    struct CryStringT<char> m_TargetingParticleEffect;
    struct CryStringT<char> m_TargetingParticleEffectLight;
    __uint64 m_PlayerPostEffectId;
    struct CryStringT<char> m_PlayerEnterAudioTrigger;
    struct CryStringT<char> m_PlayerExitAudioTrigger;
    __uint64 m_EnterLiftSignalPackageId;
};

typedef struct ArkPlayerLiftEntityZeroG ArkPlayerLiftEntityZeroG, *PArkPlayerLiftEntityZeroG;

struct ArkPlayerLiftEntityZeroG {
    struct ArkSimpleTimer m_destroyGooTimer;
    float m_speed;
};

typedef struct ArkPlayerLiftEntityZeroGSpawner ArkPlayerLiftEntityZeroGSpawner, *PArkPlayerLiftEntityZeroGSpawner;

struct ArkPlayerLiftEntityZeroGSpawner {
    float m_speed;
};

typedef struct ArkPlayerLight ArkPlayerLight, *PArkPlayerLight;

typedef enum EArkPlayerLightPriority {
    Weapon=0,
    PsiPower=1,
    Flashlight=2,
    Psychoscope=3,
    Count=4
} EArkPlayerLightPriority;

typedef struct IArkPlayerLightOwner IArkPlayerLightOwner, *PIArkPlayerLightOwner;

struct ArkPlayerLight {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    bool m_bWantsToBeVisible;
    bool m_bVisible;
    undefined field10_0xa;
    undefined field11_0xb;
    enum EArkPlayerLightPriority m_priority;
    struct IArkPlayerLightOwner * m_pOwner;
};

struct IArkPlayerLightOwner {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

typedef struct ArkPlayerLightManager ArkPlayerLightManager, *PArkPlayerLightManager;

typedef struct array<ArkPlayerLight*,4> array<ArkPlayerLight*,4>, *Parray<ArkPlayerLight*,4>;

struct array<ArkPlayerLight*,4> {
    struct ArkPlayerLight * _Elems[4];
};

struct ArkPlayerLightManager {
    struct array<ArkPlayerLight*,4> m_lights;
    uint m_suppressCount;
};

typedef struct ArkPlayerLightVFX ArkPlayerLightVFX, *PArkPlayerLightVFX;

typedef struct ArkLooseEffect ArkLooseEffect, *PArkLooseEffect;

typedef struct _smart_ptr<IParticleEmitter> _smart_ptr<IParticleEmitter>, *P_smart_ptr<IParticleEmitter>;

typedef struct QuatTS_tpl<float> QuatTS_tpl<float>, *PQuatTS_tpl<float>;

typedef struct IParticleEmitter IParticleEmitter, *PIParticleEmitter;

struct QuatTS_tpl<float> {
    struct Quat_tpl<float> q;
    struct Vec3_tpl<float> t;
    float s;
};

struct IParticleEmitter {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
};

struct _smart_ptr<IParticleEmitter> {
    struct IParticleEmitter * p;
};

struct ArkLooseEffect {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    struct _smart_ptr<IParticleEmitter> m_pEmitter;
    struct QuatTS_tpl<float> m_location;
    bool m_bStarted;
    undefined field67_0x69;
    undefined field68_0x6a;
    undefined field69_0x6b;
    undefined field70_0x6c;
    undefined field71_0x6d;
    undefined field72_0x6e;
    undefined field73_0x6f;
};

struct ArkPlayerLightVFX {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    struct ArkLooseEffect m_lightVFX;
};

