// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>

class ArkNpc;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h
template <typename T>
class ArkPlayerMimicOperatorController // Id=801B687 Size=64
{
public:
	using Properties = ArkPsiMimicOperatorProperties;
	
	ArkSimpleTimer m_ragdollTimer;
	ArkInputLegend m_modalInputLegend;
	ArkNpc *m_pNpc;
	ArkPsiMimicOperatorProperties const &m_properties;
	bool m_bZeroG;
	
#if 0
	void ArkPlayerMimicOperatorController();
	void ResetModalLegend();
	void Initialize(IEntity &_mimicEntity);
	void Update(const float _frameTime, IEntity &_mimicEntity);
	ArkNpc &GetNpc() const;
	bool IsZeroG() const;
	bool IsRagdolled() const;
	Vec3 GetMimicPosition() const;
	Quat GetMimicRotation() const;
	float GetTurnSpeedScale() const;
	ArkInputLegend const &GetModalLegend() const;
	void Initialize_Derived(IEntity &arg0) const;
	void Update_Derived(const float arg0, IEntity &arg1) const;
	void ResetModalLegend_Derived(ArkInputLegend &arg0) const;
#endif
};

