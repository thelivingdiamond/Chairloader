// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkCharacterGroup
// Header:  Prey/Ark/ArkCharacter.h
class ArkCharacterGroup : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkCharacterGroup::ArkIDProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacterGroup::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacterGroup::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkCharacterGroup::ArkNameProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacterGroup::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacterGroup::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkCharacterGroup::ArkNotesProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkNotesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNotesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacterGroup::ArkNotesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacterGroup::ArkNotesProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkCharacterGroup::ArkIDProperty>(0x2D221E0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkCharacterGroup::ArkNameProperty>(0x2D22200);
	string m_Name;
	static inline auto s_ArkNotesProperty = PreyGlobal<ArkCharacterGroup::ArkNotesProperty>(0x2D22220);
	string m_Notes;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetNotes(string _arg0_);
	const string& GetNotes() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107E6A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107E890);
};

// ArkCharacterGroups
// Header:  Prey/Ark/ArkCharacter.h
class ArkCharacterGroups : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkCharacterGroups::ArkGroupsProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkGroupsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkGroupsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacterGroups::ArkGroupsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacterGroups::ArkGroupsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107D7E0);
		static inline auto FIsArray = PreyFunction<bool(const ArkCharacterGroups::ArkGroupsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkCharacterGroups::ArkGroupsProperty* const _this, ArkReflectedObject* _pObject)>(0x107D820);
	};

	static inline auto s_ArkGroupsProperty = PreyGlobal<ArkCharacterGroups::ArkGroupsProperty>(0x2D22240);
	std::vector<ArkCharacterGroup> m_Groups;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual bool Init();

#if 0
	static ArkClass* GetClass();
	std::vector<ArkCharacterGroup>& GetGroups();
	const std::vector<ArkCharacterGroup>& GetGroups() const;
	const ArkCharacterGroup* Find(const uint64_t& _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107E6E0);
	static inline auto FInit = PreyFunction<bool(ArkCharacterGroups* const _this)>(0x107EA70);
};

// ArkCharacter
// Header:  Prey/Ark/ArkCharacter.h
class ArkCharacter : public ArkReflectedObject
{ // Size=96 (0x60)
public:
	// ArkCharacter::ArkIDProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkCharacter::ArkNameProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkCharacter::ArkLabelProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkCharacter::ArkPortraitProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkPortraitProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPortraitProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkPortraitProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkPortraitProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkCharacter::ArkPasswordProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkPasswordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPasswordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkCharacter::ArkResetPasswordPerCharacterProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkResetPasswordPerCharacterProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResetPasswordPerCharacterProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkResetPasswordPerCharacterProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkResetPasswordPerCharacterProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkCharacter::ArkJobTitleProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkJobTitleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkJobTitleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkJobTitleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkJobTitleProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkCharacter::ArkGroupProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkGroupProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGroupProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkGroupProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkGroupProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkCharacter::ArkVoiceProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkVoiceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVoiceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkVoiceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkVoiceProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkCharacter::ArkLocationProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkCharacter::ArkVitalSignsProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkVitalSignsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkVitalSignsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkVitalSignsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D520);
	};

	// ArkCharacter::ArkIsAliveProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkIsAliveProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsAliveProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkIsAliveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443DE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkIsAliveProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A3190);
	};

	// ArkCharacter::ArkHasTrackingChipProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkHasTrackingChipProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHasTrackingChipProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkHasTrackingChipProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkHasTrackingChipProperty* const _this, ArkReflectedObject* const _pObject)>(0x107D580);
	};

	// ArkCharacter::ArkIgnoreTrackingProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkIgnoreTrackingProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIgnoreTrackingProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkIgnoreTrackingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D590);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkIgnoreTrackingProperty* const _this, ArkReflectedObject* const _pObject)>(0x107D5A0);
	};

	// ArkCharacter::ArkRosterLocationProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkRosterLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRosterLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacter::ArkRosterLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D5B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacter::ArkRosterLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkCharacter::ArkIDProperty>(0x2D22260);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkCharacter::ArkNameProperty>(0x2D22280);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkCharacter::ArkLabelProperty>(0x2D222A0);
	string m_Label;
	static inline auto s_ArkPortraitProperty = PreyGlobal<ArkCharacter::ArkPortraitProperty>(0x2D222C0);
	string m_Portrait;
	static inline auto s_ArkPasswordProperty = PreyGlobal<ArkCharacter::ArkPasswordProperty>(0x2D222E0);
	string m_Password;
	static inline auto s_ArkResetPasswordPerCharacterProperty = PreyGlobal<ArkCharacter::ArkResetPasswordPerCharacterProperty>(0x2D22300);
	bool m_ResetPasswordPerCharacter;
	static inline auto s_ArkJobTitleProperty = PreyGlobal<ArkCharacter::ArkJobTitleProperty>(0x2D22320);
	string m_JobTitle;
	static inline auto s_ArkGroupProperty = PreyGlobal<ArkCharacter::ArkGroupProperty>(0x2D22340);
	uint64_t m_Group;
	static inline auto s_ArkVoiceProperty = PreyGlobal<ArkCharacter::ArkVoiceProperty>(0x2D22360);
	uint64_t m_Voice;
	static inline auto s_ArkLocationProperty = PreyGlobal<ArkCharacter::ArkLocationProperty>(0x2D22380);
	uint64_t m_Location;
	static inline auto s_ArkVitalSignsProperty = PreyGlobal<ArkCharacter::ArkVitalSignsProperty>(0x2D223A0);
	EArkVitalSign m_VitalSigns;
	static inline auto s_ArkIsAliveProperty = PreyGlobal<ArkCharacter::ArkIsAliveProperty>(0x2D223C0);
	bool m_IsAlive;
	static inline auto s_ArkHasTrackingChipProperty = PreyGlobal<ArkCharacter::ArkHasTrackingChipProperty>(0x2D223E0);
	bool m_HasTrackingChip;
	static inline auto s_ArkIgnoreTrackingProperty = PreyGlobal<ArkCharacter::ArkIgnoreTrackingProperty>(0x2D22400);
	bool m_IgnoreTracking;
	static inline auto s_ArkRosterLocationProperty = PreyGlobal<ArkCharacter::ArkRosterLocationProperty>(0x2D22420);
	uint64_t m_RosterLocation;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	static EArkVitalSign GetEnumFromString(const char* _string) { return FGetEnumFromString(_string); }

