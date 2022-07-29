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

