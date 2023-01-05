// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkPOIComponent
// Header:  Prey/GameDll/ark/player/ArkPOIComponent.h
class ArkPOIComponent
{ // Size=96 (0x60)
public:
	// ArkPOIComponent::SEntityPOI
	// Header:  Prey/GameDll/ark/player/ArkPOIComponent.h
	struct SEntityPOI
	{ // Size=24 (0x18)
		unsigned entityId;
		uint64_t poiId;
		float minRange;
		float maxRange;

	#if 0
		SEntityPOI();
		SEntityPOI(unsigned _arg0_, uint64_t _arg1_, float _arg2_, float _arg3_);
		void Serialize(TSerialize _arg0_);
		bool operator==(unsigned _arg0_);
	#endif
	};

	using TPOIMarkers = std::vector<ArkPOIComponent::SEntityPOI>;

	std::unordered_map<string, std::vector<ArkPOIComponent::SEntityPOI>> m_pois;
	std::vector<unsigned int> m_markers;
	unsigned m_labelPOI;

	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void AddMarker(unsigned _entityId, uint64_t _poiId, float _minRange, float _maxRange) { FAddMarker(this, _entityId, _poiId, _minRange, _maxRange); }
	void RemoveMarker(unsigned _entityId) { FRemoveMarker(this, _entityId); }
	void UpdateMarkers() { FUpdateMarkers(this); }

	static inline auto FReset = PreyFunction<void(ArkPOIComponent* const _this)>(0x1301610);
	static inline auto FSerialize = PreyFunction<void(ArkPOIComponent* const _this, TSerialize _ser)>(0x1301640);
	static inline auto FPostSerialize = PreyFunction<void(ArkPOIComponent* const _this)>(0x1301360);
	static inline auto FAddMarker = PreyFunction<void(ArkPOIComponent* const _this, unsigned _entityId, uint64_t _poiId, float _minRange, float _maxRange)>(0x1301160);
	static inline auto FRemoveMarker = PreyFunction<void(ArkPOIComponent* const _this, unsigned _entityId)>(0x1301440);
	static inline auto FUpdateMarkers = PreyFunction<void(ArkPOIComponent* const _this)>(0x1301660);
};

