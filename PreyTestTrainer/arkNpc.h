typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
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
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct ArkNpc ArkNpc, *PArkNpc;

typedef struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>>, *Pvector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>>;

typedef struct vector<unsignedint,std::allocator<unsignedint>> vector<unsignedint,std::allocator<unsignedint>>, *Pvector<unsignedint,std::allocator<unsignedint>>;

typedef struct Vec3_tpl<float> Vec3_tpl<float>, *PVec3_tpl<float>;

typedef struct ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc> ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc>, *PArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc>;

typedef ulonglong __uint64;

typedef struct CEffectsController CEffectsController, *PCEffectsController;

typedef struct ArkNpcFacingDesireManager ArkNpcFacingDesireManager, *PArkNpcFacingDesireManager;

typedef struct ArkNpcLookDesireManager ArkNpcLookDesireManager, *PArkNpcLookDesireManager;

typedef struct ArkNpcMovementDesireManager ArkNpcMovementDesireManager, *PArkNpcMovementDesireManager;

typedef struct ArkNpcNoiseStateDesireManager ArkNpcNoiseStateDesireManager, *PArkNpcNoiseStateDesireManager;

typedef struct ArkNpcSpeedDesireManager ArkNpcSpeedDesireManager, *PArkNpcSpeedDesireManager;

typedef struct ArkCharacterEffectsManager ArkCharacterEffectsManager, *PArkCharacterEffectsManager;

typedef struct ArkMaterialAnimationManager ArkMaterialAnimationManager, *PArkMaterialAnimationManager;

typedef struct ArkNpcAttentiveSubject ArkNpcAttentiveSubject, *PArkNpcAttentiveSubject;

typedef struct ArkNpcAttentionObject ArkNpcAttentionObject, *PArkNpcAttentionObject;

typedef struct CArkNpcLookAroundControl CArkNpcLookAroundControl, *PCArkNpcLookAroundControl;

typedef struct ArkIntrusiveList<ArkNpcCollisionObserver> ArkIntrusiveList<ArkNpcCollisionObserver>, *PArkIntrusiveList<ArkNpcCollisionObserver>;

typedef struct ArkNpcProperties ArkNpcProperties, *PArkNpcProperties;

typedef struct variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant>, *Pvariant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant>;

typedef struct unique_ptr<ArkNpcLifecycle,std::default_delete<ArkNpcLifecycle>> unique_ptr<ArkNpcLifecycle,std::default_delete<ArkNpcLifecycle>>, *Punique_ptr<ArkNpcLifecycle,std::default_delete<ArkNpcLifecycle>>;

typedef struct unique_ptr<ArkNpcBody,std::default_delete<ArkNpcBody>> unique_ptr<ArkNpcBody,std::default_delete<ArkNpcBody>>, *Punique_ptr<ArkNpcBody,std::default_delete<ArkNpcBody>>;

typedef struct unique_ptr<ArkNpcDamageFsm,std::default_delete<ArkNpcDamageFsm>> unique_ptr<ArkNpcDamageFsm,std::default_delete<ArkNpcDamageFsm>>, *Punique_ptr<ArkNpcDamageFsm,std::default_delete<ArkNpcDamageFsm>>;

typedef struct ArkNpcLookDesire ArkNpcLookDesire, *PArkNpcLookDesire;

typedef struct ArkNpcNoiseStateDesire ArkNpcNoiseStateDesire, *PArkNpcNoiseStateDesire;

typedef struct ArkNpcFacingDesire ArkNpcFacingDesire, *PArkNpcFacingDesire;

typedef struct ArkNpcMovementDesire ArkNpcMovementDesire, *PArkNpcMovementDesire;

typedef enum ECryAiSystemActiveState {
    unknown=-1,
    inactive=0,
    active=1
} ECryAiSystemActiveState;

typedef struct ArkAiKnowledge ArkAiKnowledge, *PArkAiKnowledge;

typedef struct CryStringT<char> CryStringT<char>, *PCryStringT<char>;

typedef struct shared_ptr<ArkAiTree> shared_ptr<ArkAiTree>, *Pshared_ptr<ArkAiTree>;

typedef struct unique_ptr<ArkAiTreeInstance,std::default_delete<ArkAiTreeInstance>> unique_ptr<ArkAiTreeInstance,std::default_delete<ArkAiTreeInstance>>, *Punique_ptr<ArkAiTreeInstance,std::default_delete<ArkAiTreeInstance>>;

typedef struct ArkUnanimous ArkUnanimous, *PArkUnanimous;

typedef struct ArkAudioRtpc ArkAudioRtpc, *PArkAudioRtpc;

typedef struct ArkSimpleTimer ArkSimpleTimer, *PArkSimpleTimer;

typedef struct ArkDelegate<void__cdecl(void)> ArkDelegate<void__cdecl(void)>, *PArkDelegate<void__cdecl(void)>;

typedef struct ArkDelegate<void__cdecl(unsignedint,unsignedint,bool)> ArkDelegate<void__cdecl(unsignedint,unsignedint,bool)>, *PArkDelegate<void__cdecl(unsignedint,unsignedint,bool)>;

typedef struct CTimeValue CTimeValue, *PCTimeValue;

typedef enum EArkCombatRole {
    none=0,
    melee=1,
    ranged=2,
    count_=3
} EArkCombatRole;

typedef struct HitInfo HitInfo, *PHitInfo;

typedef struct _smart_ptr<IAnimSequence> _smart_ptr<IAnimSequence>, *P_smart_ptr<IAnimSequence>;

typedef struct ArkEntityAttachmentEffect ArkEntityAttachmentEffect, *PArkEntityAttachmentEffect;

typedef struct unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>,std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>>> unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>,std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>>>, *Punique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>,std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>>>;

typedef struct ArkAirJetManager ArkAirJetManager, *PArkAirJetManager;

typedef struct ArkRobotLight ArkRobotLight, *PArkRobotLight;

typedef struct ArkFireAndForgetEffect ArkFireAndForgetEffect, *PArkFireAndForgetEffect;

typedef enum EReactionThrowAtType {
    rail=0,
    glass=1,
    ledge=2,
    breakable=3
} EReactionThrowAtType;

typedef struct ArkSpatialManagerEntryImpl_Npc ArkSpatialManagerEntryImpl_Npc, *PArkSpatialManagerEntryImpl_Npc;

typedef struct ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>, *PArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>;

typedef struct IEntity IEntity, *PIEntity;

typedef struct vector<EntityEffects::SEffectInfo,std::allocator<EntityEffects::SEffectInfo>> vector<EntityEffects::SEffectInfo,std::allocator<EntityEffects::SEffectInfo>>, *Pvector<EntityEffects::SEffectInfo,std::allocator<EntityEffects::SEffectInfo>>;

