// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct IActor;
class ICrySizer;
class XmlNodeRef;

// CAutoRegFlowNodeBase
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
// Include: Prey/CryFlowGraph/IFlowBaseNode.h
class CAutoRegFlowNodeBase : public IFlowNodeFactory
{ // Size=24 (0x18)
public:
	const char* m_sClassName;
	CAutoRegFlowNodeBase* m_pNext;
	static inline auto m_pFirst = PreyGlobal<CAutoRegFlowNodeBase*>(0x25EFEF0);
	static inline auto m_pLast = PreyGlobal<CAutoRegFlowNodeBase*>(0x25EFEF8);

	virtual ~CAutoRegFlowNodeBase();
	virtual void AddRef();
	virtual void Release();
	virtual void Reset();
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CAutoRegFlowNodeBase(const char* _arg0_);
#endif

	static inline auto FBitNotCAutoRegFlowNodeBase = PreyFunction<void(CAutoRegFlowNodeBase* const _this)>(0x2C4CD0);
	static inline auto FAddRef = PreyFunction<void(CAutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FRelease = PreyFunction<void(CAutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FReset = PreyFunction<void(CAutoRegFlowNodeBase* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAutoRegFlowNodeBase* const _this, ICrySizer* s)>(0x2BF8C0);
};

// CAutoRegFlowNode<ArkFlowNodeResetLevel>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<ArkFlowNodeResetLevel> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<ArkFlowNodeResetLevel>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<ArkFlowNodeResetLevel>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2BFE10);
};

// CAutoRegFlowNode<CClipCaptureManagement>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CClipCaptureManagement> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CClipCaptureManagement>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CClipCaptureManagement>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x34AA90);
};

// CAutoRegFlowNode<CComputeLighting_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CComputeLighting_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CComputeLighting_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CComputeLighting_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4387B0);
};

// CAutoRegFlowNode<CComputeStaticShadows_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CComputeStaticShadows_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CComputeStaticShadows_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CComputeStaticShadows_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x438840);
};

// CAutoRegFlowNode<CDeMultiplexer_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CDeMultiplexer_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CDeMultiplexer_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CDeMultiplexer_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C3270);
};

// CAutoRegFlowNode<CFlashUIArrayConcatNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIArrayConcatNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIArrayConcatNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIArrayConcatNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x302670);
};

// CAutoRegFlowNode<CFlashUIFromArrayExNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIFromArrayExNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIFromArrayExNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIFromArrayExNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x3025E0);
};

// CAutoRegFlowNode<CFlashUIFromArrayNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIFromArrayNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIFromArrayNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIFromArrayNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x302550);
};

// CAutoRegFlowNode<CFlashUIMCTemplateRemoveNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIMCTemplateRemoveNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIMCTemplateRemoveNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIMCTemplateRemoveNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x323870);
};

// CAutoRegFlowNode<CFlashUIPlatformNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIPlatformNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIPlatformNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIPlatformNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x32E5C0);
};

// CAutoRegFlowNode<CFlashUIToArrayNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlashUIToArrayNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlashUIToArrayNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlashUIToArrayNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x3024C0);
};

// CAutoRegFlowNode<CFlowActorGetHealth>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowActorGetHealth> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowActorGetHealth>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowActorGetHealth>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46FAC0);
};

// CAutoRegFlowNode<CFlowActorSetHealth>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowActorSetHealth> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowActorSetHealth>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowActorSetHealth>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46FB50);
};

// CAutoRegFlowNode<CFlowAllPlayers>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowAllPlayers> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowAllPlayers>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowAllPlayers>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4712F0);
};

// CAutoRegFlowNode<CFlowDamageEntity>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowDamageEntity> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowDamageEntity>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowDamageEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x471410);
};

// CAutoRegFlowNode<CFlowFlashInvokeNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowFlashInvokeNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowFlashInvokeNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowFlashInvokeNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46E7F0);
};

// CAutoRegFlowNode<CFlowImageNode<SArkFilterDistortion> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SArkFilterDistortion> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SArkFilterDistortion> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SArkFilterDistortion> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x442A00);
};

