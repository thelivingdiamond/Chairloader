// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDelegate.h>

class ArkDistractionInstance;
class ArkNpc;

// Header: FromCpp
// Prey/GameDll/ark/ArkDistractionManager.h
class ArkDistractionManager // Id=801518D Size=200
{
public:
	using FlowgraphRequestResultCallback = ArkDelegate<void __cdecl(unsigned int,bool)>;
	using DistractionInstances = std::vector<ArkDistractionInstance>;
	using UsedDistractionInstanceIndices = std::vector<unsigned __int64>;
	using UnusedDistractionInstanceIndices = std::vector<unsigned __int64>;
	using EntityToUsedIndicesMap = std::unordered_map<unsigned int,std::vector<unsigned __int64>>;
	using DistractionInstanceFGCallbackMap = std::unordered_map<unsigned int,ArkDelegate<void __cdecl(unsigned int,bool)>>;
	
	std::vector<ArkDistractionInstance> m_distractionInstances;
	std::vector<unsigned __int64> m_unusedIndices;
	std::unordered_map<unsigned int,std::vector<unsigned __int64>> m_entityToDistractionMap;
	std::unordered_map<unsigned int,ArkDelegate<void __cdecl(unsigned int,bool)>> m_distractionInstanceFGCallbacks;
	float m_fAreaCooldownRadius;
	uint64_t m_iLastUpdateIndex;
	int m_iAmortizedUpdateNumFrames;
	int m_iMaxSearchPerFrame;
	
