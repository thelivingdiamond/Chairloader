// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/arkintrusivelist.h>

class ArkNpcAnimAction;
enum class EActionFailure;
class IProceduralClip;
struct IProceduralParams;

// ArkNpcAnimActionObserver
// Header:  Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h
class ArkNpcAnimActionObserver : public ArkIntrusiveListElement<ArkNpcAnimActionObserver>
{ // Size=32 (0x20)
public:
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimFragmentStarted(ArkNpcAnimAction& _animAction);
	virtual void OnNpcCustomActionEvent(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params);
	virtual void OnNpcAnimActionProceduralClipBegin(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc);
	virtual void OnNpcAnimActionProceduralClipEnd(ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAnimActionObserver();
	~ArkNpcAnimActionObserver();
#endif

	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0xA13080);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0xA13080);
	static inline auto FOnNpcAnimFragmentStarted = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0xA13080);
	static inline auto FOnNpcCustomActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc, const IProceduralParams& _params)>(0xA13080);
	static inline auto FOnNpcAnimActionProceduralClipBegin = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc)>(0xA13080);
	static inline auto FOnNpcAnimActionProceduralClipEnd = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, IProceduralClip& _clip, unsigned _clipCrc)>(0xA13080);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0xA13080);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0xA13080);
};

