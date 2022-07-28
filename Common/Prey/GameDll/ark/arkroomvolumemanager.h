// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/iface/IArkRoomVolumeManager.h>

class ArkRoomPath;
struct GeneratePropagationStats;
class IArkRoomPortal;
class IArkRoomVolume;
struct ICVar;
struct IConsoleCmdArgs;

// Header: Override
// Prey/GameDll/ark/arkroomvolumemanager.h
class ArkRoomPathNode // Id=80195F0 Size=8
{
public:
	const unsigned m_volumeId;
	const unsigned m_portalId;

#if 0
	bool operator==(ArkRoomPathNode const& arg0) const;
#endif
};

// Header: Override
// Prey/GameDll/ark/arkroomvolumemanager.h
class ArkRoomPathNodePair // Id=801964C Size=16
{
public:
	ArkRoomPathNode m_pathEnd0;
	ArkRoomPathNode m_pathEnd1;

#if 0
	bool operator==(ArkRoomPathNodePair const& arg0) const;
#endif
};

// Header: Exact
// Prey/GameDll/ark/arkroomvolumemanager.h
class CArkRoomVolumeManager : public IArkRoomVolumeManager // Id=80195F1 Size=328
{
public:
	class VolumeData // Id=80195F2 Size=72
	{
	public:
		std::vector<unsigned int> m_portals;
		std::vector<Vec3> m_points;
		float m_height;
		const unsigned m_entityId;
		IArkRoomVolume *m_roomVolume;
		bool m_bExportable;
		
		bool IsPointInside(Vec3 const &_p) const { return FIsPointInside(this,_p); }
		void RemoveLinkedPortal(const unsigned _portalId) { FRemoveLinkedPortal(this,_portalId); }
		
#if 0
		unsigned GetEntityId() const;
		IArkRoomVolume *GetRoomVolume() const;
		void SetExportable(bool arg0);
		bool IsExportable() const;
		void SetPoints(std::vector<Vec3> const &arg0, const float arg1);
		std::vector<Vec3> const &GetPoints() const;
		float GetHeight() const;
		AABB GetBounds() const;
		void AddLinkedPortal(const unsigned arg0);
		bool HasLinkedPortal(const unsigned arg0) const;
		std::vector<unsigned int> const &GetLinkedPortals() const;
#endif
		
		static inline auto FIsPointInside = PreyFunction<bool(CArkRoomVolumeManager::VolumeData const *const _this, Vec3 const &_p)>(0x147C8D0);
		static inline auto FRemoveLinkedPortal = PreyFunction<void(CArkRoomVolumeManager::VolumeData *const _this, const unsigned _portalId)>(0x147DCE0);
	};

	class PortalData // Id=80195F3 Size=96
	{
	public:
		enum class EPortalSide
		{
			top = 0,
			right = 1,
			bottom = 2,
			left = 3,
		};

		unsigned m_volumeId0;
		unsigned m_volumeId1;
		Vec3 m_center;
		std::array<Vec3,4> m_corners;
		float m_occlusion;
		float m_hazardOcclusion;
		const unsigned m_entityId;
		IArkRoomPortal *m_roomPortal;
		bool m_bExportable;
		
		void SetCorners(std::array<Vec3,4> const &_corners) { FSetCorners(this,_corners); }
		Vec3 GetNearestPoint(Vec3 const &_point) const { return FGetNearestPointOv1(this,_point); }
		Vec3 GetNearestPoint(Vec3 const &_startPoint, Vec3 const &_endPoint) const { return FGetNearestPointOv0(this,_startPoint,_endPoint); }
		Vec3 GetNearestPointOnSide(Vec3 const &_point) const { return FGetNearestPointOnSide(this,_point); }
		Vec3 GetClosestPointOnEdge(CArkRoomVolumeManager::PortalData::EPortalSide _side, Vec3 const &_point1, Vec3 const &_point2) const { return FGetClosestPointOnEdge(this,_side,_point1,_point2); }
		Vec3 GetClosestPointInPortal(Vec3 const &_pointOnPlane, Vec3 const &_point1, Vec3 const &_point2) const { return FGetClosestPointInPortal(this,_pointOnPlane,_point1,_point2); }
		
#if 0
		unsigned GetEntityId() const;
		IArkRoomPortal *GetRoomPortal() const;
		bool IsExportable() const;
		void SetExportable(bool arg0);
		void SetVolumeId0(const unsigned arg0);
		unsigned GetVolumeId0() const;
		void SetVolumeId1(const unsigned arg0);
		unsigned GetVolumeId1() const;
		unsigned GetOtherVolumeId(unsigned arg0) const;
		std::array<Vec3,4> const &GetCorners() const;
		Vec3 const &GetCenterPoint() const;
		float GetWidth() const;
		float GetHeight() const;
		Vec3 GetWidthDir() const;
		Vec3 GetHeightDir() const;
		Vec3 GetNormal() const;
		float GetShortestDistance(CArkRoomVolumeManager::PortalData const &arg0) const;
		float GetShortestDistance(Vec3 const &arg0) const;
		void SetOcclusion(const float arg0);
		float GetOcclusion() const;
		void SetHazardOcclusion(const float arg0);
		float GetHazardOcclusion() const;
		Lineseg_tpl<float> GetEdge(CArkRoomVolumeManager::PortalData::EPortalSide arg0) const;
#endif
		
