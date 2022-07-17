#pragma once
class ArkAudioControl
{
	unsigned int m_controlId;
};
class ArkAudioTrigger : ArkAudioControl
{
};
class ArkAudioSwitch : ArkAudioControl
{
};
class ArkAudioRtpc : ArkAudioControl
{
};
class ArkAudioSwitchState
{
public:
	unsigned int m_id; //0x0000
}; //Size: 0x0004

template<typename T> class TArkAudioSwitch : ArkAudioSwitch
{
public:
	class ArkAudioSwitchState m_states[2]; //0x0004
}; //Size: 0x000C
class ArkAudioSwitchManager
{
	class SwitchState
	{
		unsigned int m_entityId;
		unsigned int m_switch;
		unsigned int m_state;
	};

	std::vector<ArkAudioSwitchManager::SwitchState> m_switchStates;
};