#pragma once

struct IScriptTable;

class EntityInspector
{
public:
	void ShowContents(EntityId entityId);

private:
	EntityId m_EntityId = 0;
	bool m_bShowScriptFuncs = false;

	static bool BeginInspector(const char* name, ImGuiTreeNodeFlags flags = 0);
	static void EndInspector();

	void OnEntityChanged(EntityId entityId);
	void InspectTransform(IEntity* pEnt);
	void InspectSlots(IEntity* pEnt);
	void InspectEntityScript(IEntity* pEnt);
	void ShowScriptTable(IScriptTable* pScriptTable);
	void InspectPhysics(IEntity* pEnt);
	void InspectTrigger(IEntity* pEnt);
	void InspectAudio(IEntity* pEnt);
	void InspectRender(IEntity* pEnt);
	void InspectArea(IEntity* pEnt);
	void InspectBoids(IEntity* pEnt);
	void InspectClipVolume(IEntity* pEnt);
	void InspectFlowGraph(IEntity* pEnt);
	void InspectSubstitution(IEntity* pEnt);
	void InspectCamera(IEntity* pEnt);
	void InspectRope(IEntity* pEnt);
	void InspectGameObject(IEntity* pEnt);
};
