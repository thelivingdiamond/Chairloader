// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CExactPositioningTrigger
// Header:  Prey/GameDll/ExactPositioningTrigger.h
class CExactPositioningTrigger
{ // Size=108 (0x6C)
public:
	enum EState
	{
		eS_Invalid = 0,
		eS_Initializing = 1,
		eS_Before = 2,
		eS_Optimizing = 3,
		eS_TriggeredPosition = 4,
		eS_Triggered = 5,
	};

	Vec3 m_pos;
	float m_width;
	Vec3 m_posSize;
	Quat m_orient;
	float m_cosOrientTolerance;
	float m_sideTime;
	float m_distanceErrorFactor;
	float m_orientStartDist;
	float m_animMovementLength;
	float m_distanceError;
	float m_orientError;
	float m_oldFwdDir;
	CExactPositioningTrigger::EState m_state;
	Vec3 m_userPos;
	Quat m_userOrient;

	CExactPositioningTrigger();
	CExactPositioningTrigger(const Vec3& pos, float width, const Vec3& triggerSize, const Quat& orient, float orientTolerance, float animMovementLength, float orientStartDist);
	void Update(float frameTime, Vec3 userPos, Quat userOrient, bool allowTriggering) { FUpdate(this, frameTime, userPos, userOrient, allowTriggering); }
	void ResetRadius(const Vec3& triggerSize, float orientTolerance) { FResetRadius(this, triggerSize, orientTolerance); }

#if 0
	bool IsTriggeredPosition() const;
	bool IsReached() const;
	bool IsTriggered() const;
	void SetDistanceErrorFactor(float _arg0_);
#endif

	static inline auto FCExactPositioningTriggerOv3 = PreyFunction<void(CExactPositioningTrigger* const _this)>(0x17E3910);
	static inline auto FCExactPositioningTriggerOv2 = PreyFunction<void(CExactPositioningTrigger* const _this, const Vec3& pos, float width, const Vec3& triggerSize, const Quat& orient, float orientTolerance, float animMovementLength, float orientStartDist)>(0x17E3760);
	static inline auto FUpdate = PreyFunction<void(CExactPositioningTrigger* const _this, float frameTime, Vec3 userPos, Quat userOrient, bool allowTriggering)>(0x17E3A10);
	static inline auto FResetRadius = PreyFunction<void(CExactPositioningTrigger* const _this, const Vec3& triggerSize, float orientTolerance)>(0x17E3990);
};
#endif // MOONCRASH
