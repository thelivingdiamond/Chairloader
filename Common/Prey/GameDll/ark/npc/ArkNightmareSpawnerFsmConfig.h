#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IViewSystem.h>

struct IEntityArchetype;

// ArkNightmareSpawnerFsmConfig
// Header:  _unknown/ArkNightmareSpawnerFsmConfig.h
struct ArkNightmareSpawnerFsmConfig
{ // Size=104 (0x68)
	IEntityArchetype* m_pNightmareArchetype;
	const char* m_pSpawnSfx;
	const char* m_pRoarSfx;
	const char* m_pCameraShakeSfx;
	IView::SShakeParams m_cameraShakeParams;
	float m_spawnDelay;
	float m_spawnEffectsDelay;

#if 0
	ArkNightmareSpawnerFsmConfig();
	~ArkNightmareSpawnerFsmConfig();
#endif
};

#endif // MOONCRASH
