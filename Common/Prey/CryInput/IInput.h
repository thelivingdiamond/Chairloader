#pragma once
#include <vector>

enum EInputDeviceType
{
	eIDT_Keyboard = 0x0,
	eIDT_Mouse = 0x1,
	eIDT_Joystick = 0x2,
	eIDT_Gamepad = 0x3,
	eIDT_Unknown = 0xFF,
};

enum EInputState
{
	eIS_Unknown = 0x0,
	eIS_Pressed = 0x1,
	eIS_Released = 0x2,
	eIS_Down = 0x4,
	eIS_Changed = 0x8,
	eIS_UI = 0x10,
};

enum EKeyId
{
	eKI_Escape = 0x0,
	eKI_1 = 0x1,
	eKI_2 = 0x2,
	eKI_3 = 0x3,
	eKI_4 = 0x4,
	eKI_5 = 0x5,
	eKI_6 = 0x6,
	eKI_7 = 0x7,
	eKI_8 = 0x8,
	eKI_9 = 0x9,
	eKI_0 = 0xA,
	eKI_Minus = 0xB,
	eKI_Equals = 0xC,
	eKI_Backspace = 0xD,
	eKI_Tab = 0xE,
	eKI_Q = 0xF,
	eKI_W = 0x10,
	eKI_E = 0x11,
	eKI_R = 0x12,
	eKI_T = 0x13,
	eKI_Y = 0x14,
	eKI_U = 0x15,
	eKI_I = 0x16,
	eKI_O = 0x17,
	eKI_P = 0x18,
	eKI_LBracket = 0x19,
	eKI_RBracket = 0x1A,
	eKI_Enter = 0x1B,
	eKI_LCtrl = 0x1C,
	eKI_A = 0x1D,
	eKI_S = 0x1E,
	eKI_D = 0x1F,
	eKI_F = 0x20,
	eKI_G = 0x21,
	eKI_H = 0x22,
	eKI_J = 0x23,
	eKI_K = 0x24,
	eKI_L = 0x25,
	eKI_Semicolon = 0x26,
	eKI_Apostrophe = 0x27,
	eKI_Tilde = 0x28,
	eKI_LShift = 0x29,
	eKI_Backslash = 0x2A,
	eKI_Z = 0x2B,
	eKI_X = 0x2C,
	eKI_C = 0x2D,
	eKI_V = 0x2E,
	eKI_B = 0x2F,
	eKI_N = 0x30,
	eKI_M = 0x31,
	eKI_Comma = 0x32,
	eKI_Period = 0x33,
	eKI_Slash = 0x34,
	eKI_RShift = 0x35,
	eKI_NP_Multiply = 0x36,
	eKI_LAlt = 0x37,
	eKI_Space = 0x38,
	eKI_CapsLock = 0x39,
	eKI_F1 = 0x3A,
	eKI_F2 = 0x3B,
	eKI_F3 = 0x3C,
	eKI_F4 = 0x3D,
	eKI_F5 = 0x3E,
	eKI_F6 = 0x3F,
	eKI_F7 = 0x40,
	eKI_F8 = 0x41,
	eKI_F9 = 0x42,
	eKI_F10 = 0x43,
	eKI_NumLock = 0x44,
	eKI_ScrollLock = 0x45,
	eKI_NP_7 = 0x46,
	eKI_NP_8 = 0x47,
	eKI_NP_9 = 0x48,
	eKI_NP_Substract = 0x49,
	eKI_NP_4 = 0x4A,
	eKI_NP_5 = 0x4B,
	eKI_NP_6 = 0x4C,
	eKI_NP_Add = 0x4D,
	eKI_NP_1 = 0x4E,
	eKI_NP_2 = 0x4F,
	eKI_NP_3 = 0x50,
	eKI_NP_0 = 0x51,
	eKI_F11 = 0x52,
	eKI_F12 = 0x53,
	eKI_F13 = 0x54,
	eKI_F14 = 0x55,
	eKI_F15 = 0x56,
	eKI_Colon = 0x57,
	eKI_Underline = 0x58,
	eKI_NP_Enter = 0x59,
	eKI_RCtrl = 0x5A,
	eKI_NP_Period = 0x5B,
	eKI_NP_Divide = 0x5C,
	eKI_Print = 0x5D,
	eKI_RAlt = 0x5E,
	eKI_Pause = 0x5F,
	eKI_Home = 0x60,
	eKI_Up = 0x61,
	eKI_PgUp = 0x62,
	eKI_Left = 0x63,
	eKI_Right = 0x64,
	eKI_End = 0x65,
	eKI_Down = 0x66,
	eKI_PgDn = 0x67,
	eKI_Insert = 0x68,
	eKI_Delete = 0x69,
	eKI_LWin = 0x6A,
	eKI_RWin = 0x6B,
	eKI_Apps = 0x6C,
	eKI_OEM_102 = 0x6D,
	eKI_Mouse1 = 0x100,
	eKI_Mouse2 = 0x101,
	eKI_Mouse3 = 0x102,
	eKI_Mouse4 = 0x103,
	eKI_Mouse5 = 0x104,
	eKI_Mouse6 = 0x105,
	eKI_Mouse7 = 0x106,
	eKI_Mouse8 = 0x107,
	eKI_MouseWheelUp = 0x108,
	eKI_MouseWheelDown = 0x109,
	eKI_MouseX = 0x10A,
	eKI_MouseY = 0x10B,
	eKI_MouseZ = 0x10C,
	eKI_MouseXAbsolute = 0x10D,
	eKI_MouseYAbsolute = 0x10E,
	eKI_MouseLast = 0x10F,
	eKI_XI_DPadUp = 0x200,
	eKI_XI_DPadDown = 0x201,
	eKI_XI_DPadLeft = 0x202,
	eKI_XI_DPadRight = 0x203,
	eKI_XI_Start = 0x204,
	eKI_XI_Back = 0x205,
	eKI_XI_ThumbL = 0x206,
	eKI_XI_ThumbR = 0x207,
	eKI_XI_ShoulderL = 0x208,
	eKI_XI_ShoulderR = 0x209,
	eKI_XI_A = 0x20A,
	eKI_XI_B = 0x20B,
	eKI_XI_X = 0x20C,
	eKI_XI_Y = 0x20D,
	eKI_XI_TriggerL = 0x20E,
	eKI_XI_TriggerR = 0x20F,
	eKI_XI_ThumbLX = 0x210,
	eKI_XI_ThumbLY = 0x211,
	eKI_XI_ThumbLUp = 0x212,
	eKI_XI_ThumbLDown = 0x213,
	eKI_XI_ThumbLLeft = 0x214,
	eKI_XI_ThumbLRight = 0x215,
	eKI_XI_ThumbRX = 0x216,
	eKI_XI_ThumbRY = 0x217,
	eKI_XI_ThumbRUp = 0x218,
	eKI_XI_ThumbRDown = 0x219,
	eKI_XI_ThumbRLeft = 0x21A,
	eKI_XI_ThumbRRight = 0x21B,
	eKI_XI_TriggerLBtn = 0x21C,
	eKI_XI_TriggerRBtn = 0x21D,
	eKI_XI_Connect = 0x21E,
	eKI_XI_Disconnect = 0x21F,
	eKI_Orbis_Select = 0x400,
	eKI_Orbis_L3 = 0x401,
	eKI_Orbis_R3 = 0x402,
	eKI_Orbis_Start = 0x403,
	eKI_Orbis_Up = 0x404,
	eKI_Orbis_Right = 0x405,
	eKI_Orbis_Down = 0x406,
	eKI_Orbis_Left = 0x407,
	eKI_Orbis_L2 = 0x408,
	eKI_Orbis_R2 = 0x409,
	eKI_Orbis_L1 = 0x40A,
	eKI_Orbis_R1 = 0x40B,
	eKI_Orbis_Triangle = 0x40C,
	eKI_Orbis_Circle = 0x40D,
	eKI_Orbis_Cross = 0x40E,
	eKI_Orbis_Square = 0x40F,
	eKI_Orbis_StickLX = 0x410,
	eKI_Orbis_StickLY = 0x411,
	eKI_Orbis_StickRX = 0x412,
	eKI_Orbis_StickRY = 0x413,
	eKI_Orbis_RotX = 0x414,
	eKI_Orbis_RotY = 0x415,
	eKI_Orbis_RotZ = 0x416,
	eKI_Orbis_RotX_KeyL = 0x417,
	eKI_Orbis_RotX_KeyR = 0x418,
	eKI_Orbis_RotZ_KeyD = 0x419,
	eKI_Orbis_RotZ_KeyU = 0x41A,
	eKI_Orbis_Touch = 0x41B,
	eKI_SYS_Commit = 0x2000,
	eKI_SYS_ConnectDevice = 0x2001,
	eKI_SYS_DisconnectDevice = 0x2002,
	eKI_Unknown = 0xFFFFFFFF,
};

