// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkPlayerStatusUIInfo.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>

class CCryName;
struct IEntity;
class XmlNodeRef;

// ArkPharmaComponent
// Header:  Prey/GameDll/ark/player/ArkPharmaComponent.h
class ArkPharmaComponent : public IArkStatsListener
{ // Size=40 (0x28)
public:
	// ArkPharmaComponent::ActivePharma
	// Header:  Prey/GameDll/ark/player/ArkPharmaComponent.h
	class ActivePharma
	{ // Size=56 (0x38)
	public:
		ArkTimeRemaining m_timeRemaining;
		uint64_t m_archetypeId;
		unsigned m_statPackageId;
		bool m_bWasExpiring;
		string m_pharmaName;
		string m_effectsText;
		string m_removalText;
		string m_icon;

		void ActivatePharma() { FActivatePharma(this); }
		void DeactivatePharma(bool _bImmediate) { FDeactivatePharma(this, _bImmediate); }

	#if 0
		ActivePharma();
		ActivePharma(const float _arg0_, const uint64_t _arg1_, const char* _arg2_, const char* _arg3_, const char* _arg4_, const char* _arg5_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const uint64_t _arg0_) const;
	#endif

		static inline auto FActivatePharma = PreyFunction<void(ArkPharmaComponent::ActivePharma* const _this)>(0x1229610);
		static inline auto FDeactivatePharma = PreyFunction<void(ArkPharmaComponent::ActivePharma* const _this, bool _bImmediate)>(0x1229EE0);
	};

	std::vector<ArkPharmaComponent::ActivePharma> m_activePharmas;
	float m_expirationWarningDuration;
	unsigned m_numExpiringPharmas;

	ArkPharmaComponent();
	virtual ~ArkPharmaComponent();
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Reset() { FReset(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void ApplyPharma(IEntity* _pPharma) { FApplyPharma(this, _pPharma); }
	void PopulateUIInfo(std::vector<ArkPlayerStatusUIInfo>& _uiInfo) const { FPopulateUIInfo(this, _uiInfo); }
	virtual void OnStatChange(const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue);
	void ClearExpiringPharmas() { FClearExpiringPharmas(this); }

#if 0
	void AddExpiringPharma();
	void RemoveExpiringPharma();
#endif

	static inline auto FArkPharmaComponentOv1 = PreyFunction<void(ArkPharmaComponent* const _this)>(0x1229380);
	static inline auto FUpdate = PreyFunction<void(ArkPharmaComponent* const _this, float _frameTime)>(0x122A740);
	static inline auto FSerialize = PreyFunction<void(ArkPharmaComponent* const _this, TSerialize _ser)>(0x122A6F0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPharmaComponent* const _this, const XmlNodeRef& _node)>(0x122A2F0);
	static inline auto FReset = PreyFunction<void(ArkPharmaComponent* const _this)>(0x122A680);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPharmaComponent* const _this)>(0x122A680);
	static inline auto FApplyPharma = PreyFunction<void(ArkPharmaComponent* const _this, IEntity* _pPharma)>(0x1229990);
	static inline auto FPopulateUIInfo = PreyFunction<void(const ArkPharmaComponent* const _this, std::vector<ArkPlayerStatusUIInfo>& _uiInfo)>(0x122A370);
	static inline auto FOnStatChange = PreyFunction<void(ArkPharmaComponent* const _this, const unsigned _ownerId, const CCryName& _stat64i32, const float _previousValue, const float _newValue)>(0x122A310);
	static inline auto FClearExpiringPharmas = PreyFunction<void(ArkPharmaComponent* const _this)>(0x1229DF0);
};

