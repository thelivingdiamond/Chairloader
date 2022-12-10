#pragma once

struct IChairloaderMod;

//! This is the API exported by Preditor to be used by Chairloader.
struct IPreditorToChair
{
	virtual ~IPreditorToChair() {}

	//! @returns the mod interface of Preditor.
	virtual IChairloaderMod* GetMod() = 0;
};
