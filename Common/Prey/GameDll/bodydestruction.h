// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CBodyDestrutibilityInstance;
struct HitInfo;
struct IAttachmentManager;
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IMaterial;
struct SBodyCharacterInfo;
struct SBodyDestructibilityDef;
class XmlNodeRef;

// CBodyDestructibilityProfile
// Header:  Prey/GameDll/bodydestruction.h
class CBodyDestructibilityProfile : public _reference_target<int>
{ // Size=280 (0x118)
public:
	// CBodyDestructibilityProfile::SBodyHitType
	// Header:  Prey/GameDll/bodydestruction.h
	struct SBodyHitType
	{ // Size=16 (0x10)
		int hitTypeId;
		float damageMultiplier;
		int destructionEvents[2];

	#if 0
		SBodyHitType();
		bool operator==(const CBodyDestructibilityProfile::SBodyHitType& _arg0_) const;
		bool operator==(const int& _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SDestructibleBodyPart
	// Header:  Prey/GameDll/bodydestruction.h
	struct SDestructibleBodyPart
	{ // Size=56 (0x38)
		string name;
		unsigned hashId;
		float healthRatio;
		float minHealthToDestroyOnDeathRatio;
		int destructionEvents[2];
		std::vector<CBodyDestructibilityProfile::SBodyHitType> hitTypes;

	#if 0
		SDestructibleBodyPart();
		const CBodyDestructibilityProfile::SBodyHitType* GetHitTypeModifiers(const int _arg0_) const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SBodyPartExplosion
	// Header:  Prey/GameDll/bodydestruction.h
	struct SBodyPartExplosion
	{ // Size=32 (0x20)
		float damage;
		float minRadius;
		float maxRadius;
		float pressure;
		int hitTypeId;
		string effectName;

	#if 0
		SBodyPartExplosion();
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SDestructionEvent
	// Header:  Prey/GameDll/bodydestruction.h
	struct SDestructionEvent
	{ // Size=144 (0x90)
		string name;
		string particleFX;
		string scriptCondition;
		string scriptCallback;
		unsigned eventId;
		std::vector<int> attachmentsToHide;
		std::vector<int> attachmentsToUnhide;
		std::vector<int> eventsToDisable;
		std::vector<int> eventsToStop;
		CBodyDestructibilityProfile::SBodyPartExplosion* pExplosion;

		~SDestructionEvent();

	#if 0
		SDestructionEvent();
		bool operator==(const CBodyDestructibilityProfile::SDestructionEvent& _arg0_) const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif

		static inline auto FBitNotSDestructionEvent = PreyFunction<void(CBodyDestructibilityProfile::SDestructionEvent* const _this)>(0x17B2EB0);
	};

	// CBodyDestructibilityProfile::SHealthRatioEvent
	// Header:  Prey/GameDll/bodydestruction.h
	struct SHealthRatioEvent
	{ // Size=24 (0x18)
		float healthRatio;
		int destructionEvent;
		string bone;
		string material;

	#if 0
		SHealthRatioEvent();
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::compareHealthRatios
	// Header:  Prey/GameDll/bodydestruction.h
	struct compareHealthRatios
	{ // Size=1 (0x1)
	#if 0
		bool operator()(const CBodyDestructibilityProfile::SHealthRatioEvent& _arg0_, const CBodyDestructibilityProfile::SHealthRatioEvent& _arg1_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SExplosionDeathEvent
	// Header:  Prey/GameDll/bodydestruction.h
	struct SExplosionDeathEvent
	{ // Size=32 (0x20)
		float gibProbability;
		float minExplosionDamage;
		int destructionEvent;
		string bone;
		string material;

	#if 0
		SExplosionDeathEvent();
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SMikeDeath
	// Header:  Prey/GameDll/bodydestruction.h
	struct SMikeDeath
	{ // Size=48 (0x30)
		int attachmentId;
		int destructionEvent;
		string bone;
		string object;
		string animation;
		float alphaTestFadeOutDelay;
		float alphaTestFadeOutTimeOut;
		float alphaTestFadeOutMaxAlpha;

	#if 0
		SMikeDeath();
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDestructibilityProfile::SParsingHelper
	// Header:  Prey/GameDll/bodydestruction.h
	struct SParsingHelper
	{ // Size=48 (0x30)
		std::map<unsigned int, int> attachmentIndices;
		std::map<unsigned int, int> boneIndices;
		std::map<unsigned int, int> eventIndices;

		int GetAttachmentIndex(const char* attachmentName) const { return FGetAttachmentIndex(this, attachmentName); }
		int GetEventIndex(const char* eventName) const { return FGetEventIndex(this, eventName); }

	#if 0
		int GetBoneIndex(const char* _arg0_) const;
	#endif

		static inline auto FGetAttachmentIndex = PreyFunction<int(const CBodyDestructibilityProfile::SParsingHelper* const _this, const char* attachmentName)>(0x17B3460);
		static inline auto FGetEventIndex = PreyFunction<int(const CBodyDestructibilityProfile::SParsingHelper* const _this, const char* eventName)>(0x17B34F0);
	};

	// CBodyDestructibilityProfile::SBodyPartQueryResult
	// Header:  Prey/GameDll/bodydestruction.h
	struct SBodyPartQueryResult
	{ // Size=16 (0x10)
		const CBodyDestructibilityProfile::SDestructibleBodyPart* pPart;
		int index;

	#if 0
		SBodyPartQueryResult();
	#endif
	};

	using TDestructibleBodyPartId = int;
	using TDestructionEventId = int;
	using TDestructibleAttachmentIds = std::vector<int>;
	using TDestructionEventIds = std::vector<int>;
	using TBodyHitTypes = std::vector<CBodyDestructibilityProfile::SBodyHitType>;
	using TDestructibleBodyParts = std::vector<CBodyDestructibilityProfile::SDestructibleBodyPart>;
	using TDestructionEvents = std::vector<CBodyDestructibilityProfile::SDestructionEvent>;
	using THealthRatioEvents = std::vector<CBodyDestructibilityProfile::SHealthRatioEvent>;
	using TNameHashToIdxMap = std::map<unsigned int, int>;
	using IMaterialSmartPtr = _smart_ptr<IMaterial>;
	using TReplacementMaterials = std::map<unsigned int, _smart_ptr<IMaterial>>;
	using ICharacterInstancePtr = _smart_ptr<ICharacterInstance>;
	using TCachedCharacterInstances = std::map<unsigned int, _smart_ptr<ICharacterInstance>>;

	static inline auto PHYSICS_ATTACHMENT_BASE_ID = PreyGlobal<const int>(0x1FB3A60);
	std::map<unsigned int, _smart_ptr<IMaterial>> m_replacementMaterials;
	std::map<unsigned int, _smart_ptr<ICharacterInstance>> m_cachedCharacterInstaces;
	std::vector<CBodyDestructibilityProfile::SDestructibleBodyPart> m_attachments;
	std::vector<CBodyDestructibilityProfile::SDestructibleBodyPart> m_bones;
	std::vector<CBodyDestructibilityProfile::SDestructionEvent> m_destructionEvents;
	std::vector<CBodyDestructibilityProfile::SHealthRatioEvent> m_healthRatioEvents;
	CBodyDestructibilityProfile::SExplosionDeathEvent m_gibDeath;
	CBodyDestructibilityProfile::SExplosionDeathEvent m_nonGibDeath;
	CBodyDestructibilityProfile::SMikeDeath m_mikeDeath;
	unsigned m_id;
	uint64_t m_destructibleAttachmentCount;
	bool m_initialized;
	bool m_arelevelResourcesCached;

	void Reload(SBodyDestructibilityDef& bodyDestructionDef) { FReload(this, bodyDestructionDef); }
	void LoadXmlInfo(SBodyDestructibilityDef& bodyDestructionDef) { FLoadXmlInfo(this, bodyDestructionDef); }
	void PrepareInstance(CBodyDestrutibilityInstance& instance, float instanceBaseHealth, const SBodyCharacterInfo& bodyInfo) { FPrepareInstance(this, instance, instanceBaseHealth, bodyInfo); }
	void ResetInstance(IEntity& characterEntity, CBodyDestrutibilityInstance& instance) { FResetInstance(this, characterEntity, instance); }
	void CacheLevelResources() { FCacheLevelResources(this); }
	void FlushLevelResourceCache() { FFlushLevelResourceCache(this); }
	void ProcessDestructiblesHit(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesHit(this, characterEntity, instance, hitInfo, previousHealth, newHealth); }
	void ProcessDestructiblesOnExplosion(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth) { FProcessDestructiblesOnExplosion(this, characterEntity, instance, hitInfo, previousHealth, newHealth); }
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	void CacheMaterial(const char* materialName) { FCacheMaterial(this, materialName); }
	void PreparePartsAndEventsBeforeLoad(const XmlNodeRef& rootNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FPreparePartsAndEventsBeforeLoad(this, rootNode, parsingHelper); }
	void LoadDestructibleParts(const XmlNodeRef& destructiblesNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadDestructibleParts(this, destructiblesNode, parsingHelper); }
	void LoadPart(const XmlNodeRef& partNode, CBodyDestructibilityProfile::SDestructibleBodyPart& partData, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadPart(this, partNode, partData, parsingHelper); }
	void LoadEvents(const XmlNodeRef& eventsNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadEvents(this, eventsNode, parsingHelper); }
	void LoadEvent(const XmlNodeRef& eventNode, CBodyDestructibilityProfile::SDestructionEvent& eventData, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadEvent(this, eventNode, eventData, parsingHelper); }
	void LoadHealthRatioEvents(const XmlNodeRef& hitRatiosNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadHealthRatioEvents(this, hitRatiosNode, parsingHelper); }
	void LoadExplosionDeaths(const XmlNodeRef& explosionDeathsNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadExplosionDeaths(this, explosionDeathsNode, parsingHelper); }
	void LoadMikeDeath(const XmlNodeRef& mikeDeathNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper) { FLoadMikeDeath(this, mikeDeathNode, parsingHelper); }
	void ProcessDestructionEvent(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const int destructionEventId, IAttachmentManager* pAttachmentManager, const char* targetEffectBone, const Vec3& noAttachEffectPos) { FProcessDestructionEvent(this, characterEntity, instance, hitInfo, destructionEventId, pAttachmentManager, targetEffectBone, noAttachEffectPos); }
	void ProcessDeathByExplosion(IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo) { FProcessDeathByExplosion(this, characterEntity, instance, hitInfo); }
	void ProcessDeathByHit(IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo) { FProcessDeathByHit(this, characterEntity, characterInstance, instance, hitInfo); }
	void ProcessMikeDeath(IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo) { FProcessMikeDeath(this, characterEntity, characterInstance, instance, hitInfo); }
	void ProcessHealthRatioEvents(IEntity& characterEntity, ICharacterInstance& characterInstance, IAttachmentManager* pAttachmentManager, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float newHealth) { FProcessHealthRatioEvents(this, characterEntity, characterInstance, pAttachmentManager, instance, hitInfo, newHealth); }
	void ReplaceMaterial(IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const char* material) { FReplaceMaterial(this, characterEntity, characterInstance, instance, material); }
	bool CheckAgainstScriptCondition(IEntity& characterEntity, int destructionEventId) { return FCheckAgainstScriptCondition(this, characterEntity, destructionEventId); }

#if 0
	CBodyDestructibilityProfile(unsigned _arg0_);
	unsigned GetId() const;
	bool IsInitialized() const;
	bool AreLevelResourcesCached() const;
	void ProcessDestructionEventByName(const char* _arg0_, const char* _arg1_, IEntity& _arg2_, CBodyDestrutibilityInstance& _arg3_, const HitInfo& _arg4_);
	void DebugInstance(IEntity& _arg0_, CBodyDestrutibilityInstance& _arg1_);
	void LogDamage(IEntity& _arg0_, const char* _arg1_, const char* _arg2_, float _arg3_, float _arg4_, bool _arg5_);
	void LogDestructionEvent(IEntity& _arg0_, const char* _arg1_);
	void LogHealthRatioEvent(IEntity& _arg0_, int _arg1_);
	void LogMessage(IEntity& _arg0_, const char* _arg1_);
	void CacheCharacter(const char* _arg0_);
	bool GetDestructibleAttachment(unsigned _arg0_, CBodyDestructibilityProfile::SBodyPartQueryResult& _arg1_) const;
	bool GetDestructibleBone(unsigned _arg0_, CBodyDestructibilityProfile::SBodyPartQueryResult& _arg1_) const;
	void ProcessDeathByPunishHit(IEntity& _arg0_, CBodyDestrutibilityInstance& _arg1_, const HitInfo& _arg2_);
	void HideAttachment(IAttachmentManager* _arg0_, const char* _arg1_, unsigned _arg2_);
	void ResetMaterials(IEntity& _arg0_, ICharacterInstance& _arg1_, CBodyDestrutibilityInstance& _arg2_);
	IMaterial* GetMaterial(const char* _arg0_) const;
#endif

	static inline auto FReload = PreyFunction<void(CBodyDestructibilityProfile* const _this, SBodyDestructibilityDef& bodyDestructionDef)>(0x17B8240);
	static inline auto FLoadXmlInfo = PreyFunction<void(CBodyDestructibilityProfile* const _this, SBodyDestructibilityDef& bodyDestructionDef)>(0x17B5040);
	static inline auto FPrepareInstance = PreyFunction<void(CBodyDestructibilityProfile* const _this, CBodyDestrutibilityInstance& instance, float instanceBaseHealth, const SBodyCharacterInfo& bodyInfo)>(0x17B5250);
	static inline auto FResetInstance = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance)>(0x17B8620);
	static inline auto FCacheLevelResources = PreyFunction<void(CBodyDestructibilityProfile* const _this)>(0x17B2FA0);
	static inline auto FFlushLevelResourceCache = PreyFunction<void(CBodyDestructibilityProfile* const _this)>(0x17B3430);
	static inline auto FProcessDestructiblesHit = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17B6A50);
	static inline auto FProcessDestructiblesOnExplosion = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float previousHealth, const float newHealth)>(0x17B6FF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CBodyDestructibilityProfile* const _this, ICrySizer* pSizer)>(0x17B3580);
	static inline auto FCacheMaterial = PreyFunction<void(CBodyDestructibilityProfile* const _this, const char* materialName)>(0x17B3220);
	static inline auto FPreparePartsAndEventsBeforeLoad = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& rootNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B5400);
	static inline auto FLoadDestructibleParts = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& destructiblesNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B3750);
	static inline auto FLoadPart = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& partNode, CBodyDestructibilityProfile::SDestructibleBodyPart& partData, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B4D80);
	static inline auto FLoadEvents = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& eventsNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B42F0);
	static inline auto FLoadEvent = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& eventNode, CBodyDestructibilityProfile::SDestructionEvent& eventData, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B39A0);
	static inline auto FLoadHealthRatioEvents = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& hitRatiosNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B46E0);
	static inline auto FLoadExplosionDeaths = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& explosionDeathsNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B4470);
	static inline auto FLoadMikeDeath = PreyFunction<void(CBodyDestructibilityProfile* const _this, const XmlNodeRef& mikeDeathNode, CBodyDestructibilityProfile::SParsingHelper& parsingHelper)>(0x17B4B40);
	static inline auto FProcessDestructionEvent = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const int destructionEventId, IAttachmentManager* pAttachmentManager, const char* targetEffectBone, const Vec3& noAttachEffectPos)>(0x17B7540);
	static inline auto FProcessDeathByExplosion = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo)>(0x17B6300);
	static inline auto FProcessDeathByHit = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo)>(0x17B6600);
	static inline auto FProcessMikeDeath = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo)>(0x17B7E10);
	static inline auto FProcessHealthRatioEvents = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance, IAttachmentManager* pAttachmentManager, CBodyDestrutibilityInstance& instance, const HitInfo& hitInfo, const float newHealth)>(0x17B7B90);
	static inline auto FReplaceMaterial = PreyFunction<void(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance, CBodyDestrutibilityInstance& instance, const char* material)>(0x17B8540);
	static inline auto FCheckAgainstScriptCondition = PreyFunction<bool(CBodyDestructibilityProfile* const _this, IEntity& characterEntity, int destructionEventId)>(0x17B33C0);
};
#endif // MOONCRASH
