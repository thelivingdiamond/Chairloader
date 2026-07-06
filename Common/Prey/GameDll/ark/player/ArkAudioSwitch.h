// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitchState.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaBleeding.h>
#include <Prey/GameDll/ark/player/trauma/ArkTraumaHobbled.h>

enum class EPlayerSex;
struct IEntity;

// ArkAudioSwitch
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class ArkAudioSwitch : public ArkAudioControl
{ // Size=4 (0x4)
public:
	void SetState(const ArkAudioSwitchState& _state, IEntity* _pEntity) const { FSetState(this, _state, _pEntity); }

#if 0
	ArkAudioSwitch();
	ArkAudioSwitch(const char* _arg0_);
	ArkAudioSwitch(unsigned _arg0_);
	bool Load(const char* _arg0_);
#endif

	static inline auto FSetState = PreyFunction<void(const ArkAudioSwitch* const _this, const ArkAudioSwitchState& _state, IEntity* _pEntity)>(0x1572A50);
};

// TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed>
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed> : public ArkAudioSwitch
{ // Size=12 (0xC)
public:
	using IndexType = int;

	static constexpr const int StateCount = 2;
	ArkAudioSwitchState m_states[2];

	void SetState(ArkTraumaBleeding::EAudioBleed _state, IEntity* _pEntity) const { FSetState(this, _state, _pEntity); }

#if 0
	TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed>();
	TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed>(const char* _arg0_);
	bool LoadState(ArkTraumaBleeding::EAudioBleed _arg0_, const char* _arg1_);
#endif

	static inline auto FSetState = PreyFunction<void(const TArkAudioSwitch<enum ArkTraumaBleeding::EAudioBleed>* const _this, ArkTraumaBleeding::EAudioBleed _state, IEntity* _pEntity)>(0x13C1F40);
};

// TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled>
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled> : public ArkAudioSwitch
{ // Size=12 (0xC)
public:
	using IndexType = int;

	static constexpr const int StateCount = 2;
	ArkAudioSwitchState m_states[2];

	void SetState(ArkTraumaHobbled::EAudioHobbled _state, IEntity* _pEntity) const { FSetState(this, _state, _pEntity); }

#if 0
	TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled>();
	TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled>(const char* _arg0_);
	bool LoadState(ArkTraumaHobbled::EAudioHobbled _arg0_, const char* _arg1_);
#endif

	static inline auto FSetState = PreyFunction<void(const TArkAudioSwitch<enum ArkTraumaHobbled::EAudioHobbled>* const _this, ArkTraumaHobbled::EAudioHobbled _state, IEntity* _pEntity)>(0x13C1F40);
};

// TArkAudioSwitch<enum EPlayerSex>
// Header:  Prey/GameDll/ark/player/ArkAudioSwitch.h
class TArkAudioSwitch<enum EPlayerSex> : public ArkAudioSwitch
{ // Size=12 (0xC)
public:
	using IndexType = int;

	static constexpr const int StateCount = 2;
	ArkAudioSwitchState m_states[2];

#if 0
	TArkAudioSwitch<enum EPlayerSex>();
	TArkAudioSwitch<enum EPlayerSex>(const char* _arg0_);
	bool LoadState(EPlayerSex _arg0_, const char* _arg1_);
	void SetState(EPlayerSex _arg0_, IEntity* _arg1_) const;
#endif
};
#endif // MOONCRASH
