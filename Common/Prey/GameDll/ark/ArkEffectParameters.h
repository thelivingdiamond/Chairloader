// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/ArkEffectParameters.h
struct ArkEffectParameters // Id=801935C Size=40
{
	float m_effectScale;
	IEntity *m_pEntity;
	bool m_bIsPlaying;
	_smart_ptr<IParticleEmitter> m_pEffectEmitter;
	ArkAudioTrigger m_startSoundTrigger;
	ArkAudioTrigger m_stopSoundTrigger;
	
	~ArkEffectParameters();
	
	static inline auto FBitNotArkEffectParameters = PreyFunction<void(ArkEffectParameters *const _this)>(0x13B7430);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>

struct IEntity;
struct IParticleEmitter;

// ArkEffectParameters
// Header:  Prey/GameDll/ark/ArkEffectParameters.h
struct ArkEffectParameters
{ // Size=40 (0x28)
	float m_effectScale;
	IEntity* m_pEntity;
	bool m_bIsPlaying;
	_smart_ptr<IParticleEmitter> m_pEffectEmitter;
	ArkAudioTrigger m_startSoundTrigger;
	ArkAudioTrigger m_stopSoundTrigger;

	~ArkEffectParameters();

#if 0
	ArkEffectParameters();
#endif

	static inline auto FBitNotArkEffectParameters = PreyFunction<void(ArkEffectParameters* const _this)>(0x14C3810);
};
#endif // !MOONCRASH
