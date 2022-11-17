// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ArkActionFilterStack.h>
//#include <Prey/CryAction/ActionMapManager.h>
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryInput/IInput.h>

class CActionFilter;
class CActionMap;
class CActionMapAction;
class CCryName;
struct IActionFilter;
class IActionFilterStack;
struct IActionListener;
struct IActionMap;
struct IActionMapEventListener;
struct IActionMapPopulateCallBack;
struct IConsoleCmdArgs;
class ICrySizer;
struct IInput;
struct SActionInput;
struct SActionInputDeviceData;
struct SActionMapEvent;
struct SInputEvent;
class XmlNodeRef;

// Header: Exact
// CryEngine/cryaction/actionmapmanager.h
class CActionMapManager : public IActionMapManager, public IInputEventListener // Id=80044A1 Size=256
{
public:
	std::vector<IActionListener *> m_ExtraActionListeners;
	
	struct SBindData // Id=80044E7 Size=24
	{
		SActionInput *m_pActionInput;
		CActionMapAction *m_pAction;
		CActionMap *m_pActionMap;
	};

	struct SRefireBindData // Id=80044E8 Size=32
	{
		CActionMapManager::SBindData m_bindData;
		bool m_bIgnoreNextUpdate;
		bool m_bDelayedPressNeedsRelease;
	};

	using TRefireBindData = std::vector<CActionMapManager::SRefireBindData>;
	
	struct SRefireData // Id=80044FD Size=88
	{
		unsigned m_inputCRC;
		SInputEvent m_inputEvent;
		std::vector<CActionMapManager::SRefireBindData> m_refireBindData;
	};

	using TInputCRCToBind = std::multimap<unsigned int,CActionMapManager::SBindData,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,CActionMapManager::SBindData> > >;
	using TBindPriorityList = std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> >;
	using TBlockingActionListeners = std::list<std::shared_ptr<IBlockingActionListener>,std::allocator<std::shared_ptr<IBlockingActionListener> > >;
	using TInputDeviceData = std::vector<SActionInputDeviceData>;
	using TInputCRCToRefireData = std::map<unsigned int,CActionMapManager::SRefireData *,std::less<unsigned int>>;
	
	struct SRefireReleaseListData // Id=8004571 Size=72
	{
		SInputEvent m_inputEvent;
		std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > m_inputsList;
	};

	string m_loadedXMLPath;
	IInput *m_pInput;
	std::map<string,CActionMap *,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CActionMap *>>> m_actionMaps;
	std::map<string,CActionFilter *,std::less<string>,std::allocator<std::pair<CryStringT<char> const,CActionFilter *>>> m_actionFilters;
	std::multimap<unsigned int,CActionMapManager::SBindData,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,CActionMapManager::SBindData> > > m_inputCRCToBind;
	std::map<unsigned int,CActionMapManager::SRefireData *,std::less<unsigned int>> m_inputCRCToRefireData;
	std::list<std::shared_ptr<IBlockingActionListener>,std::allocator<std::shared_ptr<IBlockingActionListener> > > m_alwaysActionListeners;
	std::map<string,XmlNodeRef,std::less<string>,std::allocator<std::pair<CryStringT<char> const,XmlNodeRef>>> m_preloadedControllerLayouts;
	std::vector<SActionInputDeviceData> m_inputDeviceData;
	EKeyId m_currentInputKeyID;
	ArkActionFilterStack m_actionFilterStack;
	int m_version;
	bool m_enabled;
	bool m_bRefiringInputs;
	bool m_bDelayedRemoveAllRefiringData;
	bool m_bIncomingInputRepeated;
	bool m_bRepeatedInputHoldTriggerFired;
	
	using TActionMapEventListeners = std::list<IActionMapEventListener *,std::allocator<IActionMapEventListener *> >;
	