		static inline auto FSetCorners = PreyFunction<void(CArkRoomVolumeManager::PortalData *const _this, std::array<Vec3,4> const &_corners)>(0x147E0C0);
		static inline auto FGetNearestPointOv1 = PreyFunction<Vec3(CArkRoomVolumeManager::PortalData const *const _this, Vec3 const &_point)>(0x147B880);
		static inline auto FGetNearestPointOv0 = PreyFunction<Vec3(CArkRoomVolumeManager::PortalData const *const _this, Vec3 const &_startPoint, Vec3 const &_endPoint)>(0x147B530);
		static inline auto FGetNearestPointOnSide = PreyFunction<Vec3(CArkRoomVolumeManager::PortalData const *const _this, Vec3 const &_point)>(0x147BB80);
		static inline auto FGetClosestPointOnEdge = PreyFunction<Vec3(CArkRoomVolumeManager::PortalData const *const _this, CArkRoomVolumeManager::PortalData::EPortalSide _side, Vec3 const &_point1, Vec3 const &_point2)>(0x147ADE0);
		static inline auto FGetClosestPointInPortal = PreyFunction<Vec3(CArkRoomVolumeManager::PortalData const *const _this, Vec3 const &_pointOnPlane, Vec3 const &_point1, Vec3 const &_point2)>(0x147AA00);
	};

	using VolumeDataMap = std::unordered_map<unsigned int,CArkRoomVolumeManager::VolumeData>;
	using PortalDataMap = std::unordered_map<unsigned int,CArkRoomVolumeManager::PortalData>;
	using ArkRoomPathMap = std::unordered_map<ArkRoomPathNodePair,ArkRoomPath>;
	
	volatile int64_t m_writeAccessThreadId;
	int64_t m_serviceThreadId;
	std::unordered_map<unsigned int,CArkRoomVolumeManager::VolumeData> m_volumes;
	std::unordered_map<unsigned int,CArkRoomVolumeManager::PortalData> m_portals;
	std::unordered_map<ArkRoomPathNodePair,ArkRoomPath> m_validPaths;
	std::unordered_multimap<unsigned int,CArkRoomVolumeManager::VolumeData const *,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,CArkRoomVolumeManager::VolumeData const *> > > m_octreeNodes;
	std::vector<unsigned int> m_validPortals;
	ICVar *m_pMaxDistance;
	ICVar *m_pDebugAINoise;
	ICVar *m_pDebugVolumeInfo;
	
