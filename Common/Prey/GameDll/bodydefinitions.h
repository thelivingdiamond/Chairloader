// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ICharacterInstance;
struct IEntity;
struct IMaterial;

// CBodyDestrutibilityInstance
// Header:  Prey/GameDll/bodydefinitions.h
class CBodyDestrutibilityInstance
{ // Size=144 (0x90)
public:
	// CBodyDestrutibilityInstance::SBodyDestructiblePartStatus
	// Header:  Prey/GameDll/bodydefinitions.h
	struct SBodyDestructiblePartStatus
	{ // Size=16 (0x10)
		float m_baseHealth;
		float m_minHealthToDestroyOnDeath;
		float m_currentHealth;
		bool m_visibleAtStart;

	#if 0
		SBodyDestructiblePartStatus();
		SBodyDestructiblePartStatus(float _arg0_, float _arg1_, bool _arg2_);
		void Reset();
		bool IsDestroyed() const;
		bool CanDestroyOnDeath() const;
		void SetHealth(float _arg0_);
		float GetInitialHealth() const;
		float GetHealth() const;
		float GetOnDeathHealthThreshold() const;
		bool WasInitialyVisible() const;
	#endif
	};

	using TDestructiblePartsStatus = std::vector<CBodyDestrutibilityInstance::SBodyDestructiblePartStatus>;
	using TAvailableDestructionEvents = std::vector<bool>;
	using TAttachmentMaterialPair = std::pair<unsigned int, IMaterial*>;
	using TOriginalMaterials = std::vector<std::pair<unsigned int, IMaterial*>>;

	std::vector<CBodyDestrutibilityInstance::SBodyDestructiblePartStatus> m_attachmentStatus;
	std::vector<CBodyDestrutibilityInstance::SBodyDestructiblePartStatus> m_boneStatus;
	std::vector<bool> m_availableDestructionEvents;
	std::vector<std::pair<unsigned int, IMaterial*>> m_originalMaterials;
	unsigned m_id;
	unsigned m_mikeAttachmentEntityId;
	unsigned m_lastEventForHitReactionsCrc;
	int m_currentHealthRatioEventIdx;
	float m_instanceInitialHealth;
	float m_mikeExplodeAlphaTestFadeOutTimer;
	float m_mikeExplodeAlphaTestFadeOutScale;
	float m_mikeExplodeAlphaTestMax;
	bool m_eventsModified;

	~CBodyDestrutibilityInstance();
	void ReserveSlots(const int totalAttachmentsCount, const int destructibleAttachmentsCount, const int destructibleBonesCount, const int destructionEventsCount) { FReserveSlots(this, totalAttachmentsCount, destructibleAttachmentsCount, destructibleBonesCount, destructionEventsCount); }
	void Reset() { FReset(this); }
	void DeleteMikeAttachmentEntity() { FDeleteMikeAttachmentEntity(this); }
	void InitWithProfileId(const unsigned profileId) { FInitWithProfileId(this, profileId); }
	bool CanTriggerEvent(int idx) const { return FCanTriggerEvent(this, idx); }
	void SetDestructibleLastEventForHitReactions(const char* eventName) { FSetDestructibleLastEventForHitReactions(this, eventName); }
	void InitializeMikeDeath(const unsigned entityId, float alphaTestFadeOutTime, float alphaTestFadeOutDelay, float alphaTestMax) { FInitializeMikeDeath(this, entityId, alphaTestFadeOutTime, alphaTestFadeOutDelay, alphaTestMax); }
	void ReplaceMaterial(IEntity& characterEntity, ICharacterInstance& characterInstance, IMaterial& replacementMaterial) { FReplaceMaterial(this, characterEntity, characterInstance, replacementMaterial); }
	void ResetMaterials(IEntity& characterEntity, ICharacterInstance& characterInstance) { FResetMaterials(this, characterEntity, characterInstance); }
	void Update(float frameTime) { FUpdate(this, frameTime); }

#if 0
	CBodyDestrutibilityInstance();
	unsigned GetProfileId() const;
	void AddAttachment(float _arg0_, float _arg1_, bool _arg2_);
	void AddBone(float _arg0_, float _arg1_);
	CBodyDestrutibilityInstance::SBodyDestructiblePartStatus* GetAttachmentStatus(int _arg0_);
	CBodyDestrutibilityInstance::SBodyDestructiblePartStatus* GetBoneStatus(int _arg0_);
	void DisableEvent(int _arg0_);
	unsigned GetLastDestructionEventForHitReactions() const;
	void SetCurrentHealthRatioIndex(const int _arg0_);
	int GetCurrentHealthRatioIndex() const;
	bool AreInstanceDestructiblesModified() const;
	void SetInstanceHealth(const float _arg0_);
	float GetInstanceInitialHealth() const;
	unsigned GetMikeAttachmentEntityId() const;
	void CleanUpOriginalMaterials();
#endif

	static inline auto FBitNotCBodyDestrutibilityInstance = PreyFunction<void(CBodyDestrutibilityInstance* const _this)>(0x17AF7E0);
	static inline auto FReserveSlots = PreyFunction<void(CBodyDestrutibilityInstance* const _this, const int totalAttachmentsCount, const int destructibleAttachmentsCount, const int destructibleBonesCount, const int destructionEventsCount)>(0x17AFB80);
	static inline auto FReset = PreyFunction<void(CBodyDestrutibilityInstance* const _this)>(0x17AFC70);
	static inline auto FDeleteMikeAttachmentEntity = PreyFunction<void(CBodyDestrutibilityInstance* const _this)>(0x17AF8D0);
	static inline auto FInitWithProfileId = PreyFunction<void(CBodyDestrutibilityInstance* const _this, const unsigned profileId)>(0x17AF900);
	static inline auto FCanTriggerEvent = PreyFunction<bool(const CBodyDestrutibilityInstance* const _this, int idx)>(0x17B3390);
	static inline auto FSetDestructibleLastEventForHitReactions = PreyFunction<void(CBodyDestrutibilityInstance* const _this, const char* eventName)>(0x17B87F0);
	static inline auto FInitializeMikeDeath = PreyFunction<void(CBodyDestrutibilityInstance* const _this, const unsigned entityId, float alphaTestFadeOutTime, float alphaTestFadeOutDelay, float alphaTestMax)>(0x17AF9C0);
	static inline auto FReplaceMaterial = PreyFunction<void(CBodyDestrutibilityInstance* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance, IMaterial& replacementMaterial)>(0x17AFA00);
	static inline auto FResetMaterials = PreyFunction<void(CBodyDestrutibilityInstance* const _this, IEntity& characterEntity, ICharacterInstance& characterInstance)>(0x17AFD90);
	static inline auto FUpdate = PreyFunction<void(CBodyDestrutibilityInstance* const _this, float frameTime)>(0x17AFE50);
};
#endif // MOONCRASH
