#include "pch.h"
#include "ChairloaderUtils.h"
SEntitySpawnParams* ChairloaderUtils::
CreateEntitySpawnParameters(char* name, Vec3_tpl<float>* pos, Quat_tpl<float>* rot, SEntitySpawnParams* params) {
	params->vScale.x = 1;
	params->vScale.y = 1;
	params->vScale.z = 1;
	params->vPosition.x = pos->x;
	params->vPosition.y = pos->y;
	params->vPosition.z = pos->z;
	params->qRotation.x = rot->x;
	params->qRotation.y = rot->y;
	params->qRotation.z = rot->z;
	params->qRotation.w = rot->w;
	params->sLayerName = (char*)"";
	params->guid = 0;
	params->prevGuid = 0;
	params->pClass = nullptr;
	params->pArchetype = nullptr;
	params->entityNode.ptr = nullptr;
	params->id = 0;
	params->prevId = 0;
	params->nFlags = 0;
	params->nFlagsExtended = 0;
	params->bIgnoreLock = 0;
	params->bStaticEntityId = 0;
	params->bCreatedThroughPool = 0;
	params->sceneMask = 0x1;
	params->shadowCasterType = '\0';
	params->pPropertiesTable = nullptr;
	params->pPropertiesInstanceTable = nullptr;
	params->sName = name;
	return params;
}
CEntity* ChairloaderUtils::CreateEntity(CEntitySystem* system, char* name, Vec3_tpl<float>* pos, Quat_tpl<float>* rot,
	uint64_t archetypeId, preyFunctions* functions) {
	SEntitySpawnParams params;
	if (CreateEntitySpawnParameters(name, pos, rot, &params) == nullptr)
		return nullptr;
	CEntityArchetype* archetype = system->GetEntityArchetype(archetypeId);
	if (archetype == nullptr)
		return nullptr;
	CEntityClass* entityClass = (CEntityClass*)archetype->GetClass();
	if (entityClass == nullptr)
		return nullptr;
	params.pArchetype = archetype;
	params.pClass = entityClass;
	// XmlNodeRef* xmlnode = archetype->GetObjectVars();
	params.entityNode = archetype->m_ObjectVars;
	// std::cout << params->id << std::endl;
	// params.id = 69420;
	params.id = functions->CEntitySystemF->generateEntityId(system, true);
	CEntity newEntity;
	return (CEntity*)functions->CEntity->CEntityConstructor(&newEntity, &params);
	return nullptr;
}