// CAutoRegFlowNode<CFlowImageNode<SColorCorrection> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SColorCorrection> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SColorCorrection> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SColorCorrection> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4431C0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffect3DHudInterference> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffect3DHudInterference> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffect3DHudInterference> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffect3DHudInterference> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4483F0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectAlienInterference> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectAlienInterference> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectAlienInterference> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectAlienInterference> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x447070);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectBloodSplats> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectBloodSplats> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectBloodSplats> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectBloodSplats> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x445860);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectCondensation> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectCondensation> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectCondensation> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectCondensation> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x444CC0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectDirectionalBlur> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectDirectionalBlur> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectDirectionalBlur> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectDirectionalBlur> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x446C80);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectDistantRain> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectDistantRain> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectDistantRain> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectDistantRain> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x447870);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectDof> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectDof> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectDof> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectDof> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4464C0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectFrost> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectFrost> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectFrost> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectFrost> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x444500);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectGhostVision> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectGhostVision> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectGhostVision> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectGhostVision> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x446020);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectGhosting> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectGhosting> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectGhosting> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectGhosting> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x445C40);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectHUDScratches> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectHUDScratches> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectHUDScratches> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectHUDScratches> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x442270);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectRainDrops> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectRainDrops> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectRainDrops> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectRainDrops> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x447470);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectVolumetricScattering> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectVolumetricScattering> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectVolumetricScattering> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectVolumetricScattering> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4468A0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectWaterDroplets> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectWaterDroplets> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectWaterDroplets> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectWaterDroplets> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4450A0);
};

// CAutoRegFlowNode<CFlowImageNode<SEffectWaterFlow> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SEffectWaterFlow> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SEffectWaterFlow> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SEffectWaterFlow> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x445480);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterBlur> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterBlur> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterBlur> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterBlur> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x443580);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterChromaShift> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterChromaShift> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterChromaShift> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterChromaShift> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x444120);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterGrain> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterGrain> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterGrain> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterGrain> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4448E0);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterRadialBlur> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterRadialBlur> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterRadialBlur> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterRadialBlur> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x443960);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterSharpen> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterSharpen> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterSharpen> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterSharpen> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x443D40);
};

// CAutoRegFlowNode<CFlowImageNode<SFilterVisualArtifacts> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SFilterVisualArtifacts> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SFilterVisualArtifacts> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SFilterVisualArtifacts> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x448030);
};

// CAutoRegFlowNode<CFlowImageNode<SGlow> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SGlow> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SGlow> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SGlow> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x447C50);
};

// CAutoRegFlowNode<CFlowImageNode<SHUDHitEffect> >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowImageNode<SHUDHitEffect> > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowImageNode<SHUDHitEffect> >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowImageNode<SHUDHitEffect> >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x442650);
};

// CAutoRegFlowNode<CFlowIsPlayer>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowIsPlayer> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowIsPlayer>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowIsPlayer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x471380);
};

// CAutoRegFlowNode<CFlowLogInput>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowLogInput> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowLogInput>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowLogInput>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x481240);
};

// CAutoRegFlowNode<CFlowModuleUserIdNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowModuleUserIdNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowModuleUserIdNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowModuleUserIdNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x33B360);
};

// CAutoRegFlowNode<CFlowNodeEntityCloneMaterial>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeEntityCloneMaterial> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeEntityCloneMaterial>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeEntityCloneMaterial>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x34DD40);
};

// CAutoRegFlowNode<CFlowNodeEntityCloneMaterialOld>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeEntityCloneMaterialOld> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeEntityCloneMaterialOld>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeEntityCloneMaterialOld>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4592C0);
};

// CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParam>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParam> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParam>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParam>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x458F00);
};

// CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParams>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParams> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParams>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeEntityMaterialShaderParams>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x34DC90);
};

// CAutoRegFlowNode<CFlowNodeMaterialShaderParam>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeMaterialShaderParam> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeMaterialShaderParam>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeMaterialShaderParam>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45AF30);
};

// CAutoRegFlowNode<CFlowNodeMaterialShaderParamSerialize>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeMaterialShaderParamSerialize> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeMaterialShaderParamSerialize>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeMaterialShaderParamSerialize>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45AFC0);
};

// CAutoRegFlowNode<CFlowNodeMaterialShaderParams>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeMaterialShaderParams> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeMaterialShaderParams>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeMaterialShaderParams>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x34DC00);
};

// CAutoRegFlowNode<CFlowNodeRenderParams>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNodeRenderParams> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNodeRenderParams>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNodeRenderParams>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x458E90);
};

// CAutoRegFlowNode<CFlowNode_AIAlertnessFilter>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIAlertnessFilter> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIAlertnessFilter>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIAlertnessFilter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4993B0);
};

// CAutoRegFlowNode<CFlowNode_AIAnim>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIAnim> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIAnim>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIAnim>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49AC90);
};

// CAutoRegFlowNode<CFlowNode_AIAnimEx>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIAnimEx> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIAnimEx>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIAnimEx>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49ACE0);
};

