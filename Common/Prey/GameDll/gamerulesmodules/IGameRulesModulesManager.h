// Header file automatically created from a PDB.
#pragma once

class IGameRulesDamageHandlingModule;
class IGameRulesSpawningModule;
class IGameRulesStateModule;

// IGameRulesModulesManager
// Header:  _unknown/IGameRulesModulesManager.h
class IGameRulesModulesManager
{ // Size=8 (0x8)
public:
	virtual ~IGameRulesModulesManager();
	virtual void RegisterFactory(const char* moduleName, IGameRulesStateModule* (*func)(), bool isAI) = 0;
	virtual void RegisterFactory(const char* moduleName, IGameRulesSpawningModule* (*func)(), bool isAI) = 0;
	virtual void RegisterFactory(const char* moduleName, IGameRulesDamageHandlingModule* (*func)(), bool isAI) = 0;
	virtual void Init() = 0;
	virtual int GetRulesCount() = 0;
	virtual const char* GetRules(int index) = 0;
};