enum EModifierMask
{
	eMM_None = 0x0,
	eMM_LCtrl = 0x1,
	eMM_LShift = 0x2,
	eMM_LAlt = 0x4,
	eMM_LWin = 0x8,
	eMM_RCtrl = 0x10,
	eMM_RShift = 0x20,
	eMM_RAlt = 0x40,
	eMM_RWin = 0x80,
	eMM_NumLock = 0x100,
	eMM_CapsLock = 0x200,
	eMM_ScrollLock = 0x400,
	eMM_Ctrl = 0x11,
	eMM_Shift = 0x22,
	eMM_Alt = 0x44,
	eMM_Win = 0x88,
	eMM_Modifiers = 0xFF,
	eMM_LockKeys = 0x700,
};

struct TKeyName
{
	const char *key;
};

struct __declspec(align(8)) SInputSymbol
{
	enum EType
	{
		Button = 0x0,
		Toggle = 0x1,
		RawAxis = 0x2,
		Axis = 0x3,
		Trigger = 0x4,
	};

	const EKeyId keyId;
	const TKeyName name;
	const unsigned int devSpecId;
	EInputState state;
	const SInputSymbol::EType type;
	float value;
	unsigned int user;
	EInputDeviceType deviceType;
	unsigned __int8 deviceIndex;
};

