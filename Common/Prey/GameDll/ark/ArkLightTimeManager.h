// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct ArkLightTimeSettings;
class CArkLight;

// Header: FromCpp
// Prey/GameDll/ark/ArkLightTimeManager.h
class ArkLightTimeManager // Id=8015494 Size=72
{
public:
	float m_fLastUpdatedTime;
	
	using RegisteredLightMap = std::unordered_map<CArkLight *,ArkLightTimeSettings>;
	
	std::unordered_map<CArkLight *,ArkLightTimeSettings> m_registeredLights;
	
	ArkLightTimeManager();
	~ArkLightTimeManager();
	void OnTimeOfDayChange() { FOnTimeOfDayChange(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void RegisterArkLight(CArkLight *_pArkLight, ArkLightTimeSettings const &_timeSettings) { FRegisterArkLight(this,_pArkLight,_timeSettings); }
	void UnRegisterArkLight(CArkLight *_pArkLight) { FUnRegisterArkLight(this,_pArkLight); }
	
	static inline auto FBitNotArkLightTimeManager = PreyFunction<void(ArkLightTimeManager *const _this)>(0x118F270);
	static inline auto FOnTimeOfDayChange = PreyFunction<void(ArkLightTimeManager *const _this)>(0x118F330);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkLightTimeManager *const _this)>(0x118F2D0);
	static inline auto FRegisterArkLight = PreyFunction<void(ArkLightTimeManager *const _this, CArkLight *_pArkLight, ArkLightTimeSettings const &_timeSettings)>(0x118F430);
	static inline auto FUnRegisterArkLight = PreyFunction<void(ArkLightTimeManager *const _this, CArkLight *_pArkLight)>(0x118F550);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkLightTimeSettings.h>

class CArkLight;

// ArkLightTimeManager
// Header:  Prey/GameDll/ark/ArkLightTimeManager.h
class ArkLightTimeManager
{ // Size=72 (0x48)
public:
	using RegisteredLightMap = std::unordered_map<CArkLight*, ArkLightTimeSettings>;

	float m_fLastUpdatedTime;
	std::unordered_map<CArkLight*, ArkLightTimeSettings> m_registeredLights;

	ArkLightTimeManager();
	~ArkLightTimeManager();
	void OnTimeOfDayChange() { FOnTimeOfDayChange(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void RegisterArkLight(CArkLight* _pArkLight, const ArkLightTimeSettings& _timeSettings) { FRegisterArkLight(this, _pArkLight, _timeSettings); }
	void UnRegisterArkLight(CArkLight* _pArkLight) { FUnRegisterArkLight(this, _pArkLight); }

	static inline auto FArkLightTimeManagerOv1 = PreyFunction<void(ArkLightTimeManager* const _this)>(0x120A410);
	static inline auto FBitNotArkLightTimeManager = PreyFunction<void(ArkLightTimeManager* const _this)>(0x120A490);
	static inline auto FOnTimeOfDayChange = PreyFunction<void(ArkLightTimeManager* const _this)>(0x120A550);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkLightTimeManager* const _this)>(0x120A4F0);
	static inline auto FRegisterArkLight = PreyFunction<void(ArkLightTimeManager* const _this, CArkLight* _pArkLight, const ArkLightTimeSettings& _timeSettings)>(0x120A650);
	static inline auto FUnRegisterArkLight = PreyFunction<void(ArkLightTimeManager* const _this, CArkLight* _pArkLight)>(0x120A770);
};
#endif // !MOONCRASH
