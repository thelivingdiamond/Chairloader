// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/arklibrary.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkNpc;
class ArkNpcGameEffect;
struct ArkNpcGameEffectInstance;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcGameEffectManager
// Header:  Prey/GameDll/ark/npc/gameeffect/ArkNpcGameEffectManager.h
class ArkNpcGameEffectManager
{ // Size=136 (0x88)
public:
	// ArkNpcGameEffectManager::AttachedGameEffect
	// Header:  Prey/GameDll/ark/npc/gameeffect/ArkNpcGameEffectManager.h
	struct AttachedGameEffect
	{ // Size=40 (0x28)
		uint64_t m_gameEffectId;
		uint64_t m_referenceCount;
		ArkNpc* m_pNpc;
		const ArkNpcGameEffect* m_pGameEffect;
		std::unique_ptr<ArkNpcGameEffectInstance> m_pGameEffectInstance;

	#if 0
		AttachedGameEffect(uint64_t _arg0_, ArkNpc& _arg1_, const ArkNpcGameEffect& _arg2_);
		AttachedGameEffect(ArkNpcGameEffectManager::AttachedGameEffect&& _arg0_);
		ArkNpcGameEffectManager::AttachedGameEffect& operator=(ArkNpcGameEffectManager::AttachedGameEffect&& _arg0_);
	#endif
	};

	using AttachedGameEffectVector = std::vector<ArkNpcGameEffectManager::AttachedGameEffect>;
	using AttachedGameEffectMap = std::unordered_map<const ArkNpc*, std::vector<ArkNpcGameEffectManager::AttachedGameEffect>>;
	using GameEffectLibrary = ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >;

	ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > > m_gameEffectLibrary;
	std::unordered_map<const ArkNpc*, std::vector<ArkNpcGameEffectManager::AttachedGameEffect>> m_attachedGameEffects;
	bool m_bInterferenceEnabled;

