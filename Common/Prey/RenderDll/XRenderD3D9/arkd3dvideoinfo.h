// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkVideoInfo
{
	void* pad[80 / sizeof(void*)];
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/IArkVideoInfo.h>
#include <_unknown/SDisplayFormat.h>
#include <_unknown/SDisplayInfo.h>
#include <_unknown/SVideoCardInfo.h>

struct SAAFormat;

// ArkVideoInfo
// Header:  CryEngine/renderdll/xrenderd3d9/arkd3dvideoinfo.h
class ArkVideoInfo : public IArkVideoInfo
{ // Size=80 (0x50)
public:
	std::vector<SVideoCardInfo> m_videoCards;
	std::vector<SDisplayInfo> m_displays;
	std::vector<std::vector<SDisplayFormat>> m_displayFormats;

	ArkVideoInfo();
	void Init() { FInit(this); }
	void Refresh() { FRefresh(this); }
	virtual const std::vector<SVideoCardInfo>& GetVideoCardInfos() const;
	virtual const std::vector<SDisplayInfo>& GetDisplayInfos() const;
	virtual const std::vector<SDisplayFormat>& GetDisplayFormats(int _displayIndex) const;
	bool GetDisplayDefaultDimensions(int _index, Vec2i& _dimensions) { return FGetDisplayDefaultDimensions(this, _index, _dimensions); }

#if 0
	int EnumAAFormats(SAAFormat* _arg0_);
#endif

	static inline auto FArkVideoInfoOv2 = PreyFunction<void(ArkVideoInfo* const _this)>(0xEED750);
	static inline auto FInit = PreyFunction<void(ArkVideoInfo* const _this)>(0xEED840);
	static inline auto FRefresh = PreyFunction<void(ArkVideoInfo* const _this)>(0xEED850);
	static inline auto FGetVideoCardInfos = PreyFunction<const std::vector<SVideoCardInfo>& (const ArkVideoInfo* const _this)>(0x133BA60);
	static inline auto FGetDisplayInfos = PreyFunction<const std::vector<SDisplayInfo>& (const ArkVideoInfo* const _this)>(0x10ED430);
	static inline auto FGetDisplayFormats = PreyFunction<const std::vector<SDisplayFormat>& (const ArkVideoInfo* const _this, int _displayIndex)>(0xEED7F0);
	static inline auto FGetDisplayDefaultDimensions = PreyFunction<bool(ArkVideoInfo* const _this, int _index, Vec2i& _dimensions)>(0xEED790);
};
#endif // !MOONCRASH
