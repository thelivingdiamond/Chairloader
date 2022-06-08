#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryInput/IInput.h>

enum EHARDWAREMOUSEEVENT
{
	HARDWAREMOUSEEVENT_MOVE = 0x0,
	HARDWAREMOUSEEVENT_LBUTTONDOWN = 0x1,
	HARDWAREMOUSEEVENT_LBUTTONUP = 0x2,
	HARDWAREMOUSEEVENT_LBUTTONDOUBLECLICK = 0x3,
	HARDWAREMOUSEEVENT_RBUTTONDOWN = 0x4,
	HARDWAREMOUSEEVENT_RBUTTONUP = 0x5,
	HARDWAREMOUSEEVENT_RBUTTONDOUBLECLICK = 0x6,
	HARDWAREMOUSEEVENT_MBUTTONDOWN = 0x7,
	HARDWAREMOUSEEVENT_MBUTTONUP = 0x8,
	HARDWAREMOUSEEVENT_MBUTTONDOUBLECLICK = 0x9,
	HARDWAREMOUSEEVENT_WHEEL = 0xA,
};

class IHardwareMouseEventListener
{
public:
	virtual ~IHardwareMouseEventListener() = 0;
	virtual void OnHardwareMouseEvent(int, int, EHARDWAREMOUSEEVENT, int) = 0;
};

class IHardwareMouse
{
public:
	virtual ~IHardwareMouse() = 0;
	virtual void Release() = 0;
	virtual void OnPreInitRenderer() = 0;
	virtual void OnPostInitInput() = 0;
	virtual void Event(int, int, EHARDWAREMOUSEEVENT, int) = 0;
	virtual void AddListener(IHardwareMouseEventListener *) = 0;
	virtual void RemoveListener(IHardwareMouseEventListener *) = 0;
	virtual void SetMouseGameMode(bool) = 0;
	virtual void IncrementCounter() = 0;
	virtual void DecrementCounter() = 0;
	virtual void PauseMouse(bool) = 0;
	virtual void UnPauseMouse() = 0;
	virtual void GetHardwareMousePosition(float *, float *) = 0;
	virtual void SetHardwareMousePosition(float, float) = 0;
	virtual void GetHardwareMouseClientPosition(float &, float &) = 0;
	virtual void SetHardwareMouseClientPosition(float, float) = 0;
	virtual void Reset(bool) = 0;
	virtual void ConfineCursor(bool, bool) = 0;
	virtual void Hide(bool) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void UseSystemCursor(bool) = 0;
	virtual ISystemEventListener *GetSystemEventListener() = 0;
};
