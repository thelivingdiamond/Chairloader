// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryAction/IItemSystem.h>
#include <Prey/CryAction/IViewSystem.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryLobby/ICryStats.h>
#include <Prey/CryNetwork/INetwork.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/IGameRules.h>
#include <Prey/GameDll/ark/ArkGameRules.h>
#include <Prey/GameDll/gamerulestypes.h>
#include <_unknown/CryHashStringId.h>
#include <_unknown/IHostMigrationEventListener.h>
#include <_unknown/SExplosionContainer.h>

class CCorpseManager;
class CCryActor;
class CCryName;
class CPlayer;
enum EChatMessageType;
enum EEntityAspects;
enum EGameOverReason;
enum EGameResourceType;
enum ESystemEvent;
enum ETextMessageType;
struct ExplosionInfo;
struct HitInfo;
struct IActor;
struct IActorSystem;
struct IAnimSequence;
struct ICharacterInstance;
struct IConsole;
struct IConsoleCmdArgs;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IEntitySystem;
struct IGameFramework;
struct IGameObject;
class IGameRulesClientConnectionListener;
class IGameRulesClientScoreListener;
class IGameRulesDamageHandlingModule;
class IGameRulesKillListener;
class IGameRulesModuleRMIListener;
class IGameRulesRevivedListener;
class IGameRulesRoundsListener;
class IGameRulesSpawningModule;
class IGameRulesStateModule;
class IGameRulesTeamChangedListener;
struct IGameplayRecorder;
struct IHitListener;
struct ILoadGame;
struct IMaterialManager;
struct INetAtSyncItem;
struct INetChannel;
struct IParticleEffect;
struct IPhysicalEntity;
struct ISaveGame;
struct IScriptSystem;
struct IScriptTable;
struct ISerializableInfo;
struct ISystem;
class ITexture;
struct RayCastResult;
struct SActionEvent;
struct SCameraParams;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
struct SGameObjectExtensionRMI;
struct SGameRulesListener;
struct SGameRulesPlayerStat;
struct SGameRulesScoreInfo;
struct SHostMigrationInfo;
struct SInputEvent;
struct SPathFollowingAttachToPathParameters;
struct SProjectileExplosionParams;
struct SProjectileExplosionParams_Impact;
struct pe_explosion;

