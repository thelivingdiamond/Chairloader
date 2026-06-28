// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkDataComponentBase
// Header:  Prey/GameDll/ark/ArkDataComponentBase.h
class ArkDataComponentBase
{ // Size=32 (0x20)
public:
	std::vector<uint64_t> m_collected;

	virtual bool IsValidData(const uint64_t _id) const;

#if 0
	ArkDataComponentBase();
	bool GiveData(const uint64_t _arg0_);
	bool HasData(const uint64_t _arg0_) const;
	const std::vector<uint64_t>& GetCollected() const;
	void Reset();
#endif

	static inline auto FIsValidData = PreyFunction<bool(const ArkDataComponentBase* const _this, const uint64_t _id)>(0x1A302A0);
};
#endif // !MOONCRASH
