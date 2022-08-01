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

