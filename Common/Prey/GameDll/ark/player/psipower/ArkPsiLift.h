// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>

// ArkPsiLift
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLift.h
class ArkPsiLift
{ // Size=56 (0x38)
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
	ArkPsiLift(ArkPsiLift&& _lift);
	ArkPsiLift(const float _radius, const float _height, const unsigned _ownerId);
	~ArkPsiLift();
	//ArkPsiLift& operator=(ArkPsiLift&& _lift) { return FoperatorEqOv1(this, _lift); }
	bool operator==(const ArkPsiLift& _lift) const { return FoperatorEqEq(this, _lift); }
	void Reset() { FReset(this); }
	bool Visible() const { return FVisible(this); }
	void Hide(const bool _bHide) { FHide(this, _bHide); }
	void SetAxis(const Vec3& _axis) { FSetAxis(this, _axis); }
	void SetHeight(const float _height) { FSetHeight(this, _height); }
	void SetPosition(const Vec3& _position) { FSetPosition(this, _position); }
	void SpawnParticleEmitter(const char* _pParticleEffectName, const bool _bUseUiTime) { FSpawnParticleEmitter(this, _pParticleEffectName, _bUseUiTime); }
	OBB GetBounds() const { alignas(OBB) std::byte _return_buf_[sizeof(OBB)]; return *FGetBounds(this, reinterpret_cast<OBB*>(_return_buf_)); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void UpdateParticleEmitter() const { FUpdateParticleEmitter(this); }

#if 0
	ArkPsiLift(const ArkPsiLift& _arg0_);
	ArkPsiLift& operator=(const ArkPsiLift& _arg0_);
	float GetHeight() const;
	float GetRadius() const;
	const Vec3& GetAxis() const;
	const Vec3& GetBasePosition() const;
	unsigned GetEntityId() const;
	unsigned GetOwnerId() const;
#endif

	static inline auto FArkPsiLiftOv3 = PreyFunction<void(ArkPsiLift* const _this)>(0x13166D0);
	static inline auto FArkPsiLiftOv2 = PreyFunction<void(ArkPsiLift* const _this, ArkPsiLift&& _lift)>(0x13164E0);
	static inline auto FArkPsiLiftOv1 = PreyFunction<void(ArkPsiLift* const _this, const float _radius, const float _height, const unsigned _ownerId)>(0x1316560);
	static inline auto FBitNotArkPsiLift = PreyFunction<void(ArkPsiLift* const _this)>(0x1316720);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiLift& (ArkPsiLift* const _this, ArkPsiLift&& _lift)>(0x13167B0);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkPsiLift* const _this, const ArkPsiLift& _lift)>(0x13167F0);
	static inline auto FReset = PreyFunction<void(ArkPsiLift* const _this)>(0x1316C10);
	static inline auto FVisible = PreyFunction<bool(const ArkPsiLift* const _this)>(0x1317490);
	static inline auto FHide = PreyFunction<void(ArkPsiLift* const _this, const bool _bHide)>(0x1316AD0);
	static inline auto FSetAxis = PreyFunction<void(ArkPsiLift* const _this, const Vec3& _axis)>(0x1316E40);
	static inline auto FSetHeight = PreyFunction<void(ArkPsiLift* const _this, const float _height)>(0x1317190);
	static inline auto FSetPosition = PreyFunction<void(ArkPsiLift* const _this, const Vec3& _position)>(0x13171B0);
	static inline auto FSpawnParticleEmitter = PreyFunction<void(ArkPsiLift* const _this, const char* _pParticleEffectName, const bool _bUseUiTime)>(0x1317210);
	static inline auto FGetBounds = PreyFunction<OBB*(const ArkPsiLift* const _this, OBB* _return_value_)>(0x1316800);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLift* const _this, TSerialize _ser)>(0x1316C90);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiLift* const _this)>(0x1316B10);
	static inline auto FUpdateParticleEmitter = PreyFunction<void(const ArkPsiLift* const _this)>(0x1317320);
};

