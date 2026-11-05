// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/CryEntitySystem/IEntityClass.h>
#include <Prey/CryEntitySystem/IEntityClass.h>

class ICrySizer;
struct IEntity;
struct IEntityEventHandler;
struct IEntityPropertyHandler;
struct IEntityScript;
struct IEntityScriptFileHandler;
struct IScriptTable;
struct SEntitySpawnParams;

// CEntityClass
// Header:  CryEngine/cryentitysystem/EntityClass.h
// Include: Prey/CryEntitySystem/EntityClass.h
class CEntityClass : public IEntityClass
{ // Size=128 (0x80)
public:
	unsigned m_nFlags;
	string m_sName;
	string m_sScriptFile;
	IEntityScript* m_pEntityScript;
	std::shared_ptr<IEntityProxy> (*m_pfnUserProxyCreate)(IEntity*, SEntitySpawnParams&, void*);
	void* m_pUserProxyUserData;
	bool m_bScriptLoaded;
	IEntityPropertyHandler* m_pPropertyHandler;
	IEntityEventHandler* m_pEventHandler;
	IEntityScriptFileHandler* m_pScriptFileHandler;
	SEditorClassInfo m_EditorClassInfo;
	DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_entityAttributes;
	DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_classAttributes;

	CEntityClass();
	virtual ~CEntityClass();
	virtual void Release();
	virtual unsigned GetFlags() const;
	virtual void SetFlags(unsigned nFlags);
	virtual const char* GetName() const;
	virtual const char* GetScriptFile() const;
	virtual IEntityScript* GetIEntityScript() const;
	virtual IScriptTable* GetScriptTable() const;
	virtual bool LoadScript(bool bForceReload);
	virtual std::shared_ptr<IEntityProxy> (*)(IEntity*, SEntitySpawnParams&, void*) GetUserProxyCreateFunc() const;
	virtual void* GetUserProxyData() const;
	virtual IEntityPropertyHandler* GetPropertyHandler() const;
	virtual IEntityEventHandler* GetEventHandler() const;
	virtual IEntityScriptFileHandler* GetScriptFileHandler() const;
	virtual const SEditorClassInfo& GetEditorClassInfo() const;
	virtual void SetEditorClassInfo(const SEditorClassInfo& editorClassInfo);
	virtual int GetEventCount();
	virtual IEntityClass::SEventInfo GetEventInfo(int nIndex);
	virtual bool FindEventInfo(const char* sEvent, IEntityClass::SEventInfo& event);
	virtual DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetClassAttributes();
	virtual const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetClassAttributes() const;
	virtual DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetEntityAttributes();
	virtual const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& GetEntityAttributes() const;
	void SetName(const char* sName) { FSetName(this, sName); }
	void SetScriptFile(const char* sScriptFile) { FSetScriptFile(this, sScriptFile); }
	void SetEntityScript(IEntityScript* pScript) { FSetEntityScript(this, pScript); }
	void SetUserProxyCreateFunc(std::shared_ptr<IEntityProxy> (*pFunc)(IEntity*, SEntitySpawnParams&, void*), void* pUserData) { FSetUserProxyCreateFunc(this, pFunc, pUserData); }
	void SetPropertyHandler(IEntityPropertyHandler* pPropertyHandler) { FSetPropertyHandler(this, pPropertyHandler); }
	void SetEventHandler(IEntityEventHandler* pEventHandler) { FSetEventHandler(this, pEventHandler); }
	void SetScriptFileHandler(IEntityScriptFileHandler* pScriptFileHandler) { FSetScriptFileHandler(this, pScriptFileHandler); }
	void SetEntityAttributes(const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes) { FSetEntityAttributes(this, attributes); }
	void SetClassAttributes(const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes) { FSetClassAttributes(this, attributes); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;

#ifndef MOONCRASH
	static inline auto FCEntityClassOv1 = PreyFunction<void(CEntityClass* const _this)>(0x984C30);
	static inline auto FRelease = PreyFunction<void(CEntityClass* const _this)>(0xA97D40);
	static inline auto FGetFlags = PreyFunction<unsigned(const CEntityClass* const _this)>(0xEEBB60);
	static inline auto FSetFlags = PreyFunction<void(CEntityClass* const _this, unsigned nFlags)>(0x834F00);
	static inline auto FGetName = PreyFunction<const char* (const CEntityClass* const _this)>(0x5BFB50);
	static inline auto FGetScriptFile = PreyFunction<const char* (const CEntityClass* const _this)>(0xD87500);
	static inline auto FGetIEntityScript = PreyFunction<IEntityScript* (const CEntityClass* const _this)>(0x1140FE0);
	static inline auto FGetScriptTable = PreyFunction<IScriptTable* (const CEntityClass* const _this)>(0x9851D0);
	static inline auto FLoadScript = PreyFunction<bool(CEntityClass* const _this, bool bForceReload)>(0x9851E0);
	static inline auto FGetUserProxyCreateFunc = PreyFunction<std::shared_ptr<IEntityProxy> (*)(IEntity*, SEntitySpawnParams&, void*) (const CEntityClass* const _this)>(0xD87510);
	static inline auto FGetUserProxyData = PreyFunction<void* (const CEntityClass* const _this)>(0x862100);
	static inline auto FGetPropertyHandler = PreyFunction<IEntityPropertyHandler* (const CEntityClass* const _this)>(0x855C80);
	static inline auto FGetEventHandler = PreyFunction<IEntityEventHandler* (const CEntityClass* const _this)>(0x1A1FF50);
	static inline auto FGetScriptFileHandler = PreyFunction<IEntityScriptFileHandler* (const CEntityClass* const _this)>(0x9DFAA0);
	static inline auto FGetEditorClassInfo = PreyFunction<const SEditorClassInfo& (const CEntityClass* const _this)>(0x10BDA50);
	static inline auto FSetEditorClassInfo = PreyFunction<void(CEntityClass* const _this, const SEditorClassInfo& editorClassInfo)>(0x985270);
	static inline auto FGetEventCount = PreyFunction<int(CEntityClass* const _this)>(0x984F10);
	static inline auto FGetEventInfo = PreyFunction<IEntityClass::SEventInfo*(CEntityClass* const _this, IEntityClass::SEventInfo* _return_value_, int nIndex)>(0x984F80);
	static inline auto FFindEventInfo = PreyFunction<bool(CEntityClass* const _this, const char* sEvent, IEntityClass::SEventInfo& event)>(0x984E90);
	static inline auto FGetClassAttributesOv1 = PreyFunction<DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CEntityClass* const _this)>(0x10BD7D0);
	static inline auto FGetClassAttributesOv0 = PreyFunction<const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (const CEntityClass* const _this)>(0x10BD7D0);
	static inline auto FGetEntityAttributesOv1 = PreyFunction<DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CEntityClass* const _this)>(0x1F4D90);
	static inline auto FGetEntityAttributesOv0 = PreyFunction<const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (const CEntityClass* const _this)>(0x1F4D90);
	static inline auto FSetName = PreyFunction<void(CEntityClass* const _this, const char* sName)>(0x859AB0);
	static inline auto FSetScriptFile = PreyFunction<void(CEntityClass* const _this, const char* sScriptFile)>(0x9852A0);
	static inline auto FSetEntityScript = PreyFunction<void(CEntityClass* const _this, IEntityScript* pScript)>(0xEC1310);
	static inline auto FSetUserProxyCreateFunc = PreyFunction<void(CEntityClass* const _this, std::shared_ptr<IEntityProxy> (*pFunc)(IEntity*, SEntitySpawnParams&, void*), void* pUserData)>(0x9852C0);
	static inline auto FSetPropertyHandler = PreyFunction<void(CEntityClass* const _this, IEntityPropertyHandler* pPropertyHandler)>(0x16011D0);
	static inline auto FSetEventHandler = PreyFunction<void(CEntityClass* const _this, IEntityEventHandler* pEventHandler)>(0x17D3400);
	static inline auto FSetScriptFileHandler = PreyFunction<void(CEntityClass* const _this, IEntityScriptFileHandler* pScriptFileHandler)>(0x9852B0);
	static inline auto FSetEntityAttributes = PreyFunction<void(CEntityClass* const _this, const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes)>(0x985290);
	static inline auto FSetClassAttributes = PreyFunction<void(CEntityClass* const _this, const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes)>(0x985260);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CEntityClass* const _this, ICrySizer* pSizer)>(0x985130);
