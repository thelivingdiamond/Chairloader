// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

struct HitInfo;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkHitDamageInfo.h
class ArkHitDamageInfo // Id=8017670 Size=48
{
public:
#ifdef MOONCRASH
	enum class EArkHitFeedbackType
	{
		normal = 0,
		resistant = 1,
		critical = 2,
		armored = 3,
		shielded = 4,
	};
#endif
	Vec3 m_pos;
	Vec2 m_offset;
	Vec2 m_vel;
	ArkTimeRemaining m_timer;
	unsigned m_groupId;
	unsigned m_targetId;
	float m_damage;
#ifdef MOONCRASH
	ArkHitDamageInfo::EArkHitFeedbackType m_feedbackType;
#endif
#ifndef MOONCRASH
	bool m_bCritical;
#endif
	
	ArkHitDamageInfo();
	void Init(HitInfo const &_hitInfo, float _time) { FInit(this,_hitInfo,_time); }
	bool Update(const float _frameTime) { return FUpdate(this,_frameTime); }
	
#if 0
	bool IsUsed() const;
	float GetTimeRemaining() const;
	Vec3 const &GetPos() const;
	Vec2 const &GetOffset() const;
	float GetDamage() const;
	void AddDamage(float arg0);
	bool IsCritical() const;
	void SetCritical(const bool arg0);
	unsigned GetGroup() const;
	unsigned GetTarget() const;
#endif
	
#ifdef MOONCRASH
	static ArkHitDamageInfo::EArkHitFeedbackType GetHitFeedbackTypeForHitInfo(const HitInfo& _hitInfo) { return FGetHitFeedbackTypeForHitInfo(_hitInfo); }
#endif
#ifndef MOONCRASH
	static inline auto FInit = PreyFunction<void(ArkHitDamageInfo *const _this, HitInfo const &_hitInfo, float _time)>(0x1349950);
	static inline auto FUpdate = PreyFunction<bool(ArkHitDamageInfo *const _this, const float _frameTime)>(0x1349A40);
#else
	static inline auto FArkHitDamageInfoOv2 = PreyFunction<void(ArkHitDamageInfo* const _this)>(0x1424BF0);
	static inline auto FInit = PreyFunction<void(ArkHitDamageInfo* const _this, const HitInfo& _hitInfo, float _time)>(0x1424C70);
	static inline auto FUpdate = PreyFunction<bool(ArkHitDamageInfo* const _this, const float _frameTime)>(0x1424DB0);
	static inline auto FGetHitFeedbackTypeForHitInfo = PreyFunction<ArkHitDamageInfo::EArkHitFeedbackType(const HitInfo& _hitInfo)>(0x1424C20);
#endif
};
