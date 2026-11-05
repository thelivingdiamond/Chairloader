// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryAISystem/IAIRecordable.h>

struct AABB;
struct AIObjectParams;
struct AgentPathfindingProperties;
class CTimeValue;
enum class EnumAreaType;
struct IAIActorProxyFactory;
struct IAIAlertnessPredicate;
struct IAIDebugRenderer;
struct IAIEventListener;
struct IAIObject;
struct IAIObjectManager;
struct IAIPathFinder;
struct IAIRecorder;
struct IAISignalExtraData;
class IAISystemListener;
class ICrySizer;
struct IEntity;
struct IFunctionHandler;
struct IMNMPathfinder;
struct IMovementSystem;
struct INavigation;
struct INavigationSystem;
class IPathFollower;
struct IPathObstacles;
struct ISelectionTreeManager;
struct ISmartObjectManager;
struct ITacticalPointSystem;
struct PathFollowerParams;
struct SAIRecorderDebugContext;
struct SNavigationShapeParams;
struct Sphere;

//! The first word refers to how the nodes are initially connected.
//! The second word refers to how the node connections are subsequently modified - partial means that links only get disabled.
//! (From CryEngine 5.2.)
enum EWaypointConnections
{
	WPCON_DESIGNER_NONE,
	WPCON_DESIGNER_PARTIAL,
	WPCON_AUTO_NONE,
	WPCON_AUTO_PARTIAL,
	WPCON_MAXVALUE = WPCON_AUTO_PARTIAL
};

// IAISystem
// Header:  _unknown/IAISystem.h
// Include: Prey/CryAISystem/IAISystem.h
struct IAISystem
{ // Size=8 (0x8)
	enum class EGroupFlags
	{
		GROUP_ALL = 1,
		GROUP_ENABLED = 2,
		GROUP_MAX = 4,
	};

	enum class ENavigationType
	{
		NAV_UNSET = 1,
		NAV_TRIANGULAR = 2,
		NAV_WAYPOINT_HUMAN = 4,
		NAV_WAYPOINT_3DSURFACE = 8,
		NAV_FLIGHT = 16,
		NAV_VOLUME = 32,
		NAV_ROAD = 64,
		NAV_SMARTOBJECT = 128,
		NAV_FREE_2D = 256,
		NAV_CUSTOM_NAVIGATION = 512,
		NAV_ARK_OFF_MESH = 1024,
		NAV_MAX_VALUE = 512,
	};

	enum
	{
		NAV_TYPE_COUNT = 10,
	};

	enum
	{
		NAVMASK_SURFACE = 198,
		NAVMASK_AIR = 176,
		NAVMASK_ALL = 1022,
	};

	enum class EResetReason
	{
		RESET_INTERNAL = 0,
		RESET_ENTER_GAME = 1,
		RESET_EXIT_GAME = 2,
		RESET_INTERNAL_LOAD = 3,
		RESET_LOAD_LEVEL = 4,
		RESET_UNLOAD_LEVEL = 5,
	};

	// IAISystem::NavCapMask
	// Header:  _unknown/IAISystem.h
	class NavCapMask
	{ // Size=4 (0x4)
	public:
		static constexpr const unsigned s_maskWidth = 32;
		static constexpr const unsigned s_lnmBits = 8;
		static constexpr const unsigned s_lnmShift = 24;
		static constexpr const unsigned s_lnmMask = 4278190080;
		unsigned m_navCaps;

		void Serialize(TSerialize ser) { FSerialize(this, ser); }

	#if 0
		NavCapMask();
		NavCapMask(unsigned _arg0_);
		unsigned operator unsigned int() const;
		IAISystem::NavCapMask& operator&=(unsigned _arg0_);
		IAISystem::NavCapMask& operator|=(unsigned _arg0_);
		unsigned GetLnmCaps() const;
		void SetLnmCaps(unsigned _arg0_);
		unsigned GetFullMask() const;
	#endif

#ifndef MOONCRASH
		static inline auto FSerialize = PreyFunction<void(IAISystem::NavCapMask* const _this, TSerialize ser)>(0x6D4790);
#else
		static inline auto FSerialize = PreyFunction<void(IAISystem::NavCapMask* const _this, TSerialize ser)>(0x6F0330);
#endif
	};

