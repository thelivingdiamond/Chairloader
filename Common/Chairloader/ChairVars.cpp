//
// Created by theli on 1/6/2023.
//

#include "ChairVars.h"
#include "ModSDK/ChairGlobalModName.h"

ICVar *Internal::ChairRegisterString(const char *sName, const char *sValue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc) {
    ICVar* cv = gEnv->pConsole->RegisterString(sName, sValue, nFlags, help, pChangeFunc);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegisterInt(const char *sName, int iValue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc) {
    ICVar* cv = gEnv->pConsole->RegisterInt(sName, iValue, nFlags, help, pChangeFunc);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegisterInt64(const char *sName, int64 iValue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc) {
    ICVar* cv = gEnv->pConsole->RegisterInt64(sName, iValue, nFlags, help, pChangeFunc);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegisterFloat(const char *sName, float fValue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc) {
    ICVar* cv = gEnv->pConsole->RegisterFloat(sName, fValue, nFlags, help, pChangeFunc);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegister(const char *name, float *src, float defaultvalue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc, bool allowModify) {
    ICVar* cv = gEnv->pConsole->Register(name, src, defaultvalue, nFlags, help, pChangeFunc, allowModify);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegister(const char *name, int *src, int defaultvalue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc, bool allowModify) {
    ICVar* cv = gEnv->pConsole->Register(name, src, defaultvalue, nFlags, help, pChangeFunc, allowModify);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}

ICVar *Internal::ChairRegister(const char *name, const char **src, const char *defaultvalue, int nFlags, const char *help, ConsoleVarFunc pChangeFunc, bool allowModify) {
    ICVar* cv = gEnv->pConsole->Register(name, src, defaultvalue, nFlags, help, pChangeFunc, allowModify);
    gCL->cl->RegisterCVar(cv, ChairGetGlobalModName());
    return cv;
}
