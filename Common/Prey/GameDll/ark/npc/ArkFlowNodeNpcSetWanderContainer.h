// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeNpcEncounterSetWanderContainer
// Header:  Prey/GameDll/ark/npc/ArkFlowNodeNpcSetWanderContainer.h
class ArkFlowNodeNpcEncounterSetWanderContainer : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		k_wanderContainerEntityId = 0,
		k_profileNameInputPortIndex = 1,
		k_encounterNameInputPortIndex = 2,
		k_speed = 3,
		k_useSpeed = 4,
		k_set = 5,
	};

	enum class OutPorts
	{
		k_out = 0,
	};

	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	ArkFlowNodeNpcEncounterSetWanderContainer(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcEncounterSetWanderContainer* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcEncounterSetWanderContainer* const _this, SFlowNodeConfig& _config)>(0x13325F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcEncounterSetWanderContainer* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1332D20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcEncounterSetWanderContainer* const _this, ICrySizer* _pSizer)>(0x455F00);
};

// ArkFlowNodeNpcSetWanderContainer
// Header:  Prey/GameDll/ark/npc/ArkFlowNodeNpcSetWanderContainer.h
class ArkFlowNodeNpcSetWanderContainer : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		wanderContainerEntityId = 0,
		speed = 1,
		useSpeed = 2,
		set = 3,
	};

	enum class OutPorts
	{
		out = 0,
	};

	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	ArkFlowNodeNpcSetWanderContainer(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcSetWanderContainer* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcSetWanderContainer* const _this, SFlowNodeConfig& _config)>(0x1331FC0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcSetWanderContainer* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1332470);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcSetWanderContainer* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
