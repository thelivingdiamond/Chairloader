// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/CryArray.h>

struct AABB;
class CDLight;
struct IAttachment;
struct IAttachmentManager;
struct IAttachmentSkin;
struct ICharacterInstance;
struct ILightSource;
struct IMaterial;
struct IParticleEffect;
struct IParticleEmitter;
struct IPhysicalEntity;
struct IStatObj;
struct SRendParams;
struct SRenderingPassInfo;
struct SpawnParams;

// IAttachmentObject
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct IAttachmentObject
{ // Size=8 (0x8)
	enum EType
	{
		eAttachment_Unknown = 0,
		eAttachment_StatObj = 1,
		eAttachment_Skeleton = 2,
		eAttachment_SkinMesh = 3,
		eAttachment_Entity = 4,
		eAttachment_Light = 5,
		eAttachment_Effect = 6,
		eAttachment_MultiEffect = 7,
	};

	virtual ~IAttachmentObject();
	virtual IAttachmentObject::EType GetAttachmentType() = 0;
	virtual void ProcessAttachment(IAttachment* pIAttachment) = 0;
	virtual void RenderAttachment(SRendParams& rParams, const SRenderingPassInfo& passInfo);
	virtual bool PhysicalizeAttachment(IAttachmentManager* pManager, int idx, int nLod, IPhysicalEntity* pent, const Vec3& offset);
	virtual bool UpdatePhysicalizedAttachment(IAttachmentManager* pManager, int idx, IPhysicalEntity* pent, const QuatT& offset);
	virtual AABB GetAABB() const = 0;
	virtual float GetRadiusSqr() const = 0;
	virtual IStatObj* GetIStatObj() const;
	virtual ICharacterInstance* GetICharacterInstance() const;
	virtual IAttachmentSkin* GetIAttachmentSkin() const;
	virtual const char* GetObjectFilePath() const;
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const = 0;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD) = 0;
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const = 0;
	virtual void OnRemoveAttachment(IAttachmentManager* pManager, int idx);
	virtual void Release() = 0;

#ifndef MOONCRASH
	static inline auto FRenderAttachment = PreyFunction<void(IAttachmentObject* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0xA13080);
	static inline auto FPhysicalizeAttachment = PreyFunction<bool(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx, int nLod, IPhysicalEntity* pent, const Vec3& offset)>(0xDD23F0);
	static inline auto FUpdatePhysicalizedAttachment = PreyFunction<bool(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx, IPhysicalEntity* pent, const QuatT& offset)>(0xDD23F0);
	static inline auto FGetIStatObj = PreyFunction<IStatObj* (const IAttachmentObject* const _this)>(0x158AEF0);
	static inline auto FGetICharacterInstance = PreyFunction<ICharacterInstance* (const IAttachmentObject* const _this)>(0x158AEF0);
	static inline auto FGetIAttachmentSkin = PreyFunction<IAttachmentSkin* (const IAttachmentObject* const _this)>(0x158AEF0);
	static inline auto FGetObjectFilePath = PreyFunction<const char* (const IAttachmentObject* const _this)>(0x3356A0);
	static inline auto FOnRemoveAttachment = PreyFunction<void(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx)>(0xA13080);
#else
	static inline auto FRenderAttachment = PreyFunction<void(IAttachmentObject* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0x1333E90);
	static inline auto FPhysicalizeAttachment = PreyFunction<bool(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx, int nLod, IPhysicalEntity* pent, const Vec3& offset)>(0x13B0900);
	static inline auto FUpdatePhysicalizedAttachment = PreyFunction<bool(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx, IPhysicalEntity* pent, const QuatT& offset)>(0x13B0900);
	static inline auto FGetIStatObj = PreyFunction<IStatObj* (const IAttachmentObject* const _this)>(0x1CBB0B0);
	static inline auto FGetICharacterInstance = PreyFunction<ICharacterInstance* (const IAttachmentObject* const _this)>(0x1CBB0B0);
	static inline auto FGetIAttachmentSkin = PreyFunction<IAttachmentSkin* (const IAttachmentObject* const _this)>(0x1CBB0B0);
	static inline auto FGetObjectFilePath = PreyFunction<const char* (const IAttachmentObject* const _this)>(0x34F170);
	static inline auto FOnRemoveAttachment = PreyFunction<void(IAttachmentObject* const _this, IAttachmentManager* pManager, int idx)>(0x1333E90);
