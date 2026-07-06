// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;
struct IGameObject;
struct SEntityEvent;

// ArkCondenser
// Header:  Prey/GameDll/ark/environment/ArkCondenser.h
class ArkCondenser
	: public ArkEnvironmentalObject
	, public IArkPlayerInteractionListener
	, public IArkInventoryListener
	, public IEntityEventListener
{ // Size=264 (0x108)
public:
	std::array<unsigned int, 2> m_slotEntities;
	std::array<Vec3, 2> m_slotLocations;
	int m_cellsRequired;
	int m_startingCells;
	uint64_t m_cellArchetype;
	string m_interactVerb;
	string m_poweredMaterialName;
	ArkAudioTrigger m_triggerPoweredStart;
	ArkAudioTrigger m_triggerPoweredStop;
	ArkAudioTrigger m_triggerCellAdded;
	ArkAudioTrigger m_triggerCellRemoved;
	ArkAudioTrigger m_triggerDrained;
	ArkFireAndForgetEffect m_drainVFX;

	ArkCondenser();
	virtual ~ArkCondenser();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId, bool _bPrimaryInventory);
	virtual void OnItemRemoved(unsigned _itemId, bool _bPrimaryInventory);
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void OnCellBroken(unsigned _cellId) { FOnCellBroken(this, _cellId); }
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	void ClearSlots() { FClearSlots(this); }
	void FillSlots() { FFillSlots(this); }
	void UpdateSlotLocations() { FUpdateSlotLocations(this); }
	std::vector<unsigned int> GetCellsFromPlayerInventory() const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetCellsFromPlayerInventory(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_)); }
	bool AddCell() { return FAddCell(this); }
	void ClearSlot(int _slotIndex) { FClearSlot(this, _slotIndex); }
	void AssignToSlot(int _slotIndex, unsigned _entity) { FAssignToSlot(this, _slotIndex, _entity); }

#if 0
	bool TestAndFillInteractionInfo(ArkInteractionInfo& _arg0_) const;
	bool IsFullyPowered() const;
	void UpdatePowered(bool _arg0_, bool _arg1_);
	void DrainCells();
#endif

	static inline auto FArkCondenserOv1 = PreyFunction<void(ArkCondenser* const _this)>(0x11CA320);
	static inline auto FPostInit = PreyFunction<void(ArkCondenser* const _this, IGameObject* _pGameObject)>(0x11CC120);
	static inline auto FFullSerialize = PreyFunction<void(ArkCondenser* const _this, TSerialize _ser)>(0x11CAE60);
	static inline auto FPostSerialize = PreyFunction<void(ArkCondenser* const _this)>(0x11CC190);
	static inline auto FProcessEvent = PreyFunction<void(ArkCondenser* const _this, SEntityEvent& _event)>(0x11CC3C0);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x11CBEA0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x11CC7E0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x11CC0D0);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x11CC0D0);
	static inline auto FOnItemAdded = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId, unsigned _originalId, bool _bPrimaryInventory)>(0x11CBF90);
	static inline auto FOnItemRemoved = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId, bool _bPrimaryInventory)>(0x1333E90);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x11CBD70);
	static inline auto FOnCellBroken = PreyFunction<void(ArkCondenser* const _this, unsigned _cellId)>(0x11CBBD0);
	static inline auto FLoadProperties = PreyFunction<void(ArkCondenser* const _this)>(0x11CB260);
	static inline auto FOnReset = PreyFunction<void(ArkCondenser* const _this, bool _bEnteringGameMode)>(0x11CBFE0);
	static inline auto FClearSlots = PreyFunction<void(ArkCondenser* const _this)>(0x11CA9D0);
	static inline auto FFillSlots = PreyFunction<void(ArkCondenser* const _this)>(0x11CAB10);
	static inline auto FUpdateSlotLocations = PreyFunction<void(ArkCondenser* const _this)>(0x11CD100);
	static inline auto FGetCellsFromPlayerInventory = PreyFunction<std::vector<unsigned int>*(const ArkCondenser* const _this, std::vector<unsigned int>* _return_value_)>(0x11CB140);
	static inline auto FAddCell = PreyFunction<bool(ArkCondenser* const _this)>(0x11CA5A0);
	static inline auto FClearSlot = PreyFunction<void(ArkCondenser* const _this, int _slotIndex)>(0x11CA8C0);
	static inline auto FAssignToSlot = PreyFunction<void(ArkCondenser* const _this, int _slotIndex, unsigned _entity)>(0x11CA830);
};
#endif // MOONCRASH
