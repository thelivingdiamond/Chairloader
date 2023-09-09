// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/FlashUI/FlashUI.h>
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>

class CFlashUIActionEvents;
struct CUIActionManager;
struct CryGUID;
struct ICVar;
struct IConsoleCmdArgs;
struct ICryFactory;
class ICrySizer;
struct IEntity;
struct ILevel;
struct ILevelInfo;
struct ILoadGame;
struct ISaveGame;
class ITexture;
struct IUIActionManager;
struct IUIModule;
struct IVirtualKeyboardEvents;
struct SActionEvent;
struct SFlashKeyEvent;
struct SInputEvent;
class XmlNodeRef;
struct IUIElement;
struct IUIAction;
struct IUIEventSystem;
class CCryName;
struct IDynTextureSource;
struct IEntity;
struct IFlashPlayer;
struct IFlashVariableObject;
class ITexture;
struct IUIElementEventListener;
struct SFlashCharEvent;
struct SFlashCursorEvent;
struct SFlashKeyEvent;
struct SUIArguments;
struct SUIEventDesc;
struct SUIMovieClipDesc;
struct SUIParameterDesc;
class TUIData;
class XmlNodeRef;
struct IUIElementIterator;
struct IUIEventSystemIterator;

// Header: MadeUp
// _unknown/IUIElement.h
struct IUIElement // Id=800224E Size=8
{
	struct SUIConstraints // Id=800224F Size=32
	{
		enum EPositionType
		{
			ePT_Fixed = 0,
			ePT_Fullscreen = 1,
			ePT_Dynamic = 2,
			ePT_FixedDynTexSize = 3,
		};

		enum EPositionAlign
		{
			ePA_Lower = 0,
			ePA_Mid = 1,
			ePA_Upper = 2,
		};

		IUIElement::SUIConstraints::EPositionType eType;
		int iLeft;
		int iTop;
		int iWidth;
		int iHeight;
		IUIElement::SUIConstraints::EPositionAlign eHAlign;
		IUIElement::SUIConstraints::EPositionAlign eVAlign;
		bool bScale;
		bool bMax;
	};

	enum EFlashUIFlags
	{
		eFUI_MASK_PER_INSTANCE = 65535,
		eFUI_NOT_CHANGEABLE = 4096,
		eFUI_HARDWARECURSOR = 1,
		eFUI_MOUSEEVENTS = 2,
		eFUI_KEYEVENTS = 4,
		eFUI_CONSOLE_MOUSE = 8,
		eFUI_CONSOLE_CURSOR = 16,
		eFUI_CONTROLLER_INPUT = 32,
		eFUI_EVENTS_EXCLUSIVE = 64,
		eFUI_RENDER_LOCKLESS = 128,
		eFUI_IS_HUD = 512,
		eFUI_SHARED_RT = 1024,
		eFUI_LAZY_UPDATE = 6144,
		eFUI_NO_AUTO_UPDATE = 8192,
		eFUI_NO_WIREFRAME = 16384,
		eFUI_RENDER_OVER_BINKS = 32768,
		eFUI_MASK_PER_ELEMENT = 983040,
		eFUI_FORCE_NO_UNLOAD = 65536,
		eFUI_USE_STEAM_MENU = 135168,
	};

	enum EControllerInputEvent
	{
		eCIE_Up = 0,
		eCIE_Down = 1,
		eCIE_Left = 2,
		eCIE_Right = 3,
		eCIE_Action = 4,
		eCIE_Back = 5,
		eCIE_Start = 6,
		eCIE_Select = 7,
		eCIE_ShoulderL1 = 8,
		eCIE_ShoulderL2 = 9,
		eCIE_ShoulderR1 = 10,
		eCIE_ShoulderR2 = 11,
		eCIE_Button3 = 12,
		eCIE_Button4 = 13,
		eCIE_DpadUp = 14,
		eCIE_DpadDown = 15,
		eCIE_DpadLeft = 16,
		eCIE_DpadRight = 17,
	};

	enum EControllerInputState
	{
		eCIS_OnPress = 0,
		eCIS_OnRelease = 1,
	};

