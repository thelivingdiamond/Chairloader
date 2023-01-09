// Header file automatically created from a PDB.
#pragma once

class IArkPlayerMimic;

// ArkPlayerMimicAction
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicAction.h
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

	static inline auto FArkPlayerMimicAction = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1464ED0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1464FF0);
	static inline auto FExit = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1465030);
	static inline auto FSetMimic = PreyFunction<void(ArkPlayerMimicAction* const _this, IArkPlayerMimic& _mimic)>(0x14659F0);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerMimicAction* const _this)>(0x1465080);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMimicAction* const _this, float _timePassed)>(0x1465A00);
};

