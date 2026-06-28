// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaPsychoshock
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaPsychoshock.h
class ArkTraumaPsychoshock : public ArkTraumaBase
{ // Size=296 (0x128)
public:
	ArkTraumaPsychoshock();
	virtual void Update(float _frametime);
	virtual void Activate(int _level);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);

	static inline auto FArkTraumaPsychoshockOv2 = PreyFunction<void(ArkTraumaPsychoshock* const _this)>(0x132C300);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaPsychoshock* const _this, float _frametime)>(0x1327F60);
	static inline auto FActivate = PreyFunction<void(ArkTraumaPsychoshock* const _this, int _level)>(0x132C380);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaPsychoshock* const _this, bool _bImmediate, bool _bFromSerialize)>(0x132C3D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBase.h>

// ArkTraumaPsychoshock
// Header:  Prey/GameDll/ark/player/trauma/ArkTraumaPsychoshock.h
class ArkTraumaPsychoshock : public ArkTraumaBase
{ // Size=328 (0x148)
public:
	ArkTraumaPsychoshock();
	virtual void Update(float _frametime);
	virtual void Activate(int _level);
	virtual void UpdateVisuals(bool _bImmediate, bool _bFromSerialize);

	static inline auto FArkTraumaPsychoshockOv2 = PreyFunction<void(ArkTraumaPsychoshock* const _this)>(0x1406720);
	static inline auto FUpdate = PreyFunction<void(ArkTraumaPsychoshock* const _this, float _frametime)>(0x14067B0);
	static inline auto FActivate = PreyFunction<void(ArkTraumaPsychoshock* const _this, int _level)>(0x1406760);
	static inline auto FUpdateVisuals = PreyFunction<void(ArkTraumaPsychoshock* const _this, bool _bImmediate, bool _bFromSerialize)>(0x14067F0);
};
#endif // !MOONCRASH
