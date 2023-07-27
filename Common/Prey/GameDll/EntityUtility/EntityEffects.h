// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/itemstring.h>

class ICrySizer;
struct IEntity;
struct ILightSource;
struct IParticleEffect;
struct IParticleEmitter;
struct IRenderNode;

namespace EntityEffects
{

// Header: Override
// Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectInfo // Id=8013ED6 Size=24
{
	unsigned id;
	int entityEffectSlot;
	int characterEffectSlot;
	SharedString::CSharedString helperName;

#if 0
	bool operator==(const unsigned& arg0) const;
#endif
};

// Header: Override
// Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectAttachParams // Id=8013EE1 Size=36
{
	Vec3 offset;
	Vec3 direction;
	float scale;
	int firstSafeSlot;
	bool prime;
};

// Header: Override
// Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectSpawnParams // Id=8016D04 Size=36
{
	Vec3 position;
	Vec3 direction;
	float scale;
	float speed;
	bool prime;
};

// Header: Override
// Prey/GameDll/EntityUtility/EntityEffects.h
struct SLightAttachParams // Id=8013D60 Size=104
{
	IRenderNode *pCasterException;
	Vec3 color;
	Vec3 offset;
	Vec3 direction;
	float radius;
	float specularMultiplier;
	float diffuseMultiplier;
	float projectFov;
	float hdrDynamic;
	const char *projectTexture;
	const char *material;
	int style;
	float animSpeed;
	int firstSafeSlot;
	bool deferred;
	bool castShadows;
	bool fakelight;
	const char *lensflare;
};

// Header: Override
// Prey/GameDll/EntityUtility/EntityEffects.h
class CEffectsController // Id=8013ED2 Size=40
{
public:
	using TAttachedEffects = std::vector<EntityEffects::SEffectInfo>;
	
	IEntity *m_pOwnerEntity = nullptr;
	std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
	unsigned m_effectGeneratorId = 0;
	
	CEffectsController() = default;
	void InitWithEntity(IEntity *pEntity) { FInitWithEntity(this,pEntity); }
	void FreeAllEffects() { FFreeAllEffects(this); }
	unsigned AttachParticleEffect(IParticleEffect *pParticleEffect, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv3(this,pParticleEffect,attachParams); }
	unsigned AttachParticleEffect(const char *effectName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv2(this,effectName,attachParams); }
	unsigned AttachParticleEffect(IParticleEffect *pParticleEffect, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv1(this,pParticleEffect,targetSlot,helperName,attachParams); }
	unsigned AttachParticleEffect(const char *effectName, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams) { return FAttachParticleEffectOv0(this,effectName,targetSlot,helperName,attachParams); }
	void DetachEffect(const unsigned effectId) { FDetachEffect(this,effectId); }
	IParticleEmitter *GetEffectEmitter(const unsigned effectId) const { return FGetEffectEmitter(this,effectId); }
	int FindSafeSlot(int firstSafeSlot) { return FFindSafeSlot(this,firstSafeSlot); }
	
#if 0
	unsigned AttachLight(const int arg0, const char *arg1, EntityEffects::SLightAttachParams const &arg2);
	EntityEffects::SEffectInfo const &GetEffectInfoAt(const unsigned arg0) const;
	unsigned GetEffectCount() const;
	ILightSource *GetLightSource(const unsigned arg0) const;
	void SetEffectWorldTM(const unsigned arg0, Matrix34 const &arg1);
	void UpdateEntitySlotEffectLocationsFromHelpers();
	void GetMemoryStatistics(ICrySizer *arg0) const;
#endif
	
	static inline auto FInitWithEntity = PreyFunction<void(EntityEffects::CEffectsController *const _this, IEntity *pEntity)>(0x10BE320);
	static inline auto FFreeAllEffects = PreyFunction<void(EntityEffects::CEffectsController *const _this)>(0x16BCC80);
	static inline auto FAttachParticleEffectOv3 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, IParticleEffect *pParticleEffect, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC120);
	static inline auto FAttachParticleEffectOv2 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, const char *effectName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC9B0);
	static inline auto FAttachParticleEffectOv1 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, IParticleEffect *pParticleEffect, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC3E0);
	static inline auto FAttachParticleEffectOv0 = PreyFunction<unsigned(EntityEffects::CEffectsController *const _this, const char *effectName, const int targetSlot, const char *helperName, EntityEffects::SEffectAttachParams const &attachParams)>(0x16BC9F0);
	static inline auto FDetachEffect = PreyFunction<void(EntityEffects::CEffectsController *const _this, const unsigned effectId)>(0x16BCA40);
	static inline auto FGetEffectEmitter = PreyFunction<IParticleEmitter *(EntityEffects::CEffectsController const *const _this, const unsigned effectId)>(0x16BCD20);
	static inline auto FFindSafeSlot = PreyFunction<int(EntityEffects::CEffectsController *const _this, int firstSafeSlot)>(0x16BCBD0);
};

} // namespace EntityEffects

