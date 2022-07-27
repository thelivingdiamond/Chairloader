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

