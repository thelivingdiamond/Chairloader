// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>

class IArkOverlappingGooListener;
struct IEntity;
struct IGameObject;

// Header: FromCpp
// Prey/GameDll/ark/ArkOverlappingGooHandler.h
class ArkOverlappingGooHandler // Id=8018FB6 Size=32
{
public:
	static float k_gooCheckTime;
	IArkOverlappingGooListener &m_listener;
	ArkSimpleTimer m_gooCheckTimer;
	bool m_bReactivateWhenGooRemoved;
	bool m_bBreaksGoo;
	bool m_bHasGoo;
	bool m_bActive;
	
	ArkOverlappingGooHandler(IArkOverlappingGooListener &_listener);
	virtual ~ArkOverlappingGooHandler();
	void PostInit(IGameObject *_pGameObject) { FPostInit(this,_pGameObject); }
	void Update(IEntity *const _pEntity, float _frameTime) { FUpdate(this,_pEntity,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	bool HasGoo() const;
	void SetBreaksGoo(const bool arg0);
	void SetReactivateWhenGooRemoved(const bool arg0);
#endif
	
	static inline auto FBitNotArkOverlappingGooHandler = PreyFunction<void(ArkOverlappingGooHandler *const _this)>(0x11AB2E0);
	static inline auto FPostInit = PreyFunction<void(ArkOverlappingGooHandler *const _this, IGameObject *_pGameObject)>(0x11AB320);
	static inline auto FUpdate = PreyFunction<void(ArkOverlappingGooHandler *const _this, IEntity *const _pEntity, float _frameTime)>(0x11AB680);
	static inline auto FSerialize = PreyFunction<void(ArkOverlappingGooHandler *const _this, TSerialize _ser)>(0x11AB630);
};

