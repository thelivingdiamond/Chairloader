// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct ICharacterInstance;

// CIKTorsoAim_Helper
// Header:  Prey/GameDll/IKTorsoAim_Helper.h
class CIKTorsoAim_Helper
{ // Size=48 (0x30)
public:
	// CIKTorsoAim_Helper::SIKTorsoParams
	// Header:  Prey/GameDll/IKTorsoAim_Helper.h
	struct SIKTorsoParams
	{ // Size=88 (0x58)
		ICharacterInstance* character;
		ICharacterInstance* shadowCharacter;
		QuatT viewOffset;
		Vec3 aimDirection;
		Vec3 targetPosition;
		float blendRate;
		int effectorJoint;
		int aimJoint;
		int pinJoint;
		bool updateTranslationPinning;
		bool needsSTAPPosition;

	#if 0
		SIKTorsoParams(ICharacterInstance* _arg0_, ICharacterInstance* _arg1_, Vec3 _arg2_, QuatT _arg3_, Vec3 _arg4_, int _arg5_, int _arg6_, int _arg7_, bool _arg8_, bool _arg9_, float _arg10_);
	#endif
	};

	std::shared_ptr<CIKTorsoAim> m_ikTorsoAim;
	std::shared_ptr<ITransformationPinning> m_transformationPin;
	bool m_initialized;
	bool m_enabled;
	float m_blendFactor;
	float m_blendFactorPosition;

	CIKTorsoAim_Helper();
	void Enable(bool snap) { FEnable(this, snap); }
	void Disable(bool snap) { FDisable(this, snap); }

#if 0
	void Update(CIKTorsoAim_Helper::SIKTorsoParams& _arg0_);
	void Reset();
	bool IsEnabled() const;
	float GetBlendFactor() const;
	const QuatT& GetLastEffectorTransform() const;
	void Init(CIKTorsoAim_Helper::SIKTorsoParams& _arg0_);
#endif

	static inline auto FCIKTorsoAim_HelperOv2 = PreyFunction<void(CIKTorsoAim_Helper* const _this)>(0x1878A40);
	static inline auto FEnable = PreyFunction<void(CIKTorsoAim_Helper* const _this, bool snap)>(0x1878AB0);
	static inline auto FDisable = PreyFunction<void(CIKTorsoAim_Helper* const _this, bool snap)>(0x1878AA0);
};
#endif // MOONCRASH