	// IAISystem::tNavCapMask
	// Header:  _unknown/IAISystem.h
	using tNavCapMask = IAISystem::NavCapMask;

	// IAISystem::SBuildingInfo
	// Header:  _unknown/IAISystem.h
	struct SBuildingInfo
	{ // Size=8 (0x8)
		EWaypointConnections waypointConnections;
		float fNodeAutoConnectDistance;
	};

	virtual ~IAISystem();
	virtual bool Init() = 0;
	virtual bool CompleteInit() = 0;
	virtual void Reload();
	virtual void Reset(IAISystem::EResetReason reason) = 0;
	virtual void Release() = 0;
	virtual void SetActorProxyFactory(IAIActorProxyFactory* pFactory) = 0;
	virtual IAIActorProxyFactory* GetActorProxyFactory() const = 0;
	virtual void Enable(bool enable) = 0;
	virtual bool IsEnabled() const = 0;
	virtual void Update(CTimeValue frameStartTime, float frameDeltaTime) = 0;
	virtual bool RegisterListener(IAISystemListener* pListener) = 0;
	virtual bool UnregisterListener(IAISystemListener* pListener) = 0;
	virtual void RegisterAIEventListener(IAIEventListener* pListener, const Vec3& pos, float rad, int flags) = 0;
	virtual void UnregisterAIEventListener(IAIEventListener* pListener) = 0;
	virtual void SendAnonymousSignal(int signalID, const char* text, const Vec3& pos, float radius, IAIObject* pSenderObject, IAISignalExtraData* pData) = 0;
	virtual void SendSignal(uint8_t cFilter, int nSignalId, const char* szText, IAIObject* pSenderObject, IAISignalExtraData* pData, unsigned crcCode) = 0;
	virtual void FreeSignalExtraData(IAISignalExtraData* pData) const = 0;
	virtual IAISignalExtraData* CreateSignalExtraData() const = 0;
	virtual void Event(int event, const char* name) = 0;
	virtual void InvalidatePathsThroughAABB(const AABB& _aabb) = 0;
	virtual void InvalidatePathsThroughAABB(const AABB& _aabb, float _minDist, float _maxDist) = 0;
	virtual bool GetUpdateAllAlways() const = 0;
	virtual float GetUpdateInterval() const = 0;
	virtual int GetAITickCount() = 0;
	virtual void SerializeObjectIDs(TSerialize ser) = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual void SetLevelPath(const char* sPath) = 0;
	virtual void FlushSystem(bool bDeleteAll) = 0;
	virtual void FlushSystemNavigation(bool bDeleteAll) = 0;
	virtual void LayerEnabled(const char* layerName, bool enabled, bool serialized) = 0;
	virtual void LoadLevelData(const char* szLevel, const char* szMission, const bool bRequiredQuickLoading) = 0;
	virtual void LoadNavigationData(const char* szLevel, const char* szMission, const bool bRequiredQuickLoading, bool bAfterExporting) = 0;
	virtual void ReadAreasFromFile(const char* fileNameAreas) = 0;
	virtual void OnMissionLoaded() = 0;
	virtual IAIDebugRenderer* GetAIDebugRenderer() = 0;
	virtual IAIDebugRenderer* GetAINetworkDebugRenderer() = 0;
	virtual void SetAIDebugRenderer(IAIDebugRenderer* pAIDebugRenderer) = 0;
	virtual void SetAINetworkDebugRenderer(IAIDebugRenderer* pAINetworkDebugRenderer) = 0;
	virtual void SetAgentDebugTarget(const unsigned id) = 0;
	virtual unsigned GetAgentDebugTarget() const = 0;
	virtual bool IsRecording(const IAIObject* pTarget, IAIRecordable::e_AIDbgEvent event) const = 0;
	virtual void Record(const IAIObject* pTarget, IAIRecordable::e_AIDbgEvent event, const char* pString) const = 0;
	virtual void GetRecorderDebugContext(SAIRecorderDebugContext* & pContext) = 0;
	virtual void AddDebugLine(const Vec3& start, const Vec3& end, uint8_t r, uint8_t g, uint8_t b, float time) = 0;
	virtual void AddDebugLine(const Vec3& start, const Vec3& end, const ColorB& color, float time, float thickness) = 0;
	virtual void AddDebugSphere(const Vec3& pos, float radius, uint8_t r, uint8_t g, uint8_t b, float time) = 0;
	virtual void AddDebugSphere(const Vec3& pos, float radius, const ColorB& color, float time) = 0;
	virtual void AddArkDebugLine(const Vec3& start, const Vec3& end, const ColorB& color, float time, float thickness) = 0;
	virtual void AddArkDebugSphere(const Vec3& pos, float radius, const ColorB& color, float time) = 0;
	virtual void AddAlwaysDebugLine(const Vec3& start, const Vec3& end, const ColorB& color, float time, float thickness) = 0;
	virtual void AddAlwaysDebugSphere(const Vec3& pos, float radius, const ColorB& color, float time) = 0;
	virtual void DebugReportHitDamage(IEntity* pVictim, IEntity* pShooter, float damage, const char* material) = 0;
	virtual void DebugReportDeath(IAIObject* pVictim) = 0;
	virtual void Warning(const char* id, const char* format, ...) const = 0;
	virtual void Error(const char* id, const char* format, ...) = 0;
	virtual void LogProgress(const char* id, const char* format, ...) = 0;
	virtual void LogEvent(const char* id, const char* format, ...) = 0;
	virtual void LogComment(const char* id, const char* format, ...) = 0;
	virtual bool IsAIInDevMode() = 0;
	virtual void DebugDrawFakeTracer(const Vec3& pos, const Vec3& dir) = 0;
	virtual void GetMemoryStatistics(ICrySizer* pSizer) = 0;
	virtual void DebugDraw() = 0;
	virtual IAIObjectManager* GetAIObjectManager() = 0;
	virtual ISmartObjectManager* GetSmartObjectManager() = 0;
	virtual ISelectionTreeManager* GetSelectionTreeManager() const = 0;
	virtual INavigationSystem* GetNavigationSystem() const = 0;
	virtual IMNMPathfinder* GetMNMPathfinder() const = 0;
	virtual ITacticalPointSystem* GetTacticalPointSystem() = 0;
	virtual IAIPathFinder* GetIAIPathFinder() = 0;
	virtual INavigation* GetINavigation() = 0;
	virtual IAIRecorder* GetIAIRecorder() = 0;
	virtual IMovementSystem* GetMovementSystem() const = 0;
	virtual int AllocGoalPipeId() const = 0;
	virtual bool CreateNavigationShape(const SNavigationShapeParams& params) = 0;
	virtual void DeleteNavigationShape(const char* szName) = 0;
	virtual bool DoesNavigationShapeExists(const char* szName, EnumAreaType areaType, bool road) = 0;
	virtual void EnableGenericShape(const char* shapeName, bool state) = 0;
	virtual void AssignPFPropertiesToPathType(const string& sPathType, const AgentPathfindingProperties& properties) = 0;
	virtual const AgentPathfindingProperties* GetPFPropertiesOfPathType(const string& sPathType) = 0;
	virtual string GetPathTypeNames() = 0;
	virtual void RegisterDamageRegion(const void* pID, const Sphere& sphere) = 0;
	virtual void DummyFunctionNumberOne() = 0;
	virtual int GetAlertness() const = 0;
	virtual int GetAlertness(const IAIAlertnessPredicate& alertnessPredicate) = 0;
	virtual void SetAssesmentMultiplier(uint16_t type, float fMultiplier) = 0;
	virtual bool ParseTables(int firstTable, bool parseMovementAbility, IFunctionHandler* pH, AIObjectParams& aiParams, bool& updateAlways) = 0;
	virtual float GetFrameStartTimeSecondsVirtual() const = 0;
	virtual void AddFrameTicks(uint64_t nTicks) = 0;
	virtual void ResetFrameTicks() = 0;
	virtual uint64_t NumFrameTicks() const = 0;
	virtual void NotifyTargetDead(IAIObject* pDeadObject) = 0;
	virtual std::shared_ptr<IPathFollower> CreateAndReturnNewDefaultPathFollower(const PathFollowerParams& params, const IPathObstacles& pathObstacleObject) = 0;

#if 0
	IAISystem();
#endif

#ifndef MOONCRASH
	static inline auto FReload = PreyFunction<void(IAISystem* const _this)>(0xA13080);
#else
	static inline auto FReload = PreyFunction<void(IAISystem* const _this)>(0x1333E90);
#endif
};

