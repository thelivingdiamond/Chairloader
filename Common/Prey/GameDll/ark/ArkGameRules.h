// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkUtils.h>
#include <Prey/GameDll/IGameRules.h>

struct IGameRules;

// Header: Exact
// Prey/GameDll/ark/ArkGameRules.h
class ArkGameRules // Id=80146B9 Size=160
{
public:
	ArkUtils::CollisionCache m_collisionCache;
	ArkUtils::ClassList m_selfDamagingClasses;
	std::unordered_map<string,std::array<unsigned __int64,4>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::array<unsigned __int64,4>>>> m_collisionLeveragePackageIds;
	uint64_t m_defaultCollisionDamagePackageId;
	uint64_t m_collisionNoDamagePackageId;
	uint64_t m_psiLiftNpcHeadBumpDamagePackageId;
	float m_collisionDamageSpeedThreshold;
	float m_collisionDamagePlayerThrowSpeedThreshold;
	float m_collisionDamageSpeedPercentage;
	float m_selfDamagingSpeedThresholdSq;
	float m_timeBeforeAllowingSameCollision;
	
	ArkGameRules();
	void OnCollision(IGameRules::SGameCollision const &_event) { FOnCollision(this,_event); }
	
#if 0
	uint64_t GetDefaultCollisionDamagePackageId() const;
	float GetCollisionDamageSpeedThreshold() const;
	uint64_t GetPsiLiftNpcHeadBumpDamagePackageId() const;
#endif
	
	static inline auto FOnCollision = PreyFunction<void(ArkGameRules *const _this, IGameRules::SGameCollision const &_event)>(0x11748F0);
};

