// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CGameMechanismBase;
enum class EGameMechanismEvent;
struct SGameMechanismEventData;

// CGameMechanismManager
// Header:  Prey/GameDll/gamemechanismmanager/GameMechanismManager.h
class CGameMechanismManager
{ // Size=8 (0x8)
public:
	static inline auto s_instance = PreyGlobal<CGameMechanismManager*>(0x2D8DA80);
	CGameMechanismBase* m_firstMechanism;

	CGameMechanismManager();
	~CGameMechanismManager();
	void Update(float dt) { FUpdate(this, dt); }
	void Inform(EGameMechanismEvent gmEvent, const SGameMechanismEventData* data) { FInform(this, gmEvent, data); }
	void RegisterMechanism(CGameMechanismBase* mechanism) { FRegisterMechanism(this, mechanism); }
	void UnregisterMechanism(CGameMechanismBase* removeThis) { FUnregisterMechanism(this, removeThis); }

#if 0
	static CGameMechanismManager* GetInstance();
#endif

	static inline auto FCGameMechanismManager = PreyFunction<void(CGameMechanismManager* const _this)>(0x1834E30);
	static inline auto FBitNotCGameMechanismManager = PreyFunction<void(CGameMechanismManager* const _this)>(0x1834E50);
	static inline auto FUpdate = PreyFunction<void(CGameMechanismManager* const _this, float dt)>(0x1834F70);
	static inline auto FInform = PreyFunction<void(CGameMechanismManager* const _this, EGameMechanismEvent gmEvent, const SGameMechanismEventData* data)>(0x1834E90);
	static inline auto FRegisterMechanism = PreyFunction<void(CGameMechanismManager* const _this, CGameMechanismBase* mechanism)>(0x1834F00);
	static inline auto FUnregisterMechanism = PreyFunction<void(CGameMechanismManager* const _this, CGameMechanismBase* removeThis)>(0x1834F20);
};
#endif // MOONCRASH