	std::list<IActionMapEventListener *,std::allocator<IActionMapEventListener *> > m_actionMapEventListeners;
	unsigned m_defaultEntityId;
	static inline auto s_pThis = PreyGlobal<CActionMapManager *>(0x247FAE0);
	
	CActionMapManager(IInput *pInput);
	virtual bool OnInputEvent(SInputEvent const &event);
	virtual void Update();
	virtual void Reset();
	virtual void ResetBindings();
	virtual void Clear();
	virtual bool InitActionMaps(const char *filename);
	virtual void SetLoadFromXMLPath(const char *szPath);
	virtual const char *GetLoadFromXMLPath() const;
	virtual bool LoadFromXML(XmlNodeRef const &node);
	virtual bool LoadRebindDataFromXML(XmlNodeRef const &node);
	virtual bool SaveRebindDataToXML(XmlNodeRef &node);
	virtual bool AddExtraActionListener(IActionListener *pExtraActionListener, const char *actionMap);
	virtual bool RemoveExtraActionListener(IActionListener *pExtraActionListener, const char *actionMap);
	virtual std::vector<IActionListener *> const &GetExtraActionListeners() const;
	virtual void AddAlwaysActionListener(std::shared_ptr<IBlockingActionListener> pActionListener);
	virtual void RemoveAlwaysActionListener(std::shared_ptr<IBlockingActionListener> pActionListener);
	virtual void RemoveAllAlwaysActionListeners();
	virtual IActionMap *CreateActionMap(const char *name);
	virtual bool RemoveActionMap(const char *name);
	virtual void RemoveAllActionMaps();
	virtual IActionMap *GetActionMap(const char *name);
	virtual IActionMap const *GetActionMap(const char *name) const;
	virtual IActionFilter *CreateActionFilter(const char *name, EActionFilterType type);
	virtual IActionFilter *GetActionFilter(const char *name);
	virtual _smart_ptr<IActionMapIterator> CreateActionMapIterator();
	virtual _smart_ptr<IActionFilterIterator> CreateActionFilterIterator();
	virtual void Enable(const bool enable, const bool resetStateOnDisable);
	virtual void EnableActionMap(const char *name, bool enable);
	virtual void EnableFilter(const char *name, bool enable);
	virtual bool IsFilterEnabled(const char *name);
	virtual void RemoveAllFilters();
	virtual void ReleaseFilteredActions();
	virtual void ClearStoredCurrentInputData();
	virtual bool ReBindActionInput(const char *actionMapName, CCryName const &actionId, const char *szCurrentInput, const char *szNewInput);
	virtual bool ReBindActionInput(const char *actionMapName, CCryName const &actionId, EActionInputDevice deviceType, const int iDeviceIndex, const char *szNewInput);
	virtual SActionInput const *GetActionInput(const char *actionMapName, CCryName const &actionId, EActionInputDevice device, const int iByDeviceIndex) const;
	virtual int GetVersion() const;
	virtual void SetVersion(int version);
	virtual void EnumerateActions(IActionMapPopulateCallBack *pCallBack) const;
	virtual int GetActionsCount() const;
	virtual int GetActionMapsCount() const;
	virtual bool AddInputDeviceMapping(EActionInputDevice deviceType, const char *szDeviceTypeStr);
	virtual bool RemoveInputDeviceMapping(EActionInputDevice deviceType);
	virtual void ClearInputDevicesMappings();
	virtual int GetNumInputDeviceData() const;
	virtual SActionInputDeviceData const *GetInputDeviceDataByIndex(const int iIndex);
	virtual SActionInputDeviceData const *GetInputDeviceDataByType(EActionInputDevice deviceType);
	virtual SActionInputDeviceData const *GetInputDeviceDataByType(const char *szDeviceType);
	virtual void RemoveAllRefireData();
	virtual bool LoadControllerLayoutFile(const char *szLayoutKeyName);
	virtual void SetDefaultActionEntity(unsigned id, bool bUpdateAll);
	virtual unsigned GetDefaultActionEntity() const;
	virtual void RegisterActionMapEventListener(IActionMapEventListener *pActionMapEventListener);
	virtual void UnregisterActionMapEventListener(IActionMapEventListener *pActionMapEventListener);
	void BroadcastActionMapEvent(SActionMapEvent const &event) { FBroadcastActionMapEvent(this,event); }
	virtual bool ActionFiltered(CCryName const &action);
	void ReleaseActionIfActive(CCryName const &actionId) { FReleaseActionIfActive(this,actionId); }
	bool AddBind(CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) { return FAddBind(this,pActionMap,pAction,pActionInput); }
	bool RemoveBind(CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) { return FRemoveBindOv2(this,pActionMap,pAction,pActionInput); }
	void RemoveBind(CActionMap *pActionMap) { FRemoveBindOv1(this,pActionMap); }
	void RemoveBind(CActionMapAction *pAction) { FRemoveBindOv0(this,pAction); }
	bool HasBind(CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) const { return FHasBind(this,pActionMap,pAction,pActionInput); }
	bool UpdateRefireData(SInputEvent const &event, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) { return FUpdateRefireData(this,event,pActionMap,pAction,pActionInput); }
	bool RemoveRefireData(CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput) { return FRemoveRefireDataOv2(this,pActionMap,pAction,pActionInput); }
	bool SetRefireDataDelayedPressNeedsRelease(SInputEvent const &event, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput, const bool bDelayedPressNeedsRelease) { return FSetRefireDataDelayedPressNeedsRelease(this,event,pActionMap,pAction,pActionInput,bDelayedPressNeedsRelease); }
	void RemoveAllDelayedPressRefireData() { FRemoveAllDelayedPressRefireData(this); }
	int GetHighestPressDelayPriority() const { return FGetHighestPressDelayPriority(this); }
	void GetMemoryStatistics(ICrySizer *pSizer) { FGetMemoryStatistics(this,pSizer); }
	virtual IActionFilterStack *GetActionFilterStack();
	virtual ~CActionMapManager();
	bool PreloadControllerLayout(XmlNodeRef const &controllerLayout) { return FPreloadControllerLayout(this,controllerLayout); }
	bool HandleAcceptedEvents(SInputEvent const &event, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList) { return FHandleAcceptedEvents(this,event,priorityList); }
	bool CreateEventPriorityList(SInputEvent const &inputEvent, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList) { return FCreateEventPriorityList(this,inputEvent,priorityList); }
	bool CreateRefiredEventPriorityList(CActionMapManager::SRefireData *pRefireData, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &removeList, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &delayPressNeedsReleaseList) { return FCreateRefiredEventPriorityList(this,pRefireData,priorityList,removeList,delayPressNeedsReleaseList); }
	void UpdateRefiringInputs() { FUpdateRefiringInputs(this); }
	
#if 0
	void Release();
	void RemoveActionFilter(CActionFilter *arg0);
	void RemoveRefireData(CActionMap *arg0);
	void RemoveRefireData(CActionMapAction *arg0);
	static void ReloadActionMaps(IConsoleCmdArgs *arg0);
	bool IsCurrentlyRefiringInput() const;
	bool IsIncomingInputRepeated() const;
	EKeyId GetIncomingInputKeyID() const;
	void SetRepeatedInputHoldTriggerFired(const bool arg0);
	bool IsRepeatedInputHoldTriggerFired() const;
	void HandleInputBlocking(SInputEvent const &arg0, SActionInput const *arg1, const float arg2);
	CActionMapManager::SBindData *GetBindData(CActionMap *arg0, CActionMapAction *arg1, SActionInput *arg2);
	bool ProcessAlwaysListeners(CCryName const &arg0, int arg1, float arg2, SInputEvent const &arg3);
	void SetCurrentlyRefiringInput(bool arg0);
#endif
	
