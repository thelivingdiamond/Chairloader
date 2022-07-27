// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkInputLegend;
class CCryName;
struct IEntityClass;

// Header: Override
// Prey/GameDll/ark/player/psipower/IArkPlayerMimic.h
class IArkPlayerMimic // Id=801944D Size=8
{
public:
	virtual ~IArkPlayerMimic();
	virtual void Show(Vec3 const &arg0) = 0;
	virtual bool Update(const float arg0) = 0;
	virtual void ProcessInput(CCryName const &arg0, const bool arg1) = 0;
	virtual bool IsDead() const = 0;
	virtual Vec3 GetSize() const = 0;
	virtual Vec3 GetPosition() const = 0;
	virtual Vec3 GetCameraPosition() const = 0;
	virtual Quat GetCameraRotation() const = 0;
	virtual unsigned GetEntityId() const = 0;
	virtual IEntityClass const *GetEntityClass() const = 0;
	virtual ArkInputLegend const &GetModalLegend() const = 0;
	virtual void SetCameraPosition(Vec3 const &arg0) = 0;
	virtual void SetCameraRotation(Quat const &arg0) = 0;
	virtual void Serialize(TSerialize arg0) = 0;
	virtual void PostSerialize() = 0;
};

