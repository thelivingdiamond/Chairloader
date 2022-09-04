#include <Prey/CryAction/GameObject.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include "EntityInspector.h"

void EntityInspector::ShowContent(EntityId entityId)
{
	if (m_EntityId != entityId)
		OnEntityChanged(entityId);

	if (entityId == 0)
	{
		ImGui::TextWrapped("No entity selected.");
		return;
	}

	IEntity* pEnt = gEnv->pEntitySystem->GetEntity(entityId);
	if (!pEnt)
	{
		ImGui::TextWrapped("The entity with ID 0x%08X no longer exists.", entityId);
		return;
	}

	ImGui::TextWrapped("Name: '%s'", pEnt->GetName());
	ImGui::TextWrapped("ID: %08X, GUID: %016X", pEnt->GetId(), pEnt->GetGuid());
	ImGui::TextWrapped("Class: '%s'", pEnt->GetClass() ? pEnt->GetClass()->GetName() : nullptr);

	if (pEnt->GetArchetype()) {
		ImGui::TextWrapped("Archetype: '%s', ID: %016X", pEnt->GetArchetype()->GetName(), pEnt->GetArchetype()->GetId());
	}
	else {
		ImGui::TextWrapped("Archetype: (null)");
	}

	InspectTransform(pEnt);
    InspectSlots(pEnt);
	InspectEntityScript(pEnt);
	InspectPhysics(pEnt);
	InspectTrigger(pEnt);
	InspectAudio(pEnt);
	InspectRender(pEnt);
	InspectArea(pEnt);
	InspectBoids(pEnt);
	InspectClipVolume(pEnt);
	InspectFlowGraph(pEnt);
	InspectSubstitution(pEnt);
	InspectCamera(pEnt);
	InspectRope(pEnt);
	InspectGameObject(pEnt);
}

bool EntityInspector::BeginInspector(const char* name, ImGuiTreeNodeFlags flags)
{
    if (ImGui::CollapsingHeader(name, ImGuiTreeNodeFlags_DefaultOpen | flags))
    {
        ImGui::PushID(name);
        return true;
    }

    return false;
}

void EntityInspector::EndInspector()
{
    ImGui::PopID();
}

void EntityInspector::OnEntityChanged(EntityId entityId)
{
	m_EntityId = entityId;
	// If there will be any persistent state, init can go here.
}

void EntityInspector::InspectTransform(IEntity* pEnt) {
    if (BeginInspector("Transform")) {
        Vec3 pos = pEnt->GetPos();
        Ang3 angles = RAD2DEG(Ang3(pEnt->GetRotation()));
        Vec3 scale = pEnt->GetScale();

        if (ImGui::InputFloat3("Position", &pos.x)) {
            pEnt->SetPos(pos);
        }

        if (ImGui::InputFloat3("Rotation (PRY)", &angles.x)) {
            pEnt->SetRotation(Quat(DEG2RAD(angles)));
        }

        if (ImGui::InputFloat3("Scale", &scale.x)) {
            pEnt->SetScale(scale);
        }

        if (scale.x != scale.y || scale.x != scale.z) {
            ImGui::TextWrapped("Note: non-uniform scaling is not supported well");
        }

        if (ImGui::Button("TP to player") && ArkPlayer::GetInstancePtr())
            pEnt->SetPos(ArkPlayer::GetInstance().GetEntity()->GetPos());

        EndInspector();
    }
}

