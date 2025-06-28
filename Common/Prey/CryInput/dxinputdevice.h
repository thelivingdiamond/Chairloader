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

