// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryCore/Containers/VectorMap.h>
#include <Prey/GameDll/ark/ArkLightManagerDisruptableData.h>
#include <Prey/GameDll/ark/ArkLightManager.h>

// Header: FromCpp
// Prey/GameDll/ark/arklightmanager.h
struct ArkLightManagerLightData // Id=80141F0 Size=84
{
	struct SubLightData // Id=80141F1 Size=16
	{
		Vec3 m_cDiffuseColor;
		uint8_t m_nLightStyle;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::array<ArkLightManagerLightData::SubLightData,2> m_sublights;
	ArkLightManagerDisruptableData m_disruptable;
	float m_fBrightness;
	float m_fTimeBrightness;
	float m_empBrightness;
	float m_empTargetBrightness;
	float m_empInfluence;
	float m_empTargetInfluence;
	float m_health;
	EArkLightInterferenceState m_interferenceState;
	bool m_bWasMoved;
	bool m_bLightsDisabledFromMovement;
	bool m_bNeedDisableShadows;
	
	ArkLightManagerLightData();
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
	static inline auto FSerialize = PreyFunction<void(ArkLightManagerLightData *const _this, TSerialize _ser)>(0x1189E60);
};

// Header: FromCpp
// Prey/GameDll/ark/ArkLightManager.h
class ArkLightManager // Id=80169B2 Size=56
{
public:
	std::vector<ArkTimeRemaining> m_recentBursts;
	VectorMap<unsigned int,ArkLightManagerLightData,std::less<unsigned int>,std::allocator<std::pair<unsigned int,ArkLightManagerLightData> > > m_lightData;
	float m_particleBurstsPerSecond;
	float m_maxDistanceFromPlayerSq;
	
