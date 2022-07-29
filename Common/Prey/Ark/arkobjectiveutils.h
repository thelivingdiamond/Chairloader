// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

namespace ArkObjectiveUtils
{
class CArkObjectiveClueData;
class CArkObjectiveDescriptionData;
} // namespace ArkObjectiveUtils
class XmlNodeRef;

namespace ArkObjectiveUtils
{

// Header: Exact
// Prey/Ark/arkobjectiveutils.h
class CArkObjectiveTaskData // Id=8013B21 Size=72
{
public:
	string m_text;
	string m_displayName;
	string m_markerLabel;
	string m_timerLabel;
	int64_t m_id;
	uint64_t m_originalLocationId;
	uint64_t m_targetCharacterId;
	uint64_t m_descriptionId;
	bool m_bOptional;
	
	CArkObjectiveTaskData(XmlNodeRef _root);
	wstring GetText() const { return FGetText(this); }
	
#if 0
	int64_t operator __int64();
	int64_t GetId() const;
	uint64_t GetOriginalLocationId() const;
	uint64_t GetTargetCharacterId() const;
	string const &GetDisplayName() const;
	string const &GetLabel() const;
	string const &GetTimerLabel() const;
	uint64_t GetDescriptionId() const;
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FGetText = PreyFunction<wstring(ArkObjectiveUtils::CArkObjectiveTaskData const *const _this)>(0x15456E0);
};

} // namespace ArkObjectiveUtils

namespace ArkObjectiveUtils
{

// Header: Exact
// Prey/Ark/arkobjectiveutils.h
class CArkObjectiveData // Id=8013B4B Size=96
{
public:
	std::vector<ArkObjectiveUtils::CArkObjectiveTaskData> m_tasks;
	std::vector<ArkObjectiveUtils::CArkObjectiveDescriptionData> m_descriptions;
	std::vector<ArkObjectiveUtils::CArkObjectiveClueData> m_clues;
	string m_title;
	int64_t m_id;
	bool m_bOptional;
	
	CArkObjectiveData(XmlNodeRef _root);
	
#if 0
	int64_t operator __int64();
	int64_t GetId() const;
	string const &GetTitle() const;
	bool GetOptional() const;
	std::vector<ArkObjectiveUtils::CArkObjectiveDescriptionData> const &GetDescriptions() const;
	std::vector<ArkObjectiveUtils::CArkObjectiveTaskData> const &GetTasks() const;
	std::vector<ArkObjectiveUtils::CArkObjectiveClueData> const &GetClues() const;
	ArkObjectiveUtils::CArkObjectiveDescriptionData const *FindDescription(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveTaskData const *FindTask(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveClueData const *FindClue(const int64_t arg0) const;
#endif
};

} // namespace ArkObjectiveUtils

namespace ArkObjectiveUtils
{

// Header: Exact
// Prey/Ark/arkobjectiveutils.h
class CArkObjectiveLib // Id=8013B59 Size=24
{
public:
	std::vector<ArkObjectiveUtils::CArkObjectiveData> m_objectives;
	
	void Init() { FInit(this); }
	
#if 0
	void Reset();
	std::vector<ArkObjectiveUtils::CArkObjectiveData> const &GetObjectives() const;
	ArkObjectiveUtils::CArkObjectiveDescriptionData const *FindDescription(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveTaskData const *FindTask(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveData const *FindObjective(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveClueData const *FindClue(const int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveData const *FindObjectiveFromTask(int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveData const *FindObjectiveFromDescription(int64_t arg0) const;
	ArkObjectiveUtils::CArkObjectiveData const *FindObjectiveFromClue(int64_t arg0) const;
#endif
	
	static inline auto FInit = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveLib *const _this)>(0x1545C10);
};

} // namespace ArkObjectiveUtils

