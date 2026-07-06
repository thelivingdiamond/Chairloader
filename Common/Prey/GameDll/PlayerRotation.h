// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class CPlayer;
struct IItem;
struct IPhysicalEntity;
struct RayCastResult;
struct SActorFrameMovementParams;
struct SAimAccelerationParams;
struct SLinkStats;

// CPlayerRotation
// Header:  Prey/GameDll/PlayerRotation.h
class CPlayerRotation
{ // Size=328 (0x148)
public:
	// CPlayerRotation::SLeanAndPeekInfo
	// Header:  Prey/GameDll/PlayerRotation.h
	struct SLeanAndPeekInfo
	{ // Size=16 (0x10)
		unsigned m_queuedRayID;
		Vec3 m_lastLimit;

		void OnRayCastDataReceived(const unsigned& rayID, const RayCastResult& result) { FOnRayCastDataReceived(this, rayID, result); }
		void CancelPendingRay() { FCancelPendingRay(this); }

	#if 0
		SLeanAndPeekInfo();
		~SLeanAndPeekInfo();
		void Reset();
		const Vec3& GetLeanLimit(const Vec3& _arg0_, const Vec3& _arg1_, int _arg2_, int _arg3_, IPhysicalEntity* * _arg4_, int _arg5_);
	#endif

		static inline auto FOnRayCastDataReceived = PreyFunction<void(CPlayerRotation::SLeanAndPeekInfo* const _this, const unsigned& rayID, const RayCastResult& result)>(0x18DBE20);
		static inline auto FCancelPendingRay = PreyFunction<void(CPlayerRotation::SLeanAndPeekInfo* const _this)>(0x18BC640);
	};

	float m_hoverRollBlend;
	float m_hoverPitchMult;
	float m_hoverPitchMaxIdle;
	float m_hoverPitchMaxMove;
	float m_hoverPivotHeight;
	CPlayerRotation::SLeanAndPeekInfo m_leanAndPeekInfo;
	const CPlayer& m_player;
	Ang3 m_viewAngles;
	Quat m_viewQuat;
	Quat m_viewQuatFinal;
	Quat m_baseQuat;
	Quat m_baseQuatLinked;
	Quat m_viewQuatLinked;
	Ang3 m_frameViewAnglesOffset;
	Vec3 m_forceLookVector;
	Vec3 m_snap_target_dir;
	Vec3 m_follow_target_dir;
	unsigned m_follow_target_id;
	unsigned m_snap_target_id;
	float m_rollSpeed;
	Vec3 m_normalToAlignView;
	Vec3 m_normalToAlignGround;
	bool m_bHasLanded;
	float m_viewRoll;
	float m_leanAmount;
	float m_peekOverAmount;
	Ang3 m_angularImpulse;
	Ang3 m_angularImpulseDelta;
	float m_angularImpulseTime;
	float m_angularImpulseDeceleration;
	float m_angularImpulseTimeMax;
	Ang3 m_deltaAngles;
	Ang3 m_externalAngles;
	bool m_currently_snapping;
	bool m_bForcedLookAtBlendingEnabled;
	float m_hoverOverrideRollSpeed;
	float m_hoverOverrideRollTarget;
	float m_zeroGDesiredPitch;
	float m_zeroGDesiredRoll;
	bool m_bHasZeroGDesiredOrient;