	ArkDistractionManager();
	~ArkDistractionManager();
	void RegisterForDistraction(unsigned _entityId, const uint64_t &_distractionId) { FRegisterForDistraction(this,_entityId,_distractionId); }
	void UnregisterForDistraction(unsigned _entityId, const uint64_t &_distractionId) { FUnregisterForDistraction(this,_entityId,_distractionId); }
	void UnregisterForAllDistractions(unsigned _entityId) { FUnregisterForAllDistractions(this,_entityId); }
	bool HasDistraction(unsigned _entityId, const uint64_t &_distractionId) const { return FHasDistraction(this,_entityId,_distractionId); }
	bool HasAnyDistraction(unsigned _entityId) const { return FHasAnyDistraction(this,_entityId); }
	void EnableAllDistractions(unsigned _entityId) { FEnableAllDistractions(this,_entityId); }
	void DisableAllDistractions(unsigned _entityId) { FDisableAllDistractions(this,_entityId); }
	ArkDistractionInstance &GetDistractionInstance(uint64_t _distractionInstanceIndex) { return FGetDistractionInstanceOv1(this,_distractionInstanceIndex); }
	uint64_t GetDistractionInstanceIndexByDistractionId(unsigned _entityId, const uint64_t &_distractionId) { return FGetDistractionInstanceIndexByDistractionId(this,_entityId,_distractionId); }
	bool IsValidDistractionInstance(uint64_t _instanceIndex) const { return FIsValidDistractionInstance(this,_instanceIndex); }
	bool TryDistractNpc(ArkNpc &_npc, uint64_t _distractionInstanceIndex, ArkDelegate<void __cdecl(unsigned int,bool)> _callback) { return FTryDistractNpc(this,_npc,_distractionInstanceIndex,_callback); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnDistractionComplete(unsigned _distractionEntityId, bool _bSuccess, bool _bTriggerAreaCooldown) { FOnDistractionComplete(this,_distractionEntityId,_bSuccess,_bTriggerAreaCooldown); }
	void DestroyInstance(uint64_t _instanceIndex) { FDestroyInstance(this,_instanceIndex); }
	void RemoveInvalidDistractions() { FRemoveInvalidDistractions(this); }
	void RemoveInvalidDistractionsFromEntity(const unsigned _entityId) { FRemoveInvalidDistractionsFromEntity(this,_entityId); }
	
#if 0
	void EnableDistraction(unsigned arg0, const uint64_t &arg1);
	void DisableDistraction(unsigned arg0, const uint64_t &arg1);
	ArkDistractionInstance const &GetDistractionInstance(uint64_t arg0) const;
	uint64_t GetDistractionInstanceIndexByDistractionDataIndex(unsigned arg0, uint64_t arg1);
	bool IsValidDistractionInstanceForEntity(unsigned arg0, uint64_t arg1);
	void StartAllAreaCooldowns(unsigned arg0);
	uint64_t CreateInstance(unsigned arg0, uint64_t arg1);
	void LoadConfig();
#endif
	
	static inline auto FBitNotArkDistractionManager = PreyFunction<void(ArkDistractionManager *const _this)>(0x125B000);
	static inline auto FRegisterForDistraction = PreyFunction<void(ArkDistractionManager *const _this, unsigned _entityId, const uint64_t &_distractionId)>(0x125B9C0);
	static inline auto FUnregisterForDistraction = PreyFunction<void(ArkDistractionManager *const _this, unsigned _entityId, const uint64_t &_distractionId)>(0x125C6F0);
	static inline auto FUnregisterForAllDistractions = PreyFunction<void(ArkDistractionManager *const _this, unsigned _entityId)>(0x125C5C0);
	static inline auto FHasDistraction = PreyFunction<bool(ArkDistractionManager const *const _this, unsigned _entityId, const uint64_t &_distractionId)>(0x125B4F0);
	static inline auto FHasAnyDistraction = PreyFunction<bool(ArkDistractionManager const *const _this, unsigned _entityId)>(0x125B420);
	static inline auto FEnableAllDistractions = PreyFunction<void(ArkDistractionManager *const _this, unsigned _entityId)>(0x125B280);
	static inline auto FDisableAllDistractions = PreyFunction<void(ArkDistractionManager *const _this, unsigned _entityId)>(0x125B1F0);
	static inline auto FGetDistractionInstanceOv1 = PreyFunction<ArkDistractionInstance &(ArkDistractionManager *const _this, uint64_t _distractionInstanceIndex)>(0x125B390);
	static inline auto FGetDistractionInstanceIndexByDistractionId = PreyFunction<uint64_t(ArkDistractionManager *const _this, unsigned _entityId, const uint64_t &_distractionId)>(0x125B3A0);
	static inline auto FIsValidDistractionInstance = PreyFunction<bool(ArkDistractionManager const *const _this, uint64_t _instanceIndex)>(0x125B6B0);
	static inline auto FTryDistractNpc = PreyFunction<bool(ArkDistractionManager *const _this, ArkNpc &_npc, uint64_t _distractionInstanceIndex, ArkDelegate<void __cdecl(unsigned int,bool)> _callback)>(0x125C340);
	static inline auto FUpdate = PreyFunction<void(ArkDistractionManager *const _this, float _elapsedTime)>(0x125C830);
	static inline auto FReset = PreyFunction<void(ArkDistractionManager *const _this, bool _bEnteringGameMode)>(0x125C230);
	static inline auto FSerialize = PreyFunction<void(ArkDistractionManager *const _this, TSerialize _ser)>(0x125C280);
	static inline auto FPostSerialize = PreyFunction<void(ArkDistractionManager *const _this)>(0x125B9B0);
	static inline auto FOnDistractionComplete = PreyFunction<void(ArkDistractionManager *const _this, unsigned _distractionEntityId, bool _bSuccess, bool _bTriggerAreaCooldown)>(0x125B6F0);
	static inline auto FDestroyInstance = PreyFunction<void(ArkDistractionManager *const _this, uint64_t _instanceIndex)>(0x125B160);
	static inline auto FRemoveInvalidDistractions = PreyFunction<void(ArkDistractionManager *const _this)>(0x125BA90);
	static inline auto FRemoveInvalidDistractionsFromEntity = PreyFunction<void(ArkDistractionManager *const _this, const unsigned _entityId)>(0x125BDC0);
};

