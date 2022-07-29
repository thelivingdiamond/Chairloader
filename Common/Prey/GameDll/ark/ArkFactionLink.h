// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/iface/IArkFactionListener.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkFactionLink.h
struct ArkFactionLink : public IArkFactionListener // Id=8014306 Size=24
{
	unsigned m_parentEntityId;
	unsigned m_parentFaction;
	unsigned m_linkedFaction;
	
	ArkFactionLink();
	~ArkFactionLink();
	void Initialize(unsigned _parentEntityId, unsigned _parentFaction, unsigned _linkedFaction) { FInitialize(this,_parentEntityId,_parentFaction,_linkedFaction); }
	virtual void OnAssignedFactionToFactionDispositionChange(unsigned _fromFaction, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedFactionToEntityDispositionChange(unsigned _fromFaction, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedEntityToFactionDispositionChange(unsigned _fromEntity, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new);
	virtual void OnAssignedEntityToEntityDispositionChange(unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new);
	
#if 0
	void Deinitialize();
#endif
	
	static inline auto FBitNotArkFactionLink = PreyFunction<void(ArkFactionLink *const _this)>(0x11688F0);
	static inline auto FInitialize = PreyFunction<void(ArkFactionLink *const _this, unsigned _parentEntityId, unsigned _parentFaction, unsigned _linkedFaction)>(0x1168900);
	static inline auto FOnAssignedFactionToFactionDispositionChange = PreyFunction<void(ArkFactionLink *const _this, unsigned _fromFaction, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new)>(0x11689C0);
	static inline auto FOnAssignedFactionToEntityDispositionChange = PreyFunction<void(ArkFactionLink *const _this, unsigned _fromFaction, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new)>(0x1168990);
	static inline auto FOnAssignedEntityToFactionDispositionChange = PreyFunction<void(ArkFactionLink *const _this, unsigned _fromEntity, unsigned _toFaction, EArkDisposition _old, EArkDisposition _new)>(0x1168960);
	static inline auto FOnAssignedEntityToEntityDispositionChange = PreyFunction<void(ArkFactionLink *const _this, unsigned _fromEntity, unsigned _toEntity, EArkDisposition _old, EArkDisposition _new)>(0x1168930);
};

