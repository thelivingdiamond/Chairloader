// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryParticleSystem/IParticles.h>
#include <Prey/GameDll/EntityUtility/EntityEffects.h>

class ArkSafeScriptTable;
namespace EntityEffects
{
class ArkEffectsCharacterController;
class CEffectsController;
struct SEffectAttachParams;
} // namespace EntityEffects
struct ICharacterInstance;
class ICrySizer;
struct IEntity;
struct IGameObjectExtension;
struct IParticleEffect;
struct IParticleEmitter;
struct ParticleLoc;

// ArkEffectBase
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEffectBase
{ // Size=64 (0x40)
public:
	_smart_ptr<IParticleEffect> m_pEffect;
	SpawnParams m_spawnParams;

	bool LoadEffect(IParticleEffect* _pEffect) { return FLoadEffectOv2(this, _pEffect); }
	bool LoadEffect(const char* _szEffectName) { return FLoadEffectOv1(this, _szEffectName); }
	bool LoadEffect(const ArkSafeScriptTable& _table, const char* _szKey) { return FLoadEffectOv0(this, _table, _szKey); }

#if 0
	bool IsLoaded() const;
	IParticleEffect* GetEffect() const;
	SpawnParams& GetParams();
	const SpawnParams& GetParams() const;
	ArkEffectBase();
	ArkEffectBase(IParticleEffect* _arg0_);
#endif

	static inline auto FLoadEffectOv2 = PreyFunction<bool(ArkEffectBase* const _this, IParticleEffect* _pEffect)>(0x11A6440);
	static inline auto FLoadEffectOv1 = PreyFunction<bool(ArkEffectBase* const _this, const char* _szEffectName)>(0x11A6480);
	static inline auto FLoadEffectOv0 = PreyFunction<bool(ArkEffectBase* const _this, const ArkSafeScriptTable& _table, const char* _szKey)>(0x11A63B0);
};

// ArkEntityEffectBase
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEntityEffectBase : public ArkEffectBase
{ // Size=128 (0x80)
public:
	Matrix34 m_localTM;
	int m_nSlot;
	bool m_bStarted;
	bool m_bSerialize;

	~ArkEntityEffectBase();
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	void SetLocalTM(const Matrix34& _localTM) { FSetLocalTM(this, _localTM); }
	void SetForceVAClip(bool _bForceVAClip) { FSetForceVAClip(this, _bForceVAClip); }
	void SetSizeScale(float _fSizeScale) { FSetSizeScale(this, _fSizeScale); }
	void SetTimeScale(float _fTimeScale) { FSetTimeScale(this, _fTimeScale); }
	void SetPulsePeriod(float _fPulsePeriod) { FSetPulsePeriod(this, _fPulsePeriod); }
	void SetStrength(float _fStrength) { FSetStrength(this, _fStrength); }
	virtual IEntity* GetEntity() const = 0;

#if 0
	void SetUseUITimer(bool _arg0_);
	void SetSpeedScale(float _arg0_);
	void UpdateParams();
	bool HasStarted() const;
	int GetSlot() const;
	ArkEntityEffectBase(int _arg0_, bool _arg1_);
	IParticleEmitter* GetEmitter();
	IParticleEmitter* GetActiveEmitter();
#endif

	static inline auto FBitNotArkEntityEffectBase = PreyFunction<void(ArkEntityEffectBase* const _this)>(0x11A5A50);
	static inline auto FStart = PreyFunction<void(ArkEntityEffectBase* const _this)>(0x11A6B20);
	static inline auto FStop = PreyFunction<void(ArkEntityEffectBase* const _this)>(0x11A6DB0);
	static inline auto FKill = PreyFunction<void(ArkEntityEffectBase* const _this)>(0x11A62E0);
	static inline auto FSetLocalTM = PreyFunction<void(ArkEntityEffectBase* const _this, const Matrix34& _localTM)>(0x11A65C0);
	static inline auto FSetForceVAClip = PreyFunction<void(ArkEntityEffectBase* const _this, bool _bForceVAClip)>(0x11A6570);
	static inline auto FSetSizeScale = PreyFunction<void(ArkEntityEffectBase* const _this, float _fSizeScale)>(0x11A6840);
	static inline auto FSetTimeScale = PreyFunction<void(ArkEntityEffectBase* const _this, float _fTimeScale)>(0x11A69D0);
	static inline auto FSetPulsePeriod = PreyFunction<void(ArkEntityEffectBase* const _this, float _fPulsePeriod)>(0x11A6730);
	static inline auto FSetStrength = PreyFunction<void(ArkEntityEffectBase* const _this, float _fStrength)>(0x11A68F0);
};

// ArkCharacterAttachmentEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkCharacterAttachmentEffect : public ArkEffectBase
{ // Size=88 (0x58)
public:
	EntityEffects::ArkEffectsCharacterController& m_controller;
	string m_attachmentName;
	int m_attachmentSlot;
	unsigned m_effectId;

	ArkCharacterAttachmentEffect(EntityEffects::ArkEffectsCharacterController& _controller, int _attachmentSlot);
	~ArkCharacterAttachmentEffect();
	void SetAttachmentName(const char* _szAttachmentName) { FSetAttachmentName(this, _szAttachmentName); }
	void Start() { FStart(this); }
	void Kill() { FKill(this); }
	IParticleEmitter* GetEmitter() const { return FGetEmitter(this); }

#if 0
	void SetAttachmentSlot(int _arg0_);
	void Stop();
	void SetStrength(float _arg0_);
	void SetTarget(const Vec3& _arg0_);
	void UpdateParams();
#endif

	static inline auto FArkCharacterAttachmentEffectOv1 = PreyFunction<void(ArkCharacterAttachmentEffect* const _this, EntityEffects::ArkEffectsCharacterController& _controller, int _attachmentSlot)>(0x11A5630);
	static inline auto FBitNotArkCharacterAttachmentEffect = PreyFunction<void(ArkCharacterAttachmentEffect* const _this)>(0x11A59F0);
	static inline auto FSetAttachmentName = PreyFunction<void(ArkCharacterAttachmentEffect* const _this, const char* _szAttachmentName)>(0x11A6560);
	static inline auto FStart = PreyFunction<void(ArkCharacterAttachmentEffect* const _this)>(0x11A6A40);
	static inline auto FKill = PreyFunction<void(ArkCharacterAttachmentEffect* const _this)>(0x11A6250);
	static inline auto FGetEmitter = PreyFunction<IParticleEmitter* (const ArkCharacterAttachmentEffect* const _this)>(0x11A60B0);
};

// ArkEntityAttachmentEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEntityAttachmentEffect : public ArkEffectBase
{ // Size=88 (0x58)
public:
	EntityEffects::CEffectsController& m_controller;
	string m_attachmentName;
	int m_attachmentSlot;
	unsigned m_effectId;

	ArkEntityAttachmentEffect(EntityEffects::CEffectsController& _controller, int _attachmentSlot);
	~ArkEntityAttachmentEffect();
	void SetAttachmentName(const char* _szAttachmentName) { FSetAttachmentName(this, _szAttachmentName); }
	void SetAttachmentSlot(int _attachmentSlot) { FSetAttachmentSlot(this, _attachmentSlot); }
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	void SetStrength(float _fStrength) { FSetStrength(this, _fStrength); }
	void SetTarget(const Vec3& _targetPos) { FSetTarget(this, _targetPos); }

#if 0
	void UpdateParams();
	IParticleEmitter* GetEmitter() const;
#endif

	static inline auto FArkEntityAttachmentEffectOv1 = PreyFunction<void(ArkEntityAttachmentEffect* const _this, EntityEffects::CEffectsController& _controller, int _attachmentSlot)>(0x11A5630);
	static inline auto FBitNotArkEntityAttachmentEffect = PreyFunction<void(ArkEntityAttachmentEffect* const _this)>(0x11A59F0);
	static inline auto FSetAttachmentName = PreyFunction<void(ArkEntityAttachmentEffect* const _this, const char* _szAttachmentName)>(0x11A6560);
	static inline auto FSetAttachmentSlot = PreyFunction<void(ArkEntityAttachmentEffect* const _this, int _attachmentSlot)>(0x2B1E20);
	static inline auto FStart = PreyFunction<void(ArkEntityAttachmentEffect* const _this)>(0x11A6AB0);
	static inline auto FStop = PreyFunction<void(ArkEntityAttachmentEffect* const _this)>(0x11A6D50);
	static inline auto FKill = PreyFunction<void(ArkEntityAttachmentEffect* const _this)>(0x11A6290);
	static inline auto FSetStrength = PreyFunction<void(ArkEntityAttachmentEffect* const _this, float _fStrength)>(0x11A68B0);
	static inline auto FSetTarget = PreyFunction<void(ArkEntityAttachmentEffect* const _this, const Vec3& _targetPos)>(0x11A6960);
};

// ArkEntityEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEntityEffect : public ArkEntityEffectBase
{ // Size=136 (0x88)
public:
	IGameObjectExtension& m_owner;

	ArkEntityEffect(IGameObjectExtension& _owner, int _nSlot, bool _bSerialize);
	virtual IEntity* GetEntity() const;

	static inline auto FArkEntityEffectOv2 = PreyFunction<void(ArkEntityEffect* const _this, IGameObjectExtension& _owner, int _nSlot, bool _bSerialize)>(0x11A5690);
	static inline auto FGetEntity = PreyFunction<IEntity* (const ArkEntityEffect* const _this)>(0x11A6160);
};

// ArkEntityPointerEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEntityPointerEffect : public ArkEntityEffectBase
{ // Size=136 (0x88)
public:
	IEntity* m_pOwnerEntity;

	ArkEntityPointerEffect(IEntity& _ownerEntity, int _nSlot, bool _bSerialize);
	virtual IEntity* GetEntity() const;

	static inline auto FArkEntityPointerEffectOv2 = PreyFunction<void(ArkEntityPointerEffect* const _this, IEntity& _ownerEntity, int _nSlot, bool _bSerialize)>(0x11A5730);
	static inline auto FGetEntity = PreyFunction<IEntity* (const ArkEntityPointerEffect* const _this)>(0x510580);
};

// ArkFireAndForgetEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkFireAndForgetEffect : public ArkEffectBase
{ // Size=64 (0x40)
public:
	ArkFireAndForgetEffect();
	ArkFireAndForgetEffect(IParticleEffect* _pEffect);
	~ArkFireAndForgetEffect();
	void Start(const QuatTS& _location) const { FStart(this, _location); }

	static inline auto FArkFireAndForgetEffectOv2 = PreyFunction<void(ArkFireAndForgetEffect* const _this)>(0x11A5860);
	static inline auto FArkFireAndForgetEffectOv1 = PreyFunction<void(ArkFireAndForgetEffect* const _this, IParticleEffect* _pEffect)>(0x11A57D0);
	static inline auto FBitNotArkFireAndForgetEffect = PreyFunction<void(ArkFireAndForgetEffect* const _this)>(0x11A5AA0);
	static inline auto FStart = PreyFunction<void(const ArkFireAndForgetEffect* const _this, const QuatTS& _location)>(0x11A6C60);
};