typedef enum EArkNpcSpeedType {
    normal=0,
    fast=1,
    fastest=2
} EArkNpcSpeedType;

typedef struct LookPoseParam LookPoseParam, *PLookPoseParam;

typedef struct MovementRequestID MovementRequestID, *PMovementRequestID;

typedef struct ArkAudioTrigger ArkAudioTrigger, *PArkAudioTrigger;

typedef struct optional<enumEArkNpcNoiseState> optional<enumEArkNpcNoiseState>, *Poptional<enumEArkNpcNoiseState>;

typedef struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> vector<CryStringT<char>,std::allocator<CryStringT<char>>>, *Pvector<CryStringT<char>,std::allocator<CryStringT<char>>>;

typedef struct vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>> vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>>, *Pvector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>>;

typedef struct ArkMaterialAnimation ArkMaterialAnimation, *PArkMaterialAnimation;

typedef struct ActiveAnimationData ActiveAnimationData, *PActiveAnimationData;

typedef struct unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>> unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>>, *Punordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>>;

typedef struct vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>> vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>>, *Pvector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>>;

typedef enum EArkNpcVisionDirection {
    cameraBone=0,
    lookJoint=1,
    mimic=2,
    cameraBoneForward=3
} EArkNpcVisionDirection;

typedef struct _smart_ptr<IAction> _smart_ptr<IAction>, *P_smart_ptr<IAction>;

typedef struct ArkIntrusiveListElement<ArkNpcCollisionObserver> ArkIntrusiveListElement<ArkNpcCollisionObserver>, *PArkIntrusiveListElement<ArkNpcCollisionObserver>;

typedef struct Ability Ability, *PAbility;

typedef struct AttentionFacing AttentionFacing, *PAttentionFacing;

typedef struct Audio Audio, *PAudio;

typedef struct CallForHelp CallForHelp, *PCallForHelp;

typedef struct Character Character, *PCharacter;

typedef struct CombatRoleInfo CombatRoleInfo, *PCombatRoleInfo;

typedef struct ControlTurrets ControlTurrets, *PControlTurrets;

typedef struct CorruptNpc CorruptNpc, *PCorruptNpc;

typedef struct Corruption Corruption, *PCorruption;

typedef struct DamageStates DamageStates, *PDamageStates;

typedef struct Dodge Dodge, *PDodge;

typedef struct Dormant Dormant, *PDormant;

typedef struct Energized Energized, *PEnergized;

typedef struct EntityFactionModifier EntityFactionModifier, *PEntityFactionModifier;

typedef struct Fatality Fatality, *PFatality;

typedef struct Fear Fear, *PFear;

typedef struct Glooed Glooed, *PGlooed;

typedef struct Hack Hack, *PHack;

typedef struct HitReaction HitReaction, *PHitReaction;

typedef struct HumanArmed HumanArmed, *PHumanArmed;

typedef struct Hypnotize Hypnotize, *PHypnotize;

typedef struct Laser Laser, *PLaser;

typedef struct Mannequin Mannequin, *PMannequin;

typedef struct MimicJumpAttack MimicJumpAttack, *PMimicJumpAttack;

typedef struct MimicReorient MimicReorient, *PMimicReorient;

typedef struct Mimicry Mimicry, *PMimicry;

typedef struct MindControl MindControl, *PMindControl;

typedef struct Nullwave Nullwave, *PNullwave;

typedef struct OnDeath OnDeath, *POnDeath;

typedef struct OnFire OnFire, *POnFire;

typedef struct OperatorEffects OperatorEffects, *POperatorEffects;

typedef struct PlayerControlled PlayerControlled, *PPlayerControlled;

typedef struct PoltergeistEffects PoltergeistEffects, *PPoltergeistEffects;

typedef struct RaiseFromCorpse RaiseFromCorpse, *PRaiseFromCorpse;

typedef struct RaisePhantom RaisePhantom, *PRaisePhantom;

typedef struct Shift Shift, *PShift;

typedef struct Sound Sound, *PSound;

typedef struct Stunned Stunned, *PStunned;

typedef struct Surprise Surprise, *PSurprise;

typedef struct TurretWeapon TurretWeapon, *PTurretWeapon;

typedef struct UnreachableTargeting UnreachableTargeting, *PUnreachableTargeting;

typedef enum EArkAttentionLevel {
    unknown=0,
    noticed=1,
    curious=2,
    interested=3,
    known=4,
    count_=5
} EArkAttentionLevel;

typedef struct aligned_storage<32,8> aligned_storage<32,8>, *Paligned_storage<32,8>;

typedef struct ArkNpcDesireTarget ArkNpcDesireTarget, *PArkNpcDesireTarget;

typedef enum ELookStyle {
    LOOKSTYLE_DEFAULT=0,
    LOOKSTYLE_HARD=1,
    LOOKSTYLE_HARD_NOLOWER=2,
    LOOKSTYLE_SOFT=3,
    LOOKSTYLE_SOFT_NOLOWER=4,
    LOOKSTYLE_COUNT=5
} ELookStyle;

typedef enum EBodyOrientationMode {
    FullyTowardsMovementDirection=0,
    FullyTowardsAimOrLook=1,
    HalfwayTowardsAimOrLook=2
} EBodyOrientationMode;

typedef struct ArkDelegate<void__cdecl(enumEArkNpcLookDesireCallbackEvent)> ArkDelegate<void__cdecl(enumEArkNpcLookDesireCallbackEvent)>, *PArkDelegate<void__cdecl(enumEArkNpcLookDesireCallbackEvent)>;

typedef enum EArkNpcNoiseState {
    idle=0,
    notice=1,
    stare=2,
    search=3,
    combat=4,
    count_=5
} EArkNpcNoiseState;

typedef enum TurnState {
    None=0,
    TurnLeft=1,
    TurnRight=2
} TurnState;

typedef struct ArkDelegate<void__cdecl(enumEArkNpcFacingDesireCallbackEvent)> ArkDelegate<void__cdecl(enumEArkNpcFacingDesireCallbackEvent)>, *PArkDelegate<void__cdecl(enumEArkNpcFacingDesireCallbackEvent)>;

typedef enum ShiftAnimation {
    None=0,
    ShiftInAndOut=1,
    ShiftInOnly=2,
    ShiftOutOnly=3,
    Attack=4
} ShiftAnimation;

typedef enum ShiftType {
    Normal=0,
    Lurk=1
} ShiftType;

typedef enum JumpStyle {
    None=0,
    ForwardJump=1,
    WallJump=2,
    AnyJump=3
} JumpStyle;

typedef enum JumpGoal {
    FromStart=0,
    FromStartImmediate=1,
    ToEnd=2,
    ToEndImmediate=3
} JumpGoal;

