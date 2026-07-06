// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkAvoidanceField
// Header:  Prey/GameDll/ark/ArkAvoidanceField.h
class ArkAvoidanceField
{ // Size=12 (0xC)
public:
	unsigned m_avoidanceFieldId;
	ArkDangerAreaType m_dangerAreaType;
	const bool m_bTreatAsHazard;

	ArkAvoidanceField(bool _bTreatAsHazard);
	~ArkAvoidanceField();
	void LoadScriptData(IEntity& _entityOwner) { FLoadScriptData(this, _entityOwner); }
	void Add(const Vec3& _position, float _radius) { FAdd(this, _position, _radius); }
	void Update(const Vec3& _position, float _radius) const { FUpdate(this, _position, _radius); }
	void Remove() { FRemove(this); }
	bool IsValid() const { return FIsValid(this); }

#if 0
	void SetDangerType(const ArkDangerAreaType _arg0_);
#endif

	static inline auto FArkAvoidanceField = PreyFunction<void(ArkAvoidanceField* const _this, bool _bTreatAsHazard)>(0x11930F0);
	static inline auto FBitNotArkAvoidanceField = PreyFunction<void(ArkAvoidanceField* const _this)>(0x1333E90);
	static inline auto FLoadScriptData = PreyFunction<void(ArkAvoidanceField* const _this, IEntity& _entityOwner)>(0x1193170);
	static inline auto FAdd = PreyFunction<void(ArkAvoidanceField* const _this, const Vec3& _position, float _radius)>(0x1193110);
	static inline auto FUpdate = PreyFunction<void(const ArkAvoidanceField* const _this, const Vec3& _position, float _radius)>(0x11932B0);
	static inline auto FRemove = PreyFunction<void(ArkAvoidanceField* const _this)>(0x1193270);
	static inline auto FIsValid = PreyFunction<bool(const ArkAvoidanceField* const _this)>(0x141ABA0);
};
#endif // MOONCRASH
