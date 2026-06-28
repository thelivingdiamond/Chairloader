// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>

class ArkWorldUIOwner;
struct IUIElement;

// Prey/GameDll/ark/worldui/ArkWorldUIManager.h
class ArkWorldUIManager : public IUIElementEventListener // Id=80163BF Size=256
{
public:
	using TPoolEntry = std::pair<IUIElement *,ArkWorldUIOwner *>;
	using TInstancePool = std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>;
	
	std::unordered_map<unsigned int,ArkWorldUIOwner *> m_worldUIEntities;
	std::unordered_map<string,std::vector<ArkWorldUIOwner *>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::vector<ArkWorldUIOwner *>>>> m_worldUIElements;
	std::unordered_map<string,std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>>>>> m_instancePools;
	std::vector<ArkMaterialParamOverride> m_interferenceOverrides;
	std::vector<ArkMaterialParamOverride> m_transcribeDisruption;
	unsigned m_highPriorityWorldUI;
	static int ui_debugKioskInteraction;
	static std::array<int,7> s_uiAutoExamine;
	
	ArkWorldUIManager();
	virtual ~ArkWorldUIManager();
	void Init() { FInit(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	bool IsWorldUI(unsigned _entityId) const { return FIsWorldUI(this,_entityId); }
	ArkWorldUIOwner *GetWorldUIOwner(unsigned _entityId) { return FGetWorldUIOwner(this,_entityId); }
	unsigned GetWorldUIFromOwner(unsigned _ownerId) const { return FGetWorldUIFromOwner(this,_ownerId); }
	void RegisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner *_pOwner) { FRegisterWorldUIOwner(this,_entityId,_pOwner); }
	void UnregisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner *_pOwner) { FUnregisterWorldUIOwner(this,_entityId,_pOwner); }
	void SetHighPriorityWorldUI(unsigned _entityId) { FSetHighPriorityWorldUI(this,_entityId); }
	void RegisterWorldUIElement(const char *_uiElement, ArkWorldUIOwner &_owner) { FRegisterWorldUIElement(this,_uiElement,_owner); }
	void UnregisterWorldUIElement(const char *_uiElement, ArkWorldUIOwner &_owner) { FUnregisterWorldUIElement(this,_uiElement,_owner); }
	bool HasUIElementPool(const char *_uiElement) { return FHasUIElementPool(this,_uiElement); }
	virtual void OnInstanceDestroyed(IUIElement *pSender, IUIElement *pDeletedInstance);
	std::vector<ArkMaterialParamOverride> const &GetInterferenceMaterialOverrides() const { return FGetInterferenceMaterialOverrides(this); }
	std::vector<ArkMaterialParamOverride> const &GetTranscribeMaterialOverrides() const { return FGetTranscribeMaterialOverrides(this); }
	static bool ShouldAutoExamineType(EArkInteractiveScreenType _type) { return FShouldAutoExamineType(_type); }
	void InitializePools() { FInitializePools(this); }
	void LoadInterferenceOverrides() { FLoadInterferenceOverrides(this); }
	
#if 0
	void GrantInstanceFromPool(std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>> &arg0, ArkWorldUIOwner &arg1);
	void ReturnInstanceToPool(std::vector<std::pair<IUIElement *,ArkWorldUIOwner *>> &arg0, ArkWorldUIOwner &arg1);
#endif
	
