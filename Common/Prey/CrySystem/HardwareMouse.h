// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CrySystem/ISystem.h>

struct IHardwareMouseEventListener;
class ITexture;
struct SInputEvent;

// Header: Exact
// CryEngine/crysystem/hardwaremouse.h
class CHardwareMouse :
	public IRendererEventListener,
	public IInputEventListener,
	public IHardwareMouse,
	public ISystemEventListener // Id=800FFB9 Size=96
{
public:
	using TListHardwareMouseEventListeners = std::list<IHardwareMouseEventListener *,std::allocator<IHardwareMouseEventListener *> >;
	
	std::list<IHardwareMouseEventListener *> m_listHardwareMouseEventListeners;
	ITexture *m_pCursorTexture;
	int m_iReferenceCounter;
	float m_fCursorX;
	float m_fCursorY;
	float m_fIncX;
	float m_fIncY;
	bool m_bFocus;
	bool m_recapture;
	const bool m_allowConfine;
	bool m_useSystemCursor;
	bool m_shouldUseSystemCursor;
	bool m_paused;
	bool m_shouldPause;
	bool m_hide;
	bool m_calledShowHWMouse;
	int m_debugHardwareMouse;
	
	virtual void OnPostCreateDevice();
	virtual void OnPostResetDevice();
	virtual bool OnInputEvent(SInputEvent const &rInputEvent);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void Release();
	virtual void OnPreInitRenderer();
	virtual void OnPostInitInput();
	virtual void Event(int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta);
	virtual void AddListener(IHardwareMouseEventListener *pHardwareMouseEventListener);
	virtual void RemoveListener(IHardwareMouseEventListener *pHardwareMouseEventListener);
	virtual void SetMouseGameMode(bool bGameMode);
	virtual void IncrementCounter();
	virtual void DecrementCounter();
	virtual void PauseMouse(bool _forceUpdate);
	virtual void UnPauseMouse();
	virtual void GetHardwareMousePosition(float *pfX, float *pfY);
	virtual void SetHardwareMousePosition(float fX, float fY);
	virtual void GetHardwareMouseClientPosition(float *pfX, float *pfY);
	virtual void SetHardwareMouseClientPosition(float fX, float fY);
	virtual void Reset(bool bVisibleByDefault);
	virtual void ConfineCursor(bool confine, bool centerCursor);
	virtual void Hide(bool hide);
	virtual void UseSystemCursor(bool useSystemCursor);
	virtual ISystemEventListener *GetSystemEventListener();
	virtual void Update();
	virtual void Render();
	CHardwareMouse(bool bVisibleByDefault);
	virtual ~CHardwareMouse();
	void ShowHardwareMouse(bool bShow) { FShowHardwareMouse(this,bShow); }
	static bool IsFullscreen() { return FIsFullscreen(); }
	
	static inline auto FOnPostCreateDevice = PreyFunction<void(CHardwareMouse *const _this)>(0xA13080);
	static inline auto FOnPostResetDevice = PreyFunction<void(CHardwareMouse *const _this)>(0xA13080);
	static inline auto FOnInputEvent = PreyFunction<bool(CHardwareMouse *const _this, SInputEvent const &rInputEvent)>(0xDA39F0);
	static inline auto FOnSystemEvent = PreyFunction<void(CHardwareMouse*const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xDA3B90);
	static inline auto FRelease = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3D30);
	static inline auto FOnPreInitRenderer = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3B70);
	static inline auto FOnPostInitInput = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3B40);
	static inline auto FEvent = PreyFunction<void(CHardwareMouse *const _this, int iX, int iY, EHARDWAREMOUSEEVENT eHardwareMouseEvent, int wheelDelta)>(0xDA37B0);
	static inline auto FAddListener = PreyFunction<void(CHardwareMouse *const _this, IHardwareMouseEventListener *pHardwareMouseEventListener)>(0xDA34B0);
	static inline auto FRemoveListener = PreyFunction<void(CHardwareMouse *const _this, IHardwareMouseEventListener *pHardwareMouseEventListener)>(0xE4CAC0);
	static inline auto FSetMouseGameMode = PreyFunction<void(CHardwareMouse *const _this, bool bGameMode)>(0xDA4080);
	static inline auto FIncrementCounter = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3960);
	static inline auto FDecrementCounter = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3760);
	static inline auto FPauseMouse = PreyFunction<void(CHardwareMouse *const _this, bool _forceUpdate)>(0xDA3CE0);
	static inline auto FUnPauseMouse = PreyFunction<void(CHardwareMouse *const _this)>(0xDA41A0);
	static inline auto FGetHardwareMousePosition = PreyFunction<void(CHardwareMouse *const _this, float *pfX, float *pfY)>(0xDA38D0);
	static inline auto FSetHardwareMousePosition = PreyFunction<void(IHardwareMouse*const _this, float fX, float fY)>(0xDA4010);
	static inline auto FGetHardwareMouseClientPosition = PreyFunction<void(IHardwareMouse*const _this, float *pfX, float *pfY)>(0xDA3840);
	static inline auto FSetHardwareMouseClientPosition = PreyFunction<void(IHardwareMouse*const _this, float fX, float fY)>(0xDA3FA0);
	static inline auto FReset = PreyFunction<void(CHardwareMouse *const _this, bool bVisibleByDefault)>(0xDA3F50);
	static inline auto FConfineCursor = PreyFunction<void(IHardwareMouse*const _this, bool confine, bool centerCursor)>(0xDA3550);
	static inline auto FHide = PreyFunction<void(CHardwareMouse *const _this, bool hide)>(0xDA3930);
	static inline auto FUseSystemCursor = PreyFunction<void(CHardwareMouse *const _this, bool useSystemCursor)>(0xDA42A0);
	static inline auto FGetSystemEventListener = PreyFunction<ISystemEventListener *(CHardwareMouse *const _this)>(0xDA3910);
	static inline auto FUpdate = PreyFunction<void(CHardwareMouse *const _this)>(0xDA41D0);
	static inline auto FRender = PreyFunction<void(CHardwareMouse *const _this)>(0xDA3D60);
	static inline auto FShowHardwareMouse = PreyFunction<void(CHardwareMouse *const _this, bool bShow)>(0xDA4090);
	static inline auto FIsFullscreen = PreyFunction<bool()>(0xDA39B0);
};

