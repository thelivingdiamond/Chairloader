#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Chairloader/PreyFunction.h>


class CAutoRegFlowNodeBase : public IFlowNodeFactory // Id=8005975 Size=24
{
public:
    const char *m_sClassName;
    CAutoRegFlowNodeBase *m_pNext;
    static inline auto m_pFirst = PreyGlobal<CAutoRegFlowNodeBase *>(0x24808D0);
    static inline auto m_pLast = PreyGlobal<CAutoRegFlowNodeBase *>(0x24808D8);

    virtual ~CAutoRegFlowNodeBase();
    virtual void AddRef();
    virtual void Release();
    virtual void Reset();
    virtual void GetMemoryUsage(ICrySizer *s) const;

    static inline auto FBitNotCAutoRegFlowNodeBase = PreyFunction<void(CAutoRegFlowNodeBase *const _this)>(0x2B1BF0);
    static inline auto FAddRef = PreyFunction<void(CAutoRegFlowNodeBase *const _this)>(0xA13080);
    static inline auto FRelease = PreyFunction<void(CAutoRegFlowNodeBase *const _this)>(0xA13080);
    static inline auto FReset = PreyFunction<void(CAutoRegFlowNodeBase *const _this)>(0xA13080);
    static inline auto FGetMemoryUsage = PreyFunction<void(CAutoRegFlowNodeBase const *const _this, ICrySizer *s)>(0x2B0D00);
};

template<class T>
class CAutoRegFlowNode : public CAutoRegFlowNodeBase
{
public:
//    CAutoRegFlowNode(const char* szClassName)
//            : CAutoRegFlowNodeBase(szClassName)
//    {
//    }

//    IFlowNodePtr Create(IFlowNode::SActivationInfo* pActInfo)
//    {
//        PREFAST_SUPPRESS_WARNING(6326)
//        if (T::myCloneType == eNCT_Singleton)
//        {
//            if (!m_pInstance.get())
//                m_pInstance = new T(pActInfo);
//
//            return m_pInstance;
//        }
//        else if (T::myCloneType == eNCT_Instanced)
//        {
//            return new T(pActInfo);
//        }
//        else
//        {
//            CRY_ASSERT(false);
//        }
//    }

//    static inline auto FCreate = PreyFunction<IFlowNodePtr(CAutoRegFlowNode<T> *const _this, IFlowNode::SActivationInfo *pActInfo)>(0x2B1C00);
public:
    IFlowNodePtr m_pInstance; // only applies for singleton nodes
};

#if CRY_PLATFORM_WINDOWS && defined(_LIB)
#define CRY_EXPORT_STATIC_LINK_VARIABLE(Var)                        \
	  extern "C" { INT_PTR lib_func_ ## Var() { return (INT_PTR)&Var; } \
	  }                                                                 \
	  __pragma(message("#pragma comment(linker,\"/include:_lib_func_" # Var "\")"))
#else
#define CRY_EXPORT_STATIC_LINK_VARIABLE(Var)
#endif

//////////////////////////////////////////////////////////////////////////
// Use this define to register a new flow node class. Handles
//	both instanced and singleton nodes
// Ex. REGISTER_FLOW_NODE( "Delay",CFlowDelayNode )
//////////////////////////////////////////////////////////////////////////
#define REGISTER_FLOW_NODE(FlowNodeClassName, FlowNodeClass)                     \
  CAutoRegFlowNode<FlowNodeClass> g_AutoReg ## FlowNodeClass(FlowNodeClassName); \
  CRY_EXPORT_STATIC_LINK_VARIABLE(g_AutoReg ## FlowNodeClass);

// macro similar to REGISTER_FLOW_NODE, but allows a different name for registration
#define REGISTER_FLOW_NODE_EX(FlowNodeClassName, FlowNodeClass, RegName)   \
  CAutoRegFlowNode<FlowNodeClass> g_AutoReg ## RegName(FlowNodeClassName); \
  CRY_EXPORT_STATIC_LINK_VARIABLE(g_AutoReg ## RegName);