// CAutoRegFlowNode<CFlowNode_AIAttTarget>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIAttTarget> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIAttTarget>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIAttTarget>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x494450);
};

// CAutoRegFlowNode<CFlowNode_AIAutoDisable>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIAutoDisable> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIAutoDisable>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIAutoDisable>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4946A0);
};

// CAutoRegFlowNode<CFlowNode_AIChangeParameter>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIChangeParameter> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIChangeParameter>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIChangeParameter>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x494610);
};

// CAutoRegFlowNode<CFlowNode_AICheckStates>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AICheckStates> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AICheckStates>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AICheckStates>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A280);
};

// CAutoRegFlowNode<CFlowNode_AIEnable>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIEnable> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIEnable>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIEnable>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x499440);
};

// CAutoRegFlowNode<CFlowNode_AIEnableShape>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIEnableShape> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIEnableShape>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIEnableShape>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x494730);
};

// CAutoRegFlowNode<CFlowNode_AIFollowPath>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIFollowPath> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIFollowPath>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIFollowPath>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49AD30);
};

// CAutoRegFlowNode<CFlowNode_AIFollowPathSpeedStance>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIFollowPathSpeedStance> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIFollowPathSpeedStance>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIFollowPathSpeedStance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x499750);
};

// CAutoRegFlowNode<CFlowNode_AIGoto>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIGoto> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIGoto>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIGoto>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A2D0);
};

// CAutoRegFlowNode<CFlowNode_AIGotoSpeedStance>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIGotoSpeedStance> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIGotoSpeedStance>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIGotoSpeedStance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A320);
};

// CAutoRegFlowNode<CFlowNode_AIIgnore>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIIgnore> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIIgnore>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIIgnore>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4994D0);
};

// CAutoRegFlowNode<CFlowNode_AIIsAliveCheck>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIIsAliveCheck> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIIsAliveCheck>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIIsAliveCheck>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4947C0);
};

// CAutoRegFlowNode<CFlowNode_AILookAt>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AILookAt> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AILookAt>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AILookAt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A570);
};

// CAutoRegFlowNode<CFlowNode_AILookAtPoint>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AILookAtPoint> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AILookAtPoint>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AILookAtPoint>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A370);
};

// CAutoRegFlowNode<CFlowNode_AIModifyStates>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIModifyStates> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIModifyStates>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIModifyStates>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A230);
};

// CAutoRegFlowNode<CFlowNode_AIPerceptionScale>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIPerceptionScale> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIPerceptionScale>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIPerceptionScale>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x494580);
};

// CAutoRegFlowNode<CFlowNode_AIRegenerateMNM>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIRegenerateMNM> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIRegenerateMNM>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIRegenerateMNM>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x494850);
};

// CAutoRegFlowNode<CFlowNode_AIShootAt>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIShootAt> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIShootAt>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIShootAt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x499840);
};

// CAutoRegFlowNode<CFlowNode_AISpeed>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AISpeed> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AISpeed>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AISpeed>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A8D0);
};

// CAutoRegFlowNode<CFlowNode_AIStance>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIStance> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIStance>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIStance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A880);
};

// CAutoRegFlowNode<CFlowNode_AIWeaponDraw>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIWeaponDraw> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIWeaponDraw>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIWeaponDraw>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4997A0);
};

// CAutoRegFlowNode<CFlowNode_AIWeaponHolster>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIWeaponHolster> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIWeaponHolster>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIWeaponHolster>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4997F0);
};

// CAutoRegFlowNode<CFlowNode_AIWeaponSelect>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AIWeaponSelect> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AIWeaponSelect>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AIWeaponSelect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x499890);
};

// CAutoRegFlowNode<CFlowNode_Abs>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Abs> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Abs>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Abs>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x481E50);
};

// CAutoRegFlowNode<CFlowNode_ActionImpulse>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ActionImpulse> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ActionImpulse>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ActionImpulse>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF630);
};

// CAutoRegFlowNode<CFlowNode_Add>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Add> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Add>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Add>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48E1E0);
};

// CAutoRegFlowNode<CFlowNode_AddVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AddVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AddVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AddVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x488D10);
};

// CAutoRegFlowNode<CFlowNode_All>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_All> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_All>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_All>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CBA0);
};

// CAutoRegFlowNode<CFlowNode_AnglesToDir>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_AnglesToDir> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_AnglesToDir>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_AnglesToDir>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x482A80);
};

// CAutoRegFlowNode<CFlowNode_Any>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Any> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Any>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Any>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CB10);
};

