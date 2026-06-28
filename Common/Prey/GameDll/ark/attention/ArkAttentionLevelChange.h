// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: MadeUp
// _unknown/ArkAttentionLevelChange.h
struct ArkAttentionLevelChange // Id=801430D Size=28
{
	unsigned m_attentiveSubjectEntityId;
	unsigned m_attentionObjectEntityId;
	EArkAttentionLevel m_previousLevel;
	EArkAttentionLevel m_currentLevel;
	EArkAttentionChangeReason m_reason;
	bool m_bChangeDueToDisposition;
	bool m_bSurprising;
	bool m_bSwitchedTarget;
	unsigned m_oldAttentionObjectEntityId;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkAttentionLevelChange
// Header:  Prey/GameDll/ark/attention/ArkAttentionLevelChange.h
struct ArkAttentionLevelChange
{ // Size=28 (0x1C)
	unsigned m_attentiveSubjectEntityId;
	unsigned m_attentionObjectEntityId;
	EArkAttentionLevel m_previousLevel;
	EArkAttentionLevel m_currentLevel;
	EArkAttentionChangeReason m_reason;
	bool m_bChangeDueToDisposition;
	bool m_bSurprising;
	bool m_bSwitchedTarget;
	unsigned m_oldAttentionObjectEntityId;

#if 0
	ArkAttentionLevelChange(unsigned _arg0_, unsigned _arg1_, EArkAttentionLevel _arg2_, EArkAttentionLevel _arg3_, EArkAttentionChangeReason _arg4_, bool _arg5_, bool _arg6_, bool _arg7_, unsigned _arg8_);
#endif
};
#endif // !MOONCRASH
