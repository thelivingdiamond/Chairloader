// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNode_EnableEnemyHealthMeter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_EnableEnemyHealthMeter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_EnableEnemyHealthMeter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_EnableEnemyHealthMeter* const _this, SFlowNodeConfig& _config)>(0x1521A00);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_EnableEnemyHealthMeter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1521CD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_EnableEnemyHealthMeter* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_GetCharacterSpecialObjective
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_GetCharacterSpecialObjective : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_GetCharacterSpecialObjective(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_GetCharacterSpecialObjective* const _this, SFlowNodeConfig& _config)>(0x1522970);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_GetCharacterSpecialObjective* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1522B70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_GetCharacterSpecialObjective* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_GetPlayableCharacter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_GetPlayableCharacter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		name = 0,
		id = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_GetPlayableCharacter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_GetPlayableCharacter* const _this, SFlowNodeConfig& _config)>(0x15223A0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_GetPlayableCharacter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15225D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_GetPlayableCharacter* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_ItemRecycled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_ItemRecycled : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		archetype = 0,
		enabled = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNode_ItemRecycled*>>(0x2D5E420);

	ArkFlowNode_ItemRecycled(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNode_ItemRecycled();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyItemRecycled(unsigned _itemId) { FNotifyItemRecycled(_itemId); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnItemRecycled(unsigned _arg0_);
#endif

	static inline auto FArkFlowNode_ItemRecycledOv1 = PreyFunction<void(ArkFlowNode_ItemRecycled* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1523F70);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ItemRecycled* const _this, SFlowNodeConfig& _rConfig)>(0x1524230);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ItemRecycled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyItemRecycled = PreyFunction<void(unsigned _itemId)>(0x1524800);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_ItemRecycled* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_ItemRecycled* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1524130);
};

// ArkFlowNode_KillLatentPowers
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_KillLatentPowers : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_KillLatentPowers(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_KillLatentPowers* const _this, SFlowNodeConfig& _config)>(0x1521350);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_KillLatentPowers* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1521550);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_KillLatentPowers* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_LearnNameForResearchTopic
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_LearnNameForResearchTopic : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		research = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_LearnNameForResearchTopic(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_LearnNameForResearchTopic* const _this, SFlowNodeConfig& _config)>(0x15215D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_LearnNameForResearchTopic* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1521900);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_LearnNameForResearchTopic* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_PlayerCorpseCreated
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_PlayerCorpseCreated : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkOutputs
	{
		corpse = 0,
		phantomInhibited = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNode_PlayerCorpseCreated*>>(0x2D5E408);

	ArkFlowNode_PlayerCorpseCreated(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNode_PlayerCorpseCreated();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyCorspeCreated(unsigned _corpseId) { FNotifyCorspeCreated(_corpseId); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnCorpseCreated(unsigned _arg0_);
#endif

	static inline auto FArkFlowNode_PlayerCorpseCreatedOv1 = PreyFunction<void(ArkFlowNode_PlayerCorpseCreated* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1523FC0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_PlayerCorpseCreated* const _this, SFlowNodeConfig& _rConfig)>(0x1524590);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_PlayerCorpseCreated* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyCorspeCreated = PreyFunction<void(unsigned _corpseId)>(0x15246F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_PlayerCorpseCreated* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_PlayerCorpseCreated* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15241B0);
};

// ArkFlowNode_RestrictPlayerItems
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_RestrictPlayerItems : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		restricted = 0,
		unrestricted = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_RestrictPlayerItems(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_RestrictPlayerItems* const _this, SFlowNodeConfig& _config)>(0x1520FF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_RestrictPlayerItems* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15212D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_RestrictPlayerItems* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_SetPlayableCharacter
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_SetPlayableCharacter : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		character = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_SetPlayableCharacter(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SetPlayableCharacter* const _this, SFlowNodeConfig& _config)>(0x1521DE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SetPlayableCharacter* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1522110);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SetPlayableCharacter* const _this, ICrySizer* _s)>(0x455F00);
};

// ArkFlowNode_UpdatePlayableCharacterStatus
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class ArkFlowNode_UpdatePlayableCharacterStatus : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		character = 0,
		unlock = 1,
		escape = 2,
		dead = 3,
		escapeMethod = 4,
	};

	enum class EOutputs
	{
		unlocked = 0,
		escaped = 1,
		died = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	ArkFlowNode_UpdatePlayableCharacterStatus(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_UpdatePlayableCharacterStatus* const _this, SFlowNodeConfig& _config)>(0x1522E00);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_UpdatePlayableCharacterStatus* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15234A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_UpdatePlayableCharacterStatus* const _this, ICrySizer* _s)>(0x455F00);
};

// CArkFlowNode_HideFailedAbilityInteractions
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class CArkFlowNode_HideFailedAbilityInteractions : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		hide = 0,
		show = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_HideFailedAbilityInteractions(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_HideFailedAbilityInteractions* const _this, SFlowNodeConfig& _config)>(0x1520CC0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_HideFailedAbilityInteractions* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1520F80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_HideFailedAbilityInteractions* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_OnPlayerSpawned
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class CArkFlowNode_OnPlayerSpawned : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_OnPlayerSpawned(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_OnPlayerSpawned* const _this, SFlowNodeConfig& _config)>(0x1520980);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_OnPlayerSpawned* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1520B40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_OnPlayerSpawned* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_SetPlayerStance
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class CArkFlowNode_SetPlayerStance : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		stance = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_SetPlayerStance(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_SetPlayerStance* const _this, SFlowNodeConfig& _config)>(0x15205E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_SetPlayerStance* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15208B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_SetPlayerStance* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_SkipNextDeathDelay
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class CArkFlowNode_SkipNextDeathDelay : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_SkipNextDeathDelay(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_SkipNextDeathDelay* const _this, SFlowNodeConfig& _config)>(0x1520380);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_SkipNextDeathDelay* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1520570);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_SkipNextDeathDelay* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_TestFlashlight
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayer.h
class CArkFlowNode_TestFlashlight : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		enabled = 0,
		disabled = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_TestFlashlight(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_TestFlashlight* const _this, SFlowNodeConfig& _config)>(0x15239A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_TestFlashlight* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1523BC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_TestFlashlight* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