// CAutoRegFlowNode<CFlowNode_ArkCompare>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ArkCompare> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ArkCompare>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ArkCompare>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CDC0);
};

// CAutoRegFlowNode<CFlowNode_BeamEntity>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_BeamEntity> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_BeamEntity>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_BeamEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x458E00);
};

// CAutoRegFlowNode<CFlowNode_BroadcastEntityEvent>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_BroadcastEntityEvent> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_BroadcastEntityEvent>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_BroadcastEntityEvent>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4647D0);
};

// CAutoRegFlowNode<CFlowNode_CVar>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CVar> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CVar>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CVar>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x43F380);
};

// CAutoRegFlowNode<CFlowNode_Calculate>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Calculate> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Calculate>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Calculate>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4864D0);
};

// CAutoRegFlowNode<CFlowNode_CalculateVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CalculateVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CalculateVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CalculateVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48D4E0);
};

// CAutoRegFlowNode<CFlowNode_Camera>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Camera> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Camera>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Camera>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x43D180);
};

// CAutoRegFlowNode<CFlowNode_CameraProxy>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CameraProxy> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CameraProxy>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CameraProxy>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF910);
};

// CAutoRegFlowNode<CFlowNode_CameraViewShake>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CameraViewShake> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CameraViewShake>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CameraViewShake>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x43D210);
};

// CAutoRegFlowNode<CFlowNode_Clamp>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Clamp> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Clamp>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Clamp>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4821D0);
};

// CAutoRegFlowNode<CFlowNode_ClampVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ClampVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ClampVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ClampVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48CA00);
};

// CAutoRegFlowNode<CFlowNode_ColliderMode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ColliderMode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ColliderMode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ColliderMode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4942D0);
};

// CAutoRegFlowNode<CFlowNode_CompareStrings>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CompareStrings> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CompareStrings>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CompareStrings>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4B8C90);
};

// CAutoRegFlowNode<CFlowNode_Condition>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Condition> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Condition>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Condition>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x43ED00);
};

// CAutoRegFlowNode<CFlowNode_Constraint>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Constraint> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Constraint>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Constraint>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF870);
};

// CAutoRegFlowNode<CFlowNode_Cos>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Cos> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Cos>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Cos>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x484F50);
};

// CAutoRegFlowNode<CFlowNode_CosInverse>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CosInverse> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CosInverse>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CosInverse>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x485C50);
};

// CAutoRegFlowNode<CFlowNode_CrossVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CrossVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CrossVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CrossVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4899C0);
};

// CAutoRegFlowNode<CFlowNode_CustomActionEnd>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CustomActionEnd> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CustomActionEnd>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CustomActionEnd>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x351B40);
};

// CAutoRegFlowNode<CFlowNode_CustomActionStart>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CustomActionStart> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CustomActionStart>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CustomActionStart>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x351900);
};

// CAutoRegFlowNode<CFlowNode_CustomActionSucceed>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CustomActionSucceed> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CustomActionSucceed>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CustomActionSucceed>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x351990);
};

// CAutoRegFlowNode<CFlowNode_CustomActionSucceedWait>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CustomActionSucceedWait> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CustomActionSucceedWait>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CustomActionSucceedWait>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x351A20);
};

// CAutoRegFlowNode<CFlowNode_CustomActionSucceedWaitComplete>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_CustomActionSucceedWaitComplete> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_CustomActionSucceedWaitComplete>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_CustomActionSucceedWaitComplete>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x351AB0);
};

// CAutoRegFlowNode<CFlowNode_DebugAISpeed>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DebugAISpeed> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DebugAISpeed>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DebugAISpeed>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x49A920);
};

// CAutoRegFlowNode<CFlowNode_DirToAngles>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DirToAngles> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DirToAngles>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DirToAngles>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x482E50);
};

// CAutoRegFlowNode<CFlowNode_Div>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Div> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Div>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Div>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48F470);
};

// CAutoRegFlowNode<CFlowNode_DotVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DotVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DotVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DotVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48AA60);
};

// CAutoRegFlowNode<CFlowNode_DrawAABB>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawAABB> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawAABB>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawAABB>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3CD0);
};

// CAutoRegFlowNode<CFlowNode_DrawCone>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawCone> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawCone>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawCone>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3A40);
};

// CAutoRegFlowNode<CFlowNode_DrawCylinder>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawCylinder> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawCylinder>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawCylinder>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3AD0);
};

// CAutoRegFlowNode<CFlowNode_DrawDirection>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawDirection> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawDirection>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawDirection>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D39B0);
};

// CAutoRegFlowNode<CFlowNode_DrawLine>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawLine> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawLine>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawLine>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3B60);
};

