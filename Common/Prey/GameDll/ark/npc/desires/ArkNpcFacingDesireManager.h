// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireManagerBase.h>

class ArkNpc;
class ArkNpcDesireTarget;
class ArkNpcFacingDesire;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcFacingDesireManager.h
#ifdef MOONCRASH
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireManagerBase.h>
#endif
class ArkNpcFacingDesireManager : public ArkNpcDesireManagerBase<ArkNpcFacingDesireManager,ArkNpcFacingDesire> // Id=80140FD Size=48
{
public:
	ArkNpcFacingDesireManager(ArkNpc &_arkNpc);
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	void OnActiveDesireAdded(ArkNpcFacingDesire const *_pPrevActiveDesire) { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
	void OnActiveDesireRemoved(ArkNpcFacingDesire const &_prevActiveDesire) { FOnActiveDesireRemoved(this,_prevActiveDesire); }
#ifndef MOONCRASH
	Vec3 GetPosition(ArkNpcDesireTarget const &_target, bool &_bAdjusted) const { return FGetPosition(this,_target,_bAdjusted); }
#else
	Vec3 GetPosition(const ArkNpcDesireTarget& _target, bool& _bAdjusted) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_), _target, _bAdjusted); }
#endif
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
	
#ifdef MOONCRASH
	bool ReachedTargetFacing(float _threshold) const { return FReachedTargetFacing(this, _threshold); }
	float GetCosNpcToTargetAngle() const { return FGetCosNpcToTargetAngle(this); }
#endif
#ifndef MOONCRASH
	static inline auto FRefresh = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262E0);
	static inline auto FShutDown = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x1213150);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcFacingDesireManager *const _this, ArkNpcFacingDesire const *_pPrevActiveDesire)>(0x15261F0);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcFacingDesireManager *const _this, ArkNpcFacingDesire const &_prevActiveDesire)>(0x1526250);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkNpcFacingDesireManager const *const _this, ArkNpcDesireTarget const &_target, bool &_bAdjusted)>(0x1525F30);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262D0);
	static inline auto FOnActiveResumeAngleChanged = PreyFunction<void(ArkNpcFacingDesireManager *const _this)>(0x15262D0);
	static inline auto FResolveBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager *const _this, bool _bAllowDesireFailure)>(0x15263A0);
	static inline auto FMakeBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager *const _this)>(0x1526040);
#else
	static inline auto FArkNpcFacingDesireManager = PreyFunction<void(ArkNpcFacingDesireManager* const _this, ArkNpc& _arkNpc)>(0x16458A0);
	static inline auto FRefresh = PreyFunction<void(ArkNpcFacingDesireManager* const _this)>(0x1646220);
	static inline auto FShutDown = PreyFunction<void(ArkNpcFacingDesireManager* const _this)>(0x12A2630);
	static inline auto FReachedTargetFacing = PreyFunction<bool(const ArkNpcFacingDesireManager* const _this, float _threshold)>(0x16461D0);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcFacingDesireManager* const _this, const ArkNpcFacingDesire* _pPrevActiveDesire)>(0x16460E0);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcFacingDesireManager* const _this, const ArkNpcFacingDesire& _prevActiveDesire)>(0x1646140);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkNpcFacingDesireManager* const _this, Vec3* _return_value_, const ArkNpcDesireTarget& _target, bool& _bAdjusted)>(0x1645E20);
	static inline auto FGetCosNpcToTargetAngle = PreyFunction<float(const ArkNpcFacingDesireManager* const _this)>(0x16458C0);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcFacingDesireManager* const _this)>(0x16461C0);
	static inline auto FOnActiveResumeAngleChanged = PreyFunction<void(ArkNpcFacingDesireManager* const _this)>(0x16461C0);
	static inline auto FResolveBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager* const _this, bool _bAllowDesireFailure)>(0x16462E0);
	static inline auto FMakeBodyTargetRequest = PreyFunction<bool(ArkNpcFacingDesireManager* const _this)>(0x1645F30);
#endif
};
