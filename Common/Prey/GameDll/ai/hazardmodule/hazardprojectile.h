// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ai/hazardmodule/hazardraycast.h>

class Agent;
namespace HazardSystem
{
class HazardCollisionResult;
class HazardProjectileID;
} // namespace HazardSystem
struct RayCastResult;

namespace HazardSystem
{

// HazardSystem::HazardDataProjectile
// Header:  Prey/GameDll/ai/hazardmodule/hazardprojectile.h
class HazardDataProjectile : public HazardSystem::HazardDataRayCast
{ // Size=104 (0x68)
public:
	using BaseClass = HazardSystem::HazardDataRayCast;

	Vec3 m_AreaStartPos;
	Vec3 m_MoveNormal;
	float m_Radius;
	float m_MaxScanDistance;
	float m_MaxPosDeviationDistance;
	float m_MaxCosAngleDeviation;
	float m_AreaLength;
	unsigned m_IgnoredWeaponEntityID;

	HazardDataProjectile();
	HazardDataProjectile(const HazardSystem::HazardDataProjectile& source);
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual const Vec3& GetNormal() const;
	virtual bool IsAgentAwareOfDanger(const Agent& agent, const Vec3& avoidPos) const;
	virtual void CheckCollision(Agent& agent, HazardSystem::HazardCollisionResult* result) const;
	virtual float GetMaxRayCastDistance() const;
	virtual void ProcessRayCastResult(const Vec3& rayStartPos, const Vec3& rayNormal, const RayCastResult& result);

#if 0
	bool IsHazardAreaDefined() const;
	HazardSystem::HazardProjectileID GetTypeInstanceID() const;
	bool IsApproximationAcceptable(const Vec3& _arg0_, const Vec3& _arg1_) const;
#endif

	static inline auto FHazardDataProjectileOv1 = PreyFunction<void(HazardSystem::HazardDataProjectile* const _this)>(0x10CA220);
	static inline auto FHazardDataProjectileOv0 = PreyFunction<void(HazardSystem::HazardDataProjectile* const _this, const HazardSystem::HazardDataProjectile& source)>(0x10CA1A0);
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardDataProjectile* const _this, TSerialize ser)>(0x10CA4C0);
	static inline auto FGetNormal = PreyFunction<const Vec3& (const HazardSystem::HazardDataProjectile* const _this)>(0x13691B0);
	static inline auto FIsAgentAwareOfDanger = PreyFunction<bool(const HazardSystem::HazardDataProjectile* const _this, const Agent& agent, const Vec3& avoidPos)>(0x10CA440);
	static inline auto FCheckCollision = PreyFunction<void(const HazardSystem::HazardDataProjectile* const _this, Agent& agent, HazardSystem::HazardCollisionResult* result)>(0x10CA2B0);
	static inline auto FGetMaxRayCastDistance = PreyFunction<float(const HazardSystem::HazardDataProjectile* const _this)>(0x10CA430);
	static inline auto FProcessRayCastResult = PreyFunction<void(HazardSystem::HazardDataProjectile* const _this, const Vec3& rayStartPos, const Vec3& rayNormal, const RayCastResult& result)>(0x10CA480);
};


} // namespace HazardSystem
#endif // MOONCRASH
