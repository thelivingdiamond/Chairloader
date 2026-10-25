// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
//#include "ArkNpcLookDesireManager.h"

class ArkNpcLookDesireManager;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireBase.h>
enum class EArkNpcLookDesirePriority;
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::TargetParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455F30);
#else
		static inline auto FTargetParam = PreyFunction<void(ArkNpcLookDesire::TargetParam* const _this, const ArkNpcDesireTarget& _target)>(0x14124F0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::TargetParam* const _this, ArkNpcLookDesire& _desire)>(0x156BE10);
#endif
	};

	class AimParam // Id=80140E4 Size=1
	{
	public:
		bool m_bEnable;
		
		AimParam(bool _bEnable);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::AimParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D20);
#else
		static inline auto FAimParam = PreyFunction<void(ArkNpcLookDesire::AimParam* const _this, bool _bEnable)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::AimParam* const _this, ArkNpcLookDesire& _desire)>(0x156BC00);
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::BlendTimeParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D60);
#else
		static inline auto FBlendTimeParam = PreyFunction<void(ArkNpcLookDesire::BlendTimeParam* const _this, const ArkNpcLookDesire::LookPoseParam& _blendInTime, const ArkNpcLookDesire::LookPoseParam& _blendOutTime)>(0x156BBB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::BlendTimeParam* const _this, ArkNpcLookDesire& _desire)>(0x156BC40);
#endif
	};

	class SmoothTimeParam // Id=80140E7 Size=16
	{
	public:
		ArkNpcLookDesire::LookPoseParam m_smoothTime;
		
		SmoothTimeParam(ArkNpcLookDesire::LookPoseParam const &_smoothTime);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::SmoothTimeParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455ED0);
#else
		static inline auto FSmoothTimeParam = PreyFunction<void(ArkNpcLookDesire::SmoothTimeParam* const _this, const ArkNpcLookDesire::LookPoseParam& _smoothTime)>(0x156BBF0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::SmoothTimeParam* const _this, ArkNpcLookDesire& _desire)>(0x156BDB0);
#endif
	};

	class MaxAngleParam // Id=80140E8 Size=32
	{
	public:
		ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansYaw;
		ArkNpcLookDesire::LookPoseParam m_maxAngleRadiansPitch;
		
		MaxAngleParam(ArkNpcLookDesire::LookPoseParam const &_maxYaw, ArkNpcLookDesire::LookPoseParam const &_maxPitch);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::MaxAngleParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455DF0);
#else
		static inline auto FMaxAngleParam = PreyFunction<void(ArkNpcLookDesire::MaxAngleParam* const _this, const ArkNpcLookDesire::LookPoseParam& _maxYaw, const ArkNpcLookDesire::LookPoseParam& _maxPitch)>(0x156BBB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::MaxAngleParam* const _this, ArkNpcLookDesire& _desire)>(0x156BCD0);
#endif
	};

	class AllowLowerBodyTurnParam // Id=80140E9 Size=1
	{
	public:
		const bool m_bAllow;
		
		AllowLowerBodyTurnParam(bool _bAllow);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::AllowLowerBodyTurnParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455D40);
#else
		static inline auto FAllowLowerBodyTurnParam = PreyFunction<void(ArkNpcLookDesire::AllowLowerBodyTurnParam* const _this, bool _bAllow)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::AllowLowerBodyTurnParam* const _this, ArkNpcLookDesire& _desire)>(0x156BC20);
#endif
	};

	class MinSpeedParam // Id=80140EA Size=4
	{
	public:
		EArkNpcSpeedType m_minSpeed;
		
		MinSpeedParam(EArkNpcSpeedType _minSpeed);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::MinSpeedParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455E80);
#else
		static inline auto FMinSpeedParam = PreyFunction<void(ArkNpcLookDesire::MinSpeedParam* const _this, EArkNpcSpeedType _minSpeed)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::MinSpeedParam* const _this, ArkNpcLookDesire& _desire)>(0x156BD60);
#endif
	};

	class StyleParam // Id=80140EB Size=4
	{
	public:
		ELookStyle m_style;
		
		StyleParam(ELookStyle _style);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::StyleParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455F20);
#else
		static inline auto FStyleParam = PreyFunction<void(ArkNpcLookDesire::StyleParam* const _this, ELookStyle _style)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::StyleParam* const _this, ArkNpcLookDesire& _desire)>(0x156BE00);
#endif
	};

	class PolarOffsetParam // Id=80140EC Size=8
	{
	public:
		const float m_x;
		const float m_y;
		
		PolarOffsetParam(float _x, float _y);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::PolarOffsetParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455E90);
#else
		static inline auto FPolarOffsetParam = PreyFunction<void(ArkNpcLookDesire::PolarOffsetParam* const _this, float _x, float _y)>(0x156BBE0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::PolarOffsetParam* const _this, ArkNpcLookDesire& _desire)>(0x156BD70);
#endif
	};

	class BodyOrientationParam // Id=80140ED Size=4
	{
	public:
		EBodyOrientationMode m_orientMode;
		
		BodyOrientationParam(EBodyOrientationMode _orientMode);
		bool Set(ArkNpcLookDesire &_desire) const { return FSet(this,_desire); }
		
#ifndef MOONCRASH
		static inline auto FSet = PreyFunction<bool(ArkNpcLookDesire::BodyOrientationParam const *const _this, ArkNpcLookDesire &_desire)>(0x1455DE0);
#else
		static inline auto FBodyOrientationParam = PreyFunction<void(ArkNpcLookDesire::BodyOrientationParam* const _this, EBodyOrientationMode _orientMode)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcLookDesire::BodyOrientationParam* const _this, ArkNpcLookDesire& _desire)>(0x156BCC0);
#endif
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
#ifdef MOONCRASH
	static inline auto FArkNpcLookDesireOv1 = PreyFunction<void(ArkNpcLookDesire* const _this, EArkNpcLookDesirePriority _priority, const char* _dbgSource)>(0x156BA70);
#endif
};
