// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>


// ILoadtimeCallback
// Header:  _unknown/ILoadtimeCallback.h
// Include: Prey/CryRenderer/IRenderer.h (forward-declared there as a class)
class ILoadtimeCallback
{ // Size=8 (0x8)
public:
	virtual void LoadtimeUpdate(float fDeltaTime) = 0;
	virtual void LoadtimeRender() = 0;
	virtual ~ILoadtimeCallback() {}
};

// SUIItemLookupSet_Impl<T>
// Header:  _unknown/SUIItemLookupSet_Impl.h
template<class T>
struct SUIItemLookupSet_Impl
{ // Size=24 (0x18)
	using TITems = DynArray<T*, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;
	using TLookup = std::map<CCryName, int>;

	TITems m_Items;
	TLookup m_Lookup;
};

class CAutoRegUIFlowNode;
class CFlashUIEventSystem;

// Header: Exact
// CryEngine/cryaction/flashui/flashui.h
class CFlashUI
	: public IFlashUI
	, public IHardwareMouseEventListener
	, public IInputEventListener
	, public IGameFrameworkListener
	, public ILevelSystemListener
	, public ISystemEventListener
	, public ILoadtimeCallback
{ // Size=480 (0x1E0)
public:
	typedef std::multimap<int, IUIElement*> TSortedElementList;

	enum ESystemState
	{
		eSS_NoLevel = 0,
		eSS_Loading = 1,
		eSS_LoadingDone = 2,
		eSS_GameStarted = 3,
		eSS_Unloading = 4,
	};

	using TUIFlowNodes = std::vector<CAutoRegUIFlowNode*>;
	using TPlayerList = std::vector<IFlashPlayer*>;
	using TTextureMap = std::map<ITexture*, string>;
	using TUIModules = CListenerSet<IUIModule*>;

	CFlashUIActionEvents* m_pFlashUIActionEvents;
	ArkBinkPlayerHandle m_spinnyPlayer;
	std::map<string, CFlashUIEventSystem*> m_eventSystemsUiToSys;
	std::map<string, CFlashUIEventSystem*> m_eventSystemsSysToUi;
	SUIItemLookupSet_Impl<IUIElement> m_elements;
	SUIItemLookupSet_Impl<IUIAction> m_actions;
	JobManager::SJobState m_flashUpdateJobState;
	TSortedElementList m_sortedElements;
	bool m_bSortedElementsInvalidated;
	bool m_bLockSortedElements;
	bool m_bLoadtimeThread;
	std::vector<IFlashPlayer*> m_loadtimePlayerList;
	std::vector<CAutoRegUIFlowNode*> m_UINodes;
	std::map<ITexture*, string> m_preloadedTextures;
	CUIActionManager* m_pUIActionManager;
	CListenerSet<IUIModule*> m_modules;
	int m_iWidth;
	int m_iHeight;
	Functor2<int&, int&> m_ScreenSizeCB;
	Functor1<IFlashUI::SUILogEvent const&> m_LogCallback;
	Functor0wRet<IFlashUI::EPlatformUI> m_plattformCallback;
	bool m_bWorldUIInteraction;
	int m_steamMenuActionSetRefCount;
	CFlashUI::ESystemState m_systemState;
	float m_fLastAdvance;
	float m_lastTimeTriggered;
	unsigned m_worldUICursorDisabledCount;
	bool m_bHudVisible;
	bool m_bReturningToFrontEnd;
	bool m_bMovieRequestedByLoadSave;
	string m_lastPressedElementName;
	int m_lastPressedElementID;

	virtual ICryFactory* GetFactory() const;
	virtual void* QueryInterface(const CryGUID& iid) const;
	virtual void* QueryComposite(const char* name) const;
	CFlashUI();
	virtual ~CFlashUI();
	virtual void Init();
	virtual bool PostInit();
	void PreUpdate() { FPreUpdate(this); }
	virtual void Update(float fDeltaTimeUI, float fDeltaTimeGame);
	void Render(bool _bAnyFullscreenBinkPlaying) { FRender(this, _bAnyFullscreenBinkPlaying); }
	void UpdateElements(float fDeltaTimeUI, float fDeltaTimeGame) { FUpdateElements(this, fDeltaTimeUI, fDeltaTimeGame); }
	virtual void Reload(bool _bFullUnload);
	virtual void Shutdown();
	virtual bool LoadElementsFromFile(const char* sFileName);
	virtual bool LoadActionFromFile(const char* sFileName, IUIAction::EUIActionType type);
	virtual IUIElement* GetUIElement(const char* sName) const;
	virtual IUIElement* GetUIElement(int index) const;
	virtual int GetUIElementCount() const;
	virtual IUIElement* GetUIElementByInstanceStr(const char* sUIInstanceStr) const;
	virtual IUIAction* GetUIAction(const char* sName) const;
	virtual IUIAction* GetUIAction(int index) const;
	virtual int GetUIActionCount() const;
	virtual IUIActionManager* GetUIActionManager() const;
	virtual void UpdateFG();
	virtual void EnableEventStack(bool bEnable);
	virtual void RegisterModule(IUIModule* pModule, const char* name);
	virtual void UnregisterModule(IUIModule* pModule);
	virtual void SetHudElementsVisible(bool bVisible);
	virtual IUIEventSystem* CreateEventSystem(const char* sName, IUIEventSystem::EEventSystemType eType);
	virtual IUIEventSystem* GetEventSystem(const char* name, IUIEventSystem::EEventSystemType eType);
	virtual _smart_ptr<IUIEventSystemIterator> CreateEventSystemIterator(IUIEventSystem::EEventSystemType eType);
	virtual void DispatchControllerEvent(IUIElement::EControllerInputEvent event, IUIElement::EControllerInputState state, float value);
	virtual void SendFlashMouseEvent(SFlashCursorEvent::ECursorState evt, int iX, int iY, int iButton, float fWheel, bool bFromController);
	virtual bool DisplayVirtualKeyboard(unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback);
	virtual bool IsVirtualKeyboardRunning();
	virtual bool CancelVirtualKeyboard();
	virtual void GetScreenSize(int& width, int& height);
	virtual void SetEditorScreenSizeCallback(Functor2<int&, int&>& cb);
	virtual void RemoveEditorScreenSizeCallback();
	virtual void SetEditorUILogEventCallback(Functor1<IFlashUI::SUILogEvent const&>& cb);
	virtual void RemoveEditorUILogEventCallback();
	virtual void SetEditorPlatformCallback(Functor0wRet<IFlashUI::EPlatformUI>& cb);
	virtual void RemoveEditorPlatformCallback();
	virtual bool UseSharedRT(const char* instanceStr, bool defVal) const;
	virtual void CheckPreloadedTexture(ITexture* pTexture) const;
	virtual void GetMemoryStatistics(ICrySizer* s) const;
	virtual bool IsWorldUIInteraction() const;
	virtual void SetWorldUICursorDisabled(bool _bDisabled);
	virtual std::pair<bool, bool> IsWorldUIEntity(const IEntity* const _pEntity) const;
	virtual void OnHardwareMouseEvent(int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta);
	virtual bool OnInputEvent(const SInputEvent& event);
	virtual bool OnInputEventUI(const SInputEvent& event);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* nextLevel);
	virtual void OnActionEvent(const SActionEvent& event);
	virtual void OnLevelNotFound(const char* levelName);
	virtual void OnLoadingStart(ILevelInfo* pLevel);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevel);
	virtual void OnLoadingComplete(ILevel* pLevel);
	virtual void OnLoadingError(ILevelInfo* pLevel, const char* error);
	virtual void OnLoadingProgress(ILevelInfo* pLevel, int progressAmount);
	virtual void OnUnloadComplete(ILevel* pLevel);
	virtual void LoadtimeUpdate(float fDeltaTime);
	virtual void LoadtimeRender();
	void UpdateSteamMenuState(bool _bEnable) { FUpdateSteamMenuState(this, _bEnable); }
	static void ReloadAllElements(IConsoleCmdArgs* __unnamed1) { FReloadAllElements(__unnamed1); }
	void InvalidateSortedElements() { FInvalidateSortedElements(this); }
	void LoadElements() { FLoadElements(this); }
	void LoadActions() { FLoadActions(this); }
	void ResetActions() { FResetActions(this); }
	void CreateNodes() { FCreateNodes(this); }
	void ClearNodes() { FClearNodes(this); }
	void LoadFromFile(const char* pFolderName, const char* pSearch, bool (*fhFileLoader)(const char*)) { FLoadFromFile(this, pFolderName, pSearch, fhFileLoader); }
	bool LoadFGActionFromFile(const char* sFileName) { return FLoadFGActionFromFile(this, sFileName); }
	bool LoadLuaActionFromFile(const char* sFileName) { return FLoadLuaActionFromFile(this, sFileName); }
	void PreloadTextures(const char* pLevelName) { FPreloadTextures(this, pLevelName); }
	void PreloadTexturesFromNode(const XmlNodeRef& node) { FPreloadTexturesFromNode(this, node); }
	bool PreloadTexture(const char* pFileName) { return FPreloadTexture(this, pFileName); }
	void ReleasePreloadedTextures(bool bReleaseTextures) { FReleasePreloadedTextures(this, bReleaseTextures); }
	const TSortedElementList& GetSortedElements() { return FGetSortedElements(this); }
	void UpdateSortedElements() { FUpdateSortedElements(this); }
	void StartRenderThread() { FStartRenderThread(this); }
	void StopRenderThread() { FStopRenderThread(this); }
	void CheckResolutionChange() { FCheckResolutionChange(this); }
	void ReloadAllBootStrapper(bool _bUnloadBootStrapper) { FReloadAllBootStrapper(this, _bUnloadBootStrapper); }
	void ShowLoadingScreen() { FShowLoadingScreen(this); }
	void HideLoadingScreen() { FHideLoadingScreen(this); }
	static bool CheckFilter(const string& str) { return FCheckFilter(str); }

	static constexpr size_t OFFSET_m_bHudVisible = 0x01C8;