#endif
};

// CCGFAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CCGFAttachment : public IAttachmentObject
{ // Size=24 (0x18)
	_smart_ptr<IStatObj> pObj;
	_smart_ptr<IMaterial> m_pReplacementMaterial;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual void RenderAttachment(SRendParams& rParams, const SRenderingPassInfo& passInfo);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual IStatObj* GetIStatObj() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CCGFAttachment* const _this)>(0x1B1DEA0);
	static inline auto FProcessAttachment = PreyFunction<void(CCGFAttachment* const _this, IAttachment* pIAttachment)>(0xA13080);
	static inline auto FRenderAttachment = PreyFunction<void(CCGFAttachment* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0x335750);
	static inline auto FGetAABB = PreyFunction<AABB*(const CCGFAttachment* const _this, AABB* _return_value_)>(0x3357C0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CCGFAttachment* const _this)>(0x3357E0);
	static inline auto FGetIStatObj = PreyFunction<IStatObj* (const CCGFAttachment* const _this)>(0x12AAC70);
	static inline auto FRelease = PreyFunction<void(CCGFAttachment* const _this)>(0xA97D40);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CCGFAttachment* const _this, unsigned nLOD)>(0x335800);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CCGFAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x335820);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CCGFAttachment* const _this, unsigned nLOD)>(0x5BFB50);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CCGFAttachment* const _this)>(0x1948930);
	static inline auto FProcessAttachment = PreyFunction<void(CCGFAttachment* const _this, IAttachment* pIAttachment)>(0x1333E90);
	static inline auto FRenderAttachment = PreyFunction<void(CCGFAttachment* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0x34F220);
	static inline auto FGetAABB = PreyFunction<AABB*(const CCGFAttachment* const _this, AABB* _return_value_)>(0x34F290);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CCGFAttachment* const _this)>(0x34F2B0);
	static inline auto FGetIStatObj = PreyFunction<IStatObj* (const CCGFAttachment* const _this)>(0x12DC700);
	static inline auto FRelease = PreyFunction<void(CCGFAttachment* const _this)>(0x3E3960);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CCGFAttachment* const _this, unsigned nLOD)>(0x34F2D0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CCGFAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x34F500);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CCGFAttachment* const _this, unsigned nLOD)>(0x547450);
#endif
};

// CEffectAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CEffectAttachment : public IAttachmentObject
{ // Size=64 (0x40)
	_smart_ptr<IParticleEmitter> m_pEmitter;
	_smart_ptr<IParticleEffect> m_pEffect;
	QuatTS m_loc;
	bool m_bPrime;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual ~CEffectAttachment();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#if 0
	CEffectAttachment(const char* _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, float _arg3_, bool _arg4_);
	CEffectAttachment(IParticleEffect* _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, float _arg3_, bool _arg4_);
	IParticleEmitter* GetEmitter();
	void SetSpawnParams(const SpawnParams& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CEffectAttachment* const _this)>(0x1C4890);
	static inline auto FProcessAttachment = PreyFunction<void(CEffectAttachment* const _this, IAttachment* pIAttachment)>(0x3AC7F0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CEffectAttachment* const _this, AABB* _return_value_)>(0x3AC6C0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CEffectAttachment* const _this)>(0x3AC760);
	static inline auto FRelease = PreyFunction<void(CEffectAttachment* const _this)>(0xA97D40);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CEffectAttachment* const _this, unsigned nLOD)>(0x158AEF0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CEffectAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0xA13080);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CEffectAttachment* const _this, unsigned nLOD)>(0x158AEF0);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CEffectAttachment* const _this)>(0x14B6CE0);
	static inline auto FProcessAttachment = PreyFunction<void(CEffectAttachment* const _this, IAttachment* pIAttachment)>(0x3C6C70);
	static inline auto FGetAABB = PreyFunction<AABB*(const CEffectAttachment* const _this, AABB* _return_value_)>(0x3C6B40);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CEffectAttachment* const _this)>(0x3C6BE0);
	static inline auto FRelease = PreyFunction<void(CEffectAttachment* const _this)>(0x3E3960);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CEffectAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CEffectAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x1333E90);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CEffectAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
