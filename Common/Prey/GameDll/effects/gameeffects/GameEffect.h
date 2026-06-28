// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/IGameEffect.h>
#include <_unknown/PodArray.h>

class ICrySizer;
struct IEntity;
struct IItemParamsNode;
struct IMaterial;
struct IParticleEffect;
struct IParticleEmitter;
struct SGameEffectParams;

// CGameEffect
// Header:  Prey/GameDll/effects/gameeffects/GameEffect.h
class CGameEffect : public IGameEffect
{ // Size=32 (0x20)
public:
	IGameEffect* m_prev;
	IGameEffect* m_next;
	uint16_t m_flags;

	CGameEffect();
	virtual ~CGameEffect();
	virtual void Initialise(const SGameEffectParams* gameEffectParams);
	virtual void Release();
	virtual void Update(float frameTime);
	virtual void SetActive(bool isActive);
	virtual void SetFlag(unsigned flag, bool state);
	virtual bool IsFlagSet(unsigned flag) const;
	virtual unsigned GetFlags() const;
	virtual void SetFlags(unsigned flags);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual IGameEffect* Next() const;
	virtual IGameEffect* Prev() const;
	virtual void SetNext(IGameEffect* newNext);
	virtual void SetPrev(IGameEffect* newPrev);

#if 0
	void SpawnParticlesOnSkeleton(IEntity* _arg0_, IParticleEmitter* _arg1_, unsigned _arg2_, float _arg3_) const;
	void SetMaterialOnEntity(IMaterial* _arg0_, unsigned _arg1_, PodArray<int,0>* _arg2_);
	void SetMaterialOnEntity(IMaterial* _arg0_, unsigned _arg1_, PodArray<SharedString::CSharedString,0>* _arg2_);
	static void ReadAttachmentNames(const IItemParamsNode* _arg0_, PodArray<SharedString::CSharedString,0>* _arg1_);
	void InitAttachmentIndexArray(PodArray<int,0>* _arg0_, PodArray<SharedString::CSharedString,0>* _arg1_, unsigned _arg2_) const;
	static IMaterial* LoadMaterial(const char* _arg0_);
	static IParticleEffect* LoadParticleEffect(const char* _arg0_);
	static bool IsEntity3rdPerson(unsigned _arg0_);
#endif

	static inline auto FCGameEffectOv1 = PreyFunction<void(CGameEffect* const _this)>(0x17DB100);
	static inline auto FBitNotCGameEffect = PreyFunction<void(CGameEffect* const _this)>(0x17DB120);
	static inline auto FInitialise = PreyFunction<void(CGameEffect* const _this, const SGameEffectParams* gameEffectParams)>(0x17DB1C0);
	static inline auto FRelease = PreyFunction<void(CGameEffect* const _this)>(0x17DB2E0);
	static inline auto FUpdate = PreyFunction<void(CGameEffect* const _this, float frameTime)>(0x1333E90);
	static inline auto FSetActive = PreyFunction<void(CGameEffect* const _this, bool isActive)>(0x17DB380);
	static inline auto FSetFlag = PreyFunction<void(CGameEffect* const _this, unsigned flag, bool state)>(0x17DB3D0);
	static inline auto FIsFlagSet = PreyFunction<bool(const CGameEffect* const _this, unsigned flag)>(0x17DB2D0);
	static inline auto FGetFlags = PreyFunction<unsigned(const CGameEffect* const _this)>(0x266580);
	static inline auto FSetFlags = PreyFunction<void(CGameEffect* const _this, unsigned flags)>(0x17DB3F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CGameEffect* const _this, ICrySizer* pSizer)>(0x189F2B0);
	static inline auto FNext = PreyFunction<IGameEffect* (const CGameEffect* const _this)>(0x547450);
	static inline auto FPrev = PreyFunction<IGameEffect* (const CGameEffect* const _this)>(0x12DC700);
	static inline auto FSetNext = PreyFunction<void(CGameEffect* const _this, IGameEffect* newNext)>(0x561EA0);
	static inline auto FSetPrev = PreyFunction<void(CGameEffect* const _this, IGameEffect* newPrev)>(0x17DB400);
};
#endif // MOONCRASH