typedef enum HoverStyle {
    MaintainFloorHeight=0,
    MaintainCurrentHeight=1,
    IgnoreHeight=2
} HoverStyle;

typedef enum EArkObstacleAvoidanceUrgency {
    Low=0,
    High=1
} EArkObstacleAvoidanceUrgency;

typedef enum FailureReason {
    NoReason=0,
    CouldNotFindValidStart=1,
    CouldNotFindValidDestination=2,
    CouldNotFindPathToRequestedDestination=3,
    CouldNotMoveAlongDesignerDesignedPath=4,
    FailedToProduceSuccessfulPlanAfterMaximumNumberOfAttempts=5,
    CouldNotFindPathAroundObstacles=6,
    FailedShift=7,
    PathingModeForced=8,
    FacingRestricted=9,
    StuckOnObstacle=10,
    StuckOnNpc=11,
    StuckOnGloo=12
} FailureReason;

typedef struct ArkDelegate<void__cdecl(enumEArkNpcMovementDesireCallbackEvent)> ArkDelegate<void__cdecl(enumEArkNpcMovementDesireCallbackEvent)>, *PArkDelegate<void__cdecl(enumEArkNpcMovementDesireCallbackEvent)>;

typedef struct IAnimSequence IAnimSequence, *PIAnimSequence;

typedef struct vector<ArkAirJet,std::allocator<ArkAirJet>> vector<ArkAirJet,std::allocator<ArkAirJet>>, *Pvector<ArkAirJet,std::allocator<ArkAirJet>>;

typedef struct ArkInterval<float> ArkInterval<float>, *PArkInterval<float>;

typedef enum LightMode {
    friendly=0,
    hostile=1,
    hacked=2
} LightMode;

typedef struct ArkDialogPlayerRobotLightExtension ArkDialogPlayerRobotLightExtension, *PArkDialogPlayerRobotLightExtension;

typedef struct ArkSpatiallySortedKey ArkSpatiallySortedKey, *PArkSpatiallySortedKey;

typedef struct vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>> vector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>>, *Pvector<ArkMaterialAnimationSubMaterialData,std::allocator<ArkMaterialAnimationSubMaterialData>>;

typedef struct vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>> vector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>>, *Pvector<ArkMaterialAnimationKeyframe,std::allocator<ArkMaterialAnimationKeyframe>>;

typedef struct IAction IAction, *PIAction;

typedef struct _smart_ptr<IParticleEffect> _smart_ptr<IParticleEffect>, *P_smart_ptr<IParticleEffect>;

typedef struct IEntityArchetype IEntityArchetype, *PIEntityArchetype;

typedef struct NoiseStates NoiseStates, *PNoiseStates;

typedef struct variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>> variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>>, *Pvariant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>>;

typedef struct ArkRandomizedTimer ArkRandomizedTimer, *PArkRandomizedTimer;

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

typedef struct IParticleEffect IParticleEffect, *PIParticleEffect;

typedef struct aligned_storage<32,4> aligned_storage<32,4>, *Paligned_storage<32,4>;

typedef struct SControllerDef SControllerDef, *PSControllerDef;

typedef struct CTagState CTagState, *PCTagState;

typedef struct DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct CMTRand_int32 CMTRand_int32, *PCMTRand_int32;

typedef struct vector<SMannParameter,std::allocator<SMannParameter>> vector<SMannParameter,std::allocator<SMannParameter>>, *Pvector<SMannParameter,std::allocator<SMannParameter>>;

typedef struct SCRCRef<1,SCRCRefHash_CRC32Lowercase> SCRCRef<1,SCRCRefHash_CRC32Lowercase>, *PSCRCRef<1,SCRCRefHash_CRC32Lowercase>;

typedef struct CTagDefinition CTagDefinition, *PCTagDefinition;

typedef struct DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SFragmentDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SScopeDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SScopeContextDef,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<SSubContext,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::STag,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::STagGroup,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct STagDefData STagDefData, *PSTagDefData;

typedef struct DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CTagDefinition::SPriorityCount,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<STagMask,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

struct Fatality {
    float m_vulnerabilityHealthThreshold;
};

