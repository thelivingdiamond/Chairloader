// Header file automatically created from a PDB.

#pragma once
//#include <Prey/Ark/arklineofsightcheck.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/signalsystem/arksignalcontext.h>

class ArkFlowSignalPackageReceiver;
class ArkFlowSignalReceiver;
namespace ArkSignalSystem
{
class Receiver;
} // namespace ArkSignalSystem
struct HitInfo;
struct IConsoleCmdArgs;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SExplosionContainer;

namespace ArkSignalSystem
{

// Header: FromCpp
// Prey/GameDll/ark/signalsystem/arksignalmanager.h
class Package // Id=80136AA Size=56
{
public:
	class Value // Id=80136AB Size=16
	{
	public:
		uint64_t m_signalId;
		float m_value;
		
		uint64_t GetSignalId() const { return FGetSignalId(this); }
		float GetValue() const { return FGetValue(this); }
		
#if 0
		void ApplyRule(ArkSignalSystem::Data::ModifierData::RuleData const &arg0);
		bool IsMatchingRule(ArkSignalSystem::Data::ModifierData::RuleData const &arg0) const;
		void SendToFlowGraphSignalReceiver(unsigned arg0, ArkFlowSignalReceiver &arg1) const;
		void Serialize(TSerialize arg0);
		bool operator==(const uint64_t &arg0) const;
#endif
		
		static inline auto FGetSignalId = PreyFunction<uint64_t(ArkSignalSystem::Package::Value const *const _this)>(0x12E5E70);
		static inline auto FGetValue = PreyFunction<float(ArkSignalSystem::Package::Value const *const _this)>(0x12D8F20);
	};

	std::vector<ArkSignalSystem::Package::Value> m_values;
	uint64_t m_id;
	unsigned m_sourceId;
	ArkSignalSystem::CArkSignalContext m_context;
	
	Package(ArkSignalSystem::Data::PackageData const &_packageData, float _scale, ArkSignalSystem::CArkSignalContext _context, unsigned _sourceId);
	void ApplyRules(std::vector<ArkSignalSystem::Data::ModifierData::RuleData> const &_rules) { FApplyRules(this,_rules); }
	HitInfo const *GetHitInfo() const { return FGetHitInfo(this); }
	std::vector<ArkSignalSystem::Package::Value> const &GetValues() const { return FGetValues(this); }
	uint64_t GetId() const { return FGetId(this); }
	
#if 0
	void SendToFlowGraphSignalReceiver(unsigned arg0, ArkFlowSignalReceiver &arg1) const;
	void SendToFlowGraphPackageReceiver(unsigned arg0, ArkFlowSignalPackageReceiver &arg1) const;
	void Serialize(TSerialize arg0);
	SExplosionContainer *GetExplosionContainer() const;
	ArkSignalSystem::CArkSignalContext const &GetContext() const;
	unsigned GetSourceId() const;
#endif
	
	static inline auto FApplyRules = PreyFunction<void(ArkSignalSystem::Package *const _this, std::vector<ArkSignalSystem::Data::ModifierData::RuleData> const &_rules)>(0x15D9430);
	static inline auto FGetHitInfo = PreyFunction<HitInfo const *(ArkSignalSystem::Package const *const _this)>(0x15D9E90);
	static inline auto FGetValues = PreyFunction<std::vector<ArkSignalSystem::Package::Value> const &(ArkSignalSystem::Package const *const _this)>(0xC71190);
	static inline auto FGetId = PreyFunction<uint64_t(ArkSignalSystem::Package const *const _this)>(0xD87500);
};

} // namespace ArkSignalSystem

namespace ArkSignalSystem
{

// Header: FromCpp
// Prey/GameDll/ark/signalsystem/arksignalmanager.h
class Manager : public IEntitySystemSink // Id=8013777 Size=384
{
public:
	using AreaEffectId = unsigned;
	
	static constexpr const int s_kInvalidAreaEffectId = 0;
	
	using AreaEffectCallback = ArkDelegate<void __cdecl(unsigned int)>;
	
	class EntityInfo // Id=80137EA Size=32
	{
	public:
		unsigned m_entityId;
		std::vector<ArkSignalSystem::Receiver *> m_receivers;
		
#if 0
		void AddReceiver(ArkSignalSystem::Receiver &arg0);
		bool RemoveReceiver(ArkSignalSystem::Receiver &arg0);
		std::vector<ArkSignalSystem::Receiver *> const &GetReceivers() const;
		unsigned GetEntityId() const;
		bool operator==(unsigned arg0) const;
#endif
	};

