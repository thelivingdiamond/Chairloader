// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IEntity;
struct IGameObject;
struct IGameObjectExtension;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/ArkHealthExtension.h
class ArkHealthExtension : public CGameObjectExtensionHelper<ArkHealthExtension,IGameObjectExtension> // Id=80192C4 Size=72
{
public:
	float m_health;
	float m_maxHealth;
	
	virtual bool Init(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	void SetMaxHealth(const float _maxHealth) { FSetMaxHealth(this,_maxHealth); }
	void ResetToDefault() { FResetToDefault(this); }
	static ArkHealthExtension *GetExtension(unsigned _id) { return FGetExtensionOv2(_id); }
	static ArkHealthExtension &GetExtension(IGameObjectExtension const &_extension) { return FGetExtensionOv1(_extension); }
	static ArkHealthExtension const *GetExtension(IEntity const &_entity) { return FGetExtensionOv0(_entity); }
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &ctx, int );
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *) const;
	virtual ~ArkHealthExtension();
	
#if 0
	bool IsDead() const;
	void SetHealth(const float arg0);
	float GetHealth() const;
	float GetMaxHealth() const;
	void Damage(const float arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkHealthExtension *const _this, IGameObject *_pGameObject)>(0x13C9320);
	static inline auto FRelease = PreyFunction<void(ArkHealthExtension *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkHealthExtension *const _this, TSerialize _ser)>(0x11DC5B0);
	static inline auto FSetMaxHealth = PreyFunction<void(ArkHealthExtension *const _this, const float _maxHealth)>(0x13C9640);
	static inline auto FResetToDefault = PreyFunction<void(ArkHealthExtension *const _this)>(0x13C94C0);
	static inline auto FGetExtensionOv2 = PreyFunction<ArkHealthExtension *(unsigned _id)>(0x13C9250);
	static inline auto FGetExtensionOv1 = PreyFunction<ArkHealthExtension &(IGameObjectExtension const &_extension)>(0x13C9240);
	static inline auto FGetExtensionOv0 = PreyFunction<ArkHealthExtension const *(IEntity const &_entity)>(0x13C9300);
	static inline auto FInitClient = PreyFunction<void(ArkHealthExtension *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkHealthExtension *const _this, IGameObject *pGameObject)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkHealthExtension *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkHealthExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkHealthExtension *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkHealthExtension *const _this, TSerialize signature)>(0x1B933B0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkHealthExtension *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkHealthExtension *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkHealthExtension *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkHealthExtension *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkHealthExtension *const _this, SEntityUpdateContext &ctx, int )>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkHealthExtension *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkHealthExtension *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkHealthExtension *const _this, SGameObjectEvent const &)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkHealthExtension *const _this, SEntityEvent &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(ArkHealthExtension *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkHealthExtension *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkHealthExtension const *const _this, ICrySizer *)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IGameObjectExtension;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkHealthExtension
// Header:  Prey/GameDll/ark/ArkHealthExtension.h
class ArkHealthExtension : public CGameObjectExtensionHelper<ArkHealthExtension, IGameObjectExtension>
{ // Size=80 (0x50)
public:
	float m_health;
	float m_maxHealth;
	float m_baseHealth;

	virtual bool Init(IGameObject* _pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	void SetHealth(const float _health) { FSetHealth(this, _health); }
	void SetMaxHealth(const float _maxHealth) { FSetMaxHealth(this, _maxHealth); }
	void ResetToDefault() { FResetToDefault(this); }
	static ArkHealthExtension* GetExtension(unsigned _id) { return FGetExtensionOv2(_id); }
	static ArkHealthExtension& GetExtension(const IGameObjectExtension& _extension) { return FGetExtensionOv1(_extension); }
	static const ArkHealthExtension* GetExtension(const IEntity& _entity) { return FGetExtensionOv0(_entity); }
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int __unnamed1);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& __unnamed1);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* __unnamed1) const;

#if 0
	ArkHealthExtension();
	bool IsDead() const;
	float GetHealth() const;
	float GetMaxHealth() const;
	float GetBaseHealth() const;
	void Damage(const float _arg0_);
#endif

	static inline auto FInit = PreyFunction<bool(ArkHealthExtension* const _this, IGameObject* _pGameObject)>(0x14D5520);
	static inline auto FRelease = PreyFunction<void(ArkHealthExtension* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkHealthExtension* const _this, TSerialize _ser)>(0x12620D0);
	static inline auto FSetHealth = PreyFunction<void(ArkHealthExtension* const _this, const float _health)>(0x14D56D0);
	static inline auto FSetMaxHealth = PreyFunction<void(ArkHealthExtension* const _this, const float _maxHealth)>(0x14D5780);
	static inline auto FResetToDefault = PreyFunction<void(ArkHealthExtension* const _this)>(0x14D5600);
	static inline auto FGetExtensionOv2 = PreyFunction<ArkHealthExtension* (unsigned _id)>(0x14D5450);
	static inline auto FGetExtensionOv1 = PreyFunction<ArkHealthExtension& (const IGameObjectExtension& _extension)>(0x14D5440);
	static inline auto FGetExtensionOv0 = PreyFunction<const ArkHealthExtension* (const IEntity& _entity)>(0x14D5500);
	static inline auto FInitClient = PreyFunction<void(ArkHealthExtension* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkHealthExtension* const _this, IGameObject* pGameObject)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(ArkHealthExtension* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkHealthExtension* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkHealthExtension* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkHealthExtension* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkHealthExtension* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkHealthExtension* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkHealthExtension* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkHealthExtension* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkHealthExtension* const _this, SEntityUpdateContext& ctx, int __unnamed1)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(ArkHealthExtension* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkHealthExtension* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkHealthExtension* const _this, const SGameObjectEvent& __unnamed1)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkHealthExtension* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(ArkHealthExtension* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkHealthExtension* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkHealthExtension* const _this, ICrySizer* __unnamed1)>(0x1333E90);
};
#endif // !MOONCRASH
