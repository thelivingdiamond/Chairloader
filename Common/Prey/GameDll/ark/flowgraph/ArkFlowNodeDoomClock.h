// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <_unknown/IArkDoomClockListener.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeDoomClock
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeDoomClock.h
class ArkFlowNodeDoomClock : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		in_increment = 0,
		in_decrement = 1,
		in_reset = 2,
		in_level = 3,
		in_setLevel = 4,
	};

	enum class OutPort
	{
		out = 0,
		out_level = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeDoomClock(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDoomClock* const _this, SFlowNodeConfig& _config)>(0x131D6C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDoomClock* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131DC40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDoomClock* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNodeDoomClockListener
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeDoomClock.h
class ArkFlowNodeDoomClockListener : public CFlowBaseNode<1>, public IArkDoomClockListener
{ // Size=72 (0x48)
public:
	enum InPort
	{
	};

	enum class OutPort
	{
		increment = 0,
		preincrement = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;

	virtual ~ArkFlowNodeDoomClockListener();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void OnDoomClockIncrement(int _doomClockLevel);
	virtual void OnDoomClockPreIncrement(int _doomClockLevel);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Release();

#if 0
	ArkFlowNodeDoomClockListener(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDoomClockListener* const _this, SFlowNodeConfig& _config)>(0x131CCF0);
	static inline auto FOnDoomClockIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _doomClockLevel)>(0x131CE50);
	static inline auto FOnDoomClockPreIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _doomClockLevel)>(0x131CE90);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDoomClockListener* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131CED0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDoomClockListener* const _this, ICrySizer* _pSizer)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeDoomClockListener* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131CF30);
	static inline auto FRelease = PreyFunction<void(ArkFlowNodeDoomClockListener* const _this)>(0x131CFB0);
};

// ArkFlowNodeDoomClockProfile
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeDoomClock.h
class ArkFlowNodeDoomClockProfile : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		profileName = 0,
		set = 1,
	};

	enum class OutPort
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeDoomClockProfile(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDoomClockProfile* const _this, SFlowNodeConfig& _config)>(0x131DEA0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDoomClockProfile* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131E1F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDoomClockProfile* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNodeEnableDoomClock
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeDoomClock.h
class ArkFlowNodeEnableDoomClock : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		enable = 0,
		disable = 1,
	};

	enum class OutPort
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeEnableDoomClock(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEnableDoomClock* const _this, SFlowNodeConfig& _config)>(0x131D320);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeEnableDoomClock* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131D600);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeEnableDoomClock* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNodeGetDoomClockLevel
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeDoomClock.h
class ArkFlowNodeGetDoomClockLevel : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		getLevel = 0,
	};

	enum class OutPort
	{
		out = 0,
		level = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeGetDoomClockLevel(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetDoomClockLevel* const _this, SFlowNodeConfig& _config)>(0x131D040);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDoomClockLevel* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131D280);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeGetDoomClockLevel* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