// CAutoRegFlowNode<CFlowNode_DrawPlanarDisc>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawPlanarDisc> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawPlanarDisc>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawPlanarDisc>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3D60);
};

// CAutoRegFlowNode<CFlowNode_DrawSphere>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_DrawSphere> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_DrawSphere>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_DrawSphere>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2D3C40);
};

// CAutoRegFlowNode<CFlowNode_Dynamics>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Dynamics> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Dynamics>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Dynamics>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF5A0);
};

// CAutoRegFlowNode<CFlowNode_EndLevel>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EndLevel> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EndLevel>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EndLevel>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x493A60);
};

// CAutoRegFlowNode<CFlowNode_EntityAttachChild>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityAttachChild> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityAttachChild>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityAttachChild>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4667D0);
};

// CAutoRegFlowNode<CFlowNode_EntityCheckDistance>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityCheckDistance> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityCheckDistance>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityCheckDistance>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4597E0);
};

// CAutoRegFlowNode<CFlowNode_EntityDetachThis>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityDetachThis> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityDetachThis>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityDetachThis>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x457DC0);
};

// CAutoRegFlowNode<CFlowNode_EntityFaceAt>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityFaceAt> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityFaceAt>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityFaceAt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45AEC0);
};

// CAutoRegFlowNode<CFlowNode_EntityGetBounds>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityGetBounds> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityGetBounds>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityGetBounds>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45A770);
};

// CAutoRegFlowNode<CFlowNode_EntityGetInfo>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityGetInfo> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityGetInfo>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityGetInfo>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x464B00);
};

// CAutoRegFlowNode<CFlowNode_EntityGetPlayer>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityGetPlayer> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityGetPlayer>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityGetPlayer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x458D70);
};

// CAutoRegFlowNode<CFlowNode_EntityGetPos>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityGetPos> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityGetPos>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityGetPos>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4644F0);
};

// CAutoRegFlowNode<CFlowNode_EntityGetProperty>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityGetProperty> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityGetProperty>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityGetProperty>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4650F0);
};

// CAutoRegFlowNode<CFlowNode_EntityId>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityId> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityId>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityId>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x464A90);
};

// CAutoRegFlowNode<CFlowNode_EntityMaterial>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityMaterial> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityMaterial>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityMaterial>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x465540);
};

// CAutoRegFlowNode<CFlowNode_EntityMaterialLayer>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityMaterialLayer> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityMaterialLayer>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityMaterialLayer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x466740);
};

// CAutoRegFlowNode<CFlowNode_EntityMaterialSerialize>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityMaterialSerialize> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityMaterialSerialize>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityMaterialSerialize>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x466670);
};

// CAutoRegFlowNode<CFlowNode_EntityPool>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityPool> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityPool>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityPool>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45AE30);
};

// CAutoRegFlowNode<CFlowNode_EntityPos>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityPos> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityPos>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityPos>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x463980);
};

// CAutoRegFlowNode<CFlowNode_EntitySetProperty>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntitySetProperty> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntitySetProperty>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntitySetProperty>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x465010);
};

// CAutoRegFlowNode<CFlowNode_EntityTagpoint>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EntityTagpoint> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EntityTagpoint>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EntityTagpoint>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x459350);
};

// CAutoRegFlowNode<CFlowNode_EnvLighting>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EnvLighting> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EnvLighting>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EnvLighting>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46DDF0);
};

// CAutoRegFlowNode<CFlowNode_EnvSun>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EnvSun> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EnvSun>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EnvSun>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46DE80);
};

// CAutoRegFlowNode<CFlowNode_EnvWind>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EnvWind> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EnvWind>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EnvWind>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46DF70);
};

// CAutoRegFlowNode<CFlowNode_Equal>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Equal> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Equal>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Equal>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48F9A0);
};

// CAutoRegFlowNode<CFlowNode_EqualCheck>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EqualCheck> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EqualCheck>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EqualCheck>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x490000);
};

// CAutoRegFlowNode<CFlowNode_EqualVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_EqualVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_EqualVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_EqualVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48B520);
};

// CAutoRegFlowNode<CFlowNode_ExecuteString>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ExecuteString> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ExecuteString>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ExecuteString>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46E760);
};

// CAutoRegFlowNode<CFlowNode_FloatToString>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_FloatToString> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_FloatToString>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_FloatToString>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x486560);
};

// CAutoRegFlowNode<CFlowNode_ForceFeedback>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ForceFeedback> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ForceFeedback>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ForceFeedback>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x474980);
};

