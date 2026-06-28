// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpc;
struct IAttachment;

// ArkNpcMeleeDamageDealer
// Header:  Prey/GameDll/ark/npc/ArkNpcMeleeDamageDealer.h
class ArkNpcMeleeDamageDealer
{ // Size=88 (0x58)
public:
	using DamagedEntityVector = std::vector<unsigned int>;

	const ArkNpc* m_pNpc;
	_smart_ptr<IAttachment> m_pAttachment;
	float m_radius;
	uint64_t m_signalPackageId;
	float m_signalPackageScale;
	float m_playerImpulse;
	float m_npcImpulse;
	float m_otherImpulse;
	Vec3 m_prevAttachmentPosition;
	std::vector<unsigned int> m_damagedEntities;

	ArkNpcMeleeDamageDealer(const ArkNpc& _npc, IAttachment& _attachment, float _radius, uint64_t _signalPackageId, float _signalPackageScale, float _playerImpulse, float _npcImpulse, float _otherImpulse);
	~ArkNpcMeleeDamageDealer();
	void Refresh() { FRefresh(this); }
	void DamageHitEntities() { FDamageHitEntities(this); }

#if 0
	void PopulateHitEntities() const;
	void FilterHitEntities() const;
#endif

	static inline auto FArkNpcMeleeDamageDealerOv1 = PreyFunction<void(ArkNpcMeleeDamageDealer* const _this, const ArkNpc& _npc, IAttachment& _attachment, float _radius, uint64_t _signalPackageId, float _signalPackageScale, float _playerImpulse, float _npcImpulse, float _otherImpulse)>(0x1294130);
	static inline auto FBitNotArkNpcMeleeDamageDealer = PreyFunction<void(ArkNpcMeleeDamageDealer* const _this)>(0x12941F0);
	static inline auto FRefresh = PreyFunction<void(ArkNpcMeleeDamageDealer* const _this)>(0x1294770);
	static inline auto FDamageHitEntities = PreyFunction<void(ArkNpcMeleeDamageDealer* const _this)>(0x1294220);
};
#endif // MOONCRASH
