// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequin.h>

class IArkPlayerMimic;

// ArkPlayerMimicAction
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicAction.h
#ifdef MOONCRASH
#include <Prey/CryAction/ICryMannequin.h>
#endif
class ArkPlayerMimicAction : public TAction<SAnimationContext>
{ // Size=168 (0xA8)
public:
	Vec3 m_backwardTargetPosition;
	Vec3 m_playerStartLerpWorldPosition;
	IArkPlayerMimic* m_pMimic;
	float m_durationSec;
	float m_elapsedSec;

	ArkPlayerMimicAction();
	virtual ~ArkPlayerMimicAction();
	virtual void Enter();
	virtual void Exit();
	void SetMimic(IArkPlayerMimic& _mimic) { FSetMimic(this, _mimic); }
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float _timePassed);

#ifndef MOONCRASH
	static inline auto FArkPlayerMimicAction = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1464ED0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1464FF0);
	static inline auto FExit = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1465030);
	static inline auto FSetMimic = PreyFunction<void(ArkPlayerMimicAction* const _this, IArkPlayerMimic& _mimic)>(0x14659F0);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1465080);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMimicAction* const _this, float _timePassed)>(0x1465A00);
#else
	static inline auto FArkPlayerMimicAction = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x157C8E0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x157C9B0);
	static inline auto FExit = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x157C9F0);
	static inline auto FSetMimic = PreyFunction<void(ArkPlayerMimicAction* const _this, IArkPlayerMimic& _mimic)>(0x157D3B0);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x157CA40);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMimicAction* const _this, float _timePassed)>(0x157D3C0);
#endif
};
