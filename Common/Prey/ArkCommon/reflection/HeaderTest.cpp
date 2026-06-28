// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/ArkCommon/reflection/ArkProperty.h
#include "ArkProperty.h"
static_assert(sizeof(ArkProperty) == 32);

#include "ArkReflectedLibrary.h"
static_assert(sizeof(ArkReflectedLibrary) == 8);

#include "ArkReflectedObject.h"
static_assert(sizeof(ArkReflectedObject) == 1);

#include "IArkValueBase.h"
static_assert(sizeof(IArkValueBase) == 8);

#include "XMLObjectReader.h"
static_assert(sizeof(XMLObjectReader) == 8);
#else // MOONCRASH
// Header test file for path Prey/ArkCommon/reflection/
#include "ArkClass.h"
static_assert(sizeof(ArkClass) == 88);
static_assert(sizeof(ArkValue<CCryName>) == 16);
static_assert(sizeof(ArkValue<CryStringT<char> >) == 16);
static_assert(sizeof(ArkValue<Vec2_tpl<float> >) == 16);
static_assert(sizeof(ArkValue<Vec3_tpl<float> >) == 24);
static_assert(sizeof(ArkValue<bool>) == 16);
static_assert(sizeof(ArkValue<float>) == 16);

#include "ArkProperty.h"
static_assert(sizeof(ArkProperty) == 32);

#include "ArkReflectedLibrary.h"
static_assert(sizeof(ArkReflectedLibrary) == 8);

#include "ArkReflectedObject.h"
static_assert(sizeof(ArkReflectedObject) == 1);

#include "IArkValueBase.h"
static_assert(sizeof(IArkValueBase) == 8);

#include "XMLObjectReader.h"
static_assert(sizeof(XMLObjectReader) == 8);
#endif // !MOONCRASH
