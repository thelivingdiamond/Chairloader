#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ArkComplexSeismicPerceptionInfo;
struct ArkSimpleSeismicPerceptionInfo;

// ArkSeismicPerceiver
// Header:  _unknown/ArkSeismicPerceiver.h
class ArkSeismicPerceiver
{ // Size=8 (0x8)
public:
	TNavigationID<ENavigationIDTag::MeshIDTag> GetNavigationMeshId(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navigationAgentTypeId) const { alignas(TNavigationID<ENavigationIDTag::MeshIDTag>) std::byte _return_buf_[sizeof(TNavigationID<ENavigationIDTag::MeshIDTag>)]; return *FGetNavigationMeshId(this, reinterpret_cast<TNavigationID<ENavigationIDTag::MeshIDTag>*>(_return_buf_), _navigationAgentTypeId); }
	void UpdateSeismicPerception(const ArkSimpleSeismicPerceptionInfo* _pFirstSimpleSeismicPerceptionInfo, const ArkSimpleSeismicPerceptionInfo* _pLastSimpleSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pFirstComplexSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pLastComplexSeismicPerceptionInfo) { FUpdateSeismicPerception(this, _pFirstSimpleSeismicPerceptionInfo, _pLastSimpleSeismicPerceptionInfo, _pFirstComplexSeismicPerceptionInfo, _pLastComplexSeismicPerceptionInfo); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual TNavigationID<ENavigationIDTag::MeshIDTag> DoGetNavigationMeshId(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navigationAgentTypeId) const = 0;
	virtual void DoUpdateSeismicPerception(const ArkSimpleSeismicPerceptionInfo* _pFirstSimpleSeismicPerceptionInfo, const ArkSimpleSeismicPerceptionInfo* _pLastSimpleSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pFirstComplexSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pLastComplexSeismicPerceptionInfo) = 0;

#if 0
	unsigned GetEntityId() const;
	~ArkSeismicPerceiver();
	ArkSeismicPerceiver& operator=(const ArkSeismicPerceiver& _arg0_);
#endif

	static inline auto FGetNavigationMeshId = PreyFunction<TNavigationID<ENavigationIDTag::MeshIDTag>*(const ArkSeismicPerceiver* const _this, TNavigationID<ENavigationIDTag::MeshIDTag>* _return_value_, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navigationAgentTypeId)>(0x12B5850);
	static inline auto FUpdateSeismicPerception = PreyFunction<void(ArkSeismicPerceiver* const _this, const ArkSimpleSeismicPerceptionInfo* _pFirstSimpleSeismicPerceptionInfo, const ArkSimpleSeismicPerceptionInfo* _pLastSimpleSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pFirstComplexSeismicPerceptionInfo, const ArkComplexSeismicPerceptionInfo* _pLastComplexSeismicPerceptionInfo)>(0x12B5870);
};



#endif