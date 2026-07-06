// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeResetPDAData
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class ArkFlowNodeResetPDAData : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeResetPDAData(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeResetPDAData* const _this, SFlowNodeConfig& _config)>(0x1526210);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeResetPDAData* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1527300);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeResetPDAData* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNode_SetStationAccess
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class ArkFlowNode_SetStationAccess : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
		path = 2,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNode_SetStationAccess(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SetStationAccess* const _this, SFlowNodeConfig& _config)>(0x1525950);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SetStationAccess* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1525D40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SetStationAccess* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_ClearLevelMapFog
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_ClearLevelMapFog : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_ClearLevelMapFog(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_ClearLevelMapFog* const _this, SFlowNodeConfig& _config)>(0x1526400);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_ClearLevelMapFog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15273E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_ClearLevelMapFog* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_ClosePDA
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_ClosePDA : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_ClosePDA(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_ClosePDA* const _this, SFlowNodeConfig& _config)>(0x1525650);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_ClosePDA* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1525840);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_ClosePDA* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_EnablePDADateAndTime
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_EnablePDADateAndTime : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		show = 0,
		hide = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnablePDADateAndTime(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnablePDADateAndTime* const _this, SFlowNodeConfig& _config)>(0x15265F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnablePDADateAndTime* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1527470);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnablePDADateAndTime* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_EnablePDAPage
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_EnablePDAPage : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		enable = 1,
		page = 2,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnablePDAPage(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnablePDAPage* const _this, SFlowNodeConfig& _config)>(0x15268B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnablePDAPage* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15274F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnablePDAPage* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_OpenPDAPage
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_OpenPDAPage : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		page = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_OpenPDAPage(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_OpenPDAPage* const _this, SFlowNodeConfig& _config)>(0x1526CC0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_OpenPDAPage* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1527710);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_OpenPDAPage* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_SetPDAAccess
// Header:  Prey/GameDll/ark/flowgraph/arkflownodepda.h
class CArkFlowNode_SetPDAAccess : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		output = 0,
		enabled = 1,
		disabled = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_SetPDAAccess(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_SetPDAAccess* const _this, SFlowNodeConfig& _config)>(0x1526FE0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_SetPDAAccess* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15278D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_SetPDAAccess* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
