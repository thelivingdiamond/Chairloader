// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

struct IEntity;
struct SEntityEvent;
struct SViewParams;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkExaminationMode.h
class ArkExaminationMode : public IEntityEventListener, public IUIControlSchemeListener, public IArkPlayerCarryListener // Id=801744A Size=280
{
public:
	enum class ExamineMode
	{
		Normal = 0,
		RemoteManipulation = 1,
		Forced = 2,
	};

	enum class EArkExaminationState
	{
		inactive = 0,
		active = 1,
		exiting = 2,
	};

	enum class EArkExaminationType
	{
		none = 0,
		worldUI = 1,
		telescope = 2,
		other = 3,
	};

	Quat m_initialRotation;
	Vec3 m_playerCameraPosition;
	Quat m_playerCameraRotation;
	Ang3 m_localRotation;
	Quat m_rotation;
	Vec2 m_reticlePos;
	Vec3 m_optimalCameraPos;
	float m_cameraLerpStartTime;
	float m_activeLerpDuration;
	float m_viewingBuffer;
	float m_maxCameraRotation;
	float m_cameraSpeedMultiplier;
	float m_cameraLerpDuration;
	float m_telescopeLerpDuration;
	float m_distFromNonWorldUI;
	ArkExaminationMode::EArkExaminationType m_examinationType;
	ArkExaminationMode::EArkExaminationState m_examinationState;
	unsigned m_targetEntity;
	int m_inputHandle;
	int m_zoomHandle;
	ArkExaminationMode::ExamineMode m_mode;
	ArkInputLegend m_inputLegendWorldUI;
	ArkInputLegend m_inputLegendDefault;
	ArkInputLegend m_inputLegendTelescope;
	ArkInputLegendHandler m_examinationLegendHandler;
	
	ArkExaminationMode();
	virtual ~ArkExaminationMode();
	void UpdateReticlePos(const float _frameTime) { FUpdateReticlePos(this,_frameTime); }
	bool CanExamineWorldUI() const { return FCanExamineWorldUI(this); }
	bool IsExaminingTelescope() const { return FIsExaminingTelescope(this); }
	void SetExamining(const bool _bValue, IEntity const *const _pWorldUIEntity, ArkExaminationMode::ExamineMode _mode) { FSetExamining(this,_bValue,_pWorldUIEntity,_mode); }
	void ExitExaminationInstant() { FExitExaminationInstant(this); }
	void RecenterRotationAndReticle() { FRecenterRotationAndReticle(this); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	bool UpdateView(SViewParams &_params) { return FUpdateView(this,_params); }
	void Reset() { FReset(this); }
	void TookDamage() { FTookDamage(this); }
	virtual void OnEntityEvent(IEntity *pEntity, SEntityEvent &event);
	void SetExamining_Internal(ArkExaminationMode::EArkExaminationState _value, IEntity const *const _pTargetEntity, ArkExaminationMode::ExamineMode _mode) { FSetExamining_Internal(this,_value,_pTargetEntity,_mode); }
	bool InqOptimalView(Vec3 &_optimalPos, Quat &_optimalRotation, IEntity const *_pTargetEntity) const { return FInqOptimalView(this,_optimalPos,_optimalRotation,_pTargetEntity); }
	uint64_t GetRemoteManipulationPostProcessId() const { return FGetRemoteManipulationPostProcessId(this); }
	IEntity const *GetUsableWorldUIEntity() const { return FGetUsableWorldUIEntity(this); }
	boost::optional<QuatT> GetLocationToPlacePlayer(IEntity const *_pWorldUIEntity) const { return FGetLocationToPlacePlayer(this,_pWorldUIEntity); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnStartCarry(IEntity *const _pEntity);
	
#if 0
	bool IsExamining() const;
	Vec2 const &GetReticlePos() const;
	bool IsZoomedIn() const;
	unsigned GetEntityBeingExamined() const;
	bool ShouldPreventRotation() const;
	ArkExaminationMode::ExamineMode GetExamineMode() const;
	float GetOptimalWorldUIOffset(Vec3 const &arg0) const;
#endif
	
	static inline auto FBitNotArkExaminationMode = PreyFunction<void(ArkExaminationMode *const _this)>(0x157C180);
	static inline auto FUpdateReticlePos = PreyFunction<void(ArkExaminationMode *const _this, const float _frameTime)>(0x157EBA0);
	static inline auto FCanExamineWorldUI = PreyFunction<bool(ArkExaminationMode const *const _this)>(0x157C800);
	static inline auto FIsExaminingTelescope = PreyFunction<bool(ArkExaminationMode const *const _this)>(0x157DD90);
	static inline auto FSetExamining = PreyFunction<void(ArkExaminationMode *const _this, const bool _bValue, IEntity const *const _pWorldUIEntity, ArkExaminationMode::ExamineMode _mode)>(0x157E1B0);
	static inline auto FExitExaminationInstant = PreyFunction<void(ArkExaminationMode *const _this)>(0x157C880);
	static inline auto FRecenterRotationAndReticle = PreyFunction<void(ArkExaminationMode *const _this)>(0x157E160);
	static inline auto FLoadConfig = PreyFunction<void(ArkExaminationMode *const _this, XmlNodeRef const &_node)>(0x157DDA0);
	static inline auto FUpdateView = PreyFunction<bool(ArkExaminationMode *const _this, SViewParams &_params)>(0x157EC80);
	static inline auto FReset = PreyFunction<void(ArkExaminationMode *const _this)>(0x157C880);
	static inline auto FTookDamage = PreyFunction<void(ArkExaminationMode *const _this)>(0x157EB40);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkExaminationMode *const _this, IEntity *pEntity, SEntityEvent &event)>(0x157C880);
	static inline auto FSetExamining_Internal = PreyFunction<void(ArkExaminationMode *const _this, ArkExaminationMode::EArkExaminationState _value, IEntity const *const _pTargetEntity, ArkExaminationMode::ExamineMode _mode)>(0x157E1E0);
	static inline auto FInqOptimalView = PreyFunction<bool(ArkExaminationMode const *const _this, Vec3 &_optimalPos, Quat &_optimalRotation, IEntity const *_pTargetEntity)>(0x157D5C0);
	static inline auto FGetRemoteManipulationPostProcessId = PreyFunction<uint64_t(ArkExaminationMode const *const _this)>(0x157D500);
	static inline auto FGetUsableWorldUIEntity = PreyFunction<IEntity const *(ArkExaminationMode const *const _this)>(0x157D540);
	static inline auto FGetLocationToPlacePlayer = PreyFunction<boost::optional<QuatT>(ArkExaminationMode const *const _this, IEntity const *_pWorldUIEntity)>(0x157C8D0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkExaminationMode *const _this, EControlScheme _controlScheme)>(0x157E0D0);
	static inline auto FOnStartCarry = PreyFunction<void(ArkExaminationMode *const _this, IEntity *const _pEntity)>(0x157E110);
};

