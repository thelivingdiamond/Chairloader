// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/itemstring.h>

namespace EntityEffects
{
struct SEffectAttachParams;
struct SLightAttachParams;
} // namespace EntityEffects
class ICrySizer;
struct IEntity;
struct ILightSource;
struct IParticleEffect;
struct IParticleEmitter;
struct IRenderNode;

namespace EntityEffects
{

// EntityEffects::SEffectInfo
// Header:  Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectInfo
{ // Size=24 (0x18)
	unsigned id;
	int entityEffectSlot;
	int characterEffectSlot;
	SharedString::CSharedString helperName;

#if 0
	SEffectInfo();
	bool operator==(const unsigned& _arg0_) const;
#endif
};

// EntityEffects::CEffectsController
// Header:  Prey/GameDll/EntityUtility/EntityEffects.h
class CEffectsController
{ // Size=40 (0x28)
public:
	using TAttachedEffects = std::vector<EntityEffects::SEffectInfo>;

	IEntity* m_pOwnerEntity;
	std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
	unsigned m_effectGeneratorId;

	CEffectsController();
	void InitWithEntity(IEntity* pEntity) { FInitWithEntity(this, pEntity); }
	void FreeAllEffects() { FFreeAllEffects(this); }
	unsigned AttachParticleEffect(IParticleEffect* pParticleEffect, const EntityEffects::SEffectAttachParams& attachParams) { return FAttachParticleEffectOv3(this, pParticleEffect, attachParams); }
	unsigned AttachParticleEffect(const char* effectName, const EntityEffects::SEffectAttachParams& attachParams) { return FAttachParticleEffectOv2(this, effectName, attachParams); }
	unsigned AttachParticleEffect(IParticleEffect* pParticleEffect, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams) { return FAttachParticleEffectOv1(this, pParticleEffect, targetSlot, helperName, attachParams); }
	unsigned AttachParticleEffect(const char* effectName, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams) { return FAttachParticleEffectOv0(this, effectName, targetSlot, helperName, attachParams); }
	void DetachEffect(const unsigned effectId) { FDetachEffect(this, effectId); }
	IParticleEmitter* GetEffectEmitter(const unsigned effectId) const { return FGetEffectEmitter(this, effectId); }
	int FindSafeSlot(int firstSafeSlot) { return FFindSafeSlot(this, firstSafeSlot); }

#if 0
	void RemoveCharacter();
	unsigned AttachLight(const int _arg0_, const char* _arg1_, const EntityEffects::SLightAttachParams& _arg2_);
	const EntityEffects::SEffectInfo& GetEffectInfoAt(const unsigned _arg0_) const;
	unsigned GetEffectCount() const;
	ILightSource* GetLightSource(const unsigned _arg0_) const;
	void SetEffectWorldTM(const unsigned _arg0_, const Matrix34& _arg1_);
	void UpdateEntitySlotEffectLocationsFromHelpers();
	void GetMemoryStatistics(ICrySizer* _arg0_) const;
#endif

	static inline auto FCEffectsControllerOv2 = PreyFunction<void(EntityEffects::CEffectsController* const _this)>(0x17DEB20);
	static inline auto FInitWithEntity = PreyFunction<void(EntityEffects::CEffectsController* const _this, IEntity* pEntity)>(0x14AD1A0);
	static inline auto FFreeAllEffects = PreyFunction<void(EntityEffects::CEffectsController* const _this)>(0x17DF6A0);
	static inline auto FAttachParticleEffectOv3 = PreyFunction<unsigned(EntityEffects::CEffectsController* const _this, IParticleEffect* pParticleEffect, const EntityEffects::SEffectAttachParams& attachParams)>(0x17DEB40);
	static inline auto FAttachParticleEffectOv2 = PreyFunction<unsigned(EntityEffects::CEffectsController* const _this, const char* effectName, const EntityEffects::SEffectAttachParams& attachParams)>(0x17DF3D0);
	static inline auto FAttachParticleEffectOv1 = PreyFunction<unsigned(EntityEffects::CEffectsController* const _this, IParticleEffect* pParticleEffect, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams)>(0x17DEE00);
	static inline auto FAttachParticleEffectOv0 = PreyFunction<unsigned(EntityEffects::CEffectsController* const _this, const char* effectName, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams)>(0x17DF410);
	static inline auto FDetachEffect = PreyFunction<void(EntityEffects::CEffectsController* const _this, const unsigned effectId)>(0x17DF460);
	static inline auto FGetEffectEmitter = PreyFunction<IParticleEmitter* (const EntityEffects::CEffectsController* const _this, const unsigned effectId)>(0x17DF740);
	static inline auto FFindSafeSlot = PreyFunction<int(EntityEffects::CEffectsController* const _this, int firstSafeSlot)>(0x17DF5F0);
};

// EntityEffects::SEffectAttachParams
// Header:  Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectAttachParams
{ // Size=36 (0x24)
	Vec3 offset;
	Vec3 direction;
	float scale;
	int firstSafeSlot;
	bool prime;

#if 0
	SEffectAttachParams();
	SEffectAttachParams(const Vec3& _arg0_, const Vec3& _arg1_, const float _arg2_, const bool _arg3_, const int _arg4_);
#endif
};

// EntityEffects::SEffectSpawnParams
// Header:  Prey/GameDll/EntityUtility/EntityEffects.h
struct SEffectSpawnParams
{ // Size=36 (0x24)
	Vec3 position;
	Vec3 direction;
	float scale;
	float speed;
	bool prime;

#if 0
	SEffectSpawnParams(const Vec3& _arg0_);
	SEffectSpawnParams(const Vec3& _arg0_, const Vec3& _arg1_, const float _arg2_, const float _arg3_, const bool _arg4_);
#endif
};

// EntityEffects::SLightAttachParams
// Header:  Prey/GameDll/EntityUtility/EntityEffects.h
struct SLightAttachParams
{ // Size=104 (0x68)
	IRenderNode* pCasterException;
	Vec3 color;
	Vec3 offset;
	Vec3 direction;
	float radius;
	float specularMultiplier;
	float diffuseMultiplier;
	float projectFov;
	float hdrDynamic;
	const char* projectTexture;
	const char* material;
	int style;
	float animSpeed;
	int firstSafeSlot;
	bool deferred;
	bool castShadows;
	bool fakelight;
	const char* lensflare;

#if 0
	SLightAttachParams();
#endif
};


} // namespace EntityEffects
#endif // !MOONCRASH
