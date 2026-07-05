#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/attention/ArkInstigationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/IGameRules.h>

class ArkClass;
class ArkNpc;
struct ICVar;
struct IEntity;
struct IGameRules;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkInstigationManager.h
class ArkInstigationManager : public IEntityEventListener // Id=80153B7 Size=176
{
public:
	using EventId = unsigned;
	
	enum class EArkInstigationType
	{
		_standard = 0,
		_thrown = 1,
		_collision = 2,
	};

	class EventRef // Id=80153B8 Size=4
	{
	public:
		unsigned m_eventId;
		
		EventRef();
		~EventRef();
		
#if 0
		bool operator!=(unsigned arg0);
		bool operator bool() const;
		unsigned GetId();
#endif
		
		static inline auto FBitNotEventRef = PreyFunction<void(ArkInstigationManager::EventRef *const _this)>(0x13F06E0);
	};

	struct Instigation // Id=80153B9 Size=16
	{
		unsigned eventId;
		ArkInstigationManager::EArkInstigationType m_type;
		ArkNpc const *m_pArkNpc;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct InstigationEvent // Id=80153BA Size=20
	{
		unsigned instigator;
		float eventTime;
		ArkSimpleTimer decayTimer;
		unsigned refCount;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	using InstigationMap = std::unordered_map<unsigned int,ArkInstigationManager::Instigation>;
	
	std::unordered_map<unsigned int,ArkInstigationManager::Instigation> m_instigations;
	
	using InstigationEventMap = std::unordered_map<unsigned int,ArkInstigationManager::InstigationEvent>;
	
	std::unordered_map<unsigned int,ArkInstigationManager::InstigationEvent> m_events;
	
	using InstigationClasses = std::vector<IEntityClass *>;
	
	std::vector<IEntityClass *> m_classes;
	ICVar *m_pDebugDraw;
	unsigned m_eventIdGen;
	
	ArkInstigationManager();
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	unsigned AddInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId, float _decayTime) { return FAddInstigation(this,_instigatedEntityId,_instigatorEntityId,_decayTime); }
	unsigned AddThrownInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId) { return FAddThrownInstigation(this,_instigatedEntityId,_instigatorEntityId); }
	unsigned AddCollisionInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId) { return FAddCollisionInstigation(this,_instigatedEntityId,_instigatorEntityId); }
	unsigned PropagateInstigation(unsigned _instigatedEntityId, unsigned _propagateEntityId, float _decayTime) { return FPropagateInstigation(this,_instigatedEntityId,_propagateEntityId,_decayTime); }
	unsigned PropagateCollisionInstigation(unsigned _instigatedEntityId, unsigned _colliderEntityId) { return FPropagateCollisionInstigation(this,_instigatedEntityId,_colliderEntityId); }
	void PropagateCollisionInstigationEvent(unsigned _eventId, unsigned _instigatedEntityId) { FPropagateCollisionInstigationEvent(this,_eventId,_instigatedEntityId); }
	void RemoveInstigation(unsigned _instigatedEntityId) { FRemoveInstigationOv1(this,_instigatedEntityId); }
	void RemoveInstigation(unsigned _instigatedEntityId, ArkInstigationManager::Instigation const &_instigation) { FRemoveInstigationOv0(this,_instigatedEntityId,_instigation); }
	unsigned GetInstigatorEntityId(unsigned _instigatedEntityId) const { return FGetInstigatorEntityId(this,_instigatedEntityId); }
	void OnCollision(IGameRules::SGameCollision const &_event) { FOnCollision(this,_event); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Reset(bool _bLoadConfig) { FReset(this,_bLoadConfig); }
	bool IsValidEvent(unsigned _eventId) const { return FIsValidEvent(this,_eventId); }
	bool CanInstigate(const unsigned _entityId) const { return FCanInstigateOv1(this,_entityId); }
	bool CanInstigate(IEntity const &_entity) const { return FCanInstigateOv0(this,_entity); }
	static bool CanBeCollisionInstigated(const unsigned _instigatedEntityId) { return FCanBeCollisionInstigated(_instigatedEntityId); }
	void LoadConfig() { FLoadConfig(this); }
	unsigned CreateInstigationEvent(unsigned _instigator, unsigned _instigated, ArkInstigationManager::EArkInstigationType _type, float _decayTime) { return FCreateInstigationEvent(this,_instigator,_instigated,_type,_decayTime); }
	void AddEventReference(unsigned _eventId, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type, float _decayTimer) { FAddEventReferenceOv1(this,_eventId,_instigatedEntityId,_type,_decayTimer); }
	bool ShouldPropagateEvent(const unsigned _eventId, const unsigned _instigatedEntityId) const { return FShouldPropagateEvent(this,_eventId,_instigatedEntityId); }
	void AddInstigationListeners(unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type) { FAddInstigationListeners(this,_instigatedEntityId,_type); }
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	
#if 0
	static void AddHitsArticulatedFlag(unsigned arg0);
	static void RemoveHitsArticulatedFlag(unsigned arg0);
	void AddEventReference(unsigned arg0);
	void RemoveEventReference(unsigned arg0);
	void RemoveInstigationListeners(unsigned arg0, ArkInstigationManager::EArkInstigationType arg1);
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkInstigationManager *const _this, float _frameTime)>(0x13F1E40);
	static inline auto FAddInstigation = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId, float _decayTime)>(0x13F0AE0);
	static inline auto FAddThrownInstigation = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId)>(0x13F0BE0);
	static inline auto FAddCollisionInstigation = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId)>(0x13F0900);
	static inline auto FPropagateInstigation = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigatedEntityId, unsigned _propagateEntityId, float _decayTime)>(0x13F1760);
	static inline auto FPropagateCollisionInstigation = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigatedEntityId, unsigned _colliderEntityId)>(0x13F15C0);
	static inline auto FPropagateCollisionInstigationEvent = PreyFunction<void(ArkInstigationManager *const _this, unsigned _eventId, unsigned _instigatedEntityId)>(0x13F16C0);
	static inline auto FRemoveInstigationOv1 = PreyFunction<void(ArkInstigationManager *const _this, unsigned _instigatedEntityId)>(0x13F1980);
	static inline auto FRemoveInstigationOv0 = PreyFunction<void(ArkInstigationManager *const _this, unsigned _instigatedEntityId, ArkInstigationManager::Instigation const &_instigation)>(0x13F1870);
	static inline auto FGetInstigatorEntityId = PreyFunction<unsigned(ArkInstigationManager const *const _this, unsigned _instigatedEntityId)>(0x13F0EA0);
	static inline auto FOnCollision = PreyFunction<void(ArkInstigationManager *const _this, IGameRules::SGameCollision const &_event)>(0x13F12F0);
	static inline auto FSerialize = PreyFunction<void(ArkInstigationManager *const _this, TSerialize _ser)>(0x13F1B20);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkInstigationManager *const _this)>(0x13F15B0);
	static inline auto FReset = PreyFunction<void(ArkInstigationManager *const _this, bool _bLoadConfig)>(0x13F1A60);
	static inline auto FIsValidEvent = PreyFunction<bool(ArkInstigationManager const *const _this, unsigned _eventId)>(0x13F1110);
	static inline auto FCanInstigateOv1 = PreyFunction<bool(ArkInstigationManager const *const _this, const unsigned _entityId)>(0x13F0D30);
	static inline auto FCanInstigateOv0 = PreyFunction<bool(ArkInstigationManager const *const _this, IEntity const &_entity)>(0x13F0C70);
	static inline auto FCanBeCollisionInstigated = PreyFunction<bool(const unsigned _instigatedEntityId)>(0x13F0C10);
	static inline auto FLoadConfig = PreyFunction<void(ArkInstigationManager *const _this)>(0x13F11C0);
	static inline auto FCreateInstigationEvent = PreyFunction<unsigned(ArkInstigationManager *const _this, unsigned _instigator, unsigned _instigated, ArkInstigationManager::EArkInstigationType _type, float _decayTime)>(0x13F0D70);
	static inline auto FAddEventReferenceOv1 = PreyFunction<void(ArkInstigationManager *const _this, unsigned _eventId, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type, float _decayTimer)>(0x13F09A0);
	static inline auto FShouldPropagateEvent = PreyFunction<bool(ArkInstigationManager const *const _this, const unsigned _eventId, const unsigned _instigatedEntityId)>(0x13F1CB0);
	static inline auto FAddInstigationListeners = PreyFunction<void(ArkInstigationManager *const _this, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type)>(0x13F0B10);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkInstigationManager *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x13F1560);
};

