// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaHobbled
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaHobbled.h
class ArkTraumaHobbled : public ArkTraumaBase
{ // Size=312 (0x138)
public:
	enum class EAudioHobbled
	{
		off = 0,
		on = 1,
		count = 2,
	};

	TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled> m_stepSwitch;

	ArkTraumaHobbled();
	virtual ~ArkTraumaHobbled();
	virtual void Activate(int _level);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);

	static inline auto FArkTraumaHobbledOv1 = PreyFunction<void(ArkTraumaHobbled* const _this)>(0x12F70F0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaHobbled* const _this, int _level)>(0x12F7200);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaHobbled* const _this, bool _bImmediate, bool _bFromSerialize)>(0x12F7230);
};

