// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct ILoadGame;
struct ISaveGame;
struct SActionEvent;
struct SFlowNodeConfig;

// CFlowNode_SetPostEffectParam
// Header:  Prey/GameDll/nodes/gamenodes.h
class CFlowNode_SetPostEffectParam : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum INPUTS
	{
		EIP_Set = 0,
		EIP_Force = 1,
		EIP_ParamName = 2,
		EIP_ParamFloat = 3,
	};

	enum OUTPUTS
	{
		EOP_Set = 0,
	};

	virtual ~CFlowNode_SetPostEffectParam();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_SetPostEffectParam(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_SetPostEffectParam* const _this, SFlowNodeConfig& config)>(0x18AF7C0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_SetPostEffectParam* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_SetPostEffectParam* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowSaveGameNode
// Header:  Prey/GameDll/nodes/gamenodes.h
class CFlowSaveGameNode : public CFlowBaseNode<1>, public IGameFrameworkListener
{ // Size=48 (0x30)
public:
	enum #unnamed_enum_EIP_Save
	{
		EIP_Save = 0,
		EIP_Load = 1,
		EIP_Name = 2,
		EIP_Desc = 3,
		EIP_EnableSave = 4,
		EIP_DisableSave = 5,
		EIP_DelaySaveIfPlayerInAir = 6,
		EIP_SaveExists = 7,
	};

	enum #unnamed_enum_EOP_SaveOrLoadDone
	{
		EOP_SaveOrLoadDone = 0,
		EOP_SaveExists = 1,
		EOP_Enabled = 2,
		EOP_Disabled = 3,
	};

	enum EState
	{
		ES_Idle = 0,
		ES_WaitForSaveDone = 1,
		ES_Notify = 2,
		ES_WaitForPlayerNotInAir = 3,
	};

	enum #unnamed_enum_EXTRA_CHECK_DEAD_NUMFRAMES
	{
		EXTRA_CHECK_DEAD_NUMFRAMES = 5,
	};

	CFlowSaveGameNode::EState m_state;
	string m_name;
	int m_extraCheckDeadTimerCounter;

	virtual ~CFlowSaveGameNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void Save(IFlowNode::SActivationInfo* pActInfo) { FSave(this, pActInfo); }
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* pNextLevel);
	virtual void OnActionEvent(const SActionEvent& event);

#if 0
	CFlowSaveGameNode(IFlowNode::SActivationInfo* _arg0_);
	bool PlayerIsInAir();
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowSaveGameNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18AFCC0);
	static inline auto FSerialize = PreyFunction<void(CFlowSaveGameNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18AFD30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowSaveGameNode* const _this, ICrySizer* pSizer)>(0x4BAFC0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowSaveGameNode* const _this, SFlowNodeConfig& config)>(0x18AFDC0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowSaveGameNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B07B0);
	static inline auto FSave = PreyFunction<void(CFlowSaveGameNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B0C00);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0x1333E90);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0x1333E90);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0x1333E90);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* pNextLevel)>(0x1333E90);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0x18B0A70);
};
#endif // MOONCRASH
