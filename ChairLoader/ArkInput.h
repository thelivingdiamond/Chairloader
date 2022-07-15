#pragma once
#include "Prey/CryCore/StdAfx.h"

class ArkInputAction {
public:
	CCryName m_Action;
	CryStringT<char> m_ActionMap;
};
class ArkInputLegendItem {
public:
	CCryName m_Action;
	CryStringT<char> m_ActionMap;
	CryStringT<char> m_Label;
	bool m_Hold;
	CryStringT<char> m_ComboString;
	std::vector<ArkInputAction> m_ActionList;
	EArkLegendControlScheme m_ControlScheme;
	bool m_enabled;
	CryStringT<wchar_t> m_localizedLabel;

};


class ArkInputLegend
{
public:
	CryStringT<char> m_actionMap;
	std::vector<ArkInputLegendItem> m_Items; //0x0008
}; //Size: 0x0020

class ArkInputLegendHandler
{
public:
	uint32_t m_handle; //0x0000
}; //Size: 0x0004