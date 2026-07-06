// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

// ArkPlayerMovementAction
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementAction.h
class ArkPlayerMovementAction : public TAction<SAnimationContext>
{ // Size=144 (0x90)
public:
	enum EArkPlayerMovementState
	{
	};

	std::array<int, 3> m_fragmentIds;

	ArkPlayerMovementAction(const std::array<int, 3>& _fragmentIds);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FArkPlayerMovementAction = PreyFunction<void(ArkPlayerMovementAction* const _this, const std::array<int, 3>& _fragmentIds)>(0x16941E0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMovementAction* const _this, float _timePassed)>(0x16942A0);
};
#endif // !MOONCRASH
