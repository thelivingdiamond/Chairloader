// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <_unknown/SGameRulesListener.h>

class ArkPlayer;
class CCryActor;
struct ICharacterInstance;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_AIBodyCount
// Header:  Prey/GameDll/nodes/flowactornodes.h
class CFlowNode_AIBodyCount : public CFlowBaseNode<1>, private SGameRulesListener
{ // Size=80 (0x50)
public:
	enum EInputPorts
	{
		eINP_Enable = 0,
		eINP_Disable = 1,
		eINP_Reset = 2,
	};

	enum EOutputPorts
	{
		eOUT_TotalDeaths = 0,
		eOUT_EnemyDeaths = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	int m_totalDeaths;
	int m_enemyDeaths;

	virtual ~CFlowNode_AIBodyCount();
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void OnActorDeath(CCryActor* pActor);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_AIBodyCount(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(CFlowNode_AIBodyCount* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x189D790);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_AIBodyCount* const _this, SFlowNodeConfig& config)>(0x189D7E0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_AIBodyCount* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189D560);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_AIBodyCount* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x189DBC0);
	static inline auto FOnActorDeath = PreyFunction<void(SGameRulesListener* const _this, CCryActor* pActor)>(0x189DCF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_AIBodyCount* const _this, ICrySizer* s)>(0x4B5230);
};

// CFlowNode_ActorSetPlayerModel
// Header:  Prey/GameDll/nodes/flowactornodes.h
class CFlowNode_ActorSetPlayerModel : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum EInputs
	{
		eIN_Set = 0,
		eIN_Model = 1,
	};

	enum EOutputs
	{
		eOUT_Set = 0,
		eOUT_Fail = 1,
	};

	_smart_ptr<ICharacterInstance> m_pPlayerModel;

	virtual ~CFlowNode_ActorSetPlayerModel();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_ActorSetPlayerModel(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_ActorSetPlayerModel* const _this, SFlowNodeConfig& config)>(0x189C800);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_ActorSetPlayerModel* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189CB70);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_ActorSetPlayerModel* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x189CBC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_ActorSetPlayerModel* const _this, ICrySizer* s)>(0x4BC120);
};

// CFlowNode_GetNearestActor
// Header:  Prey/GameDll/nodes/flowactornodes.h
class CFlowNode_GetNearestActor : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInput
	{
		eINP_Trigger = 0,
		eINP_CenterPos = 1,
		eINP_MaxDist = 2,
		eINP_Faction = 3,
		eINP_FactionFilterType = 4,
		eINP_DeadAliveFilter = 5,
	};

	enum EOutput
	{
		eOUT_NearestActorId = 0,
		eOUT_Faction = 1,
		eOUT_Position = 2,
		eOUT_Distance = 3,
		eOUT_Alive = 4,
	};

	enum EFactionFilterType
	{
		eFCT_NoFilter = 0,
		eFCT_SameFactionOnly = 1,
		eFCT_AllButFaction = 2,
		eFCT_AnyFriendly = 3,
		eFCT_AnyHostile = 4,
	};

	enum EDeadAliveFilter
	{
		eDA_Any = 0,
		eDA_Alive = 1,
		eDA_Dead = 2,
	};

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void CheckNearestActor(IFlowNode::SActivationInfo* pActInfo) { FCheckNearestActor(this, pActInfo); }

#if 0
	CFlowNode_GetNearestActor(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_GetNearestActor* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_GetNearestActor* const _this, SFlowNodeConfig& config)>(0x189CD20);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_GetNearestActor* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x189D540);
	static inline auto FCheckNearestActor = PreyFunction<void(CFlowNode_GetNearestActor* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x189EAA0);
};

// CFlowNode_PlayerCinematicControl
// Header:  Prey/GameDll/nodes/flowactornodes.h
class CFlowNode_PlayerCinematicControl : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_HolsterWeapon = 0,
		eIN_LowerWeapon = 1,
		eIN_RestrictMovement = 2,
		eIN_RestrictToWalk = 3,
		eIN_TutorialMode = 4,
		eIN_ResetAll = 5,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_PlayerCinematicControl(IFlowNode::SActivationInfo* _arg0_);
	ArkPlayer* GetLocalPlayer() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_PlayerCinematicControl* const _this, SFlowNodeConfig& config)>(0x189DE50);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_PlayerCinematicControl* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x189E420);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_PlayerCinematicControl* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowNode_PlayerLookAt
// Header:  Prey/GameDll/nodes/flowactornodes.h
class CFlowNode_PlayerLookAt : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eIN_EnableLookAt = 0,
		eIN_DisableLookAt = 1,
		eIP_Force = 2,
		eIP_Time = 3,
	};

	enum class EArkOutputs
	{
		outTrigger = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_PlayerLookAt(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_PlayerLookAt* const _this, SFlowNodeConfig& config)>(0x189E4B0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_PlayerLookAt* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_PlayerLookAt* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
