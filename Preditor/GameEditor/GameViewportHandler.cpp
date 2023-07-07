#include <Prey/CryPhysics/physinterface.h>
#include <Prey/CryPhysics/IPhysics.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include "GameEditMode.h"
#include "GameViewportHandler.h"

GameEditor::GameViewportHandler::GameViewportHandler(GameEditMode* pEditor)
{
    m_pEditor = pEditor;
}

GameEditor::GameViewportHandler::~GameViewportHandler()
{
}

EEditToolResult GameEditor::GameViewportHandler::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    return EEditToolResult::Passthrough;
}

SceneObjectId GameEditor::GameViewportHandler::Raycast(const ViewportRaycastInfo& rc)
{
    // Physics raycast
	ray_hit hit;
	const unsigned rwiFlags = rwi_stop_at_pierceable | rwi_colltype_any;

	if (gEnv->pPhysicalWorld->RayWorldIntersection(rc.ray.origin, rc.ray.direction, ent_all, rwiFlags, &hit, 1, nullptr, nullptr))
	{
		int type = hit.pCollider->GetiForeignData();
		if (type == PHYS_FOREIGN_ID_ENTITY)
		{
			IEntity* pEntity = (IEntity*)hit.pCollider->GetForeignData(PHYS_FOREIGN_ID_ENTITY);
			return pEntity->GetId();
		}
	}

    return INVALID_SCENE_OBJECT;
}

void GameEditor::GameViewportHandler::DrawAuxGeom()
{
	DrawSelectedObjects();
}

void GameEditor::GameViewportHandler::DrawSelectedObjects()
{
	IEntitySystem* pEntSys = gEnv->pEntitySystem;
	IRenderAuxGeom* pAux = gEnv->pAuxGeomRenderer;

	SelectionManager* pSel = m_pEditor->GetSelection();
	SceneObjectId activeObjId = pSel->GetActiveObject();

	for (SceneObjectId objId : pSel->GetList())
	{
		IEntity* pEnt = pEntSys->GetEntity((EntityId)objId);

		if (pEnt)
		{
			bool isActive = objId == activeObjId;
			ColorB color = isActive ? SELECTION_ACTIVE_COLOR : SELECTION_COLOR;

			AABB aabb;
			pEnt->GetLocalBounds(aabb);
			pAux->DrawAABB(aabb, pEnt->GetWorldTM(), false, color, eBBD_Faceted);
		}
	}
}
