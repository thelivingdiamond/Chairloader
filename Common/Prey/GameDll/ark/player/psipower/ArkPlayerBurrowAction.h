// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

// ArkPlayerBurrowAction
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerBurrowAction.h
class ArkPlayerBurrowAction : public TAction<SAnimationContext>
{ // Size=168 (0xA8)
public:
	Quat m_initialPlayerRotation;
	Vec3 m_initialPlayerPosition;
	float m_groundHeightDelta;
	float m_durationSec;
	float m_elapsedSec;

	ArkPlayerBurrowAction(const float _groundHeightDelta);
	virtual ~ArkPlayerBurrowAction();
	virtual void Enter();
	virtual void Exit();
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float _timePassed);

#if 0
	Quat GetTargetPlayerRotation() const;
#endif

	static inline auto FArkPlayerBurrowAction = PreyFunction<void(ArkPlayerBurrowAction* const _this, const float _groundHeightDelta)>(0x13A1DC0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerBurrowAction* const _this)>(0x157C9B0);
	static inline auto FExit = PreyFunction<void(ArkPlayerBurrowAction* const _this)>(0x13A2390);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerBurrowAction* const _this)>(0x13A2410);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerBurrowAction* const _this, float _timePassed)>(0x13A2880);
};
#endif // MOONCRASH
