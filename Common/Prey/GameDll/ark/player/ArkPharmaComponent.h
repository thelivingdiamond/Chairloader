// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkStatsListener.h>
#include <Prey/GameDll/ark/player/ArkPlayerStatusUIInfo.h>

class CCryName;
struct IEntity;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPharmaComponent.h
class ArkPharmaComponent : public IArkStatsListener // Id=80170E2 Size=40
{
public:
	class ActivePharma // Id=80170E3 Size=56
	{
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
		void DeactivatePharma(bool _bImmediate) { FDeactivatePharma(this,_bImmediate); }
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const uint64_t arg0) const;
#endif
		
		static inline auto FActivatePharma = PreyFunction<void(ArkPharmaComponent::ActivePharma *const _this)>(0x1229610);
		static inline auto FDeactivatePharma = PreyFunction<void(ArkPharmaComponent::ActivePharma *const _this, bool _bImmediate)>(0x1229EE0);
	};

	std::vector<ArkPharmaComponent::ActivePharma> m_activePharmas;
	float m_expirationWarningDuration;
	unsigned m_numExpiringPharmas;
	
	ArkPharmaComponent();
	virtual ~ArkPharmaComponent();
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void Reset() { FReset(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void ApplyPharma(IEntity *_pPharma) { FApplyPharma(this,_pPharma); }
	void PopulateUIInfo(std::vector<ArkPlayerStatusUIInfo> &_uiInfo) const { FPopulateUIInfo(this,_uiInfo); }
	virtual void OnStatChange(const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue);
	void ClearExpiringPharmas() { FClearExpiringPharmas(this); }
	
#if 0
	void AddExpiringPharma();
	void RemoveExpiringPharma();
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkPharmaComponent *const _this, float _frameTime)>(0x122A740);
	static inline auto FSerialize = PreyFunction<void(ArkPharmaComponent *const _this, TSerialize _ser)>(0x122A6F0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPharmaComponent *const _this, XmlNodeRef const &_node)>(0x122A2F0);
	static inline auto FReset = PreyFunction<void(ArkPharmaComponent *const _this)>(0x122A680);
	static inline auto FOnGameEnded = PreyFunction<void(ArkPharmaComponent *const _this)>(0x122A680);
	static inline auto FApplyPharma = PreyFunction<void(ArkPharmaComponent *const _this, IEntity *_pPharma)>(0x1229990);
	static inline auto FPopulateUIInfo = PreyFunction<void(ArkPharmaComponent const *const _this, std::vector<ArkPlayerStatusUIInfo> &_uiInfo)>(0x122A370);
	static inline auto FOnStatChange = PreyFunction<void(ArkPharmaComponent *const _this, const unsigned _ownerId, CCryName const &_stat64i32, const float _previousValue, const float _newValue)>(0x122A310);
	static inline auto FClearExpiringPharmas = PreyFunction<void(ArkPharmaComponent *const _this)>(0x1229DF0);
};

