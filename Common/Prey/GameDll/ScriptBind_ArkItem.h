// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CArkItem;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;
union ScriptHandle;

// CScriptBind_ArkItem
// Header:  Prey/GameDll/ScriptBind_ArkItem.h
class CScriptBind_ArkItem : public CScriptableBase
{ // Size=128 (0x80)
public:
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;
	SmartScriptTable m_stats;
	SmartScriptTable m_params;

	CScriptBind_ArkItem(ISystem* pSystem, IGameFramework* pGameFramework);
	virtual ~CScriptBind_ArkItem();
	void RegisterMethods() { FRegisterMethods(this); }
	void AttachTo(CArkItem* pArkItem) { FAttachTo(this, pArkItem); }
	int GetAudioLogCollectionOwnerName(IFunctionHandler* _pH, string _audioLogCollectionId) { return FGetAudioLogCollectionOwnerName(this, _pH, _audioLogCollectionId); }
	int GetCount(IFunctionHandler* pH) { return FGetCount(this, pH); }
	int ResetCount(IFunctionHandler* _pH, int _count) { return FResetCount(this, _pH, _count); }
	int SetPhysicalizeAsStatic(IFunctionHandler* _pH, bool _bAsStatic, bool _bPhysicalize) { return FSetPhysicalizeAsStatic(this, _pH, _bAsStatic, _bPhysicalize); }
	int CanPickUp(IFunctionHandler* _pH) { return FCanPickUp(this, _pH); }
	int PickUp(IFunctionHandler* _pH, ScriptHandle _pickerId, bool _bEquip) { return FPickUp(this, _pH, _pickerId, _bEquip); }
	int IsEquippable(IFunctionHandler* _pH) { return FIsEquippable(this, _pH); }
	int GetOwnerId(IFunctionHandler* _pH) { return FGetOwnerId(this, _pH); }
	int SetFabricationPlanQuality(IFunctionHandler* _pH, string _fabPlanId) { return FSetFabricationPlanQuality(this, _pH, _fabPlanId); }
	int GetQualityTier(IFunctionHandler* _pH) { return FGetQualityTier(this, _pH); }
	int SetQualityTier(IFunctionHandler* _pH, int _qualityTier) { return FSetQualityTier(this, _pH, _qualityTier); }
	int RandomizeQualityTier(IFunctionHandler* _pH, int _seed) { return FRandomizeQualityTier(this, _pH, _seed); }
	int SpawnAndConsume(IFunctionHandler* _pH, string _archetype, Vec3 _localOffset, bool _bDeployTurret) { return FSpawnAndConsume(this, _pH, _archetype, _localOffset, _bDeployTurret); }
	int GrantAndConsume(IFunctionHandler* _pH, string _archetype, int _quantity) { return FGrantAndConsume(this, _pH, _archetype, _quantity); }
	int InPlayerMuleInventory(IFunctionHandler* _pH) { return FInPlayerMuleInventory(this, _pH); }

#if 0
	int GetValidTypes(IFunctionHandler* _arg0_);
	CArkItem* GetArkItem(IFunctionHandler* _arg0_);
#endif

	static inline auto FCScriptBind_ArkItemOv1 = PreyFunction<void(CScriptBind_ArkItem* const _this, ISystem* pSystem, IGameFramework* pGameFramework)>(0x1907E20);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_ArkItem* const _this)>(0x1908EB0);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_ArkItem* const _this, CArkItem* pArkItem)>(0x1907FB0);
	static inline auto FGetAudioLogCollectionOwnerName = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, string _audioLogCollectionId)>(0x1908440);
	static inline auto FGetCount = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* pH)>(0x19087C0);
	static inline auto FResetCount = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, int _count)>(0x19094F0);
	static inline auto FSetPhysicalizeAsStatic = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, bool _bAsStatic, bool _bPhysicalize)>(0x1909730);
	static inline auto FCanPickUp = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH)>(0x1908160);
	static inline auto FPickUp = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, ScriptHandle _pickerId, bool _bEquip)>(0x1908D30);
	static inline auto FIsEquippable = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH)>(0x1908C50);
	static inline auto FGetOwnerId = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH)>(0x19088A0);
	static inline auto FSetFabricationPlanQuality = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, string _fabPlanId)>(0x1909570);
	static inline auto FGetQualityTier = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH)>(0x1908980);
	static inline auto FSetQualityTier = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, int _qualityTier)>(0x19097B0);
	static inline auto FRandomizeQualityTier = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, int _seed)>(0x1908E40);
	static inline auto FSpawnAndConsume = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, string _archetype, Vec3 _localOffset, bool _bDeployTurret)>(0x1909820);
	static inline auto FGrantAndConsume = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH, string _archetype, int _quantity)>(0x1908A50);
	static inline auto FInPlayerMuleInventory = PreyFunction<int(CScriptBind_ArkItem* const _this, IFunctionHandler* _pH)>(0x1908BA0);
};
#endif // MOONCRASH
