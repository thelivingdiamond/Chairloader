// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkFactionListener.h
class IArkFactionListener // Id=800B7C0 Size=8
{
public:
	virtual void OnAssignedFactionToFactionDispositionChange(unsigned _fromFaction, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedFactionToEntityDispositionChange(unsigned _fromFaction, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedEntityToFactionDispositionChange(unsigned _fromEntity, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedEntityToEntityDispositionChange(unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new);
	virtual void OnEffectiveEntityToEntityDispositionChange(unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new);
	
	static inline auto FOnAssignedFactionToFactionDispositionChange = PreyFunction<void(IArkFactionListener *const _this, unsigned _fromFaction, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new)>(0xA13080);
	static inline auto FOnAssignedFactionToEntityDispositionChange = PreyFunction<void(IArkFactionListener *const _this, unsigned _fromFaction, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new)>(0xA13080);
	static inline auto FOnAssignedEntityToFactionDispositionChange = PreyFunction<void(IArkFactionListener *const _this, unsigned _fromEntity, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new)>(0xA13080);
	static inline auto FOnAssignedEntityToEntityDispositionChange = PreyFunction<void(IArkFactionListener *const _this, unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new)>(0xA13080);
	static inline auto FOnEffectiveEntityToEntityDispositionChange = PreyFunction<void(IArkFactionListener *const _this, unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new)>(0xA13080);
};

