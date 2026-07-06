// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkPlayerAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerAction(int _fragmentId);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FArkPlayerAction = PreyFunction<void(ArkPlayerAction* const _this, int _fragmentId)>(0x1558F20);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerAction* const _this, float _timePassed)>(0x1558FC0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

// ArkPlayerAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerAction(int _fragmentId);
	virtual IAction::EStatus Update(float _timePassed);

	static inline auto FArkPlayerAction = PreyFunction<void(ArkPlayerAction* const _this, int _fragmentId)>(0x167E680);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerAction* const _this, float _timePassed)>(0x167E990);
};

// ArkPlayerDisarmStartAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerDisarmStartAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerDisarmStartAction(int _fragmentId);
	virtual ~ArkPlayerDisarmStartAction();

	static inline auto FArkPlayerDisarmStartAction = PreyFunction<void(ArkPlayerDisarmStartAction* const _this, int _fragmentId)>(0x167E750);
};

// ArkPlayerDisarmFailAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerDisarmFailAction : public ArkPlayerDisarmStartAction
{ // Size=128 (0x80)
public:
	ArkPlayerDisarmFailAction(int _fragmentId);
	virtual ~ArkPlayerDisarmFailAction();
	virtual void OnActionEvent(const unsigned _eventCRC);

	static inline auto FArkPlayerDisarmFailAction = PreyFunction<void(ArkPlayerDisarmFailAction* const _this, int _fragmentId)>(0x167E720);
	static inline auto FOnActionEvent = PreyFunction<void(ArkPlayerDisarmFailAction* const _this, const unsigned _eventCRC)>(0x167E8F0);
};

// ArkPlayerDisarmWinAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerDisarmWinAction : public ArkPlayerDisarmStartAction
{ // Size=128 (0x80)
public:
	ArkPlayerDisarmWinAction(int _fragmentId);
	virtual ~ArkPlayerDisarmWinAction();
	virtual void Exit();

	static inline auto FArkPlayerDisarmWinAction = PreyFunction<void(ArkPlayerDisarmWinAction* const _this, int _fragmentId)>(0x167E7F0);
	static inline auto FExit = PreyFunction<void(ArkPlayerDisarmWinAction* const _this)>(0x167E8C0);
};

// ArkPlayerGlooedAction
// Header:  Prey/GameDll/ark/player/ArkPlayerAction.h
class ArkPlayerGlooedAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	ArkPlayerGlooedAction(int _fragmentId);
	virtual ~ArkPlayerGlooedAction();
	virtual void OnFragmentStarted();

	static inline auto FArkPlayerGlooedAction = PreyFunction<void(ArkPlayerGlooedAction* const _this, int _fragmentId)>(0x167E820);
	static inline auto FOnFragmentStarted = PreyFunction<void(ArkPlayerGlooedAction* const _this)>(0x167E970);
};
#endif // !MOONCRASH
