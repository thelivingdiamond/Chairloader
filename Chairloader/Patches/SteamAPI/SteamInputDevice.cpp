#include "SteamInputDevice.h"

struct AnalogActionName
{
    SInputSymbol::EType type = SInputSymbol::Button;
    const char* main = nullptr;
    const char* x = nullptr;
    const char* y = nullptr;
};

constexpr const char* g_DigitalActions[] =
{
    "game:sc_start",
    "game:sc_back",
    "game:sc_dpad_up",
    "game:sc_dpad_down",
    "game:sc_dpad_left",
    "game:sc_dpad_right",
    "game:sc_a",
    "game:sc_b",
    "game:sc_x",
    "game:sc_y",
    "game:sc_l1",
    "game:sc_r1",
    "game:sc_l2",
    "game:sc_r2",
    "game:sc_l3",
    "game:sc_r3",
    "menu:sc_start",
    "menu:sc_back",
    "menu:sc_dpad_up",
    "menu:sc_dpad_down",
    "menu:sc_dpad_left",
    "menu:sc_dpad_right",
    "menu:sc_a",
    "menu:sc_b",
    "menu:sc_x",
    "menu:sc_y",
    "menu:sc_l1",
    "menu:sc_r1",
    "menu:sc_l2",
    "menu:sc_r2",
    "menu:sc_l3",
    "menu:sc_r3",
};

constexpr AnalogActionName g_AnalogActions[] =
{
    AnalogActionName { SInputSymbol::Axis, "game:sc_stickl", "game:sc_sticklx", "game:sc_stickly" },
    AnalogActionName { SInputSymbol::Axis, "game:sc_stickr", "game:sc_stickrx", "game:sc_stickry" },
    AnalogActionName { SInputSymbol::Axis, "game:sc_stickaim", "game:sc_stickaimx", "game:sc_stickaimy" } ,
    AnalogActionName { SInputSymbol::Trigger, "game:sc_triggerl" },
    AnalogActionName { SInputSymbol::Trigger, "game:sc_triggerr" },

    AnalogActionName { SInputSymbol::Axis, "menu:sc_stickl", "menu:sc_sticklx", "menu:sc_stickly" },
    AnalogActionName { SInputSymbol::Axis, "menu:sc_stickr", "menu:sc_stickrx", "menu:sc_stickry" },
    AnalogActionName { SInputSymbol::Trigger, "menu:sc_triggerl" },
    AnalogActionName { SInputSymbol::Trigger, "menu:sc_triggerr" },
};

constexpr const char* g_ActionSets[] =
{
    "game",
    "menu",
};

SteamInputDevice::SteamInputDevice(IInput& input)
    : CInputDevice(input, "steamcontroller")
{
    m_deviceType = eIDT_Gamepad;
}

SteamInputDevice::~SteamInputDevice()
{
    if (m_bInitialized)
    {
        SetVibration(0, 0, 0.0f, eFF_Rumble_Basic);
        SteamController()->Shutdown();
    }
}

