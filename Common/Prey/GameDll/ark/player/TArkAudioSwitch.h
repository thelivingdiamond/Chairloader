// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/ArkAudioSwitch.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitchState.h>

class ArkTraumaBleeding;
class ArkTraumaHobbled;
struct IEntity;

// Header: Override
// Prey/GameDll/ark/player/TArkAudioSwitch.h
template <typename T>
class TArkAudioSwitch : public ArkAudioSwitch // Id=80173DE Size=12
{
public:
	using IndexType = std::underlying_type_t<T>;
	
	static constexpr const int StateCount = 2;
	ArkAudioSwitchState m_states[2];
	
#if 0
	bool LoadState(T arg0, const char *arg1); // :-1 Refs: 0
	void SetState(T arg0, IEntity *arg1) const; // :-1 Refs: 0
#endif
};

