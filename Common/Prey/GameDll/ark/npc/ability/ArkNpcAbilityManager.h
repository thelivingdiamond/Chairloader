// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/ArkCommon/arklibrary.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcAbilityManagerNpcData.h>
#include <_unknown/ArkNpcAbilityParams.h>
#include <_unknown/ArkSafeIterator.h>

class ArkNpc;
class ArkNpcAbility;
class ArkNpcAbilityContext;
class ArkNpcAbilityPrereq;
class ArkNpcAbilityPrereqInstance;
class ArkNpcAbilityPrereqModifier;
class XmlNodeRef;
namespace `anonymous-namespace'
{
struct ArkNpcAbilityContextProfileXmlData;
} // namespace `anonymous-namespace'

// ArkNpcAbilityManager
// Header:  Prey/GameDll/ark/npc/ability/ArkNpcAbilityManager.h
class ArkNpcAbilityManager
{ // Size=512 (0x200)
public:
	using AbilityLibrary = ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >;
	using ContextLibrary = ArkLibrary<unsigned __int64,ArkNpcAbilityContext>;
	using ContextProfileLibrary = ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>;
	using IndexVector = std::vector<uint64_t>;
	using NpcDataMap = std::unordered_map<const ArkNpc*, ArkNpcAbilityManagerNpcData>;
	using NpcDataIterator = std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<ArkNpc const * const,ArkNpcAbilityManagerNpcData> > > >;
	using SafeNpcDataIterator = ArkSafeIterator<std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<ArkNpc const * const,ArkNpcAbilityManagerNpcData> > > > >;
	using PrereqInstanceVector = std::vector<std::unique_ptr<ArkNpcAbilityPrereqInstance>>;
	using PrereqModifierVector = std::vector<std::unique_ptr<const ArkNpcAbilityPrereqModifier>>;
	using PrereqModifierPointerVector = std::vector<const ArkNpcAbilityPrereqModifier*>;
	using PrereqPointerVector = std::vector<const ArkNpcAbilityPrereq*>;
	using PrereqVector = std::vector<std::unique_ptr<ArkNpcAbilityPrereq>>;
	using WeightedContextPointerVector = std::vector<ArkWeighted<const ArkNpcAbilityContext*>>;

	static inline auto s_params = PreyGlobal<ArkNpcAbilityParams>(0x2D4F908);
	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > > m_abilityLibrary;
	ArkLibrary<unsigned __int64,ArkNpcAbilityContext> m_contextLibrary;
	ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile> m_contextProfileLibrary;
	std::vector<std::unique_ptr<ArkNpcAbilityPrereq>> m_prereqs;
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::unique_ptr<ArkNpcAbilityPrereq,std::default_delete<ArkNpcAbilityPrereq> > > > > m_globalPrereqsEnd;
	std::vector<std::unique_ptr<const ArkNpcAbilityPrereqModifier>> m_prereqModifiers;
	std::vector<ArkWeighted<const ArkNpcAbilityContext*>> m_contextProfileWeightedContextSequences;
	std::vector<uint64_t> m_contextPrereqUnsortedIndexSequences;
	std::vector<const ArkNpcAbilityPrereq*> m_contextPrereqSequences;
	std::vector<const ArkNpcAbilityPrereqModifier*> m_prereqModifierSequences;
	std::vector<std::unique_ptr<ArkNpcAbilityPrereqInstance>> m_globalPrereqInstances;
	std::unordered_map<const ArkNpc*, ArkNpcAbilityManagerNpcData> m_enabledNpcData;
	std::unordered_map<const ArkNpc*, ArkNpcAbilityManagerNpcData> m_disabledNpcData;
	ArkSafeIterator<std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<ArkNpc const * const,ArkNpcAbilityManagerNpcData> > > > > m_safeEnabledNpcDataIter;

