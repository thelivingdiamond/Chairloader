// Header file automatically created from a PDB.

#pragma once

#include <vector>

struct SVideoCardInfo;
struct SDisplayInfo;
struct SDisplayFormat;

// IArkVideoInfo
// Header:  _unknown/IArkVideoInfo.h
struct IArkVideoInfo
{ // Size=8 (0x8)
	virtual const std::vector<SVideoCardInfo>& GetVideoCardInfos() const = 0;
	virtual const std::vector<SDisplayInfo>& GetDisplayInfos() const = 0;
	virtual const std::vector<SDisplayFormat>& GetDisplayFormats(int _displayIndex) const = 0;
};

// ArkVideoInfo
// Header:  CryEngine/renderdll/xrenderd3d9/arkd3dvideoinfo.h
class ArkVideoInfo : public IArkVideoInfo
{ // Size=80 (0x50)
public:
	// m_videoCards, m_displays, m_displayFormats (three std::vectors, element types not ported)
	void* pad[72 / sizeof(void*)];

	virtual const std::vector<SVideoCardInfo>& GetVideoCardInfos() const;
	virtual const std::vector<SDisplayInfo>& GetDisplayInfos() const;
	virtual const std::vector<SDisplayFormat>& GetDisplayFormats(int _displayIndex) const;
};

static_assert(sizeof(ArkVideoInfo) == 80);