	CPlayerRotation(const CPlayer& player);
	void Process(IItem* pCurrentItem, const SActorFrameMovementParams& movement, const SAimAccelerationParams& verticalAcceleration, float frameTime) { FProcess(this, pCurrentItem, movement, verticalAcceleration, frameTime); }
	void FullSerialize(TSerialize ser) { FFullSerialize(this, ser); }
	void SetViewRotation(const Quat& rotation) { FSetViewRotation(this, rotation); }
	void SetViewRotationOnRevive(const Quat& rotation) { FSetViewRotationOnRevive(this, rotation); }
	void AddAngularImpulse(const Ang3& angular, float deceleration, float duration) { FAddAngularImpulse(this, angular, deceleration, duration); }
	void ResetLinkedRotation(const Quat& rotation) { FResetLinkedRotation(this, rotation); }
	void ProcessNormalRoll(float frameTime) { FProcessNormalRoll(this, frameTime); }
	void ProcessNormal(float frameTime, const SAimAccelerationParams& verticalAcceleration) { FProcessNormal(this, frameTime, verticalAcceleration); }
	void ProcessNormalHover(float frameTime, const SAimAccelerationParams& verticalAcceleration) { FProcessNormalHover(this, frameTime, verticalAcceleration); }
	void HoverPivot(const Ang3& _deltaAngles) { FHoverPivot(this, _deltaAngles); }
	void ProcessLeanAndPeek(const SActorFrameMovementParams& movement) { FProcessLeanAndPeek(this, movement); }
	void ProcessLinkedState(SLinkStats& linkStats, const Quat& lastBaseQuat, const Quat& lastViewQuat) { FProcessLinkedState(this, linkStats, lastBaseQuat, lastViewQuat); }
	void ProcessFinalViewEffects(float minAngle, float maxAngle) { FProcessFinalViewEffects(this, minAngle, maxAngle); }
	void ClampAngles(float minAngle, float maxAngle) { FClampAngles(this, minAngle, maxAngle); }
	void NormalizeQuats() { FNormalizeQuats(this); }

#if 0
	void ProcessZeroG(IItem* _arg0_, const SActorFrameMovementParams& _arg1_, const SAimAccelerationParams& _arg2_, float _arg3_);
	bool HasLanded() const;
	void SetBaseQuat(const Quat& _arg0_);
	const Quat& GetBaseQuat() const;
	const Quat& GetViewQuat() const;
	const Quat& GetViewQuatFinal() const;
	const Ang3& GetViewAngles() const;
	float GetLeanAmount() const;
	float GetLeanPeekOverAmount() const;
	void SetViewRotationAndKeepBaseOrientation(const Quat& _arg0_);
	void AddViewAngles(const Ang3& _arg0_);
	void AddViewAngleOffsetForFrame(const Ang3& _arg0_);
	void SetForceLookAt(const Vec3& _arg0_, const bool _arg1_);
	void GetStanceAngleLimits(const SAimAccelerationParams& _arg0_, IItem* _arg1_, float& _arg2_, float& _arg3_);
	float GetLocalPitch();
	void ProcessForcedLookDirection(const Quat& _arg0_, float _arg1_);
	void ProcessAngularImpulses(float _arg0_);
	void SetHoverRollBlend(float _arg0_);
	void SetHoverPitch(float _arg0_, float _arg1_, float _arg2_);
	void SetHoverPivotHeight(float _arg0_);
	void HoverOverrideRollSet(float _arg0_, float _arg1_);
	void HoverOverrideRollClear();
	void SetDesiredZeroGPitchRoll(float _arg0_, float _arg1_);
	void ClearDesiredZeroGPitchRoll();
	IItem* GetCurrentItem(bool _arg0_);
#endif

	static inline auto FCPlayerRotationOv2 = PreyFunction<void(CPlayerRotation* const _this, const CPlayer& player)>(0x18DABF0);
	static inline auto FProcess = PreyFunction<void(CPlayerRotation* const _this, IItem* pCurrentItem, const SActorFrameMovementParams& movement, const SAimAccelerationParams& verticalAcceleration, float frameTime)>(0x18DBE50);
	static inline auto FFullSerialize = PreyFunction<void(CPlayerRotation* const _this, TSerialize ser)>(0x18DB4B0);
	static inline auto FSetViewRotation = PreyFunction<void(CPlayerRotation* const _this, const Quat& rotation)>(0x18DE660);
	static inline auto FSetViewRotationOnRevive = PreyFunction<void(CPlayerRotation* const _this, const Quat& rotation)>(0x18DE9A0);
	static inline auto FAddAngularImpulse = PreyFunction<void(CPlayerRotation* const _this, const Ang3& angular, float deceleration, float duration)>(0x18DAD30);
	static inline auto FResetLinkedRotation = PreyFunction<void(CPlayerRotation* const _this, const Quat& rotation)>(0x18DE550);
	static inline auto FProcessNormalRoll = PreyFunction<void(CPlayerRotation* const _this, float frameTime)>(0x18DE2D0);
	static inline auto FProcessNormal = PreyFunction<void(CPlayerRotation* const _this, float frameTime, const SAimAccelerationParams& verticalAcceleration)>(0x18DD590);
	static inline auto FProcessNormalHover = PreyFunction<void(CPlayerRotation* const _this, float frameTime, const SAimAccelerationParams& verticalAcceleration)>(0x18DD890);
	static inline auto FHoverPivot = PreyFunction<void(CPlayerRotation* const _this, const Ang3& _deltaAngles)>(0x18DB5B0);
	static inline auto FProcessLeanAndPeek = PreyFunction<void(CPlayerRotation* const _this, const SActorFrameMovementParams& movement)>(0x18DC7C0);
	static inline auto FProcessLinkedState = PreyFunction<void(CPlayerRotation* const _this, SLinkStats& linkStats, const Quat& lastBaseQuat, const Quat& lastViewQuat)>(0x18DCE00);
	static inline auto FProcessFinalViewEffects = PreyFunction<void(CPlayerRotation* const _this, float minAngle, float maxAngle)>(0x18DC3E0);
	static inline auto FClampAngles = PreyFunction<void(CPlayerRotation* const _this, float minAngle, float maxAngle)>(0x18DAD80);
	static inline auto FNormalizeQuats = PreyFunction<void(CPlayerRotation* const _this)>(0x18DBC50);
};
#endif // MOONCRASH