#ifndef MOONCRASH
	static inline auto s_factory = PreyGlobal<CSingletonFactory<CFlashUI>>(0x2242FE0);
	static inline auto CV_gfx_draw = PreyGlobal<int>(0x2473B28);
	static inline auto CV_gfx_debugdraw = PreyGlobal<int>(0x2473B2C);
	static inline auto CV_gfx_uiaction_log = PreyGlobal<int>(0x2473B30);
	static inline auto CV_gfx_uiaction_enable = PreyGlobal<int>(0x2473B34);
	static inline auto CV_gfx_loadtimethread = PreyGlobal<int>(0x2473B38);
	static inline auto CV_gfx_reloadonlanguagechange = PreyGlobal<int>(0x2473B3C);
	static inline auto CV_gfx_uievents_editorenabled = PreyGlobal<int>(0x2473B40);
	static inline auto CV_gfx_ampserver = PreyGlobal<int>(0x2473B44);
	static inline auto CV_gfx_multithreaded = PreyGlobal<int>(0x2473B48);
	static inline auto CV_gfx_inputevents_triggerstart = PreyGlobal<float>(0x2473B4C);
	static inline auto CV_gfx_inputevents_triggerrepeat = PreyGlobal<float>(0x2473B50);
	static inline auto CV_gfx_uiaction_log_filter = PreyGlobal<ICVar*>(0x2473B58);
	static inline auto CV_gfx_uiaction_folder = PreyGlobal<ICVar*>(0x2473B60);

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CFlashUI* const _this)>(0x2CD760);
	static inline auto FQueryInterface = PreyFunction<void* (const CFlashUI* const _this, const CryGUID& iid)>(0x2CD770);
	static inline auto FQueryComposite = PreyFunction<void* (const CFlashUI* const _this, const char* name)>(0x158AEF0);
	static inline auto FCFlashUIOv1 = PreyFunction<void(CFlashUI* const _this)>(0x2D4250);
	static inline auto FBitNotCFlashUI = PreyFunction<void(CFlashUI* const _this)>(0x2D4990);
	static inline auto FInit = PreyFunction<void(CFlashUI* const _this)>(0x2CD7D0);
	static inline auto FPostInit = PreyFunction<bool(CFlashUI* const _this)>(0x2CD810);
	static inline auto FPreUpdate = PreyFunction<void(CFlashUI* const _this)>(0x2D73C0);
	static inline auto FUpdate = PreyFunction<void(CFlashUI* const _this, float fDeltaTimeUI, float fDeltaTimeGame)>(0x2CDA70);
	static inline auto FRender = PreyFunction<void(CFlashUI* const _this, bool _bAnyFullscreenBinkPlaying)>(0x2D8A80);
	static inline auto FUpdateElements = PreyFunction<void(CFlashUI* const _this, float fDeltaTimeUI, float fDeltaTimeGame)>(0x2D90D0);
	static inline auto FReload = PreyFunction<void(CFlashUI* const _this, bool _bFullUnload)>(0x2CDD50);
	static inline auto FShutdown = PreyFunction<void(CFlashUI* const _this)>(0x2CDEC0);
	static inline auto FLoadElementsFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2CE3B0);
	static inline auto FLoadActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName, IUIAction::EUIActionType type)>(0x2CE740);
	static inline auto FGetUIElementOv1 = PreyFunction<IUIElement* (const CFlashUI* const _this, const char* sName)>(0x2CE760);
	static inline auto FGetUIElementOv0 = PreyFunction<IUIElement* (const CFlashUI* const _this, int index)>(0x2CE820);
	static inline auto FGetUIElementCount = PreyFunction<int(const CFlashUI* const _this)>(0x2CE840);
	static inline auto FGetUIElementByInstanceStr = PreyFunction<IUIElement* (const CFlashUI* const _this, const char* sUIInstanceStr)>(0x2CE850);
	static inline auto FGetUIActionOv1 = PreyFunction<IUIAction* (const CFlashUI* const _this, const char* sName)>(0x2CE9F0);
	static inline auto FGetUIActionOv0 = PreyFunction<IUIAction* (const CFlashUI* const _this, int index)>(0x2CEAC0);
	static inline auto FGetUIActionCount = PreyFunction<int(const CFlashUI* const _this)>(0x2CEAE0);
	static inline auto FGetUIActionManager = PreyFunction<IUIActionManager* (const CFlashUI* const _this)>(0x155AD20);
	static inline auto FUpdateFG = PreyFunction<void(CFlashUI* const _this)>(0x2CEAF0);
	static inline auto FEnableEventStack = PreyFunction<void(CFlashUI* const _this, bool bEnable)>(0xA13080);
	static inline auto FRegisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule, const char* name)>(0x2CEBB0);
	static inline auto FUnregisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule)>(0x2CEC00);
	static inline auto FSetHudElementsVisible = PreyFunction<void(CFlashUI* const _this, bool bVisible)>(0x2CEC80);
	static inline auto FCreateEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* sName, IUIEventSystem::EEventSystemType eType)>(0x2CECF0);
	static inline auto FGetEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* name, IUIEventSystem::EEventSystemType eType)>(0x2CEE00);
	static inline auto FCreateEventSystemIterator = PreyFunction<_smart_ptr<IUIEventSystemIterator>*(CFlashUI* const _this, _smart_ptr<IUIEventSystemIterator>* _return_value_, IUIEventSystem::EEventSystemType eType)>(0x2CEF40);
	static inline auto FDispatchControllerEvent = PreyFunction<void(CFlashUI* const _this, IUIElement::EControllerInputEvent event, IUIElement::EControllerInputState state, float value)>(0x2CEFD0);
	static inline auto FSendFlashMouseEvent = PreyFunction<void(CFlashUI* const _this, SFlashCursorEvent::ECursorState evt, int iX, int iY, int iButton, float fWheel, bool bFromController)>(0x2CF280);
	static inline auto FDisplayVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback)>(0x2CF7E0);
	static inline auto FIsVirtualKeyboardRunning = PreyFunction<bool(CFlashUI* const _this)>(0x2CF890);
	static inline auto FCancelVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this)>(0x2CF8C0);
	static inline auto FGetScreenSize = PreyFunction<void(CFlashUI* const _this, int& width, int& height)>(0x2CF8F0);
	static inline auto FSetEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this, Functor2<int &,int &>& cb)>(0x2CF940);
	static inline auto FRemoveEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CF960);
	static inline auto FSetEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this, Functor1<int const&>& cb /* IFlashUI::SUILogEvent const& (IFlashUI not in tree) */)>(0x2CF990);
	static inline auto FRemoveEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CF9B0);
	static inline auto FSetEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this, Functor0wRet<int>& cb /* IFlashUI::EPlatformUI (IFlashUI not in tree) */)>(0x2CF9E0);
	static inline auto FRemoveEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CFA00);
	static inline auto FUseSharedRT = PreyFunction<bool(const CFlashUI* const _this, const char* instanceStr, bool defVal)>(0x2CFA30);
	static inline auto FCheckPreloadedTexture = PreyFunction<void(const CFlashUI* const _this, ITexture* pTexture)>(0x2CFA70);
	static inline auto FGetMemoryStatistics = PreyFunction<void(const CFlashUI* const _this, ICrySizer* s)>(0x2CFB00);
	static inline auto FIsWorldUIInteraction = PreyFunction<bool(const CFlashUI* const _this)>(0x2CFEC0);
	static inline auto FSetWorldUICursorDisabled = PreyFunction<void(CFlashUI* const _this, bool _bDisabled)>(0x2CFED0);
	static inline auto FIsWorldUIEntity = PreyFunction<std::pair<bool, bool>*(const CFlashUI* const _this, std::pair<bool, bool>* _return_value_, const IEntity* const _pEntity)>(0x2CFEF0);
	static inline auto FOnHardwareMouseEvent = PreyFunction<void(IHardwareMouseEventListener* const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)>(0x2D0010);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x2D0100);
	static inline auto FOnInputEventUI = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x2D0670);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x2D08C0);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0x2D0EF0);
	static inline auto FOnLevelNotFound = PreyFunction<void(ILevelSystemListener* const _this, const char* levelName)>(0x2D0F60);
	static inline auto FOnLoadingStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0xA13080);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0xA13080);
	static inline auto FOnLoadingComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0xA13080);
	static inline auto FOnLoadingError = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, const char* error)>(0x2D1000);
	static inline auto FOnLoadingProgress = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, int progressAmount)>(0x2D1070);
	static inline auto FOnUnloadComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0xA13080);
	static inline auto FLoadtimeUpdate = PreyFunction<void(ILoadtimeCallback* const _this, float fDeltaTime)>(0x2D1180);
	static inline auto FLoadtimeRender = PreyFunction<void(ILoadtimeCallback* const _this)>(0x2D1210);
	static inline auto FUpdateSteamMenuState = PreyFunction<void(CFlashUI* const _this, bool _bEnable)>(0x2D9340);
	// varargs: static inline auto FLogUIAction = PreyFunction<void(IFlashUI::ELogEventLevel level, const char* format, ...)>(0x2D7250);
	static inline auto FReloadAllElements = PreyFunction<void(IConsoleCmdArgs* __unnamed1)>(0x2D8A60);
	static inline auto FInvalidateSortedElements = PreyFunction<void(CFlashUI* const _this)>(0x2D6360);
	static inline auto FLoadElements = PreyFunction<void(CFlashUI* const _this)>(0x2D69A0);
	static inline auto FLoadActions = PreyFunction<void(CFlashUI* const _this)>(0x2D6890);
	static inline auto FResetActions = PreyFunction<void(CFlashUI* const _this)>(0x2D8C50);
	static inline auto FCreateNodes = PreyFunction<void(CFlashUI* const _this)>(0x2D5A50);
	static inline auto FClearNodes = PreyFunction<void(CFlashUI* const _this)>(0x2D5920);
	static inline auto FLoadFromFile = PreyFunction<void(CFlashUI* const _this, const char* pFolderName, const char* pSearch, bool (*fhFileLoader)(const char*))>(0x2D6DB0);
	static inline auto FLoadFGActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2D6AD0);
	static inline auto FLoadLuaActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2D7000);
	static inline auto FPreloadTextures = PreyFunction<void(CFlashUI* const _this, const char* pLevelName)>(0x2D7CA0);
	static inline auto FPreloadTexturesFromNode = PreyFunction<void(CFlashUI* const _this, const XmlNodeRef& node)>(0x2D8130);
	static inline auto FPreloadTexture = PreyFunction<bool(CFlashUI* const _this, const char* pFileName)>(0x2D7490);
	static inline auto FReleasePreloadedTextures = PreyFunction<void(CFlashUI* const _this, bool bReleaseTextures)>(0x2D8490);
	static inline auto FGetSortedElements = PreyFunction<const std::multimap<int,IUIElement *,std::less<int>,std::allocator<std::pair<int const ,IUIElement *> > >& (CFlashUI* const _this)>(0x2D62C0);
	static inline auto FUpdateSortedElements = PreyFunction<void(CFlashUI* const _this)>(0x2D9230);
	static inline auto FStartRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2D8D50);
	static inline auto FStopRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2D8FE0);
	static inline auto FCheckResolutionChange = PreyFunction<void(CFlashUI* const _this)>(0x2D5530);
	static inline auto FReloadAllBootStrapper = PreyFunction<void(CFlashUI* const _this, bool _bUnloadBootStrapper)>(0x2D8570);
	static inline auto FShowLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2D8D00);
	static inline auto FHideLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2D6300);
	static inline auto FCheckFilter = PreyFunction<bool(const string& str)>(0x2D4D70);
