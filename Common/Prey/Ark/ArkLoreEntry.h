// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkLoreEntry.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
struct IEntityClass;
class ArkLoreEntry;
class ArkLoreLibrary;
class ArkPsiPowerMimicEffectsProperties;
#endif
class ArkLoreEntry : public ArkReflectedObject // Id=8016A89 Size=64
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016A8A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkLoreEntry::ArkIDProperty>(0x2D261F0);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016A8B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkLoreEntry::ArkNameProperty>(0x2D26210);
#endif
	string m_Name;
	
	class ArkSubjectProperty : public ArkProperty // Id=8016A8C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkSubjectProperty s_ArkSubjectProperty;
#else
	static inline auto s_ArkSubjectProperty = PreyGlobal<ArkLoreEntry::ArkSubjectProperty>(0x2D26230);
#endif
	string m_Subject;
	
	class ArkShortFormTextProperty : public ArkProperty // Id=8016A8D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkShortFormTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkShortFormTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkShortFormTextProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkShortFormTextProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkShortFormTextProperty s_ArkShortFormTextProperty;
#else
	static inline auto s_ArkShortFormTextProperty = PreyGlobal<ArkLoreEntry::ArkShortFormTextProperty>(0x2D26250);
#endif
	string m_ShortFormText;
	
	class ArkShortFormImageProperty : public ArkProperty // Id=8016A8E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkShortFormImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkShortFormImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkShortFormImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkShortFormImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkShortFormImageProperty s_ArkShortFormImageProperty;
#else
	static inline auto s_ArkShortFormImageProperty = PreyGlobal<ArkLoreEntry::ArkShortFormImageProperty>(0x2D26270);
#endif
	string m_ShortFormImage;
	
	class ArkLongFormTextProperty : public ArkProperty // Id=8016A8F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkLongFormTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkLongFormTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkLongFormTextProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkLongFormTextProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkLongFormTextProperty s_ArkLongFormTextProperty;
#else
	static inline auto s_ArkLongFormTextProperty = PreyGlobal<ArkLoreEntry::ArkLongFormTextProperty>(0x2D26290);
#endif
	string m_LongFormText;
	
	class ArkLongFormImageProperty : public ArkProperty // Id=8016A90 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkLongFormImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkLongFormImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkLongFormImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkLongFormImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkLongFormImageProperty s_ArkLongFormImageProperty;
#else
	static inline auto s_ArkLongFormImageProperty = PreyGlobal<ArkLoreEntry::ArkLongFormImageProperty>(0x2D262B0);
#endif
	string m_LongFormImage;
	
	class ArkScannerDataProperty : public ArkProperty // Id=8016A91 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkScannerDataProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkScannerDataProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkLoreEntry::ArkScannerDataProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreEntry::ArkScannerDataProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreEntry::ArkScannerDataProperty s_ArkScannerDataProperty;
#else
	static inline auto s_ArkScannerDataProperty = PreyGlobal<ArkLoreEntry::ArkScannerDataProperty>(0x2D262D0);
#endif
	string m_ScannerData;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetSubject(string arg0);
	string const &GetSubject() const;
	void SetShortFormText(string arg0);
	string const &GetShortFormText() const;
	void SetShortFormImage(string arg0);
	string const &GetShortFormImage() const;
	void SetLongFormText(string arg0);
	string const &GetLongFormText() const;
	void SetLongFormImage(string arg0);
	string const &GetLongFormImage() const;
	void SetScannerData(string arg0);
	string const &GetScannerData() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072C50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1072D00);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1098A00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1098AB0);
#endif
};

// Header: Exact
// Prey/Ark/arkloreentry.h
class ArkLoreLibrary : public ArkReflectedLibrary // Id=8016A9F Size=32
{
public:
	class ArkEntriesProperty : public ArkProperty // Id=8016AA0 Size=32
	{
	public:
		ArkEntriesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1072310);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1072350);
		static inline auto FIsArray = PreyFunction<bool(ArkLoreLibrary::ArkEntriesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1072390);
#else
		static inline auto FArkEntriesPropertyOv2 = PreyFunction<void(ArkLoreLibrary::ArkEntriesProperty* const _this)>(0x1098580);
		static inline auto FSetValue = PreyFunction<void(const ArkLoreLibrary::ArkEntriesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10980C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLoreLibrary::ArkEntriesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1098100);
		static inline auto FIsArray = PreyFunction<bool(const ArkLoreLibrary::ArkEntriesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLoreLibrary::ArkEntriesProperty* const _this, ArkReflectedObject* _pObject)>(0x1098140);
