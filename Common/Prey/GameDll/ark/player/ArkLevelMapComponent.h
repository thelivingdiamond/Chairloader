// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkLocation;
class CArkMapVolume;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkLevelMapComponent.h
class ArkLevelMapComponent // Id=80167BE Size=64
{
public:
	std::vector<std::vector<CArkMapVolume *>> m_volumes;
	std::vector<unsigned __int64> m_mapsAqcuired;
	float m_scale;
	
	ArkLevelMapComponent();
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnMapVolumeReset(CArkMapVolume &_volume) { FOnMapVolumeReset(this,_volume); }
	void Update() { FUpdate(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	std::vector<unsigned char> GetFogData(const int _index) const { return FGetFogData(this,_index); }
	float GetFogCellSize() const { return FGetFogCellSize(this); }
	AABB GetLevelBounds() const { return FGetLevelBounds(this); }
	AABB GetFloorBounds(unsigned _nFloor) const { return FGetFloorBounds(this,_nFloor); }
	CArkMapVolume *GetCurrentVolume(Vec3 const &_worldPos) const { return FGetCurrentVolume(this,_worldPos); }
	int GetCurrentFloorIndex(Vec3 const &_worldPos) const { return FGetCurrentFloorIndex(this,_worldPos); }
	int GetMapTextureID(const unsigned _nFloor) const { return FGetMapTextureID(this,_nFloor); }
	bool IsVisitedNear(const unsigned _nFloor, Vec3 const &_worldPos) const { return FIsVisitedNear(this,_nFloor,_worldPos); }
	Vec2i GetFogArea(AABB const &_bounds) const { return FGetFogArea(this,_bounds); }
	void SetMapAcquired(uint64_t _locationId, bool _bAcquired) { FSetMapAcquired(this,_locationId,_bAcquired); }
	bool IsMapAcquired(uint64_t _locationId) const { return FIsMapAcquired(this,_locationId); }
	void ResetMapsAcquired() { FResetMapsAcquired(this); }
	static float GetFogPixelSize() { return FGetFogPixelSize(); }
	static ArkLocation const *GetCurrentArkLocation() { return FGetCurrentArkLocation(); }
	
#if 0
	void SetVisitedCellState(bool arg0);
	bool IsCurrentVolume(Vec3 const &arg0, CArkMapVolume const *arg1) const;
	bool IsInFloorVolume(unsigned arg0, Vec3 const &arg1) const;
	bool IsVisited(const unsigned arg0, Vec3 const &arg1) const;
	Vec2i GetFogCell(Vec3 const &arg0, Vec3 const &arg1) const;
	const unsigned GetNumFloors() const;
	void SetScale(const float arg0);
	float GetScale() const;
	int GetCurrentVolumeIndex(Vec3 const &arg0) const;
#endif
	
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkLevelMapComponent *const _this)>(0x1225AF0);
	static inline auto FOnMapVolumeReset = PreyFunction<void(ArkLevelMapComponent *const _this, CArkMapVolume &_volume)>(0x1225860);
	static inline auto FUpdate = PreyFunction<void(ArkLevelMapComponent *const _this)>(0x1225D40);
	static inline auto FReset = PreyFunction<void(ArkLevelMapComponent *const _this)>(0x1225AF0);
	static inline auto FSerialize = PreyFunction<void(ArkLevelMapComponent *const _this, TSerialize _ser)>(0x1225B60);
	static inline auto FGetFogData = PreyFunction<std::vector<unsigned char>(ArkLevelMapComponent const *const _this, const int _index)>(0x1224DE0);
	static inline auto FGetFogCellSize = PreyFunction<float(ArkLevelMapComponent const *const _this)>(0x1224DC0);
	static inline auto FGetLevelBounds = PreyFunction<AABB(ArkLevelMapComponent const *const _this)>(0x12253A0);
	static inline auto FGetFloorBounds = PreyFunction<AABB(ArkLevelMapComponent const *const _this, unsigned _nFloor)>(0x1224C50);
	static inline auto FGetCurrentVolume = PreyFunction<CArkMapVolume *(ArkLevelMapComponent const *const _this, Vec3 const &_worldPos)>(0x1224B90);
	static inline auto FGetCurrentFloorIndex = PreyFunction<int(ArkLevelMapComponent const *const _this, Vec3 const &_worldPos)>(0x1224AD0);
	static inline auto FGetMapTextureID = PreyFunction<int(ArkLevelMapComponent const *const _this, const unsigned _nFloor)>(0x12254C0);
	static inline auto FIsVisitedNear = PreyFunction<bool(ArkLevelMapComponent const *const _this, const unsigned _nFloor, Vec3 const &_worldPos)>(0x1225610);
	static inline auto FGetFogArea = PreyFunction<Vec2i(ArkLevelMapComponent const *const _this, AABB const &_bounds)>(0x1224D50);
	static inline auto FSetMapAcquired = PreyFunction<void(ArkLevelMapComponent *const _this, uint64_t _locationId, bool _bAcquired)>(0x1225CC0);
	static inline auto FIsMapAcquired = PreyFunction<bool(ArkLevelMapComponent const *const _this, uint64_t _locationId)>(0x9AC940);
	static inline auto FResetMapsAcquired = PreyFunction<void(ArkLevelMapComponent *const _this)>(0x1227570);
	static inline auto FGetFogPixelSize = PreyFunction<float()>(0x1225390);
	static inline auto FGetCurrentArkLocation = PreyFunction<ArkLocation const *()>(0x12248E0);
};

