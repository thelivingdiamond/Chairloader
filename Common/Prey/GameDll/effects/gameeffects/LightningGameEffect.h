// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/effects/gameeffects/GameEffect.h>
#include <_unknown/SLightningStats.h>

class CLightningRenderNode;
struct IItemParamsNode;
struct IMaterial;
struct SGameEffectParams;
class XmlNodeRef;

// SLightningParams
// Header:  Prey/GameDll/effects/gameeffects/LightningGameEffect.h
struct SLightningParams
{ // Size=68 (0x44)
	unsigned m_nameCRC;
	float m_strikeTimeMin;
	float m_strikeTimeMax;
	float m_strikeFadeOut;
	int m_strikeNumSegments;
	int m_strikeNumPoints;
	float m_lightningDeviation;
	float m_lightningFuzzyness;
	float m_lightningVelocity;
	float m_branchProbability;
	int m_branchMaxLevel;
	int m_maxNumStrikes;
	float m_beamSize;
	float m_beamTexTiling;
	float m_beamTexShift;
	float m_beamTexFrames;
	float m_beamTexFPS;

	void Reset(XmlNodeRef node) { FReset(this, node); }

#if 0
	SLightningParams();
#endif

	static inline auto FReset = PreyFunction<void(SLightningParams* const _this, XmlNodeRef node)>(0x17DC110);
};

// CLightningGameEffect
// Header:  Prey/GameDll/effects/gameeffects/LightningGameEffect.h
class CLightningGameEffect : public CGameEffect
{ // Size=2216 (0x8A8)
public:
	// CLightningGameEffect::STarget
	// Header:  Prey/GameDll/effects/gameeffects/LightningGameEffect.h
	struct STarget
	{ // Size=36 (0x24)
		Vec3 m_position;
		Vec3 m_offset;
		unsigned m_entityId;
		int m_characterAttachmentSlot;
		unsigned m_characterAttachmentNameCRC;

		STarget(unsigned targetEntity);
		STarget(unsigned entityId, const Vec3& offset);

	#if 0
		STarget();
		STarget(const Vec3& _arg0_);
		STarget(unsigned _arg0_, int _arg1_, const char* _arg2_);
	#endif

		static inline auto FSTargetOv4 = PreyFunction<void(CLightningGameEffect::STarget* const _this, unsigned targetEntity)>(0x17DBB50);
		static inline auto FSTargetOv3 = PreyFunction<void(CLightningGameEffect::STarget* const _this, unsigned entityId, const Vec3& offset)>(0x17DBB70);
	};

	// CLightningGameEffect::SLightningSpark
	// Header:  Prey/GameDll/effects/gameeffects/LightningGameEffect.h
	struct SLightningSpark
	{ // Size=88 (0x58)
		CLightningRenderNode* m_renderNode;
		CLightningGameEffect::STarget m_emitter;
		CLightningGameEffect::STarget m_receiver;
		float m_timer;
	};

	using TIndex = int;

	static constexpr const int maxNumSparks = 24;
	std::vector<SLightningParams> m_lightningParams;
	CLightningGameEffect::SLightningSpark m_sparks[24];
	SLightningStats m_stats;
	Vec3 m_receiverLocalPosition;

	CLightningGameEffect();
	virtual ~CLightningGameEffect();
	virtual void Initialise(const SGameEffectParams* gameEffectParams);
	virtual const char* GetName() const;
	virtual void Update(float frameTime);
	void ClearSparks() { FClearSparks(this); }
	static void LoadStaticData(IItemParamsNode* __unnamed1) { FLoadStaticData(__unnamed1); }
	static void ReloadStaticData(IItemParamsNode* __unnamed1) { FReloadStaticData(__unnamed1); }
	static void ReleaseStaticData() { FReleaseStaticData(); }
	void LoadData() { FLoadData(this); }
	int TriggerSpark(const char* presetName, IMaterial* pMaterial, const CLightningGameEffect::STarget& emitter, const CLightningGameEffect::STarget& receiver) { return FTriggerSpark(this, presetName, pMaterial, emitter, receiver); }
	float GetSparkRemainingTime(const int spark) const { return FGetSparkRemainingTime(this, spark); }
	Vec3 ComputeTargetPosition(const CLightningGameEffect::STarget& target, const Vec3& m_receiverLocalPosition) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FComputeTargetPosition(this, reinterpret_cast<Vec3*>(_return_buf_), target, m_receiverLocalPosition); }

#if 0
	void SetReceiverLocalPosition(const Vec3& _arg0_);
	void RemoveSpark(const int _arg0_);
	void SetEmitter(const int _arg0_, const CLightningGameEffect::STarget& _arg1_);
	void SetReceiver(const int _arg0_, const CLightningGameEffect::STarget& _arg1_);
	void SetSparkDeviationMult(const int _arg0_, float _arg1_);
	void UnloadData();
	int FindEmptySlot() const;
	int FindPreset(const char* _arg0_) const;
#endif

	static inline auto FCLightningGameEffectOv1 = PreyFunction<void(CLightningGameEffect* const _this)>(0x17DBA70);
	static inline auto FInitialise = PreyFunction<void(CLightningGameEffect* const _this, const SGameEffectParams* gameEffectParams)>(0x17DBEE0);
	static inline auto FGetName = PreyFunction<const char* (const CLightningGameEffect* const _this)>(0x17DE200);
	static inline auto FUpdate = PreyFunction<void(CLightningGameEffect* const _this, float frameTime)>(0x17DC700);
	static inline auto FClearSparks = PreyFunction<void(CLightningGameEffect* const _this)>(0x17DBBF0);
	static inline auto FLoadStaticData = PreyFunction<void(IItemParamsNode* __unnamed1)>(0x17DC0F0);
	static inline auto FReloadStaticData = PreyFunction<void(IItemParamsNode* __unnamed1)>(0x17DC0F0);
	static inline auto FReleaseStaticData = PreyFunction<void()>(0x17DC0A0);
	static inline auto FLoadData = PreyFunction<void(CLightningGameEffect* const _this)>(0x17DBF00);
	static inline auto FTriggerSpark = PreyFunction<int(CLightningGameEffect* const _this, const char* presetName, IMaterial* pMaterial, const CLightningGameEffect::STarget& emitter, const CLightningGameEffect::STarget& receiver)>(0x17DC410);
	static inline auto FGetSparkRemainingTime = PreyFunction<float(const CLightningGameEffect* const _this, const int spark)>(0x17DBEB0);
	static inline auto FComputeTargetPosition = PreyFunction<Vec3*(CLightningGameEffect* const _this, Vec3* _return_value_, const CLightningGameEffect::STarget& target, const Vec3& m_receiverLocalPosition)>(0x17DBC60);
};
#endif // MOONCRASH
