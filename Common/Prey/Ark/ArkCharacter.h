// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkcharacter.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkcharacter.h
class ArkCharacterGroup : public ArkReflectedObject // Id=80135B3 Size=24
{
public:
	class ArkIDProperty : public ArkProperty // Id=80135B4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterGroup::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterGroup::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkCharacterGroup::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=80135B5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterGroup::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterGroup::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkCharacterGroup::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkNotesProperty : public ArkProperty // Id=80135B6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterGroup::ArkNotesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterGroup::ArkNotesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkCharacterGroup::ArkNotesProperty s_ArkNotesProperty;
	string m_Notes;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetNotes(string arg0);
	string const &GetNotes() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105CB40);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105CD30);
};

// Header: Exact
// Prey/Ark/arkcharacter.h
class ArkCharacterGroups : public ArkReflectedLibrary // Id=80135C4 Size=32
{
public:
	class ArkGroupsProperty : public ArkProperty // Id=80135C5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterGroups::ArkGroupsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105BC00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterGroups::ArkGroupsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BCA0);
		static inline auto FIsArray = PreyFunction<bool(ArkCharacterGroups::ArkGroupsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCharacterGroups::ArkGroupsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1079C00);
	};

	static ArkCharacterGroups::ArkGroupsProperty s_ArkGroupsProperty;
	std::vector<ArkCharacterGroup> m_Groups;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual bool Init();
	virtual ~ArkCharacterGroups();
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkCharacterGroup> &GetGroups();
	std::vector<ArkCharacterGroup> const &GetGroups() const;
	ArkCharacterGroup const *Find(const uint64_t &arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105CB80);
	static inline auto FInit = PreyFunction<bool(ArkCharacterGroups *const _this)>(0x105CF10);
};

// Header: Exact
// Prey/Ark/ArkCharacter.h
class ArkCharacter : public ArkReflectedObject // Id=80135C7 Size=88
{
public:
	class ArkIDProperty : public ArkProperty // Id=80135C8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkCharacter::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=80135C9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkCharacter::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=80135CA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkCharacter::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkPortraitProperty : public ArkProperty // Id=80135CB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkPortraitProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkPortraitProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkCharacter::ArkPortraitProperty s_ArkPortraitProperty;
	string m_Portrait;
	
	class ArkPasswordProperty : public ArkProperty // Id=80135CC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkCharacter::ArkPasswordProperty s_ArkPasswordProperty;
	string m_Password;
	
	class ArkJobTitleProperty : public ArkProperty // Id=80135CD Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkJobTitleProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkJobTitleProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkCharacter::ArkJobTitleProperty s_ArkJobTitleProperty;
	string m_JobTitle;
	
	class ArkGroupProperty : public ArkProperty // Id=80135CE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkGroupProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkGroupProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkCharacter::ArkGroupProperty s_ArkGroupProperty;
	uint64_t m_Group;
	
	class ArkVoiceProperty : public ArkProperty // Id=80135CF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkVoiceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkVoiceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkCharacter::ArkVoiceProperty s_ArkVoiceProperty;
	uint64_t m_Voice;
	
	class ArkLocationProperty : public ArkProperty // Id=80135D0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkCharacter::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	class ArkVitalSignsProperty : public ArkProperty // Id=80135D1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkVitalSignsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9F0);
	};

	static ArkCharacter::ArkVitalSignsProperty s_ArkVitalSignsProperty;
	EArkVitalSign m_VitalSigns;
	
	class ArkIsAliveProperty : public ArkProperty // Id=80135D2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkIsAliveProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1066490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkIsAliveProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BA40);
	};

	static ArkCharacter::ArkIsAliveProperty s_ArkIsAliveProperty;
	bool m_IsAlive;
	
	class ArkHasTrackingChipProperty : public ArkProperty // Id=80135D3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkHasTrackingChipProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105BA50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkHasTrackingChipProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BA60);
	};

	static ArkCharacter::ArkHasTrackingChipProperty s_ArkHasTrackingChipProperty;
	bool m_HasTrackingChip;
	
	class ArkRosterLocationProperty : public ArkProperty // Id=80135D4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacter::ArkRosterLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105BA70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacter::ArkRosterLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkCharacter::ArkRosterLocationProperty s_ArkRosterLocationProperty;
	uint64_t m_RosterLocation;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	static EArkVitalSign GetEnumFromString(const char *_string) { return FGetEnumFromString(_string); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetPortrait(string arg0);
	string const &GetPortrait() const;
	void SetPassword(string arg0);
	string const &GetPassword() const;
	void SetJobTitle(string arg0);
	string const &GetJobTitle() const;
	void SetGroup(uint64_t arg0);
	const uint64_t &GetGroup() const;
	void SetVoice(uint64_t arg0);
	const uint64_t &GetVoice() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
	void SetVitalSigns(string arg0);
	EArkVitalSign const &GetVitalSigns() const;
	void SetIsAlive(bool arg0);
	const bool &GetIsAlive() const;
	void SetHasTrackingChip(bool arg0);
	const bool &GetHasTrackingChip() const;
	void SetRosterLocation(uint64_t arg0);
	const uint64_t &GetRosterLocation() const;
	static const char *GetStringFromEnum(EArkVitalSign arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105CAF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105CC90);
	static inline auto FGetEnumFromString = PreyFunction<EArkVitalSign(const char *_string)>(0x1064A30);
};

