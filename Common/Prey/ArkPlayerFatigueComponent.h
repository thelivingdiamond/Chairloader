#pragma once
#include "ArkStats.h"
#include "Prey/CryCore/StdAfx.h"
struct ArkChargeAmount
{
	float m_amount;
	float m_maxAmount;
};

class ArkPlayerFatigueComponent : IArkStatsListener
{
public:
	virtual void OnStatChange(IArkStatsListener* _this, const unsigned int, const CCryName*, const float, const float) {};
	virtual virtual ~ArkPlayerFatigueComponent() = 0;


	bool m_bExhausted;
	bool m_bPlayingAudio;
	bool m_bShowingUI;
	int m_bInfiniteStamina;
	ArkChargeAmount m_fatigue;
	float m_staminaPercentStartAudio;
	float m_staminaPercentStopAudio;
	float m_showUIPercent;
	ArkSimpleTimer m_drainDelay;
	ArkAudioRtpc m_rtpcFatigue;
	ArkAudioTrigger m_triggerStart;
	ArkAudioTrigger m_triggerStop;
};