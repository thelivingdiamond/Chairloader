// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryGame/CoherentValue.h>

// SActorStats
// Header:  _unknown/SActorStats.h
struct SActorStats
{ // Size=76 (0x4C)
	// SActorStats::SItemExchangeStats
	// Header:  _unknown/SActorStats.h
	struct SItemExchangeStats
	{ // Size=8 (0x8)
		unsigned switchingToItemID;
		bool keepHistory;
		bool switchThisFrame;

	#if 0
		SItemExchangeStats();
	#endif
	};

	CCoherentValue<float> inAir;
	CCoherentValue<float> onGround;
	CCoherentValue<float> speedFlat;
	int movementDir;
	float inFiring;
	float maxAirSpeed;
	bool isGrabbed;
	bool isRagDoll;
	bool isInBlendRagdoll;
	bool wasHit;
	bool bStealthKilling;
	bool bStealthKilled;
	bool bAttemptingStealthKill;
	unsigned spectacularKillPartner;
	CCoherentValue<bool> isHidden;
	unsigned mountedWeaponID;
	SActorStats::SItemExchangeStats exchangeItemStats;
	float feetHeight[2];
	unsigned m_actorStatusFlags;

#if 0
	void EnableStatusFlags(unsigned _arg0_);
	void DisableStatusFlags(unsigned _arg0_);
	bool HasAnyStatusFlags(unsigned _arg0_) const;
	bool HasAllStatusFlags(unsigned _arg0_) const;
	unsigned GetStatusFlags() const;
	SActorStats();
#endif
};

