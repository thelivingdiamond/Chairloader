// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkSpeakerBase;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkDialogTurret.h
#ifdef MOONCRASH
enum class EArkDialogPlayerType;
#endif
class ArkDialogTurret : public ArkDialogPlayer // Id=80152C6 Size=256
{
public:
	ArkDialogTurret(ArkSpeakerBase *_pSpeaker);
	virtual ~ArkDialogTurret();
	virtual EArkDialogPlayerType GetType() const;
	
#ifndef MOONCRASH
	static inline auto FBitNotArkDialogTurret = PreyFunction<void(ArkDialogTurret *const _this)>(0x133DF00);
#else
	static inline auto FArkDialogTurretOv1 = PreyFunction<void(ArkDialogTurret* const _this, ArkSpeakerBase* _pSpeaker)>(0x141A350);
	static inline auto FBitNotArkDialogTurret = PreyFunction<void(ArkDialogTurret* const _this)>(0x141A380);
#endif
};