#endif
};

// CEntityAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CEntityAttachment : public IAttachmentObject
{ // Size=24 (0x18)
	unsigned m_id;
	Vec3 m_scale;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#if 0
	CEntityAttachment();
	void SetEntityId(unsigned _arg0_);
	unsigned GetEntityId();
	void SetScale(const Vec3& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CEntityAttachment* const _this)>(0x13F8580);
	static inline auto FProcessAttachment = PreyFunction<void(CEntityAttachment* const _this, IAttachment* pIAttachment)>(0x335AD0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CEntityAttachment* const _this, AABB* _return_value_)>(0x335BC0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CEntityAttachment* const _this)>(0x335C30);
	static inline auto FRelease = PreyFunction<void(CEntityAttachment* const _this)>(0xA97D40);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CEntityAttachment* const _this, unsigned nLOD)>(0x158AEF0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CEntityAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0xA13080);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CEntityAttachment* const _this, unsigned nLOD)>(0x158AEF0);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CEntityAttachment* const _this)>(0x1A2FA50);
	static inline auto FProcessAttachment = PreyFunction<void(CEntityAttachment* const _this, IAttachment* pIAttachment)>(0x350250);
	static inline auto FGetAABB = PreyFunction<AABB*(const CEntityAttachment* const _this, AABB* _return_value_)>(0x350340);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CEntityAttachment* const _this)>(0x3503B0);
	static inline auto FRelease = PreyFunction<void(CEntityAttachment* const _this)>(0x3E3960);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CEntityAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CEntityAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x1333E90);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CEntityAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
#endif
};

// CLightAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CLightAttachment : public IAttachmentObject
{ // Size=16 (0x10)
	ILightSource* m_pLightSource;

	virtual ~CLightAttachment();
	virtual IAttachmentObject::EType GetAttachmentType();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#if 0
	CLightAttachment();
	void LoadLight(const CDLight& _arg0_);
	ILightSource* GetLightSource();
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CLightAttachment* const _this)>(0x133DF50);
	static inline auto FProcessAttachment = PreyFunction<void(CLightAttachment* const _this, IAttachment* pIAttachment)>(0x9562F0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CLightAttachment* const _this, AABB* _return_value_)>(0x9420B0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CLightAttachment* const _this)>(0x948480);
	static inline auto FRelease = PreyFunction<void(CLightAttachment* const _this)>(0xA97D40);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CLightAttachment* const _this, unsigned nLOD)>(0x158AEF0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CLightAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0xA13080);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CLightAttachment* const _this, unsigned nLOD)>(0x158AEF0);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CLightAttachment* const _this)>(0x141A3D0);
	static inline auto FProcessAttachment = PreyFunction<void(CLightAttachment* const _this, IAttachment* pIAttachment)>(0x972E90);
	static inline auto FGetAABB = PreyFunction<AABB*(const CLightAttachment* const _this, AABB* _return_value_)>(0x95EC40);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CLightAttachment* const _this)>(0x964F70);
	static inline auto FRelease = PreyFunction<void(CLightAttachment* const _this)>(0x3E3960);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CLightAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CLightAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x1333E90);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CLightAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
#endif
};

