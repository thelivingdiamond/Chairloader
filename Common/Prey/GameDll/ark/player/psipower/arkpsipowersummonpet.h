#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerGroundTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/player/psipower/ArkPetFactory.h>

class ArkNpc;
class CCryName;
enum class EArkPsiPowers;
struct IEntity;
struct SEntityEvent;

// ArkPsiPowerSummonPet<TDerived,TProperties>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h
// Mooncrash-only CRTP base. Instantiations (all Size=696):
//   ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>
//   ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>
//   ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>
// No addresses: they differ per instantiation.
template <typename TDerived, typename TProperties>
class ArkPsiPowerSummonPet
	: public CArkPsiPower<TProperties>
	, public ArkPetFactory
	, public IEntityEventListener
{ // Size=696 (0x2B8)
public:
	using BasePowerType = CArkPsiPower<TProperties>;

	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	unsigned m_petEntityId;
	unsigned m_petSkinMeshAttachmentEntityId;
	ArkEntityAttachmentEffect m_summonParticle;
	EntityEffects::CEffectsController m_attachmentEffectController;

	ArkPsiPowerSummonPet();
	virtual ~ArkPsiPowerSummonPet();
	virtual void Cancel();
	virtual bool StartTargeting();
	virtual void Update(const float _frameTime);
	virtual void UpdateTargeting(const float _frameTime);
	virtual void Serialize(TSerialize _serializer);
	virtual void PostSerialize();
	virtual const IEntity* GetPet() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual const char* GetIcon() const;
	virtual void OnReset();
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual const char* GetErrorString() const;
	virtual void DestroyCurrentPet();
	virtual void KillCurrentPet();
	virtual void ApplySkin(const uint64_t _skinId);
	virtual void SetLevel_Derived(const int _level);
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	virtual bool Start_Derived();
	virtual void InitializePet_Derived(IEntity* _petEntity);

#if 0
	void ApplyCurrentSkin();
	void OnPetRemoved();
	void CleanupOnPetRemoval();
	Vec3 FindSpawnPosition() const;
	unsigned GetSummonedPetId() const;
	const char* GetSummonFX() const;
	const char* GetUnsummonFX() const;
	const char* GetSummonFXAttachment() const;
	void KillCurrentPet_Derived();
	void Update_Derived(const float _arg0_, ArkNpc& _arg1_);
#endif
};
#endif // MOONCRASH
