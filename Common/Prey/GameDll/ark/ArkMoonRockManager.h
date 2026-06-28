// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/arkdeferredaction.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <_unknown/ArkDeferredActionImpl_RayCast.h>
#include <_unknown/RayCastQueue.h>

struct IEntity;
struct RayCastRequest;
struct RayCastResult;

// ArkMoonRockManager
// Header:  Prey/GameDll/ark/ArkMoonRockManager.h
class ArkMoonRockManager
{ // Size=168 (0xA8)
public:
	// ArkMoonRockManager::DeferredRayCastImpl
	// Header:  Prey/GameDll/ark/ArkMoonRockManager.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=48 (0x30)
	public:
		unsigned m_propId;
		bool m_bHasPriority;
		unsigned m_targetId;
		int m_requesters;
		bool m_bLastTestSucceeded;
		float m_lastTestTimer;
		Vec3 m_lastRockTestPos;
		Vec3 m_lastTargetTestPos;

	#if 0
		DeferredRayCastImpl();
		DeferredRayCastImpl(unsigned _arg0_, unsigned _arg1_);
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	// ArkMoonRockManager::MoonRockTargetInfo
	// Header:  Prey/GameDll/ark/ArkMoonRockManager.h
	struct MoonRockTargetInfo
	{ // Size=20 (0x14)
		unsigned m_targetEntityId;
		Vec3 m_pos;
		int m_usersTargeting;

	#if 0
		MoonRockTargetInfo();
		MoonRockTargetInfo(unsigned _arg0_);
	#endif
	};

	// ArkMoonRockManager::MoonRockInfo
	// Header:  Prey/GameDll/ark/ArkMoonRockManager.h
	struct MoonRockInfo
	{ // Size=36 (0x24)
		unsigned m_entityId;
		float m_lastTestTimer;
		Vec3 m_pos;
		Vec3 m_lastTestPos;
		bool m_bUsedByAbility;

	#if 0
		MoonRockInfo();
		MoonRockInfo(unsigned _arg0_);
		MoonRockInfo(const ArkMoonRockManager::MoonRockInfo& _arg0_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const ArkMoonRockManager::MoonRockInfo& _arg0_) const;
		ArkMoonRockManager::MoonRockInfo& operator=(const ArkMoonRockManager::MoonRockInfo& _arg0_);
		bool IsCleared() const;
		void Clear();
	#endif
	};

	// ArkMoonRockManager::MoonRockUserInfo
	// Header:  Prey/GameDll/ark/ArkMoonRockManager.h
	struct MoonRockUserInfo
	{ // Size=48 (0x30)
		unsigned m_user;
		unsigned m_target;
		bool m_bUsingRockAbility;
		ArkSimpleTimer m_retestSurroundingRocksTimer;
		std::vector<ArkMoonRockManager::MoonRockInfo*> m_closestMoonRocks;

	#if 0
		MoonRockUserInfo(unsigned _arg0_, unsigned _arg1_);
	#endif
	};

	using DeferredRayCast = ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>;

	static inline auto s_kMaxRocks = PreyGlobal<uint64_t>(0x23DF7E0);
	static inline auto s_kPropTestAboveDist = PreyGlobal<float>(0x23DF7E8);
	static inline auto s_retestNearbyRocksTime = PreyGlobal<float>(0x23DF7EC);
	static inline auto s_kTargetMovedRetestDistSq = PreyGlobal<float>(0x23DF7F0);
	static inline auto s_kPropRetestDistSq = PreyGlobal<float>(0x23DF7F4);
	static inline auto s_maxRelevantDistanceSq = PreyGlobal<float>(0x23DF7F8);
	static inline auto s_maxCloseRocks = PreyGlobal<int>(0x23DF7FC);
	static inline auto s_kMinLOSTestTime = PreyGlobal<float>(0x23DF800);
	static inline auto s_numMoonRockArchetypes = PreyGlobal<int>(0x23DF804);
	int m_numRocksSpawnedMin;
	int m_numRocksSpawnedMax;
	Vec3 m_impulseRandomMin;
	Vec3 m_impulseRandomMax;
	float m_spawnDistanceMin;
	float m_spawnDistanceMax;
	float m_spawnAngleRadiansMin;
	float m_spawnAngleRadiansMax;
	float m_spawnZOffset;
	std::vector<ArkMoonRockManager::MoonRockUserInfo> m_users;
	std::vector<ArkMoonRockManager::MoonRockInfo> m_rockInfos;
	std::vector<int> m_rockInfoSortIndices;
	std::vector<ArkMoonRockManager::MoonRockTargetInfo> m_targets;
	std::map<std::pair<unsigned int, unsigned int>, ArkDeferredAction<ArkMoonRockManager::DeferredRayCastImpl>> m_rockTargetPairToRaycastMap;

