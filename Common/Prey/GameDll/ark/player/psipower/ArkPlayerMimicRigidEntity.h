// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/attention/ArkPlayerMimicRigidEntityAttentionObject.h>
#include <Prey/GameDll/ark/iface/IArkBreakableListener.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
struct IEntity;
struct IEntityClass;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidEntity.h
class ArkPlayerMimicRigidEntity : public IArkBreakableListener, public ArkSignalSystem::Receiver, public IEntityEventListener // Id=80195E0 Size=152
{
public:
	class SignalGroup : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalGroupData> // Id=80195E1 Size=40
	{
	public:
		string m_name;
		std::vector<unsigned __int64> m_signals;
		
		bool HasSignal(const uint64_t _id) const { return FHasSignal(this,_id); }
		void LoadParamters(XmlNodeRef _node) { FLoadParamters(this,_node); }
		
#if 0
		void SignalGroupData();
		void SignalGroupData(XmlNodeRef arg0);
		void SignalGroupData(ArkSignalSystem::Data::SignalGroupData const &arg0);
		void SignalGroupData(ArkSignalSystem::Data::SignalGroupData *arg0);
		string const &GetName() const;
		std::vector<unsigned __int64> const &GetSignals() const;
		~SignalGroupData();
#endif
		
		static inline auto FHasSignal = PreyFunction<bool(ArkSignalSystem::Data::SignalGroupData const *const _this, const uint64_t _id)>(0x13FA450);
		static inline auto FLoadParamters = PreyFunction<void(ArkSignalSystem::Data::SignalGroupData *const _this, XmlNodeRef _node)>(0x15DA250);
	};

	Vec3 m_scale;
	string m_statObjPath;
	string m_characterPath;
	string m_materialPath;
	ArkSignalSystem::Data::SignalGroupData const *m_pSignalGroup;
	unsigned m_entityId;
	float m_mass;
	float m_density;
	int m_health;
	int m_renderSlot;
	ArkPlayerMimicRigidEntityAttentionObject m_attentionObject;
	
	ArkPlayerMimicRigidEntity(IEntity const &_targetEntity, QuatT const &_worldTransform);
	ArkPlayerMimicRigidEntity(const unsigned _entityId);
	virtual ~ArkPlayerMimicRigidEntity();
	void Show(Vec3 const &_velocity) { FShow(this,_velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { return FGetSize(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	IEntityClass const *GetClass() const { return FGetClass(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	virtual void OnBroken(IEntity const &_entity);
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	static OOB ComputeInitialWorldBounds(IEntity const &_targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	void InitializeGeometry() { FInitializeGeometry(this); }
	void InitializeSignalReceiver() { FInitializeSignalReceiver(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	
#if 0
	int GetHealth() const;
	unsigned GetEntityId() const;
	void PostSerialize() const;
	void EnableAttentionObject();
#endif
	
	static inline auto FBitNotArkPlayerMimicRigidEntity = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this)>(0x131C240);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this, Vec3 const &_velocity)>(0x131D080);
	static inline auto FIsVisible = PreyFunction<bool(ArkPlayerMimicRigidEntity const *const _this)>(0x131CCE0);
	static inline auto FGetSize = PreyFunction<Vec3(ArkPlayerMimicRigidEntity const *const _this)>(0x131C910);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkPlayerMimicRigidEntity const *const _this)>(0x131C8A0);
	static inline auto FGetClass = PreyFunction<IEntityClass const *(ArkPlayerMimicRigidEntity const *const _this)>(0x131C870);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this, TSerialize _ser)>(0x131CF20);
	static inline auto FOnBroken = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this, IEntity const &_entity)>(0x131CD20);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this, ArkSignalSystem::Package const &_package)>(0x131CE10);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x131CD50);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OOB(IEntity const &_targetEntity)>(0x131C440);
	static inline auto FInitializeGeometry = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this)>(0x131C9A0);
	static inline auto FInitializeSignalReceiver = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this)>(0x131CB50);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkPlayerMimicRigidEntity *const _this)>(0x131C7E0);
};

