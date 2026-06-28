// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkNpcConeDamageDealer
// Header:  Prey/GameDll/ark/npc/ArkNpcConeDamageDealer.h
class ArkNpcConeDamageDealer
{ // Size=112 (0x70)
public:
	QuatT m_worldTm;
	const IEntity* m_pEntity;
	uint64_t m_signalPackageId;
	float m_signalPackageScale;
	float m_playerImpulse;
	float m_npcImpulse;
	float m_otherImpulse;
	float m_coneStartRadius;
	float m_coneEndRadius;
	float m_coneStartToEndDistance;
	float m_coneFullLength;
	float m_coneCosAngle;
	Vec3 m_prevPosition;
	bool m_bImpulseTowardsSource;
	float m_impulseTowardsSourceAngle;
	float m_maxHeightFromCenter;
	float m_impulseIgnoreRadius;

	ArkNpcConeDamageDealer();
	~ArkNpcConeDamageDealer();
	void Initialize(const IEntity& _entity, uint64_t _signalPackageId, float _signalPackageScale, float _playerImpulse, float _npcImpulse, float _otherImpulse, float _coneStartRadius, float _coneEndRadius, float _coneStartToEndDistance, bool _bImpulseTowardsSource, float _impulseTowardsSourceAngle, float _maxHeightFromCenter, float _impulseIgnoreRadius) { FInitialize(this, _entity, _signalPackageId, _signalPackageScale, _playerImpulse, _npcImpulse, _otherImpulse, _coneStartRadius, _coneEndRadius, _coneStartToEndDistance, _bImpulseTowardsSource, _impulseTowardsSourceAngle, _maxHeightFromCenter, _impulseIgnoreRadius); }
	void SetWorldTm(const QuatT& _worldTm) { FSetWorldTm(this, _worldTm); }
	void UpdatePrevPos() { FUpdatePrevPos(this); }
	void Refresh() { FRefresh(this); }
	float GetConeCosAngle() const { return FGetConeCosAngle(this); }
	void PopulateHitEntities() const { FPopulateHitEntities(this); }
	void DamageHitEntities() { FDamageHitEntities(this); }

	static inline auto FArkNpcConeDamageDealerOv1 = PreyFunction<void(ArkNpcConeDamageDealer* const _this)>(0x128B410);
	static inline auto FBitNotArkNpcConeDamageDealer = PreyFunction<void(ArkNpcConeDamageDealer* const _this)>(0x1333E90);
	static inline auto FInitialize = PreyFunction<void(ArkNpcConeDamageDealer* const _this, const IEntity& _entity, uint64_t _signalPackageId, float _signalPackageScale, float _playerImpulse, float _npcImpulse, float _otherImpulse, float _coneStartRadius, float _coneEndRadius, float _coneStartToEndDistance, bool _bImpulseTowardsSource, float _impulseTowardsSourceAngle, float _maxHeightFromCenter, float _impulseIgnoreRadius)>(0x128BF50);
	static inline auto FSetWorldTm = PreyFunction<void(ArkNpcConeDamageDealer* const _this, const QuatT& _worldTm)>(0x128C4A0);
	static inline auto FUpdatePrevPos = PreyFunction<void(ArkNpcConeDamageDealer* const _this)>(0x128C4D0);
	static inline auto FRefresh = PreyFunction<void(ArkNpcConeDamageDealer* const _this)>(0x128C450);
	static inline auto FGetConeCosAngle = PreyFunction<float(const ArkNpcConeDamageDealer* const _this)>(0x128BF40);
	static inline auto FPopulateHitEntities = PreyFunction<void(const ArkNpcConeDamageDealer* const _this)>(0x128C050);
	static inline auto FDamageHitEntities = PreyFunction<void(ArkNpcConeDamageDealer* const _this)>(0x128B810);
};
#endif // MOONCRASH