	class ModifierInfo // Id=80137F8 Size=32
	{
	public:
		unsigned m_entityId;
		std::vector<unsigned __int64> m_modifiers;
		
#if 0
		std::vector<unsigned __int64> const &GetModifiers() const;
		bool operator==(unsigned arg0) const;
		void Serialize(TSerialize arg0);
		void AddModifier(uint64_t arg0);
		bool RemoveModifier(uint64_t arg0);
		unsigned GetEntityId() const;
#endif
	};

	class RepeatInfo // Id=80137F9 Size=72
	{
	public:
		ArkSignalSystem::Package m_package;
		unsigned m_targetEntityId;
		int m_numRepeats;
		float m_repeatTime;
		float m_timeRemaining;
		
#if 0
		void Update(float arg0, ArkSignalSystem::Manager &arg1);
		bool NeedsUpdate() const;
		void Serialize(TSerialize arg0);
		uint64_t GetPackageId() const;
		unsigned GetTargetEntityId() const;
#endif
	};

#if 0
	class AreaTargetLOSCheckImpl // Id=80137FA Size=28
	{
	public:
		using RayCasterType = RayCastQueue<41>;
		
		unsigned m_targetId;
		Vec3 m_sourcePos;
		Vec3 m_targetPos;
		
#if 0
		RayCastQueue<41> &GetRayCaster() const;
		bool GetRayCastRequest(uint64_t arg0, RayCastRequest &arg1) const;
		void OnSucceeded();
		void OnFailed();
#endif
	};

	using AreaTargetLOSCheck = ArkLineOfSightCheck<ArkSignalSystem::Manager::AreaTargetLOSCheckImpl,1>;
	
	struct AreaTarget // Id=80137FB Size=400
	{
		AreaTargetLOSCheck m_los;
		bool m_bSent;
	};

	struct AreaEffect // Id=80137FC Size=72
	{
		std::vector<ArkSignalSystem::Manager::AreaTarget> m_targets;
		unsigned m_senderEntityId;
		unsigned m_instigatorEntityId;
		uint64_t m_packageId;
		int m_hitType;
		float m_scale;
		float m_radius;
		ArkDelegate<void __cdecl(unsigned int)> m_callback;
	};
#endif

	struct AreaEffect
	{
		void* pad[9];
	};

	class RegisteredSignals // Id=80137FD Size=56
	{
	public:
		int m_registeredForAllCount;
		std::vector<unsigned __int64> m_duplicatedSignals;
		std::vector<unsigned __int64> m_uniqueSignals;
		
		void RebuildUniqueSignals() { FRebuildUniqueSignals(this); }
		
		static inline auto FRebuildUniqueSignals = PreyFunction<void(ArkSignalSystem::Manager::RegisteredSignals *const _this)>(0x15DA8E0);
	};

	std::vector<ArkSignalSystem::Manager::ModifierInfo> m_inboundModifiers;
	std::vector<ArkSignalSystem::Manager::ModifierInfo> m_outboundModifiers;
	ArkSignalSystem::Data m_data;
	std::vector<ArkSignalSystem::Manager::EntityInfo> m_entityInfo;
	std::vector<ArkSignalSystem::Manager::RepeatInfo> m_repeats;
	std::vector<ArkFlowSignalReceiver *> m_flowgraphSignalReceivers;
	std::vector<ArkFlowSignalPackageReceiver *> m_flowgraphPackageReceivers;
	std::unordered_map<unsigned int,ArkSignalSystem::Manager::RegisteredSignals> m_registeredSignals;
	std::unordered_map<unsigned int,ArkSignalSystem::Manager::AreaEffect> m_areaEffects;
	unsigned m_areaEffectNextId;
	unsigned m_uniqueHitIdGenerator;
	
