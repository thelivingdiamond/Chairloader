// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/flowsystem/flowsystemcvars.h>

// Header: FromCpp
// CryEngine/cryaction/flowsystem/flowsystemcvars.h
struct CFlowSystemCVars // Id=8004674 Size=32
{
	int m_enableUpdates;
	int m_profile;
	int m_abortOnLoadError;
	int m_inspectorLog;
	int m_noDebugText;
	int m_noConsoleFlowNodes;
	int m_enableFlowgraphNodeDebugging;
	int m_debugNextStep;
	static inline auto s_pThis = PreyGlobal<CFlowSystemCVars *>(0x24808F0);
	
	CFlowSystemCVars();
	~CFlowSystemCVars();
	
#if 0
	static CFlowSystemCVars &Get();
#endif
	
	static inline auto FBitNotCFlowSystemCVars = PreyFunction<void(CFlowSystemCVars *const _this)>(0x41D590);
};

