// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkClass.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/ArkCommon/reflection/IArkValueBase.h>
#include <Prey/CryString/CryName.h>

class ArkProperty;
class ArkReflectedObject;

// ArkClass
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkClass
{ // Size=88 (0x58)
public:
	using TReflectedObjectFactory = ArkReflectedObject* (*)();
	using TArkProperties = std::unordered_map<string, ArkProperty*>;
	using TClassMap = std::unordered_map<string, const ArkClass*>;

	std::unordered_map<string, ArkProperty*> m_Properties;
	const ArkClass* const m_baseClass;
	const char* m_name;
	ArkReflectedObject* (*m_ObjectFactory)();

	ArkClass(const ArkClass* const _pBaseClass, const char* _name, ArkReflectedObject* (*_factory)());
	static std::unordered_map<string, const ArkClass*>& GetClasses() { return FGetClasses(); }
	static const ArkClass* GetClassByName(const char* _className) { return FGetClassByName(_className); }
	void AddProperty(ArkProperty* _pProperty) { FAddProperty(this, _pProperty); }

#if 0
	const char* GetName() const;
	static std::vector<const ArkClass*> GetClassesByName(const char* const _arg0_);
	bool HasProperty(const char* _arg0_) const;
	const std::unordered_map<string, ArkProperty*>& GetProperties() const;
	const ArkProperty* GetProperty(const char* _arg0_) const;
	const ArkClass* GetBaseClass() const;
	ArkReflectedObject* CreateObject() const;
	bool InstanceOf(const ArkClass* const _arg0_) const;
#endif

	static inline auto FArkClassOv2 = PreyFunction<void(ArkClass* const _this, const ArkClass* const _pBaseClass, const char* _name, ArkReflectedObject* (*_factory)())>(0x2B88A0);
	static inline auto FGetClasses = PreyFunction<std::unordered_map<string, const ArkClass*>& ()>(0x2B9130);
	static inline auto FGetClassByName = PreyFunction<const ArkClass* (const char* _className)>(0x2B9040);
	static inline auto FAddProperty = PreyFunction<void(ArkClass* const _this, ArkProperty* _pProperty)>(0x2B8A70);
};

// ArkValue<CCryName>
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<CCryName> : public IArkValueBase
{ // Size=16 (0x10)
public:
	CCryName m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<CCryName>();
	ArkValue<CCryName>(CCryName _arg0_);
	ArkValue<CCryName>(const char* _arg0_);
	const CCryName& Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<CCryName>* const _this, const IArkValueBase* _v)>(0x2B9DB0);
};

// ArkValue<CryStringT<char> >
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<CryStringT<char> > : public IArkValueBase
{ // Size=16 (0x10)
public:
	string m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<CryStringT<char> >();
	ArkValue<CryStringT<char> >(string _arg0_);
	string Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<CryStringT<char> >* const _this, const IArkValueBase* _v)>(0x2B9D10);
};

// ArkValue<Vec2_tpl<float> >
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<Vec2_tpl<float> > : public IArkValueBase
{ // Size=16 (0x10)
public:
	Vec2 m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<Vec2_tpl<float> >();
	ArkValue<Vec2_tpl<float> >(Vec2 _arg0_);
	Vec2 Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<Vec2_tpl<float> >* const _this, const IArkValueBase* _v)>(0x2B9CC0);
};

// ArkValue<Vec3_tpl<float> >
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<Vec3_tpl<float> > : public IArkValueBase
{ // Size=24 (0x18)
public:
	Vec3 m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<Vec3_tpl<float> >();
	ArkValue<Vec3_tpl<float> >(Vec3 _arg0_);
	Vec3 Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<Vec3_tpl<float> >* const _this, const IArkValueBase* _v)>(0x2B9CE0);
};

// ArkValue<bool>
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<bool> : public IArkValueBase
{ // Size=16 (0x10)
public:
	bool m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<bool>();
	ArkValue<bool>(bool _arg0_);
	bool Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<bool>* const _this, const IArkValueBase* _v)>(0x2B9E20);
};

// ArkValue<float>
// Header:  Prey/ArkCommon/reflection/ArkClass.h
class ArkValue<float> : public IArkValueBase
{ // Size=16 (0x10)
public:
	float m_value;

	virtual void Set(const IArkValueBase* _v);

#if 0
	ArkValue<float>();
	ArkValue<float>(float _arg0_);
	float Get() const;
#endif

	static inline auto FSet = PreyFunction<void(ArkValue<float>* const _this, const IArkValueBase* _v)>(0x2B9CB0);
};
#endif // !MOONCRASH
