// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IEntity;
struct IEntityClass;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkMarkedEnemyComponent.h
class ArkMarkedEnemyComponent : public IArkStatsListener // Id=80171E2 Size=96
{
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

	using MarkDurationArray = std::array<float,6>;
	
	class ValidTarget // Id=80171E8 Size=8
	{
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;
		
#if 0
		bool operator==(const unsigned arg0) const;
#endif
	};

	class MarkedEnemy // Id=80171E9 Size=12
	{
	public:
		unsigned m_enemy;
		bool m_bNew;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;
		
		void SetMarkClass(ArkMarkedEnemyComponent::EArkMarkClass _markClass) { FSetMarkClass(this,_markClass); }
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const unsigned arg0) const;
#endif
		
		static inline auto FSetMarkClass = PreyFunction<void(ArkMarkedEnemyComponent::MarkedEnemy *const _this, ArkMarkedEnemyComponent::EArkMarkClass _markClass)>(0x1227E60);
	};

	std::vector<ArkMarkedEnemyComponent::MarkedEnemy> m_markedEnemies;
	
	class PotentialTarget // Id=80171FE Size=16
	{
	public:
		unsigned m_target;
		ArkMarkedEnemyComponent::EArkMarkClass m_markClass;
		ArkTimeRemaining m_timeToMarked;
		ArkTimeRemaining m_timeToLose;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const unsigned arg0) const;
#endif
	};

	std::vector<ArkMarkedEnemyComponent::PotentialTarget> m_potentialTargets;
	float m_rangeSq;
	float m_durationToLose;
	ArkAudioTrigger m_triggerMarkAdded;
	ArkAudioTrigger m_triggerHiddenMarkAdded;
	ArkAudioTrigger m_triggerMarkRemoved;
	IEntityClass const *m_pEliteMimicClass;
	IEntityClass const *m_pPoltergeistClass;
	
	ArkMarkedEnemyComponent();
	bool IsMarked(unsigned _entity) const { return FIsMarked(this,_entity); }
	void GetMarkedEnemies(std::vector<unsigned int> &_markedEnemies) const { FGetMarkedEnemies(this,_markedEnemies); }
	void Init() { FInit(this); }
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void Update(float _deltaTime) { FUpdate(this,_deltaTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeLTL() { FPostSerializeLTL(this); }
	void Reset() { FReset(this); }
	void ClearPotentialTargets() { FClearPotentialTargets(this); }
	void LostMarkedEnemy(unsigned _enemy) { FLostMarkedEnemy(this,_enemy); }
	void UpdateValidTargets() { FUpdateValidTargets(this); }
	void ClearMarkedEnemies() { FClearMarkedEnemies(this); }
	bool CanSeeTarget(IEntity const *_pTarget, Vec3 const &_targetPos) const { return FCanSeeTarget(this,_pTarget,_targetPos); }
	ArkMarkedEnemyComponent::EArkMarkClass GetMarkClass(IEntity const *_pTarget, std::array<float,6> const &_markDurations) const { return FGetMarkClass(this,_pTarget,_markDurations); }
	void HandleInboundModifier(unsigned _enemy, bool _bAdd) const { FHandleInboundModifier(this,_enemy,_bAdd); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	
#if 0
	Vec3 GetTargetPosition(IEntity const &arg0) const;
	bool CanSeeTargetWithScanner(IEntity const *arg0) const;
	float GetStat(CCryName const &arg0) const;
	void UnmarkEnemy(ArkMarkedEnemyComponent::MarkedEnemy &arg0);
#endif
	
	static inline auto FIsMarked = PreyFunction<bool(ArkMarkedEnemyComponent const *const _this, unsigned _entity)>(0x12278F0);
	static inline auto FGetMarkedEnemies = PreyFunction<void(ArkMarkedEnemyComponent const *const _this, std::vector<unsigned int> &_markedEnemies)>(0x1227680);
	static inline auto FInit = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x1227870);
	static inline auto FLoadConfig = PreyFunction<void(ArkMarkedEnemyComponent *const _this, XmlNodeRef const &_root)>(0x1227920);
	static inline auto FUpdate = PreyFunction<void(ArkMarkedEnemyComponent *const _this, float _deltaTime)>(0x1227F00);
	static inline auto FSerialize = PreyFunction<void(ArkMarkedEnemyComponent *const _this, TSerialize _ser)>(0x1227CA0);
	static inline auto FPostSerialize = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x1227BF0);
	static inline auto FPostSerializeLTL = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x1227C50);
	static inline auto FReset = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x1227C70);
	static inline auto FClearPotentialTargets = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x1227570);
	static inline auto FLostMarkedEnemy = PreyFunction<void(ArkMarkedEnemyComponent *const _this, unsigned _enemy)>(0x1227AD0);
	static inline auto FUpdateValidTargets = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x12281F0);
	static inline auto FClearMarkedEnemies = PreyFunction<void(ArkMarkedEnemyComponent *const _this)>(0x12274F0);
	static inline auto FCanSeeTarget = PreyFunction<bool(ArkMarkedEnemyComponent const *const _this, IEntity const *_pTarget, Vec3 const &_targetPos)>(0x1227390);
	static inline auto FGetMarkClass = PreyFunction<ArkMarkedEnemyComponent::EArkMarkClass(ArkMarkedEnemyComponent const *const _this, IEntity const *_pTarget, std::array<float,6> const &_markDurations)>(0x1227580);
	static inline auto FHandleInboundModifier = PreyFunction<void(ArkMarkedEnemyComponent const *const _this, unsigned _enemy, bool _bAdd)>(0x1227720);
	static inline auto FOnStatChange = PreyFunction<void(ArkMarkedEnemyComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x1227BE0);
};

