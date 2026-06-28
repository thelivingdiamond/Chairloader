// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcSpawnRequester.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeSpawnNpc
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSpawnNpc.h
class ArkFlowNodeSpawnNpc : public CFlowBaseNode<1>, public ArkNpcSpawnRequester
{ // Size=48 (0x30)
public:
	enum class EInputPortIndex
	{
		k_spawnInputPortIndex = 0,
	};

	enum class EOutputPortIndex
	{
		k_outOutputPortIndex = 0,
		k_spawnedOutputPortIndex = 1,
		k_spawnedNpcEntityIdOutputPortIndex = 2,
		k_spawnFailedOutputPortIndex = 3,
	};

	// ArkFlowNodeSpawnNpc::SpawnRequestInfo
	// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSpawnNpc.h
	struct SpawnRequestInfo
	{ // Size=56 (0x38)
		uint64_t m_requestId;
		IFlowNode::SActivationInfo m_activationInfo;

	#if 0
		SpawnRequestInfo(uint64_t _arg0_, const IFlowNode::SActivationInfo& _arg1_);
	#endif
	};

	using SpawnRequestInfoVector = std::vector<ArkFlowNodeSpawnNpc::SpawnRequestInfo>;

	std::vector<ArkFlowNodeSpawnNpc::SpawnRequestInfo> m_spawnRequests;

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void DoOnSpawnRequestSucceeded(uint64_t _requestId, IEntity& _spawnedNpcEntity, void* _pData);
	virtual void DoOnSpawnRequestFailed(uint64_t _requestId, void* _pData);

#if 0
	ArkFlowNodeSpawnNpc(IFlowNode::SActivationInfo* _arg0_);
	void ProcessActivateEvent(IFlowNode::SActivationInfo& _arg0_);
	void ProcessInitializeEvent(IFlowNode::SActivationInfo& _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeSpawnNpc* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1529080);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSpawnNpc* const _this, SFlowNodeConfig& _configuration)>(0x1529550);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSpawnNpc* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15297D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeSpawnNpc* const _this, ICrySizer* _pSizer)>(0x4BAFC0);
	static inline auto FDoOnSpawnRequestSucceeded = PreyFunction<void(ArkNpcSpawnRequester* const _this, uint64_t _requestId, IEntity& _spawnedNpcEntity, void* _pData)>(0x1529470);
	static inline auto FDoOnSpawnRequestFailed = PreyFunction<void(ArkNpcSpawnRequester* const _this, uint64_t _requestId, void* _pData)>(0x15293E0);
};
#endif // MOONCRASH