// CAutoRegFlowNode<CFlowNode_ForceFeedbackTriggerTweaker>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ForceFeedbackTriggerTweaker> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ForceFeedbackTriggerTweaker>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ForceFeedbackTriggerTweaker>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x474AA0);
};

// CAutoRegFlowNode<CFlowNode_ForceFeedbackTweaker>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ForceFeedbackTweaker> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ForceFeedbackTweaker>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ForceFeedbackTweaker>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x474A10);
};

// CAutoRegFlowNode<CFlowNode_FromBoolean>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_FromBoolean> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_FromBoolean>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_FromBoolean>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4839F0);
};

// CAutoRegFlowNode<CFlowNode_FromVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_FromVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_FromVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_FromVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48C1B0);
};

// CAutoRegFlowNode<CFlowNode_InRange>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_InRange> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_InRange>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_InRange>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x490500);
};

// CAutoRegFlowNode<CFlowNode_LayerSwitch>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_LayerSwitch> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_LayerSwitch>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_LayerSwitch>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x455960);
};

// CAutoRegFlowNode<CFlowNode_Less>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Less> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Less>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Less>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x490940);
};

// CAutoRegFlowNode<CFlowNode_LessCheck>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_LessCheck> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_LessCheck>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_LessCheck>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x490CA0);
};

// CAutoRegFlowNode<CFlowNode_LookAt>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_LookAt> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_LookAt>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_LookAt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C91E0);
};

// CAutoRegFlowNode<CFlowNode_MagnitudeVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_MagnitudeVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_MagnitudeVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_MagnitudeVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48BCA0);
};

// CAutoRegFlowNode<CFlowNode_MathSetString>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_MathSetString> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_MathSetString>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_MathSetString>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4B8B70);
};

// CAutoRegFlowNode<CFlowNode_Mul>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Mul> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Mul>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Mul>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48ED20);
};

// CAutoRegFlowNode<CFlowNode_MulVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_MulVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_MulVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_MulVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x489560);
};

// CAutoRegFlowNode<CFlowNode_NOT>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_NOT> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_NOT>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_NOT>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CA80);
};

// CAutoRegFlowNode<CFlowNode_NoAiming>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_NoAiming> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_NoAiming>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_NoAiming>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C9300);
};

// CAutoRegFlowNode<CFlowNode_Noise1D>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Noise1D> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Noise1D>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Noise1D>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AA820);
};

// CAutoRegFlowNode<CFlowNode_Noise3D>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Noise3D> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Noise3D>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Noise3D>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AA8B0);
};

// CAutoRegFlowNode<CFlowNode_NormalizeVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_NormalizeVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_NormalizeVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_NormalizeVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48ADA0);
};

// CAutoRegFlowNode<CFlowNode_OnlineAttributes>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_OnlineAttributes> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_OnlineAttributes>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_OnlineAttributes>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x355570);
};

// CAutoRegFlowNode<CFlowNode_ParentId>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ParentId> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ParentId>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ParentId>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x464F10);
};

// CAutoRegFlowNode<CFlowNode_PhysicsEnable>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_PhysicsEnable> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_PhysicsEnable>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_PhysicsEnable>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF7E0);
};

// CAutoRegFlowNode<CFlowNode_Platform>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Platform> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Platform>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Platform>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4B14B0);
};

// CAutoRegFlowNode<CFlowNode_Power>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Power> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Power>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Power>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4815B0);
};

// CAutoRegFlowNode<CFlowNode_PrecacheArea>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_PrecacheArea> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_PrecacheArea>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_PrecacheArea>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x455A50);
};

// CAutoRegFlowNode<CFlowNode_ProfileAttribute>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ProfileAttribute> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ProfileAttribute>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ProfileAttribute>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x3554E0);
};

// CAutoRegFlowNode<CFlowNode_Random>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Random> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Random>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Random>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x492650);
};

// CAutoRegFlowNode<CFlowNode_RandomSelect>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_RandomSelect> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_RandomSelect>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_RandomSelect>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CBF0);
};

// CAutoRegFlowNode<CFlowNode_RandomTrigger>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_RandomTrigger> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_RandomTrigger>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_RandomTrigger>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47CC80);
};

// CAutoRegFlowNode<CFlowNode_Raycast>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Raycast> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Raycast>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Raycast>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF6C0);
};

// CAutoRegFlowNode<CFlowNode_RaycastCamera>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_RaycastCamera> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_RaycastCamera>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_RaycastCamera>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4AF750);
};

