// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/ArkStationAccessComponent.h
class ArkStationAccessComponent // Id=80172DD Size=72
{
public:
	std::vector<unsigned __int64> m_lockedPaths;
	std::vector<unsigned __int64> m_lockedAirlocks;
	std::vector<unsigned __int64> m_hiddenAirlocks;
	
	bool IsPathLocked(uint64_t _id) const { return FIsPathLocked(this,_id); }
	void SetPathLocked(uint64_t _id, bool _bLocked) { FSetPathLocked(this,_id,_bLocked); }
	bool IsAirlockLocked(uint64_t _id) const { return FIsAirlockLocked(this,_id); }
	void SetAirlockLocked(uint64_t _id, bool _bLocked) { FSetAirlockLocked(this,_id,_bLocked); }
	bool IsAirlockHidden(uint64_t _id) const { return FIsAirlockHidden(this,_id); }
	void SetAirlockHidden(uint64_t _id, bool _bHidden) { FSetAirlockHidden(this,_id,_bHidden); }
	EArkAccessState GetConnectionState(uint64_t _locationA, uint64_t _locationB) const { return FGetConnectionState(this,_locationA,_locationB); }
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void NotifyAirlockUnlocked(uint64_t _id) const { FNotifyAirlockUnlocked(this,_id); }
	
	static inline auto FIsPathLocked = PreyFunction<bool(ArkStationAccessComponent const *const _this, uint64_t _id)>(0x130C510);
	static inline auto FSetPathLocked = PreyFunction<void(ArkStationAccessComponent *const _this, uint64_t _id, bool _bLocked)>(0x130CB00);
	static inline auto FIsAirlockLocked = PreyFunction<bool(ArkStationAccessComponent const *const _this, uint64_t _id)>(0x130C4B0);
	static inline auto FSetAirlockLocked = PreyFunction<void(ArkStationAccessComponent *const _this, uint64_t _id, bool _bLocked)>(0x130CA80);
	static inline auto FIsAirlockHidden = PreyFunction<bool(ArkStationAccessComponent const *const _this, uint64_t _id)>(0x130C450);
	static inline auto FSetAirlockHidden = PreyFunction<void(ArkStationAccessComponent *const _this, uint64_t _id, bool _bHidden)>(0x130CA30);
	static inline auto FGetConnectionState = PreyFunction<EArkAccessState(ArkStationAccessComponent const *const _this, uint64_t _locationA, uint64_t _locationB)>(0x130C200);
	static inline auto FInit = PreyFunction<void(ArkStationAccessComponent *const _this)>(0x130C300);
	static inline auto FReset = PreyFunction<void(ArkStationAccessComponent *const _this)>(0x130C9B0);
	static inline auto FSerialize = PreyFunction<void(ArkStationAccessComponent *const _this, TSerialize _ser)>(0x130C9D0);
	static inline auto FNotifyAirlockUnlocked = PreyFunction<void(ArkStationAccessComponent const *const _this, uint64_t _id)>(0x130C570);
};

