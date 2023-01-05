// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/attention/ArkPlayerMimicRigidEntityAttentionObject.h>
#include <Prey/GameDll/ark/iface/IArkBreakableListener.h>
#include <Prey/GameDll/ark/signalsystem/arksignalreceiver.h>

namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IEntity;
struct IEntityClass;
struct SEntityEvent;
class XmlNodeRef;

// ArkPlayerMimicRigidEntity
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidEntity.h
class ArkPlayerMimicRigidEntity
	: public IArkBreakableListener
	, public ArkSignalSystem::Receiver
	, public IEntityEventListener
{ // Size=152 (0x98)
public:
	// ArkPlayerMimicRigidEntity::SignalGroup
	// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidEntity.h
	class SignalGroup : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalGroupData>
	{ // Size=40 (0x28)
	public:
		string m_name;
		std::vector<uint64_t> m_signals;

		//bool HasSignal(const uint64_t _id) const { return FHasSignal(this, _id); }
		//void LoadParamters(const XmlNodeRef _node) { FLoadParamters(this, _node); }

	#if 0
		void SignalGroupData();
		void SignalGroupData(const XmlNodeRef _arg0_);
		const string& GetName() const;
		const std::vector<uint64_t>& GetSignals() const;
	#endif

		static inline auto FHasSignal = PreyFunction<bool(const ArkSignalSystem::Data::SignalGroupData* const _this, const uint64_t _id)>(0x13FA450);
		static inline auto FLoadParamters = PreyFunction<void(ArkSignalSystem::Data::SignalGroupData* const _this, const XmlNodeRef _node)>(0x15DA250);
	};

	Vec3 m_scale;
	string m_statObjPath;
	string m_characterPath;
	string m_materialPath;
	const ArkSignalSystem::Data::SignalGroupData* m_pSignalGroup;
	unsigned m_entityId;
	float m_mass;
	float m_density;
	int m_health;
	int m_renderSlot;
	ArkPlayerMimicRigidEntityAttentionObject m_attentionObject;

	ArkPlayerMimicRigidEntity(const IEntity& _targetEntity, const QuatT& _worldTransform);
	ArkPlayerMimicRigidEntity(const unsigned _entityId);
	virtual ~ArkPlayerMimicRigidEntity();
	void Show(const Vec3& _velocity) { FShow(this, _velocity); }
	bool IsVisible() const { return FIsVisible(this); }
	Vec3 GetSize() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetSize(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	const IEntityClass* GetClass() const { return FGetClass(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnBroken(const IEntity& _entity);
	virtual void OnReceiveSignal(const ArkSignalSystem::Package& _package);
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	static OBB ComputeInitialWorldBounds(const IEntity& _targetEntity) { return FComputeInitialWorldBounds(_targetEntity); }
	void InitializeGeometry() { FInitializeGeometry(this); }
	void InitializeSignalReceiver() { FInitializeSignalReceiver(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }

#if 0
	int GetHealth() const;
	unsigned GetEntityId() const;
	void PostSerialize() const;
	void EnableAttentionObject();
#endif

	static inline auto FArkPlayerMimicRigidEntityOv1 = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this, const IEntity& _targetEntity, const QuatT& _worldTransform)>(0x131B720);
	static inline auto FArkPlayerMimicRigidEntityOv0 = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this, const unsigned _entityId)>(0x131C0C0);
	static inline auto FBitNotArkPlayerMimicRigidEntity = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this)>(0x131C240);
	static inline auto FShow = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this, const Vec3& _velocity)>(0x131D080);
	static inline auto FIsVisible = PreyFunction<bool(const ArkPlayerMimicRigidEntity* const _this)>(0x131CCE0);
	static inline auto FGetSize = PreyFunction<Vec3*(const ArkPlayerMimicRigidEntity* const _this, Vec3* _return_value_)>(0x131C910);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimicRigidEntity* const _this, Vec3* _return_value_)>(0x131C8A0);
	static inline auto FGetClass = PreyFunction<const IEntityClass* (const ArkPlayerMimicRigidEntity* const _this)>(0x131C870);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this, TSerialize _ser)>(0x131CF20);
	static inline auto FOnBroken = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this, const IEntity& _entity)>(0x131CD20);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkSignalSystem::Receiver* const _this, const ArkSignalSystem::Package& _package)>(0x131CE10);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x131CD50);
	static inline auto FComputeInitialWorldBounds = PreyFunction<OBB(const IEntity& _targetEntity)>(0x131C440);
	static inline auto FInitializeGeometry = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this)>(0x131C9A0);
	static inline auto FInitializeSignalReceiver = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this)>(0x131CB50);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkPlayerMimicRigidEntity* const _this)>(0x131C7E0);
};

