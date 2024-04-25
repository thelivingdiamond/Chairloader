#pragma once

namespace Internal
{
struct IChairloaderDll;
}

struct IPreditorToChair;

//! This is the API exported by Chairloader to be used by Preditor.
struct IChairToPreditor
{
	virtual ~IChairToPreditor() {}

	//! Sets the instance of IPreditorToChair.
	virtual void SetIPreditorToChair(IPreditorToChair* pPreditor) = 0;

	//! @returns IChairloaderDll instance.
	virtual Internal::IChairloaderDll* GetIChairloaderDll() = 0;
};
