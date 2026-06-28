// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EGameMechanismEvent;
struct SGameMechanismEventData;

// CGameMechanismBase
// Header:  Prey/GameDll/gamemechanismmanager/GameMechanismBase.h
class CGameMechanismBase
{ // Size=24 (0x18)
public:
	// CGameMechanismBase::SLinkedListPointers
	// Header:  Prey/GameDll/gamemechanismmanager/GameMechanismBase.h
	struct SLinkedListPointers
	{ // Size=16 (0x10)
		CGameMechanismBase* m_nextMechanism;
		CGameMechanismBase* m_prevMechanism;
	};

	CGameMechanismBase::SLinkedListPointers m_linkedListPointers;

	CGameMechanismBase(const char* className);
	virtual ~CGameMechanismBase();
	virtual void Update(float inDt) = 0;
	virtual void Inform(EGameMechanismEvent gmEvent, const SGameMechanismEventData* data);

#if 0
	CGameMechanismBase::SLinkedListPointers* GetLinkedListPointers();
	const char* GetName();
	const CGameMechanismBase* GetConstSelf() const;
#endif

	static inline auto FCGameMechanismBaseOv1 = PreyFunction<void(CGameMechanismBase* const _this, const char* className)>(0x1834D80);
	static inline auto FBitNotCGameMechanismBase = PreyFunction<void(CGameMechanismBase* const _this)>(0x1834DC0);
	static inline auto FInform = PreyFunction<void(CGameMechanismBase* const _this, EGameMechanismEvent gmEvent, const SGameMechanismEventData* data)>(0x1333E90);
};
#endif // MOONCRASH
