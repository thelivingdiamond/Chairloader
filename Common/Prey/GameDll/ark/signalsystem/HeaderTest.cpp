// Header test file for path Prey/GameDll/ark/signalsystem/ArkBreakableSignalReceiver.h
#include "ArkBreakableSignalReceiver.h"
static_assert(sizeof(ArkBreakableSignalReceiver) == 32);

#include "ArkPackageSignalRamp.h"
static_assert(sizeof(ArkSignalSystem::PackageSignalRamp) == 48);
static_assert(sizeof(ArkSignalSystem::PackageSignalRampContainer) == 64);

#include "arksignalcontext.h"
static_assert(sizeof(ArkSignalSystem::CArkSignalContext) == 16);

#include "arksignalmanager.h"
static_assert(sizeof(ArkSignalSystem::Package) == 56);
static_assert(sizeof(ArkSignalSystem::Package::Value) == 16);
static_assert(sizeof(ArkSignalSystem::Manager) == 384);
static_assert(sizeof(ArkSignalSystem::Manager::EntityInfo) == 32);
static_assert(sizeof(ArkSignalSystem::Manager::ModifierInfo) == 32);
static_assert(sizeof(ArkSignalSystem::Manager::RepeatInfo) == 72);
//static_assert(sizeof(ArkSignalSystem::Manager::AreaTargetLOSCheckImpl) == 28);
//static_assert(sizeof(ArkSignalSystem::Manager::AreaTarget) == 400);
static_assert(sizeof(ArkSignalSystem::Manager::AreaEffect) == 72);
static_assert(sizeof(ArkSignalSystem::Manager::RegisteredSignals) == 56);

#include "arksignalreceiver.h"
static_assert(sizeof(ArkSignalSystem::Receiver) == 16);
