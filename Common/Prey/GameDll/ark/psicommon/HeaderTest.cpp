// Header test file for path Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
#include "arkpsielectrostaticburst.h"
static_assert(sizeof(ArkPsiElectrostaticBurstProperties) == 144);
static_assert(sizeof(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiElectrostaticBurst) == 80);
static_assert(sizeof(ArkPsiKineticBlastProperties) == 144);
static_assert(sizeof(ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiKineticBlast) == 80);
static_assert(sizeof(ArkPsiThermalBlastProperties) == 144);
static_assert(sizeof(ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiFearBlast) == 80);

#include "arkpsifearblast.h"
static_assert(sizeof(ArkPsiFearBlastProperties) == 144);
static_assert(sizeof(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty) == 32);

#include "arkpsithermalblast.h"
static_assert(sizeof(CArkPsiThermalBlast) == 112);
