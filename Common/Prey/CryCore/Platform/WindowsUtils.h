// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once
#if CRY_PLATFORM_WINDOWS
	#include "CryWindows.h"

//! Converts an error code from winerror.h (e.g. returned by GetLastError() or from Detours)
//! into a string.
//! @param	errorMessageID	The error code.
//! @returns an English string or empty string if no error.
inline std::string WindowsErrorToString(DWORD errorMessageID)
{
	// Based on:
	// https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror

	if (errorMessageID == 0) {
		return std::string(); //No error message has been recorded
	}

	LPSTR messageBuffer = nullptr;

	// Ask Win32 to give us the string version of that message ID.
	// The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
	size_t size = FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, // dwFlags
		NULL, // lpSource
		errorMessageID, // dwMessageId
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), // dwLanguageId
		(LPSTR)&messageBuffer, // lpBuffer
		0, // nSize
		NULL // Arguments
	);

	// Copy the error message into a std::string.
	std::string message(messageBuffer, size);

	// Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return message;
}

#if 0
	#include <CryRenderer/IRenderer.h>
	#include <CryRenderer/IImage.h>
	#include <CryCore/smartptr.h>
	#include <Cry3DEngine/ImageExtensionHelper.h>

//! Types supported by CreateResourceFromTexture.
enum EResourceType
{
	eResourceType_IconBig,
	eResourceType_IconSmall,
	eResourceType_Cursor,
};