	CArkRoomVolumeManager();
	virtual void AcquireWriteAccess(unsigned long _writeThreadId);
	virtual void ReleaseWriteAccess(unsigned long _writeThreadId);
	virtual void SetServiceThreadId(unsigned long _serviceThreadId);
	virtual void Load(const char *_filename);
	virtual void Reset();
	virtual void ClearComputedData();
	virtual float GetOcclusion(Vec3 const &_soundPos, Vec3 const &_listenerPos, float _maxDistance) const;
	virtual void Export(const char *_filename) const;
	virtual void RegisterVolume(unsigned _volumeId, IArkRoomVolume *_roomVolume);
	virtual void UnregisterVolume(unsigned _volumeId);
	virtual void RegisterPortal(unsigned _portalId, IArkRoomPortal *_roomPortal);
	virtual void UnregisterPortal(unsigned _portalId);
	virtual IArkRoomVolume *GetVolume(unsigned _entityId) const;
	virtual IArkRoomPortal *GetPortal(unsigned _entityId) const;
	virtual void SetRoomVolumePoints(unsigned _entityId, std::vector<Vec3> const &_points, float _height, bool _resetPortals);
	virtual void ResetRoomVolumePortals();
	virtual void SetRoomPortalCorners(unsigned _portalId, std::array<Vec3,4> const &_corners);
	virtual void ResetPortalRoomVolumes(unsigned _portalId);
	virtual void ComputeAudioPropagation();
	virtual unsigned GetVolumeAtPosition(Vec3 const &_position) const;
	virtual void ValidateAudioPropagationPaths(std::vector<std::pair<unsigned int,unsigned int>> &_invalidPathLinks) const;
	virtual void ValidatePortalVolumes(std::vector<std::pair<unsigned int,unsigned int>> &_invalidOverlaps) const;
	virtual int EnumerateCalculatedSoundPositions(Vec3 const &_soundPos, Vec3 const &_listenerPos, IArkRoomVolumeManager::SoundPositionVisitor &_visitor) const;
	void GetRoomVolumePoints(unsigned _volumeId, std::vector<Vec3> &_points, float &_height) const { FGetRoomVolumePoints(this,_volumeId,_points,_height); }
	void SetRoomVolumeExportable(unsigned _volumeId, bool _bExported) { FSetRoomVolumeExportable(this,_volumeId,_bExported); }
	void GetRoomPortalCorners(unsigned _portalId, std::array<Vec3,4> &_corners) const { FGetRoomPortalCorners(this,_portalId,_corners); }
	void SetRoomPortalExportable(unsigned _portalId, bool _bExported) { FSetRoomPortalExportable(this,_portalId,_bExported); }
	bool IsRoomPortalValid(unsigned _portalId) const { return FIsRoomPortalValid(this,_portalId); }
	bool SetRoomPortalOcclusion(unsigned _portalId, float _occlusion) { return FSetRoomPortalOcclusion(this,_portalId,_occlusion); }
	void SetRoomPortalHazardOcclusion(unsigned _portalId, float _occlusion) { FSetRoomPortalHazardOcclusion(this,_portalId,_occlusion); }
	boost::optional<float> GetDistance(Vec3 const &_startPos, Vec3 const &_endPos, float _maxDistance) const { return FGetDistance(this,_startPos,_endPos,_maxDistance); }
	std::pair<float,float> GetHazardInfo(Vec3 const &_start, Vec3 const &_end, float _maxDistance) const { return FGetHazardInfo(this,_start,_end,_maxDistance); }
	std::pair<float,float> GetDialogInfo(Vec3 const &_start, Vec3 const &_end, const float _maxDistance) const { return FGetDialogInfo(this,_start,_end,_maxDistance); }
	void ClearComputedDataInternal() { FClearComputedDataInternal(this); }
	CArkRoomVolumeManager::VolumeData const *FindVolume(unsigned _volumeId) const { return FFindVolume(this,_volumeId); }
	CArkRoomVolumeManager::PortalData const *FindPortal(unsigned _portalId) const { return FFindPortal(this,_portalId); }
	CArkRoomVolumeManager::VolumeData &GetOrCreateVolume(unsigned _volumeId) { return FGetOrCreateVolume(this,_volumeId); }
	CArkRoomVolumeManager::PortalData &GetOrCreatePortal(unsigned _portalId) { return FGetOrCreatePortal(this,_portalId); }
	bool IsPointInBothVolumes(unsigned _portalId, Vec3 const &_point) const { return FIsPointInBothVolumes(this,_portalId,_point); }
	bool IsPortalValid(CArkRoomVolumeManager::PortalData const &_portal) const { return FIsPortalValid(this,_portal); }
	bool DoesPortalOverlapVolume(CArkRoomVolumeManager::PortalData const &_portal, CArkRoomVolumeManager::VolumeData const &_volume) const { return FDoesPortalOverlapVolume(this,_portal,_volume); }
	void ResetPortalVolumes(CArkRoomVolumeManager::PortalData &_portal) { FResetPortalVolumes(this,_portal); }
	CArkRoomVolumeManager::VolumeData const *FindVolumeAtPoint(Vec3 const &_point) const { return FFindVolumeAtPoint(this,_point); }
	void BuildVolumeOctree() { FBuildVolumeOctree(this); }
	void AddVolumeToOctree(CArkRoomVolumeManager::VolumeData const *_volume) { FAddVolumeToOctree(this,_volume); }
	static void ExploreAudioPropagation_r(CArkRoomVolumeManager const &_roomVolumeManager, std::unordered_map<ArkRoomPathNodePair,ArkRoomPath> &_pathMap, ArkRoomPath &_currentPath, float _fMaxAudibleDistance, GeneratePropagationStats &_stats) { FExploreAudioPropagation_r(_roomVolumeManager,_pathMap,_currentPath,_fMaxAudibleDistance,_stats); }
	static void ComputeAudioCmd(IConsoleCmdArgs *__formal) { FComputeAudioCmd(__formal); }
	virtual ~CArkRoomVolumeManager();
	
#if 0
	bool CanSoundBeHeard(Vec3 const &arg0, Vec3 const &arg1, float arg2) const;
	bool HasWriteAccess() const;
	bool CanAccessData() const;
	bool IsServiceThread() const;
	bool AttemptLinkingPortalToVolume(CArkRoomVolumeManager::PortalData &arg0, CArkRoomVolumeManager::VolumeData const &arg1);
	bool HasValidVolumes() const;
	void RebuildValidPortals();
	bool AllPortalsValid() const;
	void GetOctreeLocation(Vec3 const &arg0, unsigned &arg1, unsigned &arg2, unsigned &arg3) const;
	bool DoesOctreeContainPoint(Vec3 const &arg0) const;
#endif
	