struct STagState<12> {
    uchar state[12];
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

struct ArkDelegate<void__cdecl(void)> {
    void * m_pObject;
    void * m_pCaller;
};

struct Dormant {
    float m_hearingGainModifier;
    __uint64 m_signalModifierId;
};

struct Vec3_tpl<float> {
    float x;
    float y;
    float z;
};

struct ArkInterval<float> {
    float minimum;
    float maximum;
};

struct vector<ArkAirJet,std::allocator<ArkAirJet>> {
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

struct ArkAirJetManager {
    struct vector<ArkAirJet,std::allocator<ArkAirJet>> m_airJets;
    struct Vec3_tpl<float> m_prevForward;
    struct ArkInterval<float> m_airJetActiveToggleTime;
    float m_airJetOffTime;
};

struct CorruptNpc {
    bool m_bReleaseCorruptionOnDeath;
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

struct CryStringT<char> {
    char * m_str;
};

struct ArkAudioTrigger {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct _smart_ptr<IParticleEffect> {
    struct IParticleEffect * p;
};

struct Mimicry {
    int m_morphInSlot;
    int m_morphOutSlot;
    float m_defaultMass;
    float m_impulseMultiplier;
    float m_impulsePointHorizontalRatio;
    float m_impulsePointVerticalRatio;
    float m_startCharacterMorphOutTime;
    float m_startGeometryMorphInTime;
    float m_stopCharacterMorphInTime;
    float m_stopGeometryMorphOutTime;
    struct CryStringT<char> m_MorphOutBamfBoneName;
    __uint64 m_signalModifierId;
    struct _smart_ptr<IParticleEffect> m_pMorphInParticlefEffect;
    struct _smart_ptr<IParticleEffect> m_pMorphOutBamParticlefEffect;
    struct _smart_ptr<IParticleEffect> m_pMorphOutParticlefEffect;
    struct ArkAudioTrigger m_startTickingAudioTrigger;
    struct ArkAudioTrigger m_stopTickingAudioTrigger;
    struct ArkAudioTrigger m_unmorphAudioTrigger;
};

struct shared_ptr<ArkAiTree> {
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

struct TurretWeapon {
    struct IEntityArchetype * m_pLootAmmoLaserArchetype;
    struct IEntityArchetype * m_pLootAmmoStunArchetype;
};

struct ArkIntrusiveListElement<ArkNpcCollisionObserver> {
    struct ArkIntrusiveList<ArkNpcCollisionObserver> * m_pList;
    struct ArkIntrusiveListElement<ArkNpcCollisionObserver> * m_pPrev;
    struct ArkIntrusiveListElement<ArkNpcCollisionObserver> * m_pNext;
};

struct ArkIntrusiveList<ArkNpcCollisionObserver> {
    __uint64 m_size;
    struct ArkIntrusiveListElement<ArkNpcCollisionObserver> m_head;
};

struct ArkDelegate<void__cdecl(enumEArkNpcLookDesireCallbackEvent)> {
    void * m_pObject;
    void * m_pCaller;
};

struct OnDeath {
    float m_aoeDeathRadius;
    float m_aoeDeathSignalScale;
    __uint64 m_aoeDeathSignal;
    struct _smart_ptr<IParticleEffect> m_pFearAoeParticleEffect;
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

struct ArkMaterialAnimationManager {
    struct IEntity * m_pEntity;
    struct vector<ArkMaterialAnimationManager::SAttachmentMaterials,std::allocator<ArkMaterialAnimationManager::SAttachmentMaterials>> m_attachmentMaterials;
    struct ArkMaterialAnimation * m_pOneOffMaterialAnimation;
    struct ActiveAnimationData m_oneOffAnimationData;
    struct unordered_map<enumArkMaterialAnimationType,ArkMaterialAnimationconst*,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enumArkMaterialAnimationType>,std::allocator<std::pair<enumArkMaterialAnimationTypeconst,ArkMaterialAnimationconst*>>> m_animationsByType;
    struct ActiveAnimationData m_activeAnimationsByType[18];
    struct vector<MaterialParameterRamp,std::allocator<MaterialParameterRamp>> m_materialParameterRamps;
};

struct CallForHelp {
    __uint64 m_onAttackNoiseLoudness;
    __uint64 m_onAttackNoiseType;
    __uint64 m_onNewCombatAttentionNoiseLoudness;
    __uint64 m_onNewCombatAttentionNoiseType;
};

struct ArkNpcSpeedDesireManager {
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
    float m_deltaAngleRateNormal;
    float m_deltaAngleRateFast;
    float m_deltaAngleRateFastest;
    bool m_bSmoothedZTurning;
    undefined field52_0x3d;
    undefined field53_0x3e;
    undefined field54_0x3f;
};

struct DamageStates {
    bool m_bHasDamageStates;
    float m_healthThresholdDamage;
    float m_healthThresholdDisabled;
    float m_destroyedExplosionRadius;
    float m_destroyedExplosionImpulse;
    float m_destroyedExplosionDelay;
    float m_destroyedHeightOffset;
    float m_disabledRepeatDialogCD;
    float m_disabledFlickerDuration;
    char * m_pUndamagedAttachmentName;
    char * m_pDamagedAttachmentName;
    char * m_pDisabledAttachmentName;
    char * m_pChassisModelName;
    char * m_pChassisUndamagedAttachmentName;
    char * m_pChassisDestroyedAttachmentName;
    struct ArkAudioTrigger m_becomeUndamagedAudioTrigger;
    struct ArkAudioTrigger m_becomeDamagedAudioTrigger;
    struct ArkAudioTrigger m_becomeDisabledAudioTrigger;
    __uint64 m_destroyedExplosionPackageId;
    __uint64 m_destroyedExplosionCameraShakeId;
};

struct OperatorEffects {
    float m_airJetToggleOffTime;
    float m_maxAirJetToggleOnTime;
    float m_minAirJetToggleOnTime;
    __uint64 m_operatorArmRetractedGameEffectId;
    struct _smart_ptr<IParticleEffect> m_pAirJetParticleEffect;
};

struct PlayerControlled {
    __uint64 m_playerControlledGameEffectId;
};

struct Character {
    __uint64 m_characterId;
};

struct Ability {
    __uint64 m_abilityContextProfileId;
};

struct Mannequin {
    char * m_pLifetimeTag;
};

struct MimicReorient {
    bool m_bSupportsReorientation;
    float m_mimicGlitchRandTimeMax;
    float m_mimicGlitchRandTimeMin;
};

struct Nullwave {
    __uint64 m_nullwavedSignalModifierId;
};

struct Hack {
    bool m_bStartHacked;
    __uint64 m_hackedGameEffectId;
};

struct UnreachableTargeting {
    float m_defaultCombatReachabilityCheckUp;
    float m_defaultCombatReachabilityCheckDown;
    float m_defaultCombatReachabilityCheckHorizontal;
    float m_startingTraceRadius;
    float m_startingMinSearchRadius;
    float m_chanceToSearchInReverseOrder;
    float m_horizontalOffsetStanding;
    float m_standardCombatHeight;
};

struct Stunned {
    __uint64 m_stunnedGameEffectId;
};

struct Dodge {
    bool m_bEnabled;
    float m_chance;
    float m_cooldown;
    __uint64 m_damagePackageId;
};

struct Surprise {
    __uint64 m_noiseLoudnessId;
    __uint64 m_noiseTypeId;
};

struct NoiseStates {
    struct ArkAudioTrigger m_combatStateAudioTrigger;
    struct ArkAudioTrigger m_idleStateAudioTrigger;
    struct ArkAudioTrigger m_noticeStateAudioTrigger;
    struct ArkAudioTrigger m_searchStateAudioTrigger;
    struct ArkAudioTrigger m_stareStateAudioTrigger;
};

struct Sound {
    struct NoiseStates m_noiseStates;
    struct ArkAudioTrigger m_deathAudioTrigger;
    struct ArkAudioTrigger m_startAmbientLivingAudioTrigger;
    struct ArkAudioTrigger m_stopAmbientLivingAudioTrigger;
};

struct PoltergeistEffects {
    __uint64 m_invisibilityGameEffectId;
};

struct MindControl {
    __uint64 m_mindControlGameEffectId;
};

struct Hypnotize {
    float m_timeBetweenHypnotize;
};

struct AttentionFacing {
    bool m_bUsesAttentionFacing;
    bool m_bUsesAttentionLook;
};

struct Shift {
    __uint64 m_shiftingSignalModifierId;
};

struct Audio {
    char * m_pDistanceToPlayerParam;
};

struct Energized {
    __uint64 m_energizedGameEffectId;
};

struct HumanArmed {
    bool m_bIsArmed;
    int m_magSize;
    char * m_pGunAttachmentName;
    struct IEntityArchetype * m_pLootWeaponEntityArchetype;
};

struct RaiseFromCorpse {
    __uint64 m_raiseFromCorpseGameEffectId;
};

struct MimicJumpAttack {
    __uint64 m_mimicJumpAttackPackageId;
    struct _smart_ptr<IParticleEffect> m_pMimicAttackEffect;
};

struct HitReaction {
    __uint64 m_hitReactionMaterialAnimationGameEffectId;
};

struct Laser {
    int m_laserHitTypeId;
    float m_beamEndJumpDistanceSq;
    float m_materialEffectCooldown;
    float m_maxLaserLength;
    float m_maxThickness;
    float m_minThickness;
    __uint64 m_laserPackageId;
    int m_customSurfaceTypeId;
    char * m_pBeamEndEffectName;
    char * m_pLaserGeometryName;
    char * m_pLaserMaterialEffectName;
    char * m_pReflectionGeometryName;
    struct IEntityArchetype * m_pLootAmmoLaserArchetype;
    struct IEntityArchetype * m_pLootAmmoStunArchetype;
};

struct EntityFactionModifier {
    __uint64 m_hositleToFactionId;
};

struct CombatRoleInfo {
    bool m_bCanGetStaleInMeleeRole;
    bool m_bUsesCombatRoles;
    float m_meleeRoleCost;
    float m_meleeRolePreference;
    float m_meleeRoleScoreBias;
    float m_minDistanceToAllowRangeRoleSwitchSq;
};

struct Glooed {
    __uint64 m_glooGameEffectId;
    __uint64 m_onGlooedAbilityContextId;
};

struct Corruption {
    bool m_bDeletedOnLevelLoadAndUncorrupted;
    bool m_bShouldGoUnconsciousOnUncorruption;
    bool m_bStartCorrupted;
    char * m_pMovementGlitchAttachmentName1;
    char * m_pMovementGlitchAttachmentName2;
    struct ArkAudioTrigger m_becomeCorruptedAudioTrigger;
    __uint64 m_corruptedGameEffectId;
    __uint64 m_uncorruptedMetaTagId;
    struct _smart_ptr<IParticleEffect> m_pCorruptedMovementGlitchParticleEffect;
};

struct OnFire {
    __uint64 m_onFireGameEffectId;
};

struct RaisePhantom {
    bool m_bCanBeRaisedPhantom;
    int m_maxAllowedRaisedPhantoms;
};

struct Fear {
    __uint64 m_fearedGameEffectId;
    __uint64 m_fearedSignalModifierId;
};

struct ControlTurrets {
    __uint64 m_controlTurretsGameEffectId;
};

struct ArkNpcProperties {
    struct Ability m_ability;
    struct AttentionFacing m_attentionFacing;
    struct Audio m_audio;
    struct CallForHelp m_callForHelp;
    struct Character m_character;
    struct CombatRoleInfo m_combatRoleInfo;
    struct ControlTurrets m_controlTurrets;
    struct CorruptNpc m_corruptNpc;
    struct Corruption m_corruption;
    struct DamageStates m_damageStates;
    struct Dodge m_dodge;
    struct Dormant m_dormant;
    struct Energized m_energized;
    struct EntityFactionModifier m_entityFactionModifier;
    struct Fatality m_fatality;
    struct Fear m_fear;
    struct Glooed m_glooed;
    struct Hack m_hack;
    struct HitReaction m_hitReaction;
    struct HumanArmed m_humanArmed;
    struct Hypnotize m_hypnotize;
    struct Laser m_laser;
    struct Mannequin m_mannequin;
    struct MimicJumpAttack m_mimicJumpAttack;
    struct MimicReorient m_mimicReorient;
    struct Mimicry m_mimicry;
    struct MindControl m_mindControl;
    struct Nullwave m_nullwave;
    struct OnDeath m_onDeath;
    struct OnFire m_onFire;
    struct OperatorEffects m_operatorEffects;
    struct PlayerControlled m_playerControlled;
    struct PoltergeistEffects m_poltergeistEffects;
    struct RaiseFromCorpse m_raiseFromCorpse;
    struct RaisePhantom m_raisePhantom;
    struct Shift m_shift;
    struct Sound m_sound;
    struct Stunned m_stunned;
    struct Surprise m_surprise;
    struct TurretWeapon m_turretWeapon;
    struct UnreachableTargeting m_unreachableTargeting;
    bool m_bCanFall;
    bool m_bCanRagdoll;
    bool m_bSupportsLookAt;
    int m_playerPowerTierTriggerThreshold;
    int m_npcManagerCombatPoints;
    float m_combatIntensityContribution;
    float m_combatIntensityRange;
    float m_fallDamagePerMeter;
    float m_fallDistanceForDamage;
    float m_fallDistanceForDialog;
    float m_fallDistanceForFallAnim;
    float m_fallDistanceForGlooBreak;
    float m_fallDistanceForLandAnim;
    float m_forceResistScrunchDistance;
    char * m_pAiTreeFilePath;
    char * m_pFaction;
    __uint64 m_fallDamagePackage;
    __uint64 m_ragdollSignalModifierId;
    enum EArkAttentionLevel m_abortTrackviewOnHostileAttention;
    enum EArkNpcVisionDirection m_visionDirection;
};

struct _smart_ptr<IAction> {
    struct IAction * p;
};

struct CArkNpcLookAroundControl {
    bool m_bSuspended;
    bool m_bStateChange;
    bool m_bEnabled[2];
    float m_idleTime;
    struct _smart_ptr<IAction> m_pLookAroundAction;
};

struct optional<enumEArkNpcNoiseState> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkNpcNoiseStateDesireManager {
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
    struct ArkAudioTrigger m_audioTriggers[5];
    struct optional<enumEArkNpcNoiseState> m_currentNoiseState;
    undefined field50_0x4c;
    undefined field51_0x4d;
    undefined field52_0x4e;
    undefined field53_0x4f;
};

struct ArkUnanimous {
    __uint64 m_trueCount;
    __uint64 m_falseCount;
};

struct LookPoseParam {
    float m_torso;
    float m_head;
    float m_eyes;
    float m_aim;
};

struct ArkNpcLookDesireManager {
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
    enum EArkNpcSpeedType m_speed;
    struct LookPoseParam m_defaultBlendInTime;
    struct LookPoseParam m_defaultSmoothTime;
    struct LookPoseParam m_defaultBlendOutTime;
    struct LookPoseParam m_defaultMaxYaw;
    struct LookPoseParam m_defaultMaxPitch;
    float m_speedMultiplierFastHead;
    float m_speedMultiplierFastestHead;
    float m_speedMultiplierFastTorso;
    float m_speedMultiplierFastestTorso;
    float m_speedScale;
};

struct unique_ptr<ArkNpcDamageFsm,std::default_delete<ArkNpcDamageFsm>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkDelegate<void__cdecl(unsignedint,unsignedint,bool)> {
    void * m_pObject;
    void * m_pCaller;
};

struct unique_ptr<ArkNpcLifecycle,std::default_delete<ArkNpcLifecycle>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkFireAndForgetEffect {
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

struct vector<EntityEffects::SEffectInfo,std::allocator<EntityEffects::SEffectInfo>> {
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

struct CEffectsController {
    struct IEntity * m_pOwnerEntity;
    struct vector<EntityEffects::SEffectInfo,std::allocator<EntityEffects::SEffectInfo>> m_attachedEffects;
    uint m_effectGeneratorId;
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

struct ArkAiKnowledge {
    struct ArkNpc * m_npc;
};

struct unique_ptr<ArkNpcBody,std::default_delete<ArkNpcBody>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkEntityAttachmentEffect {
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
    struct CEffectsController * m_controller;
    struct CryStringT<char> m_attachmentName;
    int m_attachmentSlot;
    uint m_effectId;
};

struct aligned_storage<32,8> {
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
};

struct variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> {
    int which_;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    struct aligned_storage<32,8> storage_;
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

struct ArkCharacterEffectsManager {
    struct IEntity * m_pEntity;
    struct vector<CryStringT<char>,std::allocator<CryStringT<char>>> m_attachmentsByType[64];
};

struct ArkNpcNoiseStateDesire {
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
    enum EArkNpcNoiseState m_noiseState;
    undefined field65_0x44;
    undefined field66_0x45;
    undefined field67_0x46;
    undefined field68_0x47;
};

struct unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>,std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkSimpleTimer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float m_duration;
};

struct ArkNpcFacingDesireManager {
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
};

struct ArkRandomizedTimer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    float m_variation;
};

struct ArkDialogPlayerRobotLightExtension {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct ArkRandomizedTimer m_brightnessTimer;
    undefined field9_0x14;
    undefined field10_0x15;
    undefined field11_0x16;
    undefined field12_0x17;
    __uint64 m_lastDialogId;
    float m_minBrightness;
    float m_maxBrightness;
    struct ArkRobotLight * m_light;
};

struct ArkRobotLight {
    struct IEntity * m_pEntity;
    uint m_arkLightEntityId;
    enum LightMode m_lightMode;
    struct ArkDialogPlayerRobotLightExtension m_dialogExtension;
    struct ArkSimpleTimer m_lightFlickerDurationTimer;
    struct ArkSimpleTimer m_lightFlickerToggleTimer;
    float m_flickerToggleMaxTime;
    float m_onBrightness;
    bool m_bActive;
    bool m_bGlowHidden;
    bool m_bEntityHidden;
    bool m_bIsOn;
    bool m_bScriptEnabled;
    bool m_bIsFlickering;
    bool m_bFlickeringForceOff;
    bool m_bRemoved;
};

struct CTimeValue {
    __int64 m_lValue;
};

struct ArkSpatiallySortedKey {
    __uint64 m_index;
};

struct ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> {
    struct ArkSpatiallySortedKey m_key;
};

struct ArkSpatialManagerEntryImpl_Npc {
    undefined field0_0x0;
};

struct ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc> {
    struct ArkSpatialManagerEntryImpl_Npc m_impl;
    struct ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> m_key;
};

struct ArkAudioRtpc {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct _smart_ptr<IAnimSequence> {
    struct IAnimSequence * p;
};

struct aligned_storage<32,4> {
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
};

struct variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>> {
    int which_;
    struct aligned_storage<32,4> storage_;
};

struct ArkNpcDesireTarget {
    struct variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>> m_target;
};

struct ArkNpcLookDesire {
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
    struct ArkNpcDesireTarget m_target;
    bool m_bUseAim;
    bool m_bAllowLowerBodyTurn;
    undefined field67_0x66;
    undefined field68_0x67;
    enum ELookStyle m_style;
    enum EBodyOrientationMode m_orientMode;
    enum EArkNpcSpeedType m_minSpeed;
    struct LookPoseParam m_blendInTime;
    struct LookPoseParam m_smoothTime;
    struct LookPoseParam m_blendOutTime;
    struct LookPoseParam m_maxAngleRadiansPitch;
    struct LookPoseParam m_maxAngleRadiansYaw;
    float m_polarOffsetX;
    float m_polarOffsetY;
    undefined field79_0xcc;
    undefined field80_0xcd;
    undefined field81_0xce;
    undefined field82_0xcf;
    struct ArkDelegate<void__cdecl(enumEArkNpcLookDesireCallbackEvent)> m_callback;
};

struct unique_ptr<ArkAiTreeInstance,std::default_delete<ArkAiTreeInstance>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct ArkDelegate<void__cdecl(enumEArkNpcFacingDesireCallbackEvent)> {
    void * m_pObject;
    void * m_pCaller;
};

struct ArkNpcFacingDesire {
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
    enum TurnState m_turnState;
    struct ArkNpcDesireTarget m_target;
    struct ArkNpcDesireTarget m_turnAlignTarget;
    float m_resumeAngle;
    enum EArkNpcSpeedType m_minSpeed;
    undefined field69_0x94;
    undefined field70_0x95;
    undefined field71_0x96;
    undefined field72_0x97;
    struct ArkDelegate<void__cdecl(enumEArkNpcFacingDesireCallbackEvent)> m_callback;
};

struct ArkNpcAttentionObject {
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
    struct ArkNpc * m_pNpc;
};

struct ArkDelegate<void__cdecl(enumEArkNpcMovementDesireCallbackEvent)> {
    void * m_pObject;
    void * m_pCaller;
};

struct ArkNpcMovementDesire {
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
    struct ArkNpcDesireTarget m_destination;
    bool m_bQueryNavSystem;
    undefined field66_0x65;
    undefined field67_0x66;
    undefined field68_0x67;
    float m_navQueryHorizontalRadius;
    float m_navQueryBelowThreshold;
    float m_navQueryAboveThreshold;
    bool m_bForcePath;
    bool m_bForceGoToNavMesh;
    undefined field74_0x76;
    undefined field75_0x77;
    int m_stance;
    float m_speedLiteral;
    float m_accelLiteral;
    float m_decelLiteral;
    float m_stopDistance;
    float m_resumeDistance;
    bool m_bUseExactPosition;
    undefined field83_0x91;
    undefined field84_0x92;
    undefined field85_0x93;
    float m_exactRotationStartDist;
    struct Vec3_tpl<float> m_exactDirection;
    bool m_bShift;
    undefined field89_0xa5;
    undefined field90_0xa6;
    undefined field91_0xa7;
    float m_shiftDistBefore;
    float m_shiftDistAfter;
    float m_shiftTelegraphTime;
    enum ShiftAnimation m_shiftAnims;
    enum ShiftType m_shiftType;
    enum JumpStyle m_jumpStyle;
    enum JumpGoal m_jumpGoal;
    float m_jumpDist;
    float m_jumpGoalPathDist;
    enum HoverStyle m_hoverStyle;
    enum EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
    bool m_bContinueMoving;
    bool m_bScriptMove;
    bool m_bAllowTeleportToNavMesh;
    undefined field106_0xd7;
    enum FailureReason m_lastFailure;
    undefined field108_0xdc;
    undefined field109_0xdd;
    undefined field110_0xde;
    undefined field111_0xdf;
    struct ArkDelegate<void__cdecl(enumEArkNpcMovementDesireCallbackEvent)> m_callback;
};

struct ArkNpcAttentiveSubject {
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
    struct ArkNpc * m_pNpc;
    float m_complexHearingGain;
    float m_complexVisionGain;
    enum EArkNpcVisionDirection m_visionDirection;
    undefined field36_0x34;
    undefined field37_0x35;
    undefined field38_0x36;
    undefined field39_0x37;
};

struct MovementRequestID {
    uint id;
};

struct ArkNpcMovementDesireManager {
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
    struct MovementRequestID m_movementRequestId;
    struct MovementRequestID m_stopRequestId;
    struct ArkNpcFacingDesire m_facingDesire;
    bool m_bNeedsStop;
    bool m_bNeedsNavMeshReturn;
    undefined field53_0xe2;
    undefined field54_0xe3;
    undefined field55_0xe4;
    undefined field56_0xe5;
    undefined field57_0xe6;
    undefined field58_0xe7;
};

struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> {
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

struct HitInfo {
    uint shooterId;
    uint targetId;
    uint weaponId;
    uint projectileId;
    uint uniqueId;
    uint groupId;
    float damage;
    float impulseScale;
    float radius;
    float angle;
    int material;
    int type;
    int bulletType;
    float damageMin;
    int partId;
    struct Vec3_tpl<float> pos;
    struct Vec3_tpl<float> dir;
    struct Vec3_tpl<float> normal;
    ushort projectileClassId;
    ushort weaponClassId;
    bool remote;
    bool aimed;
    bool knocksDown;
    bool knocksDownLeg;
    bool hitViaProxy;
    bool explosion;
    bool forceLocalKill;
    bool critical;
    int penetrationCount;
};

struct ArkNpc {
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
    struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> m_cachedDoppelgangerCandidatePositions;
    struct vector<unsignedint,std::allocator<unsignedint>> m_cachedNearbyNpcsForAbility;
    struct Vec3_tpl<float> m_cachedThermogenesisLocation;
    struct Vec3_tpl<float> m_cachedEMPBlastLocation;
    struct Vec3_tpl<float> m_cachedHitReactShiftLocation;
    undefined field93_0xac;
    undefined field94_0xad;
    undefined field95_0xae;
    undefined field96_0xaf;
    struct ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc> m_spatialManagerEntry;
    __uint64 m_characterId;
    struct CEffectsController m_effectController;
    struct ArkNpcFacingDesireManager m_facingDesireManager;
    struct ArkNpcLookDesireManager m_lookDesireManager;
    struct ArkNpcMovementDesireManager m_movementDesireManager;
    struct ArkNpcNoiseStateDesireManager m_noiseStateDesireManager;
    struct ArkNpcSpeedDesireManager m_speedDesireManager;
    struct ArkCharacterEffectsManager m_characterEffectsManager;
    struct ArkMaterialAnimationManager m_materialAnimationManager;
    struct ArkNpcAttentiveSubject m_attentiveSubject;
    struct ArkNpcAttentionObject m_attentionObject;
    struct CArkNpcLookAroundControl m_lookAround;
    struct ArkIntrusiveList<ArkNpcCollisionObserver> m_collisionObservers;
    struct ArkNpcProperties m_properties;
    struct variant<ArkNpcSpawnedState_Alert,ArkNpcSpawnedState_Broken,ArkNpcSpawnedState_Dead,ArkNpcSpawnedState_Dormant> m_spawnedState;
    struct unique_ptr<ArkNpcLifecycle,std::default_delete<ArkNpcLifecycle>> m_pLifecycle;
    struct unique_ptr<ArkNpcBody,std::default_delete<ArkNpcBody>> m_pBody;
    struct unique_ptr<ArkNpcDamageFsm,std::default_delete<ArkNpcDamageFsm>> m_pDamageFsm;
    struct ArkNpcLookDesire m_attentionLookDesire;
    struct ArkNpcNoiseStateDesire m_attentionNoiseStateDesire;
    struct ArkNpcFacingDesire m_blendRagdollFacingDesire;
    struct ArkNpcLookDesire m_blendRagdollLookDesire;
    struct ArkNpcMovementDesire m_blendRagdollMovementDesire;
    struct ArkNpcFacingDesire m_conversationFaceDesire;
    struct ArkNpcLookDesire m_conversationLookDesire;
    struct ArkNpcMovementDesire m_conversationMovementDesire;
    struct ArkNpcFacingDesire m_trackViewFacingDesire;
    struct ArkNpcLookDesire m_trackViewLookingDesire;
    enum ECryAiSystemActiveState m_cryAISystemState;
    undefined field127_0x17b4;
    undefined field128_0x17b5;
    undefined field129_0x17b6;
    undefined field130_0x17b7;
    struct ArkAiKnowledge m_aiKnowledge;
    struct CryStringT<char> m_aiTreeFilePath;
    struct shared_ptr<ArkAiTree> m_pAiTree;
    struct unique_ptr<ArkAiTreeInstance,std::default_delete<ArkAiTreeInstance>> m_pAiTreeInstance;
    bool m_bUpdatingForStimuli;
    bool m_bSerializedUpdatingForStimuli;
    undefined field137_0x17e2;
    undefined field138_0x17e3;
    undefined field139_0x17e4;
    undefined field140_0x17e5;
    undefined field141_0x17e6;
    undefined field142_0x17e7;
    struct ArkUnanimous m_abilitiesEnabled;
    struct ArkUnanimous m_aiTreeEnabled;
    struct ArkUnanimous m_ambientSoundEnabled[2];
    struct ArkUnanimous m_attentionObjectEnabled;
    struct ArkUnanimous m_attentiveSubjectEnabled;
    struct ArkUnanimous m_audibleEnabled;
    struct ArkUnanimous m_combatIntensityEnabled;
    struct ArkUnanimous m_hearingEnabled;
    struct ArkUnanimous m_lifetimeEffectEnabled;
    struct ArkUnanimous m_operatorLevitatorsEffectEnabled;
    struct ArkUnanimous m_roomPerceiverEnabled;
    struct ArkUnanimous m_visibleEnabled;
    struct ArkUnanimous m_visionEnabled;
    __uint64 m_aiAlwaysUpdatePushCount;
    __uint64 m_aiTreeSuspendedCount;
    __uint64 m_disableDeathReactionsCount;
    __uint64 m_disableHitReactionsCount;
    __uint64 m_disableNpcHealthUiCount;
    __uint64 m_dumbedCount;
    __uint64 m_glassBreakingEnabledCount;
    __uint64 m_rigidOnGlooFrozenCount;
    bool m_bFlowGraphAiDisabled;
    bool m_bFlowGraphCanCorruptNpcs;
    bool m_bFlowGraphCombatIntensityDisabled;
    bool m_bFlowGraphDumbed;
    bool m_bFlowGraphIgnoreDistractions;
    bool m_bHasTimeToDeath;
    undefined field170_0x190e;
    undefined field171_0x190f;
    float m_timeToDeath;
    struct Vec3_tpl<float> m_headPosition;
    struct Vec3_tpl<float> m_headDirection;
    struct ArkAudioRtpc m_distanceToPlayerRtpc;
    uint m_wanderAreaContainerEntityId;
    bool m_bWanderDisabled;
    bool m_bCurrentlyWandering;
    bool m_bPushedAIAlwaysUpdateForPatrol;
    bool m_bCanBeDistracted;
    bool m_bIsDistracted;
    undefined field182_0x1939;
    undefined field183_0x193a;
    undefined field184_0x193b;
    float m_usedDistractionCooldown;
    struct ArkUnanimous m_breakable;
    float m_transitionStateTagTimer;
    bool m_bShouldSkipNextCombatReaction;
    bool m_bAnimatedMovement;
    bool m_bAnimatedJump;
    bool m_bIsFrozenInGloo;
    bool m_bDeflectsGloo;
    undefined field193_0x1959;
    undefined field194_0x195a;
    undefined field195_0x195b;
    uint m_breakGlooEntityId;
    struct ArkSimpleTimer m_playerBumpTimer;
    struct ArkSimpleTimer m_xRayVisionTimeOnPlayer;
    uint m_topAttentionTargetEntityId;
    undefined field200_0x1974;
    undefined field201_0x1975;
    undefined field202_0x1976;
    undefined field203_0x1977;
    struct ArkDelegate<void__cdecl(void)> m_fleeStartFlowNodeCallback;
    struct ArkDelegate<void__cdecl(void)> m_fleeEndFlowNodeCallback;
    struct ArkDelegate<void__cdecl(void)> m_guardInPositionFlowNodeCallback;
    struct ArkDelegate<void__cdecl(unsignedint,unsignedint,bool)> m_createPhantomFlowNodeCallback;
    bool m_bHasPerformedNotice;
    undefined field209_0x19b9;
    undefined field210_0x19ba;
    undefined field211_0x19bb;
    undefined field212_0x19bc;
    undefined field213_0x19bd;
    undefined field214_0x19be;
    undefined field215_0x19bf;
    struct CTimeValue m_lastSearchAnimTime;
    bool m_bIsInCombat;
    bool m_bCombatIntensityIncreased;
    undefined field219_0x19ca;
    undefined field220_0x19cb;
    enum EArkCombatRole m_currentCombatRole;
    float m_combatReactionCooldownTimer;
    struct HitInfo m_lastDamagingHitInfo;
    undefined field224_0x1a44;
    undefined field225_0x1a45;
    undefined field226_0x1a46;
    undefined field227_0x1a47;
    __uint64 m_lastDamagingPackageId;
    int m_lastOnHitFrameId;
    undefined field230_0x1a54;
    undefined field231_0x1a55;
    undefined field232_0x1a56;
    undefined field233_0x1a57;
    struct CTimeValue m_damageAccumulationStartTime;
    float m_damageAccumulationFromPlayer;
    bool m_bIsIgnoringRangedAbilities;
    undefined field237_0x1a65;
    undefined field238_0x1a66;
    undefined field239_0x1a67;
    __uint64 m_lastAbilityContextIdPerformed;
    struct CTimeValue m_dodgeTimeStamp;
    struct CTimeValue m_knockDownTimeStamp;
    struct CTimeValue m_staggerTimeStamp;
    struct CTimeValue m_hypnotizeStartTimeStamp;
    bool m_bPsiSuppressed;
    bool m_bIsPrereqHitReacting;
    bool m_bIsTakingPrereqDamage;
    bool m_bPrereqIsRegainingLoS;
    bool m_bCanMimicSideStepLeft;
    bool m_bCanMimicSideStepRight;
    undefined field251_0x1a96;
    undefined field252_0x1a97;
    __uint64 m_animAttackPackageId;
    struct _smart_ptr<IAnimSequence> m_pTrackviewSequence;
    float m_mimicGlitchTimeNext;
    undefined field256_0x1aac;
    undefined field257_0x1aad;
    undefined field258_0x1aae;
    undefined field259_0x1aaf;
    struct ArkEntityAttachmentEffect m_mimicMorphInEffect;
    struct ArkEntityAttachmentEffect m_mimicMorphOutEffect;
    struct vector<unsignedint,std::allocator<unsignedint>> m_raisedPhantomIds;
    uint m_ethericDoppelgangerId;
    uint m_ethericDoppelgangerOwnerId;
    bool m_bIsEthericDoppelganger;
    undefined field266_0x1b81;
    undefined field267_0x1b82;
    undefined field268_0x1b83;
    undefined field269_0x1b84;
    undefined field270_0x1b85;
    undefined field271_0x1b86;
    undefined field272_0x1b87;
    struct unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>,std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>>> m_pLiftVolumeManager;
    uint m_npcThatCorruptedMe;
    undefined field275_0x1b94;
    undefined field276_0x1b95;
    undefined field277_0x1b96;
    undefined field278_0x1b97;
    struct vector<unsignedint,std::allocator<unsignedint>> m_npcsCorrupted;
    bool m_bCorruptedMovementDisabled;
    bool m_bWasUncorrupted;
    undefined field282_0x1bb2;
    undefined field283_0x1bb3;
    undefined field284_0x1bb4;
    undefined field285_0x1bb5;
    undefined field286_0x1bb6;
    undefined field287_0x1bb7;
    struct ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect1;
    struct ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect2;
    struct ArkAirJetManager m_operatorAirJetManager;
    struct ArkRobotLight m_robotLight;
    struct ArkFireAndForgetEffect m_aoeDeathEffect;
    struct Vec3_tpl<float> m_cachedThrowAtLocation;
    enum EReactionThrowAtType m_cachedThrowAtType;
    uint m_leaderEntityId;
    uint m_attachedPistolEntityId;
    int m_numAmmo;
    bool m_bInitiallyUpdateAi;
    bool m_bIsSerializingRead;
    bool m_bHasFullSerializeReadBeenCalled;
    bool m_bShuttingDown_Hack;
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

struct SCRCRef<1,SCRCRefHash_CRC32Lowercase> {
    uint crc;
    char * stringValue;
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

struct CMTRand_int32 {
    uint m_nState[625];
    int p;
};

struct CTagState {
    struct CTagDefinition * m_defs;
    struct STagState<12> m_state;
};

struct SAnimationContext {
    struct SControllerDef * controllerDef;
    struct CTagState state;
    struct DynArray<CTagState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> subStates;
    struct CMTRand_int32 randGenerator;
};

struct IAnimSequence {
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

struct IEntityArchetype {
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

