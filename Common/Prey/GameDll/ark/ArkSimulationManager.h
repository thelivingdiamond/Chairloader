// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkSimulationManager
// Header:  Prey/GameDll/ark/ArkSimulationManager.h
class ArkSimulationManager
{ // Size=5 (0x5)
public:
	bool m_bInReadyRoom;
	bool m_bForceReturnToSatellite;
	bool m_bPlayerResetEnabled;
	bool m_bInSimulation;
	bool m_bIgnoreSignals;

	ArkSimulationManager();
	void Reset() { FReset(this); }
	void StartSimulationRun() { FStartSimulationRun(this); }
	void EndSimulationRun() { FEndSimulationRun(this); }
	void ResetSimulation() { FResetSimulation(this); }
	void OnEnterReadyRoom() { FOnEnterReadyRoom(this); }
	void OnReturnToSatellite() { FOnReturnToSatellite(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetForceToSatellite(bool _bEnable) { FSetForceToSatellite(this, _bEnable); }
	void SetPlayerResetEnabled(bool _bEnable) { FSetPlayerResetEnabled(this, _bEnable); }
	void OnPlayerSpawn() { FOnPlayerSpawn(this); }

#if 0
	bool IsSimulationRunning() const;
	bool GetForceToSatellite() const;
	bool IsPlayerResetEnabled() const;
	bool IsIgnoringSignals() const;
#endif

	static inline auto FArkSimulationManager = PreyFunction<void(ArkSimulationManager* const _this)>(0x1508450);
	static inline auto FReset = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7E10);
	static inline auto FStartSimulationRun = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7F90);
	static inline auto FEndSimulationRun = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7CA0);
	static inline auto FResetSimulation = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7E20);
	static inline auto FOnEnterReadyRoom = PreyFunction<void(ArkSimulationManager* const _this)>(0x127E040);
	static inline auto FOnReturnToSatellite = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7DF0);
	static inline auto FSerialize = PreyFunction<void(ArkSimulationManager* const _this, TSerialize _ser)>(0x11C7ED0);
	static inline auto FPostSerialize = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7E00);
	static inline auto FSetForceToSatellite = PreyFunction<void(ArkSimulationManager* const _this, bool _bEnable)>(0x11C7F70);
	static inline auto FSetPlayerResetEnabled = PreyFunction<void(ArkSimulationManager* const _this, bool _bEnable)>(0x11C7F80);
	static inline auto FOnPlayerSpawn = PreyFunction<void(ArkSimulationManager* const _this)>(0x11C7DD0);
};
#endif // MOONCRASH
