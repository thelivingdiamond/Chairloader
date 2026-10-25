// Header file automatically created from a PDB.
// The flash UI interfaces (CRYENGINE keeps them in CryCommon/IFlashUI.h): IUIElement and
// IFlashUI here, IUIAction / IUIEventSystem next to CFlashUI in CryAction/FlashUI/.

#pragma once
#include <Prey/CrySystem/Scaleform/SFlashCursorEvent.h>
#include <Prey/CryAction/FlashUI/IUIEventSystem.h>
#include <Prey/CryAction/FlashUI/IUIAction.h>
#include <Prey/CryExtension/ClassWeaver.h>
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/CryExtension/ICryUnknown.h>
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/CryCore/Containers/CryListenerSet.h>
#include <Prey/CryThreading/IJobManager.h>

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

// IFlashUI
// Header:  CryEngine/crycommon/IFlashUI.h
struct IFlashUI : public ICryUnknown
{ // Size=8 (0x8)
	enum EPlatformUI
	{
		ePUI_PC = 0,
		ePUI_Durango = 1,
		ePUI_Orbis = 2,
		ePUI_Android = 3,
	};

	enum ELogEventLevel
	{
		eLEL_Log = 0,
		eLEL_Warning = 1,
		eLEL_Error = 2,
	};

	// IFlashUI::SUILogEvent
	// Header:  CryEngine/crycommon/IFlashUI.h
	struct SUILogEvent
	{ // Size=16 (0x10)
		string Message;
		IFlashUI::ELogEventLevel Level;
	};

	using TEditorScreenSizeCallback = Functor2<int&, int&>;
	using TEditorPlatformCallback = Functor0wRet<IFlashUI::EPlatformUI>;
	using TEditorUILogEventCallback = Functor1<IFlashUI::SUILogEvent const&>;

	virtual ~IFlashUI() {}
	virtual void Init() = 0;
	virtual bool PostInit() = 0;
	virtual void Update(float fDeltaTimeUI, float fDeltaTimeGame) = 0;
	virtual void Reload(bool _bFullUnload) = 0;
	virtual void Shutdown() = 0;
	virtual bool LoadElementsFromFile(const char* sFileName) = 0;
	virtual bool LoadActionFromFile(const char* sFileName, IUIAction::EUIActionType type) = 0;
	virtual IUIElement* GetUIElement(const char* sName) const = 0;
	virtual IUIElement* GetUIElement(int index) const = 0;
	virtual int GetUIElementCount() const = 0;
	virtual IUIElement* GetUIElementByInstanceStr(const char* sUIInstanceStr) const = 0;
	virtual IUIAction* GetUIAction(const char* sName) const = 0;
	virtual IUIAction* GetUIAction(int index) const = 0;
	virtual int GetUIActionCount() const = 0;
	virtual IUIActionManager* GetUIActionManager() const = 0;
	virtual void UpdateFG() = 0;
	virtual void RegisterModule(IUIModule* pModule, const char* name) = 0;
	virtual void UnregisterModule(IUIModule* pModule) = 0;
	virtual void SetHudElementsVisible(bool bVisible) = 0;
	virtual void EnableEventStack(bool bEnable) = 0;
	virtual IUIEventSystem* CreateEventSystem(const char* sName, IUIEventSystem::EEventSystemType eType) = 0;
	virtual IUIEventSystem* GetEventSystem(const char* name, IUIEventSystem::EEventSystemType eType) = 0;
	virtual _smart_ptr<IUIEventSystemIterator> CreateEventSystemIterator(IUIEventSystem::EEventSystemType eType) = 0;
	virtual void DispatchControllerEvent(IUIElement::EControllerInputEvent event, IUIElement::EControllerInputState state, float value) = 0;
	virtual void SendFlashMouseEvent(SFlashCursorEvent::ECursorState evt, int iX, int iY, int iButton, float fWheel, bool bFromController) = 0;
	virtual bool DisplayVirtualKeyboard(unsigned flags, const wchar_t* title, const wchar_t* initialInput, int maxInputLength, IVirtualKeyboardEvents* pInCallback) = 0;
	virtual bool IsVirtualKeyboardRunning() = 0;
	virtual bool CancelVirtualKeyboard() = 0;
	virtual void CheckPreloadedTexture(ITexture* pTexture) const = 0;
	virtual bool UseSharedRT(const char* instanceStr, bool defVal) const = 0;
	virtual void GetMemoryStatistics(ICrySizer* s) const = 0;
	virtual void GetScreenSize(int& width, int& height) = 0;
	virtual void SetEditorScreenSizeCallback(Functor2<int&, int&>& cb) = 0;
	virtual void RemoveEditorScreenSizeCallback() = 0;
	virtual bool IsWorldUIInteraction() const = 0;
	virtual void SetWorldUICursorDisabled(bool _bDisabled) = 0;
	virtual std::pair<bool, bool> IsWorldUIEntity(const IEntity* const _pEntity) const = 0;
	static bool IsWorldUIWithinInteractAngle(const IEntity& _worldUIEntity, const float _fInteractAngle) { return FIsWorldUIWithinInteractAngle(_worldUIEntity, _fInteractAngle); }
	virtual void SetEditorPlatformCallback(Functor0wRet<IFlashUI::EPlatformUI>& cb) = 0;
	virtual void RemoveEditorPlatformCallback() = 0;
	virtual void SetEditorUILogEventCallback(Functor1<IFlashUI::SUILogEvent const&>& cb) = 0;
	virtual void RemoveEditorUILogEventCallback() = 0;

#ifndef MOONCRASH
	static inline auto FIsWorldUIWithinInteractAngle = PreyFunction<bool(const IEntity& _worldUIEntity, const float _fInteractAngle)>(0x2D6390);
#else // MOONCRASH
	static inline auto FIsWorldUIWithinInteractAngle = PreyFunction<bool(const IEntity& _worldUIEntity, const float _fInteractAngle)>(0x2F0A20);
#endif // !MOONCRASH
};
