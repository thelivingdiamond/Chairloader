// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerAction : public TAction<SAnimationContext> // Id=801C798 Size=128
{
public:
	ArkPlayerAction(int _fragmentId);
	virtual IAction::EStatus Update(float _timePassed);
	virtual ~ArkPlayerAction();
	
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerAction *const _this, float _timePassed)>(0x1558FC0);
};

