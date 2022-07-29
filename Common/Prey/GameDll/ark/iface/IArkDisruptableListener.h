// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkDisruptableListener.h
class IArkDisruptableListener // Id=80141DD Size=8
{
public:
	virtual void OnDisruptedChanged(bool arg0, bool arg1) = 0;
	virtual void OnInterferenceChanged(bool _bInterfered);
	virtual QuatT GetSparkLoc() const = 0;
	virtual bool AffectedByDisruption() const;
	virtual void OnDisruptAccumulationValueChanged(const float _value) const;
	virtual void OnInterferenceAccumulationValueChanged(const float _value) const;
	virtual void OnSparkTimerChanged(const float _value) const;
	
	static inline auto FOnInterferenceChanged = PreyFunction<void(IArkDisruptableListener *const _this, bool _bInterfered)>(0xA13080);
	static inline auto FAffectedByDisruption = PreyFunction<bool(IArkDisruptableListener const *const _this)>(0x1B933B0);
	static inline auto FOnDisruptAccumulationValueChanged = PreyFunction<void(IArkDisruptableListener const *const _this, const float _value)>(0xA13080);
	static inline auto FOnInterferenceAccumulationValueChanged = PreyFunction<void(IArkDisruptableListener const *const _this, const float _value)>(0xA13080);
	static inline auto FOnSparkTimerChanged = PreyFunction<void(IArkDisruptableListener const *const _this, const float _value)>(0xA13080);
};

