// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkComplexRoomPerceptionInfo.h
struct ArkComplexRoomPerceptionInfo // Id=8014316 Size=12
{
	unsigned m_perceivableEntityId;
	float m_magnitude;
	bool m_bSameAreaContainer;
	
	ArkComplexRoomPerceptionInfo(unsigned _entityId, const float _magnitude, const bool _bSameAreaContainer);
#ifdef MOONCRASH
	static inline auto FArkComplexRoomPerceptionInfo = PreyFunction<void(ArkComplexRoomPerceptionInfo* const _this, unsigned _entityId, const float _magnitude, const bool _bSameAreaContainer)>(0x13587D0);
#endif
};
