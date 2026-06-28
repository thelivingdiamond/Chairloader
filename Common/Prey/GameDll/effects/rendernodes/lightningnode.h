// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntityRenderState.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryRenderer/VertexFormats.h>

class CRenderObject;
enum EERType;
class ICrySizer;
struct IMaterial;
struct IPhysicalEntity;
struct IRenderer;
struct SLightningParams;
struct SLightningStats;
struct SRendParams;
struct SRenderingPassInfo;

// CLightningRenderNode
// Header:  Prey/GameDll/effects/rendernodes/lightningnode.h
class CLightningRenderNode : public IRenderNode
{ // Size=304 (0x130)
public:
	// CLightningRenderNode::CTriStrip
	// Header:  Prey/GameDll/effects/rendernodes/lightningnode.h
	class CTriStrip
	{ // Size=56 (0x38)
	public:
		using TVertexArray = std::vector<SVF_P3F_C4B_T2F>;
		using TIndexArray = std::vector<unsigned short>;

		std::vector<SVF_P3F_C4B_T2F> m_vertices;
		std::vector<unsigned short> m_indices;
		int m_firstVertex;

		void PushVertex(SVF_P3F_C4B_T2F v) { FPushVertex(this, v); }

	#if 0
		void Reset();
		void Branch();
		void Draw(const SRendParams& _arg0_, const SRenderingPassInfo& _arg1_, IRenderer* _arg2_, CRenderObject* _arg3_, IMaterial* _arg4_, float _arg5_);
		void Clear();
		void AddStats(SLightningStats* _arg0_) const;
	#endif

		static inline auto FPushVertex = PreyFunction<void(CLightningRenderNode::CTriStrip* const _this, SVF_P3F_C4B_T2F v)>(0x17DE210);
	};

	// CLightningRenderNode::SPointData
	// Header:  Prey/GameDll/effects/rendernodes/lightningnode.h
	struct SPointData
	{ // Size=72 (0x48)
		std::vector<Vec3> m_points;
		std::vector<Vec3> m_velocity;
		std::vector<Vec3> m_fuzzyPoints;
	};

	// CLightningRenderNode::CSegment
	// Header:  Prey/GameDll/effects/rendernodes/lightningnode.h
	class CSegment
	{ // Size=60 (0x3C)
	public:
		int m_firstPoint;
		int m_numPoints;
		int m_firstFuzzyPoint;
		int m_numFuzzyPoints;
		Vec3 m_origin;
		Vec3 m_destany;
		float m_duration;
		float m_time;
		float m_intensity;
		int m_parentSegmentIdx;
		int m_parentPointIdx;

		void Create(const SLightningParams& desc, CLightningRenderNode::SPointData* m_pointData, int _parentSegmentIdx, int _parentPointIdx, Vec3 _origin, Vec3 _destany, float _duration, float _intensity) { FCreate(this, desc, m_pointData, _parentSegmentIdx, _parentPointIdx, _origin, _destany, _duration, _intensity); }
		void Draw(const SLightningParams& desc, const CLightningRenderNode::SPointData& pointData, CLightningRenderNode::CTriStrip* strip, Vec3 cameraPosition, float deviationMult) { FDraw(this, desc, pointData, strip, cameraPosition, deviationMult); }
		Vec3 GetPoint(const SLightningParams& desc, const CLightningRenderNode::SPointData& pointData, int point, float deviationMult) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPoint(this, reinterpret_cast<Vec3*>(_return_buf_), desc, pointData, point, deviationMult); }

	#if 0
		void Update(const SLightningParams& _arg0_);
		bool IsDone(const SLightningParams& _arg0_);
		int GetNumPoints() const;
		void SetOrigin(Vec3 _arg0_);
		void SetDestany(Vec3 _arg0_);
		int GetParentSegmentIdx() const;
		int GetParentPointIdx() const;
		void DecrementParentIdx();
	#endif

		static inline auto FCreate = PreyFunction<void(CLightningRenderNode::CSegment* const _this, const SLightningParams& desc, CLightningRenderNode::SPointData* m_pointData, int _parentSegmentIdx, int _parentPointIdx, Vec3 _origin, Vec3 _destany, float _duration, float _intensity)>(0x17DD480);
		static inline auto FDraw = PreyFunction<void(CLightningRenderNode::CSegment* const _this, const SLightningParams& desc, const CLightningRenderNode::SPointData& pointData, CLightningRenderNode::CTriStrip* strip, Vec3 cameraPosition, float deviationMult)>(0x17DD990);
		static inline auto FGetPoint = PreyFunction<Vec3*(const CLightningRenderNode::CSegment* const _this, Vec3* _return_value_, const SLightningParams& desc, const CLightningRenderNode::SPointData& pointData, int point, float deviationMult)>(0x1834050);
	};

	using SLightningVertex = SVF_P3F_C4B_T2F;
	using TSegments = std::vector<CLightningRenderNode::CSegment>;

	CLightningRenderNode::CTriStrip m_triStrip;
	std::vector<CLightningRenderNode::CSegment> m_segments;
	Vec3 m_emmitterPosition;
	Vec3 m_receiverPosition;
	CLightningRenderNode::SPointData m_pointData;
	float m_deviationMult;
	const SLightningParams* m_pLightningDesc;
	_smart_ptr<IMaterial> m_pMaterial;
	AABB m_aabb;
	bool m_dirtyBBox;

	CLightningRenderNode();
	virtual ~CLightningRenderNode();
	virtual EERType GetRenderNodeType();
	virtual const char* GetEntityClassName() const;
	virtual const char* GetName() const;
	virtual Vec3 GetPos(bool bWorldOnly) const;
	virtual void Render(const SRendParams& rParam, const SRenderingPassInfo& passInfo);
	virtual IPhysicalEntity* GetPhysics() const;
	virtual void SetPhysics(IPhysicalEntity* __unnamed1);
	virtual void SetMaterial(IMaterial* pMat);
	virtual IMaterial* GetMaterial(Vec3* pHitPos) const;
	virtual IMaterial* GetMaterialOverride();
	virtual float GetMaxViewDist();
	virtual float GetMaxCastShadowViewDist();
	virtual void Precache();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual const AABB GetBBox() const;
	virtual void FillBBox(AABB& aabb);
	virtual void SetBBox(const AABB& WSBBox);
	virtual bool IsAllocatedOutsideOf3DEngineDLL();
	void Reset() { FReset(this); }
	float TriggerSpark() { return FTriggerSpark(this); }
	void SetLightningParams(const SLightningParams* pDescriptor) { FSetLightningParams(this, pDescriptor); }
	void SetEmiterPosition(Vec3 emiterPosition) { FSetEmiterPosition(this, emiterPosition); }
	void SetReceiverPosition(Vec3 receiverPosition) { FSetReceiverPosition(this, receiverPosition); }
	void AddStats(SLightningStats* pStats) const { FAddStats(this, pStats); }
	void Update() { FUpdate(this); }
	void CreateSegment(Vec3 originPosition, int parentIdx, int parentPointIdx, float duration, int level) { FCreateSegment(this, originPosition, parentIdx, parentPointIdx, duration, level); }