#else
	static inline auto FCEntityClassOv1 = PreyFunction<void(CEntityClass* const _this)>(0x9A1800);
	static inline auto FRelease = PreyFunction<void(CEntityClass* const _this)>(0x3E3960);
	static inline auto FGetFlags = PreyFunction<unsigned(const CEntityClass* const _this)>(0x899030);
	static inline auto FSetFlags = PreyFunction<void(CEntityClass* const _this, unsigned nFlags)>(0x8450C0);
	static inline auto FGetName = PreyFunction<const char* (const CEntityClass* const _this)>(0x547450);
	static inline auto FGetScriptFile = PreyFunction<const char* (const CEntityClass* const _this)>(0x598E60);
	static inline auto FGetIEntityScript = PreyFunction<IEntityScript* (const CEntityClass* const _this)>(0xD77240);
	static inline auto FGetScriptTable = PreyFunction<IScriptTable* (const CEntityClass* const _this)>(0x9A1DE0);
	static inline auto FLoadScript = PreyFunction<bool(CEntityClass* const _this, bool bForceReload)>(0x9A1DF0);
	static inline auto FGetUserProxyCreateFunc = PreyFunction<std::shared_ptr<IEntityProxy> (*)(IEntity*, SEntitySpawnParams&, void*) (const CEntityClass* const _this)>(0x7E3C90);
	static inline auto FGetUserProxyData = PreyFunction<void* (const CEntityClass* const _this)>(0x19B580);
	static inline auto FGetPropertyHandler = PreyFunction<IEntityPropertyHandler* (const CEntityClass* const _this)>(0x8715F0);
	static inline auto FGetEventHandler = PreyFunction<IEntityEventHandler* (const CEntityClass* const _this)>(0x9F24D0);
	static inline auto FGetScriptFileHandler = PreyFunction<IEntityScriptFileHandler* (const CEntityClass* const _this)>(0x20D640);
	static inline auto FGetEditorClassInfo = PreyFunction<const SEditorClassInfo& (const CEntityClass* const _this)>(0x10ED470);
	static inline auto FSetEditorClassInfo = PreyFunction<void(CEntityClass* const _this, const SEditorClassInfo& editorClassInfo)>(0x9A1E80);
	static inline auto FGetEventCount = PreyFunction<int(CEntityClass* const _this)>(0x9A1B20);
	static inline auto FGetEventInfo = PreyFunction<IEntityClass::SEventInfo*(CEntityClass* const _this, IEntityClass::SEventInfo* _return_value_, int nIndex)>(0x9A1B90);
	static inline auto FFindEventInfo = PreyFunction<bool(CEntityClass* const _this, const char* sEvent, IEntityClass::SEventInfo& event)>(0x9A1A90);
	static inline auto FGetClassAttributesOv1 = PreyFunction<DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CEntityClass* const _this)>(0x10ECF80);
	static inline auto FGetClassAttributesOv0 = PreyFunction<const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (const CEntityClass* const _this)>(0x10ECF80);
	static inline auto FGetEntityAttributesOv1 = PreyFunction<DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (CEntityClass* const _this)>(0x9A1B10);
	static inline auto FGetEntityAttributesOv0 = PreyFunction<const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& (const CEntityClass* const _this)>(0x9A1B10);
	static inline auto FSetName = PreyFunction<void(CEntityClass* const _this, const char* sName)>(0xEAFBD0);
	static inline auto FSetScriptFile = PreyFunction<void(CEntityClass* const _this, const char* sScriptFile)>(0xEAF660);
	static inline auto FSetEntityScript = PreyFunction<void(CEntityClass* const _this, IEntityScript* pScript)>(0x7FE860);
	static inline auto FSetUserProxyCreateFunc = PreyFunction<void(CEntityClass* const _this, std::shared_ptr<IEntityProxy> (*pFunc)(IEntity*, SEntitySpawnParams&, void*), void* pUserData)>(0x9A1EB0);
	static inline auto FSetPropertyHandler = PreyFunction<void(CEntityClass* const _this, IEntityPropertyHandler* pPropertyHandler)>(0x2D7D80);
	static inline auto FSetEventHandler = PreyFunction<void(CEntityClass* const _this, IEntityEventHandler* pEventHandler)>(0x18FAAB0);
	static inline auto FSetScriptFileHandler = PreyFunction<void(CEntityClass* const _this, IEntityScriptFileHandler* pScriptFileHandler)>(0x1B77490);
	static inline auto FSetEntityAttributes = PreyFunction<void(CEntityClass* const _this, const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes)>(0x9A1EA0);
	static inline auto FSetClassAttributes = PreyFunction<void(CEntityClass* const _this, const DynArray<std::shared_ptr<IEntityAttribute>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& attributes)>(0x9A1E70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CEntityClass* const _this, ICrySizer* pSizer)>(0x9A1D40);
#endif
};

