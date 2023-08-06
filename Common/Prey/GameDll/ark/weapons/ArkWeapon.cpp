#include <Prey/CryGame/Game.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/GameDll/ark/player/ArkPlayerComponent.h>
#include <Prey/GameDll/ark/player/ArkPlayerLightManager.h>
#include <Prey/GameDll/ark/weapons/arkweapon.h>
#include <Prey/GameDll/ark/ArkListenerManager.h>
#include <Prey/GameDll/ark/ArkNames.h>

#pragma warning(disable : 4355) // 'this': used in base member initializer list

CArkWeapon::CArkWeapon(bool _bRetainPhysicsOnEquip)
	: m_disruptionVFX(m_effectController, 0)
	, m_playerLight(EArkPlayerLightPriority::Weapon, this)
	, m_bRetainPhysicsOnEquip(_bRetainPhysicsOnEquip)
{
	// Unregistered in CArkWeapon::Release
	ArkListenerManager* pListenerMgr = g_pGame->m_pArkListenerManager.get();
	pListenerMgr->RegisterStatsListener(LOCAL_PLAYER_ENTITY_ID, *ARKNAME_WeaponCriticalHitChance, this);
	pListenerMgr->RegisterCombatFocusListener(this);
}

CArkWeapon::~CArkWeapon()
{
	*m_bIronsightsTargetClassesLoaded = false;
	ArkPlayer* pPlayer = ArkPlayer::GetInstancePtr();

	if (pPlayer)
	{
		ArkPlayerLightManager& mgr = pPlayer->m_playerComponent.GetLightManager();
		mgr.UnregisterArkPlayerLight(&m_playerLight);
	}
}
