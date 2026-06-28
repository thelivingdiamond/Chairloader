// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <_unknown/ArkDelegate.h>

class ArkNpcPlayer;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
struct HitInfo;

// ArkNpcSignalAccumulator
// Header:  Prey/GameDll/ark/npc/ArkNpcSignalAccumulatorManager.h
struct ArkNpcSignalAccumulator
{ // Size=88 (0x58)
	using RisingCallback = ArkDelegate<void __cdecl(ArkSignalSystem::Package const *,HitInfo const *)>;
	using FallingCallback = ArkDelegate<void __cdecl(void)>;

	string m_risingCallbackFunc;
	string m_fallingCallbackFunc;
	unsigned m_lastInstigator;
	float m_risingThreshold;
	float m_fallingThreshold;
	float m_durationToStartDeaccumulation;
	float m_deaccumulateAmountPerSecond;
	float m_maximum;
	ArkDelegate<void __cdecl(ArkSignalSystem::Package const *,HitInfo const *)> m_risingCallback;
	ArkDelegate<void __cdecl(void)> m_fallingCallback;
	float m_currentAccumulation;
	float m_amtChangeThisFrame;
	float m_timerToStartDeaccumulation;
	bool m_bReachedThreshold;
	bool m_bDeaccumulating;

	ArkNpcSignalAccumulator();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	ArkNpcSignalAccumulator(float _arg0_, float _arg1_, float _arg2_, float _arg3_, float _arg4_, const char* const _arg5_, const char* const _arg6_);
#endif

	static inline auto FArkNpcSignalAccumulatorOv3 = PreyFunction<void(ArkNpcSignalAccumulator* const _this)>(0x16345B0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcSignalAccumulator* const _this, TSerialize _ser)>(0x16356E0);
};

// ArkNpcSignalAccumulatorManager
// Header:  Prey/GameDll/ark/npc/ArkNpcSignalAccumulatorManager.h
class ArkNpcSignalAccumulatorManager
{ // Size=24 (0x18)
public:
	using SignalAccumulatorMap = std::map<uint64_t, ArkNpcSignalAccumulator>;
	using SignalGroupNameMap = std::unordered_map<string, uint64_t>;
	using SignalGroupIds = std::vector<uint64_t>;
	using SignalToSignalGroupMap = std::unordered_map<uint64_t, std::vector<uint64_t>>;
	using CachedSignalAccumulators = std::unordered_map<string, std::map<uint64_t, ArkNpcSignalAccumulator>>;

	ArkNpcPlayer& m_owner;
	std::map<uint64_t, ArkNpcSignalAccumulator> m_signalAccumulators;
	static inline auto s_cachedSignalAccumulators = PreyGlobal<std::unordered_map<string, std::map<uint64_t, ArkNpcSignalAccumulator>>>(0x2D7C9B0);
	static inline auto s_groupNameToGroupID = PreyGlobal<std::unordered_map<string, uint64_t>>(0x2D7C9F0);
	static inline auto s_signalToGroupMap = PreyGlobal<std::unordered_map<uint64_t, std::vector<uint64_t>>>(0x2D7CA30);

