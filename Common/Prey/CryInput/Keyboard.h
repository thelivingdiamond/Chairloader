// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/dxinputdevice.h>
#include <Prey/CryInput/Keyboard.h>

class CDXInput;
struct SInputEvent;
struct SInputSymbol;

// Header: FromCpp
// CryEngine/cryinput/keyboard.h
class CKeyboard : public CDXInputDevice // Id=800D0A8 Size=152
{
public:
    struct SScanCode // Id=800D0AA Size=12
    {
        char lc;
        char uc;
        char ac;
        char cl;
        wchar_t wlc;
        wchar_t wuc;
        wchar_t wac;
        wchar_t wcl;
    };

    static inline auto m_scanCodes = PreyGlobal<CKeyboard::SScanCode [256]>(0x2766760);
    static inline auto Symbol = PreyGlobal<SInputSymbol *[256]>(0x2767360);

    CKeyboard(CDXInput &input);
    virtual int GetDeviceIndex() const;
    virtual bool Init();
    virtual void Update(bool bFocus);
    virtual bool SetExclusiveMode(bool value);
    virtual void ClearKeyState();
    virtual char GetInputCharAscii(SInputEvent const &event);
    virtual const wchar_t *GetOSKeyName(SInputEvent const &event);
    virtual void OnLanguageChange();
    virtual void ClearBufferedKeyState();
    void SetupKeyNames() { FSetupKeyNames(this); }
    virtual ~CKeyboard();

#if 0
    uint8_t Event2ASCII(SInputEvent const &arg0);
	wchar_t Event2Unicode(SInputEvent const &arg0);
	uint8_t ToAscii(unsigned arg0, unsigned arg1, uint8_t *arg2) const;
	wchar_t ToUnicode(unsigned arg0, unsigned arg1, uint8_t *arg2) const;
	void ProcessKey(unsigned arg0, bool arg1);
#endif

    static inline auto FGetDeviceIndex = PreyFunction<int(CKeyboard const *const _this)>(0x158AEF0);
    static inline auto FInit = PreyFunction<bool(CKeyboard *const _this)>(0x9D1010);
    static inline auto FUpdate = PreyFunction<void(CKeyboard *const _this, bool bFocus)>(0x9D2DA0);
    static inline auto FSetExclusiveMode = PreyFunction<bool(CKeyboard *const _this, bool value)>(0x9D1080);
    static inline auto FClearKeyState = PreyFunction<void(CKeyboard *const _this)>(0x9D0B10);
    static inline auto FGetInputCharAscii = PreyFunction<char(CKeyboard *const _this, SInputEvent const &event)>(0x9D0BB0);
    static inline auto FGetOSKeyName = PreyFunction<const wchar_t *(CKeyboard *const _this, SInputEvent const &event)>(0x9D0D10);
    static inline auto FOnLanguageChange = PreyFunction<void(CKeyboard *const _this)>(0x9D1070);
    static inline auto FClearBufferedKeyState = PreyFunction<void(CKeyboard *const _this)>(0x9D0AD0);
    static inline auto FSetupKeyNames = PreyFunction<void(CKeyboard *const _this)>(0x9D1150);
};

