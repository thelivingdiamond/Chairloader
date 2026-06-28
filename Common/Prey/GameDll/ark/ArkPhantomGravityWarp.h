// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct IParticleEffect;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class SmartScriptTable;

// CArkPhantomGravityWarp
// Header:  Prey/GameDll/ark/ArkPhantomGravityWarp.h
class CArkPhantomGravityWarp : public CGameObjectExtensionHelper<CArkPhantomGravityWarp, IGameObjectExtension>
{ // Size=168 (0xA8)
public:
	float m_initialGravityPull;
	float m_gravityPullFalloff;
	float m_gravityDamping;
	float m_gravityRadius;
	float m_gravityIncreasePerSecond;
	float m_manualPullDamping;
	float m_maxGravity;
	float m_endingEffectsTime;
	float m_explosionRadius;
	float m_explosionImpulse;
	uint64_t m_explosionPackageId;
	float m_durationTimer;
	float m_gravity;
	float m_endingEffectsTimer;
	bool m_bHasOwnerDied;
	unsigned m_owningEntityId;
	IParticleEffect* m_pSpawnEffect;
	ArkAudioTrigger m_spawnTrigger;
	IParticleEffect* m_pLoopEffect;
	ArkAudioTrigger m_loopTrigger;

	CArkPhantomGravityWarp();
	virtual ~CArkPhantomGravityWarp();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
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
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	void UpdateManualGravityPulling(SEntityUpdateContext& _ctx) { FUpdateManualGravityPulling(this, _ctx); }
	void InitGravityArea(const Vec3& _position, const float _radius, const float _gravityZ, const bool _bUniform, const float _time) { FInitGravityArea(this, _position, _radius, _gravityZ, _bUniform, _time); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }

#if 0
	void SetOwner(unsigned _arg0_);
	void SetDuration(float _arg0_);
	void InterruptWarp();
	void TriggerExplosion();
	void WakeUpEntities(const Vec3& _arg0_, const float _arg1_, const float _arg2_);
	void StartGravityPull();
	void PerformExplosion();
	void IncreaseGravity(SEntityUpdateContext& _arg0_);
	void StopGravityPull();
	bool IsOwnerDead() const;
	void AttachParticleEmitter(IParticleEffect& _arg0_, float _arg1_) const;
	IParticleEffect* LoadEffect(const char* const _arg0_, const SmartScriptTable& _arg1_) const;
#endif

	static inline auto FCArkPhantomGravityWarpOv1 = PreyFunction<void(CArkPhantomGravityWarp* const _this)>(0x14D5850);
	static inline auto FInit = PreyFunction<bool(CArkPhantomGravityWarp* const _this, IGameObject* _pGameObject)>(0x14D59A0);
	static inline auto FUpdate = PreyFunction<void(CArkPhantomGravityWarp* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14D6480);
	static inline auto FProcessEvent = PreyFunction<void(CArkPhantomGravityWarp* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkPhantomGravityWarp* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkPhantomGravityWarp* const _this, IGameObject* _pGameObject)>(0x14D6310);
	static inline auto FPostInitClient = PreyFunction<void(CArkPhantomGravityWarp* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkPhantomGravityWarp* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkPhantomGravityWarp* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkPhantomGravityWarp* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkPhantomGravityWarp* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkPhantomGravityWarp* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkPhantomGravityWarp* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPhantomGravityWarp* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkPhantomGravityWarp* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkPhantomGravityWarp* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FPostUpdate = PreyFunction<void(CArkPhantomGravityWarp* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkPhantomGravityWarp* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkPhantomGravityWarp* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CArkPhantomGravityWarp* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkPhantomGravityWarp* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkPhantomGravityWarp* const _this, ICrySizer* _pS)>(0xD42510);
	static inline auto FUpdateManualGravityPulling = PreyFunction<void(CArkPhantomGravityWarp* const _this, SEntityUpdateContext& _ctx)>(0x14D6730);
	static inline auto FInitGravityArea = PreyFunction<void(CArkPhantomGravityWarp* const _this, const Vec3& _position, const float _radius, const float _gravityZ, const bool _bUniform, const float _time)>(0x14D59D0);
	static inline auto FLoadScriptVariables = PreyFunction<void(CArkPhantomGravityWarp* const _this)>(0x14D5CC0);
};
#endif // MOONCRASH
