// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/ISystem.h>

// Header: FromCpp
// Prey/GameDll/ark/arktargetlerper.h
#ifdef MOONCRASH
enum ESystemEvent;
#endif
class CArkTargetLerper : public ISystemEventListener // Id=80175E9 Size=120
{
public:
	using LerperPtr = std::unique_ptr<CArkTargetLerper>;
	using TimerExpiredCallback = std::function<void __cdecl(void)>;
	using LeperPtrContainer = std::vector<std::unique_ptr<CArkTargetLerper>>;
	
	float m_elapsedSec;
	const float m_durationSec;
	const bool m_bScale;
	const unsigned m_sourceEntityId;
	const unsigned m_targetEntityId;
	Vec3 m_sourceEntityStartPos;
	Vec3 m_targetEntityPosOffset;
	std::function<void __cdecl(void)> m_timerExpiredCallback;
#ifndef MOONCRASH
	static std::vector<std::unique_ptr<CArkTargetLerper>> s_targetLerpers;
#else
	static inline auto s_targetLerpers = PreyGlobal<std::vector<std::unique_ptr<CArkTargetLerper>>>(0x2D6CAF8);
#endif

    CArkTargetLerper();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	void Update(const float _dt) { FUpdateOv1(this,_dt); }
	static void Update(void *_pUserData, unsigned _timerId) { FUpdateOv0(_pUserData,_timerId); }
	virtual ~CArkTargetLerper();
	static void Clear(const unsigned &_sourceEntityId) { FClearOv1(_sourceEntityId); }
	static bool IsEntityInTransit(const unsigned &_entityId) { return FIsEntityInTransit(_entityId); }
	static void LerpToTarget(const float _durationSec, const bool _bDisableCollision, const bool _bScale, const unsigned &_sourceEntityId, const unsigned &_targetEntityId, Vec3 const &_targetEntityOffset, std::function<void __cdecl(void)> _expiredCallback) { FLerpToTarget(_durationSec,_bDisableCollision,_bScale,_sourceEntityId,_targetEntityId,_targetEntityOffset,_expiredCallback); }
	
#if 0
	void InvokeCallback() const;
	bool IsExpired() const;
	const unsigned &GetSourceEntityId() const;
	const unsigned &GetTargetEntityId() const;
	static void ClearAll();
	static void Clear(CArkTargetLerper const *const arg0);
	static void SetUpdateInterval(const float arg0);
#endif
	
#ifndef MOONCRASH
	static inline auto FOnSystemEvent = PreyFunction<void(CArkTargetLerper *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1483B80);
	static inline auto FUpdateOv1 = PreyFunction<void(CArkTargetLerper *const _this, const float _dt)>(0x1483C50);
	static inline auto FUpdateOv0 = PreyFunction<void(void *_pUserData, unsigned _timerId)>(0x14840F0);
	static inline auto FClearOv1 = PreyFunction<void(const unsigned &_sourceEntityId)>(0x1483850);
	static inline auto FIsEntityInTransit = PreyFunction<bool(const unsigned &_entityId)>(0x1483910);
	static inline auto FLerpToTarget = PreyFunction<void(const float _durationSec, const bool _bDisableCollision, const bool _bScale, const unsigned &_sourceEntityId, const unsigned &_targetEntityId, Vec3 const &_targetEntityOffset, std::function<void __cdecl(void)> _expiredCallback)>(0x1483940);
#else
	static inline auto FOnSystemEvent = PreyFunction<void(CArkTargetLerper* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x159B3F0);
	static inline auto FUpdateOv1 = PreyFunction<void(CArkTargetLerper* const _this, const float _dt)>(0x159B4C0);
	static inline auto FUpdateOv0 = PreyFunction<void(void* _pUserData, unsigned _timerId)>(0x159B960);
	static inline auto FClearOv1 = PreyFunction<void(const unsigned& _sourceEntityId)>(0x159B0C0);
	static inline auto FIsEntityInTransit = PreyFunction<bool(const unsigned& _entityId)>(0x159B180);
	static inline auto FLerpToTarget = PreyFunction<void(const float _durationSec, const bool _bDisableCollision, const bool _bScale, const unsigned& _sourceEntityId, const unsigned& _targetEntityId, const Vec3& _targetEntityOffset, std::function<void __cdecl(void)> _expiredCallback)>(0x159B1B0);
#endif
};
