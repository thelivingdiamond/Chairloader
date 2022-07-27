// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkPlayerLightOwner.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/arkplayerflashlight.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>

class CCryName;
class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerFlashlight.h
class ArkPlayerFlashlight : public IArkStatsListener, public IArkPlayerLightOwner // Id=8017486 Size=144
{
public:
	ArkPlayerLightEntity m_playerLight;
	ArkAudioTrigger m_toggleAudio;
	
	class DimRange // Id=8017487 Size=8
	{
	public:
		float m_distanceSq;
		float m_diffuseMultiplier;
		
#if 0
		bool operator<(ArkPlayerFlashlight::DimRange const &arg0) const;
#endif
	};

	std::vector<ArkPlayerFlashlight::DimRange> m_dimRanges;
	float m_dimRangeDeltaRate;
	float m_currentDimRangeDiffuse;
	float m_drainRate;
	float m_chargeRate;
	float m_maxCharge;
	float m_currentCharge;
	float m_dimStart;
	float m_minDimAmount;
	bool m_bEnabled;
	bool m_bShowingUI;
	bool m_bFlashlightOn;
	
	ArkPlayerFlashlight();
	~ArkPlayerFlashlight() { FBitNotArkPlayerFlashlight(this); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Toggle() { FToggle(this); }
	bool IsPowered() const { return FIsPowered(this); }
	void Serialize(TSerialize &_ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	virtual void LightVisibilityUpdated(bool _bVisible);
	float GetTargetDimRangeDiffuse() const { return FGetTargetDimRangeDiffuse(this); }
	
#if 0
	void Init();
	void Enable(const bool arg0);
	bool IsEnabled() const;
	bool IsShowingUI() const;
#endif
	
	static inline auto FBitNotArkPlayerFlashlight = PreyFunction<void(ArkPlayerFlashlight *const _this)>(0x155D4B0);
	static inline auto FReset = PreyFunction<void(ArkPlayerFlashlight *const _this)>(0x155DC40);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerFlashlight *const _this, const float _frameTime)>(0x155DEF0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerFlashlight *const _this, XmlNodeRef const &_node)>(0x155D7B0);
	static inline auto FToggle = PreyFunction<void(ArkPlayerFlashlight *const _this)>(0x155DEA0);
	static inline auto FIsPowered = PreyFunction<bool(ArkPlayerFlashlight const *const _this)>(0x155D650);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerFlashlight *const _this, TSerialize &_ser)>(0x155DD30);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerFlashlight *const _this)>(0x155DBA0);
	static inline auto FOnStatChange = PreyFunction<void(ArkPlayerFlashlight *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x155DB40);
	static inline auto FLightVisibilityUpdated = PreyFunction<void(ArkPlayerFlashlight *const _this, bool _bVisible)>(0x155D670);
	static inline auto FGetTargetDimRangeDiffuse = PreyFunction<float(ArkPlayerFlashlight const *const _this)>(0x155D550);
};

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayerflashlight.h
class ArkFlowNodeFlashlight : public CFlowBaseNode<0> // Id=801C7AA Size=16
{
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		enabled = 0,
		disabled = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig &_config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual ~ArkFlowNodeFlashlight();
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeFlashlight *const _this, SFlowNodeConfig &_config)>(0x155C3E0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeFlashlight *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x155C6E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeFlashlight const *const _this, ICrySizer *_pS)>(0x44D760);
};

