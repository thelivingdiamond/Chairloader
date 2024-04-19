#include <Preditor/Assets/IAssetSystem.h>
#include "UI/InvalidateWindow.h"

Assets::InvalidateWindow::InvalidateWindow()
{
    SetTitle("Cache Invalidation...");
    SetPersistentID("AssetCacheInv");
    SetVisible(false);
    SetDestroyOnClose(false);
}

Assets::InvalidateWindow::~InvalidateWindow()
{
}

void Assets::InvalidateWindow::ShowContents()
{
    ImGui::Text("Cache invalidation will cause all files to be reimported/remerged on next merge.");
    ImGui::Checkbox("Invalidate Import Cache", &m_bInvImport);
    ImGui::Checkbox("Invalidate Merge Cache", &m_bInvMerge);
    ImGui::Checkbox("Run Merging after invalidation", &m_bAutoMerge);

    if (ImGui::Button("Invalidate"))
    {
        gPreditor->pAssetSystem->InvalidateCache(m_bInvImport, m_bInvMerge);

        if (m_bAutoMerge)
            gPreditor->pAssetSystem->RequestMerging();
    }

    ImGui::SameLine();

    if (ImGui::Button("Close"))
        SetVisible(false);
}
