// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/Containers/CryListenerSet.h>
#include <Prey/CryEntitySystem/EntityClassRegistry.h>
#include <Prey/CryEntitySystem/IEntityClass.h>
#include <Chairloader/PreyFunction.h>

class ICrySizer;
struct IEntityClass;
struct IEntityClassRegistryListener;
struct ISystem;
class XmlNodeRef;

// Header: FromCpp
// CryEngine/cryentitysystem/entityclassregistry.h

class CEntityClassRegistry : public IEntityClassRegistry // Id=800CA3F Size=88
{
public:
	using ClassNameMap = std::map<string,IEntityClass *,std::less<string>,std::allocator<std::pair<CryStringT<char> const,IEntityClass *>>>;
	
	std::map<string,IEntityClass *,std::less<string>,std::allocator<std::pair<CryStringT<char> const,IEntityClass *>>> m_mapClassName;
	IEntityClass *m_pDefaultClass;
	ISystem *m_pSystem;
	std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,IEntityClass *> > > > m_currentMapIterator;


	using TListenerSet = CListenerSet<IEntityClassRegistryListener *>;
	
	TListenerSet m_listeners;
	
	CEntityClassRegistry();
	virtual ~CEntityClassRegistry();
	virtual bool RegisterEntityClass(IEntityClass *pClass);
	virtual bool UnregisterEntityClass(IEntityClass *pClass);
	virtual IEntityClass *FindClass(const char *sClassName) const;
	virtual IEntityClass *GetDefaultClass() const;
	virtual IEntityClass *RegisterStdClass(IEntityClassRegistry::SEntityClassDesc const &entityClassDesc);
	virtual void RegisterListener(IEntityClassRegistryListener *pListener);
	virtual void UnregisterListener(IEntityClassRegistryListener *pListener);
	virtual void LoadClasses(const char *sRootPath, bool bOnlyNewClasses);
	virtual void IteratorMoveFirst();
	virtual IEntityClass *IteratorNext();
	virtual int GetClassCount() const;
	void InitializeDefaultClasses() { FInitializeDefaultClasses(this); }
	void NotifyListeners(EEntityClassRegistryEvent event, IEntityClass const *pEntityClass) { FNotifyListeners(this,event,pEntityClass); }
	
#if 0
	void GetMemoryUsage(ICrySizer *arg0) const;
	void LoadClassDescription(XmlNodeRef &arg0, bool arg1);
#endif
	static inline auto FRegisterEntityClass = PreyFunction<bool(CEntityClassRegistry *const _this, IEntityClass *pClass)>(0x986820);
	static inline auto FUnregisterEntityClass = PreyFunction<bool(CEntityClassRegistry *const _this, IEntityClass *pClass)>(0x986BC0);
	static inline auto FFindClass = PreyFunction<IEntityClass *(CEntityClassRegistry const *const _this, const char *sClassName)>(0x985D70);
	static inline auto FGetDefaultClass = PreyFunction<IEntityClass *(CEntityClassRegistry const *const _this)>(0xD87500);
	static inline auto FRegisterStdClass = PreyFunction<IEntityClass *(CEntityClassRegistry *const _this, IEntityClassRegistry::SEntityClassDesc const &entityClassDesc)>(0x986A70);
	static inline auto FRegisterListener = PreyFunction<void(CEntityClassRegistry *const _this, IEntityClassRegistryListener *pListener)>(0x986A00);
	static inline auto FUnregisterListener = PreyFunction<void(CEntityClassRegistry *const _this, IEntityClassRegistryListener *pListener)>(0x986CD0);
	static inline auto FLoadClasses = PreyFunction<void(CEntityClassRegistry *const _this, const char *sRootPath, bool bOnlyNewClasses)>(0x986190);
	static inline auto FIteratorMoveFirst = PreyFunction<void(CEntityClassRegistry *const _this)>(0x986150);
	static inline auto FIteratorNext = PreyFunction<IEntityClass *(CEntityClassRegistry *const _this)>(0x986160);
	static inline auto FGetClassCount = PreyFunction<int(CEntityClassRegistry const *const _this)>(0x985E40);
	static inline auto FInitializeDefaultClasses = PreyFunction<void(CEntityClassRegistry *const _this)>(0x985E50);
	static inline auto FNotifyListeners = PreyFunction<void(CEntityClassRegistry *const _this, EEntityClassRegistryEvent event, IEntityClass const *pEntityClass)>(0x986740);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/ientityclass.h>
#include <Prey/CryEntitySystem/IEntityClass.h>
#include <_unknown/CListenerSet.h>

enum EEntityClassRegistryEvent;
class ICrySizer;
struct IEntityClass;
struct IEntityClassRegistryListener;
struct ISystem;
class XmlNodeRef;

// CEntityClassRegistry
// Header:  CryEngine/cryentitysystem/EntityClassRegistry.h
// Include: Prey/CryEntitySystem/EntityClassRegistry.h
class CEntityClassRegistry : public IEntityClassRegistry
{ // Size=88 (0x58)
public:
	using ClassNameMap = std::map<string, IEntityClass*>;
	using TListenerSet = CListenerSet<IEntityClassRegistryListener *>;

