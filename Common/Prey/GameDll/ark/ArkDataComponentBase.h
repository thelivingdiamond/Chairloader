// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ArkDataComponentBase.h
class ArkDataComponentBase // Id=8016F0C Size=32
{
public:
	std::vector<unsigned __int64> m_collected;
	
	virtual bool IsValidData(const uint64_t _id) const;
	
#if 0
	bool GiveData(const uint64_t arg0);
	bool HasData(const uint64_t arg0) const;
	std::vector<unsigned __int64> const &GetCollected() const;
	void Reset();
#endif
	
	static inline auto FIsValidData = PreyFunction<bool(ArkDataComponentBase const *const _this, const uint64_t _id)>(0x1B933B0);
};

