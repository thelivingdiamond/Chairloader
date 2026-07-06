// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	~CWeaponOffsetStack();
	
#if 0
	void SetOffset(SWeaponOffset const &arg0, float arg1);
#endif
	
	static inline auto FBlend = PreyFunction<SWeaponOffset(CWeaponOffsetStack *const _this, float deltaTime)>(0x1802570);
	static inline auto FPushOffset = PreyFunction<int(CWeaponOffsetStack *const _this, SWeaponOffset const &offset, unsigned layer, float blendTime)>(0x1802C70);
	static inline auto FPopOffset = PreyFunction<void(CWeaponOffsetStack *const _this, int offsetId, float blendTime)>(0x1802B50);
	static inline auto FBitNotCWeaponOffsetStack = PreyFunction<void(CWeaponOffsetStack *const _this)>(0xEC4CD0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

namespace Serialization
{
class IArchive;
} // namespace Serialization
enum class type_zero;

// SWeaponOffset
// Header:  Prey/GameDll/weaponoffset.h
struct SWeaponOffset
{ // Size=24 (0x18)
	Vec3 m_position;
	Ang3 m_rotation;

	SWeaponOffset(QuatT transformation);
	void Serialize(Serialization::IArchive& ar) { FSerialize(this, ar); }

#if 0
	SWeaponOffset();
	SWeaponOffset(type_zero _arg0_);
	SWeaponOffset(Vec3 _arg0_, Ang3 _arg1_);
#endif

	static inline auto FSWeaponOffsetOv3 = PreyFunction<void(SWeaponOffset* const _this, QuatT transformation)>(0x18F82F0);
	static inline auto FSerialize = PreyFunction<void(SWeaponOffset* const _this, Serialization::IArchive& ar)>(0x192A850);
};

// CWeaponOffsetState
// Header:  Prey/GameDll/weaponoffset.h
class CWeaponOffsetState
{ // Size=56 (0x38)
public:
	SWeaponOffset m_current;
	SWeaponOffset m_last;
	float m_transitiontime;
	float m_time;

	SWeaponOffset ComputeCurrentOffset() { alignas(SWeaponOffset) std::byte _return_buf_[sizeof(SWeaponOffset)]; return *FComputeCurrentOffset(this, reinterpret_cast<SWeaponOffset*>(_return_buf_)); }

#if 0
	CWeaponOffsetState();
	void SetState(const SWeaponOffset& _arg0_, float _arg1_);
	SWeaponOffset Blend(float _arg0_);
#endif

	static inline auto FComputeCurrentOffset = PreyFunction<SWeaponOffset*(CWeaponOffsetState* const _this, SWeaponOffset* _return_value_)>(0x192A0B0);
};

// CWeaponOffsetStack
// Header:  Prey/GameDll/weaponoffset.h
class CWeaponOffsetStack
{ // Size=88 (0x58)
public:
	// CWeaponOffsetStack::SWeaponOffsetLayer
	// Header:  Prey/GameDll/weaponoffset.h
	struct SWeaponOffsetLayer
	{ // Size=32 (0x20)
		SWeaponOffset m_offset;
		int m_id;
		unsigned m_layer;
	};

	using TOffsetId = int;
	using TWeaponOffsetLayers = std::vector<CWeaponOffsetStack::SWeaponOffsetLayer>;

	std::vector<CWeaponOffsetStack::SWeaponOffsetLayer> m_weaponOffsetLayers;
	CWeaponOffsetState m_state;
	int m_nextId;

	CWeaponOffsetStack();
	SWeaponOffset Blend(float deltaTime) { alignas(SWeaponOffset) std::byte _return_buf_[sizeof(SWeaponOffset)]; return *FBlend(this, reinterpret_cast<SWeaponOffset*>(_return_buf_), deltaTime); }
	int PushOffset(const SWeaponOffset& offset, unsigned layer, float blendTime) { return FPushOffset(this, offset, layer, blendTime); }
	void PopOffset(int offsetId, float blendTime) { FPopOffset(this, offsetId, blendTime); }

#if 0
	void SetOffset(const SWeaponOffset& _arg0_, float _arg1_);
#endif

	static inline auto FCWeaponOffsetStackOv2 = PreyFunction<void(CWeaponOffsetStack* const _this)>(0x192A010);
	static inline auto FBlend = PreyFunction<SWeaponOffset*(CWeaponOffsetStack* const _this, SWeaponOffset* _return_value_, float deltaTime)>(0x192A070);
	static inline auto FPushOffset = PreyFunction<int(CWeaponOffsetStack* const _this, const SWeaponOffset& offset, unsigned layer, float blendTime)>(0x192A770);
	static inline auto FPopOffset = PreyFunction<void(CWeaponOffsetStack* const _this, int offsetId, float blendTime)>(0x192A650);
};
#endif // !MOONCRASH