#if 0
	void SetSparkDeviationMult(float _arg0_);
	void Draw(CLightningRenderNode::CTriStrip* _arg0_, Vec3 _arg1_);
	void PopSegment();
#endif

	static inline auto FCLightningRenderNodeOv1 = PreyFunction<void(CLightningRenderNode* const _this)>(0x17DD0C0);
	static inline auto FGetRenderNodeType = PreyFunction<EERType(CLightningRenderNode* const _this)>(0x1B399B0);
	static inline auto FGetEntityClassName = PreyFunction<const char* (const CLightningRenderNode* const _this)>(0x17DE200);
	static inline auto FGetName = PreyFunction<const char* (const CLightningRenderNode* const _this)>(0x17DE200);
	static inline auto FGetPos = PreyFunction<Vec3*(const CLightningRenderNode* const _this, Vec3* _return_value_, bool bWorldOnly)>(0x9F8FF0);
	static inline auto FRender = PreyFunction<void(CLightningRenderNode* const _this, const SRendParams& rParam, const SRenderingPassInfo& passInfo)>(0x17DE420);
	static inline auto FGetPhysics = PreyFunction<IPhysicalEntity* (const CLightningRenderNode* const _this)>(0x1CBB0B0);
	static inline auto FSetPhysics = PreyFunction<void(CLightningRenderNode* const _this, IPhysicalEntity* __unnamed1)>(0x1333E90);
	static inline auto FSetMaterial = PreyFunction<void(CLightningRenderNode* const _this, IMaterial* pMat)>(0x17DE7C0);
	static inline auto FGetMaterial = PreyFunction<IMaterial* (const CLightningRenderNode* const _this, Vec3* pHitPos)>(0x1834030);
	static inline auto FGetMaterialOverride = PreyFunction<IMaterial* (CLightningRenderNode* const _this)>(0x1834030);
	static inline auto FGetMaxViewDist = PreyFunction<float(CLightningRenderNode* const _this)>(0x1834040);
	static inline auto FGetMaxCastShadowViewDist = PreyFunction<float(CLightningRenderNode* const _this)>(0x714650);
	static inline auto FPrecache = PreyFunction<void(CLightningRenderNode* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CLightningRenderNode* const _this, ICrySizer* pSizer)>(0x1333E90);
	static inline auto FGetBBox = PreyFunction<const AABB*(const CLightningRenderNode* const _this, const AABB* _return_value_)>(0x1833D50);
	static inline auto FFillBBox = PreyFunction<void(CLightningRenderNode* const _this, AABB& aabb)>(0x1833D20);
	static inline auto FSetBBox = PreyFunction<void(CLightningRenderNode* const _this, const AABB& WSBBox)>(0x17DE770);
	static inline auto FIsAllocatedOutsideOf3DEngineDLL = PreyFunction<bool(CLightningRenderNode* const _this)>(0x1A302A0);
	static inline auto FReset = PreyFunction<void(CLightningRenderNode* const _this)>(0x17DE720);
	static inline auto FTriggerSpark = PreyFunction<float(CLightningRenderNode* const _this)>(0x17DE830);
	static inline auto FSetLightningParams = PreyFunction<void(CLightningRenderNode* const _this, const SLightningParams* pDescriptor)>(0x17DE7B0);
	static inline auto FSetEmiterPosition = PreyFunction<void(CLightningRenderNode* const _this, Vec3 emiterPosition)>(0x17DE790);
	static inline auto FSetReceiverPosition = PreyFunction<void(CLightningRenderNode* const _this, Vec3 receiverPosition)>(0x17DE810);
	static inline auto FAddStats = PreyFunction<void(const CLightningRenderNode* const _this, SLightningStats* pStats)>(0x17DD2E0);
	static inline auto FUpdate = PreyFunction<void(CLightningRenderNode* const _this)>(0x17DE900);
	static inline auto FCreateSegment = PreyFunction<void(CLightningRenderNode* const _this, Vec3 originPosition, int parentIdx, int parentPointIdx, float duration, int level)>(0x17DD700);
};
#endif // MOONCRASH
