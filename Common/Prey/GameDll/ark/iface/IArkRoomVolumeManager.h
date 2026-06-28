// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class IArkRoomPortal;
class IArkRoomVolume;

// Header: Override
// Prey/GameDll/ark/iface/IArkRoomVolumeManager.h
class IArkRoomVolumeManager // Id=80021B3 Size=8
{
public:
	class SoundPositionVisitor // Id=80021B4 Size=8
	{
	public:
		virtual void operator()(Vec3 const &arg0, float arg1, float arg2) = 0;
	};

	using InvalidPathLinksVector = std::vector<std::pair<unsigned int,unsigned int>>;
	using InvalidPortalVolumeOverlaps = std::vector<std::pair<unsigned int,unsigned int>>;
	
	virtual ~IArkRoomVolumeManager();
	virtual void AcquireWriteAccess(unsigned long arg0) = 0;
	virtual void ReleaseWriteAccess(unsigned long arg0) = 0;
	virtual void SetServiceThreadId(unsigned long arg0) = 0;
	virtual void Load(const char *arg0) = 0;
	virtual void Reset() = 0;
	virtual void ClearComputedData() = 0;
	virtual float GetOcclusion(Vec3 const &arg0, Vec3 const &arg1, float arg2) const = 0;
	virtual void Export(const char *arg0) const = 0;
	virtual void RegisterVolume(unsigned arg0, IArkRoomVolume *arg1) = 0;
	virtual void UnregisterVolume(unsigned arg0) = 0;
	virtual void RegisterPortal(unsigned arg0, IArkRoomPortal *arg1) = 0;
	virtual void UnregisterPortal(unsigned arg0) = 0;
	virtual IArkRoomVolume *GetVolume(unsigned arg0) const = 0;
	virtual IArkRoomPortal *GetPortal(unsigned arg0) const = 0;
	virtual void SetRoomVolumePoints(unsigned arg0, std::vector<Vec3> const &arg1, float arg2, bool arg3) = 0;
	virtual void ResetRoomVolumePortals() = 0;
	virtual void SetRoomPortalCorners(unsigned arg0, std::array<Vec3,4> const &arg1) = 0;
	virtual void ResetPortalRoomVolumes(unsigned arg0) = 0;
	virtual void ComputeAudioPropagation() = 0;
	virtual unsigned GetVolumeAtPosition(Vec3 const &arg0) const = 0;
	virtual void ValidateAudioPropagationPaths(std::vector<std::pair<unsigned int,unsigned int>> &arg0) const = 0;
	virtual void ValidatePortalVolumes(std::vector<std::pair<unsigned int,unsigned int>> &arg0) const = 0;
	virtual int EnumerateCalculatedSoundPositions(Vec3 const &arg0, Vec3 const &arg1, IArkRoomVolumeManager::SoundPositionVisitor &arg2) const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class IArkRoomPortal;
class IArkRoomVolume;

// IArkRoomVolumeManager
// Header:  Prey/GameDll/ark/iface/IArkRoomVolumeManager.h
class IArkRoomVolumeManager
{ // Size=8 (0x8)
public:
	// IArkRoomVolumeManager::SoundPositionVisitor
	// Header:  Prey/GameDll/ark/iface/IArkRoomVolumeManager.h
	class SoundPositionVisitor
	{ // Size=8 (0x8)
	public:
		virtual void operator()(const Vec3& _arg0_, float _arg1_, float _arg2_) = 0;
	};

	using InvalidPathLinksVector = std::vector<std::pair<unsigned int, unsigned int>>;
	using InvalidPortalVolumeOverlaps = std::vector<std::pair<unsigned int, unsigned int>>;

	virtual ~IArkRoomVolumeManager();
	virtual void AcquireWriteAccess(unsigned long _writeThreadId) = 0;
	virtual void ReleaseWriteAccess(unsigned long _writeThreadId) = 0;
	virtual void SetServiceThreadId(unsigned long _serviceThreadId) = 0;
	virtual void Load(const char* _filename) = 0;
	virtual void Reset() = 0;
	virtual void ClearComputedData() = 0;
	virtual float GetOcclusion(const Vec3& _soundPos, const Vec3& _listenerPos, float _maxDistance) const = 0;
	virtual void Export(const char* _filename) const = 0;
	virtual void RegisterVolume(unsigned _volumeId, IArkRoomVolume* _roomVolume) = 0;
	virtual void UnregisterVolume(unsigned _volumeId) = 0;
	virtual void RegisterPortal(unsigned _portalId, IArkRoomPortal* _roomPortal) = 0;
	virtual void UnregisterPortal(unsigned _portalId) = 0;
	virtual IArkRoomVolume* GetVolume(unsigned _entityId) const = 0;
	virtual IArkRoomPortal* GetPortal(unsigned _entityId) const = 0;
	virtual void SetRoomVolumePoints(unsigned _entityId, const std::vector<Vec3>& _points, float _height, bool _resetPortals) = 0;
	virtual void ResetRoomVolumePortals() = 0;
	virtual void SetRoomPortalCorners(unsigned _portalId, const std::array<Vec3, 4>& _corners) = 0;
	virtual void ResetPortalRoomVolumes(unsigned _portalId) = 0;
	virtual void ComputeAudioPropagation() = 0;
	virtual unsigned GetVolumeAtPosition(const Vec3& _position) const = 0;
	virtual void ValidateAudioPropagationPaths(std::vector<std::pair<unsigned int, unsigned int>>& _invalidPathLinks) const = 0;
	virtual void ValidatePortalVolumes(std::vector<std::pair<unsigned int, unsigned int>>& _invalidOverlaps) const = 0;
	virtual int EnumerateCalculatedSoundPositions(const Vec3& _soundPos, const Vec3& _listenerPos, IArkRoomVolumeManager::SoundPositionVisitor& _visitor) const = 0;
};
#endif // !MOONCRASH