struct SInputEvent
{
	EInputDeviceType deviceType;
	EInputState state;
	wchar_t inputChar;
	TKeyName keyName;
	EKeyId keyId;
	int modifiers;
	float value;
	SInputSymbol *pSymbol;
	unsigned __int8 deviceIndex;
};

struct SInputBlockData
{
	float fBlockDuration;
	const EKeyId keyId;
	unsigned __int8 deviceIndex;
	bool bAllDeviceIndices;
};


class IInputEventListener
{
public:
	virtual ~IInputEventListener() {};
	virtual bool OnInputEvent(const SInputEvent &) = 0;
	virtual bool OnInputEventUI(const SInputEvent &) = 0;
	virtual int GetPriority() = 0;
};

class ITouchEventListener;
class IKinectInput;
class INaturalPointInput;
enum EFFEffectId
{
    eFF_Rumble_Basic = 0,
    eFF_Rumble_Frame
};
struct SFFTriggerOutputData
{
    struct Initial
    {
        enum Value
        {
            ZeroIt = 0,
            Default
        };
    };

    struct Flags
    {
        enum Value
        {
            LeftTouchToActivate  = 1 << 0,
            RightTouchToActivate = 1 << 1,
        };
    };

    float  leftGain, rightGain;
    float  leftStrength, rightStrength;
    uint16 leftEnv, rightEnv;
    uint32 flags;

    SFFTriggerOutputData()  { Init(Initial::ZeroIt); }
    SFFTriggerOutputData(Initial::Value v)  { Init(v); }
    SFFTriggerOutputData(bool leftTouchToActivate, bool rightTouchToActivate, float lTrigger, float rTrigger, float lStrength, float rStrength, uint16 lTriggerEnv, uint16 rTriggerEnv) :
            leftGain(lTrigger), rightGain(rTrigger), leftStrength(lStrength), rightStrength(rStrength), leftEnv(lTriggerEnv), rightEnv(rTriggerEnv)
    {
        SetFlag(Flags::LeftTouchToActivate, leftTouchToActivate);
        SetFlag(Flags::RightTouchToActivate, rightTouchToActivate);
    }

