// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkFactionListener.h>

class ArkNpc;
enum class EArkDisposition;

// ArkNpcManager
// Header:  Prey/GameDll/ark/npc/ArkNpcManager.h
class ArkNpcManager : public IArkFactionListener
{ // Size=1056 (0x420)
public:
	// ArkNpcManager::ArkNpcManagerValidationChangeInfo
	// Header:  Prey/GameDll/ark/npc/ArkNpcManager.h
	struct ArkNpcManagerValidationChangeInfo
	{ // Size=24 (0x18)
		unsigned m_entityId;
		bool m_bEntityDoesNotExist;
		bool m_bWrongActivationState;
		bool m_bCurrentAttentionLevelIsWrong;
		bool m_bIsNotHostile;
		bool m_bIsLoDOut;
		EArkAttentionLevel m_expectedAttentionLevel;
		EArkAttentionLevel m_currentAttentionLevel;
		bool m_bIsActive;

	#if 0
		ArkNpcManagerValidationChangeInfo();
		ArkNpcManagerValidationChangeInfo(const ArkNpcManager::ArkNpcManagerValidationChangeInfo& _arg0_);
		ArkNpcManagerValidationChangeInfo(unsigned _arg0_, bool _arg1_, bool _arg2_, bool _arg3_, bool _arg4_, bool _arg5_, EArkAttentionLevel _arg6_, EArkAttentionLevel _arg7_, bool _arg8_);
	#endif
	};

	ArkSimpleTimer m_validateCombatantsTimer;
	ArkSimpleTimer m_npcGlobalCombatReactionTimer;
	ArkSimpleTimer m_npcGlobalNoticeAnimTimer;
	ArkAudioTrigger m_npcGlobalCuriousAudioTrigger;
	ArkSimpleTimer m_npcGlobalCuriousAudioTimer;
	ArkAudioTrigger m_npcGlobalLostAttentionAudioTrigger;
	ArkSimpleTimer m_npcGlobalLostAttentionAudioTimer;
	ArkAudioTrigger m_globalCombatStartAudioTrigger;
	ArkSimpleTimer m_globalCombatStartTimer;
	ArkSimpleTimer m_musicStateUpdateTimer;
	std::array<std::unordered_set<unsigned int>, 5> m_activeEntityIds;
	std::array<std::unordered_set<unsigned int>, 5> m_inactiveEntityIds;
	std::array<ArkAudioTrigger, 5> m_cancelMusicAudioTriggers;
	std::array<ArkAudioTrigger, 5> m_ascendingMusicAudioTriggers;
	std::array<ArkAudioTrigger, 5> m_ascendingStingerAudioTriggers;
	std::array<ArkSimpleTimer, 5> m_ascendingStingerTimers;
	std::array<ArkAudioTrigger, 5> m_descendingMusicAudioTriggers;
	std::array<ArkAudioTrigger, 5> m_descendingStingerAudioTriggers;
	std::array<ArkSimpleTimer, 5> m_descendingStingerTimers;
	EArkAttentionLevel m_lastFrameHighestActiveAttentionLevel;
	std::vector<unsigned int> m_combatPhantomsNeedingTraces;
	int m_allowedTracingPhantomIndex;
	EArkAttentionLevel m_thisFrameHighestActiveMusicLevel;
	EArkAttentionLevel m_thisFrameHighestActiveStingerLevel;
	EArkAttentionLevel m_lastFrameHighestActiveMusicLevel;
	EArkAttentionLevel m_lastFrameHighestActiveStingerLevel;
	int m_lastFrameCombatContributionAmount;
	int m_thisFrameCombatContributionAmount;
	EArkAttentionLevel m_currentAttentionMusicState;
	bool m_bCurrentAttentionMusicRising;
	EArkAttentionLevel m_queuedAttentionMusicState;
	bool m_bQueuedAttentionMusicRising;
	std::vector<uint64_t> m_disallowedMusicContributorTags;
	std::vector<uint64_t> m_disallowedStingerContributorTags;
	int m_requiredCombatPointsForCombatMusic;
	bool m_bLoadsOnLevelStart;
	bool m_bUseCombatantValidation;
	float m_minValidateCombatantsTime;
	float m_maxValidateCombatantsTime;
	EArkAttentionLevel m_bustPlayerThroughAttentionMinAttentionLevel;
	EArkAttentionLevel m_bustPlayerBySeeingMimicMinAttentionLevel;
	EArkAttentionLevel m_unbustPlayerMinAttentionLevel;
	bool m_bDisguisedPlayerBusted;
	bool m_bImmediateRagdoll;

