// Header file automatically created from a PDB.
#pragma once

// SStateEventData
// Header:  _unknown/SStateEventData.h
struct SStateEventData
{ // Size=16 (0x10)
	enum EType
	{
		eSEDT_undef = 0,
		eSEDT_int = 1,
		eSEDT_float = 2,
		eSEDT_bool = 3,
		eSEDT_voidptr = 4,
	};

	union
	{
		int m_int;
		float m_float;
		bool m_bool;
		const void* m_pointer;
	};

	int8_t m_type;

#if 0
	SStateEventData();
	SStateEventData(int _arg0_);
	SStateEventData(float _arg0_);
	SStateEventData(bool _arg0_);
	SStateEventData(const void* _arg0_);
	int GetInt() const;
	float GetFloat() const;
	bool GetBool() const;
	const void* GetPtr() const;
#endif
};

