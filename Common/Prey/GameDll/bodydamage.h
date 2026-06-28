// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>

struct HitInfo;
struct IAttachmentManager;
class ICrySizer;
struct IDefaultSkeleton;
struct IEntity;
struct IPhysicalEntity;
struct ISkeletonPose;
struct ISurfaceType;
struct SBodyCharacterInfo;
struct SBodyDamageDef;
struct SBodyDamageImpulseFilter;
struct pe_params_part;

// CBodyDamageProfile
// Header:  Prey/GameDll/bodydamage.h
class CBodyDamageProfile : public _reference_target<int>
{ // Size=160 (0xA0)
public:
	enum EBulletHitClass
	{
		eBHC_Normal = 0,
		eBHC_Aimed = 1,
		eBHC_Max = 2,
	};

	// CBodyDamageProfile::JointId
	// Header:  Prey/GameDll/bodydamage.h
	struct JointId : public std::unary_function<bool,CBodyDamageProfile::JointId const &>
	{ // Size=4 (0x4)
		unsigned m_id;

	#if 0
		JointId();
		JointId(const char* _arg0_);
		bool operator<(const CBodyDamageProfile::JointId& _arg0_) const;
		bool operator()(const CBodyDamageProfile::JointId& _arg0_) const;
		bool operator==(const CBodyDamageProfile::JointId& _arg0_) const;
		static CBodyDamageProfile::JointId GetJointIdFromPartId(IEntity& _arg0_, const int _arg1_);
		static CBodyDamageProfile::JointId GetJointIdFromPartId(IDefaultSkeleton& _arg0_, ISkeletonPose& _arg1_, const int _arg2_);
	#endif
	};

	// CBodyDamageProfile::MatMappingId
	// Header:  Prey/GameDll/bodydamage.h
	struct MatMappingId : public std::unary_function<bool,CBodyDamageProfile::MatMappingId const &>
	{ // Size=16 (0x10)
		string m_jointName;
		CBodyDamageProfile::JointId m_jointId;

	#if 0
		MatMappingId();
		MatMappingId(const char* _arg0_);
		bool operator<(const CBodyDamageProfile::MatMappingId& _arg0_) const;
		bool operator()(const CBodyDamageProfile::MatMappingId& _arg0_) const;
		const char* GetName() const;
		static CBodyDamageProfile::MatMappingId GetMatMappingIdFromPartId(IDefaultSkeleton& _arg0_, ISkeletonPose& _arg1_, const int _arg2_);
	#endif
	};

	// CBodyDamageProfile::SMaterialMappingEntry
	// Header:  Prey/GameDll/bodydamage.h
	struct SMaterialMappingEntry
	{ // Size=100 (0x64)
		static constexpr const int MATERIALS_ARRAY_MAX_SIZE = 24;
		int materialsCount;
		int materials[24];

	#if 0
		SMaterialMappingEntry();
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDamageProfile::SProjectileMultiplier
	// Header:  Prey/GameDll/bodydamage.h
	struct SProjectileMultiplier
	{ // Size=12 (0xC)
		uint16_t projectileClassId;
		float multiplier[2];

	#if 0
		SProjectileMultiplier(uint16_t _arg0_, float _arg1_, float _arg2_);
	#endif
	};

	// CBodyDamageProfile::SBodyPartDamageMultiplier
	// Header:  Prey/GameDll/bodydamage.h
	struct SBodyPartDamageMultiplier
	{ // Size=40 (0x28)
		float defaultMultiplier[2];
		float meleeMultiplier;
		float collisionMultiplier;
		std::vector<CBodyDamageProfile::SProjectileMultiplier> bulletMultipliers;

	#if 0
		SBodyPartDamageMultiplier(float _arg0_);
	#endif
	};

	// CBodyDamageProfile::CEffectiveMaterials
	// Header:  Prey/GameDll/bodydamage.h
	class CEffectiveMaterials
	{ // Size=80 (0x50)
	public:
		std::map<CBodyDamageProfile::JointId, std::map<int, int>> m_effectiveMaterialsByBone;
		std::map<int, int> m_effectiveMaterials;
		CBodyDamageProfile& m_bodyDamageProfile;
		ISkeletonPose& m_skeletonPose;
		IDefaultSkeleton& m_rICharacterModelSkeleton;
		IPhysicalEntity& m_physicalEntity;
		std::map<CBodyDamageProfile::JointId, std::vector<int>> m_jointIdsApplied;

