// Header test file for path Prey/GameDll/ark/psicommon/

#include "arkpsielectrostaticburst.h"
static_assert(sizeof(ArkPsiElectrostaticBurstProperties) == 144);
static_assert(sizeof(ArkPsiElectrostaticBurstProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiElectrostaticBurst) == 80);
static_assert(sizeof(CArkPsiFearBlast) == 80);

#include "arkpsifearblast.h"
static_assert(sizeof(ArkPsiFearBlastProperties) == 144);
static_assert(sizeof(ArkPsiFearBlastProperties::ArkBlastPropertiesProperty) == 32);
#ifdef MOONCRASH
static_assert(sizeof(CArkPsiFearBlast) == 80);
#endif

#include "arkpsithermalblast.h"
static_assert(sizeof(ArkPsiThermalBlastProperties) == 144);
static_assert(sizeof(ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiThermalBlast) == 112);
static_assert(sizeof(CArkPsiBlast<CArkPsiElectrostaticBurst, CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>>) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiFearBlast, CArkPsiBlastProperties<ArkPsiFearBlastProperties>>) == 80);
static_assert(sizeof(CArkPsiBlast<CArkPsiThermalBlast, CArkPsiBlastProperties<ArkPsiThermalBlastProperties>>) == 80);
static_assert(sizeof(CArkPsiBlastProperties<ArkPsiThermalBlastProperties>) == 128);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPsiFlareBlast.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkPsiFlareBlastProperties) == 264);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxLightsProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkLightPropertiesProperty) == 32);
static_assert(sizeof(ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty) == 32);
static_assert(sizeof(CArkPsiFlareBlast) == 120);
static_assert(sizeof(CArkPsiBlast<CArkPsiFlareBlast, CArkPsiBlastProperties<ArkPsiFlareBlastProperties>>) == 80);
static_assert(sizeof(CArkPsiBlastProperties<ArkPsiFlareBlastProperties>) == 128);
#endif
#endif