#else
	static inline auto s_factory = PreyGlobal<CSingletonFactory<CFlashUI>>(0x23B0010);
	static inline auto CV_gfx_draw = PreyGlobal<int>(0x25E3138);
	static inline auto CV_gfx_debugdraw = PreyGlobal<int>(0x25E313C);
	static inline auto CV_gfx_uiaction_log = PreyGlobal<int>(0x25E3140);
	static inline auto CV_gfx_uiaction_enable = PreyGlobal<int>(0x25E3144);
	static inline auto CV_gfx_loadtimethread = PreyGlobal<int>(0x25E3148);
	static inline auto CV_gfx_reloadonlanguagechange = PreyGlobal<int>(0x25E314C);
	static inline auto CV_gfx_uievents_editorenabled = PreyGlobal<int>(0x25E3150);
	static inline auto CV_gfx_ampserver = PreyGlobal<int>(0x25E3154);
	static inline auto CV_gfx_multithreaded = PreyGlobal<int>(0x25E3158);
	static inline auto CV_gfx_inputevents_triggerstart = PreyGlobal<float>(0x25E315C);
	static inline auto CV_gfx_inputevents_triggerrepeat = PreyGlobal<float>(0x25E3160);
	static inline auto CV_gfx_uiaction_log_filter = PreyGlobal<ICVar*>(0x25E3168);
	static inline auto CV_gfx_uiaction_folder = PreyGlobal<ICVar*>(0x25E3170);

	static inline auto FGetFactory = PreyFunction<ICryFactory* (const CFlashUI* const _this)>(0x2E8020);
	static inline auto FQueryInterface = PreyFunction<void* (const CFlashUI* const _this, const CryGUID& iid)>(0x2E8030);
	static inline auto FQueryComposite = PreyFunction<void* (const CFlashUI* const _this, const char* name)>(0x1CBB0B0);
	static inline auto FCFlashUIOv1 = PreyFunction<void(CFlashUI* const _this)>(0x2EE8E0);
	static inline auto FBitNotCFlashUI = PreyFunction<void(CFlashUI* const _this)>(0x2EF010);
	static inline auto FInit = PreyFunction<void(CFlashUI* const _this)>(0x2E8090);
	static inline auto FPostInit = PreyFunction<bool(CFlashUI* const _this)>(0x2E80D0);
	static inline auto FPreUpdate = PreyFunction<void(CFlashUI* const _this)>(0x2F1A60);
	static inline auto FUpdate = PreyFunction<void(CFlashUI* const _this, float fDeltaTimeUI, float fDeltaTimeGame)>(0x2E8330);
	static inline auto FRender = PreyFunction<void(CFlashUI* const _this, bool _bAnyFullscreenBinkPlaying)>(0x2F3120);
	static inline auto FUpdateElements = PreyFunction<void(CFlashUI* const _this, float fDeltaTimeUI, float fDeltaTimeGame)>(0x2F3770);
	static inline auto FReload = PreyFunction<void(CFlashUI* const _this, bool _bFullUnload)>(0x2E8610);
	static inline auto FShutdown = PreyFunction<void(CFlashUI* const _this)>(0x2E8780);
	static inline auto FLoadElementsFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2E8C70);
	static inline auto FLoadActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName, IUIAction::EUIActionType type)>(0x2E9000);
	static inline auto FGetUIElementOv1 = PreyFunction<IUIElement* (const CFlashUI* const _this, const char* sName)>(0x2E9020);
	static inline auto FGetUIElementOv0 = PreyFunction<IUIElement* (const CFlashUI* const _this, int index)>(0x2E90E0);
	static inline auto FGetUIElementCount = PreyFunction<int(const CFlashUI* const _this)>(0x2E9100);
	static inline auto FGetUIElementByInstanceStr = PreyFunction<IUIElement* (const CFlashUI* const _this, const char* sUIInstanceStr)>(0x2E9110);
	static inline auto FGetUIActionOv1 = PreyFunction<IUIAction* (const CFlashUI* const _this, const char* sName)>(0x2E92B0);
	static inline auto FGetUIActionOv0 = PreyFunction<IUIAction* (const CFlashUI* const _this, int index)>(0x2E9380);
	static inline auto FGetUIActionCount = PreyFunction<int(const CFlashUI* const _this)>(0x2E93A0);
	static inline auto FGetUIActionManager = PreyFunction<IUIActionManager* (const CFlashUI* const _this)>(0x11E6CA0);
	static inline auto FUpdateFG = PreyFunction<void(CFlashUI* const _this)>(0x2E93B0);
	static inline auto FEnableEventStack = PreyFunction<void(CFlashUI* const _this, bool bEnable)>(0x1333E90);
	static inline auto FRegisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule, const char* name)>(0x2E9470);
	static inline auto FUnregisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule)>(0x2E94C0);
	static inline auto FSetHudElementsVisible = PreyFunction<void(CFlashUI* const _this, bool bVisible)>(0x2E9540);
	static inline auto FCreateEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* sName, IUIEventSystem::EEventSystemType eType)>(0x2E95B0);
	static inline auto FGetEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* name, IUIEventSystem::EEventSystemType eType)>(0x2E96C0);
	static inline auto FCreateEventSystemIterator = PreyFunction<_smart_ptr<IUIEventSystemIterator>*(CFlashUI* const _this, _smart_ptr<IUIEventSystemIterator>* _return_value_, IUIEventSystem::EEventSystemType eType)>(0x2E9800);
	static inline auto FDispatchControllerEvent = PreyFunction<void(CFlashUI* const _this, IUIElement::EControllerInputEvent event, IUIElement::EControllerInputState state, float value)>(0x2E9860);
	static inline auto FSendFlashMouseEvent = PreyFunction<void(CFlashUI* const _this, SFlashCursorEvent::ECursorState evt, int iX, int iY, int iButton, float fWheel, bool bFromController)>(0x2E9B10);
	static inline auto FDisplayVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback)>(0x2EA080);
	static inline auto FIsVirtualKeyboardRunning = PreyFunction<bool(CFlashUI* const _this)>(0x2EA130);
	static inline auto FCancelVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this)>(0x2EA180);
	static inline auto FGetScreenSize = PreyFunction<void(CFlashUI* const _this, int& width, int& height)>(0x2EA1B0);
	static inline auto FSetEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this, Functor2<int &,int &>& cb)>(0x2EA200);
	static inline auto FRemoveEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this)>(0x2EA220);
	static inline auto FSetEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this, Functor1<int const&>& cb /* IFlashUI::SUILogEvent const& (IFlashUI not in tree) */)>(0x2EA250);
	static inline auto FRemoveEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this)>(0x2EA270);
	static inline auto FSetEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this, Functor0wRet<int>& cb /* IFlashUI::EPlatformUI (IFlashUI not in tree) */)>(0x2EA2A0);
	static inline auto FRemoveEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this)>(0x2EA2C0);
	static inline auto FUseSharedRT = PreyFunction<bool(const CFlashUI* const _this, const char* instanceStr, bool defVal)>(0x2EA2F0);
	static inline auto FCheckPreloadedTexture = PreyFunction<void(const CFlashUI* const _this, ITexture* pTexture)>(0x2EA330);
	static inline auto FGetMemoryStatistics = PreyFunction<void(const CFlashUI* const _this, ICrySizer* s)>(0x2EA3C0);
	static inline auto FIsWorldUIInteraction = PreyFunction<bool(const CFlashUI* const _this)>(0x2EA780);
	static inline auto FSetWorldUICursorDisabled = PreyFunction<void(CFlashUI* const _this, bool _bDisabled)>(0x2EA790);
	static inline auto FIsWorldUIEntity = PreyFunction<std::pair<bool, bool>*(const CFlashUI* const _this, std::pair<bool, bool>* _return_value_, const IEntity* const _pEntity)>(0x2EA7B0);
	static inline auto FOnHardwareMouseEvent = PreyFunction<void(IHardwareMouseEventListener* const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)>(0x2EA8D0);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x2EA9C0);
	static inline auto FOnInputEventUI = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x2EAF30);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x2EB180);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0x1333E90);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0x1333E90);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0x1333E90);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0x1333E90);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0x2EB7F0);
	static inline auto FOnLevelNotFound = PreyFunction<void(ILevelSystemListener* const _this, const char* levelName)>(0x2EB860);
	static inline auto FOnLoadingStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0x1333E90);
	static inline auto FOnLoadingError = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, const char* error)>(0x2EB900);
	static inline auto FOnLoadingProgress = PreyFunction<void(ILevelSystemListener* const _this, ILevelInfo* pLevel, int progressAmount)>(0x2EB970);
	static inline auto FOnUnloadComplete = PreyFunction<void(ILevelSystemListener* const _this, ILevel* pLevel)>(0x1333E90);
	static inline auto FLoadtimeUpdate = PreyFunction<void(ILoadtimeCallback* const _this, float fDeltaTime)>(0x2EBA80);
	static inline auto FLoadtimeRender = PreyFunction<void(ILoadtimeCallback* const _this)>(0x2EBB10);
	static inline auto FUpdateSteamMenuState = PreyFunction<void(CFlashUI* const _this, bool _bEnable)>(0x2F39F0);
	// varargs: static inline auto FLogUIAction = PreyFunction<void(IFlashUI::ELogEventLevel level, const char* format, ...)>(0x2F18F0);
	static inline auto FReloadAllElements = PreyFunction<void(IConsoleCmdArgs* __unnamed1)>(0x2F3100);
	static inline auto FInvalidateSortedElements = PreyFunction<void(CFlashUI* const _this)>(0x2F09F0);
	static inline auto FLoadElements = PreyFunction<void(CFlashUI* const _this)>(0x2F1030);
	static inline auto FLoadActions = PreyFunction<void(CFlashUI* const _this)>(0x2F0F20);
	static inline auto FResetActions = PreyFunction<void(CFlashUI* const _this)>(0x2F32F0);
	static inline auto FCreateNodes = PreyFunction<void(CFlashUI* const _this)>(0x2F00E0);
	static inline auto FClearNodes = PreyFunction<void(CFlashUI* const _this)>(0x2EFFB0);
	static inline auto FLoadFromFile = PreyFunction<void(CFlashUI* const _this, const char* pFolderName, const char* pSearch, bool (*fhFileLoader)(const char*))>(0x2F1450);
	static inline auto FLoadFGActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2F1160);
	static inline auto FLoadLuaActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName)>(0x2F16A0);
	static inline auto FPreloadTextures = PreyFunction<void(CFlashUI* const _this, const char* pLevelName)>(0x2F2340);
	static inline auto FPreloadTexturesFromNode = PreyFunction<void(CFlashUI* const _this, const XmlNodeRef& node)>(0x2F27D0);
	static inline auto FPreloadTexture = PreyFunction<bool(CFlashUI* const _this, const char* pFileName)>(0x2F1B30);
	static inline auto FReleasePreloadedTextures = PreyFunction<void(CFlashUI* const _this, bool bReleaseTextures)>(0x2F2B30);
	static inline auto FGetSortedElements = PreyFunction<const std::multimap<int,IUIElement *,std::less<int>,std::allocator<std::pair<int const ,IUIElement *> > >& (CFlashUI* const _this)>(0x2F0950);
	static inline auto FUpdateSortedElements = PreyFunction<void(CFlashUI* const _this)>(0x2F38D0);
	static inline auto FStartRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2F33F0);
	static inline auto FStopRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2F3680);
	static inline auto FCheckResolutionChange = PreyFunction<void(CFlashUI* const _this)>(0x2EFBC0);
	static inline auto FReloadAllBootStrapper = PreyFunction<void(CFlashUI* const _this, bool _bUnloadBootStrapper)>(0x2F2C10);
	static inline auto FShowLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2F33A0);
	static inline auto FHideLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2F0990);
	static inline auto FCheckFilter = PreyFunction<bool(const string& str)>(0x2EF400);
#endif
};
