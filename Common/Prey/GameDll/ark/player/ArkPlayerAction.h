// Header file automatically created from a PDB.
#pragma once

// ArkPlayerAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerAction(int _fragmentId);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FArkPlayerAction = PreyFunction<void(ArkPlayerAction* const _this, int _fragmentId)>(0x1558F20);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerAction* const _this, float _timePassed)>(0x1558FC0);
};

