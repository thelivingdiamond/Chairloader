// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>

class IArkPlayerMimic;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicAction.h
class ArkPlayerMimicAction : public TAction<SAnimationContext> // Id=801C0F4 Size=168
{
public:
	Vec3 m_backwardTargetPosition;
	Vec3 m_playerStartLerpWorldPosition;
	IArkPlayerMimic *m_pMimic;
	float m_durationSec;
	float m_elapsedSec;
	
	ArkPlayerMimicAction();
	virtual void Enter();
	virtual void Exit();
	void SetMimic(IArkPlayerMimic &_mimic) { FSetMimic(this,_mimic); }
	virtual void OnInitialise();
	virtual IAction::EStatus Update(float _timePassed);
	
	static inline auto FEnter = PreyFunction<void(ArkPlayerMimicAction *const _this)>(0x1464FF0);
	static inline auto FExit = PreyFunction<void(ArkPlayerMimicAction *const _this)>(0x1465030);
	static inline auto FSetMimic = PreyFunction<void(ArkPlayerMimicAction *const _this, IArkPlayerMimic &_mimic)>(0x14659F0);
	static inline auto FOnInitialise = PreyFunction<void(ArkPlayerMimicAction *const _this)>(0x1465080);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerMimicAction *const _this, float _timePassed)>(0x1465A00);
};

