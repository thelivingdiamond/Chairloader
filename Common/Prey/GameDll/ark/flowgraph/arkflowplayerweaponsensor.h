// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <_unknown/IArkWeaponEventListener.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkInventory;
class CArkWeapon;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_ArkPlayerWeaponSensor
// Header:  Prey/GameDll/ark/flowgraph/arkflowplayerweaponsensor.h
class CFlowNode_ArkPlayerWeaponSensor : public CFlowBaseNode<1>, public IArkWeaponEventListener
{ // Size=72 (0x48)
public:
	enum INS
	{
		EIP_TRIGGER = 0,
		EIP_ENABLE = 1,
		EIP_DISABLE = 2,
	};

	enum OUTS
	{
		EOP_ONWEAPONCHANGE = 0,
		EOP_ONWEAPONAMMOCOUNTCHANGE = 1,
		EOP_ONSTARTFIRE = 2,
		EOP_ONSTOPFIRE = 3,
		EOP_ONOUTOFAMMO = 4,
		EOP_ONRELOAD = 5,
		EOP_CLIPSIZE = 6,
		EOP_INVENTORYAMMO = 7,
		EOP_WEAPONAMMO = 8,
		EOP_WEAPONNAME = 9,
		EOP_AMMONAME = 10,
	};

	IFlowNode::SActivationInfo m_actInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CFlowNode_ArkPlayerWeaponSensor*>>(0x2D795E0);

	CFlowNode_ArkPlayerWeaponSensor(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CFlowNode_ArkPlayerWeaponSensor();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	static void NotifyWeaponEquipped(unsigned _weaponId) { FNotifyWeaponEquipped(_weaponId); }
	static void NotifyWeaponUnequipped(unsigned _weaponId) { FNotifyWeaponUnequipped(_weaponId); }
	virtual void OnWeaponAmmoCountChanged();
	virtual void OnWeaponChange();
	virtual void OnStartFire();
	virtual void OnStopFire();
	virtual void OnEndReload();
	virtual void OnOutOfAmmo();
	virtual void OnDetachFromHand();
	void Enable(IFlowNode::SActivationInfo* _pActInfo) { FEnable(this, _pActInfo); }
	void Disable() { FDisable(this); }

#if 0
	void OnWeaponEquipped(unsigned _arg0_);
	void OnWeaponUnequipped(unsigned _arg0_);
	CArkWeapon* GetEquippedWeapon() const;
	ArkInventory* GetInventory() const;
	void RegisterWeapon();
	void UnregisterWeapon();
#endif

	static inline auto FCFlowNode_ArkPlayerWeaponSensorOv1 = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15FB0A0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this, SFlowNodeConfig& config)>(0x15FB380);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15FC000);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_ArkPlayerWeaponSensor* const _this, ICrySizer* _s)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_ArkPlayerWeaponSensor* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15FB210);
	static inline auto FSerialize = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FNotifyWeaponEquipped = PreyFunction<void(unsigned _weaponId)>(0x15FB8E0);
	static inline auto FNotifyWeaponUnequipped = PreyFunction<void(unsigned _weaponId)>(0x15FB9C0);
	static inline auto FOnWeaponAmmoCountChanged = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBBA0);
	static inline auto FOnWeaponChange = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBC80);
	static inline auto FOnStartFire = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBB20);
	static inline auto FOnStopFire = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBB60);
	static inline auto FOnEndReload = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBAA0);
	static inline auto FOnOutOfAmmo = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x15FBAE0);
	static inline auto FOnDetachFromHand = PreyFunction<void(IArkWeaponEventListener* const _this)>(0x1333E90);
	static inline auto FEnable = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15FB300);
	static inline auto FDisable = PreyFunction<void(CFlowNode_ArkPlayerWeaponSensor* const _this)>(0x15FB2B0);
};
#endif // MOONCRASH
