// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <_unknown/IGameRulesModulesManager.h>

class IGameRulesDamageHandlingModule;
class IGameRulesSpawningModule;
class IGameRulesStateModule;

// CGameRulesModulesManager
// Header:  Prey/GameDll/gamerulesmodules/GameRulesModulesManager.h
class CGameRulesModulesManager : public IGameRulesModulesManager
{ // Size=72 (0x48)
public:
	// CGameRulesModulesManager::SGameRulesData
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesModulesManager.h
	struct SGameRulesData
	{ // Size=184 (0xB8)
		CryFixedStringT<64> m_rulesXMLPath;
		CryFixedStringT<64> m_defaultHud;
		bool m_bIsTeamGame;
		bool m_bUseLobbyTeamBalancing;
		bool m_bUsePlayerTeamVisualization;

	#if 0
		SGameRulesData();
	#endif
	};

	using TFixedString_32 = CryFixedStringT<32>;
	using TFixedString_64 = CryFixedStringT<64>;
	using TModuleClassMap_State = std::map<CryFixedStringT<32>,IGameRulesStateModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesStateModule * (__cdecl*)(void)> > >;
	using TModuleClassMap_Spawning = std::map<CryFixedStringT<32>,IGameRulesSpawningModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesSpawningModule * (__cdecl*)(void)> > >;
	using TModuleClassMap_DamageHandling = std::map<CryFixedStringT<32>,IGameRulesDamageHandlingModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesDamageHandlingModule * (__cdecl*)(void)> > >;
	using TDataMap = std::map<CryFixedStringT<32>, CGameRulesModulesManager::SGameRulesData>;

	static inline auto s_pInstance = PreyGlobal<CGameRulesModulesManager*>(0x2D8DCB8);
	std::map<CryFixedStringT<32>,IGameRulesStateModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesStateModule * (__cdecl*)(void)> > > m_StateClasses;
	std::map<CryFixedStringT<32>,IGameRulesSpawningModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesSpawningModule * (__cdecl*)(void)> > > m_SpawningClasses;
	std::map<CryFixedStringT<32>,IGameRulesDamageHandlingModule * (__cdecl*)(void),std::less<CryFixedStringT<32> >,std::allocator<std::pair<CryFixedStringT<32> const ,IGameRulesDamageHandlingModule * (__cdecl*)(void)> > > m_DamageHandlingClasses;
	std::map<CryFixedStringT<32>, CGameRulesModulesManager::SGameRulesData> m_rulesData;

	virtual void RegisterFactory(const char* moduleName, IGameRulesStateModule* (*func)(), bool isAI);
	virtual void RegisterFactory(const char* moduleName, IGameRulesSpawningModule* (*func)(), bool isAI);
	virtual void RegisterFactory(const char* moduleName, IGameRulesDamageHandlingModule* (*func)(), bool isAI);
	IGameRulesStateModule* CreateStateModule(const char* moduleName) { return FCreateStateModule(this, moduleName); }
	IGameRulesSpawningModule* CreateSpawningModule(const char* moduleName) { return FCreateSpawningModule(this, moduleName); }
	IGameRulesDamageHandlingModule* CreateDamageHandlingModule(const char* moduleName) { return FCreateDamageHandlingModule(this, moduleName); }
	static CGameRulesModulesManager* GetInstance(bool create) { return FGetInstance(create); }
	virtual ~CGameRulesModulesManager();
	virtual void Init();
	const char* GetXmlPath(const char* gameRulesName) const { return FGetXmlPath(this, gameRulesName); }
	virtual int GetRulesCount();
	virtual const char* GetRules(int index);
	bool IsTeamGame(const char* gameRulesName) const { return FIsTeamGame(this, gameRulesName); }

#if 0
	void RegisterStateModule(const char* _arg0_, IGameRulesStateModule* (*_arg1_)(), bool _arg2_);
	void RegisterSpawningModule(const char* _arg0_, IGameRulesSpawningModule* (*_arg1_)(), bool _arg2_);
	void RegisterDamageHandlingModule(const char* _arg0_, IGameRulesDamageHandlingModule* (*_arg1_)(), bool _arg2_);
	CGameRulesModulesManager();
	const char* GetDefaultHud(const char* _arg0_) const;
	bool UsesLobbyTeamBalancing(const char* _arg0_) const;
	bool UsesPlayerTeamVisualization(const char* _arg0_) const;
	bool IsValidGameRules(const char* _arg0_) const;
#endif

	static inline auto FRegisterFactoryOv2 = PreyFunction<void(CGameRulesModulesManager* const _this, const char* moduleName, IGameRulesStateModule* (*func)(), bool isAI)>(0x1859830);
	static inline auto FRegisterFactoryOv1 = PreyFunction<void(CGameRulesModulesManager* const _this, const char* moduleName, IGameRulesSpawningModule* (*func)(), bool isAI)>(0x18597B0);
	static inline auto FRegisterFactoryOv0 = PreyFunction<void(CGameRulesModulesManager* const _this, const char* moduleName, IGameRulesDamageHandlingModule* (*func)(), bool isAI)>(0x1859730);
	static inline auto FCreateStateModule = PreyFunction<IGameRulesStateModule* (CGameRulesModulesManager* const _this, const char* moduleName)>(0x18588F0);
	static inline auto FCreateSpawningModule = PreyFunction<IGameRulesSpawningModule* (CGameRulesModulesManager* const _this, const char* moduleName)>(0x1858750);
	static inline auto FCreateDamageHandlingModule = PreyFunction<IGameRulesDamageHandlingModule* (CGameRulesModulesManager* const _this, const char* moduleName)>(0x18585B0);
	static inline auto FGetInstance = PreyFunction<CGameRulesModulesManager* (bool create)>(0x1858A90);
	static inline auto FInit = PreyFunction<void(CGameRulesModulesManager* const _this)>(0x1858DE0);
	static inline auto FGetXmlPath = PreyFunction<const char* (const CGameRulesModulesManager* const _this, const char* gameRulesName)>(0x1858C50);
	static inline auto FGetRulesCount = PreyFunction<int(CGameRulesModulesManager* const _this)>(0x3E9530);
	static inline auto FGetRules = PreyFunction<const char* (CGameRulesModulesManager* const _this, int index)>(0x1858B70);
	static inline auto FIsTeamGame = PreyFunction<bool(const CGameRulesModulesManager* const _this, const char* gameRulesName)>(0x1859590);
};
#endif // MOONCRASH
