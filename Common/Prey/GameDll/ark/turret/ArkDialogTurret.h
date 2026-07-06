// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkSpeakerBase;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkDialogTurret.h
class ArkDialogTurret : public ArkDialogPlayer // Id=80152C6 Size=256
{
public:
	ArkDialogTurret(ArkSpeakerBase *_pSpeaker);
	virtual ~ArkDialogTurret();
	virtual EArkDialogPlayerType GetType() const;
	
	static inline auto FBitNotArkDialogTurret = PreyFunction<void(ArkDialogTurret *const _this)>(0x133DF00);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkSpeakerBase;
enum class EArkDialogPlayerType;

// ArkDialogTurret
// Header:  Prey/GameDll/ark/turret/ArkDialogTurret.h
class ArkDialogTurret : public ArkDialogPlayer
{ // Size=256 (0x100)
public:
	ArkDialogTurret(ArkSpeakerBase* _pSpeaker);
	virtual ~ArkDialogTurret();
	virtual EArkDialogPlayerType GetType() const;

	static inline auto FArkDialogTurretOv1 = PreyFunction<void(ArkDialogTurret* const _this, ArkSpeakerBase* _pSpeaker)>(0x141A350);
	static inline auto FBitNotArkDialogTurret = PreyFunction<void(ArkDialogTurret* const _this)>(0x141A380);
};
#endif // !MOONCRASH
