// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class CHUDFader;
class ICrySizer;
struct IFlowNode;
struct ILoadGame;
struct IRenderer;
struct ISaveGame;
class ITexture;
struct SActionEvent;
struct SFlowNodeConfig;

// CFlowFadeNode
// Header:  Prey/GameDll/nodes/FlowFadeNode.h
class CFlowFadeNode : public CFlowBaseNode<1>
{ // Size=40 (0x28)
public:
	enum EInputPorts
	{
		EIP_FadeGroup = 0,
		EIP_FadeIn = 1,
		EIP_FadeOut = 2,
		EIP_UseCurrentColor = 3,
		EIP_InTime = 4,
		EIP_OutTime = 5,
		EIP_Color = 6,
		EIP_TextureName = 7,
		EIP_UpdateAlways = 8,
	};

	enum EOutputPorts
	{
		EOP_FadedIn = 0,
		EOP_FadedOut = 1,
		EOP_FadeColor = 2,
	};

	int m_ticket;
	int m_direction;
	int m_nFaderOffset;
	int m_postSerializeTrigger;
	bool m_bPlaying;
	bool m_bNeedFaderStop;

	CHUDFader* GetFader(IFlowNode::SActivationInfo* pActInfo) { return FGetFader(this, pActInfo); }
	virtual ~CFlowFadeNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	void StartFader(IFlowNode::SActivationInfo* pActInfo) { FStartFader(this, pActInfo); }
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlowFadeNode(IFlowNode::SActivationInfo* _arg0_);
	void StopFader(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetFader = PreyFunction<CHUDFader* (CFlowFadeNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18A6160);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowFadeNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A4DD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowFadeNode* const _this, ICrySizer* s)>(0x4C68D0);
	static inline auto FSerialize = PreyFunction<void(CFlowFadeNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18A4E30);
	static inline auto FStartFader = PreyFunction<void(CFlowFadeNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18A6450);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowFadeNode* const _this, SFlowNodeConfig& config)>(0x18A4F00);
	static inline auto FProcessEvent = PreyFunction<void(CFlowFadeNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A58C0);
};

// CHUDFader
// Header:  Prey/GameDll/nodes/FlowFadeNode.h
class CHUDFader
{ // Size=96 (0x60)
public:
	IRenderer* m_pRenderer;
	ColorF m_currentColor;
	ColorF m_targetColor;
	ColorF m_drawColor;
	ITexture* m_pTexture;
	float m_duration;
	float m_curTime;
	int m_direction;
	int m_ticket;
	bool m_bActive;
	bool m_bUpdateAlways;
	float m_lastTime;

	virtual ~CHUDFader();
	int FadeOut(const ColorF& targetColor, float fDuration, const char* textureName, bool bUseCurrentColor, bool bUpdateAlways) { return FFadeOut(this, targetColor, fDuration, textureName, bUseCurrentColor, bUpdateAlways); }
	virtual void Update(float fDeltaTime);
	virtual void Draw();

#if 0
	CHUDFader();
	const char* GetDebugName() const;
	void Stop();
	void Reset();
	bool IsActive() const;
	bool IsPlaying(int _arg0_) const;
	ColorF GetCurrentColor();
	int FadeIn(const ColorF& _arg0_, float _arg1_, bool _arg2_, bool _arg3_);
	static ITexture* LoadTexture(const char* _arg0_);
	void SetTexture(const char* _arg0_);
#endif

	static inline auto FFadeOut = PreyFunction<int(CHUDFader* const _this, const ColorF& targetColor, float fDuration, const char* textureName, bool bUseCurrentColor, bool bUpdateAlways)>(0x18A5F80);
	static inline auto FUpdate = PreyFunction<void(CHUDFader* const _this, float fDeltaTime)>(0x18A67F0);
	static inline auto FDraw = PreyFunction<void(CHUDFader* const _this)>(0x18A5EA0);
};

// CMasterFader
// Header:  Prey/GameDll/nodes/FlowFadeNode.h
class CMasterFader : public IGameFrameworkListener
{ // Size=80 (0x50)
public:
	bool m_bRegistered;
	CHUDFader* m_pHUDFader[8];

	virtual ~CMasterFader();
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* nextLevel);
	virtual void OnActionEvent(const SActionEvent& event);
	virtual void Update(float fDeltaTime);
	virtual void OnHUDToBeDestroyed();
	virtual void Serialize(TSerialize ser);

#if 0
	CMasterFader();
	CHUDFader* GetHUDFader(int _arg0_);
	void Register();
	void UnRegister();
#endif

	static inline auto FOnPostUpdate = PreyFunction<void(CMasterFader* const _this, float fDeltaTime)>(0x18A63A0);
	static inline auto FOnSaveGame = PreyFunction<void(CMasterFader* const _this, ISaveGame* pSaveGame)>(0x1333E90);
	static inline auto FOnLoadGame = PreyFunction<void(CMasterFader* const _this, ILoadGame* pLoadGame)>(0x1333E90);
	static inline auto FOnLevelEnd = PreyFunction<void(CMasterFader* const _this, const char* nextLevel)>(0x1333E90);
	static inline auto FOnActionEvent = PreyFunction<void(CMasterFader* const _this, const SActionEvent& event)>(0x18A6340);
	static inline auto FUpdate = PreyFunction<void(CMasterFader* const _this, float fDeltaTime)>(0x18A6920);
	static inline auto FOnHUDToBeDestroyed = PreyFunction<void(CMasterFader* const _this)>(0x18A6350);
	static inline auto FSerialize = PreyFunction<void(CMasterFader* const _this, TSerialize ser)>(0x18A63B0);
};
#endif // MOONCRASH