// CGameRules
// Header:  Prey/GameDll/GameRules.h
class CGameRules
	: public CGameObjectExtensionHelper<CGameRules,IGameRules,53>
	, public IViewSystemListener
	, public IGameFrameworkListener
	, public IHostMigrationEventListener
	, public IEntityEventListener
	, public IInputEventListener
	, public ISystemEventListener
{ // Size=14056 (0x36E8)
public:
	enum ERadarTagReason
	{
		eRTR_General = 0,
		eRTR_Tagging = 1,
		eRTR_RadarOnly = 2,
		eRTR_OnShot = 3,
		eRTR_OnShoot = 4,
		eRTR_Last = 5,
	};

	enum EHeadShotType
	{
		eHeadShotType_None = 0,
		eHeadShotType_Head = 1,
		eHeadShotType_Helmet = 2,
	};

	enum ELocalPlayerHitFeedbackChannel
	{
		eLocalPlayerHitFeedbackChannel_Undefined = 0,
		eLocalPlayerHitFeedbackChannel_HUD = 1,
		eLocalPlayerHitFeedbackChannel_2DSound = 2,
	};

	enum class #unnamed_enum_k_rptfgm_none
	{
		k_rptfgm_none = 0,
		k_rptfgm_standard = 1,
		k_rptfgm_marines = 2,
		k_rptfgm_hunter = 4,
		k_rptfgm_hunter_marine = 8,
	};

	enum eThreatRating
	{
		eFriendly = 0,
		eHostile = 1,
	};

	enum EPrematchState
	{
		ePS_Prematch = 0,
		ePS_PrematchWaitingForPlayers = 1,
		ePS_Countdown = 2,
		ePS_Match = 3,
		ePS_None = 4,
		ePS_Last = 4,
	};

	enum class #unnamed_enum_NUM_FRAMES_CHECKING_MOVIES_SYNQ
	{
		NUM_FRAMES_CHECKING_MOVIES_SYNQ = 20,
		FRAME_TIME_FOR_MOVIES_SYNQ_TRESHOLD = 400,
	};

	// CGameRules::EHitType
	// Header:  Prey/GameDll/GameRules.h
	struct EHitType
	{ // Size=1 (0x1)
		enum class type
		{
			Invalid = 0,
			Melee = 1,
			Collision = 2,
			Frag = 3,
			Explosion = 4,
			StealthKill = 5,
			SilentMelee = 6,
			Punish = 7,
			PunishFall = 8,
			Mike_Burn = 9,
			Fall = 10,
			Normal = 11,
			Fire = 12,
			Bullet = 13,
			Stamp = 14,
			EnvironmentalThrow = 15,
			meleeLeft = 16,
			meleeRight = 17,
			meleeKick = 18,
			meleeUppercut = 19,
			Electricity = 20,
			StealthKill_Maximum = 21,
			EventDamage = 22,
			VTOLExplosion = 23,
			EnvironmentalMelee = 24,
			EnvironmentalAura = 25,
			Unreserved = 26,
		};

	};

	// CGameRules::EHitTypeFlag
	// Header:  Prey/GameDll/GameRules.h
	struct EHitTypeFlag
	{ // Size=1 (0x1)
		enum class #unnamed_enum_None
		{
			None = 0,
			HIT_TYPES_FLAGS_neg1 = -1,
			BITINDEX_IsMeleeAttack = 0,
			BITINDEX_Server = 1,
			BITINDEX_ClientSelfHarm = 2,
			BITINDEX_ValidationRequired = 3,
			BITINDEX_CustomValidationRequired = 4,
			BITINDEX_SinglePlayerOnly = 5,
			BITINDEX_AllowPostDeathDamage = 6,
			BITINDEX_IgnoreHeadshots = 7,
			HIT_TYPES_FLAGS_numBits = 8,
			IsMeleeAttack = 1,
			Server = 2,
			ClientSelfHarm = 4,
			ValidationRequired = 8,
			CustomValidationRequired = 16,
			SinglePlayerOnly = 32,
			AllowPostDeathDamage = 64,
			IgnoreHeadshots = 128,
		};

	};

	// CGameRules::SMigratingPlayerInfo
	// Header:  Prey/GameDll/GameRules.h
	struct SMigratingPlayerInfo
	{ // Size=72 (0x48)
		CryFixedStringT<32> m_originalName;
		unsigned m_originalEntityId;
		unsigned m_channelID;
		bool m_inUse;

	#if 0
		SMigratingPlayerInfo();
		void SetChannelID(uint16_t _arg0_);
		void SetData(const char* _arg0_, unsigned _arg1_, int _arg2_, const Vec3& _arg3_, const Ang3& _arg4_, float _arg5_);
		void Reset();
		bool InUse();
	#endif
	};

	// CGameRules::StringParams
	// Header:  Prey/GameDll/GameRules.h
	struct StringParams
	{ // Size=8 (0x8)
		string str;

	#if 0
		StringParams();
		StringParams(const char* _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ChatMessageParams
	// Header:  Prey/GameDll/GameRules.h
	struct ChatMessageParams
	{ // Size=32 (0x20)
		uint8_t type;
		unsigned sourceId;
		unsigned targetId;
		string msg;
		bool onlyTeam;

	#if 0
		ChatMessageParams();
		ChatMessageParams(EChatMessageType _arg0_, unsigned _arg1_, unsigned _arg2_, const char* _arg3_, bool _arg4_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ForbiddenAreaWarningParams
	// Header:  Prey/GameDll/GameRules.h
	struct ForbiddenAreaWarningParams
	{ // Size=8 (0x8)
		int timer;
		bool active;

	#if 0
		ForbiddenAreaWarningParams();
		ForbiddenAreaWarningParams(bool _arg0_, int _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::UInt8Param
	// Header:  Prey/GameDll/GameRules.h
	struct UInt8Param
	{ // Size=1 (0x1)
		uint8_t param;

	#if 0
		UInt8Param();
		UInt8Param(uint8_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::TextMessageParams
	// Header:  Prey/GameDll/GameRules.h
	struct TextMessageParams
	{ // Size=56 (0x38)
		uint8_t type;
		string msg;
		uint8_t nparams;
		string params[4];

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		TextMessageParams();
		TextMessageParams(ETextMessageType _arg0_, const char* _arg1_);
		TextMessageParams(ETextMessageType _arg0_, const char* _arg1_, const char* _arg2_, const char* _arg3_, const char* _arg4_, const char* _arg5_);
		bool AddParam(const char* _arg0_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::TextMessageParams* const _this, TSerialize ser)>(0x1854A70);
	};

	// CGameRules::NetConsoleCommandParams
	// Header:  Prey/GameDll/GameRules.h
	struct NetConsoleCommandParams
	{ // Size=8 (0x8)
		string m_commandString;

	#if 0
		NetConsoleCommandParams();
		NetConsoleCommandParams(const char* _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SetTeamParams
	// Header:  Prey/GameDll/GameRules.h
	struct SetTeamParams
	{ // Size=8 (0x8)
		int teamId;
		unsigned entityId;

	#if 0
		SetTeamParams();
		SetTeamParams(unsigned _arg0_, int _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ChangeTeamParams
	// Header:  Prey/GameDll/GameRules.h
	struct ChangeTeamParams
	{ // Size=12 (0xC)
		unsigned entityId;
		int teamId;
		bool onlyIfUnassigned;

	#if 0
		ChangeTeamParams();
		ChangeTeamParams(unsigned _arg0_, int _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SpectatorModeParams
	// Header:  Prey/GameDll/GameRules.h
	struct SpectatorModeParams
	{ // Size=16 (0x10)
		unsigned entityId;
		uint8_t mode;
		unsigned targetId;
		bool resetAll;
		bool force;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		SpectatorModeParams();
		SpectatorModeParams(unsigned _arg0_, uint8_t _arg1_, unsigned _arg2_, bool _arg3_, bool _arg4_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::SpectatorModeParams* const _this, TSerialize ser)>(0x18549C0);
	};

	// CGameRules::RenameEntityParams
	// Header:  Prey/GameDll/GameRules.h
	struct RenameEntityParams
	{ // Size=16 (0x10)
		unsigned entityId;
		string name;

	#if 0
		RenameEntityParams();
		RenameEntityParams(unsigned _arg0_, const char* _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::PostInitParams
	// Header:  Prey/GameDll/GameRules.h
	struct PostInitParams
	{ // Size=12 (0xC)
		int timeSinceGameStarted;
		unsigned uSecurity;
		bool firstBlood;

	#if 0
		PostInitParams();
		PostInitParams(const int& _arg0_, bool _arg1_, unsigned _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SetGameTimeParams
	// Header:  Prey/GameDll/GameRules.h
	struct SetGameTimeParams
	{ // Size=8 (0x8)
		CTimeValue time;

	#if 0
		SetGameTimeParams();
		SetGameTimeParams(const CTimeValue& _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SPlayerEndGameStatsParams
	// Header:  Prey/GameDll/GameRules.h
	struct SPlayerEndGameStatsParams
	{ // Size=260 (0x104)
		// CGameRules::SPlayerEndGameStatsParams::SPlayerEndGameStats
		// Header:  Prey/GameDll/GameRules.h
		struct SPlayerEndGameStats
		{ // Size=16 (0x10)
			unsigned m_playerId;
			int m_points;
			uint16_t m_kills;
			uint16_t m_assists;
			uint16_t m_deaths;
			uint16_t m_skillPoints;

		#if 0
			SPlayerEndGameStats();
			void SerializeWith(TSerialize _arg0_);
		#endif
		};

		static constexpr const int k_maxPlayerStats = 16;
		CGameRules::SPlayerEndGameStatsParams::SPlayerEndGameStats m_playerStats[16];
		int m_numPlayerStats;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		SPlayerEndGameStatsParams();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::SPlayerEndGameStatsParams* const _this, TSerialize ser)>(0x1333E90);
	};

	// CGameRules::VictoryTeamParams
	// Header:  Prey/GameDll/GameRules.h
	struct VictoryTeamParams
	{ // Size=464 (0x1D0)
		CGameRules::SPlayerEndGameStatsParams m_playerStats;
		int winningTeamId;
		uint8_t reason;
		int team1Score;
		int team2Score;
		int drawLevel;
		SDrawResolutionData level1;
		SDrawResolutionData level2;
		unsigned killedEntity;
		unsigned shooterEntity;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		VictoryTeamParams();
		VictoryTeamParams(int _arg0_, uint8_t _arg1_, int _arg2_, int _arg3_, int _arg4_, SDrawResolutionData _arg5_, SDrawResolutionData _arg6_, unsigned _arg7_, unsigned _arg8_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::VictoryTeamParams* const _this, TSerialize ser)>(0x1854BD0);
	};

	// CGameRules::VictoryPlayerParams
	// Header:  Prey/GameDll/GameRules.h
	struct VictoryPlayerParams
	{ // Size=276 (0x114)
		CGameRules::SPlayerEndGameStatsParams m_playerStats;
		unsigned playerId;
		unsigned killedEntity;
		unsigned shooterEntity;
		uint8_t reason;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		VictoryPlayerParams();
		VictoryPlayerParams(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, uint8_t _arg3_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::VictoryPlayerParams* const _this, TSerialize ser)>(0x1854B20);
	};

	// CGameRules::TwoEntityParams
	// Header:  Prey/GameDll/GameRules.h
	struct TwoEntityParams
	{ // Size=8 (0x8)
		unsigned entityId;
		unsigned entityId2;

	#if 0
		TwoEntityParams();
		TwoEntityParams(unsigned _arg0_, unsigned _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ServerReviveParams
	// Header:  Prey/GameDll/GameRules.h
	struct ServerReviveParams
	{ // Size=8 (0x8)
		unsigned entityId;
		uint16_t index;

	#if 0
		ServerReviveParams();
		ServerReviveParams(unsigned _arg0_, uint16_t _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ServerSpectatorParams
	// Header:  Prey/GameDll/GameRules.h
	struct ServerSpectatorParams
	{ // Size=8 (0x8)
		unsigned entityId;
		uint8_t state;
		uint8_t mode;

	#if 0
		ServerSpectatorParams();
		ServerSpectatorParams(unsigned _arg0_, uint8_t _arg1_, uint8_t _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::EntityParams
	// Header:  Prey/GameDll/GameRules.h
	struct EntityParams
	{ // Size=4 (0x4)
		unsigned entityId;

	#if 0
		EntityParams();
		EntityParams(unsigned _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SSuccessfulFlashBangParams
	// Header:  Prey/GameDll/GameRules.h
	struct SSuccessfulFlashBangParams
	{ // Size=12 (0xC)
		unsigned shooterId;
		float time;
		float damage;

	#if 0
		SSuccessfulFlashBangParams();
		SSuccessfulFlashBangParams(unsigned _arg0_, float _arg1_, float _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ScoreChangeParams
	// Header:  Prey/GameDll/GameRules.h
	struct ScoreChangeParams
	{ // Size=16 (0x10)
		unsigned m_killedEntityId;
		int16_t m_changeToScore;
		int8_t m_type;
		EXPReason m_reason;
		int m_currentTeamScore;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		ScoreChangeParams();
		ScoreChangeParams(unsigned _arg0_, int16_t _arg1_, int8_t _arg2_, EXPReason _arg3_, int _arg4_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::ScoreChangeParams* const _this, TSerialize ser)>(0x1854900);
	};

	// CGameRules::NoParams
	// Header:  Prey/GameDll/GameRules.h
	struct NoParams
	{ // Size=1 (0x1)
	#if 0
		NoParams();
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CGameRules::SpawnGroupParams
	// Header:  Prey/GameDll/GameRules.h
	struct SpawnGroupParams
	{ // Size=4 (0x4)
		unsigned entityId;

	#if 0
		SpawnGroupParams();
		SpawnGroupParams(unsigned _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::TempRadarTaggingParams
	// Header:  Prey/GameDll/GameRules.h
	struct TempRadarTaggingParams
	{ // Size=16 (0x10)
		unsigned shooterId;
		unsigned targetId;
		float m_time;
		CGameRules::ERadarTagReason m_reason;

	#if 0
		TempRadarTaggingParams();
		TempRadarTaggingParams(unsigned _arg0_, unsigned _arg1_, float _arg2_, CGameRules::ERadarTagReason _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ProcessHitParams
	// Header:  Prey/GameDll/GameRules.h
	struct ProcessHitParams
	{ // Size=28 (0x1C)
		Vec3 dir;
		unsigned shooterId;
		unsigned weaponId;
		float damage;
		uint16_t projectileClassId;
		uint8_t hitTypeId;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		ProcessHitParams();
		ProcessHitParams(unsigned _arg0_, unsigned _arg1_, const Vec3& _arg2_, float _arg3_, uint16_t _arg4_, uint8_t _arg5_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::ProcessHitParams* const _this, TSerialize ser)>(0x18543D0);
	};

	// CGameRules::TSynqMoviesParams
	// Header:  Prey/GameDll/GameRules.h
	struct TSynqMoviesParams
	{ // Size=24 (0x18)
		// CGameRules::TSynqMoviesParams::TPlayingMovie
		// Header:  Prey/GameDll/GameRules.h
		struct TPlayingMovie
		{ // Size=16 (0x10)
			string m_Name;
			float m_fTime;
		};

		std::vector<CGameRules::TSynqMoviesParams::TPlayingMovie> m_aPlayingMovies;

	#if 0
		TSynqMoviesParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::TFinishedOnLoadMoviesParams
	// Header:  Prey/GameDll/GameRules.h
	struct TFinishedOnLoadMoviesParams
	{ // Size=24 (0x18)
		std::vector<string> m_aMovies;

	#if 0
		TFinishedOnLoadMoviesParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::EquipmentLoadoutParams
	// Header:  Prey/GameDll/GameRules.h
	struct EquipmentLoadoutParams
	{ // Size=16 (0x10)
		uint8_t m_contents[10];
		uint8_t m_modelIndex;
		uint8_t m_loadoutIndex;
		unsigned m_weaponAttachmentFlags;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		EquipmentLoadoutParams();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::EquipmentLoadoutParams* const _this, TSerialize ser)>(0x1853CA0);
	};

	// CGameRules::SModuleRMIEntityParams
	// Header:  Prey/GameDll/GameRules.h
	struct SModuleRMIEntityParams
	{ // Size=12 (0xC)
		unsigned m_entityId;
		int m_listenerIndex;
		uint8_t m_data;

	#if 0
		SModuleRMIEntityParams();
		SModuleRMIEntityParams(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void Set(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SModuleRMITwoEntityParams
	// Header:  Prey/GameDll/GameRules.h
	struct SModuleRMITwoEntityParams
	{ // Size=16 (0x10)
		unsigned m_entityId1;
		unsigned m_entityId2;
		int m_listenerIndex;
		int m_data;

	#if 0
		SModuleRMITwoEntityParams();
		SModuleRMITwoEntityParams(int _arg0_, unsigned _arg1_, unsigned _arg2_, int _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SModuleRMIEntityTimeParams
	// Header:  Prey/GameDll/GameRules.h
	struct SModuleRMIEntityTimeParams
	{ // Size=24 (0x18)
		CTimeValue m_time;
		unsigned m_entityId;
		int m_listenerIndex;
		int m_data;

	#if 0
		SModuleRMIEntityTimeParams();
		SModuleRMIEntityTimeParams(int _arg0_, unsigned _arg1_, int _arg2_, const CTimeValue& _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SHostMigrationClientRequestParams
	// Header:  Prey/GameDll/GameRules.h
	struct SHostMigrationClientRequestParams
	{ // Size=44 (0x2C)
		Quat m_environmentalWeaponRot;
		Vec3 m_environmentalWeaponPos;
		Vec3 m_environmentalWeaponVel;
		unsigned m_environmentalWeaponId;

	#if 0
		SHostMigrationClientRequestParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SHostMigrationClientControlledParams
	// Header:  Prey/GameDll/GameRules.h
	struct SHostMigrationClientControlledParams
	{ // Size=96 (0x60)
		// CGameRules::SHostMigrationClientControlledParams::SAmmoParams
		// Header:  Prey/GameDll/GameRules.h
		struct SAmmoParams
		{ // Size=16 (0x10)
			IEntityClass* m_pAmmoClass;
			int m_count;
		};

		Quat m_viewQuat;
		Vec3 m_position;
		Vec3 m_velocity;
		Vec3 m_aimDirection;
		CGameRules::SHostMigrationClientControlledParams::SAmmoParams* m_pAmmoParams;
		IEntityClass* m_pHolsteredItemClass;
		IEntityClass* m_pSelectedItemClass;
		int m_numAmmoParams;
		int m_numExpectedItems;
		bool m_hasValidVelocity;
		bool m_bInVisorMode;
		bool m_doneEnteredGame;
		bool m_doneSetAmmo;

	#if 0
		SHostMigrationClientControlledParams();
		~SHostMigrationClientControlledParams();
		bool IsDone();
	#endif
	};

	// CGameRules::SPredictionParams
	// Header:  Prey/GameDll/GameRules.h
	struct SPredictionParams
	{ // Size=4 (0x4)
		int predictionHandle;

	#if 0
		SPredictionParams();
		SPredictionParams(int _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SMidMigrationJoinParams
	// Header:  Prey/GameDll/GameRules.h
	struct SMidMigrationJoinParams
	{ // Size=8 (0x8)
		int m_state;
		float m_timeSinceStateChanged;

	#if 0
		SMidMigrationJoinParams();
		SMidMigrationJoinParams(int _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SModuleRMISvClientActionParams
	// Header:  Prey/GameDll/GameRules.h
	struct SModuleRMISvClientActionParams
	{ // Size=12 (0xC)
		enum #unnamed_enum_eACT_NULL
		{
			eACT_NULL = 0,
			eACT_HelperCarry_Pickup = 1,
			eACT_HelperCarry_Drop = 2,
			eACT_Objective_Use = 3,
		};

		// CGameRules::SModuleRMISvClientActionParams::UActionData
		// Header:  Prey/GameDll/GameRules.h
		union UActionData
		{ // Size=4 (0x4)
			// CGameRules::SModuleRMISvClientActionParams::UActionData::SHelperCarryPickup
			// Header:  Prey/GameDll/GameRules.h
			struct SHelperCarryPickup
			{ // Size=4 (0x4)
				unsigned pickupEid;
			};

			CGameRules::SModuleRMISvClientActionParams::UActionData::SHelperCarryPickup helperCarryPickup;
		};

		using TAction = uint8_t;

		CGameRules::SModuleRMISvClientActionParams::UActionData m_datau;
		int m_listenerIndex;
		uint8_t m_action;

	#if 0
		SModuleRMISvClientActionParams();
		SModuleRMISvClientActionParams(int _arg0_, uint8_t _arg1_, const CGameRules::SModuleRMISvClientActionParams::UActionData* _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SAfterMatchAwardWorkingsParams
	// Header:  Prey/GameDll/GameRules.h
	struct SAfterMatchAwardWorkingsParams
	{ // Size=808 (0x328)
		// CGameRules::SAfterMatchAwardWorkingsParams::SWorkingValue
		// Header:  Prey/GameDll/GameRules.h
		struct SWorkingValue
		{ // Size=8 (0x8)
			uint8_t m_award;
			float m_workingValue;
		};

		static constexpr const uint8_t k_maxNumAwards = 100;
		CGameRules::SAfterMatchAwardWorkingsParams::SWorkingValue m_awards[100];
		uint8_t m_numAwards;
		unsigned m_playerEntityId;

	#if 0
		SAfterMatchAwardWorkingsParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SAfterMatchAwardsParams
	// Header:  Prey/GameDll/GameRules.h
	struct SAfterMatchAwardsParams
	{ // Size=65 (0x41)
		static constexpr const uint8_t k_maxNumAwards = 64;
		uint8_t m_awards[64];
		uint8_t m_numAwards;

	#if 0
		SAfterMatchAwardsParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::SRespawnUpdateParams
	// Header:  Prey/GameDll/GameRules.h
	struct SRespawnUpdateParams
	{ // Size=8 (0x8)
		int m_respawnHashId;
		unsigned m_respawnEntityId;

	#if 0
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::STrackViewParameters
	// Header:  Prey/GameDll/GameRules.h
	struct STrackViewParameters
	{ // Size=136 (0x88)
		static constexpr const uint8_t sMaxTrackViews = 16;
		uint8_t m_NumberOfTrackViews;
		uint8_t m_NumberOfFinishedTrackViews;
		float m_Times[16];
		int m_Ids[16];
		bool m_bInitialData;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		STrackViewParameters();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::STrackViewParameters* const _this, TSerialize ser)>(0x18547F0);
	};

	// CGameRules::STrackViewRequestParameters
	// Header:  Prey/GameDll/GameRules.h
	struct STrackViewRequestParameters
	{ // Size=4 (0x4)
		int m_TrackViewID;

	#if 0
		STrackViewRequestParameters();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::ActivateHitIndicatorParams
	// Header:  Prey/GameDll/GameRules.h
	struct ActivateHitIndicatorParams
	{ // Size=12 (0xC)
		Vec3 originPos;

	#if 0
		ActivateHitIndicatorParams();
		ActivateHitIndicatorParams(Vec3 _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::StartingPrematchCountDownParams
	// Header:  Prey/GameDll/GameRules.h
	struct StartingPrematchCountDownParams
	{ // Size=4 (0x4)
		float m_timerLength;

	#if 0
		StartingPrematchCountDownParams();
		StartingPrematchCountDownParams(float _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvRequestHit
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestHit
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestHit(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const HitInfo& _arg0_) const;
	#endif
	};

	// CGameRules::MethodInfo_ClExplosion
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClExplosion
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClExplosion(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const ExplosionInfo& _arg0_) const;
	#endif
	};

	// CGameRules::MethodInfo_ClProjectileExplosion
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClProjectileExplosion
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClProjectileExplosion(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SProjectileExplosionParams& _arg0_) const;
	#endif
	};

	// CGameRules::MethodInfo_ClProjectileExplosion_Impact
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClProjectileExplosion_Impact
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClProjectileExplosion_Impact(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SProjectileExplosionParams_Impact& _arg0_) const;
	#endif
	};

	// CGameRules::MethodInfo_ClTaggedEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClTaggedEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClTaggedEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::TempRadarTaggingParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClTaggedEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClTaggedEntity
	{ // Size=16 (0x10)
		unsigned shooterId;
		unsigned targetId;
		float m_time;
		CGameRules::ERadarTagReason m_reason;

	#if 0
		void TempRadarTaggingParams();
		void TempRadarTaggingParams(unsigned _arg0_, unsigned _arg1_, float _arg2_, CGameRules::ERadarTagReason _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvRequestTagEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestTagEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestTagEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::TempRadarTaggingParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvRequestTagEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvRequestTagEntity
	{ // Size=16 (0x10)
		unsigned shooterId;
		unsigned targetId;
		float m_time;
		CGameRules::ERadarTagReason m_reason;

	#if 0
		void TempRadarTaggingParams();
		void TempRadarTaggingParams(unsigned _arg0_, unsigned _arg1_, float _arg2_, CGameRules::ERadarTagReason _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvRequestRename
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestRename
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestRename(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::RenameEntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvRequestRename
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvRequestRename
	{ // Size=16 (0x10)
		unsigned entityId;
		string name;

	#if 0
		void RenameEntityParams();
		void RenameEntityParams(unsigned _arg0_, const char* _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClRenameEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClRenameEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClRenameEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::RenameEntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClRenameEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClRenameEntity
	{ // Size=16 (0x10)
		unsigned entityId;
		string name;

	#if 0
		void RenameEntityParams();
		void RenameEntityParams(unsigned _arg0_, const char* _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvRequestChangeTeam
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestChangeTeam
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestChangeTeam(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::ChangeTeamParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvRequestChangeTeam
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvRequestChangeTeam
	{ // Size=12 (0xC)
		unsigned entityId;
		int teamId;
		bool onlyIfUnassigned;

	#if 0
		void ChangeTeamParams();
		void ChangeTeamParams(unsigned _arg0_, int _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvRequestSpectatorMode
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestSpectatorMode
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestSpectatorMode(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SpectatorModeParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvRequestSpectatorMode
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvRequestSpectatorMode
	{ // Size=16 (0x10)
		unsigned entityId;
		uint8_t mode;
		unsigned targetId;
		bool resetAll;
		bool force;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void SpectatorModeParams();
		void SpectatorModeParams(unsigned _arg0_, uint8_t _arg1_, unsigned _arg2_, bool _arg3_, bool _arg4_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::SpectatorModeParams* const _this, TSerialize ser)>(0x18549C0);
	};

	// CGameRules::MethodInfo_ClTeamFull
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClTeamFull
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClTeamFull(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::UInt8Param& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClTeamFull
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClTeamFull
	{ // Size=1 (0x1)
		uint8_t param;

	#if 0
		void UInt8Param();
		void UInt8Param(uint8_t _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClSetTeam
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClSetTeam
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClSetTeam(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SetTeamParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClSetTeam
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClSetTeam
	{ // Size=8 (0x8)
		int teamId;
		unsigned entityId;

	#if 0
		void SetTeamParams();
		void SetTeamParams(unsigned _arg0_, int _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClTextMessage
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClTextMessage
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClTextMessage(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::TextMessageParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClTextMessage
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClTextMessage
	{ // Size=56 (0x38)
		uint8_t type;
		string msg;
		uint8_t nparams;
		string params[4];

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void TextMessageParams();
		void TextMessageParams(ETextMessageType _arg0_, const char* _arg1_);
		void TextMessageParams(ETextMessageType _arg0_, const char* _arg1_, const char* _arg2_, const char* _arg3_, const char* _arg4_, const char* _arg5_);
		bool AddParam(const char* _arg0_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::TextMessageParams* const _this, TSerialize ser)>(0x1854A70);
	};

	// CGameRules::MethodInfo_ClProcessHit
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClProcessHit
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClProcessHit(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::ProcessHitParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClProcessHit
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClProcessHit
	{ // Size=28 (0x1C)
		Vec3 dir;
		unsigned shooterId;
		unsigned weaponId;
		float damage;
		uint16_t projectileClassId;
		uint8_t hitTypeId;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void ProcessHitParams();
		void ProcessHitParams(unsigned _arg0_, unsigned _arg1_, const Vec3& _arg2_, float _arg3_, uint16_t _arg4_, uint8_t _arg5_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::ProcessHitParams* const _this, TSerialize ser)>(0x18543D0);
	};

	// CGameRules::MethodInfo_ClPostInit
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClPostInit
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClPostInit(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::PostInitParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClPostInit
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClPostInit
	{ // Size=12 (0xC)
		int timeSinceGameStarted;
		unsigned uSecurity;
		bool firstBlood;

	#if 0
		void PostInitParams();
		void PostInitParams(const int& _arg0_, bool _arg1_, unsigned _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClSetGameStartedTime
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClSetGameStartedTime
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClSetGameStartedTime(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SetGameTimeParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClSetGameStartedTime
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClSetGameStartedTime
	{ // Size=8 (0x8)
		CTimeValue time;

	#if 0
		void SetGameTimeParams();
		void SetGameTimeParams(const CTimeValue& _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClSetGameStartTimer
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClSetGameStartTimer
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClSetGameStartTimer(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SetGameTimeParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClSetGameStartTimer
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClSetGameStartTimer
	{ // Size=8 (0x8)
		CTimeValue time;

	#if 0
		void SetGameTimeParams();
		void SetGameTimeParams(const CTimeValue& _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvVote
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvVote
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvVote(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::NoParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvVote
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvVote
	{ // Size=1 (0x1)
	#if 0
		void NoParams();
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvVoteNo
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvVoteNo
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvVoteNo(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::NoParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvVoteNo
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvVoteNo
	{ // Size=1 (0x1)
	#if 0
		void NoParams();
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClEnteredGame
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClEnteredGame
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClEnteredGame(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::NoParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClEnteredGame
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClEnteredGame
	{ // Size=1 (0x1)
	#if 0
		void NoParams();
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClVictoryTeam
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClVictoryTeam
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClVictoryTeam(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::VictoryTeamParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClVictoryTeam
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClVictoryTeam
	{ // Size=464 (0x1D0)
		CGameRules::SPlayerEndGameStatsParams m_playerStats;
		int winningTeamId;
		uint8_t reason;
		int team1Score;
		int team2Score;
		int drawLevel;
		SDrawResolutionData level1;
		SDrawResolutionData level2;
		unsigned killedEntity;
		unsigned shooterEntity;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void VictoryTeamParams();
		void VictoryTeamParams(int _arg0_, uint8_t _arg1_, int _arg2_, int _arg3_, int _arg4_, SDrawResolutionData _arg5_, SDrawResolutionData _arg6_, unsigned _arg7_, unsigned _arg8_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::VictoryTeamParams* const _this, TSerialize ser)>(0x1854BD0);
	};

	// CGameRules::MethodInfo_ClVictoryPlayer
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClVictoryPlayer
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClVictoryPlayer(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::VictoryPlayerParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClVictoryPlayer
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClVictoryPlayer
	{ // Size=276 (0x114)
		CGameRules::SPlayerEndGameStatsParams m_playerStats;
		unsigned playerId;
		unsigned killedEntity;
		unsigned shooterEntity;
		uint8_t reason;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void VictoryPlayerParams();
		void VictoryPlayerParams(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, uint8_t _arg3_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::VictoryPlayerParams* const _this, TSerialize ser)>(0x1854B20);
	};

	// CGameRules::MethodInfo_ClAddPoints
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClAddPoints
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAddPoints(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::ScoreChangeParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClAddPoints
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClAddPoints
	{ // Size=16 (0x10)
		unsigned m_killedEntityId;
		int16_t m_changeToScore;
		int8_t m_type;
		EXPReason m_reason;
		int m_currentTeamScore;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void ScoreChangeParams();
		void ScoreChangeParams(unsigned _arg0_, int16_t _arg1_, int8_t _arg2_, EXPReason _arg3_, int _arg4_);
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::ScoreChangeParams* const _this, TSerialize ser)>(0x1854900);
	};

	// CGameRules::MethodInfo_SvRequestRevive
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvRequestRevive
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvRequestRevive(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::ServerReviveParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvRequestRevive
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvRequestRevive
	{ // Size=8 (0x8)
		unsigned entityId;
		uint16_t index;

	#if 0
		void ServerReviveParams();
		void ServerReviveParams(unsigned _arg0_, uint16_t _arg1_, bool _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvSetEquipmentLoadout
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvSetEquipmentLoadout
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvSetEquipmentLoadout(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::EquipmentLoadoutParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvSetEquipmentLoadout
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvSetEquipmentLoadout
	{ // Size=16 (0x10)
		uint8_t m_contents[10];
		uint8_t m_modelIndex;
		uint8_t m_loadoutIndex;
		unsigned m_weaponAttachmentFlags;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void EquipmentLoadoutParams();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::EquipmentLoadoutParams* const _this, TSerialize ser)>(0x1853CA0);
	};

	// CGameRules::MethodInfo_ClModuleRMISingleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClModuleRMISingleEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClModuleRMISingleEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SModuleRMIEntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClModuleRMISingleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClModuleRMISingleEntity
	{ // Size=12 (0xC)
		unsigned m_entityId;
		int m_listenerIndex;
		uint8_t m_data;

	#if 0
		void SModuleRMIEntityParams();
		void SModuleRMIEntityParams(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void Set(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClModuleRMIDoubleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClModuleRMIDoubleEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClModuleRMIDoubleEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SModuleRMITwoEntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClModuleRMIDoubleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClModuleRMIDoubleEntity
	{ // Size=16 (0x10)
		unsigned m_entityId1;
		unsigned m_entityId2;
		int m_listenerIndex;
		int m_data;

	#if 0
		void SModuleRMITwoEntityParams();
		void SModuleRMITwoEntityParams(int _arg0_, unsigned _arg1_, unsigned _arg2_, int _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClModuleRMIEntityWithTime
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClModuleRMIEntityWithTime
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClModuleRMIEntityWithTime(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SModuleRMIEntityTimeParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClModuleRMIEntityWithTime
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClModuleRMIEntityWithTime
	{ // Size=24 (0x18)
		CTimeValue m_time;
		unsigned m_entityId;
		int m_listenerIndex;
		int m_data;

	#if 0
		void SModuleRMIEntityTimeParams();
		void SModuleRMIEntityTimeParams(int _arg0_, unsigned _arg1_, int _arg2_, const CTimeValue& _arg3_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvModuleRMISingleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvModuleRMISingleEntity
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvModuleRMISingleEntity(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SModuleRMIEntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvModuleRMISingleEntity
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvModuleRMISingleEntity
	{ // Size=12 (0xC)
		unsigned m_entityId;
		int m_listenerIndex;
		uint8_t m_data;

	#if 0
		void SModuleRMIEntityParams();
		void SModuleRMIEntityParams(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void Set(int _arg0_, unsigned _arg1_, uint8_t _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvSuccessfulFlashBang
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvSuccessfulFlashBang
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvSuccessfulFlashBang(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SSuccessfulFlashBangParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvSuccessfulFlashBang
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvSuccessfulFlashBang
	{ // Size=12 (0xC)
		unsigned shooterId;
		float time;
		float damage;

	#if 0
		void SSuccessfulFlashBangParams();
		void SSuccessfulFlashBangParams(unsigned _arg0_, float _arg1_, float _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClNetConsoleCommand
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClNetConsoleCommand
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClNetConsoleCommand(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::NetConsoleCommandParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClNetConsoleCommand
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClNetConsoleCommand
	{ // Size=8 (0x8)
		string m_commandString;

	#if 0
		void NetConsoleCommandParams();
		void NetConsoleCommandParams(const char* _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvHostMigrationRequestSetup
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvHostMigrationRequestSetup
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvHostMigrationRequestSetup(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SHostMigrationClientRequestParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvHostMigrationRequestSetup
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvHostMigrationRequestSetup
	{ // Size=44 (0x2C)
		Quat m_environmentalWeaponRot;
		Vec3 m_environmentalWeaponPos;
		Vec3 m_environmentalWeaponVel;
		unsigned m_environmentalWeaponId;

	#if 0
		void SHostMigrationClientRequestParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClHostMigrationFinished
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClHostMigrationFinished
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClHostMigrationFinished(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::NoParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClHostMigrationFinished
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClHostMigrationFinished
	{ // Size=1 (0x1)
	#if 0
		void NoParams();
		void SerializeWith(const TSerialize& _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClMidMigrationJoin
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClMidMigrationJoin
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClMidMigrationJoin(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SMidMigrationJoinParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClMidMigrationJoin
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClMidMigrationJoin
	{ // Size=8 (0x8)
		int m_state;
		float m_timeSinceStateChanged;

	#if 0
		void SMidMigrationJoinParams();
		void SMidMigrationJoinParams(int _arg0_, float _arg1_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClHostMigrationPlayerJoined
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClHostMigrationPlayerJoined
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClHostMigrationPlayerJoined(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::EntityParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClHostMigrationPlayerJoined
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClHostMigrationPlayerJoined
	{ // Size=4 (0x4)
		unsigned entityId;

	#if 0
		void EntityParams();
		void EntityParams(unsigned _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClPredictionFailed
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClPredictionFailed
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClPredictionFailed(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SPredictionParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClPredictionFailed
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClPredictionFailed
	{ // Size=4 (0x4)
		int predictionHandle;

	#if 0
		void SPredictionParams();
		void SPredictionParams(int _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvModuleRMIOnAction
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvModuleRMIOnAction
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvModuleRMIOnAction(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SModuleRMISvClientActionParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvModuleRMIOnAction
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvModuleRMIOnAction
	{ // Size=12 (0xC)
		enum #unnamed_enum_eACT_NULL
		{
			eACT_NULL = 0,
			eACT_HelperCarry_Pickup = 1,
			eACT_HelperCarry_Drop = 2,
			eACT_Objective_Use = 3,
		};

		// CGameRules::SModuleRMISvClientActionParams::UActionData
		// Header:  Prey/GameDll/GameRules.h
		union UActionData
		{ // Size=4 (0x4)
			// CGameRules::SModuleRMISvClientActionParams::UActionData::SHelperCarryPickup
			// Header:  Prey/GameDll/GameRules.h
			struct SHelperCarryPickup
			{ // Size=4 (0x4)
				unsigned pickupEid;
			};

			CGameRules::SModuleRMISvClientActionParams::UActionData::SHelperCarryPickup helperCarryPickup;
		};

		using TAction = uint8_t;

		CGameRules::SModuleRMISvClientActionParams::UActionData m_datau;
		int m_listenerIndex;
		uint8_t m_action;

	#if 0
		void SModuleRMISvClientActionParams();
		void SModuleRMISvClientActionParams(int _arg0_, uint8_t _arg1_, const CGameRules::SModuleRMISvClientActionParams::UActionData* _arg2_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_SvAfterMatchAwardsWorking
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvAfterMatchAwardsWorking
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvAfterMatchAwardsWorking(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SAfterMatchAwardWorkingsParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvAfterMatchAwardsWorking
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvAfterMatchAwardsWorking
	{ // Size=808 (0x328)
		// CGameRules::SAfterMatchAwardWorkingsParams::SWorkingValue
		// Header:  Prey/GameDll/GameRules.h
		struct SWorkingValue
		{ // Size=8 (0x8)
			uint8_t m_award;
			float m_workingValue;
		};

		static constexpr const uint8_t k_maxNumAwards = 100;
		CGameRules::SAfterMatchAwardWorkingsParams::SWorkingValue m_awards[100];
		uint8_t m_numAwards;
		unsigned m_playerEntityId;

	#if 0
		void SAfterMatchAwardWorkingsParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClAfterMatchAwards
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClAfterMatchAwards
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClAfterMatchAwards(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SAfterMatchAwardsParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClAfterMatchAwards
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClAfterMatchAwards
	{ // Size=65 (0x41)
		static constexpr const uint8_t k_maxNumAwards = 64;
		uint8_t m_awards[64];
		uint8_t m_numAwards;

	#if 0
		void SAfterMatchAwardsParams();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClUpdateRespawnData
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClUpdateRespawnData
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClUpdateRespawnData(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::SRespawnUpdateParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClUpdateRespawnData
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClUpdateRespawnData
	{ // Size=8 (0x8)
		int m_respawnHashId;
		unsigned m_respawnEntityId;

	#if 0
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClTrackViewSynchAnimations
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClTrackViewSynchAnimations
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClTrackViewSynchAnimations(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::STrackViewParameters& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClTrackViewSynchAnimations
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClTrackViewSynchAnimations
	{ // Size=136 (0x88)
		static constexpr const uint8_t sMaxTrackViews = 16;
		uint8_t m_NumberOfTrackViews;
		uint8_t m_NumberOfFinishedTrackViews;
		float m_Times[16];
		int m_Ids[16];
		bool m_bInitialData;

		void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

	#if 0
		void STrackViewParameters();
	#endif

		static inline auto FSerializeWith = PreyFunction<void(CGameRules::STrackViewParameters* const _this, TSerialize ser)>(0x18547F0);
	};

	// CGameRules::MethodInfo_SvTrackViewRequestAnimation
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_SvTrackViewRequestAnimation
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_SvTrackViewRequestAnimation(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::STrackViewRequestParameters& _arg0_) const;
	#endif
	};

	// CGameRules::Params_SvTrackViewRequestAnimation
	// Header:  Prey/GameDll/GameRules.h
	struct Params_SvTrackViewRequestAnimation
	{ // Size=4 (0x4)
		int m_TrackViewID;

	#if 0
		void STrackViewRequestParameters();
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClPathFollowingAttachToPath
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClPathFollowingAttachToPath
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClPathFollowingAttachToPath(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const SPathFollowingAttachToPathParameters& _arg0_) const;
	#endif
	};

	// CGameRules::MethodInfo_ClActivateHitIndicator
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClActivateHitIndicator
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClActivateHitIndicator(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::ActivateHitIndicatorParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClActivateHitIndicator
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClActivateHitIndicator
	{ // Size=12 (0xC)
		Vec3 originPos;

	#if 0
		void ActivateHitIndicatorParams();
		void ActivateHitIndicatorParams(Vec3 _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::MethodInfo_ClStartingPrematchCountDown
	// Header:  Prey/GameDll/GameRules.h
	struct MethodInfo_ClStartingPrematchCountDown
	{ // Size=8 (0x8)
		const SGameObjectExtensionRMI* pMethodInfo;

	#if 0
		MethodInfo_ClStartingPrematchCountDown(const SGameObjectExtensionRMI* _arg0_);
		void Verify(const CGameRules::StartingPrematchCountDownParams& _arg0_) const;
	#endif
	};

	// CGameRules::Params_ClStartingPrematchCountDown
	// Header:  Prey/GameDll/GameRules.h
	struct Params_ClStartingPrematchCountDown
	{ // Size=4 (0x4)
		float m_timerLength;

	#if 0
		void StartingPrematchCountDownParams();
		void StartingPrematchCountDownParams(float _arg0_);
		void SerializeWith(TSerialize _arg0_);
	#endif
	};

	// CGameRules::STeamScore
	// Header:  Prey/GameDll/GameRules.h
	struct STeamScore
	{ // Size=6 (0x6)
		uint16_t m_teamScore;
		uint16_t m_roundTeamScore;
		uint16_t m_teamScoreRoundStart;

	#if 0
		STeamScore();
		STeamScore(uint16_t _arg0_, uint16_t _arg1_);
		STeamScore(uint16_t _arg0_, uint16_t _arg1_, uint16_t _arg2_);
	#endif
	};

	// CGameRules::SCollisionHitInfo
	// Header:  Prey/GameDll/GameRules.h
	struct SCollisionHitInfo
	{ // Size=88 (0x58)
		Vec3 pos;
		Vec3 normal;
		Vec3 dir;
		Vec3 velocity;
		Vec3 target_velocity;
		float target_mass;
		float mass;
		unsigned targetId;
		pe_type target_type;
		int materialId;
		int partId;
		bool dir_null;
		bool backface;

	#if 0
		SCollisionHitInfo();
	#endif
	};

	// CGameRules::SEntityRespawnData
	// Header:  Prey/GameDll/GameRules.h
	struct SEntityRespawnData
	{ // Size=80 (0x50)
		SmartScriptTable properties;
		Vec3 position;
		Quat rotation;
		Vec3 scale;
		int flags;
		IEntityClass* pClass;
		CryHashStringId m_nameHash;
		unsigned m_currentEntityId;
		bool m_bHasRespawned;

	#if 0
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CGameRules::SEntityRespawn
	// Header:  Prey/GameDll/GameRules.h
	struct SEntityRespawn
	{ // Size=8 (0x8)
		bool unique;
		float timer;

	#if 0
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CGameRules::SEntityRemovalData
	// Header:  Prey/GameDll/GameRules.h
	struct SEntityRemovalData
	{ // Size=12 (0xC)
		float timer;
		float time;
		bool visibility;

	#if 0
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CGameRules::SEquipmentLoadOutPreCacheCallback
	// Header:  Prey/GameDll/GameRules.h
	struct SEquipmentLoadOutPreCacheCallback : public IEquipmentPackPreCacheCallback
	{ // Size=8 (0x8)
		virtual void PreCacheItemResources(const char* itemName);

		static inline auto FPreCacheItemResources = PreyFunction<void(CGameRules::SEquipmentLoadOutPreCacheCallback* const _this, const char* itemName)>(0x1844FA0);
	};

	// CGameRules::SForbiddenAreaHelper
	// Header:  Prey/GameDll/GameRules.h
	struct SForbiddenAreaHelper
	{ // Size=12 (0xC)
		unsigned shapeId;
		unsigned parentId;
		bool reversed;
		bool resetsObjects;

	#if 0
		SForbiddenAreaHelper(unsigned _arg0_, bool _arg1_, bool _arg2_, unsigned _arg3_);
	#endif
	};

	using TPlayers = std::vector<unsigned int>;
	using TSpawnLocations = std::vector<unsigned int>;
	using TSpawnGroupMap = std::map<unsigned int, std::vector<unsigned int>>;
	using TBuildings = std::map<unsigned int, int>;
	using TCryUserIdSet = std::set<CryUserID>;
	using TGameRulesListenerVec = std::vector<SGameRulesListener*>;
	using TExplosionAffectedEntities = std::map<IEntity*, float>;
	using Params_SvRequestHit = HitInfo;
	using Params_ClExplosion = ExplosionInfo;
	using Params_ClProjectileExplosion = SProjectileExplosionParams;
	using Params_ClProjectileExplosion_Impact = SProjectileExplosionParams_Impact;
	using Params_ClPathFollowingAttachToPath = SPathFollowingAttachToPathParameters;
	using TTeamIdEntityIdMap = std::map<int, unsigned int>;
	using TEntityTeamIdMap = std::map<unsigned int, int>;
	using TPlayerTeamIdMap = std::map<int, std::vector<unsigned int>>;
	using TChannelTeamIdMap = std::map<int, unsigned int>;
	using TTeamIdMap = std::map<string, int>;
	using TTeamScoresMap = std::map<int, CGameRules::STeamScore>;
	using THitMaterialMap = std::map<int, int>;
	using THitTypeVec = std::vector<HitTypeInfo>;
	using TEntityRespawnDataVec = std::vector<CGameRules::SEntityRespawnData>;
	using TEntityRespawnMap = std::map<unsigned int, CGameRules::SEntityRespawn>;
	using TEntityRemovalMap = std::map<unsigned int, CGameRules::SEntityRemovalData>;
	using THitListenerVec = std::vector<IHitListener*>;
	using TExplosionPtrQueue = std::queue<SExplosionContainer *,std::deque<SExplosionContainer *,std::allocator<SExplosionContainer *> > >;
	using THitQueue = std::queue<HitInfo,std::deque<HitInfo,std::allocator<HitInfo> > >;
	using TEntityIdVec = std::vector<unsigned int>;
	using TClientConnectionListenersVec = std::vector<IGameRulesClientConnectionListener*>;
	using TTeamChangedListenersVec = std::vector<IGameRulesTeamChangedListener*>;
	using TKillListenersVec = std::vector<IGameRulesKillListener*>;
	using TModuleRMIListenersVec = std::vector<IGameRulesModuleRMIListener*>;
	using TRevivedListenersVec = std::vector<IGameRulesRevivedListener*>;
	using TRoundsListenersVec = std::vector<IGameRulesRoundsListener*>;
	using TClientScoreListenersVec = std::vector<IGameRulesClientScoreListener*>;
	using TCharacterInstancePtr = _smart_ptr<ICharacterInstance>;
	using TCharacterInstancePtrVec = std::vector<_smart_ptr<ICharacterInstance>>;
	using TParticleEffectPtr = _smart_ptr<IParticleEffect>;
	using TParticleEffectPtrVec = std::vector<_smart_ptr<IParticleEffect>>;
	using TTextureInstancePtr = _smart_ptr<ITexture>;
	using TTexturePtrVec = std::vector<_smart_ptr<ITexture>>;
	using TXmlFilename2NodeRefMap = std::map<string, XmlNodeRef>;

	static constexpr const ERMIAttachmentType Attach_SvRequestHit = 3;
	static constexpr const bool ServerCall_SvRequestHit = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestHit = 1;
	static constexpr const bool LowDelay_SvRequestHit = 0;
	static inline auto m_infoSvRequestHit = PreyGlobal<CGameRules::MethodInfo_SvRequestHit>(0x2D8DB50);
	static constexpr const ERMIAttachmentType Attach_ClExplosion = 2;
	static constexpr const bool ServerCall_ClExplosion = 0;
	static constexpr const ENetReliabilityType Reliability_ClExplosion = 1;
	static constexpr const bool LowDelay_ClExplosion = 0;
	static inline auto m_infoClExplosion = PreyGlobal<CGameRules::MethodInfo_ClExplosion>(0x2D8DB58);
	static constexpr const ERMIAttachmentType Attach_ClProjectileExplosion = 3;
	static constexpr const bool ServerCall_ClProjectileExplosion = 0;
	static constexpr const ENetReliabilityType Reliability_ClProjectileExplosion = 1;
	static constexpr const bool LowDelay_ClProjectileExplosion = 0;
	static inline auto m_infoClProjectileExplosion = PreyGlobal<CGameRules::MethodInfo_ClProjectileExplosion>(0x2D8DB60);
	static constexpr const ERMIAttachmentType Attach_ClProjectileExplosion_Impact = 2;
	static constexpr const bool ServerCall_ClProjectileExplosion_Impact = 0;
	static constexpr const ENetReliabilityType Reliability_ClProjectileExplosion_Impact = 1;
	static constexpr const bool LowDelay_ClProjectileExplosion_Impact = 0;
	static inline auto m_infoClProjectileExplosion_Impact = PreyGlobal<CGameRules::MethodInfo_ClProjectileExplosion_Impact>(0x2D8DB68);
	static constexpr const ERMIAttachmentType Attach_ClTaggedEntity = 2;
	static constexpr const bool ServerCall_ClTaggedEntity = 0;
	static constexpr const ENetReliabilityType Reliability_ClTaggedEntity = 1;
	static constexpr const bool LowDelay_ClTaggedEntity = 0;
	static inline auto m_infoClTaggedEntity = PreyGlobal<CGameRules::MethodInfo_ClTaggedEntity>(0x2D8DB88);
	static constexpr const ERMIAttachmentType Attach_SvRequestTagEntity = 2;
	static constexpr const bool ServerCall_SvRequestTagEntity = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestTagEntity = 1;
	static constexpr const bool LowDelay_SvRequestTagEntity = 0;
	static inline auto m_infoSvRequestTagEntity = PreyGlobal<CGameRules::MethodInfo_SvRequestTagEntity>(0x2D8DB90);
	static constexpr const ERMIAttachmentType Attach_SvRequestRename = 2;
	static constexpr const bool ServerCall_SvRequestRename = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestRename = 0;
	static constexpr const bool LowDelay_SvRequestRename = 0;
	static inline auto m_infoSvRequestRename = PreyGlobal<CGameRules::MethodInfo_SvRequestRename>(0x2D8DB10);
	static constexpr const ERMIAttachmentType Attach_ClRenameEntity = 2;
	static constexpr const bool ServerCall_ClRenameEntity = 0;
	static constexpr const ENetReliabilityType Reliability_ClRenameEntity = 0;
	static constexpr const bool LowDelay_ClRenameEntity = 0;
	static inline auto m_infoClRenameEntity = PreyGlobal<CGameRules::MethodInfo_ClRenameEntity>(0x2D8DB18);
	static constexpr const ERMIAttachmentType Attach_SvRequestChangeTeam = 2;
	static constexpr const bool ServerCall_SvRequestChangeTeam = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestChangeTeam = 0;
	static constexpr const bool LowDelay_SvRequestChangeTeam = 0;
	static inline auto m_infoSvRequestChangeTeam = PreyGlobal<CGameRules::MethodInfo_SvRequestChangeTeam>(0x2D8DB20);
	static constexpr const ERMIAttachmentType Attach_SvRequestSpectatorMode = 2;
	static constexpr const bool ServerCall_SvRequestSpectatorMode = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestSpectatorMode = 0;
	static constexpr const bool LowDelay_SvRequestSpectatorMode = 0;
	static inline auto m_infoSvRequestSpectatorMode = PreyGlobal<CGameRules::MethodInfo_SvRequestSpectatorMode>(0x2D8DB28);
	static constexpr const ERMIAttachmentType Attach_ClTeamFull = 2;
	static constexpr const bool ServerCall_ClTeamFull = 0;
	static constexpr const ENetReliabilityType Reliability_ClTeamFull = 0;
	static constexpr const bool LowDelay_ClTeamFull = 0;
	static inline auto m_infoClTeamFull = PreyGlobal<CGameRules::MethodInfo_ClTeamFull>(0x2D8DB30);
	static constexpr const ERMIAttachmentType Attach_ClSetTeam = 2;
	static constexpr const bool ServerCall_ClSetTeam = 0;
	static constexpr const ENetReliabilityType Reliability_ClSetTeam = 0;
	static constexpr const bool LowDelay_ClSetTeam = 0;
	static inline auto m_infoClSetTeam = PreyGlobal<CGameRules::MethodInfo_ClSetTeam>(0x2D8DB38);
	static constexpr const ERMIAttachmentType Attach_ClTextMessage = 2;
	static constexpr const bool ServerCall_ClTextMessage = 0;
	static constexpr const ENetReliabilityType Reliability_ClTextMessage = 1;
	static constexpr const bool LowDelay_ClTextMessage = 0;
	static inline auto m_infoClTextMessage = PreyGlobal<CGameRules::MethodInfo_ClTextMessage>(0x2D8DB40);
	static constexpr const ERMIAttachmentType Attach_ClProcessHit = 2;
	static constexpr const bool ServerCall_ClProcessHit = 0;
	static constexpr const ENetReliabilityType Reliability_ClProcessHit = 3;
	static constexpr const bool LowDelay_ClProcessHit = 0;
	static inline auto m_infoClProcessHit = PreyGlobal<CGameRules::MethodInfo_ClProcessHit>(0x2D8DB98);
	static constexpr const ERMIAttachmentType Attach_ClPostInit = 2;
	static constexpr const bool ServerCall_ClPostInit = 0;
	static constexpr const ENetReliabilityType Reliability_ClPostInit = 1;
	static constexpr const bool LowDelay_ClPostInit = 0;
	static inline auto m_infoClPostInit = PreyGlobal<CGameRules::MethodInfo_ClPostInit>(0x2D8DB70);
	static constexpr const ERMIAttachmentType Attach_ClSetGameStartedTime = 2;
	static constexpr const bool ServerCall_ClSetGameStartedTime = 0;
	static constexpr const ENetReliabilityType Reliability_ClSetGameStartedTime = 1;
	static constexpr const bool LowDelay_ClSetGameStartedTime = 0;
	static inline auto m_infoClSetGameStartedTime = PreyGlobal<CGameRules::MethodInfo_ClSetGameStartedTime>(0x2D8DB78);
	static constexpr const ERMIAttachmentType Attach_ClSetGameStartTimer = 2;
	static constexpr const bool ServerCall_ClSetGameStartTimer = 0;
	static constexpr const ENetReliabilityType Reliability_ClSetGameStartTimer = 1;
	static constexpr const bool LowDelay_ClSetGameStartTimer = 0;
	static inline auto m_infoClSetGameStartTimer = PreyGlobal<CGameRules::MethodInfo_ClSetGameStartTimer>(0x2D8DB80);
	static constexpr const ERMIAttachmentType Attach_SvVote = 2;
	static constexpr const bool ServerCall_SvVote = 1;
	static constexpr const ENetReliabilityType Reliability_SvVote = 1;
	static constexpr const bool LowDelay_SvVote = 0;
	static inline auto m_infoSvVote = PreyGlobal<CGameRules::MethodInfo_SvVote>(0x2D8DBA0);
	static constexpr const ERMIAttachmentType Attach_SvVoteNo = 2;
	static constexpr const bool ServerCall_SvVoteNo = 1;
	static constexpr const ENetReliabilityType Reliability_SvVoteNo = 1;
	static constexpr const bool LowDelay_SvVoteNo = 0;
	static inline auto m_infoSvVoteNo = PreyGlobal<CGameRules::MethodInfo_SvVoteNo>(0x2D8DBA8);
	static constexpr const ERMIAttachmentType Attach_ClEnteredGame = 2;
	static constexpr const bool ServerCall_ClEnteredGame = 0;
	static constexpr const ENetReliabilityType Reliability_ClEnteredGame = 1;
	static constexpr const bool LowDelay_ClEnteredGame = 0;
	static inline auto m_infoClEnteredGame = PreyGlobal<CGameRules::MethodInfo_ClEnteredGame>(0x2D8DBB0);
	static constexpr const ERMIAttachmentType Attach_ClVictoryTeam = 2;
	static constexpr const bool ServerCall_ClVictoryTeam = 0;
	static constexpr const ENetReliabilityType Reliability_ClVictoryTeam = 0;
	static constexpr const bool LowDelay_ClVictoryTeam = 0;
	static inline auto m_infoClVictoryTeam = PreyGlobal<CGameRules::MethodInfo_ClVictoryTeam>(0x2D8DBC8);
	static constexpr const ERMIAttachmentType Attach_ClVictoryPlayer = 2;
	static constexpr const bool ServerCall_ClVictoryPlayer = 0;
	static constexpr const ENetReliabilityType Reliability_ClVictoryPlayer = 0;
	static constexpr const bool LowDelay_ClVictoryPlayer = 0;
	static inline auto m_infoClVictoryPlayer = PreyGlobal<CGameRules::MethodInfo_ClVictoryPlayer>(0x2D8DBD0);
	static constexpr const ERMIAttachmentType Attach_ClAddPoints = 2;
	static constexpr const bool ServerCall_ClAddPoints = 0;
	static constexpr const ENetReliabilityType Reliability_ClAddPoints = 1;
	static constexpr const bool LowDelay_ClAddPoints = 0;
	static inline auto m_infoClAddPoints = PreyGlobal<CGameRules::MethodInfo_ClAddPoints>(0x2D8DBB8);
	static constexpr const ERMIAttachmentType Attach_SvRequestRevive = 2;
	static constexpr const bool ServerCall_SvRequestRevive = 1;
	static constexpr const ENetReliabilityType Reliability_SvRequestRevive = 0;
	static constexpr const bool LowDelay_SvRequestRevive = 0;
	static inline auto m_infoSvRequestRevive = PreyGlobal<CGameRules::MethodInfo_SvRequestRevive>(0x2D8DBC0);
	static constexpr const ERMIAttachmentType Attach_SvSetEquipmentLoadout = 2;
	static constexpr const bool ServerCall_SvSetEquipmentLoadout = 1;
	static constexpr const ENetReliabilityType Reliability_SvSetEquipmentLoadout = 0;
	static constexpr const bool LowDelay_SvSetEquipmentLoadout = 0;
	static inline auto m_infoSvSetEquipmentLoadout = PreyGlobal<CGameRules::MethodInfo_SvSetEquipmentLoadout>(0x2D8DC00);
	static constexpr const ERMIAttachmentType Attach_ClModuleRMISingleEntity = 2;
	static constexpr const bool ServerCall_ClModuleRMISingleEntity = 0;
	static constexpr const ENetReliabilityType Reliability_ClModuleRMISingleEntity = 0;
	static constexpr const bool LowDelay_ClModuleRMISingleEntity = 0;
	static inline auto m_infoClModuleRMISingleEntity = PreyGlobal<CGameRules::MethodInfo_ClModuleRMISingleEntity>(0x2D8DBD8);
	static constexpr const ERMIAttachmentType Attach_ClModuleRMIDoubleEntity = 2;
	static constexpr const bool ServerCall_ClModuleRMIDoubleEntity = 0;
	static constexpr const ENetReliabilityType Reliability_ClModuleRMIDoubleEntity = 0;
	static constexpr const bool LowDelay_ClModuleRMIDoubleEntity = 0;
	static inline auto m_infoClModuleRMIDoubleEntity = PreyGlobal<CGameRules::MethodInfo_ClModuleRMIDoubleEntity>(0x2D8DBE0);
	static constexpr const ERMIAttachmentType Attach_ClModuleRMIEntityWithTime = 2;
	static constexpr const bool ServerCall_ClModuleRMIEntityWithTime = 0;
	static constexpr const ENetReliabilityType Reliability_ClModuleRMIEntityWithTime = 0;
	static constexpr const bool LowDelay_ClModuleRMIEntityWithTime = 0;
	static inline auto m_infoClModuleRMIEntityWithTime = PreyGlobal<CGameRules::MethodInfo_ClModuleRMIEntityWithTime>(0x2D8DBE8);
	static constexpr const ERMIAttachmentType Attach_SvModuleRMISingleEntity = 2;
	static constexpr const bool ServerCall_SvModuleRMISingleEntity = 1;
	static constexpr const ENetReliabilityType Reliability_SvModuleRMISingleEntity = 0;
	static constexpr const bool LowDelay_SvModuleRMISingleEntity = 0;
	static inline auto m_infoSvModuleRMISingleEntity = PreyGlobal<CGameRules::MethodInfo_SvModuleRMISingleEntity>(0x2D8DBF0);
	static constexpr const ERMIAttachmentType Attach_SvSuccessfulFlashBang = 2;
	static constexpr const bool ServerCall_SvSuccessfulFlashBang = 1;
	static constexpr const ENetReliabilityType Reliability_SvSuccessfulFlashBang = 1;
	static constexpr const bool LowDelay_SvSuccessfulFlashBang = 0;
	static inline auto m_infoSvSuccessfulFlashBang = PreyGlobal<CGameRules::MethodInfo_SvSuccessfulFlashBang>(0x2D8DC08);
	static constexpr const ERMIAttachmentType Attach_ClNetConsoleCommand = 2;
	static constexpr const bool ServerCall_ClNetConsoleCommand = 0;
	static constexpr const ENetReliabilityType Reliability_ClNetConsoleCommand = 1;
	static constexpr const bool LowDelay_ClNetConsoleCommand = 0;
	static inline auto m_infoClNetConsoleCommand = PreyGlobal<CGameRules::MethodInfo_ClNetConsoleCommand>(0x2D8DB48);
	static constexpr const ERMIAttachmentType Attach_SvHostMigrationRequestSetup = 2;
	static constexpr const bool ServerCall_SvHostMigrationRequestSetup = 1;
	static constexpr const ENetReliabilityType Reliability_SvHostMigrationRequestSetup = 1;
	static constexpr const bool LowDelay_SvHostMigrationRequestSetup = 0;
	static inline auto m_infoSvHostMigrationRequestSetup = PreyGlobal<CGameRules::MethodInfo_SvHostMigrationRequestSetup>(0x2D8DC10);
	static constexpr const ERMIAttachmentType Attach_ClHostMigrationFinished = 2;
	static constexpr const bool ServerCall_ClHostMigrationFinished = 0;
	static constexpr const ENetReliabilityType Reliability_ClHostMigrationFinished = 0;
	static constexpr const bool LowDelay_ClHostMigrationFinished = 0;
	static inline auto m_infoClHostMigrationFinished = PreyGlobal<CGameRules::MethodInfo_ClHostMigrationFinished>(0x2D8DC18);
	static constexpr const ERMIAttachmentType Attach_ClMidMigrationJoin = 2;
	static constexpr const bool ServerCall_ClMidMigrationJoin = 0;
	static constexpr const ENetReliabilityType Reliability_ClMidMigrationJoin = 0;
	static constexpr const bool LowDelay_ClMidMigrationJoin = 0;
	static inline auto m_infoClMidMigrationJoin = PreyGlobal<CGameRules::MethodInfo_ClMidMigrationJoin>(0x2D8DC28);
	static constexpr const ERMIAttachmentType Attach_ClHostMigrationPlayerJoined = 2;
	static constexpr const bool ServerCall_ClHostMigrationPlayerJoined = 0;
	static constexpr const ENetReliabilityType Reliability_ClHostMigrationPlayerJoined = 0;
	static constexpr const bool LowDelay_ClHostMigrationPlayerJoined = 0;
	static inline auto m_infoClHostMigrationPlayerJoined = PreyGlobal<CGameRules::MethodInfo_ClHostMigrationPlayerJoined>(0x2D8DC30);
	static constexpr const ERMIAttachmentType Attach_ClPredictionFailed = 2;
	static constexpr const bool ServerCall_ClPredictionFailed = 0;
	static constexpr const ENetReliabilityType Reliability_ClPredictionFailed = 1;
	static constexpr const bool LowDelay_ClPredictionFailed = 0;
	static inline auto m_infoClPredictionFailed = PreyGlobal<CGameRules::MethodInfo_ClPredictionFailed>(0x2D8DC20);
	static constexpr const ERMIAttachmentType Attach_SvModuleRMIOnAction = 2;
	static constexpr const bool ServerCall_SvModuleRMIOnAction = 1;
	static constexpr const ENetReliabilityType Reliability_SvModuleRMIOnAction = 0;
	static constexpr const bool LowDelay_SvModuleRMIOnAction = 0;
	static inline auto m_infoSvModuleRMIOnAction = PreyGlobal<CGameRules::MethodInfo_SvModuleRMIOnAction>(0x2D8DBF8);
	static constexpr const ERMIAttachmentType Attach_SvAfterMatchAwardsWorking = 2;
	static constexpr const bool ServerCall_SvAfterMatchAwardsWorking = 1;
	static constexpr const ENetReliabilityType Reliability_SvAfterMatchAwardsWorking = 1;
	static constexpr const bool LowDelay_SvAfterMatchAwardsWorking = 0;
	static inline auto m_infoSvAfterMatchAwardsWorking = PreyGlobal<CGameRules::MethodInfo_SvAfterMatchAwardsWorking>(0x0);
	static constexpr const ERMIAttachmentType Attach_ClAfterMatchAwards = 2;
	static constexpr const bool ServerCall_ClAfterMatchAwards = 0;
	static constexpr const ENetReliabilityType Reliability_ClAfterMatchAwards = 1;
	static constexpr const bool LowDelay_ClAfterMatchAwards = 0;
	static inline auto m_infoClAfterMatchAwards = PreyGlobal<CGameRules::MethodInfo_ClAfterMatchAwards>(0x0);
	static constexpr const ERMIAttachmentType Attach_ClUpdateRespawnData = 2;
	static constexpr const bool ServerCall_ClUpdateRespawnData = 0;
	static constexpr const ENetReliabilityType Reliability_ClUpdateRespawnData = 1;
	static constexpr const bool LowDelay_ClUpdateRespawnData = 0;
	static inline auto m_infoClUpdateRespawnData = PreyGlobal<CGameRules::MethodInfo_ClUpdateRespawnData>(0x2D8DC38);
	static constexpr const ERMIAttachmentType Attach_ClTrackViewSynchAnimations = 2;
	static constexpr const bool ServerCall_ClTrackViewSynchAnimations = 0;
	static constexpr const ENetReliabilityType Reliability_ClTrackViewSynchAnimations = 0;
	static constexpr const bool LowDelay_ClTrackViewSynchAnimations = 0;
	static inline auto m_infoClTrackViewSynchAnimations = PreyGlobal<CGameRules::MethodInfo_ClTrackViewSynchAnimations>(0x2D8DC40);
	static constexpr const ERMIAttachmentType Attach_SvTrackViewRequestAnimation = 2;
	static constexpr const bool ServerCall_SvTrackViewRequestAnimation = 1;
	static constexpr const ENetReliabilityType Reliability_SvTrackViewRequestAnimation = 0;
	static constexpr const bool LowDelay_SvTrackViewRequestAnimation = 0;
	static inline auto m_infoSvTrackViewRequestAnimation = PreyGlobal<CGameRules::MethodInfo_SvTrackViewRequestAnimation>(0x2D8DC48);
	static constexpr const ERMIAttachmentType Attach_ClPathFollowingAttachToPath = 2;
	static constexpr const bool ServerCall_ClPathFollowingAttachToPath = 0;
	static constexpr const ENetReliabilityType Reliability_ClPathFollowingAttachToPath = 1;
	static constexpr const bool LowDelay_ClPathFollowingAttachToPath = 0;
	static inline auto m_infoClPathFollowingAttachToPath = PreyGlobal<CGameRules::MethodInfo_ClPathFollowingAttachToPath>(0x2D8DC60);
	static constexpr const ERMIAttachmentType Attach_ClActivateHitIndicator = 2;
	static constexpr const bool ServerCall_ClActivateHitIndicator = 0;
	static constexpr const ENetReliabilityType Reliability_ClActivateHitIndicator = 1;
	static constexpr const bool LowDelay_ClActivateHitIndicator = 0;
	static inline auto m_infoClActivateHitIndicator = PreyGlobal<CGameRules::MethodInfo_ClActivateHitIndicator>(0x2D8DC50);
	static constexpr const ERMIAttachmentType Attach_ClStartingPrematchCountDown = 2;
	static constexpr const bool ServerCall_ClStartingPrematchCountDown = 0;
	static constexpr const ENetReliabilityType Reliability_ClStartingPrematchCountDown = 1;
	static constexpr const bool LowDelay_ClStartingPrematchCountDown = 0;
	static inline auto m_infoClStartingPrematchCountDown = PreyGlobal<CGameRules::MethodInfo_ClStartingPrematchCountDown>(0x2D8DC58);
	static inline auto s_reservedHitTypes = PreyGlobal<const char* [0]>(0x23EFCB0);
	static inline auto s_hitTypeFlags = PreyGlobal<const char* [0]>(0x23EFD80);
	static inline auto s_gameModeNames = PreyGlobal<const char* [0]>(0x23EFDC0);
	EGameMode m_gameMode;
	IGameFramework* m_pGameFramework;
	IGameplayRecorder* m_pGameplayRecorder;
	ISystem* m_pSystem;
	IActorSystem* m_pActorSystem;
	IEntitySystem* m_pEntitySystem;
	IScriptSystem* m_pScriptSystem;
	IMaterialManager* m_pMaterialManager;
	SmartScriptTable m_script;
	SmartScriptTable m_clientScript;
	SmartScriptTable m_serverScript;
	SmartScriptTable m_clientStateScript;
	SmartScriptTable m_serverStateScript;
	INetChannel* m_pClientNetChannel;
	std::vector<int> m_channelIds;
	std::map<string, int> m_teams;
	std::map<string, int> m_teamAliases;
	std::map<unsigned int, int> m_entityteams;
	std::map<int, std::vector<unsigned int>> m_playerteams;
	std::map<int, unsigned int> m_channelteams;
	std::map<int, CGameRules::STeamScore> m_teamscores;
	int m_teamIdGen;
	std::vector<HitTypeInfo> m_hitTypes;
	int m_hitTypeIdGen;
	SmartScriptTable m_scriptClientHitInfo;
	std::queue<SExplosionContainer *,std::deque<SExplosionContainer *,std::allocator<SExplosionContainer *> > > m_queuedExplosions;
	std::queue<SExplosionContainer *,std::deque<SExplosionContainer *,std::allocator<SExplosionContainer *> > > m_queuedExplosionsAwaitingRaycasts;
	SExplosionContainer m_explosions[64];
	bool m_explosionValidities[64];
	std::queue<HitInfo,std::deque<HitInfo,std::allocator<HitInfo> > > m_queuedHits;
	int m_processingHit;
	std::vector<CGameRules::SEntityRespawnData> m_respawndata;
	std::map<unsigned int, CGameRules::SEntityRespawn> m_respawns;
	std::map<unsigned int, CGameRules::SEntityRemovalData> m_removals;
	std::map<unsigned int, std::vector<unsigned int>> m_spawnGroups;
	std::vector<IHitListener*> m_hitListeners;
	CTimeValue m_gameStartedTime;
	CTimeValue m_gameStartTime;
	CTimeValue m_gamePausedTime;
	CTimeValue m_cachedServerTime;
	CTimeValue m_hostMigrationTimeSinceGameStarted;
	CTimeValue m_timeLastShownUnbalancedTeamsWarning;
	float m_timeLimit;
	int m_scoreLimit;
	int m_scoreLimitOverride;
	int m_roundLimit;
	bool m_votingEnabled;
	int m_votingCooldown;
	int m_votingMinVotes;
	float m_votingRatio;
	CCorpseManager* m_pCorpseManager;
	std::vector<SGameRulesListener*> m_rulesListeners;
	unsigned m_ignoreEntityNextCollision;
	bool m_timeOfDayInitialized;
	std::vector<unsigned int> m_pendingActorsToBeKnockedDown;
	CGameRules::SMigratingPlayerInfo* m_pMigratingPlayerInfo;
	unsigned m_migratingPlayerMaxCount;
	static constexpr const int MAX_PLAYERS = 16;
	unsigned m_migratedPlayerChannels[16];
	CGameRules::SHostMigrationClientRequestParams* m_pHostMigrationParams;
	CGameRules::SHostMigrationClientControlledParams* m_pHostMigrationClientParams;
	bool m_bPendingLoadoutChange;
	bool m_levelLoaded;
	bool m_hasWinningKill;
	bool m_sessionStatisticsSaved;
	bool m_bIsTeamGame;
	bool m_bClientKickVoteActive;
	bool m_bClientKickVoteSent;
	bool m_bClientKickVotedFor;
	CTimeValue m_ClientCooldownEndTime;
	IGameRulesStateModule* m_stateModule;
	IGameRulesSpawningModule* m_spawningModule;
	IGameRulesDamageHandlingModule* m_damageHandlingModule;
	std::vector<unsigned int> m_entityEventDoneListeners;
	std::vector<IGameRulesClientConnectionListener*> m_clientConnectionListeners;
	std::vector<IGameRulesTeamChangedListener*> m_teamChangedListeners;
	std::vector<IGameRulesKillListener*> m_killListeners;
	std::vector<IGameRulesModuleRMIListener*> m_moduleRMIListenersVec;
	std::vector<IGameRulesRevivedListener*> m_revivedListenersVec;
	std::vector<IGameRulesRoundsListener*> m_roundsListenersVec;
	std::vector<IGameRulesClientScoreListener*> m_clientScoreListenersVec;
	float m_idleTime;
	CGameRules::SEquipmentLoadOutPreCacheCallback m_equipmentLoadOutPreCacheCallback;
	std::vector<unsigned int> m_hostMigrationCachedEntities;
	std::vector<unsigned int> m_forbiddenAreas;
	std::vector<CGameRules::SForbiddenAreaHelper> m_forbiddenAreaHelpers;
	std::vector<_smart_ptr<ICharacterInstance>> m_cachedCharacterInstances;
	std::vector<_smart_ptr<IParticleEffect>> m_cachedParticleEffects;
	std::vector<_smart_ptr<ITexture>> m_cachedFlashTextures;
	std::vector<_smart_ptr<ITexture>> m_cachedTextures;
	int m_numLocalPlayerRevives;
	bool m_bHasCalledEnteredGame;
	bool m_bCanUpdateSkillRanking;
	bool m_bClientTeamInLead;
	bool m_bLevelNameCheckNeeded;
	bool m_isRestarting;
	CryFixedStringT<64> m_waitingForPlayerMessage1;
	CryFixedStringT<64> m_waitingForPlayerMessage2;
	int m_numRequiredPlayers;
	int m_previousNumRequiredPlayers;
	float m_finishPrematchTime;
	CGameRules::EPrematchState m_prematchState;
	CTimeValue m_timeStartedWaitingForBalancedGame;
	static inline auto s_pC4Explosive = PreyGlobal<IEntityClass*>(0x2D8DA90);
	static inline auto s_pSmartMineClass = PreyGlobal<IEntityClass*>(0x2D8DA98);
	static inline auto s_pTurretClass = PreyGlobal<IEntityClass*>(0x2D8DAA0);
	std::map<string, XmlNodeRef> m_cachedXmlNodesMap;
	EDisconnectionCause m_svLastTeamDiscoCause[2];
	std::set<CryUserID> m_participatingUsers;
	unsigned m_uSecurity;
	bool m_bSecurityInitialized;
	bool m_bIntroSequenceRegistered;
	bool m_bIntroCurrentlyPlaying;
	bool m_gameStarted;
	bool m_bIntroSequenceCompletedPlaying;
	ArkGameRules m_arkGameRules;

	CGameRules();
	virtual ~CGameRules();
	virtual bool Init(IGameObject* pGameObject);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool OnBeginCutScene(IAnimSequence* pSeq, bool bResetFX);
	virtual bool OnEndCutScene(IAnimSequence* pSeq);
	virtual bool OnCameraChange(const SCameraParams& cameraParams);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual bool ShouldKeepClient(int channelId, EDisconnectionCause cause, const char* desc) const;
	virtual void PrecacheLevel();
	virtual void PrecacheLevelResource(const char* resourceName, EGameResourceType resourceType);
	virtual XmlNodeRef FindPrecachedXmlFile(const char* sFilename);
	virtual void OnConnect(INetChannel* pNetChannel);
	virtual void OnDisconnect(EDisconnectionCause cause, const char* desc);
	virtual bool OnClientConnect(int channelId, bool isReset);
	virtual void OnClientDisconnect(int channelId, EDisconnectionCause cause, const char* desc, bool keepClient);
	virtual bool OnClientEnteredGame(int channelId, bool isReset);
	virtual void OnEntitySpawn(IEntity* pEntity);
	virtual void OnEntityRemoved(IEntity* pEntity);
	virtual void OnEntityReused(IEntity* pEntity, SEntitySpawnParams& params, unsigned prevId);
	virtual void SendTextMessage(ETextMessageType type, const char* msg, unsigned to, int channelId, const char* p0, const char* p1, const char* p2, const char* p3);
	virtual void SendChatMessage(EChatMessageType type, unsigned sourceId, unsigned targetId, const char* msg);
	virtual void ClientHit(const HitInfo& hitInfo);
	virtual void ServerHit(const HitInfo& hitInfo);
	virtual int GetHitTypeId(const unsigned crc) const;
	virtual int GetHitTypeId(const char* type) const;
	virtual const char* GetHitType(int id) const;
	const HitTypeInfo* GetHitTypeInfo(int id) const { return FGetHitTypeInfo(this, id); }
	virtual void CreateEntityRespawnData(unsigned entityId);
	virtual bool HasEntityRespawnData(unsigned entityId) const;
	virtual void ScheduleEntityRespawn(unsigned entityId, bool unique, float timer);
	virtual void AbortEntityRespawn(unsigned entityId, bool destroyData);
	virtual void ScheduleEntityRemoval(unsigned entityId, float timer, bool visibility);
	virtual void AbortEntityRemoval(unsigned entityId);
	virtual void AddHitListener(IHitListener* pHitListener);
	virtual void RemoveHitListener(IHitListener* pHitListener);
	virtual bool OnCollision(const IGameRules::SGameCollision& event);
	virtual void ShowStatus();
	virtual bool IsTimeLimited() const;
	virtual float GetRemainingGameTime() const;
	virtual void SetRemainingGameTime(float seconds);
	virtual void ClearAllMigratingPlayers();
	virtual unsigned SetChannelForMigratingPlayer(const char* name, uint16_t channelID);
	virtual void StoreMigratingPlayer(IActor* pActor);
	virtual void RestoreChannelTeamsFromMigration(IActor* pActor);
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* pNextLevel);
	virtual void OnActionEvent(const SActionEvent& event);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnInitiate(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDisconnectClient(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDemoteToClient(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnPromoteToServer(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReconnectClient(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnFinalise(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual void OnComplete(SHostMigrationInfo& hostMigrationInfo);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnTerminate(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReset(SHostMigrationInfo& hostMigrationInfo, unsigned& state);
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	virtual bool OnInputEvent(const SInputEvent& rInputEvent);
	void OnTimeOfDaySet() { FOnTimeOfDaySet(this); }
	void OnItemDropped(unsigned itemId, unsigned actorId) { FOnItemDropped(this, itemId, actorId); }
	void ForbiddenAreaWarning(bool active, int timer, unsigned targetId) { FForbiddenAreaWarning(this, active, timer, targetId); }
	void IncreasePoints(unsigned who, const SGameRulesScoreInfo& scoreInfo) { FIncreasePoints(this, who, scoreInfo); }
	float GetCurrentGameTime() const { return FGetCurrentGameTime(this); }
	float GetServerTime() const { return FGetServerTime(this); }
	void ClDoSetTeam(int teamId, unsigned entityId) { FClDoSetTeam(this, teamId, entityId); }
	void OnHostMigrationStateChanged() { FOnHostMigrationStateChanged(this); }
	void OnRevive(IActor* pActor) { FOnRevive(this, pActor); }
	void OnKill(IActor* pActor, const HitInfo& hitInfo, bool winningKill, bool firstKill, bool bulletTimeReplay) { FOnKill(this, pActor, hitInfo, winningKill, firstKill, bulletTimeReplay); }
	void OnTextMessage(ETextMessageType type, const char* msg, const char* p0, const char* p1, const char* p2, const char* p3) { FOnTextMessage(this, type, msg, p0, p1, p2, p3); }
	void OnKillMessage(unsigned targetId, unsigned shooterId) { FOnKillMessage(this, targetId, shooterId); }
	void OnActorDeath(CCryActor* pActor) { FOnActorDeath(this, pActor); }
	IActor* GetActorByChannelId(int channelId) const { return FGetActorByChannelId(this, channelId); }
	bool IsRealActor(unsigned actorId) const { return FIsRealActor(this, actorId); }
	IActor* GetActorByEntityId(unsigned entityId) const { return FGetActorByEntityId(this, entityId); }
	int GetChannelId(unsigned entityId) const { return FGetChannelId(this, entityId); }
	IActor* SpawnPlayer(int channelId, const char* name, const char* className, const Vec3& pos, const Ang3& angles) { return FSpawnPlayer(this, channelId, name, className, pos, angles); }
	void ClearInventory(IActor* pActor) { FClearInventory(this, pActor); }
	void RenamePlayer(IActor* pActor, const char* name) { FRenamePlayer(this, pActor, name); }
	string VerifyName(const char* name, IEntity* pEntity) { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FVerifyName(this, reinterpret_cast<string*>(_return_buf_), name, pEntity); }
	bool IsNameTaken(const char* name, IEntity* pEntity) { return FIsNameTaken(this, name, pEntity); }
	void KillPlayer(IActor* pActor, const bool inDropItem, const bool inDoRagdoll, const HitInfo& inHitInfo) { FKillPlayer(this, pActor, inDropItem, inDoRagdoll, inHitInfo); }
	void PostHitKillCleanup(IActor* pActor) { FPostHitKillCleanup(this, pActor); }
	void ChangeTeam(IActor* pActor, int teamId, bool onlyIfUnassigned) { FChangeTeamOv1(this, pActor, teamId, onlyIfUnassigned); }
	void ChangeTeam(IActor* pActor, const char* teamName, bool onlyIfUnassigned) { FChangeTeamOv0(this, pActor, teamName, onlyIfUnassigned); }
	void SvAddTaggedEntity(unsigned shooter, unsigned targetId, float time, CGameRules::ERadarTagReason reason) { FSvAddTaggedEntity(this, shooter, targetId, time, reason); }
	void RequestTagEntity(unsigned shooter, unsigned targetId, float time, CGameRules::ERadarTagReason reason) { FRequestTagEntity(this, shooter, targetId, time, reason); }
	void GetPlayers(std::vector<unsigned int>& players) const { FGetPlayers(this, players); }
	bool IsPlayer(unsigned playerId) const { return FIsPlayer(this, playerId); }
	void Vote(IActor* pActor, bool yes) { FVote(this, pActor, yes); }
	bool CanPlayerSwitchItem(unsigned playerId) { return FCanPlayerSwitchItem(this, playerId); }
	int CreateTeam(const char* name) { return FCreateTeam(this, name); }
	virtual const char* GetTeamName(int teamId) const;
	int GetTeamId(const char* name) const { return FGetTeamId(this, name); }
	void SetPausedGameTimer(bool bPaused, EGameOverReason reason) { FSetPausedGameTimer(this, bPaused, reason); }
	void ClientScoreEvent(int8_t scoreType, int points, EXPReason inReason, int currentTeamScore) { FClientScoreEvent(this, scoreType, points, inReason, currentTeamScore); }
	void SetTeam(int teamId, unsigned entityId, bool clientOnly) { FSetTeam(this, teamId, entityId, clientOnly); }
	int GetTeam(unsigned entityId) const { return FGetTeam(this, entityId); }
	int RegisterHitType(const char* type, const unsigned flags) { return FRegisterHitType(this, type, flags); }
	bool ShouldGiveLocalPlayerHitableFeedbackForEntityClass(const IEntityClass* pEntityClass) const { return FShouldGiveLocalPlayerHitableFeedbackForEntityClass(this, pEntityClass); }
	bool ShouldGiveLocalPlayerHitFeedback(const CGameRules::ELocalPlayerHitFeedbackChannel feedbackChannel, const float damage) const { return FShouldGiveLocalPlayerHitFeedback(this, feedbackChannel, damage); }
	void AddSpawnLocation(unsigned location, bool isInitialSpawn, bool doVisTest, const char* pGroupName) { FAddSpawnLocation(this, location, isInitialSpawn, doVisTest, pGroupName); }
	void RemoveSpawnLocation(unsigned id, bool isInitialSpawn) { FRemoveSpawnLocation(this, id, isInitialSpawn); }
	void EnableSpawnLocation(unsigned location, bool isInitialSpawn, const char* pGroupName) { FEnableSpawnLocation(this, location, isInitialSpawn, pGroupName); }
	void DisableSpawnLocation(unsigned id, bool isInitialSpawn) { FDisableSpawnLocation(this, id, isInitialSpawn); }
	unsigned GetFirstSpawnLocation(int teamId, unsigned groupId) const { return FGetFirstSpawnLocation(this, teamId, groupId); }
	void AddSpawnGroup(unsigned groupId) { FAddSpawnGroup(this, groupId); }
	void AddSpawnLocationToSpawnGroup(unsigned groupId, unsigned location) { FAddSpawnLocationToSpawnGroup(this, groupId, location); }
	void RemoveSpawnLocationFromSpawnGroup(unsigned groupId, unsigned location) { FRemoveSpawnLocationFromSpawnGroup(this, groupId, location); }
	void RemoveSpawnGroup(unsigned groupId) { FRemoveSpawnGroup(this, groupId); }
	int GetSpawnGroupCount() const { return FGetSpawnGroupCount(this); }
	unsigned GetSpawnGroup(int idx) const { return FGetSpawnGroup(this, idx); }
	bool IsSpawnGroup(unsigned id) const { return FIsSpawnGroup(this, id); }
	void SetPlayerSpawnGroup(unsigned playerId, unsigned spawnGroupId) { FSetPlayerSpawnGroup(this, playerId, spawnGroupId); }
	void CheckSpawnGroupValidity(unsigned spawnGroupId) { FCheckSpawnGroupValidity(this, spawnGroupId); }
	void Restart() { FRestart(this); }
	void NextLevel() { FNextLevel(this); }
	void OnEndGame() { FOnEndGame(this); }
	void EnteredGame() { FEnteredGame(this); }
	void EntityRevived_NotifyListeners(unsigned entityId) { FEntityRevived_NotifyListeners(this, entityId); }
	void KnockActorDown(unsigned actorEntityId) { FKnockActorDown(this, actorEntityId); }
	void ProcessServerHit(const HitInfo& hitInfo) { FProcessServerHit(this, hitInfo); }
	void ProcessLocalHit(const HitInfo& hitInfo, float fCausedDamage) { FProcessLocalHit(this, hitInfo, fCausedDamage); }
	void UpdateIdleKick(float frametime) { FUpdateIdleKick(this, frametime); }
	void QueueExplosion(const ExplosionInfo& explosionInfo) { FQueueExplosion(this, explosionInfo); }
	void ResetQueuedExplosionsAndHits() { FResetQueuedExplosionsAndHits(this); }
	void DoEntityRespawn(unsigned id) { FDoEntityRespawn(this, id); }
	void UpdateEntitySchedules(float frameTime) { FUpdateEntitySchedules(this, frameTime); }
	void ProcessQueuedExplosions() { FProcessQueuedExplosions(this); }
	void FreezeInput(bool freeze) { FFreezeInput(this, freeze); }
	void PreCacheEquipmentPack(const char* szEquipmentPackName) { FPreCacheEquipmentPack(this, szEquipmentPackName); }
	static INetAtSyncItem* Decode_SvRequestHit(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestHit(ser, pID, pChannel); }
	bool Handle_SvRequestHit(const HitInfo& params, INetChannel* pNetChannel) { return FHandle_SvRequestHit(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClExplosion(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClExplosion(ser, pID, pChannel); }
	bool Handle_ClExplosion(const ExplosionInfo& params, INetChannel* pNetChannel) { return FHandle_ClExplosion(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClProjectileExplosion(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClProjectileExplosion(ser, pID, pChannel); }
	bool Handle_ClProjectileExplosion(const SProjectileExplosionParams& params, INetChannel* pNetChannel) { return FHandle_ClProjectileExplosion(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClProjectileExplosion_Impact(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClProjectileExplosion_Impact(ser, pID, pChannel); }
	bool Handle_ClProjectileExplosion_Impact(const SProjectileExplosionParams_Impact& params, INetChannel* pNetChannel) { return FHandle_ClProjectileExplosion_Impact(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClTaggedEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClTaggedEntity(ser, pID, pChannel); }
	bool Handle_ClTaggedEntity(const CGameRules::TempRadarTaggingParams& params, INetChannel* pNetChannel) { return FHandle_ClTaggedEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestTagEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestTagEntity(ser, pID, pChannel); }
	bool Handle_SvRequestTagEntity(const CGameRules::TempRadarTaggingParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestTagEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestRename(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestRename(ser, pID, pChannel); }
	bool Handle_SvRequestRename(const CGameRules::RenameEntityParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestRename(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClRenameEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClRenameEntity(ser, pID, pChannel); }
	bool Handle_ClRenameEntity(const CGameRules::RenameEntityParams& params, INetChannel* pNetChannel) { return FHandle_ClRenameEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestChangeTeam(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestChangeTeam(ser, pID, pChannel); }
	bool Handle_SvRequestChangeTeam(const CGameRules::ChangeTeamParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestChangeTeam(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestSpectatorMode(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestSpectatorMode(ser, pID, pChannel); }
	bool Handle_SvRequestSpectatorMode(const CGameRules::SpectatorModeParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestSpectatorMode(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClTeamFull(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClTeamFull(ser, pID, pChannel); }
	bool Handle_ClTeamFull(const CGameRules::UInt8Param& params, INetChannel* pNetChannel) { return FHandle_ClTeamFull(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClSetTeam(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClSetTeam(ser, pID, pChannel); }
	bool Handle_ClSetTeam(const CGameRules::SetTeamParams& params, INetChannel* pNetChannel) { return FHandle_ClSetTeam(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClTextMessage(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClTextMessage(ser, pID, pChannel); }
	bool Handle_ClTextMessage(const CGameRules::TextMessageParams& params, INetChannel* pNetChannel) { return FHandle_ClTextMessage(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClProcessHit(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClProcessHit(ser, pID, pChannel); }
	bool Handle_ClProcessHit(const CGameRules::ProcessHitParams& params, INetChannel* pNetChannel) { return FHandle_ClProcessHit(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClPostInit(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClPostInit(ser, pID, pChannel); }
	bool Handle_ClPostInit(const CGameRules::PostInitParams& params, INetChannel* pNetChannel) { return FHandle_ClPostInit(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClSetGameStartedTime(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClSetGameStartedTime(ser, pID, pChannel); }
	bool Handle_ClSetGameStartedTime(const CGameRules::SetGameTimeParams& params, INetChannel* pNetChannel) { return FHandle_ClSetGameStartedTime(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClSetGameStartTimer(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClSetGameStartTimer(ser, pID, pChannel); }
	bool Handle_ClSetGameStartTimer(const CGameRules::SetGameTimeParams& params, INetChannel* pNetChannel) { return FHandle_ClSetGameStartTimer(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvVote(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvVote(ser, pID, pChannel); }
	bool Handle_SvVote(const CGameRules::NoParams& params, INetChannel* pNetChannel) { return FHandle_SvVote(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvVoteNo(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvVoteNo(ser, pID, pChannel); }
	bool Handle_SvVoteNo(const CGameRules::NoParams& params, INetChannel* pNetChannel) { return FHandle_SvVoteNo(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClEnteredGame(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClEnteredGame(ser, pID, pChannel); }
	bool Handle_ClEnteredGame(const CGameRules::NoParams& params, INetChannel* pNetChannel) { return FHandle_ClEnteredGame(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClVictoryTeam(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClVictoryTeam(ser, pID, pChannel); }
	bool Handle_ClVictoryTeam(const CGameRules::VictoryTeamParams& params, INetChannel* pNetChannel) { return FHandle_ClVictoryTeam(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClVictoryPlayer(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClVictoryPlayer(ser, pID, pChannel); }
	bool Handle_ClVictoryPlayer(const CGameRules::VictoryPlayerParams& params, INetChannel* pNetChannel) { return FHandle_ClVictoryPlayer(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClAddPoints(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClAddPoints(ser, pID, pChannel); }
	bool Handle_ClAddPoints(const CGameRules::ScoreChangeParams& params, INetChannel* pNetChannel) { return FHandle_ClAddPoints(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvRequestRevive(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvRequestRevive(ser, pID, pChannel); }
	bool Handle_SvRequestRevive(const CGameRules::ServerReviveParams& params, INetChannel* pNetChannel) { return FHandle_SvRequestRevive(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvSetEquipmentLoadout(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvSetEquipmentLoadout(ser, pID, pChannel); }
	bool Handle_SvSetEquipmentLoadout(const CGameRules::EquipmentLoadoutParams& params, INetChannel* pNetChannel) { return FHandle_SvSetEquipmentLoadout(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClModuleRMISingleEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClModuleRMISingleEntity(ser, pID, pChannel); }
	bool Handle_ClModuleRMISingleEntity(const CGameRules::SModuleRMIEntityParams& params, INetChannel* pNetChannel) { return FHandle_ClModuleRMISingleEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClModuleRMIDoubleEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClModuleRMIDoubleEntity(ser, pID, pChannel); }
	bool Handle_ClModuleRMIDoubleEntity(const CGameRules::SModuleRMITwoEntityParams& params, INetChannel* pNetChannel) { return FHandle_ClModuleRMIDoubleEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClModuleRMIEntityWithTime(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClModuleRMIEntityWithTime(ser, pID, pChannel); }
	bool Handle_ClModuleRMIEntityWithTime(const CGameRules::SModuleRMIEntityTimeParams& params, INetChannel* pNetChannel) { return FHandle_ClModuleRMIEntityWithTime(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvModuleRMISingleEntity(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvModuleRMISingleEntity(ser, pID, pChannel); }
	bool Handle_SvModuleRMISingleEntity(const CGameRules::SModuleRMIEntityParams& params, INetChannel* pNetChannel) { return FHandle_SvModuleRMISingleEntity(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvSuccessfulFlashBang(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvSuccessfulFlashBang(ser, pID, pChannel); }
	bool Handle_SvSuccessfulFlashBang(const CGameRules::SSuccessfulFlashBangParams& params, INetChannel* pNetChannel) { return FHandle_SvSuccessfulFlashBang(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClNetConsoleCommand(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClNetConsoleCommand(ser, pID, pChannel); }
	bool Handle_ClNetConsoleCommand(const CGameRules::NetConsoleCommandParams& params, INetChannel* pNetChannel) { return FHandle_ClNetConsoleCommand(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvHostMigrationRequestSetup(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvHostMigrationRequestSetup(ser, pID, pChannel); }
	bool Handle_SvHostMigrationRequestSetup(const CGameRules::SHostMigrationClientRequestParams& params, INetChannel* pNetChannel) { return FHandle_SvHostMigrationRequestSetup(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClHostMigrationFinished(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClHostMigrationFinished(ser, pID, pChannel); }
	bool Handle_ClHostMigrationFinished(const CGameRules::NoParams& params, INetChannel* pNetChannel) { return FHandle_ClHostMigrationFinished(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClMidMigrationJoin(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClMidMigrationJoin(ser, pID, pChannel); }
	bool Handle_ClMidMigrationJoin(const CGameRules::SMidMigrationJoinParams& params, INetChannel* pNetChannel) { return FHandle_ClMidMigrationJoin(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClHostMigrationPlayerJoined(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClHostMigrationPlayerJoined(ser, pID, pChannel); }
	bool Handle_ClHostMigrationPlayerJoined(const CGameRules::EntityParams& params, INetChannel* pNetChannel) { return FHandle_ClHostMigrationPlayerJoined(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClPredictionFailed(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClPredictionFailed(ser, pID, pChannel); }
	bool Handle_ClPredictionFailed(const CGameRules::SPredictionParams& params, INetChannel* pNetChannel) { return FHandle_ClPredictionFailed(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvModuleRMIOnAction(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvModuleRMIOnAction(ser, pID, pChannel); }
	bool Handle_SvModuleRMIOnAction(const CGameRules::SModuleRMISvClientActionParams& params, INetChannel* pNetChannel) { return FHandle_SvModuleRMIOnAction(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClUpdateRespawnData(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClUpdateRespawnData(ser, pID, pChannel); }
	bool Handle_ClUpdateRespawnData(const CGameRules::SRespawnUpdateParams& params, INetChannel* pNetChannel) { return FHandle_ClUpdateRespawnData(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClTrackViewSynchAnimations(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClTrackViewSynchAnimations(ser, pID, pChannel); }
	bool Handle_ClTrackViewSynchAnimations(const CGameRules::STrackViewParameters& params, INetChannel* pNetChannel) { return FHandle_ClTrackViewSynchAnimations(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_SvTrackViewRequestAnimation(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_SvTrackViewRequestAnimation(ser, pID, pChannel); }
	bool Handle_SvTrackViewRequestAnimation(const CGameRules::STrackViewRequestParameters& params, INetChannel* pNetChannel) { return FHandle_SvTrackViewRequestAnimation(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClPathFollowingAttachToPath(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClPathFollowingAttachToPath(ser, pID, pChannel); }
	bool Handle_ClPathFollowingAttachToPath(const SPathFollowingAttachToPathParameters& params, INetChannel* pNetChannel) { return FHandle_ClPathFollowingAttachToPath(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClActivateHitIndicator(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClActivateHitIndicator(ser, pID, pChannel); }
	bool Handle_ClActivateHitIndicator(const CGameRules::ActivateHitIndicatorParams& params, INetChannel* pNetChannel) { return FHandle_ClActivateHitIndicator(this, params, pNetChannel); }
	static INetAtSyncItem* Decode_ClStartingPrematchCountDown(TSerialize ser, unsigned* pID, INetChannel* pChannel) { return FDecode_ClStartingPrematchCountDown(ser, pID, pChannel); }
	bool Handle_ClStartingPrematchCountDown(const CGameRules::StartingPrematchCountDownParams& params, INetChannel* pNetChannel) { return FHandle_ClStartingPrematchCountDown(this, params, pNetChannel); }
	void AddGameRulesListener(SGameRulesListener* pRulesListener) { FAddGameRulesListener(this, pRulesListener); }
	void RemoveGameRulesListener(SGameRulesListener* pRulesListener) { FRemoveGameRulesListener(this, pRulesListener); }
	CGameRules::SEntityRespawnData* GetEntityRespawnDataByHashId(CryHashStringId nameHashId) { return FGetEntityRespawnDataByHashId(this, nameHashId); }
	static void CmdDebugTeams(IConsoleCmdArgs* pArgs) { FCmdDebugTeams(pArgs); }
	static void CmdGiveScore(IConsoleCmdArgs* pArgs) { FCmdGiveScore(pArgs); }
	bool NetSerializeTelemetry(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags) { return FNetSerializeTelemetry(this, ser, aspect, profile, flags); }
	void ChangePrematchState(CGameRules::EPrematchState newState) { FChangePrematchState(this, newState); }
	void CreateScriptHitInfo(SmartScriptTable& scriptHitInfo, const HitInfo& hitInfo) const { FCreateScriptHitInfo(this, scriptHitInfo, hitInfo); }
	static void CreateHitInfoFromScript(const SmartScriptTable& scriptHitInfo, HitInfo& hitInfo) { FCreateHitInfoFromScript(scriptHitInfo, hitInfo); }
	void UpdateGameRulesCvars() { FUpdateGameRulesCvars(this); }
	void ClearRemoveEntityEventListeners() { FClearRemoveEntityEventListeners(this); }
	void SaveSessionStatistics(float delay) { FSaveSessionStatistics(this, delay); }
	void RegisterKillListener(IGameRulesKillListener* pListener) { FRegisterKillListener(this, pListener); }
	void UnRegisterKillListener(IGameRulesKillListener* pListener) { FUnRegisterKillListener(this, pListener); }
	void OwnClientConnected_NotifyListeners() { FOwnClientConnected_NotifyListeners(this); }
	void OnEntityKilled(const HitInfo& hitInfo) { FOnEntityKilled(this, hitInfo); }
	void OnEntityBroken(const unsigned _brokenEntityId) { FOnEntityBroken(this, _brokenEntityId); }
	void AddForbiddenArea(unsigned entityId) { FAddForbiddenArea(this, entityId); }
	void RemoveForbiddenArea(unsigned entityId) { FRemoveForbiddenArea(this, entityId); }
	void OnLocalPlayerRevived() { FOnLocalPlayerRevived(this); }
	void PreCacheItemResources(const char* itemName) { FPreCacheItemResources(this, itemName); }
	void PrecacheList(XmlNodeRef precacheListNode) { FPrecacheList(this, precacheListNode); }
	void PrecacheFromXml(const char* xmlPath) { FPrecacheFromXml(this, xmlPath); }
	bool SetTeam_Common(int teamId, unsigned entityId, bool& bIsPlayer) { return FSetTeam_Common(this, teamId, entityId, bIsPlayer); }
	void HostMigrationFindDynamicEntities(std::vector<unsigned int>& results) { FHostMigrationFindDynamicEntities(this, results); }
	void HostMigrationRemoveDuplicateDynamicEntities() { FHostMigrationRemoveDuplicateDynamicEntities(this); }
	void SetupForbiddenAreaShapesHelpers() { FSetupForbiddenAreaShapesHelpers(this); }

#if 0
	const char* GetHitType(int _arg0_, const char* _arg1_) const;
	uint8_t GetRequiredPlayerTypesForGameMode();
	bool GameModeRequiresDifferentCloakedChatter();
	uint8_t GetRequiredPlayerTypeForConversation(int _arg0_, int _arg1_);
	unsigned GetSecurity();
	bool IsSecurityInitialized();
	void OnEntityRespawn(IEntity* _arg0_);
	void OnPickupEntityAttached(unsigned _arg0_, unsigned _arg1_, const char* _arg2_);
	void OnPickupEntityDetached(unsigned _arg0_, unsigned _arg1_, bool _arg2_, const char* _arg3_);
	void OnItemPickedUp(unsigned _arg0_, unsigned _arg1_);
	void ResetGameTime();
	float GetRemainingGameTimeNotZeroCapped() const;
	bool GameTimeValid() const;
	void ResetGameStartTimer(float _arg0_);
	float GetRemainingStartTimer() const;
	void OnHostMigrationGotLocalPlayer(CPlayer* _arg0_);
	void OnUserLeftLobby(int _arg0_);
	int GetScoreLimit() const;
	int GetRoundLimit() const;
	float GetTimeLimit() const;
	int GetMigratingPlayerIndex(unsigned _arg0_);
	void RegisterConsoleCommands(IConsole* _arg0_);
	void UnregisterConsoleCommands(IConsole* _arg0_);
	void RegisterConsoleVars(IConsole* _arg0_);
	void UnregisterConsoleVars(IConsole* _arg0_);
	const char* GetActorNameByEntityId(unsigned _arg0_) const;
	const char* GetActorName(IActor* _arg0_) const;
	CCorpseManager* GetCorpseManager() const;
	int GetNumChannels() const;
	const std::vector<int>* GetChannelIds() const;
	void ShowScores(bool _arg0_);
	bool IsLevelLoaded() const;
	void SetIntroSequenceRegistered(const bool _arg0_);
	bool IsIntroSequenceRegistered() const;
	void SetIntroSequenceCurrentlyPlaying(bool _arg0_);
	bool IsIntroSequenceCurrentlyPlaying();
	bool IntroSequenceHasCompletedPlaying();
	void SetIntroSequenceHasCompletedPlaying();
	int GetPlayerCountClient() const;
	int GetLivingPlayerCount() const;
	float GetFriendlyFireRatio() const;
	int GetSpectatorCount(bool _arg0_) const;
	unsigned GetPlayer(int _arg0_);
	void GetPlayersClient(std::vector<unsigned int>& _arg0_);
	bool IsPlayerInGame(unsigned _arg0_) const;
	bool IsPlayerActivelyPlaying(unsigned _arg0_, bool _arg1_) const;
	bool IsChannelInGame(int _arg0_) const;
	void UpdateKickVoteStatus(unsigned _arg0_);
	void EndVoting(bool _arg0_);
	int GetTotalAlivePlayerCount(const unsigned _arg0_) const;
	bool RulesUseWeaponLoadouts();
	void OnActorAction(IActor* _arg0_, const CCryName& _arg1_, int _arg2_, float _arg3_);
	void SetAllPlayerVisibility(const bool _arg0_, const bool _arg1_);
	void CreateTeamAlias(const char* _arg0_, int _arg1_);
	void RemoveTeam(int _arg0_);
	int GetTeamCount() const;
	int GetTeamPlayerCount(int _arg0_, bool _arg1_) const;
	int GetTeamPlayerCountWithStatFlags(const int _arg0_, const int _arg1_, const bool _arg2_);
	unsigned GetTeamPlayer(int _arg0_, int _arg1_);
	unsigned GetTeamActivePlayer(int _arg0_, int _arg1_) const;
	int GetTeamsScore(int _arg0_) const;
	void SetTeamsScore(int _arg0_, int _arg1_);
	int GetTeamRoundScore(int _arg0_) const;
	void SetTeamRoundScore(int _arg0_, int _arg1_);
	int SvGetTeamsScoreScoredThisRound(int _arg0_) const;
	void SvCacheRoundStartTeamScores();
	void ActorActionInformOnAction(const CCryName& _arg0_, int _arg1_, float _arg2_);
	void GetTeamPlayers(int _arg0_, std::vector<unsigned int>& _arg1_);
	int GetChannelTeam(int _arg0_) const;
	CGameRules::eThreatRating GetThreatRating(const unsigned _arg0_, const unsigned _arg1_) const;
	CGameRules::eThreatRating GetThreatRatingByTeam(const int8_t _arg0_, const int8_t _arg1_) const;
	void ClientTeamScoreFeedback(int _arg0_, int _arg1_, int _arg2_);
	bool IsKickVoteActive() const;
	bool CanSendKickVote() const;
	bool ClientKickVotedFor() const;
	bool HasVotingCooldownEnded(float& _arg0_) const;
	bool IsTeamGame() const;
	bool IndividualScore() const;
	bool ShowRoundsAsDraw() const;
	bool IsValidPlayerTeam(int _arg0_) const;
	int GetHitTypesCount() const;
	bool ShouldGiveLocalPlayerHitableFeedbackOnCrosshairHoverForEntityClass(const IEntityClass* _arg0_) const;
	int GetSpawnLocationCount() const;
	int GetEnemyTeamId(int _arg0_) const;
	bool IsSpawnUsed(const unsigned _arg0_);
	unsigned GetSpawnLocationGroup(unsigned _arg0_) const;
	void GetSpawnGroups(std::vector<unsigned int>& _arg0_) const;
	bool AllowNullSpawnGroups() const;
	void RequestSpawnGroup(unsigned _arg0_);
	unsigned GetPlayerSpawnGroup(IActor* _arg0_);
	void ResetEntities();
	void EndGameNear(unsigned _arg0_);
	void ClientDisconnect_NotifyListeners(unsigned _arg0_);
	void ClientEnteredGame_NotifyListeners(unsigned _arg0_);
	void OnActorDeath_NotifyListeners(CCryActor* _arg0_);
	void SvOnTimeLimitExpired_NotifyListeners();
	void SvSurvivorCountRefresh_NotifyListeners(int _arg0_, const unsigned* _arg1_, int _arg2_);
	void ClPlayerStatsNetSerializeReadDeath_NotifyListeners(const SGameRulesPlayerStat* _arg0_, uint16_t _arg1_, uint8_t _arg2_);
	void OnRoundStart_NotifyListeners();
	void OnRoundEnd_NotifyListeners();
	void OnSuddenDeath_NotifyListeners();
	void ClRoundsNetSerializeReadState_NotifyListeners(int _arg0_, int _arg1_);
	void OnRoundAboutToStart_NotifyListeners();
	void OnPrematchEnd_NotifyListeners();
	void UpdateNetLimbo();
	void CullEntitiesInExplosion(const ExplosionInfo& _arg0_);
	void ClientExplosion(SExplosionContainer& _arg0_);
	void ProjectileExplosion(const SProjectileExplosionParams& _arg0_);
	void FlushEntitySchedules();
	void ClearExplosion(SExplosionContainer* _arg0_);
	void ProcessServerExplosion(SExplosionContainer& _arg0_);
	void GetEntitiesToSkipByExplosion(const ExplosionInfo& _arg0_, IPhysicalEntity* * _arg1_, int& _arg2_) const;
	void SetEntityToIgnore(unsigned _arg0_);
	void PlayerPosForRespawn(CPlayer* _arg0_, bool _arg1_);
	bool IsGameRulesClass(const char* _arg0_);
	bool IsMultiplayerDeathmatch();
	bool IsMultiplayerCampaign();
	static const CGameRules::MethodInfo_SvRequestHit& SvRequestHit();
	static const CGameRules::MethodInfo_ClExplosion& ClExplosion();
	static const CGameRules::MethodInfo_ClProjectileExplosion& ClProjectileExplosion();
	static const CGameRules::MethodInfo_ClProjectileExplosion_Impact& ClProjectileExplosion_Impact();
	static const CGameRules::MethodInfo_ClTaggedEntity& ClTaggedEntity();
	static const CGameRules::MethodInfo_SvRequestTagEntity& SvRequestTagEntity();
	static const CGameRules::MethodInfo_SvRequestRename& SvRequestRename();
	static const CGameRules::MethodInfo_ClRenameEntity& ClRenameEntity();
	static const CGameRules::MethodInfo_SvRequestChangeTeam& SvRequestChangeTeam();
	static const CGameRules::MethodInfo_SvRequestSpectatorMode& SvRequestSpectatorMode();
	static const CGameRules::MethodInfo_ClTeamFull& ClTeamFull();
	static const CGameRules::MethodInfo_ClSetTeam& ClSetTeam();
	static const CGameRules::MethodInfo_ClTextMessage& ClTextMessage();
	static const CGameRules::MethodInfo_ClProcessHit& ClProcessHit();
	static const CGameRules::MethodInfo_ClPostInit& ClPostInit();
	static const CGameRules::MethodInfo_ClSetGameStartedTime& ClSetGameStartedTime();
	static const CGameRules::MethodInfo_ClSetGameStartTimer& ClSetGameStartTimer();
	static const CGameRules::MethodInfo_SvVote& SvVote();
	static const CGameRules::MethodInfo_SvVoteNo& SvVoteNo();
	static const CGameRules::MethodInfo_ClEnteredGame& ClEnteredGame();
	static const CGameRules::MethodInfo_ClVictoryTeam& ClVictoryTeam();
	static const CGameRules::MethodInfo_ClVictoryPlayer& ClVictoryPlayer();
	static const CGameRules::MethodInfo_ClAddPoints& ClAddPoints();
	static const CGameRules::MethodInfo_SvRequestRevive& SvRequestRevive();
	static const CGameRules::MethodInfo_SvSetEquipmentLoadout& SvSetEquipmentLoadout();
	static const CGameRules::MethodInfo_ClModuleRMISingleEntity& ClModuleRMISingleEntity();
	static const CGameRules::MethodInfo_ClModuleRMIDoubleEntity& ClModuleRMIDoubleEntity();
	static const CGameRules::MethodInfo_ClModuleRMIEntityWithTime& ClModuleRMIEntityWithTime();
	static const CGameRules::MethodInfo_SvModuleRMISingleEntity& SvModuleRMISingleEntity();
	static const CGameRules::MethodInfo_SvSuccessfulFlashBang& SvSuccessfulFlashBang();
	static const CGameRules::MethodInfo_ClNetConsoleCommand& ClNetConsoleCommand();
	static const CGameRules::MethodInfo_SvHostMigrationRequestSetup& SvHostMigrationRequestSetup();
	static const CGameRules::MethodInfo_ClHostMigrationFinished& ClHostMigrationFinished();
	static const CGameRules::MethodInfo_ClMidMigrationJoin& ClMidMigrationJoin();
	static const CGameRules::MethodInfo_ClHostMigrationPlayerJoined& ClHostMigrationPlayerJoined();
	static const CGameRules::MethodInfo_ClPredictionFailed& ClPredictionFailed();
	static const CGameRules::MethodInfo_SvModuleRMIOnAction& SvModuleRMIOnAction();
	static INetAtSyncItem* Decode_SvAfterMatchAwardsWorking(TSerialize _arg0_, unsigned* _arg1_, INetChannel* _arg2_);
	bool Handle_SvAfterMatchAwardsWorking(const CGameRules::SAfterMatchAwardWorkingsParams& _arg0_, INetChannel* _arg1_);
	static const CGameRules::MethodInfo_SvAfterMatchAwardsWorking& SvAfterMatchAwardsWorking();
	static INetAtSyncItem* Decode_ClAfterMatchAwards(TSerialize _arg0_, unsigned* _arg1_, INetChannel* _arg2_);
	bool Handle_ClAfterMatchAwards(const CGameRules::SAfterMatchAwardsParams& _arg0_, INetChannel* _arg1_);
	static const CGameRules::MethodInfo_ClAfterMatchAwards& ClAfterMatchAwards();
	static const CGameRules::MethodInfo_ClUpdateRespawnData& ClUpdateRespawnData();
	static const CGameRules::MethodInfo_ClTrackViewSynchAnimations& ClTrackViewSynchAnimations();
	static const CGameRules::MethodInfo_SvTrackViewRequestAnimation& SvTrackViewRequestAnimation();
	static const CGameRules::MethodInfo_ClPathFollowingAttachToPath& ClPathFollowingAttachToPath();
	static const CGameRules::MethodInfo_ClActivateHitIndicator& ClActivateHitIndicator();
	static const CGameRules::MethodInfo_ClStartingPrematchCountDown& ClStartingPrematchCountDown();
	bool IsGameInProgress() const;
	CGameRules::SEntityRespawnData* GetEntityRespawnData(unsigned _arg0_);
	void PrematchRespawn();
	void StartPrematch();
	void SkipPrematch();
	void ForceBalanceTeams();
	static const char* * S_GetGameModeNamesArray();
	EGameMode GetGameMode() const;
	void SuccessfulFlashBang(const ExplosionInfo& _arg0_, float _arg1_);
	void SetPendingLoadoutChange();
	void ClearEntityTeams();
	void InitSessionStatistics();
	void UpdateAffectedEntitiesSet(std::map<IEntity*, float>& _arg0_, const pe_explosion& _arg1_);
	void AddOrUpdateAffectedEntity(std::map<IEntity*, float>& _arg0_, IEntity* _arg1_, float _arg2_);
	void RemoveFriendlyAffectedEntities(const ExplosionInfo& _arg0_, std::map<IEntity*, float>& _arg1_);
	void ChatLog(EChatMessageType _arg0_, unsigned _arg1_, unsigned _arg2_, const char* _arg3_);
	void KnockBackPendingActors();
	bool IsGamemodeScoringEvent(int8_t _arg0_) const;
	void PrepCollision(int _arg0_, int _arg1_, const IGameRules::SGameCollision& _arg2_, IEntity* _arg3_, CGameRules::SCollisionHitInfo& _arg4_);
	void CallScript(IScriptTable* _arg0_, const char* _arg1_);
	IGameRulesStateModule* GetStateModule();
	IGameRulesSpawningModule* GetSpawningModule();
	IGameRulesDamageHandlingModule* GetDamageHandlingModule();
	const ArkGameRules& GetArkGameRules() const;
	void RegisterClientConnectionListener(IGameRulesClientConnectionListener* _arg0_);
	void UnRegisterClientConnectionListener(IGameRulesClientConnectionListener* _arg0_);
	void RegisterTeamChangedListener(IGameRulesTeamChangedListener* _arg0_);
	void UnRegisterTeamChangedListener(IGameRulesTeamChangedListener* _arg0_);
	void RegisterRevivedListener(IGameRulesRevivedListener* _arg0_);
	void UnRegisterRevivedListener(IGameRulesRevivedListener* _arg0_);
	void RegisterRoundsListener(IGameRulesRoundsListener* _arg0_);
	void UnRegisterRoundsListener(IGameRulesRoundsListener* _arg0_);
	void RegisterClientScoreListener(IGameRulesClientScoreListener* _arg0_);
	void UnRegisterClientScoreListener(IGameRulesClientScoreListener* _arg0_);
	int RegisterModuleRMIListener(IGameRulesModuleRMIListener* _arg0_);
	void UnRegisterModuleRMIListener(int _arg0_);
	void OnEntityKilledEarly(const HitInfo& _arg0_);
	void CallEntityScriptFunction(unsigned _arg0_, const char* _arg1_);
	const char* GetEntityName(unsigned _arg0_) const;
	const CGameRules::SHostMigrationClientControlledParams* GetHostMigrationClientParams();
	void SendRMI_SvRequestSpectatorMode(unsigned _arg0_, uint8_t _arg1_, unsigned _arg2_, bool _arg3_, unsigned _arg4_, bool _arg5_);
	void SanityCheckHitInfo(const HitInfo& _arg0_, const char* _arg1_);
	void SanityCheckHitData(const Vec3& _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned _arg3_, uint16_t _arg4_, const char* _arg5_);
	bool IsInsideForbiddenArea(const Vec3& _arg0_, bool _arg1_, IEntity* * _arg2_);
	bool CanCalculateSkillRanking() const;
	float GetGameStartTime() const;
	bool LevelNameCheckNeeded() const;
	void LevelNameCheckDone();
	EDisconnectionCause SvGetLastTeamDiscoCause(const int _arg0_) const;
	EDisconnectionCause SvGetLastDiscoCause() const;
	bool ActorShouldHideCurrentItemInsteadOfDroppingOnDeath(IActor* _arg0_);
	bool GameEndedByWinningKill() const;
	const std::set<CryUserID>& GetParticipatingUsers();
	bool HasGameActuallyStarted() const;
	bool IsPrematchCountDown() const;
	CGameRules::EPrematchState GetPrematchState() const;
	bool IsRestarting() const;
	void CallOnForbiddenAreas(const char* _arg0_);
	bool GetThreatRatingWithoutTeams(const unsigned _arg0_, const unsigned _arg1_, CGameRules::eThreatRating& _arg2_) const;
	void ApplyLoadoutChange();
	bool IsValidName(const char* _arg0_) const;
	void ProcessDeferredMaterialEffects();
	int GetFreeExplosionIndex();
	void CalculateExplosionAffectedEntities(const ExplosionInfo& _arg0_, std::map<IEntity*, float>& _arg1_);
	void FinishMigrationForPlayer(int _arg0_);
	void FakeDisconnectPlayer(unsigned _arg0_);
	void HostMigrationRemoveNonchanneledPlayers();
	void AddEntityEventDoneListener(unsigned _arg0_);
	void RemoveEntityEventDoneListener(unsigned _arg0_);
	void RetrieveCurrentHealthAndDeathForTarget(const IEntity* _arg0_, const IActor* _arg1_, float* _arg2_, bool* _arg3_) const;
#endif

	static inline auto FCGameRulesOv1 = PreyFunction<void(CGameRules* const _this)>(0x183A960);
	static inline auto FBitNotCGameRules = PreyFunction<void(CGameRules* const _this)>(0x183B630);
	static inline auto FInit = PreyFunction<bool(CGameRules* const _this, IGameObject* pGameObject)>(0x1840920);
	static inline auto FPostInit = PreyFunction<void(CGameRules* const _this, IGameObject* pGameObject)>(0x1844700);
	static inline auto FInitClient = PreyFunction<void(CGameRules* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CGameRules* const _this, int channelId)>(0x1844880);
	static inline auto FReloadExtension = PreyFunction<bool(CGameRules* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x508E40);
	static inline auto FPostReloadExtension = PreyFunction<void(CGameRules* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CGameRules* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CGameRules* const _this)>(0x1846B70);
	static inline auto FFullSerialize = PreyFunction<void(CGameRules* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CGameRules* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x18415A0);
	static inline auto FPostSerialize = PreyFunction<void(CGameRules* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CGameRules* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CGameRules* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CGameRules* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x1849900);
	static inline auto FHandleEvent = PreyFunction<void(CGameRules* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CGameRules* const _this, SEntityEvent& event)>(0x1846380);
	static inline auto FSetChannelId = PreyFunction<void(CGameRules* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CGameRules* const _this, bool auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CGameRules* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CGameRules* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CGameRules* const _this, ICrySizer* s)>(0x183FC60);
	static inline auto FOnBeginCutScene = PreyFunction<bool(IViewSystemListener* const _this, IAnimSequence* pSeq, bool bResetFX)>(0x1841FF0);
	static inline auto FOnEndCutScene = PreyFunction<bool(IViewSystemListener* const _this, IAnimSequence* pSeq)>(0x1843390);
	static inline auto FOnCameraChange = PreyFunction<bool(IViewSystemListener* const _this, const SCameraParams& cameraParams)>(0x1A302A0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x18444F0);
	static inline auto FShouldKeepClient = PreyFunction<bool(const CGameRules* const _this, int channelId, EDisconnectionCause cause, const char* desc)>(0x1848D20);
	static inline auto FPrecacheLevel = PreyFunction<void(CGameRules* const _this)>(0x18457D0);
	static inline auto FPrecacheLevelResource = PreyFunction<void(CGameRules* const _this, const char* resourceName, EGameResourceType resourceType)>(0x1845CA0);
	static inline auto FFindPrecachedXmlFile = PreyFunction<XmlNodeRef*(CGameRules* const _this, XmlNodeRef* _return_value_, const char* sFilename)>(0x183F500);
	static inline auto FOnConnect = PreyFunction<void(CGameRules* const _this, INetChannel* pNetChannel)>(0x1843140);
	static inline auto FOnDisconnect = PreyFunction<void(CGameRules* const _this, EDisconnectionCause cause, const char* desc)>(0x1843220);
	static inline auto FOnClientConnect = PreyFunction<bool(CGameRules* const _this, int channelId, bool isReset)>(0x1842010);
	static inline auto FOnClientDisconnect = PreyFunction<void(CGameRules* const _this, int channelId, EDisconnectionCause cause, const char* desc, bool keepClient)>(0x1842910);
	static inline auto FOnClientEnteredGame = PreyFunction<bool(CGameRules* const _this, int channelId, bool isReset)>(0x1842CA0);
	static inline auto FOnEntitySpawn = PreyFunction<void(CGameRules* const _this, IEntity* pEntity)>(0x1333E90);
	static inline auto FOnEntityRemoved = PreyFunction<void(CGameRules* const _this, IEntity* pEntity)>(0x18436A0);
	static inline auto FOnEntityReused = PreyFunction<void(CGameRules* const _this, IEntity* pEntity, SEntitySpawnParams& params, unsigned prevId)>(0x18436E0);
	static inline auto FSendTextMessage = PreyFunction<void(CGameRules* const _this, ETextMessageType type, const char* msg, unsigned to, int channelId, const char* p0, const char* p1, const char* p2, const char* p3)>(0x1847A40);
	static inline auto FSendChatMessage = PreyFunction<void(CGameRules* const _this, EChatMessageType type, unsigned sourceId, unsigned targetId, const char* msg)>(0x1333E90);
	static inline auto FClientHit = PreyFunction<void(CGameRules* const _this, const HitInfo& hitInfo)>(0x184BF40);
	static inline auto FServerHit = PreyFunction<void(CGameRules* const _this, const HitInfo& hitInfo)>(0x1854D20);
	static inline auto FGetHitTypeIdOv1 = PreyFunction<int(const CGameRules* const _this, const unsigned crc)>(0x183FAE0);
	static inline auto FGetHitTypeIdOv0 = PreyFunction<int(const CGameRules* const _this, const char* type)>(0x183FBA0);
	static inline auto FGetHitTypeOv1 = PreyFunction<const char* (const CGameRules* const _this, int id)>(0x183FAA0);
	static inline auto FGetHitTypeInfo = PreyFunction<const HitTypeInfo* (const CGameRules* const _this, int id)>(0x183FC30);
	static inline auto FCreateEntityRespawnData = PreyFunction<void(CGameRules* const _this, unsigned entityId)>(0x183DA40);
	static inline auto FHasEntityRespawnData = PreyFunction<bool(const CGameRules* const _this, unsigned entityId)>(0x1840310);
	static inline auto FScheduleEntityRespawn = PreyFunction<void(CGameRules* const _this, unsigned entityId, bool unique, float timer)>(0x1847990);
	static inline auto FAbortEntityRespawn = PreyFunction<void(CGameRules* const _this, unsigned entityId, bool destroyData)>(0x183C100);
	static inline auto FScheduleEntityRemoval = PreyFunction<void(CGameRules* const _this, unsigned entityId, float timer, bool visibility)>(0x1847830);
	static inline auto FAbortEntityRemoval = PreyFunction<void(CGameRules* const _this, unsigned entityId)>(0x183C0A0);
	static inline auto FAddHitListener = PreyFunction<void(CGameRules* const _this, IHitListener* pHitListener)>(0x183C360);
	static inline auto FRemoveHitListener = PreyFunction<void(CGameRules* const _this, IHitListener* pHitListener)>(0x1846CF0);
	static inline auto FOnCollision = PreyFunction<bool(CGameRules* const _this, const IGameRules::SGameCollision& event)>(0x1843010);
	static inline auto FShowStatus = PreyFunction<void(CGameRules* const _this)>(0x1848D50);
	static inline auto FIsTimeLimited = PreyFunction<bool(const CGameRules* const _this)>(0x18411F0);
	static inline auto FGetRemainingGameTime = PreyFunction<float(const CGameRules* const _this)>(0x183FFD0);
	static inline auto FSetRemainingGameTime = PreyFunction<void(CGameRules* const _this, float seconds)>(0x18482F0);
	static inline auto FClearAllMigratingPlayers = PreyFunction<void(CGameRules* const _this)>(0x183CD30);
	static inline auto FSetChannelForMigratingPlayer = PreyFunction<unsigned(CGameRules* const _this, const char* name, uint16_t channelID)>(0x1848080);
	static inline auto FStoreMigratingPlayer = PreyFunction<void(CGameRules* const _this, IActor* pActor)>(0x1849210);
	static inline auto FRestoreChannelTeamsFromMigration = PreyFunction<void(CGameRules* const _this, IActor* pActor)>(0x1847660);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0x1333E90);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0x18444C0);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0x1843D20);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* pNextLevel)>(0x1333E90);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0x1841E90);
	static inline auto FOnInitiate = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x18439C0);
	static inline auto FOnDisconnectClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1CBB0B0);
	static inline auto FOnDemoteToClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x18431C0);
	static inline auto FOnPromoteToServer = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1843EE0);
	static inline auto FOnReconnectClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1844420);
	static inline auto FOnFinalise = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1843700);
	static inline auto FOnComplete = PreyFunction<void(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo)>(0x1843050);
	static inline auto FOnTerminate = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1CBB0B0);
	static inline auto FOnReset = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(IHostMigrationEventListener* const _this, SHostMigrationInfo& hostMigrationInfo, unsigned& state)>(0x1CBB0B0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x1843580);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& rInputEvent)>(0x1843AD0);
	static inline auto FOnTimeOfDaySet = PreyFunction<void(CGameRules* const _this)>(0x1844630);
	static inline auto FOnItemDropped = PreyFunction<void(CGameRules* const _this, unsigned itemId, unsigned actorId)>(0x1333E90);
	static inline auto FForbiddenAreaWarning = PreyFunction<void(CGameRules* const _this, bool active, int timer, unsigned targetId)>(0x183F670);
	static inline auto FIncreasePoints = PreyFunction<void(CGameRules* const _this, unsigned who, const SGameRulesScoreInfo& scoreInfo)>(0x18405C0);
	static inline auto FGetCurrentGameTime = PreyFunction<float(const CGameRules* const _this)>(0x183F9F0);
	static inline auto FGetServerTime = PreyFunction<float(const CGameRules* const _this)>(0x1840030);
	static inline auto FClDoSetTeam = PreyFunction<void(CGameRules* const _this, int teamId, unsigned entityId)>(0x184BF20);
	static inline auto FOnHostMigrationStateChanged = PreyFunction<void(CGameRules* const _this)>(0x18437F0);
	static inline auto FOnRevive = PreyFunction<void(CGameRules* const _this, IActor* pActor)>(0x1333E90);
	static inline auto FOnKill = PreyFunction<void(CGameRules* const _this, IActor* pActor, const HitInfo& hitInfo, bool winningKill, bool firstKill, bool bulletTimeReplay)>(0x1843B30);
	static inline auto FOnTextMessage = PreyFunction<void(CGameRules* const _this, ETextMessageType type, const char* msg, const char* p0, const char* p1, const char* p2, const char* p3)>(0x1844520);
	static inline auto FOnKillMessage = PreyFunction<void(CGameRules* const _this, unsigned targetId, unsigned shooterId)>(0x1333E90);
	static inline auto FOnActorDeath = PreyFunction<void(CGameRules* const _this, CCryActor* pActor)>(0x1841F90);
	static inline auto FGetActorByChannelId = PreyFunction<IActor* (const CGameRules* const _this, int channelId)>(0x183F830);
	static inline auto FIsRealActor = PreyFunction<bool(const CGameRules* const _this, unsigned actorId)>(0x1841110);
	static inline auto FGetActorByEntityId = PreyFunction<IActor* (const CGameRules* const _this, unsigned entityId)>(0x183F970);
	static inline auto FGetChannelId = PreyFunction<int(const CGameRules* const _this, unsigned entityId)>(0x183F9A0);
	static inline auto FSpawnPlayer = PreyFunction<IActor* (CGameRules* const _this, int channelId, const char* name, const char* className, const Vec3& pos, const Ang3& angles)>(0x1848FC0);
	static inline auto FClearInventory = PreyFunction<void(CGameRules* const _this, IActor* pActor)>(0x183CD70);
	static inline auto FRenamePlayer = PreyFunction<void(CGameRules* const _this, IActor* pActor, const char* name)>(0x1846E70);
	static inline auto FVerifyName = PreyFunction<string*(CGameRules* const _this, string* _return_value_, const char* name, IEntity* pEntity)>(0x184A230);
	static inline auto FIsNameTaken = PreyFunction<bool(CGameRules* const _this, const char* name, IEntity* pEntity)>(0x1841020);
	static inline auto FKillPlayer = PreyFunction<void(CGameRules* const _this, IActor* pActor, const bool inDropItem, const bool inDoRagdoll, const HitInfo& inHitInfo)>(0x1841200);
	static inline auto FPostHitKillCleanup = PreyFunction<void(CGameRules* const _this, IActor* pActor)>(0x1333E90);
	static inline auto FChangeTeamOv1 = PreyFunction<void(CGameRules* const _this, IActor* pActor, int teamId, bool onlyIfUnassigned)>(0x1333E90);
	static inline auto FChangeTeamOv0 = PreyFunction<void(CGameRules* const _this, IActor* pActor, const char* teamName, bool onlyIfUnassigned)>(0x183C840);
	static inline auto FSvAddTaggedEntity = PreyFunction<void(CGameRules* const _this, unsigned shooter, unsigned targetId, float time, CGameRules::ERadarTagReason reason)>(0x18494F0);
	static inline auto FRequestTagEntity = PreyFunction<void(CGameRules* const _this, unsigned shooter, unsigned targetId, float time, CGameRules::ERadarTagReason reason)>(0x1847080);
	static inline auto FGetPlayers = PreyFunction<void(const CGameRules* const _this, std::vector<unsigned int>& players)>(0x183FEC0);
	static inline auto FIsPlayer = PreyFunction<bool(const CGameRules* const _this, unsigned playerId)>(0x18410B0);
	static inline auto FVote = PreyFunction<void(CGameRules* const _this, IActor* pActor, bool yes)>(0x1333E90);
	static inline auto FCanPlayerSwitchItem = PreyFunction<bool(CGameRules* const _this, unsigned playerId)>(0x183C4F0);
	static inline auto FCreateTeam = PreyFunction<int(CGameRules* const _this, const char* name)>(0x183EF90);
	static inline auto FGetTeamName = PreyFunction<const char* (const CGameRules* const _this, int teamId)>(0x1840290);
	static inline auto FGetTeamId = PreyFunction<int(const CGameRules* const _this, const char* name)>(0x18401B0);
	static inline auto FSetPausedGameTimer = PreyFunction<void(CGameRules* const _this, bool bPaused, EGameOverReason reason)>(0x1848130);
	static inline auto FClientScoreEvent = PreyFunction<void(CGameRules* const _this, int8_t scoreType, int points, EXPReason inReason, int currentTeamScore)>(0x183D240);
	static inline auto FSetTeam = PreyFunction<void(CGameRules* const _this, int teamId, unsigned entityId, bool clientOnly)>(0x1848360);
	static inline auto FGetTeam = PreyFunction<int(const CGameRules* const _this, unsigned entityId)>(0x1840160);
	static inline auto FRegisterHitType = PreyFunction<int(CGameRules* const _this, const char* type, const unsigned flags)>(0x1846A50);
	static inline auto FShouldGiveLocalPlayerHitableFeedbackForEntityClass = PreyFunction<bool(const CGameRules* const _this, const IEntityClass* pEntityClass)>(0x1848CF0);
	static inline auto FShouldGiveLocalPlayerHitFeedback = PreyFunction<bool(const CGameRules* const _this, const CGameRules::ELocalPlayerHitFeedbackChannel feedbackChannel, const float damage)>(0x1848CD0);
	static inline auto FAddSpawnLocation = PreyFunction<void(CGameRules* const _this, unsigned location, bool isInitialSpawn, bool doVisTest, const char* pGroupName)>(0x183C440);
	static inline auto FRemoveSpawnLocation = PreyFunction<void(CGameRules* const _this, unsigned id, bool isInitialSpawn)>(0x1846DC0);
	static inline auto FEnableSpawnLocation = PreyFunction<void(CGameRules* const _this, unsigned location, bool isInitialSpawn, const char* pGroupName)>(0x183F420);
	static inline auto FDisableSpawnLocation = PreyFunction<void(CGameRules* const _this, unsigned id, bool isInitialSpawn)>(0x183F120);
	static inline auto FGetFirstSpawnLocation = PreyFunction<unsigned(const CGameRules* const _this, int teamId, unsigned groupId)>(0x183FA90);
	static inline auto FAddSpawnGroup = PreyFunction<void(CGameRules* const _this, unsigned groupId)>(0x183C3B0);
	static inline auto FAddSpawnLocationToSpawnGroup = PreyFunction<void(CGameRules* const _this, unsigned groupId, unsigned location)>(0x183C450);
	static inline auto FRemoveSpawnLocationFromSpawnGroup = PreyFunction<void(CGameRules* const _this, unsigned groupId, unsigned location)>(0x1846DD0);
	static inline auto FRemoveSpawnGroup = PreyFunction<void(CGameRules* const _this, unsigned groupId)>(0x1846D40);
	static inline auto FGetSpawnGroupCount = PreyFunction<int(const CGameRules* const _this)>(0x1840150);
	static inline auto FGetSpawnGroup = PreyFunction<unsigned(const CGameRules* const _this, int idx)>(0x1840060);
	static inline auto FIsSpawnGroup = PreyFunction<bool(const CGameRules* const _this, unsigned id)>(0x18411A0);
	static inline auto FSetPlayerSpawnGroup = PreyFunction<void(CGameRules* const _this, unsigned playerId, unsigned spawnGroupId)>(0x1848190);
	static inline auto FCheckSpawnGroupValidity = PreyFunction<void(CGameRules* const _this, unsigned spawnGroupId)>(0x183C930);
	static inline auto FRestart = PreyFunction<void(CGameRules* const _this)>(0x1847470);
	static inline auto FNextLevel = PreyFunction<void(CGameRules* const _this)>(0x1333E90);
	static inline auto FOnEndGame = PreyFunction<void(CGameRules* const _this)>(0x18433B0);
	static inline auto FEnteredGame = PreyFunction<void(CGameRules* const _this)>(0x183F430);
	static inline auto FEntityRevived_NotifyListeners = PreyFunction<void(CGameRules* const _this, unsigned entityId)>(0x183F4A0);
	static inline auto FKnockActorDown = PreyFunction<void(CGameRules* const _this, unsigned actorEntityId)>(0x1333E90);
	static inline auto FProcessServerHit = PreyFunction<void(CGameRules* const _this, const HitInfo& hitInfo)>(0x1852E00);
	static inline auto FProcessLocalHit = PreyFunction<void(CGameRules* const _this, const HitInfo& hitInfo, float fCausedDamage)>(0x1852A90);
	static inline auto FUpdateIdleKick = PreyFunction<void(CGameRules* const _this, float frametime)>(0x1333E90);
	static inline auto FQueueExplosion = PreyFunction<void(CGameRules* const _this, const ExplosionInfo& explosionInfo)>(0x1853070);
	static inline auto FResetQueuedExplosionsAndHits = PreyFunction<void(CGameRules* const _this)>(0x1847370);
	static inline auto FDoEntityRespawn = PreyFunction<void(CGameRules* const _this, unsigned id)>(0x183F130);
	static inline auto FUpdateEntitySchedules = PreyFunction<void(CGameRules* const _this, float frameTime)>(0x1849D30);
	static inline auto FProcessQueuedExplosions = PreyFunction<void(CGameRules* const _this)>(0x1852C30);
	static inline auto FFreezeInput = PreyFunction<void(CGameRules* const _this, bool freeze)>(0x183F7F0);
	static inline auto FPreCacheEquipmentPack = PreyFunction<void(CGameRules* const _this, const char* szEquipmentPackName)>(0x1844F30);
	static inline auto FDecode_SvRequestHit = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850270);
	static inline auto FHandle_SvRequestHit = PreyFunction<bool(CGameRules* const _this, const HitInfo& params, INetChannel* pNetChannel)>(0x1852860);
	static inline auto FDecode_ClExplosion = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184CAE0);
	static inline auto FHandle_ClExplosion = PreyFunction<bool(CGameRules* const _this, const ExplosionInfo& params, INetChannel* pNetChannel)>(0x18519A0);
	static inline auto FDecode_ClProjectileExplosion = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184DF70);
	static inline auto FHandle_ClProjectileExplosion = PreyFunction<bool(CGameRules* const _this, const SProjectileExplosionParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClProjectileExplosion_Impact = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184E2B0);
	static inline auto FHandle_ClProjectileExplosion_Impact = PreyFunction<bool(CGameRules* const _this, const SProjectileExplosionParams_Impact& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClTaggedEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184EC50);
	static inline auto FHandle_ClTaggedEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::TempRadarTaggingParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_SvRequestTagEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850A50);
	static inline auto FHandle_SvRequestTagEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::TempRadarTaggingParams& params, INetChannel* pNetChannel)>(0x18529C0);
	static inline auto FDecode_SvRequestRename = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850510);
	static inline auto FHandle_SvRequestRename = PreyFunction<bool(CGameRules* const _this, const CGameRules::RenameEntityParams& params, INetChannel* pNetChannel)>(0x1852920);
	static inline auto FDecode_ClRenameEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184E4E0);
	static inline auto FHandle_ClRenameEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::RenameEntityParams& params, INetChannel* pNetChannel)>(0x1852010);
	static inline auto FDecode_SvRequestChangeTeam = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18500C0);
	static inline auto FHandle_SvRequestChangeTeam = PreyFunction<bool(CGameRules* const _this, const CGameRules::ChangeTeamParams& params, INetChannel* pNetChannel)>(0x1852820);
	static inline auto FDecode_SvRequestSpectatorMode = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850860);
	static inline auto FHandle_SvRequestSpectatorMode = PreyFunction<bool(CGameRules* const _this, const CGameRules::SpectatorModeParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClTeamFull = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184EE30);
	static inline auto FHandle_ClTeamFull = PreyFunction<bool(CGameRules* const _this, const CGameRules::UInt8Param& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClSetTeam = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184E970);
	static inline auto FHandle_ClSetTeam = PreyFunction<bool(CGameRules* const _this, const CGameRules::SetTeamParams& params, INetChannel* pNetChannel)>(0x1852150);
	static inline auto FDecode_ClTextMessage = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184EF90);
	static inline auto FHandle_ClTextMessage = PreyFunction<bool(CGameRules* const _this, const CGameRules::TextMessageParams& params, INetChannel* pNetChannel)>(0x1852400);
	static inline auto FDecode_ClProcessHit = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184DD30);
	static inline auto FHandle_ClProcessHit = PreyFunction<bool(CGameRules* const _this, const CGameRules::ProcessHitParams& params, INetChannel* pNetChannel)>(0x1851C80);
	static inline auto FDecode_ClPostInit = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184DA20);
	static inline auto FHandle_ClPostInit = PreyFunction<bool(CGameRules* const _this, const CGameRules::PostInitParams& params, INetChannel* pNetChannel)>(0x1851BF0);
	static inline auto FDecode_ClSetGameStartedTime = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184E810);
	static inline auto FHandle_ClSetGameStartedTime = PreyFunction<bool(CGameRules* const _this, const CGameRules::SetGameTimeParams& params, INetChannel* pNetChannel)>(0x1852140);
	static inline auto FDecode_ClSetGameStartTimer = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184E6B0);
	static inline auto FHandle_ClSetGameStartTimer = PreyFunction<bool(CGameRules* const _this, const CGameRules::SetGameTimeParams& params, INetChannel* pNetChannel)>(0x1852110);
	static inline auto FDecode_SvVote = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18510B0);
	static inline auto FHandle_SvVote = PreyFunction<bool(CGameRules* const _this, const CGameRules::NoParams& params, INetChannel* pNetChannel)>(0x1852A10);
	static inline auto FDecode_SvVoteNo = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18511F0);
	static inline auto FHandle_SvVoteNo = PreyFunction<bool(CGameRules* const _this, const CGameRules::NoParams& params, INetChannel* pNetChannel)>(0x1852A50);
	static inline auto FDecode_ClEnteredGame = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184C9A0);
	static inline auto FHandle_ClEnteredGame = PreyFunction<bool(CGameRules* const _this, const CGameRules::NoParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClVictoryTeam = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184F840);
	static inline auto FHandle_ClVictoryTeam = PreyFunction<bool(CGameRules* const _this, const CGameRules::VictoryTeamParams& params, INetChannel* pNetChannel)>(0x18526D0);
	static inline auto FDecode_ClVictoryPlayer = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184F590);
	static inline auto FHandle_ClVictoryPlayer = PreyFunction<bool(CGameRules* const _this, const CGameRules::VictoryPlayerParams& params, INetChannel* pNetChannel)>(0x18526B0);
	static inline auto FDecode_ClAddPoints = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184C7B0);
	static inline auto FHandle_ClAddPoints = PreyFunction<bool(CGameRules* const _this, const CGameRules::ScoreChangeParams& params, INetChannel* pNetChannel)>(0x1851830);
	static inline auto FDecode_SvRequestRevive = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x18506E0);
	static inline auto FHandle_SvRequestRevive = PreyFunction<bool(CGameRules* const _this, const CGameRules::ServerReviveParams& params, INetChannel* pNetChannel)>(0x1852960);
	static inline auto FDecode_SvSetEquipmentLoadout = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850C30);
	static inline auto FHandle_SvSetEquipmentLoadout = PreyFunction<bool(CGameRules* const _this, const CGameRules::EquipmentLoadoutParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClModuleRMISingleEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184D520);
	static inline auto FHandle_ClModuleRMISingleEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::SModuleRMIEntityParams& params, INetChannel* pNetChannel)>(0x1851BB0);
	static inline auto FDecode_ClModuleRMIDoubleEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184D170);
	static inline auto FHandle_ClModuleRMIDoubleEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::SModuleRMITwoEntityParams& params, INetChannel* pNetChannel)>(0x1851B20);
	static inline auto FDecode_ClModuleRMIEntityWithTime = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184D340);
	static inline auto FHandle_ClModuleRMIEntityWithTime = PreyFunction<bool(CGameRules* const _this, const CGameRules::SModuleRMIEntityTimeParams& params, INetChannel* pNetChannel)>(0x1851B60);
	static inline auto FDecode_SvModuleRMISingleEntity = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184FF00);
	static inline auto FHandle_SvModuleRMISingleEntity = PreyFunction<bool(CGameRules* const _this, const CGameRules::SModuleRMIEntityParams& params, INetChannel* pNetChannel)>(0x1851BB0);
	static inline auto FDecode_SvSuccessfulFlashBang = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850DA0);
	static inline auto FHandle_SvSuccessfulFlashBang = PreyFunction<bool(CGameRules* const _this, const CGameRules::SSuccessfulFlashBangParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClNetConsoleCommand = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184D6E0);
	static inline auto FHandle_ClNetConsoleCommand = PreyFunction<bool(CGameRules* const _this, const CGameRules::NetConsoleCommandParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_SvHostMigrationRequestSetup = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184FAD0);
	static inline auto FHandle_SvHostMigrationRequestSetup = PreyFunction<bool(CGameRules* const _this, const CGameRules::SHostMigrationClientRequestParams& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClHostMigrationFinished = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184CD40);
	static inline auto FHandle_ClHostMigrationFinished = PreyFunction<bool(CGameRules* const _this, const CGameRules::NoParams& params, INetChannel* pNetChannel)>(0x18519B0);
	static inline auto FDecode_ClMidMigrationJoin = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184CFE0);
	static inline auto FHandle_ClMidMigrationJoin = PreyFunction<bool(CGameRules* const _this, const CGameRules::SMidMigrationJoinParams& params, INetChannel* pNetChannel)>(0x1851AC0);
	static inline auto FDecode_ClHostMigrationPlayerJoined = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184CE80);
	static inline auto FHandle_ClHostMigrationPlayerJoined = PreyFunction<bool(CGameRules* const _this, const CGameRules::EntityParams& params, INetChannel* pNetChannel)>(0x18519D0);
	static inline auto FDecode_ClPredictionFailed = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184DBD0);
	static inline auto FHandle_ClPredictionFailed = PreyFunction<bool(CGameRules* const _this, const CGameRules::SPredictionParams& params, INetChannel* pNetChannel)>(0x1851C60);
	static inline auto FDecode_SvModuleRMIOnAction = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184FD30);
	static inline auto FHandle_SvModuleRMIOnAction = PreyFunction<bool(CGameRules* const _this, const CGameRules::SModuleRMISvClientActionParams& params, INetChannel* pNetChannel)>(0x18527A0);
	static inline auto FDecode_ClUpdateRespawnData = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184F410);
	static inline auto FHandle_ClUpdateRespawnData = PreyFunction<bool(CGameRules* const _this, const CGameRules::SRespawnUpdateParams& params, INetChannel* pNetChannel)>(0x1852480);
	static inline auto FDecode_ClTrackViewSynchAnimations = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184F240);
	static inline auto FHandle_ClTrackViewSynchAnimations = PreyFunction<bool(CGameRules* const _this, const CGameRules::STrackViewParameters& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_SvTrackViewRequestAnimation = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x1850F50);
	static inline auto FHandle_SvTrackViewRequestAnimation = PreyFunction<bool(CGameRules* const _this, const CGameRules::STrackViewRequestParameters& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClPathFollowingAttachToPath = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184D880);
	static inline auto FHandle_ClPathFollowingAttachToPath = PreyFunction<bool(CGameRules* const _this, const SPathFollowingAttachToPathParameters& params, INetChannel* pNetChannel)>(0x1A302A0);
	static inline auto FDecode_ClActivateHitIndicator = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184C630);
	static inline auto FHandle_ClActivateHitIndicator = PreyFunction<bool(CGameRules* const _this, const CGameRules::ActivateHitIndicatorParams& params, INetChannel* pNetChannel)>(0x18516B0);
	static inline auto FDecode_ClStartingPrematchCountDown = PreyFunction<INetAtSyncItem* (TSerialize ser, unsigned* pID, INetChannel* pChannel)>(0x184EAF0);
	static inline auto FHandle_ClStartingPrematchCountDown = PreyFunction<bool(CGameRules* const _this, const CGameRules::StartingPrematchCountDownParams& params, INetChannel* pNetChannel)>(0x1852170);
	static inline auto FAddGameRulesListener = PreyFunction<void(CGameRules* const _this, SGameRulesListener* pRulesListener)>(0x183C310);
	static inline auto FRemoveGameRulesListener = PreyFunction<void(CGameRules* const _this, SGameRulesListener* pRulesListener)>(0x1846CA0);
	static inline auto FGetEntityRespawnDataByHashId = PreyFunction<CGameRules::SEntityRespawnData* (CGameRules* const _this, CryHashStringId nameHashId)>(0x183FA30);
	static inline auto FCmdDebugTeams = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x183D2D0);
	static inline auto FCmdGiveScore = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x183D4A0);
	static inline auto FNetSerializeTelemetry = PreyFunction<bool(CGameRules* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1841CB0);
	static inline auto FChangePrematchState = PreyFunction<void(CGameRules* const _this, CGameRules::EPrematchState newState)>(0x183C6E0);
	static inline auto FCreateScriptHitInfo = PreyFunction<void(const CGameRules* const _this, SmartScriptTable& scriptHitInfo, const HitInfo& hitInfo)>(0x183E250);
	static inline auto FCreateHitInfoFromScript = PreyFunction<void(const SmartScriptTable& scriptHitInfo, HitInfo& hitInfo)>(0x183DC00);
	static inline auto FUpdateGameRulesCvars = PreyFunction<void(CGameRules* const _this)>(0x184A170);
	static inline auto FClearRemoveEntityEventListeners = PreyFunction<void(CGameRules* const _this)>(0x183D1B0);
	static inline auto FSaveSessionStatistics = PreyFunction<void(CGameRules* const _this, float delay)>(0x18477B0);
	static inline auto FRegisterKillListener = PreyFunction<void(CGameRules* const _this, IGameRulesKillListener* pListener)>(0x1846B20);
	static inline auto FUnRegisterKillListener = PreyFunction<void(CGameRules* const _this, IGameRulesKillListener* pListener)>(0x18498B0);
	static inline auto FOwnClientConnected_NotifyListeners = PreyFunction<void(CGameRules* const _this)>(0x1844660);
	static inline auto FOnEntityKilled = PreyFunction<void(CGameRules* const _this, const HitInfo& hitInfo)>(0x1843620);
	static inline auto FOnEntityBroken = PreyFunction<void(CGameRules* const _this, const unsigned _brokenEntityId)>(0x1843510);
	static inline auto FAddForbiddenArea = PreyFunction<void(CGameRules* const _this, unsigned entityId)>(0x183C2B0);
	static inline auto FRemoveForbiddenArea = PreyFunction<void(CGameRules* const _this, unsigned entityId)>(0x1846C30);
	static inline auto FOnLocalPlayerRevived = PreyFunction<void(CGameRules* const _this)>(0x1843D50);
	static inline auto FPreCacheItemResources = PreyFunction<void(CGameRules* const _this, const char* itemName)>(0x1844F90);
	static inline auto FPrecacheList = PreyFunction<void(CGameRules* const _this, XmlNodeRef precacheListNode)>(0x1845D20);
	static inline auto FPrecacheFromXml = PreyFunction<void(CGameRules* const _this, const char* xmlPath)>(0x1845590);
	static inline auto FSetTeam_Common = PreyFunction<bool(CGameRules* const _this, int teamId, unsigned entityId, bool& bIsPlayer)>(0x1848560);
	static inline auto FHostMigrationFindDynamicEntities = PreyFunction<void(CGameRules* const _this, std::vector<unsigned int>& results)>(0x1840370);
	static inline auto FHostMigrationRemoveDuplicateDynamicEntities = PreyFunction<void(CGameRules* const _this)>(0x1840490);
	static inline auto FSetupForbiddenAreaShapesHelpers = PreyFunction<void(CGameRules* const _this)>(0x1848A10);
};

// SDeferredMfxExplosion
// Header:  Prey/GameDll/GameRules.h
struct SDeferredMfxExplosion
{ // Size=24 (0x18)
	unsigned m_rayId;
	int m_mfxTargetSurfaceId;
	_smart_ptr<IPhysicalEntity> m_pMfxTargetPhysEnt;
	EDeferredMfxExplosionState m_state;

	void Reset() { FReset(this); }

#if 0
	SDeferredMfxExplosion();
	~SDeferredMfxExplosion();
	void OnRayCastDataReceived(const unsigned& _arg0_, const RayCastResult& _arg1_);
#endif

	static inline auto FReset = PreyFunction<void(SDeferredMfxExplosion* const _this)>(0x18471F0);
};

// SPathFollowingAttachToPathParameters
// Header:  Prey/GameDll/GameRules.h
struct SPathFollowingAttachToPathParameters
{ // Size=36 (0x24)
	uint16_t classId;
	unsigned pathFollowerId;
	uint8_t pathIndex;
	bool shouldStartAtInitialNode;
	bool shouldLoop;
	float speed;
	float defaultSpeed;
	int nodeIndex;
	int interpNodeIndex;
	float waitTime;
	bool forceSnap;

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	SPathFollowingAttachToPathParameters();
	SPathFollowingAttachToPathParameters(uint16_t _arg0_, unsigned _arg1_, uint8_t _arg2_, bool _arg3_, bool _arg4_, float _arg5_, float _arg6_, int _arg7_, int _arg8_, float _arg9_, bool _arg10_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(SPathFollowingAttachToPathParameters* const _this, TSerialize ser)>(0x1854570);
};

// SProjectileExplosionParams
// Header:  Prey/GameDll/GameRules.h
struct SProjectileExplosionParams
{ // Size=80 (0x50)
	string m_overrideEffectClassName;
	unsigned m_shooterId;
	unsigned m_weaponId;
	unsigned m_projectileId;
	unsigned m_impactId;
	Vec3 m_pos;
	Vec3 m_dir;
	Vec3 m_impactDir;
	Vec3 m_impactVel;
	float m_damage;
	uint16_t m_projectileClass;
	bool m_impact;
	bool m_isProxyExplosion;

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	SProjectileExplosionParams();
	SProjectileExplosionParams(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, unsigned _arg3_, Vec3 _arg4_, Vec3 _arg5_, Vec3 _arg6_, Vec3 _arg7_, float _arg8_, uint16_t _arg9_, bool _arg10_, bool _arg11_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(SProjectileExplosionParams* const _this, TSerialize ser)>(0x1854700);
};
#endif // MOONCRASH
