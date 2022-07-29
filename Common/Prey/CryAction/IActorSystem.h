#pragma once

#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

struct HitInfo;
struct IAnimatedCharacter;
struct IAnimationGraphState;
class IArkSpeaker;
struct IEntity;
struct IInventory;
struct IItem;
struct IMovementController;
struct IPhysicalEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;
class CCryActor;

// Header: Exact
// CryEngine/cryaction/iactorsystem.h
struct IActor : public IGameObjectExtension // Id=8001EFE Size=64
{
	struct TrackviewLookPoseData // Id=8001F59 Size=20
	{
		float m_blendInTime;
		float m_smoothTime;
		float m_blendOutTime;
		float m_maxRadiansYaw;
		float m_maxRadiansPitch;
	};

	virtual ~IActor();
	virtual void SetHealth(float arg0) = 0;
	virtual float GetHealth() const = 0;
	virtual int GetHealthAsRoundedPercentage() const = 0;
	virtual void SetMaxHealth(float arg0) = 0;
	virtual float GetMaxHealth() const = 0;
	virtual int GetArmor() const = 0;
	virtual int GetMaxArmor() const = 0;
	virtual int GetTeamId() const = 0;
	virtual bool IsFallen() const = 0;
	virtual bool IsDead() const = 0;
	virtual int IsGod() = 0;
	virtual void Fall(Vec3 arg0) = 0;
	virtual bool AllowLandingBob() = 0;
	virtual EStance GetLockedStance();
	virtual EStance GetStance() const = 0;
	virtual void PlayAction(const char* arg0, const char* arg1, bool arg2) = 0;
	virtual IAnimationGraphState* GetAnimationGraphState() = 0;
	virtual void ResetAnimationState() = 0;
	virtual void CreateScriptEvent(const char* arg0, float arg1, const char* arg2) = 0;
	virtual bool BecomeAggressiveToAgent(unsigned arg0) = 0;
	virtual void SetFacialAlertnessLevel(int arg0) = 0;
	virtual void RequestFacialExpression(const char* arg0, float* arg1) = 0;
	virtual void PrecacheFacialExpression(const char* arg0) = 0;
	virtual unsigned GetGrabbedEntityId() const = 0;
	virtual void HideAllAttachments(bool arg0) = 0;
	virtual void SetIKPos(const char* arg0, Vec3 const& arg1, int arg2) = 0;
	virtual void SetViewRotation(Quat const& arg0) = 0;
	virtual Quat GetViewRotation() const = 0;
	virtual bool IsFriendlyEntity(unsigned arg0, bool arg1) const = 0;
	virtual Vec3 GetLocalEyePos() const = 0;
	virtual void CameraShake(float arg0, float arg1, float arg2, float arg3, Vec3 arg4, int arg5, const char* arg6) = 0;
	virtual IItem* GetHolsteredItem() const = 0;
	virtual void HolsterItem(bool arg0, bool arg1, float arg2, bool arg3) = 0;
	virtual IItem* GetCurrentItem() const = 0;
	virtual bool DropItem(unsigned arg0, float arg1, bool arg2, bool arg3) = 0;
	virtual IInventory* GetInventory() const = 0;
	virtual void NotifyCurrentItemChanged(IItem* arg0) = 0;
	virtual IMovementController* GetMovementController() const = 0;
	virtual IEntity* GetLinkedEntity() const = 0;
	virtual uint8_t GetSpectatorMode() const = 0;
	virtual bool IsThirdPerson() const = 0;
	virtual void ToggleThirdPerson() = 0;
	virtual bool IsStillWaitingOnServerUseResponse() const;
	virtual void SetStillWaitingOnServerUseResponse(bool waiting);
	virtual void SetFlyMode(uint8_t flyMode, const float _fSpeed);
	virtual uint8_t GetFlyMode() const;
	virtual void Release() = 0;
	virtual bool IsPlayer() const = 0;
	virtual bool IsClient() const = 0;
	virtual bool IsMigrating() const = 0;
	virtual void SetMigrating(bool arg0) = 0;
	virtual void InitLocalPlayer() = 0;
	virtual const char* GetActorClassName() const = 0;
	virtual int GetActorClass() const = 0;
	virtual const char* GetEntityClassName() const = 0;
	virtual void SerializeXML(XmlNodeRef& arg0, bool arg1) = 0;
	virtual void SerializeLevelToLevel(TSerialize& arg0) = 0;
	virtual void ProcessEvent(SEntityEvent& arg0) = 0;
	virtual IAnimatedCharacter* GetAnimatedCharacter() = 0;
	virtual IAnimatedCharacter const* GetAnimatedCharacter() const = 0;
	virtual void PlayExactPositioningAnimation(const char* arg0, bool arg1, Vec3 const& arg2, Vec3 const& arg3, float arg4, float arg5, float arg6) = 0;
	virtual void CancelExactPositioningAnimation() = 0;
	virtual void PlayAnimation(const char* arg0, bool arg1) = 0;
	virtual void SetTrackviewArkLookAt(IEntity* _pTargetEntity, IActor::TrackviewLookPoseData const& _torso, IActor::TrackviewLookPoseData const& _head, IActor::TrackviewLookPoseData const& _eyes);
	virtual void SetTrackviewArkAimAt(IEntity* _pTargetEntity, IActor::TrackviewLookPoseData const& _aim);
	virtual IArkSpeaker* GetArkSpeaker() = 0;
	virtual bool Respawn();
	virtual void ResetToSpawnLocation();
	virtual bool CanBreakGlass() const;
	virtual bool MustBreakGlass() const;
	virtual void EnableTimeDemo(bool arg0) = 0;
	virtual void SetChannelId(uint16_t id);
	virtual void SwitchDemoModeSpectator(bool arg0) = 0;
	virtual void SetCustomHead(const char* customHead);
	virtual void OnAIProxyEnabled(bool arg0) = 0;
	virtual void OnReturnedToPool() = 0;
	virtual void OnPreparedFromPool() = 0;
	virtual void MountedGunControllerEnabled(bool val);
	virtual bool MountedGunControllerEnabled() const;
	virtual bool ShouldMuteWeaponSoundStimulus() const = 0;
	virtual int GetPhysicalSkipEntities(IPhysicalEntity** pSkipList, const int maxSkipSize) const;
	virtual void OnReused(IEntity* arg0, SEntitySpawnParams& arg1) = 0;
	virtual void OnFakeHitToHitReactions(HitInfo const& _hitInfo);
	virtual Vec3 GetAttackTargetPos() const;
	virtual bool IsArkNpcPlayer();
	virtual void IgnoreCollisionSignals(unsigned _entityId, float _timeOut);
	virtual bool IsIgnoringCollisionSignals(unsigned _entityId) const;
	virtual bool IsZeroG() const;

#if 0
	uint16_t GetChannelId() const;
#endif

