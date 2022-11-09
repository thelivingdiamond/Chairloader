#pragma once

struct SInputEvent;

namespace Internal
{

//! Base interface for a Chairloader submodule.
struct IChairloaderModule
{
	virtual ~IChairloaderModule() {};
	virtual void ShutdownGame() {}
	virtual void ShutdownSystem() {}
	virtual void PreUpdate() {}
	virtual void PostUpdate() {}

	//! @returns whether it was handled and shouldn't be passed over to the game.
	virtual bool HandleKeyPress(const SInputEvent& event) { return false; };
};

} // namespace Internal