#if 0
	ArkCharacter();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetPortrait(string _arg0_);
	const string& GetPortrait() const;
	void SetPassword(string _arg0_);
	const string& GetPassword() const;
	void SetResetPasswordPerCharacter(bool _arg0_);
	const bool& GetResetPasswordPerCharacter() const;
	void SetJobTitle(string _arg0_);
	const string& GetJobTitle() const;
	void SetGroup(uint64_t _arg0_);
	const uint64_t& GetGroup() const;
	void SetVoice(uint64_t _arg0_);
	const uint64_t& GetVoice() const;
	void SetLocation(uint64_t _arg0_);
	const uint64_t& GetLocation() const;
	void SetVitalSigns(string _arg0_);
	const EArkVitalSign& GetVitalSigns() const;
	void SetIsAlive(bool _arg0_);
	const bool& GetIsAlive() const;
	void SetHasTrackingChip(bool _arg0_);
	const bool& GetHasTrackingChip() const;
	void SetIgnoreTracking(bool _arg0_);
	const bool& GetIgnoreTracking() const;
	void SetRosterLocation(uint64_t _arg0_);
	const uint64_t& GetRosterLocation() const;
	static const char* GetStringFromEnum(EArkVitalSign _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107E650);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107E7F0);
	static inline auto FGetEnumFromString = PreyFunction<EArkVitalSign(const char* _string)>(0x1087970);
};

// ArkCharacters
// Header:  Prey/Ark/ArkCharacter.h
class ArkCharacters : public ArkReflectedLibrary
{ // Size=96 (0x60)
public:
	// ArkCharacters::ArkCharactersProperty
	// Header:  Prey/Ark/ArkCharacter.h
	class ArkCharactersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCharactersProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCharacters::ArkCharactersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCharacters::ArkCharactersProperty* const _this, ArkReflectedObject* const _pObject)>(0x107D690);
		static inline auto FIsArray = PreyFunction<bool(const ArkCharacters::ArkCharactersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkCharacters::ArkCharactersProperty* const _this, ArkReflectedObject* _pObject)>(0x107D6D0);
	};

	static inline auto s_ArkCharactersProperty = PreyGlobal<ArkCharacters::ArkCharactersProperty>(0x2D22440);
	std::vector<ArkCharacter> m_Characters;
	std::unordered_map<uint64_t, std::vector<uint64_t>> m_rosterMasterList;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkCharacter>& GetCharacters();
	const std::vector<ArkCharacter>& GetCharacters() const;
	const ArkCharacter* Find(const uint64_t& _arg0_) const;
	const std::unordered_map<uint64_t, std::vector<uint64_t>>& GetRosterMasterList() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107E740);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107E930);
	static inline auto FInit = PreyFunction<bool(ArkCharacters* const _this)>(0x107EC40);
};
#endif // !MOONCRASH
