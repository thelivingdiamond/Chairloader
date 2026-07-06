// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSimpleSeismicPerceptionInfo
// Header:  Prey/GameDll/ark/perception/ArkSimpleSeismicPerceptionInfo.h
struct ArkSimpleSeismicPerceptionInfo
{ // Size=16 (0x10)
	unsigned m_sourceEntityId;
	Vec3 m_position;

	ArkSimpleSeismicPerceptionInfo(unsigned _sourceEntityId, const Vec3& _position);

	static inline auto FArkSimpleSeismicPerceptionInfoOv2 = PreyFunction<void(ArkSimpleSeismicPerceptionInfo* const _this, unsigned _sourceEntityId, const Vec3& _position)>(0x12BBCD0);
};
#endif // MOONCRASH