bool SteamInputDevice::Init()
{
    if (!SteamController()->Init())
        return false;

    m_bInitialized = true;
    m_DigitalActions.resize(std::size(g_DigitalActions));

    int nextKeyId = eKI_SteamControllerBegin;

    for (size_t actionIdx = 0; actionIdx < std::size(g_DigitalActions); actionIdx++)
    {
        DigitalAction& action = m_DigitalActions[actionIdx];
        ControllerDigitalActionHandle_t hAction = SteamController()->GetDigitalActionHandle(g_DigitalActions[actionIdx]);

        if (!hAction)
        {
            CryError("[SteamController] Failed to bind digital action handle '{}'[{}]", g_DigitalActions[actionIdx], actionIdx);
            continue;
        }

        action.hAction = hAction;
        action.pSymbol = MapSymbol(actionIdx, (EKeyId)nextKeyId, { g_DigitalActions[actionIdx] }, SInputSymbol::Button, 0);
        nextKeyId++;

        m_Actions[g_DigitalActions[actionIdx]] = ActionByName{ (unsigned)actionIdx, false };
    }

    m_AnalogActions.resize(std::size(g_AnalogActions));

    for (size_t actionIdx = 0; actionIdx < std::size(g_AnalogActions); actionIdx++)
    {
        const AnalogActionName& name = g_AnalogActions[actionIdx];
        AnalogAction& action = m_AnalogActions[actionIdx];
        ControllerAnalogActionHandle_t hAction = SteamController()->GetAnalogActionHandle(name.main);

        if (!hAction)
        {
            CryError("[SteamController] Failed to bind analog action handle '{}'[{}]", name.main, actionIdx);
            continue;
        }

        action.hAction = hAction;

        if (name.x && name.y)
        {
            action.pSymbolX = MapSymbol(actionIdx, (EKeyId)nextKeyId, { name.x }, name.type, 0);
            nextKeyId++;
            action.pSymbolY = MapSymbol(actionIdx, (EKeyId)nextKeyId, { name.y }, name.type, 0);
            nextKeyId++;
        }
        else
        {
            action.pSymbolX = MapSymbol(actionIdx, (EKeyId)nextKeyId, { name.main }, name.type, 0);
            nextKeyId++;
        }

        m_Actions[g_DigitalActions[actionIdx]] = ActionByName{ (unsigned)actionIdx, true };
    }

    m_ActionSets.resize(std::size(g_ActionSets));

    for (size_t actionSetIdx = 0; actionSetIdx < std::size(g_ActionSets); actionSetIdx++)
    {
        m_ActionSets[actionSetIdx] = SteamController()->GetActionSetHandle(g_ActionSets[actionSetIdx]);

        if (!m_ActionSets[actionSetIdx])
        {
            CryError("[SteamController] Failed to initialize ActionSet '{}'[{}]", g_ActionSets[actionSetIdx], actionSetIdx);
            continue;
        }
    }

    m_hCurrentActionSet = m_ActionSets[0];
    return true;
}

void SteamInputDevice::Update(bool bFocus)
{
    if (m_hCurrentController && m_hCurrentActionSet)
    {
        SteamController()->ActivateActionSet(m_hCurrentController, m_hCurrentActionSet);
    }

    SteamController()->RunFrame();

    if (SteamController()->GetConnectedControllers(m_hConnectedControllers) > 0)
    {
        m_hCurrentController = m_hConnectedControllers[0];
    }

    SInputEvent inputEvent = {};
    inputEvent.deviceType = eIDT_Gamepad;
    inputEvent.state = eIS_Unknown;
    inputEvent.inputChar = L'\0';
    inputEvent.keyName = TKeyName{ "" };
    inputEvent.keyId = eKI_Unknown;
    inputEvent.modifiers = 0;
    inputEvent.value = 0.0f;
    inputEvent.pSymbol = nullptr;
    inputEvent.deviceIndex = GetDeviceIndex();

    auto fnPostSymbolEvent = [&](SInputSymbol* pSymbol)
    {
        inputEvent.pSymbol = pSymbol;
        inputEvent.deviceType = pSymbol->deviceType;
        inputEvent.modifiers = 0;
        inputEvent.state = pSymbol->state;
        inputEvent.value = pSymbol->value;
        inputEvent.keyName = pSymbol->name;
        inputEvent.keyId = pSymbol->keyId;

        m_input.PostInputEvent(inputEvent, false);
    };

    auto fnSendAnalogEvent = [&](SInputSymbol* pSymbol, float value)
    {
        if (!pSymbol || pSymbol->value == value)
            return;

        pSymbol->value = value;
        pSymbol->state = eIS_Changed;
        fnPostSymbolEvent(pSymbol);
    };

    for (DigitalAction& action : m_DigitalActions)
    {
        if (!action.hAction || !action.pSymbol)
            continue;

        ControllerDigitalActionData_t data = SteamController()->GetDigitalActionData(m_hCurrentController, action.hAction);

        if (!data.bActive)
            continue;
        
        if (action.isReset && data.bState)
            continue;

        action.isReset = false;

        SInputSymbol* pSymbol = action.pSymbol;
        bool isPressed = data.bState;
        bool wasPressed = (pSymbol->state == eIS_Pressed) || (pSymbol->state == eIS_Down);

        if (isPressed != wasPressed)
        {
            if (isPressed)
            {
                pSymbol->state = eIS_Pressed;
                pSymbol->value = 1.0f;
            }
            else
            {
                pSymbol->state = eIS_Released;
                pSymbol->value = 0.0f;
            }

            fnPostSymbolEvent(pSymbol);
        }
    }

    for (AnalogAction& action : m_AnalogActions)
    {
        if (!action.hAction)
            continue;

        ControllerAnalogActionData_t data = SteamController()->GetAnalogActionData(m_hCurrentController, action.hAction);

        if (!data.bActive)
            continue;

        fnSendAnalogEvent(action.pSymbolX, data.x);
        fnSendAnalogEvent(action.pSymbolY, data.y);
    }

    EControllerActionOrigin origin = (EControllerActionOrigin)GetSteamActionOrigin(g_DigitalActions[0]);
    if (m_nCurrentActionOrigin != origin)
    {
        gEnv->pGame->RefreshControlScheme();
        m_nCurrentActionOrigin = origin;
    }
}

