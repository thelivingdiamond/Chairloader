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
	~ArkLightTimeManager() { FBitNotArkLightTimeManager(this); }
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

