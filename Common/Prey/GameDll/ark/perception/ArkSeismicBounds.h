// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSeismicBounds
// Header:  Prey/GameDll/ark/perception/ArkSeismicBounds.h
struct ArkSeismicBounds
{ // Size=12 (0xC)
	float m_horizontal;
	float m_down;
	float m_up;

	ArkSeismicBounds();
	ArkSeismicBounds(float _horizontal, float _down, float _up);

	static inline auto FArkSeismicBoundsOv1 = PreyFunction<void(ArkSeismicBounds* const _this)>(0x12B5840);
	static inline auto FArkSeismicBoundsOv0 = PreyFunction<void(ArkSeismicBounds* const _this, float _horizontal, float _down, float _up)>(0x1646BE0);
};
#endif // MOONCRASH
