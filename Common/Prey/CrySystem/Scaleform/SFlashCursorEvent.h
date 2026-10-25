// Header file automatically created from a PDB.
#pragma once

// SFlashCursorEvent
// Header:  _unknown/SFlashCursorEvent.h
// Include: Prey/CrySystem/Scaleform/IFlashPlayer.h
struct SFlashCursorEvent
{ // Size=20 (0x14)
	enum ECursorState
	{
		eCursorMoved = 0,
		eCursorPressed = 1,
		eCursorReleased = 2,
		eWheel = 3,
	};

	SFlashCursorEvent::ECursorState m_state;
	int m_cursorX;
	int m_cursorY;
	int m_button;
	float m_wheelScrollVal;

#if 0
	SFlashCursorEvent(SFlashCursorEvent::ECursorState _arg0_, int _arg1_, int _arg2_, int _arg3_, float _arg4_);
#endif
};

