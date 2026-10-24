// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/ArkEffectParameters.h
#ifdef MOONCRASH
struct IParticleEmitter;
#endif
struct ArkEffectParameters // Id=801935C Size=40
{
	float m_effectScale;
	IEntity *m_pEntity;
	bool m_bIsPlaying;
	_smart_ptr<IParticleEmitter> m_pEffectEmitter;
	ArkAudioTrigger m_startSoundTrigger;
	ArkAudioTrigger m_stopSoundTrigger;
	
	~ArkEffectParameters();
	
#ifndef MOONCRASH
	static inline auto FBitNotArkEffectParameters = PreyFunction<void(ArkEffectParameters *const _this)>(0x13B7430);
#else
	static inline auto FBitNotArkEffectParameters = PreyFunction<void(ArkEffectParameters* const _this)>(0x14C3810);
#endif
};