// CMultiEffectAttachment
// Header:  CryEngine/crycommon/iattachment.h
struct CMultiEffectAttachment : public IAttachmentObject
{ // Size=80 (0x50)
	// CMultiEffectAttachment::EffectSlot
	// Header:  CryEngine/crycommon/iattachment.h
	struct EffectSlot
	{ // Size=56 (0x38)
		_smart_ptr<IParticleEffect> m_pEffect;
		_smart_ptr<IParticleEmitter> m_pEmitter;
		bool m_enabled;
		QuatTS m_offset;

	#if 0
		EffectSlot();
	#endif
	};

	std::vector<CMultiEffectAttachment::EffectSlot> m_effectSlots;
	QuatTS m_loc;
	Vec3 m_orientationOverride;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual ~CMultiEffectAttachment();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;
	void SetEffectForSlot(uint8_t _slot, _smart_ptr<IParticleEffect> _effect, const Vec3& _positionOffset, const Vec3& _rotationOffset) { FSetEffectForSlot(this, _slot, _effect, _positionOffset, _rotationOffset); }

#if 0
	CMultiEffectAttachment(uint8_t _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, float _arg3_);
	void SetOrientation(const Vec3 _arg0_);
	void SetStrength(float _arg0_);
	void SetSpawnParams(const SpawnParams& _arg0_);
	void SetEnabledForSlot(uint8_t _arg0_, bool _arg1_);
	void RemoveEmitterForSlot(uint8_t _arg0_);
	void KillEffectForSlot(uint8_t _arg0_);
	_smart_ptr<IParticleEffect> GetEffectForSlot(uint8_t _arg0_);
	_smart_ptr<IParticleEmitter> GetEmitterForSlot(uint8_t _arg0_);
	bool GetEnabledForSlot(uint8_t _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CMultiEffectAttachment* const _this)>(0x15A4FC0);
	static inline auto FProcessAttachment = PreyFunction<void(CMultiEffectAttachment* const _this, IAttachment* pIAttachment)>(0x1150900);
	static inline auto FGetAABB = PreyFunction<AABB*(const CMultiEffectAttachment* const _this, AABB* _return_value_)>(0x114FBC0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CMultiEffectAttachment* const _this)>(0x114FCC0);
	static inline auto FRelease = PreyFunction<void(CMultiEffectAttachment* const _this)>(0xA97D40);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CMultiEffectAttachment* const _this, unsigned nLOD)>(0x158AEF0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CMultiEffectAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0xA13080);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CMultiEffectAttachment* const _this, unsigned nLOD)>(0x158AEF0);
	static inline auto FSetEffectForSlot = PreyFunction<void(CMultiEffectAttachment* const _this, uint8_t _slot, _smart_ptr<IParticleEffect> _effect, const Vec3& _positionOffset, const Vec3& _rotationOffset)>(0x11513A0);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CMultiEffectAttachment* const _this)>(0xA72AA0);
	static inline auto FProcessAttachment = PreyFunction<void(CMultiEffectAttachment* const _this, IAttachment* pIAttachment)>(0x1198CD0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CMultiEffectAttachment* const _this, AABB* _return_value_)>(0x1197E20);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CMultiEffectAttachment* const _this)>(0x1197F20);
	static inline auto FRelease = PreyFunction<void(CMultiEffectAttachment* const _this)>(0x3E3960);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CMultiEffectAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CMultiEffectAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x1333E90);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CMultiEffectAttachment* const _this, unsigned nLOD)>(0x1CBB0B0);
	static inline auto FSetEffectForSlot = PreyFunction<void(CMultiEffectAttachment* const _this, uint8_t _slot, _smart_ptr<IParticleEffect> _effect, const Vec3& _positionOffset, const Vec3& _rotationOffset)>(0x1199770);
#endif
};

// CSKELAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CSKELAttachment : public IAttachmentObject
{ // Size=24 (0x18)
	_smart_ptr<ICharacterInstance> m_pCharInstance;
	_smart_ptr<IMaterial> m_pReplacementMaterial;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual void RenderAttachment(SRendParams& rParams, const SRenderingPassInfo& passInfo);
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual ICharacterInstance* GetICharacterInstance() const;
	virtual void Release();
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#if 0
	CSKELAttachment();
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CSKELAttachment* const _this)>(0x1A42CE0);
	static inline auto FRenderAttachment = PreyFunction<void(CSKELAttachment* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0x3358C0);
	static inline auto FProcessAttachment = PreyFunction<void(CSKELAttachment* const _this, IAttachment* pIAttachment)>(0x335990);
	static inline auto FGetAABB = PreyFunction<AABB*(const CSKELAttachment* const _this, AABB* _return_value_)>(0x3359A0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CSKELAttachment* const _this)>(0x335A60);
	static inline auto FGetICharacterInstance = PreyFunction<ICharacterInstance* (const CSKELAttachment* const _this)>(0x12AAC70);
	static inline auto FRelease = PreyFunction<void(CSKELAttachment* const _this)>(0x335A80);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CSKELAttachment* const _this, unsigned nLOD)>(0x335AB0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CSKELAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x335820);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CSKELAttachment* const _this, unsigned nLOD)>(0x5BFB50);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CSKELAttachment* const _this)>(0x4FD7F0);
	static inline auto FRenderAttachment = PreyFunction<void(CSKELAttachment* const _this, SRendParams& rParams, const SRenderingPassInfo& passInfo)>(0x34F2F0);
	static inline auto FProcessAttachment = PreyFunction<void(CSKELAttachment* const _this, IAttachment* pIAttachment)>(0x34F3C0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CSKELAttachment* const _this, AABB* _return_value_)>(0x34F3D0);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CSKELAttachment* const _this)>(0x34F490);
	static inline auto FGetICharacterInstance = PreyFunction<ICharacterInstance* (const CSKELAttachment* const _this)>(0x12DC700);
	static inline auto FRelease = PreyFunction<void(CSKELAttachment* const _this)>(0x34F4B0);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CSKELAttachment* const _this, unsigned nLOD)>(0x34F4E0);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CSKELAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x34F500);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CSKELAttachment* const _this, unsigned nLOD)>(0x547450);
#endif
};

// CSKINAttachment
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct CSKINAttachment : public IAttachmentObject
{ // Size=72 (0x48)
	_smart_ptr<IAttachmentSkin> m_pIAttachmentSkin;
	_smart_ptr<IMaterial> m_pReplacementMaterial[6];
	bool m_isJointSkeletonOverride;

	virtual IAttachmentObject::EType GetAttachmentType();
	virtual AABB GetAABB() const;
	virtual float GetRadiusSqr() const;
	virtual IAttachmentSkin* GetIAttachmentSkin() const;
	virtual void Release();
	virtual void ProcessAttachment(IAttachment* pIAttachment);
	virtual IMaterial* GetBaseMaterial(unsigned nLOD) const;
	virtual void SetReplacementMaterial(IMaterial* pMaterial, unsigned nLOD);
	virtual IMaterial* GetReplacementMaterial(unsigned nLOD) const;

#if 0
	CSKINAttachment();
#endif

#ifndef MOONCRASH
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CSKINAttachment* const _this)>(0xC36440);
	static inline auto FGetAABB = PreyFunction<AABB*(const CSKINAttachment* const _this, AABB* _return_value_)>(0x3AE830);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CSKINAttachment* const _this)>(0xB5F050);
	static inline auto FGetIAttachmentSkin = PreyFunction<IAttachmentSkin* (const CSKINAttachment* const _this)>(0x12AAC70);
	static inline auto FRelease = PreyFunction<void(CSKINAttachment* const _this)>(0xA97D40);
	static inline auto FProcessAttachment = PreyFunction<void(CSKINAttachment* const _this, IAttachment* pIAttachment)>(0xA13080);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CSKINAttachment* const _this, unsigned nLOD)>(0x3AE880);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CSKINAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x3AE8C0);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CSKINAttachment* const _this, unsigned nLOD)>(0x3AE900);
