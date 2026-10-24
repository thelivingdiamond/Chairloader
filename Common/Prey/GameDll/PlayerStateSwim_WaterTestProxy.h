// Header file automatically created from a PDB.
#pragma once

class CPlayer;
struct IPhysicalEntity;
struct RayCastResult;

// CPlayerStateSwim_WaterTestProxy
// Header:  Prey/GameDll/PlayerStateSwim_WaterTestProxy.h
class CPlayerStateSwim_WaterTestProxy
{ // Size=68 (0x44)
public:
	enum EProxyInternalState
	{
		eProxyInternalState_OutOfWater = 0,
		eProxyInternalState_PartiallySubmerged = 1,
		eProxyInternalState_Swimming = 2,
	};

	CPlayerStateSwim_WaterTestProxy::EProxyInternalState m_internalState;
	CPlayerStateSwim_WaterTestProxy::EProxyInternalState m_lastInternalState;
	Vec3 m_lastWaterLevelCheckPosition;
	float m_submergedFraction;
	float m_bottomLevel;
	float m_relativeBottomLevel;
	float m_waterLevel;
	float m_playerWaterLevel;
	float m_swimmingTimer;
	float m_drowningTimer;
	float m_oxygenLevel;
	float m_timeWaterLevelLastUpdated;
	float m_lastRayCastResult;
	bool m_headUnderwater;
	bool m_headComingOutOfWater;
	bool m_shouldSwim;
	unsigned m_bottomLevelRayID;
#ifndef MOONCRASH
	static inline auto s_rayLength = PreyGlobal<float>(0x2282584);
#else
	static inline auto s_rayLength = PreyGlobal<float>(0x23F108C);
#endif

	CPlayerStateSwim_WaterTestProxy();
	~CPlayerStateSwim_WaterTestProxy();
	void Reset(bool bCancelRays) { FReset(this, bCancelRays); }
	void OnEnterWater(const CPlayer& player) { FOnEnterWater(this, player); }
	void OnExitWater(const CPlayer& player) { FOnExitWater(this, player); }
	void PreUpdateNotSwimming(const CPlayer& player, const float frameTime) { FPreUpdateNotSwimming(this, player, frameTime); }
	void PreUpdateSwimming(const CPlayer& player, const float frameTime) { FPreUpdateSwimming(this, player, frameTime); }
	void Update(const CPlayer& player, const float frameTime) { FUpdate(this, player, frameTime); }
	void ForceUpdateBottomLevel(const CPlayer& player) { FForceUpdateBottomLevel(this, player); }
	void UpdateOutOfWater(const CPlayer& player, const float frameTime) { FUpdateOutOfWater(this, player, frameTime); }
	void UpdateInWater(const CPlayer& player, const float frameTime) { FUpdateInWater(this, player, frameTime); }
	void OnRayCastBottomLevelDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnRayCastBottomLevelDataReceived(this, rayID, result); }
	void RayTestBottomLevel(const CPlayer& player, const Vec3& referencePosition, float maxRelevantDepth) { FRayTestBottomLevel(this, player, referencePosition, maxRelevantDepth); }
	void CancelPendingRays() { FCancelPendingRays(this); }

#if 0
	bool ShouldSwim() const;
	bool ShouldSwim(const float _arg0_) const;
	bool IsInWater() const;
	bool IsHeadUnderWater() const;
	bool IsHeadComingOutOfWater() const;
	float GetRelativeBottomDepth() const;
	float GetWaterLevel() const;
	float GetRelativeWaterLevel() const;
	float GetSwimmingTimer() const;
	float GetLastRaycastResult() const;
	void SetSubmergedFraction(const float _arg0_);
	float GetSubmergedFraction() const;
	float GetWaterLevelTimeUpdated() const;
	float GetOxygenLevel() const;
	static float GetRayLength();
	void UpdateWaterLevel(const Vec3& _arg0_, const Vec3& _arg1_, IPhysicalEntity* _arg2_);
	void UpdateSubmergedFraction(const float _arg0_, const float _arg1_, const float _arg2_);
	static Vec3 GetLocalReferencePosition(const CPlayer& _arg0_);
	void UpdateDrowningTimer(const float _arg0_);
	void UpdateDrowning(const CPlayer& _arg0_);
	bool IsWaitingForBottomLevelResults() const;
#endif

#ifndef MOONCRASH
	static inline auto FCPlayerStateSwim_WaterTestProxyOv1 = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x17C25F0);
	static inline auto FBitNotCPlayerStateSwim_WaterTestProxy = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x17C2640);
	static inline auto FReset = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, bool bCancelRays)>(0x17C2E70);
	static inline auto FOnEnterWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x17C2840);
	static inline auto FOnExitWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x17C2C30);
	static inline auto FPreUpdateNotSwimming = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x17C2CC0);
	static inline auto FPreUpdateSwimming = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x17C2CE0);
	static inline auto FUpdate = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x17C2EE0);
	static inline auto FForceUpdateBottomLevel = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x17C27E0);
	static inline auto FUpdateOutOfWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x17C3800);
	static inline auto FUpdateInWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x17C3050);
	static inline auto FOnRayCastBottomLevelDataReceived = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const unsigned& rayID, const RayCastResult& result)>(0x17C2C90);
	static inline auto FRayTestBottomLevel = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const Vec3& referencePosition, float maxRelevantDepth)>(0x17C2CF0);
	static inline auto FCancelPendingRays = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x17C2650);
#else
	static inline auto FCPlayerStateSwim_WaterTestProxyOv1 = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x18E98A0);
	static inline auto FBitNotCPlayerStateSwim_WaterTestProxy = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x18E98F0);
	static inline auto FReset = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, bool bCancelRays)>(0x18EA120);
	static inline auto FOnEnterWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x18E9AF0);
	static inline auto FOnExitWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x18E9EE0);
	static inline auto FPreUpdateNotSwimming = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x18E9F70);
	static inline auto FPreUpdateSwimming = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x18E9F90);
	static inline auto FUpdate = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x18EA190);
	static inline auto FForceUpdateBottomLevel = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player)>(0x18E9A90);
	static inline auto FUpdateOutOfWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x18EAAA0);
	static inline auto FUpdateInWater = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const float frameTime)>(0x18EA300);
	static inline auto FOnRayCastBottomLevelDataReceived = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const unsigned& rayID, const RayCastResult& result)>(0x18E9F40);
	static inline auto FRayTestBottomLevel = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this, const CPlayer& player, const Vec3& referencePosition, float maxRelevantDepth)>(0x18E9FA0);
	static inline auto FCancelPendingRays = PreyFunction<void(CPlayerStateSwim_WaterTestProxy* const _this)>(0x18E9900);
#endif
};