	ArkMoonRockManager();
	~ArkMoonRockManager();
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	bool TrySpawnMoonRockCluster(const Matrix34& _spawnTM, bool _bImpulse) { return FTrySpawnMoonRockCluster(this, _spawnTM, _bImpulse); }
	bool TrySpawnMoonRock(const Vec3 _spawnPos, bool _bImpulse) { return FTrySpawnMoonRock(this, _spawnPos, _bImpulse); }
	void RegisterRock(unsigned _rockId) { FRegisterRock(this, _rockId); }
	float GetMaxRevelantDistanceSq() const { return FGetMaxRevelantDistanceSq(this); }
	int CalcNumNearbyRocks(unsigned _userId) { return FCalcNumNearbyRocks(this, _userId); }
	void GetClosestRocksToUser(unsigned _userId, std::vector<unsigned int>& _outRockIdResults) const { FGetClosestRocksToUser(this, _userId, _outRockIdResults); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void AddUser(unsigned _user, unsigned _target) { FAddUser(this, _user, _target); }
	void RemoveUser(unsigned _user) { FRemoveUser(this, _user); }
	bool HasLos(unsigned _rockId, unsigned _targetId) { return FHasLos(this, _rockId, _targetId); }
	int FindFurthestRockIndex() { return FFindFurthestRockIndex(this); }
	void ClearAllTracking() { FClearAllTracking(this); }
	IEntity* SpawnRock(const Vec3& _spawnPos, int _spawnIndex) { return FSpawnRock(this, _spawnPos, _spawnIndex); }
	Vec3 GetRandomSpawnLocation(const Matrix34& _spawnTM) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetRandomSpawnLocation(this, reinterpret_cast<Vec3*>(_return_buf_), _spawnTM); }
	void ImpulseRock(IEntity* _pRockEntity, const Matrix34& _spawnTM) { FImpulseRock(this, _pRockEntity, _spawnTM); }
	void UpdateUsers(float _elapsedTime) { FUpdateUsers(this, _elapsedTime); }
	void UpdateRocks(float _elapsedTime) { FUpdateRocks(this, _elapsedTime); }
	void UpdateRaycasts(float _elaspedTime) { FUpdateRaycasts(this, _elaspedTime); }
	void RemoveTarget(unsigned _targetId) { FRemoveTarget(this, _targetId); }
	void AddRaycast(unsigned _rockId, unsigned _targetId) { FAddRaycast(this, _rockId, _targetId); }
	void LoadConfig() { FLoadConfig(this); }

#if 0
	IEntity* GetClosestRock(const Vec3& _arg0_);
	int CalcNumNearbyRocksWithLoS(unsigned _arg0_);
	const ArkMoonRockManager::MoonRockTargetInfo* GetRockTargetFromId(unsigned _arg0_);
	void UpdateTargets(float _arg0_);
	const ArkMoonRockManager::MoonRockUserInfo* GetMoonRockUser(unsigned _arg0_) const;
	void AddTarget(unsigned _arg0_);
	void RemoveRaycast(unsigned _arg0_, unsigned _arg1_);
	void RemoveAllRaycastsFromRock(unsigned _arg0_);
	void RemoveAllRaycastsToTarget(unsigned _arg0_);
	bool HasRock(unsigned _arg0_) const;
	void ClearRock(ArkMoonRockManager::MoonRockInfo& _arg0_);
#endif

