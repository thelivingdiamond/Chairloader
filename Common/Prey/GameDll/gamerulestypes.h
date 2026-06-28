// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/CryNetwork/ISerialize.h>

// SDrawResolutionData
// Header:  Prey/GameDll/gamerulestypes.h
struct SDrawResolutionData
{ // Size=88 (0x58)
	enum EDataType
	{
		eDataType_float = 0,
		eDataType_int = 1,
	};

	enum EWinningDataTest
	{
		eWinningData_greater_than = 0,
		eWinningData_less_than = 1,
	};

	using TFixedString = CryFixedStringT<32>;

	float m_floatDataForTeams[2];
	int m_intDataForTeams[2];
	SDrawResolutionData::EDataType m_dataType;
	SDrawResolutionData::EWinningDataTest m_dataTest;
	CryFixedStringT<32> m_winningMessage;
	bool m_active;

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	SDrawResolutionData();
	void Clear();
#endif

	static inline auto FSerializeWith = PreyFunction<void(SDrawResolutionData* const _this, TSerialize ser)>(0x18544A0);
};
#endif // MOONCRASH
