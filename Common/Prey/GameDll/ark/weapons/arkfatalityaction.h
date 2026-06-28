// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/npc/anim/arknpcanimcoopactions.h>

class ArkNpc;
class IAction;

// Header: Exact
// Prey/GameDll/ark/weapons/arkfatalityaction.h
template <typename T>
class ArkFatalityAction : public CArkNpcAnimCoopAction // Id=801BC24 Size=208
{
public:
#if 0
	void ArkFatalityAction(ArkNpc &_npc, const bool _bRL);
	virtual void Exit();
	virtual EPriorityComparison ComparePriority(IAction const &_actionCurrent) const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/npc/anim/arknpcanimcoopactions.h>

class ArkNpc;
enum class EPriorityComparison;
class IAction;

// ArkFatalityAction<ArkWeaponDoubleWrench>
// Header:  Prey/GameDll/ark/weapons/arkfatalityaction.h
class ArkFatalityAction<ArkWeaponDoubleWrench> : public CArkNpcAnimCoopAction
{ // Size=208 (0xD0)
public:
	ArkFatalityAction<ArkWeaponDoubleWrench>(ArkNpc& _npc, const bool _bRL);
	virtual void Exit();
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;

	static inline auto FArkFatalityActionLessArkWeaponDoubleWrenchGreater = PreyFunction<void(ArkFatalityAction<ArkWeaponDoubleWrench>* const _this, ArkNpc& _npc, const bool _bRL)>(0x148EA30);
	static inline auto FExit = PreyFunction<void(ArkFatalityAction<ArkWeaponDoubleWrench>* const _this)>(0x148EBF0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkFatalityAction<ArkWeaponDoubleWrench>* const _this, const IAction& _actionCurrent)>(0x4FD7F0);
};

// ArkFatalityAction<ArkWeaponWrench>
// Header:  Prey/GameDll/ark/weapons/arkfatalityaction.h
class ArkFatalityAction<ArkWeaponWrench> : public CArkNpcAnimCoopAction
{ // Size=208 (0xD0)
public:
	ArkFatalityAction<ArkWeaponWrench>(ArkNpc& _npc, const bool _bRL);
	virtual void Exit();
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;

	static inline auto FArkFatalityActionLessArkWeaponWrenchGreater = PreyFunction<void(ArkFatalityAction<ArkWeaponWrench>* const _this, ArkNpc& _npc, const bool _bRL)>(0x17A6950);
	static inline auto FExit = PreyFunction<void(ArkFatalityAction<ArkWeaponWrench>* const _this)>(0x17A7040);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkFatalityAction<ArkWeaponWrench>* const _this, const IAction& _actionCurrent)>(0x4FD7F0);
};
#endif // !MOONCRASH