// ArkLooseEffect
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkLooseEffect : public ArkEffectBase
{ // Size=112 (0x70)
public:
	_smart_ptr<IParticleEmitter> m_pEmitter;
	QuatTS m_location;
	bool m_bStarted;

	ArkLooseEffect();
	~ArkLooseEffect();
	void Start() { FStart(this); }
	void Stop() { FStop(this); }
	void Kill() { FKill(this); }
	bool OnEmitterDeletedExternally(IParticleEmitter* _pEmitter) { return FOnEmitterDeletedExternally(this, _pEmitter); }
	void SetLocation(const ParticleLoc& _location) { FSetLocationOv1(this, _location); }
	void SetLocation(const Vec3& _position, const Vec3& _direction) { FSetLocationOv0(this, _position, _direction); }
	void SetRotation(const Quat& _rotation) { FSetRotation(this, _rotation); }
	const QuatTS& GetLocation() const { return FGetLocation(this); }
	void SetUseUITimer(bool _bUseUITimer) { FSetUseUITimer(this, _bUseUITimer); }
	void SetSizeScale(float _fSizeScale) { FSetSizeScale(this, _fSizeScale); }
	void SetStrength(float _fStrength) { FSetStrength(this, _fStrength); }

#if 0
	void SetSpeedScale(float _arg0_);
	void SetTimeScale(float _arg0_);
	void UpdateParams();
	bool HasStarted() const;
#endif

	static inline auto FArkLooseEffectOv1 = PreyFunction<void(ArkLooseEffect* const _this)>(0x11A58B0);
	static inline auto FBitNotArkLooseEffect = PreyFunction<void(ArkLooseEffect* const _this)>(0x11A5AE0);
	static inline auto FStart = PreyFunction<void(ArkLooseEffect* const _this)>(0x11A6CA0);
	static inline auto FStop = PreyFunction<void(ArkLooseEffect* const _this)>(0x11A6E20);
	static inline auto FKill = PreyFunction<void(ArkLooseEffect* const _this)>(0x11A6340);
	static inline auto FOnEmitterDeletedExternally = PreyFunction<bool(ArkLooseEffect* const _this, IParticleEmitter* _pEmitter)>(0x11A64E0);
	static inline auto FSetLocationOv1 = PreyFunction<void(ArkLooseEffect* const _this, const ParticleLoc& _location)>(0x11A66E0);
	static inline auto FSetLocationOv0 = PreyFunction<void(ArkLooseEffect* const _this, const Vec3& _position, const Vec3& _direction)>(0x11A6670);
	static inline auto FSetRotation = PreyFunction<void(ArkLooseEffect* const _this, const Quat& _rotation)>(0x11A6780);
	static inline auto FGetLocation = PreyFunction<const QuatTS& (const ArkLooseEffect* const _this)>(0x10ED490);
	static inline auto FSetUseUITimer = PreyFunction<void(ArkLooseEffect* const _this, bool _bUseUITimer)>(0x11A6A20);
	static inline auto FSetSizeScale = PreyFunction<void(ArkLooseEffect* const _this, float _fSizeScale)>(0x11A6890);
	static inline auto FSetStrength = PreyFunction<void(ArkLooseEffect* const _this, float _fStrength)>(0x11A6940);
};

namespace EntityEffects
{

// EntityEffects::ArkEffectsCharacterController
// Header:  Prey/GameDll/ark/arkeffectutils.h
class ArkEffectsCharacterController
{ // Size=40 (0x28)
public:
	using TAttachedEffects = std::vector<EntityEffects::SEffectInfo>;

	ICharacterInstance* m_pOwnerCharacter;
	std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
	unsigned m_effectGeneratorId;

	ArkEffectsCharacterController();
	void InitWithCharacter(ICharacterInstance* pCharacter) { FInitWithCharacter(this, pCharacter); }
	void FreeAllEffects() { FFreeAllEffects(this); }
	unsigned AttachParticleEffect(IParticleEffect* pParticleEffect, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams) { return FAttachParticleEffectOv1(this, pParticleEffect, targetSlot, helperName, attachParams); }
	void DetachEffect(const unsigned effectId) { FDetachEffect(this, effectId); }

#if 0
	void RemoveCharacter();
	unsigned AttachParticleEffect(const char* _arg0_, const int _arg1_, const char* _arg2_, const EntityEffects::SEffectAttachParams& _arg3_);
	IParticleEmitter* GetEffectEmitter(const unsigned _arg0_) const;
	void GetMemoryStatistics(ICrySizer* _arg0_) const;
	bool IsValid() const;
#endif

	static inline auto FArkEffectsCharacterControllerOv2 = PreyFunction<void(EntityEffects::ArkEffectsCharacterController* const _this)>(0x17DEB20);
	static inline auto FInitWithCharacter = PreyFunction<void(EntityEffects::ArkEffectsCharacterController* const _this, ICharacterInstance* pCharacter)>(0x14AD1A0);
	static inline auto FFreeAllEffects = PreyFunction<void(EntityEffects::ArkEffectsCharacterController* const _this)>(0x11A6010);
	static inline auto FAttachParticleEffectOv1 = PreyFunction<unsigned(EntityEffects::ArkEffectsCharacterController* const _this, IParticleEffect* pParticleEffect, const int targetSlot, const char* helperName, const EntityEffects::SEffectAttachParams& attachParams)>(0x11A5BB0);
	static inline auto FDetachEffect = PreyFunction<void(EntityEffects::ArkEffectsCharacterController* const _this, const unsigned effectId)>(0x11A5EA0);
};


} // namespace EntityEffects
#endif // !MOONCRASH