#endif
	};

#ifndef MOONCRASH
	static ArkLoreLibrary::ArkEntriesProperty s_ArkEntriesProperty;
#else
	static inline auto s_ArkEntriesProperty = PreyGlobal<ArkLoreLibrary::ArkEntriesProperty>(0x2D262F0);
#endif
	std::vector<ArkLoreEntry> m_Entries;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkLoreLibrary();
	
#if 0
	std::vector<ArkLoreEntry> &GetEntries();
	std::vector<ArkLoreEntry> const &GetEntries() const;
	ArkLoreEntry const *FindLoreEntry(const uint64_t arg0) const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072CA0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1072DA0);
	static inline auto FInit = PreyFunction<bool(ArkLoreLibrary *const _this)>(0x1072E90);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1098A50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1098B50);
	static inline auto FInit = PreyFunction<bool(ArkLoreLibrary* const _this)>(0x1098C40);
#endif
};

// Header: Exact
// Prey/Ark/arkloreentry.h
class ArkPsiPowerMimicEffectsProperties : public ArkReflectedObject // Id=8019497 Size=64
{
public:
	class ArkMorphEffectDurationSecProperty : public ArkProperty // Id=8019498 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty s_ArkMorphEffectDurationSecProperty;
#else
	static inline auto s_ArkMorphEffectDurationSecProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty>(0x2D54D28);
#endif
	float m_MorphEffectDurationSec;
	
	class ArkJumpAudioTriggerProperty : public ArkProperty // Id=8019499 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty s_ArkJumpAudioTriggerProperty;
#else
	static inline auto s_ArkJumpAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty>(0x2D54D48);
#endif
	string m_JumpAudioTrigger;
	
	class ArkMorphInAudioTriggerProperty : public ArkProperty // Id=801949A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty s_ArkMorphInAudioTriggerProperty;
#else
	static inline auto s_ArkMorphInAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty>(0x2D54D68);
#endif
	string m_MorphInAudioTrigger;
	
	class ArkMorphOutAudioTriggerProperty : public ArkProperty // Id=801949B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty s_ArkMorphOutAudioTriggerProperty;
#else
	static inline auto s_ArkMorphOutAudioTriggerProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty>(0x2D54D88);
#endif
	string m_MorphOutAudioTrigger;
	
	class ArkMovementParticleEffectProperty : public ArkProperty // Id=801949C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty s_ArkMovementParticleEffectProperty;
#else
	static inline auto s_ArkMovementParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty>(0x2D54DA8);
#endif
	string m_MovementParticleEffect;
	
	class ArkPersistentParticleEffectProperty : public ArkProperty // Id=801949D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty s_ArkPersistentParticleEffectProperty;
#else
	static inline auto s_ArkPersistentParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty>(0x2D54DC8);
#endif
	string m_PersistentParticleEffect;
	
	class ArkMorphOutParticleEffectProperty : public ArkProperty // Id=801949E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty s_ArkMorphOutParticleEffectProperty;
#else
	static inline auto s_ArkMorphOutParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty>(0x2D54DE8);
#endif
	string m_MorphOutParticleEffect;
	
	class ArkObjectMorphInParticleEffectProperty : public ArkProperty // Id=801949F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
	};

#ifndef MOONCRASH
	static ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty s_ArkObjectMorphInParticleEffectProperty;
#else
	static inline auto s_ArkObjectMorphInParticleEffectProperty = PreyGlobal<ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty>(0x2D54E08);
#endif
	string m_ObjectMorphInParticleEffect;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMorphEffectDurationSec(float arg0);
	const float &GetMorphEffectDurationSec() const;
	void SetJumpAudioTrigger(string arg0);
	string const &GetJumpAudioTrigger() const;
	void SetMorphInAudioTrigger(string arg0);
	string const &GetMorphInAudioTrigger() const;
	void SetMorphOutAudioTrigger(string arg0);
	string const &GetMorphOutAudioTrigger() const;
	void SetMovementParticleEffect(string arg0);
	string const &GetMovementParticleEffect() const;
	void SetPersistentParticleEffect(string arg0);
	string const &GetPersistentParticleEffect() const;
	void SetMorphOutParticleEffect(string arg0);
	string const &GetMorphOutParticleEffect() const;
	void SetObjectMorphInParticleEffect(string arg0);
	string const &GetObjectMorphInParticleEffect() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072C50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AD60);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1098A00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14053C0);
#endif
};
