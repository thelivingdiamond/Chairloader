// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkPsiElectrostaticBurstProperties;
class ArkPsiFearBlastProperties;
class ArkPsiKineticBlastProperties;
class ArkPsiPowerTargetingComponent;
class ArkPsiThermalBlastProperties;
struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
template <typename T>
class CArkPsiBlastManager : public IEntityEventListener // Id=801C18A Size=160
{
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiThermalBlastProperties>;
	
	CArkPsiBlastProperties<ArkPsiThermalBlastProperties> m_properties;
	std::vector<T> m_blasts;
	
	virtual ~CArkPsiBlastManager();
	void SpawnBlast(Vec3 const &arg0);
	void Update(const float arg0);
	void Initialize(ArkPsiThermalBlastProperties const &arg0, ArkPsiPowerTargetingComponent const &arg1);
	int GetBlastCount() const;
	CArkPsiBlastProperties<ArkPsiThermalBlastProperties> const &GetBlastProperties() const;
	void ClearBlasts();
	void Serialize(TSerialize _ser);
	void PostSerialize();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
};

