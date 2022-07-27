// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/arkprojectilegoophysicsmanager.h
class CArkProjectileGooPhysicsManager // Id=8015EAF Size=256
{
public:
	struct DynamicEntity_GooInfo // Id=8015EB0 Size=64
	{
		std::vector<unsigned int> m_dynamicGooIdsList;
		std::vector<unsigned int> m_staticGooIdsList;
		bool m_bIsStatic;
		float m_entityMass;
		float m_gooMass;
		
#if 0
		void Serialize(TSerialize arg0);
		void DeleteGooId(const unsigned arg0);
#endif
	};

	std::unordered_map<unsigned int,CArkProjectileGooPhysicsManager::DynamicEntity_GooInfo> m_dynamicEntitiesMap;
	std::unordered_map<unsigned int,std::vector<unsigned int>> m_permStaticGooMap;
	std::unordered_map<unsigned int,std::vector<unsigned int>> m_tempStaticGooMap;
	std::unordered_map<unsigned int,std::vector<unsigned int>> m_staticGooOnDoorsMap;
	
	void Shutdown() { FShutdown(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void AddGooOnDoorEntity(const unsigned _doorEntityId, const unsigned _gooId) { FAddGooOnDoorEntity(this,_doorEntityId,_gooId); }
	void RemoveAllGooOnDoorEntity(const unsigned _doorEntityId) { FRemoveAllGooOnDoorEntity(this,_doorEntityId); }
	void AddGooOnDynamicEntity(const unsigned _dynamicEntityId, const unsigned _gooId, const bool _bIsEntityStatic, const bool _bIsGooStatic, const float _mass, const float _gooMass, const unsigned _attachedEntityId) { FAddGooOnDynamicEntity(this,_dynamicEntityId,_gooId,_bIsEntityStatic,_bIsGooStatic,_mass,_gooMass,_attachedEntityId); }
	void RemoveGooOnDynamicEntity(const unsigned _dynamicEntityId, const unsigned _gooId, const bool _bUpdateListState) { FRemoveGooOnDynamicEntity(this,_dynamicEntityId,_gooId,_bUpdateListState); }
	void RemoveStaticGoo(const unsigned _gooId, const unsigned _dynamicEntityId, const bool _bUpdateListState) { FRemoveStaticGoo(this,_gooId,_dynamicEntityId,_bUpdateListState); }
	static bool IsEntityInDynamicList(const unsigned _dynamicEntityId) { return FIsEntityInDynamicList(_dynamicEntityId); }
	static bool IsPermStatic(IPhysicalEntity *const _pEntityPhysics) { return FIsPermStaticOv1(_pEntityPhysics); }
	static void ZeroOutVelocities(const unsigned _entityId) { FZeroOutVelocities(_entityId); }
	bool DoesEntityHaveGoo(const unsigned _dynamicEntityId) const { return FDoesEntityHaveGoo(this,_dynamicEntityId); }
	void RemoveDynamicGooAttachedToDynamicEntity(const unsigned _dynamicEntityId) { FRemoveDynamicGooAttachedToDynamicEntity(this,_dynamicEntityId); }
	void RemoveAllGooAttachedToDynamicEntity(const unsigned _dynamicEntityId) { FRemoveAllGooAttachedToDynamicEntity(this,_dynamicEntityId); }
	void ChangeEntityListToStatic(const unsigned _dynamicEntityId) { FChangeEntityListToStatic(this,_dynamicEntityId); }
	void ChangeEntityListToDynamic(const unsigned _dynamicEntityId, const unsigned _gooId) { FChangeEntityListToDynamic(this,_dynamicEntityId,_gooId); }
	void ChangeTempStaticToPermStatic(const unsigned _gooId, const unsigned _dynamicEntityId) { FChangeTempStaticToPermStatic(this,_gooId,_dynamicEntityId); }
	void AddDynamicGooToEntityList(const unsigned _gooId, const unsigned _dynamicEntityId, const float _mass, const float _gooMass) { FAddDynamicGooToEntityList(this,_gooId,_dynamicEntityId,_mass,_gooMass); }
	void DeleteDynamicGooFromEntityList(const unsigned _gooId, const unsigned _dynamicEntityId) { FDeleteDynamicGooFromEntityList(this,_gooId,_dynamicEntityId); }
	void AddStaticGooToEntityList(const unsigned _gooId, const unsigned _dynamicEntityId, const float _mass, const float _gooMass) { FAddStaticGooToEntityList(this,_gooId,_dynamicEntityId,_mass,_gooMass); }
	void AddPermStaticGoo(const unsigned _gooId, const unsigned _dynamicEntityId) { FAddPermStaticGoo(this,_gooId,_dynamicEntityId); }
	void RemovePermStaticGoo(const unsigned _gooId, const unsigned _dynamicEntityId) { FRemovePermStaticGoo(this,_gooId,_dynamicEntityId); }
	void AddTempStaticGoo(const unsigned _gooId, const unsigned _dynamicEntityId) { FAddTempStaticGoo(this,_gooId,_dynamicEntityId); }
	bool RemoveTempStaticGoo(const unsigned _gooId, const unsigned _dynamicEntityId, const bool _bDeleteOverlappingGoo) { return FRemoveTempStaticGoo(this,_gooId,_dynamicEntityId,_bDeleteOverlappingGoo); }
	void ChangeTempPhysicsState(const unsigned _entityId, const bool _bStatic, const float _mass) { FChangeTempPhysicsState(this,_entityId,_bStatic,_mass); }
	
#if 0
	static bool IsPermStatic(const unsigned arg0);
	bool IsEntityInGooList(const unsigned arg0, const unsigned arg1) const;
	void RemoveStaticGooAttachedToDynamicEntity(const unsigned arg0);
#endif
	
	static inline auto FShutdown = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this)>(0x1474CE0);
	static inline auto FSerialize = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, TSerialize _ser)>(0x14748E0);
	static inline auto FReset = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this)>(0x1474CE0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const float _frameTime)>(0x1474D30);
	static inline auto FAddGooOnDoorEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _doorEntityId, const unsigned _gooId)>(0x1472950);
	static inline auto FRemoveAllGooOnDoorEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _doorEntityId)>(0x1473CD0);
	static inline auto FAddGooOnDynamicEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId, const unsigned _gooId, const bool _bIsEntityStatic, const bool _bIsGooStatic, const float _mass, const float _gooMass, const unsigned _attachedEntityId)>(0x1472A60);
	static inline auto FRemoveGooOnDynamicEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId, const unsigned _gooId, const bool _bUpdateListState)>(0x1473FB0);
	static inline auto FRemoveStaticGoo = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId, const bool _bUpdateListState)>(0x1474240);
	static inline auto FIsEntityInDynamicList = PreyFunction<bool(const unsigned _dynamicEntityId)>(0x1473900);
	static inline auto FIsPermStaticOv1 = PreyFunction<bool(IPhysicalEntity *const _pEntityPhysics)>(0x14739B0);
	static inline auto FZeroOutVelocities = PreyFunction<void(const unsigned _entityId)>(0x1474E30);
	static inline auto FDoesEntityHaveGoo = PreyFunction<bool(CArkProjectileGooPhysicsManager const *const _this, const unsigned _dynamicEntityId)>(0x1473850);
	static inline auto FRemoveDynamicGooAttachedToDynamicEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId)>(0x1473E70);
	static inline auto FRemoveAllGooAttachedToDynamicEntity = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId)>(0x1473AC0);
	static inline auto FChangeEntityListToStatic = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId)>(0x1473260);
	static inline auto FChangeEntityListToDynamic = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _dynamicEntityId, const unsigned _gooId)>(0x14730B0);
	static inline auto FChangeTempStaticToPermStatic = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId)>(0x14735C0);
	static inline auto FAddDynamicGooToEntityList = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId, const float _mass, const float _gooMass)>(0x1472740);
	static inline auto FDeleteDynamicGooFromEntityList = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId)>(0x1473760);
	static inline auto FAddStaticGooToEntityList = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId, const float _mass, const float _gooMass)>(0x1472D90);
	static inline auto FAddPermStaticGoo = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId)>(0x1472C90);
	static inline auto FRemovePermStaticGoo = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId)>(0x1474120);
	static inline auto FAddTempStaticGoo = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId)>(0x1472FA0);
	static inline auto FRemoveTempStaticGoo = PreyFunction<bool(CArkProjectileGooPhysicsManager *const _this, const unsigned _gooId, const unsigned _dynamicEntityId, const bool _bDeleteOverlappingGoo)>(0x1474790);
	static inline auto FChangeTempPhysicsState = PreyFunction<void(CArkProjectileGooPhysicsManager *const _this, const unsigned _entityId, const bool _bStatic, const float _mass)>(0x14733A0);
};

