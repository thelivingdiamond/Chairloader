// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/CryInput/InputDevice.h>

struct IInput;
struct SInputEvent;
struct TKeyName;

// Header: Exact
// CryEngine/cryinput/inputdevice.h
class CInputDevice : public IInputDevice // Id=800CFCF Size=112
{
public:
	EInputDeviceType m_deviceType;
	uint64_t m_deviceId;
	bool m_enabled;
	IInput &m_input;
	string m_deviceName;
	
	using TNameToIdMap = std::map<TKeyName,unsigned int,std::less<TKeyName>>;
	using TNameToSymbolMap = std::map<TKeyName,SInputSymbol *,std::less<TKeyName>>;
	using TIdToSymbolMap = std::map<enum EKeyId,SInputSymbol *,std::less<enum EKeyId>>;
	using TDevSpecIdToSymbolMap = std::map<unsigned int,SInputSymbol *,std::less<unsigned int>>;
	
	std::map<TKeyName,unsigned int,std::less<TKeyName>> m_nameToId;
	std::map<TKeyName,SInputSymbol *,std::less<TKeyName>> m_nameToInfo;
	std::map<enum EKeyId,SInputSymbol *,std::less<enum EKeyId>> m_idToInfo;
	std::map<unsigned int,SInputSymbol *,std::less<unsigned int>> m_devSpecIdToSymbol;
	
	CInputDevice(IInput &input, const char *deviceName);
	virtual ~CInputDevice();
	virtual const char *GetDeviceName() const;
	virtual bool IsOfDeviceType(EInputDeviceType type) const;
	virtual EInputDeviceType GetDeviceType() const;
	virtual uint64_t GetDeviceId() const;
	virtual bool Init();
	virtual void PostInit();
	virtual void Update(bool bFocus);
	virtual bool SetForceFeedback(IFFParams params);
	virtual bool InputState(TKeyName const &keyName, EInputState state);
	virtual bool SetExclusiveMode(bool value);
	virtual void ClearKeyState();
	virtual void ClearAnalogKeyState(std::vector<SInputSymbol *> &clearedSymbols);
	virtual const char *GetKeyName(SInputEvent const &event) const;
	virtual const char *GetKeyName(EKeyId keyId) const;
	virtual char GetInputCharAscii(SInputEvent const &event);
	virtual const wchar_t *GetOSKeyName(SInputEvent const &event);
	virtual SInputSymbol *LookupSymbol(EKeyId id) const;
	virtual SInputSymbol const *GetSymbolByName(const char *name) const;
	virtual void Enable(bool enable);
	virtual bool IsEnabled() const;
	virtual bool IsConnected() const;
	virtual void OnLanguageChange();
	virtual void SetDeadZone(float fThreshold);
	virtual void RestoreDefaultDeadZone();
	unsigned NameToId(TKeyName const &name) const { return FNameToId(this,name); }
	SInputSymbol *DevSpecIdToSymbol(unsigned devSpecId) const { return FDevSpecIdToSymbol(this,devSpecId); }
	SInputSymbol *MapSymbol(unsigned deviceSpecificId, EKeyId keyId, TKeyName const &name, SInputSymbol::EType type, unsigned user) { return FMapSymbol(this,deviceSpecificId,keyId,name,type,user); }
	
#if 0
	IInput &GetIInput() const;
	SInputSymbol *IdToSymbol(EKeyId arg0) const;
	SInputSymbol *NameToSymbol(TKeyName const &arg0) const;
#endif
	
	static inline auto FBitNotCInputDevice = PreyFunction<void(CInputDevice *const _this)>(0x9D7940);
	static inline auto FGetDeviceName = PreyFunction<const char *(CInputDevice const *const _this)>(0xD87510);
	static inline auto FIsOfDeviceType = PreyFunction<bool(CInputDevice const *const _this, EInputDeviceType type)>(0x9D0A00);
	static inline auto FGetDeviceType = PreyFunction<EInputDeviceType(CInputDevice const *const _this)>(0xEEBB60);
	static inline auto FGetDeviceId = PreyFunction<uint64_t(CInputDevice const *const _this)>(0x5BFB50);
	static inline auto FInit = PreyFunction<bool(CInputDevice *const _this)>(0x1B933B0);
	static inline auto FPostInit = PreyFunction<void(CInputDevice *const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CInputDevice *const _this, bool bFocus)>(0xA13080);
	static inline auto FSetForceFeedback = PreyFunction<bool(CInputDevice *const _this, IFFParams params)>(0xDD23F0);
	static inline auto FInputState = PreyFunction<bool(CInputDevice *const _this, TKeyName const &keyName, EInputState state)>(0x9D7D70);
	static inline auto FSetExclusiveMode = PreyFunction<bool(CInputDevice *const _this, bool value)>(0x1B933B0);
	static inline auto FClearKeyState = PreyFunction<void(CInputDevice *const _this)>(0x9D7B10);
	static inline auto FClearAnalogKeyState = PreyFunction<void(CInputDevice *const _this, std::vector<SInputSymbol *> &clearedSymbols)>(0xA13080);
	static inline auto FGetKeyNameOv1 = PreyFunction<const char *(CInputDevice const *const _this, SInputEvent const &event)>(0x9D7C60);
	static inline auto FGetKeyNameOv0 = PreyFunction<const char *(CInputDevice const *const _this, EKeyId keyId)>(0x9D7C70);
	static inline auto FGetInputCharAscii = PreyFunction<char(CInputDevice *const _this, SInputEvent const &event)>(0xDD23F0);
	static inline auto FGetOSKeyName = PreyFunction<const wchar_t *(CInputDevice *const _this, SInputEvent const &event)>(0x9D7CC0);
	static inline auto FLookupSymbol = PreyFunction<SInputSymbol *(CInputDevice const *const _this, EKeyId id)>(0x9D7E20);
	static inline auto FGetSymbolByName = PreyFunction<SInputSymbol const *(CInputDevice const *const _this, const char *name)>(0x9D7CD0);
	static inline auto FEnable = PreyFunction<void(CInputDevice *const _this, bool enable)>(0x12BE0F0);
	static inline auto FIsEnabled = PreyFunction<bool(CInputDevice const *const _this)>(0x1141F10);
	static inline auto FIsConnected = PreyFunction<bool(CInputDevice const *const _this)>(0x1B933B0);
	static inline auto FOnLanguageChange = PreyFunction<void(CInputDevice *const _this)>(0xA13080);
	static inline auto FSetDeadZone = PreyFunction<void(CInputDevice *const _this, float fThreshold)>(0xA13080);
	static inline auto FRestoreDefaultDeadZone = PreyFunction<void(CInputDevice *const _this)>(0xA13080);
	static inline auto FNameToId = PreyFunction<unsigned(CInputDevice const *const _this, TKeyName const &name)>(0x9D8100);
	static inline auto FDevSpecIdToSymbol = PreyFunction<SInputSymbol *(CInputDevice const *const _this, unsigned devSpecId)>(0x9D7C10);
	static inline auto FMapSymbol = PreyFunction<SInputSymbol *(CInputDevice *const _this, unsigned deviceSpecificId, EKeyId keyId, TKeyName const &name, SInputSymbol::EType type, unsigned user)>(0x9D7E70);
};

