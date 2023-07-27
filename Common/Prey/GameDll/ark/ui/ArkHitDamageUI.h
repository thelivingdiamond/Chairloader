// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkHitDamageInfo.h>

struct HitInfo;
struct ICVar;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkHitDamageUI.h
class ArkHitDamageUI // Id=80176B8 Size=416
{
public:
	static constexpr const unsigned s_numIndicators = 8;
	std::array<ArkHitDamageInfo,8> m_hits;
	std::vector<unsigned int> m_updateHits;
	ICVar *m_pEnableCvar;
	
	ArkHitDamageUI();
	~ArkHitDamageUI();
	void Init() const { FInit(this); }
	void Add(HitInfo const &_hitInfo) { FAdd(this,_hitInfo); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void UpdateHUDMarkers() { FUpdateHUDMarkers(this); }
	
#if 0
	bool IsEnabled() const;
	unsigned FindBestAvailable() const;
#endif
	
	static inline auto FBitNotArkHitDamageUI = PreyFunction<void(ArkHitDamageUI *const _this)>(0x1349CF0);
	static inline auto FInit = PreyFunction<void(ArkHitDamageUI const *const _this)>(0x1349EA0);
	static inline auto FAdd = PreyFunction<void(ArkHitDamageUI *const _this, HitInfo const &_hitInfo)>(0x1349D30);
	static inline auto FUpdate = PreyFunction<void(ArkHitDamageUI *const _this, float _frameTime)>(0x1349ED0);
	static inline auto FUpdateHUDMarkers = PreyFunction<void(ArkHitDamageUI *const _this)>(0x134A4E0);
};

