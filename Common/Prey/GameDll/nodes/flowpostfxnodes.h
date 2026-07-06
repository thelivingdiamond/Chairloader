// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CFlowControlPlayerHealthEffect
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowControlPlayerHealthEffect : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class #unnamed_enum_INP_ENABLE
	{
		INP_ENABLE = 0,
		INP_DISABLE = 1,
		INP_INTENSITY = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowControlPlayerHealthEffect(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowControlPlayerHealthEffect* const _this, SFlowNodeConfig& config)>(0x18A8CD0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowControlPlayerHealthEffect* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowControlPlayerHealthEffect* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsBloodSplats>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsBloodSplats> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsBloodSplats>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsBloodSplats>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsBloodSplats>* const _this, SFlowNodeConfig& config)>(0x18A96A0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsBloodSplats>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A96D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsBloodSplats>* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsGlittering>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsGlittering> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsGlittering>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsGlittering>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsGlittering>* const _this, SFlowNodeConfig& config)>(0x18A9A80);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsGlittering>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A9AB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsGlittering>* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsGlobal>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsGlobal> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsGlobal>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsGlobal>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsGlobal>* const _this, SFlowNodeConfig& config)>(0x18A90D0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsGlobal>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A9100);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsGlobal>* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsGlow>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsGlow> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsGlow>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsGlow>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsGlow>* const _this, SFlowNodeConfig& config)>(0x18A9890);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsGlow>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A98C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsGlow>* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsScreenFrost>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsScreenFrost> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsScreenFrost>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsScreenFrost>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsScreenFrost>* const _this, SFlowNodeConfig& config)>(0x18A92C0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsScreenFrost>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A92F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsScreenFrost>* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowFXNode<FXParamsWaterDroplets>
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
class CFlowFXNode<FXParamsWaterDroplets> : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	virtual ~CFlowFXNode<FXParamsWaterDroplets>();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowFXNode<FXParamsWaterDroplets>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowFXNode<FXParamsWaterDroplets>* const _this, SFlowNodeConfig& config)>(0x18A94B0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFXNode<FXParamsWaterDroplets>* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A94E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFXNode<FXParamsWaterDroplets>* const _this, ICrySizer* s)>(0x455F00);
};

// FXParamsBloodSplats
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsBloodSplats
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18A9C70);
};

// FXParamsGlittering
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsGlittering
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18AA290);
};

// FXParamsGlobal
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsGlobal
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18AA530);
};

// FXParamsGlow
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsGlow
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18AAEC0);
};

// FXParamsScreenFrost
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsScreenFrost
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18AB250);
};

// FXParamsWaterDroplets
// Header:  Prey/GameDll/nodes/flowpostfxnodes.h
struct FXParamsWaterDroplets
{ // Size=1 (0x1)
	static void GetConfiguration(SFlowNodeConfig& config) { FGetConfiguration(config); }

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& config)>(0x18AB6C0);
};
#endif // MOONCRASH
