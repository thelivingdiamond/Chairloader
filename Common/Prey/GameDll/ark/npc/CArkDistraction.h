// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/Ark/arkdistractiondata.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkDistraction
// Header:  Prey/GameDll/ark/npc/CArkDistraction.h
class CArkDistraction : public CGameObjectExtensionHelper<CArkDistraction, IGameObjectExtension>
{ // Size=248 (0xF8)
public:
	uint64_t m_distractionId;
	Distraction m_distractionData;

	CArkDistraction();
	virtual ~CArkDistraction();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* _pGameObject);
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
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	void UnRegisterForDistraction() { FUnRegisterForDistraction(this); }
	void LoadScriptData() { FLoadScriptData(this); }

#if 0
	uint64_t GetDistractionId() const;
	const Distraction& GetDistractionData() const;
	void RegisterForDistraction();
	void Reset();
#endif

	static inline auto FCArkDistractionOv1 = PreyFunction<void(CArkDistraction* const _this)>(0x1606DA0);
	static inline auto FInit = PreyFunction<bool(CArkDistraction* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FInitClient = PreyFunction<void(CArkDistraction* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkDistraction* const _this, IGameObject* _pGameObject)>(0x1607660);
	static inline auto FPostInitClient = PreyFunction<void(CArkDistraction* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkDistraction* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkDistraction* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkDistraction* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkDistraction* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkDistraction* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkDistraction* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkDistraction* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkDistraction* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkDistraction* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkDistraction* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkDistraction* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkDistraction* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkDistraction* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkDistraction* const _this, SEntityEvent& _event)>(0x1607670);
	static inline auto FSetChannelId = PreyFunction<void(CArkDistraction* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkDistraction* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkDistraction* const _this, ICrySizer* s)>(0x17682A0);
	static inline auto FUnRegisterForDistraction = PreyFunction<void(CArkDistraction* const _this)>(0x1607700);
	static inline auto FLoadScriptData = PreyFunction<void(CArkDistraction* const _this)>(0x1606E70);
};
#endif // MOONCRASH
