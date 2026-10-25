// Header file automatically created from a PDB.
#pragma once

// IGameRulesRoundsListener
// Header:  _unknown/IGameRulesRoundsListener.h
class IGameRulesRoundsListener
{ // Size=8 (0x8)
public:
	virtual ~IGameRulesRoundsListener();
	virtual void OnRoundStart() = 0;
	virtual void OnRoundEnd() = 0;
	virtual void OnSuddenDeath() = 0;
	virtual void ClRoundsNetSerializeReadState(int _arg0_, int _arg1_) = 0;
	virtual void OnRoundAboutToStart() = 0;
};

