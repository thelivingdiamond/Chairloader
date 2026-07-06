// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/effects/gameeffects/GameEffect.h>
#include <_unknown/CryFixedArray.h>

// CParameterGameEffect
// Header:  Prey/GameDll/effects/gameeffects/ParameterGameEffect.h
class CParameterGameEffect : public CGameEffect
{ // Size=64 (0x40)
public:
	enum ESaturationEffectUsage
	{
		eSEU_PreMatch = 0,
		eSEU_LeavingBattleArea = 1,
		eSEU_PlayerHealth = 2,
		eSEU_Intro = 3,
		eSEU_NUMTYPES = 4,
	};

	// CParameterGameEffect::SSaturationData
	// Header:  Prey/GameDll/effects/gameeffects/ParameterGameEffect.h
	struct SSaturationData
	{ // Size=4 (0x4)
		float m_amount;

	#if 0
		SSaturationData();
	#endif
	};

	using TSaturationEffectExecutionData = CryFixedArray<CParameterGameEffect::SSaturationData,4>;

	CryFixedArray<CParameterGameEffect::SSaturationData,4> m_saturationExecutionData;

	CParameterGameEffect();
	virtual void SetActive(bool isActive);
	virtual void Update(float frameTime);
	virtual const char* GetName() const;
	void Reset() { FReset(this); }
	void SetSaturationAmount(const float fAmount, const CParameterGameEffect::ESaturationEffectUsage usage) { FSetSaturationAmount(this, fAmount, usage); }

#if 0
	bool UpdateSaturation(float _arg0_);
	void ResetSaturation();
#endif

	static inline auto FCParameterGameEffectOv2 = PreyFunction<void(CParameterGameEffect* const _this)>(0x17DCAC0);
	static inline auto FSetActive = PreyFunction<void(CParameterGameEffect* const _this, bool isActive)>(0x17DCBD0);
	static inline auto FUpdate = PreyFunction<void(CParameterGameEffect* const _this, float frameTime)>(0x17DCCD0);
	static inline auto FGetName = PreyFunction<const char* (const CParameterGameEffect* const _this)>(0x17DCBA0);
	static inline auto FReset = PreyFunction<void(CParameterGameEffect* const _this)>(0x17DCBB0);
	static inline auto FSetSaturationAmount = PreyFunction<void(CParameterGameEffect* const _this, const float fAmount, const CParameterGameEffect::ESaturationEffectUsage usage)>(0x17DCC80);
};
#endif // MOONCRASH
