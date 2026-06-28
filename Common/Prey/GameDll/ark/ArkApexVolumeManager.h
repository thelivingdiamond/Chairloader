// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkApexVolumeManager.h
class ArkApexVolumeManager // Id=80169EA Size=96
{
public:
	std::unordered_map<unsigned int,float> m_entityTimes;
	ArkAutoResetTimer m_timer;
	uint64_t m_dotSignal;
	uint64_t m_killSignal;
	float m_killTimeThreshold;
	
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	
#if 0
	void AddEntity(const unsigned arg0);
	void RemoveEntity(const unsigned arg0);
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkApexVolumeManager *const _this, const float _frameTime)>(0x114B7E0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// ArkApexVolumeManager
// Header:  Prey/GameDll/ark/ArkApexVolumeManager.h
class ArkApexVolumeManager
{ // Size=96 (0x60)
public:
	std::unordered_map<unsigned int, float> m_entityTimes;
	ArkAutoResetTimer m_timer;
	uint64_t m_dotSignal;
	uint64_t m_killSignal;
	float m_killTimeThreshold;

	void Update(const float _frameTime) { FUpdate(this, _frameTime); }

#if 0
	ArkApexVolumeManager();
	void AddEntity(const unsigned _arg0_);
	void RemoveEntity(const unsigned _arg0_);
	void Serialize(TSerialize _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<void(ArkApexVolumeManager* const _this, const float _frameTime)>(0x1192590);
};
#endif // !MOONCRASH