bool SteamInputDevice::SetForceFeedback(IFFParams params)
{
    if (!m_hCurrentController)
        return false;

    SetVibration(
        min(1.0f, (float)abs(params.strengthA)) * 65535.f,
        min(1.0f, (float)abs(params.strengthB)) * 65535.f,
        params.timeInSeconds,
        params.effectId
    );

    return true;
}

bool SteamInputDevice::SetExclusiveMode(bool value)
{
    return true;
}

void SteamInputDevice::ClearKeyState()
{
    m_fVibrationTimer = 0.0f;
    SetVibration(0, 0, 0.0f, eFF_Rumble_Basic);

    for (DigitalAction& action : m_DigitalActions)
    {
        action.isReset = true;
    }

    CInputDevice::ClearKeyState();
}

bool SteamInputDevice::IsOfDeviceType(EInputDeviceType type) const
{
    return type == eIDT_Gamepad && m_hCurrentController != 0;
}

bool SteamInputDevice::IsConnected() const
{
    return m_hCurrentController != 0;
}

void SteamInputDevice::ClearBufferedKeyState()
{
}

bool SteamInputDevice::IsSteamInputDevice() const
{
    return true;
}

bool SteamInputDevice::ShowBindingsPanel() const
{
    return SteamController()->ShowBindingPanel(m_hCurrentController);
}

bool SteamInputDevice::IsSteamInBigPictureMode() const
{
    return SteamUtils()->IsSteamInBigPictureMode();
}

unsigned SteamInputDevice::GetSteamActionOrigin(const char* const _szActionName) const
{
    if (!m_hCurrentController || !_szActionName)
        return 0;

    // Split action set from action
    std::string_view actionSetName;
    std::string_view fullActionName = _szActionName;
    size_t sep = fullActionName.find(':');

    if (sep != fullActionName.npos)
    {
        actionSetName = fullActionName.substr(0, sep);
    }
    else
    {
        actionSetName = "game";
    }

    // Find action set
    ControllerActionSetHandle_t hActionSet = 0;

    for (size_t i = 0; i < std::size(g_ActionSets); i++)
    {
        if (actionSetName == g_ActionSets[i])
        {
            hActionSet = m_ActionSets[i];
        }
    }

    if (!hActionSet)
    {
        CryWarning("[SteamController] Attempted to lookup an origin for an invalid action set [{}]", actionSetName);
        return 0;
    }

    // Find action
    auto it = m_Actions.find(fullActionName);

    if (it == m_Actions.end())
    {
        CryWarning("[SteamController] Attempted to lookup an origin for an invalid action [{}]", fullActionName);
        return 0;
    }

    EControllerActionOrigin origins[STEAM_CONTROLLER_MAX_ORIGINS];
    int originCount = 0;

    if (it->second.isAnalog)
    {
        originCount = SteamController()->GetAnalogActionOrigins(
            m_hCurrentController,
            m_hCurrentActionSet,
            m_AnalogActions[it->second.index].hAction,
            origins
        );
    }
    else
    {
        originCount = SteamController()->GetDigitalActionOrigins(
            m_hCurrentController,
            m_hCurrentActionSet,
            m_DigitalActions[it->second.index].hAction,
            origins
        );
    }

    if (originCount <= 0)
        return 0;

    return origins[0];
}

