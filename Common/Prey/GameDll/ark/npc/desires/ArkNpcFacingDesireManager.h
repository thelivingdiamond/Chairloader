// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireManagerBase.h>

class ArkNpc;
class ArkNpcDesireTarget;
class ArkNpcFacingDesire;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcFacingDesireManager.h
class ArkNpcFacingDesireManager : public ArkNpcDesireManagerBase<ArkNpcFacingDesireManager,ArkNpcFacingDesire> // Id=80140FD Size=48
{
public:
	ArkNpcFacingDesireManager(ArkNpc &_arkNpc);
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	void OnActiveDesireAdded(ArkNpcFacingDesire const *_pPrevActiveDesire) { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
	void OnActiveDesireRemoved(ArkNpcFacingDesire const &_prevActiveDesire) { FOnActiveDesireRemoved(this,_prevActiveDesire); }
	Vec3 GetPosition(ArkNpcDesireTarget const &_target, bool &_bAdjusted) const { return FGetPosition(this,_target,_bAdjusted); }
	void OnActiveParamsChanged() { FOnActiveParamsChanged(this); }
	void OnActiveResumeAngleChanged() { FOnActiveResumeAngleChanged(this); }
	bool ResolveBodyTargetRequest(bool _bAllowDesireFailure) { return FResolveBodyTargetRequest(this,_bAllowDesireFailure); }
	bool MakeBodyTargetRequest() { return FMakeBodyTargetRequest(this); }
	
#if 0
	bool GetFacingDirection(Vec3 &arg0) const;
	void ClearBodyTargetRequest();
	void FailDesire(ArkNpcFacingDesire &arg0);
	void DebugDraw();
#endif
	
	static inline auto FRefresh = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262E0);
	static inline auto FShutDown = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x1213150);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcFacingDesireManager *const _this, ArkNpcFacingDesire const *_pPrevActiveDesire)>(0x15261F0);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcFacingDesireManager *const _this, ArkNpcFacingDesire const &_prevActiveDesire)>(0x1526250);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkNpcFacingDesireManager const *const _this, ArkNpcDesireTarget const &_target, bool &_bAdjusted)>(0x1525F30);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262D0);
	static inline auto FOnActiveResumeAngleChanged = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262D0);
	static inline auto FResolveBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager *const _this, bool _bAllowDesireFailure)>(0x15263A0);
	static inline auto FMakeBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager *const _this)>(0x1526040);
};

