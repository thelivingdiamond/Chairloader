// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkPlayerMimicEngineeringOperatorController;
class ArkPlayerMimicMilitaryOperatorController;
class ArkPlayerMimicScienceOperatorController;
class CCryName;
struct IAnimatedCharacter;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h
template <typename T>
class ArkPlayerMimicOperatorMovementController // Id=801B685 Size=40
{
public:
	Vec3 m_velocity;
	float m_speed;
	T const &m_controller;
	IAnimatedCharacter *m_pAnimatedCharacter;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bSprinting;
	
#if 0
	void ArkPlayerMimicOperatorMovementController(T const &_controller);
	void Initialize(IEntity &_mimicEntity);
	void Update(const float _frameTime, IEntity const &_mimicEntity);
	void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	void Serialize(TSerialize _ser);
	bool IsSprinting() const;
#endif
};

