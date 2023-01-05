// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkInputLegend;
class CCryName;
struct IEntityClass;

// IArkPlayerMimic
// Header:  Prey/GameDll/ark/player/psipower/IArkPlayerMimic.h
class IArkPlayerMimic
{ // Size=8 (0x8)
public:
	virtual ~IArkPlayerMimic();
	virtual void Show(const Vec3& _velocity) = 0;
	virtual bool Update(const float _frameTime) = 0;
	virtual void ProcessInput(const CCryName& _actionId, const bool _bPressed) = 0;
	virtual bool IsDead() const = 0;
	virtual Vec3 GetSize() const = 0;
	virtual Vec3 GetPosition() const = 0;
	virtual Vec3 GetCameraPosition() const = 0;
	virtual Quat GetCameraRotation() const = 0;
	virtual unsigned GetEntityId() const = 0;
	virtual const IEntityClass* GetEntityClass() const = 0;
	virtual const ArkInputLegend& GetModalLegend() const = 0;
	virtual void SetCameraPosition(const Vec3& endDir) = 0;
	virtual void SetCameraRotation(const Quat& _rotation) = 0;
	virtual void Serialize(TSerialize _ser) = 0;
	virtual void PostSerialize() = 0;
};

