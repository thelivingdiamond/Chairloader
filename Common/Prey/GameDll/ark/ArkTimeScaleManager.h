// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/ITimer.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkTimeScaleManager.h
class ArkTimeScaleManager // Id=8016204 Size=104
{
public:
	enum class EArkTimerFlag
	{
		Real = 1,
		Game = 2,
		UI = 4,
		Player = 8,
	};

	class TimeScaleInfo // Id=8016205 Size=8
	{
	public:
		int m_handle;
		float m_scale;
		
#if 0
		bool operator==(const int arg0) const;
#endif
	};

	std::array<std::vector<ArkTimeScaleManager::TimeScaleInfo>,4> m_overrides;
	int m_handleGenerator;
	
	ArkTimeScaleManager();
	int OverrideTimeScale(unsigned _timers, float _scale) { return FOverrideTimeScale(this,_timers,_scale); }
	void ClearTimeScaleOverride(const int _handle) { FClearTimeScaleOverride(this,_handle); }
	void UpdateTimeScaleOverride(const int _handle, const float _scale) { FUpdateTimeScaleOverride(this,_handle,_scale); }
	void Reset() { FReset(this); }
	void UpdateScale(ITimer::ETimer _timer) const { FUpdateScale(this,_timer); }
	
	static inline auto FOverrideTimeScale = PreyFunction<int(ArkTimeScaleManager *const _this, unsigned _timers, float _scale)>(0x1258CC0);
	static inline auto FClearTimeScaleOverride = PreyFunction<void(ArkTimeScaleManager *const _this, const int _handle)>(0x1258C40);
	static inline auto FUpdateTimeScaleOverride = PreyFunction<void(ArkTimeScaleManager *const _this, const int _handle, const float _scale)>(0x1258FB0);
	static inline auto FReset = PreyFunction<void(ArkTimeScaleManager *const _this)>(0x1258E50);
	static inline auto FUpdateScale = PreyFunction<void(ArkTimeScaleManager const *const _this, ITimer::ETimer _timer)>(0x1258EE0);
};

