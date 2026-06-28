// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkTurret;

namespace ArkTurretDamageFsm::States
{

// ArkTurretDamageFsm::States::Base
// Header:  Prey/GameDll/ark/turret/turretdamagefsm/states/arkturretdamagefsm_states_base.h
class Base
{ // Size=1 (0x1)
public:
	static void TryHideAttachment(ArkTurret& _turret, const char* _pAttachmentName, bool _bHidden) { FTryHideAttachment(_turret, _pAttachmentName, _bHidden); }

#if 0
	void Update(ArkTurret& _arg0_, float _arg1_);
	void OnBrokenChanged(ArkTurret& _arg0_, bool _arg1_);
#endif

	static inline auto FTryHideAttachment = PreyFunction<void(ArkTurret& _turret, const char* _pAttachmentName, bool _bHidden)>(0x143E250);
};


} // namespace ArkTurretDamageFsm::States
#endif // !MOONCRASH
