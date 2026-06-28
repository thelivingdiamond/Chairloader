// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Exact
// Prey/GameDll/ark/arkprojectilegoonetworkmanager.h
class CArkProjectileGooNetworkManager // Id=8015EDC Size=88
{
public:
	static const int k_invalidNetworkId;
	
	struct GooNetwork // Id=8015EDD Size=88
	{
		std::vector<unsigned int> m_stoppedGooIdsList;
		std::vector<unsigned int> m_burstingGooIdsList;
		std::vector<unsigned int> m_growingGooIdsList;
		ArkSimpleTimer m_lockingTimer;
		ArkSimpleTimer m_burstingTimer;
		
		GooNetwork(const unsigned _gooId, const float _lockTime, const float _burstTime);
		
#if 0
		void Serialize(TSerialize arg0);
		void AddGooId(const unsigned arg0);
		void DeleteGooId(const unsigned arg0);
		void NeedsToBurst(const unsigned arg0);
		void StopGooGrowth(const unsigned arg0);
		bool IncreaseGoo(const unsigned arg0, const float arg1);
		bool IsEmpty() const;
		void ClearAll();
		void LockAll();
#endif
	};

	int m_nextNetworkId;
	std::unordered_map<int,CArkProjectileGooNetworkManager::GooNetwork> m_gooNetworksList;
	bool m_bNetworkGainedGoo;
	float m_gooBurstTimeToMinDelay;
	float m_gooMinBurstDelay;
	
