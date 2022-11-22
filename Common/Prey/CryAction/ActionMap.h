// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryAction/ActionMap.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CryCore/Containers/CryListenerSet.h>

class CActionMap;
class ICrySizer;
struct SActionInput;

// Header: FromCpp
// CryEngine/cryaction/actionmap.h
class CActionMapAction : public IActionMapAction // Id=80044A3 Size=112
{
public:
	CryFixedStringT<32> m_triggeredInput;
	CCryName m_actionId;
	std::vector<SActionInput *> m_actionInputs;
	CActionMap *m_pParentActionMap;
	int m_iNumRebindedInputs;
	
	CActionMapAction();
	virtual ~CActionMapAction();
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	virtual void Release();
	virtual int GetNumActionInputs() const;
	virtual SActionInput const *FindActionInput(const char *szInput) const;
	virtual SActionInput const *GetActionInput(const int iIndex) const;
	virtual SActionInput const *GetActionInput(EActionInputDevice device, const int iIndexByDevice) const;
	SActionInput *GetActionInput(EActionInputDevice device, const int iIndexByDevice) { return FGetActionInputOv0(this,device,iIndexByDevice); }
	virtual CCryName const &GetActionId() const;
	virtual const char *GetTriggeredActionInput() const;
	bool AddActionInput(SActionInput const &actionInput, const int iByDeviceIndex) { return FAddActionInput(this,actionInput,iByDeviceIndex); }
	bool RemoveActionInput(unsigned inputCRC) { return FRemoveActionInput(this,inputCRC); }
	SActionInput *AddAndGetActionInput(SActionInput const &actionInput) { return FAddAndGetActionInput(this,actionInput); }
	
#if 0
	SActionInput *FindActionInput(unsigned arg0);
	SActionInput *GetActionInput(const int arg0);
	void RemoveAllActionInputs();
	void SetParentActionMap(CActionMap *arg0);
	void SetActionId(CCryName const &arg0);
	void SetNumRebindedInputs(const int arg0);
	int GetNumRebindedInputs() const;
#endif
	
	static inline auto FBitNotCActionMapAction = PreyFunction<void(CActionMapAction *const _this)>(0x3C4700);
	static inline auto FGetMemoryUsage = PreyFunction<void(CActionMapAction const *const _this, ICrySizer *pSizer)>(0xA13080);
	static inline auto FRelease = PreyFunction<void(CActionMapAction *const _this)>(0xA97D40);
	static inline auto FGetNumActionInputs = PreyFunction<int(CActionMapAction const *const _this)>(0xA39880);
	static inline auto FFindActionInputOv1 = PreyFunction<SActionInput const *(CActionMapAction const *const _this, const char *szInput)>(0x3C5C80);
	static inline auto FGetActionInputOv3 = PreyFunction<SActionInput const *(CActionMapAction const *const _this, const int iIndex)>(0x3C5EA0);
	static inline auto FGetActionInputOv2 = PreyFunction<SActionInput const *(CActionMapAction const *const _this, EActionInputDevice device, const int iIndexByDevice)>(0x3C5E50);
	static inline auto FGetActionInputOv0 = PreyFunction<SActionInput *(CActionMapAction *const _this, EActionInputDevice device, const int iIndexByDevice)>(0x3C5E50);
	static inline auto FGetActionId = PreyFunction<CCryName const &(CActionMapAction const *const _this)>(0x12BDA90);
	static inline auto FGetTriggeredActionInput = PreyFunction<const char *(CActionMapAction const *const _this)>(0xD87500);
	static inline auto FAddActionInput = PreyFunction<bool(CActionMapAction *const _this, SActionInput const &actionInput, const int iByDeviceIndex)>(0x3C4F40);
	static inline auto FRemoveActionInput = PreyFunction<bool(CActionMapAction *const _this, unsigned inputCRC)>(0x3C9EE0);
	static inline auto FAddAndGetActionInput = PreyFunction<SActionInput *(CActionMapAction *const _this, SActionInput const &actionInput)>(0x3C5300);
};

