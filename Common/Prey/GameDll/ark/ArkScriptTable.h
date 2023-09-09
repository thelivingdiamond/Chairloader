// Header file automatically created from a PDB.

#pragma once
#include <cinttypes>
#include <Prey/CryScriptSystem/IScriptSystem.h>

struct IEntity;
struct IEntityClass;
struct IScriptTable;

class ArkSafeScriptTable;

// Header: Exact
// Prey/GameDll/ark/arkscripttable.h
template <typename T>
class ArkScriptTableBase // Id=8013471 Size=8
{
public:
	SmartScriptTable m_pScriptTable;

	ArkSafeScriptTable GetSafeSubTable(const char* sKey) const;

	float GetFloat(const char* _pKey, float _default = 0.0f) const
	{
		float result = _default;

		if (m_pScriptTable)
		{
			ScriptAnyValue any;
			if (m_pScriptTable->GetValueAny(_pKey, any))
				any.CopyTo(result);
		}

		return result;
	}

	uint64_t GetArkUniqueId(const char* _pKey, uint64_t _default = 0) const
	{
		uint64_t result = _default;

		if (m_pScriptTable)
		{
			ScriptAnyValue any;
			if (m_pScriptTable->GetValueAny(_pKey, any))
			{
				if (any.GetVarType() == ANY_TSTRING)
					sscanf(any.str, SCNx64, &result);
			}
		}

		return result;
	}

	const char* GetString(const char* _pKey, const char* _default = "") const
	{
		const char* result = _default;

		if (m_pScriptTable)
		{
			ScriptAnyValue any;
			if (m_pScriptTable->GetValueAny(_pKey, any))
				any.CopyTo(result);
		}

		return result;
	}

#if 0
	int* operator int ArkSafeBool<ArkScriptTableBase<T>>::* () const;
	SmartScriptTable const& AsSmartScriptTable() const;
	T operator[](const char* _pTableName) const;
	T GetSubTable(const char* arg0) const;
	ArkSafeScriptTable GetSafeSubTable(const char* arg0) const;
	bool GetBool(const char* arg0, bool arg1) const;
	int GetInt(const char* arg0, int arg1) const;
	unsigned GetUnsignedInt(const char* arg0, unsigned arg1) const;
	uint64_t GetArkUniqueId(const char* arg0, uint64_t arg1) const;
	float GetFloat(const char* _pKey, float _default) const;
	const char* GetString(const char* arg0, const char* arg1) const;
	Vec3 GetVector(const char* arg0, Vec3 const& arg1) const;
	Ang3_tpl<float> GetEulerAngles(const char* arg0, Ang3_tpl<float> const& arg1) const;
	IScriptTable* GetScriptTable(const char* arg0, IScriptTable* arg1) const;
	SmartScriptTable GetSmartScriptTable(const char* arg0, SmartScriptTable const& arg1) const;
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/arkscripttable.h
class ArkSafeScriptTable : public ArkScriptTableBase<ArkSafeScriptTable> // Id=801346F Size=8
{
public:
	ArkSafeScriptTable(SmartScriptTable const& _pScriptTable) { m_pScriptTable = _pScriptTable; }
	ArkSafeScriptTable(IScriptTable *_pScriptTable);
	ArkSafeScriptTable(IEntity const &_entity);
	ArkSafeScriptTable(IEntity const *_pEntity);
};

// Header: FromCpp
// Prey/GameDll/ark/ArkScriptTable.h
class ArkScriptTable : public ArkScriptTableBase<ArkScriptTable> // Id=8013470 Size=8
{
public:
	ArkScriptTable(SmartScriptTable const &_pScriptTable) { m_pScriptTable = _pScriptTable; }
	ArkScriptTable(IScriptTable *_pScriptTable);
	ArkScriptTable(IEntity const *_pEntity);
};

template <typename T>
ArkSafeScriptTable ArkScriptTableBase<T>::GetSafeSubTable(const char* _pKey) const
{
	SmartScriptTable outTable;

	if (m_pScriptTable)
	{
		ScriptAnyValue any;
		if (m_pScriptTable->GetValueAny(_pKey, any))
			any.CopyTo(outTable);
	}

	return ArkSafeScriptTable(outTable);
}
