#pragma once
#include "CryDX.h"
#include <Prey/CryRenderer/ITexture.h>
#include <Prey/RenderDll/Common/CommonRender.h>
#include <ChairLoader/PreyFunction.h>
#include <mem.h>

class CDeviceTexture;
class CTexture;

struct SResourceView
{
	typedef uint64 KeyType;

	static const KeyType DefaultView = (KeyType)-1LL;
	static const KeyType DefaultViewMS = (KeyType)-2LL;
	static const KeyType DefaultViewSRGB = (KeyType)-3LL;
	static const KeyType DefaultRendertargetView = (KeyType)-4LL;
	static const KeyType DefaultDepthStencilView = (KeyType)-5LL;
	static const KeyType DefaultUnordererdAccessView = (KeyType)-6LL;

	enum ResourceViewType
	{
		eShaderResourceView = 0,
		eRenderTargetView,
		eDepthStencilView,
		eUnorderedAccessView,

		eNumResourceViews
	};

	enum ResourceViewFlags
	{
		eSRV_DepthOnly = 0,
		eSRV_StencilOnly = 1,

		eDSV_ReadWrite = 0,
		eDSV_ReadOnly = 1,

		eUAV_WriteOnly = 0,
		eUAV_ReadWrite = 1,
	};

	union ResourceViewDesc
	{
		struct
		{
			uint64 nDefaultMarker : 1;
			uint64 eViewType : 3;
			uint64 nFormat : 6;
			uint64 nFirstSlice : 11;
			uint64 nSliceCount : 11;
			uint64 nMostDetailedMip : 4;
			uint64 nMipCount : 4;
			uint64 bSrgbRead : 1;
			uint64 bMultisample : 1;
			uint64 nFlags : 2;
			uint64 nUnused : 19;
		};

		KeyType Key;
	};

	SResourceView(uint64 nKey = DefaultView) {
		static_assert(sizeof(m_Desc) <= sizeof(KeyType));

		m_Desc.Key = nKey;
		m_pDeviceResourceView = NULL;
	}

	static SResourceView ShaderResourceView(ETEX_Format nFormat, int nFirstSlice = 0, int nSliceCount = -1, int nMostDetailedMip = 0, int nMipCount = -1, bool bSrgbRead = false, bool bMultisample = false, int nFlags = 0) {
		return FShaderResourceView(nFormat, nFirstSlice, nSliceCount, nMostDetailedMip, nMipCount, bSrgbRead, bMultisample, nFlags);
	}

	static SResourceView RenderTargetView(ETEX_Format nFormat, int nFirstSlice = 0, int nSliceCount = -1, int nMipLevel = 0, bool bMultisample = false) {
		return FRenderTargetView(nFormat, nFirstSlice, nSliceCount, nMipLevel, bMultisample);
	}

	/*static SResourceView DepthStencilView(ETEX_Format nFormat, int nFirstSlice = 0, int nSliceCount = -1, int nMipLevel = 0, bool bMultisample = false, int nFlags = 0) {
		return FDepthStencilView(nFormat, nFirstSlice, nSliceCount, nMipLevel, bMultisample, nFlags);
	}

	static SResourceView UnorderedAccessView(ETEX_Format nFormat, int nFirstSlice = 0, int nSliceCount = -1, int nMipLevel = 0, int nFlags = 0) {
		return FUnorderedAccessView(nFormat, nFirstSlice, nSliceCount, nMipLevel, nFlags);
	}*/


	static bool          IsDefaultView(KeyType key) { return key < 0LL; }
	static bool          IsShaderResourceView(KeyType key) { return key == DefaultView || key == DefaultViewMS || key == DefaultViewSRGB || SResourceView(key).m_Desc.eViewType == eShaderResourceView; }
	static bool          IsRenderTargetView(KeyType key) { return key == DefaultRendertargetView || SResourceView(key).m_Desc.eViewType == eRenderTargetView; }
	static bool          IsDepthStencilView(KeyType key) { return key == DefaultDepthStencilView || SResourceView(key).m_Desc.eViewType == eDepthStencilView; }
	static bool          IsUnorderedAccessView(KeyType key) { return key == DefaultUnordererdAccessView || SResourceView(key).m_Desc.eViewType == eUnorderedAccessView; }

	bool                 operator==(const SResourceView &other) const {
		return m_Desc.Key == other.m_Desc.Key;
	}

	ResourceViewDesc m_Desc;
	void *m_pDeviceResourceView;

	static inline auto FShaderResourceView = PreyFunction<SResourceView(
		ETEX_Format nFormat, int nFirstSlice, int nSliceCount, int nMostDetailedMip,
		int nMipCount, bool bSrgbRead, bool bMultisample, int nFlags)>(0xFE6A40);
	static inline auto FRenderTargetView = PreyFunction<SResourceView(
		ETEX_Format nFormat, int nFirstSlice, int nSliceCount, int nMipLevel, bool bMultisample)>(0xFE6550);
};
