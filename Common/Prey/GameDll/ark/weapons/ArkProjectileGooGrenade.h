// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkProjectileGrenade.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// CArkProjectileGooGrenade
// Header:  Prey/GameDll/ark/weapons/ArkProjectileGooGrenade.h
class CArkProjectileGooGrenade : public CArkProjectileGrenade
{ // Size=1968 (0x7B0)
public:
	string m_ammoArchetypeName;
	string m_ammoArchetypeName_Target;
	string m_ammoArchetypeName_Magic;
	float m_gooSpawnDegree;
	float m_gravityTime;
	float m_magicTestHeight;
	int m_numPerPulse;
	std::vector<unsigned int> m_entitiesBeenGlood;

	CArkProjectileGooGrenade();
	virtual ~CArkProjectileGooGrenade();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void ReInitFromPool();
	static CArkProjectileGooGrenade* GetProjectileGrenadeFromEntityId(const unsigned _entityId) { return FGetProjectileGrenadeFromEntityId(_entityId); }
	virtual void LoadCachedProperties();
	virtual void Pulse();
	virtual void DoDetonation();

	static inline auto FCArkProjectileGooGrenadeOv1 = PreyFunction<void(CArkProjectileGooGrenade* const _this)>(0x14860B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectileGooGrenade* const _this, ICrySizer* _s)>(0x1486270);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileGooGrenade* const _this, IGameObject* _pGameObject)>(0x1488050);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGooGrenade* const _this, TSerialize _ser)>(0x1487F10);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooGrenade* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x1487DB0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileGooGrenade* const _this)>(0x1487D80);
	static inline auto FGetProjectileGrenadeFromEntityId = PreyFunction<CArkProjectileGooGrenade* (const unsigned _entityId)>(0x1486290);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileGooGrenade* const _this)>(0x1486340);
	static inline auto FPulse = PreyFunction<void(CArkProjectileGooGrenade* const _this)>(0x14867A0);
	static inline auto FDoDetonation = PreyFunction<void(CArkProjectileGooGrenade* const _this)>(0x1486260);
};
#endif // MOONCRASH
