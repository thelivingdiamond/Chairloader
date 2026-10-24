// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;
struct SEntitySpawnParams;
class XmlNodeRef;

// IEntityPoolListener
// Header:  CryEngine/crycommon/ientitypoolmanager.h
struct IEntityPoolListener
{ // Size=8 (0x8)
	enum class ESubscriptions
	{
		PoolBookmarkCreated = 1,
		EntityPreparedFromPool = 2,
		EntityReturningToPool = 4,
		EntityReturnedToPool = 8,
		PoolDefinitionsLoaded = 16,
		BookmarkEntitySerialize = 32,
	};

	enum
	{
		COUNT_SUBSCRIPTIONS = 6,
	};

	virtual ~IEntityPoolListener();
	virtual void OnPoolBookmarkCreated(unsigned entityId, const SEntitySpawnParams& params, XmlNodeRef entityNode);
	virtual void OnEntityPreparedFromPool(unsigned entityId, IEntity* pEntity);
	virtual void OnEntityReturningToPool(unsigned entityId, IEntity* pEntity);
	virtual void OnEntityReturnedToPool(unsigned entityId, IEntity* pEntity);
	virtual void OnPoolDefinitionsLoaded(uint64_t numAI);
	virtual void OnBookmarkEntitySerialize(TSerialize serialize, void* pVEntity);

#ifndef MOONCRASH
	static inline auto FOnPoolBookmarkCreated = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, const SEntitySpawnParams& params, XmlNodeRef entityNode)>(0x2CBEB0);
	static inline auto FOnEntityPreparedFromPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0xA13080);
	static inline auto FOnEntityReturningToPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0xA13080);
	static inline auto FOnEntityReturnedToPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0xA13080);
	static inline auto FOnPoolDefinitionsLoaded = PreyFunction<void(IEntityPoolListener* const _this, uint64_t numAI)>(0xA13080);
	static inline auto FOnBookmarkEntitySerialize = PreyFunction<void(IEntityPoolListener* const _this, TSerialize serialize, void* pVEntity)>(0xA13080);
#else
	static inline auto FOnPoolBookmarkCreated = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, const SEntitySpawnParams& params, XmlNodeRef entityNode)>(0x2E62D0);
	static inline auto FOnEntityPreparedFromPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0x1333E90);
	static inline auto FOnEntityReturningToPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0x1333E90);
	static inline auto FOnEntityReturnedToPool = PreyFunction<void(IEntityPoolListener* const _this, unsigned entityId, IEntity* pEntity)>(0x1333E90);
	static inline auto FOnPoolDefinitionsLoaded = PreyFunction<void(IEntityPoolListener* const _this, uint64_t numAI)>(0x1333E90);
	static inline auto FOnBookmarkEntitySerialize = PreyFunction<void(IEntityPoolListener* const _this, TSerialize serialize, void* pVEntity)>(0x1333E90);
#endif
};