	ArkNpcManager();
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	bool CanPerformNoticeAnim() const { return FCanPerformNoticeAnim(this); }
	void ResetNoticeAnimTimer() { FResetNoticeAnimTimer(this); }
	bool CanPerformCombatReaction() const { return FCanPerformCombatReaction(this); }
	bool IsPlayerMimicBusted() const { return FIsPlayerMimicBusted(this); }
	void OnPlayerStartMimic() { FOnPlayerStartMimic(this); }
	void OnPlayerStopMimic() { FOnPlayerStopMimic(this); }
	bool TryPerformCombatStartAudio() { return FTryPerformCombatStartAudio(this); }
	void Reset(bool _bGameStart) { FReset(this, _bGameStart); }
	void OnAttentionToPlayerChanged(unsigned _npcChangingAttentionLevel, EArkAttentionLevel _previousLevelOnPlayer, EArkAttentionLevel _newLevelOnPlayer) { FOnAttentionToPlayerChanged(this, _npcChangingAttentionLevel, _previousLevelOnPlayer, _newLevelOnPlayer); }
	void BustMimickingPlayer() { FBustMimickingPlayer(this); }
	void OnNpcStartedInactiveMusicBehavior(unsigned _npcStartingMimicry, EArkAttentionLevel _currentAttentionLevelOnPlayer) { FOnNpcStartedInactiveMusicBehavior(this, _npcStartingMimicry, _currentAttentionLevelOnPlayer); }
	void OnNpcStoppedInactiveMusicBehavior(unsigned _npcStoppingMimicry, EArkAttentionLevel _currentAttentionLevelOnPlayer) { FOnNpcStoppedInactiveMusicBehavior(this, _npcStoppingMimicry, _currentAttentionLevelOnPlayer); }
	bool IsNpcMusicInactive(const ArkNpc& _npcToCheck) const { return FIsNpcMusicInactive(this, _npcToCheck); }
	virtual void OnEffectiveEntityToEntityDispositionChange(unsigned _arg0_, unsigned _arg1_, EArkDisposition _arg2_, EArkDisposition _arg3_);
	unsigned GetAllowedTracingPhantomId() const { return FGetAllowedTracingPhantomId(this); }
	void AddPhantomNeedingTraces(unsigned _phantomId) { FAddPhantomNeedingTraces(this, _phantomId); }
	void RemovePhantomNeedingTraces(unsigned _phantomId) { FRemovePhantomNeedingTraces(this, _phantomId); }
	void ValidateCurrentCombatants() { FValidateCurrentCombatants(this); }
	void TryPlayAttentionAudio(float _elapsedTime) { FTryPlayAttentionAudio(this, _elapsedTime); }
	void CancelAllMusic(bool _bUnBustPlayer) { FCancelAllMusic(this, _bUnBustPlayer); }
	void EraseIdFromAllTracking(unsigned _idToErase) { FEraseIdFromAllTracking(this, _idToErase); }
	void LoadConfig() { FLoadConfig(this); }

#if 0
	void ResetCombatReactionTimer();
	bool IsImmediateRagdollEnabled() const;
	void SetImmediateRagdollEnabled(bool _arg0_);
	void UpdateMimicBustedAttention();
	void VerifyTracingPhantoms();
	void IncrementAllowedTracingPhantomIndex();
	void ResetPhantomsNeedingTraces();
	int GetNumPhantomsNeedingTraceChecks() const;
	bool CanPassXRayTraceCheck(unsigned _arg0_, unsigned _arg1_) const;
	void MoveInactiveNpcToActive(unsigned _arg0_, EArkAttentionLevel _arg1_);
	void MoveActiveNpcToInactive(unsigned _arg0_, EArkAttentionLevel _arg1_);
	int CountNpcsAtOrAboveAttentionLevel(EArkAttentionLevel _arg0_, bool _arg1_) const;
	EArkAttentionLevel GetHighestAttentionLevel(bool _arg0_) const;
	EArkAttentionLevel GetHighestActiveMusicAttentionLevel() const;
	EArkAttentionLevel GetHighestActiveStingerAttentionLevel() const;
	int GetCurrentCombatPoints() const;
	void ResetStateTrackingValues();
	void ResetValidateCombatantsTimer();
#endif

