// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMedicalOperatorController.h>
#include <Prey/GameDll/ark/IArkGravShaftListener.h>
#include <Prey/GameDll/ark/player/psipower/IArkPlayerMimic.h>

class ArkInputLegend;
class CArkGravShaftEntity;
class CCryName;
struct IEntity;
struct IEntityArchetype;
struct IEntityClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B846 Size=144
{
public:
	ArkPlayerMimicTurretCamera m_camera;
	ArkPlayerMimicTurretController m_controller;
	ArkPlayerMimicTurretEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B84B Size=632
{
public:
	ArkPlayerMimicRigidCamera m_camera;
	ArkPlayerMimicRigidController m_controller;
	ArkPlayerMimicRigidEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B850 Size=1144
{
public:
	ArkPlayerMimicMilitaryOperatorCamera m_camera;
	ArkPlayerMimicMilitaryOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B855 Size=336
{
public:
	ArkPlayerMimicEngineeringOperatorCamera m_camera;
	ArkPlayerMimicEngineeringOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicScienceOperatorCamera,ArkPlayerMimicScienceOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B85A Size=624
{
public:
	ArkPlayerMimicScienceOperatorCamera m_camera;
	ArkPlayerMimicScienceOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicScienceOperatorCamera,ArkPlayerMimicMedicalOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener // Id=801B85F Size=624
{
public:
	ArkPlayerMimicScienceOperatorCamera m_camera;
	ArkPlayerMimicMedicalOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;
	
#if 0
	virtual bool IsDead() const;
	virtual void Show(Vec3 const &_velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(CCryName const &_actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual IEntityClass const *GetEntityClass() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual void SetCameraPosition(Vec3 const &_position);
	virtual void SetCameraRotation(Quat const &_rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
	virtual void OnExit(CArkGravShaftEntity const &_gravShaft, const unsigned _entity);
#endif
};

