#include "ArkUglySteamDlcSystem.h"

static_assert(sizeof(CArkUglySteamDlcSystem) == 232);

static PreyPointer g_CArkSteamDlcSystem_vftable(0x1C745E0);

CArkUglySteamDlcSystem::CArkUglySteamDlcSystem() = default;
CArkUglySteamDlcSystem::~CArkUglySteamDlcSystem() = default;

IArkDlcSystem* CArkUglySteamDlcSystem::Instantiate()
{
	CArkUglySteamDlcSystem* ptr = new CArkUglySteamDlcSystem();
	ptr->vftable = g_CArkSteamDlcSystem_vftable.GetVoidPtr();
	return std::launder(reinterpret_cast<IArkDlcSystem*>(ptr));
}
