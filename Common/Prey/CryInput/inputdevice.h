// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/CryInput/InputDevice.h>

struct IInput;
struct SInputEvent;
struct TKeyName;

// CInputDevice
// Header:  CryEngine/cryinput/InputDevice.h
// Include: Prey/CryInput/InputDevice.h
class CInputDevice : public IInputDevice
{ // Size=112 (0x70)
public:
	using TNameToIdMap = std::map<TKeyName, unsigned int>;
	using TNameToSymbolMap = std::map<TKeyName, SInputSymbol*>;
	using TIdToSymbolMap = std::map<enum::EKeyId, SInputSymbol*>;
	using TDevSpecIdToSymbolMap = std::map<unsigned int, SInputSymbol*>;
	
	EInputDeviceType m_deviceType = eIDT_Unknown;
	uint64_t m_deviceId = 0;
	bool m_enabled = true;
	IInput& m_input;
	string m_deviceName;
	std::map<TKeyName, unsigned int> m_nameToId;
	std::map<TKeyName, SInputSymbol*> m_nameToInfo;
	std::map<enum::EKeyId, SInputSymbol*> m_idToInfo;
	std::map<unsigned int, SInputSymbol*> m_devSpecIdToSymbol;
	
	CInputDevice(IInput& input, const char* deviceName) : m_input(input)
	{
		m_deviceName = deviceName;
	}

	virtual ~CInputDevice()
	{
		while (m_idToInfo.size())
		{
			TIdToSymbolMap::iterator iter = m_idToInfo.begin();
			SInputSymbol* pSymbol = (*iter).second;
			m_idToInfo.erase(iter);
			SAFE_DELETE(pSymbol);
		}
	}

	virtual const char* GetDeviceName() const { return FGetDeviceName(this); }
	virtual bool IsOfDeviceType(EInputDeviceType type) const { return FIsOfDeviceType(this, type); }
	virtual EInputDeviceType GetDeviceType() const { return FGetDeviceType(this); }
	virtual uint64_t GetDeviceId() const { return FGetDeviceId(this); }
	virtual bool Init() { return FInit(this); }
	virtual void PostInit() { FPostInit(this); }
	virtual void Update(bool bFocus) { FUpdate(this, bFocus); }
	virtual bool SetForceFeedback(IFFParams params) { return FSetForceFeedback(this, params); }
	virtual bool InputState(const TKeyName& keyName, EInputState state) { return FInputState(this, keyName, state); }
	virtual bool SetExclusiveMode(bool value) { return FSetExclusiveMode(this, value); }
	virtual void ClearKeyState() { FClearKeyState(this); }
	virtual void ClearAnalogKeyState(std::vector<SInputSymbol*>& clearedSymbols) { FClearAnalogKeyState(this, clearedSymbols); }
	virtual const char* GetKeyName(const SInputEvent& event) const { return FGetKeyNameOv1(this, event); }
	virtual const char* GetKeyName(const EKeyId keyId) const { return FGetKeyNameOv0(this, keyId); }
	virtual char GetInputCharAscii(const SInputEvent& event) { return FGetInputCharAscii(this, event); }
	virtual const wchar_t* GetOSKeyName(const SInputEvent& event) { return FGetOSKeyName(this, event); }
	virtual SInputSymbol* LookupSymbol(EKeyId id) const { return FLookupSymbol(this, id); }
	virtual const SInputSymbol* GetSymbolByName(const char* name) const { return FGetSymbolByName(this, name); }
	virtual void Enable(bool enable) { FEnable(this, enable); }
	virtual bool IsEnabled() const { return FIsEnabled(this); }
	virtual bool IsConnected() const { return FIsConnected(this); }
	virtual void OnLanguageChange() { FOnLanguageChange(this); }
	virtual void SetDeadZone(float fThreshold) { FSetDeadZone(this, fThreshold); }
	virtual void RestoreDefaultDeadZone() { FRestoreDefaultDeadZone(this); }
	unsigned NameToId(const TKeyName& name) const { return FNameToId(this, name); }
	SInputSymbol* DevSpecIdToSymbol(unsigned devSpecId) const { return FDevSpecIdToSymbol(this, devSpecId); }
	SInputSymbol* MapSymbol(unsigned deviceSpecificId, EKeyId keyId, const TKeyName& name, SInputSymbol::EType type, unsigned user) { return FMapSymbol(this, deviceSpecificId, keyId, name, type, user); }
	
#if 0
	IInput& GetIInput() const;
	SInputSymbol* IdToSymbol(EKeyId _arg0_) const;
	SInputSymbol* NameToSymbol(const TKeyName& _arg0_) const;
#endif
	
