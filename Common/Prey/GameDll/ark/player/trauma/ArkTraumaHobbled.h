// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/TArkAudioSwitch.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaHobbled.h
class ArkTraumaHobbled : public ArkTraumaBase // Id=801B6BB Size=312
{
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
	
	static inline auto FActivate = PreyFunction<void(ArkTraumaHobbled *const _this, int _level)>(0x12F7200);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaHobbled *const _this, bool _bImmediate, bool _bFromSerialize)>(0x12F7230);
};

