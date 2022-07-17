#pragma once
class IArkPlayerLightOwner
{
public:
	virtual void LightVisibilityUpdated(bool) = 0;
};

class IArkPlayerLight {
	virtual unsigned int GetLightAttachmentEntity() = 0;
	virtual void AttachLightEntity() = 0;
	virtual void SpawnLightEntity() = 0;
	virtual void SetLightVisible_Internal(bool) = 0;
};

class ArkPlayerLight
{
public:
	void* vtable;
	bool m_bWantsToBeVisible;
	bool m_bVisible;
	EArkPlayerLightPriority m_priority;
	IArkPlayerLightOwner* m_pOwner;
};
class ArkPlayerLightVFX : ArkPlayerLight
{
public:
	ArkLooseEffect m_lightVFX;
};