// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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

	Vec3 GetVector(const char* _pKey, const Vec3& _default = ZERO) const
	{
		Vec3 result = _default;

		if (m_pScriptTable)
		{
			ScriptAnyValue any(result);
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class ArkSafeScriptTable;
class ArkScriptTable;
struct IEntity;
struct IEntityClass;
struct IScriptTable;

// ArkScriptTableBase<ArkSafeScriptTable>
// Header:  Prey/GameDll/ark/arkscripttable.h
class ArkScriptTableBase<ArkSafeScriptTable>
{ // Size=8 (0x8)
public:
	SmartScriptTable m_pScriptTable;

	ArkSafeScriptTable operator[](const char* _pTableName) const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FoperatorSBLSBR(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_), _pTableName); }
	ArkSafeScriptTable GetSafeSubTable(const char* _pTableName) const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FGetSafeSubTable(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_), _pTableName); }
	bool GetBool(const char* _pKey, bool _bDefault) const { return FGetBool(this, _pKey, _bDefault); }
	int GetInt(const char* _pKey, int _default) const { return FGetInt(this, _pKey, _default); }
	uint64_t GetArkUniqueId(const char* _pKey, uint64_t _default) const { return FGetArkUniqueId(this, _pKey, _default); }
	float GetFloat(const char* _pKey, float _default) const { return FGetFloat(this, _pKey, _default); }
	const char* GetString(const char* _pKey, const char* _pDefault) const { return FGetString(this, _pKey, _pDefault); }
	Vec3 GetVector(const char* _pKey, const Vec3& _default) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetVector(this, reinterpret_cast<Vec3*>(_return_buf_), _pKey, _default); }
	SmartScriptTable GetSmartScriptTable(const char* _pKey, const SmartScriptTable& _pDefault) const { alignas(SmartScriptTable) std::byte _return_buf_[sizeof(SmartScriptTable)]; return *FGetSmartScriptTable(this, reinterpret_cast<SmartScriptTable*>(_return_buf_), _pKey, _pDefault); }

#if 0
	ArkScriptTableBase<ArkSafeScriptTable>(const SmartScriptTable& _arg0_);
	int* (*)() const;
	const SmartScriptTable& AsSmartScriptTable() const;
	ArkScriptTable GetSubTable(const char* _arg0_) const;
	unsigned GetUnsignedInt(const char* _arg0_, unsigned _arg1_) const;
	Ang3 GetEulerAngles(const char* _arg0_, const Ang3& _arg1_) const;
	IScriptTable* GetScriptTable(const char* _arg0_, IScriptTable* _arg1_) const;
#endif

	static inline auto FoperatorSBLSBR = PreyFunction<ArkSafeScriptTable*(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, ArkSafeScriptTable* _return_value_, const char* _pTableName)>(0x10D89D0);
	static inline auto FGetSafeSubTable = PreyFunction<ArkSafeScriptTable*(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, ArkSafeScriptTable* _return_value_, const char* _pTableName)>(0x10D89D0);
	static inline auto FGetBool = PreyFunction<bool(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, const char* _pKey, bool _bDefault)>(0x10D9820);
	static inline auto FGetInt = PreyFunction<int(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, const char* _pKey, int _default)>(0x10E13D0);
	static inline auto FGetArkUniqueId = PreyFunction<uint64_t(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, const char* _pKey, uint64_t _default)>(0x10E04B0);
	static inline auto FGetFloat = PreyFunction<float(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, const char* _pKey, float _default)>(0x1072D30);
	static inline auto FGetString = PreyFunction<const char* (const ArkScriptTableBase<ArkSafeScriptTable>* const _this, const char* _pKey, const char* _pDefault)>(0x10DA570);
	static inline auto FGetVector = PreyFunction<Vec3*(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, Vec3* _return_value_, const char* _pKey, const Vec3& _default)>(0x1190680);
	static inline auto FGetSmartScriptTable = PreyFunction<SmartScriptTable*(const ArkScriptTableBase<ArkSafeScriptTable>* const _this, SmartScriptTable* _return_value_, const char* _pKey, const SmartScriptTable& _pDefault)>(0x10DA3D0);
};

