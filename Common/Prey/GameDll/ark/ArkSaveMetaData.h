// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ArkSaveMetaData.h
class ArkSaveMetaData // Id=801666C Size=24
{
public:
	string m_location;
	string m_screenshot;
	int m_playTime;
	EPlayerSex m_gender;
	
#if 0
	int GetPlayTimeInMinutes() const;
	string const &GetLocation() const;
	EPlayerSex GetGender() const;
	string const &GetScreenshotPath() const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSaveMetaData
// Header:  Prey/GameDll/ark/ArkSaveMetaData.h
class ArkSaveMetaData
{ // Size=24 (0x18)
public:
	string m_location;
	string m_screenshot;
	int m_playTime;
	EPlayerSex m_gender;

#if 0
	ArkSaveMetaData(const char* const _arg0_, const char* const _arg1_, const int _arg2_, const EPlayerSex _arg3_);
	int GetPlayTimeInMinutes() const;
	const string& GetLocation() const;
	EPlayerSex GetGender() const;
	const string& GetScreenshotPath() const;
#endif
};
#endif // !MOONCRASH
