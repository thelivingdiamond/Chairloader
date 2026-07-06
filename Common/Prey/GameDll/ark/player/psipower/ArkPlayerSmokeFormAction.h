// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EPriorityComparison;
class IAction;

// ArkPlayerSmokeFormAction
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerSmokeFormAction.h
class ArkPlayerSmokeFormAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerSmokeFormAction();
	virtual ~ArkPlayerSmokeFormAction();
	virtual void OnInitialise();
	virtual EPriorityComparison ComparePriority(const IAction& _action) const;

	static inline auto FArkPlayerSmokeFormAction = PreyFunction<void(ArkPlayerSmokeFormAction* const _this)>(0x146C000);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerSmokeFormAction* const _this)>(0x146C0A0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkPlayerSmokeFormAction* const _this, const IAction& _action)>(0x1A42CE0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

enum class EPriorityComparison;
class IAction;

// ArkPlayerSmokeFormAction
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerSmokeFormAction.h
class ArkPlayerSmokeFormAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerSmokeFormAction();
	virtual ~ArkPlayerSmokeFormAction();
	virtual void OnInitialise();
	virtual EPriorityComparison ComparePriority(const IAction& _action) const;

	static inline auto FArkPlayerSmokeFormAction = PreyFunction<void(ArkPlayerSmokeFormAction* const _this)>(0x15838F0);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerSmokeFormAction* const _this)>(0x15839E0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkPlayerSmokeFormAction* const _this, const IAction& _action)>(0x4FD7F0);
};
#endif // !MOONCRASH
