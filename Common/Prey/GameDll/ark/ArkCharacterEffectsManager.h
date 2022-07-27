// Header file automatically created from a PDB.

#pragma once

struct CMultiEffectAttachment;
struct IAttachment;
struct IAttachmentManager;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/ArkCharacterEffectsManager.h
class ArkCharacterEffectsManager // Id=8014234 Size=1544
{
public:
	IEntity *m_pEntity;
	std::vector<string> m_attachmentsByType[64];
	
	ArkCharacterEffectsManager();
	void StartEffect(ArkCharacterEffectType _effectType) { FStartEffect(this,_effectType); }
	void ForceStopEffect(ArkCharacterEffectType _effectType) { FForceStopEffect(this,_effectType); }
	bool IsEffectEnabled(ArkCharacterEffectType _effectType) const { return FIsEffectEnabled(this,_effectType); }
	void StopEffect(ArkCharacterEffectType _effectType) { FStopEffect(this,_effectType); }
	void SetEffectStrength(ArkCharacterEffectType _effectType, float _strenght) const { FSetEffectStrength(this,_effectType,_strenght); }
	void Initialize(IEntity &_entity) { FInitialize(this,_entity); }
	void ShutDown() { FShutDown(this); }
	void StopAllEffects() { FStopAllEffects(this); }
	void OnHide() { FOnHide(this); }
	void EnableEffect(ArkCharacterEffectType _type, const bool _bEnable) { FEnableEffect(this,_type,_bEnable); }
	
#if 0
	void SetEffectOrientation(ArkCharacterEffectType arg0, Vec3 arg1) const;
	IAttachmentManager *GetAttachmentManager(ArkCharacterEffectType arg0) const;
	IAttachment *FindAttachment(const char *const arg0, ArkCharacterEffectType arg1) const;
	int GetSlot(ArkCharacterEffectType arg0) const;
	CMultiEffectAttachment *GetMultiEffect(string const &arg0, ArkCharacterEffectType arg1) const;
#endif
	
	static inline auto FStartEffect = PreyFunction<void(ArkCharacterEffectsManager *const _this, ArkCharacterEffectType _effectType)>(0x1151880);
	static inline auto FForceStopEffect = PreyFunction<void(ArkCharacterEffectsManager *const _this, ArkCharacterEffectType _effectType)>(0x114FA30);
	static inline auto FIsEffectEnabled = PreyFunction<bool(ArkCharacterEffectsManager const *const _this, ArkCharacterEffectType _effectType)>(0x1150650);
	static inline auto FStopEffect = PreyFunction<void(ArkCharacterEffectsManager *const _this, ArkCharacterEffectType _effectType)>(0x1151A30);
	static inline auto FSetEffectStrength = PreyFunction<void(ArkCharacterEffectsManager const *const _this, ArkCharacterEffectType _effectType, float _strenght)>(0x1151630);
	static inline auto FInitialize = PreyFunction<void(ArkCharacterEffectsManager *const _this, IEntity &_entity)>(0x114FD30);
	static inline auto FShutDown = PreyFunction<void(ArkCharacterEffectsManager *const _this)>(0x1151850);
	static inline auto FStopAllEffects = PreyFunction<void(ArkCharacterEffectsManager *const _this)>(0x1151890);
	static inline auto FOnHide = PreyFunction<void(ArkCharacterEffectsManager *const _this)>(0x1150770);
	static inline auto FEnableEffect = PreyFunction<void(ArkCharacterEffectsManager *const _this, ArkCharacterEffectType _type, const bool _bEnable)>(0x114F8A0);
};

