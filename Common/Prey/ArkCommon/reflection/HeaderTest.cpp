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
