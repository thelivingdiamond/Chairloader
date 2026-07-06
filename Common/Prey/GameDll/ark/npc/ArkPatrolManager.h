// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkPatrol.h>
#include <_unknown/ArkPatrolPoint.h>
#include <_unknown/IArkPatrolManager.h>

struct ArkPatrolState;

// ArkPatrolManager
// Header:  Prey/GameDll/ark/npc/ArkPatrolManager.h
class ArkPatrolManager : public IArkPatrolManager
{ // Size=184 (0xB8)
public:
	std::vector<ArkPatrol> m_patrols;
	std::vector<ArkPatrolPoint> m_points;
	std::unordered_map<string, unsigned int> m_nameToIndexMap;
	std::unordered_map<uint64_t, unsigned int> m_idToIndexMap;

	ArkPatrolManager();
	~ArkPatrolManager();
	virtual unsigned GetPatrolIndex(const char* const _pName) const;
	virtual unsigned GetPatrolIndex(const uint64_t& _id) const;
	virtual const string& GetPatrolName(unsigned _patrolIndex) const;
	virtual uint64_t GetPatrolId(unsigned _patrolIndex) const;
	ArkPatrolState CreateInitialPatrolStateFromClosestPatrolTo(const Vec3& _point) { alignas(ArkPatrolState) std::byte _return_buf_[sizeof(ArkPatrolState)]; return *FCreateInitialPatrolStateFromClosestPatrolTo(this, reinterpret_cast<ArkPatrolState*>(_return_buf_), _point); }
	ArkPatrolState CreateInitialPatrolStateFromClosestForwardPointOnPatrolTo(unsigned _patrolIndex, const Vec3& _point) { alignas(ArkPatrolState) std::byte _return_buf_[sizeof(ArkPatrolState)]; return *FCreateInitialPatrolStateFromClosestForwardPointOnPatrolTo(this, reinterpret_cast<ArkPatrolState*>(_return_buf_), _patrolIndex, _point); }
	ArkPatrolState CreateInitialPatrolStateFromPatrolAndPoint(unsigned _patrolIndex, int _pointIndex) { alignas(ArkPatrolState) std::byte _return_buf_[sizeof(ArkPatrolState)]; return *FCreateInitialPatrolStateFromPatrolAndPoint(this, reinterpret_cast<ArkPatrolState*>(_return_buf_), _patrolIndex, _pointIndex); }
	bool UpdatePatrolState(ArkPatrolState& _patrolState) const { return FUpdatePatrolState(this, _patrolState); }
	bool ReachedDestination(const ArkPatrolState& _patrolState, const Vec3& _pos, float _epsilon) const { return FReachedDestination(this, _patrolState, _pos, _epsilon); }
	Vec3 GetCurrentPointDestination(const ArkPatrolState& _patrolState, unsigned _forEntityId) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetCurrentPointDestination(this, reinterpret_cast<Vec3*>(_return_buf_), _patrolState, _forEntityId); }
	float GetCurrentPointGuardTime(const ArkPatrolState& _patrolState) const { return FGetCurrentPointGuardTime(this, _patrolState); }
	float GetCurrentPointIdleChance(const ArkPatrolState& _patrolState) const { return FGetCurrentPointIdleChance(this, _patrolState); }
	int GetCurrentPointLocalIndex(const ArkPatrolState& _patrolState) const { return FGetCurrentPointLocalIndex(this, _patrolState); }
	bool GetZeroGDesiredPitchRoll(const ArkPatrolState& _patrolState, float& _pitch, float& _roll) const { return FGetZeroGDesiredPitchRoll(this, _patrolState, _pitch, _roll); }
	void RelinquishPatrol(ArkPatrolState& _patrolState) const { FRelinquishPatrol(this, _patrolState); }
	void SetPatrolEnabled(unsigned _patrolIndex, bool _bEnabled) { FSetPatrolEnabled(this, _patrolIndex, _bEnabled); }
	void Update(float _framTime) { FUpdate(this, _framTime); }
	virtual void LoadFromFile(const char* _pLevelName);
	virtual const std::unordered_map<string, unsigned int>& GetNameMap() const;
	virtual const std::unordered_map<uint64_t, unsigned int>& GetIdMap() const;
	int GetNextPointIndex(const ArkPatrolState& _patrolState) const { return FGetNextPointIndex(this, _patrolState); }
	int GetClosestPointIndexOnPatrolTo(const ArkPatrol& _patrol, const Vec3& _toPoint) const { return FGetClosestPointIndexOnPatrolTo(this, _patrol, _toPoint); }

#if 0
	ArkPatrolManager(const ArkPatrolManager& _arg0_);
	ArkPatrolState CreateInitialPatrolStateFromClosestPointOnPatrolTo(unsigned _arg0_, const Vec3& _arg1_);
	bool GetNextPointGuardTime(const ArkPatrolState& _arg0_, float& _arg1_) const;
	bool IsPatrolEnabled(unsigned _arg0_) const;
	bool IsValidPatrolIndex(unsigned _arg0_) const;
	ArkPatrolManager& operator=(const ArkPatrolManager& _arg0_);
	void Clear();
	void DebugDraw();
	bool IsValidPointIndex(int _arg0_) const;
	ArkPatrol* GetPatrol(unsigned _arg0_);
	const ArkPatrol* GetPatrol(unsigned _arg0_) const;
	const ArkPatrolPoint* GetPatrolPoint(int _arg0_) const;
