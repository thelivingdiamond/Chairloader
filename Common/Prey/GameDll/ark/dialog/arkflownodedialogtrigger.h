// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Circular reference
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkConversation;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

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

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x159F0A0);
};

// ArkFlowNodeDialogTrigger<ArkPADialogTrigger>
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkFlowNodeDialogTrigger<ArkPADialogTrigger> : public CFlowBaseNode<1>, public IArkConversationListener
{ // Size=128 (0x80)
public:
	IFlowNode::SActivationInfo m_ActInfo;
	uint64_t m_hookId;
	uint64_t m_conversationId;
	uint64_t m_loadConversationId;
	ArkConversation* m_pConversation;
	ArkPADialogTrigger m_dialogTrigger;

	virtual ~ArkFlowNodeDialogTrigger<ArkPADialogTrigger>();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnTriggerStarted(ArkConversation* const _pConversation) { FOnTriggerStarted(this, _pConversation); }
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnConversationComplete(const bool _bComplete);
	static uint64_t GetTriggerRule(const IFlowNode::SActivationInfo* _pActInfo) { return FGetTriggerRule(_pActInfo); }

#if 0
	ArkFlowNodeDialogTrigger<ArkPADialogTrigger>(IFlowNode::SActivationInfo* const _arg0_);
	void ExecuteTrigger();
	void OnTriggerQueued(const bool _arg0_);
	void Stop();
	const ArkConversation* GetConversation() const;
	uint64_t GetConversationHook() const;
	void Reset();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, SFlowNodeConfig& _rConfig)>(0x159E640);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x159E650);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, ICrySizer* _pS)>(0x4A5BF0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x159E880);
	static inline auto FOnTriggerStarted = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, ArkConversation* const _pConversation)>(0x15A3850);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x159E910);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x159E970);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x159EA40);
	static inline auto FGetTriggerRule = PreyFunction<uint64_t(const IFlowNode::SActivationInfo* _pActInfo)>(0x15A0360);
};

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

// ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger> : public CFlowBaseNode<1>, public IArkConversationListener
{ // Size=112 (0x70)
public:
	IFlowNode::SActivationInfo m_ActInfo;
	uint64_t m_hookId;
	uint64_t m_conversationId;
	uint64_t m_loadConversationId;
	ArkConversation* m_pConversation;
	ArkTelepathDialogTrigger m_dialogTrigger;

	virtual ~ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnConversationComplete(const bool _bComplete);
	static uint64_t GetTriggerRule(const IFlowNode::SActivationInfo* _pActInfo) { return FGetTriggerRule(_pActInfo); }

#if 0
	ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>(IFlowNode::SActivationInfo* const _arg0_);
	void ExecuteTrigger();
	void OnTriggerStarted(ArkConversation* const _arg0_);
	void OnTriggerQueued(const bool _arg0_);
	void Stop();
	const ArkConversation* GetConversation() const;
	uint64_t GetConversationHook() const;
	void Reset();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, SFlowNodeConfig& _rConfig)>(0x159EB20);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x159EB30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, ICrySizer* _pS)>(0x578280);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x159ECF0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x159ED70);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTelepathDialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x159EDC0);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x159EA40);
	static inline auto FGetTriggerRule = PreyFunction<uint64_t(const IFlowNode::SActivationInfo* _pActInfo)>(0x15A0360);
};

// ArkTranscribeDialogTrigger
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkTranscribeDialogTrigger
{ // Size=16 (0x10)
public:
	enum class EArkTranscribeInput
	{
		queue = 3,
		mintime = 4,
	};

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

	static inline auto FGetConfiguration = PreyFunction<void(SFlowNodeConfig& _rConfig)>(0x159FCB0);
};

// ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>
// Header:  Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h
class ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger> : public CFlowBaseNode<1>, public IArkConversationListener
{ // Size=120 (0x78)
public:
	IFlowNode::SActivationInfo m_ActInfo;
	uint64_t m_hookId;
	uint64_t m_conversationId;
	uint64_t m_loadConversationId;
	ArkConversation* m_pConversation;
	ArkTranscribeDialogTrigger m_dialogTrigger;

	virtual ~ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnTriggerStarted(ArkConversation* const _pConversation) { FOnTriggerStarted(this, _pConversation); }
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnConversationComplete(const bool _bComplete);
	static uint64_t GetTriggerRule(const IFlowNode::SActivationInfo* _pActInfo) { return FGetTriggerRule(_pActInfo); }

#if 0
	ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>(IFlowNode::SActivationInfo* const _arg0_);
	void ExecuteTrigger();
	void OnTriggerQueued(const bool _arg0_);
	void Stop();
	const ArkConversation* GetConversation() const;
	uint64_t GetConversationHook() const;
	void Reset();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, SFlowNodeConfig& _rConfig)>(0x159E2A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x159E2B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, ICrySizer* _pS)>(0x159E480);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x159EED0);
	static inline auto FOnTriggerStarted = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, ArkConversation* const _pConversation)>(0x13E7A50);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x159E4A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDialogTrigger<ArkTranscribeDialogTrigger>* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x159E500);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x159EA40);
	static inline auto FGetTriggerRule = PreyFunction<uint64_t(const IFlowNode::SActivationInfo* _pActInfo)>(0x15A0360);
};
#endif // MOONCRASH
