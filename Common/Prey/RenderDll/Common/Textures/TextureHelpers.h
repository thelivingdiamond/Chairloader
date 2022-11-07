// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:   TextureHelpers.h
//  Version:     v1.00
//  Created:     12/6/2014 by NielsF.
//  Compilers:   Visual Studio 2012
//  Description:
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////

#ifndef __TextureHelpers_h__
#define __TextureHelpers_h__
#pragma once

#include "Texture.h"

namespace TextureHelpers
{
inline auto FFindTexSlot = PreyFunction<EEfResTextures(const char* texSemantic)>(0xED2B00);
inline auto FVerifyTexSuffixOv1 = PreyFunction<bool(EEfResTextures texSlot, const char* texPath)>(0xED2C40);
inline auto FVerifyTexSuffixOv2 = PreyFunction<bool(EEfResTextures texSlot, const string& texPath)>(0xED2BF0);
inline auto FLookupTexPriority = PreyFunction<int8(EEfResTextures texSlot)>(0xED2BD0);
inline auto FLookupTexDefault = PreyFunction<CTexture* (EEfResTextures texSlot)>(0xED2BB0);
//////////////////////////////////////////////////////////////////////////
EEfResTextures FindTexSlot(const char* texSemantic) { return FFindTexSlot(texSemantic); }
bool           VerifyTexSuffix(EEfResTextures texSlot, const char* texPath) { return FVerifyTexSuffixOv1(texSlot, texPath); }
bool           VerifyTexSuffix(EEfResTextures texSlot, const string& texPath) { return FVerifyTexSuffixOv2(texSlot, texPath); }
//const char*    LookupTexSuffix(EEfResTextures texSlot);
int8           LookupTexPriority(EEfResTextures texSlot) { return FLookupTexPriority(texSlot); }
CTexture*      LookupTexDefault(EEfResTextures texSlot) { return FLookupTexDefault(texSlot); }
//CTexture*      LookupTexNeutral(EEfResTextures texSlot);
}

#endif
