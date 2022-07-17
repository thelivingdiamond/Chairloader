#pragma once
class IArkHUDListener
{
public:
	virtual void OnEntityUnderReticleChanged(const unsigned int, const unsigned int) = 0;
};