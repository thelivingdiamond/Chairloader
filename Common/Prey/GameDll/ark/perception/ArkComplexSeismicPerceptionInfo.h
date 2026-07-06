// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkComplexSeismicPerceptionInfo
// Header:  Prey/GameDll/ark/perception/ArkComplexSeismicPerceptionInfo.h
struct ArkComplexSeismicPerceptionInfo
{ // Size=24 (0x18)
	unsigned m_instigatorEntityId;
	unsigned m_eventSourceEntityId;
	Vec3 m_position;
	float m_magnitude;

	ArkComplexSeismicPerceptionInfo(unsigned _instigatorEntityId, unsigned _eventSourceEntityId, const Vec3& _position, float _magnitude);

	static inline auto FArkComplexSeismicPerceptionInfoOv2 = PreyFunction<void(ArkComplexSeismicPerceptionInfo* const _this, unsigned _instigatorEntityId, unsigned _eventSourceEntityId, const Vec3& _position, float _magnitude)>(0x12B5810);
};
#endif // MOONCRASH
