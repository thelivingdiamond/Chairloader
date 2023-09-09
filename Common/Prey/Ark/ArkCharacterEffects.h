// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkcharactereffects.h
class ArkAttachmentEffect : public ArkReflectedObject // Id=801360F Size=40
{
public:
	class ArkAttachmentProperty : public ArkProperty // Id=8013610 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAttachmentEffect::ArkAttachmentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAttachmentEffect::ArkAttachmentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAttachmentEffect::ArkAttachmentProperty s_ArkAttachmentProperty;
	string m_Attachment;
	
	class ArkParticleEffectProperty : public ArkProperty // Id=8013611 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAttachmentEffect::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAttachmentEffect::ArkParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAttachmentEffect::ArkParticleEffectProperty s_ArkParticleEffectProperty;
	string m_ParticleEffect;
	
	class ArkPositionOffsetProperty : public ArkProperty // Id=8013612 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAttachmentEffect::ArkPositionOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105DAF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAttachmentEffect::ArkPositionOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAttachmentEffect::ArkPositionOffsetProperty s_ArkPositionOffsetProperty;
	Vec3 m_PositionOffset;
	
	class ArkRotationOffsetProperty : public ArkProperty // Id=8013613 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAttachmentEffect::ArkRotationOffsetProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105DB20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAttachmentEffect::ArkRotationOffsetProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkAttachmentEffect::ArkRotationOffsetProperty s_ArkRotationOffsetProperty;
	Vec3 m_RotationOffset;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAttachment(string arg0);
	string const &GetAttachment() const;
	void SetParticleEffect(string arg0);
	string const &GetParticleEffect() const;
	void SetPositionOffset(Vec3 arg0);
	Vec3 const &GetPositionOffset() const;
	void SetRotationOffset(Vec3 arg0);
	Vec3 const &GetRotationOffset() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1326180);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105E950);
};

// Header: Exact
// Prey/Ark/arkcharactereffects.h
class ArkCharacterEffect : public ArkReflectedObject // Id=8013614 Size=40
{
public:
	class ArkIdProperty : public ArkProperty // Id=8013615 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterEffect::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterEffect::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkCharacterEffect::ArkIdProperty s_ArkIdProperty;
	uint64_t m_Id;
	
	class ArkNameProperty : public ArkProperty // Id=8013616 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterEffect::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterEffect::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkCharacterEffect::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkAttachEffectsProperty : public ArkProperty // Id=8013617 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterEffect::ArkAttachEffectsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105DB50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterEffect::ArkAttachEffectsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105DC00);
		static inline auto FIsArray = PreyFunction<bool(ArkCharacterEffect::ArkAttachEffectsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCharacterEffect::ArkAttachEffectsProperty const *const _this, ArkReflectedObject *_pObject)>(0x105DC20);
	};

	static ArkCharacterEffect::ArkAttachEffectsProperty s_ArkAttachEffectsProperty;
	std::vector<ArkAttachmentEffect> m_AttachEffects;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetId(uint64_t arg0);
	const uint64_t &GetId() const;
	void SetName(string arg0);
	string const &GetName() const;
	std::vector<ArkAttachmentEffect> &GetAttachEffects();
	std::vector<ArkAttachmentEffect> const &GetAttachEffects() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105E880);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105E9F0);
};

// Header: Exact
// Prey/Ark/ArkCharacterEffects.h
class ArkCharacterEffects : public ArkReflectedLibrary // Id=8013633 Size=32
{
public:
	class ArkEffectsProperty : public ArkProperty // Id=8013634 Size=32
	{
	public:
		ArkEffectsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCharacterEffects::ArkEffectsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105D990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCharacterEffects::ArkEffectsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105DA20);
		static inline auto FIsArray = PreyFunction<bool(ArkCharacterEffects::ArkEffectsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCharacterEffects::ArkEffectsProperty const *const _this, ArkReflectedObject *_pObject)>(0x105DA60);
	};

	static ArkCharacterEffects::ArkEffectsProperty s_ArkEffectsProperty;
	std::vector<ArkCharacterEffect> m_Effects;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkCharacterEffect const *GetCharacterEffectById(const uint64_t _characterEffectId) const { return FGetCharacterEffectByIdOv1(this,_characterEffectId); }
	virtual ~ArkCharacterEffects();
	
#if 0
	std::vector<ArkCharacterEffect> &GetEffects();
	std::vector<ArkCharacterEffect> const &GetEffects() const;
	ArkCharacterEffect *GetCharacterEffectById(const uint64_t arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105E8C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105EA90);
	static inline auto FInit = PreyFunction<bool(ArkCharacterEffects *const _this)>(0x105EB80);
	static inline auto FGetCharacterEffectByIdOv1 = PreyFunction<ArkCharacterEffect const *(ArkCharacterEffects const *const _this, const uint64_t _characterEffectId)>(0x105E920);
};

