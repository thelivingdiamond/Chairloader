// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

class IAction;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerSmokeFormAction.h
class ArkPlayerSmokeFormAction : public TAction<SAnimationContext> // Id=801C169 Size=128
{
public:
	ArkPlayerSmokeFormAction();
	virtual ~ArkPlayerSmokeFormAction();
	virtual void OnInitialise();
	virtual EPriorityComparison ComparePriority(IAction const &_action) const;
	
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerSmokeFormAction *const _this)>(0x146C0A0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(ArkPlayerSmokeFormAction const *const _this, IAction const &_action)>(0x1A42CE0);
};

