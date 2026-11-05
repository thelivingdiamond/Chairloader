// Header file automatically created from a PDB.
#pragma once

enum EZLibFlush;
enum EZLibMethod;
enum EZLibStrategy;
struct IZLibDeflateStream;
struct SMD5Context;

// IZLibCompressor
// Header:  _unknown/IZLibCompressor.h
// Include: Prey/CrySystem/ZLib/IZLibCompressor.h
struct IZLibCompressor
{ // Size=8 (0x8)
	virtual ~IZLibCompressor();
	virtual IZLibDeflateStream* CreateDeflateStream(int inLevel, EZLibMethod inMethod, int inWindowBits, int inMemLevel, EZLibStrategy inStrategy, EZLibFlush inFlushMethod) = 0;
	virtual void Release() = 0;
	virtual void MD5Init(SMD5Context* pIOCtx) = 0;
	virtual void MD5Update(SMD5Context* pIOCtx, const char* pInBuff, unsigned len) = 0;
	virtual void MD5Final(SMD5Context* pIOCtx, char* outDigest) = 0;
};

