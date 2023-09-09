// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/Ark/ArkUtils.h>
#include <Chairloader/PreyFunction.h>

struct EventPhysCollision;
struct SMFXRunTimeEffectParams;

// Header: Exact
// CryEngine/cryaction/ark/ArkActionGame.h
class ArkActionGame // Id=800460E Size=96
{
public:
	ArkUtils::CollisionCache m_collisionCache;
	ArkUtils::ClassList m_glassBreakingClasses;
	ArkUtils::ClassList m_nonGlassBreakingClasses;
	
	struct BreakAudioInfo // Id=800460F Size=8
	{
		unsigned audio;
		float sizeThreshold;
	};

	std::vector<ArkActionGame::BreakAudioInfo> m_breakAudioInfos;
	
	void PlayCollisionEffect(const uint16_t _effect, SMFXRunTimeEffectParams &_params) { FPlayCollisionEffect(this,_effect,_params); }
	void LoadConfig() { FLoadConfig(this); }
	static bool IsEntityPresentInList(EventPhysCollision const &_epc, ArkUtils::ClassList const &_list) { return FIsEntityPresentInList(_epc,_list); }
	
#if 0
	bool ShouldEntityBreakGlass(EventPhysCollision const &arg0) const;
	bool ShouldEntityNeverBreakGlass(EventPhysCollision const &arg0) const;
	void PlayGlassBreakAudio(Vec3 arg0, const float arg1) const;
#endif
	
	static inline auto FPlayCollisionEffect = PreyFunction<void(ArkActionGame *const _this, const uint16_t _effect, SMFXRunTimeEffectParams &_params)>(0x2A3620);
	static inline auto FLoadConfig = PreyFunction<void(ArkActionGame *const _this)>(0x5AC510);
	static inline auto FIsEntityPresentInList = PreyFunction<bool(EventPhysCollision const &_epc, ArkUtils::ClassList const &_list)>(0x5AC480);
};

