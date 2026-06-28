// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/arkflownodenpctrackview_setdynamicentity.h
class ArkFlowNodeNpcTrackView_SetDynamicNode : public CFlowBaseNode<0> // Id=801BFF9 Size=16
{
public:
	enum class EInputPortIndex
	{
		set = 0,
		clear = 1,
		dynNodeName = 2,
	};

	enum class EOutputPortIndex
	{
		succeeded = 0,
		failed = 1,
		cleared = 2,
		out = 3,
	};

	virtual ~ArkFlowNodeNpcTrackView_SetDynamicNode();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
#if 0
	void ProcessSet(IFlowNode::SActivationInfo *arg0);
	void ProcessClear(IFlowNode::SActivationInfo *arg0);
#endif
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, SFlowNodeConfig &config)>(0x1435DF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x1436280);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcTrackView_SetDynamicNode
// Header:  Prey/GameDll/ark/arkflownodenpctrackview_setdynamicentity.h
class ArkFlowNodeNpcTrackView_SetDynamicNode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		set = 0,
		clear = 1,
		dynNodeName = 2,
	};

	enum class EOutputPortIndex
	{
		succeeded = 0,
		failed = 1,
		cleared = 2,
		out = 3,
	};

	virtual ~ArkFlowNodeNpcTrackView_SetDynamicNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcTrackView_SetDynamicNode(IFlowNode::SActivationInfo* _arg0_);
	void ProcessSet(IFlowNode::SActivationInfo* _arg0_);
	void ProcessClear(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, SFlowNodeConfig& config)>(0x154BAB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x154BF40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // !MOONCRASH