    void Init(Initial::Value v)
    {
        if (v == Initial::ZeroIt)
        {
            flags = 0;
            leftGain = rightGain = 0.0f;
            leftStrength = rightStrength = 0.0f;
            leftEnv = rightEnv = 0;
        }
        else if (v == Initial::Default)
        {
            flags = 0;
            leftGain = rightGain = 1.0f;
            leftStrength = rightStrength = 0.0f;
            leftEnv = rightEnv = 4;
        }
    }

    void operator+=(const SFFTriggerOutputData& operand2)
    {
        leftGain += operand2.leftGain;
        rightGain += operand2.rightGain;
        // DARIO_TODO: check what to do with envelopes in this case
        leftEnv = max(leftEnv, operand2.leftEnv);
        rightEnv = max(rightEnv, operand2.rightEnv);
        // DARIO_TODO: check what to do with the touch required in this case
        SetFlag(Flags::LeftTouchToActivate, IsFlagEnabled(Flags::LeftTouchToActivate) || operand2.IsFlagEnabled(Flags::LeftTouchToActivate));
        SetFlag(Flags::RightTouchToActivate, IsFlagEnabled(Flags::RightTouchToActivate) || operand2.IsFlagEnabled(Flags::RightTouchToActivate));
    }

    ILINE float GetClampedLeftGain() const          { return clamp_tpl(leftGain, 0.0f, 1.0f); }
    ILINE float GetClampedRightGain() const         { return clamp_tpl(rightGain, 0.0f, 1.0f); }

    bool        IsFlagEnabled(Flags::Value f) const { return (flags & f) != 0; }

private:
    void EnableFlag(Flags::Value f)      { flags |= f; }
    void DisableFlag(Flags::Value f)     { flags &= ~f; }
    void SetFlag(Flags::Value f, bool b) { if (b) EnableFlag(f); else DisableFlag(f); }

};
struct IFFParams
{
    EInputDeviceType     deviceType;
    EFFEffectId          effectId;
    float                strengthA, strengthB;
    float                timeInSeconds;
    SFFTriggerOutputData triggerData;

    IFFParams() : strengthA(0), strengthB(0), timeInSeconds(0), triggerData(SFFTriggerOutputData::Initial::ZeroIt)
    {
        effectId = eFF_Rumble_Basic;
        deviceType = eIDT_Unknown;
    }
};struct STouchEvent;
struct SFFOutputEvent;

class IInputDevice
{
public:
	virtual ~IInputDevice() {};
	virtual const char *GetDeviceName() = 0;
	virtual EInputDeviceType GetDeviceType() = 0;
	virtual unsigned __int64 GetDeviceId() = 0;
	virtual int GetDeviceIndex() = 0;
	virtual bool Init() = 0;
	virtual void PostInit() = 0;
	virtual void Update(bool) = 0;
	virtual bool SetForceFeedback(IFFParams) = 0;
	virtual bool InputState(const TKeyName *, EInputState) = 0;
	virtual bool SetExclusiveMode(bool) = 0;
	virtual void ClearKeyState() = 0;
	virtual void ClearAnalogKeyState(std::vector<SInputSymbol *> *) = 0;
	virtual const char *GetKeyName(const EKeyId) = 0;
	virtual const char *GetKeyName(const SInputEvent *) = 0;
	virtual char GetInputCharAscii(const SInputEvent *) = 0;
	virtual const wchar_t *GetOSKeyName(const SInputEvent *) = 0;
	virtual SInputSymbol *LookupSymbol(EKeyId) = 0;
	virtual const SInputSymbol *GetSymbolByName(const char *) = 0;
	virtual bool IsOfDeviceType(EInputDeviceType) = 0;
	virtual void Enable(bool) = 0;
	virtual bool IsEnabled() = 0;
	virtual bool IsConnected() = 0;
	virtual void OnLanguageChange() = 0;
	virtual void SetDeadZone(float) = 0;
	virtual void RestoreDefaultDeadZone() = 0;
	virtual void ClearBufferedKeyState() = 0;
	virtual bool IsSteamInputDevice() = 0;
	virtual bool ShowBindingsPanel() = 0;
	virtual bool IsSteamInBigPictureMode() = 0;
	virtual unsigned int GetSteamActionOrigin(const char *const) = 0;
	virtual const char *GetGlyphFromActionOrigin(unsigned int) = 0;
	virtual void ActivateSteamActionSet(const char *const) = 0;
};