void EntityInspector::InspectSlots(IEntity* pEnt)
{
    int slotCount = pEnt->GetSlotCount();
    for (int slotIdx = 0; slotIdx < slotCount; slotIdx++)
    {
        if (!pEnt->IsSlotValid(slotIdx))
            continue;

        char slotName[64];
        snprintf(slotName, sizeof(slotName), "Slot %d", slotIdx);
        if (BeginInspector(slotName)) {
            SEntitySlotInfo slotInfo;
            pEnt->GetSlotInfo(slotIdx, slotInfo);

            ImGui::Text("Flags: 0x%X", slotInfo.nFlags);
            ImGui::Text("Parent Slot: %d", slotInfo.nParentSlot);

            if (slotInfo.pStatObj)
                ImGui::Text("StatObj");
            if (slotInfo.pCharacter)
                ImGui::Text("Character");
            if (slotInfo.pParticleEmitter)
                ImGui::Text("ParticleEmitter");
            if (slotInfo.pLight)
                ImGui::Text("Light");
            if (slotInfo.pChildRenderNode)
                ImGui::Text("ChildRenderNode");
            if (slotInfo.pGeomCacheRenderNode)
                ImGui::Text("GeomCacheRenderNode");
            if (slotInfo.pMaterial)
                ImGui::Text("Custom material is set");

            if (ImGui::TreeNode("Transform"))
            {
                Matrix33 rotMat; slotInfo.pLocalTM->GetRotation33(rotMat);
                Vec3 pos = slotInfo.pLocalTM->GetTranslation();
                Ang3 rot = Ang3(rotMat);
                Vec3 scale = slotInfo.pLocalTM->GetScale();

                bool transformChanged = false;
                transformChanged |= ImGui::InputFloat3("Position", &pos.x);
                transformChanged |= ImGui::InputFloat3("Rotation (PRY)", &rot.x);
                transformChanged |= ImGui::InputFloat3("Scale", &scale.x);

                if (transformChanged)
                {
                    Matrix34 newTransform;
                    newTransform = Matrix34::CreateTranslationMat(pos) * Matrix34::CreateRotationXYZ(rot) * Matrix34::CreateScale(scale);
                    pEnt->SetSlotLocalTM(slotIdx, newTransform);
                }

                Vec3 cameraSpacePos;
                pEnt->GetSlotCameraSpacePos(slotIdx, cameraSpacePos);
                if (ImGui::InputFloat3("Cam-space Pos", &cameraSpacePos.x))
                {
                    pEnt->SetSlotCameraSpacePos(slotIdx, cameraSpacePos);
                }

                ImGui::TreePop();
            }
            EndInspector();
        }
    }
}

void EntityInspector::InspectEntityScript(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityScriptProxy*>(pEnt->GetProxy(ENTITY_PROXY_SCRIPT));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Lua Script")) {
        ImGui::Text("State: %s [%d]", pProxy->GetState(), pProxy->GetStateId());

        IScriptTable* pScriptTable = pProxy->GetScriptTable();

        if (!pScriptTable)
        {
            ImGui::Text("No script table");
        }
        else
        {
            ImGui::Checkbox("Show Functions", &m_bShowScriptFuncs);
            ShowScriptTable(pScriptTable);
        }

        EndInspector();
    }
}

void EntityInspector::ShowScriptTable(IScriptTable* pScriptTable)
{
    IScriptTable::Iterator iter = pScriptTable->BeginIteration(true);

    int propIdx = 0;

    while (pScriptTable->MoveNext(iter))
    {
        char keyStr[128];
        if (iter.sKey)
        {
            cry_strcpy(keyStr, iter.sKey);
        }
        else
        {
            if (iter.key.type == ANY_TNUMBER)
            {
                int idx = 0;
                iter.key.CopyTo(idx);
                snprintf(keyStr, sizeof(keyStr), "[%d]", idx);
            }
            else
            {
                snprintf(keyStr, sizeof(keyStr), "unk key type %d", iter.nKey);
            }
        }

        char propUiTag[32];
        snprintf(propUiTag, sizeof(propUiTag), "##Prop%d", propIdx);

        if (iter.value.type == ANY_TTABLE)
        {
            if (ImGui::TreeNode(keyStr))
            {
                IScriptTable* pChildTable = nullptr;
                iter.value.CopyTo(pChildTable);
                ShowScriptTable(pChildTable);
                ImGui::TreePop();
            }
        }
        else if (m_bShowScriptFuncs || iter.value.type != ANY_TFUNCTION)
        {
            ImGui::Text("%s = ", keyStr);
            ImGui::SameLine();

            switch (iter.value.type)
            {
            case ANY_TNIL:
            {
                ImGui::Text("nil");
                break;
            }
            case ANY_TBOOLEAN:
            {
                bool val = false;
                iter.value.CopyTo(val);
                if (ImGui::Checkbox(propUiTag, &val))
                    pScriptTable->SetValue(iter.sKey, val);
                break;
            }
            case ANY_THANDLE:
            {
                ScriptHandle handle;
                iter.value.CopyTo(handle);
                ImGui::Text("0x%X (handle)", handle.n);
                break;
            }
            case ANY_TNUMBER:
            {
                float val = 0;
                iter.value.CopyTo(val);
                if (ImGui::InputFloat(propUiTag, &val))
                    pScriptTable->SetValue(iter.sKey, val);
                break;
            }
            case ANY_TSTRING:
            {
                const char* val = nullptr;
                iter.value.CopyTo(val);
                ImGui::Text("\"%s\"", val);
                break;
            }
            case ANY_TFUNCTION:
            {
                ImGui::Text("function");
                break;
            }
            case ANY_TUSERDATA:
            {
                ImGui::Text("user data");
                break;
            }
            case ANY_TVECTOR:
            {
                Vec3 val(ZERO);
                iter.value.CopyTo(val);
                if (ImGui::InputFloat3(propUiTag, &val.x))
                    pScriptTable->SetValue(iter.sKey, val);
                break;
            }
            }
        }

        propIdx++;
    }

    pScriptTable->EndIteration(iter);
}

