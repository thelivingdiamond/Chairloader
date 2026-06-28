// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CArkAngleRotationComponent;
class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowAngleRotation
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowAngleRotation.h
class CArkFlowAngleRotation : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	unsigned m_entityId;

	virtual ~CArkFlowAngleRotation();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* const _actInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* const __unnamed1, TSerialize __unnamed2);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* const _actInfo);
	virtual void GetMemoryUsage(ICrySizer* const s) const;
	void DeactivateRotationComponent() { FDeactivateRotationComponent(this); }
	CArkAngleRotationComponent* GetRotationComponent() const { return FGetRotationComponent(this); }
	void ReleaseRotationComponent(CArkAngleRotationComponent* const _rotationComponent) { FReleaseRotationComponent(this, _rotationComponent); }

#if 0
	CArkFlowAngleRotation(IFlowNode::SActivationInfo* const _arg0_);
	bool ActivateRotationComponent(IEntity* const _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowAngleRotation* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* const _actInfo)>(0x123CAF0);
	static inline auto FSerialize = PreyFunction<void(CArkFlowAngleRotation* const _this, IFlowNode::SActivationInfo* const __unnamed1, TSerialize __unnamed2)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowAngleRotation* const _this, SFlowNodeConfig& config)>(0x123CB40);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowAngleRotation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* const _actInfo)>(0x123D090);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowAngleRotation* const _this, ICrySizer* const s)>(0x4BC120);
	static inline auto FDeactivateRotationComponent = PreyFunction<void(CArkFlowAngleRotation* const _this)>(0x123D360);
	static inline auto FGetRotationComponent = PreyFunction<CArkAngleRotationComponent* (const CArkFlowAngleRotation* const _this)>(0x123D3D0);
	static inline auto FReleaseRotationComponent = PreyFunction<void(CArkFlowAngleRotation* const _this, CArkAngleRotationComponent* const _rotationComponent)>(0x123D440);
};
#endif // MOONCRASH
