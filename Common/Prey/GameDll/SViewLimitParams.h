// Header file automatically created from a PDB.
#pragma once

// SViewLimitParams
// Header:  _unknown/SViewLimitParams.h
struct SViewLimitParams
{ // Size=32 (0x20)
	enum EViewLimitState
	{
		eVLS_None = 0,
		eVLS_Ladder = 1,
		eVLS_Slide = 2,
		eVLS_Item = 3,
		eVLS_Ledge = 4,
		eVLS_Stage = 5,
	};

	Vec3 vLimitDir;
	float vLimitRangeH;
	float vLimitRangeV;
	float vLimitRangeVUp;
	float vLimitRangeVDown;
	SViewLimitParams::EViewLimitState vLimitType;

#if 0
	SViewLimitParams();
	void SetViewLimit(Vec3 _arg0_, float _arg1_, float _arg2_, float _arg3_, float _arg4_, SViewLimitParams::EViewLimitState _arg5_);
	void ClearViewLimit(SViewLimitParams::EViewLimitState _arg0_, bool _arg1_);
	Vec3 GetViewLimitDir() const;
	float GetViewLimitRangeH() const;
	float GetViewLimitRangeV() const;
	float GetViewLimitRangeVUp() const;
	float GetViewLimitRangeVDown() const;
	SViewLimitParams::EViewLimitState GetViewLimitState() const;
#endif
};

