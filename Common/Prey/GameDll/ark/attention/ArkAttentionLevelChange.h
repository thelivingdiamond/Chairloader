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

