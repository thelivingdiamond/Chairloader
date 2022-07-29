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

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerAchievementComponent.h
class ArkPlayerAchievementComponent // Id=801715F Size=128
{
public:
	std::vector<unsigned __int64> m_mimickedObjects;
	std::vector<unsigned int> m_repairedWeapons;
	std::vector<unsigned __int64> m_consumedFoodAndDrink;
	ArkSimpleTimer m_recycledTimer;
	ArkSimpleTimer m_blastOffWindow;
	Vec3 m_blastOffPosition;
	
	class TimerWindowCount // Id=8017160 Size=16
	{
	public:
		ArkTimeRemaining m_timeRemaining;
		unsigned m_count;
		uint64_t m_metric;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkPlayerAchievementComponent::TimerWindowCount> m_timerWindows;
	
	ArkPlayerAchievementComponent();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void ObjectMimicked(IEntity const &_entity) { FObjectMimicked(this,_entity); }
	void WeaponRepaired(const unsigned _entity) { FWeaponRepaired(this,_entity); }
	void ConsumedItem(IEntity const &_entity) { FConsumedItem(this,_entity); }
	void NpcKilled(ArkNpc const &_npc) { FNpcKilled(this,_npc); }
	void EntityScanned(IEntity const &_entity) { FEntityScanned(this,_entity); }
	void PlayerDied() { FPlayerDied(this); }
	void NoteRead(const uint64_t _noteId) { FNoteRead(this,_noteId); }
	void OnReceiveSignal(ArkSignalSystem::Package const &_package) { FOnReceiveSignal(this,_package); }
	bool TriggerAchievement(uint64_t _id) { return FTriggerAchievement(this,_id); }
	void OnGameEnded() { FOnGameEnded(this); }
	void MimickingPlayerBlasted() { FMimickingPlayerBlasted(this); }
	
#if 0
	bool CompareMetric(ArkMetricComparison const &arg0) const;
#endif
	
	static inline auto FReset = PreyFunction<void(ArkPlayerAchievementComponent *const _this)>(0x122BA90);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerAchievementComponent *const _this, TSerialize _ser)>(0x122BAF0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerAchievementComponent *const _this, float _frameTime)>(0x122BF90);
	static inline auto FObjectMimicked = PreyFunction<void(ArkPlayerAchievementComponent *const _this, IEntity const &_entity)>(0x122B640);
	static inline auto FWeaponRepaired = PreyFunction<void(ArkPlayerAchievementComponent *const _this, const unsigned _entity)>(0x122C2A0);
	static inline auto FConsumedItem = PreyFunction<void(ArkPlayerAchievementComponent *const _this, IEntity const &_entity)>(0x122B3C0);
	static inline auto FNpcKilled = PreyFunction<void(ArkPlayerAchievementComponent *const _this, ArkNpc const &_npc)>(0x122B5E0);
	static inline auto FEntityScanned = PreyFunction<void(ArkPlayerAchievementComponent *const _this, IEntity const &_entity)>(0x122B4E0);
	static inline auto FPlayerDied = PreyFunction<void(ArkPlayerAchievementComponent *const _this)>(0x122BA50);
	static inline auto FNoteRead = PreyFunction<void(ArkPlayerAchievementComponent *const _this, const uint64_t _noteId)>(0x122B580);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkPlayerAchievementComponent *const _this, ArkSignalSystem::Package const &_package)>(0x122B9C0);
	static inline auto FTriggerAchievement = PreyFunction<bool(ArkPlayerAchievementComponent *const _this, uint64_t _id)>(0x122BD30);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPlayerAchievementComponent *const _this)>(0x122B6E0);
	static inline auto FMimickingPlayerBlasted = PreyFunction<void(ArkPlayerAchievementComponent *const _this)>(0x122B520);
};

