// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CMovementTransitions;
class ICrySizer;
struct IEntity;
struct IEntityClass;
class SmartScriptTable;

// CMovementTransitionsSystem
// Header:  Prey/GameDll/MovementTransitionsSystem.h
class CMovementTransitionsSystem
{ // Size=24 (0x18)
public:
	using MovementTransitionsVector = std::vector<CMovementTransitions*>;

	std::vector<CMovementTransitions*> m_entityTransitions;

	CMovementTransitionsSystem();
	~CMovementTransitionsSystem();
	CMovementTransitions* const GetMovementTransitions(IEntity* pEntity) { return FGetMovementTransitionsOv1(this, pEntity); }
	CMovementTransitions* const GetMovementTransitions(IEntityClass* pEntityClass, SmartScriptTable pEntityScript) { return FGetMovementTransitionsOv0(this, pEntityClass, pEntityScript); }
	void GetMemoryUsage(ICrySizer* s) const { FGetMemoryUsage(this, s); }
	void Reload() const { FReload(this); }
	void Flush() { FFlush(this); }

#if 0
	CMovementTransitionsSystem(const CMovementTransitionsSystem& _arg0_);
	CMovementTransitionsSystem& operator=(const CMovementTransitionsSystem& _arg0_);
#endif

	static inline auto FCMovementTransitionsSystemOv1 = PreyFunction<void(CMovementTransitionsSystem* const _this)>(0x1F4DF0);
	static inline auto FBitNotCMovementTransitionsSystem = PreyFunction<void(CMovementTransitionsSystem* const _this)>(0x189B9D0);
	static inline auto FGetMovementTransitionsOv1 = PreyFunction<CMovementTransitions* const (CMovementTransitionsSystem* const _this, IEntity* pEntity)>(0x189BB90);
	static inline auto FGetMovementTransitionsOv0 = PreyFunction<CMovementTransitions* const (CMovementTransitionsSystem* const _this, IEntityClass* pEntityClass, SmartScriptTable pEntityScript)>(0x189BC10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CMovementTransitionsSystem* const _this, ICrySizer* s)>(0x189BB00);
	static inline auto FReload = PreyFunction<void(const CMovementTransitionsSystem* const _this)>(0x189BF10);
	static inline auto FFlush = PreyFunction<void(CMovementTransitionsSystem* const _this)>(0x189BA60);
};
#endif // MOONCRASH