void EntityInspector::InspectPhysics(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityPhysicalProxy*>(pEnt->GetProxy(ENTITY_PROXY_PHYSICS));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Physics")) {
        ImGui::Text("Enabled: %d", pProxy->IsPhysicsEnabled());
        EndInspector();
    }
}

void EntityInspector::InspectTrigger(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityTriggerProxy*>(pEnt->GetProxy(ENTITY_PROXY_TRIGGER));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Trigger")) {
        EndInspector();
    }
}

void EntityInspector::InspectAudio(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityProxy*>(pEnt->GetProxy(ENTITY_PROXY_AUDIO));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Audio")) {
        EndInspector();
    }
}

void EntityInspector::InspectRender(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityRenderProxy*>(pEnt->GetProxy(ENTITY_PROXY_RENDER));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Render")) {
        ImGui::Text("Render material: %s", pProxy->GetRenderMaterial() ? "set" : "not set");
        ImGui::Text("Material layers mask: %02X", pProxy->GetMaterialLayersMask());
        ImGui::Text("Shadow dissolve: %d", pProxy->GetShadowDissolve());
        ImGui::Text("Opacity: %.3f", pProxy->GetOpacity());
        ImGui::Text("Last seen time: %.3f", pProxy->GetLastSeenTime());
        ImGui::Text("Visarea visible: %d", pProxy->IsRenderProxyVisAreaVisible());
        EndInspector();
    }
}

void EntityInspector::InspectArea(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityAreaProxy*>(pEnt->GetProxy(ENTITY_PROXY_AREA));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Area")) {
        ImGui::Text("Flags: %01X", pProxy->GetFlags());
        ImGui::Text("Area type: %d", pProxy->GetAreaType());
        ImGui::Text("ID: %d", pProxy->GetID());
        ImGui::Text("Group: %d", pProxy->GetGroup());
        ImGui::Text("Priority: %d", pProxy->GetPriority());
        ImGui::Text("Proximity: %.2f", pProxy->GetProximity());
        EndInspector();
    }
}

void EntityInspector::InspectBoids(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityBoidsProxy*>(pEnt->GetProxy(ENTITY_PROXY_BOIDS));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Boids")) {
        EndInspector();
    }
}

void EntityInspector::InspectClipVolume(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityProxy*>(pEnt->GetProxy(ENTITY_PROXY_CLIPVOLUME));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Clip Volume")) {
        EndInspector();
    }
}

void EntityInspector::InspectFlowGraph(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityFlowGraphProxy*>(pEnt->GetProxy(ENTITY_PROXY_FLOWGRAPH));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Flow Graph")) {
        EndInspector();
    }
}

void EntityInspector::InspectSubstitution(IEntity* pEnt) {
    auto pProxy = static_cast<IEntitySubstitutionProxy*>(pEnt->GetProxy(ENTITY_PROXY_SUBSTITUTION));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Substitution")) {
        ImGui::Text("Substitute: %s", pProxy->GetSubstitute() ? "set" : "not set");
        EndInspector();
    }
}

void EntityInspector::InspectCamera(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityCameraProxy*>(pEnt->GetProxy(ENTITY_PROXY_CAMERA));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Camera")) {
        const CCamera& cam = pProxy->GetCamera();
        ImGui::BeginDisabled();
        Vec3 pos = cam.GetPosition();
        Ang3 ang = RAD2DEG(cam.GetAngles());
        ImGui::InputFloat3("Position", &pos.x);
        ImGui::InputFloat3("Rotation", &ang.x);
        ImGui::EndDisabled();
        EndInspector();
    }
}

void EntityInspector::InspectRope(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityRopeProxy*>(pEnt->GetProxy(ENTITY_PROXY_ROPE));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Rope")) {
        EndInspector();
    }
}

void EntityInspector::InspectGameObject(IEntity* pEnt) {
    auto pProxy = static_cast<CGameObject*>(pEnt->GetProxy(ENTITY_PROXY_USER));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("GameObject")) {
        auto& exts = pProxy->m_extensions;
        ImGui::Text("Extensions: %d", (int)exts.size());
        for (auto& ext : exts) {
            const char* name = g_pGame->GetIGameFramework()->GetIGameObjectSystem()->GetName(ext.id);
            ImGui::Text("%s 0x%p", name, ext.pExtension.get());
        }
        EndInspector();
    }
}
