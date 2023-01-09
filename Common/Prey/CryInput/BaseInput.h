#pragma once
#include <list>
#include <Prey/CryCore/Containers/CryListenerSet.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CryInput/IInput.h>
class CInputCVars;
class CKinectInputNULL;
struct CNaturalPointInputNull;
struct IInputDevice;
struct IInputEventListener;
struct IKinectInput;
struct INaturalPointInput;
struct ITouchEventListener;
struct SFFOutputEvent;
struct SInputBlockData;
struct SInputEvent;
struct SInputSymbol;
struct STouchEvent;
struct TKeyName;

// Header: Exact
// CryEngine/cryinput/baseinput.h
class CBaseInput : public IInput, public ISystemEventListener // Id=800D045 Size=264
{
public:
    using TInputDevices = std::vector<IInputDevice *>;
    using TInputEventListeners = std::list<IInputEventListener *,std::allocator<IInputEventListener *> >;

    std::vector<SInputSymbol *> m_holdSymbols;
    std::list<IInputEventListener *,std::allocator<IInputEventListener *> > m_listeners;
    std::list<IInputEventListener *,std::allocator<IInputEventListener *> > m_consoleListeners;
    IInputEventListener *m_pExclusiveListener;
    CListenerSet<ITouchEventListener *> m_touchListeners;
    bool m_enableEventPosting;
    bool m_retriggering;
    CryCriticalSection m_postInputEventMutex;
    bool m_hasFocus;
    std::vector<IInputDevice *> m_inputDevices;
    int m_forceFeedbackDeviceIndex;

    using TInputBlockData = std::list<SInputBlockData,std::allocator<SInputBlockData> >;

    std::list<SInputBlockData,std::allocator<SInputBlockData> > m_inputBlockData;
    int m_modifiers;
    CInputCVars *m_pCVars;
    CKinectInputNULL *m_pKinectInput;
    CNaturalPointInputNull *m_pNaturalPointInput;
    unsigned m_platformFlags;

    CBaseInput();
    virtual ~CBaseInput();
    virtual bool Init();
    virtual void PostInit();
    virtual void Update(bool bFocus);
    virtual void ShutDown();
    virtual void SetExclusiveMode(EInputDeviceType deviceType, bool exclusive, void *pUser);
    virtual bool InputState(TKeyName const &keyName, EInputState state);
    virtual const char *GetKeyName(SInputEvent const &event) const;
    virtual const char *GetKeyName(EKeyId keyId) const;
    virtual char GetInputCharAscii(SInputEvent const &event);
    virtual SInputSymbol *LookupSymbol(EInputDeviceType deviceType, int deviceIndex, EKeyId keyId);
    virtual SInputSymbol const *LookupSymbolByName(EInputDeviceType deviceType, int deviceIndex, const char *name) const;
    virtual SInputSymbol const *GetSymbolByName(const char *name) const;
    virtual const wchar_t *GetOSKeyName(SInputEvent const &event);
    virtual void ClearKeyState();
    virtual void ClearAnalogKeyState();
    virtual void RetriggerKeyState();
    virtual bool Retriggering();
    virtual bool HasInputDeviceOfType(EInputDeviceType type);
    virtual bool HasGamepadConnected();
    virtual void RefreshDevices();
    virtual void SetDeadZone(float fThreshold);
    virtual void RestoreDefaultDeadZone();
    virtual IInputDevice *GetDevice(uint16_t id, EInputDeviceType deviceType);
    virtual IInputDevice *GetDevice(uint64_t deviceId);
    virtual void AddEventListener(IInputEventListener *pListener);
    virtual void RemoveEventListener(IInputEventListener *pListener);
    virtual bool AddTouchEventListener(ITouchEventListener *pListener, const char *name);
    virtual void RemoveTouchEventListener(ITouchEventListener *pListener);
    virtual void AddConsoleEventListener(IInputEventListener *pListener);
    virtual void RemoveConsoleEventListener(IInputEventListener *pListener);
    virtual void SetExclusiveListener(IInputEventListener *pListener);
    virtual IInputEventListener *GetExclusiveListener();
    virtual bool AddInputDevice(IInputDevice *pDevice);
    virtual void EnableEventPosting(bool bEnable);
    virtual bool IsEventPostingEnabled() const;
    virtual void PostInputEvent(SInputEvent const &event, bool bForce);
    virtual void PostTouchEvent(STouchEvent const &event, bool bForce);
    virtual void ForceFeedbackEvent(SFFOutputEvent const &event);
    virtual void ForceFeedbackSetDeviceIndex(int index);
    virtual void EnableDevice(EInputDeviceType deviceType, bool enable);
    virtual void ProcessKey(unsigned key, bool pressed, wchar_t unicode, bool repeat);
    virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
    virtual int GetModifiers() const;
    virtual unsigned GetPlatformFlags() const;
    virtual bool SetBlockingInput(SInputBlockData const &inputBlockData);
    virtual bool RemoveBlockingInput(SInputBlockData const &inputBlockData);
    virtual bool HasBlockingInput(SInputBlockData const &inputBlockData) const;
    virtual int GetNumBlockingInputs() const;
    virtual void ClearBlockingInputs();
    virtual bool ShouldBlockInputEventPosting(EKeyId keyId, EInputDeviceType deviceType, const uint8_t deviceIndex) const;
    virtual IKinectInput *GetKinectInput();
    virtual INaturalPointInput *GetNaturalPointInput();
    virtual IInputDevice *GetSteamInputDevice();
    virtual bool GrabInput(bool bGrab);
    void ClearHoldEvent(SInputSymbol *pSymbol) { FClearHoldEvent(this,pSymbol); }
    bool SendEventToListeners(SInputEvent const &event) { return FSendEventToListeners(this,event); }

#if 0
    bool HasFocus() const;
	void SetModifiers(int arg0);
	void UpdateBlockingInputs();
	void PostHoldEvents();
	void AddEventToHoldSymbols(SInputEvent const &arg0);
	void RemoveDeviceHoldSymbols(EInputDeviceType arg0, uint8_t arg1);
#endif

