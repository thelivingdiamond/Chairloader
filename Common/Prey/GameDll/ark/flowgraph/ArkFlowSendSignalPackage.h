// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowSendSignalPackage
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSendSignalPackage.h
class ArkFlowSendSignalPackage : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		sender = 1,
		packageId = 2,
		value = 3,
		numRepeats = 4,
		repeatTime = 5,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowSendSignalPackage(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSendSignalPackage* const _this, SFlowNodeConfig& _config)>(0x15F5CA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSendSignalPackage* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F6350);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSendSignalPackage* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowSendSignalPackageInArea
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSendSignalPackage.h
class ArkFlowSendSignalPackageInArea : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		sender = 1,
		packageId = 2,
		value = 3,
		numRepeats = 4,
		repeatTime = 5,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowSendSignalPackageInArea(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSendSignalPackageInArea* const _this, SFlowNodeConfig& _config)>(0x15F66F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSendSignalPackageInArea* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F6DA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSendSignalPackageInArea* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowSendSignalPackageToNpcsInVolume
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowSendSignalPackage.h
class ArkFlowSendSignalPackageToNpcsInVolume : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		sender = 1,
		packageId = 2,
		value = 3,
		numRepeats = 4,
		repeatTime = 5,
		metaTagsString = 6,
		metaTagCheckType = 7,
		aabbMin = 8,
		aabbMax = 9,
	};

	enum class EOutputs
	{
		failed = 0,
		success = 1,
	};

	enum class EMetaTagCheckType
	{
		ignoreTags = 0,
		hasAnyTags = 1,
		hasAllTags = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowSendSignalPackageToNpcsInVolume(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowSendSignalPackageToNpcsInVolume* const _this, SFlowNodeConfig& _config)>(0x15F7310);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowSendSignalPackageToNpcsInVolume* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F7DE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowSendSignalPackageToNpcsInVolume* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
