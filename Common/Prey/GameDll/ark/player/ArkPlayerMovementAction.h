// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>

// ArkPlayerMovementAction
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementAction.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
class ArkPlayerMovementAction : public TAction<SAnimationContext>
{ // Size=144 (0x90)
public:
	enum EArkPlayerMovementState
	{
	};

	std::array<int,3> m_fragmentIds;

	ArkPlayerMovementAction(const std::array<int,3>& _fragmentIds);
	virtual IAction::EStatus Update(float _timePassed);

#ifndef MOONCRASH
	static inline auto FArkPlayerMovementAction = PreyFunction<void(ArkPlayerMovementAction* const _this, const std::array<int,3>& _fragmentIds)>(0x156DE00);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMovementAction* const _this, float _timePassed)>(0x156DEC0);
#else
	static inline auto FArkPlayerMovementAction = PreyFunction<void(ArkPlayerMovementAction* const _this, const std::array<int, 3>& _fragmentIds)>(0x16941E0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMovementAction* const _this, float _timePassed)>(0x16942A0);
#endif
};
