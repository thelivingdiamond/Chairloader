// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkResponseKeyLibrary.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/dialog/ArkDialogAudioManager.h>
#include <Prey/GameDll/ark/dialog/ArkGlobalFacts.h>
#include <Prey/GameDll/ark/dialog/IArkResponseManager.h>

class ArkConversation;
class ArkResponseQuery;
class ArkResponseRule;
class ArkResponseSet;
struct ArkResponseValue;
class CArkFlowNodeConversationEvent;
class CCryName;
class IArkConversation;
class IArkDialogAudioManager;
class IArkSpeaker;
struct ICVar;
struct IEntity;
struct IEntityArchetype;
struct SArkRuleQuery;
struct SConversationParams;

// Header: Exact
// Prey/GameDll/ark/dialog/ArkResponseManager.h
class ArkResponseManager : public IArkResponseManager, public ISystemEventListener // Id=80139C7 Size=2072
{
public:
	using TConversationRecord = std::pair<unsigned __int64,unsigned char>;
	using TRuleBuckets = std::vector<std::vector<ArkResponseRule>>;
	using TWritebackKeyMap = std::unordered_map<unsigned __int64,string>;
	
	struct QueryIterSet // Id=80139E3 Size=16
	{
		std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > current;
		std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > end;
		
#if 0
		void Set(std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > arg0, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > arg1);
#endif
	};

	using TQueryIters = std::array<ArkResponseManager::QueryIterSet,3>;
	
	ArkDialogAudioManager m_audioManager;
	std::vector<std::vector<ArkResponseRule>> m_ruleBuckets;
	std::unordered_map<unsigned __int64,ArkResponseSet> m_responseSets;
	std::unordered_map<unsigned __int64,string> m_writebackKeys;
	ArkGlobalFacts m_globalFacts;
	ArkResponseKeyLibrary m_keyLibrary;
	std::list<ArkConversation,std::allocator<ArkConversation> > m_conversations;
	std::vector<CArkFlowNodeConversationEvent *> m_listeners;
	std::vector<std::pair<unsigned __int64,unsigned char>> m_conversationRecords;
	std::unordered_map<unsigned __int64,float> m_rulesUsed;
	std::unordered_map<unsigned __int64,float> m_responsesUsed;
	uint64_t m_conversationIdGen;
	uint64_t m_dominantConversation;
	ICVar *m_pMaxDistance;
	ICVar *m_pDuckedAudioLevel;
	std::array<ArkResponseManager::QueryIterSet,3> m_queryIters;
	
