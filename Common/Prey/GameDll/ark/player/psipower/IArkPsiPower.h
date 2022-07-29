// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkInputLegend;
class ArkPsiPowerComponent;
class ArkPsiPowerTargetingComponent;
class ArkSimpleTimer;
class CCryName;
struct IEntity;

// Header: Exact
// Prey/GameDll/ark/player/psipower/IArkPsiPower.h
class IArkPsiPower // Id=801348C Size=8
{
public:
	using PowerArray = std::vector<enum EArkPsiPowers>;
	
	static EArkPsiPowers GetEnumFromString(const char *const _string) { return FGetEnumFromString(_string); }
	static const char *GetStringFromEnum(EArkPsiPowers _type) { return FGetStringFromEnum(_type); }
	virtual ~IArkPsiPower();
	virtual const char *GetDescription() const;
	virtual int SetLevel(const int _level);
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual bool GetCanCancel() const;
	virtual void ProcessInput(CCryName const &_actionId, int _activationMode, float _value);
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual void RefreshTargets();
	virtual void Update(const float _fFrameTime);
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual void Cancel();
	virtual EArkPsiPowerError GetExecutionError() const;
	virtual bool StartTargeting();
	virtual void OnReset();
	virtual const char *GetHelpText() const;
	virtual ArkInputLegend const &GetTargetingLegend() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual EArkPsiPowers GetEnum() const = 0;
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	virtual wstring GetTextForEntity(IEntity const &_entity) const;
	virtual bool ShowTextWhileTargeting() const;
	virtual bool Start();
	virtual bool InterruptsMimicGrabSequence() const;
	virtual bool Stop();
	virtual int GetCost() const;
	virtual const char *GetDisplayName() const;
	virtual float GetZoomDuration() const;
	virtual Vec3 GetTargetPosition() const;
	virtual std::vector<enum EArkPsiPowers> const &GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual ArkSimpleTimer const &GetCooldownTimer() const;
	virtual bool CanEnterFocusMode(EArkPsiPowers const &_equippedPower) const;
	virtual const char *GetErrorString() const;
	virtual const char *GetTargetingErrorString() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual bool ShouldGenerateGameNoises() const;
	ArkPsiPowerComponent &GetPowerComponent() const { return FGetPowerComponent(this); }
	bool AddCancelToInputLegend(ArkInputLegend const &_original, ArkInputLegend &_cancel) const { return FAddCancelToInputLegend(this,_original,_cancel); }
	virtual void EmitNoise() const;
	
#if 0
	void Lock();
	static void SetEntityHighlight(IEntity const &arg0, ColorF const &arg1);
#endif
	
	static inline auto FGetEnumFromString = PreyFunction<EArkPsiPowers(const char *const _string)>(0x1064D40);
	static inline auto FGetStringFromEnum = PreyFunction<const char *(EArkPsiPowers _type)>(0x1064DD0);
	static inline auto FGetDescription = PreyFunction<const char *(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FSetLevel = PreyFunction<int(IArkPsiPower *const _this, const int _level)>(0x12941A0);
	static inline auto FGetLevel = PreyFunction<int(IArkPsiPower const *const _this)>(0xA38740);
	static inline auto FGetMaxLevel = PreyFunction<int(IArkPsiPower const *const _this)>(0xA38740);
	static inline auto FGetCanCancel = PreyFunction<bool(IArkPsiPower const *const _this)>(0xDD23F0);
	static inline auto FProcessInput = PreyFunction<void(IArkPsiPower *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FProcessInputForTargeting = PreyFunction<void(IArkPsiPower *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FRefreshTargets = PreyFunction<void(IArkPsiPower *const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(IArkPsiPower *const _this, const float _fFrameTime)>(0xA13080);
	static inline auto FUpdateTargeting = PreyFunction<void(IArkPsiPower *const _this, const float _fFrameTime)>(0xA13080);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity *>(IArkPsiPower const *const _this)>(0x146DAD0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity *>(IArkPsiPower const *const _this)>(0x146DAD0);
	static inline auto FCancel = PreyFunction<void(IArkPsiPower *const _this)>(0xA13080);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FStartTargeting = PreyFunction<bool(IArkPsiPower *const _this)>(0x1B933B0);
	static inline auto FOnReset = PreyFunction<void(IArkPsiPower *const _this)>(0xA13080);
	static inline auto FGetHelpText = PreyFunction<const char *(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FGetTargetingLegend = PreyFunction<ArkInputLegend const &(IArkPsiPower const *const _this)>(0x15B16F0);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(IArkPsiPower const *const _this)>(0x15B16F0);
	static inline auto FSerialize = PreyFunction<void(IArkPsiPower *const _this, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(IArkPsiPower *const _this)>(0xA13080);
	static inline auto FGetTextForEntity = PreyFunction<wstring(IArkPsiPower const *const _this, IEntity const &_entity)>(0x15B1730);
	static inline auto FShowTextWhileTargeting = PreyFunction<bool(IArkPsiPower const *const _this)>(0xDD23F0);
	static inline auto FStart = PreyFunction<bool(IArkPsiPower *const _this)>(0x1B933B0);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(IArkPsiPower const *const _this)>(0xDD23F0);
	static inline auto FStop = PreyFunction<bool(IArkPsiPower *const _this)>(0x1B933B0);
	static inline auto FGetCost = PreyFunction<int(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FGetDisplayName = PreyFunction<const char *(IArkPsiPower const *const _this)>(0x12F5370);
	static inline auto FGetZoomDuration = PreyFunction<float(IArkPsiPower const *const _this)>(0xB5F050);
	static inline auto FGetTargetPosition = PreyFunction<Vec3(IArkPsiPower const *const _this)>(0x610560);
	static inline auto FGetBlacklistedPowers = PreyFunction<std::vector<enum EArkPsiPowers> const &(IArkPsiPower const *const _this)>(0x15B1610);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(IArkPsiPower const *const _this)>(0x191BC50);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF(IArkPsiPower const *const _this)>(0xE62940);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(IArkPsiPower *const _this, const float _deltaTime)>(0xB5F050);
	static inline auto FGetCooldownTimer = PreyFunction<ArkSimpleTimer const &(IArkPsiPower const *const _this)>(0x15B1680);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(IArkPsiPower const *const _this, EArkPsiPowers const &_equippedPower)>(0x1B933B0);
	static inline auto FGetErrorString = PreyFunction<const char *(IArkPsiPower const *const _this)>(0x12F5380);
	static inline auto FGetTargetingErrorString = PreyFunction<const char *(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FGetTargetingComponent = PreyFunction<ArkPsiPowerTargetingComponent const *(IArkPsiPower const *const _this)>(0x158AEF0);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(IArkPsiPower const *const _this)>(0x1B933B0);
	static inline auto FGetPowerComponent = PreyFunction<ArkPsiPowerComponent &(IArkPsiPower const *const _this)>(0x15B1700);
	static inline auto FAddCancelToInputLegend = PreyFunction<bool(IArkPsiPower const *const _this, ArkInputLegend const &_original, ArkInputLegend &_cancel)>(0x15B13F0);
	static inline auto FEmitNoise = PreyFunction<void(IArkPsiPower const *const _this)>(0xA13080);
};

