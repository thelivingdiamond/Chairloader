// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class Agent;
namespace HazardSystem
{
class HazardSetup;
} // namespace HazardSystem

namespace HazardSystem
{

// HazardSystem::HazardCollisionResult
// Header:  Prey/GameDll/ai/hazardmodule/hazard.h
class HazardCollisionResult
{ // Size=16 (0x10)
public:
	bool m_CollisionFlag;
	Vec3 m_HazardOriginPos;

	HazardCollisionResult();
	void Reset() { FReset(this); }

	static inline auto FHazardCollisionResultOv2 = PreyFunction<void(HazardSystem::HazardCollisionResult* const _this)>(0x10C7FC0);
	static inline auto FReset = PreyFunction<void(HazardSystem::HazardCollisionResult* const _this)>(0x10C8030);
};

// HazardSystem::HazardData
// Header:  Prey/GameDll/ai/hazardmodule/hazard.h
class HazardData
{ // Size=24 (0x18)
public:
	unsigned m_InstanceID;
	float m_ExpireTimeIndex;
	unsigned m_OriginEntityID;
	bool m_WarnOriginEntityFlag;

	HazardData();
	virtual ~HazardData();
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual void Expire();
	bool ShouldWarnEntityID(unsigned entityID) const { return FShouldWarnEntityID(this, entityID); }
	virtual const Vec3& GetNormal() const = 0;
	virtual bool IsAgentAwareOfDanger(const Agent& agent, const Vec3& avoidPos) const = 0;
	float GetExpireTimeIndex() const { return FGetExpireTimeIndex(this); }
	virtual void CheckCollision(Agent& agent, HazardSystem::HazardCollisionResult* result) const = 0;

#if 0
	HazardData(const HazardSystem::HazardData& _arg0_);
	void BasicInit(const unsigned _arg0_, const HazardSystem::HazardSetup& _arg1_);
	unsigned GetInstanceID() const;
	unsigned GetOriginEntityID() const;
#endif

	static inline auto FHazardDataOv1 = PreyFunction<void(HazardSystem::HazardData* const _this)>(0x10C7FD0);
	static inline auto FBitNotHazardData = PreyFunction<void(HazardSystem::HazardData* const _this)>(0x10C7FF0);
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardData* const _this, TSerialize ser)>(0x10C8060);
	static inline auto FExpire = PreyFunction<void(HazardSystem::HazardData* const _this)>(0x1333E90);
	static inline auto FShouldWarnEntityID = PreyFunction<bool(const HazardSystem::HazardData* const _this, unsigned entityID)>(0x10C80F0);
	static inline auto FGetExpireTimeIndex = PreyFunction<float(const HazardSystem::HazardData* const _this)>(0x138B7A0);
};


} // namespace HazardSystem
#endif // MOONCRASH
