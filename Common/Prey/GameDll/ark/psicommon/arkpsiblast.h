// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkPsiBlastProperties.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#ifndef MOONCRASH
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>
#endif

class ArkPsiPowerTargetingComponent;
enum class EArkPsiPowers;
struct IEntity;

// CArkPsiBlast<T,TProp>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblast.h
// Instantiations (all Size=80): CArkPsiElectrostaticBurst, CArkPsiFearBlast,
// CArkPsiKineticBlast, CArkPsiThermalBlast (+ CArkPsiFlareBlast in Mooncrash), each with
// TProp = CArkPsiBlastProperties<Ark...Properties>. No addresses: they differ per instantiation.
template <typename T, typename TProp>
class CArkPsiBlast // Id=801C116 Size=80
{ // Size=80 (0x50)
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
	const TProp* m_pProperties;
	bool m_bApplyImpulse;

	CArkPsiBlast(CArkPsiBlast&& _blast);
	CArkPsiBlast(const Vec3& _position, const TProp* _pProperties);
	~CArkPsiBlast();
	bool Update(const float _frameTime);

#if 0
	CArkPsiBlast();
	CArkPsiBlast(const CArkPsiBlast& _arg0_);
	CArkPsiBlast& operator=(CArkPsiBlast&& _arg0_);
	CArkPsiBlast& operator=(const CArkPsiBlast& _arg0_);
	bool operator==(const CArkPsiBlast& _arg0_) const;
	void EndDelay();
	float GetRadius() const;
	float GetFalloffScale(const float _arg0_) const;
	const Vec3 GetPosition() const;
	EArkPsiPowers GetPower() const;
	void OnEnterArea(const IEntity& _arg0_);
	ArkState GetState() const;
	unsigned GetEntityId() const;
	const TProp& GetProperties() const;
	void SetProperties(const TProp* _arg0_);
	void Serialize(TSerialize _arg0_);
	void PostSerialize();
	float GetDelaySec() const;
	void UpdateDelay(const std::vector<IEntity*> _arg0_) const;
	void UpdateEffect(const std::vector<IEntity*> _arg0_) const;
	void UpdateFrame(const float _arg0_) const;
	void OnEnterAreaDerived(const IEntity& _arg0_);
#endif
};
