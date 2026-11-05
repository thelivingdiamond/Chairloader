// Header file automatically created from a PDB.
#pragma once

class CCryActor;
enum EGameOverType;
class ICrySizer;

// SGameRulesListener
// Header:  _unknown/SGameRulesListener.h
struct SGameRulesListener
{ // Size=8 (0x8)
	virtual ~SGameRulesListener();
	virtual void GameOver(EGameOverType localWinner, bool isClientSpectator);
	virtual void EnteredGame();
	virtual void EndGameNear(unsigned id);
	virtual void ClientEnteredGame(unsigned clientId);
	virtual void ClientDisconnect(unsigned clientId);
	virtual void OnActorDeath(CCryActor* pActor);
	virtual void SvOnTimeLimitExpired();
	virtual void ClTeamScoreFeedback(int teamId, int prevScore, int newScore);

#if 0
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

#ifndef MOONCRASH
	static inline auto FGameOver = PreyFunction<void(SGameRulesListener* const _this, EGameOverType localWinner, bool isClientSpectator)>(0xA13080);
	static inline auto FEnteredGame = PreyFunction<void(SGameRulesListener* const _this)>(0xA13080);
	static inline auto FEndGameNear = PreyFunction<void(SGameRulesListener* const _this, unsigned id)>(0xA13080);
	static inline auto FClientEnteredGame = PreyFunction<void(SGameRulesListener* const _this, unsigned clientId)>(0xA13080);
	static inline auto FClientDisconnect = PreyFunction<void(SGameRulesListener* const _this, unsigned clientId)>(0xA13080);
	static inline auto FOnActorDeath = PreyFunction<void(SGameRulesListener* const _this, CCryActor* pActor)>(0xA13080);
	static inline auto FSvOnTimeLimitExpired = PreyFunction<void(SGameRulesListener* const _this)>(0xA13080);
	static inline auto FClTeamScoreFeedback = PreyFunction<void(SGameRulesListener* const _this, int teamId, int prevScore, int newScore)>(0xA13080);
#else
	static inline auto FGameOver = PreyFunction<void(SGameRulesListener* const _this, EGameOverType localWinner, bool isClientSpectator)>(0x1333E90);
	static inline auto FEnteredGame = PreyFunction<void(SGameRulesListener* const _this)>(0x1333E90);
	static inline auto FEndGameNear = PreyFunction<void(SGameRulesListener* const _this, unsigned id)>(0x1333E90);
	static inline auto FClientEnteredGame = PreyFunction<void(SGameRulesListener* const _this, unsigned clientId)>(0x1333E90);
	static inline auto FClientDisconnect = PreyFunction<void(SGameRulesListener* const _this, unsigned clientId)>(0x1333E90);
	static inline auto FOnActorDeath = PreyFunction<void(SGameRulesListener* const _this, CCryActor* pActor)>(0x1333E90);
	static inline auto FSvOnTimeLimitExpired = PreyFunction<void(SGameRulesListener* const _this)>(0x1333E90);
	static inline auto FClTeamScoreFeedback = PreyFunction<void(SGameRulesListener* const _this, int teamId, int prevScore, int newScore)>(0x1333E90);
#endif
};

