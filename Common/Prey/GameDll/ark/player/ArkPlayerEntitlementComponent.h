// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkEntitlementListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerEntitlementComponent.h
class ArkPlayerEntitlementComponent : public IArkEntitlementListener, public IArkInventoryListener, public IArkPlayerInteractionListener // Id=8017175 Size=128
{
public:
	unsigned m_bonusContainerId;
	uint64_t m_bonusContainerLocationId;
	bool m_bEntitlementUnlocksInContainer;
	bool m_bRefreshEntitlements;
	std::vector<unsigned __int64> m_populatedEntitlements;
	std::vector<unsigned __int64> m_previouslyPopulatedEntitlements;
	
	class OverflowItem // Id=8017176 Size=24
	{
	public:
		uint64_t m_entitlement;
		uint64_t m_archetype;
		int m_quantity;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkPlayerEntitlementComponent::OverflowItem> m_overflowItems;
	bool m_bRestoreMargrave;
	
	ArkPlayerEntitlementComponent();
	virtual ~ArkPlayerEntitlementComponent();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Update() { FUpdate(this); }
	void PopulateBonusContainer(IEntity *_pBonusContainer) { FPopulateBonusContainer(this,_pBonusContainer); }
	virtual void OnEntitlementChanged(uint64_t _entitlement, bool _bGranted);
	void EntitlementGranted(uint64_t _entitlement) { FEntitlementGranted(this,_entitlement); }
	void EntitlementRevoked(uint64_t _entitlement) { FEntitlementRevoked(this,_entitlement); }
	void AddOverflowItemsToContainer() { FAddOverflowItemsToContainer(this); }
	void RefreshEntitlements() { FRefreshEntitlements(this); }
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnStopLookingAt(unsigned _targetId);
	void UnregisterOnBonusContainer() { FUnregisterOnBonusContainer(this); }
	
#if 0
	void RestoreMargrave();
	void RegisterOnBonusContainer();
#endif
	
	static inline auto FInit = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x1233AA0);
	static inline auto FReset = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x12340D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, TSerialize _ser)>(0x1234130);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x1233C30);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x1234250);
	static inline auto FPopulateBonusContainer = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, IEntity *_pBonusContainer)>(0x1233B50);
	static inline auto FOnEntitlementChanged = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, uint64_t _entitlement, bool _bGranted)>(0x1233AC0);
	static inline auto FEntitlementGranted = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, uint64_t _entitlement)>(0x1233730);
	static inline auto FEntitlementRevoked = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, uint64_t _entitlement)>(0x12338F0);
	static inline auto FAddOverflowItemsToContainer = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x12335E0);
	static inline auto FRefreshEntitlements = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x1233DC0);
	static inline auto FOnItemAdded = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, unsigned _itemId, unsigned _originalId)>(0x9A4980);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, unsigned _itemId)>(0x1233AF0);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkPlayerEntitlementComponent *const _this, unsigned _targetId)>(0x1233B30);
	static inline auto FUnregisterOnBonusContainer = PreyFunction<void(ArkPlayerEntitlementComponent *const _this)>(0x12341F0);
};

