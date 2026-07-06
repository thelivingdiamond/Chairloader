// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeCharacterLocatedEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeCharacterLocatedEvent : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class ArkInputPort
	{
		CharacterId = 0,
	};

	enum class ArkOutputPort
	{
		Located = 0,
	};

	IFlowNode::SActivationInfo m_activationInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeCharacterLocatedEvent*>>(0x2D73128);

	CArkFlowNodeCharacterLocatedEvent(IFlowNode::SActivationInfo* _pInfo);
	virtual ~CArkFlowNodeCharacterLocatedEvent();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyLocated(const uint64_t _characterId) { FNotifyLocated(_characterId); }

#if 0
	void OnLocated(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeCharacterLocatedEventOv1 = PreyFunction<void(CArkFlowNodeCharacterLocatedEvent* const _this, IFlowNode::SActivationInfo* _pInfo)>(0x15C5330);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeCharacterLocatedEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C5470);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCharacterLocatedEvent* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCharacterLocatedEvent* const _this, SFlowNodeConfig& _config)>(0x15C5500);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCharacterLocatedEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyLocated = PreyFunction<void(const uint64_t _characterId)>(0x15C7B00);
};

// CArkFlowNodeGetCharacterIsAlive
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeGetCharacterIsAlive
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		IsAlive = 0,
		True = 1,
		False = 2,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetCharacterIsAlive* const _this, SFlowNodeConfig& _config)>(0x15C5780);
};

// CArkFlowNodeGetCharacterIsLocated
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeGetCharacterIsLocated
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		True = 1,
		False = 2,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetCharacterIsLocated* const _this, SFlowNodeConfig& _config)>(0x15C5B00);
};

// CArkFlowNodeGetCharacterLocation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeGetCharacterLocation
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		LocationID = 0,
		LocationLabel = 1,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }
	void OnActivated(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo) { FOnActivated(this, _event, _pActInfo); }

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetCharacterLocation* const _this, SFlowNodeConfig& _config)>(0x15C5E80);
	static inline auto FOnActivated = PreyFunction<void(CArkFlowNodeGetCharacterLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C7E10);
};

// CArkFlowNodeGetCharacterVitalSigns
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeGetCharacterVitalSigns
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		Nominal = 1,
		NoLifeSigns = 2,
		Error = 3,
		Safe = 4,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetCharacterVitalSigns* const _this, SFlowNodeConfig& _config)>(0x15C61D0);
};

// CArkFlowNodeSetCharacterDiscovered
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeSetCharacterDiscovered
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetCharacterDiscovered* const _this, SFlowNodeConfig& _config)>(0x15C65A0);
};

// CArkFlowNodeSetCharacterHasTrackingChip
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeSetCharacterHasTrackingChip
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		CharacterId = 0,
		AttachTrackingChip = 1,
		DetachTrackingChip = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetCharacterHasTrackingChip* const _this, SFlowNodeConfig& _config)>(0x15C68C0);
};

// CArkFlowNodeSetCharacterIsAlive
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeSetCharacterIsAlive
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		CharacterId = 0,
		Alive = 1,
		Dead = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetCharacterIsAlive* const _this, SFlowNodeConfig& _config)>(0x15C6CD0);
};

// CArkFlowNodeSetCharacterLocation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeSetCharacterLocation
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		CharacterId = 1,
		LocationId = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }
	void OnActivated(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo) { FOnActivated(this, _event, _pActInfo); }

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetCharacterLocation* const _this, SFlowNodeConfig& _config)>(0x15C70E0);
	static inline auto FOnActivated = PreyFunction<void(CArkFlowNodeSetCharacterLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C8140);
};

// CArkFlowNodeSetCharacterVitalSigns
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacterstatus.h
class CArkFlowNodeSetCharacterVitalSigns
{ // Size=1 (0x1)
public:
	enum class ArkInputPort
	{
		CharacterId = 0,
		NoLifeSigns = 1,
		Nominal = 2,
		Error = 3,
		Safe = 4,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	void GetConfiguration(SFlowNodeConfig& _config) { FGetConfiguration(this, _config); }

#if 0
	void OnActivated(IFlowNode::EFlowEvent _arg0_, IFlowNode::SActivationInfo* _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetCharacterVitalSigns* const _this, SFlowNodeConfig& _config)>(0x15C7540);
};
#endif // MOONCRASH