	ArkResponseManager();
	virtual ~ArkResponseManager();
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	void LoadRules() { FLoadRules(this); }
	void Update() { FUpdate(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void ResetFacts() { FResetFacts(this); }
	void ResetConversationRecords() { FResetConversationRecords(this); }
	virtual IArkConversation *StartConversation(IArkSpeaker *_pSpeaker, uint64_t _conversationId, SConversationParams &_params);
	virtual void EndConversation(IArkConversation *_pConversation, bool _bComplete);
	virtual uint64_t GetNextConversationId();
	void EndAllConversations() { FEndAllConversations(this); }
	ArkResponseRule *FindResponseRuleMatch(uint64_t _conceptId, SArkRuleQuery const &_ruleQuery, bool _bDebug) { return FFindResponseRuleMatch(this,_conceptId,_ruleQuery,_bDebug); }
	ArkResponseSet *FindResponse(const uint64_t _responseId) { return FFindResponse(this,_responseId); }
	ArkResponseRule *FindRuleByID(const uint64_t _ruleId) { return FFindRuleByIDOv1(this,_ruleId); }
	bool MeetsCriteria(SArkRuleQuery const &_ruleQuery, ArkResponseRule const &_rule) { return FMeetsCriteriaOv1(this,_ruleQuery,_rule); }
	bool MeetsCriteria(std::array<ArkResponseManager::QueryIterSet,3> &_queryIters, const bool _bIgnoreVoice, std::vector<unsigned __int64> const &_voices, ArkResponseRule const &_rule) { return FMeetsCriteriaOv0(this,_queryIters,_bIgnoreVoice,_voices,_rule); }
	std::pair<char const *,char const *> GetCharacterNameAndPortrait(ArkResponseRule const &_rule) const { return FGetCharacterNameAndPortrait(this,_rule); }
	uint64_t GetVoiceForRule(ArkResponseRule const &_rule) const { return FGetVoiceForRule(this,_rule); }
	virtual uint64_t ResolveAbstractVoiceIdByPlayerSex(uint64_t _voiceId) const;
	ArkConversation *GetConversation(uint64_t _conversationId) { return FGetConversationOv1(this,_conversationId); }
	ArkConversation const *GetConversation(uint64_t _conversationId) const { return FGetConversationOv0(this,_conversationId); }
	virtual IArkDialogAudioManager &GetAudioManager();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void SetRuleDebug(uint64_t _ruleId, bool _bEnable);
	virtual bool GetRuleDebug(uint64_t _ruleId) const;
	virtual void SaveDebugRules() const;
	virtual void ClearDebugRules();
	bool IsImportantConversationPlaying() const { return FIsImportantConversationPlaying(this); }
	EArkConversationStatus GetConversationStatus(uint64_t _conversationId) const { return FGetConversationStatus(this,_conversationId); }
	static void AddEntityMetaTagsToQuery(IEntity const &_entity, ArkResponseQuery &_query) { FAddEntityMetaTagsToQuery(_entity,_query); }
	static void AddArchetypeMetaTagsToQuery(IEntityArchetype const &_archetype, ArkResponseQuery &_query) { FAddArchetypeMetaTagsToQuery(_archetype,_query); }
	void SetConversationStatus(uint64_t _conversationId, EArkConversationStatus _status) { FSetConversationStatus(this,_conversationId,_status); }
	void ScanResponseData(XmlNodeRef _root, CCryName const &_filename) { FScanResponseData(this,_root,_filename); }
	void LoadDebugRules() { FLoadDebugRules(this); }
	
#if 0
	ArkResponseRule const *FindRuleByID(const uint64_t arg0) const;
	uint64_t GetKey(EArkResponseKey arg0) const;
	ArkGlobalFacts const &GetGlobalFacts() const;
	ArkGlobalFacts &GetGlobalFacts();
	void AddListener(CArkFlowNodeConversationEvent *const arg0);
	void RemoveListener(CArkFlowNodeConversationEvent const *const arg0);
	std::unordered_map<unsigned __int64,ArkResponseSet> const &GetResponseSets() const;
	static unsigned GetBucketIndex(ArkResponseValue const &arg0);
	float GetMaxDistance() const;
	float GetDuckLevel() const;
	bool ShouldDuckConversationAudio(const uint64_t arg0) const;
	void SetRuleAndResponseUsed(uint64_t arg0, uint64_t arg1, float arg2);
	std::unordered_map<unsigned __int64,float> const &GetResponsesUsed() const;
	std::unordered_map<unsigned __int64,string> const &GetWritebackKeys() const;
	ArkResponseKeyLibrary const &GetKeyLibrary() const;
	std::vector<std::vector<ArkResponseRule>> const &GetRuleBuckets() const;
	std::list<ArkConversation,std::allocator<ArkConversation> > const &GetConversations() const;
	ArkConversation const *GetDominantConversation() const;
	void ResetQueryDataIters(SArkRuleQuery const &arg0);
#endif
	
	static inline auto FBitNotArkResponseManager = PreyFunction<void(ArkResponseManager *const _this)>(0x1492370);
	static inline auto FInit = PreyFunction<void(ArkResponseManager *const _this)>(0x14936D0);
	static inline auto FShutdown = PreyFunction<void(ArkResponseManager *const _this)>(0x1495350);
	static inline auto FLoadRules = PreyFunction<void(ArkResponseManager *const _this)>(0x1493BA0);
	static inline auto FUpdate = PreyFunction<void(ArkResponseManager *const _this)>(0x14954A0);
	static inline auto FReset = PreyFunction<void(ArkResponseManager *const _this)>(0x1493FA0);
	static inline auto FSerialize = PreyFunction<void(ArkResponseManager *const _this, TSerialize _ser)>(0x1494A00);
	static inline auto FResetFacts = PreyFunction<void(ArkResponseManager *const _this)>(0x1494090);
	static inline auto FResetConversationRecords = PreyFunction<void(ArkResponseManager *const _this)>(0x1493FD0);
	static inline auto FStartConversation = PreyFunction<IArkConversation *(ArkResponseManager *const _this, IArkSpeaker *_pSpeaker, uint64_t _conversationId, SConversationParams &_params)>(0x1495360);
	static inline auto FEndConversation = PreyFunction<void(ArkResponseManager *const _this, IArkConversation *_pConversation, bool _bComplete)>(0x1492F10);
	static inline auto FGetNextConversationId = PreyFunction<uint64_t(ArkResponseManager *const _this)>(0x1493620);
	static inline auto FEndAllConversations = PreyFunction<void(ArkResponseManager *const _this)>(0x1492D80);
	static inline auto FFindResponseRuleMatch = PreyFunction<ArkResponseRule *(ArkResponseManager *const _this, uint64_t _conceptId, SArkRuleQuery const &_ruleQuery, bool _bDebug)>(0x1493060);
	static inline auto FFindResponse = PreyFunction<ArkResponseSet *(ArkResponseManager *const _this, const uint64_t _responseId)>(0x1493010);
	static inline auto FFindRuleByIDOv1 = PreyFunction<ArkResponseRule *(ArkResponseManager *const _this, const uint64_t _ruleId)>(0x14932C0);
	static inline auto FMeetsCriteriaOv1 = PreyFunction<bool(ArkResponseManager *const _this, SArkRuleQuery const &_ruleQuery, ArkResponseRule const &_rule)>(0x1493F00);
	static inline auto FMeetsCriteriaOv0 = PreyFunction<bool(ArkResponseManager *const _this, std::array<ArkResponseManager::QueryIterSet,3> &_queryIters, const bool _bIgnoreVoice, std::vector<unsigned __int64> const &_voices, ArkResponseRule const &_rule)>(0x1493CF0);
	static inline auto FGetCharacterNameAndPortrait = PreyFunction<std::pair<char const *,char const *>(ArkResponseManager const *const _this, ArkResponseRule const &_rule)>(0x1493300);
	static inline auto FGetVoiceForRule = PreyFunction<uint64_t(ArkResponseManager const *const _this, ArkResponseRule const &_rule)>(0x1493690);
	static inline auto FResolveAbstractVoiceIdByPlayerSex = PreyFunction<uint64_t(ArkResponseManager const *const _this, uint64_t _voiceId)>(0x14940A0);
	static inline auto FGetConversationOv1 = PreyFunction<ArkConversation *(ArkResponseManager *const _this, uint64_t _conversationId)>(0x14934F0);
	static inline auto FGetConversationOv0 = PreyFunction<ArkConversation const *(ArkResponseManager const *const _this, uint64_t _conversationId)>(0x14934F0);
	static inline auto FGetAudioManager = PreyFunction<IArkDialogAudioManager &(ArkResponseManager *const _this)>(0x1296490);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkResponseManager *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1493F60);
	static inline auto FSetRuleDebug = PreyFunction<void(ArkResponseManager *const _this, uint64_t _ruleId, bool _bEnable)>(0x1495310);
	static inline auto FGetRuleDebug = PreyFunction<bool(ArkResponseManager const *const _this, uint64_t _ruleId)>(0x1493640);
	static inline auto FSaveDebugRules = PreyFunction<void(ArkResponseManager const *const _this)>(0x1494260);
	static inline auto FClearDebugRules = PreyFunction<void(ArkResponseManager *const _this)>(0x1492D30);
	static inline auto FIsImportantConversationPlaying = PreyFunction<bool(ArkResponseManager const *const _this)>(0x14936F0);
	static inline auto FGetConversationStatus = PreyFunction<EArkConversationStatus(ArkResponseManager const *const _this, uint64_t _conversationId)>(0x1493560);
	static inline auto FAddEntityMetaTagsToQuery = PreyFunction<void(IEntity const &_entity, ArkResponseQuery &_query)>(0x1492A50);
	static inline auto FAddArchetypeMetaTagsToQuery = PreyFunction<void(IEntityArchetype const &_archetype, ArkResponseQuery &_query)>(0x14929B0);
	static inline auto FSetConversationStatus = PreyFunction<void(ArkResponseManager *const _this, uint64_t _conversationId, EArkConversationStatus _status)>(0x1495210);
	static inline auto FScanResponseData = PreyFunction<void(ArkResponseManager *const _this, XmlNodeRef _root, CCryName const &_filename)>(0x14943E0);
	static inline auto FLoadDebugRules = PreyFunction<void(ArkResponseManager *const _this)>(0x14938C0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Arkresponsekeylibrary.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/dialog/ArkDialogAudioManager.h>
#include <Prey/GameDll/ark/dialog/ArkGlobalFacts.h>
#include <Prey/GameDll/ark/dialog/ArkResponse.h>
#include <Prey/GameDll/ark/dialog/IArkResponseManager.h>

class ArkConversation;
class ArkResponseQuery;
class ArkResponseRule;
struct ArkResponseValue;
class CArkFlowNodeConversationEvent;
enum class EArkConversationStatus;
enum class EArkResponseKey;
enum ESystemEvent;
class IArkConversation;
class IArkDialogAudioManager;
class IArkSpeaker;
struct ICVar;
struct IEntity;
struct IEntityArchetype;
struct SArkRuleQuery;
struct SConversationParams;
class XmlNodeRef;

// ArkResponseManager
// Header:  Prey/GameDll/ark/dialog/ArkResponseManager.h
class ArkResponseManager : public IArkResponseManager, public ISystemEventListener
{ // Size=2104 (0x838)
public:
	// ArkResponseManager::QueryIterSet
	// Header:  Prey/GameDll/ark/dialog/ArkResponseManager.h
	struct QueryIterSet
	{ // Size=16 (0x10)
		std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > current;
		std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > end;

	#if 0
		QueryIterSet();
		void Set(std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > _arg0_, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkResponseFact> > > _arg1_);
	#endif
	};

	using TConversationRecord = std::pair<uint64_t, unsigned char>;
	using TRuleBuckets = std::vector<std::vector<ArkResponseRule>>;
	using TWritebackKeyMap = std::unordered_map<uint64_t, string>;
	using TQueryIters = std::array<ArkResponseManager::QueryIterSet, 3>;

	ArkDialogAudioManager m_audioManager;
	std::vector<std::vector<ArkResponseRule>> m_ruleBuckets;
	std::unordered_map<uint64_t, ArkResponseSet> m_responseSets;
	std::unordered_map<uint64_t, string> m_writebackKeys;
	ArkGlobalFacts m_globalFacts;
	ArkResponseKeyLibrary m_keyLibrary;
	std::list<ArkConversation,std::allocator<ArkConversation> > m_conversations;
	std::vector<CArkFlowNodeConversationEvent*> m_listeners;
	std::vector<std::pair<uint64_t, unsigned char>> m_conversationRecords;
	std::unordered_map<uint64_t, float> m_rulesUsed;
	std::unordered_map<uint64_t, float> m_responsesUsed;
	uint64_t m_conversationIdGen;
	uint64_t m_dominantConversation;
	ICVar* m_pMaxDistance;
	ICVar* m_pDuckedAudioLevel;
	std::array<ArkResponseManager::QueryIterSet, 3> m_queryIters;

	ArkResponseManager();
	virtual ~ArkResponseManager();
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	void LoadRules() { FLoadRules(this); }
	void Update() { FUpdate(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void ResetFacts() { FResetFacts(this); }
	void ResetConversationRecords() { FResetConversationRecords(this); }
	virtual IArkConversation* StartConversation(IArkSpeaker* _pSpeaker, uint64_t _conversationId, SConversationParams& _params);
	virtual void EndConversation(IArkConversation* _pConversation, bool _bComplete);
	virtual uint64_t GetNextConversationId();
	void EndAllConversations() { FEndAllConversations(this); }
	ArkResponseRule* FindResponseRuleMatch(uint64_t _conceptId, const SArkRuleQuery& _ruleQuery, bool _bDebug) { return FFindResponseRuleMatch(this, _conceptId, _ruleQuery, _bDebug); }
	ArkResponseSet* FindResponse(const uint64_t _responseId) { return FFindResponse(this, _responseId); }
	ArkResponseRule* FindRuleByID(const uint64_t _ruleId) { return FFindRuleByIDOv1(this, _ruleId); }
	bool MeetsCriteria(const SArkRuleQuery& _ruleQuery, const ArkResponseRule& _rule) { return FMeetsCriteriaOv1(this, _ruleQuery, _rule); }
	bool MeetsCriteria(std::array<ArkResponseManager::QueryIterSet, 3>& _queryIters, const bool _bIgnoreVoice, const std::vector<uint64_t>& _voices, const ArkResponseRule& _rule) { return FMeetsCriteriaOv0(this, _queryIters, _bIgnoreVoice, _voices, _rule); }
	std::pair<const char*, const char*> GetCharacterNameAndPortrait(const ArkResponseRule& _rule) const { alignas(std::pair<const char*, const char*>) std::byte _return_buf_[sizeof(std::pair<const char*, const char*>)]; return *FGetCharacterNameAndPortrait(this, reinterpret_cast<std::pair<const char*, const char*>*>(_return_buf_), _rule); }
	uint64_t GetVoiceForRule(const ArkResponseRule& _rule) const { return FGetVoiceForRule(this, _rule); }
	virtual uint64_t ResolveAbstractVoiceIdByPlayerSex(uint64_t _voiceId) const;
	ArkConversation* GetConversation(uint64_t _conversationId) { return FGetConversationOv1(this, _conversationId); }
	const ArkConversation* GetConversation(uint64_t _conversationId) const { return FGetConversationOv0(this, _conversationId); }
	virtual IArkDialogAudioManager& GetAudioManager();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void SetRuleDebug(uint64_t _ruleId, bool _bEnable);
	virtual bool GetRuleDebug(uint64_t _ruleId) const;
	virtual void SaveDebugRules() const;
	virtual void ClearDebugRules();
	bool IsImportantConversationPlaying() const { return FIsImportantConversationPlaying(this); }
	EArkConversationStatus GetConversationStatus(uint64_t _conversationId) const { return FGetConversationStatus(this, _conversationId); }
	static void AddEntityMetaTagsToQuery(const IEntity& _entity, ArkResponseQuery& _query) { FAddEntityMetaTagsToQuery(_entity, _query); }
	static void AddArchetypeMetaTagsToQuery(const IEntityArchetype& _archetype, ArkResponseQuery& _query) { FAddArchetypeMetaTagsToQuery(_archetype, _query); }
	void SetConversationStatus(uint64_t _conversationId, EArkConversationStatus _status) { FSetConversationStatus(this, _conversationId, _status); }
	void ScanResponseData(XmlNodeRef _root, const char* _filename) { FScanResponseData(this, _root, _filename); }
	void LoadDebugRules() { FLoadDebugRules(this); }

#if 0
	const ArkResponseRule* FindRuleByID(const uint64_t _arg0_) const;
	uint64_t GetKey(const EArkResponseKey _arg0_) const;
	const ArkGlobalFacts& GetGlobalFacts() const;
	ArkGlobalFacts& GetGlobalFacts();
	void AddListener(CArkFlowNodeConversationEvent* const _arg0_);
	void RemoveListener(const CArkFlowNodeConversationEvent* const _arg0_);
	const std::unordered_map<uint64_t, ArkResponseSet>& GetResponseSets() const;
	static unsigned GetBucketIndex(const ArkResponseValue& _arg0_);
	float GetMaxDistance() const;
	float GetDuckLevel() const;
	bool ShouldDuckConversationAudio(const uint64_t _arg0_) const;
	void SetRuleAndResponseUsed(uint64_t _arg0_, uint64_t _arg1_, float _arg2_);
	const std::unordered_map<uint64_t, float>& GetResponsesUsed() const;
	const std::unordered_map<uint64_t, string>& GetWritebackKeys() const;
	const ArkResponseKeyLibrary& GetKeyLibrary() const;
	const std::vector<std::vector<ArkResponseRule>>& GetRuleBuckets() const;
	const std::list<ArkConversation,std::allocator<ArkConversation> >& GetConversations() const;
	const ArkConversation* GetDominantConversation() const;
	void ResetQueryDataIters(const SArkRuleQuery& _arg0_);
#endif

	static inline auto FArkResponseManagerOv1 = PreyFunction<void(ArkResponseManager* const _this)>(0x15A97A0);
	static inline auto FBitNotArkResponseManager = PreyFunction<void(ArkResponseManager* const _this)>(0x15A9D30);
	static inline auto FInit = PreyFunction<void(ArkResponseManager* const _this)>(0x15AAF00);
	static inline auto FShutdown = PreyFunction<void(ArkResponseManager* const _this)>(0x15ACE00);
	static inline auto FLoadRules = PreyFunction<void(ArkResponseManager* const _this)>(0x15AB3E0);
	static inline auto FUpdate = PreyFunction<void(ArkResponseManager* const _this)>(0x15ACF50);
	static inline auto FReset = PreyFunction<void(ArkResponseManager* const _this)>(0x15AB9D0);
	static inline auto FSerialize = PreyFunction<void(ArkResponseManager* const _this, TSerialize _ser)>(0x15AC4B0);
	static inline auto FResetFacts = PreyFunction<void(ArkResponseManager* const _this)>(0x15ABAC0);
	static inline auto FResetConversationRecords = PreyFunction<void(ArkResponseManager* const _this)>(0x15ABA00);
	static inline auto FStartConversation = PreyFunction<IArkConversation* (ArkResponseManager* const _this, IArkSpeaker* _pSpeaker, uint64_t _conversationId, SConversationParams& _params)>(0x15ACE10);
	static inline auto FEndConversation = PreyFunction<void(ArkResponseManager* const _this, IArkConversation* _pConversation, bool _bComplete)>(0x15AA740);
	static inline auto FGetNextConversationId = PreyFunction<uint64_t(ArkResponseManager* const _this)>(0x15AAE50);
	static inline auto FEndAllConversations = PreyFunction<void(ArkResponseManager* const _this)>(0x15AA5B0);
	static inline auto FFindResponseRuleMatch = PreyFunction<ArkResponseRule* (ArkResponseManager* const _this, uint64_t _conceptId, const SArkRuleQuery& _ruleQuery, bool _bDebug)>(0x15AA890);
	static inline auto FFindResponse = PreyFunction<ArkResponseSet* (ArkResponseManager* const _this, const uint64_t _responseId)>(0x15AA840);
	static inline auto FFindRuleByIDOv1 = PreyFunction<ArkResponseRule* (ArkResponseManager* const _this, const uint64_t _ruleId)>(0x15AAAF0);
	static inline auto FMeetsCriteriaOv1 = PreyFunction<bool(ArkResponseManager* const _this, const SArkRuleQuery& _ruleQuery, const ArkResponseRule& _rule)>(0x15AB930);
	static inline auto FMeetsCriteriaOv0 = PreyFunction<bool(ArkResponseManager* const _this, std::array<ArkResponseManager::QueryIterSet, 3>& _queryIters, const bool _bIgnoreVoice, const std::vector<uint64_t>& _voices, const ArkResponseRule& _rule)>(0x15AB720);
	static inline auto FGetCharacterNameAndPortrait = PreyFunction<std::pair<const char*, const char*>*(const ArkResponseManager* const _this, std::pair<const char*, const char*>* _return_value_, const ArkResponseRule& _rule)>(0x15AAB30);
	static inline auto FGetVoiceForRule = PreyFunction<uint64_t(const ArkResponseManager* const _this, const ArkResponseRule& _rule)>(0x15AAEC0);
	static inline auto FResolveAbstractVoiceIdByPlayerSex = PreyFunction<uint64_t(const ArkResponseManager* const _this, uint64_t _voiceId)>(0x15ABAD0);
	static inline auto FGetConversationOv1 = PreyFunction<ArkConversation* (ArkResponseManager* const _this, uint64_t _conversationId)>(0x15AAD20);
	static inline auto FGetConversationOv0 = PreyFunction<const ArkConversation* (const ArkResponseManager* const _this, uint64_t _conversationId)>(0x15AAD20);
	static inline auto FGetAudioManager = PreyFunction<IArkDialogAudioManager& (ArkResponseManager* const _this)>(0x10ED260);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x15AB990);
	static inline auto FSetRuleDebug = PreyFunction<void(ArkResponseManager* const _this, uint64_t _ruleId, bool _bEnable)>(0x15ACDC0);
	static inline auto FGetRuleDebug = PreyFunction<bool(const ArkResponseManager* const _this, uint64_t _ruleId)>(0x15AAE70);
	static inline auto FSaveDebugRules = PreyFunction<void(const ArkResponseManager* const _this)>(0x15ABC90);
	static inline auto FClearDebugRules = PreyFunction<void(ArkResponseManager* const _this)>(0x15AA560);
	static inline auto FIsImportantConversationPlaying = PreyFunction<bool(const ArkResponseManager* const _this)>(0x15AAF20);
	static inline auto FGetConversationStatus = PreyFunction<EArkConversationStatus(const ArkResponseManager* const _this, uint64_t _conversationId)>(0x15AAD90);
	static inline auto FAddEntityMetaTagsToQuery = PreyFunction<void(const IEntity& _entity, ArkResponseQuery& _query)>(0x15AA280);
	static inline auto FAddArchetypeMetaTagsToQuery = PreyFunction<void(const IEntityArchetype& _archetype, ArkResponseQuery& _query)>(0x15AA1E0);
	static inline auto FSetConversationStatus = PreyFunction<void(ArkResponseManager* const _this, uint64_t _conversationId, EArkConversationStatus _status)>(0x15ACCC0);
	static inline auto FScanResponseData = PreyFunction<void(ArkResponseManager* const _this, XmlNodeRef _root, const char* _filename)>(0x15ABE10);
	static inline auto FLoadDebugRules = PreyFunction<void(ArkResponseManager* const _this)>(0x15AB0F0);
};
#endif // !MOONCRASH