class CActionMapManager;

// Header: Exact
// CryEngine/cryanimation/facialanimation/faceeffector.h
class CActionMap : public IActionMap // Id=80044A2 Size=104
{
public:
    using TActionMap = std::map<CCryName,CActionMapAction,std::less<CCryName>>;
    using TActionMapListeners = CListenerSet<IActionListener *>;

    bool m_enabled;
    CActionMapManager *m_pActionMapManager;
    std::map<CCryName,CActionMapAction,std::less<CCryName>> m_actions;
    unsigned m_listenerId;
    CListenerSet<IActionListener *> m_actionMapListeners;
    string m_name;
    int m_iNumRebindedInputs;

    CActionMap(CActionMapManager *pActionMapManager, const char *name);
    virtual ~CActionMap();
    virtual void GetMemoryUsage(ICrySizer *s) const;
    virtual void Release();
    virtual void Clear();
    virtual IActionMapAction const *GetAction(CCryName const &actionId) const;
    virtual IActionMapAction *GetAction(CCryName const &actionId);
    virtual IActionMapAction const *GetAction(const int _index) const;
    virtual IActionMapAction *GetAction(const int _index);
    virtual bool CreateAction(CCryName const &actionId);
    virtual bool RemoveAction(CCryName const &actionId);
    virtual int GetActionsCount() const;
    virtual bool AddActionInput(CCryName const &actionId, SActionInput const &actionInput, const int iByDeviceIndex);
    virtual bool AddAndBindActionInput(CCryName const &actionId, SActionInput const &actionInput);
    bool AddAndBindActionInput(CActionMapAction *pAction, SActionInput const &actionInput) { return FAddAndBindActionInputOv0(this,pAction,actionInput); }
    virtual bool RemoveActionInput(CCryName const &actionId, const char *szInput);
    virtual bool ReBindActionInput(CCryName const &actionId, const char *szCurrentInput, const char *szNewInput);
    virtual bool ReBindActionInput(CCryName const &actionId, const char *szNewInput, EActionInputDevice device, const int iByDeviceIndex);
    bool ReBindActionInput(CActionMapAction *pAction, const char *szCurrentInput, const char *szNewInput) { return FReBindActionInputOv2(this,pAction,szCurrentInput,szNewInput); }
    bool ReBindActionInput(CActionMapAction *pAction, SActionInput &actionInput, const char *szNewInput) { return FReBindActionInputOv1(this,pAction,actionInput,szNewInput); }
    bool ReBindActionInput(CActionMapAction *pAction, const char *szNewInput, EActionInputDevice device, const int iByDeviceIndex) { return FReBindActionInputOv0(this,pAction,szNewInput,device,iByDeviceIndex); }
    virtual int GetNumRebindedInputs();
    virtual bool Reset();
    virtual bool ResetBindings();
    virtual bool LoadFromXML(XmlNodeRef const &actionMapNode);
    virtual bool LoadRebindingDataFromXML(XmlNodeRef const &actionMapNode);
    virtual bool SaveRebindingDataToXML(XmlNodeRef &actionMapNode) const;
    virtual _smart_ptr<IActionMapActionIterator> CreateActionIterator();
    virtual void SetActionListener(unsigned id);
    virtual unsigned GetActionListener() const;
    virtual const char *GetName();
    virtual void Enable(bool enable);
    virtual bool Enabled() const;
    void EnumerateActions(IActionMapPopulateCallBack *pCallBack) const { FEnumerateActions(this,pCallBack); }
    bool CanProcessInput(SInputEvent const &inputEvent, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) { return FCanProcessInput(this,inputEvent,pActionMap,pAction,pActionInput); }
    bool IsActionInputTriggered(SInputEvent const &inputEvent, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) const { return FIsActionInputTriggered(this,inputEvent,pActionMap,pAction,pActionInput); }
    void InputProcessed() { FInputProcessed(this); }
    void ReleaseActionsIfActive() { FReleaseActionsIfActive(this); }
    void ReleaseActionIfActive(CCryName const &actionId) { FReleaseActionIfActive(this,actionId); }
    void ReleaseFilteredActions() { FReleaseFilteredActions(this); }
    void AddExtraActionListener(IActionListener *pExtraActionListener) { FAddExtraActionListener(this,pExtraActionListener); }
    void RemoveExtraActionListener(IActionListener *pExtraActionListener) { FRemoveExtraActionListener(this,pExtraActionListener); }
    void NotifyExtraActionListeners(CCryName const &action, int currentState, float value) { FNotifyExtraActionListeners(this,action,currentState,value); }
    CActionMapAction *CreateAndGetAction(CCryName const &actionId) { return FCreateAndGetAction(this,actionId); }
    void ReleaseActionIfActiveInternal(CActionMapAction &action) { FReleaseActionIfActiveInternal(this,action); }
    bool LoadActionInputAttributesFromXML(XmlNodeRef const &actionInputNode, SActionInput &actionInput) { return FLoadActionInputAttributesFromXML(this,actionInputNode,actionInput); }

#if 0
    EActionAnalogCompareOperation GetAnalogCompareOpTypeFromStr(const char *arg0);
	const char *GetAnalogCompareOpStr(EActionAnalogCompareOperation arg0) const;
	void SetNumRebindedInputs(const int arg0);
	bool LoadModifiersFromXML(const char *arg0, int &arg1);
	bool SaveActionInputAttributesToXML(XmlNodeRef &arg0, SActionInput const &arg1) const;
	void LoadActivationModeBitAttributeFromXML(XmlNodeRef const &arg0, int &arg1, const char *arg2, EActionActivationMode arg3);
	void SaveActivationModeBitAttributeToXML(XmlNodeRef &arg0, const int arg1, const char *arg2, EActionActivationMode arg3) const;
#endif

