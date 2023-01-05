// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>

class ArkPsiPowerTargetingComponent;
struct IEntity;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsiblast.h
template <typename T, typename TProp>
class CArkPsiBlast // Id=801C116 Size=80
{
public:
	enum class ArkState
	{
		Delay = 0,
		Execute = 1,
		Finishing = 2,
	};

	Vec3 m_lastUpdatePosition;
	std::vector<unsigned int> m_targetEntities;
	ArkState m_state;
	unsigned m_entityId;
	float m_elapsedSec;
	float m_updateElapsedSec;
	float m_updateIntervalSec;
	int m_delayEmitterSlot;
	TProp const *m_pProperties;
	bool m_bApplyImpulse;
	
#if 0
	void CArkPsiBlast(CArkPsiBlast *_blast);
	void CArkPsiBlast(Vec3 const &_position, TProp const *_pProperties);
	void ~CArkPsiBlast();
	bool operator==(CArkPsiBlast const &arg0) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float arg0) const;
	Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	bool Update(const float _frameTime);
	void OnEnterArea(IEntity const &arg0);
	CArkPsiBlast::ArkState GetState() const;
	unsigned GetEntityId() const;
	TProp const &GetProperties() const;
	void SetProperties(TProp const *arg0);
	void Serialize(TSerialize arg0);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(std::vector<IEntity *> arg0) const;
	void UpdateEffect(std::vector<IEntity *> arg0) const;
	void UpdateFrame(const float arg0) const;
	void OnEnterAreaDerived(IEntity const &arg0);
#endif
};

