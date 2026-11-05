// Header file automatically created from a PDB.
#pragma once

// AIFlowBaseNode
// Header:  CryEngine/cryaisystem/flownodes/AIFlowBaseNode.h
// Include: Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h
struct AIFlowBaseNode
{ // Size=1 (0x1)
	static void RegisterFactory() { FRegisterFactory(); }

#ifndef MOONCRASH
	static inline auto FRegisterFactory = PreyFunction<void()>(0x6283F0);
#else
	static inline auto FRegisterFactory = PreyFunction<void()>(0x643F40);
#endif
};