	static inline auto FArkMoonRockManagerOv1 = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BA750);
	static inline auto FBitNotArkMoonRockManager = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BA9D0);
	static inline auto FUpdate = PreyFunction<void(ArkMoonRockManager* const _this, float _elapsedTime)>(0x11BCD20);
	static inline auto FReset = PreyFunction<void(ArkMoonRockManager* const _this, bool _bEnteringGameMode)>(0x11BC740);
	static inline auto FSerialize = PreyFunction<void(ArkMoonRockManager* const _this, TSerialize _ser)>(0x11BC750);
	static inline auto FPostSerialize = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BC4C0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkMoonRockManager* const _this)>(0x1333E90);
	static inline auto FTrySpawnMoonRockCluster = PreyFunction<bool(ArkMoonRockManager* const _this, const Matrix34& _spawnTM, bool _bImpulse)>(0x11BCC20);
	static inline auto FTrySpawnMoonRock = PreyFunction<bool(ArkMoonRockManager* const _this, const Vec3 _spawnPos, bool _bImpulse)>(0x11BCB40);
	static inline auto FRegisterRock = PreyFunction<void(ArkMoonRockManager* const _this, unsigned _rockId)>(0x11BC550);
	static inline auto FGetMaxRevelantDistanceSq = PreyFunction<float(const ArkMoonRockManager* const _this)>(0x11BB4A0);
	static inline auto FCalcNumNearbyRocks = PreyFunction<int(ArkMoonRockManager* const _this, unsigned _userId)>(0x11BB180);
	static inline auto FGetClosestRocksToUser = PreyFunction<void(const ArkMoonRockManager* const _this, unsigned _userId, std::vector<unsigned int>& _outRockIdResults)>(0x11BB410);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BC740);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkMoonRockManager* const _this)>(0x1333E90);
	static inline auto FAddUser = PreyFunction<void(ArkMoonRockManager* const _this, unsigned _user, unsigned _target)>(0x11BADD0);
	static inline auto FRemoveUser = PreyFunction<void(ArkMoonRockManager* const _this, unsigned _user)>(0x11BC6E0);
	static inline auto FHasLos = PreyFunction<bool(ArkMoonRockManager* const _this, unsigned _rockId, unsigned _targetId)>(0x11BB780);
	static inline auto FFindFurthestRockIndex = PreyFunction<int(ArkMoonRockManager* const _this)>(0x11BB2A0);
	static inline auto FClearAllTracking = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BB1B0);
	static inline auto FSpawnRock = PreyFunction<IEntity* (ArkMoonRockManager* const _this, const Vec3& _spawnPos, int _spawnIndex)>(0x11BC770);
	static inline auto FGetRandomSpawnLocation = PreyFunction<Vec3*(ArkMoonRockManager* const _this, Vec3* _return_value_, const Matrix34& _spawnTM)>(0x11BB4B0);
	static inline auto FImpulseRock = PreyFunction<void(ArkMoonRockManager* const _this, IEntity* _pRockEntity, const Matrix34& _spawnTM)>(0x11BB7F0);
	static inline auto FUpdateUsers = PreyFunction<void(ArkMoonRockManager* const _this, float _elapsedTime)>(0x11BD480);
	static inline auto FUpdateRocks = PreyFunction<void(ArkMoonRockManager* const _this, float _elapsedTime)>(0x11BD210);
	static inline auto FUpdateRaycasts = PreyFunction<void(ArkMoonRockManager* const _this, float _elaspedTime)>(0x11BCE70);
	static inline auto FRemoveTarget = PreyFunction<void(ArkMoonRockManager* const _this, unsigned _targetId)>(0x11BC5F0);
	static inline auto FAddRaycast = PreyFunction<void(ArkMoonRockManager* const _this, unsigned _rockId, unsigned _targetId)>(0x11BAAD0);
	static inline auto FLoadConfig = PreyFunction<void(ArkMoonRockManager* const _this)>(0x11BBB60);
};
#endif // MOONCRASH
