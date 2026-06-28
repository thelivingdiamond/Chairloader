// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryGame/IGameTokens.h>
#include <Prey/Ark/ArkAudioUtil.h>

enum EGameTokenEvent;
class ICrySizer;
struct IGameToken;
class XmlNodeRef;

// ArkPlayerAudio
// Header:  Prey/GameDll/ark/player/ArkPlayerAudio.h
class ArkPlayerAudio : private IGameTokenEventListener
{ // Size=80 (0x50)
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
	void IncreaseCombatIntensity(const float _intensity) { FIncreaseCombatIntensity(this, _intensity); }
	void DecreaseCombatIntensity(const float _intensity) { FDecreaseCombatIntensity(this, _intensity); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Update() const { FUpdate(this); }
	void OnHelmetOn(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOn(this, _bAtmosphere, _bReset); }
	void OnHelmetOff(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOff(this, _bAtmosphere, _bReset); }
	virtual void OnGameTokenEvent(EGameTokenEvent _event, IGameToken* _pGameToken);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	void OnCombatIntensityChanged() const { FOnCombatIntensityChanged(this); }

	static inline auto FArkPlayerAudioOv1 = PreyFunction<void(ArkPlayerAudio* const _this)>(0x145BA70);
	static inline auto FBitNotArkPlayerAudio = PreyFunction<void(ArkPlayerAudio* const _this)>(0x145BB00);
	static inline auto FIncreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio* const _this, const float _intensity)>(0x145BD20);
	static inline auto FDecreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio* const _this, const float _intensity)>(0x145BC10);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerAudio* const _this, const XmlNodeRef& _node)>(0x145BDB0);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x145C360);
	static inline auto FOnHelmetOn = PreyFunction<void(const ArkPlayerAudio* const _this, const bool _bAtmosphere, const bool _bReset)>(0x12F9840);
	static inline auto FOnHelmetOff = PreyFunction<void(const ArkPlayerAudio* const _this, const bool _bAtmosphere, const bool _bReset)>(0x12F9750);
	static inline auto FOnGameTokenEvent = PreyFunction<void(ArkPlayerAudio* const _this, EGameTokenEvent _event, IGameToken* _pGameToken)>(0x145C210);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkPlayerAudio* const _this, ICrySizer* _pSizer)>(0xA13080);
	static inline auto FOnCombatIntensityChanged = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x145C1A0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryGame/IGameTokens.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitch.h>
#include <Prey/GameDll/ark/player/ArkAudioSwitchState.h>

enum EGameTokenEvent;
class ICrySizer;
struct IGameToken;
class XmlNodeRef;

// ArkPlayerAudio
// Header:  Prey/GameDll/ark/player/ArkPlayerAudio.h
class ArkPlayerAudio : private IGameTokenEventListener
{ // Size=152 (0x98)
public:
	TArkAudioSwitch<enum EPlayerSex> m_genderAudioSwitch;
	ArkAudioSwitch m_characterSwitch;
	std::unordered_map<uint64_t, ArkAudioSwitchState> m_characterSwitchStates;
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
	void IncreaseCombatIntensity(const float _intensity) { FIncreaseCombatIntensity(this, _intensity); }
	void DecreaseCombatIntensity(const float _intensity) { FDecreaseCombatIntensity(this, _intensity); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Update() const { FUpdate(this); }
	void PostSerialize() const { FPostSerialize(this); }
	void OnHelmetOn(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOn(this, _bAtmosphere, _bReset); }
	void OnHelmetOff(const bool _bAtmosphere, const bool _bReset) const { FOnHelmetOff(this, _bAtmosphere, _bReset); }
	void OnPlayableCharacterChanged(const uint64_t _characterId) const { FOnPlayableCharacterChanged(this, _characterId); }
	virtual void OnGameTokenEvent(EGameTokenEvent _event, IGameToken* _pGameToken);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	void OnCombatIntensityChanged() const { FOnCombatIntensityChanged(this); }
	void UpdateCharacterAudioSwitch() const { FUpdateCharacterAudioSwitch(this); }

	static inline auto FArkPlayerAudioOv1 = PreyFunction<void(ArkPlayerAudio* const _this)>(0x1571C90);
	static inline auto FBitNotArkPlayerAudio = PreyFunction<void(ArkPlayerAudio* const _this)>(0x1571D80);
	static inline auto FIncreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio* const _this, const float _intensity)>(0x1572030);
	static inline auto FDecreaseCombatIntensity = PreyFunction<void(ArkPlayerAudio* const _this, const float _intensity)>(0x1571F20);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerAudio* const _this, const XmlNodeRef& _node)>(0x15720D0);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x1572BD0);
	static inline auto FPostSerialize = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x1572A40);
	static inline auto FOnHelmetOn = PreyFunction<void(const ArkPlayerAudio* const _this, const bool _bAtmosphere, const bool _bReset)>(0x13D3E10);
	static inline auto FOnHelmetOff = PreyFunction<void(const ArkPlayerAudio* const _this, const bool _bAtmosphere, const bool _bReset)>(0x13D3D10);
	static inline auto FOnPlayableCharacterChanged = PreyFunction<void(const ArkPlayerAudio* const _this, const uint64_t _characterId)>(0x1572920);
	static inline auto FOnGameTokenEvent = PreyFunction<void(ArkPlayerAudio* const _this, EGameTokenEvent _event, IGameToken* _pGameToken)>(0x15727D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkPlayerAudio* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FOnCombatIntensityChanged = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x1572750);
	static inline auto FUpdateCharacterAudioSwitch = PreyFunction<void(const ArkPlayerAudio* const _this)>(0x1572CB0);
};
#endif // !MOONCRASH