	void Shutdown() { FShutdown(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	int CreateNetwork(const unsigned _gooId, const float _lockTime, const float _burstTime) { return FCreateNetwork(this,_gooId,_lockTime,_burstTime); }
	void AddToNetwork(const int _networkId, const unsigned _gooId) { FAddToNetwork(this,_networkId,_gooId); }
	void DeleteFromNetwork(const int _networkId, const unsigned _gooId) { FDeleteFromNetwork(this,_networkId,_gooId); }
	void NeedsToBurst(const int _networkId, const unsigned _gooId) { FNeedsToBurst(this,_networkId,_gooId); }
	bool IncreaseGoo(const int _networkId, const unsigned _gooId, const float _gooScale) { return FIncreaseGoo(this,_networkId,_gooId,_gooScale); }
	CArkProjectileGooNetworkManager::GooNetwork *GetGooNetworkFromId(const int _networkId) { return FGetGooNetworkFromId(this,_networkId); }
	
#if 0
	void StopGooGrowth(const int arg0, const unsigned arg1);
	bool DidNetworkGainGoo() const;
	void SetBurstValues(const float arg0, const float arg1);
	void DeleteNetwork(const int arg0);
#endif
	
	static inline auto FShutdown = PreyFunction<void(CArkProjectileGooNetworkManager *const _this)>(0x124BC30);
	static inline auto FSerialize = PreyFunction<void(CArkProjectileGooNetworkManager *const _this, TSerialize _ser)>(0x124B670);
	static inline auto FReset = PreyFunction<void(CArkProjectileGooNetworkManager *const _this)>(0x124BC30);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooNetworkManager *const _this, const float _frameTime)>(0x124BC70);
	static inline auto FCreateNetwork = PreyFunction<int(CArkProjectileGooNetworkManager *const _this, const unsigned _gooId, const float _lockTime, const float _burstTime)>(0x124B270);
	static inline auto FAddToNetwork = PreyFunction<void(CArkProjectileGooNetworkManager *const _this, const int _networkId, const unsigned _gooId)>(0x124B240);
	static inline auto FDeleteFromNetwork = PreyFunction<void(CArkProjectileGooNetworkManager *const _this, const int _networkId, const unsigned _gooId)>(0x124B370);
	static inline auto FNeedsToBurst = PreyFunction<void(CArkProjectileGooNetworkManager *const _this, const int _networkId, const unsigned _gooId)>(0x124B600);
	static inline auto FIncreaseGoo = PreyFunction<bool(CArkProjectileGooNetworkManager *const _this, const int _networkId, const unsigned _gooId, const float _gooScale)>(0x124B500);
	static inline auto FGetGooNetworkFromId = PreyFunction<CArkProjectileGooNetworkManager::GooNetwork *(CArkProjectileGooNetworkManager *const _this, const int _networkId)>(0x124B440);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// CArkProjectileGooNetworkManager
// Header:  Prey/GameDll/ark/ArkProjectileGooNetworkManager.h
class CArkProjectileGooNetworkManager
{ // Size=88 (0x58)
public:
	// CArkProjectileGooNetworkManager::GooNetwork
	// Header:  Prey/GameDll/ark/ArkProjectileGooNetworkManager.h
	struct GooNetwork
	{ // Size=88 (0x58)
		std::vector<unsigned int> m_stoppedGooIdsList;
		std::vector<unsigned int> m_burstingGooIdsList;
		std::vector<unsigned int> m_growingGooIdsList;
		ArkSimpleTimer m_lockingTimer;
		ArkSimpleTimer m_burstingTimer;

		GooNetwork(const unsigned _gooId, const float _lockTime, const float _burstTime);

	#if 0
		~GooNetwork();
		void Serialize(TSerialize _arg0_);
		void AddGooId(const unsigned _arg0_);
		void DeleteGooId(const unsigned _arg0_);
		void NeedsToBurst(const unsigned _arg0_);
		void StopGooGrowth(const unsigned _arg0_);
		bool IncreaseGoo(const unsigned _arg0_, const float _arg1_);
		bool IsEmpty() const;
		void ClearAll();
		void LockAll();
	#endif

		static inline auto FGooNetworkOv1 = PreyFunction<void(CArkProjectileGooNetworkManager::GooNetwork* const _this, const unsigned _gooId, const float _lockTime, const float _burstTime)>(0x12EF400);
	};

	static inline auto k_invalidNetworkId = PreyGlobal<const int>(0x1F4CA3C);
	int m_nextNetworkId;
	std::unordered_map<int, CArkProjectileGooNetworkManager::GooNetwork> m_gooNetworksList;
	bool m_bNetworkGainedGoo;
	float m_gooBurstTimeToMinDelay;
	float m_gooMinBurstDelay;

	void Shutdown() { FShutdown(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	int CreateNetwork(const unsigned _gooId, const float _lockTime, const float _burstTime) { return FCreateNetwork(this, _gooId, _lockTime, _burstTime); }
	void AddToNetwork(const int _networkId, const unsigned _gooId) { FAddToNetwork(this, _networkId, _gooId); }
	void DeleteFromNetwork(const int _networkId, const unsigned _gooId) { FDeleteFromNetwork(this, _networkId, _gooId); }
	void NeedsToBurst(const int _networkId, const unsigned _gooId) { FNeedsToBurst(this, _networkId, _gooId); }
	bool IncreaseGoo(const int _networkId, const unsigned _gooId, const float _gooScale) { return FIncreaseGoo(this, _networkId, _gooId, _gooScale); }
	CArkProjectileGooNetworkManager::GooNetwork* GetGooNetworkFromId(const int _networkId) { return FGetGooNetworkFromId(this, _networkId); }

#if 0
	CArkProjectileGooNetworkManager();
	void StopGooGrowth(const int _arg0_, const unsigned _arg1_);
	bool DidNetworkGainGoo() const;
	void SetBurstValues(const float _arg0_, const float _arg1_);
	void DeleteNetwork(const int _arg0_);
#endif

	static inline auto FShutdown = PreyFunction<void(CArkProjectileGooNetworkManager* const _this)>(0x12EF8F0);
	static inline auto FSerialize = PreyFunction<void(CArkProjectileGooNetworkManager* const _this, TSerialize _ser)>(0x12EF930);
	static inline auto FReset = PreyFunction<void(CArkProjectileGooNetworkManager* const _this)>(0x12EF8F0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooNetworkManager* const _this, const float _frameTime)>(0x12EFEF0);
	static inline auto FCreateNetwork = PreyFunction<int(CArkProjectileGooNetworkManager* const _this, const unsigned _gooId, const float _lockTime, const float _burstTime)>(0x12EF4F0);
	static inline auto FAddToNetwork = PreyFunction<void(CArkProjectileGooNetworkManager* const _this, const int _networkId, const unsigned _gooId)>(0x12EF4C0);
	static inline auto FDeleteFromNetwork = PreyFunction<void(CArkProjectileGooNetworkManager* const _this, const int _networkId, const unsigned _gooId)>(0x12EF5F0);
	static inline auto FNeedsToBurst = PreyFunction<void(CArkProjectileGooNetworkManager* const _this, const int _networkId, const unsigned _gooId)>(0x12EF880);
	static inline auto FIncreaseGoo = PreyFunction<bool(CArkProjectileGooNetworkManager* const _this, const int _networkId, const unsigned _gooId, const float _gooScale)>(0x12EF780);
	static inline auto FGetGooNetworkFromId = PreyFunction<CArkProjectileGooNetworkManager::GooNetwork* (CArkProjectileGooNetworkManager* const _this, const int _networkId)>(0x12EF6C0);
};
#endif // !MOONCRASH
