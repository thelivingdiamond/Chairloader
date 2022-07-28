// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkSpeakerExtension.h>

class IArkSpeaker;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/ArkSpeakerExtension.h
class ArkSpeakerExtension : public CGameObjectExtensionHelper<ArkSpeakerExtension,IArkSpeakerExtension> // Id=801BDF0 Size=72
{
public:
	enum class EArkSpeakerType
	{
		prop = 0,
		npc = 1,
		last = 2,
	};

	std::unique_ptr<ArkSpeakerBase> m_pSpeaker;
	
	virtual void Release();
	virtual bool Init(IGameObject *const _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *_pGameObject);
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
	virtual IArkSpeaker *GetSpeaker();
	virtual ~ArkSpeakerExtension();
	
	static inline auto FRelease = PreyFunction<void(ArkSpeakerExtension *const _this)>(0xA97D40);
	static inline auto FInit = PreyFunction<bool(ArkSpeakerExtension *const _this, IGameObject *const _pGameObject)>(0x13D5830);
	static inline auto FInitClient = PreyFunction<void(ArkSpeakerExtension *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkSpeakerExtension *const _this, IGameObject *_pGameObject)>(0x13D6020);
	static inline auto FPostInitClient = PreyFunction<void(ArkSpeakerExtension *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkSpeakerExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkSpeakerExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkSpeakerExtension *const _this, TSerialize signature)>(0x1B933B0);
	static inline auto FFullSerialize = PreyFunction<void(ArkSpeakerExtension *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(ArkSpeakerExtension *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkSpeakerExtension *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkSpeakerExtension *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkSpeakerExtension *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkSpeakerExtension *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13D61E0);
	static inline auto FPostUpdate = PreyFunction<void(ArkSpeakerExtension *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkSpeakerExtension *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkSpeakerExtension *const _this, SGameObjectEvent const &__formal)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkSpeakerExtension *const _this, SEntityEvent &_event)>(0x13D6040);
	static inline auto FSetChannelId = PreyFunction<void(ArkSpeakerExtension *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkSpeakerExtension *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkSpeakerExtension const *const _this, ICrySizer *__formal)>(0xA13080);
	static inline auto FGetSpeaker = PreyFunction<IArkSpeaker *(ArkSpeakerExtension *const _this)>(0x855C80);
};

