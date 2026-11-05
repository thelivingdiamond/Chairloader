#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

namespace ArkObjectiveUtils
{
class CArkObjectiveTaskData;
} // namespace ArkObjectiveUtils
class XmlNodeRef;

namespace ArkObjectiveUtils
{

// ArkObjectiveUtils::CArkObjectiveDynamicTaskData
// Header:  _unknown/ArkObjectiveUtils__CArkObjectiveDynamicTaskData.h
class CArkObjectiveDynamicTaskData
{ // Size=16 (0x10)
public:
	ArkObjectiveUtils::CArkObjectiveTaskData* m_pTaskData;
	bool m_bIsBounty;

#if 0
	CArkObjectiveDynamicTaskData();
	CArkObjectiveDynamicTaskData(const XmlNodeRef _arg0_);
	ArkObjectiveUtils::CArkObjectiveTaskData& GetTaskData() const;
	void Serialize(TSerialize _arg0_);
#endif
};


} // namespace ArkObjectiveUtils

#endif // MOONCRASH
