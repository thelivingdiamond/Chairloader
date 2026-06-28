// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
//#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>

class IAction;
class IArkPlayer;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAction : public TAction<SAnimationContext> // Id=801A7D1 Size=136
{
public:
	unsigned m_weaponId;
	
	ArkWeaponAction(const unsigned _weaponId, const int _fragmentId, IArkPlayer::EArkPlayerAnimationPriority _priority);
	virtual EPriorityComparison ComparePriority(IAction const &_actionCurrent) const;
	virtual ~ArkWeaponAction();
	
#if 0
	unsigned GetWeaponId() const;
#endif
	
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(ArkWeaponAction const *const _this, IAction const &_actionCurrent)>(0x1A42CE0);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponThrowIdleAction : public ArkWeaponAction // Id=801A7D2 Size=136
{
public:
	ArkWeaponThrowIdleAction(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(IAction const &_actionCurrent) const;
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponThrowIdleAction();
	
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(ArkWeaponThrowIdleAction const *const _this, IAction const &_actionCurrent)>(0x158AEF0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponThrowIdleAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponThrowIdleAction *const _this)>(0x1670190);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadAction : public ArkWeaponAction // Id=801A7D4 Size=136
{
public:
	ArkWeaponReloadAction(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(IAction const &_actionCurrent) const;
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponReloadAction();
	
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(ArkWeaponReloadAction const *const _this, IAction const &_actionCurrent)>(0x158AEF0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadAction *const _this)>(0x1670090);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadActionOnEvent : public ArkWeaponAction // Id=801A7D5 Size=136
{
public:
	ArkWeaponReloadActionOnEvent(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(IAction const &_actionCurrent) const;
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual ~ArkWeaponReloadActionOnEvent();
	
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(ArkWeaponReloadActionOnEvent const *const _this, IAction const &_actionCurrent)>(0x158AEF0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadActionOnEvent *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadActionOnEvent *const _this)>(0x16700D0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponReloadActionOnEvent *const _this, const unsigned _eventCRC)>(0x1670590);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackAction : public ArkWeaponAction // Id=801BC26 Size=136
{
public:
	ArkWeaponAttackAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual ~ArkWeaponAttackAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackAction *const _this)>(0x166FD90);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackAction *const _this)>(0x166FEA0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponAttackAction *const _this, const unsigned _eventCRC)>(0x16702A0);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponDeployAction : public ArkWeaponAttackAction // Id=801CD94 Size=136
{
public:
	ArkWeaponDeployAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponDeployAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponDeployAction *const _this)>(0x166FD90);
	static inline auto FExit = PreyFunction<void(ArkWeaponDeployAction *const _this)>(0x1670030);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackOutAction : public ArkWeaponAction // Id=801BC31 Size=136
{
public:
	ArkWeaponAttackOutAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponAttackOutAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackOutAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackOutAction *const _this)>(0x166FEA0);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackOutAndUnselectAction : public ArkWeaponAttackOutAction // Id=801CD63 Size=144
{
public:
	int m_unselectFragmentId;
	
	ArkWeaponAttackOutAndUnselectAction(const unsigned _weaponId, const int _attackOutFragmentId, const int _unselectFragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponAttackOutAndUnselectAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackOutAndUnselectAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackOutAndUnselectAction *const _this)>(0x166FF70);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackInAction : public ArkWeaponAction // Id=801BC32 Size=136
{
public:
	ArkWeaponAttackInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponAttackInAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackInAction *const _this)>(0x166FDF0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackInAction *const _this)>(0x166FF30);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponSelectAction : public ArkWeaponAction // Id=801CD62 Size=144
{
public:
	const bool m_bBlockAttack;
	
	ArkWeaponSelectAction(const unsigned _weaponId, const int _fragmentId, const bool _bBlockAttack);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponSelectAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponSelectAction *const _this)>(0x166FE50);
	static inline auto FExit = PreyFunction<void(ArkWeaponSelectAction *const _this)>(0x1670150);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponUnselectAction : public ArkWeaponAction // Id=801CD64 Size=136
{
public:
	ArkWeaponUnselectAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponUnselectAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponUnselectAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponUnselectAction *const _this)>(0x1670220);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadInAction : public ArkWeaponAction // Id=801CD65 Size=136
{
public:
	ArkWeaponReloadInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponReloadInAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadInAction *const _this)>(0x166FE20);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadInAction *const _this)>(0x16700D0);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadOutAction : public ArkWeaponAction // Id=801CD66 Size=136
{
public:
	ArkWeaponReloadOutAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual ~ArkWeaponReloadOutAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadOutAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadOutAction *const _this)>(0x1670110);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponThrowInAction : public ArkWeaponAction // Id=801CD92 Size=136
{
public:
	ArkWeaponThrowInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual ~ArkWeaponThrowInAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponThrowInAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponThrowInAction *const _this)>(0x16701E0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponThrowInAction *const _this, const unsigned _eventCRC)>(0x16706B0);
};

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackContinueMalfunctionAction : public ArkWeaponAction // Id=801CD93 Size=136
{
public:
	ArkWeaponAttackContinueMalfunctionAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual ~ArkWeaponAttackContinueMalfunctionAction();
	
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction *const _this)>(0x2BDD60);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction *const _this)>(0x166FEE0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction *const _this, const unsigned _eventCRC)>(0x16704F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

class IAction;

// ArkWeaponAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAction : public TAction<SAnimationContext>
{ // Size=136 (0x88)
public:
	unsigned m_weaponId;
	EPriorityComparison m_priorityComp;

	ArkWeaponAction(unsigned _weaponId, int _fragmentId, int _priority, const EPriorityComparison _priorityComp, unsigned _flags);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void OnActionEvent(const unsigned _eventCRC);

#if 0
	unsigned GetWeaponId() const;
#endif

	static inline auto FArkWeaponAction = PreyFunction<void(ArkWeaponAction* const _this, unsigned _weaponId, int _fragmentId, int _priority, const EPriorityComparison _priorityComp, unsigned _flags)>(0x17929A0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkWeaponAction* const _this, const IAction& _actionCurrent)>(0xE7AEF0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponAction* const _this, const unsigned _eventCRC)>(0x1793370);
};

// ArkWeaponAttackAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponAttackAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FArkWeaponAttackAction = PreyFunction<void(ArkWeaponAttackAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792A60);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackAction* const _this)>(0x1792E40);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackAction* const _this)>(0x1792F60);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponAttackAction* const _this, const unsigned _eventCRC)>(0x1793480);
};

// ArkWeaponAttackOutAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackOutAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponAttackOutAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponAttackOutAction = PreyFunction<void(ArkWeaponAttackOutAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792B60);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackOutAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackOutAction* const _this)>(0x1792F60);
};

// ArkWeaponAttackContinueAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackContinueAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponAttackContinueAction(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponAttackContinueAction = PreyFunction<void(ArkWeaponAttackContinueAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792AA0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkWeaponAttackContinueAction* const _this, const IAction& _actionCurrent)>(0x1CBB0B0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackContinueAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackContinueAction* const _this)>(0x2DA4C0);
};

// ArkWeaponAttackContinueMalfunctionAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackContinueMalfunctionAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponAttackContinueMalfunctionAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FArkWeaponAttackContinueMalfunctionAction = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792AE0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction* const _this)>(0x1792FA0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponAttackContinueMalfunctionAction* const _this, const unsigned _eventCRC)>(0x1793710);
};

// ArkWeaponAttackInAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackInAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponAttackInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponAttackInAction = PreyFunction<void(ArkWeaponAttackInAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792B20);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackInAction* const _this)>(0x1792EA0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackInAction* const _this)>(0x1792FF0);
};

// ArkWeaponAttackOutAndUnselectAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponAttackOutAndUnselectAction : public ArkWeaponAttackOutAction
{ // Size=144 (0x90)
public:
	int m_unselectFragmentId;

	ArkWeaponAttackOutAndUnselectAction(const unsigned _weaponId, const int _attackOutFragmentId, const int _unselectFragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponAttackOutAndUnselectAction = PreyFunction<void(ArkWeaponAttackOutAndUnselectAction* const _this, const unsigned _weaponId, const int _attackOutFragmentId, const int _unselectFragmentId)>(0x1792BA0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponAttackOutAndUnselectAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponAttackOutAndUnselectAction* const _this)>(0x1793030);
};

// ArkWeaponDeployAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponDeployAction : public ArkWeaponAttackAction
{ // Size=136 (0x88)
public:
	ArkWeaponDeployAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponDeployAction = PreyFunction<void(ArkWeaponDeployAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792BF0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponDeployAction* const _this)>(0x1792E40);
	static inline auto FExit = PreyFunction<void(ArkWeaponDeployAction* const _this)>(0x1793100);
};

// ArkWeaponReloadAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponReloadAction(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponReloadAction = PreyFunction<void(ArkWeaponReloadAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792C30);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkWeaponReloadAction* const _this, const IAction& _actionCurrent)>(0x1CBB0B0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadAction* const _this)>(0x1793160);
};

