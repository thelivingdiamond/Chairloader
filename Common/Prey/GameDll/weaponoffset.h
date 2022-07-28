// Header file automatically created from a PDB.

#pragma once

// Header: Exact
// Prey/GameDll/weaponoffset.h
struct SWeaponOffset // Id=8016D05 Size=24
{
	Vec3 m_position;
	Ang3 m_rotation;
	
	SWeaponOffset(QuatT transformation);
	void Serialize(Serialization::IArchive &ar) { FSerialize(this,ar); }
	
	static inline auto FSerialize = PreyFunction<void(SWeaponOffset *const _this, Serialization::IArchive &ar)>(0x1802D50);
};

// Header: FromCpp
// Prey/GameDll/weaponoffset.h
class CWeaponOffsetState // Id=8016D21 Size=56
{
public:
	SWeaponOffset m_current;
	SWeaponOffset m_last;
	float m_transitiontime;
	float m_time;
	
	SWeaponOffset ComputeCurrentOffset() { return FComputeCurrentOffset(this); }
	
#if 0
	void SetState(SWeaponOffset const &arg0, float arg1);
	SWeaponOffset Blend(float arg0);
#endif
	
	static inline auto FComputeCurrentOffset = PreyFunction<SWeaponOffset(CWeaponOffsetState *const _this)>(0x18025B0);
};

// Header: FromCpp
// Prey/GameDll/weaponoffset.h
class CWeaponOffsetStack // Id=8016D0A Size=88
{
public:
	using TOffsetId = int;
	
	struct SWeaponOffsetLayer // Id=8016D0B Size=32
	{
		SWeaponOffset m_offset;
		int m_id;
		unsigned m_layer;
	};

	using TWeaponOffsetLayers = std::vector<CWeaponOffsetStack::SWeaponOffsetLayer>;
	
	std::vector<CWeaponOffsetStack::SWeaponOffsetLayer> m_weaponOffsetLayers;
	CWeaponOffsetState m_state;
	int m_nextId;
	
	CWeaponOffsetStack();
	SWeaponOffset Blend(float deltaTime) { return FBlend(this,deltaTime); }
	int PushOffset(SWeaponOffset const &offset, unsigned layer, float blendTime) { return FPushOffset(this,offset,layer,blendTime); }
	void PopOffset(int offsetId, float blendTime) { FPopOffset(this,offsetId,blendTime); }
	~CWeaponOffsetStack() { FBitNotCWeaponOffsetStack(this); }
	
#if 0
	void SetOffset(SWeaponOffset const &arg0, float arg1);
#endif
	
	static inline auto FBlend = PreyFunction<SWeaponOffset(CWeaponOffsetStack *const _this, float deltaTime)>(0x1802570);
	static inline auto FPushOffset = PreyFunction<int(CWeaponOffsetStack *const _this, SWeaponOffset const &offset, unsigned layer, float blendTime)>(0x1802C70);
	static inline auto FPopOffset = PreyFunction<void(CWeaponOffsetStack *const _this, int offsetId, float blendTime)>(0x1802B50);
	static inline auto FBitNotCWeaponOffsetStack = PreyFunction<void(CWeaponOffsetStack *const _this)>(0xEC4CD0);
};

