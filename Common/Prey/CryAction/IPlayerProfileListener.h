// Header file automatically created from a PDB.
#pragma once

struct IPlayerProfile;

// IPlayerProfileListener
// Header:  _unknown/IPlayerProfileListener.h
// Include: Prey/CryAction/IPlayerProfiles.h
class IPlayerProfileListener
{ // Size=8 (0x8)
public:
	virtual ~IPlayerProfileListener();
	virtual void SaveToProfile(IPlayerProfile* pProfile, bool online, unsigned reason) = 0;
	virtual void LoadFromProfile(IPlayerProfile* pProfile, bool online, unsigned reason) = 0;
};