	ArkNpcGameEffectManager();
	~ArkNpcGameEffectManager();
	void Initialize() { FInitialize(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	bool HasGameEffect(uint64_t _gameEffectId) const { return FHasGameEffect(this, _gameEffectId); }
	void AttachGameEffectToNpc(ArkNpc& _npc, uint64_t _gameEffectId) { FAttachGameEffectToNpcOv1(this, _npc, _gameEffectId); }
	void AttachGameEffectToNpc(uint64_t _gameEffectId, ArkNpc& _npc, const ArkNpcGameEffect& _gameEffect) { FAttachGameEffectToNpcOv0(this, _gameEffectId, _npc, _gameEffect); }
	void DetachGameEffectFromNpc(const ArkNpc& _npc, uint64_t _gameEffectId) { FDetachGameEffectFromNpcOv2(this, _npc, _gameEffectId); }
	void DetachGameEffectFromNpc(const ArkNpc& _npc, const ArkNpcGameEffect& _gameEffect) { FDetachGameEffectFromNpcOv1(this, _npc, _gameEffect); }
	bool SafeAttachGameEffectToNpc(ArkNpc& _npc, uint64_t _gameEffectId) { return FSafeAttachGameEffectToNpc(this, _npc, _gameEffectId); }
	bool SafeDetachGameEffectFromNpc(const ArkNpc& _npc, uint64_t _gameEffectId) { return FSafeDetachGameEffectFromNpcOv1(this, _npc, _gameEffectId); }
	bool NpcHasGameEffect(const ArkNpc& _npc, uint64_t _gameEffectId) const { return FNpcHasGameEffectOv1(this, _npc, _gameEffectId); }
	void DetachAllGameEffectsFromNpc(const ArkNpc& _npc) { FDetachAllGameEffectsFromNpc(this, _npc); }
	std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*> FindGameEffectPair(const ArkNpc& _npc, uint64_t _gameEffectId) const { alignas(std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*>) std::byte _return_buf_[sizeof(std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*>)]; return *FFindGameEffectPair(this, reinterpret_cast<std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*>*>(_return_buf_), _npc, _gameEffectId); }
	void OnNpcReceivedPackage(const ArkNpc& _npc, const ArkSignalSystem::Package& _package) const { FOnNpcReceivedPackage(this, _npc, _package); }
	float ModifyDamage(const ArkNpc& _npc, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { return FModifyDamage(this, _npc, _hitInfo, _package); }
	void OnTakeDamage(const ArkNpc& _npc, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package) const { FOnTakeDamage(this, _npc, _hitInfo, _package); }
	void OnDealtDamage(const ArkNpc& _npc, unsigned _damagedEntityId) const { FOnDealtDamage(this, _npc, _damagedEntityId); }
	void OnDied(const ArkNpc& _npc) const { FOnDied(this, _npc); }
	void OnDeleted(const ArkNpc* _pNpc) { FOnDeleted(this, _pNpc); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void CleanupAttachedGameEffects() { FCleanupAttachedGameEffects(this); }

#if 0
	ArkNpcGameEffectManager(const ArkNpcGameEffectManager& _arg0_);
	const ArkNpcGameEffect& GetGameEffect(uint64_t _arg0_) const;
	const ArkNpcGameEffect* FindGameEffect(uint64_t _arg0_) const;
	void DetachGameEffectFromNpc(const ArkNpc& _arg0_, const ArkNpcGameEffect& _arg1_, std::_List_const_iterator<std::_List_val<std::_List_simple_types<std::pair<ArkNpc const * const,std::vector<ArkNpcGameEffectManager::AttachedGameEffect,std::allocator<ArkNpcGameEffectManager::AttachedGameEffect> > > > > > _arg2_, std::vector<ArkNpcGameEffectManager::AttachedGameEffect>& _arg3_, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkNpcGameEffectManager::AttachedGameEffect> > > _arg4_);
	bool SafeDetachGameEffectFromNpc(const ArkNpc& _arg0_, const ArkNpcGameEffect& _arg1_);
	bool NpcHasGameEffect(const ArkNpc& _arg0_, const ArkNpcGameEffect& _arg1_) const;
	std::pair<const ArkNpcGameEffect&, ArkNpcGameEffectInstance&> GetGameEffectPair(const ArkNpc& _arg0_, uint64_t _arg1_) const;
	bool IsInterferenceEnabled();
	void EnableInterference(const bool _arg0_);
	ArkNpcGameEffectManager& operator=(const ArkNpcGameEffectManager& _arg0_);
	void LoadGameEffects();
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkNpcGameEffectManager::AttachedGameEffect> > > GetAttachedGameEffectIter(std::vector<ArkNpcGameEffectManager::AttachedGameEffect>& _arg0_, const ArkNpcGameEffect& _arg1_);
	std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ArkNpcGameEffectManager::AttachedGameEffect> > > GetAttachedGameEffectIter(const std::vector<ArkNpcGameEffectManager::AttachedGameEffect>& _arg0_, const ArkNpcGameEffect& _arg1_) const;
#endif

	static inline auto FArkNpcGameEffectManagerOv1 = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x1342000);
	static inline auto FBitNotArkNpcGameEffectManager = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x13421D0);
	static inline auto FInitialize = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x1348F50);
	static inline auto FReset = PreyFunction<void(ArkNpcGameEffectManager* const _this, bool _bEnteringGameMode)>(0x1333E90);
	static inline auto FHasGameEffect = PreyFunction<bool(const ArkNpcGameEffectManager* const _this, uint64_t _gameEffectId)>(0x1348E10);
	static inline auto FAttachGameEffectToNpcOv1 = PreyFunction<void(ArkNpcGameEffectManager* const _this, ArkNpc& _npc, uint64_t _gameEffectId)>(0x1344340);
	static inline auto FAttachGameEffectToNpcOv0 = PreyFunction<void(ArkNpcGameEffectManager* const _this, uint64_t _gameEffectId, ArkNpc& _npc, const ArkNpcGameEffect& _gameEffect)>(0x1344110);
	static inline auto FDetachGameEffectFromNpcOv2 = PreyFunction<void(ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, uint64_t _gameEffectId)>(0x1344B80);
	static inline auto FDetachGameEffectFromNpcOv1 = PreyFunction<void(ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, const ArkNpcGameEffect& _gameEffect)>(0x1344A40);
	static inline auto FSafeAttachGameEffectToNpc = PreyFunction<bool(ArkNpcGameEffectManager* const _this, ArkNpc& _npc, uint64_t _gameEffectId)>(0x134BB10);
	static inline auto FSafeDetachGameEffectFromNpcOv1 = PreyFunction<bool(ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, uint64_t _gameEffectId)>(0x134BB90);
	static inline auto FNpcHasGameEffectOv1 = PreyFunction<bool(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, uint64_t _gameEffectId)>(0x1348FC0);
	static inline auto FDetachAllGameEffectsFromNpc = PreyFunction<void(ArkNpcGameEffectManager* const _this, const ArkNpc& _npc)>(0x13448A0);
	static inline auto FFindGameEffectPair = PreyFunction<std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*>*(const ArkNpcGameEffectManager* const _this, std::pair<const ArkNpcGameEffect*, ArkNpcGameEffectInstance*>* _return_value_, const ArkNpc& _npc, uint64_t _gameEffectId)>(0x1344E10);
	static inline auto FOnNpcReceivedPackage = PreyFunction<void(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, const ArkSignalSystem::Package& _package)>(0x13492E0);
	static inline auto FModifyDamage = PreyFunction<float(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1348F60);
	static inline auto FOnTakeDamage = PreyFunction<void(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, const HitInfo& _hitInfo, const ArkSignalSystem::Package& _package)>(0x1349300);
	static inline auto FOnDealtDamage = PreyFunction<void(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc, unsigned _damagedEntityId)>(0x1349130);
	static inline auto FOnDied = PreyFunction<void(const ArkNpcGameEffectManager* const _this, const ArkNpc& _npc)>(0x13491A0);
	static inline auto FOnDeleted = PreyFunction<void(ArkNpcGameEffectManager* const _this, const ArkNpc* _pNpc)>(0x1349150);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x13491C0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x13492B0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcGameEffectManager* const _this, float _elapsedTime)>(0x134C420);
	static inline auto FSerialize = PreyFunction<void(ArkNpcGameEffectManager* const _this, TSerialize _serializer)>(0x134BD20);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x1349330);
	static inline auto FCleanupAttachedGameEffects = PreyFunction<void(ArkNpcGameEffectManager* const _this)>(0x13443A0);
};
#endif // MOONCRASH
