// Header file automatically created from a PDB.

#pragma once
#include "IArkValueBase.h"

class ArkReflectedObject;
class IArkValueBase;

// Prey/ArkCommon/reflection/ArkProperty.h
class ArkProperty // Id=800201D Size=32
{
public:
	enum class EArkType
	{
		intT = 0,
		uintT = 1,
		boolT = 2,
		floatT = 3,
		stringT = 4,
		crynameT = 5,
		vec2T = 6,
		vec3T = 7,
		objectT = 8,
		object_ptrT = 9,
		unknownT = 10,
	};

	string m_name;
	const char *m_typeStr;
	ArkProperty::EArkType m_arkType;
	
	virtual void SetValue(ArkReflectedObject *const arg0, IArkValueBase const *arg1) const = 0;
	virtual bool IsArray() const;
	virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
	virtual void Reset(ArkReflectedObject *_pObject) const;
	
#if 0
	string const &GetName() const;
	ArkProperty::EArkType GetArkType() const;
	const char *GetTypeStr() const;
#endif
	
	static inline auto FIsArray = PreyFunction<bool(ArkProperty const *const _this)>(0xDD23F0);
	static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkProperty const *const _this, ArkReflectedObject *const _pObject)>(0x158AEF0);
	static inline auto FReset = PreyFunction<void(ArkProperty const *const _this, ArkReflectedObject *_pObject)>(0xA13080);
};

