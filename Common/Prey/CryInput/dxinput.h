// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/BaseInput.h>

struct HWND__;
struct IDirectInput8A;
struct ISystem;

// Header: FromCpp
// CryEngine/cryinput/dxinput.h
class CDXInput : public CBaseInput // Id=800D044 Size=288
{
public:
	HWND__ *m_hwnd;
	IDirectInput8A *m_pDI;
	int64_t (*m_prevWndProc)(HWND__ *, unsigned, uint64_t, int64_t);
	static inline auto This = PreyGlobal<CDXInput *>(0x2766750);
	
	CDXInput(ISystem *pSystem, HWND__ *hwnd);
	virtual ~CDXInput();
	virtual bool Init();
	virtual void Update(bool bFocus);
	virtual void ShutDown();
	virtual void ClearKeyState();
	virtual void SetExclusiveMode(EInputDeviceType deviceType, bool exclusive, void *pUser);
	
#if 0
	HWND__ *GetHWnd() const;
	IDirectInput8A *GetDirectInput() const;
	static int64_t InputWndProc(HWND__ *arg0, unsigned arg1, uint64_t arg2, int64_t arg3);
	int64_t OnInputWndProc(HWND__ *arg0, unsigned arg1, uint64_t arg2, int64_t arg3);
#endif
	
	static inline auto FInit = PreyFunction<bool(CDXInput *const _this)>(0x9D0540);
	static inline auto FUpdate = PreyFunction<void(CDXInput *const _this, bool bFocus)>(0x9D0710);
	static inline auto FShutDown = PreyFunction<void(CDXInput *const _this)>(0x9D06C0);
	static inline auto FClearKeyState = PreyFunction<void(CDXInput *const _this)>(0x9D04D0);
	static inline auto FSetExclusiveMode = PreyFunction<void(CDXInput *const _this, EInputDeviceType deviceType, bool exclusive, void *pUser)>(0x9D06A0);
};

