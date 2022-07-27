// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>

class ArkInputLegend;
class CCryName;
struct IEntity;
struct IParticleEffect;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidController.h
class ArkPlayerMimicRigidController // Id=801B809 Size=56
{
public:
	using Properties = ArkPsiMimicRigidProperties;
	
	ArkSimpleTimer m_noiseTimer;
	ArkAudioTrigger m_jumpAudioTrigger;
	IParticleEffect *m_pParticleEffect;
	ArkPsiMimicRigidProperties const &m_properties;
	Vec3 m_localLongAxis;
	unsigned m_entityId;
	int m_movementParticleEffectSlot;
	bool m_bZeroG;
	bool m_bJumping;
	bool m_bAscending;
	bool m_bDescending;
	
	ArkPlayerMimicRigidController();
	void Initialize(IEntity &_mimicEntity) { FInitialize(this,_mimicEntity); }
	void Update(const float _frameTime, IEntity &_entity) { FUpdate(this,_frameTime,_entity); }
	void ProcessInput(CCryName const &_actionId, const bool _bPressed) { FProcessInput(this,_actionId,_bPressed); }
	ArkInputLegend const &GetModalLegend() const { return FGetModalLegend(this); }
	
#if 0
	void Serialize(TSerialize arg0) const;
	void PostSerialize() const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicRigidController *const _this, IEntity &_mimicEntity)>(0x131D520);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicRigidController *const _this, const float _frameTime, IEntity &_entity)>(0x131D650);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicRigidController *const _this, CCryName const &_actionId, const bool _bPressed)>(0x131D620);
	static inline auto FGetModalLegend = PreyFunction<ArkInputLegend const &(ArkPlayerMimicRigidController const *const _this)>(0x131D500);
};

