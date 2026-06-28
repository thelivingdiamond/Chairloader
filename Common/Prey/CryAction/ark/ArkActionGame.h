// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkUtils.h>

struct EventPhysCollision;
struct SMFXRunTimeEffectParams;

// ArkActionGame
// Header:  CryEngine/cryaction/ark/ArkActionGame.h
class ArkActionGame
{ // Size=96 (0x60)
public:
	// ArkActionGame::BreakAudioInfo
	// Header:  CryEngine/cryaction/ark/ArkActionGame.h
	struct BreakAudioInfo
	{ // Size=8 (0x8)
		unsigned audio;
		float sizeThreshold;

	#if 0
		BreakAudioInfo();
	#endif
	};

	ArkUtils::CollisionCache m_collisionCache;
	ArkUtils::ClassList m_glassBreakingClasses;
	ArkUtils::ClassList m_nonGlassBreakingClasses;
	std::vector<ArkActionGame::BreakAudioInfo> m_breakAudioInfos;

	void PlayCollisionEffect(const uint16_t _effect, SMFXRunTimeEffectParams& _params) { FPlayCollisionEffect(this, _effect, _params); }
	void LoadConfig() { FLoadConfig(this); }
	static bool IsEntityPresentInList(const EventPhysCollision& _epc, const ArkUtils::ClassList& _list) { return FIsEntityPresentInList(_epc, _list); }

#if 0
	bool ShouldEntityBreakGlass(const EventPhysCollision& _arg0_) const;
	bool ShouldEntityNeverBreakGlass(const EventPhysCollision& _arg0_) const;
	void PlayGlassBreakAudio(const Vec3 _arg0_, const float _arg1_) const;
#endif

	static inline auto FPlayCollisionEffect = PreyFunction<void(ArkActionGame* const _this, const uint16_t _effect, SMFXRunTimeEffectParams& _params)>(0x2BBB80);
	static inline auto FLoadConfig = PreyFunction<void(ArkActionGame* const _this)>(0x5C5BF0);
	static inline auto FIsEntityPresentInList = PreyFunction<bool(const EventPhysCollision& _epc, const ArkUtils::ClassList& _list)>(0x5C5B60);
};
#endif // !MOONCRASH
