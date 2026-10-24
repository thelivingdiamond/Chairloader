// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class XmlNodeRef;

namespace ArkObjectiveUtils
{

// ArkObjectiveUtils::CArkObjectiveClueData
// Header:  _unknown/ArkObjectiveUtils__CArkObjectiveClueData.h
class CArkObjectiveClueData
{ // Size=24 (0x18)
public:
#ifdef MOONCRASH
	uint64_t m_id;
#endif
#ifndef MOONCRASH
	int64_t m_id;
#endif
	string m_text;
	string m_displayName;

#if 0
	CArkObjectiveClueData(const XmlNodeRef _arg0_);
	int64_t GetId() const;
	const string& GetText() const;
	const string& GetDisplayName() const;
	void Serialize(TSerialize _arg0_);
#endif
};


} // namespace ArkObjectiveUtils

