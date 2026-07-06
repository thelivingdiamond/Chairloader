// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

class ArkSafeScriptTable;
class ArkTurret;
struct ArkTurretProperties;
enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkTurretWeapon
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeapon.h
class ArkTurretWeapon : public CGameObjectExtensionHelper<ArkTurretWeapon, IGameObjectExtension>
{ // Size=296 (0x128)
public:
	EntityEffects::CEffectsController m_effectController;
	ArkEntityAttachmentEffect m_windUpEffect;
	ArkEntityAttachmentEffect m_cooldownEffect;
	float m_firingActiveTime;
	float m_firingDeactiveTime;
	unsigned m_turretAttachmentCrc;
	bool m_bShouldShoot;

	ArkTurretWeapon();
	virtual ~ArkTurretWeapon();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual void GetMemoryUsage(ICrySizer* _pSize) const;
	void LoadProperties(const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties) { FLoadProperties(this, _weaponTable, _properties); }
	void OnWindup() { FOnWindup(this); }
	void OnCooldown() { FOnCooldown(this); }
	void OnTurretModelChanged() { FOnTurretModelChanged(this); }
	void StartFire() { FStartFire(this); }
	void StopFire() { FStopFire(this); }
	bool IsFiring() const { return FIsFiring(this); }
	float GetActiveShootingTime() const { return FGetActiveShootingTime(this); }
	float GetDeactiveShootingTime() const { return FGetDeactiveShootingTime(this); }
	virtual Vec3 GetAttackTargetPositionToLeadTarget(unsigned _targetEntityId, float _hitPercentage) const;
	ArkTurret& GetTurret() { return FGetTurretOv1(this); }
	QuatT GetWorldTm() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetWorldTm(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	Vec3 GetShootDirToHitTarget() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetShootDirToHitTarget(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetShootDirToMissTarget(float _spreadInRadians) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetShootDirToMissTarget(this, reinterpret_cast<Vec3*>(_return_buf_), _spreadInRadians); }
	virtual void DoPostInit() = 0;
	virtual void DoRelease() = 0;
	virtual void DoUpdate(SEntityUpdateContext& _ctx) = 0;
	virtual void DoFullSerialize(TSerialize _ser) = 0;
	virtual void DoPostSerialize() = 0;
	virtual void DoLoadProperties(const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties) = 0;
	virtual void DoOnTurretModelChanged() = 0;
	virtual void DoOnCreatedModel() = 0;
	virtual void DoOnDestroyedModel() = 0;
	virtual void DoStartFire() = 0;
	virtual void DoStopFire() = 0;

#if 0
	const ArkTurret& GetTurret() const;
#endif

	static inline auto FArkTurretWeaponOv1 = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13CF450);
	static inline auto FBitNotArkTurretWeapon = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13CF4E0);
	static inline auto FInit = PreyFunction<bool(ArkTurretWeapon* const _this, IGameObject* _pGameObject)>(0x13CFE20);
	static inline auto FInitClient = PreyFunction<void(ArkTurretWeapon* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkTurretWeapon* const _this, IGameObject* _pGameObject)>(0x13D01F0);
	static inline auto FPostInitClient = PreyFunction<void(ArkTurretWeapon* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkTurretWeapon* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkTurretWeapon* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkTurretWeapon* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D0250);
	static inline auto FFullSerialize = PreyFunction<void(ArkTurretWeapon* const _this, TSerialize _ser)>(0x13CF5D0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkTurretWeapon* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D0230);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkTurretWeapon* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkTurretWeapon* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkTurretWeapon* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x13D0320);
	static inline auto FPostUpdate = PreyFunction<void(ArkTurretWeapon* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkTurretWeapon* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkTurretWeapon* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkTurretWeapon* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(ArkTurretWeapon* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkTurretWeapon* const _this, bool _auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeapon* const _this, ICrySizer* _pSize)>(0x13CF6E0);
	static inline auto FLoadProperties = PreyFunction<void(ArkTurretWeapon* const _this, const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties)>(0x13CFE70);
	static inline auto FOnWindup = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D01C0);
	static inline auto FOnCooldown = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D00F0);
	static inline auto FOnTurretModelChanged = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D0120);
	static inline auto FStartFire = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D0280);
	static inline auto FStopFire = PreyFunction<void(ArkTurretWeapon* const _this)>(0x13D02E0);
	static inline auto FIsFiring = PreyFunction<bool(const ArkTurretWeapon* const _this)>(0x13CFE60);
	static inline auto FGetActiveShootingTime = PreyFunction<float(const ArkTurretWeapon* const _this)>(0x1056B0);
	static inline auto FGetDeactiveShootingTime = PreyFunction<float(const ArkTurretWeapon* const _this)>(0x13CF6D0);
	static inline auto FGetAttackTargetPositionToLeadTarget = PreyFunction<Vec3*(const ArkTurretWeapon* const _this, Vec3* _return_value_, unsigned _targetEntityId, float _hitPercentage)>(0x13CF680);
	static inline auto FGetTurretOv1 = PreyFunction<ArkTurret& (ArkTurretWeapon* const _this)>(0x13CFA60);
	static inline auto FGetWorldTm = PreyFunction<QuatT*(const ArkTurretWeapon* const _this, QuatT* _return_value_)>(0x13CFA70);
	static inline auto FGetShootDirToHitTarget = PreyFunction<Vec3*(const ArkTurretWeapon* const _this, Vec3* _return_value_)>(0x13CF710);
	static inline auto FGetShootDirToMissTarget = PreyFunction<Vec3*(const ArkTurretWeapon* const _this, Vec3* _return_value_, float _spreadInRadians)>(0x13CF8A0);
};
#endif // MOONCRASH
