// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkRoomPathNode;
class CArkRoomVolumeManager;

// Header: FromCpp
// Prey/GameDll/ark/ArkRoomPath.h
class ArkRoomPath // Id=80195EF Size=56
{
public:
	float m_minDist;
	std::vector<unsigned int> m_volumes;
	std::vector<unsigned int> m_portals;
	
	ArkRoomPath(unsigned _startingVolumeId);
	ArkRoomPath(std::vector<unsigned int> const &_volumes, std::vector<unsigned int> const &_portals);
	void AppendPathNode(ArkRoomPathNode const &_pathEnd) { FAppendPathNode(this,_pathEnd); }
	void RemoveLastPathNode() { FRemoveLastPathNode(this); }
	unsigned GetVolumeId(int _index) const { return FGetVolumeId(this,_index); }
	unsigned GetLastVolumeId() const { return FGetLastVolumeId(this); }
	bool HasVolume(unsigned _entityId) const { return FHasVolume(this,_entityId); }
	unsigned GetPortalId(int _index) const { return FGetPortalId(this,_index); }
	unsigned GetLastPortalId() const { return FGetLastPortalId(this); }
	float GetOcclusion(CArkRoomVolumeManager const &_roomVolumeManager) const { return FGetOcclusion(this,_roomVolumeManager); }
	float GetHazardOcclusion(CArkRoomVolumeManager const &_roomVolumeManager) const { return FGetHazardOcclusion(this,_roomVolumeManager); }
	bool IsBetterThan(ArkRoomPath const &_other) const { return FIsBetterThan(this,_other); }
	void Reverse() { FReverse(this); }
	Vec3 Finalize(CArkRoomVolumeManager const &_roomVolumeManager, Vec3 const &_startPoint, Vec3 const &_endPoint, std::vector<Vec3> &_pathPoints) const { return FFinalize(this,_roomVolumeManager,_startPoint,_endPoint,_pathPoints); }
	bool Validate(CArkRoomVolumeManager const &_roomVolumeManager, std::function<void __cdecl(unsigned int,unsigned int)> const &_onInvalidFn) const { return FValidate(this,_roomVolumeManager,_onInvalidFn); }
	
#if 0
	int GetNumPortals() const;
	float GetMinDist() const;
	void SetMinDist(const float arg0);
	std::vector<unsigned int> const &GetVolumes() const;
	std::vector<unsigned int> const &GetPortals() const;
#endif
	