//! Loads a (DDS) texture resource from the renderer into a Win32 GDI resource.
//! \return HICON that must be closed with DestroyIcon(), or NULL on failure.
static HICON CreateResourceFromTexture(IRenderer* pRenderer, const char* path, EResourceType type)
{
	if (!pRenderer || !path || !*path)
	{
		// Invalid parameter passed
		return NULL;
	}

	// Find the target dimensions of the GDI resource
	const int nRequestedWidth = GetSystemMetrics(type == eResourceType_IconBig ? SM_CXICON : type == eResourceType_IconSmall ? SM_CXSMICON : SM_CXCURSOR);
	const int nRequestedHeight = GetSystemMetrics(type == eResourceType_IconBig ? SM_CYICON : type == eResourceType_IconSmall ? SM_CYSMICON : SM_CYCURSOR);
	if (nRequestedWidth != nRequestedHeight || nRequestedHeight <= 0 || nRequestedWidth <= 0)
	{
		// Don't support non-squares icons or cursors
		return NULL;
	}

	// Load texture
	_smart_ptr<IImageFile> pImage = pRenderer->EF_LoadImage(path, 0);
	if (!pImage || pImage->mfGet_depth() != 1 || pImage->mfGet_NumSides() != 1 || pImage->mfGetTileMode() != eTM_None)
	{
		// Can't load texture, or texture is a cube-map or volume texture, or uses tiling of some kind
		return NULL;
	}
	byte* pImgRaw = pImage->mfGet_image(0);
	const ETEX_Format texFormat = pImage->mfGetFormat();

	// Pick first mip level smaller than the GDI resource
	int nMip = 0;
	size_t offset = 0;
	int nMipWidth = pImage->mfGet_width();
	int nMipHeight = pImage->mfGet_height();
	while (nMipWidth > nRequestedWidth)
	{
		++nMip;
		offset += pRenderer->GetTextureFormatDataSize(nMipWidth, nMipHeight, 1, 1, texFormat);
		nMipWidth = max(nMipWidth / 2, 1);
		nMipHeight = max(nMipHeight / 2, 1);
	}
	pImgRaw += offset;
	if (nMip >= pImage->mfGet_numMips())
	{
		// No appropriate mip in the texture
		// Note: Consider creating a full mip-chain on the texture so this can't happen
		return NULL;
	}
	const size_t nRawSize = pRenderer->GetTextureFormatDataSize(nMipWidth, nMipHeight, 1, 1, texFormat);

	#if 0
	// Check that DDS indexing is correct here
	offset += nRawSize;
	for (int nIdx = nMip + 1; nIdx < pImage->mfGet_numMips(); ++nIdx)
	{
		const int w = max(nMipWidth >> (nIdx - nMip), 1);
		const int h = max(nMipHeight >> (nIdx - nMip), 1);
		offset += pRenderer->GetTextureFormatDataSize(w, h, 1, 1, texFormat);
	}
	assert(offset == pImage->mfGet_ImageSize());
	#endif

	// Type of bitmap to create
	BITMAPV5HEADER bi = { 0 };
	bi.bV5Size = sizeof(BITMAPV5HEADER);
	bi.bV5Width = nRequestedWidth;
	bi.bV5Height = -nRequestedHeight;
	bi.bV5Planes = 1;
	bi.bV5BitCount = 32;
	bi.bV5Compression = BI_BITFIELDS;
	// The following mask specification specifies a supported 32 BPP alpha format for Windows XP+
	bi.bV5AlphaMask = 0xFF000000;
	bi.bV5RedMask = 0x00FF0000;
	bi.bV5GreenMask = 0x0000FF00;
	bi.bV5BlueMask = 0x000000FF;

	// Create the DIB section with an alpha channel
	const HDC hdc = GetDC(NULL);
	void* lpBits;
	const HBITMAP hBitmap = CreateDIBSection(hdc, (BITMAPINFO*)&bi, DIB_RGB_COLORS, &lpBits, NULL, 0);
	ReleaseDC(NULL, hdc);
	if (!hBitmap || !lpBits)
	{
		// Can't allocate OS bitmap
		return NULL;
	}
	GdiFlush();

	// Decompress texture
	const bool bTryDecompress = texFormat != eTF_R8G8B8A8 && texFormat != eTF_B8G8R8A8 && texFormat != eTF_B8G8R8X8;
	byte* const pImgDecomp = bTryDecompress ? new byte[nMipWidth * nMipHeight * sizeof(int32)] : pImgRaw;
	const bool bImgDecompressed = bTryDecompress && pRenderer->DXTDecompress(pImgRaw, nRawSize, pImgDecomp, nMipWidth, nMipHeight, 1, texFormat, false, sizeof(int32));

	// Check which conversions need to be performed
	const bool bSRGB = (pImage->mfGet_Flags() & FIM_SRGB_READ) != 0;
	const bool bSwap = (texFormat == eTF_R8G8B8A8) || bTryDecompress;

	HICON result = NULL;
	if (!bTryDecompress || bImgDecompressed)
	{
		// Assign texture data with mismatching sizes
		// Note: Any pixels not in the selected mip will become 100% transparent black, no resizing is performed
		const size_t sourceRowStride = nMipWidth;
		const size_t targetRowStride = nRequestedWidth;
		const uint32* pSourceRow = (uint32*)pImgDecomp;
		uint32* pTargetRow = (uint32*)lpBits;

		assert(sourceRowStride <= targetRowStride);
		assert(nMipHeight <= nRequestedHeight);
		assert(pSourceRow != pTargetRow);
		assert(pSourceRow && pTargetRow);

		uint8 gammaTable[256];
		if (!bSRGB)
		{
			// Linear to sRGB table
			const float gamma = 1.0f / 2.2f;
			const float gammaMultiplier = 255.0f / powf(255.0f, gamma);
			for (int i = 0; i < 256; ++i)
			{
				gammaTable[i] = uint8(powf(float(i), gamma) * gammaMultiplier);
			}
		}
		else if (bSwap)
		{
			// sRGB to sRGB table (no change)
			for (int i = 0; i < 256; ++i)
			{
				gammaTable[i] = uint8(i);
			}
		}

		for (int y = 0; y < nMipHeight; ++y, pSourceRow += sourceRowStride, pTargetRow += targetRowStride)
		{
			if (!bSwap && bSRGB)
			{
				memcpy(pTargetRow, pSourceRow, sourceRowStride * sizeof(uint32));
			}
			else
			{
				const uint32* pSourceTexel = pSourceRow;
				uint32* pTargetTexel = pTargetRow;
				for (int x = 0; x < nMipWidth; ++x, ++pSourceTexel, ++pTargetTexel)
				{
					const uint8 red = gammaTable[uint8(*pSourceTexel >> 0)];
					const uint8 green = gammaTable[uint8(*pSourceTexel >> 8)];
					const uint8 blue = gammaTable[uint8(*pSourceTexel >> 16)];
					const uint32 alpha = *pSourceTexel & 0xFF000000;
					*pTargetTexel = (red << (bSwap ? 16 : 0)) | (green << 8) | (blue << (bSwap ? 0 : 16)) | alpha;
				}
			}

			// Fill remaining columns with zeros
			memset(pTargetRow + sourceRowStride, 0, (targetRowStride - sourceRowStride) * sizeof(uint32));
		}

		// Fill remaining rows with zeros
		for (int y = nMipHeight; y < nRequestedHeight; ++y)
		{
			memset(pTargetRow, 0, targetRowStride * sizeof(uint32));
			pTargetRow += targetRowStride;
		}

		// Convert to GDI icon
		ICONINFO iconinfo = { 0 };
		iconinfo.fIcon = type == eResourceType_Cursor ? FALSE : TRUE;
		iconinfo.hbmMask = ::CreateBitmap(nRequestedWidth, nRequestedHeight, 1, 1, NULL);
		iconinfo.hbmColor = hBitmap;
		result = ::CreateIconIndirect(&iconinfo);
		DeleteObject(iconinfo.hbmMask);
	}

	// Clean up
	DeleteObject(hBitmap);
	if (bTryDecompress)
	{
		delete[] pImgDecomp;
	}
	pImage.reset();

	return result;
}
#endif
#endif
