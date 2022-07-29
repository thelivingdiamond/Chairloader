// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiLift.h
class ArkPsiLift // Id=80141B5 Size=56
{
public:
	Vec3 m_axis;
	Vec3 m_position;
	string m_particleEffectName;
	unsigned m_entityId;
	unsigned m_ownerId;
	int m_particleEmitterSlot;
	float m_radius;
	float m_height;
	
	ArkPsiLift();
	ArkPsiLift(ArkPsiLift *_lift);
	ArkPsiLift(const float _radius, const float _height, const unsigned _ownerId);
	~ArkPsiLift();
	ArkPsiLift &operator=(ArkPsiLift *_lift) { return FoperatorEqOv1(this,_lift); }
	bool operator==(ArkPsiLift const &_lift) const { return FoperatorEqEq(this,_lift); }
	void Reset() { FReset(this); }
	bool Visible() const { return FVisible(this); }
	void Hide(const bool _bHide) { FHide(this,_bHide); }
	void SetAxis(Vec3 const &_axis) { FSetAxis(this,_axis); }
	void SetHeight(const float _height) { FSetHeight(this,_height); }
	void SetPosition(Vec3 const &_position) { FSetPosition(this,_position); }
	void SpawnParticleEmitter(const char *_pParticleEffectName, const bool _bUseUiTime) { FSpawnParticleEmitter(this,_pParticleEffectName,_bUseUiTime); }
	OBB GetBounds() const { return FGetBounds(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void UpdateParticleEmitter() const { FUpdateParticleEmitter(this); }
	
#if 0
	float GetHeight() const;
	float GetRadius() const;
	Vec3 const &GetAxis() const;
	Vec3 const &GetBasePosition() const;
	unsigned GetEntityId() const;
	unsigned GetOwnerId() const;
#endif
	
	static inline auto FBitNotArkPsiLift = PreyFunction<void(ArkPsiLift *const _this)>(0x1316720);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiLift &(ArkPsiLift *const _this, ArkPsiLift *_lift)>(0x13167B0);
	static inline auto FoperatorEqEq = PreyFunction<bool(ArkPsiLift const *const _this, ArkPsiLift const &_lift)>(0x13167F0);
	static inline auto FReset = PreyFunction<void(ArkPsiLift *const _this)>(0x1316C10);
	static inline auto FVisible = PreyFunction<bool(ArkPsiLift const *const _this)>(0x1317490);
	static inline auto FHide = PreyFunction<void(ArkPsiLift *const _this, const bool _bHide)>(0x1316AD0);
	static inline auto FSetAxis = PreyFunction<void(ArkPsiLift *const _this, Vec3 const &_axis)>(0x1316E40);
	static inline auto FSetHeight = PreyFunction<void(ArkPsiLift *const _this, const float _height)>(0x1317190);
	static inline auto FSetPosition = PreyFunction<void(ArkPsiLift *const _this, Vec3 const &_position)>(0x13171B0);
	static inline auto FSpawnParticleEmitter = PreyFunction<void(ArkPsiLift *const _this, const char *_pParticleEffectName, const bool _bUseUiTime)>(0x1317210);
	static inline auto FGetBounds = PreyFunction<OBB(ArkPsiLift const *const _this)>(0x1316800);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLift *const _this, TSerialize _ser)>(0x1316C90);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiLift *const _this)>(0x1316B10);
	static inline auto FUpdateParticleEmitter = PreyFunction<void(ArkPsiLift const *const _this)>(0x1317320);
};

