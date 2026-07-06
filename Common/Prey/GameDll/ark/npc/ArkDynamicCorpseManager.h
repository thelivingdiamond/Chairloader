// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkTurret;
class CArkAlienGiblet;

// ArkDynamicCorpseManager
// Header:  Prey/GameDll/ark/npc/ArkDynamicCorpseManager.h
class ArkDynamicCorpseManager
{ // Size=96 (0x60)
public:
	uint64_t m_alienGibletCount;
	uint64_t m_operatorCorpseCount;
	uint64_t m_turretCorpseCount;
	static inline auto s_maxAlienGiblets = PreyGlobal<uint64_t>(0x23E27E0);
	static inline auto s_maxOperatorCorpses = PreyGlobal<uint64_t>(0x23E27E8);
	static inline auto s_maxTurretCorpses = PreyGlobal<uint64_t>(0x23E27F0);
	std::vector<CArkAlienGiblet*> m_alienGibletVec;
	std::vector<unsigned int> m_operatorCorpseVec;
	std::vector<ArkTurret*> m_turretCorpseVec;

	ArkDynamicCorpseManager();
	void OnCreateAlienGiblet(CArkAlienGiblet* _giblet) { FOnCreateAlienGiblet(this, _giblet); }
	void OnCreateOperatorCorpse(unsigned _operatorId) { FOnCreateOperatorCorpse(this, _operatorId); }
	void OnReleaseAlienGiblet(CArkAlienGiblet* _pGiblet) { FOnReleaseAlienGiblet(this, _pGiblet); }
	void OnReleaseOperatorCorpse(unsigned _operatorId) { FOnReleaseOperatorCorpse(this, _operatorId); }
	bool DoesAlienHaveGiblets(unsigned _alienId) const { return FDoesAlienHaveGiblets(this, _alienId); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void OnLoadGame() { FOnLoadGame(this); }
	void Shutdown() { FShutdown(this); }
	void Update() { FUpdate(this); }
	bool IsCritical(unsigned _entity) const { return FIsCriticalOv0(this, _entity); }
	void ProcessCorpses() { FProcessCorpses(this); }

#if 0
	ArkDynamicCorpseManager(const ArkDynamicCorpseManager& _arg0_);
	void OnCreateTurretCorpse(ArkTurret* _arg0_);
	void OnReleaseTurretCorpse(ArkTurret* _arg0_);
	void Reset();
	const std::vector<CArkAlienGiblet*>& GetAlienGiblets() const;
	ArkDynamicCorpseManager& operator=(const ArkDynamicCorpseManager& _arg0_);
	bool IsCritical(CArkAlienGiblet* _arg0_) const;
	bool IsVisibleToPlayer(Vec3 _arg0_) const;
	void LoadConfig();
	void ReduceAlienGiblets();
	void ReduceOperatorCorpses();
	void ReduceTurretCorpses();
#endif

	static inline auto FArkDynamicCorpseManagerOv1 = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127E830);
	static inline auto FOnCreateAlienGiblet = PreyFunction<void(ArkDynamicCorpseManager* const _this, CArkAlienGiblet* _giblet)>(0x127EC80);
	static inline auto FOnCreateOperatorCorpse = PreyFunction<void(ArkDynamicCorpseManager* const _this, unsigned _operatorId)>(0x127ECB0);
	static inline auto FOnReleaseAlienGiblet = PreyFunction<void(ArkDynamicCorpseManager* const _this, CArkAlienGiblet* _pGiblet)>(0x127ED10);
	static inline auto FOnReleaseOperatorCorpse = PreyFunction<void(ArkDynamicCorpseManager* const _this, unsigned _operatorId)>(0x127ED60);
	static inline auto FDoesAlienHaveGiblets = PreyFunction<bool(const ArkDynamicCorpseManager* const _this, unsigned _alienId)>(0x127E9F0);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127ECE0);
	static inline auto FOnLoadGame = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127ECE0);
	static inline auto FShutdown = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127ECE0);
	static inline auto FUpdate = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127F200);
	static inline auto FIsCriticalOv0 = PreyFunction<bool(const ArkDynamicCorpseManager* const _this, unsigned _entity)>(0x127EA20);
	static inline auto FProcessCorpses = PreyFunction<void(ArkDynamicCorpseManager* const _this)>(0x127EDB0);
};
#endif // MOONCRASH
