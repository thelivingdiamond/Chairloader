// Based on CryEngine 5.2 CryGame/CoherentValue.h.
#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

template<typename T>
class CCoherentValue
{
public:
	inline CCoherentValue()
		: m_dirty(false)
	{
	}

	inline CCoherentValue(const T& val)
		: m_val(val)
		, m_dirty(true)
	{
	}

	inline CCoherentValue(const CCoherentValue& other)
	{
		if (m_val != other.m_val)
		{
			m_dirty = true;
		}
		m_val = other.m_val;
	}

	inline CCoherentValue& operator=(const CCoherentValue& rhs)
	{
		if (this != &rhs)
		{
			if (m_val != rhs.m_val)
			{
				m_dirty = true;
			}
			m_val = rhs.m_val;
		}
		return *this;
	}

	inline CCoherentValue operator+=(const CCoherentValue& rhs)
	{
		m_dirty = true;
		m_val += rhs.m_val;

		return *this;
	}

	inline bool IsDirty() const
	{
		return m_dirty;
	}

	inline void Clear()
	{
		m_dirty = false;
	}

	inline const T& Value() const
	{
		return m_val;
	}

	inline void SetDirtyValue(CScriptSetGetChain& chain, const char* name)
	{
		if (IsDirty())
		{
			chain.SetValue(name, m_val);
			Clear();
		}
	}

	inline void Serialize(TSerialize ser, const char* name)
	{
		ser.Value(name, m_val);
		if (ser.IsReading())
		{
			m_dirty = true;
		}
	}

	inline operator T() const
	{
		return m_val;
	}
private:
	T    m_val;
	bool m_dirty;
};