// CAutoRegFlowNode<CFlowNode_ReadStereoParameters>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ReadStereoParameters> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ReadStereoParameters>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ReadStereoParameters>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4A9B30);
};

// CAutoRegFlowNode<CFlowNode_Reciprocal>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Reciprocal> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Reciprocal>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Reciprocal>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x492210);
};

// CAutoRegFlowNode<CFlowNode_ReciprocalVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ReciprocalVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ReciprocalVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ReciprocalVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48C580);
};

// CAutoRegFlowNode<CFlowNode_Remainder>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Remainder> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Remainder>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Remainder>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x491750);
};

// CAutoRegFlowNode<CFlowNode_Round>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Round> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Round>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Round>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48DE40);
};

// CAutoRegFlowNode<CFlowNode_ScaleVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ScaleVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ScaleVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ScaleVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48B490);
};

// CAutoRegFlowNode<CFlowNode_Select2>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Select2> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Select2>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Select2>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x491C30);
};

// CAutoRegFlowNode<CFlowNode_SetColor>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetColor> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetColor>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetColor>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4846D0);
};

// CAutoRegFlowNode<CFlowNode_SetDefaultActionEntity>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetDefaultActionEntity> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetDefaultActionEntity>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetDefaultActionEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2CF790);
};

// CAutoRegFlowNode<CFlowNode_SetNumber>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetNumber> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetNumber>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetNumber>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4831B0);
};

// CAutoRegFlowNode<CFlowNode_SetOceanMat>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetOceanMat> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetOceanMat>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetOceanMat>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46E000);
};

// CAutoRegFlowNode<CFlowNode_SetShadowMode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetShadowMode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetShadowMode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetShadowMode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x442E00);
};

// CAutoRegFlowNode<CFlowNode_SetString>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetString> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetString>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetString>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4B8C00);
};

// CAutoRegFlowNode<CFlowNode_SetVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SetVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SetVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SetVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48CA90);
};

// CAutoRegFlowNode<CFlowNode_Sin>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Sin> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Sin>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Sin>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x484AB0);
};

// CAutoRegFlowNode<CFlowNode_SinCos>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SinCos> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SinCos>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SinCos>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4825D0);
};

// CAutoRegFlowNode<CFlowNode_SinInverse>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SinInverse> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SinInverse>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SinInverse>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4858F0);
};

// CAutoRegFlowNode<CFlowNode_SkyMaterialSwitch>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SkyMaterialSwitch> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SkyMaterialSwitch>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SkyMaterialSwitch>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x46B3D0);
};

// CAutoRegFlowNode<CFlowNode_SpawnArchetypeEntity>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SpawnArchetypeEntity> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SpawnArchetypeEntity>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SpawnArchetypeEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45BAD0);
};

// CAutoRegFlowNode<CFlowNode_SpawnEntity>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SpawnEntity> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SpawnEntity>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SpawnEntity>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x45B610);
};

// CAutoRegFlowNode<CFlowNode_Sqrt>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Sqrt> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Sqrt>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Sqrt>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x481AD0);
};

// CAutoRegFlowNode<CFlowNode_StopAnimation>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_StopAnimation> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_StopAnimation>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_StopAnimation>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C9270);
};

// CAutoRegFlowNode<CFlowNode_StringConcat>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_StringConcat> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_StringConcat>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_StringConcat>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4B8D20);
};

// CAutoRegFlowNode<CFlowNode_Sub>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Sub> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Sub>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Sub>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48E980);
};

// CAutoRegFlowNode<CFlowNode_SubVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SubVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SubVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SubVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x488DF0);
};

// CAutoRegFlowNode<CFlowNode_SynchronizeTwoAnimations>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_SynchronizeTwoAnimations> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_SynchronizeTwoAnimations>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_SynchronizeTwoAnimations>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C9390);
};

// CAutoRegFlowNode<CFlowNode_Tan>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Tan> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Tan>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Tan>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4852B0);
};

// CAutoRegFlowNode<CFlowNode_TanInverse>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_TanInverse> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_TanInverse>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_TanInverse>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x485CE0);
};

// CAutoRegFlowNode<CFlowNode_TimeOfDay>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_TimeOfDay> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_TimeOfDay>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_TimeOfDay>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4BCE20);
};

// CAutoRegFlowNode<CFlowNode_TimeOfDay_LoadDefinitionFile>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_TimeOfDay_LoadDefinitionFile> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_TimeOfDay_LoadDefinitionFile>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_TimeOfDay_LoadDefinitionFile>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4BCD90);
};

// CAutoRegFlowNode<CFlowNode_ToBoolean>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ToBoolean> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ToBoolean>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ToBoolean>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x483690);
};

