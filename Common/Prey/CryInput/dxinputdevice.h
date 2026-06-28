// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/inputdevice.h>

class CDXInput;
struct IDirectInputDevice8A;

class _DIDATAFORMAT;

// Header: FromCpp
// CryEngine/cryinput/dxinputdevice.h
class CDXInputDevice : public CInputDevice // Id=800D0A9 Size=152
{
public:
	CDXInput &m_dxInput;
	IDirectInputDevice8A *m_pDevice;
	_GUID const &m_guid;
	_DIDATAFORMAT const *m_pDataFormat;
	unsigned long m_dwCoopLevel;
	bool m_bNeedsPoll;
	
	CDXInputDevice(CDXInput &input, const char *deviceName, _GUID const &guid);
	virtual ~CDXInputDevice();
	CDXInput &GetDXInput() const { return FGetDXInput(this); }
	IDirectInputDevice8A *GetDirectInputDevice() const { return FGetDirectInputDevice(this); }
	bool Acquire() { return FAcquire(this); }
	bool Unacquire() { return FUnacquire(this); }
	bool CreateDirectInputDevice(_DIDATAFORMAT const *dataFormat, unsigned long coopLevel, unsigned long bufSize) { return FCreateDirectInputDevice(this,dataFormat,coopLevel,bufSize); }
	
	static inline auto FBitNotCDXInputDevice = PreyFunction<void(CDXInputDevice *const _this)>(0x9D0780);
	static inline auto FGetDXInput = PreyFunction<CDXInput &(CDXInputDevice const *const _this)>(0xE70280);
	static inline auto FGetDirectInputDevice = PreyFunction<IDirectInputDevice8A *(CDXInputDevice const *const _this)>(0x155ACE0);
	static inline auto FAcquire = PreyFunction<bool(CDXInputDevice *const _this)>(0x9D0840);
	static inline auto FUnacquire = PreyFunction<bool(CDXInputDevice *const _this)>(0x9D0A20);
	static inline auto FCreateDirectInputDevice = PreyFunction<bool(CDXInputDevice *const _this, _DIDATAFORMAT const *dataFormat, unsigned long coopLevel, unsigned long bufSize)>(0x9D08B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryInput/InputDevice.h>

class CDXInput;
struct IDirectInputDevice8A;

// CDXInputDevice
// Header:  CryEngine/cryinput/DXInputDevice.h
// Include: Prey/CryInput/DXInputDevice.h
class CDXInputDevice : public CInputDevice
{ // Size=152 (0x98)
public:
	CDXInput& m_dxInput;
	IDirectInputDevice8A* m_pDevice;
	const _GUID& m_guid;
	const _DIDATAFORMAT* m_pDataFormat;
	unsigned long m_dwCoopLevel;
	bool m_bNeedsPoll;

	CDXInputDevice(CDXInput& input, const char* deviceName, const _GUID& guid);
	virtual ~CDXInputDevice();
	CDXInput& GetDXInput() const { return FGetDXInput(this); }
	IDirectInputDevice8A* GetDirectInputDevice() const { return FGetDirectInputDevice(this); }
	bool Acquire() { return FAcquire(this); }
	bool Unacquire() { return FUnacquire(this); }
	bool CreateDirectInputDevice(const _DIDATAFORMAT* dataFormat, unsigned long coopLevel, unsigned long bufSize) { return FCreateDirectInputDevice(this, dataFormat, coopLevel, bufSize); }

	static inline auto FCDXInputDeviceOv1 = PreyFunction<void(CDXInputDevice* const _this, CDXInput& input, const char* deviceName, const _GUID& guid)>(0x9EDAA0);
	static inline auto FBitNotCDXInputDevice = PreyFunction<void(CDXInputDevice* const _this)>(0x9EDB00);
	static inline auto FGetDXInput = PreyFunction<CDXInput& (const CDXInputDevice* const _this)>(0xB48DC0);
	static inline auto FGetDirectInputDevice = PreyFunction<IDirectInputDevice8A* (const CDXInputDevice* const _this)>(0x83F4B0);
	static inline auto FAcquire = PreyFunction<bool(CDXInputDevice* const _this)>(0x9EDBC0);
	static inline auto FUnacquire = PreyFunction<bool(CDXInputDevice* const _this)>(0x9EDDB0);
	static inline auto FCreateDirectInputDevice = PreyFunction<bool(CDXInputDevice* const _this, const _DIDATAFORMAT* dataFormat, unsigned long coopLevel, unsigned long bufSize)>(0x9EDC30);
};
#endif // !MOONCRASH
