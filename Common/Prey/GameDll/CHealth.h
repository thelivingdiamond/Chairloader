// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/utility/MaskedVar.h>

// CHealth
// Header:  _unknown/CHealth.h
class CHealth
{ // Size=24 (0x18)
public:
	CMaskedVarT<float,unsigned int,4294967295> m_health;
	float m_healthMax;
	float m_regenMax;
	CMaskedVarT<int,unsigned int,4294967295> m_healthAsRoundedPercentage;

#if 0
	CHealth();
	float GetMaxRegen() const;
	void SetMaxRegen(const float _arg0_);
	float GetHealth() const;
	void SetHealth(float _arg0_);
	float GetHealthMax() const;
	void SetHealthMax(float _arg0_);
	int GetHealthAsRoundedPercentage() const;
	bool IsDead() const;
#endif
};

