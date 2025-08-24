// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkDisruptionProfile;
struct ArkLightManagerDisruptableData;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class IArkDisruptableListener;
struct IGameObjectExtension;

// Header: FromCpp
// Prey/GameDll/ark/ArkDisruptable.h
class ArkDisruptable // Id=80141E0 Size=152
{
public:
	IGameObjectExtension &m_extension;
	IArkDisruptableListener &m_listener;
	float m_disruptAccumulation;
	float m_interferenceAccumulation;
	ArkRandomizedAutoResetTimer m_sparkTimer;
	bool m_bDisrupted;
	bool m_bInterfered;
	std::vector<unsigned int> m_uniqueSignalPackages;
	ArkDisruptionProfile const *m_pProfile;
	ArkAudioTrigger m_triggerSpark;
	ArkFireAndForgetEffect m_sparkVfx;
	
	ArkDisruptable(IArkDisruptableListener &_listener, IGameObjectExtension &_extension);
	virtual ~ArkDisruptable();
	void Spark() { FSpark(this); }
	void ResetAccumulators() { FResetAccumulators(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnReceiveSignal(ArkSignalSystem::Package const &_package) { FOnReceiveSignal(this,_package); }
	void RegisterForSignals(const bool _bRegister) { FRegisterForSignals(this,_bRegister); }
	void LoadProperties() { FLoadProperties(this); }
	void ApplySerializedData(ArkLightManagerDisruptableData const &_data) { FApplySerializedData(this,_data); }
	void SetDisrupted(bool _bDisrupted, bool _bForce) { FSetDisrupted(this,_bDisrupted,_bForce); }
	
#if 0
	bool IsDisrupted() const;
	bool IsInterfered() const;
	void SetInterfered(bool arg0, bool arg1);
	void SetDisruptAccumulation(const float arg0);
	void SetInterferenceAccumulation(const float arg0);
	void PreSerialize() const;
#endif
	
	static inline auto FBitNotArkDisruptable = PreyFunction<void(ArkDisruptable *const _this)>(0x1153550);
	static inline auto FSpark = PreyFunction<void(ArkDisruptable *const _this)>(0x11543C0);
	static inline auto FResetAccumulators = PreyFunction<void(ArkDisruptable *const _this)>(0x1154120);
	static inline auto FUpdate = PreyFunction<void(ArkDisruptable *const _this, float _frameTime)>(0x1154470);
	static inline auto FSerialize = PreyFunction<void(ArkDisruptable *const _this, TSerialize _ser)>(0x11541E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkDisruptable *const _this)>(0x1153F90);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkDisruptable *const _this, ArkSignalSystem::Package const &_package)>(0x1153CF0);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkDisruptable *const _this, const bool _bRegister)>(0x1154000);
	static inline auto FLoadProperties = PreyFunction<void(ArkDisruptable *const _this)>(0x11537C0);
	static inline auto FApplySerializedData = PreyFunction<void(ArkDisruptable *const _this, ArkLightManagerDisruptableData const &_data)>(0x11535D0);
	static inline auto FSetDisrupted = PreyFunction<void(ArkDisruptable *const _this, bool _bDisrupted, bool _bForce)>(0x1154300);
};

