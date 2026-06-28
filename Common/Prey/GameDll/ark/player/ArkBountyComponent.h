// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;

// ArkBountyComponent
// Header:  Prey/GameDll/ark/player/ArkBountyComponent.h
class ArkBountyComponent
{ // Size=24 (0x18)
public:
	uint64_t m_currentBounty;
	uint64_t m_currentTarget;
	bool m_bEnabled;
	int m_bountiesGenerated;

	ArkBountyComponent();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void GenerateBounty(const char* _bountyName) { FGenerateBounty(this, _bountyName); }
	void OnTargetKilled(unsigned _weapon, const IEntity* _pTarget) { FOnTargetKilled(this, _weapon, _pTarget); }
	void OnTargetHit(unsigned _weapon, const IEntity* _pTarget) { FOnTargetHit(this, _weapon, _pTarget); }
	void ResetActiveBounties() { FResetActiveBounties(this); }
	void EnableBounties(bool _bEnable) { FEnableBounties(this, _bEnable); }
	void TestBounty(unsigned _weapon, const IEntity* _pTarget, bool _bLethal) { FTestBounty(this, _weapon, _pTarget, _bLethal); }

#if 0
	bool IsEnabled() const;
#endif

	static inline auto FArkBountyComponent = PreyFunction<void(ArkBountyComponent* const _this)>(0x12BF230);
	static inline auto FReset = PreyFunction<void(ArkBountyComponent* const _this)>(0x12BF600);
	static inline auto FSerialize = PreyFunction<void(ArkBountyComponent* const _this, TSerialize _ser)>(0x12BF660);
	static inline auto FGenerateBounty = PreyFunction<void(ArkBountyComponent* const _this, const char* _bountyName)>(0x12BF2A0);
	static inline auto FOnTargetKilled = PreyFunction<void(ArkBountyComponent* const _this, unsigned _weapon, const IEntity* _pTarget)>(0x12BF5F0);
	static inline auto FOnTargetHit = PreyFunction<void(ArkBountyComponent* const _this, unsigned _weapon, const IEntity* _pTarget)>(0x12BF5E0);
	static inline auto FResetActiveBounties = PreyFunction<void(ArkBountyComponent* const _this)>(0x12BF610);
	static inline auto FEnableBounties = PreyFunction<void(ArkBountyComponent* const _this, bool _bEnable)>(0x12BF250);
	static inline auto FTestBounty = PreyFunction<void(ArkBountyComponent* const _this, unsigned _weapon, const IEntity* _pTarget, bool _bLethal)>(0x12BF700);
};
#endif // MOONCRASH
