// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkNewGamePlus.h
class ArkNewGamePlus // Id=80169D3 Size=64
{
public:
	int m_newGameCount;
	uint64_t m_campaignPlayTime;
	std::vector<unsigned __int64> m_unlockedAbilities;
	
	class ArkResearchSaveData // Id=80169D4 Size=16
	{
	public:
		uint64_t m_researchTopicId;
		int m_scanCount;
		
#if 0
		void Serialize(TSerialize arg0);
		uint64_t GetResearchTopicId() const;
		int GetScanCount() const;
#endif
	};

	std::vector<ArkNewGamePlus::ArkResearchSaveData> m_researchData;
	
	ArkNewGamePlus();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PopulateFromPlayer() { FPopulateFromPlayer(this); }
	void UpdatePlayer() const { FUpdatePlayer(this); }
	void Copy(ArkNewGamePlus const *_pSource) { FCopy(this,_pSource); }
	wstring BuildDescString() const { return FBuildDescString(this); }
	static uint64_t GetEntitlementId() { return FGetEntitlementId(); }
	
#if 0
	int GetNewGameCount() const;
#endif
	
	static inline auto FReset = PreyFunction<void(ArkNewGamePlus *const _this)>(0x11A3B10);
	static inline auto FSerialize = PreyFunction<void(ArkNewGamePlus *const _this, TSerialize _ser)>(0x11A3B30);
	static inline auto FPopulateFromPlayer = PreyFunction<void(ArkNewGamePlus *const _this)>(0x11A38A0);
	static inline auto FUpdatePlayer = PreyFunction<void(ArkNewGamePlus const *const _this)>(0x11A3CD0);
	static inline auto FCopy = PreyFunction<void(ArkNewGamePlus *const _this, ArkNewGamePlus const *_pSource)>(0x11A3880);
	static inline auto FBuildDescString = PreyFunction<wstring(ArkNewGamePlus const *const _this)>(0x11A3340);
	static inline auto FGetEntitlementId = PreyFunction<uint64_t()>(0x11A3890);
};

