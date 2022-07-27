// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaConcussion.h
class ArkTraumaConcussion : public ArkTraumaBase // Id=801B884 Size=304
{
public:
	ArkAudioTrigger m_repeatAudio;
	
	ArkTraumaConcussion();
	virtual void RepeatEffect();
	
	static inline auto FRepeatEffect = PreyFunction<void(ArkTraumaConcussion *const _this)>(0x132C2B0);
};

