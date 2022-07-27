// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeventscheduler.h>

class ICrySizer;
struct SFlowNodeConfig;
struct tm;

// Header: Exact
// Prey/GameDll/ark/ArkEventScheduler.h
class ArkEventScheduler // Id=80166BB Size=40
{
public:
	using Time = uint64_t;
	
	struct TimeEventInfo // Id=80166BC Size=32
	{
		uint16_t m_id;
		unsigned m_graphId;
		string m_levelName;
		uint64_t m_time;
		uint64_t m_period;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkEventScheduler::TimeEventInfo> m_events;
	uint64_t m_time;
	uint64_t m_playTime;
	
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	tm const &GetTimeInFuture(float time_to_add) const { return FGetTimeInFuture(this,time_to_add); }
	void OnLevelLoaded() { FOnLevelLoaded(this); }
	tm const &GetTime() const { return FGetTime(this); }
	int GetPlayTimeInMinutes() const { return FGetPlayTimeInMinutes(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void AddEvent(IFlowNode::SActivationInfo const &_actInfo, const uint64_t _time) { FAddEvent(this,_actInfo,_time); }
	static const char *GetLevelName(IFlowNode::SActivationInfo const &_actInfo) { return FGetLevelName(_actInfo); }
	static bool Compare(ArkEventScheduler::TimeEventInfo const &_event, IFlowNode::SActivationInfo const &_actInfo) { return FCompare(_event,_actInfo); }
	
#if 0
	void AddAbsoluteEvent(IFlowNode::SActivationInfo const &arg0);
	void AddRelativeEvent(IFlowNode::SActivationInfo const &arg0);
	float GetRemainingTime(IFlowNode::SActivationInfo const &arg0) const;
	void RemoveEvent(IFlowNode::SActivationInfo const &arg0);
	float GetTimeRaw() const;
	void SetTime(tm arg0);
	void SortEvents();
	static const char *GetCurrentLevelName();
	static uint64_t FloatToTime(const float arg0);
	static float TimeToFloat(const uint64_t arg0);
	static tm const &GetTm(uint64_t arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkEventScheduler *const _this, const float _frameTime)>(0x13BCDE0);
	static inline auto FReset = PreyFunction<void(ArkEventScheduler *const _this)>(0x13BCCD0);
	static inline auto FSerialize = PreyFunction<void(ArkEventScheduler *const _this, TSerialize _ser)>(0x13BCCF0);
	static inline auto FGetTimeInFuture = PreyFunction<tm const &(ArkEventScheduler const *const _this, float time_to_add)>(0x13BCC10);
	static inline auto FOnLevelLoaded = PreyFunction<void(ArkEventScheduler *const _this)>(0x13BCCC0);
	static inline auto FGetTime = PreyFunction<tm const &(ArkEventScheduler const *const _this)>(0x13BCBB0);
	static inline auto FGetPlayTimeInMinutes = PreyFunction<int(ArkEventScheduler const *const _this)>(0x13BCB70);
	static inline auto FOnGameEnded = PreyFunction<void(ArkEventScheduler *const _this)>(0x13BCCB0);
	static inline auto FAddEvent = PreyFunction<void(ArkEventScheduler *const _this, IFlowNode::SActivationInfo const &_actInfo, const uint64_t _time)>(0x13BC8E0);
	static inline auto FGetLevelName = PreyFunction<const char *(IFlowNode::SActivationInfo const &_actInfo)>(0x13BCB00);
	static inline auto FCompare = PreyFunction<bool(ArkEventScheduler::TimeEventInfo const &_event, IFlowNode::SActivationInfo const &_actInfo)>(0x13BC9F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeventscheduler.h
class ArkFlowNodeTimeEventBase : public CFlowBaseNode<1> // Id=801BD16 Size=64
{
public:
	enum class InPort
	{
		INP_Enable = 0,
		INP_Disable = 1,
		INP_Time = 2,
		INP_Period = 3,
		INP_Query = 4,
	};

	enum class OutPort
	{
		OUTP_Enabled = 0,
		OUTP_Disabled = 1,
		OUTP_Alarm = 2,
		OUTP_PastDueDelta = 3,
		OUTP_PastDueCount = 4,
		OUTP_RemainingTime = 5,
	};

	IFlowNode::SActivationInfo m_actInfo;
	
	static bool TriggerPastDue(const uint16_t _id, const unsigned _graphId, const float _delta, const int _count) { return FTriggerPastDue(_id,_graphId,_delta,_count); }
	virtual ~ArkFlowNodeTimeEventBase();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	static IFlowNode::SActivationInfo *FindActInfo(const uint16_t _id, const unsigned _graphId) { return FFindActInfo(_id,_graphId); }
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	
#if 0
	static bool Trigger(const uint16_t arg0, const unsigned arg1);
#endif
	
	static inline auto FTriggerPastDue = PreyFunction<bool(const uint16_t _id, const unsigned _graphId, const float _delta, const int _count)>(0x13BCD50);
	static inline auto FBitNotArkFlowNodeTimeEventBase = PreyFunction<void(ArkFlowNodeTimeEventBase *const _this)>(0x13BC870);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeTimeEventBase *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13BA290);
	static inline auto FFindActInfo = PreyFunction<IFlowNode::SActivationInfo *(const uint16_t _id, const unsigned _graphId)>(0x13BCA70);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeTimeEventBase const *const _this, ICrySizer *_pS)>(0x1187D80);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeventscheduler.h
class ArkFlowNodeAbsoluteTimeEvent : public ArkFlowNodeTimeEventBase // Id=801BD15 Size=64
{
public:
	ArkFlowNodeAbsoluteTimeEvent(IFlowNode::SActivationInfo const *const _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(ArkFlowNodeAbsoluteTimeEvent *const _this, IFlowNode::SActivationInfo *_pActInfo)>(0x13B82C0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeAbsoluteTimeEvent *const _this, SFlowNodeConfig &_config)>(0x13B8360);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeAbsoluteTimeEvent *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13B89B0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeventscheduler.h
class ArkFlowNodeRelativeTimeEvent : public ArkFlowNodeTimeEventBase // Id=801BD18 Size=64
{
public:
	ArkFlowNodeRelativeTimeEvent(IFlowNode::SActivationInfo const *const _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(ArkFlowNodeRelativeTimeEvent *const _this, IFlowNode::SActivationInfo *_pActInfo)>(0x13B8C10);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeRelativeTimeEvent *const _this, SFlowNodeConfig &_config)>(0x13B8CB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeRelativeTimeEvent *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13B9300);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeventscheduler.h
class ArkFlowNodeGetGameTime : public CFlowBaseNode<0> // Id=801BD1A Size=16
{
public:
	enum class OutPort
	{
		OUTP_Out = 0,
		OUTP_Time = 1,
		OUTP_Day = 2,
		OUTP_Hour = 3,
		OUTP_Minute = 4,
	};

	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetGameTime *const _this, SFlowNodeConfig &_config)>(0x13B9460);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetGameTime *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13B9730);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeGetGameTime const *const _this, ICrySizer *_pS)>(0x44D760);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeventscheduler.h
class ArkFlowNodeSetGameTime : public CFlowBaseNode<0> // Id=801BD1C Size=16
{
public:
	enum class InPort
	{
		INP_Trigger = 0,
		INP_Year = 1,
		INP_Month = 2,
		INP_Day = 3,
		INP_Hour = 4,
		INP_Minute = 5,
	};

	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetGameTime *const _this, SFlowNodeConfig &_config)>(0x13B9910);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetGameTime *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13B9F80);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeSetGameTime const *const _this, ICrySizer *_pS)>(0x44D760);
};

