#pragma once
#include "ChairLoader/PreyFunction.h"
class ArkTimeRemaining
{
public:
	static inline auto HasElapsed = PreyFunction<bool(ArkTimeRemaining*)>(0x12585F0);
	static inline auto Invalidate = PreyFunction<void(ArkTimeRemaining*)>(0x1258600);
	static inline auto IsValid = PreyFunction<bool(ArkTimeRemaining*)>(0x1258620);
	static inline auto Update = PreyFunction<bool(ArkTimeRemaining*, float)>(0x12589B0);
	static inline auto SetElapsed = PreyFunction<void(ArkTimeRemaining*)>(0x1B216D0);
	float m_timeRemaining;
};
class ArkSimpleTimer : ArkTimeRemaining
{
public:
	static inline auto SetDuration = PreyFunction<void(float duration, bool bResetTimer)>(0x1258850);
	float m_duration;
};
class ArkRandomizedTimer : ArkSimpleTimer
{
	float m_variation;
};
class ArkRandomizedAutoResetTimer : ArkRandomizedTimer
{
};
class ArkAutoResetTimer : ArkSimpleTimer
{
};