// Header file automatically created from a PDB.
#pragma once

// ArkPlayerMovementAction
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementAction.h
class ArkPlayerMovementAction : public TAction<SAnimationContext>
{ // Size=144 (0x90)
public:
	enum EArkPlayerMovementState
	{
	};

	std::array<int,3> m_fragmentIds;

	ArkPlayerMovementAction(const std::array<int,3>& _fragmentIds);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FArkPlayerMovementAction = PreyFunction<void(ArkPlayerMovementAction* const _this, const std::array<int,3>& _fragmentIds)>(0x156DE00);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMovementAction* const _this, float _timePassed)>(0x156DEC0);
};

