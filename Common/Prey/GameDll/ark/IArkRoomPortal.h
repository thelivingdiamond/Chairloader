// Header file automatically created from a PDB.
#pragma once

// IArkRoomPortal
// Header:  _unknown/IArkRoomPortal.h
class IArkRoomPortal
{ // Size=8 (0x8)
public:
	virtual void SetOcclusion(float _occlusion) = 0;
	virtual float GetOcclusion() const = 0;
	virtual void SetHazardOcclusion(float _occlusion) = 0;
	virtual float GetHazardOcclusion() const = 0;
	virtual const std::array<Vec3, 4>& GetCorners() const = 0;
	virtual void SetCorners(const std::array<Vec3, 4>& _corners) = 0;
	virtual bool IsValid() const = 0;
	virtual void SetExportable(bool _bExportable) = 0;
	virtual const char* GetName() const = 0;
	virtual ~IArkRoomPortal();
};

