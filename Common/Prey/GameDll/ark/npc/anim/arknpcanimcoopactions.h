// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/GameDll/ark/npc/anim/arknpcanimactions.h>

class ArkNpc;
enum class EPlayerActionPriority;
enum class EPriorityComparison;
class IAction;
struct IAnimatedCharacter;
class IAnimationDatabase;
struct IEntity;

// CArkNpcAnimCoopAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimcoopactions.h
class CArkNpcAnimCoopAction : public ArkNpcAnimAction
{ // Size=208 (0xD0)
public:
	const unsigned m_targetSlaveEntityId;
	int m_contextSlaveTagId;
	const IAnimationDatabase* m_pADB;
	bool m_bShouldReleaseSlave;

	CArkNpcAnimCoopAction(ArkNpc& _rNpc, EPlayerActionPriority _priority, int _fragmentId, unsigned _targetSlave, const char* _pContextSlaveTag, const char* _pADBPath);
	virtual ~CArkNpcAnimCoopAction();
	virtual void Install();
	virtual void Enter();
	virtual void Exit();
	virtual IAction::EStatus Update(float _elapsedTime);
	virtual void OnActionEvent(const unsigned _eventCRC);
	void SlaveTarget(bool _bEnslave) { FSlaveTarget(this, _bEnslave); }

#if 0
	IEntity* GetNpcEntity() const;
	IEntity* GetSlaveEntity() const;
	IAnimatedCharacter* GetNpcAnimatedCharacter() const;
	IAnimatedCharacter* GetTargetAnimatedCharacter() const;
#endif

	static inline auto FCArkNpcAnimCoopAction = PreyFunction<void(CArkNpcAnimCoopAction* const _this, ArkNpc& _rNpc, EPlayerActionPriority _priority, int _fragmentId, unsigned _targetSlave, const char* _pContextSlaveTag, const char* _pADBPath)>(0x126FFA0);
	static inline auto FBitNotCArkNpcAnimCoopAction = PreyFunction<void(CArkNpcAnimCoopAction* const _this)>(0x1270440);
	static inline auto FInstall = PreyFunction<void(CArkNpcAnimCoopAction* const _this)>(0x12708A0);
	static inline auto FEnter = PreyFunction<void(CArkNpcAnimCoopAction* const _this)>(0x126F1C0);
	static inline auto FExit = PreyFunction<void(CArkNpcAnimCoopAction* const _this)>(0x12705C0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CArkNpcAnimCoopAction* const _this, float _elapsedTime)>(0x12712D0);
	static inline auto FOnActionEvent = PreyFunction<void(CArkNpcAnimCoopAction* const _this, const unsigned _eventCRC)>(0x1270B00);
	static inline auto FSlaveTarget = PreyFunction<void(CArkNpcAnimCoopAction* const _this, bool _bEnslave)>(0x1271180);
};

// CMimicGrabPlayerAnimAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimcoopactions.h
class CMimicGrabPlayerAnimAction : public CArkNpcAnimCoopAction
{ // Size=240 (0xF0)
public:
	static inline auto s_kPlayerMimicGrabWinEvent = PreyGlobal<const char* const>(0x0);
	const float m_damageCooldown;
	const uint64_t m_damageSignal;
	float m_grabDuration;
	float m_damageCooldownTimer;
	int m_mimicGrabHandle;
	bool m_bCompleted;

	CMimicGrabPlayerAnimAction(ArkNpc& _rNpc, const int _fragmentId, float _grabDuration, float _damageCooldown, const uint64_t& _damageSignal);
	virtual ~CMimicGrabPlayerAnimAction();
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionEvent(const unsigned _eventCRC);
	virtual IAction::EStatus Update(float _elapsedTime);
	virtual EPriorityComparison ComparePriority(const IAction& _actionCurrent) const;
	virtual void Install();

#if 0
	void OnPlayerWin();
	void ClosePlayerMashUi();
#endif

	static inline auto FCMimicGrabPlayerAnimAction = PreyFunction<void(CMimicGrabPlayerAnimAction* const _this, ArkNpc& _rNpc, const int _fragmentId, float _grabDuration, float _damageCooldown, const uint64_t& _damageSignal)>(0x12700F0);
	static inline auto FEnter = PreyFunction<void(CMimicGrabPlayerAnimAction* const _this)>(0x1270510);
	static inline auto FExit = PreyFunction<void(CMimicGrabPlayerAnimAction* const _this)>(0x12706D0);
	static inline auto FOnActionEvent = PreyFunction<void(CMimicGrabPlayerAnimAction* const _this, const unsigned _eventCRC)>(0x1270BE0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CMimicGrabPlayerAnimAction* const _this, float _elapsedTime)>(0x1271310);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const CMimicGrabPlayerAnimAction* const _this, const IAction& _actionCurrent)>(0x4FD7F0);
	static inline auto FInstall = PreyFunction<void(CMimicGrabPlayerAnimAction* const _this)>(0x1270AB0);
};

// CMimicGrabPlayerJumpAnimAction
// Header:  Prey/GameDll/ark/npc/anim/arknpcanimcoopactions.h
class CMimicGrabPlayerJumpAnimAction : public ArkNpcAnimAction
{ // Size=200 (0xC8)
public:
	const float m_jumpAbortDistanceSqrd;
	const float m_cosAngleAbort;
	bool m_bAborted;
	bool m_bJumping;

	CMimicGrabPlayerJumpAnimAction(ArkNpc& _rNpc, const int _fragmentId, float _jumpAbortDistance, float _cosAngleAbort);
	virtual ~CMimicGrabPlayerJumpAnimAction();
	virtual void Enter();
	virtual void Exit();
	virtual void OnActionFinished();

	static inline auto FCMimicGrabPlayerJumpAnimAction = PreyFunction<void(CMimicGrabPlayerJumpAnimAction* const _this, ArkNpc& _rNpc, const int _fragmentId, float _jumpAbortDistance, float _cosAngleAbort)>(0x12703C0);
	static inline auto FEnter = PreyFunction<void(CMimicGrabPlayerJumpAnimAction* const _this)>(0x1270590);
	static inline auto FExit = PreyFunction<void(CMimicGrabPlayerJumpAnimAction* const _this)>(0x1270800);
	static inline auto FOnActionFinished = PreyFunction<void(CMimicGrabPlayerJumpAnimAction* const _this)>(0x1270D90);
};
#endif // MOONCRASH
