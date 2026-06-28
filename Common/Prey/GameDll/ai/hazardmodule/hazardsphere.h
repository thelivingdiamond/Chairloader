// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ai/hazardmodule/hazard.h>
#include <_unknown/HazardSystem__HazardSphere.h>

class Agent;
namespace HazardSystem
{
class HazardCollisionResult;
class HazardSphereID;
} // namespace HazardSystem

namespace HazardSystem
{

// HazardSystem::HazardDataSphere
// Header:  Prey/GameDll/ai/hazardmodule/hazardsphere.h
class HazardDataSphere : public HazardSystem::HazardData
{ // Size=48 (0x30)
public:
	HazardSystem::HazardSphere m_Context;
	float m_RadiusSq;

	HazardDataSphere();
	HazardDataSphere(const HazardSystem::HazardDataSphere& source);
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual const Vec3& GetNormal() const;
	virtual bool IsAgentAwareOfDanger(const Agent& agent, const Vec3& avoidPos) const;
	virtual void CheckCollision(Agent& agent, HazardSystem::HazardCollisionResult* result) const;

#if 0
	HazardSystem::HazardSphereID GetTypeInstanceID() const;
#endif

	static inline auto FHazardDataSphereOv1 = PreyFunction<void(HazardSystem::HazardDataSphere* const _this)>(0x10CABE0);
	static inline auto FHazardDataSphereOv0 = PreyFunction<void(HazardSystem::HazardDataSphere* const _this, const HazardSystem::HazardDataSphere& source)>(0x10CAB90);
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardDataSphere* const _this, TSerialize ser)>(0x10CACF0);
	static inline auto FGetNormal = PreyFunction<const Vec3& (const HazardSystem::HazardDataSphere* const _this)>(0x10CACE0);
	static inline auto FIsAgentAwareOfDanger = PreyFunction<bool(const HazardSystem::HazardDataSphere* const _this, const Agent& agent, const Vec3& avoidPos)>(0x1A302A0);
	static inline auto FCheckCollision = PreyFunction<void(const HazardSystem::HazardDataSphere* const _this, Agent& agent, HazardSystem::HazardCollisionResult* result)>(0x10CAC50);
};


} // namespace HazardSystem
#endif // MOONCRASH
