// Header file automatically created from a PDB.

#pragma once

class ArkTurret;

namespace ArkTurretDamageFsm::States
{

// Header: FromCpp
// Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h
class Base // Id=80152E4 Size=1
{
public:
	static void TryHideAttachment(ArkTurret &_turret, const char *_pAttachmentName, bool _bHidden) { FTryHideAttachment(_turret,_pAttachmentName,_bHidden); }
	
#if 0
	void Update(ArkTurret &arg0, float arg1);
	void OnBrokenChanged(ArkTurret &arg0, bool arg1);
#endif
	
	static inline auto FTryHideAttachment = PreyFunction<void(ArkTurret &_turret, const char *_pAttachmentName, bool _bHidden)>(0x135AFB0);
};

} // namespace ArkTurretDamageFsm::States