	static inline auto FArkNpcManagerOv2 = PreyFunction<void(ArkNpcManager* const _this)>(0x1290970);
	static inline auto FUpdate = PreyFunction<void(ArkNpcManager* const _this, float _elapsedTime)>(0x1293310);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkNpcManager* const _this)>(0x12926D0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkNpcManager* const _this)>(0x12926B0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcManager* const _this)>(0x1292870);
	static inline auto FSerialize = PreyFunction<void(ArkNpcManager* const _this, TSerialize _ser)>(0x1292F00);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcManager* const _this)>(0x1292CE0);
	static inline auto FCanPerformNoticeAnim = PreyFunction<bool(const ArkNpcManager* const _this)>(0x1290BF0);
	static inline auto FResetNoticeAnimTimer = PreyFunction<void(ArkNpcManager* const _this)>(0x1292EF0);
	static inline auto FCanPerformCombatReaction = PreyFunction<bool(const ArkNpcManager* const _this)>(0x1290BE0);
	static inline auto FIsPlayerMimicBusted = PreyFunction<bool(const ArkNpcManager* const _this)>(0x1290F70);
	static inline auto FOnPlayerStartMimic = PreyFunction<void(ArkNpcManager* const _this)>(0x1292970);
	static inline auto FOnPlayerStopMimic = PreyFunction<void(ArkNpcManager* const _this)>(0x1292BE0);
	static inline auto FTryPerformCombatStartAudio = PreyFunction<bool(ArkNpcManager* const _this)>(0x1292F80);
	static inline auto FReset = PreyFunction<void(ArkNpcManager* const _this, bool _bGameStart)>(0x1292DC0);
	static inline auto FOnAttentionToPlayerChanged = PreyFunction<void(ArkNpcManager* const _this, unsigned _npcChangingAttentionLevel, EArkAttentionLevel _previousLevelOnPlayer, EArkAttentionLevel _newLevelOnPlayer)>(0x1292340);
	static inline auto FBustMimickingPlayer = PreyFunction<void(ArkNpcManager* const _this)>(0x1290BD0);
	static inline auto FOnNpcStartedInactiveMusicBehavior = PreyFunction<void(ArkNpcManager* const _this, unsigned _npcStartingMimicry, EArkAttentionLevel _currentAttentionLevelOnPlayer)>(0x1292890);
	static inline auto FOnNpcStoppedInactiveMusicBehavior = PreyFunction<void(ArkNpcManager* const _this, unsigned _npcStoppingMimicry, EArkAttentionLevel _currentAttentionLevelOnPlayer)>(0x1292900);
	static inline auto FIsNpcMusicInactive = PreyFunction<bool(const ArkNpcManager* const _this, const ArkNpc& _npcToCheck)>(0x1290F40);
	static inline auto FGetAllowedTracingPhantomId = PreyFunction<unsigned(const ArkNpcManager* const _this)>(0x1290F00);
	static inline auto FAddPhantomNeedingTraces = PreyFunction<void(ArkNpcManager* const _this, unsigned _phantomId)>(0x1290B80);
	static inline auto FRemovePhantomNeedingTraces = PreyFunction<void(ArkNpcManager* const _this, unsigned _phantomId)>(0x1292D30);
	static inline auto FValidateCurrentCombatants = PreyFunction<void(ArkNpcManager* const _this)>(0x1293740);
	static inline auto FTryPlayAttentionAudio = PreyFunction<void(ArkNpcManager* const _this, float _elapsedTime)>(0x1293030);
	static inline auto FCancelAllMusic = PreyFunction<void(ArkNpcManager* const _this, bool _bUnBustPlayer)>(0x1290C00);
	static inline auto FEraseIdFromAllTracking = PreyFunction<void(ArkNpcManager* const _this, unsigned _idToErase)>(0x1290CC0);
	static inline auto FLoadConfig = PreyFunction<void(ArkNpcManager* const _this)>(0x1290F80);
};
#endif // MOONCRASH
