// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEventScheduler.h>

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
	virtual ~ArkFlowNodeAbsoluteTimeEvent();
	
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
	virtual ~ArkFlowNodeRelativeTimeEvent();
	
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
	virtual ~ArkFlowNodeGetGameTime();
	
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
	virtual ~ArkFlowNodeSetGameTime();
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetGameTime *const _this, SFlowNodeConfig &_config)>(0x13B9910);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetGameTime *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x13B9F80);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeSetGameTime const *const _this, ICrySizer *_pS)>(0x44D760);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
struct tm;

// ArkEventScheduler
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkEventScheduler
{ // Size=40 (0x28)
public:
	// ArkEventScheduler::TimeEventInfo
	// Header:  Prey/GameDll/ark/ArkEventScheduler.h
	struct TimeEventInfo
	{ // Size=32 (0x20)
		uint16_t m_id;
		unsigned m_graphId;
		string m_levelName;
		uint64_t m_time;
		uint64_t m_period;

	#if 0
		TimeEventInfo(const uint16_t _arg0_, const unsigned _arg1_, const string& _arg2_, const uint64_t _arg3_, const uint64_t _arg4_);
		TimeEventInfo();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	using Time = uint64_t;

	std::vector<ArkEventScheduler::TimeEventInfo> m_events;
	uint64_t m_time;
	uint64_t m_playTime;

	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void OnLevelLoaded() { FOnLevelLoaded(this); }
	const tm& GetTime() const { return FGetTime(this); }
	int GetPlayTimeInMinutes() const { return FGetPlayTimeInMinutes(this); }
	float GetPlayTimeInSeconds() const { return FGetPlayTimeInSeconds(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void AddEvent(const IFlowNode::SActivationInfo& _actInfo, const uint64_t _time) { FAddEvent(this, _actInfo, _time); }
	static const char* GetLevelName(const IFlowNode::SActivationInfo& _actInfo) { return FGetLevelName(_actInfo); }
	static bool Compare(const ArkEventScheduler::TimeEventInfo& _event, const IFlowNode::SActivationInfo& _actInfo) { return FCompare(_event, _actInfo); }

#if 0
	ArkEventScheduler();
	void AddAbsoluteEvent(const IFlowNode::SActivationInfo& _arg0_);
	void AddRelativeEvent(const IFlowNode::SActivationInfo& _arg0_);
	float GetRemainingTime(const IFlowNode::SActivationInfo& _arg0_) const;
	const tm& GetTimeInFuture(float _arg0_) const;
	void RemoveEvent(const IFlowNode::SActivationInfo& _arg0_);
	float GetTimeRaw() const;
	void SetTime(tm _arg0_);
	void SortEvents();
	static const char* GetCurrentLevelName();
	static uint64_t FloatToTime(const float _arg0_);
	static float TimeToFloat(const uint64_t _arg0_);
	static const tm& GetTm(uint64_t _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<void(ArkEventScheduler* const _this, const float _frameTime)>(0x14C90F0);
	static inline auto FReset = PreyFunction<void(ArkEventScheduler* const _this)>(0x14C8FE0);
	static inline auto FSerialize = PreyFunction<void(ArkEventScheduler* const _this, TSerialize _ser)>(0x14C9000);
	static inline auto FOnLevelLoaded = PreyFunction<void(ArkEventScheduler* const _this)>(0x14C8FD0);
	static inline auto FGetTime = PreyFunction<const tm& (const ArkEventScheduler* const _this)>(0x14C8F60);
	static inline auto FGetPlayTimeInMinutes = PreyFunction<int(const ArkEventScheduler* const _this)>(0x14C8EF0);
	static inline auto FGetPlayTimeInSeconds = PreyFunction<float(const ArkEventScheduler* const _this)>(0x14C8F30);
	static inline auto FOnGameEnded = PreyFunction<void(ArkEventScheduler* const _this)>(0x14C8FC0);
	static inline auto FAddEvent = PreyFunction<void(ArkEventScheduler* const _this, const IFlowNode::SActivationInfo& _actInfo, const uint64_t _time)>(0x14C8C60);
	static inline auto FGetLevelName = PreyFunction<const char* (const IFlowNode::SActivationInfo& _actInfo)>(0x14C8E80);
	static inline auto FCompare = PreyFunction<bool(const ArkEventScheduler::TimeEventInfo& _event, const IFlowNode::SActivationInfo& _actInfo)>(0x14C8D70);
};

// ArkFlowNodeTimeEventBase
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkFlowNodeTimeEventBase : public CFlowBaseNode<1>
{ // Size=64 (0x40)
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

	static bool TriggerPastDue(const uint16_t _id, const unsigned _graphId, const float _delta, const int _count) { return FTriggerPastDue(_id, _graphId, _delta, _count); }
	virtual ~ArkFlowNodeTimeEventBase();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static IFlowNode::SActivationInfo* FindActInfo(const uint16_t _id, const unsigned _graphId) { return FFindActInfo(_id, _graphId); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	static bool Trigger(const uint16_t _arg0_, const unsigned _arg1_);
	ArkFlowNodeTimeEventBase(const IFlowNode::SActivationInfo& _arg0_);
#endif

	static inline auto FTriggerPastDue = PreyFunction<bool(const uint16_t _id, const unsigned _graphId, const float _delta, const int _count)>(0x14C9060);
	static inline auto FBitNotArkFlowNodeTimeEventBase = PreyFunction<void(ArkFlowNodeTimeEventBase* const _this)>(0x14C8BF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeTimeEventBase* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14C5D10);
	static inline auto FFindActInfo = PreyFunction<IFlowNode::SActivationInfo* (const uint16_t _id, const unsigned _graphId)>(0x14C8DF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeTimeEventBase* const _this, ICrySizer* _pS)>(0x182A3D0);
};

// ArkFlowNodeAbsoluteTimeEvent
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkFlowNodeAbsoluteTimeEvent : public ArkFlowNodeTimeEventBase
{ // Size=64 (0x40)
public:
	ArkFlowNodeAbsoluteTimeEvent(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

	static inline auto FArkFlowNodeAbsoluteTimeEventOv2 = PreyFunction<void(ArkFlowNodeAbsoluteTimeEvent* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x14C8B30);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeAbsoluteTimeEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x14C5EC0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeAbsoluteTimeEvent* const _this, SFlowNodeConfig& _config)>(0x14C5F60);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeAbsoluteTimeEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14C65B0);
};

// ArkFlowNodeRelativeTimeEvent
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkFlowNodeRelativeTimeEvent : public ArkFlowNodeTimeEventBase
{ // Size=64 (0x40)
public:
	ArkFlowNodeRelativeTimeEvent(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

	static inline auto FArkFlowNodeRelativeTimeEventOv2 = PreyFunction<void(ArkFlowNodeRelativeTimeEvent* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x14C8B90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeRelativeTimeEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x14C4690);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeRelativeTimeEvent* const _this, SFlowNodeConfig& _config)>(0x14C4730);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeRelativeTimeEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14C4D80);
};

// ArkFlowNodeGetGameTime
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkFlowNodeGetGameTime : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class OutPort
	{
		OUTP_Out = 0,
		OUTP_Time = 1,
		OUTP_Day = 2,
		OUTP_Hour = 3,
		OUTP_Minute = 4,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeGetGameTime(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetGameTime* const _this, SFlowNodeConfig& _config)>(0x14C4EE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetGameTime* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14C51B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeGetGameTime* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNodeSetGameTime
// Header:  Prey/GameDll/ark/ArkEventScheduler.h
class ArkFlowNodeSetGameTime : public CFlowBaseNode<0>
{ // Size=16 (0x10)
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

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeSetGameTime(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetGameTime* const _this, SFlowNodeConfig& _config)>(0x14C5390);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetGameTime* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14C5A00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeSetGameTime* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // !MOONCRASH
