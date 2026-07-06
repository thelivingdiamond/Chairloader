// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/MTPseudoRandom.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/CustomReactionFunctions.h>
#include <Prey/GameDll/hitdeathreactionsdefs.h>
#include <_unknown/STagState.h>
#include <_unknown/VectorMap.h>

class CCryActor;
class CTagDefinition;
enum EAirState;
enum ECardinalDirection;
class IActionController;
class IAnimationDatabase;
struct IAnimationSet;
class ICrySizer;
struct IScriptTable;

// CHitDeathReactionsSystem
// Header:  Prey/GameDll/HitDeathReactionsSystem.h
class CHitDeathReactionsSystem
{ // Size=2752 (0xAC0)
public:
	// CHitDeathReactionsSystem::SReactionsProfile
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct SReactionsProfile
	{ // Size=96 (0x60)
		using entitiesUsingProfileContainer = std::map<unsigned int, unsigned int>;

		SmartScriptTable pHitAndDeathReactionsTable;
		std::weak_ptr<std::vector<SReactionParams,std::allocator<SReactionParams> > const > pHitReactions;
		std::weak_ptr<std::vector<SReactionParams,std::allocator<SReactionParams> > const > pDeathReactions;
		std::weak_ptr<std::vector<SReactionParams,std::allocator<SReactionParams> > const > pCollisionReactions;
		std::weak_ptr<SHitDeathReactionsConfig const > pHitDeathReactionsConfig;
		std::map<unsigned int, unsigned int> entitiesUsingProfile;
		int iRefCount;
		unsigned timerId;

		SReactionsProfile(std::shared_ptr<const std::vector<SReactionParams>> pHitReactions, std::shared_ptr<const std::vector<SReactionParams>> pDeathReactions, std::shared_ptr<const std::vector<SReactionParams>> pCollisionReactions, SmartScriptTable pHitAndDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pHitDeathReactionsConfig);
		~SReactionsProfile();
		void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }

	#if 0
		SReactionsProfile();
		bool IsValid() const;
	#endif

