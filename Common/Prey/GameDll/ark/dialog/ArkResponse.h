// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/arkresponse.h>

class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkResponse.h
class ArkResponse // Id=8013647 Size=72
{
public:
	uint64_t m_dialog;
	uint64_t m_id;
	float m_weight;
	float m_globalCooldown;
	float m_entityCooldown;
	float m_delay;
	float m_cutoff;
	bool m_bConversationComplete;
	uint64_t m_trackTargetId;
	EResponseTrackTargetType m_trackTargetType;
	EResponseTrackMethod m_speakerTrackMethod;
	EResponseTrackMethod m_targetTrackMethod;
	uint64_t m_emotionId;
	
	ArkResponse(XmlNodeRef _root);
	
#if 0
	uint64_t GetDialog() const;
	uint64_t GetId() const;
	float GetWeight() const;
	float GetDelay() const;
	bool IsAvailable(const float arg0, const float arg1, const float arg2) const;
	float GetGlobalCooldown() const;
	float GetEntityCooldown() const;
	bool IsValid() const;
	bool IsConversationComplete() const;
	EResponseTrackMethod GetSpeakerTrackMethod() const;
	EResponseTrackMethod GetTargetTrackMethod() const;
	EResponseTrackTargetType GetTargetType() const;
	uint64_t GetTargetId() const;
	uint64_t GetEmotionId() const;
	float GetCutoff() const;
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/dialog/arkresponse.h
class ArkResponseSet // Id=8013648 Size=24
{
public:
	using TResponses = std::vector<ArkResponse>;
	using TLastUsedMap = std::unordered_map<unsigned __int64,float>;
	
	std::vector<ArkResponse> m_responses;
	
	ArkResponseSet(XmlNodeRef _root);
	ArkResponse *FindWeightedResponse(const float _currentTime, std::unordered_map<unsigned __int64,float> const &_entityLastUsed, std::unordered_map<unsigned __int64,float> const &_globalLastUsed) { return FFindWeightedResponse(this,_currentTime,_entityLastUsed,_globalLastUsed); }
	
#if 0
	void AddResponse(ArkResponse const &arg0);
	std::vector<ArkResponse> &GetResponses();
	std::vector<ArkResponse> const &GetResponses() const;
	bool IsValid() const;
#endif
	
	static inline auto FFindWeightedResponse = PreyFunction<ArkResponse *(ArkResponseSet *const _this, const float _currentTime, std::unordered_map<unsigned __int64,float> const &_entityLastUsed, std::unordered_map<unsigned __int64,float> const &_globalLastUsed)>(0x148DA00);
};

