// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/ArkEntityGrabber.h
class ArkEntityGrabber // Id=8017451 Size=40
{
public:
	float m_breakDistanceSq;
	float m_lastDesiredLerpVelocity;
	float m_timeUnderDesiredLerpVelocity;
	float m_totalDistanceForLerp;
	float m_lerpSpeed;
	float m_lerpObstructedSpeed;
	float m_lerpAcceleration;
	float m_lerpObstructedAcceleration;
	float m_maxTimeAllowedUnderDesiredLerpVelocity;
	bool m_bConstrained;
	
	void Start(IEntity &_entity, const bool _bConstrained, const bool _bSimple, const bool _bRemote) { FStart(this,_entity,_bConstrained,_bSimple,_bRemote); }
	bool Update(IEntity &_entity, Vec3 _target, const float _frameTime, Quat _desiredRotation, const bool _bSimple) { return FUpdate(this,_entity,_target,_frameTime,_desiredRotation,_bSimple); }
	static void Stop(IEntity &_entity) { FStop(_entity); }
	void ConstrainCarriedObject(const bool _bSimple, IEntity &_entity) { FConstrainCarriedObject(this,_bSimple,_entity); }
	
#if 0
	void Initialize(const float arg0, const float arg1, const float arg2, const float arg3, const float arg4, const float arg5, const bool arg6);
	bool IsConstrained() const;
#endif
	
	static inline auto FStart = PreyFunction<void(ArkEntityGrabber *const _this, IEntity &_entity, const bool _bConstrained, const bool _bSimple, const bool _bRemote)>(0x115AAA0);
	static inline auto FUpdate = PreyFunction<bool(ArkEntityGrabber *const _this, IEntity &_entity, Vec3 _target, const float _frameTime, Quat _desiredRotation, const bool _bSimple)>(0x115AF50);
	static inline auto FStop = PreyFunction<void(IEntity &_entity)>(0x115AD80);
	static inline auto FConstrainCarriedObject = PreyFunction<void(ArkEntityGrabber *const _this, const bool _bSimple, IEntity &_entity)>(0x115AA00);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkEntityGrabber
// Header:  Prey/GameDll/ark/ArkEntityGrabber.h
class ArkEntityGrabber
{ // Size=40 (0x28)
public:
	float m_breakDistanceSq;
	float m_lastDesiredLerpVelocity;
	float m_timeUnderDesiredLerpVelocity;
	float m_totalDistanceForLerp;
	float m_lerpSpeed;
	float m_lerpObstructedSpeed;
	float m_lerpAcceleration;
	float m_lerpObstructedAcceleration;
	float m_maxTimeAllowedUnderDesiredLerpVelocity;
	bool m_bConstrained;

	void Start(IEntity& _entity, const bool _bConstrained, const bool _bSimple, const bool _bRemote) { FStart(this, _entity, _bConstrained, _bSimple, _bRemote); }
	bool Update(IEntity& _entity, const Vec3 _target, const float _frameTime, const Quat _desiredRotation, const bool _bSimple) { return FUpdate(this, _entity, _target, _frameTime, _desiredRotation, _bSimple); }
	static void Stop(IEntity& _entity) { FStop(_entity); }
	void ConstrainCarriedObject(const bool _bSimple, IEntity& _entity) { FConstrainCarriedObject(this, _bSimple, _entity); }

#if 0
	ArkEntityGrabber();
	void Initialize(const float _arg0_, const float _arg1_, const float _arg2_, const float _arg3_, const float _arg4_, const float _arg5_, const bool _arg6_);
	bool IsConstrained() const;
#endif

	static inline auto FStart = PreyFunction<void(ArkEntityGrabber* const _this, IEntity& _entity, const bool _bConstrained, const bool _bSimple, const bool _bRemote)>(0x11A9A10);
	static inline auto FUpdate = PreyFunction<bool(ArkEntityGrabber* const _this, IEntity& _entity, const Vec3 _target, const float _frameTime, const Quat _desiredRotation, const bool _bSimple)>(0x11A9ED0);
	static inline auto FStop = PreyFunction<void(IEntity& _entity)>(0x11A9D00);
	static inline auto FConstrainCarriedObject = PreyFunction<void(ArkEntityGrabber* const _this, const bool _bSimple, IEntity& _entity)>(0x11A9970);
};
#endif // !MOONCRASH
