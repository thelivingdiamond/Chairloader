// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcLookAtEntity
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLookAtEntity.h
class ArkFlowNodeNpcLookAtEntity : public CFlowBaseNode<1>
{ // Size=240 (0xF0)
public:
	enum class EInputPortIndex
	{
		request = 0,
		lookAtEntity = 1,
		cancel = 2,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		canceled = 1,
		out = 2,
	};

	ArkNpcLookDesire m_lookDesire;

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual bool ProcessRequest(IFlowNode::SActivationInfo* _pActInfo);
	virtual bool ProcessCancel(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcLookAtEntity(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLookAtEntity* const _this, SFlowNodeConfig& config)>(0x151BBB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x151BFC0);
	static inline auto FProcessRequest = PreyFunction<bool(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151C070);
	static inline auto FProcessCancel = PreyFunction<bool(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151C1D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcLookAtEntity* const _this, ICrySizer* s)>(0x151E1A0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcLookAtEntity* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcLookAtEntity* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151DA40);
};

// ArkFlowNodeNpcLookAtEntityCustom
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcLookAtEntity.h
class ArkFlowNodeNpcLookAtEntityCustom : public ArkFlowNodeNpcLookAtEntity
{ // Size=240 (0xF0)
public:
	enum class EInputPortIndex
	{
		request = 0,
		lookAtEntity = 1,
		cancel = 2,
		archetype = 3,
		lookPose = 4,
		torsoBlendInTime = 5,
		torsoSmoothTime = 6,
		torsoBlendOutTime = 7,
		torsoMaxDegreesYaw = 8,
		torsoMaxDegreesPitch = 9,
		headBlendInTime = 10,
		headSmoothTime = 11,
		headBlendOutTime = 12,
		headMaxDegreesYaw = 13,
		headMaxDegreesPitch = 14,
		eyesBlendInTime = 15,
		eyesSmoothTime = 16,
		eyesBlendOutTime = 17,
		eyesMaxDegreesYaw = 18,
		eyesMaxDegreesPitch = 19,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		canceled = 1,
		out = 2,
	};

	ArkFlowNodeNpcLookAtEntityCustom(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNodeNpcLookAtEntityCustom();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual bool ProcessRequest(IFlowNode::SActivationInfo* _pActInfo);
	virtual bool ProcessCancel(IFlowNode::SActivationInfo* _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

	static inline auto FArkFlowNodeNpcLookAtEntityCustom = PreyFunction<void(ArkFlowNodeNpcLookAtEntityCustom* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151DB00);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcLookAtEntityCustom* const _this, SFlowNodeConfig& config)>(0x151C260);
	static inline auto FProcessRequest = PreyFunction<bool(ArkFlowNodeNpcLookAtEntityCustom* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151D180);
	static inline auto FProcessCancel = PreyFunction<bool(ArkFlowNodeNpcLookAtEntityCustom* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x151D860);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcLookAtEntityCustom* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x151D970);
};
#endif // MOONCRASH
