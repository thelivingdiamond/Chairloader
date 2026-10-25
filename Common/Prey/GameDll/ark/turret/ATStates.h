// Header file automatically created from a PDB.

#pragma once

class ArkTurretFsm;

#ifndef MOONCRASH
enum class EArkTurretStateId
{
	any = -1,
	null = 0,
	undeployed = 1,
	fallenSpaz = 2,
	attacking = 3,
	searching = 4,
	flowgraphControlled = 5,
	playerControlled = 6,
	playerCarried = 7,
	disabled = 8,
	count_ = 9,
};
#else
enum class EArkTurretStateId : int
{   // Mooncrash: no fallenSpaz / flowgraphControlled
	any = -1,
	null = 0,
	undeployed = 1,
	attacking = 2,
	searching = 3,
	playerControlled = 4,
	playerCarried = 5,
	disabled = 6,
	count_ = 7,
};
#endif

namespace ATStates
{

// Header: Override
// Prey/GameDll/ark/turret/ATStates.h
class BaseState // Id=80152AC Size=1
{
public:
#if 0
	void Enter(ArkTurretFsm &arg0);
	void Exit(ArkTurretFsm &arg0);
	void Update(ArkTurretFsm &arg0, const float arg1);
	void AnimEvent(ArkTurretFsm &arg0, const char *const arg1);
	void LoadData(ArkTurretFsm &arg0);
	const char *GetStateName() const;
#endif
};

} // namespace ATStates
