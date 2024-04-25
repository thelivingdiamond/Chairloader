#include <Prey/CryScriptSystem/ScriptSystem.h>
#include <Chairloader/IChairloaderDll.h>
#include "LuaDbgRes.h"

namespace
{

PreyGlobal<void*> gDLLHandle(0x29773B0); // gDLLHandle in CryScriptSystem.dll

} // namespace

void LuaDbgRes::InitSystem()
{
    // CLUADbg::CLUADbg uses gDLLHandle value for resources
    *gDLLHandle = gChair->GetDllHandle();
}
