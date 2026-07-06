// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkChallenge.h>

class ArkChallenge;
class XmlNodeRef;

// ArkChallengeManager
// Header:  Prey/GameDll/ark/ArkChallengeManager.h
class ArkChallengeManager
{ // Size=112 (0x70)
public:
	uint64_t m_currentChallenge;
	ArkChallengeList m_challengeList;
	float m_cryptoScoreMultiplier;
	float m_timeScoreMultiplier;
	float m_maxTime;
	int m_maxRandomStartingNeuromods;
	std::vector<float> m_randomCryptoAmounts;
	std::vector<uint64_t> m_fabPlanBlackList;
	string m_doomClockProfile;
	int m_randomChallenges;

	ArkChallengeManager();
	~ArkChallengeManager();
	void LoadData() { FLoadData(this); }
	void ExitChallengeMode() { FExitChallengeMode(this); }
	const ArkChallenge* GetCurrentChallenge() const { return FGetCurrentChallenge(this); }
	uint64_t GetPlayableCharacter() const { return FGetPlayableCharacter(this); }
	float GetStartingCrypto() const { return FGetStartingCrypto(this); }
	int GetStartingNeuromods() const { return FGetStartingNeuromods(this); }
	void CalculateScore(float& _cryptoScore, float& _timeScore) const { FCalculateScore(this, _cryptoScore, _timeScore); }

#if 0
	bool AnyChallengesAvailable() const;
	void EnterChallengeMode();
	bool IsInChallengeMode() const;
	const std::vector<uint64_t>& GetFabricationPlanBlackList() const;
	static void LoadListResult(bool _arg0_, const uint8_t* _arg1_, uint64_t _arg2_, void* _arg3_);
	void LoadListFailed();
	bool LoadChallengeList(XmlNodeRef _arg0_);
#endif

	static inline auto FArkChallengeManagerOv1 = PreyFunction<void(ArkChallengeManager* const _this)>(0x1196790);
	static inline auto FBitNotArkChallengeManager = PreyFunction<void(ArkChallengeManager* const _this)>(0x11968C0);
	static inline auto FLoadData = PreyFunction<void(ArkChallengeManager* const _this)>(0x1196D50);
	static inline auto FExitChallengeMode = PreyFunction<void(ArkChallengeManager* const _this)>(0x11969B0);
	static inline auto FGetCurrentChallenge = PreyFunction<const ArkChallenge* (const ArkChallengeManager* const _this)>(0x1196A00);
	static inline auto FGetPlayableCharacter = PreyFunction<uint64_t(const ArkChallengeManager* const _this)>(0x1196A20);
	static inline auto FGetStartingCrypto = PreyFunction<float(const ArkChallengeManager* const _this)>(0x1196C70);
	static inline auto FGetStartingNeuromods = PreyFunction<int(const ArkChallengeManager* const _this)>(0x1196D00);
	static inline auto FCalculateScore = PreyFunction<void(const ArkChallengeManager* const _this, float& _cryptoScore, float& _timeScore)>(0x1196920);
};
#endif // MOONCRASH
