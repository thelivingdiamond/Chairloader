// Header file automatically created from a PDB.
#pragma once

class CSharedParamsTypeInfo;

// ISharedParams
// Header:  _unknown/ISharedParams.h
// Include: Prey/CryAction/SharedParams/ISharedParams.h
class ISharedParams
{ // Size=8 (0x8)
public:
	virtual ~ISharedParams();
	virtual ISharedParams* Clone() const = 0;
	virtual const CSharedParamsTypeInfo& GetTypeInfo() const = 0;
};