	static inline auto FCInputDeviceOv1 = PreyFunction<void(CInputDevice* const _this, IInput& input, const char* deviceName)>(0x9D7830);
	static inline auto FBitNotCInputDevice = PreyFunction<void(CInputDevice* const _this)>(0x9D7940);
	static inline auto FGetDeviceName = PreyFunction<const char* (const CInputDevice* const _this)>(0xD87510);
	static inline auto FIsOfDeviceType = PreyFunction<bool(const CInputDevice* const _this, EInputDeviceType type)>(0x9D0A00);
	static inline auto FGetDeviceType = PreyFunction<EInputDeviceType(const CInputDevice* const _this)>(0xEEBB60);
	static inline auto FGetDeviceId = PreyFunction<uint64_t(const CInputDevice* const _this)>(0x5BFB50);
	static inline auto FInit = PreyFunction<bool(CInputDevice* const _this)>(0x1B933B0);
	static inline auto FPostInit = PreyFunction<void(CInputDevice* const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CInputDevice* const _this, bool bFocus)>(0xA13080);
	static inline auto FSetForceFeedback = PreyFunction<bool(CInputDevice* const _this, IFFParams params)>(0xDD23F0);
	static inline auto FInputState = PreyFunction<bool(CInputDevice* const _this, const TKeyName& keyName, EInputState state)>(0x9D7D70);
	static inline auto FSetExclusiveMode = PreyFunction<bool(CInputDevice* const _this, bool value)>(0x1B933B0);
	static inline auto FClearKeyState = PreyFunction<void(CInputDevice* const _this)>(0x9D7B10);
	static inline auto FClearAnalogKeyState = PreyFunction<void(CInputDevice* const _this, std::vector<SInputSymbol*>& clearedSymbols)>(0xA13080);
	static inline auto FGetKeyNameOv1 = PreyFunction<const char* (const CInputDevice* const _this, const SInputEvent& event)>(0x9D7C60);
	static inline auto FGetKeyNameOv0 = PreyFunction<const char* (const CInputDevice* const _this, const EKeyId keyId)>(0x9D7C70);
	static inline auto FGetInputCharAscii = PreyFunction<char(CInputDevice* const _this, const SInputEvent& event)>(0xDD23F0);
	static inline auto FGetOSKeyName = PreyFunction<const wchar_t* (CInputDevice* const _this, const SInputEvent& event)>(0x9D7CC0);
	static inline auto FLookupSymbol = PreyFunction<SInputSymbol* (const CInputDevice* const _this, EKeyId id)>(0x9D7E20);
	static inline auto FGetSymbolByName = PreyFunction<const SInputSymbol* (const CInputDevice* const _this, const char* name)>(0x9D7CD0);
	static inline auto FEnable = PreyFunction<void(CInputDevice* const _this, bool enable)>(0x12BE0F0);
	static inline auto FIsEnabled = PreyFunction<bool(const CInputDevice* const _this)>(0x1141F10);
	static inline auto FIsConnected = PreyFunction<bool(const CInputDevice* const _this)>(0x1B933B0);
	static inline auto FOnLanguageChange = PreyFunction<void(CInputDevice* const _this)>(0xA13080);
	static inline auto FSetDeadZone = PreyFunction<void(CInputDevice* const _this, float fThreshold)>(0xA13080);
	static inline auto FRestoreDefaultDeadZone = PreyFunction<void(CInputDevice* const _this)>(0xA13080);
	static inline auto FNameToId = PreyFunction<unsigned(const CInputDevice* const _this, const TKeyName& name)>(0x9D8100);
	static inline auto FDevSpecIdToSymbol = PreyFunction<SInputSymbol* (const CInputDevice* const _this, unsigned devSpecId)>(0x9D7C10);
	static inline auto FMapSymbol = PreyFunction<SInputSymbol* (CInputDevice* const _this, unsigned deviceSpecificId, EKeyId keyId, const TKeyName& name, SInputSymbol::EType type, unsigned user)>(0x9D7E70);
};

