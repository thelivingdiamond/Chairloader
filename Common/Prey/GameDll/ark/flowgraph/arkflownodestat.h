// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeStatChanged
// Header:  Prey/GameDll/ark/flowgraph/arkflownodestat.h
class CArkFlowNodeStatChanged : public CFlowBaseNode<1>, public IArkStatsListener
{ // Size=80 (0x50)
public:
	enum class EArkInputs
	{
		onChanged = 0,
		trigger = 1,
		statName = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	CCryName m_stat;
	IFlowNode::SActivationInfo m_activationInfo;

	virtual ~CArkFlowNodeStatChanged();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void ResetStatComponent() { FResetStatComponent(this); }

#if 0
	CArkFlowNodeStatChanged(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeStatChanged* const _this, SFlowNodeConfig& _config)>(0x152A040);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeStatChanged* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152A490);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeStatChanged* const _this, ICrySizer* _s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeStatChanged* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1529FD0);
	static inline auto FOnStatChange = PreyFunction<void(IArkStatsListener* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x152A450);
	static inline auto FResetStatComponent = PreyFunction<void(CArkFlowNodeStatChanged* const _this)>(0x152A570);
};

// CArkFlowNodeStatModifierPackage
// Header:  Prey/GameDll/ark/flowgraph/arkflownodestat.h
class CArkFlowNodeStatModifierPackage : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum class EInputs
	{
		add = 0,
		remove = 1,
		modifier = 2,
	};

	enum class EOutputs
	{
		added = 0,
		removed = 1,
	};

	unsigned m_statModHandle;

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* const _pActInfo, TSerialize _ser);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeStatModifierPackage(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeStatModifierPackage* const _this, SFlowNodeConfig& _config)>(0x15298F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeStatModifierPackage* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1529D30);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeStatModifierPackage* const _this, IFlowNode::SActivationInfo* const _pActInfo, TSerialize _ser)>(0x1529EC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeStatModifierPackage* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeStatModifierPackage* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1529EE0);
};
#endif // MOONCRASH