		void UpdateMapping(const char* jointName, const int physicsJointId, const std::map<int, int>& effectiveMaterials) { FUpdateMappingOv1(this, jointName, physicsJointId, effectiveMaterials); }
		void UpdateMapping(const char* jointName, const int physicsJointId, ISurfaceType& sourceMaterial, ISurfaceType& targetMaterial) { FUpdateMappingOv0(this, jointName, physicsJointId, sourceMaterial, targetMaterial); }
		void FinalizeMapping() { FFinalizeMapping(this); }
		void LoadEffectiveMaterials(const XmlNodeRef& parentNode, const char* boneName, int boneId) { FLoadEffectiveMaterials(this, parentNode, boneName, boneId); }
		void LoadEffectiveMaterial(const XmlNodeRef& effectiveMaterial, const char* boneName, int boneId) { FLoadEffectiveMaterial(this, effectiveMaterial, boneName, boneId); }
		void LogEffectiveMaterialApplied(int sourceMaterialId, const char* sourceMaterial, const char* targetMaterial, int jointId, int materialIndex) const { FLogEffectiveMaterialApplied(this, sourceMaterialId, sourceMaterial, targetMaterial, jointId, materialIndex); }
		void UpdatePhysicsPartById(const CBodyDamageProfile::MatMappingId& matMappingId, const pe_params_part& part, CBodyDamageProfile::SMaterialMappingEntry& mappingEntry, const std::vector<int>& appliedMaterialIds) { FUpdatePhysicsPartById(this, matMappingId, part, mappingEntry, appliedMaterialIds); }

	#if 0
		CEffectiveMaterials(CBodyDamageProfile& _arg0_, IDefaultSkeleton& _arg1_, ISkeletonPose& _arg2_, IPhysicalEntity& _arg3_);
		void Load(const XmlNodeRef& _arg0_);
		void UpdateMapping(const char* _arg0_, const int _arg1_);
	#endif

