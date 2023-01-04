// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkComplexRoomPerceivable.h>
#include <Prey/GameDll/ark/perception/ArkComplexVisualPerceivable.h>
#include <Prey/GameDll/ark/attention/arkcomplexattentionobject.h>

struct ArkAttentionLevelChange;
class ArkPlayer;
struct IPhysicalEntity;

// ArkPlayerAttentionObject
// Header:  Prey/GameDll/ark/attention/ArkPlayerAttentionObject.h
class ArkPlayerAttentionObject
	: public ArkComplexAttentionObject
	, public ArkAuralPerceivable
	, public ArkComplexVisualPerceivable
	, public ArkComplexRoomPerceivable
{ // Size=48 (0x30)
public:
	ArkPlayer* m_pPlayer;
	unsigned m_roomEntityId;

	ArkPlayerAttentionObject(ArkPlayer& _player);
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	bool IsAttentionObjectEnabled() const { return FIsAttentionObjectEnabled(this); }
	void EnableVisualPerceivable() { FEnableVisualPerceivable(this); }
	void DisableVisualPerceivable() { FDisableVisualPerceivable(this); }
	bool IsVisualPerceivableEnabled() const { return FIsVisualPerceivableEnabled(this); }
	void EnableAuralPerceivable() { FEnableAuralPerceivable(this); }
	void DisableAuralPerceivable() { FDisableAuralPerceivable(this); }
	bool IsAuralPerceivableEnabled() const { return FIsAuralPerceivableEnabled(this); }
	void EnableRoomPerceivable() { FEnableRoomPerceivable(this); }
	void DisableRoomPerceivable() { FDisableRoomPerceivable(this); }
	bool IsRoomPerceivableEnabled() const { return FIsRoomPerceivableEnabled(this); }
	void SetRoomEntityId(unsigned _id) { FSetRoomEntityId(this, _id); }
	virtual unsigned DoGetEntityId() const;
	virtual Vec3 DoGetAttentionPosition() const;
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange);
	virtual std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *> DoGetComplexVisualPerceivableWorldPoints(Vec3* _pFirstAnyWorldPoint, Vec3* _pLastAnyWorldPoint, Vec3* _pFirstAcuteWorldPoint, Vec3* _pLastAcuteWorldPoint, Vec3* _pFirstAllWorldPoint, Vec3* _pLastAllWorldPoint) const;
	virtual IPhysicalEntity* * DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const;
	virtual float DoGetVisibilityScalar() const;
	virtual bool DoGetIsInMimicryHidden() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	virtual unsigned DoGetCurrentRoomEntityId() const;

#if 0
	ArkPlayerAttentionObject(const ArkPlayerAttentionObject& _arg0_);
	unsigned GetRoomEntityId() const;
	ArkPlayerAttentionObject& operator=(const ArkPlayerAttentionObject& _arg0_);
#endif

	static inline auto FArkPlayerAttentionObjectOv1 = PreyFunction<void(ArkPlayerAttentionObject* const _this, ArkPlayer& _player)>(0x13F5B10);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F62F0);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F5B50);
	static inline auto FIsAttentionObjectEnabled = PreyFunction<bool(const ArkPlayerAttentionObject* const _this)>(0x13F63A0);
	static inline auto FEnableVisualPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F6370);
	static inline auto FDisableVisualPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F5BB0);
	static inline auto FIsVisualPerceivableEnabled = PreyFunction<bool(const ArkPlayerAttentionObject* const _this)>(0x13F6400);
	static inline auto FEnableAuralPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F6310);
	static inline auto FDisableAuralPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F5B70);
	static inline auto FIsAuralPerceivableEnabled = PreyFunction<bool(const ArkPlayerAttentionObject* const _this)>(0x13F63C0);
	static inline auto FEnableRoomPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F6340);
	static inline auto FDisableRoomPerceivable = PreyFunction<void(ArkPlayerAttentionObject* const _this)>(0x13F5B90);
	static inline auto FIsRoomPerceivableEnabled = PreyFunction<bool(const ArkPlayerAttentionObject* const _this)>(0x13F63E0);
	static inline auto FSetRoomEntityId = PreyFunction<void(ArkPlayerAttentionObject* const _this, unsigned _id)>(0x860630);
	static inline auto FDoGetEntityId = PreyFunction<unsigned(const ArkPlayerAttentionObject* const _this)>(0x13F6150);
	static inline auto FDoGetAttentionPosition = PreyFunction<Vec3*(const ArkPlayerAttentionObject* const _this, Vec3* _return_value_)>(0x13F5BD0);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkPlayerAttentionObject* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x13F6290);
	static inline auto FDoGetComplexVisualPerceivableWorldPoints = PreyFunction<std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *>*(const ArkComplexVisualPerceivable* const _this, std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *>* _return_value_, Vec3* _pFirstAnyWorldPoint, Vec3* _pLastAnyWorldPoint, Vec3* _pFirstAcuteWorldPoint, Vec3* _pLastAcuteWorldPoint, Vec3* _pFirstAllWorldPoint, Vec3* _pLastAllWorldPoint)>(0x13F5BF0);
	static inline auto FDoGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkComplexVisualPerceivable* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x11B23B0);
	static inline auto FDoGetVisibilityScalar = PreyFunction<float(const ArkComplexVisualPerceivable* const _this)>(0x13F61B0);
	static inline auto FDoGetIsInMimicryHidden = PreyFunction<bool(const ArkComplexRoomPerceivable* const _this)>(0x13F6170);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(const ArkAuralPerceivable* const _this)>(0x11B22F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(const ArkAuralPerceivable* const _this)>(0x1B933B0);
	static inline auto FDoGetCurrentRoomEntityId = PreyFunction<unsigned(const ArkComplexRoomPerceivable* const _this)>(0x985E40);
};