	ArkNpcSignalAccumulatorManager(ArkNpcPlayer& _owner);
	~ArkNpcSignalAccumulatorManager();
	bool OnReceivePackage(const ArkSignalSystem::Package& _package, const HitInfo& _hitInfo, const float _scale) { return FOnReceivePackage(this, _package, _hitInfo, _scale); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void ResetAccumulator(const uint64_t& _signalGroup) { FResetAccumulator(this, _signalGroup); }
	void RegisterCallbacks(const uint64_t& _signalGroupId, ArkDelegate<void __cdecl(ArkSignalSystem::Package const *,HitInfo const *)> _risingCallback, ArkDelegate<void __cdecl(void)> _fallingCallback) { FRegisterCallbacks(this, _signalGroupId, _risingCallback, _fallingCallback); }
	void Initialize(const char* _pConfigFile) { FInitialize(this, _pConfigFile); }
	void IncreaseAccumulationForSignalGroup(uint64_t _signalGroupId, float _amount) { FIncreaseAccumulationForSignalGroupOv1(this, _signalGroupId, _amount); }
	void IncreaseAccumulationForSignalGroup(ArkNpcSignalAccumulator& _accumulator, float _amount, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo) { FIncreaseAccumulationForSignalGroupOv0(this, _accumulator, _amount, _pPackage, _pHitInfo); }
	void SetAccumulationForSignalGroup(uint64_t _signalGroupId, float _accumulation) { FSetAccumulationForSignalGroup(this, _signalGroupId, _accumulation); }
	const ArkNpcSignalAccumulator* GetAccumulator(uint64_t _signalGroupId) const { return FGetAccumulatorOv1(this, _signalGroupId); }
	ArkNpcSignalAccumulator* GetAccumulator(uint64_t _signalGroupId) { return FGetAccumulatorOv0(this, _signalGroupId); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	static void Precache(const char* _pConfigFile) { FPrecache(_pConfigFile); }
	static void ClearPrecache() { FClearPrecache(); }
	static uint64_t GetSignalGroupId(const string& group_name) { return FGetSignalGroupId(group_name); }
	static const std::map<uint64_t, ArkNpcSignalAccumulator>& LoadConfig(string _configFile) { return FLoadConfig(_configFile); }
	static void LoadConfig_Recursive(const string& _configFile, std::vector<CCryNameCRC>& _loadedFiles, std::map<uint64_t, ArkNpcSignalAccumulator>& _cachedAccumulator) { FLoadConfig_Recursive(_configFile, _loadedFiles, _cachedAccumulator); }
	static void SetAccumulator(ArkNpcSignalAccumulator& _accumulator, const uint64_t& _signalGroupId, const float _risingThreshold, const float _fallingThreshold, const float _deaccumulateAmountPerSecond, const float _durationToStartDeaccumulation, const float _maximum, const char* const _pRisingCallback, const char* const _pFallingCallback) { FSetAccumulator(_accumulator, _signalGroupId, _risingThreshold, _fallingThreshold, _deaccumulateAmountPerSecond, _durationToStartDeaccumulation, _maximum, _pRisingCallback, _pFallingCallback); }

#if 0
	ArkNpcSignalAccumulatorManager(const ArkNpcSignalAccumulatorManager& _arg0_);
	void RemoveAccumulator(const uint64_t& _arg0_);
	void RegisterAccumulator(const uint64_t& _arg0_, const float _arg1_, const float _arg2_, const float _arg3_, const float _arg4_, const float _arg5_, const char* const _arg6_, const char* const _arg7_);
	void UnregisterCallbacks(const uint64_t& _arg0_);
	void UnregisterAllCallbacks();
	float GetAccumulationForSignalGroup(uint64_t _arg0_) const;
	static void SetDebugEntity(const char* _arg0_);
	ArkNpcSignalAccumulatorManager& operator=(const ArkNpcSignalAccumulatorManager& _arg0_);
	void DebugDraw();
	void OnRisingThresholdExceeded(ArkNpcSignalAccumulator& _arg0_, const ArkSignalSystem::Package* _arg1_, const HitInfo* _arg2_);
	void OnFallingThresholdExceeded(ArkNpcSignalAccumulator& _arg0_);
#endif

	static inline auto FArkNpcSignalAccumulatorManagerOv1 = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, ArkNpcPlayer& _owner)>(0x1634690);
	static inline auto FBitNotArkNpcSignalAccumulatorManager = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this)>(0x16347B0);
	static inline auto FOnReceivePackage = PreyFunction<bool(ArkNpcSignalAccumulatorManager* const _this, const ArkSignalSystem::Package& _package, const HitInfo& _hitInfo, const float _scale)>(0x16353C0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, float _frameTime)>(0x1635D80);
	static inline auto FResetAccumulator = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, const uint64_t& _signalGroup)>(0x16356C0);
	static inline auto FRegisterCallbacks = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, const uint64_t& _signalGroupId, ArkDelegate<void __cdecl(ArkSignalSystem::Package const *,HitInfo const *)> _risingCallback, ArkDelegate<void __cdecl(void)> _fallingCallback)>(0x1635630);
	static inline auto FInitialize = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, const char* _pConfigFile)>(0x1634C30);
	static inline auto FIncreaseAccumulationForSignalGroupOv1 = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, uint64_t _signalGroupId, float _amount)>(0x1634BD0);
	static inline auto FIncreaseAccumulationForSignalGroupOv0 = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, ArkNpcSignalAccumulator& _accumulator, float _amount, const ArkSignalSystem::Package* _pPackage, const HitInfo* _pHitInfo)>(0x1634AF0);
	static inline auto FSetAccumulationForSignalGroup = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, uint64_t _signalGroupId, float _accumulation)>(0x16359D0);
	static inline auto FGetAccumulatorOv1 = PreyFunction<const ArkNpcSignalAccumulator* (const ArkNpcSignalAccumulatorManager* const _this, uint64_t _signalGroupId)>(0x16349A0);
	static inline auto FGetAccumulatorOv0 = PreyFunction<ArkNpcSignalAccumulator* (ArkNpcSignalAccumulatorManager* const _this, uint64_t _signalGroupId)>(0x16349A0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcSignalAccumulatorManager* const _this, TSerialize _ser)>(0x16359B0);
	static inline auto FPrecache = PreyFunction<void(const char* _pConfigFile)>(0x1635610);
	static inline auto FClearPrecache = PreyFunction<void()>(0x16348A0);
	static inline auto FGetSignalGroupId = PreyFunction<uint64_t(const string& group_name)>(0x16349F0);
	static inline auto FLoadConfig = PreyFunction<const std::map<uint64_t, ArkNpcSignalAccumulator>& (string _configFile)>(0x1634D30);
	static inline auto FLoadConfig_Recursive = PreyFunction<void(const string& _configFile, std::vector<CCryNameCRC>& _loadedFiles, std::map<uint64_t, ArkNpcSignalAccumulator>& _cachedAccumulator)>(0x1634F80);
	static inline auto FSetAccumulator = PreyFunction<void(ArkNpcSignalAccumulator& _accumulator, const uint64_t& _signalGroupId, const float _risingThreshold, const float _fallingThreshold, const float _deaccumulateAmountPerSecond, const float _durationToStartDeaccumulation, const float _maximum, const char* const _pRisingCallback, const char* const _pFallingCallback)>(0x1635A20);
};
#endif // MOONCRASH
