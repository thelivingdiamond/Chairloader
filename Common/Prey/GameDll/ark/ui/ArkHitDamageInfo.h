// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

struct HitInfo;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkHitDamageInfo.h
class ArkHitDamageInfo // Id=8017670 Size=48
{
public:
	Vec3 m_pos;
	Vec2 m_offset;
	Vec2 m_vel;
	ArkTimeRemaining m_timer;
	unsigned m_groupId;
	unsigned m_targetId;
	float m_damage;
	bool m_bCritical;
	
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
	
	static inline auto FInit = PreyFunction<void(ArkHitDamageInfo *const _this, HitInfo const &_hitInfo, float _time)>(0x1349950);
	static inline auto FUpdate = PreyFunction<bool(ArkHitDamageInfo *const _this, const float _frameTime)>(0x1349A40);
};