// CAutoRegFlowNode<CFlowNode_ToVec3>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_ToVec3> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_ToVec3>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_ToVec3>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x48BD30);
};

// CAutoRegFlowNode<CFlowNode_TriggerOnKeyTime>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_TriggerOnKeyTime> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_TriggerOnKeyTime>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_TriggerOnKeyTime>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C9420);
};

// CAutoRegFlowNode<CFlowNode_Viewport>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowNode_Viewport> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowNode_Viewport>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowNode_Viewport>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x455AE0);
};

// CAutoRegFlowNode<CFlowPlayMannequinFragment>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowPlayMannequinFragment> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowPlayMannequinFragment>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowPlayMannequinFragment>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x2DA210);
};

// CAutoRegFlowNode<CFlowPlayer>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowPlayer> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowPlayer>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowPlayer>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x471260);
};

// CAutoRegFlowNode<CFlowSmoothNode<Vec3_tpl<float>,Limits<Vec3_tpl<float> > > >
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowSmoothNode<Vec3_tpl<float>,Limits<Vec3_tpl<float> > > > : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowSmoothNode<Vec3_tpl<float>,Limits<Vec3_tpl<float> > > >(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowSmoothNode<Vec3_tpl<float>,Limits<Vec3_tpl<float> > > >* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x47A640);
};

// CAutoRegFlowNode<CFlowTimeNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CFlowTimeNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CFlowTimeNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CFlowTimeNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4BCCA0);
};

// CAutoRegFlowNode<CHUDEndFXNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CHUDEndFXNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CHUDEndFXNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CHUDEndFXNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x5302D0);
};

// CAutoRegFlowNode<CHUDStartFXNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CHUDStartFXNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CHUDStartFXNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CHUDStartFXNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x530240);
};

// CAutoRegFlowNode<CIndexer_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CIndexer_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CIndexer_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CIndexer_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C12E0);
};

// CAutoRegFlowNode<CIsAnimPlaying_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CIsAnimPlaying_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CIsAnimPlaying_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CIsAnimPlaying_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C9100);
};

// CAutoRegFlowNode<CMaterialFlashGotoAndPlayNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CMaterialFlashGotoAndPlayNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CMaterialFlashGotoAndPlayNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CMaterialFlashGotoAndPlayNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x5303F0);
};

// CAutoRegFlowNode<CMaterialFlashInvokeNode>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CMaterialFlashInvokeNode> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CMaterialFlashInvokeNode>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CMaterialFlashInvokeNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x530360);
};

// CAutoRegFlowNode<CMultiplexer_Node>
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
class CAutoRegFlowNode<CMultiplexer_Node> : public CAutoRegFlowNodeBase
{ // Size=32 (0x20)
public:
	_smart_ptr<IFlowNode> m_pInstance;

	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CAutoRegFlowNode<CMultiplexer_Node>(const char* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoRegFlowNode<CMultiplexer_Node>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4C31E0);
};

// CFlowBaseNodeInternal
// Header:  CryEngine/cryaction/flowsystem/nodes/flowbasenode.h
// Include: Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h
class CFlowBaseNodeInternal : public IFlowNode
{ // Size=16 (0x10)
public:
	int m_refs;

	virtual ~CFlowBaseNodeInternal();
	virtual void AddRef();
	virtual void Release();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo) = 0;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	bool InputEntityIsLocalPlayer(const IFlowNode::SActivationInfo* const pActInfo) const { return FInputEntityIsLocalPlayer(this, pActInfo); }
	IActor* GetInputActor(const IFlowNode::SActivationInfo* const pActInfo) const { return FGetInputActor(this, pActInfo); }

#if 0
	CFlowBaseNodeInternal();
#endif

	static inline auto FAddRef = PreyFunction<void(CFlowBaseNodeInternal* const _this)>(0x4678B0);
	static inline auto FRelease = PreyFunction<void(CFlowBaseNodeInternal* const _this)>(0xA56ED0);
	static inline auto FSerializeXML = PreyFunction<bool(CFlowBaseNodeInternal* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(CFlowBaseNodeInternal* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(CFlowBaseNodeInternal* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CFlowBaseNodeInternal* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FInputEntityIsLocalPlayer = PreyFunction<bool(const CFlowBaseNodeInternal* const _this, const IFlowNode::SActivationInfo* const pActInfo)>(0x43D620);
	static inline auto FGetInputActor = PreyFunction<IActor* (const CFlowBaseNodeInternal* const _this, const IFlowNode::SActivationInfo* const pActInfo)>(0x17E4E30);
};
#endif // !MOONCRASH
