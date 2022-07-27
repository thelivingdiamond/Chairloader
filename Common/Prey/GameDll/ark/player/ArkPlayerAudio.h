// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryGame/IGameTokens.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitch.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitchState.h>
#include <Prey/GameDll/ark/player/TArkAudioSwitch.h>

class ICrySizer;
struct IGameToken;
class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ark/player/ArkPlayerAudio.h
class ArkPlayerAudio : private IGameTokenEventListener // Id=80173DD Size=80
{
public:
	TArkAudioSwitch<enum EPlayerSex> m_genderAudioSwitch;
	ArkAudioRtpc m_combatIntensityRtpc;
	ArkAudioRtpc m_jumpHeightRtpc;
	ArkAudioSwitch m_combatAudioSwitch;
	ArkAudioSwitchState m_combatOnAudioState;
	ArkAudioSwitchState m_combatOffAudioState;
	ArkAudioTrigger m_combatEndAudio;
	ArkAudioTrigger m_setHelmetOnAtmosphere;
	ArkAudioTrigger m_setHelmetOnNoAtmosphere;
	ArkAudioTrigger m_setHelmetOffAtmosphere;
	ArkAudioTrigger m_setHelmetOffNoAtmosphere;
	ArkAudioTrigger m_helmetOn;
	ArkAudioTrigger m_helmetOff;
	float m_combatIntensity;
	float m_combatIntensityEventStartThreshold;
	float m_combatIntensityEventStopThreshold;
	
	ArkPlayerAudio();
	virtual ~ArkPlayerAudio();
	void IncreaseCombatIntensity(const float _intensity) { FIncreaseCombatIntensity(this,_intensity); }
	void DecreaseCombatIntensity(const float _intensity) { FDecreaseCombatIntensity(this,_intensity); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Update() const { FUpdate(this); }
	void OnHelmetOn(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOn(this,_bAtmosphere,_bReset); }
	void OnHelmetOff(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOff(this,_bAtmosphere,_bReset); }
	virtual void OnGameTokenEvent(EGameTokenEvent _event, IGameToken *_pGameToken);
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	void OnCombatIntensityChanged() const { FOnCombatIntensityChanged(this); }
	
	static inline auto FBitNotArkPlayerAudio = PreyFunction<void(ArkPlayerAudio *const _this)>(0x145BB00);
	static inline auto FIncreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio *const _this, const float _intensity)>(0x145BD20);
	static inline auto FDecreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio *const _this, const float _intensity)>(0x145BC10);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerAudio *const _this, XmlNodeRef const &_node)>(0x145BDB0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerAudio const *const _this)>(0x145C360);
	static inline auto FOnHelmetOn = PreyFunction<void(ArkPlayerAudio const *const _this, const bool _bAtmosphere, const bool _bReset)>(0x12F9840);
	static inline auto FOnHelmetOff = PreyFunction<void(ArkPlayerAudio const *const _this, const bool _bAtmosphere, const bool _bReset)>(0x12F9750);
	static inline auto FOnGameTokenEvent = PreyFunction<void(ArkPlayerAudio *const _this, EGameTokenEvent _event, IGameToken *_pGameToken)>(0x145C210);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkPlayerAudio const *const _this, ICrySizer *_pSizer)>(0xA13080);
	static inline auto FOnCombatIntensityChanged = PreyFunction<void(ArkPlayerAudio const *const _this)>(0x145C1A0);
};