	static inline auto FBitNotArkWorldUIManager = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE300);
	static inline auto FInit = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE940);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AEFA0);
	static inline auto FReset = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AF2E0);
	static inline auto FUpdate = PreyFunction<void(ArkWorldUIManager *const _this, const float _frameTime)>(0x13AF5D0);
	static inline auto FIsWorldUI = PreyFunction<bool(ArkWorldUIManager const *const _this, unsigned _entityId)>(0x145A1E0);
	static inline auto FGetWorldUIOwner = PreyFunction<ArkWorldUIOwner *(ArkWorldUIManager *const _this, unsigned _entityId)>(0x13AE7B0);
	static inline auto FGetWorldUIFromOwner = PreyFunction<unsigned(ArkWorldUIManager const *const _this, unsigned _ownerId)>(0x13AE750);
	static inline auto FRegisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId, ArkWorldUIOwner *_pOwner)>(0x13AF160);
	static inline auto FUnregisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId, ArkWorldUIOwner *_pOwner)>(0x13AF510);
	static inline auto FSetHighPriorityWorldUI = PreyFunction<void(ArkWorldUIManager *const _this, unsigned _entityId)>(0x13AF300);
	static inline auto FRegisterWorldUIElement = PreyFunction<void(ArkWorldUIManager *const _this, const char *_uiElement, ArkWorldUIOwner &_owner)>(0x13AEFB0);
	static inline auto FUnregisterWorldUIElement = PreyFunction<void(ArkWorldUIManager *const _this, const char *_uiElement, ArkWorldUIOwner &_owner)>(0x13AF330);
	static inline auto FHasUIElementPool = PreyFunction<bool(ArkWorldUIManager *const _this, const char *_uiElement)>(0x13AE870);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(ArkWorldUIManager *const _this, IUIElement *pSender, IUIElement *pDeletedInstance)>(0x13AEE60);
	static inline auto FGetInterferenceMaterialOverrides = PreyFunction<std::vector<ArkMaterialParamOverride> const &(ArkWorldUIManager const *const _this)>(0x10BD480);
	static inline auto FGetTranscribeMaterialOverrides = PreyFunction<std::vector<ArkMaterialParamOverride> const &(ArkWorldUIManager const *const _this)>(0x13AE740);
	static inline auto FShouldAutoExamineType = PreyFunction<bool(EArkInteractiveScreenType _type)>(0x13AF310);
	static inline auto FInitializePools = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AE950);
	static inline auto FLoadInterferenceOverrides = PreyFunction<void(ArkWorldUIManager *const _this)>(0x13AECC0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <_unknown/ArkMaterialParamOverride.h>

class ArkWorldUIOwner;
enum class EArkInteractiveScreenType;
enum class EArkWorldUIMaterialOverride;
struct IUIElement;

// ArkWorldUIManager
// Header:  Prey/GameDll/ark/worldui/ArkWorldUIManager.h
class ArkWorldUIManager : public IUIElementEventListener
{ // Size=280 (0x118)
public:
	using TPoolEntry = std::pair<IUIElement*, ArkWorldUIOwner*>;
	using TInstancePool = std::vector<std::pair<IUIElement*, ArkWorldUIOwner*>>;

	std::unordered_map<unsigned int, ArkWorldUIOwner*> m_worldUIEntities;
	std::unordered_map<string, std::vector<ArkWorldUIOwner*>> m_worldUIElements;
	std::unordered_map<string, std::vector<std::pair<IUIElement*, ArkWorldUIOwner*>>> m_instancePools;
	std::vector<ArkMaterialParamOverride> m_interferenceOverrides;
	std::vector<ArkMaterialParamOverride> m_transcribeDisruption;
	std::vector<ArkMaterialParamOverride> m_keyWorldUIBroken;
	unsigned m_highPriorityWorldUI;
	static inline auto ui_debugKioskInteraction = PreyGlobal<int>(0x2D58A98);
	static inline auto s_uiAutoExamine = PreyGlobal<std::array<int, 7>>(0x23E3C98);

	ArkWorldUIManager();
	virtual ~ArkWorldUIManager();
	void Init() { FInit(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	bool IsWorldUI(unsigned _entityId) const { return FIsWorldUI(this, _entityId); }
	ArkWorldUIOwner* GetWorldUIOwner(unsigned _entityId) { return FGetWorldUIOwner(this, _entityId); }
	unsigned GetWorldUIFromOwner(unsigned _ownerId) const { return FGetWorldUIFromOwner(this, _ownerId); }
	void RegisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner* _pOwner) { FRegisterWorldUIOwner(this, _entityId, _pOwner); }
	void UnregisterWorldUIOwner(unsigned _entityId, ArkWorldUIOwner* _pOwner) { FUnregisterWorldUIOwner(this, _entityId, _pOwner); }
	void SetHighPriorityWorldUI(unsigned _entityId) { FSetHighPriorityWorldUI(this, _entityId); }
	void RegisterWorldUIElement(const char* _uiElement, ArkWorldUIOwner& _owner) { FRegisterWorldUIElement(this, _uiElement, _owner); }
	void UnregisterWorldUIElement(const char* _uiElement, ArkWorldUIOwner& _owner) { FUnregisterWorldUIElement(this, _uiElement, _owner); }
	bool HasUIElementPool(const char* _uiElement) { return FHasUIElementPool(this, _uiElement); }
	virtual void OnInstanceDestroyed(IUIElement* pSender, IUIElement* pDeletedInstance);
	const std::vector<ArkMaterialParamOverride>& GetMaterialOverrides(EArkWorldUIMaterialOverride _overrideType) const { return FGetMaterialOverrides(this, _overrideType); }
	static bool ShouldAutoExamineType(EArkInteractiveScreenType _type) { return FShouldAutoExamineType(_type); }
	void InitializePools() { FInitializePools(this); }
	void LoadInterferenceOverrides() { FLoadInterferenceOverrides(this); }

#if 0
	void GrantInstanceFromPool(std::vector<std::pair<IUIElement*, ArkWorldUIOwner*>>& _arg0_, ArkWorldUIOwner& _arg1_);
	void ReturnInstanceToPool(std::vector<std::pair<IUIElement*, ArkWorldUIOwner*>>& _arg0_, ArkWorldUIOwner& _arg1_);
#endif

	static inline auto FArkWorldUIManagerOv1 = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14B9930);
	static inline auto FBitNotArkWorldUIManager = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14B9D70);
	static inline auto FInit = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14BA400);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14BAA20);
	static inline auto FReset = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14BAD60);
	static inline auto FUpdate = PreyFunction<void(ArkWorldUIManager* const _this, const float _frameTime)>(0x14BB050);
	static inline auto FIsWorldUI = PreyFunction<bool(const ArkWorldUIManager* const _this, unsigned _entityId)>(0x12BA340);
	static inline auto FGetWorldUIOwner = PreyFunction<ArkWorldUIOwner* (ArkWorldUIManager* const _this, unsigned _entityId)>(0x14BA270);
	static inline auto FGetWorldUIFromOwner = PreyFunction<unsigned(const ArkWorldUIManager* const _this, unsigned _ownerId)>(0x14BA210);
	static inline auto FRegisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager* const _this, unsigned _entityId, ArkWorldUIOwner* _pOwner)>(0x14BABE0);
	static inline auto FUnregisterWorldUIOwner = PreyFunction<void(ArkWorldUIManager* const _this, unsigned _entityId, ArkWorldUIOwner* _pOwner)>(0x14BAF90);
	static inline auto FSetHighPriorityWorldUI = PreyFunction<void(ArkWorldUIManager* const _this, unsigned _entityId)>(0x14BAD80);
	static inline auto FRegisterWorldUIElement = PreyFunction<void(ArkWorldUIManager* const _this, const char* _uiElement, ArkWorldUIOwner& _owner)>(0x14BAA30);
	static inline auto FUnregisterWorldUIElement = PreyFunction<void(ArkWorldUIManager* const _this, const char* _uiElement, ArkWorldUIOwner& _owner)>(0x14BADB0);
	static inline auto FHasUIElementPool = PreyFunction<bool(ArkWorldUIManager* const _this, const char* _uiElement)>(0x14BA330);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(ArkWorldUIManager* const _this, IUIElement* pSender, IUIElement* pDeletedInstance)>(0x14BA8E0);
	static inline auto FGetMaterialOverrides = PreyFunction<const std::vector<ArkMaterialParamOverride>& (const ArkWorldUIManager* const _this, EArkWorldUIMaterialOverride _overrideType)>(0x14BA1E0);
	static inline auto FShouldAutoExamineType = PreyFunction<bool(EArkInteractiveScreenType _type)>(0x14BAD90);
	static inline auto FInitializePools = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14BA410);
	static inline auto FLoadInterferenceOverrides = PreyFunction<void(ArkWorldUIManager* const _this)>(0x14BA780);
};
#endif // !MOONCRASH
