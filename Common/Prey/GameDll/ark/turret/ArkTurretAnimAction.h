// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

class ArkTurretCharacter;
enum class EPriorityComparison;
class IAction;

// ArkTurretAdditiveAnimAction
// Header:  Prey/GameDll/ark/turret/ArkTurretAnimAction.h
class ArkTurretAdditiveAnimAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkTurretAdditiveAnimAction(int fragmentId);
	virtual ~ArkTurretAdditiveAnimAction();
	virtual EPriorityComparison ComparePriority(const IAction& currentAction) const;

	static inline auto FGetName = PreyFunction<const char* (const ArkTurretAdditiveAnimAction* const _this)>(0x13CA350);
	static inline auto FDoDelete = PreyFunction<void(ArkTurretAdditiveAnimAction* const _this)>(0x3E3960);
	static inline auto FArkTurretAdditiveAnimAction = PreyFunction<void(ArkTurretAdditiveAnimAction* const _this, int fragmentId)>(0x13CA1A0);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const ArkTurretAdditiveAnimAction* const _this, const IAction& currentAction)>(0x4FD7F0);
};

// ArkTurretAnimAction
// Header:  Prey/GameDll/ark/turret/ArkTurretAnimAction.h
class ArkTurretAnimAction : public TAction<SAnimationContext>
{ // Size=136 (0x88)
public:
	using Base = TAction<SAnimationContext>;

	ArkTurretCharacter& m_character;

	virtual const char* GetName() const;
	virtual void DoDelete();
	ArkTurretAnimAction(ArkTurretCharacter& _character, int fragmentId, bool _bAutoBlendout);
	virtual ~ArkTurretAnimAction();
	virtual void Enter();
	virtual void OnFragmentStarted();
	virtual void Exit();

	static inline auto FGetName = PreyFunction<const char* (const ArkTurretAnimAction* const _this)>(0x13CA360);
	static inline auto FDoDelete = PreyFunction<void(ArkTurretAnimAction* const _this)>(0x3E3960);
	static inline auto FArkTurretAnimAction = PreyFunction<void(ArkTurretAnimAction* const _this, ArkTurretCharacter& _character, int fragmentId, bool _bAutoBlendout)>(0x13CA240);
	static inline auto FEnter = PreyFunction<void(ArkTurretAnimAction* const _this)>(0x13CA2F0);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkTurretAnimAction* const _this)>(0x13CA370);
	static inline auto FExit = PreyFunction<void(ArkTurretAnimAction* const _this)>(0x13CA320);
};
#endif // MOONCRASH
