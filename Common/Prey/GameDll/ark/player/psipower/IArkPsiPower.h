// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkInputLegend;
class ArkPsiPowerComponent;
class ArkPsiPowerTargetingComponent;
class ArkSimpleTimer;
class CCryName;
enum class EArkPsiPowerError;
enum class EArkPsiPowers;
struct IEntity;

// IArkPsiPower
// Header:  Prey/GameDll/ark/player/psipower/IArkPsiPower.h
class IArkPsiPower
{ // Size=8 (0x8)
public:
	using PowerArray = std::vector<enum::EArkPsiPowers>;

	static EArkPsiPowers GetEnumFromString(const char* const _string) { return FGetEnumFromString(_string); }
	static const char* GetStringFromEnum(EArkPsiPowers _type) { return FGetStringFromEnum(_type); }
	virtual ~IArkPsiPower();
	virtual const char* GetDescription() const;
	virtual int SetLevel(const int _level);
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual bool GetCanCancel() const;
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void RefreshTargets();
	virtual void Update(const float _fFrameTime);
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual void Cancel();
	virtual EArkPsiPowerError GetExecutionError() const;
	virtual bool StartTargeting();
	virtual void OnReset();
	virtual const char* GetHelpText() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual EArkPsiPowers GetEnum() const = 0;
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	virtual wstring GetTextForEntity(const IEntity& _entity) const;
	virtual bool ShowTextWhileTargeting() const;
	virtual bool Start();
	virtual bool InterruptsMimicGrabSequence() const;
	virtual bool Stop();
	virtual int GetCost() const;
	virtual const char* GetDisplayName() const;
	virtual float GetZoomDuration() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool CanEnterFocusMode(const EArkPsiPowers& _equippedPower) const;
	virtual const char* GetErrorString() const;
	virtual const char* GetTargetingErrorString() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual bool ShouldGenerateGameNoises() const;
	ArkPsiPowerComponent& GetPowerComponent() const { return FGetPowerComponent(this); }
	bool AddCancelToInputLegend(const ArkInputLegend& _original, ArkInputLegend& _cancel) const { return FAddCancelToInputLegend(this, _original, _cancel); }
	virtual void EmitNoise() const;

#if 0
	void Lock();
	static void SetEntityHighlight(const IEntity& _arg0_, const ColorF& _arg1_);
#endif

