// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/player/ArkAimAssistConfig.h>
#include <Prey/GameDll/ark/player/arkaimassistcomponent.h>

struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkAimAssistComponent.h
class ArkAimAssistComponent : public IEntitySystemSink // Id=801718C Size=232
{
public:
	struct ArkAimAssistTarget // Id=801718D Size=64
	{
		std::vector<Vec3> attachPoints;
		Vec3 aimPos;
		IEntity *pEntity;
		float score;
		float distanceSq;
		bool bHasLOS;
		
#if 0
		void Clear();
#endif
	};

	ArkAimAssistConfig m_config;
	ArkAimAssistComponent::ArkAimAssistTarget m_target;
	std::vector<IEntity *> m_potentialTargets;
	std::unordered_map<IEntityClass const *,ArkAimAssistEntity const *> m_entityConfigs;
	uint64_t m_CQCPostProcessId;
	float m_fCQCMinDistanceSq;
	float m_deadZoneSq;
	unsigned m_nAnalyzed;
	bool m_bShowingCQCPostProcess;
	
	ArkAimAssistComponent();
	void Update() { FUpdate(this); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Apply(Ang3 &_gamepadRotation) const { FApply(this,_gamepadRotation); }
	void Reset() { FReset(this); }
	boost::optional<Vec3> GetReticlePosAtTargetDistance() const { return FGetReticlePosAtTargetDistance(this); }
	boost::optional<Vec3> GetBoneAimPos() const { return FGetBoneAimPos(this); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams &_params);
	virtual void OnSpawn(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual bool OnRemove(IEntity *_pEntity);
	virtual void OnReused(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual void OnEvent(IEntity *_pEntity, SEntityEvent &_event);
	bool IsAimAssistEntity(IEntity const &_entity) const { return FIsAimAssistEntity(this,_entity); }
	
#if 0
	static void RegisterCVars();
	boost::optional<Vec3> GetAimPos() const;
	std::pair<IEntity const *,bool> GetCurrentTarget() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkAimAssistComponent *const _this)>(0x12B4550);
	static inline auto FLoadConfig = PreyFunction<void(ArkAimAssistComponent *const _this, XmlNodeRef const &_node)>(0x12B3D00);
	static inline auto FApply = PreyFunction<void(ArkAimAssistComponent const *const _this, Ang3 &_gamepadRotation)>(0x12B2B70);
	static inline auto FReset = PreyFunction<void(ArkAimAssistComponent *const _this)>(0x12B4070);
	static inline auto FGetReticlePosAtTargetDistance = PreyFunction<boost::optional<Vec3>(ArkAimAssistComponent const *const _this)>(0x12B3AF0);
	static inline auto FGetBoneAimPos = PreyFunction<boost::optional<Vec3>(ArkAimAssistComponent const *const _this)>(0x12B38C0);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkAimAssistComponent *const _this, SEntitySpawnParams &_params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkAimAssistComponent *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0x12B3F00);
	static inline auto FOnRemove = PreyFunction<bool(ArkAimAssistComponent *const _this, IEntity *_pEntity)>(0x12B3E70);
	static inline auto FOnReused = PreyFunction<void(ArkAimAssistComponent *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkAimAssistComponent *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x12B3DF0);
	static inline auto FIsAimAssistEntity = PreyFunction<bool(ArkAimAssistComponent const *const _this, IEntity const &_entity)>(0x12B3BF0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/arkaimassistcomponent.h
struct ArkAimEntityDebug // Id=801AD72 Size=56
{
	IEntity const *pEntity;
	Vec3 aimPos;
	float innerWidth;
	float outerWidth;
	float score;
	std::vector<Vec3> points;
	
	void Draw(Matrix44 const &_unprojMtx, float _projRatio) const { FDraw(this,_unprojMtx,_projRatio); }
	
	static inline auto FDraw = PreyFunction<void(ArkAimEntityDebug const *const _this, Matrix44 const &_unprojMtx, float _projRatio)>(0x12B3320);
};

