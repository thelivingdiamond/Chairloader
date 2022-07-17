#pragma once
#include "Prey/CryCore/StdAfx.h"

class IArkStatsListener
{
public:
	virtual void OnStatChange(const unsigned int, const CCryName*, const float, const float) {};
	virtual void OnStatSerialize(const unsigned int, const CCryName*, const float) {};

};
class ArkStatModifier {
public:
	CCryName m_StatName;
	float m_Modifier;
};
class ArkConditionalStatModifier : ArkStatModifier {
public:
	bool m_IsActiveInAlternateForm;
};