	std::map<string, IEntityClass*> m_mapClassName;
	IEntityClass* m_pDefaultClass;
	ISystem* m_pSystem;
	std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,IEntityClass *> > > > m_currentMapIterator;
	CListenerSet<IEntityClassRegistryListener *> m_listeners;

	CEntityClassRegistry();
	virtual ~CEntityClassRegistry();
	virtual bool RegisterEntityClass(IEntityClass* pClass);
	virtual bool UnregisterEntityClass(IEntityClass* pClass);
	virtual IEntityClass* FindClass(const char* sClassName) const;
	virtual IEntityClass* GetDefaultClass() const;
	virtual IEntityClass* RegisterStdClass(const IEntityClassRegistry::SEntityClassDesc& entityClassDesc);
	virtual void RegisterListener(IEntityClassRegistryListener* pListener);
	virtual void UnregisterListener(IEntityClassRegistryListener* pListener);
	virtual void LoadClasses(const char* sRootPath, bool bOnlyNewClasses);
	virtual void IteratorMoveFirst();
	virtual IEntityClass* IteratorNext();
	virtual int GetClassCount() const;
	void InitializeDefaultClasses() { FInitializeDefaultClasses(this); }
	void NotifyListeners(EEntityClassRegistryEvent event, const IEntityClass* pEntityClass) { FNotifyListeners(this, event, pEntityClass); }

#if 0
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	void LoadClassDescription(XmlNodeRef& _arg0_, bool _arg1_);
#endif

	static inline auto FCEntityClassRegistryOv1 = PreyFunction<void(CEntityClassRegistry* const _this)>(0x9A2850);
	static inline auto FRegisterEntityClass = PreyFunction<bool(CEntityClassRegistry* const _this, IEntityClass* pClass)>(0x9A3400);
	static inline auto FUnregisterEntityClass = PreyFunction<bool(CEntityClassRegistry* const _this, IEntityClass* pClass)>(0x9A37A0);
	static inline auto FFindClass = PreyFunction<IEntityClass* (const CEntityClassRegistry* const _this, const char* sClassName)>(0x9A2960);
	static inline auto FGetDefaultClass = PreyFunction<IEntityClass* (const CEntityClassRegistry* const _this)>(0x598E60);
	static inline auto FRegisterStdClass = PreyFunction<IEntityClass* (CEntityClassRegistry* const _this, const IEntityClassRegistry::SEntityClassDesc& entityClassDesc)>(0x9A3650);
	static inline auto FRegisterListener = PreyFunction<void(CEntityClassRegistry* const _this, IEntityClassRegistryListener* pListener)>(0x9A35E0);
	static inline auto FUnregisterListener = PreyFunction<void(CEntityClassRegistry* const _this, IEntityClassRegistryListener* pListener)>(0x9A38B0);
	static inline auto FLoadClasses = PreyFunction<void(CEntityClassRegistry* const _this, const char* sRootPath, bool bOnlyNewClasses)>(0x9A2D70);
	static inline auto FIteratorMoveFirst = PreyFunction<void(CEntityClassRegistry* const _this)>(0x9A2D30);
	static inline auto FIteratorNext = PreyFunction<IEntityClass* (CEntityClassRegistry* const _this)>(0x9A2D40);
	static inline auto FGetClassCount = PreyFunction<int(const CEntityClassRegistry* const _this)>(0x387590);
	static inline auto FInitializeDefaultClasses = PreyFunction<void(CEntityClassRegistry* const _this)>(0x9A2A30);
	static inline auto FNotifyListeners = PreyFunction<void(CEntityClassRegistry* const _this, EEntityClassRegistryEvent event, const IEntityClass* pEntityClass)>(0x9A3320);
};
#endif // !MOONCRASH