	static inline auto FGetEnumFromString = PreyFunction<EArkPsiPowers(const char* const _string)>(0x1064D40);
	static inline auto FGetStringFromEnum = PreyFunction<const char* (EArkPsiPowers _type)>(0x1064DD0);
	static inline auto FGetDescription = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FSetLevel = PreyFunction<int(IArkPsiPower* const _this, const int _level)>(0x12941A0);
	static inline auto FGetLevel = PreyFunction<int(const IArkPsiPower* const _this)>(0xA38740);
	static inline auto FGetMaxLevel = PreyFunction<int(const IArkPsiPower* const _this)>(0xA38740);
	static inline auto FGetCanCancel = PreyFunction<bool(const IArkPsiPower* const _this)>(0xDD23F0);
	static inline auto FProcessInput = PreyFunction<void(IArkPsiPower* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FProcessInputForTargeting = PreyFunction<void(IArkPsiPower* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FRefreshTargets = PreyFunction<void(IArkPsiPower* const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(IArkPsiPower* const _this, const float _fFrameTime)>(0xA13080);
	static inline auto FUpdateTargeting = PreyFunction<void(IArkPsiPower* const _this, const float _fFrameTime)>(0xA13080);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const IArkPsiPower* const _this, std::vector<IEntity*>* _return_value_)>(0x146DAD0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const IArkPsiPower* const _this, std::vector<IEntity*>* _return_value_)>(0x146DAD0);
	static inline auto FCancel = PreyFunction<void(IArkPsiPower* const _this)>(0xA13080);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FStartTargeting = PreyFunction<bool(IArkPsiPower* const _this)>(0x1B933B0);
	static inline auto FOnReset = PreyFunction<void(IArkPsiPower* const _this)>(0xA13080);
	static inline auto FGetHelpText = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const IArkPsiPower* const _this)>(0x15B16F0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const IArkPsiPower* const _this)>(0x15B16F0);
	static inline auto FSerialize = PreyFunction<void(IArkPsiPower* const _this, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(IArkPsiPower* const _this)>(0xA13080);
	static inline auto FGetTextForEntity = PreyFunction<wstring*(const IArkPsiPower* const _this, wstring* _return_value_, const IEntity& _entity)>(0x15B1730);
	static inline auto FShowTextWhileTargeting = PreyFunction<bool(const IArkPsiPower* const _this)>(0xDD23F0);
	static inline auto FStart = PreyFunction<bool(IArkPsiPower* const _this)>(0x1B933B0);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const IArkPsiPower* const _this)>(0xDD23F0);
	static inline auto FStop = PreyFunction<bool(IArkPsiPower* const _this)>(0x1B933B0);
	static inline auto FGetCost = PreyFunction<int(const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x12F5370);
	static inline auto FGetZoomDuration = PreyFunction<float(const IArkPsiPower* const _this)>(0xB5F050);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const IArkPsiPower* const _this, Vec3* _return_value_)>(0x610560);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const IArkPsiPower* const _this)>(0x15B1610);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const IArkPsiPower* const _this)>(0x191BC50);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const IArkPsiPower* const _this, ColorF* _return_value_)>(0xE62940);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(IArkPsiPower* const _this, const float _deltaTime)>(0xB5F050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const IArkPsiPower* const _this)>(0x15B1680);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const IArkPsiPower* const _this, const EArkPsiPowers& _equippedPower)>(0x1B933B0);
	static inline auto FGetErrorString = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x12F5380);
	static inline auto FGetTargetingErrorString = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const IArkPsiPower* const _this)>(0x158AEF0);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(const IArkPsiPower* const _this)>(0x1B933B0);
	static inline auto FGetPowerComponent = PreyFunction<ArkPsiPowerComponent& (const IArkPsiPower* const _this)>(0x15B1700);
	static inline auto FAddCancelToInputLegend = PreyFunction<bool(const IArkPsiPower* const _this, const ArkInputLegend& _original, ArkInputLegend& _cancel)>(0x15B13F0);
	static inline auto FEmitNoise = PreyFunction<void(const IArkPsiPower* const _this)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkInputLegend;
class ArkPsiPowerComponent;
class ArkPsiPowerTargetingComponent;
class ArkSimpleTimer;
class CCryName;
enum class EArkPsiPowerError;
enum class EArkPsiPowers;
struct IEntity;

// IArkPsiPower
// Header:  Prey/GameDll/ark/player/psipower/IArkPsiPower.h
class IArkPsiPower
{ // Size=8 (0x8)
public:
	using PowerArray = std::vector<enum::EArkPsiPowers>;

	static EArkPsiPowers GetEnumFromString(const char* const _string) { return FGetEnumFromString(_string); }
	static const char* GetStringFromEnum(EArkPsiPowers _type) { return FGetStringFromEnum(_type); }
	virtual ~IArkPsiPower();
	virtual const char* GetDescription() const;
	virtual int SetLevel(const int _level);
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual bool GetCanCancel() const;
	virtual void ProcessInput(const CCryName& _actionId, int _activationMode, float _value);
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void RefreshTargets();
	virtual void Update(const float _fFrameTime);
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual void Cancel();
	virtual EArkPsiPowerError GetExecutionError() const;
	virtual bool StartTargeting();
	virtual void OnReset();
	virtual const char* GetHelpText() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual EArkPsiPowers GetEnum() const = 0;
	virtual void Serialize(TSerialize ser);
	virtual void PostSerialize();
	virtual wstring GetTextForEntity(const IEntity& _entity) const;
	virtual bool ShowTextWhileTargeting() const;
	virtual bool Start();
	virtual bool InterruptsMimicGrabSequence() const;
	virtual bool Stop();
	virtual int GetCost() const;
	virtual const char* GetDisplayName() const;
	virtual float GetZoomDuration() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool CanEnterFocusMode(const EArkPsiPowers& _equippedPower) const;
	virtual const char* GetErrorString() const;
	virtual const char* GetTargetingErrorString() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual bool ShouldGenerateGameNoises() const;
	virtual const IEntity* GetPet() const;
	virtual const char* GetIcon() const;
	ArkPsiPowerComponent& GetPowerComponent() const { return FGetPowerComponent(this); }
	bool AddCancelToInputLegend(const ArkInputLegend& _original, ArkInputLegend& _cancel) const { return FAddCancelToInputLegend(this, _original, _cancel); }
	virtual void EmitNoise() const;

#if 0
	void Lock();
	static void SetEntityHighlight(const IEntity& _arg0_, const ColorF& _arg1_);
#endif

