// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkempblast.h
class CArkEMPBlast : public CGameObjectExtensionHelper<CArkEMPBlast,IGameObjectExtension> // Id=801BBFB Size=152
{
public:
	_smart_ptr<IParticleEmitter> m_telegraphEmitter;
	IParticleEffect *m_pTelegraphEffect;
	ArkAudioTrigger m_telegraphTrigger;
	_smart_ptr<IParticleEmitter> m_explosionEmitter;
	IParticleEffect *m_pExplosionEffect;
	ArkAudioTrigger m_explosionTrigger;
	uint64_t m_packageId;
	bool m_bHasDealtDamage;
	bool m_bHasExploded;
	float m_minimumDamagePercent;
	float m_explosionDuration;
	float m_explosionDelayTimer;
	float m_explosionRadius;
	float m_explosionDamage;
	float m_explosionDamageDelayTimer;
	unsigned m_owningEntity;
	
	CArkEMPBlast();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void StartExplosion() { FStartExplosion(this); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	virtual ~CArkEMPBlast();
	
#if 0
	void SetDelayTime(float arg0);
	void SetExplosionsRadius(float arg0);
	void SetExplosionDamage(float arg0);
	void SetExplosionDuration(float arg0);
	void SetOwningEntity(unsigned arg0);
	void StartExplosionTelegraph();
	void ApplyDamageEffects() const;
	void StartParticleEmitterNonUniformScale(_smart_ptr<IParticleEmitter> &arg0, IParticleEffect &arg1, float arg2, float arg3, float arg4) const;
	void StartParticleEmitterUniformScale(_smart_ptr<IParticleEmitter> &arg0, IParticleEffect &arg1, float arg2);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkEMPBlast const *const _this, ICrySizer *_s)>(0x137E8D0);
	static inline auto FInit = PreyFunction<bool(CArkEMPBlast *const _this, IGameObject *_pGameObject)>(0x137E8F0);
	static inline auto FPostInit = PreyFunction<void(CArkEMPBlast *const _this, IGameObject *_pGameObject)>(0x137EE60);
	static inline auto FInitClient = PreyFunction<void(CArkEMPBlast *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkEMPBlast *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkEMPBlast *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkEMPBlast *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkEMPBlast *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkEMPBlast *const _this)>(0x137EE80);
	static inline auto FFullSerialize = PreyFunction<void(CArkEMPBlast *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkEMPBlast *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkEMPBlast *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkEMPBlast *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkEMPBlast *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkEMPBlast *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x137F0B0);
	static inline auto FHandleEvent = PreyFunction<void(CArkEMPBlast *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkEMPBlast *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(CArkEMPBlast *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkEMPBlast *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkEMPBlast const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkEMPBlast *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkEMPBlast *const _this)>(0xA13080);
	static inline auto FStartExplosion = PreyFunction<void(CArkEMPBlast *const _this)>(0x137EEF0);
	static inline auto FLoadScriptVariables = PreyFunction<void(CArkEMPBlast *const _this)>(0x137E920);
};

