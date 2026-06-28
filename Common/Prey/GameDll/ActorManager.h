// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/CryActor.h>

struct AABB;
struct IAIObject;
struct IActor;
struct IEntity;
struct SActorData;

// CActorManager
// Header:  Prey/GameDll/ActorManager.h
class CActorManager
{ // Size=72 (0x48)
public:
	using TEntityPtrIndexMap = std::map<IEntity*, int>;
	using TActorPtrIndexMap = std::map<IActor*, int>;

	static constexpr const int kMaxActorsTrackedInit = 1;
	char* m_startMemoryPtr;
	void* m_startMemoryPtrAlign;
	unsigned* m_actorEntityIds;
	Vec3* m_actorPositions;
	CCryActor::EActorSpectatorMode* m_actorSpectatorModes;
	float* m_actorHealth;
	int m_iNumActorsTracked;
	int m_iNumActorsTrackedIncLocalPlayer;
	int m_iMaxTrackedActors;

	virtual ~CActorManager();
	void Update(float dt) { FUpdate(this, dt); }
	void Reset(bool bReallocate) { FReset(this, bReallocate); }
	void ActorRemoved(IActor* pActor) { FActorRemoved(this, pActor); }
	void ActorRevived(IActor* pActor) { FActorRevived(this, pActor); }
	static CActorManager* GetActorManager() { return FGetActorManager(); }
	void CacheDataFromActor(const IActor* pActor, IEntity* pEntity, const IAIObject* pAIObject, int kActorIndexMultiplier, int iActorIndex) { FCacheDataFromActor(this, pActor, pEntity, pAIObject, kActorIndexMultiplier, iActorIndex); }
	void ReallocateMemoryForNActors(int iNumActorsRequired) { FReallocateMemoryForNActors(this, iNumActorsRequired); }

#if 0
	CActorManager();
	float GetDistSqToClosestActor(const Vec3& _arg0_) const;
	bool AnyActorWithinAABB(const AABB& _arg0_) const;
	void PrepareForIteration() const;
	void GetNthActorData(int _arg0_, SActorData& _arg1_) const;
	int GetNumActors() const;
	int GetNumActorsIncludingLocalPlayer() const;
	void WriteCachedActorData(int _arg0_, int _arg1_);
	uint64_t GetMemoryRequiredForNActors(int _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<void(CActorManager* const _this, float dt)>(0x10C0030);
	static inline auto FReset = PreyFunction<void(CActorManager* const _this, bool bReallocate)>(0x10BFFD0);
	static inline auto FActorRemoved = PreyFunction<void(CActorManager* const _this, IActor* pActor)>(0x10BFBF0);
	static inline auto FActorRevived = PreyFunction<void(CActorManager* const _this, IActor* pActor)>(0x10BFD00);
	static inline auto FGetActorManager = PreyFunction<CActorManager* ()>(0x10BFE80);
	static inline auto FCacheDataFromActor = PreyFunction<void(CActorManager* const _this, const IActor* pActor, IEntity* pEntity, const IAIObject* pAIObject, int kActorIndexMultiplier, int iActorIndex)>(0x10BFDE0);
	static inline auto FReallocateMemoryForNActors = PreyFunction<void(CActorManager* const _this, int iNumActorsRequired)>(0x10BFF00);
};
#endif // MOONCRASH
