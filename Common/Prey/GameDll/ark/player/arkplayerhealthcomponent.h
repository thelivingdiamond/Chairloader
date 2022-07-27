// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>

struct IParticleEffect;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayerhealthcomponent.h
class ArkPlayerHealthFeedback // Id=801707B Size=72
{
public:
	float m_lowHealth;
	float m_nearDeath;
	float m_prevHealth;
	int m_vfxSlot;
	bool m_bTookDamageThisTick;
	IParticleEffect *m_pLowHealthParticle;
	IParticleEffect *m_pNearDeathParticle;
	uint64_t m_lowHealthPostEffect;
	uint64_t m_nearDeathPostEffect;
	ArkAudioTrigger m_triggerNearDeathStart;
	ArkAudioTrigger m_triggerNearDeathStop;
	ArkAudioTrigger m_triggerNearDeathStinger;
	ArkAudioRtpc m_rtpcNearDeathIntensity;
	
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void UpdateFeedback(float _currentHealth, float _frameTime) { FUpdateFeedback(this,_currentHealth,_frameTime); }
	
#if 0
	float GetNearDeathThreshold() const;
	void SetTookDamage();
#endif
	
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerHealthFeedback *const _this, XmlNodeRef const &_node)>(0x155EA00);
	static inline auto FUpdateFeedback = PreyFunction<void(ArkPlayerHealthFeedback *const _this, float _currentHealth, float _frameTime)>(0x155F7E0);
};

