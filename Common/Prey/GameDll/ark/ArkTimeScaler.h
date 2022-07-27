// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkTimeScaleManager.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkTimeScaler.h
class ArkTimeScaler // Id=801725E Size=28
{
public:
	float m_initialTimeScale;
	float m_targetTimeScale;
	float m_currentTimeScale;
	float m_elapsedSec;
	float m_durationSec;
	int m_timeScaleHandle;
	ArkTimeScaleManager::EArkTimerFlag m_timer;
	
	ArkTimeScaler(ArkTimeScaleManager::EArkTimerFlag _timer);
	~ArkTimeScaler() { FBitNotArkTimeScaler(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void SetTargetTimeScale(const float _targetTimeScale, const float _durationSec) { FSetTargetTimeScale(this,_targetTimeScale,_durationSec); }
	
#if 0
	float GetTimeRemainingSec() const;
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FBitNotArkTimeScaler = PreyFunction<void(ArkTimeScaler *const _this)>(0x11B2030);
	static inline auto FUpdate = PreyFunction<void(ArkTimeScaler *const _this, const float _frameTime)>(0x11B20C0);
	static inline auto FSetTargetTimeScale = PreyFunction<void(ArkTimeScaler *const _this, const float _targetTimeScale, const float _durationSec)>(0x11B2050);
};