// ArkWeaponReloadActionOnEvent
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadActionOnEvent : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponReloadActionOnEvent(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FArkWeaponReloadActionOnEvent = PreyFunction<void(ArkWeaponReloadActionOnEvent* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792C70);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkWeaponReloadActionOnEvent* const _this, const IAction& _actionCurrent)>(0x1CBB0B0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadActionOnEvent* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadActionOnEvent* const _this)>(0x17931A0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponReloadActionOnEvent* const _this, const unsigned _eventCRC)>(0x17937B0);
};

// ArkWeaponReloadInAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadInAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponReloadInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponReloadInAction = PreyFunction<void(ArkWeaponReloadInAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792CB0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadInAction* const _this)>(0x1792EE0);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadInAction* const _this)>(0x17931A0);
};

// ArkWeaponReloadOutAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponReloadOutAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponReloadOutAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponReloadOutAction = PreyFunction<void(ArkWeaponReloadOutAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792CF0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponReloadOutAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponReloadOutAction* const _this)>(0x17931E0);
};

// ArkWeaponSelectAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponSelectAction : public ArkWeaponAction
{ // Size=144 (0x90)
public:
	const bool m_bBlockAttack;

	ArkWeaponSelectAction(const unsigned _weaponId, const int _fragmentId, const bool _bBlockAttack);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponSelectAction = PreyFunction<void(ArkWeaponSelectAction* const _this, const unsigned _weaponId, const int _fragmentId, const bool _bBlockAttack)>(0x1792D30);
	static inline auto FEnter = PreyFunction<void(ArkWeaponSelectAction* const _this)>(0x1792F10);
	static inline auto FExit = PreyFunction<void(ArkWeaponSelectAction* const _this)>(0x1793220);
};

// ArkWeaponThrowIdleAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponThrowIdleAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponThrowIdleAction(const unsigned _weaponId, const int _fragmentId);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponThrowIdleAction = PreyFunction<void(ArkWeaponThrowIdleAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792D80);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkWeaponThrowIdleAction* const _this, const IAction& _actionCurrent)>(0x1CBB0B0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponThrowIdleAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponThrowIdleAction* const _this)>(0x1793260);
};

// ArkWeaponThrowInAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponThrowInAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponThrowInAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FArkWeaponThrowInAction = PreyFunction<void(ArkWeaponThrowInAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792DC0);
	static inline auto FEnter = PreyFunction<void(ArkWeaponThrowInAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponThrowInAction* const _this)>(0x17932B0);
	static inline auto FOnActionEvent = PreyFunction<void(ArkWeaponThrowInAction* const _this, const unsigned _eventCRC)>(0x17938D0);
};

// ArkWeaponUnselectAction
// Header:  Prey/GameDll/ark/weapons/arkweaponactions.h
class ArkWeaponUnselectAction : public ArkWeaponAction
{ // Size=136 (0x88)
public:
	ArkWeaponUnselectAction(const unsigned _weaponId, const int _fragmentId);
	virtual void Enter();
	virtual void Exit();

	static inline auto FArkWeaponUnselectAction = PreyFunction<void(ArkWeaponUnselectAction* const _this, const unsigned _weaponId, const int _fragmentId)>(0x1792E00);
	static inline auto FEnter = PreyFunction<void(ArkWeaponUnselectAction* const _this)>(0x1792ED0);
	static inline auto FExit = PreyFunction<void(ArkWeaponUnselectAction* const _this)>(0x17932F0);
};
#endif // !MOONCRASH
