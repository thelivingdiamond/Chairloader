// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <_unknown/CGameObjectExtensionHelper.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct IParticleEffect;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkPhantomThermogenesisBlast
// Header:  Prey/GameDll/ark/weapons/ArkPhantomThermogenesisBlast.h
class CArkPhantomThermogenesisBlast : public CGameObjectExtensionHelper<CArkPhantomThermogenesisBlast, IGameObjectExtension>
{ // Size=248 (0xF8)
public:
	ArkFireAndForgetEffect m_telegraphEffect;
	ArkFireAndForgetEffect m_explosionEffect;
	ArkAudioTrigger m_telegraphTrigger;
	ArkAudioTrigger m_explosionTrigger;
	uint64_t m_packageId;
	bool m_bHasDealtDamage;
	bool m_bHasExploded;
	float m_explosionDuration;
	float m_explosionDelayTimer;
	float m_explosionRadius;
	float m_explosionDamage;
	float m_explosionDamageDelayTimer;
	float m_explosionImpulse;
	float m_minimumSignalPercent;
	unsigned m_owningEntity;

	CArkPhantomThermogenesisBlast();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	void SetParticleEffects(IParticleEffect* _pTelegraph, IParticleEffect* _pExplosion) { FSetParticleEffects(this, _pTelegraph, _pExplosion); }
	void SetDelayTime(float _delayTime) { FSetDelayTime(this, _delayTime); }
	void SetExplosionsRadius(float _explosionRadius) { FSetExplosionsRadius(this, _explosionRadius); }
	void SetOwningEntity(unsigned _owner) { FSetOwningEntity(this, _owner); }
	void StartExplosionTelegraph() { FStartExplosionTelegraph(this); }
	void LoadScriptVariables() { FLoadScriptVariables(this); }

#if 0
	void SetExplosionDamage(float _arg0_);
	void SetExplosionDuration(float _arg0_);
	void StartExplosion();
	void ApplyDamageEffects() const;
#endif

	static inline auto FCArkPhantomThermogenesisBlastOv2 = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x1768080);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkPhantomThermogenesisBlast* const _this, ICrySizer* _s)>(0x17682A0);
	static inline auto FInit = PreyFunction<bool(CArkPhantomThermogenesisBlast* const _this, IGameObject* _pGameObject)>(0x17682C0);
	static inline auto FPostInit = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, IGameObject* _pGameObject)>(0x147BE20);
	static inline auto FInitClient = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkPhantomThermogenesisBlast* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkPhantomThermogenesisBlast* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, TSerialize _ser)>(0x1768180);
	static inline auto FNetSerialize = PreyFunction<bool(CArkPhantomThermogenesisBlast* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkPhantomThermogenesisBlast* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1768950);
	static inline auto FHandleEvent = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, bool _auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkPhantomThermogenesisBlast* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x1333E90);
	static inline auto FSetParticleEffects = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, IParticleEffect* _pTelegraph, IParticleEffect* _pExplosion)>(0x17688C0);
	static inline auto FSetDelayTime = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, float _delayTime)>(0x1768890);
	static inline auto FSetExplosionsRadius = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, float _explosionRadius)>(0x17688A0);
	static inline auto FSetOwningEntity = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this, unsigned _owner)>(0x17688B0);
	static inline auto FStartExplosionTelegraph = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x1768900);
	static inline auto FLoadScriptVariables = PreyFunction<void(CArkPhantomThermogenesisBlast* const _this)>(0x17682F0);
};
#endif // MOONCRASH
