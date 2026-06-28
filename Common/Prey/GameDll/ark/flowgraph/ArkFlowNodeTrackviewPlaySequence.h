// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMovie/IMovieSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <_unknown/IMovieListener.h>

struct ArkAttachmentKey;
struct IAnimSequence;
struct IAttachment;
class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeTrackviewPlaySequence
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeTrackviewPlaySequence.h
class CArkFlowNodeTrackviewPlaySequence : public CFlowBaseNode<1>, public IMovieListener
{ // Size=96 (0x60)
public:
	enum INPUTS
	{
		EIP_Sequence = 0,
		EIP_Start = 1,
		EIP_Pause = 2,
		EIP_Stop = 3,
		EIP_Precache = 4,
		EIP_StartTime = 5,
		EIP_DisableVision = 6,
		EIP_DisableHearing = 7,
		EIP_NpcCanAbort = 8,
	};

	enum OUTPUTS
	{
		EOP_Started = 0,
		EOP_Finished = 1,
		EOP_Aborted = 2,
	};

	enum class EPlayingState
	{
		PS_Stopped = 0,
		PS_Playing = 1,
		PS_Last = 2,
	};

	// CArkFlowNodeTrackviewPlaySequence::EntityInterpInfo
	// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeTrackviewPlaySequence.h
	struct EntityInterpInfo
	{ // Size=60 (0x3C)
		const unsigned m_entityId;
		const QuatT m_startTM;
		const QuatT m_endTM;

	#if 0
		EntityInterpInfo(unsigned _arg0_, const QuatT& _arg1_, const QuatT& _arg2_);
	#endif
	};

	_smart_ptr<IAnimSequence> m_pSequence;
	IFlowNode::SActivationInfo m_actInfo;
	CArkFlowNodeTrackviewPlaySequence::EPlayingState m_playingState;
	float m_currentTime;
	float m_currentSpeed;
	bool m_bPostSerializePlay;
	bool m_bPostSerializePaused;

	CArkFlowNodeTrackviewPlaySequence(IFlowNode::SActivationInfo* pActInfo);
	virtual ~CArkFlowNodeTrackviewPlaySequence();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void OnMovieEvent(IMovieListener::EMovieEvent event, IAnimSequence* pSequence);
	virtual void PlaySerialized(IFlowNode::SActivationInfo* pActInfo);
	void SequenceAborted() { FSequenceAborted(this); }
	void SequenceStopped() { FSequenceStopped(this); }
	void StartSequence(IFlowNode::SActivationInfo* pActInfo, float curTime, float curSpeed, bool bNotifyStarted) { FStartSequence(this, pActInfo, curTime, curSpeed, bNotifyStarted); }
	void StopSequence(IFlowNode::SActivationInfo* pActInfo, bool bUnRegisterOnly, bool bAbort, bool bLeaveTime) { FStopSequence(this, pActInfo, bUnRegisterOnly, bAbort, bLeaveTime); }
	void NotifyEntities(IFlowNode::SActivationInfo* pActInfo, const bool _bSequenceStarting) { FNotifyEntities(this, pActInfo, _bSequenceStarting); }

#if 0
	void OnSequenceEnded();
	void PrecacheSequence(IFlowNode::SActivationInfo* _arg0_, float _arg1_);
	void PauseSequence(IFlowNode::SActivationInfo* _arg0_);
	void NotifyEntityScript(IEntity* _arg0_);
	void NotifyEntity(IEntity* const _arg0_, IFlowNode::SActivationInfo* _arg1_, const bool _arg2_);
	IAnimSequence* GetSequence(IFlowNode::SActivationInfo* const _arg0_) const;
	IEntity* GetEntity(IFlowNode::SActivationInfo* const _arg0_, const char* const _arg1_);
	IAttachment* GetAttachment(IFlowNode::SActivationInfo* const _arg0_, const char* const _arg1_, const char* const _arg2_);
	int GetAttachmentIndex(IFlowNode::SActivationInfo* const _arg0_, const char* const _arg1_, const char* const _arg2_);
	std::tuple<bool,QuatT_tpl<float> > GetAttachmentTransform(IFlowNode::SActivationInfo* const _arg0_, const ArkAttachmentKey& _arg1_);
#endif

	static inline auto FCArkFlowNodeTrackviewPlaySequenceOv1 = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x1321CE0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeTrackviewPlaySequence* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1321B50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeTrackviewPlaySequence* const _this, ICrySizer* s)>(0xA55F00);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x1322E10);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, SFlowNodeConfig& config)>(0x1321F70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1322B80);
	static inline auto FOnMovieEvent = PreyFunction<void(IMovieListener* const _this, IMovieListener::EMovieEvent event, IAnimSequence* pSequence)>(0x1322A30);
	static inline auto FPlaySerialized = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x1322B20);
	static inline auto FSequenceAborted = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this)>(0x1322D50);
	static inline auto FSequenceStopped = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this)>(0x1322DA0);
	static inline auto FStartSequence = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo, float curTime, float curSpeed, bool bNotifyStarted)>(0x1322FE0);
	static inline auto FStopSequence = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo, bool bUnRegisterOnly, bool bAbort, bool bLeaveTime)>(0x1323380);
	static inline auto FNotifyEntities = PreyFunction<void(CArkFlowNodeTrackviewPlaySequence* const _this, IFlowNode::SActivationInfo* pActInfo, const bool _bSequenceStarting)>(0x1322900);
};
#endif // MOONCRASH