struct IInput
{
public:
	virtual ~IInput() = 0;
	virtual void AddEventListener(IInputEventListener *) = 0;
	virtual void RemoveEventListener(IInputEventListener *) = 0;
	virtual void AddConsoleEventListener(IInputEventListener *) = 0;
	virtual void RemoveConsoleEventListener(IInputEventListener *) = 0;
	virtual bool AddTouchEventListener(ITouchEventListener *, const char *) = 0;
	virtual void RemoveTouchEventListener(ITouchEventListener *) = 0;
	virtual void SetExclusiveListener(IInputEventListener *) = 0;
	virtual IInputEventListener *GetExclusiveListener() = 0;
	virtual bool AddInputDevice(IInputDevice *) = 0;
	virtual void EnableEventPosting(bool) = 0;
	virtual bool IsEventPostingEnabled() = 0;
	virtual void PostInputEvent(const SInputEvent *, bool) = 0;
	virtual void PostTouchEvent(const STouchEvent *, bool) = 0;
	virtual void ProcessKey(unsigned int, bool, wchar_t, bool) = 0;
	virtual void ForceFeedbackEvent(const SFFOutputEvent *) = 0;
	virtual void ForceFeedbackSetDeviceIndex(int) = 0;
	virtual bool Init() = 0;
	virtual void PostInit() = 0;
	virtual void Update(bool) = 0;
	virtual void ShutDown() = 0;
	virtual void SetExclusiveMode(EInputDeviceType, bool, void *) = 0;
	virtual bool InputState(const TKeyName *, EInputState) = 0;
	virtual const char *GetKeyName(EKeyId) = 0;
	virtual const char *GetKeyName(const SInputEvent *) = 0;
	virtual char GetInputCharAscii(const SInputEvent *) = 0;
	virtual SInputSymbol *LookupSymbol(EInputDeviceType, int, EKeyId) = 0;
	virtual const SInputSymbol *LookupSymbolByName(EInputDeviceType, int, const char *) = 0;
	virtual const SInputSymbol *GetSymbolByName(const char *) = 0;
	virtual const wchar_t *GetOSKeyName(const SInputEvent *) = 0;
	virtual void ClearKeyState() = 0;
	virtual void ClearAnalogKeyState() = 0;
	virtual void RetriggerKeyState() = 0;
	virtual bool Retriggering() = 0;
	virtual bool HasInputDeviceOfType(EInputDeviceType) = 0;
	virtual bool HasGamepadConnected() = 0;
	virtual void RefreshDevices() = 0;
	virtual int GetModifiers() = 0;
	virtual void EnableDevice(EInputDeviceType, bool) = 0;
	virtual void SetDeadZone(float) = 0;
	virtual void RestoreDefaultDeadZone() = 0;
	virtual IInputDevice *GetDevice(unsigned __int64) = 0;
	virtual IInputDevice *GetDevice(unsigned __int16, EInputDeviceType) = 0;
	virtual unsigned int GetPlatformFlags() = 0;
	virtual bool SetBlockingInput(const SInputBlockData *) = 0;
	virtual bool RemoveBlockingInput(const SInputBlockData *) = 0;
	virtual bool HasBlockingInput(const SInputBlockData *) = 0;
	virtual int GetNumBlockingInputs() = 0;
	virtual void ClearBlockingInputs() = 0;
	virtual bool ShouldBlockInputEventPosting(const EKeyId, const EInputDeviceType, const unsigned __int8) = 0;
	virtual IKinectInput *GetKinectInput() = 0;
	virtual INaturalPointInput *GetNaturalPointInput() = 0;
	virtual bool GrabInput(bool) = 0;
	virtual IInputDevice *GetSteamInputDevice() = 0;
};