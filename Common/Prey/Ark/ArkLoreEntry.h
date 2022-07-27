// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkloreentry.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkLoreEntry.h
class ArkLoreEntry : public ArkReflectedObject // Id=8016A89 Size=64
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016A8A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLoreEntry::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016A8B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkLoreEntry::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkSubjectProperty : public ArkProperty // Id=8016A8C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkSubjectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkLoreEntry::ArkSubjectProperty s_ArkSubjectProperty;
	string m_Subject;
	
	class ArkShortFormTextProperty : public ArkProperty // Id=8016A8D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkShortFormTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkShortFormTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkLoreEntry::ArkShortFormTextProperty s_ArkShortFormTextProperty;
	string m_ShortFormText;
	
	class ArkShortFormImageProperty : public ArkProperty // Id=8016A8E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkShortFormImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkShortFormImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkLoreEntry::ArkShortFormImageProperty s_ArkShortFormImageProperty;
	string m_ShortFormImage;
	
	class ArkLongFormTextProperty : public ArkProperty // Id=8016A8F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkLongFormTextProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkLongFormTextProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkLoreEntry::ArkLongFormTextProperty s_ArkLongFormTextProperty;
	string m_LongFormText;
	
	class ArkLongFormImageProperty : public ArkProperty // Id=8016A90 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkLongFormImageProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkLongFormImageProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkLoreEntry::ArkLongFormImageProperty s_ArkLongFormImageProperty;
	string m_LongFormImage;
	
	class ArkScannerDataProperty : public ArkProperty // Id=8016A91 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreEntry::ArkScannerDataProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreEntry::ArkScannerDataProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkLoreEntry::ArkScannerDataProperty s_ArkScannerDataProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072C50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1072D00);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1072310);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1072350);
		static inline auto FIsArray = PreyFunction<bool(ArkLoreLibrary::ArkEntriesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLoreLibrary::ArkEntriesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1072390);
	};

	static ArkLoreLibrary::ArkEntriesProperty s_ArkEntriesProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072CA0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1072DA0);
	static inline auto FInit = PreyFunction<bool(ArkLoreLibrary *const _this)>(0x1072E90);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkMorphEffectDurationSecProperty s_ArkMorphEffectDurationSecProperty;
	float m_MorphEffectDurationSec;
	
	class ArkJumpAudioTriggerProperty : public ArkProperty // Id=8019499 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkJumpAudioTriggerProperty s_ArkJumpAudioTriggerProperty;
	string m_JumpAudioTrigger;
	
	class ArkMorphInAudioTriggerProperty : public ArkProperty // Id=801949A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkMorphInAudioTriggerProperty s_ArkMorphInAudioTriggerProperty;
	string m_MorphInAudioTrigger;
	
	class ArkMorphOutAudioTriggerProperty : public ArkProperty // Id=801949B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkMorphOutAudioTriggerProperty s_ArkMorphOutAudioTriggerProperty;
	string m_MorphOutAudioTrigger;
	
	class ArkMovementParticleEffectProperty : public ArkProperty // Id=801949C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkMovementParticleEffectProperty s_ArkMovementParticleEffectProperty;
	string m_MovementParticleEffect;
	
	class ArkPersistentParticleEffectProperty : public ArkProperty // Id=801949D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkPersistentParticleEffectProperty s_ArkPersistentParticleEffectProperty;
	string m_PersistentParticleEffect;
	
	class ArkMorphOutParticleEffectProperty : public ArkProperty // Id=801949E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkMorphOutParticleEffectProperty s_ArkMorphOutParticleEffectProperty;
	string m_MorphOutParticleEffect;
	
	class ArkObjectMorphInParticleEffectProperty : public ArkProperty // Id=801949F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiPowerMimicEffectsProperties::ArkObjectMorphInParticleEffectProperty s_ArkObjectMorphInParticleEffectProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1072C50);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x132AD60);
};

