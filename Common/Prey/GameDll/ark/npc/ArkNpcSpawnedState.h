// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alive // Id=80142E0 Size=1
{
	bool m_bAlwaysUpdate;
};

// Header: Override
// Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alert : public ArkNpcSpawnedState_Alive // Id=80142DF Size=1
{
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkNpcSpawnedState_Alive
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alive
{ // Size=1 (0x1)
	bool m_bAlwaysUpdate;

#if 0
	ArkNpcSpawnedState_Alive(const bool _arg0_);
#endif
};

// ArkNpcSpawnedState_Alert
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Alert : public ArkNpcSpawnedState_Alive
{ // Size=1 (0x1)
#if 0
	ArkNpcSpawnedState_Alert(const bool _arg0_);
#endif
};

// ArkNpcSpawnedState_Broken
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Broken : public ArkNpcSpawnedState_Alive
{ // Size=16 (0x10)
	const char* m_pPoseAnimName;

#if 0
	ArkNpcSpawnedState_Broken(const bool _arg0_, const char* const _arg1_);
#endif
};

// ArkNpcSpawnedState_Dormant
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Dormant : public ArkNpcSpawnedState_Alive
{ // Size=32 (0x20)
	Vec3 m_position;
	Quat m_rotation;

#if 0
	ArkNpcSpawnedState_Dormant(const bool _arg0_, const Vec3& _arg1_, const Quat& _arg2_);
#endif
};

// ArkNpcSpawnedState_Dead
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnedState.h
struct ArkNpcSpawnedState_Dead
{ // Size=1 (0x1)
#if 0
	ArkNpcSpawnedState_Dead();
#endif
};
#endif // !MOONCRASH
