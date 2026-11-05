// Header file automatically created from a PDB.
#pragma once

struct ArkComplexAuralPerceptionInfo;
struct ArkSimpleAuralPerceptionInfo;

// ArkAuralPerceiver
// Header:  Prey/GameDll/ark/perception/ArkAuralPerceiver.h
class ArkAuralPerceiver
{ // Size=8 (0x8)
public:
	unsigned GetEntityId() const { return FGetEntityId(this); }
	Vec3 GetHearingPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetHearingPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void UpdateAuralPerception(const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo) { FUpdateAuralPerception(this, _pFirstSimpleAuralPerceptionInfo, _pLastSimpleAuralPerceptionInfo, _pFirstComplexAuralPerceptionInfo, _pLastComplexAuralPerceptionInfo); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual Vec3 DoGetHearingPosition() const = 0;
	virtual void DoUpdateAuralPerception(const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo) = 0;

#if 0
	~ArkAuralPerceiver();
	ArkAuralPerceiver& operator=(const ArkAuralPerceiver& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkAuralPerceiver* const _this)>(0x13B26F0);
	static inline auto FGetHearingPosition = PreyFunction<Vec3*(const ArkAuralPerceiver* const _this, Vec3* _return_value_)>(0x13EF180);
	static inline auto FUpdateAuralPerception = PreyFunction<void(ArkAuralPerceiver* const _this, const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo)>(0x1457570);
#else
	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkAuralPerceiver* const _this)>(0x14BE950);
	static inline auto FGetHearingPosition = PreyFunction<Vec3*(const ArkAuralPerceiver* const _this, Vec3* _return_value_)>(0x12B5850);
	static inline auto FUpdateAuralPerception = PreyFunction<void(ArkAuralPerceiver* const _this, const ArkSimpleAuralPerceptionInfo* _pFirstSimpleAuralPerceptionInfo, const ArkSimpleAuralPerceptionInfo* _pLastSimpleAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pFirstComplexAuralPerceptionInfo, const ArkComplexAuralPerceptionInfo* _pLastComplexAuralPerceptionInfo)>(0x12B5870);
#endif
};