	static inline auto FGetEnumFromString = PreyFunction<EArkPsiPowers(const char* const _string)>(0x1087C80);
	static inline auto FGetStringFromEnum = PreyFunction<const char* (EArkPsiPowers _type)>(0x1087D10);
	static inline auto FGetDescription = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FSetLevel = PreyFunction<int(IArkPsiPower* const _this, const int _level)>(0x1338520);
	static inline auto FGetLevel = PreyFunction<int(const IArkPsiPower* const _this)>(0xA554A0);
	static inline auto FGetMaxLevel = PreyFunction<int(const IArkPsiPower* const _this)>(0xA554A0);
	static inline auto FGetCanCancel = PreyFunction<bool(const IArkPsiPower* const _this)>(0x13B0900);
	static inline auto FProcessInput = PreyFunction<void(IArkPsiPower* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FProcessInputForTargeting = PreyFunction<void(IArkPsiPower* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FRefreshTargets = PreyFunction<void(IArkPsiPower* const _this)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(IArkPsiPower* const _this, const float _fFrameTime)>(0x1333E90);
	static inline auto FUpdateTargeting = PreyFunction<void(IArkPsiPower* const _this, const float _fFrameTime)>(0x1333E90);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const IArkPsiPower* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const IArkPsiPower* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FCancel = PreyFunction<void(IArkPsiPower* const _this)>(0x1333E90);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FStartTargeting = PreyFunction<bool(IArkPsiPower* const _this)>(0x1A302A0);
	static inline auto FOnReset = PreyFunction<void(IArkPsiPower* const _this)>(0x1333E90);
	static inline auto FGetHelpText = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const IArkPsiPower* const _this)>(0x16D5BE0);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const IArkPsiPower* const _this)>(0x16D5BE0);
	static inline auto FSerialize = PreyFunction<void(IArkPsiPower* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(IArkPsiPower* const _this)>(0x1333E90);
	static inline auto FGetTextForEntity = PreyFunction<wstring*(const IArkPsiPower* const _this, wstring* _return_value_, const IEntity& _entity)>(0x16D5C20);
	static inline auto FShowTextWhileTargeting = PreyFunction<bool(const IArkPsiPower* const _this)>(0x13B0900);
	static inline auto FStart = PreyFunction<bool(IArkPsiPower* const _this)>(0x1A302A0);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const IArkPsiPower* const _this)>(0x13B0900);
	static inline auto FStop = PreyFunction<bool(IArkPsiPower* const _this)>(0x1A302A0);
	static inline auto FGetCost = PreyFunction<int(const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x13B0AA0);
	static inline auto FGetZoomDuration = PreyFunction<float(const IArkPsiPower* const _this)>(0x714650);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const IArkPsiPower* const _this, Vec3* _return_value_)>(0x9F8FF0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const IArkPsiPower* const _this)>(0x16D59B0);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const IArkPsiPower* const _this)>(0xB00930);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const IArkPsiPower* const _this, ColorF* _return_value_)>(0xE7F6A0);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(IArkPsiPower* const _this, const float _deltaTime)>(0x714650);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const IArkPsiPower* const _this)>(0x16D5A20);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const IArkPsiPower* const _this, const EArkPsiPowers& _equippedPower)>(0x1A302A0);
	static inline auto FGetErrorString = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x13B0B90);
	static inline auto FGetTargetingErrorString = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FShouldGenerateGameNoises = PreyFunction<bool(const IArkPsiPower* const _this)>(0x1A302A0);
	static inline auto FGetPet = PreyFunction<const IEntity* (const IArkPsiPower* const _this)>(0x1CBB0B0);
	static inline auto FGetIcon = PreyFunction<const char* (const IArkPsiPower* const _this)>(0x16D5A90);
	static inline auto FGetPowerComponent = PreyFunction<ArkPsiPowerComponent& (const IArkPsiPower* const _this)>(0x16D5BF0);
	static inline auto FAddCancelToInputLegend = PreyFunction<bool(const IArkPsiPower* const _this, const ArkInputLegend& _original, ArkInputLegend& _cancel)>(0x16D5790);
	static inline auto FEmitNoise = PreyFunction<void(const IArkPsiPower* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
