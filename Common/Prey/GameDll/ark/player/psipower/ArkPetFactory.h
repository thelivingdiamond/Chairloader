#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkPetFactory
// Header:  _unknown/ArkPetFactory.h
class ArkPetFactory
{ // Size=8 (0x8)
public:
	static inline auto s_petFactories = PreyGlobal<std::vector<ArkPetFactory*>>(0x2D521D0);

	virtual ~ArkPetFactory();
	virtual void DestroyCurrentPet() = 0;
	virtual void KillCurrentPet() = 0;
	virtual void ApplySkin(const uint64_t _skinId) = 0;

#if 0
	ArkPetFactory();
	const std::vector<ArkPetFactory*>& GetPetFactories() const;
#endif
};

#endif // MOONCRASH
