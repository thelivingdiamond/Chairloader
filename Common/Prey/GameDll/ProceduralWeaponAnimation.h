// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/WeaponZoomOffset.h>
#include <Prey/GameDll/weaponbumpoffset.h>
#include <Prey/GameDll/weaponlookoffset.h>
#include <Prey/GameDll/weaponrecoiloffset.h>
#include <Prey/GameDll/weaponstrafeoffset.h>

// CProceduralWeaponAnimation
// Header:  Prey/GameDll/ProceduralWeaponAnimation.h
class CProceduralWeaponAnimation
{ // Size=808 (0x328)
public:
	CWeaponZoomOffset m_weaponZoomOffset;
	CLookOffset m_lookOffset;
	CStrafeOffset m_strafeOffset;
	CRecoilOffset m_recoilOffset;
	CBumpOffset m_bumpOffset;
	QuatT m_customOffset;
	QuatT m_rightOffset;
	QuatT m_leftOffset;
	std::shared_ptr<CWeaponOffsetInput> m_weaponOffsetInput;
	bool m_debugInput;

	CProceduralWeaponAnimation();
	void Update(float deltaTime) { FUpdate(this, deltaTime); }
	void AddCustomOffset(const QuatT& offset) { FAddCustomOffset(this, offset); }
	void ComputeOffsets(float deltaTime) { FComputeOffsets(this, deltaTime); }

#if 0
	CWeaponZoomOffset& GetZoomOffset();
	CLookOffset& GetLookOffset();
	CStrafeOffset& GetStrafeOffset();
	CRecoilOffset& GetRecoilOffset();
	CBumpOffset& GetBumpOffset();
	QuatT GetRightOffset() const;
	QuatT GetLeftOffset() const;
	void UpdateDebugState();
	void ResetCustomOffset();
#endif

	static inline auto FCProceduralWeaponAnimationOv2 = PreyFunction<void(CProceduralWeaponAnimation* const _this)>(0x18F8230);
	static inline auto FUpdate = PreyFunction<void(CProceduralWeaponAnimation* const _this, float deltaTime)>(0x18F9F40);
	static inline auto FAddCustomOffset = PreyFunction<void(CProceduralWeaponAnimation* const _this, const QuatT& offset)>(0x18F8480);
	static inline auto FComputeOffsets = PreyFunction<void(CProceduralWeaponAnimation* const _this, float deltaTime)>(0x18F8700);
};
#endif // MOONCRASH
