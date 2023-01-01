// Header test file for path CryEngine/cryinput/baseinput.h
#include "baseinput.h"
static_assert(sizeof(CBaseInput) == 264);

#include "cryinput.h"
static_assert(sizeof(CEngineModule_CryInput) == 8);

#include "dxinput.h"
static_assert(sizeof(CDXInput) == 288);

#include "dxinputdevice.h"
static_assert(sizeof(CDXInputDevice) == 152);

#include "inputcvars.h"
static_assert(sizeof(CInputCVars) == 112);

#include "inputdevice.h"
static_assert(sizeof(CInputDevice) == 112);

#include "keyboard.h"
static_assert(sizeof(CKeyboard) == 152);
static_assert(sizeof(CKeyboard::SScanCode) == 12);

#include "mouse.h"
static_assert(sizeof(CMouse) == 184);

#include "xinputdevice.h"
static_assert(sizeof(CXInputDevice) == 168);
static_assert(sizeof(CInputConnectionThreadTask) == 80);
//static_assert(sizeof(CServiceNetworkConnection) == 304);
//static_assert(sizeof(CServiceNetworkConnection::Header) == 5);
//static_assert(sizeof(CServiceNetworkConnection::InitHeader) == 24);
