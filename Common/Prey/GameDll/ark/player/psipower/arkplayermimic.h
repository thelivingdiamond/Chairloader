// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#include <Prey/GameDll/ark/iface/IArkGravShaftListener.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkGravShaftListener.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretCamera.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretEntity.h>
#include <Prey/GameDll/ark/player/psipower/IArkPlayerMimic.h>

class ArkInputLegend;
class CArkGravShaftEntity;
class CCryName;
struct IEntity;
struct IEntityArchetype;
struct IEntityClass;

// ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener
{ // Size=336 (0x150)
public:
	ArkPlayerMimicEngineeringOperatorCamera m_camera;
	ArkPlayerMimicEngineeringOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;

	virtual ~ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>();
	virtual bool IsDead() const;
	virtual void Show(const Vec3& _velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(const CCryName& _actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual const IEntityClass* GetEntityClass() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual void SetCameraPosition(const Vec3& _position);
	virtual void SetCameraRotation(const Quat& _rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);
	virtual void OnExit(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);

#if 0
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>(const IEntity& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>(const IEntityArchetype& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>(const unsigned _arg0_);
#endif

	static inline auto FIsDead = PreyFunction<bool(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13FAFA0);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, const Vec3& _velocity)>(0x13FBA90);
	static inline auto FUpdate = PreyFunction<bool(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, const float _frameTime)>(0x13FC340);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13FB340);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, Vec3* _return_value_)>(0x13FAD80);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, Vec3* _return_value_)>(0x13FACE0);
	static inline auto FGetCameraPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, Vec3* _return_value_)>(0x13FAB20);
	static inline auto FGetCameraRotation = PreyFunction<Quat*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, Quat* _return_value_)>(0x13FABA0);
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13FAC50);
	static inline auto FGetEntityClass = PreyFunction<const IEntityClass* (const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13FAC00);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13FAC90);
	static inline auto FSetCameraPosition = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, const Vec3& _position)>(0x13FBA20);
	static inline auto FSetCameraRotation = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, const Quat& _rotation)>(0x13FBA60);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this, TSerialize _ser)>(0x13FB4E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicEngineeringOperatorCamera,ArkPlayerMimicEngineeringOperatorController>* const _this)>(0x13FB2F0);
	static inline auto FOnEnter = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB0E0);
	static inline auto FOnExit = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB1E0);
};

// ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController> : public IArkPlayerMimic, public IArkGravShaftListener
{ // Size=1168 (0x490)
public:
	ArkPlayerMimicMilitaryOperatorCamera m_camera;
	ArkPlayerMimicMilitaryOperatorController m_controller;
	ArkPlayerMimicOperatorEntity m_entity;

	virtual ~ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>();
	virtual bool IsDead() const;
	virtual void Show(const Vec3& _velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(const CCryName& _actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual const IEntityClass* GetEntityClass() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual void SetCameraPosition(const Vec3& _position);
	virtual void SetCameraRotation(const Quat& _rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);
	virtual void OnExit(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);

#if 0
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>(const IEntity& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>(const IEntityArchetype& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>(const unsigned _arg0_);
#endif

	static inline auto FIsDead = PreyFunction<bool(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13FAFE0);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, const Vec3& _velocity)>(0x13FBB10);
	static inline auto FUpdate = PreyFunction<bool(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, const float _frameTime)>(0x13FC3D0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13FB3A0);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, Vec3* _return_value_)>(0x13FADA0);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, Vec3* _return_value_)>(0x13FAD00);
	static inline auto FGetCameraPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, Vec3* _return_value_)>(0x13FAB00);
	static inline auto FGetCameraRotation = PreyFunction<Quat*(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, Quat* _return_value_)>(0x13FAB80);
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13FAC60);
	static inline auto FGetEntityClass = PreyFunction<const IEntityClass* (const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13FAC10);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13FACA0);
	static inline auto FSetCameraPosition = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, const Vec3& _position)>(0x13FBA30);
	static inline auto FSetCameraRotation = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, const Quat& _rotation)>(0x12E0F10);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this, TSerialize _ser)>(0x13FB580);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicOperatorEntity,ArkPlayerMimicMilitaryOperatorCamera,ArkPlayerMimicMilitaryOperatorController>* const _this)>(0x13FB300);
	static inline auto FOnEnter = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB120);
	static inline auto FOnExit = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB220);
};

// ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController> : public IArkPlayerMimic, public IArkGravShaftListener
{ // Size=632 (0x278)
public:
	ArkPlayerMimicRigidCamera m_camera;
	ArkPlayerMimicRigidController m_controller;
	ArkPlayerMimicRigidEntity m_entity;

	virtual ~ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>();
	virtual bool IsDead() const;
	virtual void Show(const Vec3& _velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(const CCryName& _actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual const IEntityClass* GetEntityClass() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual void SetCameraPosition(const Vec3& _position);
	virtual void SetCameraRotation(const Quat& _rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);
	virtual void OnExit(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);

#if 0
	ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>(const IEntity& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>(const IEntityArchetype& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>(const unsigned _arg0_);
#endif

	static inline auto FIsDead = PreyFunction<bool(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this)>(0x13FB060);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, const Vec3& _velocity)>(0x13FBC10);
	static inline auto FUpdate = PreyFunction<bool(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, const float _frameTime)>(0x13FC4E0);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13FB440);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, Vec3* _return_value_)>(0x13FADE0);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, Vec3* _return_value_)>(0x13FAD40);
	static inline auto FGetCameraPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, Vec3* _return_value_)>(0x13FAB40);
	static inline auto FGetCameraRotation = PreyFunction<Quat*(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, Quat* _return_value_)>(0x13FABC0);
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this)>(0xC44F80);
	static inline auto FGetEntityClass = PreyFunction<const IEntityClass* (const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this)>(0x13FAC30);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this)>(0x13FACC0);
	static inline auto FSetCameraPosition = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, const Vec3& _position)>(0x13FBA50);
	static inline auto FSetCameraRotation = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, const Quat& _rotation)>(0x13FBA70);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this, TSerialize _ser)>(0x13FB6A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicRigidEntity,ArkPlayerMimicRigidCamera,ArkPlayerMimicRigidController>* const _this)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB1A0);
	static inline auto FOnExit = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB2A0);
};

// ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>
// Header:  Prey/GameDll/ark/player/psipower/arkplayermimic.h
class ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController> : public IArkPlayerMimic, public IArkGravShaftListener
{ // Size=152 (0x98)
public:
	ArkPlayerMimicTurretCamera m_camera;
	ArkPlayerMimicTurretController m_controller;
	ArkPlayerMimicTurretEntity m_entity;

	virtual ~ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>();
	virtual bool IsDead() const;
	virtual void Show(const Vec3& _velocity);
	virtual bool Update(const float _frameTime);
	virtual void ProcessInput(const CCryName& _actionId, const bool _bPressed);
	virtual Vec3 GetSize() const;
	virtual Vec3 GetPosition() const;
	virtual Vec3 GetCameraPosition() const;
	virtual Quat GetCameraRotation() const;
	virtual unsigned GetEntityId() const;
	virtual const IEntityClass* GetEntityClass() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual void SetCameraPosition(const Vec3& _position);
	virtual void SetCameraRotation(const Quat& _rotation);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnEnter(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);
	virtual void OnExit(const CArkGravShaftEntity& _gravShaft, const unsigned _entity);

#if 0
	ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>(const IEntity& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>(const IEntityArchetype& _arg0_, const QuatT& _arg1_);
	ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>(const unsigned _arg0_);
#endif

	static inline auto FIsDead = PreyFunction<bool(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this)>(0x13FB0A0);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, const Vec3& _velocity)>(0x13FBC70);
	static inline auto FUpdate = PreyFunction<bool(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, const float _frameTime)>(0x13FC570);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, const CCryName& _actionId, const bool _bPressed)>(0x13FB490);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, Vec3* _return_value_)>(0x13FAE00);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, Vec3* _return_value_)>(0x13FAD60);
	static inline auto FGetCameraPosition = PreyFunction<Vec3*(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, Vec3* _return_value_)>(0x13FAB60);
	static inline auto FGetCameraRotation = PreyFunction<Quat*(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, Quat* _return_value_)>(0x13FABE0);
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this)>(0x13FAC80);
	static inline auto FGetEntityClass = PreyFunction<const IEntityClass* (const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this)>(0x13FAC40);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this)>(0x13FACD0);
	static inline auto FSetCameraPosition = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, const Vec3& _position)>(0x10EDB50);
	static inline auto FSetCameraRotation = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, const Quat& _rotation)>(0x13FBA80);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this, TSerialize _ser)>(0x13FB720);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMimic<ArkPlayerMimicTurretEntity,ArkPlayerMimicTurretCamera,ArkPlayerMimicTurretController>* const _this)>(0x1333E90);
	static inline auto FOnEnter = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB2E0);
	static inline auto FOnExit = PreyFunction<void(IArkGravShaftListener* const _this, const CArkGravShaftEntity& _gravShaft, const unsigned _entity)>(0x13FB2E0);
};
#endif // !MOONCRASH
