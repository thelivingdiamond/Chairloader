// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkMetricComparison;
class ArkNpc;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct IEntity;

// ArkPlayerAchievementComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerAchievementComponent.h
class ArkPlayerAchievementComponent
{ // Size=128 (0x80)
public:
	// ArkPlayerAchievementComponent::TimerWindowCount
	// Header:  Prey/GameDll/ark/player/ArkPlayerAchievementComponent.h
	class TimerWindowCount
	{ // Size=16 (0x10)
	public:
		ArkTimeRemaining m_timeRemaining;
		unsigned m_count;
		uint64_t m_metric;

	#if 0
		TimerWindowCount();
		TimerWindowCount(const uint64_t _arg0_, const float _arg1_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::vector<uint64_t> m_mimickedObjects;
	std::vector<unsigned int> m_repairedWeapons;
	std::vector<uint64_t> m_consumedFoodAndDrink;
	ArkSimpleTimer m_recycledTimer;
	ArkSimpleTimer m_blastOffWindow;
	Vec3 m_blastOffPosition;
	std::vector<ArkPlayerAchievementComponent::TimerWindowCount> m_timerWindows;

	ArkPlayerAchievementComponent();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void ObjectMimicked(const IEntity& _entity) { FObjectMimicked(this, _entity); }
	void WeaponRepaired(const unsigned _entity) { FWeaponRepaired(this, _entity); }
	void ConsumedItem(const IEntity& _entity) { FConsumedItem(this, _entity); }
	void NpcKilled(const ArkNpc& _npc) { FNpcKilled(this, _npc); }
	void EntityScanned(const IEntity& _entity) { FEntityScanned(this, _entity); }
	void PlayerDied() { FPlayerDied(this); }
	void NoteRead(const uint64_t _noteId) { FNoteRead(this, _noteId); }
	void OnReceiveSignal(const ArkSignalSystem::Package& _package) { FOnReceiveSignal(this, _package); }
	bool TriggerAchievement(uint64_t _id) { return FTriggerAchievement(this, _id); }
	void OnGameEnded() { FOnGameEnded(this); }
	void MimickingPlayerBlasted() { FMimickingPlayerBlasted(this); }

#if 0
	bool CompareMetric(const ArkMetricComparison& _arg0_) const;
#endif

	static inline auto FArkPlayerAchievementComponentOv2 = PreyFunction<void(ArkPlayerAchievementComponent* const _this)>(0x122B250);
	static inline auto FReset = PreyFunction<void(ArkPlayerAchievementComponent* const _this)>(0x122BA90);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerAchievementComponent* const _this, TSerialize _ser)>(0x122BAF0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerAchievementComponent* const _this, float _frameTime)>(0x122BF90);
	static inline auto FObjectMimicked = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const IEntity& _entity)>(0x122B640);
	static inline auto FWeaponRepaired = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const unsigned _entity)>(0x122C2A0);
	static inline auto FConsumedItem = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const IEntity& _entity)>(0x122B3C0);
	static inline auto FNpcKilled = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const ArkNpc& _npc)>(0x122B5E0);
	static inline auto FEntityScanned = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const IEntity& _entity)>(0x122B4E0);
	static inline auto FPlayerDied = PreyFunction<void(ArkPlayerAchievementComponent* const _this)>(0x122BA50);
	static inline auto FNoteRead = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const uint64_t _noteId)>(0x122B580);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerAchievementComponent* const _this, const ArkSignalSystem::Package& _package)>(0x122B9C0);
	static inline auto FTriggerAchievement = PreyFunction<bool(ArkPlayerAchievementComponent* const _this, uint64_t _id)>(0x122BD30);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPlayerAchievementComponent* const _this)>(0x122B6E0);
	static inline auto FMimickingPlayerBlasted = PreyFunction<void(ArkPlayerAchievementComponent* const _this)>(0x122B520);
};

