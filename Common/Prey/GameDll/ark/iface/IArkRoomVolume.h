// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkRoomVolume.h
class IArkRoomVolume // Id=80021B5 Size=8
{
public:
	virtual bool IsPointInside(Vec3 const &arg0) const = 0;
	virtual void SetPoints(std::vector<Vec3> const &arg0, float arg1, bool arg2) = 0;
	virtual void SetExportable(bool arg0) = 0;
	virtual const char *GetName() const = 0;
	virtual ~IArkRoomVolume();
};

