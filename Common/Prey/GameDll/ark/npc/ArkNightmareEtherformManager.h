// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// ArkNightmareEtherformManager
// Header:  Prey/GameDll/ark/npc/ArkNightmareEtherformManager.h
class ArkNightmareEtherformManager
{ // Size=80 (0x50)
public:
	// ArkNightmareEtherformManager::EtherFormTrackTime
	// Header:  Prey/GameDll/ark/npc/ArkNightmareEtherformManager.h
	struct EtherFormTrackTime
	{ // Size=16 (0x10)
		CTimeValue m_startTime;
		float m_duration;
		bool m_bOngoing;

	#if 0
		EtherFormTrackTime();
	#endif
	};

	ArkSimpleTimer m_etherFormCooldown;
	ArkSimpleTimer m_etherFormLeaveTimer;
	ArkSimpleTimer m_etherFormLeaveAfterPlayerDamageTimer;
	float m_etherFormTrackWindowTime;
	float m_etherFormTrackDurationMin;
	float m_etherFormTrackDurationMax;
	float m_etherFormCoolDownMin;
	float m_etherFormCoolDownMax;
	bool m_bEtherFormRestricted;
	std::vector<ArkNightmareEtherformManager::EtherFormTrackTime> m_etherFormTrackTimes;
	float m_etherFormTrackTimer;
	bool m_bEtherFormPlayerDamage;

	ArkNightmareEtherformManager();
	~ArkNightmareEtherformManager();
	void Initialize() { FInitialize(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void FullSerialize(TSerialize _serializer) { FFullSerialize(this, _serializer); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void DamagePlayerInEtherForm(const unsigned _nightmareId) { FDamagePlayerInEtherForm(this, _nightmareId); }
	void LoadXml() { FLoadXml(this); }

#if 0
	ArkNightmareEtherformManager(const ArkNightmareEtherformManager& _arg0_);
	bool IsEtherFormRestricted() const;
	void EnterEtherForm(const unsigned _arg0_);
	void ExitEtherForm(const unsigned _arg0_);
	void RestrictEtherForm(bool _arg0_);
	float GetTrackedTimeInEtherForm();
	ArkNightmareEtherformManager& operator=(const ArkNightmareEtherformManager& _arg0_);
#endif

	static inline auto FArkNightmareEtherformManagerOv1 = PreyFunction<void(ArkNightmareEtherformManager* const _this)>(0x1281360);
	static inline auto FBitNotArkNightmareEtherformManager = PreyFunction<void(ArkNightmareEtherformManager* const _this)>(0x12813B0);
	static inline auto FInitialize = PreyFunction<void(ArkNightmareEtherformManager* const _this)>(0x1281540);
	static inline auto FReset = PreyFunction<void(ArkNightmareEtherformManager* const _this, bool _bEnteringGameMode)>(0x1281540);
	static inline auto FUpdate = PreyFunction<void(ArkNightmareEtherformManager* const _this, float _frameTime)>(0x12817C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkNightmareEtherformManager* const _this, TSerialize _serializer)>(0x12813F0);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkNightmareEtherformManager* const _this)>(0x12817B0);
	static inline auto FDamagePlayerInEtherForm = PreyFunction<void(ArkNightmareEtherformManager* const _this, const unsigned _nightmareId)>(0x12813C0);
	static inline auto FLoadXml = PreyFunction<void(ArkNightmareEtherformManager* const _this)>(0x1281590);
};
#endif // MOONCRASH
