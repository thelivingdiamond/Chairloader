// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>

struct IEntity;
struct IEntityArchetype;

// ArkPsiCorpsePhantom
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiCorpsePhantom.h
class ArkPsiCorpsePhantom : public IArkPlayerCarryListener
{ // Size=72 (0x48)
public:
	ArkSimpleTimer m_timer;
	Vec3 m_targetSpawnPosition;
	string m_levelName;
	unsigned m_ownerEntityId;
	unsigned m_corpseEntityId;
	unsigned m_phantomEntityId;
	uint64_t m_phantomArchetypeId;
	bool m_bSpawnedOnFloor;
	static inline auto s_corpsePhantoms = PreyGlobal<std::vector<const ArkPsiCorpsePhantom*>>(0x2BDBA80);

	ArkPsiCorpsePhantom();
	ArkPsiCorpsePhantom(const unsigned _ownerEntityId);
	ArkPsiCorpsePhantom(ArkPsiCorpsePhantom&& _other);
	virtual ~ArkPsiCorpsePhantom();
	//ArkPsiCorpsePhantom& operator=(ArkPsiCorpsePhantom&& _other) { return FoperatorEqOv1(this, _other); }
	bool operator==(const ArkPsiCorpsePhantom& _other) const { return FoperatorEqEq(this, _other); }
	void Spawn(IEntity& _corpseEntity, const IEntityArchetype& _archetype) { FSpawn(this, _corpseEntity, _archetype); }
	bool Update(const float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	static const ArkPsiCorpsePhantom* GetCorpsePhantomFromCorpse(const unsigned _entityId) { return FGetCorpsePhantomFromCorpse(_entityId); }
	virtual void OnStartCarry(IEntity* const _pEntity);
	void ResetCorpse() { FResetCorpse(this); }
	void SpawnCorpseParticleEffect() { FSpawnCorpseParticleEffect(this); }

#if 0
	ArkPsiCorpsePhantom(const ArkPsiCorpsePhantom& _arg0_);
	ArkPsiCorpsePhantom& operator=(const ArkPsiCorpsePhantom& _arg0_);
	unsigned GetOwnerId() const;
	unsigned GetCorpseEntityId() const;
	unsigned GetPhantomEntityId() const;
	const char* GetLevelName() const;
#endif

	static inline auto FArkPsiCorpsePhantomOv3 = PreyFunction<void(ArkPsiCorpsePhantom* const _this)>(0x132F8A0);
	static inline auto FArkPsiCorpsePhantomOv2 = PreyFunction<void(ArkPsiCorpsePhantom* const _this, const unsigned _ownerEntityId)>(0x132F7F0);
	static inline auto FArkPsiCorpsePhantomOv1 = PreyFunction<void(ArkPsiCorpsePhantom* const _this, ArkPsiCorpsePhantom&& _other)>(0x132F750);
	static inline auto FBitNotArkPsiCorpsePhantom = PreyFunction<void(ArkPsiCorpsePhantom* const _this)>(0x132F940);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiCorpsePhantom& (ArkPsiCorpsePhantom* const _this, ArkPsiCorpsePhantom&& _other)>(0x132F9D0);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkPsiCorpsePhantom* const _this, const ArkPsiCorpsePhantom& _other)>(0x132F9F0);
	static inline auto FSpawn = PreyFunction<void(ArkPsiCorpsePhantom* const _this, IEntity& _corpseEntity, const IEntityArchetype& _archetype)>(0x132FD90);
	static inline auto FUpdate = PreyFunction<bool(ArkPsiCorpsePhantom* const _this, const float _frameTime)>(0x13302E0);
	static inline auto FSerialize = PreyFunction<void(ArkPsiCorpsePhantom* const _this, TSerialize _serializer)>(0x132FCA0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiCorpsePhantom* const _this)>(0x132FAC0);
	static inline auto FGetCorpsePhantomFromCorpse = PreyFunction<const ArkPsiCorpsePhantom* (const unsigned _entityId)>(0x132FA60);
	static inline auto FOnStartCarry = PreyFunction<void(ArkPsiCorpsePhantom* const _this, IEntity* const _pEntity)>(0x132FA90);
	static inline auto FResetCorpse = PreyFunction<void(ArkPsiCorpsePhantom* const _this)>(0x132FB00);
	static inline auto FSpawnCorpseParticleEffect = PreyFunction<void(ArkPsiCorpsePhantom* const _this)>(0x13300F0);
};

