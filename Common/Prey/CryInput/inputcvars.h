// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/inputcvars.h>

struct ICVar;

// Header: FromCpp
// CryEngine/cryinput/inputcvars.h
class CInputCVars // Id=800D090 Size=112
{
public:
	int i_debug;
	int i_forcefeedback;
	int i_mouse_buffered;
	float i_mouse_accel;
	float i_mouse_accel_max;
	float i_mouse_smooth;
	float i_mouse_inertia;
	int i_bufferedkeys;
	int i_xinput;
	int i_xinput_poll_time;
	int i_xinput_deadzone_handling;
	int i_debugDigitalButtons;
	int i_kinSkeletonSmoothType;
	int i_kinectDebug;
	int i_useKinect;
	int i_useSteamController;
	int i_seatedTracking;
	float i_kinSkeletonMovedDistance;
	float i_kinGlobalExpSmoothFactor;
	float i_kinGlobalExpCorrectionFactor;
	float i_kinGlobalExpPredictionFactor;
	float i_kinGlobalExpJitterRadius;
	float i_kinGlobalExpDeviationRadius;
	int i_kinectXboxConnect;
	int i_kinectXboxConnectPort;
	ICVar *i_kinectXboxConnectIP;
	
	CInputCVars();
	~CInputCVars();
	
	static inline auto FBitNotCInputCVars = PreyFunction<void(CInputCVars *const _this)>(0x9DAEC0);
};

inline PreyGlobal<CInputCVars*> g_pInputCVars(0x2767F50);
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ICVar;

// CInputCVars
// Header:  CryEngine/cryinput/InputCVars.h
// Include: Prey/CryInput/InputCVars.h
class CInputCVars
{ // Size=112 (0x70)
public:
	int i_debug;
	int i_forcefeedback;
	int i_mouse_buffered;
	float i_mouse_accel;
	float i_mouse_accel_max;
	float i_mouse_smooth;
	float i_mouse_inertia;
	int i_bufferedkeys;
	int i_xinput;
	int i_xinput_poll_time;
	int i_xinput_deadzone_handling;
	int i_debugDigitalButtons;
	int i_kinSkeletonSmoothType;
	int i_kinectDebug;
	int i_useKinect;
	int i_useSteamController;
	int i_seatedTracking;
	float i_kinSkeletonMovedDistance;
	float i_kinGlobalExpSmoothFactor;
	float i_kinGlobalExpCorrectionFactor;
	float i_kinGlobalExpPredictionFactor;
	float i_kinGlobalExpJitterRadius;
	float i_kinGlobalExpDeviationRadius;
	int i_kinectXboxConnect;
	int i_kinectXboxConnectPort;
	ICVar* i_kinectXboxConnectIP;

	CInputCVars();
	~CInputCVars();

	static inline auto FCInputCVars = PreyFunction<void(CInputCVars* const _this)>(0x9F7BD0);
	static inline auto FBitNotCInputCVars = PreyFunction<void(CInputCVars* const _this)>(0x9F8280);
};
#endif // !MOONCRASH