// ArkSafeScriptTable
// Header:  Prey/GameDll/ark/arkscripttable.h
class ArkSafeScriptTable : public ArkScriptTableBase<ArkSafeScriptTable>
{ // Size=8 (0x8)
public:
	ArkSafeScriptTable(const SmartScriptTable& _pScriptTable);
	ArkSafeScriptTable(IScriptTable* _pScriptTable);
	ArkSafeScriptTable(const IEntity& _entity);
	ArkSafeScriptTable(const IEntity* _pEntity);

#if 0
	ArkSafeScriptTable(IScriptTable& _arg0_);
	ArkSafeScriptTable(const IEntityClass& _arg0_);
	ArkSafeScriptTable(const IEntityClass* _arg0_);
#endif

	static inline auto FArkSafeScriptTableOv8 = PreyFunction<void(ArkSafeScriptTable* const _this, const SmartScriptTable& _pScriptTable)>(0x1597960);
	static inline auto FArkSafeScriptTableOv6 = PreyFunction<void(ArkSafeScriptTable* const _this, IScriptTable* _pScriptTable)>(0x1597890);
	static inline auto FArkSafeScriptTableOv5 = PreyFunction<void(ArkSafeScriptTable* const _this, const IEntity& _entity)>(0x1597820);
	static inline auto FArkSafeScriptTableOv4 = PreyFunction<void(ArkSafeScriptTable* const _this, const IEntity* _pEntity)>(0x15978E0);
};

// ArkScriptTableBase<ArkScriptTable>
// Header:  Prey/GameDll/ark/arkscripttable.h
class ArkScriptTableBase<ArkScriptTable>
{ // Size=8 (0x8)
public:
	SmartScriptTable m_pScriptTable;

	ArkScriptTable operator[](const char* _pTableName) const { alignas(ArkScriptTable) std::byte _return_buf_[sizeof(ArkScriptTable)]; return *FoperatorSBLSBR(this, reinterpret_cast<ArkScriptTable*>(_return_buf_), _pTableName); }
	float GetFloat(const char* _pKey, float _default) const { return FGetFloat(this, _pKey, _default); }

#if 0
	ArkScriptTableBase<ArkScriptTable>(const SmartScriptTable& _arg0_);
	int* (*)() const;
	const SmartScriptTable& AsSmartScriptTable() const;
	ArkScriptTable GetSubTable(const char* _arg0_) const;
	ArkSafeScriptTable GetSafeSubTable(const char* _arg0_) const;
	bool GetBool(const char* _arg0_, bool _arg1_) const;
	int GetInt(const char* _arg0_, int _arg1_) const;
	unsigned GetUnsignedInt(const char* _arg0_, unsigned _arg1_) const;
	uint64_t GetArkUniqueId(const char* _arg0_, uint64_t _arg1_) const;
	const char* GetString(const char* _arg0_, const char* _arg1_) const;
	Vec3 GetVector(const char* _arg0_, const Vec3& _arg1_) const;
	Ang3 GetEulerAngles(const char* _arg0_, const Ang3& _arg1_) const;
	IScriptTable* GetScriptTable(const char* _arg0_, IScriptTable* _arg1_) const;
	SmartScriptTable GetSmartScriptTable(const char* _arg0_, const SmartScriptTable& _arg1_) const;
#endif

	static inline auto FoperatorSBLSBR = PreyFunction<ArkScriptTable*(const ArkScriptTableBase<ArkScriptTable>* const _this, ArkScriptTable* _return_value_, const char* _pTableName)>(0x13237B0);
	static inline auto FGetFloat = PreyFunction<float(const ArkScriptTableBase<ArkScriptTable>* const _this, const char* _pKey, float _default)>(0x1588700);
};
#endif // !MOONCRASH
