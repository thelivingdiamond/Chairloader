#pragma once

struct IChairloaderMod;

//! This is the API exported by Preditor to be used by Chairloader.
struct IPreditorToChair
{
	virtual ~IPreditorToChair() {}

	//! @returns the mod interface of Preditor.
	virtual IChairloaderMod* GetMod() = 0;

	//! Processes an input event.
	//! @param	event	The input event.
	//! @returns true if the event was processed and doesn't need to be passed to the game.
	virtual bool HandleInputEvent(const SInputEvent& event) = 0;
};