	ArkLightManager();
	void Init() { FInit(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	bool TestInterferenceBurst(Vec3 _pos) { return FTestInterferenceBurst(this,_pos); }
	void PostSerialize() { FPostSerialize(this); }
	
#if 0
	void Serialize(TSerialize arg0);
	void OnLevelLoad();
	void SetBrightness(const unsigned arg0, const float arg1);
	void SetTimeBrightness(const unsigned arg0, const float arg1);
	void SetEmpBrightness(const unsigned arg0, const float arg1);
	void SetEmpTargetBrightness(const unsigned arg0, const float arg1);
	void SetEmpInfluence(const unsigned arg0, const float arg1);
	void SetEmpTargetInfluence(const unsigned arg0, const float arg1);
	void SetHealth(const unsigned arg0, const float arg1);
	void SetInterferenceState(const unsigned arg0, EArkLightInterferenceState arg1);
	void SetWasMoved(const unsigned arg0, const bool arg1);
	void SetLightsDisabledFromMovement(const unsigned arg0, const bool arg1);
	void SetNeedsDisableShadows(const unsigned arg0, const bool arg1);
	void SetDiffuseColor(const unsigned arg0, const int arg1, Vec3 arg2);
	void SetLightStyle(const unsigned arg0, const int arg1, const uint8_t arg2);
	void SetDisruptableDisruptAccumulation(const unsigned arg0, const float arg1);
	void SetDisruptableInterferenceAccumulation(const unsigned arg0, const float arg1);
	void SetDisruptableSparkTimerTimeRemaining(const unsigned arg0, const float arg1);
	void SetDisruptableDisrupted(const unsigned arg0, const bool arg1);
	void SetDisruptableInterfered(const unsigned arg0, const bool arg1);
#endif
	
	static inline auto FInit = PreyFunction<void(ArkLightManager *const _this)>(0x1189BE0);
	static inline auto FUpdate = PreyFunction<void(ArkLightManager *const _this, float _frameTime)>(0x118A060);
	static inline auto FTestInterferenceBurst = PreyFunction<bool(ArkLightManager *const _this, Vec3 _pos)>(0x1189F90);
	static inline auto FPostSerialize = PreyFunction<void(ArkLightManager *const _this)>(0x1189D50);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/vectormap.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkLightManagerDisruptableData.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

// ArkLightManager
// Header:  Prey/GameDll/ark/ArkLightManager.h
class ArkLightManager
{ // Size=56 (0x38)
public:
	std::vector<ArkTimeRemaining> m_recentBursts;
	VectorMap<unsigned int,ArkLightManagerLightData,std::less<unsigned int>,std::allocator<std::pair<unsigned int,ArkLightManagerLightData> > > m_lightData;
	float m_particleBurstsPerSecond;
	float m_maxDistanceFromPlayerSq;

	ArkLightManager();
	void Init() { FInit(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	bool TestInterferenceBurst(Vec3 _pos) { return FTestInterferenceBurst(this, _pos); }
	void PostSerialize() { FPostSerialize(this); }

#if 0
	void Serialize(TSerialize _arg0_);
	void OnLevelLoad();
	void SetBrightness(const unsigned _arg0_, const float _arg1_);
	void SetTimeBrightness(const unsigned _arg0_, const float _arg1_);
	void SetEmpBrightness(const unsigned _arg0_, const float _arg1_);
	void SetEmpTargetBrightness(const unsigned _arg0_, const float _arg1_);
	void SetEmpInfluence(const unsigned _arg0_, const float _arg1_);
	void SetEmpTargetInfluence(const unsigned _arg0_, const float _arg1_);
	void SetHealth(const unsigned _arg0_, const float _arg1_);
	void SetInterferenceState(const unsigned _arg0_, const EArkLightInterferenceState _arg1_);
	void SetWasMoved(const unsigned _arg0_, const bool _arg1_);
	void SetLightsDisabledFromMovement(const unsigned _arg0_, const bool _arg1_);
	void SetNeedsDisableShadows(const unsigned _arg0_, const bool _arg1_);
	void SetDiffuseColor(const unsigned _arg0_, const int _arg1_, const Vec3 _arg2_);
	void SetLightStyle(const unsigned _arg0_, const int _arg1_, const uint8_t _arg2_);
	void SetDisruptableDisruptAccumulation(const unsigned _arg0_, const float _arg1_);
	void SetDisruptableInterferenceAccumulation(const unsigned _arg0_, const float _arg1_);
	void SetDisruptableSparkTimerTimeRemaining(const unsigned _arg0_, const float _arg1_);
	void SetDisruptableDisrupted(const unsigned _arg0_, const bool _arg1_);
	void SetDisruptableInterfered(const unsigned _arg0_, const bool _arg1_);
#endif

	static inline auto FArkLightManagerOv2 = PreyFunction<void(ArkLightManager* const _this)>(0x1257E30);
	static inline auto FInit = PreyFunction<void(ArkLightManager* const _this)>(0x1204E00);
	static inline auto FUpdate = PreyFunction<void(ArkLightManager* const _this, float _frameTime)>(0x1205280);
	static inline auto FTestInterferenceBurst = PreyFunction<bool(ArkLightManager* const _this, Vec3 _pos)>(0x12051B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkLightManager* const _this)>(0x1204F70);
};

// ArkLightManagerLightData
// Header:  Prey/GameDll/ark/ArkLightManager.h
struct ArkLightManagerLightData
{ // Size=84 (0x54)
	// ArkLightManagerLightData::SubLightData
	// Header:  Prey/GameDll/ark/ArkLightManager.h
	struct SubLightData
	{ // Size=16 (0x10)
		Vec3 m_cDiffuseColor;
		uint8_t m_nLightStyle;

	#if 0
		SubLightData();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::array<ArkLightManagerLightData::SubLightData, 2> m_sublights;
	ArkLightManagerDisruptableData m_disruptable;
	float m_fBrightness;
	float m_fTimeBrightness;
	float m_empBrightness;
	float m_empTargetBrightness;
	float m_empInfluence;
	float m_empTargetInfluence;
	float m_health;
	EArkLightInterferenceState m_interferenceState;
	bool m_bWasMoved;
	bool m_bLightsDisabledFromMovement;
	bool m_bNeedDisableShadows;

	ArkLightManagerLightData();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

	static inline auto FArkLightManagerLightDataOv2 = PreyFunction<void(ArkLightManagerLightData* const _this)>(0x1204DB0);
	static inline auto FSerialize = PreyFunction<void(ArkLightManagerLightData* const _this, TSerialize _ser)>(0x1205080);
};
#endif // !MOONCRASH
