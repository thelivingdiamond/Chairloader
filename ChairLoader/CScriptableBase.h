#pragma once
#include "Prey/CrySystem/ISystem.h"
class CScriptableBase
{
public:
    virtual ~CScriptableBase() = 0;
    virtual void Init(IScriptSystem*, ISystem*, int) = 0;
    virtual void GetMemoryStatistics(ICrySizer*) = 0;


    char m_sGlobalName[64];
    IScriptTable* m_pMethodsTable;
    IScriptSystem* m_pSS;
    int m_nParamIdOffset;
};