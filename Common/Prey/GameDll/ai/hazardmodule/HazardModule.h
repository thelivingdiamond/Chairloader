// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ai/gameaihelpers.h>
#include <Prey/GameDll/ai/hazardmodule/hazardprojectile.h>
#include <Prey/GameDll/ai/hazardmodule/hazardsphere.h>

class Agent;
namespace HazardSystem
{
class HazardProjectile;
class HazardProjectileID;
class HazardSetup;
class HazardSphere;
class HazardSphereID;
} // namespace HazardSystem
struct RayCastResult;

namespace HazardSystem
{

// HazardSystem::HazardModule
// Header:  Prey/GameDll/ai/hazardmodule/HazardModule.h
class HazardModule : public AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>
{ // Size=112 (0x70)
public:
	using BaseClass = AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>;
	using HazardDataProjectiles = std::vector<HazardSystem::HazardDataProjectile>;
	using HazardDataSpheres = std::vector<HazardSystem::HazardDataSphere>;

	static inline auto debugColor = PreyGlobal<const ColorF>(0x23DF3F8);
	static inline auto debugPrimitiveFadeDelay = PreyGlobal<const float>(0x1F19AB0);
	std::vector<HazardSystem::HazardDataProjectile> m_ProjectileHazards;
	std::vector<HazardSystem::HazardDataSphere> m_SphereHazards;
	int m_UpdateLockCount;
	unsigned m_InstanceIDGen;

	HazardModule();
	virtual void Reset(bool bUnload);
	virtual const char* GetName() const;
	virtual void Update(float elapsedTime);
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	void OnRayCastDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnRayCastDataReceived(this, rayID, result); }
	void ReportHazardCollisionsHelper() { FReportHazardCollisionsHelper(this); }

#if 0
	HazardSystem::HazardProjectileID ReportHazard(const HazardSystem::HazardSetup& _arg0_, const HazardSystem::HazardProjectile& _arg1_);
	HazardSystem::HazardSphereID ReportHazard(const HazardSystem::HazardSetup& _arg0_, const HazardSystem::HazardSphere& _arg1_);
	void ExpireHazard(const HazardSystem::HazardProjectileID _arg0_);
	void ExpireHazard(const HazardSystem::HazardSphereID _arg0_);
	bool ModifyHazard(const HazardSystem::HazardProjectileID _arg0_, const Vec3& _arg1_, const Vec3& _arg2_);
	bool IsHazardExpired(const HazardSystem::HazardProjectileID _arg0_) const;
	bool IsHazardExpired(const HazardSystem::HazardSphereID _arg0_) const;
	void ReportHazardCollisions();
	void ProcessCollisionsWithEntity(const unsigned _arg0_);
	void ProcessAgentAndProjectile(Agent& _arg0_, const HazardSystem::HazardDataProjectile& _arg1_);
	void ProcessAgentAndSphere(Agent& _arg0_, const HazardSystem::HazardDataSphere& _arg1_);
	void SendSignalToAgent(Agent& _arg0_, const char* _arg1_, const Vec3& _arg2_, const Vec3& _arg3_);
	unsigned GenerateHazardID();
	void RemoveExpiredHazards();
	void RemoveExpiredHazardsHelper();
	void PurgeAllHazards();
	HazardSystem::HazardDataProjectile* FindPendingProjectileRay(const unsigned _arg0_);
	void PurgeHazardsWithPendingRayRequests();
	void StartRequestedRayCasts();
#endif

	static inline auto FHazardModule = PreyFunction<void(HazardSystem::HazardModule* const _this)>(0x10C8880);
	static inline auto FReset = PreyFunction<void(HazardSystem::HazardModule* const _this, bool bUnload)>(0x10C9A30);
	static inline auto FGetName = PreyFunction<const char* (const HazardSystem::HazardModule* const _this)>(0x10C92C0);
	static inline auto FUpdate = PreyFunction<void(HazardSystem::HazardModule* const _this, float elapsedTime)>(0x10C9C80);
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardModule* const _this, TSerialize ser)>(0x10C9B10);
	static inline auto FPostSerialize = PreyFunction<void(HazardSystem::HazardModule* const _this)>(0x10C9640);
	static inline auto FOnRayCastDataReceived = PreyFunction<void(HazardSystem::HazardModule* const _this, const unsigned& rayID, const RayCastResult& result)>(0x10C95C0);
	static inline auto FReportHazardCollisionsHelper = PreyFunction<void(HazardSystem::HazardModule* const _this)>(0x10C9690);
};


} // namespace HazardSystem
#endif // MOONCRASH
