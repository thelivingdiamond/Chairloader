// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h>
#include <Prey/GameDll/ark/flowgraph/arkflownodeobjective.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeCheckLocateCharacterObjectiveTarget m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>* const _this, SFlowNodeConfig& _config)>(0x15CCDA0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeCheckLocateCharacterObjectiveTarget>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CCDB0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeEnableBounties m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>* const _this, SFlowNodeConfig& _config)>(0x15CD230);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeEnableBounties>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CD240);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeGetCharacterIsAlive m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>* const _this, SFlowNodeConfig& _config)>(0x15C4640);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsAlive>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4650);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeGetCharacterIsLocated m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>* const _this, SFlowNodeConfig& _config)>(0x15C4EB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterIsLocated>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4EC0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeGetCharacterLocation m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>* const _this, SFlowNodeConfig& _config)>(0x15C4D50);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterLocation>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4D60);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeGetCharacterVitalSigns m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>* const _this, SFlowNodeConfig& _config)>(0x15C49A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGetCharacterVitalSigns>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C49B0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeGiveLocateCharacterTask m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>* const _this, SFlowNodeConfig& _config)>(0x15CCFD0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeGiveLocateCharacterTask>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CCFE0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeSetCharacterDiscovered m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>* const _this, SFlowNodeConfig& _config)>(0x15C44B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterDiscovered>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C44C0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeSetCharacterHasTrackingChip m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>* const _this, SFlowNodeConfig& _config)>(0x15C5080);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterHasTrackingChip>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C5090);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeSetCharacterIsAlive m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>* const _this, SFlowNodeConfig& _config)>(0x15C4800);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterIsAlive>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4810);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeSetCharacterLocation m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>* const _this, SFlowNodeConfig& _config)>(0x15C4E00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterLocation>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4E10);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeSetCharacterVitalSigns m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>* const _this, SFlowNodeConfig& _config)>(0x15C4B90);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeSetCharacterVitalSigns>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C4BA0);
};

// CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehelpers.h
class CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue> : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	CArkFlowNodeShowObjectiveClue m_derived;

	virtual ~CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>();
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>* const _this, SFlowNodeConfig& _config)>(0x15CCE50);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSingletonWrapper<CArkFlowNodeShowObjectiveClue>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CCE60);
};
#endif // MOONCRASH
