// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alive // Id=80142E0 Size=1
{
    bool m_bAlwaysUpdate;

    ArkNpcSpawnedState_Alive(bool alwaysUpdate)
    {
        m_bAlwaysUpdate = alwaysUpdate;
	}
};

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alert : public ArkNpcSpawnedState_Alive // Id=80142DF Size=1
{
    ArkNpcSpawnedState_Alert(bool alwaysUpdate) : ArkNpcSpawnedState_Alive(alwaysUpdate) {}
    
#if 0
	void __dflt_ctor_closure();
#endif
};

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Broken : public ArkNpcSpawnedState_Alive // Id=80142E7 Size=16
{
	const char *m_pPoseAnimName;
};

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Dormant : public ArkNpcSpawnedState_Alive // Id=80142ED Size=32
{
	Vec3 m_position;
	Quat m_rotation;
};

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Dead // Id=80142EA Size=1
{
};

