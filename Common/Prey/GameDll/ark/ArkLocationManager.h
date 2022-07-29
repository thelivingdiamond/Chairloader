// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Exact
// Prey/GameDll/ark/ArkLocationManager.h
class ArkLocationManager // Id=80167DE Size=88
{
public:
	struct LocationInfo // Id=80167DF Size=16
	{
		string label;
		string screenshotPath;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::unordered_map<unsigned __int64,ArkLocationManager::LocationInfo> m_alternateNames;
	std::vector<unsigned __int64> m_loaded;
	
	void Reset() { FReset(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	const char *GetLocationLabel(uint64_t _id) const { return FGetLocationLabel(this,_id); }
	const char *GetCurrentLocationLabel() const { return FGetCurrentLocationLabel(this); }
	const char *GetCurrentLocationScreenshotPath() const { return FGetCurrentLocationScreenshotPath(this); }
	uint64_t GetCurrentLocation() const { return FGetCurrentLocation(this); }
	void SetAlternateName(const uint64_t _id, const char *_altName, const char *_screenshotPath) { FSetAlternateName(this,_id,_altName,_screenshotPath); }
	void RemoveAlternateName(const uint64_t _id) { FRemoveAlternateName(this,_id); }
	bool HasLoaded(const uint64_t _id) const { return FHasLoaded(this,_id); }
	void SetLoaded(const uint64_t _id, const bool _bLoaded) { FSetLoaded(this,_id,_bLoaded); }
	ArkLocationManager::LocationInfo const *GetAlternateNameInfo(const uint64_t _id) const { return FGetAlternateNameInfo(this,_id); }
	
	static inline auto FReset = PreyFunction<void(ArkLocationManager *const _this)>(0x11983D0);
	static inline auto FSerialize = PreyFunction<void(ArkLocationManager *const _this, TSerialize ser)>(0x11983E0);
	static inline auto FGetLocationLabel = PreyFunction<const char *(ArkLocationManager const *const _this, uint64_t _id)>(0x11981C0);
	static inline auto FGetCurrentLocationLabel = PreyFunction<const char *(ArkLocationManager const *const _this)>(0x1198080);
	static inline auto FGetCurrentLocationScreenshotPath = PreyFunction<const char *(ArkLocationManager const *const _this)>(0x1198120);
	static inline auto FGetCurrentLocation = PreyFunction<uint64_t(ArkLocationManager const *const _this)>(0x1197FD0);
	static inline auto FSetAlternateName = PreyFunction<void(ArkLocationManager *const _this, const uint64_t _id, const char *_altName, const char *_screenshotPath)>(0x1198550);
	static inline auto FRemoveAlternateName = PreyFunction<void(ArkLocationManager *const _this, const uint64_t _id)>(0x1198290);
	static inline auto FHasLoaded = PreyFunction<bool(ArkLocationManager const *const _this, const uint64_t _id)>(0x1198230);
	static inline auto FSetLoaded = PreyFunction<void(ArkLocationManager *const _this, const uint64_t _id, const bool _bLoaded)>(0x1198750);
	static inline auto FGetAlternateNameInfo = PreyFunction<ArkLocationManager::LocationInfo const *(ArkLocationManager const *const _this, const uint64_t _id)>(0x1197ED0);
};

