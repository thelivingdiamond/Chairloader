#pragma once
#include "Prey/CryCore/StdAfx.h"

class ArkEffectBase
{
	_smart_ptr<IParticleEffect> m_pEffect;
	SpawnParams m_spawnParams;
};
static_assert(sizeof(ArkEffectBase) == 0x40);
class ArkLooseEffect : public ArkEffectBase
{
	_smart_ptr<IParticleEmitter> m_pEmitter;
	QuatTS_tpl<float> m_location;
	bool m_bStarted;
};
class ArkEntityEffectBase : ArkEffectBase
{
public:
	void* vtable;
	Matrix34_tpl<float> m_localTM;
	int m_nSlot;
	bool m_bStarted;
	bool m_bSerialize;
};
class ArkFireAndForgetEffect : ArkEffectBase
{
};
class ArkEntityEffect : ArkEntityEffectBase
{
public:
	void* vtable;


	IGameObjectExtension* m_owner;
};
static_assert(sizeof(ArkLooseEffect) == 0x70);
namespace EntityEffects {
	class SEffectInfo {
	public:
		uint32_t id;
		int32_t entityEffectSlot;
		int32_t characterEffectSlot;
		CSharedString helperName;
	};
	class CEffectsController {
	public:
		IEntity* m_pOwnerEntity;
		std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
		uint32_t m_effectGeneratorId;
	};
}
class ArkEntityAttachmentEffect : ArkEffectBase
{
	EntityEffects::CEffectsController* m_controller;
	CryStringT<char> m_attachmentName;
	int m_attachmentSlot;
	unsigned int m_effectId;
};