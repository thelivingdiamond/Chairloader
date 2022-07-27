// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkEmotionExtension.h
class ArkEmotionExtension : public CGameObjectExtensionHelper<ArkEmotionExtension,IArkEmotionExtension> // Id=8019007 Size=80
{
public:
	uint64_t m_emotionId;
	int m_nAnimLayer;
	
	ArkEmotionExtension();
	virtual void SetEmotion(uint64_t _emotionId, float _blend);
	virtual void ClearEmotion(float _blend);
	virtual uint64_t GetCurrentEmotion() const;
	virtual void Release();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &__formal);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *__formal) const;
	
	static inline auto FSetEmotion = PreyFunction<void(ArkEmotionExtension *const _this, uint64_t _emotionId, float _blend)>(0x115A200);
	static inline auto FClearEmotion = PreyFunction<void(ArkEmotionExtension *const _this, float _blend)>(0x1159E90);
	static inline auto FGetCurrentEmotion = PreyFunction<uint64_t(ArkEmotionExtension const *const _this)>(0x855C80);
	static inline auto FRelease = PreyFunction<void(ArkEmotionExtension *const _this)>(0xA97D40);
	static inline auto FInit = PreyFunction<bool(ArkEmotionExtension *const _this, IGameObject *_pGameObject)>(0x115A060);
	static inline auto FInitClient = PreyFunction<void(ArkEmotionExtension *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkEmotionExtension *const _this, IGameObject *pGameObject)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkEmotionExtension *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkEmotionExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkEmotionExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkEmotionExtension *const _this, TSerialize signature)>(0x1B933B0);
	static inline auto FFullSerialize = PreyFunction<void(ArkEmotionExtension *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(ArkEmotionExtension *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkEmotionExtension *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkEmotionExtension *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkEmotionExtension *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkEmotionExtension *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkEmotionExtension *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkEmotionExtension *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkEmotionExtension *const _this, SGameObjectEvent const &__formal)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkEmotionExtension *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(ArkEmotionExtension *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkEmotionExtension *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkEmotionExtension const *const _this, ICrySizer *__formal)>(0xA13080);
};

