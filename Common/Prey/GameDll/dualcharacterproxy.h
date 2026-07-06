// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IAnimationGraph.h>

class CAnimation;
struct CryCharAnimationParams;
struct IAnimationSet;
struct IEntity;

// CAnimationProxyDualCharacterBase
// Header:  Prey/GameDll/dualcharacterproxy.h
class CAnimationProxyDualCharacterBase : public CAnimationPlayerProxy
{ // Size=24 (0x18)
public:
	// CAnimationProxyDualCharacterBase::SPlayParams
	// Header:  Prey/GameDll/dualcharacterproxy.h
	struct SPlayParams
	{ // Size=16 (0x10)
		int animIDFP;
		int animIDTP;
		float speedFP;
		float speedTP;
	};

	using NameHashMap = std::map<unsigned int, unsigned int>;

	static inline auto s_animCrCHashMap = PreyGlobal<std::map<unsigned int, unsigned int>>(0x2D82328);
	int m_characterMain;
	int m_characterShadow;
	bool m_firstPersonMode;

	static void Load1P3PPairFile() { FLoad1P3PPairFile(); }
	static void ReleaseBuffers() { FReleaseBuffers(); }
	virtual bool StartAnimation(IEntity* entity, const char* szAnimName, const CryCharAnimationParams& Params, float speedMultiplier);
	virtual void OnReload();
	void GetPlayParams(int animID, float speedMul, IAnimationSet* animSet, CAnimationProxyDualCharacterBase::SPlayParams& params) { FGetPlayParams(this, animID, speedMul, animSet, params); }

#if 0
	CAnimationProxyDualCharacterBase();
	static int Get3PAnimID(IAnimationSet* _arg0_, int _arg1_);
#endif

	static inline auto FLoad1P3PPairFile = PreyFunction<void()>(0x17D9AD0);
	static inline auto FReleaseBuffers = PreyFunction<void()>(0x17D9CC0);
	static inline auto FStartAnimation = PreyFunction<bool(CAnimationProxyDualCharacterBase* const _this, IEntity* entity, const char* szAnimName, const CryCharAnimationParams& Params, float speedMultiplier)>(0x17D9E80);
	static inline auto FGetPlayParams = PreyFunction<void(CAnimationProxyDualCharacterBase* const _this, int animID, float speedMul, IAnimationSet* animSet, CAnimationProxyDualCharacterBase::SPlayParams& params)>(0x17D99E0);
};

// CAnimationProxyDualCharacter
// Header:  Prey/GameDll/dualcharacterproxy.h
class CAnimationProxyDualCharacter : public CAnimationProxyDualCharacterBase
{ // Size=32 (0x20)
public:
	bool m_killMixInFirst;
	bool m_allowsMix;

	CAnimationProxyDualCharacter();
	virtual bool StartAnimationById(IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier);
	virtual bool StopAnimationInLayer(IEntity* entity, int nLayer, float BlendOutTime);
	virtual bool RemoveAnimationInLayer(IEntity* entity, int nLayer, unsigned token);
	virtual const CAnimation* GetAnimation(IEntity* entity, int layer);
	virtual CAnimation* GetAnimation(IEntity* entity, int layer, unsigned token);
	virtual void OnReload();

#if 0
	void SetFirstPerson(bool _arg0_);
	void SetKillMixInFirst(bool _arg0_);
	void SetCanMixUpperBody(bool _arg0_);
	bool CanMixUpperBody() const;
#endif

	static inline auto FCAnimationProxyDualCharacterOv2 = PreyFunction<void(CAnimationProxyDualCharacter* const _this)>(0x17D9800);
	static inline auto FStartAnimationById = PreyFunction<bool(CAnimationProxyDualCharacter* const _this, IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier)>(0x17D9F00);
	static inline auto FStopAnimationInLayer = PreyFunction<bool(CAnimationProxyDualCharacter* const _this, IEntity* entity, int nLayer, float BlendOutTime)>(0x17DA290);
	static inline auto FRemoveAnimationInLayer = PreyFunction<bool(CAnimationProxyDualCharacter* const _this, IEntity* entity, int nLayer, unsigned token)>(0x17D9D40);
	static inline auto FGetAnimationOv1 = PreyFunction<const CAnimation* (CAnimationProxyDualCharacter* const _this, IEntity* entity, int layer)>(0x17D9940);
	static inline auto FGetAnimationOv0 = PreyFunction<CAnimation* (CAnimationProxyDualCharacter* const _this, IEntity* entity, int layer, unsigned token)>(0x17D9890);
	static inline auto FOnReload = PreyFunction<void(CAnimationProxyDualCharacter* const _this)>(0x17D9C80);
};

// CAnimationProxyDualCharacterUpper
// Header:  Prey/GameDll/dualcharacterproxy.h
class CAnimationProxyDualCharacterUpper : public CAnimationProxyDualCharacterBase
{ // Size=32 (0x20)
public:
	bool m_killMixInFirst;

	CAnimationProxyDualCharacterUpper();
	virtual bool StartAnimationById(IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier);
	virtual bool StopAnimationInLayer(IEntity* entity, int nLayer, float BlendOutTime);
	virtual bool RemoveAnimationInLayer(IEntity* entity, int nLayer, unsigned token);
	virtual void OnReload();

#if 0
	void SetFirstPerson(bool _arg0_);
#endif

	static inline auto FCAnimationProxyDualCharacterUpperOv2 = PreyFunction<void(CAnimationProxyDualCharacterUpper* const _this)>(0x17D9830);
	static inline auto FStartAnimationById = PreyFunction<bool(CAnimationProxyDualCharacterUpper* const _this, IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier)>(0x17DA0E0);
	static inline auto FStopAnimationInLayer = PreyFunction<bool(CAnimationProxyDualCharacterUpper* const _this, IEntity* entity, int nLayer, float BlendOutTime)>(0x17DA340);
	static inline auto FRemoveAnimationInLayer = PreyFunction<bool(CAnimationProxyDualCharacterUpper* const _this, IEntity* entity, int nLayer, unsigned token)>(0x17D9D40);
	static inline auto FOnReload = PreyFunction<void(CAnimationProxyDualCharacterUpper* const _this)>(0x17D9CA0);
};
#endif // MOONCRASH
