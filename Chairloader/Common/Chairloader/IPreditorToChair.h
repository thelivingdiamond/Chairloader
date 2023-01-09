#pragma once

struct IChairloaderMod;
struct SInputEvent;

//! This is the API exported by Preditor to be used by Chairloader.
struct IPreditorToChair
{
	virtual ~IPreditorToChair() {}

	//! @returns the mod interface of Preditor.
	virtual IChairloaderMod* GetMod() = 0;

	//! Processes an input event before ChairImGui and the engine.
	//! @param	event	The input event.
	//! @returns true if the event was processed and doesn't need to be passed to ChairImGui.
	virtual bool HandleInputEvent(const SInputEvent& event) = 0;

	//! Processes an input event after ChairImGui but before the engine.
	//! @param	event	The input event.
	//! @returns true if the event was processed and doesn't need to be passed to the engine.
	virtual bool HandleInputEventPreGame(const SInputEvent& event) = 0;
};
