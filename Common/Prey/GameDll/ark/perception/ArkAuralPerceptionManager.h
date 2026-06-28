// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>
#include <Prey/GameDll/ark/perception/ArkSimpleAuralPerceptionInfo.h>
#include <Prey/GameDll/ark/perception/ArkComplexAuralPerceptionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkAuralPerceivable;
class ArkAuralPerceiver;
struct ArkGameNoiseInfo;

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
class ArkAuralPerceptionManager // Id=8014FAD Size=392
{
public:
	struct Noise // Id=8014FAE Size=56
	{
		unsigned m_noiseMakerEntityId;
		ArkGameNoiseInfo m_noiseInfo;
		float m_magnitude;
		Vec3 m_position;
		float m_radius;
	};

	struct RepeatingNoise // Id=8014FAF Size=72
	{
		int m_id;
		ArkAutoResetTimer m_repeatTimer;
		ArkAuralPerceptionManager::Noise m_noise;
		
		RepeatingNoise(int _id, float _repeatPeriod, ArkAuralPerceptionManager::Noise const &_noise);
	};

	struct PerceiverInfo // Id=8014FB0 Size=16
	{
		unsigned m_entityId;
		Vec3 m_hearingPosition;
	};

	struct PerceivableInfo // Id=8014FB1 Size=2
	{
		bool m_bInVacuum;
		bool m_bIsComplex;
	};

	struct PerceivedNoise // Id=8014FB2 Size=24
	{
		uint64_t m_perceiverIndex;
		uint64_t m_noiseIndex;
		float m_occlusion;
		
#if 0
		bool operator<(ArkAuralPerceptionManager::PerceivedNoise const &arg0) const;
#endif
	};

	using ArkSimpleAuralPerceptionInfoVector = std::vector<ArkSimpleAuralPerceptionInfo>;
	using ArkComplexAuralPerceptionInfoVector = std::vector<ArkComplexAuralPerceptionInfo>;
	using AuralPerceiverVector = std::vector<ArkAuralPerceiver *>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int,unsigned __int64>;
	using IndexVector = std::vector<unsigned __int64>;
	using NoiseVector = std::vector<ArkAuralPerceptionManager::Noise>;
	using PerceivableInfoMap = std::map<unsigned int,ArkAuralPerceptionManager::PerceivableInfo,std::less<unsigned int>>;
	using PerceivableVector = std::vector<ArkAuralPerceivable const *>;
	using PerceivedNoiseVector = std::vector<ArkAuralPerceptionManager::PerceivedNoise>;
	using PerceiverInfoVector = std::vector<ArkAuralPerceptionManager::PerceiverInfo>;
	using RepeatingNoiseVector = std::vector<ArkAuralPerceptionManager::RepeatingNoise>;
	
	float m_noiseRadiusScalarInVacuum;
	std::unordered_map<unsigned int,unsigned __int64> m_perceiverIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_perceivableIndexMap;
	std::vector<unsigned __int64> m_freePerceiverIndexes;
	std::vector<ArkAuralPerceiver *> m_perceivers;
	std::vector<unsigned __int64> m_freePerceivableIndexes;
	std::vector<ArkAuralPerceivable const *> m_perceivables;
	std::vector<ArkAuralPerceptionManager::RepeatingNoise> m_repeatingNoises;
	std::vector<ArkAuralPerceptionManager::Noise> m_noises;
	std::vector<ArkAuralPerceptionManager::PerceiverInfo> m_perceiverInfo;
	std::map<unsigned int,ArkAuralPerceptionManager::PerceivableInfo,std::less<unsigned int>> m_perceivableInfo;
	std::vector<ArkAuralPerceptionManager::PerceivedNoise> m_perceivedNoises;
	std::vector<ArkSimpleAuralPerceptionInfo> m_simpleNotificationBuffer;
	std::vector<ArkComplexAuralPerceptionInfo> m_complexNotificationBuffer;
	
	ArkAuralPerceptionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void RegisterPerceiver(unsigned _perceiverEntityId, ArkAuralPerceiver &_perceiver) { FRegisterPerceiver(this,_perceiverEntityId,_perceiver); }
	bool IsPerceiverRegistered(unsigned _perceiverEntityId) { return FIsPerceiverRegistered(this,_perceiverEntityId); }
	void UnregisterPerceiver(unsigned _perceiverEntityId) { FUnregisterPerceiver(this,_perceiverEntityId); }
	void RegisterPerceivable(unsigned _perceivableEntityId, ArkAuralPerceivable const &_perceivable) { FRegisterPerceivable(this,_perceivableEntityId,_perceivable); }
	bool IsPerceivableRegistered(unsigned _perceivableEntityId) const { return FIsPerceivableRegistered(this,_perceivableEntityId); }
	void UnregisterPerceivable(unsigned _perceivableEntityId) { FUnregisterPerceivable(this,_perceivableEntityId); }
	void AddNoise(unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo, float _magnitude, Vec3 const &_position, uint64_t _loudness) { FAddNoise(this,_noiseMakerEntityId,_noiseInfo,_magnitude,_position,_loudness); }
	int AddRepeatingNoise(unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo, float _magnitude, Vec3 const &_position, uint64_t _loudness, float _repeatPeriod) { return FAddRepeatingNoise(this,_noiseMakerEntityId,_noiseInfo,_magnitude,_position,_loudness,_repeatPeriod); }
	void RemoveRepeatingNoise(int _noiseId) { FRemoveRepeatingNoise(this,_noiseId); }
	void UpdateRepeatingNoisePosition(int _noiseId, Vec3 const &_position) { FUpdateRepeatingNoisePosition(this,_noiseId,_position); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	
#if 0
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkAuralPerceptionManager::RepeatingNoise> > > FindRepeatingNoise(int arg0);
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkAuralPerceptionManager *const _this)>(0x145A050);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkAuralPerceptionManager *const _this)>(0x145A290);
	static inline auto FReset = PreyFunction<void(ArkAuralPerceptionManager *const _this, bool _bEnteringGameMode)>(0xA13080);
	static inline auto FRegisterPerceiver = PreyFunction<void(ArkAuralPerceptionManager *const _this, unsigned _perceiverEntityId, ArkAuralPerceiver &_perceiver)>(0x145A480);
	static inline auto FIsPerceiverRegistered = PreyFunction<bool(ArkAuralPerceptionManager *const _this, unsigned _perceiverEntityId)>(0x145A1E0);
	static inline auto FUnregisterPerceiver = PreyFunction<void(ArkAuralPerceptionManager *const _this, unsigned _perceiverEntityId)>(0x145A760);
	static inline auto FRegisterPerceivable = PreyFunction<void(ArkAuralPerceptionManager *const _this, unsigned _perceivableEntityId, ArkAuralPerceivable const &_perceivable)>(0x145A380);
	static inline auto FIsPerceivableRegistered = PreyFunction<bool(ArkAuralPerceptionManager const *const _this, unsigned _perceivableEntityId)>(0x13F1110);
	static inline auto FUnregisterPerceivable = PreyFunction<void(ArkAuralPerceptionManager *const _this, unsigned _perceivableEntityId)>(0x145A650);
	static inline auto FAddNoise = PreyFunction<void(ArkAuralPerceptionManager *const _this, unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo, float _magnitude, Vec3 const &_position, uint64_t _loudness)>(0x1459E30);
	static inline auto FAddRepeatingNoise = PreyFunction<int(ArkAuralPerceptionManager *const _this, unsigned _noiseMakerEntityId, ArkGameNoiseInfo const &_noiseInfo, float _magnitude, Vec3 const &_position, uint64_t _loudness, float _repeatPeriod)>(0x1459EC0);
	static inline auto FRemoveRepeatingNoise = PreyFunction<void(ArkAuralPerceptionManager *const _this, int _noiseId)>(0x145A580);
	static inline auto FUpdateRepeatingNoisePosition = PreyFunction<void(ArkAuralPerceptionManager *const _this, int _noiseId, Vec3 const &_position)>(0x145AF20);
	static inline auto FUpdate = PreyFunction<void(ArkAuralPerceptionManager *const _this, float _elapsedTime)>(0x145A870);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/perception/ArkComplexAuralPerceptionInfo.h>
#include <Prey/GameDll/ark/perception/ArkGameNoiseInfo.h>
#include <Prey/GameDll/ark/perception/ArkSimpleAuralPerceptionInfo.h>

class ArkAuralPerceivable;
class ArkAuralPerceiver;

// ArkAuralPerceptionManager
// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
class ArkAuralPerceptionManager
{ // Size=392 (0x188)
public:
	// ArkAuralPerceptionManager::Noise
	// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
	struct Noise
	{ // Size=56 (0x38)
		unsigned m_noiseMakerEntityId;
		unsigned m_noiseEmitterEntityId;
		ArkGameNoiseInfo m_noiseInfo;
		float m_magnitude;
		Vec3 m_position;
		float m_radius;