#else
	static inline auto FGetAttachmentType = PreyFunction<IAttachmentObject::EType(CSKINAttachment* const _this)>(0x1C657B0);
	static inline auto FGetAABB = PreyFunction<AABB*(const CSKINAttachment* const _this, AABB* _return_value_)>(0x3C9820);
	static inline auto FGetRadiusSqr = PreyFunction<float(const CSKINAttachment* const _this)>(0x714650);
	static inline auto FGetIAttachmentSkin = PreyFunction<IAttachmentSkin* (const CSKINAttachment* const _this)>(0x12DC700);
	static inline auto FRelease = PreyFunction<void(CSKINAttachment* const _this)>(0x3E3960);
	static inline auto FProcessAttachment = PreyFunction<void(CSKINAttachment* const _this, IAttachment* pIAttachment)>(0x1333E90);
	static inline auto FGetBaseMaterial = PreyFunction<IMaterial* (const CSKINAttachment* const _this, unsigned nLOD)>(0x3C9870);
	static inline auto FSetReplacementMaterial = PreyFunction<void(CSKINAttachment* const _this, IMaterial* pMaterial, unsigned nLOD)>(0x3C98B0);
	static inline auto FGetReplacementMaterial = PreyFunction<IMaterial* (const CSKINAttachment* const _this, unsigned nLOD)>(0x3C98F0);
#endif
#ifdef MOONCRASH
	static constexpr const int s_kNumberOfLodLevels = 6;
#endif
};

// SVClothParams
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct SVClothParams
{ // Size=120 (0x78)
	float thickness;
	float collisionDamping;
	float dragDamping;
	float stretchStiffness;
	float shearStiffness;
	float bendStiffness;
	int numIterations;
	float timeStep;
	float rigidDamping;
	float translationBlend;
	float rotationBlend;
	float friction;
	float pullStiffness;
	float tolerance;
	float* weights;
	float maxBlendWeight;
	float maxAnimDistance;
	float windBlend;
	int collDampingRange;
	float stiffnessGradient;
	bool halfStretchIterations;
	bool hide;
	bool isMainCharacter;
	string simMeshName;
	string renderMeshName;
	string renderBinding;
	string simBinding;

	SVClothParams();

#ifndef MOONCRASH
	static inline auto FSVClothParamsOv2 = PreyFunction<void(SVClothParams* const _this)>(0x81EFC0);
#else
	static inline auto FSVClothParamsOv2 = PreyFunction<void(SVClothParams* const _this)>(0x83AA70);
#endif
};

// SimulationParams
// Header:  CryEngine/crycommon/iattachment.h
// Include: Prey/CryAnimation/IAttachment.h
struct SimulationParams
{ // Size=112 (0x70)
	enum class ClampType
	{
		DISABLED = 0,
		PENDULUM_CONE = 1,
		PENDULUM_HINGE_PLANE = 2,
		PENDULUM_HALF_CONE = 3,
		SPRING_ELLIPSOID = 4,
	};

	SimulationParams::ClampType m_nClampType;
	bool m_useDebug;
	bool m_useSimulation;
	bool m_useRedirect;
	uint8_t m_nSimFPS;
	float m_fMaxDeg;
	float m_fHRotation;
	float m_fScaleZP;
	float m_fScaleZN;
	float m_fMass;
	float m_fGravity;
	float m_fDamping;
	float m_fStiffness;
	Vec3 m_vPivotOffset;
	Vec3 m_vSimulationAxis;
	Vec3 m_vStiffnessTarget;
	Vec2 m_vCapsule;
	unsigned m_crcProcFunction;
	uint8_t m_nProjectionType;
	DynArray<unsigned int,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_arrProxyCRC32;
	DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_arrProxyName;

	SimulationParams();

#ifndef MOONCRASH
	static inline auto FSimulationParamsOv2 = PreyFunction<void(SimulationParams* const _this)>(0x7A7640);
#else
	static inline auto FSimulationParamsOv2 = PreyFunction<void(SimulationParams* const _this)>(0x7C2B10);
#endif
};

