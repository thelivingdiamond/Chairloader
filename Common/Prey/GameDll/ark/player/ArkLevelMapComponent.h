// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct AABB;
class ArkLocation;
class CArkMapVolume;

// ArkLevelMapComponent
// Header:  Prey/GameDll/ark/player/ArkLevelMapComponent.h
class ArkLevelMapComponent
{ // Size=64 (0x40)
public:
	std::vector<std::vector<CArkMapVolume*>> m_volumes;
	std::vector<uint64_t> m_mapsAqcuired;
	float m_scale;

	ArkLevelMapComponent();
	virtual ~ArkLevelMapComponent();
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnMapVolumeReset(CArkMapVolume& _volume) { FOnMapVolumeReset(this, _volume); }
	void Update() { FUpdate(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	std::vector<unsigned char> GetFogData(const int _index) const { alignas(std::vector<unsigned char>) std::byte _return_buf_[sizeof(std::vector<unsigned char>)]; return *FGetFogData(this, reinterpret_cast<std::vector<unsigned char>*>(_return_buf_), _index); }
	float GetFogCellSize() const { return FGetFogCellSize(this); }
	AABB GetLevelBounds() const { alignas(AABB) std::byte _return_buf_[sizeof(AABB)]; return *FGetLevelBounds(this, reinterpret_cast<AABB*>(_return_buf_)); }
	AABB GetFloorBounds(unsigned _nFloor) const { alignas(AABB) std::byte _return_buf_[sizeof(AABB)]; return *FGetFloorBounds(this, reinterpret_cast<AABB*>(_return_buf_), _nFloor); }
	CArkMapVolume* GetCurrentVolume(const Vec3& _worldPos) const { return FGetCurrentVolume(this, _worldPos); }
	int GetCurrentFloorIndex(const Vec3& _worldPos) const { return FGetCurrentFloorIndex(this, _worldPos); }
	int GetMapTextureID(const unsigned _nFloor) const { return FGetMapTextureID(this, _nFloor); }
	bool IsVisitedNear(const unsigned _nFloor, const Vec3& _worldPos) const { return FIsVisitedNear(this, _nFloor, _worldPos); }
	Vec2i GetFogArea(const AABB& _bounds) const { alignas(Vec2i) std::byte _return_buf_[sizeof(Vec2i)]; return *FGetFogArea(this, reinterpret_cast<Vec2i*>(_return_buf_), _bounds); }
	void SetMapAcquired(uint64_t _locationId, bool _bAcquired) { FSetMapAcquired(this, _locationId, _bAcquired); }
	bool IsMapAcquired(uint64_t _locationId) const { return FIsMapAcquired(this, _locationId); }
	void ResetMapsAcquired() { FResetMapsAcquired(this); }
	static float GetFogPixelSize() { return FGetFogPixelSize(); }
	static const ArkLocation* GetCurrentArkLocation() { return FGetCurrentArkLocation(); }

#if 0
	void SetVisitedCellState(bool _arg0_);
	bool IsCurrentVolume(const Vec3& _arg0_, const CArkMapVolume* _arg1_) const;
	bool IsInFloorVolume(unsigned _arg0_, const Vec3& _arg1_) const;
	bool IsVisited(const unsigned _arg0_, const Vec3& _arg1_) const;
	Vec2i GetFogCell(const Vec3& _arg0_, const Vec3& _arg1_) const;
	const unsigned GetNumFloors() const;
	void SetScale(const float _arg0_);
	float GetScale() const;
	int GetCurrentVolumeIndex(const Vec3& _arg0_) const;
#endif

	static inline auto FArkLevelMapComponentOv1 = PreyFunction<void(ArkLevelMapComponent* const _this)>(0x1224560);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkLevelMapComponent* const _this)>(0x1225AF0);
	static inline auto FOnMapVolumeReset = PreyFunction<void(ArkLevelMapComponent* const _this, CArkMapVolume& _volume)>(0x1225860);
	static inline auto FUpdate = PreyFunction<void(ArkLevelMapComponent* const _this)>(0x1225D40);
	static inline auto FReset = PreyFunction<void(ArkLevelMapComponent* const _this)>(0x1225AF0);
	static inline auto FSerialize = PreyFunction<void(ArkLevelMapComponent* const _this, TSerialize _ser)>(0x1225B60);
	static inline auto FGetFogData = PreyFunction<std::vector<unsigned char>*(const ArkLevelMapComponent* const _this, std::vector<unsigned char>* _return_value_, const int _index)>(0x1224DE0);
	static inline auto FGetFogCellSize = PreyFunction<float(const ArkLevelMapComponent* const _this)>(0x1224DC0);
	static inline auto FGetLevelBounds = PreyFunction<AABB*(const ArkLevelMapComponent* const _this, AABB* _return_value_)>(0x12253A0);
	static inline auto FGetFloorBounds = PreyFunction<AABB*(const ArkLevelMapComponent* const _this, AABB* _return_value_, unsigned _nFloor)>(0x1224C50);
	static inline auto FGetCurrentVolume = PreyFunction<CArkMapVolume* (const ArkLevelMapComponent* const _this, const Vec3& _worldPos)>(0x1224B90);
	static inline auto FGetCurrentFloorIndex = PreyFunction<int(const ArkLevelMapComponent* const _this, const Vec3& _worldPos)>(0x1224AD0);
	static inline auto FGetMapTextureID = PreyFunction<int(const ArkLevelMapComponent* const _this, const unsigned _nFloor)>(0x12254C0);
	static inline auto FIsVisitedNear = PreyFunction<bool(const ArkLevelMapComponent* const _this, const unsigned _nFloor, const Vec3& _worldPos)>(0x1225610);
	static inline auto FGetFogArea = PreyFunction<Vec2i*(const ArkLevelMapComponent* const _this, Vec2i* _return_value_, const AABB& _bounds)>(0x1224D50);
	static inline auto FSetMapAcquired = PreyFunction<void(ArkLevelMapComponent* const _this, uint64_t _locationId, bool _bAcquired)>(0x1225CC0);
	static inline auto FIsMapAcquired = PreyFunction<bool(const ArkLevelMapComponent* const _this, uint64_t _locationId)>(0x9AC940);
	static inline auto FResetMapsAcquired = PreyFunction<void(ArkLevelMapComponent* const _this)>(0x1227570);
	static inline auto FGetFogPixelSize = PreyFunction<float()>(0x1225390);
	static inline auto FGetCurrentArkLocation = PreyFunction<const ArkLocation* ()>(0x12248E0);
};

