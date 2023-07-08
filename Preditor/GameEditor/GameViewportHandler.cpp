#include <Prey/Cry3DEngine/IStatObj.h>
#include <Prey/CryEntitySystem/Entity.h>
#include <Prey/CryGame/IGameFramework.h>
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

void GameEditor::GameViewportHandler::ShowViewportControls()
{
	ImGui::SameLine();
	ImGui::Text("Raycast:");
	ImGui::SameLine();

	if (ImGui::RadioButton("Physics", m_bPhysicsRaycast))
		m_bPhysicsRaycast = true;
	ImGui::SameLine();
	if (ImGui::RadioButton("Mesh", !m_bPhysicsRaycast))
		m_bPhysicsRaycast = false;
}

EEditToolResult GameEditor::GameViewportHandler::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    return EEditToolResult::Passthrough;
}

SceneObjectId GameEditor::GameViewportHandler::Raycast(const ViewportRaycastInfo& rc)
{
	if (m_bPhysicsRaycast)
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
	}
	else
	{
		// Render mesh raycast
		IEntityItPtr it = gEnv->pEntitySystem->GetEntityIterator();
		IEntity* pEnt = nullptr;

		float lastSeenThreshold = gEnv->pTimer->GetCurrTime() - 5 * gEnv->pTimer->GetFrameTime();

		float currentDist = rc.ray.direction.len();
		IEntity* pHitEnt = nullptr;
		Vec3 hitPoint = Vec3(ZERO);

		for (it->MoveFirst(); (pEnt = it->Next());)
		{
			// Check scene mask
			uint8_t entSceneMask = static_cast<CEntity*>(pEnt)->GetSceneMask();
			if ((entSceneMask & rc.sceneMask) == 0)
				continue;

			// Check visibility
			auto pProxy = static_cast<IEntityRenderProxy*>(pEnt->GetProxy(ENTITY_PROXY_RENDER));
			if (!pProxy)
				continue;

			// TODO 2023-07-08: Sometimes GetLastSeenTime lags behind GetCurrTime (but still updated every frame).
			// if (pProxy->GetLastSeenTime() < lastSeenThreshold)
			//	continue;

			// Test AABB
			{
				const Matrix34& entTM = pEnt->GetWorldTM();
				Matrix34 invTM = entTM.GetInverted();

				// Some entities have invalid transform (e.g. scale = 0)
				if (!entTM.IsValid() || !invTM.IsValid())
					continue;

				AABB entAabb;
				pEnt->GetLocalBounds(entAabb);
				Vec3 point;

				if (!Intersect::Ray_AABB(Ray(invTM * rc.ray.origin, invTM.TransformVector(rc.ray.direction)), entAabb, point))
					continue;
			}

			int slotCount = pEnt->GetSlotCount();

			for (int slotIdx = 0; slotIdx < slotCount; slotIdx++)
			{
				if (IStatObj* pObj = pEnt->GetStatObj(slotIdx))
				{
					Matrix34 slotTM = pEnt->GetSlotWorldTM(slotIdx);
					Matrix34 invTM = slotTM.GetInverted();

					// Some entities have invalid transform (e.g. scale = 0)
					if (!slotTM.IsValid() || !invTM.IsValid())
						continue;

					SRayHitInfo objRay;
					objRay.inRay = Ray(invTM * rc.ray.origin, Matrix33(invTM) * rc.ray.direction);
					objRay.inReferencePoint = objRay.inRay.origin;
					objRay.fMaxHitDistance = currentDist;

					if (pObj->RayIntersection(objRay))
					{
						CRY_ASSERT(objRay.fDistance <= currentDist);
						currentDist = objRay.fDistance;
						pHitEnt = pEnt;
						hitPoint = slotTM * objRay.vHitPos;
					}
				}
			}
		}

		if (pHitEnt)
		{
			// IPersistantDebug* pd = gEnv->pGame->GetIGameFramework()->GetIPersistantDebug();
			// pd->Begin("GameRaycast", false);
			// pd->AddSphere(hitPoint, 0.05f, ColorF(1, 0, 0, 1), 15);
			return pHitEnt->GetId();
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
