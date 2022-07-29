// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>

struct IEntity;
struct IEntityArchetype;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPsiCorpsePhantom.h
class ArkPsiCorpsePhantom : public IArkPlayerCarryListener // Id=80192C7 Size=72
{
public:
	ArkSimpleTimer m_timer;
	Vec3 m_targetSpawnPosition;
	string m_levelName;
	unsigned m_ownerEntityId;
	unsigned m_corpseEntityId;
	unsigned m_phantomEntityId;
	uint64_t m_phantomArchetypeId;
	bool m_bSpawnedOnFloor;
	static std::vector<ArkPsiCorpsePhantom const *> s_corpsePhantoms;
	
	ArkPsiCorpsePhantom();
	ArkPsiCorpsePhantom(const unsigned _ownerEntityId);
	ArkPsiCorpsePhantom(ArkPsiCorpsePhantom *_other);
	virtual ~ArkPsiCorpsePhantom();
	ArkPsiCorpsePhantom &operator=(ArkPsiCorpsePhantom *_other) { return FoperatorEqOv1(this,_other); }
	bool operator==(ArkPsiCorpsePhantom const &_other) const { return FoperatorEqEq(this,_other); }
	void Spawn(IEntity &_corpseEntity, IEntityArchetype const &_archetype) { FSpawn(this,_corpseEntity,_archetype); }
	bool Update(const float _frameTime) { return FUpdate(this,_frameTime); }
	void Serialize(TSerialize _serializer) { FSerialize(this,_serializer); }
	void PostSerialize() { FPostSerialize(this); }
	static ArkPsiCorpsePhantom const *GetCorpsePhantomFromCorpse(const unsigned _entityId) { return FGetCorpsePhantomFromCorpse(_entityId); }
	virtual void OnStartCarry(IEntity *const _pEntity);
	void ResetCorpse() { FResetCorpse(this); }
	void SpawnCorpseParticleEffect() { FSpawnCorpseParticleEffect(this); }
	
#if 0
	unsigned GetOwnerId() const;
	unsigned GetCorpseEntityId() const;
	unsigned GetPhantomEntityId() const;
	const char *GetLevelName() const;
#endif
	
	static inline auto FBitNotArkPsiCorpsePhantom = PreyFunction<void(ArkPsiCorpsePhantom *const _this)>(0x132F940);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiCorpsePhantom &(ArkPsiCorpsePhantom *const _this, ArkPsiCorpsePhantom *_other)>(0x132F9D0);
	static inline auto FoperatorEqEq = PreyFunction<bool(ArkPsiCorpsePhantom const *const _this, ArkPsiCorpsePhantom const &_other)>(0x132F9F0);
	static inline auto FSpawn = PreyFunction<void(ArkPsiCorpsePhantom *const _this, IEntity &_corpseEntity, IEntityArchetype const &_archetype)>(0x132FD90);
	static inline auto FUpdate = PreyFunction<bool(ArkPsiCorpsePhantom *const _this, const float _frameTime)>(0x13302E0);
	static inline auto FSerialize = PreyFunction<void(ArkPsiCorpsePhantom *const _this, TSerialize _serializer)>(0x132FCA0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiCorpsePhantom *const _this)>(0x132FAC0);
	static inline auto FGetCorpsePhantomFromCorpse = PreyFunction<ArkPsiCorpsePhantom const *(const unsigned _entityId)>(0x132FA60);
	static inline auto FOnStartCarry = PreyFunction<void(ArkPsiCorpsePhantom *const _this, IEntity *const _pEntity)>(0x132FA90);
	static inline auto FResetCorpse = PreyFunction<void(ArkPsiCorpsePhantom *const _this)>(0x132FB00);
	static inline auto FSpawnCorpseParticleEffect = PreyFunction<void(ArkPsiCorpsePhantom *const _this)>(0x13300F0);
};

