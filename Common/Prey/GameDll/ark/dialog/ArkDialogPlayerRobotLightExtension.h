// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkDialogPlayerExtension.h>

struct ArkRobotLight;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogPlayerRobotLightExtension.h
class ArkDialogPlayerRobotLightExtension : public IArkDialogPlayerExtension // Id=80141D7 Size=48
{
public:
	ArkRandomizedTimer m_brightnessTimer;
	uint64_t m_lastDialogId;
	float m_minBrightness;
	float m_maxBrightness;
	ArkRobotLight &m_light;
	
	ArkDialogPlayerRobotLightExtension(ArkRobotLight &_light);
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	virtual void OnDialogStart(uint64_t _dialogId);
	virtual void OnDialogEnd(uint64_t _dialogId);
	void SetMinMaxBrightness(float _min, float _max) { FSetMinMaxBrightness(this,_min,_max); }
	
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerRobotLightExtension *const _this, float _frameTime)>(0x11B3820);
	static inline auto FOnDialogStart = PreyFunction<void(ArkDialogPlayerRobotLightExtension *const _this, uint64_t _dialogId)>(0x11B3800);
	static inline auto FOnDialogEnd = PreyFunction<void(ArkDialogPlayerRobotLightExtension *const _this, uint64_t _dialogId)>(0x11B37F0);
	static inline auto FSetMinMaxBrightness = PreyFunction<void(ArkDialogPlayerRobotLightExtension *const _this, float _min, float _max)>(0x11B3810);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkDialogPlayerExtension.h>

struct ArkRobotLight;

// ArkDialogPlayerRobotLightExtension
// Header:  Prey/GameDll/ark/dialog/ArkDialogPlayerRobotLightExtension.h
class ArkDialogPlayerRobotLightExtension : public IArkDialogPlayerExtension
{ // Size=48 (0x30)
public:
	ArkRandomizedTimer m_brightnessTimer;
	uint64_t m_lastDialogId;
	float m_minBrightness;
	float m_maxBrightness;
	ArkRobotLight& m_light;

	ArkDialogPlayerRobotLightExtension(ArkRobotLight& _light);
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	virtual void OnDialogStart(uint64_t _dialogId);
	virtual void OnDialogEnd(uint64_t _dialogId);
	void SetMinMaxBrightness(float _min, float _max) { FSetMinMaxBrightness(this, _min, _max); }

	static inline auto FArkDialogPlayerRobotLightExtensionOv2 = PreyFunction<void(ArkDialogPlayerRobotLightExtension* const _this, ArkRobotLight& _light)>(0x1231000);
	static inline auto FUpdate = PreyFunction<void(ArkDialogPlayerRobotLightExtension* const _this, float _frameTime)>(0x12310A0);
	static inline auto FOnDialogStart = PreyFunction<void(ArkDialogPlayerRobotLightExtension* const _this, uint64_t _dialogId)>(0x1231080);
	static inline auto FOnDialogEnd = PreyFunction<void(ArkDialogPlayerRobotLightExtension* const _this, uint64_t _dialogId)>(0x1231070);
	static inline auto FSetMinMaxBrightness = PreyFunction<void(ArkDialogPlayerRobotLightExtension* const _this, float _min, float _max)>(0x1231090);
};
#endif // !MOONCRASH
