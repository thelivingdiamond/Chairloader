// Header file automatically created from a PDB.

#pragma once

struct HWND__;

// Header: FromCpp
// Prey/GameDll/basiceventlistener.h
struct IBasicEventListener // Id=801CDC3 Size=8
{
	enum EAction
	{
		eA_Default = 0,
		eA_None = 1,
		eA_ActivateAndEat = 2,
	};

	virtual ~IBasicEventListener();
	virtual IBasicEventListener::EAction OnClose(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnMouseActivate(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnEnterSizeMove(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnExitSizeMove(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnEnterMenuLoop(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnExitMenuLoop(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnHotKey(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnSycChar(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnChar(HWND__ *arg0, uint64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnIMEChar(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnSysKeyDown(HWND__ *arg0, uint64_t arg1, int64_t arg2) = 0;
	virtual IBasicEventListener::EAction OnSetCursor(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnMouseMove(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnLeftButtonDown(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnLeftButtonUp(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnLeftButtonDoubleClick(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnRightButtonDown(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnRightButtonUp(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnMouseWheel(HWND__ *arg0, int64_t arg1, int16_t arg2) = 0;
	virtual IBasicEventListener::EAction OnMove(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnSize(HWND__ *arg0, int64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnActivate(HWND__ *arg0, uint64_t arg1) = 0;
	virtual IBasicEventListener::EAction OnSetFocus(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnKillFocus(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnWindowPositionChanged(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnWindowStyleChanged(HWND__ *arg0) = 0;
	virtual IBasicEventListener::EAction OnInputLanguageChanged(HWND__ *arg0, uint64_t arg1, int64_t arg2) = 0;
	virtual IBasicEventListener::EAction OnSysCommand(HWND__ *arg0, uint64_t arg1) = 0;
	
	static inline auto FBitNotIBasicEventListener = PreyFunction<void(IBasicEventListener *const _this)>(0x16859B0);
};

// Header: FromCpp
// Prey/GameDll/basiceventlistener.h
class CBasicEventListener : public IBasicEventListener // Id=801CDC4 Size=16
{
public:
	static inline auto g_debugWindowsMessages = PreyGlobal<const bool>(0x1E60948);
	int m_iLastMoveX;
	int m_iLastMoveY;
	
	CBasicEventListener();
	virtual IBasicEventListener::EAction OnClose(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnMouseActivate(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnEnterSizeMove(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnExitSizeMove(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnEnterMenuLoop(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnExitMenuLoop(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnHotKey(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnSycChar(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnChar(HWND__ *hWnd, uint64_t wParam);
	virtual IBasicEventListener::EAction OnIMEChar(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnSysKeyDown(HWND__ *hWn, uint64_t wParam, int64_t lParam);
	virtual IBasicEventListener::EAction OnSetCursor(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnMouseMove(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnLeftButtonDown(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnLeftButtonUp(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnLeftButtonDoubleClick(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnRightButtonDown(HWND__ *_hWnd, int64_t _lParam);
	virtual IBasicEventListener::EAction OnRightButtonUp(HWND__ *_hWnd, int64_t _lParam);
	virtual IBasicEventListener::EAction OnMouseWheel(HWND__ *hWnd, int64_t lParam, int16_t WheelDelta);
	virtual IBasicEventListener::EAction OnMove(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnSize(HWND__ *hWnd, int64_t lParam);
	virtual IBasicEventListener::EAction OnActivate(HWND__ *hWnd, uint64_t wParam);
	virtual IBasicEventListener::EAction OnSetFocus(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnKillFocus(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnWindowPositionChanged(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnWindowStyleChanged(HWND__ *hWnd);
	virtual IBasicEventListener::EAction OnInputLanguageChanged(HWND__ *hWnd, uint64_t wParam, int64_t lParam);
	virtual IBasicEventListener::EAction OnSysCommand(HWND__ *hWnd, uint64_t wParam);
	virtual ~CBasicEventListener();
	
	static inline auto FOnClose = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685B90);
	static inline auto FOnMouseActivate = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1A42CE0);
	static inline auto FOnEnterSizeMove = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685BC0);
	static inline auto FOnExitSizeMove = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685C10);
	static inline auto FOnEnterMenuLoop = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685BC0);
	static inline auto FOnExitMenuLoop = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685C10);
	static inline auto FOnHotKey = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1B1DEA0);
	static inline auto FOnSycChar = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1B1DEA0);
	static inline auto FOnChar = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, uint64_t wParam)>(0x1685A90);
	static inline auto FOnIMEChar = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1B1DEA0);
	static inline auto FOnSysKeyDown = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWn, uint64_t wParam, int64_t lParam)>(0x16860D0);
	static inline auto FOnSetCursor = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685F90);
	static inline auto FOnMouseMove = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1685E00);
	static inline auto FOnLeftButtonDown = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1685D60);
	static inline auto FOnLeftButtonUp = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1685DB0);
	static inline auto FOnLeftButtonDoubleClick = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1685D10);
	static inline auto FOnRightButtonDown = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *_hWnd, int64_t _lParam)>(0x1685EF0);
	static inline auto FOnRightButtonUp = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *_hWnd, int64_t _lParam)>(0x1685F40);
	static inline auto FOnMouseWheel = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam, int16_t WheelDelta)>(0x1685E50);
	static inline auto FOnMove = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1685E90);
	static inline auto FOnSize = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, int64_t lParam)>(0x1686010);
	static inline auto FOnActivate = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, uint64_t wParam)>(0x1685A20);
	static inline auto FOnSetFocus = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685FC0);
	static inline auto FOnKillFocus = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1685CC0);
	static inline auto FOnWindowPositionChanged = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x16861D0);
	static inline auto FOnWindowStyleChanged = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd)>(0x1686220);
	static inline auto FOnInputLanguageChanged = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, uint64_t wParam, int64_t lParam)>(0x1685C60);
	static inline auto FOnSysCommand = PreyFunction<IBasicEventListener::EAction(CBasicEventListener *const _this, HWND__ *hWnd, uint64_t wParam)>(0x1686070);
};

