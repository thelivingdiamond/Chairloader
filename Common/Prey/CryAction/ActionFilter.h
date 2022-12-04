// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ActionFilter.h>
#include <Prey/CryAction/IActionMapManager.h>

class CActionMapManager;
class CCryName;
class ICrySizer;
struct IInput;
class XmlNodeRef;

// Header: FromCpp
// CryEngine/cryaction/actionfilter.h
class CActionFilter : public IActionFilter // Id=80044A0 Size=64
{
public:
    bool m_enabled;
    CActionMapManager *m_pActionMapManager;
    IInput *m_pInput;
    std::set<CCryName,std::less<CCryName>> m_filterActions;
    EActionFilterType m_type;
    string m_name;

    CActionFilter(CActionMapManager *pActionMapManager, IInput *pInput, const char *name, EActionFilterType type);
    virtual ~CActionFilter();
    virtual void Release();
    virtual void Filter(CCryName const &action);
    virtual void ClearFilters();
    virtual bool SerializeXML(XmlNodeRef const &root, bool bLoading);
    virtual const char *GetName();
    virtual void Enable(bool enable);
    virtual bool Enabled();
    bool ActionFiltered(CCryName const &action) { return FActionFiltered(this,action); }
    virtual void GetMemoryUsage(ICrySizer *s) const;

    static inline auto FRelease = PreyFunction<void(CActionFilter *const _this)>(0xA97D40);
    static inline auto FFilter = PreyFunction<void(CActionFilter *const _this, CCryName const &action)>(0x3C32B0);
    static inline auto FClearFilters = PreyFunction<void(CActionFilter *const _this)>(0x3C3170);
    static inline auto FSerializeXML = PreyFunction<bool(CActionFilter *const _this, XmlNodeRef const &root, bool bLoading)>(0x3C33B0);
    static inline auto FGetName = PreyFunction<const char *(CActionFilter *const _this)>(0x864AF0);
    static inline auto FEnable = PreyFunction<void(CActionFilter *const _this, bool enable)>(0x3C31B0);
    static inline auto FEnabled = PreyFunction<bool(CActionFilter *const _this)>(0xAAD760);
    static inline auto FActionFiltered = PreyFunction<bool(CActionFilter *const _this, CCryName const &action)>(0x3C3040);
    static inline auto FGetMemoryUsage = PreyFunction<void(CActionFilter const *const _this, ICrySizer *s)>(0x3C32E0);
};

