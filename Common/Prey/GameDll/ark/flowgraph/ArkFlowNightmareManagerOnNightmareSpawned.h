// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <_unknown/INightmareSpawnObserver.h>

class ArkNpc;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNightmareManagerOnNightmareSpawned
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNightmareManagerOnNightmareSpawned.h
class ArkFlowNightmareManagerOnNightmareSpawned : public CFlowBaseNode<1>, public INightmareSpawnObserver
{ // Size=72 (0x48)
public:
	enum InPort
	{
	};

	enum class OutPort
	{
		spawned = 0,
		nightmareId = 1,
		dead = 2,
		dissipated = 3,
	};

	IFlowNode::SActivationInfo m_prevActivationInfo;

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Release();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void OnNightmareSpawned(ArkNpc& _nightmare);
	virtual void OnNightmareKilled(ArkNpc& _nightmare);
	virtual void OnNightmareDissipated(ArkNpc& _nightmare);

#if 0
	ArkFlowNightmareManagerOnNightmareSpawned(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNightmareManagerOnNightmareSpawned* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x123DC80);
	static inline auto FRelease = PreyFunction<void(ArkFlowNightmareManagerOnNightmareSpawned* const _this)>(0x123DD00);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNightmareManagerOnNightmareSpawned* const _this, SFlowNodeConfig& _config)>(0x123DD50);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNightmareManagerOnNightmareSpawned* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123DF00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNightmareManagerOnNightmareSpawned* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FOnNightmareSpawned = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x123DF60);
	static inline auto FOnNightmareKilled = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x123DFE0);
	static inline auto FOnNightmareDissipated = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x123E020);
};
#endif // MOONCRASH
