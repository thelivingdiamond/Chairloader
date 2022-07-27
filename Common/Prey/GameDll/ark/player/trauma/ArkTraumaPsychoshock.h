// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// Header: FromCpp
// Prey/GameDll/ark/player/trauma/ArkTraumaPsychoshock.h
class ArkTraumaPsychoshock : public ArkTraumaBase // Id=801B885 Size=296
{
public:
	ArkTraumaPsychoshock();
	virtual void Update(float _frametime);
	virtual void Activate(int _level);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);
	
	static inline auto FUpdate = PreyFunction<void(ArkTraumaPsychoshock *const _this, float _frametime)>(0x1327F60);
	static inline auto FActivate = PreyFunction<void(ArkTraumaPsychoshock *const _this, int _level)>(0x132C380);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaPsychoshock *const _this, bool _bImmediate, bool _bFromSerialize)>(0x132C3D0);
};

