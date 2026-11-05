#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ArkComplexRoomPerceptionInfo;

// ArkRoomPerceiver
// Header:  _unknown/ArkRoomPerceiver.h
class ArkRoomPerceiver
{ // Size=8 (0x8)
public:
	uint64_t GetRoomPerceptionModelId() const { return FGetRoomPerceptionModelId(this); }
	unsigned GetAreaContainerEntityId() const { return FGetAreaContainerEntityId(this); }
	unsigned FindCurrentRoomEntityId() const { return FFindCurrentRoomEntityId(this); }
	void UpdateRoomPerception(const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) { FUpdateRoomPerception(this, _pFirstComplexStartPerceivingPerceptionInfo, _pLastComplexStartPerceivingPerceptionInfo, _pFirstComplexContinuePerceivingPerceptionInfo, _pLastComplexContinuePerceivingPerceptionInfo, _pFirstComplexStopPerceivingEntityId, _pLastComplexStopPerceivingEntityId); }
	virtual Vec3 DoGetRoomPosition() const = 0;
	virtual unsigned DoGetRoomPerceiverEntityId() const = 0;
	virtual uint64_t DoGetRoomPerceptionModelId() const = 0;
	virtual unsigned DoGetAreaContainerEntityId() const = 0;
	virtual unsigned DoFindCurrentRoomEntityId() const = 0;
	virtual void DoUpdateRoomPerception(const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexPContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) = 0;

#if 0
	unsigned GetRoomPerceiverEntityId() const;
	Vec3 GetRoomPosition() const;
	~ArkRoomPerceiver();
	ArkRoomPerceiver& operator=(const ArkRoomPerceiver& _arg0_);
#endif

	static inline auto FGetRoomPerceptionModelId = PreyFunction<uint64_t(const ArkRoomPerceiver* const _this)>(0x15AAEA0);
	static inline auto FGetAreaContainerEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x12941A0);
	static inline auto FFindCurrentRoomEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x12B5B30);
	static inline auto FUpdateRoomPerception = PreyFunction<void(ArkRoomPerceiver* const _this, const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x12B5B20);
};
#else
// Header file automatically created from a PDB.
#pragma once

struct ArkComplexRoomPerceptionInfo;

// ArkRoomPerceiver
// Header:  _unknown/ArkRoomPerceiver.h
class ArkRoomPerceiver
{ // Size=8 (0x8)
public:
	uint64_t GetRoomPerceptionModelId() const { return FGetRoomPerceptionModelId(this); }
	unsigned GetAreaContainerEntityId() const { return FGetAreaContainerEntityId(this); }
	unsigned FindCurrentRoomEntityId() const { return FFindCurrentRoomEntityId(this); }
	void UpdateRoomPerception(const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) { FUpdateRoomPerception(this, _pFirstComplexStartPerceivingPerceptionInfo, _pLastComplexStartPerceivingPerceptionInfo, _pFirstComplexContinuePerceivingPerceptionInfo, _pLastComplexContinuePerceivingPerceptionInfo, _pFirstComplexStopPerceivingEntityId, _pLastComplexStopPerceivingEntityId); }
	virtual Vec3 DoGetRoomPosition() const = 0;
	virtual unsigned DoGetRoomPerceiverEntityId() const = 0;
	virtual uint64_t DoGetRoomPerceptionModelId() const = 0;
	virtual unsigned DoGetAreaContainerEntityId() const = 0;
	virtual unsigned DoFindCurrentRoomEntityId() const = 0;
	virtual void DoUpdateRoomPerception(const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexPContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) = 0;

#if 0
	unsigned GetRoomPerceiverEntityId() const;
	Vec3 GetRoomPosition() const;
	~ArkRoomPerceiver();
	ArkRoomPerceiver& operator=(const ArkRoomPerceiver& _arg0_);
#endif

	static inline auto FGetRoomPerceptionModelId = PreyFunction<uint64_t(const ArkRoomPerceiver* const _this)>(0x6CBC30);
	static inline auto FGetAreaContainerEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x1338520);
	static inline auto FFindCurrentRoomEntityId = PreyFunction<unsigned(const ArkRoomPerceiver* const _this)>(0x1727910);
	static inline auto FUpdateRoomPerception = PreyFunction<void(ArkRoomPerceiver* const _this, const ArkComplexRoomPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexStartPerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexRoomPerceptionInfo* _pLastComplexContinuePerceivingPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x135F1E0);
};
#endif
