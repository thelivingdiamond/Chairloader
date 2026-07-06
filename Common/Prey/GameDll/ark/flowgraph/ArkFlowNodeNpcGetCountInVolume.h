// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcGetCountInVolume
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcGetCountInVolume.h
class ArkFlowNodeNpcGetCountInVolume : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		check = 0,
		metaTagsString = 1,
		metaTagCheckType = 2,
		aabbMin = 3,
		aabbMax = 4,
	};

	enum class EOutputPortIndex
	{
		failed = 0,
		success = 1,
		outCount = 2,
	};

	enum class EMetaTagCheckType
	{
		ignoreTags = 0,
		hasAnyTags = 1,
		hasAllTags = 2,
	};

	virtual ~ArkFlowNodeNpcGetCountInVolume();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcGetCountInVolume(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcGetCountInVolume* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x12434A0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcGetCountInVolume* const _this, SFlowNodeConfig& config)>(0x12434F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcGetCountInVolume* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1243B10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcGetCountInVolume* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcGetCountInVolume* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcGetCountInVolume* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcGetCountInVolume* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
