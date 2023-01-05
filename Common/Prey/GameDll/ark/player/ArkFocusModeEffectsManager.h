// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/arkeffectutils.h>

// ArkFocusModeEffectsManager
// Header:  Prey/GameDll/ark/player/ArkFocusModeEffectsManager.h
class ArkFocusModeEffectsManager
{ // Size=672 (0x2A0)
public:
	enum class Transition
	{
		FocusMode = 0,
		PsiTargeting = 1,
		PsiTargetingToFocusMode = 2,
		FocusModeToPsiTargeting = 3,
		ExitFromFocusMode = 4,
		ExitFromPsiTargeting = 5,
		_Count = 6,
	};

	ArkLooseEffect m_effects[6];

	ArkFocusModeEffectsManager();
	void Reset() { FReset(this); }
	void SpawnParticleEffect(const ArkFocusModeEffectsManager::Transition _effect) { FSpawnParticleEffect(this, _effect); }

#if 0
	void KillAllEffects();
#endif

	static inline auto FArkFocusModeEffectsManagerOv2 = PreyFunction<void(ArkFocusModeEffectsManager* const _this)>(0x1223270);
	static inline auto FReset = PreyFunction<void(ArkFocusModeEffectsManager* const _this)>(0x12232E0);
	static inline auto FSpawnParticleEffect = PreyFunction<void(ArkFocusModeEffectsManager* const _this, const ArkFocusModeEffectsManager::Transition _effect)>(0x1223570);
};

