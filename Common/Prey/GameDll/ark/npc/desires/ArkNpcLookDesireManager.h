// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireManagerBase.h>

class ArkNpc;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcLookDesireManager.h
class ArkNpcLookDesireManager : public ArkNpcDesireManagerBase<ArkNpcLookDesireManager,ArkNpcLookDesire> // Id=801409F Size=152
{
public:
	EArkNpcSpeedType m_speed;
	ArkNpcLookDesire::LookPoseParam m_defaultBlendInTime;
	ArkNpcLookDesire::LookPoseParam m_defaultSmoothTime;
	ArkNpcLookDesire::LookPoseParam m_defaultBlendOutTime;
	ArkNpcLookDesire::LookPoseParam m_defaultMaxYaw;
	ArkNpcLookDesire::LookPoseParam m_defaultMaxPitch;
	float m_speedMultiplierFastHead;
	float m_speedMultiplierFastestHead;
	float m_speedMultiplierFastTorso;
	float m_speedMultiplierFastestTorso;
	float m_speedScale;
	
	ArkNpcLookDesireManager(ArkNpc &_arkNpc);
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	void SetSpeedScale(float _scale) { FSetSpeedScale(this,_scale); }
	static void GetPoseBlenderParams(IEntity *_pEntity, ArkNpcLookDesire::LookPoseParam &_blendInTime, ArkNpcLookDesire::LookPoseParam &_smoothTime, ArkNpcLookDesire::LookPoseParam &_blendOutTime, ArkNpcLookDesire::LookPoseParam &_maxYaw, ArkNpcLookDesire::LookPoseParam &_maxPitch) { FGetPoseBlenderParams(_pEntity,_blendInTime,_smoothTime,_blendOutTime,_maxYaw,_maxPitch); }
	static void SetPoseBlenderParams(IEntity *_pEntity, ArkNpcLookDesire::LookPoseParam const &_blendInTime, ArkNpcLookDesire::LookPoseParam const &_smoothTime, ArkNpcLookDesire::LookPoseParam const &_blendOutTime, ArkNpcLookDesire::LookPoseParam const &_maxYaw, ArkNpcLookDesire::LookPoseParam const &_maxPitch) { FSetPoseBlenderParamsOv1(_pEntity,_blendInTime,_smoothTime,_blendOutTime,_maxYaw,_maxPitch); }
	void SetPoseBlenderParams() { FSetPoseBlenderParamsOv0(this); }
	void OnActiveDesireAdded(ArkNpcLookDesire const *_pPrevActiveDesire) { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
	void OnActiveDesireRemoved(ArkNpcLookDesire const &_prevActiveDesire) { FOnActiveDesireRemoved(this,_prevActiveDesire); }
	void OnActiveParamsChanged() { FOnActiveParamsChanged(this); }
	bool GetActiveLookPosition(Vec3 &_lookTargetPos) { return FGetActiveLookPosition(this,_lookTargetPos); }
	bool ResolveLookTargetRequest() { return FResolveLookTargetRequest(this); }
	void MakeLookTargetRequest() { FMakeLookTargetRequest(this); }
	void ClearLookTargetRequest() { FClearLookTargetRequest(this); }
	void UpdateSpeed() { FUpdateSpeed(this); }
	void SetPolarOffsetCoordinates(float _x, float _y) { FSetPolarOffsetCoordinates(this,_x,_y); }
	
#if 0
	void OnActiveResumeAngleChanged();
	void ResetPoseBlenderParams();
	void DebugDraw();
	float GetSpeedMultiplierHead() const;
	float GetSpeedMultiplierTorso() const;
#endif
	
	static inline auto FRefresh = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x14567B0);
	static inline auto FShutDown = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x1213150);
	static inline auto FSetSpeedScale = PreyFunction<void(ArkNpcLookDesireManager *const _this, float _scale)>(0x1457270);
	static inline auto FGetPoseBlenderParams = PreyFunction<void(IEntity *_pEntity, ArkNpcLookDesire::LookPoseParam &_blendInTime, ArkNpcLookDesire::LookPoseParam &_smoothTime, ArkNpcLookDesire::LookPoseParam &_blendOutTime, ArkNpcLookDesire::LookPoseParam &_maxYaw, ArkNpcLookDesire::LookPoseParam &_maxPitch)>(0x14562F0);
	static inline auto FSetPoseBlenderParamsOv1 = PreyFunction<void(IEntity *_pEntity, ArkNpcLookDesire::LookPoseParam const &_blendInTime, ArkNpcLookDesire::LookPoseParam const &_smoothTime, ArkNpcLookDesire::LookPoseParam const &_blendOutTime, ArkNpcLookDesire::LookPoseParam const &_maxYaw, ArkNpcLookDesire::LookPoseParam const &_maxPitch)>(0x1456FC0);
	static inline auto FSetPoseBlenderParamsOv0 = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x1456A40);
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcLookDesireManager *const _this, ArkNpcLookDesire const *_pPrevActiveDesire)>(0x14566F0);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcLookDesireManager *const _this, ArkNpcLookDesire const &_prevActiveDesire)>(0x1456740);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x14567A0);
	static inline auto FGetActiveLookPosition = PreyFunction<bool(ArkNpcLookDesireManager *const _this, Vec3 &_lookTargetPos)>(0x14561F0);
	static inline auto FResolveLookTargetRequest = PreyFunction<bool(ArkNpcLookDesireManager *const _this)>(0x1456870);
	static inline auto FMakeLookTargetRequest = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x1456530);
	static inline auto FClearLookTargetRequest = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x1456110);
	static inline auto FUpdateSpeed = PreyFunction<void(ArkNpcLookDesireManager *const _this)>(0x1457290);
	static inline auto FSetPolarOffsetCoordinates = PreyFunction<void(ArkNpcLookDesireManager *const _this, float _x, float _y)>(0x1456900);
};

