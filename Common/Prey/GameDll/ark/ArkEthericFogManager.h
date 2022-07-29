// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkEthericFogManager.h
class ArkEthericFogManager // Id=801530C Size=40
{
public:
	struct EthericFogInfo // Id=801530D Size=8
	{
		unsigned m_fogFragmentEntityId;
		bool m_bIsTrackingSmallFragment;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(ArkEthericFogManager::EthericFogInfo const &arg0) const;
#endif
	};

	uint64_t m_maxNumFragments;
	float m_minDistanceBetweenFragmentsSq;
	float m_largeFragmentPreventOverlapRadiusSq;
	std::vector<ArkEthericFogManager::EthericFogInfo> m_activeFogFragments;
	
	ArkEthericFogManager();
	~ArkEthericFogManager();
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	bool TrySpawnEthericFogFragment(Vec3 _fogSpawnLocation, bool _bIsFragmentSmall) { return FTrySpawnEthericFogFragment(this,_fogSpawnLocation,_bIsFragmentSmall); }
	void OnFragmentExpired(unsigned _expiredFragment) { FOnFragmentExpired(this,_expiredFragment); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void SpawnFragment(Vec3 _fogSpawnLocation, bool _bIsFragmentSmall) { FSpawnFragment(this,_fogSpawnLocation,_bIsFragmentSmall); }
	
#if 0
	void Update(float arg0);
	void Reset(bool arg0);
	void EmptyActiveList();
	void LoadConfig();
#endif
	
	static inline auto FBitNotArkEthericFogManager = PreyFunction<void(ArkEthericFogManager *const _this)>(0x115E360);
	static inline auto FSerialize = PreyFunction<void(ArkEthericFogManager *const _this, TSerialize _ser)>(0x115E3E0);
	static inline auto FTrySpawnEthericFogFragment = PreyFunction<bool(ArkEthericFogManager *const _this, Vec3 _fogSpawnLocation, bool _bIsFragmentSmall)>(0x115E650);
	static inline auto FOnFragmentExpired = PreyFunction<void(ArkEthericFogManager *const _this, unsigned _expiredFragment)>(0x115E380);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkEthericFogManager *const _this)>(0x115E3D0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkEthericFogManager *const _this)>(0x115E3D0);
	static inline auto FSpawnFragment = PreyFunction<void(ArkEthericFogManager *const _this, Vec3 _fogSpawnLocation, bool _bIsFragmentSmall)>(0x115E400);
};