// Header: FromCpp
// Prey/GameDll/ark/attention/arkinstigationmanager.h
class ArkInstigationConfig : public ArkReflectedObject // Id=801BE4A Size=24
{
public:
	class ArkEntitiesProperty : public ArkProperty // Id=801BE4B Size=32
	{
	public:
		ArkEntitiesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInstigationConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13EF400);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInstigationConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13EF460);
		static inline auto FIsArray = PreyFunction<bool(ArkInstigationConfig::ArkEntitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkInstigationConfig::ArkEntitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x13EF480);
	};

	static ArkInstigationConfig::ArkEntitiesProperty s_ArkEntitiesProperty;
	std::vector<string> m_Entities;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	void Init() { FInit(this); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<string> &GetEntities();
	std::vector<string> const &GetEntities() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
	static inline auto FInit = PreyFunction<void(ArkInstigationConfig *const _this)>(0x13F0F90);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/IGameRules.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkClass;
class ArkNpc;
class IArkValueBase;
struct ICVar;
struct IEntity;
struct IEntityClass;
struct SEntityEvent;

// ArkInstigationConfig
// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
class ArkInstigationConfig : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkInstigationConfig::ArkEntitiesProperty
	// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
	class ArkEntitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkEntitiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkEntitiesPropertyOv2 = PreyFunction<void(ArkInstigationConfig::ArkEntitiesProperty* const _this)>(0x1501B10);
		static inline auto FSetValue = PreyFunction<void(const ArkInstigationConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1500D30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInstigationConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1500D90);
		static inline auto FIsArray = PreyFunction<bool(const ArkInstigationConfig::ArkEntitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkInstigationConfig::ArkEntitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x139FFB0);
	};

	static inline auto s_ArkEntitiesProperty = PreyGlobal<ArkInstigationConfig::ArkEntitiesProperty>(0x2D5B270);
	std::vector<string> m_Entities;

	static ArkReflectedObject* Create() { return FCreate(); }
	void Init() { FInit(this); }

