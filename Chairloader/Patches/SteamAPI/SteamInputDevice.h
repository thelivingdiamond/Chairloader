#pragma once
#include <Prey/CryInput/inputdevice.h>
#include <Chairloader/SteamAPI/IChairSteamAPI.h>

class SteamInputDevice : public CInputDevice
{
public:
    SteamInputDevice(IInput& input);
    ~SteamInputDevice();

    // CInputDevice
    virtual int GetDeviceIndex() const override { return 0; } //Assume only one device of this type
    virtual bool Init() override;
    virtual void Update(bool bFocus) override;
    virtual bool SetForceFeedback(IFFParams params) override;
    virtual bool SetExclusiveMode(bool value) override;
    virtual void ClearKeyState() override;
    virtual bool IsOfDeviceType(EInputDeviceType type) const override;
    virtual bool IsConnected() const override;
    virtual void ClearBufferedKeyState() override;
    virtual bool IsSteamInputDevice() const override;
    virtual bool ShowBindingsPanel() const override;
    virtual bool IsSteamInBigPictureMode() const override;
    virtual unsigned GetSteamActionOrigin(const char* const _szActionName) const override;
    virtual const char* GetGlyphFromActionOrigin(unsigned _actionOrigin) const override;
    virtual void ActivateSteamActionSet(const char* const _szActionSetName) override;

private:
    struct DigitalAction
    {
        ControllerDigitalActionHandle_t hAction = 0;
        SInputSymbol* pSymbol = nullptr;
        bool isReset = false;
    };

    struct AnalogAction
    {
        ControllerAnalogActionHandle_t hAction = 0;
        SInputSymbol* pSymbolX = nullptr;
        SInputSymbol* pSymbolY = nullptr;
    };

    struct ActionByName
    {
        unsigned index = 0;
        bool isAnalog = false;
    };

    std::vector<DigitalAction> m_DigitalActions;
    std::vector<AnalogAction> m_AnalogActions;
    std::vector<ControllerActionSetHandle_t> m_ActionSets;
    std::map<std::string, ActionByName, std::less<>> m_Actions;

    ControllerHandle_t m_hConnectedControllers[STEAM_CONTROLLER_MAX_COUNT] = {};
    ControllerHandle_t m_hCurrentController = 0;
    ControllerActionSetHandle_t m_hCurrentActionSet = 0;
    EControllerActionOrigin m_nCurrentActionOrigin = k_EControllerActionOrigin_None;

    float m_basicLeftMotorRumble = 0.0f, m_basicRightMotorRumble = 0.0f;
    float m_frameLeftMotorRumble = 0.0f, m_frameRightMotorRumble = 0.0f;
    float m_fVibrationTimer = 0.0f;

    bool m_bInitialized = false;

    float GetClampedLeftMotorAccumulatedVibration() const { return clamp_tpl(m_basicLeftMotorRumble + m_frameLeftMotorRumble, 0.0f, 65535.0f); }
    float GetClampedRightMotorAccumulatedVibration() const { return clamp_tpl(m_basicRightMotorRumble + m_frameRightMotorRumble, 0.0f, 65535.0f); }

    void SetVibration(uint16 leftMotor, uint16 rightMotor, float timing, EFFEffectId effectId);
};
