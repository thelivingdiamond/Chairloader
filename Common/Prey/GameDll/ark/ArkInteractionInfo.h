// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// `
struct ArkInteractionInfo // Id=8014062 Size=24
{
	EArkInteractionType m_interactionType;
	string m_displayText;
	bool m_bDisplayTextSpecified;
	float m_holdDuration;
	
#if 0
	void Clear();
	bool operator!=(ArkInteractionInfo const &arg0) const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkInteractionInfo
// Header:  Prey/GameDll/ark/ArkInteractionInfo.h
struct ArkInteractionInfo
{ // Size=24 (0x18)
	EArkInteractionType m_interactionType;
	string m_displayText;
	bool m_bDisplayTextSpecified;
	float m_holdDuration;

#if 0
	ArkInteractionInfo();
	void Clear();
	bool operator!=(const ArkInteractionInfo& _arg0_) const;
#endif
};
#endif // !MOONCRASH
