// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkAttraction
// Header:  Prey/GameDll/ark/npc/CArkAttraction.h
class CArkAttraction : public CGameObjectExtensionHelper<CArkAttraction, IGameObjectExtension>
{ // Size=96 (0x60)
public:
	ArkInterval<float> m_waitPeriod;
	float m_locationRadius;
	float m_chanceToAttract;
	float m_attractionStrength;
	float m_attractionCD;
	float m_attractionCDTimer;
	bool m_bBeingUsed;
	bool m_bEnabled;

	CArkAttraction();
	virtual ~CArkAttraction();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	bool IsUseableAttractor() const { return FIsUseableAttractor(this); }
	Vec3 GetRandomPosOnNavMesh(IEntity& _navAgentEntity) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetRandomPosOnNavMeshOv0(this, reinterpret_cast<Vec3*>(_return_buf_), _navAgentEntity); }
	void Acquire() { FAcquire(this); }
	void Relinquish() { FRelinquish(this); }
	void LoadScriptData() { FLoadScriptData(this); }

#if 0
	bool IsInAnyArea() const;
	bool IsBeingUsed() const;
	bool IsOnCooldown() const;
	void SetEnabled(bool _arg0_);
	bool CanAttract() const;
	float GetAttractionStrength() const;
	float GetAttractionWaitTime() const;
	Vec3 GetRandomPos() const;
	Vec3 GetRandomPosOnNavMesh(unsigned _arg0_) const;
	void Reset();
#endif

	static inline auto FCArkAttractionOv1 = PreyFunction<void(CArkAttraction* const _this)>(0x1602EB0);
	static inline auto FInit = PreyFunction<bool(CArkAttraction* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FInitClient = PreyFunction<void(CArkAttraction* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkAttraction* const _this, IGameObject* pGameObject)>(0x1603660);
	static inline auto FPostInitClient = PreyFunction<void(CArkAttraction* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkAttraction* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkAttraction* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkAttraction* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkAttraction* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkAttraction* const _this, TSerialize ser)>(0x1602F90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkAttraction* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkAttraction* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkAttraction* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkAttraction* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkAttraction* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x1603750);
	static inline auto FPostUpdate = PreyFunction<void(CArkAttraction* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkAttraction* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkAttraction* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkAttraction* const _this, SEntityEvent& event)>(0x1603690);
	static inline auto FSetChannelId = PreyFunction<void(CArkAttraction* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkAttraction* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkAttraction* const _this, ICrySizer* s)>(0xA55F00);
	static inline auto FIsUseableAttractor = PreyFunction<bool(const CArkAttraction* const _this)>(0x1603300);
	static inline auto FGetRandomPosOnNavMeshOv0 = PreyFunction<Vec3*(const CArkAttraction* const _this, Vec3* _return_value_, IEntity& _navAgentEntity)>(0x1602FF0);
	static inline auto FAcquire = PreyFunction<void(CArkAttraction* const _this)>(0x1602F80);
	static inline auto FRelinquish = PreyFunction<void(CArkAttraction* const _this)>(0x1603720);
	static inline auto FLoadScriptData = PreyFunction<void(CArkAttraction* const _this)>(0x1603320);
};
#endif // MOONCRASH