#if 0
	static ArkClass* GetClass();
	std::vector<string>& GetEntities();
	const std::vector<string>& GetEntities() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
	static inline auto FInit = PreyFunction<void(ArkInstigationConfig* const _this)>(0x1502890);
};

// ArkInstigationManager
// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
class ArkInstigationManager : public IEntityEventListener
{ // Size=176 (0xB0)
public:
	enum class EArkInstigationType
	{
		_standard = 0,
		_thrown = 1,
		_collision = 2,
	};

	// ArkInstigationManager::EventRef
	// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
	class EventRef
	{ // Size=4 (0x4)
	public:
		unsigned m_eventId;

		EventRef();
		~EventRef();

	#if 0
		EventRef(unsigned _arg0_);
		bool operator!=(unsigned _arg0_);
		bool operator bool() const;
		unsigned GetId();
	#endif

		static inline auto FEventRefOv1 = PreyFunction<void(ArkInstigationManager::EventRef* const _this)>(0x1643FB0);
		static inline auto FBitNotEventRef = PreyFunction<void(ArkInstigationManager::EventRef* const _this)>(0x1501FA0);
	};

	// ArkInstigationManager::Instigation
	// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
	struct Instigation
	{ // Size=16 (0x10)
		unsigned eventId;
		ArkInstigationManager::EArkInstigationType m_type;
		const ArkNpc* m_pArkNpc;

