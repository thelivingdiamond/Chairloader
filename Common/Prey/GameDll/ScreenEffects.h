// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CBlendGroup;
struct IBlendType;
struct IBlendedEffect;
class ICrySizer;

// CScreenEffects
// Header:  Prey/GameDll/ScreenEffects.h
class CScreenEffects
{ // Size=72 (0x48)
public:
	enum ScreenEffectsGroupId
	{
		eSFX_GID_RBlur = 1,
		eSFX_GID_ZoomIn = 2,
		eSFX_GID_ZoomOut = 3,
		eSFX_GID_HitReaction = 4,
		eSFX_GID_MotionBlur = 5,
		eSFX_GID_Last = 6,
	};

	enum CameraShakeGroupId
	{
		eCS_GID_Default = 1,
		eCS_GID_Player = 2,
		eCS_GID_Weapon = 3,
		eCS_GID_HitRecoil = 4,
	};

	std::map<int, CBlendGroup*> m_blends;
	std::map<int, bool> m_enabledGroups;
	int m_curUniqueID;
	bool m_enableBlends;
	bool m_updatecoords;
	string m_coordsXname;
	string m_coordsYname;
	Vec3 m_coords3d;

	CScreenEffects();
	~CScreenEffects();
	void Reset() { FReset(this); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	void PostUpdate(float frameTime) { FPostUpdate(this, frameTime); }
	void GetMemoryStatistics(ICrySizer* s) { FGetMemoryStatistics(this, s); }
	void ClearAllBlendGroups(bool resetScreen) { FClearAllBlendGroups(this, resetScreen); }
	void ResetScreen() { FResetScreen(this); }
	void ResetGameEffectPools() { FResetGameEffectPools(this); }

#if 0
	void ResetAllBlendGroups(bool _arg0_);
	void CamShake(Vec3 _arg0_, Vec3 _arg1_, float _arg2_, float _arg3_, float _arg4_, int _arg5_);
	void ProcessExplosionEffect(float _arg0_, const Vec3& _arg1_);
	void ProcessZoomInEffect();
	void ProcessZoomOutEffect();
	void ProcessSlidingFX();
	void ProcessSprintingFX(bool _arg0_, bool _arg1_);
	void ProcessPsiEffect_KineticBlast(float _arg0_, const Vec3& _arg1_);
	void SetUpdateCoords(const char* _arg0_, const char* _arg1_, Vec3 _arg2_);
	void EnableBlends(bool _arg0_);
	void EnableBlends(bool _arg0_, int _arg1_);
	void ClearBlendGroup(int _arg0_, bool _arg1_);
	void ResetBlendGroup(int _arg0_, bool _arg1_);
	int GetUniqueID();
	void StartBlend(IBlendedEffect* _arg0_, IBlendType* _arg1_, float _arg2_, int _arg3_);
	bool HasJobs(int _arg0_);
#endif

	static inline auto FCScreenEffectsOv1 = PreyFunction<void(CScreenEffects* const _this)>(0x1900020);
	static inline auto FBitNotCScreenEffects = PreyFunction<void(CScreenEffects* const _this)>(0x1900090);
	static inline auto FReset = PreyFunction<void(CScreenEffects* const _this)>(0x19003B0);
	static inline auto FUpdate = PreyFunction<void(CScreenEffects* const _this, float frameTime)>(0x1900540);
	static inline auto FPostUpdate = PreyFunction<void(CScreenEffects* const _this, float frameTime)>(0x1900300);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CScreenEffects* const _this, ICrySizer* s)>(0x1900280);
	static inline auto FClearAllBlendGroups = PreyFunction<void(CScreenEffects* const _this, bool resetScreen)>(0x19001B0);
	static inline auto FResetScreen = PreyFunction<void(CScreenEffects* const _this)>(0x1900420);
	static inline auto FResetGameEffectPools = PreyFunction<void(CScreenEffects* const _this)>(0x19007C0);
};
#endif // MOONCRASH