    static inline auto FBitNotCBaseInput = PreyFunction<void(CBaseInput *const _this)>(0x9D4530);
    static inline auto FInit = PreyFunction<bool(CBaseInput *const _this)>(0x9D5510);
    static inline auto FPostInit = PreyFunction<void(CBaseInput *const _this)>(0x9D5880);
    static inline auto FUpdate = PreyFunction<void(CBaseInput *const _this, bool bFocus)>(0x9D63F0);
    static inline auto FShutDown = PreyFunction<void(CBaseInput *const _this)>(0x9D6360);
    static inline auto FSetExclusiveMode = PreyFunction<void(CBaseInput *const _this, EInputDeviceType deviceType, bool exclusive, void *pUser)>(0x9D6250);
    static inline auto FInputState = PreyFunction<bool(CBaseInput *const _this, TKeyName const &keyName, EInputState state)>(0x9D5590);
    static inline auto FGetKeyNameOv1 = PreyFunction<const char *(CBaseInput const *const _this, SInputEvent const &event)>(0x9D5190);
    static inline auto FGetKeyNameOv0 = PreyFunction<const char *(CBaseInput const *const _this, EKeyId keyId)>(0x9D5220);
    static inline auto FGetInputCharAscii = PreyFunction<char(CBaseInput *const _this, SInputEvent const &event)>(0x9D5110);
    static inline auto FLookupSymbol = PreyFunction<SInputSymbol *(CBaseInput *const _this, EInputDeviceType deviceType, int deviceIndex, EKeyId keyId)>(0x9D5610);
    static inline auto FLookupSymbolByName = PreyFunction<SInputSymbol const *(CBaseInput const *const _this, EInputDeviceType deviceType, int deviceIndex, const char *name)>(0x9D56D0);
    static inline auto FGetSymbolByName = PreyFunction<SInputSymbol const *(CBaseInput const *const _this, const char *name)>(0x9D5370);
    static inline auto FGetOSKeyName = PreyFunction<const wchar_t *(CBaseInput *const _this, SInputEvent const &event)>(0x9D5280);
    static inline auto FClearKeyState = PreyFunction<void(CBaseInput *const _this)>(0x9D4D80);
    static inline auto FClearAnalogKeyState = PreyFunction<void(CBaseInput *const _this)>(0x9D4A50);
    static inline auto FRetriggerKeyState = PreyFunction<void(CBaseInput *const _this)>(0x9D5E50);
    static inline auto FRetriggering = PreyFunction<bool(CBaseInput *const _this)>(0x10B3A80);
    static inline auto FHasInputDeviceOfType = PreyFunction<bool(CBaseInput *const _this, EInputDeviceType type)>(0x9D5490);
    static inline auto FHasGamepadConnected = PreyFunction<bool(CBaseInput *const _this)>(0x9D5410);
    static inline auto FRefreshDevices = PreyFunction<void(CBaseInput *const _this)>(0xA13080);
    static inline auto FSetDeadZone = PreyFunction<void(CBaseInput *const _this, float fThreshold)>(0x9D61B0);
    static inline auto FRestoreDefaultDeadZone = PreyFunction<void(CBaseInput *const _this)>(0x9D5DC0);
    static inline auto FGetDeviceOv1 = PreyFunction<IInputDevice *(CBaseInput *const _this, uint16_t id, EInputDeviceType deviceType)>(0x9D5080);
    static inline auto FGetDeviceOv0 = PreyFunction<IInputDevice *(CBaseInput *const _this, uint64_t deviceId)>(0x158AEF0);
    static inline auto FAddEventListener = PreyFunction<void(CBaseInput *const _this, IInputEventListener *pListener)>(0x9D48C0);
    static inline auto FRemoveEventListener = PreyFunction<void(CBaseInput *const _this, IInputEventListener *pListener)>(0x9D5D00);
    static inline auto FAddTouchEventListener = PreyFunction<bool(CBaseInput *const _this, ITouchEventListener *pListener, const char *name)>(0x9D4A00);
    static inline auto FRemoveTouchEventListener = PreyFunction<void(CBaseInput *const _this, ITouchEventListener *pListener)>(0x9D5D50);
    static inline auto FAddConsoleEventListener = PreyFunction<void(CBaseInput *const _this, IInputEventListener *pListener)>(0x9D47E0);
    static inline auto FRemoveConsoleEventListener = PreyFunction<void(CBaseInput *const _this, IInputEventListener *pListener)>(0x983630);
    static inline auto FSetExclusiveListener = PreyFunction<void(CBaseInput *const _this, IInputEventListener *pListener)>(0x17D3400);
    static inline auto FGetExclusiveListener = PreyFunction<IInputEventListener *(CBaseInput *const _this)>(0x1A1FF50);
    static inline auto FAddInputDevice = PreyFunction<bool(CBaseInput *const _this, IInputDevice *pDevice)>(0x9D49A0);
    static inline auto FEnableEventPosting = PreyFunction<void(CBaseInput *const _this, bool bEnable)>(0x9D4EB0);
    static inline auto FIsEventPostingEnabled = PreyFunction<bool(CBaseInput const *const _this)>(0x9D5600);
    static inline auto FPostInputEvent = PreyFunction<void(CBaseInput *const _this, SInputEvent const &event, bool bForce)>(0x9D58D0);
    static inline auto FPostTouchEvent = PreyFunction<void(CBaseInput *const _this, STouchEvent const &event, bool bForce)>(0x9D5B70);
    static inline auto FForceFeedbackEvent = PreyFunction<void(CBaseInput *const _this, SFFOutputEvent const &event)>(0x9D4EF0);
    static inline auto FForceFeedbackSetDeviceIndex = PreyFunction<void(CBaseInput *const _this, int index)>(0x9D5020);
    static inline auto FEnableDevice = PreyFunction<void(CBaseInput *const _this, EInputDeviceType deviceType, bool enable)>(0x9D4E20);
    static inline auto FProcessKey = PreyFunction<void(CBaseInput *const _this, unsigned key, bool pressed, wchar_t unicode, bool repeat)>(0xA13080);
    static inline auto FOnSystemEvent = PreyFunction<void(CBaseInput *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x9D5770);
    static inline auto FGetModifiers = PreyFunction<int(CBaseInput const *const _this)>(0x9D0520);
    static inline auto FGetPlatformFlags = PreyFunction<unsigned(CBaseInput const *const _this)>(0x9D0530);
    static inline auto FSetBlockingInput = PreyFunction<bool(CBaseInput *const _this, SInputBlockData const &inputBlockData)>(0x9D60C0);
    static inline auto FRemoveBlockingInput = PreyFunction<bool(CBaseInput *const _this, SInputBlockData const &inputBlockData)>(0x9D5C90);
    static inline auto FHasBlockingInput = PreyFunction<bool(CBaseInput const *const _this, SInputBlockData const &inputBlockData)>(0x9D53D0);
    static inline auto FGetNumBlockingInputs = PreyFunction<int(CBaseInput const *const _this)>(0x9D5270);
    static inline auto FClearBlockingInputs = PreyFunction<void(CBaseInput *const _this)>(0x9D4C60);
    static inline auto FShouldBlockInputEventPosting = PreyFunction<bool(CBaseInput const *const _this, EKeyId keyId, EInputDeviceType deviceType, const uint8_t deviceIndex)>(0x9D6330);
    static inline auto FGetKinectInput = PreyFunction<IKinectInput *(CBaseInput *const _this)>(0x833BD0);
    static inline auto FGetNaturalPointInput = PreyFunction<INaturalPointInput *(CBaseInput *const _this)>(0x36CFD0);
    static inline auto FGetSteamInputDevice = PreyFunction<IInputDevice *(CBaseInput *const _this)>(0x9D52F0);
    static inline auto FGrabInput = PreyFunction<bool(CBaseInput *const _this, bool bGrab)>(0xDD23F0);
    static inline auto FClearHoldEvent = PreyFunction<void(CBaseInput *const _this, SInputSymbol *pSymbol)>(0x9D4CC0);
    static inline auto FSendEventToListeners = PreyFunction<bool(CBaseInput *const _this, SInputEvent const &event)>(0x9D5FD0);
};

