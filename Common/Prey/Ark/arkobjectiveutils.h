// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/ArkObjectiveComponent.h>
#include <_unknown/ArkObjectiveUtils__CArkObjectiveClueData.h>

class XmlNodeRef;

namespace ArkObjectiveUtils
{

// ArkObjectiveUtils::CArkObjectiveTaskData
// Header:  Prey/Ark/arkobjectiveutils.h
class CArkObjectiveTaskData
{ // Size=80 (0x50)
public:
	string m_text;
	string m_displayName;
	string m_markerLabel;
	string m_timerLabel;
	uint64_t m_id;
	uint64_t m_originalLocationId;
	uint64_t m_targetCharacterId;
	uint64_t m_descriptionId;
	float m_crypto;
	bool m_bOptional;

	CArkObjectiveTaskData(const XmlNodeRef _root);
	virtual ~CArkObjectiveTaskData();
	virtual wstring GetText() const;
	virtual void Serialize(TSerialize _ser);

#if 0
	CArkObjectiveTaskData();
	uint64_t operator unsigned __int64();
	uint64_t GetId() const;
	uint64_t GetOriginalLocationId() const;
	uint64_t GetTargetCharacterId() const;
	const string& GetDisplayName() const;
	const string& GetLabel() const;
	const string& GetTimerLabel() const;
	uint64_t GetDescriptionId() const;
	float GetCrypto() const;
#endif

	static inline auto FCArkObjectiveTaskDataOv1 = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveTaskData* const _this, const XmlNodeRef _root)>(0x1663440);
	static inline auto FBitNotCArkObjectiveTaskData = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveTaskData* const _this)>(0x1663A50);
	static inline auto FGetText = PreyFunction<wstring*(const ArkObjectiveUtils::CArkObjectiveTaskData* const _this, wstring* _return_value_)>(0x1667400);
	static inline auto FSerialize = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveTaskData* const _this, TSerialize _ser)>(0x166A200);
};

// ArkObjectiveUtils::CArkObjectiveData
// Header:  Prey/Ark/arkobjectiveutils.h
class CArkObjectiveData
{ // Size=112 (0x70)
public:
	std::vector<ArkObjectiveUtils::CArkObjectiveTaskData> m_tasks;
	std::vector<ArkObjectiveUtils::CArkObjectiveDescriptionData> m_descriptions;
	std::vector<ArkObjectiveUtils::CArkObjectiveClueData> m_clues;
	string m_title;
	uint64_t m_id;
	bool m_bOptional;
	bool m_bCountsForQuantumLeap;
	uint64_t m_ownerId;
	float m_crypto;

	CArkObjectiveData(const XmlNodeRef _root);

#if 0
	uint64_t operator unsigned __int64();
	uint64_t GetId() const;
	const string& GetTitle() const;
	bool GetOptional() const;
	bool GetCountsForQuantumLeap() const;
	uint64_t GetOwner() const;
	float GetCrypto() const;
	const std::vector<ArkObjectiveUtils::CArkObjectiveDescriptionData>& GetDescriptions() const;
	const std::vector<ArkObjectiveUtils::CArkObjectiveTaskData>& GetTasks() const;
	const std::vector<ArkObjectiveUtils::CArkObjectiveClueData>& GetClues() const;
	const ArkObjectiveUtils::CArkObjectiveDescriptionData* FindDescription(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveTaskData* FindTask(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveClueData* FindClue(const uint64_t _arg0_) const;
#endif

	static inline auto FCArkObjectiveDataOv2 = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveData* const _this, const XmlNodeRef _root)>(0x16630E0);
};

// ArkObjectiveUtils::CArkBountyObjectiveTaskData
// Header:  Prey/Ark/arkobjectiveutils.h
class CArkBountyObjectiveTaskData : public ArkObjectiveUtils::CArkObjectiveTaskData
{ // Size=104 (0x68)
public:
	string m_verb;
	uint64_t m_weaponId;
	uint64_t m_targetId;

	virtual wstring GetText() const;
	virtual void Serialize(TSerialize _ser);

#if 0
	CArkBountyObjectiveTaskData();
	CArkBountyObjectiveTaskData(const XmlNodeRef _arg0_);
#endif

	static inline auto FGetText = PreyFunction<wstring*(const ArkObjectiveUtils::CArkBountyObjectiveTaskData* const _this, wstring* _return_value_)>(0x1666DE0);
	static inline auto FSerialize = PreyFunction<void(ArkObjectiveUtils::CArkBountyObjectiveTaskData* const _this, TSerialize _ser)>(0x166A080);
};

// ArkObjectiveUtils::CArkObjectiveLib
// Header:  Prey/Ark/arkobjectiveutils.h
class CArkObjectiveLib
{ // Size=24 (0x18)
public:
	std::vector<ArkObjectiveUtils::CArkObjectiveData> m_objectives;

	void Init() { FInit(this); }

#if 0
	void Reset();
	const std::vector<ArkObjectiveUtils::CArkObjectiveData>& GetObjectives() const;
	const ArkObjectiveUtils::CArkObjectiveDescriptionData* FindDescription(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveTaskData* FindTask(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveData* FindObjective(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveClueData* FindClue(const uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveData* FindObjectiveFromTask(uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveData* FindObjectiveFromDescription(uint64_t _arg0_) const;
	const ArkObjectiveUtils::CArkObjectiveData* FindObjectiveFromClue(uint64_t _arg0_) const;
#endif

	static inline auto FInit = PreyFunction<void(ArkObjectiveUtils::CArkObjectiveLib* const _this)>(0x1667930);
};


} // namespace ArkObjectiveUtils
#endif // !MOONCRASH
