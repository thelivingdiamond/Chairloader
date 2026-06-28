// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IEntity;
struct IEntityClass;
class XmlNodeRef;

// ArkMarkedEnemyComponent
// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
class ArkMarkedEnemyComponent : public IArkStatsListener
{ // Size=96 (0x60)
public:
	enum class EArkMarkClass
	{
		Invalid = 0,
		Hostile = 1,
		NonHostile = 2,
		Mimic = 3,
		EliteMimic = 4,
		Poltergeist = 5,
		Count = 6,
	};

	// ArkMarkedEnemyComponent::ValidTarget
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class ValidTarget
	{ // Size=8 (0x8)
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;

	#if 0
		ValidTarget(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_);
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	// ArkMarkedEnemyComponent::MarkedEnemy
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class MarkedEnemy
	{ // Size=12 (0xC)
	public:
		unsigned m_enemy;
		bool m_bNew;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;

		void SetMarkClass(ArkMarkedEnemyComponent::EArkMarkClass _markClass) { FSetMarkClass(this, _markClass); }

	#if 0
		MarkedEnemy();
		MarkedEnemy(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const unsigned _arg0_) const;
	#endif

		static inline auto FSetMarkClass = PreyFunction<void(ArkMarkedEnemyComponent::MarkedEnemy* const _this, ArkMarkedEnemyComponent::EArkMarkClass _markClass)>(0x1227E60);
	};

	// ArkMarkedEnemyComponent::PotentialTarget
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class PotentialTarget
	{ // Size=16 (0x10)
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;
		ArkTimeRemaining m_timeToMarked;
		ArkTimeRemaining m_timeToLose;

	#if 0
		PotentialTarget();
		PotentialTarget(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_, const float _arg2_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	using MarkDurationArray = std::array<float,6>;

	std::vector<ArkMarkedEnemyComponent::MarkedEnemy> m_markedEnemies;
	std::vector<ArkMarkedEnemyComponent::PotentialTarget> m_potentialTargets;
	float m_rangeSq;
	float m_durationToLose;
	ArkAudioTrigger m_triggerMarkAdded;
	ArkAudioTrigger m_triggerHiddenMarkAdded;
	ArkAudioTrigger m_triggerMarkRemoved;
	const IEntityClass* m_pEliteMimicClass;
	const IEntityClass* m_pPoltergeistClass;

	ArkMarkedEnemyComponent();
	virtual ~ArkMarkedEnemyComponent();
	bool IsMarked(unsigned _entity) const { return FIsMarked(this, _entity); }
	void GetMarkedEnemies(std::vector<unsigned int>& _markedEnemies) const { FGetMarkedEnemies(this, _markedEnemies); }
	void Init() { FInit(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(float _deltaTime) { FUpdate(this, _deltaTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeLTL() { FPostSerializeLTL(this); }
	void Reset() { FReset(this); }
	void ClearPotentialTargets() { FClearPotentialTargets(this); }
	void LostMarkedEnemy(unsigned _enemy) { FLostMarkedEnemy(this, _enemy); }
	void UpdateValidTargets() { FUpdateValidTargets(this); }
	void ClearMarkedEnemies() { FClearMarkedEnemies(this); }
	bool CanSeeTarget(const IEntity* _pTarget, const Vec3& _targetPos) const { return FCanSeeTarget(this, _pTarget, _targetPos); }
	ArkMarkedEnemyComponent::EArkMarkClass GetMarkClass(const IEntity* _pTarget, const std::array<float,6>& _markDurations) const { return FGetMarkClass(this, _pTarget, _markDurations); }
	void HandleInboundModifier(unsigned _enemy, bool _bAdd) const { FHandleInboundModifier(this, _enemy, _bAdd); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);

#if 0
	Vec3 GetTargetPosition(const IEntity& _arg0_) const;
	bool CanSeeTargetWithScanner(const IEntity* _arg0_) const;
	float GetStat(const CCryName& _arg0_) const;
	void UnmarkEnemy(ArkMarkedEnemyComponent::MarkedEnemy& _arg0_);
#endif

	static inline auto FArkMarkedEnemyComponentOv1 = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12271F0);
	static inline auto FIsMarked = PreyFunction<bool(const ArkMarkedEnemyComponent* const _this, unsigned _entity)>(0x12278F0);
	static inline auto FGetMarkedEnemies = PreyFunction<void(const ArkMarkedEnemyComponent* const _this, std::vector<unsigned int>& _markedEnemies)>(0x1227680);
	static inline auto FInit = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x1227870);
	static inline auto FLoadConfig = PreyFunction<void(ArkMarkedEnemyComponent* const _this, const XmlNodeRef& _root)>(0x1227920);
	static inline auto FUpdate = PreyFunction<void(ArkMarkedEnemyComponent* const _this, float _deltaTime)>(0x1227F00);
	static inline auto FSerialize = PreyFunction<void(ArkMarkedEnemyComponent* const _this, TSerialize _ser)>(0x1227CA0);
	static inline auto FPostSerialize = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x1227BF0);
	static inline auto FPostSerializeLTL = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x1227C50);
	static inline auto FReset = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x1227C70);
	static inline auto FClearPotentialTargets = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x1227570);
	static inline auto FLostMarkedEnemy = PreyFunction<void(ArkMarkedEnemyComponent* const _this, unsigned _enemy)>(0x1227AD0);
	static inline auto FUpdateValidTargets = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12281F0);
	static inline auto FClearMarkedEnemies = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12274F0);
	static inline auto FCanSeeTarget = PreyFunction<bool(const ArkMarkedEnemyComponent* const _this, const IEntity* _pTarget, const Vec3& _targetPos)>(0x1227390);
	static inline auto FGetMarkClass = PreyFunction<ArkMarkedEnemyComponent::EArkMarkClass(const ArkMarkedEnemyComponent* const _this, const IEntity* _pTarget, const std::array<float,6>& _markDurations)>(0x1227580);
	static inline auto FHandleInboundModifier = PreyFunction<void(const ArkMarkedEnemyComponent* const _this, unsigned _enemy, bool _bAdd)>(0x1227720);
	static inline auto FOnStatChange = PreyFunction<void(ArkMarkedEnemyComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x1227BE0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IEntity;
struct IEntityClass;
class XmlNodeRef;

// ArkMarkedEnemyComponent
// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
class ArkMarkedEnemyComponent : public IArkStatsListener
{ // Size=96 (0x60)
public:
	enum class EArkMarkClass
	{
		Invalid = 0,
		Hostile = 1,
		NonHostile = 2,
		Mimic = 3,
		EliteMimic = 4,
		Poltergeist = 5,
		Underground = 6,
		Count = 7,
	};

	// ArkMarkedEnemyComponent::ValidTarget
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class ValidTarget
	{ // Size=8 (0x8)
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;

	#if 0
		ValidTarget(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_);
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	// ArkMarkedEnemyComponent::MarkedEnemy
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class MarkedEnemy
	{ // Size=12 (0xC)
	public:
		unsigned m_enemy;
		bool m_bNew;
		bool m_bForceMarked;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;

	#if 0
		MarkedEnemy();
		MarkedEnemy(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const ArkMarkedEnemyComponent::MarkedEnemy& _arg0_) const;
		bool operator==(const unsigned _arg0_) const;
		void SetMarkClass(ArkMarkedEnemyComponent::EArkMarkClass _arg0_, bool _arg1_);
	#endif
	};

	// ArkMarkedEnemyComponent::PotentialTarget
	// Header:  Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
	class PotentialTarget
	{ // Size=16 (0x10)
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;
		ArkTimeRemaining m_timeToMarked;
		ArkTimeRemaining m_timeToLose;

	#if 0
		PotentialTarget();
		PotentialTarget(const unsigned _arg0_, const ArkMarkedEnemyComponent::EArkMarkClass _arg1_, const float _arg2_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	using MarkDurationArray = std::array<float, 7>;

	std::vector<ArkMarkedEnemyComponent::MarkedEnemy> m_markedEnemies;
	std::vector<ArkMarkedEnemyComponent::PotentialTarget> m_potentialTargets;
	float m_rangeSq;
	float m_durationToLose;
	ArkAudioTrigger m_triggerMarkAdded;
	ArkAudioTrigger m_triggerHiddenMarkAdded;
	ArkAudioTrigger m_triggerMarkRemoved;
	const IEntityClass* m_pEliteMimicClass;
	const IEntityClass* m_pPoltergeistClass;

	ArkMarkedEnemyComponent();
	virtual ~ArkMarkedEnemyComponent();
	bool IsMarked(unsigned _entity) const { return FIsMarked(this, _entity); }
	void GetMarkedEnemies(std::vector<unsigned int>& _markedEnemies) const { FGetMarkedEnemies(this, _markedEnemies); }
	void Init() { FInit(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(float _deltaTime) { FUpdate(this, _deltaTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeLTL() { FPostSerializeLTL(this); }
	void Reset() { FReset(this); }
	void ClearPotentialTargets() { FClearPotentialTargets(this); }
	void LostMarkedEnemy(unsigned _enemy) { FLostMarkedEnemy(this, _enemy); }
	void MarkEnemy(IEntity& _entity, const bool _bForceMark) { FMarkEnemyOv1(this, _entity, _bForceMark); }
	ArkMarkedEnemyComponent::MarkedEnemy* MarkEnemy(IEntity& _entity, const ArkMarkedEnemyComponent::EArkMarkClass _markClass) { return FMarkEnemyOv0(this, _entity, _markClass); }
	void UpdateValidTargets() { FUpdateValidTargets(this); }
	void ClearMarkedEnemies() { FClearMarkedEnemies(this); }
	bool CanSeeTarget(const IEntity* _pTarget, const Vec3& _targetPos) const { return FCanSeeTarget(this, _pTarget, _targetPos); }
	ArkMarkedEnemyComponent::EArkMarkClass GetMarkClass(const IEntity* _pTarget, const std::array<float, 7>& _markDurations, const bool _bForceMark) const { return FGetMarkClass(this, _pTarget, _markDurations, _bForceMark); }
	void HandleInboundModifier(unsigned _enemy, bool _bAdd) const { FHandleInboundModifier(this, _enemy, _bAdd); }
	const std::array<float, 7> GetMarkDurationArray() const { alignas(const std::array<float, 7>) std::byte _return_buf_[sizeof(const std::array<float, 7>)]; return *FGetMarkDurationArray(this, reinterpret_cast<const std::array<float, 7>*>(_return_buf_)); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void UnmarkEnemy(ArkMarkedEnemyComponent::MarkedEnemy& _enemy) { FUnmarkEnemy(this, _enemy); }

#if 0
	Vec3 GetTargetPosition(const IEntity& _arg0_) const;
	bool CanSeeTargetWithScanner(const IEntity* _arg0_) const;
	float GetStat(const CCryName& _arg0_) const;
#endif

	static inline auto FArkMarkedEnemyComponentOv1 = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7120);
	static inline auto FBitNotArkMarkedEnemyComponent = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7190);
	static inline auto FIsMarked = PreyFunction<bool(const ArkMarkedEnemyComponent* const _this, unsigned _entity)>(0x12C7A40);
	static inline auto FGetMarkedEnemies = PreyFunction<void(const ArkMarkedEnemyComponent* const _this, std::vector<unsigned int>& _markedEnemies)>(0x12C77D0);
	static inline auto FInit = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C79C0);
	static inline auto FLoadConfig = PreyFunction<void(ArkMarkedEnemyComponent* const _this, const XmlNodeRef& _root)>(0x12C7A70);
	static inline auto FUpdate = PreyFunction<void(ArkMarkedEnemyComponent* const _this, float _deltaTime)>(0x12C8220);
	static inline auto FSerialize = PreyFunction<void(ArkMarkedEnemyComponent* const _this, TSerialize _ser)>(0x12C7FC0);
	static inline auto FPostSerialize = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7E90);
	static inline auto FPostSerializeLTL = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7F70);
	static inline auto FReset = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7F90);
	static inline auto FClearPotentialTargets = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C75D0);
	static inline auto FLostMarkedEnemy = PreyFunction<void(ArkMarkedEnemyComponent* const _this, unsigned _enemy)>(0x12C7C20);
	static inline auto FMarkEnemyOv1 = PreyFunction<void(ArkMarkedEnemyComponent* const _this, IEntity& _entity, const bool _bForceMark)>(0x12C7E20);
	static inline auto FMarkEnemyOv0 = PreyFunction<ArkMarkedEnemyComponent::MarkedEnemy* (ArkMarkedEnemyComponent* const _this, IEntity& _entity, const ArkMarkedEnemyComponent::EArkMarkClass _markClass)>(0x12C7D20);
	static inline auto FUpdateValidTargets = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C84C0);
	static inline auto FClearMarkedEnemies = PreyFunction<void(ArkMarkedEnemyComponent* const _this)>(0x12C7500);
	static inline auto FCanSeeTarget = PreyFunction<bool(const ArkMarkedEnemyComponent* const _this, const IEntity* _pTarget, const Vec3& _targetPos)>(0x12C73A0);
	static inline auto FGetMarkClass = PreyFunction<ArkMarkedEnemyComponent::EArkMarkClass(const ArkMarkedEnemyComponent* const _this, const IEntity* _pTarget, const std::array<float, 7>& _markDurations, const bool _bForceMark)>(0x12C75E0);
	static inline auto FHandleInboundModifier = PreyFunction<void(const ArkMarkedEnemyComponent* const _this, unsigned _enemy, bool _bAdd)>(0x12C7870);
	static inline auto FGetMarkDurationArray = PreyFunction<const std::array<float, 7>*(const ArkMarkedEnemyComponent* const _this, const std::array<float, 7>* _return_value_)>(0x12C7720);
	static inline auto FOnStatChange = PreyFunction<void(ArkMarkedEnemyComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x12C7E80);
	static inline auto FUnmarkEnemy = PreyFunction<void(ArkMarkedEnemyComponent* const _this, ArkMarkedEnemyComponent::MarkedEnemy& _enemy)>(0x12C8180);
};
#endif // !MOONCRASH
