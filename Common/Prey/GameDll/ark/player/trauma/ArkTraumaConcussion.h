// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaConcussion
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaConcussion.h
class ArkTraumaConcussion : public ArkTraumaBase
{ // Size=304 (0x130)
public:
	ArkAudioTrigger m_repeatAudio;

	ArkTraumaConcussion();
	virtual void RepeatEffect();

	static inline auto FArkTraumaConcussionOv2 = PreyFunction<void(ArkTraumaConcussion* const _this)>(0x132C250);
	static inline auto FRepeatEffect = PreyFunction<void(ArkTraumaConcussion* const _this)>(0x132C2B0);
};

