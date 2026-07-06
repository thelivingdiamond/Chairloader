// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerGroundTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <_unknown/ArkPetFactory.h>

class ArkNpc;
class CCryName;
enum class EArkPsiPowers;
struct IEntity;
struct SEntityEvent;

// ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h
class ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>
	: public CArkPsiPower<SummonPetMimicPowerProperties>
	, public ArkPetFactory
	, public IEntityEventListener
{ // Size=696 (0x2B8)
public:
	using BasePowerType = CArkPsiPower<SummonPetMimicPowerProperties>;

	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	unsigned m_petEntityId;
	unsigned m_petSkinMeshAttachmentEntityId;
	ArkEntityAttachmentEffect m_summonParticle;
	EntityEffects::CEffectsController m_attachmentEffectController;

	ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>();
	virtual ~ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>();
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
	void ApplyCurrentSkin() { FApplyCurrentSkin(this); }
	virtual void SetLevel_Derived(const int _level);
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	virtual bool Start_Derived();
	virtual void InitializePet_Derived(IEntity* _petEntity);
	void OnPetRemoved() { FOnPetRemoved(this); }
	void CleanupOnPetRemoval() { FCleanupOnPetRemoval(this); }
	Vec3 FindSpawnPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FFindSpawnPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	unsigned GetSummonedPetId() const;
	const char* GetSummonFX() const;
	const char* GetUnsummonFX() const;
	const char* GetSummonFXAttachment() const;
	void KillCurrentPet_Derived();
	void Update_Derived(const float _arg0_, ArkNpc& _arg1_);
#endif

	static inline auto FArkPsiPowerSummonPetLessArkPsiPowerSummonPetMimicCommaSummonPetMimicPowerPropertiesGreaterOv1 = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C23A0);
	static inline auto FBitNotArkPsiPowerSummonPetLessArkPsiPowerSummonPetMimicCommaSummonPetMimicPowerPropertiesGreater = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C2AF0);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x16AAB60);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C6220);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, const float _frameTime)>(0x13C6FF0);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, const float _frameTime)>(0x13C7070);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, TSerialize _serializer)>(0x13C5F40);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C5E50);
	static inline auto FGetPet = PreyFunction<const IEntity* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C4B20);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x995FB0);
	static inline auto FGetIcon = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C4990);
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x16C3CF0);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x13C5ED0);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13BEF50);
	static inline auto FDestroyCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C3C90);
	static inline auto FKillCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C4B50);
	static inline auto FApplySkin = PreyFunction<void(ArkPetFactory* const _this, const uint64_t _skinId)>(0x13C38D0);
	static inline auto FApplyCurrentSkin = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C3870);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, const int _level)>(0x13C60D0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13C5D90);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C6230);
	static inline auto FInitializePet_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, IEntity* _petEntity)>(0x1333E90);
	static inline auto FOnPetRemoved = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C5DA0);
	static inline auto FCleanupOnPetRemoval = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this)>(0x13C3C30);
	static inline auto FFindSpawnPosition = PreyFunction<Vec3*(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>* const _this, Vec3* _return_value_)>(0x13C3CE0);
};

// ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h
class ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>
	: public CArkPsiPower<SummonPetOperatorPowerProperties>
	, public ArkPetFactory
	, public IEntityEventListener
{ // Size=696 (0x2B8)
public:
	using BasePowerType = CArkPsiPower<SummonPetOperatorPowerProperties>;

	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	unsigned m_petEntityId;
	unsigned m_petSkinMeshAttachmentEntityId;
	ArkEntityAttachmentEffect m_summonParticle;
	EntityEffects::CEffectsController m_attachmentEffectController;

	ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>();
	virtual ~ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>();
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
	void OnPetRemoved() { FOnPetRemoved(this); }
	void CleanupOnPetRemoval() { FCleanupOnPetRemoval(this); }
	Vec3 FindSpawnPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FFindSpawnPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	unsigned GetSummonedPetId() const;
	const char* GetSummonFX() const;
	const char* GetUnsummonFX() const;
	const char* GetSummonFXAttachment() const;
	void ApplyCurrentSkin();
	void KillCurrentPet_Derived();
	void Update_Derived(const float _arg0_, ArkNpc& _arg1_);
#endif

	static inline auto FArkPsiPowerSummonPetLessArkPsiPowerSummonPetOperatorCommaSummonPetOperatorPowerPropertiesGreaterOv1 = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C2440);
	static inline auto FBitNotArkPsiPowerSummonPetLessArkPsiPowerSummonPetOperatorCommaSummonPetOperatorPowerPropertiesGreater = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C2C00);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x16AAB60);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C6220);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, const float _frameTime)>(0x13C7030);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, const float _frameTime)>(0x13C7070);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, TSerialize _serializer)>(0x13C5F40);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C5E50);
	static inline auto FGetPet = PreyFunction<const IEntity* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C4B20);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x1B399B0);
	static inline auto FGetIcon = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C49F0);
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x16C3CF0);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x13C5ED0);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13BEF50);
	static inline auto FDestroyCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C3C90);
	static inline auto FKillCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C5170);
	static inline auto FApplySkin = PreyFunction<void(ArkPetFactory* const _this, const uint64_t _skinId)>(0x13C38D0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, const int _level)>(0x13C6140);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13C5D90);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C66C0);
	static inline auto FInitializePet_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, IEntity* _petEntity)>(0x1333E90);
	static inline auto FOnPetRemoved = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C5DA0);
	static inline auto FCleanupOnPetRemoval = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this)>(0x13C3C30);
	static inline auto FFindSpawnPosition = PreyFunction<Vec3*(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetOperator,SummonPetOperatorPowerProperties>* const _this, Vec3* _return_value_)>(0x13C4080);
};

// ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h
class ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>
	: public CArkPsiPower<SummonPetTurretPowerProperties>
	, public ArkPetFactory
	, public IEntityEventListener
{ // Size=696 (0x2B8)
public:
	using BasePowerType = CArkPsiPower<SummonPetTurretPowerProperties>;

	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	unsigned m_petEntityId;
	unsigned m_petSkinMeshAttachmentEntityId;
	ArkEntityAttachmentEffect m_summonParticle;
	EntityEffects::CEffectsController m_attachmentEffectController;

	ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>();
	virtual ~ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>();
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
	void OnPetRemoved() { FOnPetRemoved(this); }
	void CleanupOnPetRemoval() { FCleanupOnPetRemoval(this); }
	Vec3 FindSpawnPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FFindSpawnPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	unsigned GetSummonedPetId() const;
	const char* GetSummonFX() const;
	const char* GetUnsummonFX() const;
	const char* GetSummonFXAttachment() const;
	void ApplyCurrentSkin();
	void KillCurrentPet_Derived();
	void Update_Derived(const float _arg0_, ArkNpc& _arg1_);
#endif

	static inline auto FArkPsiPowerSummonPetLessArkPsiPowerSummonPetTurretCommaSummonPetTurretPowerPropertiesGreaterOv1 = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C24E0);
	static inline auto FBitNotArkPsiPowerSummonPetLessArkPsiPowerSummonPetTurretCommaSummonPetTurretPowerPropertiesGreater = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C2D10);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x16AAB60);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C6220);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, const float _frameTime)>(0x13C7030);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, const float _frameTime)>(0x13C7070);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, TSerialize _serializer)>(0x13C5F40);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C5E50);
	static inline auto FGetPet = PreyFunction<const IEntity* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C4B20);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0xA56AF0);
	static inline auto FGetIcon = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C4A50);
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x16C3CF0);
	static inline auto FProcessInput = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x13C5ED0);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13BEF50);
	static inline auto FDestroyCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C3C90);
	static inline auto FKillCurrentPet = PreyFunction<void(ArkPetFactory* const _this)>(0x13C5780);
	static inline auto FApplySkin = PreyFunction<void(ArkPetFactory* const _this, const uint64_t _skinId)>(0x13C38D0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, const int _level)>(0x13C61B0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13C5D90);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C6B60);
	static inline auto FInitializePet_Derived = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, IEntity* _petEntity)>(0x1333E90);
	static inline auto FOnPetRemoved = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C5DA0);
	static inline auto FCleanupOnPetRemoval = PreyFunction<void(ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this)>(0x13C3C30);
	static inline auto FFindSpawnPosition = PreyFunction<Vec3*(const ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>* const _this, Vec3* _return_value_)>(0x13C4430);
};
#endif // MOONCRASH
