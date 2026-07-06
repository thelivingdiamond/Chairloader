// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// SItemActionParamCRCs
// Header:  Prey/GameDll/itemdefinitions.h
struct SItemActionParamCRCs
{ // Size=68 (0x44)
	unsigned concentratedFire;
	unsigned ammoLeft;
	unsigned burstFire;
	unsigned spinSpeed;
	unsigned ffeedbackScale;
	unsigned fired;
	unsigned firstFire;
	unsigned bowChargeLevel;
	unsigned bowChargeSound;
	unsigned bowFireIntensity;
	unsigned bowStrength;
	unsigned aimDirection;
	unsigned zoomTransition;
	unsigned inputMove;
	unsigned inputRot;
	unsigned velocity;
	unsigned fallFactor;

	void Init() { FInit(this); }

	static inline auto FInit = PreyFunction<void(SItemActionParamCRCs* const _this)>(0x1675FB0);
};

// SItemFragmentTagCRCs
// Header:  Prey/GameDll/itemdefinitions.h
struct SItemFragmentTagCRCs
{ // Size=48 (0x30)
	unsigned ammo_clipRemaining;
	unsigned ammo_empty;
	unsigned ammo_last1;
	unsigned ammo_last2;
	unsigned ammo_last3;
	unsigned inventory_last2;
	unsigned inventory_last1;
	unsigned doubleclip_fast;
	unsigned ammo_partiallycharged;
	unsigned ammo_fullycharged;
	unsigned holo;
	unsigned typhoonAttachment;

	void Init() { FInit(this); }

	static inline auto FInit = PreyFunction<void(SItemFragmentTagCRCs* const _this)>(0x187CC50);
};
#endif // MOONCRASH
