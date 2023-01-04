// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkBreakableListener.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerMimicTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkInputLegend;
class ArkPsiPowerTargetingComponent;
class CCryName;
enum class EArkPsiPowerError;
enum class EArkPsiPowers;
enum class EStance;
class IArkPlayerMimic;
struct IEntity;
struct SViewParams;

// CArkPsiPowerMimic
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMimic.h
class CArkPsiPowerMimic : public CArkPsiPower<MimicPowerProperties>, public IArkBreakableListener
{ // Size=808 (0x328)
public:
	using BaseType = CArkPsiPower<MimicPowerProperties>;

	ArkPsiPowerMimicTargetingComponent m_targetingComponent;
	ArkSimpleTimer m_morphOutTimer;
	ArkSimpleTimer m_gameNoiseTimer;
	QuatT m_initialWorldTransform;
	Vec3 m_initialVelocity;
	Vec3 m_safeWorldPosition;
	std::vector<unsigned int> m_cameraOverlappingEntities;
	std::unique_ptr<IArkPlayerMimic> m_pPsiMimic;
	unsigned m_clonedEntityId;
	int m_persistentParticleEffectSlot;
	bool m_bMorphingIn;
	bool m_bMorphingOut;
	bool m_bPendingMorphIn;
	bool m_bDelayMorphInFrame;

	CArkPsiPowerMimic();
	virtual ~CArkPsiPowerMimic();
	virtual void Cancel();
	virtual void OnReset();
	virtual void Update(const float _frameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual void RefreshTargets();
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual bool CanEnterFocusMode(const EArkPsiPowers& _equippedPower) const;
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _serializer);
	virtual void PostSerialize();
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual bool ShouldGenerateGameNoises() const;
	virtual void OnBroken(const IEntity& _entity);
	bool MorphOut() { return FMorphOut(this); }
	void FinishMorphIn() { FFinishMorphIn(this); }
	void MorphInObject() { FMorphInObject(this); }
	bool IsInZeroG() const { return FIsInZeroG(this); }
	float GetMimicVisibility() const { return FGetMimicVisibility(this); }
	unsigned GetTargetedEntityId() const { return FGetTargetedEntityId(this); }
	unsigned GetMimickedEntityId() const { return FGetMimickedEntityId(this); }
	void CleanUp() { FCleanUp(this); }
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual bool GetCanCancel() const;
	void UpdateCamera(SViewParams& _params) { FUpdateCamera(this, _params); }
	virtual void SetLevel_Derived(const int _level);
	virtual EArkPsiPowerError GetExecutionError() const;
	bool PlayerCanFit(const EStance _stance, const Vec3& _position) const { return FPlayerCanFit(this, _stance, _position); }
	boost::optional<QuatT_tpl<float> > ComputeInitialWorldTransform(const IEntity& _targetEntity) const { alignas(boost::optional<QuatT_tpl<float> >) std::byte _return_buf_[sizeof(boost::optional<QuatT_tpl<float> >)]; return *FComputeInitialWorldTransform(this, reinterpret_cast<boost::optional<QuatT_tpl<float> >*>(_return_buf_), _targetEntity); }
	bool FilterTarget(const IEntity& _entity) const { return FFilterTarget(this, _entity); }

#if 0
	bool QueueMorphInAction();
#endif

	static inline auto FCArkPsiPowerMimic = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159ABA0);
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159AF80);
	static inline auto FOnReset = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159C780);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerMimic* const _this, const float _frameTime)>(0x159DC80);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerMimic* const _this)>(0x159D560);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerMimic* const _this, const float _fFrameTime)>(0x159E610);
	static inline auto FRefreshTargets = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159D0F0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerMimic* const _this, std::vector<IEntity*>* _return_value_)>(0x15A2A60);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerMimic* const _this, std::vector<IEntity*>* _return_value_)>(0x15A2A80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerMimic* const _this, Vec3* _return_value_)>(0x159BFC0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPowerMimic* const _this)>(0x159BEA0);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const CArkPsiPowerMimic* const _this, const EArkPsiPowers& _equippedPower)>(0x159AF60);
	static inline auto FProcessInput = PreyFunction<void(CArkPsiPowerMimic* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x159D020);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerMimic* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerMimic* const _this, TSerialize _serializer)>(0x159D150);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159CEF0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerMimic* const _this)>(0x222910);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerMimic* const _this)>(0x1C4890);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(const CArkPsiPowerMimic* const _this)>(0x159D4D0);
	static inline auto FOnBroken = PreyFunction<void(IArkBreakableListener* const _this, const IEntity& _entity)>(0x159C700);
	static inline auto FMorphOut = PreyFunction<bool(CArkPsiPowerMimic* const _this)>(0x159C110);
	static inline auto FFinishMorphIn = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159B850);
	static inline auto FMorphInObject = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159C040);
	static inline auto FIsInZeroG = PreyFunction<bool(const CArkPsiPowerMimic* const _this)>(0x159C010);
	static inline auto FGetMimicVisibility = PreyFunction<float(const CArkPsiPowerMimic* const _this)>(0x159BD50);
	static inline auto FGetTargetedEntityId = PreyFunction<unsigned(const CArkPsiPowerMimic* const _this)>(0x159C000);
	static inline auto FGetMimickedEntityId = PreyFunction<unsigned(const CArkPsiPowerMimic* const _this)>(0x159BE80);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerMimic* const _this)>(0x159AF90);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerMimic* const _this)>(0x159D8F0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerMimic* const _this)>(0x159D590);
	static inline auto FGetCanCancel = PreyFunction<bool(const CArkPsiPowerMimic* const _this)>(0x159BB50);
	static inline auto FUpdateCamera = PreyFunction<void(CArkPsiPowerMimic* const _this, SViewParams& _params)>(0x159E4A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerMimic* const _this, const int _level)>(0x159D3F0);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(const CArkPsiPowerMimic* const _this)>(0x15A22E0);
	static inline auto FPlayerCanFit = PreyFunction<bool(const CArkPsiPowerMimic* const _this, const EStance _stance, const Vec3& _position)>(0x159C7A0);
	static inline auto FComputeInitialWorldTransform = PreyFunction<boost::optional<QuatT_tpl<float> >*(const CArkPsiPowerMimic* const _this, boost::optional<QuatT_tpl<float> >* _return_value_, const IEntity& _targetEntity)>(0x159B150);
	static inline auto FFilterTarget = PreyFunction<bool(const CArkPsiPowerMimic* const _this, const IEntity& _entity)>(0x159B600);
};

