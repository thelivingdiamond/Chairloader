// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/iface/IGameRulesKillListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerHealthListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <_unknown/IPlayerEventListener.h>

class ArkPlayer;
enum class EStance;
enum ESystemEvent;
struct HitInfo;
struct IActor;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_ActorSensor
// Header:  Prey/GameDll/nodes/flowactorsensor.h
class CFlowNode_ActorSensor
	: public CFlowBaseNode<1>
	, public IPlayerEventListener
	, public IGameRulesKillListener
	, public IArkPlayerHealthListener
{ // Size=104 (0x68)
public:
	enum INS
	{
		EIP_TRIGGER = 0,
		EIP_ENABLE = 1,
		EIP_DISABLE = 2,
	};

	enum OUTS
	{
		EOP_ITEMPICKEDUP = 0,
		EOP_ITEMDROPPED = 1,
		EOP_ITEMUSED = 2,
		EOP_OBJECTGRABBED = 3,
		EOP_OBJECTTHROWN = 4,
		EOP_STANCECHANGED = 5,
		EOP_JUMPED = 6,
		EOP_SPRINTED = 7,
		EOP_SPECIALMOVE = 8,
		EOP_ONDEATH = 9,
		EOP_ONREVIVE = 10,
		EOP_ONHEALTHCHANGE = 11,
		EOP_ONTOGGLETHIRDPERSON = 12,
		EOP_MAXHEALTH = 13,
		EOP_ISINWATER = 14,
		EOP_ISHEADUNDERWATER = 15,
		EOP_OXYGENLEVEL = 16,
	};

	unsigned m_entityId;
	IFlowNode::SActivationInfo m_actInfo;
	bool m_bEnabled;

	virtual ~CFlowNode_ActorSensor();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActivationInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	ArkPlayer* GetArkPlayer() const { return FGetArkPlayer(this); }
	void RegisterActor() { FRegisterActor(this); }
	void UnRegisterActor() { FUnRegisterActor(this); }
	void TriggerPorts(IFlowNode::SActivationInfo* pActInfo) { FTriggerPorts(this, pActInfo); }
	virtual void OnToggleThirdPerson(IActor* pActor, bool bThirdPerson);
	virtual void OnItemDropped(IActor* pActor, unsigned itemId);
	virtual void OnItemUsed(IActor* pActor, unsigned itemId);
	virtual void OnItemPickedUp(IActor* pActor, unsigned itemId);
	virtual void OnStanceChanged(IActor* pActor, EStance stance);
	virtual void OnSpecialMove(IActor* pActor, IPlayerEventListener::ESpecialMove move);
	virtual void OnObjectGrabbed(IActor* pActor, bool bIsGrab, unsigned objectId, bool bIsNPC, bool bIsTwoHanded);
	virtual void OnRevive(IActor* pActor, bool bIsGod);
	virtual void OnHealthChanged(IActor* pActor, float fHealth);
	virtual void OnHealthChanged();
	virtual void OnIsInWater(IActor* pActor, bool bIsInWater);
	virtual void OnHeadUnderwater(IActor* pActor, bool bHeadUnderwater);
	virtual void OnOxygenLevelChanged(IActor* pActor, float fNewOxygenLevel);
	virtual void OnEntityKilledEarly(const HitInfo& hitInfo);
	virtual void OnEntityKilled(const HitInfo& hitInfo);
	virtual void OnEntityBroken(const unsigned _brokenEntityId);

#if 0
	CFlowNode_ActorSensor(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_ActorSensor* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x189EDB0);
	static inline auto FSerialize = PreyFunction<void(CFlowNode_ActorSensor* const _this, IFlowNode::SActivationInfo* pActivationInfo, TSerialize ser)>(0x18A06D0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_ActorSensor* const _this, SFlowNodeConfig& config)>(0x189F9C0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_ActorSensor* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A0490);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_ActorSensor* const _this, ICrySizer* s)>(0x18AD2D0);
	static inline auto FGetArkPlayer = PreyFunction<ArkPlayer* (const CFlowNode_ActorSensor* const _this)>(0x189F960);
	static inline auto FRegisterActor = PreyFunction<void(CFlowNode_ActorSensor* const _this)>(0x18A0540);
	static inline auto FUnRegisterActor = PreyFunction<void(CFlowNode_ActorSensor* const _this)>(0x18A0990);
	static inline auto FTriggerPorts = PreyFunction<void(CFlowNode_ActorSensor* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18A0750);
	static inline auto FOnToggleThirdPerson = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bThirdPerson)>(0x18A0450);
	static inline auto FOnItemDropped = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x18A0220);
	static inline auto FOnItemUsed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x18A02A0);
	static inline auto FOnItemPickedUp = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, unsigned itemId)>(0x18A0260);
	static inline auto FOnStanceChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, EStance stance)>(0x18A0410);
	static inline auto FOnSpecialMove = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, IPlayerEventListener::ESpecialMove move)>(0x18A03B0);
	static inline auto FOnObjectGrabbed = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGrab, unsigned objectId, bool bIsNPC, bool bIsTwoHanded)>(0x18A02E0);
	static inline auto FOnRevive = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsGod)>(0x18A0370);
	static inline auto FOnHealthChangedOv1 = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float fHealth)>(0x18A00D0);
	static inline auto FOnHealthChangedOv0 = PreyFunction<void(IArkPlayerHealthListener* const _this)>(0x18A0160);
	static inline auto FOnIsInWater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bIsInWater)>(0x18A01E0);
	static inline auto FOnHeadUnderwater = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, bool bHeadUnderwater)>(0x18A0090);
	static inline auto FOnOxygenLevelChanged = PreyFunction<void(IPlayerEventListener* const _this, IActor* pActor, float fNewOxygenLevel)>(0x18A0330);
	static inline auto FOnEntityKilledEarly = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& hitInfo)>(0x18A0050);
	static inline auto FOnEntityKilled = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& hitInfo)>(0x1333E90);
	static inline auto FOnEntityBroken = PreyFunction<void(IGameRulesKillListener* const _this, const unsigned _brokenEntityId)>(0x1333E90);
};

// CFlowNode_OverrideFOV
// Header:  Prey/GameDll/nodes/flowactorsensor.h
class CFlowNode_OverrideFOV : public CFlowBaseNode<0>, public ISystemEventListener
{ // Size=32 (0x20)
public:
	enum INPUTS
	{
		EIP_SetFOV = 0,
		EIP_GetFOV = 1,
		EIP_ResetFOV = 2,
	};

	enum OUTPUTS
	{
		EOP_CurFOV = 0,
		EOP_ResetDone = 1,
	};

	float m_storedFOV;

	virtual ~CFlowNode_OverrideFOV();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void ResetFOV() { FResetFOV(this); }
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);

#if 0
	CFlowNode_OverrideFOV(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_OverrideFOV* const _this, SFlowNodeConfig& config)>(0x189EEE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_OverrideFOV* const _this, ICrySizer* s)>(0x189F2B0);
	static inline auto FSerialize = PreyFunction<void(CFlowNode_OverrideFOV* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x189F2D0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_OverrideFOV* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x189F420);
	static inline auto FResetFOV = PreyFunction<void(CFlowNode_OverrideFOV* const _this)>(0x18A0620);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x189F590);
};
#endif // MOONCRASH