	static inline auto FGetLockedStance = PreyFunction<EStance(IActor* const _this)>(0x154FB00);
	static inline auto FIsStillWaitingOnServerUseResponse = PreyFunction<bool(IActor const* const _this)>(0xDD23F0);
	static inline auto FSetStillWaitingOnServerUseResponse = PreyFunction<void(IActor* const _this, bool waiting)>(0xA13080);
	static inline auto FSetFlyMode = PreyFunction<void(IActor* const _this, uint8_t flyMode, const float _fSpeed)>(0xA13080);
	static inline auto FGetFlyMode = PreyFunction<uint8_t(IActor const* const _this)>(0xDD23F0);
	static inline auto FSetTrackviewArkLookAt = PreyFunction<void(IActor* const _this, IEntity* _pTargetEntity, IActor::TrackviewLookPoseData const& _torso, IActor::TrackviewLookPoseData const& _head, IActor::TrackviewLookPoseData const& _eyes)>(0xA13080);
	static inline auto FSetTrackviewArkAimAt = PreyFunction<void(IActor* const _this, IEntity* _pTargetEntity, IActor::TrackviewLookPoseData const& _aim)>(0xA13080);
	static inline auto FRespawn = PreyFunction<bool(IActor* const _this)>(0x1512280);
	static inline auto FResetToSpawnLocation = PreyFunction<void(IActor* const _this)>(0x1512260);
	static inline auto FCanBreakGlass = PreyFunction<bool(IActor const* const _this)>(0xDD23F0);
	static inline auto FMustBreakGlass = PreyFunction<bool(IActor const* const _this)>(0xDD23F0);
	static inline auto FSetChannelId = PreyFunction<void(IActor* const _this, uint16_t id)>(0x15573A0);
	static inline auto FSetCustomHead = PreyFunction<void(IActor* const _this, const char* customHead)>(0xA13080);
	static inline auto FMountedGunControllerEnabledOv1 = PreyFunction<void(IActor* const _this, bool val)>(0xA13080);
	static inline auto FMountedGunControllerEnabledOv0 = PreyFunction<bool(IActor const* const _this)>(0xDD23F0);
	static inline auto FGetPhysicalSkipEntities = PreyFunction<int(IActor const* const _this, IPhysicalEntity** pSkipList, const int maxSkipSize)>(0x158AEF0);
	static inline auto FOnFakeHitToHitReactions = PreyFunction<void(IActor* const _this, HitInfo const& _hitInfo)>(0xA13080);
	static inline auto FGetAttackTargetPos = PreyFunction<Vec3(IActor const* const _this)>(0x610560);
	static inline auto FIsArkNpcPlayer = PreyFunction<bool(IActor* const _this)>(0xDD23F0);
	static inline auto FIgnoreCollisionSignals = PreyFunction<void(IActor* const _this, unsigned _entityId, float _timeOut)>(0xA13080);
	static inline auto FIsIgnoringCollisionSignals = PreyFunction<bool(IActor const* const _this, unsigned _entityId)>(0xDD23F0);
	static inline auto FIsZeroG = PreyFunction<bool(IActor const* const _this)>(0xDD23F0);
};

class CActor : public IActor // Id=8013CD8 Size=64
{
public:
	virtual QuatT const& GetBoneTransform(int arg0) const = 0;
	virtual CCryActor* ToCryActor();
	virtual ~CActor();

	static inline auto FToCryActor = PreyFunction<CCryActor* (CActor* const _this)>(0x158AEF0);
};
