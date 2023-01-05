// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEntityGrabber.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkBreakableListener.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
class XmlNodeRef;

// ArkPlayerCarry
// Header:  Prey/GameDll/ark/player/ArkPlayerCarry.h
class ArkPlayerCarry : public IEntitySystemSink, public IArkBreakableListener
{ // Size=256 (0x100)
public:
	ArkInputLegend m_carryLegend;
	ArkInputLegendHandler m_carryLegendHandler;
	ArkSimpleTimer m_collisionRestoreTimer;
	ArkEntityGrabber m_grabber;
	ArkAudioTrigger m_throwAudio;
	std::vector<string> m_dragCorpseJointNames;
	std::array<float,4> m_throwKickBacks;
	std::array<float,4> m_leverageHoldDurations;
	Quat m_pickupEntityOriginalRotation;
	unsigned m_pickedUpEntityId;
	int m_pickedUpEntityConstraintId;
	float m_carryMaxPullForce;
	float m_carryMaxPullForceZeroG;
	float m_carryHeightOffset;
	float m_carryCameraRotationToEntityMinThreshold;
	float m_carryCameraRotationToEntityMaxThreshold;
	float m_carryObjectLengthRotationLimitScaleMin;
	float m_carryObjectLengthRotationLimitScaleMax;
	float m_carrySneakPitchLimit;
	float m_dragCorpseHeight;
	float m_dragCorpseDistance;
	float m_dragCorpseBreakDistanceSq;
	float m_dragCorpseSyncSpeed;
	float m_dragCorpseRemoteSyncSpeed;
	float m_opacity;
	int m_dragCorpsePartId;
	int m_attachedEmitterSlot;
	EStance m_dragCorpsePreviousStance;
	bool m_bThrowCarriedEntity;
	bool m_bCastSunShadow;
	bool m_bRemoteManipulatedCorpse;
	bool m_bJustThrown;

	ArkPlayerCarry();
	virtual ~ArkPlayerCarry();
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void PreSerialize() { FPreSerialize(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	bool IsDraggingCorpse() const { return FIsDraggingCorpse(this); }
	void DropCarriedEntity() { FDropCarriedEntity(this); }
	bool ThrowCarriedEntity() { return FThrowCarriedEntity(this); }
	void UpdateCarryConstraintForZeroG(bool _bZerog) const { FUpdateCarryConstraintForZeroG(this, _bZerog); }
	void Reset() { FReset(this); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void OnStanceChanged() const { FOnStanceChanged(this); }
	bool StartCarrying(IEntity* _pEntity, const bool _bRemote, const bool _bFromSerialize) { return FStartCarrying(this, _pEntity, _bRemote, _bFromSerialize); }
	QuatT GetLerpTargetLocation(const IEntity* _pLerpingEntity, const Quat& _originalRotation) const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetLerpTargetLocation(this, reinterpret_cast<QuatT*>(_return_buf_), _pLerpingEntity, _originalRotation); }
	static Quat GetCarryDirection(const IEntity* _pEntity) { return FGetCarryDirection(_pEntity); }
	float GetLeverageHoldDuration(const uint64_t _leverageRequirement) const { return FGetLeverageHoldDuration(this, _leverageRequirement); }
	bool RestoreCollision(const bool _bFromSerialize) { return FRestoreCollision(this, _bFromSerialize); }
	void StopCarrying(const float _impulse, const bool _bApplyAngularImpulse, const bool _bThrown, const bool _bFromSerialize) { FStopCarrying(this, _impulse, _bApplyAngularImpulse, _bThrown, _bFromSerialize); }
	Vec3 GetDragCorpseConstraintPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetDragCorpseConstraintPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void RemoveEmitter() { FRemoveEmitter(this); }
	virtual void OnBroken(const IEntity& _entity);
	virtual bool OnBeforeSpawn(SEntitySpawnParams& params);
	virtual void OnSpawn(IEntity* pEntity, SEntitySpawnParams& params);
	virtual bool OnRemove(IEntity* pEntity);
	virtual void OnReused(IEntity* pEntity, SEntitySpawnParams& params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	bool IsCarrying() const;
	unsigned GetPickedUpEntity() const;
	bool IsAttemptingToRestoreCollision() const;
	float GetCarrySneakPitchLimit() const;
	void ClearPickedUpEntity();
#endif

	static inline auto FArkPlayerCarryOv1 = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122D6B0);
	static inline auto FBitNotArkPlayerCarry = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122D930);
	static inline auto FUpdate = PreyFunction<bool(ArkPlayerCarry* const _this, float _frameTime)>(0x1231C80);
	static inline auto FPreSerialize = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122F980);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerCarry* const _this, TSerialize _ser)>(0x122FBB0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122F880);
	static inline auto FIsDraggingCorpse = PreyFunction<bool(const ArkPlayerCarry* const _this)>(0x122EE80);
	static inline auto FDropCarriedEntity = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122DAD0);
	static inline auto FThrowCarriedEntity = PreyFunction<bool(ArkPlayerCarry* const _this)>(0x1231B50);
	static inline auto FUpdateCarryConstraintForZeroG = PreyFunction<void(const ArkPlayerCarry* const _this, bool _bZerog)>(0x1232900);
	static inline auto FReset = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122FA40);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerCarry* const _this, const XmlNodeRef& _node)>(0x122EED0);
	static inline auto FOnStanceChanged = PreyFunction<void(const ArkPlayerCarry* const _this)>(0x122F780);
	static inline auto FStartCarrying = PreyFunction<bool(ArkPlayerCarry* const _this, IEntity* _pEntity, const bool _bRemote, const bool _bFromSerialize)>(0x122FC50);
	static inline auto FGetLerpTargetLocation = PreyFunction<QuatT*(const ArkPlayerCarry* const _this, QuatT* _return_value_, const IEntity* _pLerpingEntity, const Quat& _originalRotation)>(0x122DFD0);
	static inline auto FGetCarryDirection = PreyFunction<Quat(const IEntity* _pEntity)>(0x122DB50);
	static inline auto FGetLeverageHoldDuration = PreyFunction<float(const ArkPlayerCarry* const _this, const uint64_t _leverageRequirement)>(0x122ED40);
	static inline auto FRestoreCollision = PreyFunction<bool(ArkPlayerCarry* const _this, const bool _bFromSerialize)>(0x122FA70);
	static inline auto FStopCarrying = PreyFunction<void(ArkPlayerCarry* const _this, const float _impulse, const bool _bApplyAngularImpulse, const bool _bThrown, const bool _bFromSerialize)>(0x12307F0);
	static inline auto FGetDragCorpseConstraintPos = PreyFunction<Vec3*(const ArkPlayerCarry* const _this, Vec3* _return_value_)>(0x122DEF0);
	static inline auto FRemoveEmitter = PreyFunction<void(ArkPlayerCarry* const _this)>(0x122F9E0);
	static inline auto FOnBroken = PreyFunction<void(IArkBreakableListener* const _this, const IEntity& _entity)>(0x122F5A0);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkPlayerCarry* const _this, SEntitySpawnParams& params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkPlayerCarry* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0xA13080);
	static inline auto FOnRemove = PreyFunction<bool(ArkPlayerCarry* const _this, IEntity* pEntity)>(0x1B933B0);
	static inline auto FOnReused = PreyFunction<void(ArkPlayerCarry* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkPlayerCarry* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x122F6A0);
};