	#if 0
		Instigation();
		Instigation(const unsigned _arg0_, const ArkInstigationManager::EArkInstigationType _arg1_, const ArkNpc* const _arg2_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkInstigationManager::InstigationEvent
	// Header:  Prey/GameDll/ark/attention/ArkInstigationManager.h
	struct InstigationEvent
	{ // Size=20 (0x14)
		unsigned instigator;
		float eventTime;
		ArkSimpleTimer decayTimer;
		unsigned refCount;

	#if 0
		InstigationEvent();
		InstigationEvent(const unsigned _arg0_, const float _arg1_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	using EventId = unsigned;
	using InstigationMap = std::unordered_map<unsigned int, ArkInstigationManager::Instigation>;
	using InstigationEventMap = std::unordered_map<unsigned int, ArkInstigationManager::InstigationEvent>;
	using InstigationClasses = std::vector<IEntityClass*>;

	std::unordered_map<unsigned int, ArkInstigationManager::Instigation> m_instigations;
	std::unordered_map<unsigned int, ArkInstigationManager::InstigationEvent> m_events;
	std::vector<IEntityClass*> m_classes;
	ICVar* m_pDebugDraw;
	unsigned m_eventIdGen;

	ArkInstigationManager();
	virtual ~ArkInstigationManager();
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	unsigned AddInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId, float _decayTime) { return FAddInstigation(this, _instigatedEntityId, _instigatorEntityId, _decayTime); }
	unsigned AddThrownInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId) { return FAddThrownInstigation(this, _instigatedEntityId, _instigatorEntityId); }
	unsigned AddCollisionInstigation(unsigned _instigatedEntityId, unsigned _instigatorEntityId) { return FAddCollisionInstigation(this, _instigatedEntityId, _instigatorEntityId); }
	unsigned PropagateInstigation(unsigned _instigatedEntityId, unsigned _propagateEntityId, float _decayTime) { return FPropagateInstigation(this, _instigatedEntityId, _propagateEntityId, _decayTime); }
	unsigned PropagateCollisionInstigation(unsigned _instigatedEntityId, unsigned _colliderEntityId) { return FPropagateCollisionInstigation(this, _instigatedEntityId, _colliderEntityId); }
	void PropagateCollisionInstigationEvent(unsigned _eventId, unsigned _instigatedEntityId) { FPropagateCollisionInstigationEvent(this, _eventId, _instigatedEntityId); }
	void RemoveInstigation(unsigned _instigatedEntityId) { FRemoveInstigationOv1(this, _instigatedEntityId); }
	void RemoveInstigation(unsigned _instigatedEntityId, const ArkInstigationManager::Instigation& _instigation) { FRemoveInstigationOv0(this, _instigatedEntityId, _instigation); }
	unsigned GetInstigatorEntityId(unsigned _instigatedEntityId) const { return FGetInstigatorEntityId(this, _instigatedEntityId); }
	void OnCollision(const IGameRules::SGameCollision& _event) { FOnCollision(this, _event); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Reset(bool _bLoadConfig) { FReset(this, _bLoadConfig); }
	bool IsValidEvent(unsigned _eventId) const { return FIsValidEvent(this, _eventId); }
	bool CanInstigate(const unsigned _entityId) const { return FCanInstigateOv1(this, _entityId); }
	bool CanInstigate(const IEntity& _entity) const { return FCanInstigateOv0(this, _entity); }
	static bool CanBeCollisionInstigated(const unsigned _instigatedEntityId) { return FCanBeCollisionInstigated(_instigatedEntityId); }
	void LoadConfig() { FLoadConfig(this); }
	unsigned CreateInstigationEvent(unsigned _instigator, unsigned _instigated, ArkInstigationManager::EArkInstigationType _type, float _decayTime) { return FCreateInstigationEvent(this, _instigator, _instigated, _type, _decayTime); }
	void AddEventReference(unsigned _eventId, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type, float _decayTimer) { FAddEventReferenceOv1(this, _eventId, _instigatedEntityId, _type, _decayTimer); }
	bool ShouldPropagateEvent(const unsigned _eventId, const unsigned _instigatedEntityId) const { return FShouldPropagateEvent(this, _eventId, _instigatedEntityId); }
	void AddInstigationListeners(unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type) { FAddInstigationListeners(this, _instigatedEntityId, _type); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	ArkInstigationManager(const ArkInstigationManager& _arg0_);
	ArkInstigationManager& operator=(const ArkInstigationManager& _arg0_);
	static void AddHitsArticulatedFlag(unsigned _arg0_);
	static void RemoveHitsArticulatedFlag(unsigned _arg0_);
	void AddEventReference(unsigned _arg0_);
	void RemoveEventReference(unsigned _arg0_);
	void RemoveInstigationListeners(unsigned _arg0_, ArkInstigationManager::EArkInstigationType _arg1_);
#endif

	static inline auto FArkInstigationManagerOv1 = PreyFunction<void(ArkInstigationManager* const _this)>(0x1501E50);
	static inline auto FUpdate = PreyFunction<void(ArkInstigationManager* const _this, float _frameTime)>(0x1503760);
	static inline auto FAddInstigation = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId, float _decayTime)>(0x15023A0);
	static inline auto FAddThrownInstigation = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId)>(0x15024A0);
	static inline auto FAddCollisionInstigation = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigatedEntityId, unsigned _instigatorEntityId)>(0x15021C0);
	static inline auto FPropagateInstigation = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigatedEntityId, unsigned _propagateEntityId, float _decayTime)>(0x1503080);
	static inline auto FPropagateCollisionInstigation = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigatedEntityId, unsigned _colliderEntityId)>(0x1502EE0);
	static inline auto FPropagateCollisionInstigationEvent = PreyFunction<void(ArkInstigationManager* const _this, unsigned _eventId, unsigned _instigatedEntityId)>(0x1502FE0);
	static inline auto FRemoveInstigationOv1 = PreyFunction<void(ArkInstigationManager* const _this, unsigned _instigatedEntityId)>(0x15032A0);
	static inline auto FRemoveInstigationOv0 = PreyFunction<void(ArkInstigationManager* const _this, unsigned _instigatedEntityId, const ArkInstigationManager::Instigation& _instigation)>(0x1503190);
	static inline auto FGetInstigatorEntityId = PreyFunction<unsigned(const ArkInstigationManager* const _this, unsigned _instigatedEntityId)>(0x15027A0);
	static inline auto FOnCollision = PreyFunction<void(ArkInstigationManager* const _this, const IGameRules::SGameCollision& _event)>(0x1502C10);
	static inline auto FSerialize = PreyFunction<void(ArkInstigationManager* const _this, TSerialize _ser)>(0x1503440);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkInstigationManager* const _this)>(0x1502ED0);
	static inline auto FReset = PreyFunction<void(ArkInstigationManager* const _this, bool _bLoadConfig)>(0x1503380);
	static inline auto FIsValidEvent = PreyFunction<bool(const ArkInstigationManager* const _this, unsigned _eventId)>(0x1502A30);
	static inline auto FCanInstigateOv1 = PreyFunction<bool(const ArkInstigationManager* const _this, const unsigned _entityId)>(0x1502630);
	static inline auto FCanInstigateOv0 = PreyFunction<bool(const ArkInstigationManager* const _this, const IEntity& _entity)>(0x1502580);
	static inline auto FCanBeCollisionInstigated = PreyFunction<bool(const unsigned _instigatedEntityId)>(0x1502520);
	static inline auto FLoadConfig = PreyFunction<void(ArkInstigationManager* const _this)>(0x1502AE0);
	static inline auto FCreateInstigationEvent = PreyFunction<unsigned(ArkInstigationManager* const _this, unsigned _instigator, unsigned _instigated, ArkInstigationManager::EArkInstigationType _type, float _decayTime)>(0x1502670);
	static inline auto FAddEventReferenceOv1 = PreyFunction<void(ArkInstigationManager* const _this, unsigned _eventId, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type, float _decayTimer)>(0x1502260);
	static inline auto FShouldPropagateEvent = PreyFunction<bool(const ArkInstigationManager* const _this, const unsigned _eventId, const unsigned _instigatedEntityId)>(0x15035D0);
	static inline auto FAddInstigationListeners = PreyFunction<void(ArkInstigationManager* const _this, unsigned _instigatedEntityId, ArkInstigationManager::EArkInstigationType _type)>(0x15023D0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkInstigationManager* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x1502E80);
};
#endif // !MOONCRASH
