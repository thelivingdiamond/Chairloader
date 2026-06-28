// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
// Prey/GameDll/ark/arkareacontainer.h
class CArkAreaContainer : public CGameObjectExtensionHelper<CArkAreaContainer,IGameObjectExtension> // Id=8014FAA Size=88
{
public:
	using AreaProxyEntities = std::vector<unsigned int>;
	
	std::vector<unsigned int> m_areaShapes;
	
	CArkAreaContainer();
	virtual ~CArkAreaContainer();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &event);
	virtual void ProcessEvent(SEntityEvent &event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	std::vector<unsigned int> const &GetAreas() { return FGetAreas(this); }
	bool ContainsArea(unsigned _areaEntityId) const { return FContainsArea(this,_areaEntityId); }
	bool IsPointInAnyArea(Vec3 const &_point) const { return FIsPointInAnyArea(this,_point); }
	void InitializeAreaShapes() { FInitializeAreaShapes(this); }
	
#if 0
	int GetAreaCount() const;
	void InitializeContainer();
	void ClearAreaShapes();
#endif
	
	static inline auto FInit = PreyFunction<bool(CArkAreaContainer *const _this, IGameObject *_pGameObject)>(0x13CACC0);
	static inline auto FInitClient = PreyFunction<void(CArkAreaContainer *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(CArkAreaContainer *const _this, IGameObject *pGameObject)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkAreaContainer *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkAreaContainer *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkAreaContainer *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkAreaContainer *const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkAreaContainer *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(CArkAreaContainer *const _this, TSerialize ser)>(0xA13080);
	static inline auto FNetSerialize = PreyFunction<bool(CArkAreaContainer *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkAreaContainer *const _this)>(0xA13080);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkAreaContainer *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkAreaContainer *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkAreaContainer *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(CArkAreaContainer *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkAreaContainer *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkAreaContainer *const _this, SGameObjectEvent const &event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkAreaContainer *const _this, SEntityEvent &event)>(0x13CADD0);
	static inline auto FSetChannelId = PreyFunction<void(CArkAreaContainer *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkAreaContainer *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkAreaContainer const *const _this, ICrySizer *s)>(0x14B4470);
	static inline auto FGetAreas = PreyFunction<std::vector<unsigned int> const &(CArkAreaContainer *const _this)>(0x13CABC0);
	static inline auto FContainsArea = PreyFunction<bool(CArkAreaContainer const *const _this, unsigned _areaEntityId)>(0x13CAB90);
	static inline auto FIsPointInAnyArea = PreyFunction<bool(CArkAreaContainer const *const _this, Vec3 const &_point)>(0x13CAD50);
	static inline auto FInitializeAreaShapes = PreyFunction<void(CArkAreaContainer *const _this)>(0x13CACE0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
class ICrySizer;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkAreaContainer
// Header:  Prey/GameDll/ark/ArkAreaContainer.h
class CArkAreaContainer : public CGameObjectExtensionHelper<CArkAreaContainer, IGameObjectExtension>
{ // Size=88 (0x58)
public:
	using AreaProxyEntities = std::vector<unsigned int>;

	std::vector<unsigned int> m_areaShapes;

	CArkAreaContainer();
	virtual ~CArkAreaContainer();
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
	const std::vector<unsigned int>& GetAreas() { return FGetAreas(this); }
	bool ContainsArea(unsigned _areaEntityId) const { return FContainsArea(this, _areaEntityId); }
	bool IsPointInAnyArea(const Vec3& _point) const { return FIsPointInAnyArea(this, _point); }
	void InitializeAreaShapes() { FInitializeAreaShapes(this); }

#if 0
	int GetAreaCount() const;
	void InitializeContainer();
	void ClearAreaShapes();
#endif

	static inline auto FCArkAreaContainerOv1 = PreyFunction<void(CArkAreaContainer* const _this)>(0x14D6B30);
	static inline auto FInit = PreyFunction<bool(CArkAreaContainer* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FInitClient = PreyFunction<void(CArkAreaContainer* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(CArkAreaContainer* const _this, IGameObject* pGameObject)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkAreaContainer* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkAreaContainer* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkAreaContainer* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkAreaContainer* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkAreaContainer* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkAreaContainer* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CArkAreaContainer* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkAreaContainer* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkAreaContainer* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkAreaContainer* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkAreaContainer* const _this, SEntityUpdateContext& ctx, int updateSlot)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkAreaContainer* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkAreaContainer* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(CArkAreaContainer* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkAreaContainer* const _this, SEntityEvent& event)>(0x14D6E00);
	static inline auto FSetChannelId = PreyFunction<void(CArkAreaContainer* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkAreaContainer* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkAreaContainer* const _this, ICrySizer* s)>(0xE98E40);
	static inline auto FGetAreas = PreyFunction<const std::vector<unsigned int>& (CArkAreaContainer* const _this)>(0x14D6C10);
	static inline auto FContainsArea = PreyFunction<bool(const CArkAreaContainer* const _this, unsigned _areaEntityId)>(0x14D6BE0);
	static inline auto FIsPointInAnyArea = PreyFunction<bool(const CArkAreaContainer* const _this, const Vec3& _point)>(0x14D6D80);
	static inline auto FInitializeAreaShapes = PreyFunction<void(CArkAreaContainer* const _this)>(0x14D6D10);
};
#endif // !MOONCRASH