#endif

	static inline auto FArkPatrolManagerOv1 = PreyFunction<void(ArkPatrolManager* const _this)>(0x163DBC0);
	static inline auto FBitNotArkPatrolManager = PreyFunction<void(ArkPatrolManager* const _this)>(0x163DCA0);
	static inline auto FGetPatrolIndexOv1 = PreyFunction<unsigned(const ArkPatrolManager* const _this, const char* const _pName)>(0x163EA70);
	static inline auto FGetPatrolIndexOv0 = PreyFunction<unsigned(const ArkPatrolManager* const _this, const uint64_t& _id)>(0x163E980);
	static inline auto FGetPatrolName = PreyFunction<const string& (const ArkPatrolManager* const _this, unsigned _patrolIndex)>(0x163EC10);
	static inline auto FGetPatrolId = PreyFunction<uint64_t(const ArkPatrolManager* const _this, unsigned _patrolIndex)>(0x163E920);
	static inline auto FCreateInitialPatrolStateFromClosestPatrolTo = PreyFunction<ArkPatrolState*(ArkPatrolManager* const _this, ArkPatrolState* _return_value_, const Vec3& _point)>(0x163E150);
	static inline auto FCreateInitialPatrolStateFromClosestForwardPointOnPatrolTo = PreyFunction<ArkPatrolState*(ArkPatrolManager* const _this, ArkPatrolState* _return_value_, unsigned _patrolIndex, const Vec3& _point)>(0x163DD50);
	static inline auto FCreateInitialPatrolStateFromPatrolAndPoint = PreyFunction<ArkPatrolState*(ArkPatrolManager* const _this, ArkPatrolState* _return_value_, unsigned _patrolIndex, int _pointIndex)>(0x163E280);
	static inline auto FUpdatePatrolState = PreyFunction<bool(const ArkPatrolManager* const _this, ArkPatrolState& _patrolState)>(0x163FB20);
	static inline auto FReachedDestination = PreyFunction<bool(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState, const Vec3& _pos, float _epsilon)>(0x163F8C0);
	static inline auto FGetCurrentPointDestination = PreyFunction<Vec3*(const ArkPatrolManager* const _this, Vec3* _return_value_, const ArkPatrolState& _patrolState, unsigned _forEntityId)>(0x163E540);
	static inline auto FGetCurrentPointGuardTime = PreyFunction<float(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState)>(0x163E6E0);
	static inline auto FGetCurrentPointIdleChance = PreyFunction<float(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState)>(0x163E740);
	static inline auto FGetCurrentPointLocalIndex = PreyFunction<int(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState)>(0x163E7A0);
	static inline auto FGetZeroGDesiredPitchRoll = PreyFunction<bool(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState, float& _pitch, float& _roll)>(0x163ED50);
	static inline auto FRelinquishPatrol = PreyFunction<void(const ArkPatrolManager* const _this, ArkPatrolState& _patrolState)>(0x163F990);
	static inline auto FSetPatrolEnabled = PreyFunction<void(ArkPatrolManager* const _this, unsigned _patrolIndex, bool _bEnabled)>(0x163FAD0);
	static inline auto FUpdate = PreyFunction<void(ArkPatrolManager* const _this, float _framTime)>(0x1333E90);
	static inline auto FLoadFromFile = PreyFunction<void(ArkPatrolManager* const _this, const char* _pLevelName)>(0x163EE30);
	static inline auto FGetNameMap = PreyFunction<const std::unordered_map<string, unsigned int>& (const ArkPatrolManager* const _this)>(0x10ECF30);
	static inline auto FGetIdMap = PreyFunction<const std::unordered_map<uint64_t, unsigned int>& (const ArkPatrolManager* const _this)>(0x10ECF80);
	static inline auto FGetNextPointIndex = PreyFunction<int(const ArkPatrolManager* const _this, const ArkPatrolState& _patrolState)>(0x163E840);
	static inline auto FGetClosestPointIndexOnPatrolTo = PreyFunction<int(const ArkPatrolManager* const _this, const ArkPatrol& _patrol, const Vec3& _toPoint)>(0x163E310);
};

// ArkPatrolState
// Header:  Prey/GameDll/ark/npc/ArkPatrolManager.h
struct ArkPatrolState
{ // Size=16 (0x10)
	int m_patrolIndex;
	int m_pointIndex;
	int m_movementStyleSpeed;
	bool m_bMovingForward;
	bool m_bOffNavMesh;
	bool m_bNeedsNextPointResetToClosest;

	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	ArkPatrolState();
	bool IsValid() const;
	unsigned GetPatrolIndex() const;
	int GetPointIndex() const;
	void SetMovementStyleSpeed(const int _arg0_);
	int GetMovementStyleSpeed() const;
	void SetAllowOffNavMesh(const bool _arg0_);
	bool GetAllowOffNavMesh() const;
	void SetPointNeedsResetToClosest();
	bool PointNeedsResetToClosest() const;
#endif

	static inline auto FReset = PreyFunction<void(ArkPatrolState* const _this)>(0x163F9B0);
	static inline auto FSerialize = PreyFunction<void(ArkPatrolState* const _this, TSerialize _ser)>(0x163F9D0);
};
#endif // MOONCRASH
