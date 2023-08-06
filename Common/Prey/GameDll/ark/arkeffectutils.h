// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryParticleSystem/IParticles.h>

class ArkSafeScriptTable;
namespace EntityEffects
{
class CEffectsController;
} // namespace EntityEffects
struct IEntity;
struct IGameObjectExtension;
struct IParticleEffect;
struct IParticleEmitter;
struct ParticleLoc;

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkEffectBase // Id=80134D1 Size=64
{
public:
	_smart_ptr<IParticleEffect> m_pEffect;
	SpawnParams m_spawnParams;
	
	bool LoadEffect(IParticleEffect *_pEffect) { return FLoadEffectOv2(this,_pEffect); }
	bool LoadEffect(const char *_szEffectName) { return FLoadEffectOv1(this,_szEffectName); }
	bool LoadEffect(ArkSafeScriptTable const &_table, const char *_szKey) { return FLoadEffectOv0(this,_table,_szKey); }
	
#if 0
	bool IsLoaded() const;
	IParticleEffect *GetEffect() const;
	SpawnParams &GetParams();
	SpawnParams const &GetParams() const;
#endif
	
	static inline auto FLoadEffectOv2 = PreyFunction<bool(ArkEffectBase *const _this, IParticleEffect *_pEffect)>(0x1157AB0);
	static inline auto FLoadEffectOv1 = PreyFunction<bool(ArkEffectBase *const _this, const char *_szEffectName)>(0x1157AF0);
	static inline auto FLoadEffectOv0 = PreyFunction<bool(ArkEffectBase *const _this, ArkSafeScriptTable const &_table, const char *_szKey)>(0x1157A20);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkLooseEffect : public ArkEffectBase // Id=80134D0 Size=112
{
public:
	_smart_ptr<IParticleEmitter> m_pEmitter;
	QuatTS m_location;
	bool m_bStarted;
	
	ArkLooseEffect();
	~ArkLooseEffect();
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	bool OnEmitterDeletedExternally(IParticleEmitter *_pEmitter) { return FOnEmitterDeletedExternally(this,_pEmitter); }
	void SetLocation(ParticleLoc const &_location) { FSetLocationOv1(this,_location); }
	void SetLocation(Vec3 const &_position, Vec3 const &_direction) { FSetLocationOv0(this,_position,_direction); }
	void SetRotation(Quat const &_rotation) { FSetRotation(this,_rotation); }
	QuatTS const &GetLocation() const { return FGetLocation(this); }
	void SetUseUITimer(bool _bUseUITimer) { FSetUseUITimer(this,_bUseUITimer); }
	void SetSizeScale(float _fSizeScale) { FSetSizeScale(this,_fSizeScale); }
	
#if 0
	void SetSpeedScale(float arg0);
	void SetTimeScale(float arg0);
	void SetStrength(float arg0);
	void UpdateParams();
	bool HasStarted() const;
#endif
	
	static inline auto FBitNotArkLooseEffect = PreyFunction<void(ArkLooseEffect *const _this)>(0x1157820);
	static inline auto FStart = PreyFunction<void(ArkLooseEffect *const _this)>(0x11582F0);
	static inline auto FStop = PreyFunction<void(ArkLooseEffect *const _this)>(0x1158470);
	static inline auto FKill = PreyFunction<void(ArkLooseEffect *const _this)>(0x11579B0);
	static inline auto FOnEmitterDeletedExternally = PreyFunction<bool(ArkLooseEffect *const _this, IParticleEmitter *_pEmitter)>(0x1157B50);
	static inline auto FSetLocationOv1 = PreyFunction<void(ArkLooseEffect *const _this, ParticleLoc const &_location)>(0x1157E30);
	static inline auto FSetLocationOv0 = PreyFunction<void(ArkLooseEffect *const _this, Vec3 const &_position, Vec3 const &_direction)>(0x1157DC0);
	static inline auto FSetRotation = PreyFunction<void(ArkLooseEffect *const _this, Quat const &_rotation)>(0x1157ED0);
	static inline auto FGetLocation = PreyFunction<QuatTS const &(ArkLooseEffect const *const _this)>(0x222910);
	static inline auto FSetUseUITimer = PreyFunction<void(ArkLooseEffect *const _this, bool _bUseUITimer)>(0x11580E0);
	static inline auto FSetSizeScale = PreyFunction<void(ArkLooseEffect *const _this, float _fSizeScale)>(0x1157FE0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkFireAndForgetEffect : public ArkEffectBase // Id=80141EF Size=64
{
public:
	ArkFireAndForgetEffect() = default;
	ArkFireAndForgetEffect(IParticleEffect* _pEffect) { LoadEffect(_pEffect); }
	~ArkFireAndForgetEffect() = default;
	void Start(QuatTS const &_location) const { FStart(this,_location); }
	
	static inline auto FBitNotArkFireAndForgetEffect = PreyFunction<void(ArkFireAndForgetEffect *const _this)>(0x11577E0);
	static inline auto FStart = PreyFunction<void(ArkFireAndForgetEffect const *const _this, QuatTS const &_location)>(0x11582B0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkEntityEffectBase : public ArkEffectBase // Id=801422F Size=128
{
public:
	Matrix34 m_localTM = Matrix34(IDENTITY);
	int m_nSlot = -1;
	bool m_bStarted = false;
	bool m_bSerialize = false;
	
	~ArkEntityEffectBase() {}
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	void SetLocalTM(Matrix34 const &_localTM) { FSetLocalTM(this,_localTM); }
	void SetForceVAClip(bool _bForceVAClip) { FSetForceVAClip(this,_bForceVAClip); }
	void SetSizeScale(float _fSizeScale) { FSetSizeScale(this,_fSizeScale); }
	void SetTimeScale(float _fTimeScale) { FSetTimeScale(this,_fTimeScale); }
	void SetPulsePeriod(float _fPulsePeriod) { FSetPulsePeriod(this,_fPulsePeriod); }
	void SetStrength(float _fStrength) { FSetStrength(this,_fStrength); }
	virtual IEntity *GetEntity() const = 0;
	
#if 0
	void SetUseUITimer(bool arg0);
	void SetSpeedScale(float arg0);
	void UpdateParams();
	bool HasStarted() const;
	int GetSlot() const;
	IParticleEmitter *GetEmitter();
	IParticleEmitter *GetActiveEmitter();
#endif
	
	static inline auto FBitNotArkEntityEffectBase = PreyFunction<void(ArkEntityEffectBase *const _this)>(0x1157790);
	static inline auto FStart = PreyFunction<void(ArkEntityEffectBase *const _this)>(0x1158170);
	static inline auto FStop = PreyFunction<void(ArkEntityEffectBase *const _this)>(0x1158400);
	static inline auto FKill = PreyFunction<void(ArkEntityEffectBase *const _this)>(0x1157950);
	static inline auto FSetLocalTM = PreyFunction<void(ArkEntityEffectBase *const _this, Matrix34 const &_localTM)>(0x1157D10);
	static inline auto FSetForceVAClip = PreyFunction<void(ArkEntityEffectBase *const _this, bool _bForceVAClip)>(0x1157CC0);
	static inline auto FSetSizeScale = PreyFunction<void(ArkEntityEffectBase *const _this, float _fSizeScale)>(0x1157F90);
	static inline auto FSetTimeScale = PreyFunction<void(ArkEntityEffectBase *const _this, float _fTimeScale)>(0x1158090);
	static inline auto FSetPulsePeriod = PreyFunction<void(ArkEntityEffectBase *const _this, float _fPulsePeriod)>(0x1157E80);
	static inline auto FSetStrength = PreyFunction<void(ArkEntityEffectBase *const _this, float _fStrength)>(0x1158040);
};

// Header: Exact
// Prey/GameDll/ark/arkeffectutils.h
class ArkEntityEffect : public ArkEntityEffectBase // Id=801422E Size=136
{
public:
	IGameObjectExtension &m_owner;
	
	ArkEntityEffect(IGameObjectExtension& _owner, int _nSlot, bool _bSerialize)
		: m_owner(_owner)
	{
		m_nSlot = _nSlot;
		m_bSerialize = _nSlot;
	}

	virtual IEntity* GetEntity() const { return FGetEntity(this); }
	
	static inline auto FGetEntity = PreyFunction<IEntity *(ArkEntityEffect const *const _this)>(0x11578F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkEntityPointerEffect : public ArkEntityEffectBase // Id=8016E4C Size=136
{
public:
	IEntity *m_pOwnerEntity;
	
	ArkEntityPointerEffect(IEntity &_ownerEntity, int _nSlot, bool _bSerialize);
	virtual IEntity *GetEntity() const;
	
	static inline auto FGetEntity = PreyFunction<IEntity *(ArkEntityPointerEffect const *const _this)>(0x16A1030);
};

// Header: FromCpp
// Prey/GameDll/ark/arkeffectutils.h
class ArkEntityAttachmentEffect : public ArkEffectBase // Id=8014423 Size=88
{
public:
	EntityEffects::CEffectsController &m_controller;
	string m_attachmentName;
	int m_attachmentSlot;
	unsigned m_effectId = 0;
	
	ArkEntityAttachmentEffect(EntityEffects::CEffectsController& _controller, int _attachmentSlot)
		: m_controller(_controller)
	{
		m_attachmentSlot = _attachmentSlot;
	}

	void SetAttachmentName(const char *_szAttachmentName) { FSetAttachmentName(this,_szAttachmentName); }
	void SetAttachmentSlot(int _attachmentSlot) { FSetAttachmentSlot(this,_attachmentSlot); }
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	void SetStrength(float _fStrength) { FSetStrength(this,_fStrength); }
	
#if 0
	void UpdateParams();
	IParticleEmitter *GetEmitter() const;
#endif
	
	static inline auto FBitNotArkEntityAttachmentEffect = PreyFunction<void(ArkEntityAttachmentEffect *const _this)>(0x1157730);
	static inline auto FSetAttachmentName = PreyFunction<void(ArkEntityAttachmentEffect *const _this, const char *_szAttachmentName)>(0x1157BD0);
	static inline auto FSetAttachmentSlot = PreyFunction<void(ArkEntityAttachmentEffect *const _this, int _attachmentSlot)>(0x1157CB0);
	static inline auto FStart = PreyFunction<void(ArkEntityAttachmentEffect *const _this)>(0x1158100);
	static inline auto FStop = PreyFunction<void(ArkEntityAttachmentEffect *const _this)>(0x11583A0);
	static inline auto FKill = PreyFunction<void(ArkEntityAttachmentEffect *const _this)>(0x1157900);
	static inline auto FSetStrength = PreyFunction<void(ArkEntityAttachmentEffect *const _this, float _fStrength)>(0x1158000);
};

