// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/signalsystem/arksignalmanager.h>

class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ArkSignalDispositionModifier.h
class ArkSignalDispositionModifier // Id=80138D0 Size=320
{
public:
	std::array<std::unordered_map<unsigned __int64,float>,4> m_dispositionFactors;
	std::unordered_map<unsigned __int64,float> m_enslavedFactors;
	
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	float GetFactor(const unsigned _instigatorId, const unsigned _ownerId, std::vector<ArkSignalSystem::Package::Value> const &_values) const { return FGetFactor(this,_instigatorId,_ownerId,_values); }
	
	static inline auto FLoadConfig = PreyFunction<void(ArkSignalDispositionModifier *const _this, XmlNodeRef const &_root)>(0x11AEF00);
	static inline auto FGetFactor = PreyFunction<float(ArkSignalDispositionModifier const *const _this, const unsigned _instigatorId, const unsigned _ownerId, std::vector<ArkSignalSystem::Package::Value> const &_values)>(0x11AEDA0);
};

