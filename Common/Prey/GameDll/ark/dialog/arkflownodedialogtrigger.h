// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkEnums.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkConversation;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeDialogTrigger<T>
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
// Instantiations: ArkPADialogTrigger (Size=128), ArkTranscribeDialogTrigger (Size=120),
// ArkTelepathDialogTrigger (Size=112, Mooncrash only).
// No addresses: they differ per instantiation.
template <typename T>
class ArkFlowNodeDialogTrigger : public CFlowBaseNode<eNCT_Instanced>, public IArkConversationListener
{
public:
	IFlowNode::SActivationInfo m_ActInfo;
	uint64_t m_hookId;
	uint64_t m_conversationId;
	uint64_t m_loadConversationId;
	ArkConversation* m_pConversation;
	T m_dialogTrigger;

	virtual ~ArkFlowNodeDialogTrigger();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnTriggerStarted(ArkConversation* const _pConversation);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnConversationComplete(const bool _bComplete);
	// T-independent; every instantiation folds to the same function in each game.
	static uint64_t GetTriggerRule(const IFlowNode::SActivationInfo* _pActInfo) { return FGetTriggerRule(_pActInfo); }

#if 0
	ArkFlowNodeDialogTrigger(IFlowNode::SActivationInfo* const _arg0_);
#ifndef MOONCRASH
	void ExecuteTrigger(const bool _arg0_);
#else
	void ExecuteTrigger();
#endif
	void OnTriggerQueued(const bool _arg0_);
	void Stop();
	const ArkConversation* GetConversation() const;
	uint64_t GetConversationHook() const;
	void Reset();
#endif

#ifndef MOONCRASH
	static inline auto FGetTriggerRule = PreyFunction<uint64_t(const IFlowNode::SActivationInfo* _pActInfo)>(0x1488280);
#else
	static inline auto FGetTriggerRule = PreyFunction<uint64_t(const IFlowNode::SActivationInfo* _pActInfo)>(0x15A0360);
#endif
};

// ArkPADialogTrigger
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkPADialogTrigger
{ // Size=24 (0x18)
public:
	enum class EArkPAInput
	{
		chime = 3,
		channel = 4,
		chimeType = 5,
	};

	ArkFlowNodeDialogTrigger<ArkPADialogTrigger>& m_triggerNode;
	EArkChimeType m_chimeType;
	int m_channelId;
	bool m_bQueuedAnnouncement;

	static void GetConfiguration(SFlowNodeConfig& _rConfig) { FGetConfiguration(_rConfig); }

#if 0
	ArkPADialogTrigger(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>& _arg0_);
	void DoTrigger(const uint64_t _arg0_);
	void Stop(const ArkConversation* _arg0_);
	void OnTriggerStarted();
	void OnTriggerQueued();
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	void ProcessActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x1487470);
#else
	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x159F0A0);
#endif
};

#ifdef MOONCRASH
// ArkTelepathDialogTrigger
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkTelepathDialogTrigger
{ // Size=8 (0x8)
public:
	ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>& m_triggerNode;

	static void GetConfiguration(SFlowNodeConfig& _rConfig) { FGetConfiguration(_rConfig); }

#if 0
	ArkTelepathDialogTrigger(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>& _arg0_);
	void DoTrigger(const uint64_t _arg0_);
	void Stop(const ArkConversation* _arg0_);
	void Serialize(TSerialize _arg0_);
	bool ShouldQueue(IFlowNode::SActivationInfo* const _arg0_);
	void PostSerialize();
	void OnTriggerStarted();
	void OnTriggerQueued();
	void ProcessActivate(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x159F800);
};
#endif

// ArkTranscribeDialogTrigger
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkTranscribeDialogTrigger
{ // Size=16 (0x10)
public:
#ifdef MOONCRASH
	enum class EArkTranscribeInput
	{
		queue = 3,
		mintime = 4,
	};
#endif

	ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>& m_triggerNode;
	bool m_bQueued;
	bool m_bCanQueue;
	float m_fMinTimeSinceLastCall;

	static void GetConfiguration(SFlowNodeConfig& _rConfig) { FGetConfiguration(_rConfig); }

#if 0
	ArkTranscribeDialogTrigger(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>& _arg0_);
	void DoTrigger(const uint64_t _arg0_);
	void Stop(const ArkConversation* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	void OnTriggerStarted();
	void OnTriggerQueued();
	void ProcessActivate(IFlowNode::SActivationInfo* const _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x1487BD0);
#else
	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x159FCB0);
#endif
};
