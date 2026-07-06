// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>

class IArkSpeaker;

// Header: Override
// Prey/GameDll/ark/iface/IArkSpeakerExtension.h
class IArkSpeakerExtension : public IGameObjectExtension // Id=800D7C6 Size=64
{
public:
	virtual IArkSpeaker *GetSpeaker() = 0;
	virtual ~IArkSpeakerExtension();
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameObject.h>

class IArkSpeaker;

// IArkSpeakerExtension
// Header:  Prey/GameDll/ark/iface/IArkSpeakerExtension.h
class IArkSpeakerExtension : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	virtual IArkSpeaker* GetSpeaker() = 0;
};
#endif // !MOONCRASH
