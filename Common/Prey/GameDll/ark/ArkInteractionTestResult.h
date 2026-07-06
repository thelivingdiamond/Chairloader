// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ArkInteractionTestResult.h
struct ArkInteractionTestResult // Id=8014067 Size=40
{
	bool m_bPassedTest;
	bool m_bHideLine;
	string m_actionVerb;
	wstring m_localizedActionVerb;
	string m_requirementText;
	wstring m_localizedRequirementText;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>

// ArkInteractionTestResult
// Header:  Prey/GameDll/ark/ArkInteractionTestResult.h
struct ArkInteractionTestResult
{ // Size=40 (0x28)
	bool m_bPassedTest;
	bool m_bHideLine;
	string m_actionVerb;
	wstring m_localizedActionVerb;
	string m_requirementText;
	wstring m_localizedRequirementText;

#if 0
	ArkInteractionTestResult();
#endif
};
#endif // !MOONCRASH