	Manager();
	virtual ~Manager();
	void Scan() { FScan(this); }
	void Reset() { FReset(this); }
	void RegisterEntityReceiver(const unsigned _entityId, ArkSignalSystem::Receiver &_receiver) { FRegisterEntityReceiver(this,_entityId,_receiver); }
	void UnregisterEntityReceiver(const unsigned _entityId, ArkSignalSystem::Receiver &_receiver) { FUnregisterEntityReceiver(this,_entityId,_receiver); }
	void RegisterSignalsForEntity(const unsigned _entityId, std::vector<unsigned __int64> const &_signals) { FRegisterSignalsForEntity(this,_entityId,_signals); }
	void UnregisterSignalsForEntity(const unsigned _entityId, std::vector<unsigned __int64> const &_signals) { FUnregisterSignalsForEntity(this,_entityId,_signals); }
	void RegisterForAllSignalsForEntity(const unsigned _entityId) { FRegisterForAllSignalsForEntity(this,_entityId); }
	void UnregisterForAllSignalsForEntity(const unsigned _entityId) { FUnregisterForAllSignalsForEntity(this,_entityId); }
	std::vector<unsigned __int64> GetRegisteredSignals(const unsigned _entityId, bool &_bAllSignals) const { return FGetRegisteredSignals(this,_entityId,_bAllSignals); }
	void SendPackage(unsigned _targetEntityId, unsigned _senderEntityId, unsigned _instigatorEntityId, uint64_t _packageId, ArkSignalSystem::CArkSignalContext _context, float _scale, int _numRepeats, float _repeatTime, bool _bDelayFirstSend) { FSendPackage(this,_targetEntityId,_senderEntityId,_instigatorEntityId,_packageId,_context,_scale,_numRepeats,_repeatTime,_bDelayFirstSend); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams &params);
	virtual void OnSpawn(IEntity *pEntity, SEntitySpawnParams &params);
	virtual bool OnRemove(IEntity *_pEntity);
	virtual void OnReused(IEntity *pEntity, SEntitySpawnParams &params);
	virtual void OnEvent(IEntity *pEntity, SEntityEvent &event);
	unsigned SendPackageInArea(Vec3 const &_pos, float _radius, unsigned _senderEntityId, unsigned _instigatorEntityId, uint64_t _packageId, int _hitType, float _scale, ArkDelegate<void __cdecl(unsigned int)> _callback) { return FSendPackageInArea(this,_pos,_radius,_senderEntityId,_instigatorEntityId,_packageId,_hitType,_scale,_callback); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	ArkSignalSystem::Data::PackageData const *GetPackageData(uint64_t _id) const { return FGetPackageData(this,_id); }
	ArkSignalSystem::Data::SignalGroupData const *GetSignalGroupData(const uint64_t _id) const { return FGetSignalGroupData(this,_id); }
	void Update(float _deltaTime) { FUpdate(this,_deltaTime); }
	void SendToReceiver(const unsigned _targetEntityId, ArkSignalSystem::Package const &_package) { FSendToReceiver(this,_targetEntityId,_package); }
	void RegisterFlowGraphSignalReceiver(ArkFlowSignalReceiver &_receiver) { FRegisterFlowGraphSignalReceiver(this,_receiver); }
	void RegisterFlowGraphPackageReceiver(ArkFlowSignalPackageReceiver &_receiver) { FRegisterFlowGraphPackageReceiver(this,_receiver); }
	void UnregisterFlowGraphSignalReceiver(ArkFlowSignalReceiver &_receiver) { FUnregisterFlowGraphSignalReceiver(this,_receiver); }
	void UnregisterFlowGraphPackageReceiver(ArkFlowSignalPackageReceiver &_receiver) { FUnregisterFlowGraphPackageReceiver(this,_receiver); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void AddInboundModifier(unsigned _entityId, uint64_t _modifierId) { FAddInboundModifier(this,_entityId,_modifierId); }
	void AddOutboundModifier(unsigned _entityId, uint64_t _modifierId) { FAddOutboundModifier(this,_entityId,_modifierId); }
	bool RemoveInboundModifier(unsigned _entityId, uint64_t _modifierId) { return FRemoveInboundModifier(this,_entityId,_modifierId); }
	bool RemoveOutboundModifier(unsigned _entityId, uint64_t _modifierId) { return FRemoveOutboundModifier(this,_entityId,_modifierId); }
	bool HasInboundModifier(unsigned _entityId, uint64_t _modifierId) const { return FHasInboundModifier(this,_entityId,_modifierId); }
	bool HasOutboundModifier(unsigned _entityId, uint64_t _modifierId) const { return FHasOutboundModifier(this,_entityId,_modifierId); }
	void GetInboundModifierIdsForEntity(unsigned _entityId, std::vector<unsigned __int64> &_modifierIds) const { FGetInboundModifierIdsForEntity(this,_entityId,_modifierIds); }
	void GetOutboundModifierIdsForEntity(unsigned _entityId, std::vector<unsigned __int64> &_modifierIds) const { FGetOutboundModifierIdsForEntity(this,_entityId,_modifierIds); }
	unsigned GetUniqueHitIdentifier() { return FGetUniqueHitIdentifier(this); }
	void ApplyModifiers(std::vector<unsigned __int64> const &_modifiers, ArkSignalSystem::Package &_package) const { FApplyModifiersOv1(this,_modifiers,_package); }
	void ApplyModifiers(std::vector<ArkSignalSystem::Manager::ModifierInfo> const &_modifiers, unsigned _entityId, ArkSignalSystem::Package &_package) const { FApplyModifiersOv0(this,_modifiers,_entityId,_package); }
	void Shutdown() { FShutdown(this); }
	void Cleanup() { FCleanup(this); }
	void AddModifier(std::vector<ArkSignalSystem::Manager::ModifierInfo> &_modifiers, unsigned _entityId, uint64_t _modifierId) const { FAddModifier(this,_modifiers,_entityId,_modifierId); }
	
#if 0
	void Reload();
	void OnReload(IConsoleCmdArgs *arg0);
	bool DoesEntityReceiveSignals(const unsigned arg0) const;
	bool DoesEntityHaveSignalReceiverOfType(const unsigned arg0, ArkSignalSystem::EArkSignalReceiverType arg1) const;
	ArkSignalSystem::Data::SignalData const *GetSignalData(uint64_t arg0) const;
	bool HasRepeatingPackage(unsigned arg0, uint64_t arg1) const;
	ArkSignalSystem::Data const &GetData() const;
	void GetEntityModifierNames(const unsigned arg0, std::vector<char const *> &arg1, std::vector<char const *> &arg2) const;
	bool RemovedModifier(std::vector<ArkSignalSystem::Manager::ModifierInfo> &arg0, unsigned arg1, uint64_t arg2) const;
	bool HasModifier(std::vector<ArkSignalSystem::Manager::ModifierInfo> const &arg0, unsigned arg1, uint64_t arg2) const;
	void GetModifierIdsForEntity(std::vector<ArkSignalSystem::Manager::ModifierInfo> const &arg0, unsigned arg1, std::vector<unsigned __int64> &arg2) const;
#endif
	
	static inline auto FScan = PreyFunction<void(ArkSignalSystem::Manager *const _this)>(0x15DB370);
	static inline auto FReset = PreyFunction<void(ArkSignalSystem::Manager *const _this)>(0x15DAED0);
	static inline auto FRegisterEntityReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId, ArkSignalSystem::Receiver &_receiver)>(0x15DA990);
	static inline auto FUnregisterEntityReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId, ArkSignalSystem::Receiver &_receiver)>(0x15DCA50);
	static inline auto FRegisterSignalsForEntity = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId, std::vector<unsigned __int64> const &_signals)>(0x15DACA0);
	static inline auto FUnregisterSignalsForEntity = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId, std::vector<unsigned __int64> const &_signals)>(0x15DCF30);
	static inline auto FRegisterForAllSignalsForEntity = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId)>(0x15DABA0);
	static inline auto FUnregisterForAllSignalsForEntity = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _entityId)>(0x15DCD40);
	static inline auto FGetRegisteredSignals = PreyFunction<std::vector<unsigned __int64>(ArkSignalSystem::Manager const *const _this, const unsigned _entityId, bool &_bAllSignals)>(0x15D9F30);
	static inline auto FSendPackage = PreyFunction<void(ArkSignalSystem::Manager *const _this, unsigned _targetEntityId, unsigned _senderEntityId, unsigned _instigatorEntityId, uint64_t _packageId, ArkSignalSystem::CArkSignalContext _context, float _scale, int _numRepeats, float _repeatTime, bool _bDelayFirstSend)>(0x15DB380);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkSignalSystem::Manager *const _this, SEntitySpawnParams &params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkSignalSystem::Manager *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0xA13080);
	static inline auto FOnRemove = PreyFunction<bool(ArkSignalSystem::Manager *const _this, IEntity *_pEntity)>(0x15DA630);
	static inline auto FOnReused = PreyFunction<void(ArkSignalSystem::Manager *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkSignalSystem::Manager *const _this, IEntity *pEntity, SEntityEvent &event)>(0xA13080);
	static inline auto FSendPackageInArea = PreyFunction<unsigned(ArkSignalSystem::Manager *const _this, Vec3 const &_pos, float _radius, unsigned _senderEntityId, unsigned _instigatorEntityId, uint64_t _packageId, int _hitType, float _scale, ArkDelegate<void __cdecl(unsigned int)> _callback)>(0x15DB5F0);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkSignalSystem::Manager *const _this)>(0x15DA620);
	static inline auto FGetPackageData = PreyFunction<ArkSignalSystem::Data::PackageData const *(ArkSignalSystem::Manager const *const _this, uint64_t _id)>(0x15D9F20);
	static inline auto FGetSignalGroupData = PreyFunction<ArkSignalSystem::Data::SignalGroupData const *(ArkSignalSystem::Manager const *const _this, const uint64_t _id)>(0x15DA120);
	static inline auto FUpdate = PreyFunction<void(ArkSignalSystem::Manager *const _this, float _deltaTime)>(0x15DD1A0);
	static inline auto FSendToReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, const unsigned _targetEntityId, ArkSignalSystem::Package const &_package)>(0x15DBEB0);
	static inline auto FRegisterFlowGraphSignalReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, ArkFlowSignalReceiver &_receiver)>(0x15DAB50);
	static inline auto FRegisterFlowGraphPackageReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, ArkFlowSignalPackageReceiver &_receiver)>(0x15DAA20);
	static inline auto FUnregisterFlowGraphSignalReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, ArkFlowSignalReceiver &_receiver)>(0x15DCCF0);
	static inline auto FUnregisterFlowGraphPackageReceiver = PreyFunction<void(ArkSignalSystem::Manager *const _this, ArkFlowSignalPackageReceiver &_receiver)>(0x15DCB80);
	static inline auto FSerialize = PreyFunction<void(ArkSignalSystem::Manager *const _this, TSerialize _ser)>(0x15DC8D0);
	static inline auto FAddInboundModifier = PreyFunction<void(ArkSignalSystem::Manager *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15D9110);
	static inline auto FAddOutboundModifier = PreyFunction<void(ArkSignalSystem::Manager *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15D91C0);
	static inline auto FRemoveInboundModifier = PreyFunction<bool(ArkSignalSystem::Manager *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15DADF0);
	static inline auto FRemoveOutboundModifier = PreyFunction<bool(ArkSignalSystem::Manager *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15DAE60);
	static inline auto FHasInboundModifier = PreyFunction<bool(ArkSignalSystem::Manager const *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15DA1D0);
	static inline auto FHasOutboundModifier = PreyFunction<bool(ArkSignalSystem::Manager const *const _this, unsigned _entityId, uint64_t _modifierId)>(0x15DA210);
	static inline auto FGetInboundModifierIdsForEntity = PreyFunction<void(ArkSignalSystem::Manager const *const _this, unsigned _entityId, std::vector<unsigned __int64> &_modifierIds)>(0x15D9EA0);
	static inline auto FGetOutboundModifierIdsForEntity = PreyFunction<void(ArkSignalSystem::Manager const *const _this, unsigned _entityId, std::vector<unsigned __int64> &_modifierIds)>(0x15D9EE0);
	static inline auto FGetUniqueHitIdentifier = PreyFunction<unsigned(ArkSignalSystem::Manager *const _this)>(0x15DA1B0);
	static inline auto FApplyModifiersOv1 = PreyFunction<void(ArkSignalSystem::Manager const *const _this, std::vector<unsigned __int64> const &_modifiers, ArkSignalSystem::Package &_package)>(0x15D9320);
	static inline auto FApplyModifiersOv0 = PreyFunction<void(ArkSignalSystem::Manager const *const _this, std::vector<ArkSignalSystem::Manager::ModifierInfo> const &_modifiers, unsigned _entityId, ArkSignalSystem::Package &_package)>(0x15D91E0);
	static inline auto FShutdown = PreyFunction<void(ArkSignalSystem::Manager *const _this)>(0x15DC9D0);
	static inline auto FCleanup = PreyFunction<void(ArkSignalSystem::Manager *const _this)>(0x15D9BB0);
	static inline auto FAddModifier = PreyFunction<void(ArkSignalSystem::Manager const *const _this, std::vector<ArkSignalSystem::Manager::ModifierInfo> &_modifiers, unsigned _entityId, uint64_t _modifierId)>(0x15D9130);
};

} // namespace ArkSignalSystem

