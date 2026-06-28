// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkPlayerUpperBodyAction
// Header:  Prey/GameDll/ark/player/ArkPlayerUpperBodyAction.h
class ArkPlayerUpperBodyAction : public TAction<SAnimationContext>
{ // Size=152 (0x98)
public:
	enum class fragment
	{
		idle = 0,
		idleBreak = 1,
		movement = 2,
		last = 3,
	};

	std::array<int,3> m_fragmentIds;
	float m_lastIdleBreakTime;
	bool m_bPlayingIdleBreak;

	ArkPlayerUpperBodyAction();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void OnSequenceFinished(int _layer, unsigned _scopeID);
	virtual void Exit();

#if 0
	void ResetIdleBreak();
#endif

	static inline auto FArkPlayerUpperBodyAction = PreyFunction<void(ArkPlayerUpperBodyAction* const _this)>(0x12FF8B0);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerUpperBodyAction* const _this, float _timePassed)>(0x12FFB50);
	static inline auto FOnSequenceFinished = PreyFunction<void(ArkPlayerUpperBodyAction* const _this, int _layer, unsigned _scopeID)>(0x12FFAF0);
	static inline auto FExit = PreyFunction<void(ArkPlayerUpperBodyAction* const _this)>(0x12FFAB0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>

// ArkPlayerUpperBodyAction
// Header:  Prey/GameDll/ark/player/ArkPlayerUpperBodyAction.h
class ArkPlayerUpperBodyAction : public TAction<SAnimationContext>
{ // Size=152 (0x98)
public:
	enum class fragment
	{
		idle = 0,
		idleBreak = 1,
		movement = 2,
		last = 3,
	};

	std::array<int, 3> m_fragmentIds;
	float m_lastIdleBreakTime;
	bool m_bPlayingIdleBreak;

	ArkPlayerUpperBodyAction();
	virtual IAction::EStatus Update(float _timePassed);
	virtual void OnSequenceFinished(int _layer, unsigned _scopeID);
	virtual void Exit();

#if 0
	void ResetIdleBreak();
#endif

	static inline auto FArkPlayerUpperBodyAction = PreyFunction<void(ArkPlayerUpperBodyAction* const _this)>(0x13DA730);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkPlayerUpperBodyAction* const _this, float _timePassed)>(0x13DA9D0);
	static inline auto FOnSequenceFinished = PreyFunction<void(ArkPlayerUpperBodyAction* const _this, int _layer, unsigned _scopeID)>(0x13DA970);
	static inline auto FExit = PreyFunction<void(ArkPlayerUpperBodyAction* const _this)>(0x13DA930);
};
#endif // !MOONCRASH
