// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

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