		static inline auto FSReactionsProfileOv1 = PreyFunction<void(CHitDeathReactionsSystem::SReactionsProfile* const _this, std::shared_ptr<const std::vector<SReactionParams>> pHitReactions, std::shared_ptr<const std::vector<SReactionParams>> pDeathReactions, std::shared_ptr<const std::vector<SReactionParams>> pCollisionReactions, SmartScriptTable pHitAndDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pHitDeathReactionsConfig)>(0x186E7D0);
		static inline auto FBitNotSReactionsProfile = PreyFunction<void(CHitDeathReactionsSystem::SReactionsProfile* const _this)>(0x186F120);
		static inline auto FGetMemoryUsage = PreyFunction<void(const CHitDeathReactionsSystem::SReactionsProfile* const _this, ICrySizer* s)>(0x1870310);
	};

	// CHitDeathReactionsSystem::SFailSafeProfile
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct SFailSafeProfile
	{ // Size=64 (0x40)
		std::shared_ptr<const std::vector<SReactionParams>> pHitReactions;
		std::shared_ptr<const std::vector<SReactionParams>> pDeathReactions;
		std::shared_ptr<const std::vector<SReactionParams>> pCollisionReactions;
		std::shared_ptr<const SHitDeathReactionsConfig> pHitDeathReactionsConfig;
	};

	// CHitDeathReactionsSystem::STagMappingHelper
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct STagMappingHelper
	{ // Size=56 (0x38)
		enum ETagType
		{
			ETagType_Part = 0,
			ETagType_HitType = 1,
			ETagType_Weapon = 2,
			ETagType_Projectile = 3,
			ETagType_Collision = 4,
			ETagType_Stances = 5,
			ETagType_NUM = 6,
		};

		std::multimap<CryStringT<char>,CryStringT<char>,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,CryStringT<char> > > >* m_tagMapping[6];
		const CTagDefinition* m_pTagDefinition;

	#if 0
		STagMappingHelper(const CTagDefinition* _arg0_);
		~STagMappingHelper();
	#endif
	};

	// CHitDeathReactionsSystem::SPredGetMemoryUsage
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct SPredGetMemoryUsage
	{ // Size=8 (0x8)
		ICrySizer* m_pCrySizer;

	#if 0
		SPredGetMemoryUsage(ICrySizer* _arg0_);
		void operator()(const std::pair<const unsigned int, CHitDeathReactionsSystem::SReactionsProfile>& _arg0_);
	#endif
	};

	// CHitDeathReactionsSystem::SPredGetAnims
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct SPredGetAnims
	{ // Size=0 (0x0)
	};

	// CHitDeathReactionsSystem::SPredRequestAnims
	// Header:  Prey/GameDll/HitDeathReactionsSystem.h
	struct SPredRequestAnims : public std::unary_function<void,SReactionParams const &>
	{ // Size=32 (0x20)
		bool m_bRequest;
		const IAnimationSet* m_pAnimSet;
		const IActionController* m_pActionController;
		const IAnimationDatabase* m_pOptionalAnimDB;

	#if 0
		SPredRequestAnims(bool _arg0_, unsigned _arg1_, const IAnimationDatabase* _arg2_);
		void operator()(const SReactionParams& _arg0_);
	#endif
	};

	using TTagToMapTag = std::multimap<CryStringT<char>,CryStringT<char>,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char> const ,CryStringT<char> > > >;
	using ProfilesContainer = std::map<unsigned int, CHitDeathReactionsSystem::SReactionsProfile>;
	using ProfilesContainersItem = std::pair<const unsigned int, CHitDeathReactionsSystem::SReactionsProfile>;
	using FileToScriptTableMap = VectorMap<CryStringT<char>,SmartScriptTable,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char>,SmartScriptTable> > >;

	std::map<unsigned int, CHitDeathReactionsSystem::SReactionsProfile> m_reactionProfiles;
	CHitDeathReactionsSystem::SFailSafeProfile m_failSafeProfile;
	CCustomReactionFunctions m_customReactionFunctions;
	VectorMap<CryStringT<char>,SmartScriptTable,std::less<CryStringT<char> >,std::allocator<std::pair<CryStringT<char>,SmartScriptTable> > > m_reactionsScriptTableCache;
	CMTRand_int32 m_pseudoRandom;
	uint8_t m_streamingEnabled;

	static void Warning(const char* szFormat, ... _arg1_) { FWarning(szFormat, _arg1_); }
	CHitDeathReactionsSystem();
	~CHitDeathReactionsSystem();
	void OnToggleGameMode() { FOnToggleGameMode(this); }
	void Reset() { FReset(this); }
	unsigned GetReactionParamsForActor(const CCryActor& actor, std::shared_ptr<const std::vector<SReactionParams>>& pHitReactions, std::shared_ptr<const std::vector<SReactionParams>>& pDeathReactions, std::shared_ptr<const std::vector<SReactionParams>>& pCollisionReactions, std::shared_ptr<const SHitDeathReactionsConfig>& pHitDeathReactionsConfig) { return FGetReactionParamsForActor(this, actor, pHitReactions, pDeathReactions, pCollisionReactions, pHitDeathReactionsConfig); }
	void RequestReactionAnimsForActor(const CCryActor& actor, unsigned requestFlags) { FRequestReactionAnimsForActor(this, actor, requestFlags); }
	void ReleaseReactionAnimsForActor(const CCryActor& actor, unsigned requestFlags) { FReleaseReactionAnimsForActor(this, actor, requestFlags); }
	void Reload() { FReload(this); }
	void PreloadActorData(SmartScriptTable pActorPropertiesTable) { FPreloadActorData(this, pActorPropertiesTable); }
	void DumpHitDeathReactionsAssetUsage() const { FDumpHitDeathReactionsAssetUsage(this); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	void ForceRequestAnims(const CCryActor& _actor) { FForceRequestAnims(this, _actor); }
	unsigned GetActorProfileId(const CCryActor& actor) const { return FGetActorProfileId(this, actor); }
	SmartScriptTable LoadReactionsScriptTable(const CCryActor& actor) const { alignas(SmartScriptTable) std::byte _return_buf_[sizeof(SmartScriptTable)]; return *FLoadReactionsScriptTableOv1(this, reinterpret_cast<SmartScriptTable*>(_return_buf_), actor); }
	SmartScriptTable LoadReactionsScriptTable(const char* szReactionsDataFile) const { alignas(SmartScriptTable) std::byte _return_buf_[sizeof(SmartScriptTable)]; return *FLoadReactionsScriptTableOv0(this, reinterpret_cast<SmartScriptTable*>(_return_buf_), szReactionsDataFile); }
	bool LoadHitDeathReactionsParams(const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, std::shared_ptr<std::vector<SReactionParams>> pHitReactions, std::shared_ptr<std::vector<SReactionParams>> pDeathReactions, std::shared_ptr<std::vector<SReactionParams>> pCollisionReactions) { return FLoadHitDeathReactionsParams(this, actor, pHitDeathReactionsTable, pNewHitDeathReactionsConfig, pHitReactions, pDeathReactions, pCollisionReactions); }
	bool LoadHitDeathReactionsConfig(const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, std::shared_ptr<SHitDeathReactionsConfig> pHitDeathReactionsConfig) { return FLoadHitDeathReactionsConfig(this, actor, pHitDeathReactionsTable, pHitDeathReactionsConfig); }
	void LoadReactionsParams(const CCryActor& actor, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, IScriptTable* pHitDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, const char* szReactionParamsName, bool bDeathReactions, int baseReactionId, int reactionType, std::vector<SReactionParams>& reactions) { FLoadReactionsParams(this, actor, tagMapping, pHitDeathReactionsTable, pNewHitDeathReactionsConfig, szReactionParamsName, bDeathReactions, baseReactionId, reactionType, reactions); }
	void GetReactionParamsFromScript(const CCryActor& actor, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, const SmartScriptTable pScriptTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, SReactionParams& reactionParams, int reactionId) const { FGetReactionParamsFromScript(this, actor, tagMapping, pScriptTable, pNewHitDeathReactionsConfig, reactionParams, reactionId); }
	bool GetValidationParamsFromScript(const SmartScriptTable pScriptTable, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, SReactionParams& reactionParams, const CCryActor& actor, int reactionId) const { return FGetValidationParamsFromScript(this, pScriptTable, tagMapping, reactionParams, actor, reactionId); }
	void GetReactionAnimParamsFromScript(const CCryActor& actor, SmartScriptTable pScriptTable, SReactionParams::SReactionAnim& reactionAnim) const { FGetReactionAnimParamsFromScript(this, actor, pScriptTable, reactionAnim); }
	void FillAllowedPartIds(const CCryActor& actor, const SmartScriptTable pScriptTable, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, bool bIsMannequinReaction, SReactionParams& reactionParams, SReactionParams::SValidationParams& validationParams) const { FFillAllowedPartIds(this, actor, pScriptTable, tagMapping, bIsMannequinReaction, reactionParams, validationParams); }
	ECardinalDirection GetCardinalDirectionFromString(const char* szCardinalDirection) const { return FGetCardinalDirectionFromString(this, szCardinalDirection); }
	void OnRequestAnimsTimer(void* pUserData, unsigned handler) { FOnRequestAnimsTimer(this, pUserData, handler); }
	void OnReleaseAnimsTimer(void* pUserData, unsigned handler) { FOnReleaseAnimsTimer(this, pUserData, handler); }
	void AddDirectionToTagState(const ECardinalDirection direction, const char* pPrefix, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, STagState<12>& tagState) const { FAddDirectionToTagState(this, direction, pPrefix, tagMapping, tagState); }
	void RequestAnims(unsigned _profileID) { FRequestAnims(this, _profileID); }
	void ReleaseAnims(unsigned _profileID) { FReleaseAnims(this, _profileID); }
	void GenerateTagMapping(SmartScriptTable pTags, const char* pArrayName, const int tagType, CHitDeathReactionsSystem::STagMappingHelper& tagMappingHelper) { FGenerateTagMapping(this, pTags, pArrayName, tagType, tagMappingHelper); }
	void LoadTagMapping(const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, CHitDeathReactionsSystem::STagMappingHelper* pTagMappingHelper) { FLoadTagMapping(this, actor, pHitDeathReactionsTable, pTagMappingHelper); }

#if 0
	void PreloadData();
	bool IsStreamingEnabled() const;
	CCustomReactionFunctions& GetCustomReactionFunctions();
	const CCustomReactionFunctions& GetCustomReactionFunctions() const;
	CMTRand_int32& GetRandomGenerator();
	void ForceReleaseAnims(const CCryActor& _arg0_);
	void ExecuteHitDeathReactionsScripts(bool _arg0_);
	uint8_t GetStreamingPolicy() const;
	void PreProcessStanceParams(SmartScriptTable _arg0_) const;
	EAirState GetAirStateFromString(const char* _arg0_) const;
	bool FlagsValidateLocking(unsigned _arg0_) const;
	void GenerateDirectionalMannequinTagsFromReactionParams(const CCryActor& _arg0_, const CHitDeathReactionsSystem::STagMappingHelper& _arg1_, const SReactionParams& _arg2_, STagState<12>& _arg3_) const;
#endif

	static inline auto FWarning = PreyFunction<void(const char* szFormat, ... _arg1_)>(0xAA85D0);
	static inline auto FCHitDeathReactionsSystem = PreyFunction<void(CHitDeathReactionsSystem* const _this)>(0x186E290);
	static inline auto FBitNotCHitDeathReactionsSystem = PreyFunction<void(CHitDeathReactionsSystem* const _this)>(0x186EE60);
	static inline auto FOnToggleGameMode = PreyFunction<void(CHitDeathReactionsSystem* const _this)>(0x18765C0);
	static inline auto FReset = PreyFunction<void(CHitDeathReactionsSystem* const _this)>(0x1877930);
	static inline auto FGetReactionParamsForActor = PreyFunction<unsigned(CHitDeathReactionsSystem* const _this, const CCryActor& actor, std::shared_ptr<const std::vector<SReactionParams>>& pHitReactions, std::shared_ptr<const std::vector<SReactionParams>>& pDeathReactions, std::shared_ptr<const std::vector<SReactionParams>>& pCollisionReactions, std::shared_ptr<const SHitDeathReactionsConfig>& pHitDeathReactionsConfig)>(0x1870D20);
	static inline auto FRequestReactionAnimsForActor = PreyFunction<void(CHitDeathReactionsSystem* const _this, const CCryActor& actor, unsigned requestFlags)>(0x18776A0);
	static inline auto FReleaseReactionAnimsForActor = PreyFunction<void(CHitDeathReactionsSystem* const _this, const CCryActor& actor, unsigned requestFlags)>(0x1876D10);
	static inline auto FReload = PreyFunction<void(CHitDeathReactionsSystem* const _this)>(0x1877050);
	static inline auto FPreloadActorData = PreyFunction<void(CHitDeathReactionsSystem* const _this, SmartScriptTable pActorPropertiesTable)>(0x1876700);
	static inline auto FDumpHitDeathReactionsAssetUsage = PreyFunction<void(const CHitDeathReactionsSystem* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CHitDeathReactionsSystem* const _this, ICrySizer* s)>(0x1870160);
	static inline auto FForceRequestAnims = PreyFunction<void(CHitDeathReactionsSystem* const _this, const CCryActor& _actor)>(0x186FA10);
	static inline auto FGetActorProfileId = PreyFunction<unsigned(const CHitDeathReactionsSystem* const _this, const CCryActor& actor)>(0x186FD00);
	static inline auto FLoadReactionsScriptTableOv1 = PreyFunction<SmartScriptTable*(const CHitDeathReactionsSystem* const _this, SmartScriptTable* _return_value_, const CCryActor& actor)>(0x1875A30);
	static inline auto FLoadReactionsScriptTableOv0 = PreyFunction<SmartScriptTable*(const CHitDeathReactionsSystem* const _this, SmartScriptTable* _return_value_, const char* szReactionsDataFile)>(0x1875C70);
	static inline auto FLoadHitDeathReactionsParams = PreyFunction<bool(CHitDeathReactionsSystem* const _this, const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, std::shared_ptr<std::vector<SReactionParams>> pHitReactions, std::shared_ptr<std::vector<SReactionParams>> pDeathReactions, std::shared_ptr<std::vector<SReactionParams>> pCollisionReactions)>(0x1874FC0);
	static inline auto FLoadHitDeathReactionsConfig = PreyFunction<bool(CHitDeathReactionsSystem* const _this, const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, std::shared_ptr<SHitDeathReactionsConfig> pHitDeathReactionsConfig)>(0x1874820);
	static inline auto FLoadReactionsParams = PreyFunction<void(CHitDeathReactionsSystem* const _this, const CCryActor& actor, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, IScriptTable* pHitDeathReactionsTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, const char* szReactionParamsName, bool bDeathReactions, int baseReactionId, int reactionType, std::vector<SReactionParams>& reactions)>(0x1875440);
	static inline auto FGetReactionParamsFromScript = PreyFunction<void(const CHitDeathReactionsSystem* const _this, const CCryActor& actor, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, const SmartScriptTable pScriptTable, std::shared_ptr<const SHitDeathReactionsConfig> pNewHitDeathReactionsConfig, SReactionParams& reactionParams, int reactionId)>(0x18717A0);
	static inline auto FGetValidationParamsFromScript = PreyFunction<bool(const CHitDeathReactionsSystem* const _this, const SmartScriptTable pScriptTable, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, SReactionParams& reactionParams, const CCryActor& actor, int reactionId)>(0x18728C0);
	static inline auto FGetReactionAnimParamsFromScript = PreyFunction<void(const CHitDeathReactionsSystem* const _this, const CCryActor& actor, SmartScriptTable pScriptTable, SReactionParams::SReactionAnim& reactionAnim)>(0x1870580);
	static inline auto FFillAllowedPartIds = PreyFunction<void(const CHitDeathReactionsSystem* const _this, const CCryActor& actor, const SmartScriptTable pScriptTable, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, bool bIsMannequinReaction, SReactionParams& reactionParams, SReactionParams::SValidationParams& validationParams)>(0x186F700);
	static inline auto FGetCardinalDirectionFromString = PreyFunction<ECardinalDirection(const CHitDeathReactionsSystem* const _this, const char* szCardinalDirection)>(0x186FFF0);
	static inline auto FOnRequestAnimsTimer = PreyFunction<void(CHitDeathReactionsSystem* const _this, void* pUserData, unsigned handler)>(0x18765B0);
	static inline auto FOnReleaseAnimsTimer = PreyFunction<void(CHitDeathReactionsSystem* const _this, void* pUserData, unsigned handler)>(0x18765A0);
	static inline auto FAddDirectionToTagState = PreyFunction<void(const CHitDeathReactionsSystem* const _this, const ECardinalDirection direction, const char* pPrefix, const CHitDeathReactionsSystem::STagMappingHelper& tagMapping, STagState<12>& tagState)>(0x186F3F0);
	static inline auto FRequestAnims = PreyFunction<void(CHitDeathReactionsSystem* const _this, unsigned _profileID)>(0x18770B0);
	static inline auto FReleaseAnims = PreyFunction<void(CHitDeathReactionsSystem* const _this, unsigned _profileID)>(0x1876900);
	static inline auto FGenerateTagMapping = PreyFunction<void(CHitDeathReactionsSystem* const _this, SmartScriptTable pTags, const char* pArrayName, const int tagType, CHitDeathReactionsSystem::STagMappingHelper& tagMappingHelper)>(0x186FA30);
	static inline auto FLoadTagMapping = PreyFunction<void(CHitDeathReactionsSystem* const _this, const CCryActor& actor, SmartScriptTable pHitDeathReactionsTable, CHitDeathReactionsSystem::STagMappingHelper* pTagMappingHelper)>(0x1876180);
};
#endif // MOONCRASH
