// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkRoomVolume
// Header:  Prey/GameDll/ark/iface/IArkRoomVolume.h
class IArkRoomVolume
{ // Size=8 (0x8)
public:
	virtual bool IsPointInside(const Vec3& _point) const = 0;
	virtual void SetPoints(const std::vector<Vec3>& _points, float _height, bool _resetPoints) = 0;
	virtual void SetExportable(bool _bExported) = 0;
	virtual const char* GetName() const = 0;
	virtual ~IArkRoomVolume();
};
#endif // !MOONCRASH
