// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/arkclass.h>
#include <Prey/CryString/CryName.h>
#include "IArkValueBase.h"

class ArkProperty;
class ArkReflectedObject;

// Header: Exact
// Prey/ArkCommon/reflection/ArkClass.h
class ArkClass // Id=800200E Size=88
{
public:
	using TReflectedObjectFactory = ArkReflectedObject *(*)();
	using TArkProperties = std::unordered_map<string,ArkProperty *>;
	using TClassMap = std::unordered_map<string,ArkClass const *>;
	
	TArkProperties m_Properties;
	ArkClass const *const m_baseClass;
	const char *m_name;
	ArkReflectedObject *(*m_ObjectFactory)();
	
	ArkClass(ArkClass const *const _pBaseClass, const char *_name, ArkReflectedObject *(*_factory)());
	static TClassMap &GetClasses() { return FGetClasses(); }
	static ArkClass const *GetClassByName(const char *_className) { return FGetClassByName(_className); }
	void AddProperty(ArkProperty *_pProperty) { FAddProperty(this,_pProperty); }
	
#if 0
	const char *GetName() const;
	static std::vector<ArkClass const *> GetClassesByName(const char *const arg0);
	bool HasProperty(const char *arg0) const;
	std::unordered_map<string,ArkProperty *,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,ArkProperty *>>> const &GetProperties() const;
	ArkProperty const *GetProperty(const char *arg0) const;
	ArkClass const *GetBaseClass() const;
	ArkReflectedObject *CreateObject() const;
	bool InstanceOf(ArkClass const *const arg0) const;
#endif
	
	static inline auto FGetClasses = PreyFunction<std::unordered_map<string,ArkClass const *,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,ArkClass const *>>> &()>(0x2A0C80);
	static inline auto FGetClassByName = PreyFunction<ArkClass const *(const char *_className)>(0x2A0B90);
	static inline auto FAddProperty = PreyFunction<void(ArkClass *const _this, ArkProperty *_pProperty)>(0x2A0590);
};

// Header: Exact
// Prey/ArkCommon/reflection/arkclass.h
template <typename T>
class ArkValue : public IArkValueBase // Id=8004434 Size=16
{
public:
	T m_value;
	
#if 0
	virtual void Set(IArkValueBase const *_v);
	T Get() const;
#endif
};

