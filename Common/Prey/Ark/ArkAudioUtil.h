// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAudio/IAudioSystem.h>

struct IEntity;

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioControl // Id=80020DC Size=4
{
public:
	unsigned m_controlId = 0;
	
#if 0
	bool IsValid() const;
	void Invalidate();
	unsigned GetId() const;
	void SetName(const char *arg0);
#endif
};

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioTrigger : public ArkAudioControl // Id=80020DB Size=4
{
public:
	bool Load(const char *_pName) { return FLoad(this,_pName); }
	void Execute(IEntity *_pEntity) const { FExecute(this,_pEntity); }
	void Stop(IEntity *_pEntity) const { FStop(this,_pEntity); }
	
	static inline auto FLoad = PreyFunction<bool(ArkAudioTrigger *const _this, const char *_pName)>(0x12086D0);
	static inline auto FExecute = PreyFunction<void(ArkAudioTrigger const *const _this, IEntity *_pEntity)>(0x10B19B0);
	static inline auto FStop = PreyFunction<void(ArkAudioTrigger const *const _this, IEntity *_pEntity)>(0x1236480);
};

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioRtpc : public ArkAudioControl // Id=8005A03 Size=4
{
public:
	void SetValue(float _value, IEntity *_pEntity) const { FSetValue(this,_value,_pEntity); }
	
#if 0
	bool Load(const char *arg0);
#endif
	
	static inline auto FSetValue = PreyFunction<void(ArkAudioRtpc const *const _this, float _value, IEntity *_pEntity)>(0x12402B0);
};

// ArkAudioSwitch
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class ArkAudioSwitch : public ArkAudioControl
{ // Size=4 (0x4)
public:
	ArkAudioSwitch() = default;

	ArkAudioSwitch(const char* sAudioSwitchName)
	{
		gEnv->pAudioSystem->GetAudioSwitchID(sAudioSwitchName, m_controlId);
	}

	ArkAudioSwitch(unsigned id)
	{
		m_controlId = id;
	}

#if 0
	ArkAudioSwitch();
	ArkAudioSwitch(const char* _arg0_);
	ArkAudioSwitch(unsigned _arg0_);
	bool Load(const char* _arg0_);
	void SetState(const ArkAudioSwitchState& _arg0_, IEntity* _arg1_) const;
#endif
};

// ArkAudioSwitchState
// Header:  Prey/GameDll/ark/player/ArkAudioSwitchState.h
class ArkAudioSwitchState
{ // Size=4 (0x4)
public:
	unsigned m_id = 0;

	bool Load(const ArkAudioSwitch& audioSwitch, const char* sAudioTriggerName)
	{
		return gEnv->pAudioSystem->GetAudioSwitchStateID(audioSwitch.m_controlId, sAudioTriggerName, m_id);
	}

#if 0
	ArkAudioSwitchState();
	ArkAudioSwitchState(const ArkAudioSwitch& _arg0_, const char* _arg1_);
	unsigned GetId() const;
#endif
};

// TArkAudioSwitch
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
template <typename T>
class TArkAudioSwitch : public ArkAudioSwitch
{ // Size=12 (0xC)
public:
	using IndexType = int;

	static constexpr const int StateCount = (int)T::count;
	ArkAudioSwitchState m_states[StateCount];

	TArkAudioSwitch() = default;
	TArkAudioSwitch(const char* sAudioSwitchName) : ArkAudioSwitch(sAudioSwitchName) {}

	void SetState(T _state, IEntity* _pEntity) const
	{
		FSetState(this, _state, _pEntity);
	}

	bool LoadState(T stateId, const char* sAudioTriggerName)
	{
		return m_states[(int)stateId].Load(*this, sAudioTriggerName);
	}

#if 0
	TArkAudioSwitch();
	TArkAudioSwitch(const char* _arg0_);
	bool LoadState(T _arg0_, const char* _arg1_);
#endif

	static inline auto FSetState = PreyFunction<void(TArkAudioSwitch const* const _this, T _state, IEntity * _pEntity)>(0x132BC80);
};
