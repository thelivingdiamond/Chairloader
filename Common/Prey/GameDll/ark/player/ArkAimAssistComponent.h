// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/player/ArkAimAssistConfig.h>

class ArkAimAssistEntity;
struct IEntity;
struct IEntityClass;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;

// ArkAimAssistComponent
// Header:  Prey/GameDll/ark/player/ArkAimAssistComponent.h
class ArkAimAssistComponent : public IEntitySystemSink
{ // Size=232 (0xE8)
public:
	// ArkAimAssistComponent::ArkAimAssistTarget
	// Header:  Prey/GameDll/ark/player/ArkAimAssistComponent.h
	struct ArkAimAssistTarget
	{ // Size=64 (0x40)
		std::vector<Vec3> attachPoints;
		Vec3 aimPos;
		IEntity* pEntity;
		float score;
		float distanceSq;
		bool bHasLOS;

	#if 0
		ArkAimAssistTarget();
		void Clear();
	#endif
	};

	ArkAimAssistConfig m_config;
	ArkAimAssistComponent::ArkAimAssistTarget m_target;
	std::vector<IEntity*> m_potentialTargets;
	std::unordered_map<const IEntityClass*, const ArkAimAssistEntity*> m_entityConfigs;
	uint64_t m_CQCPostProcessId;
	float m_fCQCMinDistanceSq;
	float m_deadZoneSq;
	unsigned m_nAnalyzed;
	bool m_bShowingCQCPostProcess;

	ArkAimAssistComponent();
	virtual ~ArkAimAssistComponent();
	void Update() { FUpdate(this); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Apply(Ang3& _gamepadRotation) const { FApply(this, _gamepadRotation); }
	void Reset() { FReset(this); }
	boost::optional<Vec3_tpl<float> > GetReticlePosAtTargetDistance() const { alignas(boost::optional<Vec3_tpl<float> >) std::byte _return_buf_[sizeof(boost::optional<Vec3_tpl<float> >)]; return *FGetReticlePosAtTargetDistance(this, reinterpret_cast<boost::optional<Vec3_tpl<float> >*>(_return_buf_)); }
	boost::optional<Vec3_tpl<float> > GetBoneAimPos() const { alignas(boost::optional<Vec3_tpl<float> >) std::byte _return_buf_[sizeof(boost::optional<Vec3_tpl<float> >)]; return *FGetBoneAimPos(this, reinterpret_cast<boost::optional<Vec3_tpl<float> >*>(_return_buf_)); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& _params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& _event);
	bool IsAimAssistEntity(const IEntity& _entity) const { return FIsAimAssistEntity(this, _entity); }

#if 0
	static void RegisterCVars();
	boost::optional<Vec3_tpl<float> > GetAimPos() const;
	std::pair<const IEntity*, bool> GetCurrentTarget() const;
#endif

	static inline auto FArkAimAssistComponentOv1 = PreyFunction<void(ArkAimAssistComponent* const _this)>(0x12B2000);
	static inline auto FUpdate = PreyFunction<void(ArkAimAssistComponent* const _this)>(0x12B4550);
	static inline auto FLoadConfig = PreyFunction<void(ArkAimAssistComponent* const _this, const XmlNodeRef& _node)>(0x12B3D00);
	static inline auto FApply = PreyFunction<void(const ArkAimAssistComponent* const _this, Ang3& _gamepadRotation)>(0x12B2B70);
	static inline auto FReset = PreyFunction<void(ArkAimAssistComponent* const _this)>(0x12B4070);
	static inline auto FGetReticlePosAtTargetDistance = PreyFunction<boost::optional<Vec3_tpl<float> >*(const ArkAimAssistComponent* const _this, boost::optional<Vec3_tpl<float> >* _return_value_)>(0x12B3AF0);
	static inline auto FGetBoneAimPos = PreyFunction<boost::optional<Vec3_tpl<float> >*(const ArkAimAssistComponent* const _this, boost::optional<Vec3_tpl<float> >* _return_value_)>(0x12B38C0);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkAimAssistComponent* const _this, SEntitySpawnParams& _params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkAimAssistComponent* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0x12B3F00);
	static inline auto FOnRemove = PreyFunction<bool(ArkAimAssistComponent* const _this, IEntity* _pEntity)>(0x12B3E70);
	static inline auto FOnReused = PreyFunction<void(ArkAimAssistComponent* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkAimAssistComponent* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x12B3DF0);
	static inline auto FIsAimAssistEntity = PreyFunction<bool(const ArkAimAssistComponent* const _this, const IEntity& _entity)>(0x12B3BF0);
};

// ArkAimEntityDebug
// Header:  Prey/GameDll/ark/player/ArkAimAssistComponent.h
struct ArkAimEntityDebug
{ // Size=56 (0x38)
	const IEntity* pEntity;
	Vec3 aimPos;
	float innerWidth;
	float outerWidth;
	float score;
	std::vector<Vec3> points;

	void Draw(const Matrix44& _unprojMtx, float _projRatio) const { FDraw(this, _unprojMtx, _projRatio); }

#if 0
	ArkAimEntityDebug(const IEntity* const _arg0_);
#endif

	static inline auto FDraw = PreyFunction<void(const ArkAimEntityDebug* const _this, const Matrix44& _unprojMtx, float _projRatio)>(0x12B3320);
};

