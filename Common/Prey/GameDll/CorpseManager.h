// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CryFixedArray.h>
#include <_unknown/IGameRulesRoundsListener.h>

struct IPhysicalEntity;

// CCorpseManager
// Header:  Prey/GameDll/CorpseManager.h
class CCorpseManager : private IGameRulesRoundsListener
{ // Size=696 (0x2B8)
public:
	enum ECorpseFlags
	{
		eCF_NeverSleep = 1,
	};

	// CCorpseManager::SCorpseInfo
	// Header:  Prey/GameDll/CorpseManager.h
	struct SCorpseInfo
	{ // Size=28 (0x1C)
		Vec3 corpsePos;
		float age;
		float awakeTime;
		unsigned corpseId;
		uint8_t flags;

	#if 0
		SCorpseInfo(unsigned _arg0_, Vec3 _arg1_);
	#endif
	};

	CryFixedArray<CCorpseManager::SCorpseInfo,24> m_activeCorpses;

	virtual ~CCorpseManager();
	void RegisterCorpse(unsigned corpseId, Vec3 corpsePos) { FRegisterCorpse(this, corpseId, corpsePos); }
	void RemoveACorpse() { FRemoveACorpse(this); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	virtual void OnRoundStart();
	virtual void OnRoundEnd();
	virtual void OnSuddenDeath();
	virtual void ClRoundsNetSerializeReadState(int _arg0_, int _arg1_);
	virtual void OnRoundAboutToStart();
	void UpdateCorpses(float frameTime) { FUpdateCorpses(this, frameTime); }

#if 0
	CCorpseManager();
	void KeepAwake(const unsigned _arg0_, IPhysicalEntity* _arg1_);
	void ClearCorpses();
	void OnRemovedCorpse(const unsigned _arg0_);
#endif

	static inline auto FRegisterCorpse = PreyFunction<void(CCorpseManager* const _this, unsigned corpseId, Vec3 corpsePos)>(0x17BDB40);
	static inline auto FRemoveACorpse = PreyFunction<void(CCorpseManager* const _this)>(0x17BDC60);
	static inline auto FUpdate = PreyFunction<void(CCorpseManager* const _this, float frameTime)>(0x17BE030);
	static inline auto FUpdateCorpses = PreyFunction<void(CCorpseManager* const _this, float frameTime)>(0x17BE180);
};
#endif // MOONCRASH
