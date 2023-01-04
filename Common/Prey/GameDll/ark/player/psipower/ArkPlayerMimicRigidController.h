// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkInputLegend;
class ArkPsiMimicRigidProperties;
class CCryName;
struct IEntity;
struct IParticleEffect;

// ArkPlayerMimicRigidController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidController.h
class ArkPlayerMimicRigidController
{ // Size=56 (0x38)
public:
	using Properties = ArkPsiMimicRigidProperties;

	ArkSimpleTimer m_noiseTimer;
	ArkAudioTrigger m_jumpAudioTrigger;
	IParticleEffect* m_pParticleEffect;
	const ArkPsiMimicRigidProperties& m_properties;
	Vec3 m_localLongAxis;
	unsigned m_entityId;
	int m_movementParticleEffectSlot;
	bool m_bZeroG;
	bool m_bJumping;
	bool m_bAscending;
	bool m_bDescending;

	ArkPlayerMimicRigidController();
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _entity) { FUpdate(this, _frameTime, _entity); }
	void ProcessInput(const CCryName& _actionId, const bool _bPressed) { FProcessInput(this, _actionId, _bPressed); }
	const ArkInputLegend& GetModalLegend() const { return FGetModalLegend(this); }

#if 0
	void Serialize(TSerialize _arg0_) const;
	void PostSerialize() const;
#endif

	static inline auto FArkPlayerMimicRigidControllerOv2 = PreyFunction<void(ArkPlayerMimicRigidController* const _this)>(0x131D2E0);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicRigidController* const _this, IEntity& _mimicEntity)>(0x131D520);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicRigidController* const _this, const float _frameTime, IEntity& _entity)>(0x131D650);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicRigidController* const _this, const CCryName& _actionId, const bool _bPressed)>(0x131D620);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const ArkPlayerMimicRigidController* const _this)>(0x131D500);
};

