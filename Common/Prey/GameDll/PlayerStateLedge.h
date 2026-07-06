// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class CPlayer;
struct IItemParamsNode;
struct SActorFrameMovementParams;
struct SLedgeTransitionData;
struct SStateEventLedge;

// CPlayerStateLedge
// Header:  Prey/GameDll/PlayerStateLedge.h
class CPlayerStateLedge
{ // Size=104 (0x68)
public:
	// CPlayerStateLedge::SLedgeBlending
	// Header:  Prey/GameDll/PlayerStateLedge.h
	struct SLedgeBlending
	{ // Size=40 (0x28)
		QuatT m_qtTargetLocation;
		Vec3 m_forwardDir;

	#if 0
		SLedgeBlending();
	#endif
	};

	// CPlayerStateLedge::SLedgeBlendingParams
	// Header:  Prey/GameDll/PlayerStateLedge.h
	struct SLedgeBlendingParams
	{ // Size=40 (0x28)
		float m_fMoveDuration;
		float m_fCorrectionDuration;
		Vec3 m_vPositionOffset;
		Vec3 m_vExitVelocity;
		ELedgeType m_ledgeType;
		bool m_bIsVault;
		bool m_bIsHighVault;
		bool m_bKeepOrientation;
		bool m_bEndFalling;

	#if 0
		SLedgeBlendingParams();
		void SetParamsFromXml(const IItemParamsNode* _arg0_);
	#endif
	};

	// CPlayerStateLedge::SLedgeNearbyParams
	// Header:  Prey/GameDll/PlayerStateLedge.h
	struct SLedgeNearbyParams
	{ // Size=24 (0x18)
		Vec3 m_vSearchDir;
		float m_fMaxDistance;
		float m_fMaxAngleDeviationFromSearchDirInDegrees;
		float m_fMaxExtendedAngleDeviationFromSearchDirInDegrees;

	#if 0
		SLedgeNearbyParams();
		void SetParamsFromXml(const IItemParamsNode* _arg0_);
	#endif
	};

	// CPlayerStateLedge::SLedgeGrabbingParams
	// Header:  Prey/GameDll/PlayerStateLedge.h
	struct SLedgeGrabbingParams
	{ // Size=396 (0x18C)
		float m_fNormalSpeedUp;
		float m_fMobilitySpeedUp;
		float m_fMobilitySpeedUpMaximum;
		CPlayerStateLedge::SLedgeNearbyParams m_ledgeNearbyParams;
		CPlayerStateLedge::SLedgeBlendingParams m_grabTransitionsParams[9];

		SLedgeGrabbingParams();

	#if 0
		void SetParamsFromXml(const IItemParamsNode* _arg0_);
	#endif

		static inline auto FSLedgeGrabbingParamsOv2 = PreyFunction<void(CPlayerStateLedge::SLedgeGrabbingParams* const _this)>(0x18E4A10);
	};

	float m_ledgeSpeedMultiplier;
	float m_lastTimeOnLedge;
	Vec3 m_exitVelocity;
	Vec3 m_ledgePreviousPosition;
	Vec3 m_ledgePreviousPositionDiff;
	Quat m_ledgePreviousRotation;
	bool m_onLedge;
	bool m_enterFromGround;
	bool m_enterFromSprint;
	uint8_t m_postSerializeLedgeTransition;
	CPlayerStateLedge::SLedgeBlending m_ledgeBlending;
	static inline auto s_ledgeGrabbingParams = PreyGlobal<CPlayerStateLedge::SLedgeGrabbingParams>(0x2D933E0);

	CPlayerStateLedge();
	~CPlayerStateLedge();
	void OnEnter(CPlayer& player, const SStateEventLedge& ledgeEvent) { FOnEnter(this, player, ledgeEvent); }
	void OnPrePhysicsUpdate(CPlayer& player, const SActorFrameMovementParams& movement, float frameTime) { FOnPrePhysicsUpdate(this, player, movement, frameTime); }
	void OnAnimFinished(CPlayer& player) { FOnAnimFinished(this, player); }
	void OnExit(CPlayer& player) { FOnExit(this, player); }
	void Serialize(TSerialize serializer) { FSerialize(this, serializer); }
	void PostSerialize(CPlayer& player) { FPostSerialize(this, player); }

#if 0
	static void SetParamsFromXml(const IItemParamsNode* _arg0_);
	bool IsOnLedge() const;
	static bool TryLedgeGrab(CPlayer& _arg0_, const float _arg1_, const float _arg2_, const bool _arg3_, SLedgeTransitionData* _arg4_, const bool _arg5_);
	static bool CanGrabOntoLedge(const CPlayer& _arg0_);
	static void UpdateNearestGrabbableLedge(const CPlayer& _arg0_, SLedgeTransitionData* _arg1_, const bool _arg2_);
	static bool CanReachPlatform(const CPlayer& _arg0_, const Vec3& _arg1_, const Vec3& _arg2_);
	QuatT CalculateLedgeOffsetLocation(const Matrix34& _arg0_, const Vec3& _arg1_, const bool _arg2_) const;
	void StartLedgeBlending(CPlayer& _arg0_, const CPlayerStateLedge::SLedgeBlendingParams& _arg1_);
	float GetLedgeGrabSpeed(const CPlayer& _arg0_) const;
	static CPlayerStateLedge::SLedgeGrabbingParams& GetLedgeGrabbingParams();
#endif

	static inline auto FCPlayerStateLedgeOv1 = PreyFunction<void(CPlayerStateLedge* const _this)>(0x18E49C0);
	static inline auto FBitNotCPlayerStateLedge = PreyFunction<void(CPlayerStateLedge* const _this)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(CPlayerStateLedge* const _this, CPlayer& player, const SStateEventLedge& ledgeEvent)>(0x1333E90);
	static inline auto FOnPrePhysicsUpdate = PreyFunction<void(CPlayerStateLedge* const _this, CPlayer& player, const SActorFrameMovementParams& movement, float frameTime)>(0x1333E90);
	static inline auto FOnAnimFinished = PreyFunction<void(CPlayerStateLedge* const _this, CPlayer& player)>(0x1333E90);
	static inline auto FOnExit = PreyFunction<void(CPlayerStateLedge* const _this, CPlayer& player)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CPlayerStateLedge* const _this, TSerialize serializer)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(CPlayerStateLedge* const _this, CPlayer& player)>(0x1333E90);
};
#endif // MOONCRASH
