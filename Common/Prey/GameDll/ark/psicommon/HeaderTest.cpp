// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
#include "arkpsielectrostaticburst.h"
static_assert(sizeof(ArkPsiElectrostaticBurstProperties) == 144);
static_assert(sizeof(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiElectrostaticBurst) == 80);
static_assert(sizeof(CArkPsiFearBlast) == 80);

#include "arkpsifearblast.h"
static_assert(sizeof(ArkPsiFearBlastProperties) == 144);
static_assert(sizeof(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty) == 32);

#include "arkpsithermalblast.h"
static_assert(sizeof(CArkPsiThermalBlast) == 112);
#else // MOONCRASH
// Header test file for path Prey/GameDll/ark/psicommon/
#include "ArkPsiElectrostaticBurst.h"
static_assert(sizeof(ArkPsiElectrostaticBurstProperties) == 144);
static_assert(sizeof(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiElectrostaticBurst) == 80);

#include "ArkPsiFearBlast.h"
static_assert(sizeof(ArkPsiFearBlastProperties) == 144);
static_assert(sizeof(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiFearBlast) == 80);

#include "ArkPsiFlareBlast.h"
static_assert(sizeof(ArkPsiFlareBlastProperties) == 264);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkLightPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxLightsProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiFlareBlast) == 120);

#include "ArkPsiKineticBlast.h"
static_assert(sizeof(ArkPsiKineticBlastProperties) == 144);
static_assert(sizeof(ArkPsiKineticBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiKineticBlast) == 80);

#include "ArkPsiThermalBlast.h"
static_assert(sizeof(ArkPsiThermalBlastProperties) == 144);
static_assert(sizeof(ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiThermalBlast) == 112);

#include "arkpsiblast.h"
static_assert(sizeof(CArkPsiBlast<CArkPsiElectrostaticBurst,CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> >) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiFearBlast,CArkPsiBlastProperties<ArkPsiFearBlastProperties> >) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiKineticBlast,CArkPsiBlastProperties<ArkPsiKineticBlastProperties> >) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >) == 80);
static_assert(sizeof(CArkPsiBlastProperties<ArkPsiFlareBlastProperties>) == 128);

#include "arkpsiblastmanager.h"
static_assert(sizeof(CArkPsiBlastManager<CArkPsiElectrostaticBurst>) == 160);
static_assert(sizeof(CArkPsiBlastManager<CArkPsiFearBlast>) == 160);
static_assert(sizeof(CArkPsiBlastManager<CArkPsiFlareBlast>) == 160);
static_assert(sizeof(CArkPsiBlastManager<CArkPsiKineticBlast>) == 160);
static_assert(sizeof(CArkPsiBlastManager<CArkPsiThermalBlast>) == 160);
#endif // !MOONCRASH
