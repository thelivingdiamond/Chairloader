// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/turret/arkflownodesturret.h
class ArkFlowNode_ArkTurret_EnableFlowgraphControl : public CFlowBaseNode<0> // Id=801CB3B Size=16
{
public:
	enum class EInputPortIndex
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNode_ArkTurret_EnableFlowgraphControl();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ArkTurret_EnableFlowgraphControl *const _this, SFlowNodeConfig &config)>(0x15DF150);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ArkTurret_EnableFlowgraphControl *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo)>(0x15DF430);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNode_ArkTurret_EnableFlowgraphControl const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNode_ArkTurret_EnableFlowgraphControl *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_EnableFlowgraphControl *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_EnableFlowgraphControl *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/turret/arkflownodesturret.h
class ArkFlowNode_ArkTurret_ManualTarget : public CFlowBaseNode<0> // Id=801CB3D Size=16
{
public:
	enum class EInputPortIndex
	{
		activate = 0,
		clearTarget = 1,
		targetID = 2,
		shouldTargetPos = 3,
		targetPosition = 4,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNode_ArkTurret_ManualTarget();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ArkTurret_ManualTarget *const _this, SFlowNodeConfig &config)>(0x15DF4B0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ArkTurret_ManualTarget *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo)>(0x15DFA30);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNode_ArkTurret_ManualTarget const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNode_ArkTurret_ManualTarget *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_ManualTarget *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_ManualTarget *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/turret/arkflownodesturret.h
class ArkFlowNode_ArkTurret_WeaponProperties : public CFlowBaseNode<0> // Id=801CB3F Size=16
{
public:
	enum class EInputPortIndex
	{
		set = 0,
		reset = 1,
		bulletHitChance = 2,
		spreadRange = 3,
		distanceRange = 4,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNode_ArkTurret_WeaponProperties();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ArkTurret_WeaponProperties *const _this, SFlowNodeConfig &config)>(0x15DFC20);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ArkTurret_WeaponProperties *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *pActInfo)>(0x15E01D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNode_ArkTurret_WeaponProperties const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNode_ArkTurret_WeaponProperties *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_WeaponProperties *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNode_ArkTurret_WeaponProperties *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
};

