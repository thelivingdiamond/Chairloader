// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include "ArkNpcDesireManagerBase.h"

class ArkNpc;
class ArkNpcSpeedDesire;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesireManager.h
class ArkNpcSpeedDesireManager : public ArkNpcDesireManagerBase<ArkNpcSpeedDesireManager,ArkNpcSpeedDesire> // Id=8014136 Size=64
{
public:
	float m_deltaAngleRateNormal;
	float m_deltaAngleRateFast;
	float m_deltaAngleRateFastest;
	bool m_bSmoothedZTurning;
	
	ArkNpcSpeedDesireManager(ArkNpc &_arkNpc);
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	EArkNpcSpeedType GetSpeed() const { return FGetSpeed(this); }
	void OnActiveDesireAdded(ArkNpcSpeedDesire const *_pPrevActiveDesire) { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
	void OnActiveDesireRemoved(ArkNpcSpeedDesire const &_prevActiveDesire) { FOnActiveDesireRemoved(this,_prevActiveDesire); }
	void OnActiveParamsChanged() { FOnActiveParamsChanged(this); }
	void UpdateSpeed() { FUpdateSpeed(this); }
	
#if 0
	void DebugDraw();
#endif
	
	static inline auto FRefresh = PreyFunction<void(ArkNpcSpeedDesireManager *const _this)>(0xA13080);
	static inline auto FShutDown = PreyFunction<void(ArkNpcSpeedDesireManager *const _this)>(0x1213150);
	static inline auto FGetSpeed = PreyFunction<EArkNpcSpeedType(ArkNpcSpeedDesireManager const *const _this)>(0x1213090);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcSpeedDesireManager *const _this, ArkNpcSpeedDesire const *_pPrevActiveDesire)>(0x12130B0);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcSpeedDesireManager *const _this, ArkNpcSpeedDesire const &_prevActiveDesire)>(0x12130F0);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcSpeedDesireManager *const _this)>(0x1213140);
	static inline auto FUpdateSpeed = PreyFunction<void(ArkNpcSpeedDesireManager *const _this)>(0x12131B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcDesireManagerBase.h>

class ArkNpc;
class ArkNpcSpeedDesire;
enum class EArkNpcSpeedType;

// ArkNpcSpeedDesireManager
// Header:  Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesireManager.h
class ArkNpcSpeedDesireManager : public ArkNpcDesireManagerBase<ArkNpcSpeedDesireManager,ArkNpcSpeedDesire>
{ // Size=64 (0x40)
public:
	float m_deltaAngleRateNormal;
	float m_deltaAngleRateFast;
	float m_deltaAngleRateFastest;
	bool m_bSmoothedZTurning;

	ArkNpcSpeedDesireManager(ArkNpc& _arkNpc);
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	EArkNpcSpeedType GetSpeed() const { return FGetSpeed(this); }
	void OnActiveDesireAdded(const ArkNpcSpeedDesire* _pPrevActiveDesire) { FOnActiveDesireAdded(this, _pPrevActiveDesire); }
	void OnActiveDesireRemoved(const ArkNpcSpeedDesire& _prevActiveDesire) { FOnActiveDesireRemoved(this, _prevActiveDesire); }
	void OnActiveParamsChanged() { FOnActiveParamsChanged(this); }
	void UpdateSpeed() { FUpdateSpeed(this); }

#if 0
	void DebugDraw();
#endif

	static inline auto FArkNpcSpeedDesireManager = PreyFunction<void(ArkNpcSpeedDesireManager* const _this, ArkNpc& _arkNpc)>(0x12A2530);
	static inline auto FRefresh = PreyFunction<void(ArkNpcSpeedDesireManager* const _this)>(0x1333E90);
	static inline auto FShutDown = PreyFunction<void(ArkNpcSpeedDesireManager* const _this)>(0x12A2630);
	static inline auto FGetSpeed = PreyFunction<EArkNpcSpeedType(const ArkNpcSpeedDesireManager* const _this)>(0x12A2570);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcSpeedDesireManager* const _this, const ArkNpcSpeedDesire* _pPrevActiveDesire)>(0x12A2590);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcSpeedDesireManager* const _this, const ArkNpcSpeedDesire& _prevActiveDesire)>(0x12A25D0);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcSpeedDesireManager* const _this)>(0x12A2620);
	static inline auto FUpdateSpeed = PreyFunction<void(ArkNpcSpeedDesireManager* const _this)>(0x12A2690);
};
#endif // !MOONCRASH
