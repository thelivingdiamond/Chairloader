#pragma once
#include "Prey/CryCore/StdAfx.h"

class IProxy
{
public:
	virtual const char* GetName() = 0;
	virtual unsigned int GetNameCRC() = 0;
	virtual unsigned int ReName(const char*, unsigned int) = 0;
	virtual unsigned int SetJointName(const char*) = 0;
	virtual unsigned int GetJointID() = 0;
	virtual const QuatT_tpl<float>* GetProxyAbsoluteDefault() = 0;
	virtual const QuatT_tpl<float>* GetProxyRelativeDefault() = 0;
	virtual const QuatT_tpl<float>* GetProxyModelRelative() = 0;
	virtual void SetProxyAbsoluteDefault(const QuatT_tpl<float>*) = 0;
	virtual unsigned int ProjectProxy() = 0;
	virtual void AlignProxyWithJoint() = 0;
	virtual Vec4_tpl<float>* GetProxyParams(Vec4_tpl<float>* result) = 0;
	virtual void SetProxyParams(const Vec4_tpl<float>*) = 0;
	virtual char GetProxyPurpose() = 0;
	virtual void SetProxyPurpose(char) = 0;
	virtual void SetHideProxy(unsigned __int8) = 0;
	virtual virtual ~IProxy() = 0;


};