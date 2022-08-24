// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
//#include "ArkNpcLookDesireManager.h"

class ArkNpcLookDesireManager;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h
class ArkNpcLookDesire : public ArkNpcDesireBase<ArkNpcLookDesireManager,ArkNpcLookDesire,enum EArkNpcLookDesirePriority> // Id=801409D Size=224
{
public:
	using Callback = ArkDelegate<void __cdecl(enum EArkNpcLookDesireCallbackEvent)>;
	
	class TargetParam // Id=80140A2 Size=8
	{
	public:
		ArkNpcDesireTarget const &m_target;
		
		TargetParam(ArkNpcDesireTarget const &_target);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::TargetParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455F30);
	};

	class AimParam // Id=80140E4 Size=1
	{
	public:
		bool m_bEnable;
		
		AimParam(bool _bEnable);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::AimParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D20);
	};

	struct LookPoseParam // Id=80140E5 Size=16
	{
		float m_torso;
		float m_head;
		float m_eyes;
		float m_aim;
		
#if 0
		bool operator==(ArkNpcLookDesire::LookPoseParam const &arg0) const;
		bool operator!=(ArkNpcLookDesire::LookPoseParam const &arg0) const;
		ArkNpcLookDesire::LookPoseParam FillDefaults(ArkNpcLookDesire::LookPoseParam &arg0);
		ArkNpcLookDesire::LookPoseParam Scale(ArkNpcLookDesire::LookPoseParam arg0);
#endif
	};

	class BlendTimeParam // Id=80140E6 Size=32
	{
	public:
		ArkNpcLookDesire::LookPoseParam m_blendInTime;
		ArkNpcLookDesire::LookPoseParam m_blendOutTime;
		
		BlendTimeParam(ArkNpcLookDesire::LookPoseParam const &_blendInTime, ArkNpcLookDesire::LookPoseParam const &_blendOutTime);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::BlendTimeParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D60);
	};

	class SmoothTimeParam // Id=80140E7 Size=16
	{
	public:
		ArkNpcLookDesire::LookPoseParam m_smoothTime;
		
		SmoothTimeParam(ArkNpcLookDesire::LookPoseParam const &_smoothTime);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::SmoothTimeParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455ED0);
	};

	class MaxAngleParam // Id=80140E8 Size=32
	{
	public:
		ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansYaw;
		ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansPitch;
		
		MaxAngleParam(ArkNpcLookDesire::LookPoseParam const &_maxYaw, ArkNpcLookDesire::LookPoseParam const &_maxPitch);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::MaxAngleParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455DF0);
	};

	class AllowLowerBodyTurnParam // Id=80140E9 Size=1
	{
	public:
		const bool m_bAllow;
		
		AllowLowerBodyTurnParam(bool _bAllow);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::AllowLowerBodyTurnParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D40);
	};

	class MinSpeedParam // Id=80140EA Size=4
	{
	public:
		EArkNpcSpeedType m_minSpeed;
		
		MinSpeedParam(EArkNpcSpeedType _minSpeed);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::MinSpeedParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455E80);
	};

	class StyleParam // Id=80140EB Size=4
	{
	public:
		ELookStyle m_style;
		
		StyleParam(ELookStyle _style);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::StyleParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455F20);
	};

	class PolarOffsetParam // Id=80140EC Size=8
	{
	public:
		const float m_x;
		const float m_y;
		
		PolarOffsetParam(float _x, float _y);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::PolarOffsetParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455E90);
	};

	class BodyOrientationParam // Id=80140ED Size=4
	{
	public:
		EBodyOrientationMode m_orientMode;
		
		BodyOrientationParam(EBodyOrientationMode _orientMode);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::BodyOrientationParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455DE0);
	};

	ArkNpcDesireTarget m_target;
	bool m_bUseAim;
	bool m_bAllowLowerBodyTurn;
	ELookStyle m_style;
	EBodyOrientationMode m_orientMode;
	EArkNpcSpeedType m_minSpeed;
	ArkNpcLookDesire::LookPoseParam m_blendInTime;
	ArkNpcLookDesire::LookPoseParam m_smoothTime;
	ArkNpcLookDesire::LookPoseParam m_blendOutTime;
	ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansPitch;
	ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansYaw;
	float m_polarOffsetX;
	float m_polarOffsetY;
	ArkDelegate<void __cdecl(enum EArkNpcLookDesireCallbackEvent)> m_callback;
	
	ArkNpcLookDesire(EArkNpcLookDesirePriority _priority, const char *_dbgSource);
	
#if 0
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcLookDesireCallbackEvent)> arg0);
	void ClearCallback();
#endif
};