	ArkNpcAbilityManager();
	~ArkNpcAbilityManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	const ArkNpcAbilityContext* GetContext(uint64_t _contextId) const { return FGetContext(this, _contextId); }
	ArkNpcAbilityPrereqInstance& GetGlobalPrereqInstance(const ArkNpcAbilityPrereq& _prereq) const { return FGetGlobalPrereqInstance(this, _prereq); }
	void AddNpc(ArkNpc& _npc, uint64_t _contextProfileId) { FAddNpc(this, _npc, _contextProfileId); }
	void RemoveNpc(const ArkNpc& _npc) { FRemoveNpc(this, _npc); }
	bool HasNpc(const ArkNpc& _npc) const { return FHasNpc(this, _npc); }
	void SetContextProfile(const ArkNpc& _npc, uint64_t _contextProfileId) { FSetContextProfile(this, _npc, _contextProfileId); }
	void PushEnableNpcUpdate(const ArkNpc& _npc) { FPushEnableNpcUpdate(this, _npc); }
	void PopEnableNpcUpdate(const ArkNpc& _npc) { FPopEnableNpcUpdate(this, _npc); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	uint64_t ChooseContext(const ArkNpc& _npc) const { return FChooseContext(this, _npc); }
	bool HasContext(const ArkNpc& _npc, uint64_t _contextId) const { return FHasContext(this, _npc, _contextId); }
	bool CanPerformContext(const ArkNpc& _npc, uint64_t _contextId) const { return FCanPerformContext(this, _npc, _contextId); }
	bool PerformContext(const ArkNpc& _npc, uint64_t _contextId) { return FPerformContext(this, _npc, _contextId); }
	bool IsPerformingAbility(const ArkNpc& _npc) const { return FIsPerformingAbility(this, _npc); }
	bool SafeIsPerformingAbility(const ArkNpc& _npc) const { return FSafeIsPerformingAbility(this, _npc); }
	uint64_t GetCurrentContextId(const ArkNpc& _npc) const { return FGetCurrentContextId(this, _npc); }
	void InterruptCurrentContext(const ArkNpc& _npc) { FInterruptCurrentContext(this, _npc); }
	void OnContextFinished(const ArkNpc& _npc, uint64_t _contextId) { FOnContextFinished(this, _npc, _contextId); }
	const ArkNpcAbility* FindAbility(uint64_t _abilityID) const { return FFindAbility(this, _abilityID); }
	const ArkNpcAbility* FindContextAbility(uint64_t _contextId) const { return FFindContextAbility(this, _contextId); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void LoadContexts() { FLoadContexts(this); }
	void LoadContextProfiles() { FLoadContextProfiles(this); }
	void FinalizeGlobalPrereqs() { FFinalizeGlobalPrereqs(this); }
	const ArkNpcAbilityManagerNpcData& GetNpcData(const ArkNpc& _npc) const { return FGetNpcData(this, _npc); }
	ArkNpcAbilityManagerNpcData* SafeGetNpcData(const ArkNpc& _npc) { return FSafeGetNpcData(this, _npc); }
	ArkNpcAbilityManagerNpcData* GetEnabledNpcData(const ArkNpc& _npc) { return FGetEnabledNpcDataOv1(this, _npc); }
	ArkNpcAbilityManagerNpcData* GetActivelyEnabledNpcData(const ArkNpc& _npc) { return FGetActivelyEnabledNpcDataOv1(this, _npc); }
	const ArkNpcAbilityManagerNpcData* GetActivelyEnabledNpcData(const ArkNpc& _npc) const { return FGetActivelyEnabledNpcDataOv0(this, _npc); }
	void OnContextStarted(const ArkNpc& _npc, uint64_t _contextId) { FOnContextStarted(this, _npc, _contextId); }

#if 0
	ArkNpcAbilityManager(const ArkNpcAbilityManager& _arg0_);
	bool IsNpcUpdateEnabled(const ArkNpc& _arg0_) const;
	uint64_t SafeGetCurrentContextId(const ArkNpc& _arg0_) const;
	ArkNpcAbilityManager& operator=(const ArkNpcAbilityManager& _arg0_);
	void LoadData();
	void UnloadData();
	void LoadAbilities();
	void InitializeGlobalPrereqs();
	const ArkNpcAbilityManagerNpcData* GetEnabledNpcData(const ArkNpc& _arg0_) const;
	const ArkNpcAbilityManagerNpcData* SafeGetEnabledNpcData(const ArkNpc& _arg0_) const;
#endif

	static inline auto FArkNpcAbilityManagerOv1 = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x137A510);
	static inline auto FBitNotArkNpcAbilityManager = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x137A9C0);
	static inline auto FInitialize = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x138BC10);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x138D170);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x138D2B0);
	static inline auto FReset = PreyFunction<void(ArkNpcAbilityManager* const _this, bool _bEnteringGameMode)>(0x1333E90);
	static inline auto FGetContext = PreyFunction<const ArkNpcAbilityContext* (const ArkNpcAbilityManager* const _this, uint64_t _contextId)>(0x138B460);
	static inline auto FGetGlobalPrereqInstance = PreyFunction<ArkNpcAbilityPrereqInstance& (const ArkNpcAbilityManager* const _this, const ArkNpcAbilityPrereq& _prereq)>(0x138B6F0);
	static inline auto FAddNpc = PreyFunction<void(ArkNpcAbilityManager* const _this, ArkNpc& _npc, uint64_t _contextProfileId)>(0x137ADE0);
	static inline auto FRemoveNpc = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x1396680);
	static inline auto FHasNpc = PreyFunction<bool(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138BA90);
	static inline auto FSetContextProfile = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextProfileId)>(0x1396D50);
	static inline auto FPushEnableNpcUpdate = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138D600);
	static inline auto FPopEnableNpcUpdate = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138D480);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAbilityManager* const _this, float _elapsedTime)>(0x1396E50);
	static inline auto FChooseContext = PreyFunction<uint64_t(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x1380230);
	static inline auto FHasContext = PreyFunction<bool(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextId)>(0x138B930);
	static inline auto FCanPerformContext = PreyFunction<bool(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextId)>(0x13801D0);
	static inline auto FPerformContext = PreyFunction<bool(ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextId)>(0x138D3B0);
	static inline auto FIsPerformingAbility = PreyFunction<bool(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x13969B0);
	static inline auto FSafeIsPerformingAbility = PreyFunction<bool(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x13969B0);
	static inline auto FGetCurrentContextId = PreyFunction<uint64_t(const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138B4B0);
	static inline auto FInterruptCurrentContext = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138BC30);
	static inline auto FOnContextFinished = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextId)>(0x138D0B0);
	static inline auto FFindAbility = PreyFunction<const ArkNpcAbility* (const ArkNpcAbilityManager* const _this, uint64_t _abilityID)>(0x13804C0);
	static inline auto FFindContextAbility = PreyFunction<const ArkNpcAbility* (const ArkNpcAbilityManager* const _this, uint64_t _contextId)>(0x13805C0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcAbilityManager* const _this, TSerialize _serializer)>(0x1396AE0);
	static inline auto FLoadContexts = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x138BFE0);
	static inline auto FLoadContextProfiles = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x138BC60);
	static inline auto FFinalizeGlobalPrereqs = PreyFunction<void(ArkNpcAbilityManager* const _this)>(0x1380450);
	static inline auto FGetNpcData = PreyFunction<const ArkNpcAbilityManagerNpcData& (const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138B7B0);
	static inline auto FSafeGetNpcData = PreyFunction<ArkNpcAbilityManagerNpcData* (ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x1396830);
	static inline auto FGetEnabledNpcDataOv1 = PreyFunction<ArkNpcAbilityManagerNpcData* (ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138B5E0);
	static inline auto FGetActivelyEnabledNpcDataOv1 = PreyFunction<ArkNpcAbilityManagerNpcData* (ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138B340);
	static inline auto FGetActivelyEnabledNpcDataOv0 = PreyFunction<const ArkNpcAbilityManagerNpcData* (const ArkNpcAbilityManager* const _this, const ArkNpc& _npc)>(0x138B340);
	static inline auto FOnContextStarted = PreyFunction<void(ArkNpcAbilityManager* const _this, const ArkNpc& _npc, uint64_t _contextId)>(0x138D0E0);
};

// ArkXmlElementReader<`anonymous namespace'::ArkNpcAbilityContextProfileXmlData>
// Header:  Prey/GameDll/ark/npc/ability/ArkNpcAbilityManager.h
struct ArkXmlElementReader<`anonymous namespace'::ArkNpcAbilityContextProfileXmlData>
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, `anonymous-namespace'::ArkNpcAbilityContextProfileXmlData& _value) { return FRead(_elementXmlNode, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, `anonymous-namespace'::ArkNpcAbilityContextProfileXmlData& _value)>(0x138DD70);
};

// ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityPrereqXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityPrereqXmlData> > >
// Header:  Prey/GameDll/ark/npc/ability/ArkNpcAbilityManager.h
struct ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityPrereqXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityPrereqXmlData> > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _vectorXmlNode, std::vector<`anonymous namespace'::ArkNpcAbilityPrereqXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityPrereqXmlData> >& _value) { return FRead(_vectorXmlNode, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _vectorXmlNode, std::vector<`anonymous namespace'::ArkNpcAbilityPrereqXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityPrereqXmlData> >& _value)>(0x138E3F0);
};
#endif // MOONCRASH