	static inline auto FOnInputEvent = PreyFunction<bool(CActionMapManager *const _this, SInputEvent const &event)>(0x3D0640);
	static inline auto FUpdate = PreyFunction<void(CActionMapManager *const _this)>(0x3D1F70);
	static inline auto FReset = PreyFunction<void(CActionMapManager *const _this)>(0x3D1B40);
	static inline auto FResetBindings = PreyFunction<void(CActionMapManager *const _this)>(0x3D1BD0);
	static inline auto FClear = PreyFunction<void(CActionMapManager *const _this)>(0x3CE370);
	static inline auto FInitActionMaps = PreyFunction<bool(CActionMapManager *const _this, const char *filename)>(0x3CFC50);
	static inline auto FSetLoadFromXMLPath = PreyFunction<void(CActionMapManager *const _this, const char *szPath)>(0x3D1E40);
	static inline auto FGetLoadFromXMLPath = PreyFunction<const char *(CActionMapManager const *const _this)>(0xD87510);
	static inline auto FLoadFromXML = PreyFunction<bool(CActionMapManager *const _this, XmlNodeRef const &node)>(0x3D01B0);
	static inline auto FLoadRebindDataFromXML = PreyFunction<bool(CActionMapManager *const _this, XmlNodeRef const &node)>(0x3D0470);
	static inline auto FSaveRebindDataToXML = PreyFunction<bool(CActionMapManager *const _this, XmlNodeRef &node)>(0x3D1C60);
	static inline auto FAddExtraActionListener = PreyFunction<bool(CActionMapManager *const _this, IActionListener *pExtraActionListener, const char *actionMap)>(0x3CE0C0);
	static inline auto FRemoveExtraActionListener = PreyFunction<bool(CActionMapManager *const _this, IActionListener *pExtraActionListener, const char *actionMap)>(0x3D1860);
	static inline auto FGetExtraActionListeners = PreyFunction<std::vector<IActionListener *> const &(CActionMapManager const *const _this)>(0x1296490);
	static inline auto FAddAlwaysActionListener = PreyFunction<void(CActionMapManager *const _this, std::shared_ptr<IBlockingActionListener> pActionListener)>(0x3CDD70);
	static inline auto FRemoveAlwaysActionListener = PreyFunction<void(CActionMapManager *const _this, std::shared_ptr<IBlockingActionListener> pActionListener)>(0x3D1150);
	static inline auto FRemoveAllAlwaysActionListeners = PreyFunction<void(CActionMapManager *const _this)>(0x3D0E80);
	static inline auto FCreateActionMap = PreyFunction<IActionMap *(CActionMapManager *const _this, const char *name)>(0x3CE5E0);
	static inline auto FRemoveActionMap = PreyFunction<bool(CActionMapManager *const _this, const char *name)>(0x3D0CD0);
	static inline auto FRemoveAllActionMaps = PreyFunction<void(CActionMapManager *const _this)>(0x3D0D90);
	static inline auto FGetActionMapOv1 = PreyFunction<IActionMap *(CActionMapManager *const _this, const char *name)>(0x3CF200);
	static inline auto FGetActionMapOv0 = PreyFunction<IActionMap const *(CActionMapManager const *const _this, const char *name)>(0x3CF270);
	static inline auto FCreateActionFilter = PreyFunction<IActionFilter *(CActionMapManager *const _this, const char *name, EActionFilterType type)>(0x3CE490);
	static inline auto FGetActionFilter = PreyFunction<IActionFilter *(CActionMapManager *const _this, const char *name)>(0x3CF0B0);
	static inline auto FCreateActionMapIterator = PreyFunction<_smart_ptr<IActionMapIterator>(CActionMapManager *const _this)>(0x3CE6D0);
	static inline auto FCreateActionFilterIterator = PreyFunction<_smart_ptr<IActionFilterIterator>(CActionMapManager *const _this)>(0x3CE560);
	static inline auto FEnable = PreyFunction<void(CActionMapManager *const _this, const bool enable, const bool resetStateOnDisable)>(0x3CEC70);
	static inline auto FEnableActionMap = PreyFunction<void(CActionMapManager *const _this, const char *name, bool enable)>(0x3CED30);
	static inline auto FEnableFilter = PreyFunction<void(CActionMapManager *const _this, const char *name, bool enable)>(0x3CEEA0);
	static inline auto FIsFilterEnabled = PreyFunction<bool(CActionMapManager *const _this, const char *name)>(0x3CFF90);
	static inline auto FRemoveAllFilters = PreyFunction<void(CActionMapManager *const _this)>(0x3D0FC0);
	static inline auto FReleaseFilteredActions = PreyFunction<void(CActionMapManager *const _this)>(0x3D0C30);
	static inline auto FClearStoredCurrentInputData = PreyFunction<void(CActionMapManager *const _this)>(0x3CE470);
	static inline auto FReBindActionInputOv1 = PreyFunction<bool(CActionMapManager *const _this, const char *actionMapName, CCryName const &actionId, const char *szCurrentInput, const char *szNewInput)>(0x3D0A10);
	static inline auto FReBindActionInputOv0 = PreyFunction<bool(CActionMapManager *const _this, const char *actionMapName, CCryName const &actionId, EActionInputDevice deviceType, const int iDeviceIndex, const char *szNewInput)>(0x3D0A80);
	static inline auto FGetActionInput = PreyFunction<SActionInput const *(CActionMapManager const *const _this, const char *actionMapName, CCryName const &actionId, EActionInputDevice device, const int iByDeviceIndex)>(0x3CF120);
	static inline auto FGetVersion = PreyFunction<int(CActionMapManager const *const _this)>(0x9D5270);
	static inline auto FSetVersion = PreyFunction<void(CActionMapManager *const _this, int version)>(0x3D1F10);
	static inline auto FEnumerateActions = PreyFunction<void(CActionMapManager const *const _this, IActionMapPopulateCallBack *pCallBack)>(0x3CF010);
	static inline auto FGetActionsCount = PreyFunction<int(CActionMapManager const *const _this)>(0x3CF340);
	static inline auto FGetActionMapsCount = PreyFunction<int(CActionMapManager const *const _this)>(0xE79B70);
	static inline auto FAddInputDeviceMapping = PreyFunction<bool(CActionMapManager *const _this, EActionInputDevice deviceType, const char *szDeviceTypeStr)>(0x3CE190);
	static inline auto FRemoveInputDeviceMapping = PreyFunction<bool(CActionMapManager *const _this, EActionInputDevice deviceType)>(0x3D1930);
	static inline auto FClearInputDevicesMappings = PreyFunction<void(CActionMapManager *const _this)>(0x3CE3D0);
	static inline auto FGetNumInputDeviceData = PreyFunction<int(CActionMapManager const *const _this)>(0x3CF750);
	static inline auto FGetInputDeviceDataByIndex = PreyFunction<SActionInputDeviceData const *(CActionMapManager *const _this, const int iIndex)>(0x3CF4A0);
	static inline auto FGetInputDeviceDataByTypeOv1 = PreyFunction<SActionInputDeviceData const *(CActionMapManager *const _this, EActionInputDevice deviceType)>(0x3CF550);
	static inline auto FGetInputDeviceDataByTypeOv0 = PreyFunction<SActionInputDeviceData const *(CActionMapManager *const _this, const char *szDeviceType)>(0x3CF4F0);
	static inline auto FRemoveAllRefireData = PreyFunction<void(CActionMapManager *const _this)>(0x3D1080);
	static inline auto FLoadControllerLayoutFile = PreyFunction<bool(CActionMapManager *const _this, const char *szLayoutKeyName)>(0x3D0000);
	static inline auto FSetDefaultActionEntity = PreyFunction<void(CActionMapManager *const _this, unsigned id, bool bUpdateAll)>(0x3D1D90);
	static inline auto FGetDefaultActionEntity = PreyFunction<unsigned(CActionMapManager const *const _this)>(0x3CF3E0);
	static inline auto FRegisterActionMapEventListener = PreyFunction<void(CActionMapManager *const _this, IActionMapEventListener *pActionMapEventListener)>(0x3D0AF0);
	static inline auto FUnregisterActionMapEventListener = PreyFunction<void(CActionMapManager *const _this, IActionMapEventListener *pActionMapEventListener)>(0x3D1F20);
	static inline auto FBroadcastActionMapEvent = PreyFunction<void(CActionMapManager *const _this, SActionMapEvent const &event)>(0x3CE2A0);
	static inline auto FActionFiltered = PreyFunction<bool(CActionMapManager *const _this, CCryName const &action)>(0x3CDCC0);
	static inline auto FReleaseActionIfActive = PreyFunction<void(CActionMapManager *const _this, CCryName const &actionId)>(0x3D0B90);
	static inline auto FAddBind = PreyFunction<bool(CActionMapManager *const _this, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3CDEF0);
	static inline auto FRemoveBindOv2 = PreyFunction<bool(CActionMapManager *const _this, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3D1720);
	static inline auto FRemoveBindOv1 = PreyFunction<void(CActionMapManager *const _this, CActionMap *pActionMap)>(0x3D1240);
	static inline auto FRemoveBindOv0 = PreyFunction<void(CActionMapManager *const _this, CActionMapAction *pAction)>(0x3D14B0);
	static inline auto FHasBind = PreyFunction<bool(CActionMapManager const *const _this, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3CFB30);
	static inline auto FUpdateRefireData = PreyFunction<bool(CActionMapManager *const _this, SInputEvent const &event, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3D2040);
	static inline auto FRemoveRefireDataOv2 = PreyFunction<bool(CActionMapManager *const _this, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput)>(0x3D1A10);
	static inline auto FSetRefireDataDelayedPressNeedsRelease = PreyFunction<bool(CActionMapManager *const _this, SInputEvent const &event, CActionMap *pActionMap, CActionMapAction *pAction, SActionInput *pActionInput, const bool bDelayedPressNeedsRelease)>(0x3D1E70);
	static inline auto FRemoveAllDelayedPressRefireData = PreyFunction<void(CActionMapManager *const _this)>(0x3D0E90);
	static inline auto FGetHighestPressDelayPriority = PreyFunction<int(CActionMapManager const *const _this)>(0x3CF3F0);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CActionMapManager *const _this, ICrySizer *pSizer)>(0x3CF580);
	static inline auto FGetActionFilterStack = PreyFunction<IActionFilterStack *(CActionMapManager *const _this)>(0x10BD800);
	static inline auto FBitNotCActionMapManager = PreyFunction<void(CActionMapManager *const _this)>(0x3CD9F0);
	static inline auto FPreloadControllerLayout = PreyFunction<bool(CActionMapManager *const _this, XmlNodeRef const &controllerLayout)>(0x3D0760);
	static inline auto FHandleAcceptedEvents = PreyFunction<bool(CActionMapManager *const _this, SInputEvent const &event, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList)>(0x3CF780);
	static inline auto FCreateEventPriorityList = PreyFunction<bool(CActionMapManager *const _this, SInputEvent const &inputEvent, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList)>(0x3CE750);
	static inline auto FCreateRefiredEventPriorityList = PreyFunction<bool(CActionMapManager *const _this, CActionMapManager::SRefireData *pRefireData, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &priorityList, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &removeList, std::list<CActionMapManager::SBindData const *,std::allocator<CActionMapManager::SBindData const *> > &delayPressNeedsReleaseList)>(0x3CE980);
	static inline auto FUpdateRefiringInputs = PreyFunction<void(CActionMapManager *const _this)>(0x3D2230);
};

