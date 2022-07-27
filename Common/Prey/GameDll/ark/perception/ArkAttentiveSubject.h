// Header file automatically created from a PDB.

#pragma once

struct ArkAttentionLevelChange;

// Header: Override
// Prey/GameDll/ark/perception/ArkAttentiveSubject.h
class ArkAttentiveSubject // Id=801430C Size=8
{
public:
	uint64_t GetAttentionModelId() const { return FGetAttentionModelId(this); }
	void GetAttentiveSubjectInfo(bool &_bUpdateAttentionLevels, Vec3 &_position) const { FGetAttentiveSubjectInfo(this,_bUpdateAttentionLevels,_position); }
	void OnAttentionLevelsChanged(ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange) { FOnAttentionLevelsChanged(this,_pFirstChange,_pLastChange); }
	void OnAttentionProxiesUpdated(const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId) { FOnAttentionProxiesUpdated(this,_pFirstEntityId,_pLastEntityId); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual uint64_t DoGetAttentionModelId() const = 0;
	virtual void DoGetAttentiveSubjectInfo(bool &arg0, Vec3 &arg1) const = 0;
	virtual void DoOnAttentionLevelsChanged(ArkAttentionLevelChange const *arg0, ArkAttentionLevelChange const *arg1) = 0;
	virtual void DoOnAttentionProxiesUpdated(const unsigned *arg0, const unsigned *arg1) = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FGetAttentionModelId = PreyFunction<uint64_t(ArkAttentiveSubject const *const _this)>(0x172F070);
	static inline auto FGetAttentiveSubjectInfo = PreyFunction<void(ArkAttentiveSubject const *const _this, bool &_bUpdateAttentionLevels, Vec3 &_position)>(0x15AAEA0);
	static inline auto FOnAttentionLevelsChanged = PreyFunction<void(ArkAttentiveSubject *const _this, ArkAttentionLevelChange const *_pFirstChange, ArkAttentionLevelChange const *_pLastChange)>(0x12941A0);
	static inline auto FOnAttentionProxiesUpdated = PreyFunction<void(ArkAttentiveSubject *const _this, const unsigned *_pFirstEntityId, const unsigned *_pLastEntityId)>(0x12B5B30);
};

