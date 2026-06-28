// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/GameDll/ark/ArkAudioEnvironment.h
class ArkAudioEnvironment // Id=8005A06 Size=4
{
public:
	unsigned m_environmentId;
	
#if 0
	bool Load(const char *arg0);
	void SetValue(float arg0, IEntity *arg1);
	bool IsValid() const;
	void Invalidate();
	static void ClearEnvironment(IEntity *arg0);
	unsigned GetId() const;
	void SetName(const char *arg0);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkAudioEnvironment
// Header:  Prey/GameDll/ark/ArkAudioEnvironment.h
class ArkAudioEnvironment
{ // Size=4 (0x4)
public:
	unsigned m_environmentId;

#if 0
	ArkAudioEnvironment();
	ArkAudioEnvironment(const char* _arg0_);
	ArkAudioEnvironment(unsigned _arg0_);
	bool Load(const char* _arg0_);
	void SetValue(float _arg0_, IEntity* _arg1_);
	bool IsValid() const;
	void Invalidate();
	static void ClearEnvironment(IEntity* _arg0_);
	unsigned GetId() const;
	void SetName(const char* _arg0_);
#endif
};
#endif // !MOONCRASH
