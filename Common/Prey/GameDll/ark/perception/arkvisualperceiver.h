// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/perception/arkvisualperceiver.h
struct ArkVisualPerceiverVisionParams // Id=8014313 Size=60
{
	Matrix34 m_visionConeLocalToWorldTransform;
	Vec3 m_worldEyePosition;
	
	ArkVisualPerceiverVisionParams();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ArkComplexVisualPerceptionInfo;
struct ArkVisualPerceiverVisionParams;
struct IPhysicalEntity;

// ArkVisualPerceiver
// Header:  Prey/GameDll/ark/perception/ArkVisualPerceiver.h
class ArkVisualPerceiver
{ // Size=8 (0x8)
public:
	uint64_t* GetVisionConeIds(uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId) const { return FGetVisionConeIds(this, _pFirstVisionConeId, _pLastVisionConeId); }
	ArkVisualPerceiverVisionParams GetVisionParams() const { alignas(ArkVisualPerceiverVisionParams) std::byte _return_buf_[sizeof(ArkVisualPerceiverVisionParams)]; return *FGetVisionParams(this, reinterpret_cast<ArkVisualPerceiverVisionParams*>(_return_buf_)); }
	IPhysicalEntity* * GetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const { return FGetIgnoredPhysicalEntitiesInLineOfSight(this, _ppFirstPhysicalEntity, _ppLastPhysicalEntity); }
	void UpdateVisualPerception(const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) { FUpdateVisualPerception(this, _pFirstSimpleStartPerceivingEntityId, _pFirstSimpleContinuePerceivingEntityId, _pFirstSimpleStopPerceivingEntityId, _pLastSimpleStopPerceivingEntityId, _pFirstComplexStartPerceivingPerceptionInfo, _pFirstComplexContinuePerceivingPerceptionInfo, _pLastComplexPerceptionInfo, _pFirstComplexStopPerceivingEntityId, _pLastComplexStopPerceivingEntityId); }
	virtual uint64_t* DoGetVisionConeIds(uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId) const = 0;
	virtual ArkVisualPerceiverVisionParams DoGetVisionParams() const = 0;
	virtual IPhysicalEntity* * DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const = 0;
	virtual void DoUpdateVisualPerception(const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId) = 0;

#if 0
	~ArkVisualPerceiver();
	ArkVisualPerceiver& operator=(const ArkVisualPerceiver& _arg0_);
#endif

	static inline auto FGetVisionConeIds = PreyFunction<uint64_t* (const ArkVisualPerceiver* const _this, uint64_t* _pFirstVisionConeId, uint64_t* _pLastVisionConeId)>(0x14BE950);
	static inline auto FGetVisionParams = PreyFunction<ArkVisualPerceiverVisionParams*(const ArkVisualPerceiver* const _this, ArkVisualPerceiverVisionParams* _return_value_)>(0x12B5850);
	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkVisualPerceiver* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x6CBC30);
	static inline auto FUpdateVisualPerception = PreyFunction<void(ArkVisualPerceiver* const _this, const unsigned* _pFirstSimpleStartPerceivingEntityId, const unsigned* _pFirstSimpleContinuePerceivingEntityId, const unsigned* _pFirstSimpleStopPerceivingEntityId, const unsigned* _pLastSimpleStopPerceivingEntityId, const ArkComplexVisualPerceptionInfo* _pFirstComplexStartPerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pFirstComplexContinuePerceivingPerceptionInfo, const ArkComplexVisualPerceptionInfo* _pLastComplexPerceptionInfo, const unsigned* _pFirstComplexStopPerceivingEntityId, const unsigned* _pLastComplexStopPerceivingEntityId)>(0x1648750);
};

// ArkVisualPerceiverVisionParams
// Header:  Prey/GameDll/ark/perception/ArkVisualPerceiver.h
struct ArkVisualPerceiverVisionParams
{ // Size=60 (0x3C)
	Matrix34 m_visionConeLocalToWorldTransform;
	Vec3 m_worldEyePosition;

	ArkVisualPerceiverVisionParams();

	static inline auto FArkVisualPerceiverVisionParamsOv2 = PreyFunction<void(ArkVisualPerceiverVisionParams* const _this)>(0x1648710);
};
#endif // !MOONCRASH
