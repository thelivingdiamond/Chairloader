// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkPlayerStatusUIInfo.h>

class ArkTraumaBase;
enum class EArkPlayerStatus;
struct IConsoleCmdArgs;
struct IMaterial;
class XmlNodeRef;

// ArkPlayerStatusComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerStatusComponent.h
class ArkPlayerStatusComponent
{ // Size=96 (0x60)
public:
	// ArkPlayerStatusComponent::TArmMaterial
	// Header:  Prey/GameDll/ark/player/ArkPlayerStatusComponent.h
	struct TArmMaterial
	{ // Size=16 (0x10)
		int m_priority;
		IMaterial* m_pMaterial;

	#if 0
		TArmMaterial(IMaterial* _arg0_, int _arg1_);
		bool operator==(const ArkPlayerStatusComponent::TArmMaterial& _arg0_) const;
		bool operator<(const ArkPlayerStatusComponent::TArmMaterial& _arg0_) const;
	#endif
	};

	std::vector<std::unique_ptr<ArkTraumaBase>> m_statuses;
	std::vector<enum::EArkPlayerStatus> m_activeStatuses;
	std::vector<ArkPlayerStatusComponent::TArmMaterial> m_armMaterials;
	ArkSimpleTimer m_blendTimer;
	ArkSimpleTimer m_blendOutTimer;
	float m_hudIconBlinkRate;

	ArkPlayerStatusComponent();
	~ArkPlayerStatusComponent();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void OnGameEnded() { FOnGameEnded(this); }
	void Release() { FRelease(this); }
	bool AccumulateTrauma(uint64_t _signalId, float _amount) { return FAccumulateTrauma(this, _signalId, _amount); }
	void ReduceStatus(uint64_t _signalId, float _amount) { FReduceStatus(this, _signalId, _amount); }
	void RemoveStatus(EArkPlayerStatus _status) { FRemoveStatus(this, _status); }
	void ClearAllStatuses() { FClearAllStatuses(this); }
	void SuspendTraumas() { FSuspendTraumas(this); }
	void ResumeTraumas() { FResumeTraumas(this); }
	void AddHudIcon(const string& _iconName) const { FAddHudIcon(this, _iconName); }
	void RemoveHudIcon(const string& _iconName) const { FRemoveHudIcon(this, _iconName); }
	void UpdateHudIcon(const string& _iconName, float _fillPct, bool _bBlink) const { FUpdateHudIcon(this, _iconName, _fillPct, _bBlink); }
	bool IsStatusActive(EArkPlayerStatus _status) const { return FIsStatusActive(this, _status); }
	bool IsTraumaActive(uint64_t _traumaId) const { return FIsTraumaActive(this, _traumaId); }
	bool CanHealTrauma(uint64_t _traumaId) const { return FCanHealTrauma(this, _traumaId); }
	void SetStatus(EArkPlayerStatus _status, bool _bActivate, bool _bSilent) { FSetStatus(this, _status, _bActivate, _bSilent); }
	void PushArmMaterial(IMaterial* _pMaterial, int _priority) { FPushArmMaterial(this, _pMaterial, _priority); }
	void PopArmMaterial(IMaterial* _pMaterial, int _priority) { FPopArmMaterial(this, _pMaterial, _priority); }
	std::vector<ArkPlayerStatusUIInfo> GetUIInfo() const { alignas(std::vector<ArkPlayerStatusUIInfo>) std::byte _return_buf_[sizeof(std::vector<ArkPlayerStatusUIInfo>)]; return *FGetUIInfo(this, reinterpret_cast<std::vector<ArkPlayerStatusUIInfo>*>(_return_buf_)); }
	std::vector<uint64_t> GetActiveHarmfulMedicalTraumas() const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetActiveHarmfulMedicalTraumas(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_)); }
	const ArkTraumaBase* GetTraumaForStatus(EArkPlayerStatus _status) const { return FGetTraumaForStatusOv1(this, _status); }
	ArkTraumaBase* GetTraumaForStatus(EArkPlayerStatus _status) { return FGetTraumaForStatusOv0(this, _status); }
	static void StatusCmd(IConsoleCmdArgs* _pArgs) { FStatusCmd(_pArgs); }
	void ForceStatus(EArkPlayerStatus _status, bool _bActivate) { FForceStatus(this, _status, _bActivate); }
	void ApplyArmMaterial(IMaterial* _pMaterial) { FApplyArmMaterial(this, _pMaterial); }

