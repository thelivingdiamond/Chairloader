// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/player/IArkPlayer.h
class IArkPlayer // Id=80020C5 Size=8
{
public:
	enum class EArkPlayerAnimationPriority
	{
		APAP_Lowest = 0,
		APAP_Movement = 1,
		APAP_PsiPower = 3,
		APAP_Normal = 4,
		APAP_High = 5,
		APAP_PDA = 6,
		APAP_Trackview = 7,
	};

	virtual std::pair<Vec3,Vec3> GetReticleViewPositionAndDir() const = 0;
	virtual void EnableIdleBreak(const bool arg0) = 0;
	virtual void InhibitRotation(const bool arg0) = 0;
};

