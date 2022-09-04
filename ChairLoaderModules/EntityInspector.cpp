#include <Prey/CryAction/GameObject.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryGame/Game.h>
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

void EntityInspector::InspectEntityScript(IEntity* pEnt) {
    auto pProxy = static_cast<IEntityScriptProxy*>(pEnt->GetProxy(ENTITY_PROXY_SCRIPT));
    if (!pProxy) {
        return;
    }

    if (BeginInspector("Script")) {
        ImGui::Text("State: %s [%d]", pProxy->GetState(), pProxy->GetStateId());
        EndInspector();
    }
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