	virtual ~IUIElement();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual unsigned GetInstanceID() const = 0;
	virtual IUIElement* GetInstance(unsigned arg0) = 0;
	virtual _smart_ptr<IUIElementIterator> GetInstances() const = 0;
	virtual bool DestroyInstance(unsigned arg0) = 0;
	virtual bool DestroyThis() = 0;
	virtual void SetName(const char* arg0) = 0;
	virtual const char* GetName() const = 0;
	virtual void SetGroupName(const char* arg0) = 0;
	virtual const char* GetGroupName() const = 0;
	virtual void SetFlashFile(const char* arg0) = 0;
	virtual const char* GetFlashFile() const = 0;
	virtual bool Init(bool arg0) = 0;
	virtual void Unload(bool arg0) = 0;
	virtual void Reload(bool arg0) = 0;
	virtual bool IsInit() const = 0;
	virtual void RequestUnload(bool arg0) = 0;
	virtual bool IsValid() const = 0;
	virtual void UnloadBootStrapper() = 0;
	virtual void ReloadBootStrapper() = 0;
	virtual void PreUpdate() = 0;
	virtual void Update(float arg0) = 0;
	virtual void Render() = 0;
	virtual void RenderLockless() = 0;
	virtual void RequestHide() = 0;
	virtual bool IsHiding() const = 0;
	virtual void SetVisible(bool arg0) = 0;
	virtual bool IsVisible() const = 0;
	virtual void SetFlag(IUIElement::EFlashUIFlags arg0, bool arg1) = 0;
	virtual bool HasFlag(IUIElement::EFlashUIFlags arg0) const = 0;
	virtual float GetAlpha() const = 0;
	virtual void SetAlpha(float arg0) = 0;
	virtual int GetLayer() const = 0;
	virtual void SetLayer(int arg0) = 0;
	virtual void SetConstraints(IUIElement::SUIConstraints const& arg0) = 0;
	virtual IUIElement::SUIConstraints const& GetConstraints() const = 0;
	virtual void ForceLazyUpdate() = 0;
	virtual void LazyRendered() = 0;
	virtual bool NeedLazyRender() const = 0;
	virtual IFlashPlayer* GetFlashPlayer() = 0;
	virtual SUIParameterDesc const* GetVariableDesc(int arg0) const = 0;
	virtual SUIParameterDesc const* GetVariableDesc(const char* arg0) const = 0;
	virtual int GetVariableCount() const = 0;
	virtual SUIParameterDesc const* GetArrayDesc(int arg0) const = 0;
	virtual SUIParameterDesc const* GetArrayDesc(const char* arg0) const = 0;
	virtual int GetArrayCount() const = 0;
	virtual SUIMovieClipDesc const* GetMovieClipDesc(int arg0) const = 0;
	virtual SUIMovieClipDesc const* GetMovieClipDesc(const char* arg0) const = 0;
	virtual int GetMovieClipCount() const = 0;
	virtual SUIMovieClipDesc const* GetMovieClipTmplDesc(int arg0) const = 0;
	virtual SUIMovieClipDesc const* GetMovieClipTmplDesc(const char* arg0) const = 0;
	virtual int GetMovieClipTmplCount() const = 0;
	virtual SUIEventDesc const* GetEventDesc(int arg0) const = 0;
	virtual SUIEventDesc const* GetEventDesc(const char* arg0) const = 0;
	virtual int GetEventCount() const = 0;
	virtual SUIEventDesc const* GetFunctionDesc(int arg0) const = 0;
	virtual SUIEventDesc const* GetFunctionDesc(const char* arg0) const = 0;
	virtual int GetFunctionCount() const = 0;
	virtual void UpdateViewPort() = 0;
	virtual void GetViewPort(int& arg0, int& arg1, int& arg2, int& arg3, float& arg4) = 0;
	virtual bool Serialize(XmlNodeRef& arg0, const char* arg1, bool arg2) = 0;
	virtual void AddEventListener(IUIElementEventListener* arg0, const char* arg1) = 0;
	virtual void RemoveEventListener(IUIElementEventListener* arg0) = 0;
	virtual bool CallFunction(const char* arg0, SUIArguments const& arg1, TUIData* arg2, const char* arg3) = 0;
	virtual bool CallFunction(SUIEventDesc const* arg0, SUIArguments const& arg1, TUIData* arg2, SUIMovieClipDesc const* arg3, bool arg4) = 0;
	virtual IFlashVariableObject* GetMovieClip(const char* arg0, const char* arg1) = 0;
	virtual IFlashVariableObject* GetMovieClip(SUIMovieClipDesc const* arg0, SUIMovieClipDesc const* arg1) = 0;
	virtual IFlashVariableObject* CreateMovieClip(SUIMovieClipDesc const*& arg0, const char* arg1, const char* arg2, const char* arg3) = 0;
	virtual IFlashVariableObject* CreateMovieClip(SUIMovieClipDesc const*& arg0, SUIMovieClipDesc const* arg1, SUIMovieClipDesc const* arg2, const char* arg3) = 0;
	virtual void RemoveMovieClip(const char* arg0) = 0;
	virtual void RemoveMovieClip(SUIParameterDesc const* arg0) = 0;
	virtual void RemoveMovieClip(IFlashVariableObject* arg0) = 0;
	virtual bool SetVariable(const char* arg0, TUIData const& arg1, const char* arg2) = 0;
	virtual bool SetVariable(SUIParameterDesc const* arg0, TUIData const& arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual bool GetVariable(const char* arg0, TUIData& arg1, const char* arg2) = 0;
	virtual bool GetVariable(SUIParameterDesc const* arg0, TUIData& arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual bool CreateVariable(SUIParameterDesc const*& arg0, const char* arg1, TUIData const& arg2, const char* arg3) = 0;
	virtual bool CreateVariable(SUIParameterDesc const*& arg0, const char* arg1, TUIData const& arg2, SUIMovieClipDesc const* arg3) = 0;
	virtual bool SetArray(const char* arg0, SUIArguments const& arg1, const char* arg2) = 0;
	virtual bool SetArray(SUIParameterDesc const* arg0, SUIArguments const& arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual bool GetArray(const char* arg0, SUIArguments& arg1, const char* arg2) = 0;
	virtual bool GetArray(SUIParameterDesc const* arg0, SUIArguments& arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual bool CreateArray(SUIParameterDesc const*& arg0, const char* arg1, SUIArguments const& arg2, const char* arg3) = 0;
	virtual bool CreateArray(SUIParameterDesc const*& arg0, const char* arg1, SUIArguments const& arg2, SUIMovieClipDesc const* arg3) = 0;
	virtual void LoadTexIntoMc(const char* arg0, ITexture* arg1, const char* arg2) = 0;
	virtual void LoadTexIntoMc(SUIParameterDesc const* arg0, ITexture* arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual void UnloadTexFromMc(const char* arg0, ITexture* arg1, const char* arg2) = 0;
	virtual void UnloadTexFromMc(SUIParameterDesc const* arg0, ITexture* arg1, SUIMovieClipDesc const* arg2) = 0;
	virtual void ScreenToFlash(const float& arg0, const float& arg1, float& arg2, float& arg3, bool arg4) const = 0;
	virtual void WorldToFlash(Matrix34 const& arg0, Vec3 const& arg1, Vec3& arg2, Vec2& arg3, float& arg4, bool arg5) const = 0;
	virtual void AddTexture(IDynTextureSource* arg0) = 0;
	virtual void RemoveTexture(IDynTextureSource* arg0) = 0;
	virtual int GetNumExtTextures() const = 0;
	virtual bool GetDynTexSize(int& arg0, int& arg1) const = 0;
	virtual void SendCursorEvent(int arg0, int arg1, int arg2, int arg3, float arg4) = 0;
	virtual void SendKeyEvent(SFlashKeyEvent const& arg0) = 0;
	virtual void SendCharEvent(SFlashCharEvent const& arg0) = 0;
	virtual void SendControllerEvent(IUIElement::EControllerInputEvent arg0, IUIElement::EControllerInputState arg1, float arg2) = 0;
	virtual void GetMemoryUsage(ICrySizer* arg0) const = 0;
	virtual void RemoveFlashVarObj(SUIParameterDesc const* arg0) = 0;
	virtual void SetAssociatedEntity(IEntity* const arg0) = 0;
	virtual void SetWorldUIEntity(IEntity* arg0) = 0;
	virtual IEntity* GetWorldUIEntity() const = 0;
	virtual void SetWorldUIDistances(float arg0, float arg1, float arg2) = 0;
	virtual void SetWorldUIInteractPos(Vec3 const& arg0, Vec3 const& arg1) = 0;
	virtual void SetWorldUIActive(bool arg0) = 0;
	virtual bool IsWorldUIElement() const = 0;
	virtual int GetWorldUIPoolSize() const = 0;
	virtual bool IsAvailableForGameMode(CCryName arg0) const = 0;
};

// Header: Exact
// CryEngine/cryaction/flashui/flashui.h
class CFlashUI
{
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

	static constexpr size_t OFFSET_m_bHudVisible = 0x01C8;

	static inline auto CV_gfx_draw = PreyGlobal<int>(0x2473B28);

	static inline auto FGetFactory = PreyFunction<ICryFactory* (CFlashUI const* const _this)>(0x2CD760);
	static inline auto FQueryInterface = PreyFunction<void* (CFlashUI const* const _this, CryGUID const& iid)>(0x2CD770);
	static inline auto FQueryComposite = PreyFunction<void* (CFlashUI const* const _this, const char* name)>(0x158AEF0);
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
	static inline auto FLoadActionFromFile = PreyFunction<bool(CFlashUI* const _this, const char* sFileName, int type)>(0x2CE740);
	static inline auto FGetUIElementOv1 = PreyFunction<IUIElement* (CFlashUI const* const _this, const char* sName)>(0x2CE760);
	static inline auto FGetUIElementOv0 = PreyFunction<IUIElement* (CFlashUI const* const _this, int index)>(0x2CE820);
	static inline auto FGetUIElementCount = PreyFunction<int(CFlashUI const* const _this)>(0x2CE840);
	static inline auto FGetUIElementByInstanceStr = PreyFunction<IUIElement* (CFlashUI const* const _this, const char* sUIInstanceStr)>(0x2CE850);
	static inline auto FGetUIActionOv1 = PreyFunction<IUIAction* (CFlashUI const* const _this, const char* sName)>(0x2CE9F0);
	static inline auto FGetUIActionOv0 = PreyFunction<IUIAction* (CFlashUI const* const _this, int index)>(0x2CEAC0);
	static inline auto FGetUIActionCount = PreyFunction<int(CFlashUI const* const _this)>(0x2CEAE0);
	static inline auto FGetUIActionManager = PreyFunction<IUIActionManager* (CFlashUI const* const _this)>(0x155AD20);
	static inline auto FUpdateFG = PreyFunction<void(CFlashUI* const _this)>(0x2CEAF0);
	static inline auto FEnableEventStack = PreyFunction<void(CFlashUI* const _this, bool bEnable)>(0xA13080);
	static inline auto FRegisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule, const char* name)>(0x2CEBB0);
	static inline auto FUnregisterModule = PreyFunction<void(CFlashUI* const _this, IUIModule* pModule)>(0x2CEC00);
	static inline auto FSetHudElementsVisible = PreyFunction<void(CFlashUI* const _this, bool bVisible)>(0x2CEC80);
	static inline auto FCreateEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* sName, int eType)>(0x2CECF0);
	static inline auto FGetEventSystem = PreyFunction<IUIEventSystem* (CFlashUI* const _this, const char* name, int eType)>(0x2CEE00);
	static inline auto FCreateEventSystemIterator = PreyFunction<_smart_ptr<IUIEventSystemIterator>(CFlashUI* const _this, int eType)>(0x2CEF40);
	static inline auto FDispatchControllerEvent = PreyFunction<void(CFlashUI* const _this, IUIElement::EControllerInputEvent event, IUIElement::EControllerInputState state, float value)>(0x2CEFD0);
	static inline auto FSendFlashMouseEvent = PreyFunction<void(CFlashUI* const _this, int evt, int iX, int iY, int iButton, float fWheel, bool bFromController)>(0x2CF280);
	static inline auto FDisplayVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this, unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback)>(0x2CF7E0);
	static inline auto FIsVirtualKeyboardRunning = PreyFunction<bool(CFlashUI* const _this)>(0x2CF890);
	static inline auto FCancelVirtualKeyboard = PreyFunction<bool(CFlashUI* const _this)>(0x2CF8C0);
	static inline auto FGetScreenSize = PreyFunction<void(CFlashUI* const _this, int& width, int& height)>(0x2CF8F0);
	static inline auto FSetEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this, Functor2<int&, int&>& cb)>(0x2CF940);
	static inline auto FRemoveEditorScreenSizeCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CF960);
	static inline auto FSetEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this, Functor1<int const&>& cb)>(0x2CF990);
	static inline auto FRemoveEditorUILogEventCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CF9B0);
	static inline auto FSetEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this, Functor0wRet<int>& cb)>(0x2CF9E0);
	static inline auto FRemoveEditorPlatformCallback = PreyFunction<void(CFlashUI* const _this)>(0x2CFA00);
	static inline auto FUseSharedRT = PreyFunction<bool(CFlashUI const* const _this, const char* instanceStr, bool defVal)>(0x2CFA30);
	static inline auto FCheckPreloadedTexture = PreyFunction<void(CFlashUI const* const _this, ITexture* pTexture)>(0x2CFA70);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CFlashUI const* const _this, ICrySizer* s)>(0x2CFB00);
	static inline auto FIsWorldUIInteraction = PreyFunction<bool(CFlashUI const* const _this)>(0x2CFEC0);
	static inline auto FSetWorldUICursorDisabled = PreyFunction<void(CFlashUI* const _this, bool _bDisabled)>(0x2CFED0);
	static inline auto FIsWorldUIEntity = PreyFunction<std::pair<bool, bool>(CFlashUI const* const _this, IEntity const* const _pEntity)>(0x2CFEF0);
	static inline auto FOnHardwareMouseEvent = PreyFunction<void(CFlashUI* const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)>(0x2D0010);
	static inline auto FOnInputEvent = PreyFunction<bool(CFlashUI* const _this, SInputEvent const& event)>(0x2D0100);
	static inline auto FOnInputEventUI = PreyFunction<bool(CFlashUI* const _this, SInputEvent const& event)>(0x2D0670);
	static inline auto FOnSystemEvent = PreyFunction<void(CFlashUI* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x2D08C0);
	static inline auto FOnPostUpdate = PreyFunction<void(CFlashUI* const _this, float fDeltaTime)>(0xA13080);
	static inline auto FOnSaveGame = PreyFunction<void(CFlashUI* const _this, ISaveGame* pSaveGame)>(0xA13080);
	static inline auto FOnLoadGame = PreyFunction<void(CFlashUI* const _this, ILoadGame* pLoadGame)>(0xA13080);
	static inline auto FOnLevelEnd = PreyFunction<void(CFlashUI* const _this, const char* nextLevel)>(0xA13080);
	static inline auto FOnActionEvent = PreyFunction<void(CFlashUI* const _this, SActionEvent const& event)>(0x2D0EF0);
	static inline auto FOnLevelNotFound = PreyFunction<void(CFlashUI* const _this, const char* levelName)>(0x2D0F60);
	static inline auto FOnLoadingStart = PreyFunction<void(CFlashUI* const _this, ILevelInfo* pLevel)>(0xA13080);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(CFlashUI* const _this, ILevelInfo* pLevel)>(0xA13080);
	static inline auto FOnLoadingComplete = PreyFunction<void(CFlashUI* const _this, ILevel* pLevel)>(0xA13080);
	static inline auto FOnLoadingError = PreyFunction<void(CFlashUI* const _this, ILevelInfo* pLevel, const char* error)>(0x2D1000);
	static inline auto FOnLoadingProgress = PreyFunction<void(CFlashUI* const _this, ILevelInfo* pLevel, int progressAmount)>(0x2D1070);
	static inline auto FOnUnloadComplete = PreyFunction<void(CFlashUI* const _this, ILevel* pLevel)>(0xA13080);
	static inline auto FLoadtimeUpdate = PreyFunction<void(CFlashUI* const _this, float fDeltaTime)>(0x2D1180);
	static inline auto FLoadtimeRender = PreyFunction<void(CFlashUI* const _this)>(0x2D1210);
	static inline auto FUpdateSteamMenuState = PreyFunction<void(CFlashUI* const _this, bool _bEnable)>(0x2D9340);
	//static inline auto FLogUIAction = PreyFunction<void(int level, const char* format, ...)>(0x2D7250);
	static inline auto FReloadAllElements = PreyFunction<void(IConsoleCmdArgs* )>(0x2D8A60);
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
	static inline auto FPreloadTexturesFromNode = PreyFunction<void(CFlashUI* const _this, XmlNodeRef const& node)>(0x2D8130);
	static inline auto FPreloadTexture = PreyFunction<bool(CFlashUI* const _this, const char* pFileName)>(0x2D7490);
	static inline auto FReleasePreloadedTextures = PreyFunction<void(CFlashUI* const _this, bool bReleaseTextures)>(0x2D8490);
	static inline auto FGetSortedElements = PreyFunction<std::multimap<int, IUIElement*, std::less<int>, std::allocator<std::pair<int const, IUIElement*> > > const& (CFlashUI* const _this)>(0x2D62C0);
	static inline auto FUpdateSortedElements = PreyFunction<void(CFlashUI* const _this)>(0x2D9230);
	static inline auto FStartRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2D8D50);
	static inline auto FStopRenderThread = PreyFunction<void(CFlashUI* const _this)>(0x2D8FE0);
	static inline auto FCheckResolutionChange = PreyFunction<void(CFlashUI* const _this)>(0x2D5530);
	static inline auto FReloadAllBootStrapper = PreyFunction<void(CFlashUI* const _this, bool _bUnloadBootStrapper)>(0x2D8570);
	static inline auto FShowLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2D8D00);
	static inline auto FHideLoadingScreen = PreyFunction<void(CFlashUI* const _this)>(0x2D6300);
	static inline auto FCheckFilter = PreyFunction<bool(string const& str)>(0x2D4D70);
};

struct IFlashPlayer
{
	virtual ~IFlashPlayer() {}
};

struct IFlashPlayer_RenderProxy
{
	virtual ~IFlashPlayer_RenderProxy() {}
};

class CFlashPlayer : public IFlashPlayer, public IFlashPlayer_RenderProxy
{
public:
	virtual void AddRef();
	virtual void Release();
};
