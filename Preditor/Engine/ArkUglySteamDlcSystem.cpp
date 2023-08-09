#include "ArkUglySteamDlcSystem.h"

static_assert(sizeof(Engine::CArkUglySteamDlcSystem) == 232);

static PreyPointer g_CArkSteamDlcSystem_vftable(0x1C745E0);

Engine::CArkUglySteamDlcSystem::CArkUglySteamDlcSystem() = default;
Engine::CArkUglySteamDlcSystem::~CArkUglySteamDlcSystem() = default;

IArkDlcSystem* Engine::CArkUglySteamDlcSystem::Instantiate()
{
	CArkUglySteamDlcSystem* ptr = new CArkUglySteamDlcSystem();
	ptr->vftable = g_CArkSteamDlcSystem_vftable.GetVoidPtr();
	return std::launder(reinterpret_cast<IArkDlcSystem*>(ptr));
}
