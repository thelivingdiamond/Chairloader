// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryCore/functor.h>

enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IParticleEffect;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CLightningArc
// Header:  Prey/GameDll/environment/LightningArc.h
class CLightningArc : public CGameObjectExtensionHelper<CLightningArc, IGameObjectExtension>
{ // Size=208 (0xD0)
public:
	using LightningCallback = Functor3<IEntity *,IEntity *,float>;

	const char* m_lightningPreset;
	float m_delay;
	float m_delayVariation;
	float m_timer;
	bool m_enabled;
	bool m_inGameMode;
	bool m_bCheckLOS;
	unsigned m_ownerId;
	Functor3<IEntity *,IEntity *,float> m_callback;
	Vec3 m_receiverLocalPosition;
	Vec3 m_fixedDestPosition;
	bool m_bFixedDestPosition;
	IEntity* m_pSourceEntity;
	Vec3 m_sourceOffset;
	int m_sourceCharacterAttachmentSlot;
	unsigned m_sourceCharacterAttachmentNameCRC;
	IParticleEffect* m_pTargetParticle;
	IParticleEffect* m_pSourceParticle;

	CLightningArc();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual bool Init(IGameObject* pGameObject);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	bool TriggerSpark() { return FTriggerSpark(this); }
	void ReadLuaParameters() { FReadLuaParameters(this); }
	void SetFixedDestPosition(const Vec3& fixedDestPosition) { FSetFixedDestPosition(this, fixedDestPosition); }
	void SetSourceAttachment(unsigned _attachmentCrc, int _characterSlot) { FSetSourceAttachment(this, _attachmentCrc, _characterSlot); }
	void Enable_Internal(bool _bEnable, bool _bInGame) { FEnable_Internal(this, _bEnable, _bInGame); }

#if 0
	void Enable(bool _arg0_);
	void SetOwnerId(unsigned _arg0_);
	void SetCallback(Functor3<IEntity *,IEntity *,float> _arg0_);
	void SetReceiverLocalPosition(const Vec3 _arg0_);
	void SetReady();
	void SetSourceEntity(IEntity* _arg0_);
	void SetSourceOffset(const Vec3& _arg0_);
	void Reset(bool _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FCLightningArcOv2 = PreyFunction<void(CLightningArc* const _this)>(0x16BD5E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CLightningArc* const _this, ICrySizer* pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(CLightningArc* const _this, IGameObject* pGameObject)>(0x16BD740);
	static inline auto FPostInit = PreyFunction<void(CLightningArc* const _this, IGameObject* pGameObject)>(0x16BD790);
	static inline auto FInitClient = PreyFunction<void(CLightningArc* const _this, int channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CLightningArc* const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CLightningArc* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(CLightningArc* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CLightningArc* const _this, TSerialize signature)>(0x1B933B0);
	static inline auto FRelease = PreyFunction<void(CLightningArc* const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(CLightningArc* const _this, TSerialize ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CLightningArc* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CLightningArc* const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CLightningArc* const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CLightningArc* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CLightningArc* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x16BE470);
	static inline auto FHandleEvent = PreyFunction<void(CLightningArc* const _this, const SGameObjectEvent& event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CLightningArc* const _this, SEntityEvent& event)>(0x16BD7E0);
	static inline auto FSetChannelId = PreyFunction<void(CLightningArc* const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CLightningArc* const _this, bool auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CLightningArc* const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CLightningArc* const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CLightningArc* const _this)>(0xA13080);
	static inline auto FTriggerSpark = PreyFunction<bool(CLightningArc* const _this)>(0x16BDBA0);
	static inline auto FReadLuaParameters = PreyFunction<void(CLightningArc* const _this)>(0x16BD870);
	static inline auto FSetFixedDestPosition = PreyFunction<void(CLightningArc* const _this, const Vec3& fixedDestPosition)>(0x16BDB70);
	static inline auto FSetSourceAttachment = PreyFunction<void(CLightningArc* const _this, unsigned _attachmentCrc, int _characterSlot)>(0x16BDB90);
	static inline auto FEnable_Internal = PreyFunction<void(CLightningArc* const _this, bool _bEnable, bool _bInGame)>(0x16BD6E0);
#else
	static inline auto FCLightningArcOv2 = PreyFunction<void(CLightningArc* const _this)>(0x17E0000);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CLightningArc* const _this, ICrySizer* pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CLightningArc* const _this, IGameObject* pGameObject)>(0x17E0160);
	static inline auto FPostInit = PreyFunction<void(CLightningArc* const _this, IGameObject* pGameObject)>(0x17E01B0);
	static inline auto FInitClient = PreyFunction<void(CLightningArc* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CLightningArc* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CLightningArc* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CLightningArc* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CLightningArc* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(CLightningArc* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CLightningArc* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CLightningArc* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CLightningArc* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CLightningArc* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CLightningArc* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CLightningArc* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x17E0E90);
	static inline auto FHandleEvent = PreyFunction<void(CLightningArc* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CLightningArc* const _this, SEntityEvent& event)>(0x17E0200);
	static inline auto FSetChannelId = PreyFunction<void(CLightningArc* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CLightningArc* const _this, bool auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CLightningArc* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CLightningArc* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CLightningArc* const _this)>(0x1333E90);
	static inline auto FTriggerSpark = PreyFunction<bool(CLightningArc* const _this)>(0x17E05C0);
	static inline auto FReadLuaParameters = PreyFunction<void(CLightningArc* const _this)>(0x17E0290);
	static inline auto FSetFixedDestPosition = PreyFunction<void(CLightningArc* const _this, const Vec3& fixedDestPosition)>(0x17E0590);
	static inline auto FSetSourceAttachment = PreyFunction<void(CLightningArc* const _this, unsigned _attachmentCrc, int _characterSlot)>(0x17E05B0);
	static inline auto FEnable_Internal = PreyFunction<void(CLightningArc* const _this, bool _bEnable, bool _bInGame)>(0x17E0100);
#endif
};

