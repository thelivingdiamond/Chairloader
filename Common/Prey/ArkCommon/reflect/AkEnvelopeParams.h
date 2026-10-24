// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflect/AkModulatorParams.h>

class CAkModulatorCtx;

// AkEnvelopeParams
// Header:  _unknown/AkEnvelopeParams.h
struct AkEnvelopeParams : public AkModulatorParams
{ // Size=48 (0x30)
	float m_fStartValue;
	unsigned long m_uAttack;
	float m_fCurve;
	float m_fSustain;
	unsigned long m_uDecay;
	unsigned long m_uRelease;

#if 0
	void Fill(CAkModulatorCtx* _arg0_);
#endif
};

