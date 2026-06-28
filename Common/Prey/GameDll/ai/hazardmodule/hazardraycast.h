// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ai/hazardmodule/hazard.h>

namespace HazardSystem
{
class HazardModule;
} // namespace HazardSystem
struct RayCastResult;

namespace HazardSystem
{

// HazardSystem::HazardDataRayCast
// Header:  Prey/GameDll/ai/hazardmodule/hazardraycast.h
class HazardDataRayCast : public HazardSystem::HazardData
{ // Size=56 (0x38)
public:
	enum class RayCastState
	{
		RayCastRequested = 0,
		RayCastPending = 1,
		RayCastCompleted = 2,
		RayCastLast = 3,
	};

	using BaseClass = HazardSystem::HazardData;

	HazardSystem::HazardDataRayCast::RayCastState m_RayCastState;
	unsigned m_QueuedRayID;
	Vec3 m_PendingRayStartPos;
	Vec3 m_PendingRayNormal;

	HazardDataRayCast();
	virtual ~HazardDataRayCast();
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	virtual void Expire();
	virtual bool HasPendingRayCasts() const;
	virtual void StartRequestedRayCasts(HazardSystem::HazardModule* hazardModule);
	bool IsWaitingForRay(const unsigned rayID) const { return FIsWaitingForRay(this, rayID); }
	virtual void QueueRayCast(HazardSystem::HazardModule* hazardModule, const Vec3& rayStartPos, const Vec3& rayNormal);
	void MainProcessRayCastResult(const unsigned rayID, const RayCastResult& result) { FMainProcessRayCastResult(this, rayID, result); }
	void CancelPendingRayCast() { FCancelPendingRayCast(this); }
	virtual float GetMaxRayCastDistance() const = 0;
	virtual void ProcessRayCastResult(const Vec3& rayStartPos, const Vec3& rayNormal, const RayCastResult& result) = 0;

#if 0
	HazardDataRayCast(const HazardSystem::HazardDataRayCast& _arg0_);
#endif

	static inline auto FHazardDataRayCastOv1 = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this)>(0x10CA5E0);
	static inline auto FBitNotHazardDataRayCast = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this)>(0x10CA620);
	static inline auto FSerialize = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this, TSerialize ser)>(0x10CAAA0);
	static inline auto FExpire = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this)>(0x10CA7E0);
	static inline auto FHasPendingRayCasts = PreyFunction<bool(const HazardSystem::HazardDataRayCast* const _this)>(0x10CA800);
	static inline auto FStartRequestedRayCasts = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this, HazardSystem::HazardModule* hazardModule)>(0x10CAB70);
	static inline auto FIsWaitingForRay = PreyFunction<bool(const HazardSystem::HazardDataRayCast* const _this, const unsigned rayID)>(0x10CA820);
	static inline auto FQueueRayCast = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this, HazardSystem::HazardModule* hazardModule, const Vec3& rayStartPos, const Vec3& rayNormal)>(0x10CA880);
	static inline auto FMainProcessRayCastResult = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this, const unsigned rayID, const RayCastResult& result)>(0x10CA860);
	static inline auto FCancelPendingRayCast = PreyFunction<void(HazardSystem::HazardDataRayCast* const _this)>(0x10CA670);
};


} // namespace HazardSystem
#endif // MOONCRASH