// Header: Exact
// Prey/Ark/arkcharacter.h
class ArkCharacters : public ArkReflectedLibrary // Id=80135E2 Size=96
{
public:
	class ArkCharactersProperty : public ArkProperty // Id=80135E3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacters::ArkCharactersProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105BA80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacters::ArkCharactersProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105BB50);
		static inline auto FIsArray = PreyFunction<bool(ArkCharacters::ArkCharactersProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCharacters::ArkCharactersProperty const *const _this, ArkReflectedObject *_pObject)>(0x105BB90);
	};

	static ArkCharacters::ArkCharactersProperty s_ArkCharactersProperty;
	std::vector<ArkCharacter> m_Characters;
	std::unordered_map<unsigned __int64,std::vector<unsigned __int64>> m_rosterMasterList;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkCharacters();
	
#if 0
	std::vector<ArkCharacter> &GetCharacters();
	std::vector<ArkCharacter> const &GetCharacters() const;
	ArkCharacter const *Find(const uint64_t &arg0) const;
	std::unordered_map<unsigned __int64,std::vector<unsigned __int64>> const &GetRosterMasterList() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105CBE0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105CDD0);
	static inline auto FInit = PreyFunction<bool(ArkCharacters *const _this)>(0x105D0C0);
};

// Header: Exact
// Prey/Ark/arkcharacter.h
class ArkNote : public ArkReflectedObject // Id=8016B13 Size=72
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016B14 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkNote::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016B15 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkNote::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkPlotCriticalProperty : public ArkProperty // Id=8016B16 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkPlotCriticalProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkPlotCriticalProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkNote::ArkPlotCriticalProperty s_ArkPlotCriticalProperty;
	bool m_PlotCritical;
	
	class ArkSubjectProperty : public ArkProperty // Id=8016B17 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkNote::ArkSubjectProperty s_ArkSubjectProperty;
	string m_Subject;
	
	class ArkContentProperty : public ArkProperty // Id=8016B18 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkContentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkContentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkNote::ArkContentProperty s_ArkContentProperty;
	string m_Content;
	
	class ArkKeyCodeProperty : public ArkProperty // Id=8016B19 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkKeyCodeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A840);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkKeyCodeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkNote::ArkKeyCodeProperty s_ArkKeyCodeProperty;
	uint64_t m_KeyCode;
	
	class ArkLocationProperty : public ArkProperty // Id=8016B1A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkNote::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	class ArkPasswordProperty : public ArkProperty // Id=8016B1B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkPasswordProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkNote::ArkPasswordProperty s_ArkPasswordProperty;
	uint64_t m_Password;
	
	class ArkImageNameProperty : public ArkProperty // Id=8016B1C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNote::ArkImageNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNote::ArkImageNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkNote::ArkImageNameProperty s_ArkImageNameProperty;
	string m_ImageName;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetPlotCritical(bool arg0);
	const bool &GetPlotCritical() const;
	void SetSubject(string arg0);
	string const &GetSubject() const;
	void SetContent(string arg0);
	string const &GetContent() const;
	void SetKeyCode(uint64_t arg0);
	const uint64_t &GetKeyCode() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
	void SetPassword(uint64_t arg0);
	const uint64_t &GetPassword() const;
	void SetImageName(string arg0);
	string const &GetImageName() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1079440);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10794F0);
};