    static inline auto FGetMemoryUsage = PreyFunction<void(CActionMap const *const _this, ICrySizer *s)>(0x3C5ED0);
    static inline auto FRelease = PreyFunction<void(CActionMap *const _this)>(0x3C9540);
    static inline auto FClear = PreyFunction<void(CActionMap *const _this)>(0x3C5790);
    static inline auto FGetActionOv3 = PreyFunction<IActionMapAction const *(CActionMap const *const _this, CCryName const &actionId)>(0x3C5E00);
    static inline auto FGetActionOv2 = PreyFunction<IActionMapAction *(CActionMap *const _this, CCryName const &actionId)>(0x3C5E00);
    static inline auto FGetActionOv1 = PreyFunction<IActionMapAction const &(CActionMap const *const _this, const int _index)>(0x3C5D20);
    static inline auto FGetActionOv0 = PreyFunction<IActionMapAction &(CActionMap *const _this, const int _index)>(0x3C5D20);
    static inline auto FCreateAction = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId)>(0x3C57F0);
    static inline auto FRemoveAction = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId)>(0x3C9C60);
    static inline auto FGetActionsCount = PreyFunction<int(CActionMap const *const _this)>(0x12380B0);
    static inline auto FAddActionInput = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId, SActionInput const &actionInput, const int iByDeviceIndex)>(0x3C4E70);
    static inline auto FAddAndBindActionInputOv1 = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId, SActionInput const &actionInput)>(0x3C5220);
    static inline auto FAddAndBindActionInputOv0 = PreyFunction<bool(CActionMap *const _this, CActionMapAction *pAction, SActionInput const &actionInput)>(0x3C5160);
    static inline auto FRemoveActionInput = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId, const char *szInput)>(0x3C9DC0);
    static inline auto FReBindActionInputOv4 = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId, const char *szCurrentInput, const char *szNewInput)>(0x3C9420);
    static inline auto FReBindActionInputOv3 = PreyFunction<bool(CActionMap *const _this, CCryName const &actionId, const char *szNewInput, EActionInputDevice device, const int iByDeviceIndex)>(0x3C94B0);
    static inline auto FReBindActionInputOv2 = PreyFunction<bool(CActionMap *const _this, CActionMapAction *pAction, const char *szCurrentInput, const char *szNewInput)>(0x3C9070);
    static inline auto FReBindActionInputOv1 = PreyFunction<bool(CActionMap *const _this, CActionMapAction *pAction, SActionInput &actionInput, const char *szNewInput)>(0x3C8E20);
    static inline auto FReBindActionInputOv0 = PreyFunction<bool(CActionMap *const _this, CActionMapAction *pAction, const char *szNewInput, EActionInputDevice device, const int iByDeviceIndex)>(0x3C9170);
    static inline auto FGetNumRebindedInputs = PreyFunction<int(CActionMap *const _this)>(0xCE7E0);
    static inline auto FReset = PreyFunction<bool(CActionMap *const _this)>(0x3C9F70);
    static inline auto FResetBindings = PreyFunction<bool(CActionMap *const _this)>(0x3C9FB0);
    static inline auto FLoadFromXML = PreyFunction<bool(CActionMap *const _this, XmlNodeRef const &actionMapNode)>(0x3C7140);
    static inline auto FLoadRebindingDataFromXML = PreyFunction<bool(CActionMap *const _this, XmlNodeRef const &actionMapNode)>(0x3C8950);
    static inline auto FSaveRebindingDataToXML = PreyFunction<bool(CActionMap const *const _this, XmlNodeRef &actionMapNode)>(0x3CA110);
    static inline auto FCreateActionIterator = PreyFunction<_smart_ptr<IActionMapActionIterator>(CActionMap *const _this)>(0x3C5900);
    static inline auto FSetActionListener = PreyFunction<void(CActionMap *const _this, unsigned id)>(0x860630);
    static inline auto FGetActionListener = PreyFunction<unsigned(CActionMap const *const _this)>(0x158AF80);
    static inline auto FGetName = PreyFunction<const char *(CActionMap *const _this)>(0x1545000);
    static inline auto FEnable = PreyFunction<void(CActionMap *const _this, bool enable)>(0x3C5A80);
    static inline auto FEnabled = PreyFunction<bool(CActionMap const *const _this)>(0xAAD760);
    static inline auto FEnumerateActions = PreyFunction<void(CActionMap const *const _this, IActionMapPopulateCallBack *pCallBack)>(0x3C5BD0);
    static inline auto FCanProcessInput = PreyFunction<bool(CActionMap *const _this, SInputEvent const &inputEvent, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3C54F0);
    static inline auto FIsActionInputTriggered = PreyFunction<bool(CActionMap const *const _this, SInputEvent const &inputEvent, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3C60C0);
    static inline auto FInputProcessed = PreyFunction<void(CActionMap *const _this)>(0x3C5FC0);
    static inline auto FReleaseActionsIfActive = PreyFunction<void(CActionMap *const _this)>(0x3C9980);
    static inline auto FReleaseActionIfActive = PreyFunction<void(CActionMap *const _this, CCryName const &actionId)>(0x3C9560);
    static inline auto FReleaseFilteredActions = PreyFunction<void(CActionMap *const _this)>(0x3C9A20);
    static inline auto FAddExtraActionListener = PreyFunction<void(CActionMap *const _this, IActionListener *pExtraActionListener)>(0x3C54A0);
    static inline auto FRemoveExtraActionListener = PreyFunction<void(CActionMap *const _this, IActionListener *pExtraActionListener)>(0x313BC0);
    static inline auto FNotifyExtraActionListeners = PreyFunction<void(CActionMap *const _this, CCryName const &action, int currentState, float value)>(0x3C8D30);
    static inline auto FCreateAndGetAction = PreyFunction<CActionMapAction *(CActionMap *const _this, CCryName const &actionId)>(0x3C5980);
    static inline auto FReleaseActionIfActiveInternal = PreyFunction<void(CActionMap *const _this, CActionMapAction &action)>(0x3C95B0);
    static inline auto FLoadActionInputAttributesFromXML = PreyFunction<bool(CActionMap *const _this, XmlNodeRef const &actionInputNode, SActionInput &actionInput)>(0x3C6460);
};