	static inline auto FAcquireWriteAccess = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned long _writeThreadId)>(0x1478D70);
	static inline auto FReleaseWriteAccess = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned long _writeThreadId)>(0x147DCD0);
	static inline auto FSetServiceThreadId = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned long _serviceThreadId)>(0x147E730);
	static inline auto FLoad = PreyFunction<void(CArkRoomVolumeManager *const _this, const char *_filename)>(0x147CD90);
	static inline auto FReset = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x147DD90);
	static inline auto FClearComputedData = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x1479290);
	static inline auto FGetOcclusion = PreyFunction<float(CArkRoomVolumeManager const *const _this, Vec3 const &_soundPos, Vec3 const &_listenerPos, float _maxDistance)>(0x147BEA0);
	static inline auto FExport = PreyFunction<void(CArkRoomVolumeManager const *const _this, const char *_filename)>(0x1479E20);
	static inline auto FRegisterVolume = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _volumeId, IArkRoomVolume *_roomVolume)>(0x147DBB0);
	static inline auto FUnregisterVolume = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _volumeId)>(0x147E820);
	static inline auto FRegisterPortal = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId, IArkRoomPortal *_roomPortal)>(0x147DA60);
	static inline auto FUnregisterPortal = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId)>(0x147E740);
	static inline auto FGetVolume = PreyFunction<IArkRoomVolume *(CArkRoomVolumeManager const *const _this, unsigned _entityId)>(0x147C740);
	static inline auto FGetPortal = PreyFunction<IArkRoomPortal *(CArkRoomVolumeManager const *const _this, unsigned _entityId)>(0x147C470);
	static inline auto FSetRoomVolumePoints = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _entityId, std::vector<Vec3> const &_points, float _height, bool _resetPortals)>(0x147E600);
	static inline auto FResetRoomVolumePortals = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x147E060);
	static inline auto FSetRoomPortalCorners = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId, std::array<Vec3,4> const &_corners)>(0x147E180);
	static inline auto FResetPortalRoomVolumes = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId)>(0x147DE00);
	static inline auto FComputeAudioPropagation = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x14793D0);
	static inline auto FGetVolumeAtPosition = PreyFunction<unsigned(CArkRoomVolumeManager const *const _this, Vec3 const &_position)>(0x147C820);
	static inline auto FValidateAudioPropagationPaths = PreyFunction<void(CArkRoomVolumeManager const *const _this, std::vector<std::pair<unsigned int,unsigned int>> &_invalidPathLinks)>(0x147E860);
	static inline auto FValidatePortalVolumes = PreyFunction<void(CArkRoomVolumeManager const *const _this, std::vector<std::pair<unsigned int,unsigned int>> &_invalidOverlaps)>(0x147E930);
	static inline auto FEnumerateCalculatedSoundPositions = PreyFunction<int(CArkRoomVolumeManager const *const _this, Vec3 const &_soundPos, Vec3 const &_listenerPos, IArkRoomVolumeManager::SoundPositionVisitor &_visitor)>(0x1479990);
	static inline auto FGetRoomVolumePoints = PreyFunction<void(CArkRoomVolumeManager const *const _this, unsigned _volumeId, std::vector<Vec3> &_points, float &_height)>(0x147C640);
	static inline auto FSetRoomVolumeExportable = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _volumeId, bool _bExported)>(0x147E520);
	static inline auto FGetRoomPortalCorners = PreyFunction<void(CArkRoomVolumeManager const *const _this, unsigned _portalId, std::array<Vec3,4> &_corners)>(0x147C550);
	static inline auto FSetRoomPortalExportable = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId, bool _bExported)>(0x147E270);
	static inline auto FIsRoomPortalValid = PreyFunction<bool(CArkRoomVolumeManager const *const _this, unsigned _portalId)>(0x147CCA0);
	static inline auto FSetRoomPortalOcclusion = PreyFunction<bool(CArkRoomVolumeManager *const _this, unsigned _portalId, float _occlusion)>(0x147E430);
	static inline auto FSetRoomPortalHazardOcclusion = PreyFunction<void(CArkRoomVolumeManager *const _this, unsigned _portalId, float _occlusion)>(0x147E350);
	static inline auto FGetDistance = PreyFunction<boost::optional<float>(CArkRoomVolumeManager const *const _this, Vec3 const &_startPos, Vec3 const &_endPos, float _maxDistance)>(0x147B210);
	static inline auto FGetHazardInfo = PreyFunction<std::pair<float,float>(CArkRoomVolumeManager const *const _this, Vec3 const &_start, Vec3 const &_end, float _maxDistance)>(0x147B4F0);
	static inline auto FGetDialogInfo = PreyFunction<std::pair<float,float>(CArkRoomVolumeManager const *const _this, Vec3 const &_start, Vec3 const &_end, const float _maxDistance)>(0x147B1D0);
	static inline auto FClearComputedDataInternal = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x14792D0);
	static inline auto FFindVolume = PreyFunction<CArkRoomVolumeManager::VolumeData const *(CArkRoomVolumeManager const *const _this, unsigned _volumeId)>(0x147A680);
	static inline auto FFindPortal = PreyFunction<CArkRoomVolumeManager::PortalData const *(CArkRoomVolumeManager const *const _this, unsigned _portalId)>(0x147A5C0);
	static inline auto FGetOrCreateVolume = PreyFunction<CArkRoomVolumeManager::VolumeData &(CArkRoomVolumeManager *const _this, unsigned _volumeId)>(0x147C2C0);
	static inline auto FGetOrCreatePortal = PreyFunction<CArkRoomVolumeManager::PortalData &(CArkRoomVolumeManager *const _this, unsigned _portalId)>(0x147C100);
	static inline auto FIsPointInBothVolumes = PreyFunction<bool(CArkRoomVolumeManager const *const _this, unsigned _portalId, Vec3 const &_point)>(0x147C840);
	static inline auto FIsPortalValid = PreyFunction<bool(CArkRoomVolumeManager const *const _this, CArkRoomVolumeManager::PortalData const &_portal)>(0x147CC40);
	static inline auto FDoesPortalOverlapVolume = PreyFunction<bool(CArkRoomVolumeManager const *const _this, CArkRoomVolumeManager::PortalData const &_portal, CArkRoomVolumeManager::VolumeData const &_volume)>(0x1479610);
	static inline auto FResetPortalVolumes = PreyFunction<void(CArkRoomVolumeManager *const _this, CArkRoomVolumeManager::PortalData &_portal)>(0x147DED0);
	static inline auto FFindVolumeAtPoint = PreyFunction<CArkRoomVolumeManager::VolumeData const *(CArkRoomVolumeManager const *const _this, Vec3 const &_point)>(0x147A740);
	static inline auto FBuildVolumeOctree = PreyFunction<void(CArkRoomVolumeManager *const _this)>(0x14791F0);
	static inline auto FAddVolumeToOctree = PreyFunction<void(CArkRoomVolumeManager *const _this, CArkRoomVolumeManager::VolumeData const *_volume)>(0x1478D80);
	static inline auto FExploreAudioPropagation_r = PreyFunction<void(CArkRoomVolumeManager const &_roomVolumeManager, std::unordered_map<ArkRoomPathNodePair,ArkRoomPath> &_pathMap, ArkRoomPath &_currentPath, float _fMaxAudibleDistance, GeneratePropagationStats &_stats)>(0x1479C20);
	static inline auto FComputeAudioCmd = PreyFunction<void(IConsoleCmdArgs *__formal)>(0x1479360);
};