const char* SteamInputDevice::GetGlyphFromActionOrigin(unsigned _actionOrigin) const
{
    if (!m_bInitialized)
        return nullptr;

    return SteamController()->GetGlyphForActionOrigin((EControllerActionOrigin)_actionOrigin);
}

void SteamInputDevice::ActivateSteamActionSet(const char* const _szActionSetName)
{
    for (size_t i = 0; i < std::size(g_ActionSets); i++)
    {
        if (!strcmp(g_ActionSets[i], _szActionSetName))
        {
            m_hCurrentActionSet = m_ActionSets[i];

            for (DigitalAction& action : m_DigitalActions)
            {
                action.isReset = true;
            }

            CInputDevice::ClearKeyState();
            return;
        }
    }
}

void SteamInputDevice::SetVibration(uint16 leftMotor, uint16 rightMotor, float timing, EFFEffectId effectId)
{
    uint16 desiredVibrationLeft = 0;
    uint16 desiredVibrationRight = 0;

    if (effectId == eFF_Rumble_Basic)
    {
        // gEnv is null at shutdown because Chairloader has already reset it
        const float now = gEnv ? gEnv->pTimer->GetFrameStartTime().GetSeconds() : 0.0f;

        if (m_fVibrationTimer > 0.0f)
        {
            const float oldRumbleRatio = (float)__fsel(-timing, 1.0f, min(1.0f, (fabsf(m_fVibrationTimer - now) * (float)__fres((timing + FLT_EPSILON)))));

            //Store only 'basic', without frame part
            m_basicLeftMotorRumble = max(leftMotor, (uint16)(m_basicLeftMotorRumble * oldRumbleRatio));
            m_basicRightMotorRumble = max(rightMotor, (uint16)(m_basicRightMotorRumble * oldRumbleRatio));

            const float newLeftMotor = GetClampedLeftMotorAccumulatedVibration() * oldRumbleRatio;
            const float newRightMotor = GetClampedRightMotorAccumulatedVibration() * oldRumbleRatio;
            desiredVibrationLeft = max(leftMotor, (uint16)newLeftMotor);
            desiredVibrationRight = max(rightMotor, (uint16)newRightMotor);
        }
        else
        {
            m_basicLeftMotorRumble = leftMotor;
            m_basicRightMotorRumble = rightMotor;

            desiredVibrationLeft = max(leftMotor, (uint16)GetClampedLeftMotorAccumulatedVibration());
            desiredVibrationRight = max(rightMotor, (uint16)GetClampedRightMotorAccumulatedVibration());
        }

        m_fVibrationTimer = (float)__fsel(-timing, 0.0f, now + timing);
    }
    else if (effectId == eFF_Rumble_Frame)
    {
        m_frameLeftMotorRumble = leftMotor;
        m_frameRightMotorRumble = rightMotor;

        desiredVibrationLeft = (uint16)GetClampedLeftMotorAccumulatedVibration();
        desiredVibrationRight = (uint16)GetClampedRightMotorAccumulatedVibration();
    }

    SteamController()->TriggerVibration(m_hCurrentController, desiredVibrationLeft, desiredVibrationRight);
}
