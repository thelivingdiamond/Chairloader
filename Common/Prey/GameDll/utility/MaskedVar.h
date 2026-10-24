// Based on CryEngine 5.2 GameSDK/GameDll/Utility/MaskedVar.h. Prey is a release build, so the debug
// m_dbgVal member is not present.
//
// Templated data type that attempts to protect itself from being identifiable to cheat tools by obfuscating its value
// with a randomly generated bitmask.
#pragma once
#include <limits>
#include <Prey/CryMath/Random.h>

template<class TVarType, typename TMaskType, TMaskType TMaxMaskValue>
class CMaskedVarT
{
private:
	union UVal
	{ // Size=4 (0x4)
		TVarType asVarType;
		TMaskType asMaskType;
	};

	UVal m_val;
	TMaskType m_mask;

public:
	CMaskedVarT()
		: m_mask(0)
	{
		static_assert(sizeof(TVarType) <= sizeof(TMaskType), "the mask type must be at least as large as the value type");
		static_assert(std::numeric_limits<TMaskType>::is_integer && !std::numeric_limits<TMaskType>::is_signed, "the mask type must be an unsigned integer");
	}

	CMaskedVarT(const TVarType v)
	{
		Set(v);
	}

	operator TVarType() const
	{
		return this->Get();
	}

	CMaskedVarT& operator+=(const TVarType rhs)
	{
		TVarType v = this->Get();
		v += rhs;
		this->Set(v);
		return *this;
	}

	CMaskedVarT& operator-=(const TVarType rhs)
	{
		TVarType v = this->Get();
		v -= rhs;
		this->Set(v);
		return *this;
	}

	CMaskedVarT& operator*=(const TVarType rhs)
	{
		TVarType v = this->Get();
		v *= rhs;
		this->Set(v);
		return *this;
	}

	CMaskedVarT& operator/=(const TVarType rhs)
	{
		TVarType v = this->Get();
		v /= rhs;
		this->Set(v);
		return *this;
	}

private:
	void Set(const TVarType v)
	{
		const TMaskType m = cry_random((TMaskType)1, TMaxMaskValue);
		UVal w;
		w.asVarType = v;
		m_val.asMaskType = (w.asMaskType ^ m);
		m_mask = m;
	}

	TVarType Get() const
	{
		UVal w;
		w.asMaskType = 0;
		if (m_mask > 0)
		{
			w.asMaskType = (m_val.asMaskType ^ m_mask);
		}
		return w.asVarType;
	}
};

typedef CMaskedVarT<float, uint32, 0xffffffff> TMaskedFloat;
typedef CMaskedVarT<int, uint32, 0xffffffff> TMaskedInt;
typedef CMaskedVarT<uint32, uint32, 0xffffffff> TMaskedUInt;
