// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerMovementAction.h
class ArkPlayerMovementAction : public TAction<SAnimationContext> // Id=801C797 Size=144
{
public:
	enum EArkPlayerMovementState
	{
	};

	std::array<int,3> m_fragmentIds;
	
	ArkPlayerMovementAction(std::array<int,3> const &_fragmentIds);
	virtual IAction::EStatus Update(float _timePassed);
	virtual ~ArkPlayerMovementAction();
	
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMovementAction *const _this, float _timePassed)>(0x156DEC0);
};

