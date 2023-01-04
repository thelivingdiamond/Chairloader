// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h>

class ArkPsiLift;
struct IEntity;

// ArkPlayerLiftEntityZeroG
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntityZeroG.h
class ArkPlayerLiftEntityZeroG
{ // Size=12 (0xC)
public:
	ArkSimpleTimer m_destroyGooTimer;
	float m_speed;

	ArkPlayerLiftEntityZeroG();
	void ExitLiftVolume(const IEntity& _entity) const { FExitLiftVolume(this, _entity); }
	void Update(const IEntity& _entity, const ArkPsiLift& _lift, const float _frameTime) const { FUpdate(this, _entity, _lift, _frameTime); }

#if 0
	ArkPlayerLiftEntityZeroG(const float _arg0_);
	void EnterLiftVolume(const IEntity& _arg0_) const;
	void PostSerialize(const IEntity& _arg0_) const;
#endif

	static inline auto FArkPlayerLiftEntityZeroGOv1 = PreyFunction<void(ArkPlayerLiftEntityZeroG* const _this)>(0x130F030);
	static inline auto FExitLiftVolume = PreyFunction<void(const ArkPlayerLiftEntityZeroG* const _this, const IEntity& _entity)>(0x130F090);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerLiftEntityZeroG* const _this, const IEntity& _entity, const ArkPsiLift& _lift, const float _frameTime)>(0x130F1A0);
};

// ArkPlayerLiftEntityZeroGSpawner
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntityZeroG.h
class ArkPlayerLiftEntityZeroGSpawner
{ // Size=4 (0x4)
public:
	float m_speed;

	ArkPlayerLiftEntityZeroGSpawner();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG> Spawn(const unsigned _entityId) const { alignas(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>) std::byte _return_buf_[sizeof(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>)]; return *FSpawn(this, reinterpret_cast<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>*>(_return_buf_), _entityId); }

	static inline auto FArkPlayerLiftEntityZeroGSpawner = PreyFunction<void(ArkPlayerLiftEntityZeroGSpawner* const _this)>(0x130F050);
	static inline auto FSpawn = PreyFunction<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>*(const ArkPlayerLiftEntityZeroGSpawner* const _this, ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>* _return_value_, const unsigned _entityId)>(0x130F0E0);
};