	#if 0
		Noise(unsigned _arg0_, unsigned _arg1_, const ArkGameNoiseInfo& _arg2_, float _arg3_, const Vec3& _arg4_, float _arg5_);
	#endif
	};

	// ArkAuralPerceptionManager::RepeatingNoise
	// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
	struct RepeatingNoise
	{ // Size=72 (0x48)
		int m_id;
		ArkAutoResetTimer m_repeatTimer;
		ArkAuralPerceptionManager::Noise m_noise;

		RepeatingNoise(int _id, float _repeatPeriod, const ArkAuralPerceptionManager::Noise& _noise);

		static inline auto FRepeatingNoiseOv2 = PreyFunction<void(ArkAuralPerceptionManager::RepeatingNoise* const _this, int _id, float _repeatPeriod, const ArkAuralPerceptionManager::Noise& _noise)>(0x156FD10);
	};

	// ArkAuralPerceptionManager::PerceiverInfo
	// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
	struct PerceiverInfo
	{ // Size=16 (0x10)
		unsigned m_entityId;
		Vec3 m_hearingPosition;

	#if 0
		PerceiverInfo();
		PerceiverInfo(unsigned _arg0_, const Vec3& _arg1_);
	#endif
	};

	// ArkAuralPerceptionManager::PerceivableInfo
	// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
	struct PerceivableInfo
	{ // Size=2 (0x2)
		bool m_bInVacuum;
		bool m_bIsComplex;

	#if 0
		PerceivableInfo(bool _arg0_, bool _arg1_);
	#endif
	};

	// ArkAuralPerceptionManager::PerceivedNoise
	// Header:  Prey/GameDll/ark/perception/ArkAuralPerceptionManager.h
	struct PerceivedNoise
	{ // Size=24 (0x18)
		uint64_t m_perceiverIndex;
		uint64_t m_noiseIndex;
		float m_occlusion;

	#if 0
		PerceivedNoise(uint64_t _arg0_, uint64_t _arg1_, float _arg2_);
		bool operator<(const ArkAuralPerceptionManager::PerceivedNoise& _arg0_) const;
	#endif
	};

	using ArkSimpleAuralPerceptionInfoVector = std::vector<ArkSimpleAuralPerceptionInfo>;
	using ArkComplexAuralPerceptionInfoVector = std::vector<ArkComplexAuralPerceptionInfo>;
	using AuralPerceiverVector = std::vector<ArkAuralPerceiver*>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int, uint64_t>;
	using IndexVector = std::vector<uint64_t>;
	using NoiseVector = std::vector<ArkAuralPerceptionManager::Noise>;
	using PerceivableInfoMap = std::map<unsigned int, ArkAuralPerceptionManager::PerceivableInfo>;
	using PerceivableVector = std::vector<const ArkAuralPerceivable*>;
	using PerceivedNoiseVector = std::vector<ArkAuralPerceptionManager::PerceivedNoise>;
	using PerceiverInfoVector = std::vector<ArkAuralPerceptionManager::PerceiverInfo>;
	using RepeatingNoiseVector = std::vector<ArkAuralPerceptionManager::RepeatingNoise>;

	float m_noiseRadiusScalarInVacuum;
	std::unordered_map<unsigned int, uint64_t> m_perceiverIndexMap;
	std::unordered_map<unsigned int, uint64_t> m_perceivableIndexMap;
	std::vector<uint64_t> m_freePerceiverIndexes;
	std::vector<ArkAuralPerceiver*> m_perceivers;
	std::vector<uint64_t> m_freePerceivableIndexes;
	std::vector<const ArkAuralPerceivable*> m_perceivables;
	std::vector<ArkAuralPerceptionManager::RepeatingNoise> m_repeatingNoises;
	std::vector<ArkAuralPerceptionManager::Noise> m_noises;
	std::vector<ArkAuralPerceptionManager::PerceiverInfo> m_perceiverInfo;
	std::map<unsigned int, ArkAuralPerceptionManager::PerceivableInfo> m_perceivableInfo;
	std::vector<ArkAuralPerceptionManager::PerceivedNoise> m_perceivedNoises;
	std::vector<ArkSimpleAuralPerceptionInfo> m_simpleNotificationBuffer;
	std::vector<ArkComplexAuralPerceptionInfo> m_complexNotificationBuffer;

	ArkAuralPerceptionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void RegisterPerceiver(unsigned _perceiverEntityId, ArkAuralPerceiver& _perceiver) { FRegisterPerceiver(this, _perceiverEntityId, _perceiver); }
	bool IsPerceiverRegistered(unsigned _perceiverEntityId) { return FIsPerceiverRegistered(this, _perceiverEntityId); }
	void UnregisterPerceiver(unsigned _perceiverEntityId) { FUnregisterPerceiver(this, _perceiverEntityId); }
	void RegisterPerceivable(unsigned _perceivableEntityId, const ArkAuralPerceivable& _perceivable) { FRegisterPerceivable(this, _perceivableEntityId, _perceivable); }
	bool IsPerceivableRegistered(unsigned _perceivableEntityId) const { return FIsPerceivableRegistered(this, _perceivableEntityId); }
	void UnregisterPerceivable(unsigned _perceivableEntityId) { FUnregisterPerceivable(this, _perceivableEntityId); }
	void AddNoise(unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _position, uint64_t _loudness) { FAddNoise(this, _noiseMakerEntityId, _noiseEmitterEntityId, _noiseInfo, _magnitude, _position, _loudness); }
	int AddRepeatingNoise(unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _position, uint64_t _loudness, float _repeatPeriod) { return FAddRepeatingNoise(this, _noiseMakerEntityId, _noiseEmitterEntityId, _noiseInfo, _magnitude, _position, _loudness, _repeatPeriod); }
	void RemoveRepeatingNoise(int _noiseId) { FRemoveRepeatingNoise(this, _noiseId); }
	void UpdateRepeatingNoisePosition(int _noiseId, const Vec3& _position) { FUpdateRepeatingNoisePosition(this, _noiseId, _position); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }

#if 0
	ArkAuralPerceptionManager(const ArkAuralPerceptionManager& _arg0_);
	ArkAuralPerceptionManager& operator=(const ArkAuralPerceptionManager& _arg0_);
	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ArkAuralPerceptionManager::RepeatingNoise> > > FindRepeatingNoise(int _arg0_);
#endif

	static inline auto FArkAuralPerceptionManagerOv1 = PreyFunction<void(ArkAuralPerceptionManager* const _this)>(0x156FBD0);
	static inline auto FInitialize = PreyFunction<void(ArkAuralPerceptionManager* const _this)>(0x156FFD0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkAuralPerceptionManager* const _this)>(0x1570160);
	static inline auto FReset = PreyFunction<void(ArkAuralPerceptionManager* const _this, bool _bEnteringGameMode)>(0x1333E90);
	static inline auto FRegisterPerceiver = PreyFunction<void(ArkAuralPerceptionManager* const _this, unsigned _perceiverEntityId, ArkAuralPerceiver& _perceiver)>(0x1570350);
	static inline auto FIsPerceiverRegistered = PreyFunction<bool(ArkAuralPerceptionManager* const _this, unsigned _perceiverEntityId)>(0x12BA340);
	static inline auto FUnregisterPerceiver = PreyFunction<void(ArkAuralPerceptionManager* const _this, unsigned _perceiverEntityId)>(0x1570630);
	static inline auto FRegisterPerceivable = PreyFunction<void(ArkAuralPerceptionManager* const _this, unsigned _perceivableEntityId, const ArkAuralPerceivable& _perceivable)>(0x1570250);
	static inline auto FIsPerceivableRegistered = PreyFunction<bool(const ArkAuralPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x1502A30);
	static inline auto FUnregisterPerceivable = PreyFunction<void(ArkAuralPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x1570520);
	static inline auto FAddNoise = PreyFunction<void(ArkAuralPerceptionManager* const _this, unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _position, uint64_t _loudness)>(0x156FD90);
	static inline auto FAddRepeatingNoise = PreyFunction<int(ArkAuralPerceptionManager* const _this, unsigned _noiseMakerEntityId, unsigned _noiseEmitterEntityId, const ArkGameNoiseInfo& _noiseInfo, float _magnitude, const Vec3& _position, uint64_t _loudness, float _repeatPeriod)>(0x156FE30);
	static inline auto FRemoveRepeatingNoise = PreyFunction<void(ArkAuralPerceptionManager* const _this, int _noiseId)>(0x1570450);
	static inline auto FUpdateRepeatingNoisePosition = PreyFunction<void(ArkAuralPerceptionManager* const _this, int _noiseId, const Vec3& _position)>(0x1570E00);
	static inline auto FUpdate = PreyFunction<void(ArkAuralPerceptionManager* const _this, float _elapsedTime)>(0x1570740);
};
#endif // !MOONCRASH
