// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

class ICrySizer;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class SmartScriptTable;

// Header: Exact
// Prey/GameDll/ark/arkethericfogentity.h
class CArkEthericFogEntity : public CGameObjectExtensionHelper<CArkEthericFogEntity,IGameObjectExtension> // Id=801905F Size=384
{
public:
	ArkEntityEffect m_spawnEffect;
	ArkEntityEffect m_loopEffect;
	ArkAudioTrigger m_spawnTrigger;
	ArkAudioTrigger m_loopTrigger;
	float m_debugDisplayRefreshTimer;
	float m_radius;
	float m_height;
	float m_ethericFogLifetime;
	float m_damageTickRate;
	float m_damageTimer;
	bool m_bIsSmallFogFragment;
	uint64_t m_fogHitPackageId;
	
	CArkEthericFogEntity();
	virtual ~CArkEthericFogEntity();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	void SetSmallAttributes(bool _bFromLoad) { FSetSmallAttributes(this,_bFromLoad); }
	void SetLargeAttributes(bool _bFromLoad) { FSetLargeAttributes(this,_bFromLoad); }
	void StartFogEffects(bool _bFromLoad) { FStartFogEffects(this,_bFromLoad); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }
	
#if 0
	float GetRadius() const;
	void AttachParticleEmitter(IParticleEffect &arg0) const;
	void ApplyDamageEffects();
	IParticleEffect *LoadEffect(const char *const arg0, SmartScriptTable const &arg1) const;
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkEthericFogEntity *const _this, IGameObject *_pGameObject)>(0x142C380);
	static inline auto FUpdate = PreyFunction<void(CArkEthericFogEntity *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x142CF10);
	static inline auto FProcessEvent = PreyFunction<void(CArkEthericFogEntity *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FInitClient = PreyFunction<void(CArkEthericFogEntity *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(CArkEthericFogEntity *const _this, IGameObject *_pGameObject)>(0x137EE60);
	static inline auto FPostInitClient = PreyFunction<void(CArkEthericFogEntity *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkEthericFogEntity *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkEthericFogEntity *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkEthericFogEntity *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkEthericFogEntity *const _this)>(0x142C770);
	static inline auto FFullSerialize = PreyFunction<void(CArkEthericFogEntity *const _this, TSerialize _ser)>(0x142C240);
	static inline auto FNetSerialize = PreyFunction<bool(CArkEthericFogEntity *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkEthericFogEntity *const _this)>(0x142C720);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkEthericFogEntity *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkEthericFogEntity *const _this)>(0x13883F0);
	static inline auto FPostUpdate = PreyFunction<void(CArkEthericFogEntity *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkEthericFogEntity *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkEthericFogEntity *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(CArkEthericFogEntity *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkEthericFogEntity *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkEthericFogEntity const *const _this, ICrySizer *_pS)>(0x142C350);
	static inline auto FSetSmallAttributes = PreyFunction<void(CArkEthericFogEntity *const _this, bool _bFromLoad)>(0x142CB30);
	static inline auto FSetLargeAttributes = PreyFunction<void(CArkEthericFogEntity *const _this, bool _bFromLoad)>(0x142C7B0);
	static inline auto FStartFogEffects = PreyFunction<void(CArkEthericFogEntity *const _this, bool _bFromLoad)>(0x142CEB0);
	static inline auto FLoadScriptVariables = PreyFunction<void(CArkEthericFogEntity *const _this)>(0x142C3B0);
};

