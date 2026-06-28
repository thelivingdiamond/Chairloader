// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <_unknown/CGameObjectExtensionHelper.h>

class ArkSafeScriptTable;
enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct IParticleEffect;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkNpcWeapon
// Header:  Prey/GameDll/ark/npc/ArkNpcWeapon.h
class CArkNpcWeapon : public CGameObjectExtensionHelper<CArkNpcWeapon, IGameObjectExtension>
{ // Size=192 (0xC0)
public:
	EntityEffects::CEffectsController m_effectController;
	ArkEntityAttachmentEffect m_muzzleFlashEffect;

	CArkNpcWeapon();
	virtual ~CArkNpcWeapon();
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
	static CArkNpcWeapon* FromEntityId(unsigned pistolId) { return FFromEntityId(pistolId); }
	void LoadEffectAttachment(const string& attachmentName, IParticleEffect* particleEffect) { FLoadEffectAttachment(this, attachmentName, particleEffect); }
	void PlayEffectAttachment() { FPlayEffectAttachment(this); }

#if 0
	ArkSafeScriptTable GetPropertiesTable() const;
	void LoadModel();
#endif

	static inline auto FCArkNpcWeaponOv1 = PreyFunction<void(CArkNpcWeapon* const _this)>(0x129C640);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNpcWeapon* const _this, ICrySizer* _s)>(0x18AECC0);
	static inline auto FInit = PreyFunction<bool(CArkNpcWeapon* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FPostInit = PreyFunction<void(CArkNpcWeapon* const _this, IGameObject* _pGameObject)>(0x129C880);
	static inline auto FInitClient = PreyFunction<void(CArkNpcWeapon* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkNpcWeapon* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNpcWeapon* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNpcWeapon* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNpcWeapon* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkNpcWeapon* const _this)>(0x129C970);
	static inline auto FFullSerialize = PreyFunction<void(CArkNpcWeapon* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNpcWeapon* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CArkNpcWeapon* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNpcWeapon* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNpcWeapon* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNpcWeapon* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkNpcWeapon* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNpcWeapon* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CArkNpcWeapon* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNpcWeapon* const _this, bool _auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkNpcWeapon* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkNpcWeapon* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNpcWeapon* const _this)>(0x1333E90);
	static inline auto FFromEntityId = PreyFunction<CArkNpcWeapon* (unsigned pistolId)>(0x129C720);
	static inline auto FLoadEffectAttachment = PreyFunction<void(CArkNpcWeapon* const _this, const string& attachmentName, IParticleEffect* particleEffect)>(0x129C810);
	static inline auto FPlayEffectAttachment = PreyFunction<void(CArkNpcWeapon* const _this)>(0x129C870);
};
#endif // MOONCRASH
