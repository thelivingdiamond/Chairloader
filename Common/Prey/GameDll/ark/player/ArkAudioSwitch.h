// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitchState.h>

class ArkAudioSwitchState;
struct IEntity;

// ArkAudioSwitch
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class ArkAudioSwitch : public ArkAudioControl
{ // Size=4 (0x4)
public:
#if 0
	ArkAudioSwitch();
	ArkAudioSwitch(const char* _arg0_);
	ArkAudioSwitch(unsigned _arg0_);
	bool Load(const char* _arg0_);
	void SetState(const ArkAudioSwitchState& _arg0_, IEntity* _arg1_) const;
#endif
};

// TArkAudioSwitch
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
template <typename T>
class TArkAudioSwitch : public ArkAudioSwitch
{ // Size=12 (0xC)
public:
	using IndexType = int;

	static constexpr const int StateCount = 2;
	ArkAudioSwitchState m_states[2];

	void SetState(T _state, IEntity* _pEntity) const;

#if 0
	TArkAudioSwitch();
	TArkAudioSwitch(const char* _arg0_);
	bool LoadState(T _arg0_, const char* _arg1_);
#endif
};
