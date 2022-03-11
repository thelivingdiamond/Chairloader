#pragma once
#include "pch.h"
#include "ArkBasicTypes.h"
#include <map>
#include <set>
#include <unordered_map>

#include "preyDllObjects.h"


typedef enum EHostMigrationState {

   eHMS_NotMigrating=0,
    eHMS_WaitingForPlayers=1,
    eHMS_Resuming=2
} EHostMigrationState;

typedef enum ERichPresenceState {

   eRPS_none=0,
    eRPS_idle=1,
    eRPS_frontend=2,
    eRPS_lobby=3,
    eRPS_inGame=4
} ERichPresenceState;

typedef enum EInviteAcceptedState {

   eIAS_None=0,
    eIAS_Init=1,
    eIAS_StartAcceptInvite=2,
    eIAS_InitProfile=3,
    eIAS_WaitForInitProfile=4,
    eIAS_WaitForLoadToFinish=5,
    eIAS_DisconnectGame=6,
    eIAS_DisconnectLobby=7,
    eIAS_WaitForSessionDelete=8,
    eIAS_ConfirmInvite=9,
    eIAS_WaitForInviteConfirmation=10,
    eIAS_InitSinglePlayer=11,
    eIAS_WaitForInitSinglePlayer=12,
    eIAS_WaitForSplashScreen=13,
    eIAS_WaitForValidUser=14,
    eIAS_InitMultiplayer=15,
    eIAS_WaitForInitMultiplayer=16,
    eIAS_InitOnline=17,
    eIAS_WaitForInitOnline=18,
    eIAS_WaitForSquadManagerEnabled=19,
    eIAS_Accept=20,
    eIAS_Error=21
} EInviteAcceptedState;

typedef enum ESaveIconMode {

   eSIM_Off=0,
    eSIM_SaveStart=1,
    eSIM_Saving=2,
    eSIM_Finished=3
} ESaveIconMode;

typedef enum EPlatform {

   ePlatform_Unknown=0,
    ePlatform_PC=1,
    ePlatform_XBoxOne=2,
    ePlatform_PS4=3,
    ePlatform_COUNT=4
} EPlatform;

typedef enum State {

   Idle=0,
    UpdatingModules=1
} State;

typedef enum EControlScheme {

   eControlScheme_NotSpecified=0,
    eControlScheme_Keyboard=1,
    eControlScheme_KeyboardMouse=2,
    eControlScheme_XBoxOneController=3,
    eControlScheme_PS4Controller=4,
    eControlScheme_SteamController=5
} EControlScheme;

typedef enum ECryLobbyService {

   eCLS_LAN=0,
    eCLS_Online=1,
    eCLS_NumServices=2
} ECryLobbyService;

typedef enum ECryLobbyError {

   eCLE_Success=0,
    eCLE_SuccessContinue=1,
    eCLE_ServiceNotSupported=2,
    eCLE_AlreadyInitialised=3,
    eCLE_NotInitialised=4,
    eCLE_TooManyTasks=5,
    eCLE_OutOfMemory=6,
    eCLE_OutOfSessionUserData=7,
    eCLE_UserDataNotRegistered=8,
    eCLE_UserDataTypeMissMatch=9,
    eCLE_TooManySessions=10,
    eCLE_InvalidSession=11,
    eCLE_InvalidRequest=12,
    eCLE_SPAFileOutOfDate=13,
    eCLE_ConnectionFailed=14,
    eCLE_SessionFull=15,
    eCLE_SessionWrongState=16,
    eCLE_UserNotSignedIn=17,
    eCLE_InvalidParam=18,
    eCLE_TimeOut=19,
    eCLE_InsufficientPrivileges=20,
    eCLE_AlreadyInSession=21,
    eCLE_LeaderBoardNotRegistered=22,
    eCLE_UserNotInSession=23,
    eCLE_OutOfUserData=24,
    eCLE_NoUserDataRegistered=25,
    eCLE_ReadDataNotWritten=26,
    eCLE_UserDataMissMatch=27,
    eCLE_InvalidUser=28,
    eCLE_PSNContextError=29,
    eCLE_PSNWrongSupportState=30,
    eCLE_SuccessUnreachable=31,
    eCLE_ServerNotDefined=32,
    eCLE_WorldNotDefined=33,
    eCLE_SystemIsBusy=34,
    eCLE_TooManyParameters=35,
    eCLE_NotEnoughParameters=36,
    eCLE_DuplicateParameters=37,
    eCLE_ExceededReadWriteLimits=38,
    eCLE_InvalidTitleID=39,
    eCLE_IllegalSessionJoin=40,
    eCLE_InternetDisabled=41,
    eCLE_NoOnlineAccount=42,
    eCLE_NotConnected=43,
    eCLE_CyclingForInvite=44,
    eCLE_CableNotConnected=45,
    eCLE_SessionNotMigratable=46,
    eCLE_SuccessInvalidSession=47,
    eCLE_RoomDoesNotExist=48,
    eCLE_PSNUnavailable=49,
    eCLE_TooManyOrders=50,
    eCLE_InvalidOrder=51,
    eCLE_OrderInUse=52,
    eCLE_OnlineAccountBlocked=53,
    eCLE_AgeRestricted=54,
    eCLE_ReadDataCorrupt=55,
    eCLE_PasswordIncorrect=56,
    eCLE_InvalidInviteFriendData=57,
    eCLE_InvalidJoinFriendData=58,
    eCLE_InvalidPing=60,
    eCLE_CDKeyMalformed=61,
    eCLE_CDKeyUnknown=62,
    eCLE_CDKeyAuthFailed=63,
    eCLE_CDKeyDisabled=64,
    eCLE_CDKeyInUse=65,
    eCLE_MultipleSignIn=66,
    eCLE_Banned=67,
    eCLE_CDKeyTimeOut=68,
    eCLE_IncompleteLoginCredentials=69,
    eCLE_WrongVersion=70,
    eCLE_NoServerAvailable=71,
    eCLE_ArbitratorTimeOut=72,
    eCLE_RequiresInvite=73,
    eCLE_SteamInitFailed=74,
    eCLE_SteamBlocked=75,
    eCLE_NothingToEnumerate=76,
    eCLE_ServiceNotConnected=77,
    eCLE_GlobalBan=78,
    eCLE_Cancelled=79,
    eCLE_Kicked=79,
    eCLE_UnhandledNickError=80,
    eCLE_InternalError=81,
    eCLE_NumErrors=82
} ECryLobbyError;

typedef enum ECryLobbyInviteType {

   eCLIT_InviteToSquad=0,
    eCLIT_JoinSessionInProgress=1,
    eCLIT_InviteToSession=2
} ECryLobbyInviteType;

typedef enum AsyncState {

   AsyncFailed=0,
    AsyncReady=1,
    AsyncInProgress=2,
    AsyncComplete=3
} AsyncState;


class DeferredDeathReaction {
public:
    std::multimap<float, uint32_t, std::less<float>> potentialWitnesses;
    Vec3 deathPos;
    uint32_t victimID,
        closestID,
        witnessID,
        killerID;
    int32_t groupID;
    float timestamp;
    unsigned char state;
    char pad[3];
};
class DeadBody {
public:
    Vec3 position;
    int32_t groupID;
    uint32_t entityID,
        killerID;
};

class DeathManager {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    std::vector<DeferredDeathReaction> m_deferredDeathReactions;
    std::vector<DeadBody> m_unseenDeadBodies;
    enum AsyncState m_asyncState;
    uint32_t m_rayID;
};