#if 0
	bool HasActiveStatus() const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
#endif

	static inline auto FArkPlayerStatusComponentOv1 = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x1461900);
	static inline auto FBitNotArkPlayerStatusComponent = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x1461E00);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerStatusComponent* const _this, TSerialize _ser)>(0x1463430);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x14630C0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerStatusComponent* const _this, float _frameTime)>(0x1463910);
	static inline auto FReset = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x1463330);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerStatusComponent* const _this, const XmlNodeRef& _node)>(0x1462F90);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x1462FB0);
	static inline auto FRelease = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x12E5C40);
	static inline auto FAccumulateTrauma = PreyFunction<bool(ArkPlayerStatusComponent* const _this, uint64_t _signalId, float _amount)>(0x1461E60);
	static inline auto FReduceStatus = PreyFunction<void(ArkPlayerStatusComponent* const _this, uint64_t _signalId, float _amount)>(0x14631A0);
	static inline auto FRemoveStatus = PreyFunction<void(ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status)>(0x14632F0);
	static inline auto FClearAllStatuses = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x14620A0);
	static inline auto FSuspendTraumas = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x14638D0);
	static inline auto FResumeTraumas = PreyFunction<void(ArkPlayerStatusComponent* const _this)>(0x14633F0);
	static inline auto FAddHudIcon = PreyFunction<void(const ArkPlayerStatusComponent* const _this, const string& _iconName)>(0x1461F00);
	static inline auto FRemoveHudIcon = PreyFunction<void(const ArkPlayerStatusComponent* const _this, const string& _iconName)>(0x14632A0);
	static inline auto FUpdateHudIcon = PreyFunction<void(const ArkPlayerStatusComponent* const _this, const string& _iconName, float _fillPct, bool _bBlink)>(0x1463B40);
	static inline auto FIsStatusActive = PreyFunction<bool(const ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status)>(0x1462EA0);
	static inline auto FIsTraumaActive = PreyFunction<bool(const ArkPlayerStatusComponent* const _this, uint64_t _traumaId)>(0x1462F20);
	static inline auto FCanHealTrauma = PreyFunction<bool(const ArkPlayerStatusComponent* const _this, uint64_t _traumaId)>(0x1462060);
	static inline auto FSetStatus = PreyFunction<void(ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status, bool _bActivate, bool _bSilent)>(0x1463610);
	static inline auto FPushArmMaterial = PreyFunction<void(ArkPlayerStatusComponent* const _this, IMaterial* _pMaterial, int _priority)>(0x1463110);
	static inline auto FPopArmMaterial = PreyFunction<void(ArkPlayerStatusComponent* const _this, IMaterial* _pMaterial, int _priority)>(0x1462FC0);
	static inline auto FGetUIInfo = PreyFunction<std::vector<ArkPlayerStatusUIInfo>*(const ArkPlayerStatusComponent* const _this, std::vector<ArkPlayerStatusUIInfo>* _return_value_)>(0x1462550);
	static inline auto FGetActiveHarmfulMedicalTraumas = PreyFunction<std::vector<uint64_t>*(const ArkPlayerStatusComponent* const _this, std::vector<uint64_t>* _return_value_)>(0x14623A0);
	static inline auto FGetTraumaForStatusOv1 = PreyFunction<const ArkTraumaBase* (const ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status)>(0x1462520);
	static inline auto FGetTraumaForStatusOv0 = PreyFunction<ArkTraumaBase* (ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status)>(0x14624F0);
	static inline auto FStatusCmd = PreyFunction<void(IConsoleCmdArgs* _pArgs)>(0x1463740);
	static inline auto FForceStatus = PreyFunction<void(ArkPlayerStatusComponent* const _this, EArkPlayerStatus _status, bool _bActivate)>(0x1462210);
	static inline auto FApplyArmMaterial = PreyFunction<void(ArkPlayerStatusComponent* const _this, IMaterial* _pMaterial)>(0x1461F50);
};

