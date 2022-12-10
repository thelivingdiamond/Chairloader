#pragma once

struct IPreditorToChair;

//! This is the API exported by Chairloader to be used by Preditor.
struct IChairToPreditor
{
	virtual ~IChairToPreditor() {}

	//! Sets the instance of IPreditorToChair.
	virtual void SetIPreditorToChair(IPreditorToChair* pPreditor) = 0;
};