class IActionFilter {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class CScriptBind_Game {
public:
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
    class ISystem * m_pSystem;
    class IGameFramework * m_pGameFW;
};

class SExtractionParams {
public:
   float carryingTick_SpeedScale;
    float carryingTick_EnergyCostPerHit;
    float carryingTick_DamageAbsorbDesperateEnergyCost;
};

class LoadingColorGradient {
public:

};
class LoadedColorGradient {
public:
    CryStringT<char> m_filePath;
    float m_fadeInTimeInSeconds;

};

class CColorGradientManager {
public:
   std::vector<LoadingColorGradient> m_colorGradientsToLoad;
    std::vector<LoadedColorGradient> m_currentGradients;
};


class SmartScriptTable {
public:
   class IScriptTable * p;
};

class SPlatformInfo {
public:
   enum EPlatform platformId;
    unsigned char devices;
};



class PrefetchSlot {
public:
    CSharedString geomName;
    float requestTime;
};

class CItemPrefetchCHRManager {
public:
   float m_fTimeout;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    std::vector<PrefetchSlot> m_prefetches;
};

class IInputEventListener {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class SCaptureTheFlagParams {
public:
   float carryingFlag_SpeedScale;
};

class IScriptTable {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};








class SPointData {
public:
   std::vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> m_points;
    std::vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> m_velocity;
    std::vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> m_fuzzyPoints;
};

class IXmlNode {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int32_t m_nRefCount;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
};

class XmlNodeRef {
public:
   class IXmlNode * p;
};

class CDataPatchDownloader {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    class IDataPatcherListener * m_pListener;
    uint32_t m_patchCRC;
    int32_t m_patchId;
    class XmlNodeRef m_patchXML;
    char * m_pFileBeingPatched;
    bool m_patchingEnabled;
    bool m_bNeedWeaponSystemReload;
    undefined field15_0x2a;
    undefined field16_0x2b;
    undefined field17_0x2c;
    undefined field18_0x2d;
    undefined field19_0x2e;
    undefined field20_0x2f;
};

class SDBAGroupUser {
	
};
class SDBAGroup {
public:
    CryHashStringId m_groupId;
    int32_t m_userCount;
    std::vector<CryStringT<char>> m_dbas;
};

class CGameCharacterDBAs {
public:
   std::vector<SDBAGroupUser> m_dbaGroupUsers;
    std::vector<SDBAGroup> m_dbaGroups;
};

class SLinkedListPointers {
public:
   class CGameMechanismBase * m_nextMechanism;
    class CGameMechanismBase * m_prevMechanism;
};

class CGameMechanismBase {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    class SLinkedListPointers m_linkedListPointers;
};


class STarget {
public:
    Vec3_tpl<float> m_position;
    Vec3_tpl<float> m_offset;
    uint32_t m_entityId;
    int32_t m_characterAttachmentSlot;
    uint32_t m_characterAttachmentNameCRC;
};



class CCustomReactionFunctions {
public:
    //TODO
   //std::unordered_map<CryStringT<char>,Functor4wRet<CCryActor&,SReactionParams::SValidationParamsconst&,HitInfoconst&,enumArkNpcCustomHitReaction::Type,bool>,stl::hash_stricmp<CryStringT<char>>,stl::hash_stricmp<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,Functor4wRet<CCryActor&,SReactionParams::SValidationParamsconst&,HitInfoconst&,enumArkNpcCustomHitReaction::Type,bool>>>> m_validationFunctors;
    //std::unordered_map<CryStringT<char>,Functor3<CCryActor&,SReactionParamsconst&,HitInfoconst&>,stl::hash_stricmp<CryStringT<char>>,stl::hash_stricmp<CryStringT<char>>const,Functor3<CCryActor&,SReactionParamsconst&,HitInfoconst&>>>> m_executionFunctors;
    char pad1[64];
    char pad2[64];
    unsigned short m_shotgunShellProjectile;
    undefined field3_0x82;
    undefined field4_0x83;
    undefined field5_0x84;
    undefined field6_0x85;
    undefined field7_0x86;
    undefined field8_0x87;
};








class IPlayerProfileManager {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};










class DLCContents {
public:
	std::vector<CryStringT<char>> levels;
    uint32_t bonusID;
    wchar_t name[32];
    undefined field3_0x5c;
    undefined field4_0x5d;
    undefined field5_0x5e;
    undefined field6_0x5f;
    CryFixedStringT<32> root;
    CryFixedStringT<2048> scoreRewardsPath;
    CryFixedStringT<2048> playlistsPath;
    CryFixedStringT<32> uniqueTag;
    CryFixedStringT<32> descriptionStr;
    uint32_t uniqueID;
    uint32_t messageID;
};

class CDLCManager {
public:
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
    DLCContents m_dlcContents[16];
    CryFixedArray<uint32_t,16> m_itemUnlockDLCids;
    CryFixedStringT<128> m_prevLevelName;
    CryFixedStringT<128> m_dlcWarning;
    uint32_t m_loadedDLCs;
    uint32_t m_allowedDLCs;
    uint32_t m_entitledDLCs;
    uint32_t m_warningPriority;
    int32_t m_requiredDLCs;
    bool m_dlcLoaded;
    bool m_allowedDLCUpToDate;
    bool m_allowedDLCCheckFailed;
    bool m_onlineAttributesRead;
    bool m_bContentRemoved;
    bool m_bContentAvailable;
    undefined field39_0x115b2;
    undefined field40_0x115b3;
    uint32_t m_appliedDLCStat;
    uint32_t m_DLCXPToAward;
    bool m_bNewDLCAdded;
    bool m_queueEventEntitlement;
    undefined field45_0x115be;
    undefined field46_0x115bf;
    uint32_t m_entitlementTask;
    undefined field48_0x115c4;
    undefined field49_0x115c5;
    undefined field50_0x115c6;
    undefined field51_0x115c7;
};




class SPlayerLadder {
public:
   int32_t ladder_renderPlayerLast;
    int32_t ladder_logVerbosity;
};

class SAIPerceptionCVars {
public:
   int32_t movement_useSurfaceType;
    float movement_movingSurfaceDefault;
    float movement_standingRadiusDefault;
    float movement_crouchRadiusDefault;
    float movement_standingMovingMultiplier;
    float movement_crouchMovingMultiplier;
    float landed_baseRadius;
    float landed_speedMultiplier;
};





class AABB {
public:
   Vec3_tpl<float> min;
	Vec3_tpl<float> max;
};


class SPlayerEnemyRamming {
public:
   float player_to_player;
    float ragdoll_to_player;
    float fall_damage_threashold;
    float safe_falling_speed;
    float fatal_falling_speed;
    float max_falling_damage;
    float min_momentum_to_fall;
};



class SPlayerLedgeClamber {
public:
   float cameraBlendWeight;
    int32_t debugDraw;
    int32_t enableVaultFromStanding;
};



class CGamePhysicsSettings {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    char * m_names[23];
    uint32_t m_classIgnoreMap[23];
    undefined field10_0x11c;
    undefined field11_0x11d;
    undefined field12_0x11e;
    undefined field13_0x11f;
};



class CItemParticleEffectCache {
public:
   std::map<int32_t,IParticleEffect*,std::less<int32_t>,std::allocator<std::pair<const int32_t,IParticleEffect*>>> m_cachedParticles;
};

class CScriptBind_GameAI {
public:
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
    class ISystem * m_system;
    class IGameFramework * m_gameFramework;
    class IScriptSystem * m_scriptSystem;
};

class CScriptBind_HitDeathReactions {
public:
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
    class SmartScriptTable m_pParams;
    class ISystem * m_pSystem;
    class IGameFramework * m_pGameFW;
};



class CDownloadableResource {
public:
    //TODO
    char pad[632];
};

class CDownloadMgr {
public:
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
    std::vector<CDownloadableResource*> m_resources;
};





class ICharacterInstance {
public:
    void* ptr;
};

class IStatObj {
public:
    char pad[48];
};


class CItemGeometryCache {
public:
   std::map<uint32_t,ICharacterInstance*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,ICharacterInstance*>>> m_editorCachedCharacters;
    std::map<uint32_t,IStatObj*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,IStatObj*>>> m_cachedStaticObjects;
};

class CorpseInfo {
public:
    uint32_t corpseId;
    CCryFlags<uint32_t> flags;
};

class CAICorpseManager {
public:
   std::vector<CorpseInfo> m_corpsesArray;
    uint32_t m_maxCorpses;
    uint32_t m_lastUpdatedCorpseIdx;
};

class SPlayerSlideControl {
public:
   float min_speed_threshold;
    float min_speed;
    float deceleration_speed;
    float min_downhill_threshold;
    float max_downhill_threshold;
    float max_downhill_acceleration;
};


class CGameLocalizationManager {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    class CryStringT<char> m_loadedTag[3];
};











class SAltNormalization {
public:
   int32_t enable;
    float hud_ctrl_Curve_Unified;
    float hud_ctrl_Coeff_Unified;
};



class IActorSystem {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};



class IDataPatcherListener {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class SDeathCamSPParams {
public:
   int32_t enable;
    int32_t dof_enable;
    float updateFrequency;
    float dofRange;
    float dofRangeNoKiller;
    float dofRangeSpeed;
    float dofDistanceSpeed;
};

class CMTRand_int32 {
public:
   uint32_t m_nState[625];
    int32_t p;
};

class CRndGen {
public:
   uint64_t m_state;
};

class CBlendGroup {
	//TODO
public:
    char pad[40];
};

class CScreenEffects {
public:
   std::map<int32_t,CBlendGroup*,std::less<int32_t>,std::allocator<std::pair<const int32_t,CBlendGroup*>>> m_blends;
    std::map<int32_t,bool,std::less<int32_t>,std::allocator<std::pair<const int32_t,bool>>> m_enabledGroups;
    int32_t m_curUniqueID;
    bool m_enableBlends;
    bool m_updatecoords;
    CryStringT<char> m_coordsXname;
    CryStringT<char> m_coordsYname;
    Vec3_tpl<float> m_coords3d;
};



class SIgnoreEntity {
public:
   uint32_t id;
    uint32_t refCount;
};

template<uint32_t i> class RayCastQueue {
public:
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
};

class SVisTableEntry {
public:
   uint32_t entityId;
    float heightOffset;
    unsigned short flags;
    unsigned char framesSinceLastCheck;
    unsigned char lastRequestedLatency;
};

class CScriptBind_ProtectedBinds {
public:
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
    class ISystem * m_pSystem;
    bool m_active;
    undefined field98_0x69;
    undefined field99_0x6a;
    undefined field100_0x6b;
    undefined field101_0x6c;
    undefined field102_0x6d;
    undefined field103_0x6e;
    undefined field104_0x6f;
};


class CBodyDamageManager {
public:
    //TODO
    char pad[136];
  /* std::vector<SBodyDamageDef> m_bodyDamageDefinitions;
    std::vector<CBodyDamageProfile*,std::allocator<CBodyDamageProfile*>> m_bodyDamageProfiles;
    uint32_t m_bodyDamageIdGen;
    undefined field3_0x34;
    undefined field4_0x35;
    undefined field5_0x36;
    undefined field6_0x37;
    std::vector<SBodyDeclassibilityDef> m_bodyDeclassibilityDefinitions;
    std::vector<CBodyDeclassibilityProfile*,std::allocator<CBodyDeclassibilityProfile*>> m_bodyDeclassibilityProfiles;
    uint32_t m_bodyDeclassibilityIdGen;
    undefined field10_0x6c;
    undefined field11_0x6d;
    undefined field12_0x6e;
    undefined field13_0x6f;
    std::vectorMap<uint32_t,uint32_t,std::less<uint32_t>>> m_bodyDamageProfileIdEntityBindings;
    */
};

class SDeferredLinetestReceiver {
public:
   uint32_t queuedRayID;
    short visTableIndex;
    char visBufferIndex;
};



class CPrefabManager {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    std::map<CryStringT<char>,CPrefabLib*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CPrefabLib*>>> m_lstPrefabLibs;
    std::map<uint32_t,CRuntimePrefab*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,CRuntimePrefab*>>> m_lstRuntimePrefabs;
    std::map<CPrefab*,int32_t,std::less<CPrefab*>,std::allocator<std::pair<CPrefab*const,int32_t>>> m_lstOccurrences;
    class CryStringT<char> m_sLastPrefab;
    class CryStringT<char> m_sCurrentGroup;
};

class CWorldBuilder {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    class CPrefabManager m_PrefabManager;
};

class SPredatorParams {
public:
   float hudTimerAlertWhenTimeRemaining;
    float hintMessagePauseTime;
};



class SPowerSprintParams {
public:
   float foward_angle;
};



class SUIEventSenderDispatcher<enumCUIManager::EUIEvent> {
public:
   std::map<enumCUIManager::EUIEvent,uint32_t,std::less<enumCUIManager::EUIEvent>,std::allocator<std::pair<enumCUIManager::EUIEventconst,uint32_t>>> m_EventMap;
    class IUIEventSystem * m_pEventSystem;
};

class SLightningParams {
public:
   uint32_t m_nameCRC;
    float m_strikeTimeMin;
    float m_strikeTimeMax;
    float m_strikeFadeOut;
    int32_t m_strikeNumSegments;
    int32_t m_strikeNumPoints;
    float m_lightningDeviation;
    float m_lightningFuzzyness;
    float m_lightningVelocity;
    float m_branchProbability;
    int32_t m_branchMaxLevel;
    int32_t m_maxNumStrikes;
    float m_beamSize;
    float m_beamTexTiling;
    float m_beamTexShift;
    float m_beamTexFrames;
    float m_beamTexFPS;
};

class CHitDeathReactionsSystem {
public:
   std::map<uint32_t,CHitDeathReactionsSystem::SReactionsProfile,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,CHitDeathReactionsSystem::SReactionsProfile>>> m_reactionProfiles;
    class SFailSafeProfile m_failSafeProfile;
    class CCustomReactionFunctions m_customReactionFunctions;
    std::vectorMap<CryStringT<char>,SmartScriptTable,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>,SmartScriptTable>>> m_reactionsScriptTableCache;
    class CMTRand_int32 m_pseudoRandom;
    unsigned char m_streamingEnabled;
    undefined field6_0xab9;
    undefined field7_0xaba;
    undefined field8_0xabb;
    undefined field9_0xabc;
    undefined field10_0xabd;
    undefined field11_0xabe;
    undefined field12_0xabf;
};



class CScriptBind_Actor {
public:
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
    class ISystem * m_pSystem;
    class IGameFramework * m_pGameFW;
};

class SAIThreatModifierCVars {
public:
   char * DebugAgentName;
    float SOMIgnoreVisualRatio;
    float SOMDecayTime;
    float SOMMinimumRelaxed;
    float SOMMinimumCombat;
    float SOMCrouchModifierRelaxed;
    float SOMCrouchModifierCombat;
    float SOMMovementModifierRelaxed;
    float SOMMovementModifierCombat;
    float SOMWeaponFireModifierRelaxed;
    float SOMWeaponFireModifierCombat;
    float SOMCloakMaxTimeRelaxed;
    float SOMCloakMaxTimeCombat;
    float SOMUncloakMinTimeRelaxed;
    float SOMUncloakMinTimeCombat;
    float SOMUncloakMaxTimeRelaxed;
    float SOMUncloakMaxTimeCombat;
};

class SPlayerMelee {
public:
   float melee_snap_angle_limit;
    float melee_snap_blend_speed;
    float melee_snap_target_select_range;
    float melee_snap_end_position_range;
    float melee_snap_move_speed_multiplier;
    float damage_multiplier_from_behind;
    float damage_multiplier_mp;
    float angle_limit_from_behind;
    float mp_victim_screenfx_intensity;
    float mp_victim_screenfx_duration;
    float mp_victim_screenfx_blendout_duration;
    float mp_victim_screenfx_dbg_force_test_duration;
    int32_t impulses_enable;
    int32_t debug_gfx;
    int32_t mp_melee_system;
    int32_t mp_melee_system_camera_lock_and_turn;
    int32_t mp_knockback_enabled;
    float mp_melee_system_camera_lock_time;
    float mp_melee_system_camera_lock_crouch_height_offset;
    float mp_knockback_strength_vert;
    float mp_knockback_strength_hor;
    int32_t mp_sliding_auto_melee_enabled;
};

class SActorFileModelInfo {
public:
   class CryStringT<char> sFileName;
    class CryStringT<char> sClientFileName;
    class CryStringT<char> sShadowFileName;
    bool bUseFacialFrameRateLimiting;
    undefined field4_0x19;
    undefined field5_0x1a;
    undefined field6_0x1b;
    undefined field7_0x1c;
    undefined field8_0x1d;
    undefined field9_0x1e;
    undefined field10_0x1f;
    std::vector<SActorIKLimbInfo,std::allocator<SActorIKLimbInfo>> IKLimbInfo;
};

class SLuaCache_ActorProperties {
public:
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
    class SActorFileModelInfo fileModelInfo;
    float fPhysicMassMult;
    bool bIsCached;
    undefined field19_0x4d;
    undefined field20_0x4e;
    undefined field21_0x4f;
};

template<uint32_t i> class IntersectionTestQueue {
public:
    void* ptr;
    void *ptrArray[i];
};



class SLightningSpark {
public:
   class CLightningRenderNode * m_renderNode;
    class STarget m_emitter;
    class STarget m_receiver;
    float m_timer;
};

class SStat {
public:
   int32_t m_current;
    int32_t m_peak;
};

class SLightningStats {
public:
   class SStat m_activeSparks;
    class SStat m_memory;
    class SStat m_triCount;
    class SStat m_branches;
};

class CLightningGameEffect {
public:
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
    std::vector<SLightningParams,std::allocator<SLightningParams>> m_lightningParams;
    class SLightningSpark m_sparks[24];
    class SLightningStats m_stats;
    class Vec3_tpl<float> m_receiverLocalPosition;
    undefined field36_0x8a4;
    undefined field37_0x8a5;
    undefined field38_0x8a6;
    undefined field39_0x8a7;
};

































class SInviteAcceptedData {
public:
   enum ECryLobbyService m_service;
    uint32_t m_user;
    class SCrySessionID* m_id;
    enum ECryLobbyError m_error;
    enum ECryLobbyInviteType m_type;
    bool m_bannedFromSession;
    bool m_failedToAcceptInviteAsNotSignedIn;
};









class CTimeValue {
public:
   int64_t m_lValue;
};























class CGame {
public:
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
    class SPlatformInfo m_platformInfo;
    class CGameCache * m_pGameCache;
    class CRndGen m_randomGenerator;
    class IGameFramework * m_pFramework;
    class IConsole * m_pConsole;
    class CGamePhysicsSettings * m_pGamePhysicsSettings;
    bool m_bReload;
    bool m_gameTypeMultiplayer;
    bool m_gameTypeInitialized;
    bool m_userProfileChanged;
    bool m_bLastSaveDirty;
    bool m_needsInitPatchables;
    bool m_editorDisplayHelpers;
    undefined field61_0x67;
    class CScriptBind_Actor * m_pScriptBindActor;
    class CScriptBind_Item * m_pScriptBindItem;
    class CScriptBind_GameRules * m_pScriptBindGameRules;
    class CScriptBind_Game * m_pScriptBindGame;
    class CScriptBind_GameAI * m_pScriptBindGameAI;
    class CScriptBind_HitDeathReactions * m_pScriptBindHitDeathReactions;
    class CScriptBind_ProtectedBinds * m_pScriptBindProtected;
    class CPlayerVisTable * m_pPlayerVisTable;
    class CDataPatchDownloader * m_pDataPatchDownloader;
    class IAntiCheatManager * m_pAntiCheatManager;
    class CGameLocalizationManager * m_pGameLocalizationManager;
    class ITelemetryCollector * m_telemetryCollector;
    class CGameActions * m_pGameActions;
    class IPlayerProfileManager * m_pPlayerProfileManager;
    bool m_inDevMode;
    bool m_hasExclusiveController;
    bool m_bExclusiveControllerConnected;
    bool m_rebindExclusiveControllerOnNextInput;
    bool m_bPausedForControllerDisconnect;
    bool m_bPausedForSystemMenu;
    bool m_bDeferredSystemMenuPause;
    bool m_previousPausedGameState;
    bool m_wasGamePausedByPLM;
    undefined field85_0xe1;
    undefined field86_0xe2;
    undefined field87_0xe3;
    undefined field88_0xe4;
    undefined field89_0xe5;
    undefined field90_0xe6;
    undefined field91_0xe7;
    uint64_t m_exclusiveControllerDeviceId;
    int32_t m_currentXboxLivePartySize;
    uint32_t m_clientActorId;
    class SCVars * m_pCVars;
    class SItemStrings * m_pItemStrings;
    class CGameSharedParametersStorage * m_pGameParametersStorage;
    class CryStringT<char> m_lastSaveGame;
    class CScreenEffects * m_pScreenEffects;
    class CDownloadMgr * m_pDownloadMgr;
    class CDLCManager * m_pDLCManager;
    class CLightningGameEffect * m_pLightningGameEffect;
    class CParameterGameEffect * m_pParameterGameEffect;
    class CWorldBuilder * m_pWorldBuilder;
    class IInputEventListener * m_pInputEventListenerOverride;
    std::map<CryStringT<char>,CryStringT<char>,stl::less_stricmp<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CryStringT<char>>>> m_variantOptions;
    std::map<CryFixedStringT<128>,int32_t,std::less<CryFixedStringT<128>>,std::allocator<std::pair<CryFixedStringT<128>const,int32_t>>> m_richPresence;
    std::vector<CGame::IRenderSceneListener*,std::allocator<CGame::IRenderSceneListener*>> m_renderSceneListeners;
    class CColorGradientManager * m_colorGradientManager;
    class CGameAISystem * m_pGameAISystem;
    class RayCastQueue<41> * m_pRayCaster;
    class IntersectionTestQueue<43> * m_pIntersectionTester;
    class CUIManager * m_pUIManager;
    class CHitDeathReactionsSystem * m_pHitDeathReactionsSystem;
    class CBodyDamageManager * m_pBodyDamageManager;
    class CMovementTransitionsSystem * m_pMovementTransitionsSystem;
    class CGameMechanismManager * m_gameMechanismManager;
    class CModInfoManager * m_pModInfoManager;
    float m_hostMigrationTimeStateChanged;
    float m_hostMigrationNetTimeoutLength;
    enum EHostMigrationState m_hostMigrationState;
    enum ERichPresenceState m_desiredRichPresenceState;
    enum ERichPresenceState m_pendingRichPresenceState;
    enum ERichPresenceState m_currentRichPresenceState;
    class SCrySessionID* m_pendingRichPresenceSessionID;
    class SCrySessionID* m_currentRichPresenceSessionID;
    float m_updateRichPresenceTimer;
    bool m_settingRichPresence;
    bool m_bRefreshRichPresence;
    bool m_bSignInOrOutEventOccured;
    undefined field131_0x207;
    class SInviteAcceptedData m_inviteAcceptedData;
    enum EInviteAcceptedState m_inviteAcceptedState;
    bool m_bLoggedInFromInvite;
    bool m_gameDataInstalled;
    bool m_postLocalisationBootChecksDone;
    undefined field137_0x22f;
    class CTimeValue m_levelStartTime;
    int32_t m_iCachedGsmValue;
    float m_fCachedGsmRangeValue;
    float m_fCachedGsmRangeStepValue;
    enum ESaveIconMode m_saveIconMode;
    float m_saveIconTimer;
    int32_t m_cachedUserRegion;
    bool m_bUserHasPhysicalStorage;
    bool m_bCheckPointSave;
    undefined field147_0x252;
    undefined field148_0x253;
    undefined field149_0x254;
    undefined field150_0x255;
    undefined field151_0x256;
    undefined field152_0x257;
    std::vector<uint32_t,std::allocator<uint32_t>> m_deferredKills;
    std::unique_ptr<ArkAiManager,std::default_delete<ArkAiManager>> m_pArkAiManager;
    std::unique_ptr<ArkAttentionManager,std::default_delete<ArkAttentionManager>> m_pArkAttentionManager;
    std::unique_ptr<ArkAttractionManager,std::default_delete<ArkAttractionManager>> m_pArkAttractionManager;
    std::unique_ptr<ArkAuralPerceptionManager,std::default_delete<ArkAuralPerceptionManager>> m_pArkAuralPerceptionManager;
    std::unique_ptr<ArkCharacterManager,std::default_delete<ArkCharacterManager>> m_pArkCharacterManager;
    std::unique_ptr<ArkCombatManager,std::default_delete<ArkCombatManager>> m_pArkCombatManager;
    std::unique_ptr<ArkCystoidManager,std::default_delete<ArkCystoidManager>> m_pArkCystoidManager;
    std::unique_ptr<ArkDistractionEntitySink,std::default_delete<ArkDistractionEntitySink>> m_pArkDistractionEntitySink;
    std::unique_ptr<ArkDistractionManager,std::default_delete<ArkDistractionManager>> m_pArkDistractionManager;
    std::unique_ptr<ArkDynamicCorpseManager,std::default_delete<ArkDynamicCorpseManager>> m_pArkDynamicCorpseManager;
    std::unique_ptr<ArkEncounterManager,std::default_delete<ArkEncounterManager>> m_pArkEncounterManager;
    std::unique_ptr<CArkFlowGraphManager,std::default_delete<CArkFlowGraphManager>> m_pArkFlowGraphManager;
    std::unique_ptr<ArkEthericFogManager,std::default_delete<ArkEthericFogManager>> m_pArkEthericFogManager;
    std::unique_ptr<ArkFactionManager,std::default_delete<ArkFactionManager>> m_pArkFactionManager;
    std::unique_ptr<ArkGameDataManager,std::default_delete<ArkGameDataManager>> m_pArkGameDataManager;
    std::unique_ptr<ArkGlintConfigManager,std::default_delete<ArkGlintConfigManager>> m_pArkGlintConfigManager;
    std::unique_ptr<CArkGlooIslandNavLinkManager,std::default_delete<CArkGlooIslandNavLinkManager>> m_pArkGlooIslandNavLinkManager;
    std::unique_ptr<ArkInstigationManager,std::default_delete<ArkInstigationManager>> m_pArkInstigationManager;
    std::unique_ptr<ArkLightTimeManager,std::default_delete<ArkLightTimeManager>> m_pArkLightTimeManager;
    std::unique_ptr<ArkListenerManager,std::default_delete<ArkListenerManager>> m_pArkListenerManager;
    std::unique_ptr<ArkLurkManager,std::default_delete<ArkLurkManager>> m_pArkLurkManager;
    std::unique_ptr<ArkMetaTagManager,std::default_delete<ArkMetaTagManager>> m_pArkMetaTagManager;
    std::unique_ptr<ArkNightmareEtherformManager,std::default_delete<ArkNightmareEtherformManager>> m_pArkNightmareEtherformManager;
    std::unique_ptr<ArkNightmareSpawnManager,std::default_delete<ArkNightmareSpawnManager>> m_pArkNightmareSpawnManager;
    std::unique_ptr<ArkNpcAbilityManager,std::default_delete<ArkNpcAbilityManager>> m_pArkNpcAbilityManager;
    std::unique_ptr<ArkNpcAreaManager,std::default_delete<ArkNpcAreaManager>> m_pArkNpcAreaManager;
    std::unique_ptr<ArkNpcBlackboardManager,std::default_delete<ArkNpcBlackboardManager>> m_pArkNpcBlackboardManager;
    std::unique_ptr<ArkNpcGameEffectManager,std::default_delete<ArkNpcGameEffectManager>> m_pArkNpcGameEffectManager;
    std::unique_ptr<ArkNpcManager,std::default_delete<ArkNpcManager>> m_pArkNpcManager;
    std::unique_ptr<ArkNpcSpawnManager,std::default_delete<ArkNpcSpawnManager>> m_pArkNpcSpawnManager; // 0x358
    std::unique_ptr<ArkNpcThrowPropManager,std::default_delete<ArkNpcThrowPropManager>> m_pArkNpcThrowPropManager;
    std::unique_ptr<ArkNpcUnreachableTargetingManager,std::default_delete<ArkNpcUnreachableTargetingManager>> m_pArkNpcUnreachableTargetingManager;
    std::unique_ptr<CArkPADialogManager,std::default_delete<CArkPADialogManager>> m_pArkPADialogManager;
    std::unique_ptr<ArkPatrolManager,std::default_delete<ArkPatrolManager>> m_pArkPatrolManager;
    std::unique_ptr<ArkPostEffectManager,std::default_delete<ArkPostEffectManager>> m_pArkPostEffectManager;
    std::unique_ptr<CArkProjectileGooNetworkManager,std::default_delete<CArkProjectileGooNetworkManager>> m_pArkProjectileGooNetworkManager;
    std::unique_ptr<CArkProjectileGooPhysicsManager,std::default_delete<CArkProjectileGooPhysicsManager>> m_pArkProjectileGooPhysicsManager;
    std::unique_ptr<CArkProjectilePoolManager,std::default_delete<CArkProjectilePoolManager>> m_pArkProjectilePoolManager;
    std::unique_ptr<ArkResponseManager,std::default_delete<ArkResponseManager>> m_pArkResponseManager;
    std::unique_ptr<ArkRetreatManager,std::default_delete<ArkRetreatManager>> m_pArkRetreatManager;
    std::unique_ptr<ArkRoomPerceptionManager,std::default_delete<ArkRoomPerceptionManager>> m_pArkRoomPerceptionManager;
    std::unique_ptr<ArkSpatialManager,std::default_delete<ArkSpatialManager>> m_pArkSpatialManager;
    std::unique_ptr<ArkTimeScaleManager,std::default_delete<ArkTimeScaleManager>> m_pArkTimeScaleManager;
    std::unique_ptr<ArkVisualPerceptionManager,std::default_delete<ArkVisualPerceptionManager>> m_pArkVisualPerceptionManager;
    std::unique_ptr<ArkWorldUIManager,std::default_delete<ArkWorldUIManager>> m_pArkWorldUIManager;
    class CScriptBind_Ark * m_pScriptBindArk;
    std::unique_ptr<CScriptBind_ArkBreakable,std::default_delete<CScriptBind_ArkBreakable>> m_pScriptBindArkBreakable;
    std::unique_ptr<CScriptBind_ArkItem,std::default_delete<CScriptBind_ArkItem>> m_pScriptBindArkItem;
    std::unique_ptr<CScriptBind_ArkFaction,std::default_delete<CScriptBind_ArkFaction>> m_pScriptBindArkFaction;
    std::unique_ptr<CScriptBind_ArkKiosk,std::default_delete<CScriptBind_ArkKiosk>> m_pScriptBindArkKiosk;
    std::unique_ptr<CScriptBind_ArkNpc,std::default_delete<CScriptBind_ArkNpc>> m_pScriptBindArkNpc;
    std::unique_ptr<CScriptBind_ArkRoster,std::default_delete<CScriptBind_ArkRoster>> m_pScriptBindArkRoster;
    std::unique_ptr<CScriptBind_ArkTurret,std::default_delete<CScriptBind_ArkTurret>> m_pScriptBindArkTurret;
    std::unique_ptr<CScriptBind_Inventory,std::default_delete<CScriptBind_Inventory>> m_pScriptBindInventory;
    std::unique_ptr<CScriptBind_ItemSystem,std::default_delete<CScriptBind_ItemSystem>> m_pScriptBindItemSystem;
    std::unique_ptr<CScriptBind_LightningArc,std::default_delete<CScriptBind_LightningArc>> m_pScriptBindLightningArc;
    class CryStringT<char> m_arkLoadLocation;
    class XmlNodeRef m_gameLevelToLevelSave;
    std::unique_ptr<ArkGame,std::default_delete<ArkGame>> m_pArkGame;
    std::unique_ptr<ArkActiveUserManagerBase,std::default_delete<ArkActiveUserManagerBase>> m_pActiveUserManager;
};

class SPlayerHealth {
public:
   float normal_regeneration_rateSP;
    float critical_health_thresholdSP;
    float critical_health_updateTimeSP;
    float normal_threshold_time_to_regenerateSP;
    float normal_regeneration_rateMP;
    float critical_health_thresholdMP;
    float fast_regeneration_rateMP;
    float slow_regeneration_rateMP;
    float normal_threshold_time_to_regenerateMP;
    int32_t enable_FallandPlay;
    int32_t collision_health_threshold;
    float fallDamage_SpeedSafe;
    float fallDamage_SpeedFatal;
    float fallSpeed_HeavyLand;
    float fallDamage_SpeedFatalArmor;
    float fallSpeed_HeavyLandArmor;
    float fallDamage_SpeedSafeArmorMP;
    float fallDamage_SpeedFatalArmorMP;
    float fallSpeed_HeavyLandArmorMP;
    float fallDamage_CurveAttackMP;
    float fallDamage_CurveAttack;
    int32_t fallDamage_health_threshold;
    int32_t debug_FallDamage;
    int32_t enableNewHUDEffect;
    int32_t minimalHudEffect;
};

class IAntiCheatManager {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class CProfileOptions {
public:
};

class SAICollisions {
public:
   float minSpeedForFallAndPlay;
    float minMassForFallAndPlay;
    float dmgFactorWhenCollidedByObject;
    int32_t showInLog;
};



class SVisTablePriority {
public:
   class SVisTableEntry * visInfo;
    short priority;
    short visIndex;
};

class ArkExclusiveActionFilter {
public:
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
    class CryStringT<char> m_filterName;
    class CryStringT<char> m_actionMap;
    std::vector<CCryName,std::allocator<CCryName>> m_filteredActionIds;
    std::vector<CCryName,std::allocator<CCryName>> m_allowedActionIds;
};

class CScriptBind_Item {
public:
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
    class ISystem * m_pSystem;
    class IGameFramework * m_pGameFW;
    class SmartScriptTable m_stats;
    class SmartScriptTable m_params;
};



class IScriptSystem {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};



class SDeferredLinetestBuffer {
public:
   class SDeferredLinetestReceiver m_deferredLinetestReceivers[5];
    short m_numLinetestsCurrentlyProcessing;
};

class CPlayerVisTable {
public:
   class SDeferredLinetestBuffer m_linetestBuffers[2];
    class SVisTableEntry m_visTableEntries[128];
    class SVisTablePriority m_visTablePriorities[5];
    class SIgnoreEntity m_globalIgnoreEntities[8];
    short m_numUsedVisTableEntries;
    short m_numLinetestsThisFrame;
    unsigned char m_currentNumIgnoreEntities;
    unsigned char m_currentBufferTarget;
    unsigned char m_currentBufferProcessing;
};

class CGameMechanismManager {
public:
   class CGameMechanismBase * m_firstMechanism;
};

class CListenerSet<IUIControlSchemeListener*> {
public:
   std::vector<CListenerSet<IUIControlSchemeListener*>::ListenerRecord,std::allocator<CListenerSet<IUIControlSchemeListener*>::ListenerRecord>> m_listeners;
    uint64_t m_activeNotifications;
    bool m_cleanupRequired;
    bool m_freeMemOnCleanup;
};

class IGameFramework {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class SCrySessionID {
public:
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

class SGameReleaseConstantCVars {
public:
   undefined field0_0x0;
};





class SActorInstanceLuaCache {
public:
   class SLuaCache_ActorProperties* pProperties;
};

class CGameCache {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    std::map<IEntityClass*,CGameCache::SActorClassLuaCache,std::less<IEntityClass*>,std::allocator<std::pair<IEntityClass*const,CGameCache::SActorClassLuaCache>>> m_ActorClassLuaCache;
    std::map<uint32_t,CGameCache::SActorInstanceLuaCache,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,CGameCache::SActorInstanceLuaCache>>> m_ActorInstanceLuaCache;
    class SActorInstanceLuaCache m_PlayerInstanceLuaCache;
    std::map<uint32_t,ICharacterInstance*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,ICharacterInstance*>>> m_editorCharacterFileModelCache[3];
    std::map<CGameCache::STextureKey,ITexture*,CGameCache::STextureKey::compare,std::allocator<std::pair<CGameCache::STextureKeyconst,ITexture*>>> m_textureCache;
    std::map<uint32_t,IMaterial*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,IMaterial*>>> m_materialCache;
    std::map<uint32_t,IStatObj*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,IStatObj*>>> m_statiObjectCache;
    class CGameCharacterDBAs m_characterDBAs;
    class IActorSystem * m_pActorSystem;
};

class CMovementTransitionsSystem {
public:
   std::vector<CMovementTransitions*,std::allocator<CMovementTransitions*>> m_entityTransitions;
};

class SJumpAirControl {
public:
   float air_control_scale;
    float air_resistance_scale;
    float air_inertia_scale;
};

class CItemAnimationDBAManager {
public:
   std::vector<std::pair<SharedString::CSharedString,CItemAnimationDBAManager::SItemDBAInfo>,std::allocator<std::pair<SharedString::CSharedString,CItemAnimationDBAManager::SItemDBAInfo>>> m_inUseDBAs;
    std::vector<std::pair<SharedString::CSharedString,CItemAnimationDBAManager::SItemDBAInfo>,std::allocator<std::pair<SharedString::CSharedString,CItemAnimationDBAManager::SItemDBAInfo>>> m_preloadedDBASlots;
};


class ICVar {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class ITelemetryCollector {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class CItemMaterialAndTextureCache {
public:
   std::map<uint32_t,ITexture*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,ITexture*>>> m_cachedTextures;
    std::map<uint32_t,IMaterial*,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,IMaterial*>>> m_cachedMaterials;
};

class CScriptBind_GameRules {
public:
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
    class SmartScriptTable m_players;
    class SmartScriptTable m_teamplayers;
    class SmartScriptTable m_spawnlocations;
    class SmartScriptTable m_spectatorlocations;
    class SmartScriptTable m_spawngroups;
    class ISystem * m_pSystem;
    class IGameFramework * m_pGameFW;
};



class SSpectacularKillCVars {
public:
   float maxDistanceError;
    float minTimeBetweenKills;
    float minTimeBetweenSameKills;
    float minKillerToTargetDotProduct;
    float maxHeightBetweenActors;
    float sqMaxDistanceFromPlayer;
    int32_t debug;
};

class CItemResourceCache {
public:
   class CItemGeometryCache m_itemGeometryCache;
    class CItemGeometryCache m_ammoGeometryCache;
    class CItemParticleEffectCache m_particleEffectCache;
    class CItemMaterialAndTextureCache m_materialsAndTextureCache;
    class CItemAnimationDBAManager m_1pDBAManager;
    class CItemPrefetchCHRManager m_pfCHRManager;
	std::set<IEntityClassconst*, std::less<IEntityClassconst*>, std::allocator<IEntityClassconst*>> m_cachedClasses;
};

class SItemStrings {
public:
   class CSharedString nw;
    class CSharedString left_item_attachment;
    class CSharedString right_item_attachment;
    class CSharedString bottom;
    class CSharedString barrel;
    class CSharedString scope;
    class CSharedString ammo;
};

class CAdvantagePointOccupancyControl {
public:
   std::map<uint32_t,Vec3_tpl<float>,std::less<uint32_t>,std::allocator<std::pair<const uint32_t,Vec3_tpl<float>>>> m_occupiedAdvantagePoints;
};

class CGameAISystem {
public:
   std::vector<IGameAIModule*,std::allocator<IGameAIModule*>> m_modules;
    class CAdvantagePointOccupancyControl m_advantagePointOccupancyControl;
    class DeathManager * m_pDeathManager;
    enum State m_state;
    class CAICorpseManager * m_pCorpsesManager;
};

class IMaterial {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    unsigned char m_ucDefautMappingAxis;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    float m_fDefautMappingScale;
};

class SPlayerMovement {
public:
   float nonCombat_heavy_weapon_speed_scale;
    float nonCombat_heavy_weapon_sprint_scale;
    float nonCombat_heavy_weapon_strafe_speed_scale;
    float nonCombat_heavy_weapon_sneak_speed_scale;
    float power_sprint_targetFov;
    float ground_timeInAirToFall;
    float speedScale;
    float strafe_SpeedScale;
    float sprint_SpeedScale;
    float sneak_SpeedScale;
    int32_t sprintStamina_debug;
    float mp_slope_speed_multiplier_uphill;
    float mp_slope_speed_multiplier_downhill;
    float mp_slope_speed_multiplier_minHill;
};



class CScriptBind_Ark {
public:
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
    class ISystem * m_pSystem;
    class IRenderer * m_pRenderer;
};





class CUIManager {
public:
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
    uint32_t m_soundListener;
    bool m_bRegistered;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    class CProfileOptions * m_pOptions;
    enum EControlScheme m_curControlScheme;
    enum EControlScheme m_actualControlScheme;
    int32_t m_lastDeviceIndices[4];
    class CListenerSet<IUIControlSchemeListener*> m_controlSchemeListeners;
    std::map<CryStringT<char>,std::shared_ptr<IUIGameEventSystem>,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,std::shared_ptr<IUIGameEventSystem>>>> m_EventSystems;
    class SUIEventSenderDispatcher<enumCUIManager::EUIEvent> m_eventSender;
    class IUIEventSystem * m_pUIFunctions;
};

class CGameSharedParametersStorage {
public:
   class CItemResourceCache * m_pItemResourceCache;
    std::map<CryStringT<char>,IGameSharedParameters*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IGameSharedParameters*>>> m_itemParametersMap;
    std::map<CryStringT<char>,IGameSharedParameters*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IGameSharedParameters*>>> m_weaponParametersMap;
    std::set<SAimLookParameters,std::less<SAimLookParameters>,std::allocator<SAimLookParameters>> m_SAimLookParameters;
};

class SPostEffect {
public:
   float FilterGrain_Amount;
    float FilterRadialBlurring_Amount;
    float FilterRadialBlurring_ScreenPosX;
    float FilterRadialBlurring_ScreenPosY;
    float FilterRadialBlurring_Radius;
    float Global_User_ColorC;
    float Global_User_ColorM;
    float Global_User_ColorY;
    float Global_User_ColorK;
    float Global_User_Brightness;
    float Global_User_Contrast;
    float Global_User_Saturation;
    float Global_User_ColorHue;
};



class CTriStrip {
public:
   std::vector<SVF_P3F_C4B_T2F> m_vertices;
    std::vector<unsigned short> m_indices;
    int32_t m_firstVertex;
    undefined field3_0x34;
    undefined field4_0x35;
    undefined field5_0x36;
    undefined field6_0x37;
};

class CGameActions {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    class CCryName moveleft;
    class CCryName moveright;
    class CCryName moveforward;
    class CCryName moveback;
    class CCryName jump;
    class CCryName sneak;
    class CCryName sprint;
    class CCryName sprint_xi;
    class CCryName special;
    class CCryName quicksave;
    class CCryName loadLastSave;
    class CCryName rotateyaw;
    class CCryName rotatepitch;
    class CCryName rotaterollleft;
    class CCryName rotaterollright;
    class CCryName prone;
    class CCryName hmd_rotateyaw;
    class CCryName hmd_rotatepitch;
    class CCryName hmd_rotateroll;
    class CCryName flymode;
    class CCryName godmode;
    class CCryName toggleaidebugdraw;
    class CCryName togglepdrawhelpers;
    class CCryName toggledmode;
    class CCryName record_bookmark;
    class CCryName spectate_gen_spawn;
    class CCryName spectate_gen_nextmode;
    class CCryName spectate_gen_prevmode;
    class CCryName spectate_gen_skipdeathcam;
    class CCryName spectate_gen_nextcamera;
    class CCryName spectate_3rdperson_nextteammate;
    class CCryName spectate_3rdperson_prevteammate;
    class CCryName spectate_3rdperson_changeteammate_xi;
    class CCryName spectate_cctv_nextcam;
    class CCryName spectate_cctv_prevcam;
    class CCryName spectate_cctv_changecam_xi;
    class CCryName attack1;
    class CCryName attack1_xi;
    class CCryName attack2_xi;
    class CCryName attack1_cine;
    class CCryName attack2_cine;
    class CCryName reload;
    class CCryName modify;
    class CCryName nextweapon;
    class CCryName prevweapon;
    class CCryName nextitem;
    class CCryName previtem;
    class CCryName toggle_explosive;
    class CCryName toggle_weapon;
    class CCryName toggle_special;
    class CCryName drop;
    class CCryName toggle_grenade;
    class CCryName handgrenade;
    class CCryName xi_handgrenade;
    class CCryName stabilize;
    class CCryName toggle_flashlight;
    class CCryName play_audiolog;
    class CCryName debug;
    class CCryName zoom;
    class CCryName firemode;
    class CCryName weapon_change_firemode;
    class CCryName binoculars;
    class CCryName objectives;
    class CCryName grenade;
    class CCryName xi_grenade;
    class CCryName zoom_toggle;
    class CCryName zoom_in;
    class CCryName zoom_out;
    class CCryName invert_mouse;
    class CCryName flycam_movex;
    class CCryName flycam_movey;
    class CCryName flycam_moveup;
    class CCryName flycam_movedown;
    class CCryName flycam_speedup;
    class CCryName flycam_speeddown;
    class CCryName flycam_turbo;
    class CCryName flycam_rotateyaw;
    class CCryName flycam_rotatepitch;
    class CCryName flycam_setpoint;
    class CCryName flycam_play;
    class CCryName flycam_clear;
    class CCryName thirdperson;
    class CCryName preUse;
    class CCryName use;
    class CCryName itemPrePickup;
    class CCryName itemPickup;
    class CCryName lookAt;
    class CCryName ripout;
    class CCryName voice_chat_talk;
    class CCryName save;
    class CCryName load;
    class CCryName respawn;
    class CCryName xi_zoom;
    class CCryName xi_movex;
    class CCryName xi_movey;
    class CCryName xi_disconnect;
    class CCryName xi_rotateyaw;
    class CCryName xi_rotatepitch;
    class CCryName xi_v_rotateyaw;
    class CCryName xi_v_rotatepitch;
    class CCryName xi_v_movex;
    class CCryName xi_v_movey;
    class CCryName xi_v_accelerate;
    class CCryName xi_v_deccelerate;
    class CCryName xi_v_strafe;
    class CCryName xi_v_moveupdown;
    class CCryName move_overlay_enable;
    class CCryName move_overlay_disable;
    class CCryName move_overlay_weight;
    class CCryName move_overlay_x;
    class CCryName move_overlay_y;
    class CCryName hud_mousex;
    class CCryName hud_mousey;
    class CCryName hud_mouseclick;
    class CCryName hud_openchat;
    class CCryName hud_openteamchat;
    class CCryName hud_vote_for;
    class CCryName hud_vote_against;
    class CCryName scores;
    class CCryName mouse_wheel;
    class CCryName mouse_wheel_infiction_close;
    class CCryName v_changeseat1;
    class CCryName v_changeseat2;
    class CCryName v_changeseat3;
    class CCryName v_changeseat4;
    class CCryName v_changeseat5;
    class CCryName v_changeview;
    class CCryName v_viewoption;
    class CCryName v_zoom_in;
    class CCryName v_zoom_out;
    class CCryName heavyweaponremove;
    class CCryName v_attack1;
    class CCryName v_attack2;
    class CCryName v_lights;
    class CCryName v_horn;
    class CCryName v_exit;
    class CCryName v_rotateyaw;
    class CCryName v_rotatepitch;
    class CCryName v_moveforward;
    class CCryName v_moveback;
    class CCryName v_moveup;
    class CCryName v_movedown;
    class CCryName v_rotatedir;
    class CCryName v_turnleft;
    class CCryName v_turnright;
    class CCryName v_strafeleft;
    class CCryName v_straferight;
    class CCryName v_rollleft;
    class CCryName v_rollright;
    class CCryName v_pitchup;
    class CCryName v_pitchdown;
    class CCryName v_brake;
    class CCryName v_afterburner;
    class CCryName v_boost;
    class CCryName v_changeseat;
    class CCryName v_debug_1;
    class CCryName v_debug_2;
    class CCryName debug_ag_step;
    class CCryName tweakenter;
    class CCryName tweakup;
    class CCryName tweakdown;
    class CCryName tweakleft;
    class CCryName tweakright;
    class CCryName tweakincrement;
    class CCryName tweakdecrement;
    class CCryName menu_scoreboard_open;
    class CCryName menu_scoreboard_close;
    class CCryName skip_cutscene;
    class CCryName skip_loadingscreen;
    class CCryName skip_loadingscreen_switched;
    class CCryName menu_open_customizeweapon;
    class CCryName menu_close_customizeweapon;
    class CCryName menu_scrollup;
    class CCryName menu_scrolldown;
    class CCryName xi_menu_scrollup;
    class CCryName xi_menu_scrolldown;
    class CCryName menu_scrollleft;
    class CCryName menu_scrollright;
    class CCryName menu_fcommand1;
    class CCryName menu_fcommand2;
    class CCryName menu_switchtab_left;
    class CCryName menu_switchtab_right;
    class CCryName menu_switchpage_left;
    class CCryName menu_switchpage_right;
    class CCryName menu_up;
    class CCryName menu_down;
    class CCryName menu_left;
    class CCryName menu_right;
    class CCryName menu_map_zoomout;
    class CCryName menu_map_zoomin;
    class CCryName menu_map_pan_left;
    class CCryName menu_map_pan_right;
    class CCryName menu_map_pan_up;
    class CCryName menu_map_pan_down;
    class CCryName menu_map_floor_up;
    class CCryName menu_map_floor_down;
    class CCryName menu_map_center_to_player;
    class CCryName menu_map_reset_zoom;
    class CCryName menu_map_objective;
    class CCryName menu_show_completed_objectives;
    class CCryName menu_toggle_barrel;
    class CCryName menu_toggle_bottom;
    class CCryName menu_toggle_scope;
    class CCryName menu_toggle_ammo;
    class CCryName menu_confirm;
    class CCryName menu_back;
    class CCryName menu_dialog_cancel;
    class CCryName menu_exit;
    class CCryName menu_external_exit;
    class CCryName menu_xi_start;
    class CCryName menu_delete;
    class CCryName menu_apply;
    class CCryName menu_default;
    class CCryName menu_back_select;
    class CCryName menu_tab;
    class CCryName menu_rotatex;
    class CCryName menu_rotatey;
    class CCryName menu_use;
    class CCryName menu_examine;
    class CCryName autosort;
    class CCryName menu_drop;
    class CCryName menu_dismantle;
    class CCryName menu_qsopen;
    class CCryName menu_split;
    class CCryName menu_qs_down;
    class CCryName menu_qs_left;
    class CCryName menu_qs_right;
    class CCryName inventory_confirm;
    class CCryName menu_stick_up;
    class CCryName menu_stick_down;
    class CCryName menu_stick_left;
    class CCryName menu_stick_right;
    class CCryName menu_arrow_up;
    class CCryName menu_arrow_down;
    class CCryName menu_friends_open;
    class CCryName menu_take_stow;
    class CCryName menu_take_all;
    class CCryName menu_external_consume;
    class CCryName menu_inventory_prev;
    class CCryName menu_inventory_next;
    class CCryName menu_reset;
    class CCryName menu_assetpause;
    class CCryName menu_assetzoom;
    class CCryName menu_toggle_index_finger;
    class CCryName menu_toggle_middle_finger;
    class CCryName menu_toggle_ring_finger;
    class CCryName menu_toggle_ring_finger_switched;
    class CCryName menu_toggle_pink;
    class CCryName ui_toggle_pause;
    class CCryName ui_start_pause;
    class CCryName ui_up;
    class CCryName ui_down;
    class CCryName ui_left;
    class CCryName ui_right;
    class CCryName ui_click;
    class CCryName ui_back;
    class CCryName ui_confirm;
    class CCryName ui_reset;
    class CCryName ui_skip_video;
    class CCryName ui_toggle_debug;
    class CCryName minigame_decrypt_input_1;
    class CCryName minigame_decrypt_input_2;
    class CCryName minigame_decrypt_input_3;
    class CCryName minigame_decrypt_input_4;
    class CCryName minigame_decrypt_quit;
    class CCryName minigame_waveddr_lockon;
    class CCryName minigame_ingame_quit;
    class CCryName mannequin_debugai;
    class CCryName mannequin_debugplayer;
    class CCryName ai_debugCenterViewAgent;
    class CCryName mouse_enter_focusmode;
    class CCryName enter_focusmode;
    class CCryName mouse_execute_power_type1;
    class CCryName mouse_execute_power_type2;
    class CCryName controller_execute_power;
    class CCryName select_equipped_power;
    class CCryName mouse_cancel_focusmode_type1;
    class CCryName mouse_cancel_focusmode_type2;
    class CCryName controller_cancel_focusmode;
    class CCryName controller_cancel_psitargeting;
    class CCryName mouse_select_item;
    class CCryName controller_select_item;
    class CCryName mouse_cancel_select_item;
    class CCryName mouse_menu_rotate_yaw;
    class CCryName mouse_menu_rotate_pitch;
    class CCryName controller_left_menu_rotate_yaw;
    class CCryName controller_left_menu_rotate_pitch;
    class CCryName controller_right_menu_rotate_yaw;
    class CCryName controller_right_menu_rotate_pitch;
    class CCryName menu_rotate_up;
    class CCryName menu_rotate_down;
    class CCryName target_rotate_yaw;
    class CCryName target_rotate_pitch;
    class CCryName use_psi_item;
    class CCryName use_healing_item;
    class CCryName use_food_item;
    class CCryName use_armor_item;
    class CCryName psimode;
    class CCryName activate_psipower;
    class CCryName deactivate_psipower;
    class CCryName toggle_scope;
    class CCryName togglepda;
    class CCryName pdanextpage;
    class CCryName pdaprevpage;
    class CCryName toggleinventory;
    class CCryName toggleobjectives;
    class CCryName toggleabilities;
    class CCryName togglemap;
    class CCryName toggledata;
    class CCryName togglestatus;
    class CCryName equip_last_weapon;
    class CCryName increasetimedilation;
    class CCryName decreasetimedilation;
    class CCryName normaltimedilation;
    class CCryName xi_reticle_movex;
    class CCryName xi_reticle_movey;
    class CCryName specialUse;
    class CCryName viewTutorial;
    class CCryName carry;
    class CCryName leanleft;
    class CCryName leanright;
    class CCryName xi_recenter_worldui;
    class CCryName examination_back;
    class CCryName worldui_examine;
    class CCryName start_ether_duplicate;
    class CCryName hack_moveprompt_y;
    class CCryName hack_moveprompt_x;
    class CCryName hack_moveup;
    class CCryName hack_movedown;
    class CCryName hack_moveleft;
    class CCryName hack_moveright;
    class CCryName hack_final1;
    class CCryName hack_final2;
    class CCryName hack_final3;
    class CCryName hack_final4;
    class CCryName fire_turret;
    class CCryName mimic_swap_camera;
    class CCryName togglearkprofile;
    class CCryName editor_pause;
    class CCryName editor_resume;
    class CCryName reportbug;
    class CCryName openlog;
    class CCryName instakill;
    class CCryName scanner_lock_target;
    class CCryName scanner_exit_fanfare;
    class CCryName loot_navup;
    class CCryName loot_navdown;
    class CCryName loot_navright;
    class CCryName loot_navleft;
    class CCryName loot_search;
    class CCryName loot_scroll_up;
    class CCryName loot_scroll_down;
    class CCryName favorites_confirm;
    class CCryName favorites_cancel;
    class CCryName quickselect_left;
    class CCryName quickselect_right;
    class CCryName quickselect_down;
    class CCryName keypad0;
    class CCryName keypad1;
    class CCryName keypad2;
    class CCryName keypad3;
    class CCryName keypad4;
    class CCryName keypad5;
    class CCryName keypad6;
    class CCryName keypad7;
    class CCryName keypad8;
    class CCryName keypad9;
    class CCryName backspace;
    class CCryName numkey0;
    class CCryName numkey1;
    class CCryName numkey2;
    class CCryName numkey3;
    class CCryName numkey4;
    class CCryName numkey5;
    class CCryName numkey6;
    class CCryName numkey7;
    class CCryName numkey8;
    class CCryName numkey9;
    class IActionFilter * m_pFilterNoMove;
    class IActionFilter * m_pFilterNoMouse;
    class IActionFilter * m_pFilterTutorialNoMove;
    class IActionFilter * m_pFilterNoWeaponCustomization;
    class IActionFilter * m_pFilterNoFireModeSwitch;
    class IActionFilter * m_pFilterWarningPopup;
    class IActionFilter * m_pFilterMindControlMenu;
    class IActionFilter * m_pFilterFreezeTime;
    class IActionFilter * m_pFilterHostMigration;
    class IActionFilter * m_pFilterMPPreGameFreeze;
    class IActionFilter * m_pFilterMPRadio;
    class IActionFilter * m_pFilterMPChat;
    class IActionFilter * m_pFilterCutscene;
    class IActionFilter * m_pFilterCutsceneNoPlayer;
    class IActionFilter * m_pFilterCutsceneTrain;
    class IActionFilter * m_pFilterCutscenePlayerMoving;
    class IActionFilter * m_pFilterNoConnectivity;
    class IActionFilter * m_pFilterTweakMenu;
    class IActionFilter * m_pFilterIngameMenu;
    class IActionFilter * m_pFilterScoreboard;
    class IActionFilter * m_pFilterStrikePointer;
    class IActionFilter * m_pFilterUseKeyOnly;
    class IActionFilter * m_pFilterInfictionMenu;
    class IActionFilter * m_pFilterMPWeaponCustomizationMenu;
    class IActionFilter * m_pFilterLedgeGrab;
    class IActionFilter * m_pFilterVault;
    class IActionFilter * m_pFilterItemPickup;
    class IActionFilter * m_pFilterNotYetSpawned;
    class IActionFilter * m_pFilterButtonMashingSequence;
    class IActionFilter * m_pFilterUIOnly;
    class IActionFilter * m_pFilterPsiPowerShift;
    class IActionFilter * m_pFilterNoCameraMove;
    class IActionFilter * m_pFilterPsiCameraZoom;
    class IActionFilter * m_pFilterChargeWeapon;
    class IActionFilter * m_pFilterFocusMode;
    class IActionFilter * m_pFilterPsiTargeting;
    class IActionFilter * m_pFilterNoteUI;
    class IActionFilter * m_pFilterNeuromodIntro;
    class IActionFilter * m_pFilterDeathMenu;
    class IActionFilter * m_pFilterWrenchChargeAttack;
    class IActionFilter * m_pFilterNoReload;
    class IActionFilter * m_pFilterPsiPowerMimic;
    class IActionFilter * m_pFilterPsiPowerSmokeForm;
    class IActionFilter * m_pFilterGenderSelect;
    class IActionFilter * m_pFilterDoorPry;
    class ArkExclusiveActionFilter m_filterQuickSelect;
    class ArkExclusiveActionFilter m_filterInventoryPreview;
    class ArkExclusiveActionFilter m_filterScope;
    class ArkExclusiveActionFilter m_filterPsychoscope;
    class ArkExclusiveActionFilter m_filterNpcFocus;
    class ArkExclusiveActionFilter m_filterKeypadInteraction;
    class ArkExclusiveActionFilter m_filterPsiScanningLock;
};



class CModInfoManager {
public:
	std::vector<ModInfo> m_mods;
    std::vector<ModInfo> m_modLevels;
    uint32_t m_modCheckSum;
    bool m_bRunningMod;
};

class SPlayerPickAndThrow {
public:
   int32_t debugDraw;
    int32_t useProxies;
    int32_t cloakedEnvironmentalWeaponsAllowed;
    float maxOrientationCorrectionTime;
    float orientationCorrectionTimeMult;
    float environmentalWeaponObjectImpulseScale;
    float environmentalWeaponImpulseScale;
    float environmentalWeaponHitConeInDegrees;
    float minRequiredThrownEnvWeaponHitVelocity;
    float awayFromPlayerImpulseRatio;
    float environmentalWeaponDesiredRootedGrabAnimDuration;
    float environmentalWeaponDesiredGrabAnimDuration;
    float environmentalWeaponDesiredPrimaryAttackAnimDuration;
    float environmentalWeaponDesiredComboAttackAnimDuration;
    float environmentalWeaponUnrootedPickupTimeMult;
    float environmentalWeaponThrowAnimationSpeed;
    float environmentalWeaponFlippedImpulseOverrideMult;
    float environmentalWeaponFlipImpulseThreshold;
    float environmentalWeaponLivingToArticulatedImpulseRatio;
    int32_t enviromentalWeaponUseThrowInitialFacingOveride;
    float environmentalWeaponMinViewClamp;
    float environmentalWeaponViewLerpZOffset;
    float environmentalWeaponViewLerpSmoothTime;
    float complexMelee_snap_angle_limit;
    float complexMelee_lerp_target_speed;
    float objectImpulseLowMassThreshold;
    float objectImpulseLowerScaleLimit;
    float comboInputWindowSize;
    float minComboInputWindowDurationInSecs;
    float impactNormalGroundClassificationAngle;
    float impactPtValidHeightDiffForImpactStick;
    float reboundAnimPlaybackSpeedMultiplier;
    int32_t environmentalWeaponSweepTestsEnabled;
    float chargedThrowAutoAimDistance;
    float chargedThrowAutoAimConeSize;
    float chargedThrowAutoAimDistanceHeuristicWeighting;
    float chargedThrowAutoAimAngleHeuristicWeighting;
    float chargedThrowAimHeightOffset;
    int32_t chargedthrowAutoAimEnabled;
    int32_t intersectionAssistDebugEnabled;
    int32_t intersectionAssistDeleteObjectOnEmbed;
    float intersectionAssistCollisionsPerSecond;
    float intersectionAssistTimePeriod;
    float intersectionAssistTranslationThreshold;
    float intersectionAssistPenetrationThreshold;
};

class SCVars {
public:
   class SGameReleaseConstantCVars m_releaseConstants;
    float cl_fov;
    float cl_hfov;
    float cl_mp_fov_scalar;
    float cl_tpvDist;
    float cl_tpvYaw;
    float cl_sensitivity;
    float cl_sensitivityController;
    float cl_sensitivityControllerMP;
    float cl_reticleSensitivityController;
    int32_t cl_invertMouse;
    int32_t cl_invertController;
    int32_t cl_sneakToggle;
    int32_t cl_worldUIExaminationToggle;
    int32_t cl_sprintToggle;
    int32_t cl_debugSwimming;
    int32_t cl_logAsserts;
    int32_t cl_zoomToggle;
    float cl_motionBlurVectorScale;
    float cl_motionBlurVectorScaleSprint;
    int32_t g_enableMPDoubleTapGrenadeSwitch;
    class ICVar * ca_GameControlledStrafingPtr;
    float cl_shallowWaterSpeedMulPlayer;
    float cl_shallowWaterSpeedMulAI;
    float cl_shallowWaterDepthLo;
    float cl_shallowWaterDepthHi;
    float cl_speedToBobFactor;
    float cl_bobAmount;
    float cl_rollAmount;
    float cl_bobWidth;
    float cl_bobHeight;
    float cl_bobSprintMultiplier;
    float cl_bobVerticalMultiplier;
    float cl_bobMaxHeight;
    float cl_strafeHorzScale;
    float g_highlightingMaxDistanceToHighlightSquared;
    float g_highlightingMovementDistanceToUpdateSquared;
    float g_highlightingTimeBetweenForcedRefresh;
    float g_ledgeGrabClearHeight;
    float g_ledgeGrabMovingledgeExitVelocityMult;
    float g_vaultMinHeightDiff;
    float g_vaultMinAnimationSpeed;
    int32_t g_cloakFlickerOnRun;
    int32_t kc_useAimAdjustment;
    float kc_aimAdjustmentMinAngle;
    float kc_precacheTimeStartPos;
    float kc_precacheTimeWeaponModels;
    int32_t g_useQuickGrenadeThrow;
    int32_t g_debugWeaponOffset;
    int32_t g_MicrowaveBeamStaticObjectMaxChunkThreshold;
    float i_fastSelectMultiplier;
    float cl_idleBreaksDelayTime;
    int32_t cl_postUpdateCamera;
    int32_t p_collclassdebug;
    float pl_cameraTransitionTime;
    float pl_cameraTransitionTimeLedgeGrabIn;
    float pl_cameraTransitionTimeLedgeGrabOut;
    float pl_slideCameraFactor;
    float cl_slidingBlurRadius;
    float cl_slidingBlurAmount;
    float cl_slidingBlurBlendSpeed;
    int32_t sv_votingTimeout;
    int32_t sv_votingCooldown;
    int32_t sv_votingEnable;
    int32_t sv_votingMinVotes;
    float sv_votingRatio;
    float sv_votingTeamRatio;
    float sv_votingBanTime;
    int32_t sv_input_timeout;
    class ICVar * sv_aiTeamName;
    class ICVar * performance_profile_logname;
    int32_t g_infiniteAmmoTutorialMode;
    int32_t i_lighteffects;
    int32_t i_particleeffects;
    int32_t i_rejecteffects;
    int32_t i_grenade_showTrajectory;
    float i_grenade_trajectory_resolution;
    float i_grenade_trajectory_dashes;
    float i_grenade_trajectory_gaps;
    int32_t i_grenade_trajectory_useGeometry;
    int32_t i_ironsight_while_jumping_mp;
    int32_t i_ironsight_while_falling_mp;
    float i_ironsight_falling_unzoom_minAirTime;
    float i_weapon_customisation_transition_time;
    int32_t i_highlight_dropped_weapons;
    float i_laser_hitPosOffset;
    float pl_inputAccel;
    int32_t pl_debug_energyConsumption;
    int32_t pl_debug_pickable_items;
    float pl_useItemHoldTime;
    int32_t pl_autoPickupItemsWhenUseHeld;
    float pl_autoPickupMinTimeBetweenPickups;
    int32_t pl_debug_projectileAimHelper;
    float pl_nanovision_timeToRecharge;
    float pl_nanovision_timeToDrain;
    float pl_nanovision_minFractionToUse;
    float pl_refillAmmoDelay;
    int32_t pl_spawnCorpseOnDeath;
    int32_t pl_doLocalHitImpulsesMP;
    int32_t kc_enable;
    int32_t kc_debug;
    int32_t kc_debugStressTest;
    int32_t kc_debugVictimPos;
    int32_t kc_debugWinningKill;
    int32_t kc_debugSkillKill;
    int32_t kc_memStats;
    int32_t kc_maxFramesToPlayAtOnce;
    int32_t kc_cameraCollision;
    int32_t kc_showHighlightsAtEndOfGame;
    int32_t kc_enableWinningKill;
    int32_t kc_canSkip;
    float kc_length;
    float kc_skillKillLength;
    float kc_bulletSpeed;
    float kc_bulletHoverDist;
    float kc_bulletHoverTime;
    float kc_bulletHoverTimeScale;
    float kc_bulletPostHoverTimeScale;
    float kc_bulletTravelTimeScale;
    float kc_bulletCamOffsetX;
    float kc_bulletCamOffsetY;
    float kc_bulletCamOffsetZ;
    float kc_bulletRiflingSpeed;
    float kc_bulletZoomDist;
    float kc_bulletZoomTime;
    float kc_bulletZoomOutRatio;
    float kc_kickInTime;
    float kc_projectileDistance;
    float kc_projectileHeightOffset;
    float kc_largeProjectileDistance;
    float kc_largeProjectileHeightOffset;
    float kc_projectileVictimHeightOffset;
    float kc_projectileMinimumVictimDist;
    float kc_smoothing;
    float kc_grenadeSmoothingDist;
    float kc_cameraRaiseHeight;
    float kc_resendThreshold;
    float kc_chunkStreamTime;
    float g_multikillTimeBetweenKills;
    float g_flushed_timeBetweenGrenadeBounceAndSkillKill;
    float g_gotYourBackKill_targetDistFromFriendly;
    float g_gotYourBackKill_FOVRange;
    float g_guardian_maxTimeSinceLastDamage;
    float g_defiant_timeAtLowHealth;
    float g_defiant_lowHealthFraction;
    float g_intervention_timeBetweenZoomedAndKill;
    float g_blinding_timeBetweenFlashbangAndKill;
    float g_blinding_flashbangRecoveryDelayFrac;
    float g_neverFlagging_maxMatchTimeRemaining;
    float g_combinedFire_maxTimeBetweenWeapons;
    float g_fovToRotationSpeedInfluence;
    int32_t dd_maxRMIsPerFrame;
    float dd_waitPeriodBetweenRMIBatches;
    int32_t g_debugSpawnPointsRegistration;
    int32_t g_debugSpawnPointValidity;
    float g_randomSpawnPointCacheTime;
    int32_t g_detachCamera;
    int32_t g_moveDetachedCamera;
    float g_detachedCameraMoveSpeed;
    float g_detachedCameraRotateSpeed;
    float g_detachedCameraTurboBoost;
    int32_t g_detachedCameraDebug;
    int32_t g_difficultyLevel;
    int32_t g_difficultyLevelLowestPlayed;
    float g_flashBangMinSpeedMultiplier;
    float g_flashBangSpeedMultiplierFallOffEase;
    float g_flashBangNotInFOVRadiusFraction;
    float g_flashBangMinFOVMultiplier;
    int32_t g_flashBangFriends;
    int32_t g_flashBangSelf;
    float g_friendlyLowerItemMaxDistance;
    int32_t g_holdObjectiveDebug;
    int32_t g_gameRayCastQuota;
    int32_t g_gameIntersectionTestQuota;
    int32_t g_STAPCameraAnimation;
    float g_reticleYPercentage;
    float g_ExplosionImpulseScale;
    int32_t g_debugaimlook;
    float g_playerLowHealthThreshold;
    float g_playerMidHealthThreshold;
    int32_t g_SurvivorOneVictoryConditions_watchLvl;
    int32_t g_SimpleEntityBasedObjective_watchLvl;
    int32_t g_CTFScoreElement_watchLvl;
    int32_t g_KingOfTheHillObjective_watchLvl;
    float g_HoldObjective_secondsBeforeStartForSpawn;
    int32_t g_CombiCaptureObjective_watchLvl;
    int32_t g_CombiCaptureObjective_watchTerminalSignalPlayers;
    int32_t g_disable_OpponentsDisconnectedGameEnd;
    int32_t g_victoryConditionsDebugDrawResolution;
    int32_t g_restartWhenPrematchFinishes;
    float g_predator_marineRedCrosshairDelay;
    int32_t sv_pacifist;
    int32_t g_devDemo;
    int32_t g_bulletPenetrationDebug;
    float g_bulletPenetrationDebugTimeout;
    int32_t g_fpDbaManagementEnable;
    int32_t g_fpDbaManagementDebug;
    int32_t g_charactersDbaManagementEnable;
    int32_t g_charactersDbaManagementDebug;
    int32_t g_thermalVisionDebug;
    float g_droppedItemVanishTimer;
    float g_droppedHeavyWeaponVanishTimer;
    int32_t g_corpseManager_maxNum;
    float g_corpseManager_timeoutInSeconds;
    float g_explosion_materialFX_raycastLength;
    int32_t g_ec_enable;
    float g_ec_radiusScale;
    float g_ec_volume;
    float g_ec_extent;
    int32_t g_ec_removeThreshold;
    float g_radialBlur;
    float g_timelimit;
    float g_timelimitextratime;
    float g_roundScoreboardTime;
    float g_roundStartTime;
    int32_t g_roundlimit;
    float g_friendlyfireratio;
    int32_t g_revivetime;
    int32_t g_minplayerlimit;
    float g_hostMigrationResumeTime;
    int32_t g_hostMigrationUseAutoLobbyMigrateInPrivateGames;
    int32_t g_minPlayersForRankedGame;
    float g_gameStartingMessageTime;
    int32_t g_mpRegenerationRate;
    int32_t g_mpHeadshotsOnly;
    int32_t g_mpNoVTOL;
    int32_t g_mpNoEnvironmentalWeapons;
    int32_t g_allowCustomLoadouts;
    int32_t g_allowFatalityBonus;
    float g_spawnPrecacheTimeBeforeRevive;
    float g_autoReviveTime;
    float g_spawn_timeToRetrySpawnRequest;
    float g_spawn_recentSpawnTimer;
    float g_forcedReviveTime;
    int32_t g_numLives;
    int32_t g_autoAssignTeams;
    float g_maxHealthMultiplier;
    int32_t g_mp_as_DefendersMaxHealth;
    float g_xpMultiplyer;
    int32_t g_allowExplosives;
    int32_t g_forceWeapon;
    int32_t g_allowSpectators;
    int32_t g_infiniteCloak;
    int32_t g_allowWeaponCustomisation;
    class ICVar * g_forceHeavyWeapon;
    class ICVar * g_forceLoadoutPackage;
    int32_t g_switchTeamAllowed;
    int32_t g_switchTeamRequiredPlayerDifference;
    int32_t g_switchTeamUnbalancedWarningDifference;
    float g_switchTeamUnbalancedWarningTimer;
    int32_t g_tk_punish;
    int32_t g_tk_punish_limit;
    int32_t g_debugNetPlayerInput;
    int32_t g_debugCollisionDamage;
    int32_t g_debugHits;
    int32_t g_suppressHitSanityCheckWarnings;
    int32_t g_drawLeaks;
    int32_t g_transcribeAutosaveFrequency;
    int32_t g_enableLanguageSelectionMenu;
    int32_t g_multiplayerDefault;
    int32_t g_multiplayerModeOnly;
    int32_t g_EPD;
    int32_t g_frontEndRequiredEPD;
    int32_t g_EnableDevMenuOptions;
    int32_t g_frontEndUnicodeInput;
    int32_t g_DisableMenuButtons;
    int32_t g_EnablePersistantStatsDebugScreen;
    int32_t g_craigNetworkDebugLevel;
    int32_t g_presaleUnlock;
    int32_t g_dlcPurchaseOverwrite;
    int32_t g_MatchmakingVersion;
    int32_t g_MatchmakingBlock;
    int32_t g_enableInitialLoadoutScreen;
    int32_t g_ProcessOnlineCallbacks;
    float g_gameRules_startTimerLength;
    float g_gameRules_postGame_HUDMessageTime;
    float g_gameRules_postGame_Top3Time;
    float g_gameRules_postGame_ScoreboardTime;
    int32_t g_gameRules_startTimerMinPlayers;
    int32_t g_gameRules_startTimerMinPlayersPerTeam;
    float g_gameRules_startTimerPlayersRatio;
    float g_gameRules_startTimerOverrideWait;
    int32_t g_gameRules_preGame_StartSpawnedFrozen;
    int32_t g_debug_fscommand;
    int32_t g_skipIntro;
    int32_t g_skipAfterLoadingScreen;
    int32_t g_goToCampaignAfterTutorial;
    int32_t g_aiCorpses_Enable;
    int32_t g_aiCorpses_DebugDraw;
    int32_t g_aiCorpses_MaxCorpses;
    float g_aiCorpses_DelayTimeToSwap;
    float g_aiCorpses_CullPhysicsDistance;
    float g_aiCorpses_ForceDeleteDistance;
    int32_t g_scoreLimit;
    int32_t g_scoreLimitOverride;
    float g_spawn_explosiveSafeDist;
    int32_t g_logPrimaryRound;
    int32_t g_server_region;
    int32_t g_enableInitialLoginSilent;
    float g_dataRefreshFrequency;
    int32_t g_maxGameBrowserResults;
    int32_t g_inventoryNoLimits;
    int32_t g_inventoryWeaponCapacity;
    int32_t g_inventoryExplosivesCapacity;
    int32_t g_inventoryGrenadesCapacity;
    int32_t g_inventorySpecialCapacity;
    int32_t g_loadoutServerControlled;
    class ICVar * pl_debug_filter;
    int32_t pl_debug_vistable;
    int32_t pl_debug_movement;
    int32_t pl_debug_jumping;
    int32_t pl_debug_aiming;
    int32_t pl_debug_aiming_input;
    int32_t pl_debug_view;
    int32_t pl_debug_hit_recoil;
    int32_t pl_debug_look_poses;
    int32_t pl_renderInNearest;
    int32_t pl_aim_assistance_enabled;
    int32_t pl_aim_assistance_disabled_atDifficultyLevel;
    int32_t pl_aim_acceleration_enabled;
    float pl_aim_cloaked_multiplier;
    float pl_aim_near_lookat_target_distance;
    int32_t pl_targeting_debug;
    int32_t pl_switchTPOnKill;
    int32_t pl_stealthKill_allowInMP;
    int32_t pl_stealthKill_uncloakInMP;
    int32_t pl_stealthKill_debug;
    float pl_stealthKill_aimVsSpineLerp;
    float pl_stealthKill_maxVelocitySquared;
    int32_t pl_slealth_cloakinterference_onactionMP;
    int32_t pl_stealthKill_usePhysicsCheck;
    int32_t pl_stealthKill_useExtendedRange;
    float pl_stealth_shotgunDamageCap;
    float pl_shotgunDamageCap;
    float pl_freeFallDeath_cameraAngle;
    float pl_freeFallDeath_fadeTimer;
    float pl_fall_intensity_multiplier;
    float pl_fall_intensity_max;
    float pl_fall_time_multiplier;
    float pl_fall_time_max;
    float pl_fall_intensity_hit_multiplier;
    float pl_TacticalScanDuration;
    float pl_TacticalScanDurationMP;
    float pl_TacticalTaggingDuration;
    float pl_TacticalTaggingDurationMP;
    float controller_power_curve;
    float controller_multiplier_z;
    float controller_multiplier_x;
    float controller_full_turn_multiplier_x;
    float controller_full_turn_multiplier_z;
    int32_t ctrlr_corner_smoother;
    int32_t ctrlr_corner_smoother_debug;
    int32_t ctrlr_OUTPUTDEBUGINFO;
    float pl_stampTimeout;
    int32_t pl_stampTier;
    float pl_jump_maxTimerValue;
    float pl_jump_baseTimeAddedPerJump;
    float pl_jump_currentTimeMultiplierOnJump;
    float pl_jump_quickPressThresh;
    int32_t pl_showClimbIndicator;
    int32_t pl_boostedMelee_allowInMP;
    float pl_velocityInterpAirControlScale;
    int32_t pl_velocityInterpSynchJump;
    int32_t pl_debugInterpolation;
    float pl_velocityInterpAirDeltaFactor;
    float pl_velocityInterpPathCorrection;
    int32_t pl_velocityInterpAlwaysSnap;
    int32_t pl_adjustJumpAngleWithFloorNormal;
    float pl_netAimLerpFactor;
    float pl_netSerialiseMaxSpeed;
    int32_t pl_serialisePhysVel;
    float pl_clientInertia;
    float pl_fallHeight;
    float pl_legs_colliders_dist;
    float pl_legs_colliders_scale;
    float g_manualFrameStepFrequency;
    class SPowerSprintParams pl_power_sprint;
    class SJumpAirControl pl_jump_control;
    class SPlayerHealth pl_health;
    class SPlayerMovement pl_movement;
    class SPlayerLedgeClamber pl_ledgeClamber;
    class SPlayerLadder pl_ladderControl;
    class SPlayerPickAndThrow pl_pickAndThrow;
    class SPlayerSlideControl pl_sliding_control;
    class SPlayerSlideControl pl_sliding_control_mp;
    class SPlayerEnemyRamming pl_enemy_ramming;
    class SAICollisions AICollisions;
    class SPlayerMelee pl_melee;
    class SAltNormalization aim_altNormalization;
    class SCaptureTheFlagParams mp_ctfParams;
    class SExtractionParams mp_extractionParams;
    class SPredatorParams mp_predatorParams;
    int32_t g_FootstepSoundsFollowEntity;
    int32_t g_FootstepSoundsDebug;
    float g_footstepSoundMaxDistanceSq;
    float pl_swimBackSpeedMul;
    float pl_swimSideSpeedMul;
    float pl_swimVertSpeedMul;
    float pl_swimNormalSprintSpeedMul;
    int32_t pl_swimAlignArmsToSurface;
    int32_t pl_drownDamage;
    float pl_drownTime;
    float pl_drownRecoveryTime;
    float pl_drownDamageInterval;
    int32_t pl_mike_debug;
    int32_t pl_mike_maxBurnPoints;
    int32_t pl_impulseEnabled;
    float pl_impulseDuration;
    int32_t pl_impulseLayer;
    float pl_impulseFullRecoilFactor;
    float pl_impulseMaxPitch;
    float pl_impulseMaxTwist;
    float pl_impulseCounterFactor;
    int32_t pl_ZeroGRollFixInputMode;
    int32_t pl_ZeroGRollMode;
    int32_t pl_ZeroGRollPivotOffset;
    float pl_ExplosionUpImpulseScale;
    float pl_PsiTargetingDepthCamSpeed;
    float pl_fictionalTimeScale;
    int32_t pl_unlimitedPsi;
    int32_t pl_forceFlashlight;
    int32_t pl_infiniteFlashlight;
    int32_t pl_useFemaleModel;
    float pl_cameraNearZ;
    int32_t pl_enableTraumas;
    int32_t g_assertWhenVisTableNotUpdatedForNumFrames;
    float gl_time;
    float gl_waitForBalancedGameTime;
    int32_t hud_ContextualHealthIndicator;
    float hud_objectiveIcons_flashTime;
    int32_t hud_faderDebug;
    int32_t hud_ctrlZoomMode;
    int32_t hud_aspectCorrection;
    float hud_canvas_width_adjustment;
    int32_t hud_colorLine;
    int32_t hud_colorOver;
    int32_t hud_colorText;
    float hud_defaultObjectiveTaskOpaqueDistance;
    float hud_objectiveTaskFadeDistance;
    float hud_objectiveTaskTextFadeDistance;
    float hud_logVisibleDuration;
    int32_t hud_subtitles;
    int32_t hud_tutorials;
    int32_t hud_playstationContext;
    int32_t hud_forceControllerGlyphs;
    int32_t hud_startPaused;
    int32_t hud_allowMouseInput;
    int32_t hud_reticleSetting;
    int32_t hud_showOptionalHud;
    int32_t hud_showPlayerState;
    int32_t hud_showHitFeedback;
    int32_t hud_showObjectiveMarkers;
    int32_t hud_showEnemyMarkers;
    int32_t hud_showPsiScanPrompt;
    int32_t hud_showHudLog;
    int32_t hud_showLegends;
    int32_t hud_showInteractPrompt;
    int32_t hud_showEnemyHealthBar;
    int32_t hud_psychoPsycho;
    int32_t hud_hide;
    int32_t menu3D_enabled;
    int32_t g_flashrenderingduringloading;
    int32_t g_levelfadein_levelload;
    int32_t g_levelfadein_quickload;
    float aim_assistMinDistance;
    float aim_assistMaxDistance;
    float aim_assistMaxDistanceTagged;
    float aim_assistFalloffDistance;
    float aim_assistInputForFullFollow_Ironsight;
    float aim_assistMinTurnScale;
    float aim_assistSlowFalloffStartDistance;
    float aim_assistSlowDisableDistance;
    float aim_assistSlowThresholdOuter;
    float aim_assistSlowDistanceModifier;
    float aim_assistSlowStartFadeinDistance;
    float aim_assistSlowStopFadeinDistance;
    float aim_assistStrength;
    float aim_assistSnapRadiusScale;
    float aim_assistSnapRadiusTaggedScale;
    float aim_assistStrength_IronSight;
    float aim_assistMaxDistance_IronSight;
    float aim_assistMinTurnScale_IronSight;
    float aim_assistStrength_SniperScope;
    float aim_assistMaxDistance_SniperScope;
    float aim_assistMinTurnScale_SniperScope;
    class ICVar * i_debuggun_1;
    class ICVar * i_debuggun_2;
    float slide_spread;
    int32_t i_debug_projectiles;
    int32_t i_debug_weaponActions;
    int32_t i_debug_spread;
    int32_t i_debug_recoil;
    int32_t i_auto_turret_target;
    int32_t i_auto_turret_target_tacshells;
    int32_t i_debug_zoom_mods;
    int32_t i_debug_turrets;
    int32_t i_debug_sounds;
    int32_t i_debug_mp_flowgraph;
    int32_t i_flashlight_has_shadows;
    int32_t i_flashlight_has_fog_volume;
    int32_t i_debug_itemparams_memusage;
    int32_t i_debug_weaponparams_memusage;
    float i_failedDetonation_speedMultiplier;
    float i_failedDetonation_lifetime;
    float i_hmg_detachWeaponAnimFraction;
    float i_hmg_impulseLocalDirection_x;
    float i_hmg_impulseLocalDirection_y;
    float i_hmg_impulseLocalDirection_z;
    int32_t g_displayIgnoreList;
    int32_t g_buddyMessagesIngame;
    int32_t g_enableFriendlyAIHits;
    int32_t g_enableFriendlyPlayerHits;
    int32_t g_mpAllSeeingRadar;
    int32_t g_mpAllSeeingRadarSv;
    int32_t g_mpDisableRadar;
    int32_t g_mpNoEnemiesOnRadar;
    int32_t g_mpHatsBootsOnRadar;
    int32_t g_spectate_TeamOnly;
    int32_t g_spectate_DisableManual;
    int32_t g_spectate_DisableDead;
    int32_t g_spectate_DisableFree;
    int32_t g_spectate_DisableFollow;
    float g_spectate_skipInvalidTargetAfterTime;
    float g_spectate_follow_orbitYawSpeedDegrees;
    int32_t g_spectate_follow_orbitAlsoRotateWithTarget;
    float g_spectate_follow_orbitMouseSpeedMultiplier;
    float g_spectate_follow_orbitMinPitchRadians;
    float g_spectate_follow_orbitMaxPitchRadians;
    int32_t g_deathCam;
    int32_t g_spectatorOnly;
    float g_spectatorOnlySwitchCooldown;
    int32_t g_forceIntroSequence;
    int32_t g_IntroSequencesEnabled;
    class SDeathCamSPParams g_deathCamSP;
    float g_tpdeathcam_timeOutKilled;
    float g_tpdeathcam_timeOutSuicide;
    float g_tpdeathcam_lookDistWhenNoKiller;
    float g_tpdeathcam_camDistFromPlayerStart;
    float g_tpdeathcam_camDistFromPlayerEnd;
    float g_tpdeathcam_camDistFromPlayerMin;
    float g_tpdeathcam_camHeightTweak;
    float g_tpdeathcam_camCollisionRadius;
    float g_tpdeathcam_maxBumpCamUpOnCollide;
    float g_tpdeathcam_zVerticalLimit;
    float g_tpdeathcam_testLenIncreaseRestriction;
    float g_tpdeathcam_collisionEpsilon;
    float g_tpdeathcam_directionalFocusGroundTestLen;
    float g_tpdeathcam_camSmoothSpeed;
    float g_tpdeathcam_maxTurn;
    int32_t g_killercam_disable;
    float g_killercam_displayDuration;
    float g_killercam_dofBlurAmount;
    float g_killercam_dofFocusRange;
    int32_t g_killercam_canSkip;
    float g_postkill_minTimeForDeathCamAndKillerCam;
    float g_postkill_splitScaleDeathCam;
    int32_t g_useHitSoundFeedback;
    int32_t g_useSkillKillSoundEffects;
    int32_t g_hasWindowFocus;
    int32_t g_displayPlayerDamageTaken;
    int32_t g_displayDbgText_hud;
    int32_t g_displayDbgText_silhouettes;
    int32_t g_displayDbgText_plugins;
    int32_t g_displayDbgText_pmv;
    int32_t g_displayDbgText_actorState;
    int32_t g_spawn_vistable_numLineTestsPerFrame;
    int32_t g_spawn_vistable_numAreaTestsPerFrame;
    int32_t g_showShadowChar;
    int32_t g_infiniteAmmo;
    float g_persistantStats_gamesCompletedFractionNeeded;
    int32_t g_animatorDebug;
    int32_t g_hideArms;
    int32_t g_debugSmokeGrenades;
    float g_smokeGrenadeRadius;
    float g_empOverTimeGrenadeLife;
    int32_t g_kickCarDetachesEntities;
    float g_kickCarDetachStartTime;
    float g_kickCarDetachEndTime;
    int32_t g_playerUsesDedicatedInput;
    int32_t watch_enabled;
    float watch_text_render_start_pos_x;
    float watch_text_render_start_pos_y;
    float watch_text_render_size;
    float watch_text_render_lineSpacing;
    float watch_text_render_fxscale;
    int32_t autotest_enabled;
    class ICVar * autotest_state_setup;
    int32_t autotest_quit_when_done;
    int32_t autotest_verbose;
    int32_t designer_warning_enabled;
    int32_t designer_warning_level_resources;
    int32_t g_teamDifferentiation;
    class SPostEffect g_postEffect;
    int32_t g_gameFXSystemDebug;
    int32_t g_gameFXLightningProfile;
    int32_t g_DebugDrawPhysicsAccess;
    int32_t ai_DebugVisualScriptErrors;
    int32_t ai_EnablePressureSystem;
    int32_t ai_DebugPressureSystem;
    int32_t ai_DebugAggressionSystem;
    int32_t ai_DebugBattleFront;
    int32_t ai_DebugSearch;
    int32_t ai_DebugDeferredDeath;
    float ai_CloakingDelay;
    float ai_CompleteCloakDelay;
    float ai_UnCloakingDelay;
    int32_t ai_HazardsDebug;
    int32_t ai_SquadManager_DebugDraw;
    float ai_SquadManager_MaxDistanceFromSquadCenter;
    float ai_SquadManager_UpdateTick;
    float ai_ProximityToHostileAlertnessIncrementThresholdDistance;
    int32_t ai_invulnerable;
    int32_t ai_cantdie;
    int32_t ai_forceEnableNightmareManager;
    int32_t g_actorViewDistRatio;
    int32_t g_playerLodRatio;
    float g_itemsLodRatioScale;
    float g_itemsViewDistanceRatioScale;
    int32_t g_hitDeathReactions_enable;
    int32_t g_hitDeathReactions_useLuaDefaultFunctions;
    int32_t g_hitDeathReactions_disable_ai;
    int32_t g_hitDeathReactions_debug;
    int32_t g_hitDeathReactions_disableRagdoll;
    int32_t g_hitDeathReactions_usePrecaching;
    int32_t g_hitDeathReactions_logReactionAnimsOnLoading;
    int32_t g_hitDeathReactions_streaming;
    class SSpectacularKillCVars g_spectacularKill;
    int32_t g_movementTransitions_enable;
    int32_t g_movementTransitions_log;
    int32_t g_movementTransitions_debug;
    float g_maximumDamage;
    float g_instantKillDamageThreshold;
    int32_t g_flyCamLoop;
    int32_t g_dummyPlayersFire;
    int32_t g_dummyPlayersMove;
    int32_t g_dummyPlayersChangeWeapon;
    float g_dummyPlayersJump;
    int32_t g_dummyPlayersRespawnAtDeathPosition;
    int32_t g_dummyPlayersCommitSuicide;
    int32_t g_dummyPlayersShowDebugText;
    float g_dummyPlayersMinInTime;
    float g_dummyPlayersMaxInTime;
    float g_dummyPlayersMinOutTime;
    float g_dummyPlayersMaxOutTime;
    class ICVar * g_dummyPlayersGameRules;
    int32_t g_dummyPlayersRanked;
    int32_t g_muzzleFlashCull;
    float g_muzzleFlashCullDistance;
    int32_t g_rejectEffectVisibilityCull;
    float g_rejectEffectCullDistance;
    int32_t g_mpCullShootProbablyHits;
    float g_cloakRefractionScale;
    float g_cloakBlendSpeedScale;
    int32_t g_telemetry_onlyInGame;
    int32_t g_telemetry_drawcall_budget;
    int32_t g_telemetry_memory_display;
    int32_t g_telemetry_memory_size_sp;
    int32_t g_telemetry_memory_size_mp;
    int32_t g_telemetry_gameplay_enabled;
    int32_t g_telemetry_gameplay_save_to_disk;
    int32_t g_telemetry_gameplay_gzip;
    int32_t g_telemetry_gameplay_copy_to_global_heap;
    int32_t g_telemetryEnabledSP;
    float g_telemetrySampleRatePerformance;
    float g_telemetrySampleRateBandwidth;
    float g_telemetrySampleRateMemory;
    float g_telemetrySampleRateSound;
    float g_telemetry_xp_event_send_interval;
    float g_telemetry_mp_upload_delay;
    char * g_telemetryTags;
    char * g_telemetryConfig;
    int32_t g_telemetry_serialize_method;
    int32_t g_telemetryDisplaySessionId;
    char * g_telemetryEntityClassesToExport;
    int32_t g_modevarivar_proHud;
    int32_t g_modevarivar_disableKillCam;
    int32_t g_modevarivar_disableSpectatorCam;
    char * g_dataCentreConfigStr;
    char * g_downloadMgrDataCentreConfigStr;
    int32_t g_ignoreDLCRequirements;
    float sv_netLimboTimeout;
    float g_idleKickTime;
    int32_t g_useOnlineServiceForDedicated;
    int32_t g_enablePoolCache;
    int32_t g_setActorModelFromLua;
    int32_t g_loadPlayerModelOnLoad;
    int32_t g_enableActorLuaCache;
    int32_t g_enableSlimCheckpoints;
    float g_mpLoaderScreenMaxTime;
    float g_mpLoaderScreenMaxTimeSoftLimit;
    int32_t g_mpKickableCars;
    float g_forceItemRespawnTimer;
    float g_defaultItemRespawnTimer;
    float g_updateRichPresenceInterval;
    int32_t g_useNetSyncToSpeedUpRMIs;
    class ICVar * g_presaleURL;
    class ICVar * g_messageOfTheDay;
    class ICVar * g_serverImageUrl;
    class SAIPerceptionCVars ai_perception;
    class SAIThreatModifierCVars ai_threatModifiers;
    int32_t pl_showInactiveTasks;
    float pl_maxRegen;
    float pl_taskLabelShowAngle;
    int32_t pl_enableFPIK;
    float pl_incrementCameraYaw;
    int32_t g_debugTimerEvents;
    int32_t beta_debugShift;
    int32_t pl_playerVoiceOn;
    int32_t pl_playerVoiceFemale;
    int32_t pl_danielleRobo;
    int32_t s_DrawDialogAudioLatency;
    int32_t pl_traumaDebug;
    int32_t g_shownightmareheat;
    int32_t g_debugdistraction;
    int32_t g_debugDistractionCurrentAI;
    int32_t wpn_firstTimePickup;
    float g_arkLightDisableDistance;
};

class IConsole {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class ISystem {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class IRenderer {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class CLightningRenderNode {
public:
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
    class CTriStrip m_triStrip;
    std::vector<CLightningRenderNode::CSegment> m_segments;
    class Vec3_tpl<float> m_emmitterPosition;
    class Vec3_tpl<float> m_receiverPosition;
    class SPointData m_pointData;
    float m_deviationMult;
    undefined field78_0xfc;
    undefined field79_0xfd;
    undefined field80_0xfe;
    undefined field81_0xff;
    class SLightningParams * m_pLightningDesc;
    class IMaterial* m_pMaterial;
    class AABB m_aabb;
    bool m_dirtyBBox;
    undefined field86_0x129;
    undefined field87_0x12a;
    undefined field88_0x12b;
    undefined field89_0x12c;
    undefined field90_0x12d;
    undefined field91_0x12e;
    undefined field92_0x12f;
};

class IUIEventSystem {
public:
   undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class CParameterGameEffect {
public:
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
    class CryFixedArray<CParameterGameEffect::SSaturationData,4> m_saturationExecutionData;
};

