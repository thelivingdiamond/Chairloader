// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaFear.h
class ArkTraumaFear : public ArkTraumaBase // Id=801C0C9 Size=312
{
public:
	unsigned m_cameraModifierHandle;
	Ang3 m_storedRotation;
	
	ArkTraumaFear();
	virtual ~ArkTraumaFear();
	virtual void PostSerialize();
	virtual void Activate(int _level);
	virtual void ReevaluatePhase(bool _bImmediate);
	virtual void ForceRemove(bool _bImmediate);
	void HandleFearCameraRotation(Ang3 &_cameraRotation, float _frameTime) { FHandleFearCameraRotation(this,_cameraRotation,_frameTime); }
	void SetUpCameraRotation() { FSetUpCameraRotation(this); }
	void CleanUpFear() { FCleanUpFear(this); }
	
	static inline auto FPostSerialize = PreyFunction<void(ArkTraumaFear *const _this)>(0x1464C90);
	static inline auto FActivate = PreyFunction<void(ArkTraumaFear *const _this, int _level)>(0x14646D0);
	static inline auto FReevaluatePhase = PreyFunction<void(ArkTraumaFear *const _this, bool _bImmediate)>(0x1464CE0);
	static inline auto FForceRemove = PreyFunction<void(ArkTraumaFear *const _this, bool _bImmediate)>(0x1464860);
	static inline auto FHandleFearCameraRotation = PreyFunction<void(ArkTraumaFear *const _this, Ang3 &_cameraRotation, float _frameTime)>(0x1464880);
	static inline auto FSetUpCameraRotation = PreyFunction<void(ArkTraumaFear *const _this)>(0x1464D20);
	static inline auto FCleanUpFear = PreyFunction<void(ArkTraumaFear *const _this)>(0x1464710);
};