		static inline auto FUpdateMappingOv1 = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this, const char* jointName, const int physicsJointId, const std::map<int, int>& effectiveMaterials)>(0x17AEBB0);
		static inline auto FUpdateMappingOv0 = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this, const char* jointName, const int physicsJointId, ISurfaceType& sourceMaterial, ISurfaceType& targetMaterial)>(0x17AE8B0);
		static inline auto FFinalizeMapping = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this)>(0x17AC000);
		static inline auto FLoadEffectiveMaterials = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this, const XmlNodeRef& parentNode, const char* boneName, int boneId)>(0x17AD7F0);
		static inline auto FLoadEffectiveMaterial = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this, const XmlNodeRef& effectiveMaterial, const char* boneName, int boneId)>(0x17AD590);
		static inline auto FLogEffectiveMaterialApplied = PreyFunction<void(const CBodyDamageProfile::CEffectiveMaterials* const _this, int sourceMaterialId, const char* sourceMaterial, const char* targetMaterial, int jointId, int materialIndex)>(0x17AE520);
		static inline auto FUpdatePhysicsPartById = PreyFunction<void(CBodyDamageProfile::CEffectiveMaterials* const _this, const CBodyDamageProfile::MatMappingId& matMappingId, const pe_params_part& part, CBodyDamageProfile::SMaterialMappingEntry& mappingEntry, const std::vector<int>& appliedMaterialIds)>(0x17AECD0);
	};

	// CBodyDamageProfile::CPart
	// Header:  Prey/GameDll/bodydamage.h
	class CPart
	{ // Size=32 (0x20)
	public:
		std::map<CBodyDamageProfile::JointId, std::vector<int>> m_jointIds;
		string m_name;
		unsigned m_flags;
		int m_id;

		void LoadElements(const XmlNodeRef& partNode, IDefaultSkeleton& skeletonPose, IAttachmentManager& attachmentManager, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials, const CBodyDamageProfile& ownerDamageProfile) { FLoadElements(this, partNode, skeletonPose, attachmentManager, effectiveMaterials, ownerDamageProfile); }
		void AddBone(const XmlNodeRef& boneNode, const char* boneName, IDefaultSkeleton& rIDefaultSkeleton, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials) { FAddBone(this, boneNode, boneName, rIDefaultSkeleton, effectiveMaterials); }

	#if 0
		CPart(const char* _arg0_, unsigned _arg1_, int _arg2_);
		const string& GetName() const;
		int GetId() const;
		const std::map<CBodyDamageProfile::JointId, std::vector<int>>& GetJointIds() const;
		const std::vector<int>* GetMaterialsByJointId(const CBodyDamageProfile::JointId& _arg0_) const;
		unsigned GetFlags() const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
		void AddMaterial(const XmlNodeRef& _arg0_, const char* _arg1_, std::vector<int>& _arg2_);
		void AddAttachment(const char* _arg0_, IAttachmentManager& _arg1_);
		static int GetNextId();
	#endif

		static inline auto FLoadElements = PreyFunction<void(CBodyDamageProfile::CPart* const _this, const XmlNodeRef& partNode, IDefaultSkeleton& skeletonPose, IAttachmentManager& attachmentManager, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials, const CBodyDamageProfile& ownerDamageProfile)>(0x17AD930);
		static inline auto FAddBone = PreyFunction<void(CBodyDamageProfile::CPart* const _this, const XmlNodeRef& boneNode, const char* boneName, IDefaultSkeleton& rIDefaultSkeleton, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials)>(0x17ABD20);
	};

	// CBodyDamageProfile::CPartByNameFunctor
	// Header:  Prey/GameDll/bodydamage.h
	class CPartByNameFunctor : private std::unary_function<bool,CBodyDamageProfile::CPart const &>
	{ // Size=8 (0x8)
	public:
		const char* m_name;

	#if 0
		CPartByNameFunctor(const char* _arg0_);
		bool operator()(const CBodyDamageProfile::CPart& _arg0_) const;
	#endif
	};

	// CBodyDamageProfile::CPartInfo
	// Header:  Prey/GameDll/bodydamage.h
	class CPartInfo
	{ // Size=16 (0x10)
	public:
		const std::vector<int>& m_materialIds;
		const CBodyDamageProfile::CPart& m_part;

	#if 0
		CPartInfo(const CBodyDamageProfile::CPart& _arg0_, const std::vector<int>& _arg1_);
		const std::vector<int>& GetMaterialIds() const;
		const CBodyDamageProfile::CPart& GetPart() const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CBodyDamageProfile::SDefaultMultipliers
	// Header:  Prey/GameDll/bodydamage.h
	struct SDefaultMultipliers
	{ // Size=8 (0x8)
		float m_global;
		float m_collision;

	#if 0
		SDefaultMultipliers();
	#endif
	};

	using MaterialId = int;
	using PartId = int;
	using TMaterialIds = std::vector<int>;
	using TJointIds = std::map<CBodyDamageProfile::JointId, std::vector<int>>;
	using TEffectiveMaterials = std::map<int, int>;
	using TEffectiveMaterialsByBone = std::map<CBodyDamageProfile::JointId, std::map<int, int>>;
	using TProjectileMultipliers = std::vector<CBodyDamageProfile::SProjectileMultiplier>;
	using TParts = std::vector<CBodyDamageProfile::CPart>;
	using TPartsByJointId = std::multimap<CBodyDamageProfile::JointId,CBodyDamageProfile::CPartInfo,std::less<CBodyDamageProfile::JointId>,std::allocator<std::pair<CBodyDamageProfile::JointId const ,CBodyDamageProfile::CPartInfo> > >;
	using TPartIdsToMultipliers = std::map<int, CBodyDamageProfile::SBodyPartDamageMultiplier>;
	using TPartsByJointIdIterator = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CBodyDamageProfile::JointId const ,CBodyDamageProfile::CPartInfo> > > >;
	using TPartsByJointIdRange = std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const CBodyDamageProfile::JointId, CBodyDamageProfile::CPartInfo>>>>, std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const CBodyDamageProfile::JointId, CBodyDamageProfile::CPartInfo>>>>>;
	using TMaterialMappingEntries = std::map<CBodyDamageProfile::MatMappingId, CBodyDamageProfile::SMaterialMappingEntry>;
	using TImpulseFilters = std::multimap<int,SBodyDamageImpulseFilter,std::less<int>,std::allocator<std::pair<int const ,SBodyDamageImpulseFilter> > >;

	static constexpr const int ATTACHMENT_BASE_ID = 1000;
	bool m_bInitialized;
	unsigned m_id;
	XmlNodeRef m_partsRootNode;
	XmlNodeRef m_damageRootNode;
	std::vector<CBodyDamageProfile::CPart> m_parts;
	std::multimap<CBodyDamageProfile::JointId,CBodyDamageProfile::CPartInfo,std::less<CBodyDamageProfile::JointId>,std::allocator<std::pair<CBodyDamageProfile::JointId const ,CBodyDamageProfile::CPartInfo> > > m_partsByJointId;
	std::map<int, CBodyDamageProfile::SBodyPartDamageMultiplier> m_partIdsToMultipliers;
	std::map<CBodyDamageProfile::MatMappingId, CBodyDamageProfile::SMaterialMappingEntry> m_effectiveMaterialsMapping;
	std::multimap<int,SBodyDamageImpulseFilter,std::less<int>,std::allocator<std::pair<int const ,SBodyDamageImpulseFilter> > > m_impulseFilters;
	std::vector<CBodyDamageProfile::SProjectileMultiplier> m_explosionMultipliers;
	CBodyDamageProfile::SDefaultMultipliers m_defaultMultipliers;

	CBodyDamageProfile(unsigned id);
	void LoadXmlInfo(const SBodyDamageDef& bodyDamageDef, bool bReload) { FLoadXmlInfo(this, bodyDamageDef, bReload); }
	bool Init(const SBodyCharacterInfo& characterInfo, bool loadEffectiveMaterials, bool bReload) { return FInit(this, characterInfo, loadEffectiveMaterials, bReload); }
	bool Reload(const SBodyCharacterInfo& characterInfo, const SBodyDamageDef& bodyDamageDef, unsigned id) { return FReload(this, characterInfo, bodyDamageDef, id); }
	bool PhysicalizeEntity(IPhysicalEntity* pPhysicalEntity, IDefaultSkeleton* pIDefaultSkeleton) const { return FPhysicalizeEntity(this, pPhysicalEntity, pIDefaultSkeleton); }
	float GetDamageMultiplier(IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetDamageMultiplier(this, characterEntity, hitInfo); }
	float GetExplosionDamageMultiplier(IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetExplosionDamageMultiplier(this, characterEntity, hitInfo); }
	unsigned GetPartFlags(IEntity& characterEntity, const HitInfo& hitInfo) const { return FGetPartFlags(this, characterEntity, hitInfo); }
	CBodyDamageProfile::SMaterialMappingEntry& InsertMappingEntry(const CBodyDamageProfile::MatMappingId& matMappingId, const pe_params_part& part) { return FInsertMappingEntry(this, matMappingId, part); }
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	void GetHitImpulseFilter(IEntity& characterEntity, const HitInfo& hitInfo, SBodyDamageImpulseFilter& impulseFilter) const { FGetHitImpulseFilter(this, characterEntity, hitInfo, impulseFilter); }
	void LoadParts(const XmlNodeRef& rootNode, IDefaultSkeleton& skeletonPose, IAttachmentManager& attachmentManager, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials) { FLoadParts(this, rootNode, skeletonPose, attachmentManager, effectiveMaterials); }
	void LoadMultiplier(const XmlNodeRef& multiplierNode) { FLoadMultiplier(this, multiplierNode); }
	void LoadImpulse(const XmlNodeRef& filterNode, IDefaultSkeleton& skeletonPose, const int partID) { FLoadImpulse(this, filterNode, skeletonPose, partID); }
	const CBodyDamageProfile::CPart* FindPart(IEntity& characterEntity, const int partId, int material) const { return FFindPart(this, characterEntity, partId, material); }

#if 0
	unsigned GetId() const;
	bool IsInitialized() const;
	void RemoveMappingEntry(const CBodyDamageProfile::MatMappingId& _arg0_);
	const CBodyDamageProfile::CPart* FindPartWithBoneName(const char* _arg0_) const;
	XmlNodeRef LoadXml(const char* _arg0_) const;
	void LoadDamage(const char* _arg0_);
	unsigned LoadPartFlags(const XmlNodeRef& _arg0_) const;
	void LoadMultipliers(const XmlNodeRef& _arg0_);
	void LoadExplosionMultipliers(const XmlNodeRef& _arg0_);
	void LoadExplosionMultiplier(const XmlNodeRef& _arg0_);
	void LoadImpulseFilters(const XmlNodeRef& _arg0_, IDefaultSkeleton& _arg1_);
	void LoadImpulseFilter(const XmlNodeRef& _arg0_, IDefaultSkeleton& _arg1_);
	void IndexParts();
	void LogDamageMultiplier(IEntity& _arg0_, const HitInfo& _arg1_, const char* _arg2_, const float _arg3_) const;
	void LogExplosionDamageMultiplier(IEntity& _arg0_, const float _arg1_) const;
	void LogFoundMaterial(int _arg0_, const CBodyDamageProfile::CPartInfo& _arg1_, const int _arg2_) const;
	bool FindDamageMultiplierForBullet(const std::vector<CBodyDamageProfile::SProjectileMultiplier>& _arg0_, uint16_t _arg1_, CBodyDamageProfile::EBulletHitClass _arg2_, float& _arg3_) const;
	float GetBestMultiplierForHitType(const CBodyDamageProfile::SBodyPartDamageMultiplier& _arg0_, int _arg1_, CBodyDamageProfile::EBulletHitClass _arg2_) const;
	float GetDefaultDamageMultiplier(const HitInfo& _arg0_) const;
#endif

	static inline auto FCBodyDamageProfileOv2 = PreyFunction<void(CBodyDamageProfile* const _this, unsigned id)>(0x17ABA80);
	static inline auto FLoadXmlInfo = PreyFunction<void(CBodyDamageProfile* const _this, const SBodyDamageDef& bodyDamageDef, bool bReload)>(0x17AE370);
	static inline auto FInit = PreyFunction<bool(CBodyDamageProfile* const _this, const SBodyCharacterInfo& characterInfo, bool loadEffectiveMaterials, bool bReload)>(0x17ACED0);
	static inline auto FReload = PreyFunction<bool(CBodyDamageProfile* const _this, const SBodyCharacterInfo& characterInfo, const SBodyDamageDef& bodyDamageDef, unsigned id)>(0x17AE7E0);
	static inline auto FPhysicalizeEntity = PreyFunction<bool(const CBodyDamageProfile* const _this, IPhysicalEntity* pPhysicalEntity, IDefaultSkeleton* pIDefaultSkeleton)>(0x17AE5D0);
	static inline auto FGetDamageMultiplier = PreyFunction<float(const CBodyDamageProfile* const _this, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17AC8B0);
	static inline auto FGetExplosionDamageMultiplier = PreyFunction<float(const CBodyDamageProfile* const _this, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17ACB80);
	static inline auto FGetPartFlags = PreyFunction<unsigned(const CBodyDamageProfile* const _this, IEntity& characterEntity, const HitInfo& hitInfo)>(0x17ACEA0);
	static inline auto FInsertMappingEntry = PreyFunction<CBodyDamageProfile::SMaterialMappingEntry& (CBodyDamageProfile* const _this, const CBodyDamageProfile::MatMappingId& matMappingId, const pe_params_part& part)>(0x17AD420);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CBodyDamageProfile* const _this, ICrySizer* pSizer)>(0x17ACDE0);
	static inline auto FGetHitImpulseFilter = PreyFunction<void(const CBodyDamageProfile* const _this, IEntity& characterEntity, const HitInfo& hitInfo, SBodyDamageImpulseFilter& impulseFilter)>(0x17ACCA0);
	static inline auto FLoadParts = PreyFunction<void(CBodyDamageProfile* const _this, const XmlNodeRef& rootNode, IDefaultSkeleton& skeletonPose, IAttachmentManager& attachmentManager, CBodyDamageProfile::CEffectiveMaterials& effectiveMaterials)>(0x17AE000);
	static inline auto FLoadMultiplier = PreyFunction<void(CBodyDamageProfile* const _this, const XmlNodeRef& multiplierNode)>(0x17ADCE0);
	static inline auto FLoadImpulse = PreyFunction<void(CBodyDamageProfile* const _this, const XmlNodeRef& filterNode, IDefaultSkeleton& skeletonPose, const int partID)>(0x17ADB90);
	static inline auto FFindPart = PreyFunction<const CBodyDamageProfile::CPart* (const CBodyDamageProfile* const _this, IEntity& characterEntity, const int partId, int material)>(0x17AC5F0);
};
#endif // MOONCRASH
