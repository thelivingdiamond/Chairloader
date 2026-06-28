// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcCreatePhantomRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcCreatePhantomRequest.h
class ArkFlowNodeNpcCreatePhantomRequest : public CFlowBaseNode<1>
{ // Size=88 (0x58)
public:
	enum class EInputPortIndex
	{
		request = 0,
		corpseEntityId = 1,
		cancel = 2,
		archetypeId = 3,
		ignoreMovement = 4,
		failsafeTimeout = 5,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		completed = 1,
		failed = 2,
		canceled = 3,
		spawnedNpcEntityIdOutputPortIndex = 4,
	};

	IFlowNode::SActivationInfo m_prevActivationInfo;
	bool m_bRequested;
	bool m_bFinished;
	bool m_bPostSerializePlay;
	CTimeValue m_FailsafeTimerEnd;
	int m_lastInitializeFrameId;
	ArkGameSaveVersion m_savedVersion;

	virtual ~ArkFlowNodeNpcCreatePhantomRequest();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	bool ProcessRequest(IFlowNode::SActivationInfo* _pActInfo) { return FProcessRequest(this, _pActInfo); }
	void OnRequestCompleted(unsigned _completingTelepathId, unsigned _createdNpcId, bool _bRequestSucceeded) { FOnRequestCompleted(this, _completingTelepathId, _createdNpcId, _bRequestSucceeded); }
	bool ProcessCancel(IFlowNode::SActivationInfo* _pActInfo) { return FProcessCancel(this, _pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	void BeginFailsafeTimer(IFlowNode::SActivationInfo* _pActInfo) { FBeginFailsafeTimer(this, _pActInfo); }

#if 0
	ArkFlowNodeNpcCreatePhantomRequest(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcCreatePhantomRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15CBA70);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, SFlowNodeConfig& config)>(0x15CBCC0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CC670);
	static inline auto FProcessRequest = PreyFunction<bool(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15CC8D0);
	static inline auto FOnRequestCompleted = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, unsigned _completingTelepathId, unsigned _createdNpcId, bool _bRequestSucceeded)>(0x15CC410);
	static inline auto FProcessCancel = PreyFunction<bool(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15CC630);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcCreatePhantomRequest* const _this, ICrySizer* s)>(0xE98E40);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x15CCBE0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15CC4B0);
	static inline auto FBeginFailsafeTimer = PreyFunction<void(ArkFlowNodeNpcCreatePhantomRequest* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15CBBF0);
};
#endif // MOONCRASH