	static inline auto FAppendPathNode = PreyFunction<void(ArkRoomPath *const _this, ArkRoomPathNode const &_pathEnd)>(0x1470370);
	static inline auto FRemoveLastPathNode = PreyFunction<void(ArkRoomPath *const _this)>(0x1470A80);
	static inline auto FGetVolumeId = PreyFunction<unsigned(ArkRoomPath const *const _this, int _index)>(0x14709F0);
	static inline auto FGetLastVolumeId = PreyFunction<unsigned(ArkRoomPath const *const _this)>(0x1470920);
	static inline auto FHasVolume = PreyFunction<bool(ArkRoomPath const *const _this, unsigned _entityId)>(0x1470A10);
	static inline auto FGetPortalId = PreyFunction<unsigned(ArkRoomPath const *const _this, int _index)>(0x14709D0);
	static inline auto FGetLastPortalId = PreyFunction<unsigned(ArkRoomPath const *const _this)>(0x1470900);
	static inline auto FGetOcclusion = PreyFunction<float(ArkRoomPath const *const _this, CArkRoomVolumeManager const &_roomVolumeManager)>(0x1470940);
	static inline auto FGetHazardOcclusion = PreyFunction<float(ArkRoomPath const *const _this, CArkRoomVolumeManager const &_roomVolumeManager)>(0x1470870);
	static inline auto FIsBetterThan = PreyFunction<bool(ArkRoomPath const *const _this, ArkRoomPath const &_other)>(0x1470A40);
	static inline auto FReverse = PreyFunction<void(ArkRoomPath *const _this)>(0x1470A90);
	static inline auto FFinalize = PreyFunction<Vec3(ArkRoomPath const *const _this, CArkRoomVolumeManager const &_roomVolumeManager, Vec3 const &_startPoint, Vec3 const &_endPoint, std::vector<Vec3> &_pathPoints)>(0x14703A0);
	static inline auto FValidate = PreyFunction<bool(ArkRoomPath const *const _this, CArkRoomVolumeManager const &_roomVolumeManager, std::function<void __cdecl(unsigned int,unsigned int)> const &_onInvalidFn)>(0x1470AF0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkRoomPathNode;
class CArkRoomVolumeManager;

// ArkRoomPath
// Header:  Prey/GameDll/ark/ArkRoomPath.h
class ArkRoomPath
{ // Size=56 (0x38)
public:
	float m_minDist;
	std::vector<unsigned int> m_volumes;
	std::vector<unsigned int> m_portals;

	ArkRoomPath(unsigned _startingVolumeId);
	ArkRoomPath(const std::vector<unsigned int>& _volumes, const std::vector<unsigned int>& _portals);
	void AppendPathNode(const ArkRoomPathNode& _pathEnd) { FAppendPathNode(this, _pathEnd); }
	void RemoveLastPathNode() { FRemoveLastPathNode(this); }
	unsigned GetVolumeId(int _index) const { return FGetVolumeId(this, _index); }
	unsigned GetLastVolumeId() const { return FGetLastVolumeId(this); }
	bool HasVolume(unsigned _entityId) const { return FHasVolume(this, _entityId); }
	unsigned GetPortalId(int _index) const { return FGetPortalId(this, _index); }
	unsigned GetLastPortalId() const { return FGetLastPortalId(this); }
	float GetOcclusion(const CArkRoomVolumeManager& _roomVolumeManager) const { return FGetOcclusion(this, _roomVolumeManager); }
	float GetHazardOcclusion(const CArkRoomVolumeManager& _roomVolumeManager) const { return FGetHazardOcclusion(this, _roomVolumeManager); }
	bool IsBetterThan(const ArkRoomPath& _other) const { return FIsBetterThan(this, _other); }
	void Reverse() { FReverse(this); }
	Vec3 Finalize(const CArkRoomVolumeManager& _roomVolumeManager, const Vec3& _startPoint, const Vec3& _endPoint, std::vector<Vec3>& _pathPoints) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FFinalize(this, reinterpret_cast<Vec3*>(_return_buf_), _roomVolumeManager, _startPoint, _endPoint, _pathPoints); }
	bool Validate(const CArkRoomVolumeManager& _roomVolumeManager, const std::function<void __cdecl(unsigned int,unsigned int)>& _onInvalidFn) const { return FValidate(this, _roomVolumeManager, _onInvalidFn); }

#if 0
	int GetNumPortals() const;
	float GetMinDist() const;
	void SetMinDist(const float _arg0_);
	const std::vector<unsigned int>& GetVolumes() const;
	const std::vector<unsigned int>& GetPortals() const;
#endif

	static inline auto FArkRoomPathOv3 = PreyFunction<void(ArkRoomPath* const _this, unsigned _startingVolumeId)>(0x1587AB0);
	static inline auto FArkRoomPathOv2 = PreyFunction<void(ArkRoomPath* const _this, const std::vector<unsigned int>& _volumes, const std::vector<unsigned int>& _portals)>(0x1587A70);
	static inline auto FAppendPathNode = PreyFunction<void(ArkRoomPath* const _this, const ArkRoomPathNode& _pathEnd)>(0x1587B00);
	static inline auto FRemoveLastPathNode = PreyFunction<void(ArkRoomPath* const _this)>(0x1588210);
	static inline auto FGetVolumeId = PreyFunction<unsigned(const ArkRoomPath* const _this, int _index)>(0x1588180);
	static inline auto FGetLastVolumeId = PreyFunction<unsigned(const ArkRoomPath* const _this)>(0x15880B0);
	static inline auto FHasVolume = PreyFunction<bool(const ArkRoomPath* const _this, unsigned _entityId)>(0x15881A0);
	static inline auto FGetPortalId = PreyFunction<unsigned(const ArkRoomPath* const _this, int _index)>(0x1588160);
	static inline auto FGetLastPortalId = PreyFunction<unsigned(const ArkRoomPath* const _this)>(0x1588090);
	static inline auto FGetOcclusion = PreyFunction<float(const ArkRoomPath* const _this, const CArkRoomVolumeManager& _roomVolumeManager)>(0x15880D0);
	static inline auto FGetHazardOcclusion = PreyFunction<float(const ArkRoomPath* const _this, const CArkRoomVolumeManager& _roomVolumeManager)>(0x1588000);
	static inline auto FIsBetterThan = PreyFunction<bool(const ArkRoomPath* const _this, const ArkRoomPath& _other)>(0x15881D0);
	static inline auto FReverse = PreyFunction<void(ArkRoomPath* const _this)>(0x1588220);
	static inline auto FFinalize = PreyFunction<Vec3*(const ArkRoomPath* const _this, Vec3* _return_value_, const CArkRoomVolumeManager& _roomVolumeManager, const Vec3& _startPoint, const Vec3& _endPoint, std::vector<Vec3>& _pathPoints)>(0x1587B30);
	static inline auto FValidate = PreyFunction<bool(const ArkRoomPath* const _this, const CArkRoomVolumeManager& _roomVolumeManager, const std::function<void __cdecl(unsigned int,unsigned int)>& _onInvalidFn)>(0x1588280);
};
#endif // !MOONCRASH
