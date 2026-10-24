// Header file automatically created from a PDB.
#pragma once

// IOnlineAttributesListener
// Header:  _unknown/IOnlineAttributesListener.h
// Include: Prey/CryAction/IPlayerProfiles.h
class IOnlineAttributesListener
{ // Size=8 (0x8)
public:
	enum EEvent
	{
		eOAE_Invalid = -1,
		eOAE_Register = 0,
		eOAE_Load = 1,
		eOAE_Max = 2,
	};

	enum EState
	{
		eOAS_None = 0,
		eOAS_Processing = 1,
		eOAS_Failed = 2,
		eOAS_Success = 3,
	};

	virtual ~IOnlineAttributesListener();
	virtual void OnlineAttributeState(IOnlineAttributesListener::EEvent _arg0_, IOnlineAttributesListener::EState _arg1_) = 0;
};

