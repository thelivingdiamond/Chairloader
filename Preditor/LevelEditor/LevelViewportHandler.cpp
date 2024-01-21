#include <Prey/Cry3DEngine/IStatObj.h>
#include <Prey/CryEntitySystem/Entity.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/CryPhysics/IPhysics.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include "Objects/Object.h"
#include "LevelEditMode.h"
#include "LevelViewportHandler.h"
#include "ObjectManager.h"
#include "RayIntersectInfo.h"
#include "AuxGeomManager.h"

static Vec3 g_LastRaycastHit = ZERO;

LevelEditor::LevelViewportHandler::LevelViewportHandler(LevelEditMode* pEditor)
{
    m_pEditor = pEditor;
}

LevelEditor::LevelViewportHandler::~LevelViewportHandler()
{
}

void LevelEditor::LevelViewportHandler::ShowViewportControls()
{
}

EEditToolResult LevelEditor::LevelViewportHandler::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    return EEditToolResult::Passthrough;
}

SceneObjectId LevelEditor::LevelViewportHandler::Raycast(const ViewportRaycastInfo& rc)
{
    auto& objects = m_pEditor->GetObjectManager()->GetObjects();

    // Raycast to the world
    IPhysicalWorld::SRWIParams worldRWI;
    ray_hit worldHit;
    worldRWI.org = rc.ray.origin;
    worldRWI.dir = rc.ray.direction;
    worldRWI.objtypes = ent_static | ent_terrain;
    worldRWI.flags = rwi_stop_at_pierceable;
    worldRWI.hits = &worldHit;
    worldRWI.nMaxHits = 1;

    Vec3 raycastEnd = rc.ray.origin + rc.ray.direction;

    if (gEnv->pPhysicalWorld->RayWorldIntersection(worldRWI, "LevelViewportRWI"))
        raycastEnd = worldHit.pt;

    ViewportRaycastInfo rayInfo = rc;
    Object* pHitObject = nullptr;

    for (const std::unique_ptr<Object>& pObject : objects)
    {
        if (!pObject)
            continue;

        rayInfo.ray.direction = raycastEnd - rayInfo.ray.origin;

        RayIntersectInfo intersect;
        if (pObject->IntersectRay(rayInfo, intersect))
        {
            float curDist2 = rayInfo.ray.direction.len2();
            float dist2 = intersect.hitPosition.GetSquaredDistance(rayInfo.ray.origin);

            if (dist2 < curDist2)
            {
                pHitObject = pObject.get();
                raycastEnd = intersect.hitPosition;
            }
        }
    }

    // g_LastRaycastHit = raycastEnd;
    // CryLog("Hit: {} {} {}", raycastEnd.x, raycastEnd.y, raycastEnd.z);

    if (pHitObject)
        return pHitObject->GetObjectId();

    return INVALID_SCENE_OBJECT;
}

void LevelEditor::LevelViewportHandler::DrawAuxGeom()
{
    // gEnv->pAuxGeomRenderer->DrawSphere(g_LastRaycastHit, 0.05f, ColorB(255, 0, 0, 255));
    gLevel->pAuxGeomManager->RenderAuxGeom();
	DrawSelectedObjects();
}

void LevelEditor::LevelViewportHandler::DrawSelectedObjects()
{
    ObjectManager* pObjMgr = m_pEditor->GetObjectManager();
    SelectionManager* pSel = m_pEditor->GetSelection();
    SceneObjectId activeObjId = pSel->GetActiveObject();

    for (SceneObjectId objId : pSel->GetList())
    {
        Object* pObject = pObjMgr->GetObject(objId);

        if (pObject)
            pObject->DrawSelection(objId == activeObjId);
    }
}
