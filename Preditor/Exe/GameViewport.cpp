#include <Preditor/IPreditorEngine.h>
#include "GameViewport.h"

GameViewport::GameViewport()
{
	SetTitle("Viewport");
	SetPersistentID("GameViewport");
	m_pViewportTexture = IPreditorEngine::Get()->GetViewportTexture();
	assert(m_pViewportTexture);

	m_pCVarWidth = gEnv->pConsole->GetCVar("r_Width");
	m_pCVarHeight = gEnv->pConsole->GetCVar("r_Height");
}

void GameViewport::ShowContents()
{
	// Calculate viewport size
	ImVec2 min = ImGui::GetWindowContentRegionMin();
	ImVec2 max = ImGui::GetWindowContentRegionMax();
	Vec2i size(max.x - min.x, max.y - min.y);

	// Clamp it to a reasonable size
	size.x = std::clamp(size.x, MIN_WIDTH, MAX_SIZE);
	size.y = std::clamp(size.y, MIN_HEIGHT, MAX_SIZE);

	// Draw the image
	ImVec2 imageSize(size.x, size.y);
	ImGui::Image(m_pViewportTexture, imageSize);

	// Set engine viewport size
	if (m_pCVarWidth->GetIVal() != size.x)
		m_pCVarWidth->Set(size.x);
	if (m_pCVarHeight->GetIVal() != size.y)
		m_pCVarHeight->Set(size.y);
}
